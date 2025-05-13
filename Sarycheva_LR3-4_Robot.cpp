#include "Sarycheva_LR3-4_Robot.h"
#include <iostream>
#include <string>
#include <vector>
#include <numeric>  // Для std::accumulate
#include <algorithm> // Для std::sort, std::generate
#include <iomanip>   // Для std::setprecision
#include <random>    // Для генерации случайных чисел
#include <functional> //Для std::function

// Инициализация статического члена
unsigned int Robot::next_robot_id = 0;

Robot::Robot() : model(""), functionality(""), robot_id(next_robot_id++) {}

Robot::Robot(const string& model, const string& functionality, const vector<double>& prices)
    : model(model), functionality(functionality), prices(prices), robot_id(next_robot_id++) {}

Robot::Robot(const Robot& other)
    : model(other.model), functionality(other.functionality), prices(other.prices), robot_id(next_robot_id++) {}

Robot::Robot(unsigned int num_prices) : Robot() {
    if (num_prices > 0) {
        prices.resize(num_prices);
        //Заполняем prices случайными значениями
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<> distrib(100.0, 1000.0); //диапазон цен
        for (size_t i = 0; i < num_prices; ++i) {
            prices[i] = distrib(gen);
        }
    }
}

Robot::Robot(const string& model_name) : Robot() {
    model = model_name;
}

Robot::~Robot() {}

string Robot::getModel() const { return model; }
string Robot::getFunctionality() const { return functionality; }
vector<double> Robot::getPrices() const { return prices; }
unsigned int Robot::getRobotId() const { return robot_id; }

void Robot::setModel(const string& model) { this->model = model; }
void Robot::setFunctionality(const string& functionality) { this->functionality = functionality; }
void Robot::setPrices(const vector<double>& prices) { this->prices = prices; }

double Robot::calculateAveragePrice() const {
    if (prices.empty()) {
        return 0.0; // Или другое значение, сигнализирующее об отсутствии цен
    }
    return accumulate(prices.begin(), prices.end(), 0.0) / prices.size();
}

bool Robot::operator<(const Robot& other) const {
    return calculateAveragePrice() < other.calculateAveragePrice();
}

Robot Robot::operator+(const Robot& other) const {
    Robot result;
    result.model = this->model + " + " + other.model;
    result.functionality = this->functionality + " + " + other.functionality;

    // Объединяем цены
    result.prices = this->prices;
    result.prices.insert(result.prices.end(), other.prices.begin(), other.prices.end());

    return result;
}

Robot Robot::operator++(int) {
    Robot temp = *this;
    prices.push_back(100.0); // добавляем новую цену (пример)
    return temp;
}

Robot& Robot::operator++() {
    prices.push_back(100.0); // добавляем новую цену (пример)
    return *this;
}

Robot& Robot::operator=(const Robot& other) {
    if (this != &other) { // Проверка на самоприсваивание
        model = other.model;
        functionality = other.functionality;
        prices = other.prices;
        robot_id = next_robot_id++; // присваиваем новый ID
    }
    return *this;
}

ostream& operator<<(ostream& os, const Robot& robot) {
    os << "Model: " << robot.model << endl;
    os << "Functionality: " << robot.functionality << endl;
    os << "Prices: ";
    for (double price : robot.prices) {
        os << fixed << setprecision(2) << price << " ";
    }
    os << endl;
    os << "Average Price: " << fixed << setprecision(2) << robot.calculateAveragePrice() << endl;
    os << "Robot ID: " << robot.robot_id << endl;
    return os;
}

istream& operator>>(istream& is, Robot& robot) {
    cout << "Enter model: ";
    is >> ws; // Очистка буфера
    getline(is, robot.model);

    cout << "Enter functionality: ";
    getline(is, robot.functionality);

    cout << "Enter number of prices: ";
    int numPrices;
    is >> numPrices;
    robot.prices.resize(numPrices);

    cout << "Enter prices (separated by spaces): ";
    for (int i = 0; i < numPrices; ++i) {
        is >> robot.prices[i];
    }
    return is;
}