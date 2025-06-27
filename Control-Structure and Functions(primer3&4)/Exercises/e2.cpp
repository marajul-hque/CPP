// 2. Write a short program that asks for your height in feet and inches and your weight
// in pounds. (Use three variables to store the information.) Have the program report
// your body mass index (BMI).To calculate the BMI, first convert your height in feet
// and inches to your height in inches (1 foot = 12 inches).Then convert your height
// in inches to your height in meters by multiplying by 0.0254.Then convert your
// weight in pounds into your mass in kilograms by dividing by 2.2. Finally, compute
// your BMI by dividing your mass in kilograms by the square of your height in
// meters. Use symbolic constants to represent the various conversion factors.

#include <iostream>
using namespace std;
const double INCHES_PER_FOOT = 12.0;

const double inchesToMeter = 0.0254;
const double poundTokg = 2.2;

int main()
{

    double heightfeet, heightInInches, weightInPound;
    cout << "enter your height in feet __\b\b";
    cin >> heightfeet;
    cout << "and inches__\b\b";
    cin >> heightInInches;
    cout << "and weight in pounds:__\b\b";
    cin >> weightInPound;

    double height = heightfeet * INCHES_PER_FOOT + heightInInches;
    double heightInMeter = height * inchesToMeter;
    double weightInKg = weightInPound / poundTokg;

    double BMI = weightInKg / (heightInMeter * heightInMeter);
    cout << "your BMI is : " << BMI << endl;

    return 0;
}