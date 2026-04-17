const canvas = document.getElementById("globeCanvas");
const ctx = canvas.getContext("2d");

const tooltip = document.getElementById("tooltip");
const cityInfo = document.getElementById("cityInfo");
const cityFilter = document.getElementById("cityFilter");
const pauseBtn = document.getElementById("pauseBtn");
const resetBtn = document.getElementById("resetBtn");
const reducedMotionToggle = document.getElementById("reducedMotionToggle");
const categoryToggles = [...document.querySelectorAll(".category-toggle")];

const cities = [
  { id: "nyc", name: "New York", lat: 40.7128, lon: -74.006, region: "North America" },
  { id: "rio", name: "Rio de Janeiro", lat: -22.9068, lon: -43.1729, region: "South America" },
  { id: "lagos", name: "Lagos", lat: 6.5244, lon: 3.3792, region: "Africa" },
  { id: "london", name: "London", lat: 51.5072, lon: -0.1276, region: "Europe" },
  { id: "paris", name: "Paris", lat: 48.8566, lon: 2.3522, region: "Europe" },
  { id: "mumbai", name: "Mumbai", lat: 19.076, lon: 72.8777, region: "Asia" },
  { id: "dubai", name: "Dubai", lat: 25.2048, lon: 55.2708, region: "Asia" },
  { id: "tokyo", name: "Tokyo", lat: 35.6762, lon: 139.6503, region: "Asia" },
  { id: "seoul", name: "Seoul", lat: 37.5665, lon: 126.978, region: "Asia" },
  { id: "sydney", name: "Sydney", lat: -33.8688, lon: 151.2093, region: "Oceania" },
  { id: "melbourne", name: "Melbourne", lat: -37.8136, lon: 144.9631, region: "Oceania" },
  { id: "cairo", name: "Cairo", lat: 30.0444, lon: 31.2357, region: "Africa" },
  { id: "mexico", name: "Mexico City", lat: 19.4326, lon: -99.1332, region: "North America" },
];

const flows = [
  { from: "lagos", to: "london", category: "music", intensity: 0.96 },
  { from: "tokyo", to: "nyc", category: "fashion", intensity: 0.82 },
  { from: "mumbai", to: "dubai", category: "film", intensity: 0.66 },
  { from: "seoul", to: "paris", category: "fashion", intensity: 0.73 },
  { from: "rio", to: "paris", category: "music", intensity: 0.79 },
  { from: "mexico", to: "nyc", category: "food", intensity: 0.88 },
  { from: "cairo", to: "mumbai", category: "food", intensity: 0.61 },
  { from: "sydney", to: "tokyo", category: "film", intensity: 0.69 },
  { from: "melbourne", to: "seoul", category: "music", intensity: 0.58 },
  { from: "paris", to: "tokyo", category: "fashion", intensity: 0.72 },
  { from: "london", to: "mexico", category: "film", intensity: 0.55 },
  { from: "nyc", to: "rio", category: "food", intensity: 0.63 },
  { from: "mumbai", to: "london", category: "film", intensity: 0.8 },
  { from: "cairo", to: "paris", category: "fashion", intensity: 0.57 },
  { from: "tokyo", to: "seoul", category: "music", intensity: 0.76 },
];

const categoryColors = {
  music: "#66b8ff",
  film: "#c37bff",
  food: "#ff9f59",
  fashion: "#4de0c8",
};

const NORMAL_FPS = 60;
const REDUCED_MOTION_FPS = 30;
const UI_FONT_STACK = "Inter, Segoe UI, Roboto, Arial, sans-serif";

const cityMap = new Map(cities.map((city) => [city.id, city]));
flows.forEach((flow) => {
  if (!cityMap.has(flow.from) || !cityMap.has(flow.to)) {
    throw new Error(`Invalid flow city reference: ${flow.from} -> ${flow.to}`);
  }
});

const state = {
  rotationY: 0.55,
  rotationX: -0.18,
  zoom: 1,
  autoRotate: true,
  paused: false,
  reducedMotion: window.matchMedia("(prefers-reduced-motion: reduce)").matches,
  selectedCity: null,
  hoveredCity: null,
  hoveredFlow: null,
  dragging: false,
  dragStartX: 0,
  dragStartY: 0,
  startRotX: 0,
  startRotY: 0,
  lastRenderAt: 0,
  animationTime: 0,
  activeCategories: new Set(["music", "film", "food", "fashion"]),
  cityFilter: "all",
  cityScreenPoints: [],
};

const stars = Array.from({ length: 220 }, () => ({
  x: Math.random(),
  y: Math.random(),
  r: Math.random() * 1.7 + 0.25,
  twinkle: Math.random() * Math.PI * 2,
}));

const flowPaths = flows.map((flow) => ({
  ...flow,
  phase: Math.random(),
  pathHigh: buildArcPath(flow, 60),
  pathLow: buildArcPath(flow, 26),
}));

if (state.reducedMotion) {
  reducedMotionToggle.checked = true;
}

init();
requestAnimationFrame(loop);

function init() {
  populateCityFilter();
  updateCityPanel();
  verifyContrast();
  setupThemeWatchers();
  bindEvents();
  resizeCanvas();
}

function populateCityFilter() {
  cities.forEach((city) => {
    const option = document.createElement("option");
    option.value = city.id;
    option.textContent = city.name;
    cityFilter.appendChild(option);
  });
}

function bindEvents() {
  window.addEventListener("resize", resizeCanvas);

  canvas.addEventListener("mousedown", (event) => {
    state.dragging = true;
    canvas.classList.add("dragging");
    state.dragStartX = event.clientX;
    state.dragStartY = event.clientY;
    state.startRotX = state.rotationX;
    state.startRotY = state.rotationY;
  });

  window.addEventListener("mouseup", () => {
    state.dragging = false;
    canvas.classList.remove("dragging");
  });

  window.addEventListener("mousemove", (event) => {
    const bounds = canvas.getBoundingClientRect();
    const x = event.clientX - bounds.left;
    const y = event.clientY - bounds.top;

    if (state.dragging) {
      const dx = event.clientX - state.dragStartX;
      const dy = event.clientY - state.dragStartY;
      state.rotationY = state.startRotY + dx * 0.0055;
      state.rotationX = clamp(state.startRotX + dy * 0.0045, -1.1, 1.1);
      return;
    }

    const cityHit = pickCity(x, y);
    state.hoveredCity = cityHit;
    if (cityHit) {
      showTooltip(event.clientX, event.clientY, `${cityHit.name}<br>${cityHit.region}`);
    } else {
      hideTooltip();
    }
  });

  canvas.addEventListener("mouseleave", () => {
    state.hoveredCity = null;
    hideTooltip();
  });

  canvas.addEventListener("click", (event) => {
    const bounds = canvas.getBoundingClientRect();
    const x = event.clientX - bounds.left;
    const y = event.clientY - bounds.top;
    const hit = pickCity(x, y);
    state.selectedCity = hit ? hit.id : null;
    updateCityPanel();
  });

  canvas.addEventListener("wheel", (event) => {
    const zoomStep = state.reducedMotion ? 0.045 : 0.07;
    const nextZoom = clamp(state.zoom - Math.sign(event.deltaY) * zoomStep, 0.72, 1.72);
    if (nextZoom === state.zoom) {
      return;
    }
    event.preventDefault();
    state.zoom = nextZoom;
  }, { passive: false });

  pauseBtn.addEventListener("click", () => {
    state.paused = !state.paused;
    pauseBtn.textContent = state.paused ? "Resume" : "Pause";
  });

  resetBtn.addEventListener("click", () => {
    state.rotationY = 0.55;
    state.rotationX = -0.18;
    state.zoom = 1;
    state.selectedCity = null;
    state.cityFilter = "all";
    cityFilter.value = "all";
    updateCityPanel();
  });

  reducedMotionToggle.addEventListener("change", () => {
    state.reducedMotion = reducedMotionToggle.checked;
  });

  cityFilter.addEventListener("change", () => {
    state.cityFilter = cityFilter.value;
    if (state.cityFilter !== "all" && state.selectedCity !== state.cityFilter) {
      state.selectedCity = state.cityFilter;
    }
    updateCityPanel();
  });

  categoryToggles.forEach((toggle) => {
    toggle.addEventListener("change", () => {
      if (toggle.checked) {
        state.activeCategories.add(toggle.value);
      } else {
        state.activeCategories.delete(toggle.value);
      }
      updateCityPanel();
    });
  });
}

function resizeCanvas() {
  const ratio = window.devicePixelRatio || 1;
  const bounds = canvas.getBoundingClientRect();
  canvas.width = Math.floor(bounds.width * ratio);
  canvas.height = Math.floor(bounds.height * ratio);
  ctx.setTransform(ratio, 0, 0, ratio, 0, 0);
}

function loop(timestamp) {
  requestAnimationFrame(loop);
  const frameBudget = state.reducedMotion ? 1000 / REDUCED_MOTION_FPS : 1000 / NORMAL_FPS;
  if (timestamp - state.lastRenderAt < frameBudget) {
    return;
  }

  const delta = Math.min(48, timestamp - state.lastRenderAt || 16.7);
  state.lastRenderAt = timestamp;

  if (!state.paused) {
    state.animationTime += delta / 1000;
    if (state.autoRotate && !state.dragging) {
      state.rotationY += state.reducedMotion ? 0.001 : 0.0022;
    }
  }

  draw();
}

function draw() {
  const width = canvas.clientWidth;
  const height = canvas.clientHeight;
  const cx = width * 0.5;
  const cy = height * 0.5;
  const radius = Math.min(width, height) * 0.33 * state.zoom;

  ctx.clearRect(0, 0, width, height);
  drawStarfield(width, height);
  drawAtmosphere(cx, cy, radius);
  drawGlobeBody(cx, cy, radius);

  const visibleFlows = getVisibleFlows();
  const useLowDetail = state.zoom < 0.92 || visibleFlows.length > 10;
  const grouped = { music: [], film: [], food: [], fashion: [] };

  visibleFlows.forEach((flow) => {
    grouped[flow.category].push(flow);
  });

  Object.entries(grouped).forEach(([category, categoryFlows]) => {
    if (!categoryFlows.length) return;
    ctx.save();
    ctx.strokeStyle = categoryColors[category];
    ctx.globalAlpha = 0.5;
    ctx.lineWidth = 1.1;
    ctx.shadowColor = categoryColors[category];
    ctx.shadowBlur = 8;
    categoryFlows.forEach((flow) => drawFlowPath(flow, cx, cy, radius, useLowDetail));
    ctx.restore();
  });

  state.cityScreenPoints = drawCities(cx, cy, radius);
  drawPulseMarkers(visibleFlows, cx, cy, radius, useLowDetail);
  drawLabels();
}

function drawStarfield(width, height) {
  ctx.save();
  for (const star of stars) {
    const pulse = 0.25 + 0.75 * (0.5 + 0.5 * Math.sin(state.animationTime + star.twinkle));
    ctx.fillStyle = `rgba(200,220,255,${0.2 + pulse * 0.55})`;
    ctx.beginPath();
    ctx.arc(star.x * width, star.y * height, star.r * pulse, 0, Math.PI * 2);
    ctx.fill();
  }
  ctx.restore();
}

function drawAtmosphere(cx, cy, radius) {
  const grad = ctx.createRadialGradient(cx, cy, radius * 0.55, cx, cy, radius * 1.55);
  grad.addColorStop(0, "rgba(41,104,176,0.08)");
  grad.addColorStop(1, "rgba(20,66,130,0)");
  ctx.fillStyle = grad;
  ctx.beginPath();
  ctx.arc(cx, cy, radius * 1.45, 0, Math.PI * 2);
  ctx.fill();
}

function drawGlobeBody(cx, cy, radius) {
  const globeGradient = ctx.createRadialGradient(
    cx - radius * 0.45,
    cy - radius * 0.55,
    radius * 0.12,
    cx,
    cy,
    radius
  );
  globeGradient.addColorStop(0, "#172f56");
  globeGradient.addColorStop(1, "#08162e");
  ctx.fillStyle = globeGradient;
  ctx.beginPath();
  ctx.arc(cx, cy, radius, 0, Math.PI * 2);
  ctx.fill();

  ctx.strokeStyle = "rgba(108,170,255,0.24)";
  ctx.lineWidth = 1.2;
  ctx.beginPath();
  ctx.arc(cx, cy, radius, 0, Math.PI * 2);
  ctx.stroke();
}

function drawCities(cx, cy, radius) {
  const points = [];
  cities.forEach((city) => {
    const rotated = rotatePoint(latLonToXYZ(city.lat, city.lon));
    if (rotated.z < -0.2) return;

    const depth = 0.5 + (rotated.z + 1) * 0.5;
    const x = cx + rotated.x * radius;
    const y = cy - rotated.y * radius;
    const baseR = 2.2 + depth * 1.7;
    const isActive = city.id === state.selectedCity || city.id === state.hoveredCity?.id;
    const glowRadius = isActive ? baseR * 4.1 : baseR * 2.4;

    ctx.save();
    ctx.globalAlpha = 0.65 + depth * 0.3;
    ctx.fillStyle = isActive ? "#d9f2ff" : "#8ec8ff";
    ctx.shadowBlur = glowRadius;
    ctx.shadowColor = isActive ? "#95dbff" : "#4da4ff";
    ctx.beginPath();
    ctx.arc(x, y, isActive ? baseR + 1 : baseR, 0, Math.PI * 2);
    ctx.fill();
    ctx.restore();

    points.push({ ...city, x, y, depth, r: glowRadius * 0.35 });
  });
  return points;
}

function drawFlowPath(flow, cx, cy, radius, useLowDetail) {
  const path = useLowDetail ? flow.pathLow : flow.pathHigh;
  let started = false;

  for (const point of path) {
    const p = rotatePoint(point);
    if (p.z < -0.18) {
      started = false;
      continue;
    }

    const x = cx + p.x * radius;
    const y = cy - p.y * radius;
    if (!started) {
      ctx.beginPath();
      ctx.moveTo(x, y);
      started = true;
    } else {
      ctx.lineTo(x, y);
    }
  }

  if (started) {
    ctx.lineWidth = 0.7 + flow.intensity * 1.2;
    ctx.stroke();
  }
}

function drawPulseMarkers(visibleFlows, cx, cy, radius, useLowDetail) {
  visibleFlows.forEach((flow) => {
    const speed = (state.reducedMotion ? 0.06 : 0.15) * (0.7 + flow.intensity);
    const t = ((state.animationTime * speed + flow.phase) % 1 + 1) % 1;
    const path = useLowDetail ? flow.pathLow : flow.pathHigh;
    const idx = Math.floor(t * (path.length - 1));
    const p = rotatePoint(path[idx]);
    if (p.z < -0.14) return;
    const x = cx + p.x * radius;
    const y = cy - p.y * radius;
    const size = 1.7 + 2.6 * flow.intensity;

    ctx.save();
    ctx.globalAlpha = 0.82;
    ctx.fillStyle = categoryColors[flow.category];
    ctx.shadowBlur = 14;
    ctx.shadowColor = categoryColors[flow.category];
    ctx.beginPath();
    ctx.arc(x, y, size, 0, Math.PI * 2);
    ctx.fill();
    ctx.restore();
  });
}

function drawLabels() {
  const showAmbientLabels = state.zoom > 1.25;
  state.cityScreenPoints.forEach((city) => {
    if (city.id !== state.selectedCity && city.id !== state.hoveredCity?.id && !showAmbientLabels) return;

    ctx.font = `12px ${UI_FONT_STACK}`;
    ctx.fillStyle = city.id === state.selectedCity ? "#f2f7ff" : "#d8e8ff";
    ctx.textAlign = "left";
    ctx.textBaseline = "middle";
    ctx.fillText(city.name, city.x + 8, city.y - 8);
  });
}

function getVisibleFlows() {
  return flowPaths.filter((flow) => {
    if (!state.activeCategories.has(flow.category)) return false;
    if (state.cityFilter === "all") return true;
    return flow.from === state.cityFilter || flow.to === state.cityFilter;
  });
}

function pickCity(x, y) {
  let best = null;
  let bestD = 16;

  for (const city of state.cityScreenPoints) {
    const dx = x - city.x;
    const dy = y - city.y;
    const d = Math.sqrt(dx * dx + dy * dy);
    if (d < bestD) {
      best = city;
      bestD = d;
    }
  }
  return best;
}

function updateCityPanel() {
  if (!state.selectedCity || !cityMap.has(state.selectedCity)) {
    cityInfo.innerHTML = `
      <h2>City details</h2>
      <p>Select a city to view flow summary.</p>
    `;
    return;
  }

  const city = cityMap.get(state.selectedCity);
  const connected = flows.filter((flow) =>
    (flow.from === city.id || flow.to === city.id) && state.activeCategories.has(flow.category)
  );
  const outgoing = connected.filter((flow) => flow.from === city.id).length;
  const incoming = connected.filter((flow) => flow.to === city.id).length;
  const strongest = connected.reduce((max, flow) => {
    if (!max) return flow;
    return flow.intensity > max.intensity ? flow : max;
  }, null);
  const strongestFrom = strongest ? cityMap.get(strongest.from) : null;
  const strongestTo = strongest ? cityMap.get(strongest.to) : null;
  const strongestLabel =
    strongestFrom && strongestTo ? `${strongestFrom.name} → ${strongestTo.name}` : "None";

  cityInfo.innerHTML = `
    <h2>${city.name}</h2>
    <p>${city.region}</p>
    <p>Incoming flows: <strong>${incoming}</strong></p>
    <p>Outgoing flows: <strong>${outgoing}</strong></p>
    <p>Active categories: <strong>${new Set(connected.map((f) => f.category)).size}</strong></p>
    <p>Highest intensity route: <strong>${strongestLabel}</strong></p>
  `;
}

function showTooltip(clientX, clientY, html) {
  tooltip.innerHTML = html;
  tooltip.classList.remove("hidden");
  const bounds = canvas.getBoundingClientRect();
  const left = clientX - bounds.left;
  const top = clientY - bounds.top;
  tooltip.style.left = `${left}px`;
  tooltip.style.top = `${top}px`;
}

function hideTooltip() {
  tooltip.classList.add("hidden");
}

function buildArcPath(flow, segments) {
  const from = cityMap.get(flow.from);
  const to = cityMap.get(flow.to);
  const start = latLonToXYZ(from.lat, from.lon);
  const end = latLonToXYZ(to.lat, to.lon);
  const pts = [];

  for (let i = 0; i <= segments; i += 1) {
    const t = i / segments;
    const p = slerp(start, end, t);
    const elevation = 1 + Math.sin(Math.PI * t) * (0.13 + flow.intensity * 0.09);
    pts.push(scale(normalize(p), elevation));
  }
  return pts;
}

function latLonToXYZ(lat, lon) {
  const latR = (lat * Math.PI) / 180;
  const lonR = (lon * Math.PI) / 180;
  const cosLat = Math.cos(latR);
  return {
    x: cosLat * Math.sin(lonR),
    y: Math.sin(latR),
    z: cosLat * Math.cos(lonR),
  };
}

function rotatePoint(point) {
  const cosY = Math.cos(state.rotationY);
  const sinY = Math.sin(state.rotationY);
  const cosX = Math.cos(state.rotationX);
  const sinX = Math.sin(state.rotationX);

  const x1 = point.x * cosY + point.z * sinY;
  const z1 = -point.x * sinY + point.z * cosY;
  const y2 = point.y * cosX - z1 * sinX;
  const z2 = point.y * sinX + z1 * cosX;
  return { x: x1, y: y2, z: z2 };
}

function slerp(a, b, t) {
  const dotProduct = clamp(dot(a, b), -1, 1);
  const theta = Math.acos(dotProduct);
  if (theta < 0.0001) return { ...a };
  const sinTheta = Math.sin(theta);
  const w1 = Math.sin((1 - t) * theta) / sinTheta;
  const w2 = Math.sin(t * theta) / sinTheta;
  return {
    x: a.x * w1 + b.x * w2,
    y: a.y * w1 + b.y * w2,
    z: a.z * w1 + b.z * w2,
  };
}

function dot(a, b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

function normalize(v) {
  const len = Math.hypot(v.x, v.y, v.z) || 1;
  return { x: v.x / len, y: v.y / len, z: v.z / len };
}

function scale(v, factor) {
  return { x: v.x * factor, y: v.y * factor, z: v.z * factor };
}

function clamp(value, min, max) {
  return Math.max(min, Math.min(max, value));
}

function verifyContrast() {
  const styles = getComputedStyle(document.body);
  const bg = styles.getPropertyValue("--panel").trim() || "#0b1120";
  const fg = styles.getPropertyValue("--text").trim() || "#ebf2ff";
  const ratio = contrastRatio(bg, fg);
  if (ratio < 4.5) {
    console.warn(`Contrast ratio too low: ${ratio.toFixed(2)}:1`);
    document.body.classList.add("high-contrast");
  } else {
    document.body.classList.remove("high-contrast");
  }
}

function contrastRatio(colorA, colorB) {
  let lumA = 0;
  let lumB = 0;
  try {
    lumA = luminance(colorA);
    lumB = luminance(colorB);
  } catch (error) {
    console.warn(`Color contrast check failed: ${error.message}`);
  }
  const [light, dark] = lumA > lumB ? [lumA, lumB] : [lumB, lumA];
  return (light + 0.05) / (dark + 0.05);
}

function luminance(hex) {
  const normalized = hex.trim().replace("#", "");
  if (!/^[0-9a-fA-F]{6}$/.test(normalized)) {
    throw new Error(`Unsupported color format: ${hex}`);
  }
  const rawChannels = normalized.match(/.{2}/g);
  if (!rawChannels) {
    throw new Error(`Unable to parse color channels: ${hex}`);
  }
  const channels = rawChannels
    .map((c) => parseInt(c, 16) / 255)
    .map((v) => (v <= 0.03928 ? v / 12.92 : ((v + 0.055) / 1.055) ** 2.4));
  return channels[0] * 0.2126 + channels[1] * 0.7152 + channels[2] * 0.0722;
}

function setupThemeWatchers() {
  const observer = new MutationObserver(() => verifyContrast());
  observer.observe(document.body, {
    attributes: true,
    attributeFilter: ["class", "style"],
  });
  observer.observe(document.documentElement, {
    attributes: true,
    attributeFilter: ["style"],
  });
  window.matchMedia("(prefers-color-scheme: dark)").addEventListener("change", verifyContrast);
}
