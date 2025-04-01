#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Robot
{
    unsigned deg {0};
    vector <double> koef;
    public:

    Robot();
    Robot(unsigned k);
    Robot(unsigned k, vector<double> mas);
    Robot(const Robot &ob);

    ~Robot()
    {   }


//set-методы


    void setRobot(unsigned k, const vector<double>& mas) {
        if (k<= mas.size()) {
            deg = k;
            koef.resize(k);
            koef.assign(mas.begin(), mas.begin() + k);

        } else {
            cerr << "Error: Degree exceeds coefficients count." << endl;
        }
    }

void setDegree(unsigned k) {deg = k;};


//get-методы


unsigned getDegree() const { return deg; };

const vector<double> getKoef() const { return koef;}

double CalculateValue(double x) const;

Robot operator+(const Robot& other) const;

const Robot& operator = (const Robot& other);

friend ostream& operator<<(ostream& mystream, const Robot &obj);
friend istream& operator>>(istream& mystream, Robot &obj);

};

#endif //ROBOT_H