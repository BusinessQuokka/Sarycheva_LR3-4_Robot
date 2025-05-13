#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <string>
#include <vector>
#include <numeric>  // Для std::accumulate
#include <algorithm> // Для std::sort, std::generate
#include <iomanip>   // Для std::setprecision
#include <random>    // Для генерации случайных чисел
#include <functional> //Для std::function

using namespace std;

class Robot {
private:
    string model;
    string functionality;
    vector<double> prices;
    unsigned int robot_id;
    static unsigned int next_robot_id;

public:
    // Constructors
    Robot();
    Robot(const string& model, const string& functionality, const vector<double>& prices);
    Robot(const Robot& other);
    Robot(unsigned int num_prices);
    Robot(const string& model_name);
    ~Robot();

    // Get methods
    string getModel() const;
    string getFunctionality() const;
    vector<double> getPrices() const;
    unsigned int getRobotId() const;

    // Set methods
    void setModel(const string& model);
    void setFunctionality(const string& functionality);
    void setPrices(const vector<double>& prices);

    // Method to calculate the average price
    double calculateAveragePrice() const;

    // Overloaded operators
    bool operator<(const Robot& other) const;
    Robot operator+(const Robot& other) const;
    Robot operator++(int);
    Robot& operator++();
    Robot& operator=(const Robot& other);

    friend ostream& operator<<(ostream& os, const Robot& robot);
    friend istream& operator>>(istream& is, Robot& robot);
};


#endif // _ROBOT_H