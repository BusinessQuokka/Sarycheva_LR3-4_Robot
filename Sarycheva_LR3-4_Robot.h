#ifndef _ROBOT_H
#define _ROBOT_H

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

void CalculateValue(double x); 

Robot operator+(const Robot& other) const;

const Robot& operator = (const Polynom& other)

{

if (&other == this) return *this;
deg = other.deg;
koef = other.koef;
return *this;

}

friend ostream& operator<<(ostream& mystream, const Robot &obj);
friend istream& operator>>(istream& mystream, Robot &obj);

};

endif //_ROBOT_H