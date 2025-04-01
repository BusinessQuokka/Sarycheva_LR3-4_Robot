#include "Sarycheva_LR3-4_Robot.h"
#include <numeric>
#include <cmath>


using namespace std;

Robot::Robot() : deg(0), koef({}) {}

Robot::Robot(unsigned k) : deg(k), koef(vector<double>(k, 0.0)) {}

Robot::Robot(unsigned k, vector<double> mas) : deg(k) {
    if (k <= mas.size()) {
        koef.resize(k);
        koef.assign(mas.begin(), mas.begin() + k);
    } else {
        cerr << "Error: Degree exceeds coefficients count." << endl;
    }
}

Robot::Robot(const Robot& ob) : deg(ob.deg), koef(ob.koef) {}

double Robot::CalculateValue(double x) const {
    double result = 0.0;
    for (int i = 0; i < deg; ++i) {
        result += koef[i] * pow(x, i);
    }
   // cout << "Value at x = " << x << ": " << result << endl; Закомментировано
    return result; // возвращаем результат
}

Robot Robot::operator+(const Robot& other) const {
    unsigned maxDeg = max(deg, other.deg);
    vector<double> resultKoef(maxDeg, 0.0);

    for (int i = 0; i < deg; ++i) {
        resultKoef[i] += koef[i];
    }

    for (int i = 0; i < other.deg; ++i) {
        resultKoef[i] += other.koef[i];
    }

    return Robot(maxDeg, resultKoef);
}

const Robot& Robot::operator=(const Robot& other) {
    if (this == &other) return *this;
    deg = other.deg;
    koef = other.koef;
    return *this;
}

ostream& operator<<(ostream& mystream, const Robot& obj) {
    mystream << "Degree: " << obj.deg << endl;
    mystream << "Coefficients: ";
    for (double k : obj.koef) {
        mystream << k << " ";
    }
    mystream << endl;
    return mystream;
}

istream& operator>>(istream& mystream, Robot& obj) {
    cout << "Enter degree: ";
    mystream >> obj.deg;
    obj.koef.resize(obj.deg);
    cout << "Enter coefficients: ";
    for (int i = 0; i < obj.deg; ++i) {
        mystream >> obj.koef[i];
    }
    return mystream;
}