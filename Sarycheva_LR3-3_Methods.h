#ifndef SARYCHEVA_LR3_3_METHODS_H
#define SARYCHEVA_LR3_3_METHODS_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits> 
#include <functional>
#include <algorithm>
#include "Sarycheva_LR3-4_Robot.h"
#include "Sarycheva_LR3-4_Robot.cpp"

using namespace std;

//глобальный массив роботов
vector<Robot> vectorOfAllRobots;

//Функции, связанные с меню (создание, отображение, редактирование и т.д.)
// Структура для описания пункта меню
struct MenuItem {
    string title;            // Название пункта меню
    function<void()> action; // Действие, выполняемое при выборе пункта
};

//Вспомогательная функция для ввода целых чисел
function<void()> EnterNumber(unsigned& varLink, string label) {
    return[&varLink, label]() {
        string raw_input;
        cout << label << " = ";
        getline(cin, raw_input);

        while (!UserInput(raw_input)) {
            cout << label << " = ";
            getline(cin, raw_input);
        }
        varLink = stoi(raw_input);
    };
}

//вспомогательная функция для ввода строк
function<void()> EnterString(string& varLink, string label) {
    return[&varLink, label]() {
        cout << label << " = ";
        getline(cin, varLink);
    };
}

//функция проверки корректности вводимых данных
bool UserInput(string input) {
    //если строка пустая - ввод некорректен
    if (input.empty()) return false;
    //попытаться
    try {
        //преобразование введенного значения в тип int
        int number = stoi(input);
        if (number < 0) return false;
    }
    catch (...)//если возникла ошибка в блоке try
    {
        return false;
    }
    return true;
}

void createRobDefault() {
    Robot f, g;
    //добавление созданных объектов в глобальный массив
    vectorOfAllRobots.push_back(f);
    vectorOfAllRobots.push_back(g);
    //вывод созданных роботов
    cout << " f(x)= " << f << endl;
    cout << " g(x)= " << g << endl;
}

void createRobDeg() {
    unsigned deg;
    EnterNumber(deg, "Input number of prices for robot: ")();

    //использование конструктора преобразования
    Robot robot1{ deg };
    //добавление созданного объекта в глобальный массив
    vectorOfAllRobots.push_back(robot1);

    cout << endl << "robot1: " << endl;
    cout << robot1;
}
void createRobDegCoeff() {
    // Создание робота с заданными параметрами
    string model;
    string functionality;
    vector<double> prices;

    cout << "Введите модель робота: ";
    cin >> ws; // Очистка буфера
    getline(cin, model);

    cout << "Введите функциональность робота: ";
    getline(cin, functionality);

    int numPrices;
    cout << "Введите количество цен: ";
    cin >> numPrices;

    prices.resize(numPrices);
    cout << "Введите цены (через пробел): ";
    for (int i = 0; i < numPrices; ++i) {
        cin >> prices[i];
    }

    Robot robot(model, functionality, prices);
    vectorOfAllRobots.push_back(robot);

    cout << robot;
}

void createRobCons() {
    Robot f;
    //ввод робота с консоли
    cin >> f;
    //добавление созданного объекта в глобальный массив
    vectorOfAllRobots.push_back(f);
    //вывод созданного робота
    cout << " f(x)= ";
    cout << f;
}

function<void()> showArrayRob(vector<Robot>& v) {
    return[&v]() {
        if (v.size() > 0) {
            cout << "\n======= The list of Robots ========\n";
            for (auto it = v.begin(); it != v.end(); it++)
                cout << (it - v.begin()) << ") " << *it << endl;
            cout << "====================================\n";
        }
        else
            cerr << "Errror, list of Robots is empty\n";
    };
}

void calcValRob() {
    if (vectorOfAllRobots.size() > 0) {
        //вывод списка роботов
        cout << "\n======= The list of Robots ========\n";
        for (auto it = vectorOfAllRobots.begin(); it != vectorOfAllRobots.end(); it++)
            cout << (it - vectorOfAllRobots.begin()) << ") " << *it << endl;
        cout << "====================================\n";

        //ввод номера робота для вычислений
        unsigned number = 0;
        EnterNumber(number, "Input number of robot for calculation: ")();
        //try {
        //vectorOfAllRobots[number].CalculateValue(stod(st));
        cout << vectorOfAllRobots[number].calculateAveragePrice() << endl;
        //}
        //catch (...) {
        //cerr << "Errror, value x is not digit!\n";
        //}
    }
    else
        cerr << "Errror, list of Robots is empty\n";
}

void addRobots() {
    if (vectorOfAllRobots.size() > 0) {
        //вывод списка роботов
        cout << "\n======= The list of Robots ========\n";
        for (auto it = vectorOfAllRobots.begin(); it != vectorOfAllRobots.end(); it++)
            cout << (it - vectorOfAllRobots.begin()) << ") " << *it << endl;
        cout << "====================================\n";

        //ввод номера 1-го робота для сложения
        unsigned number1 = 0, number2 = 0;
        EnterNumber(number1, "Input number 1 robot for add: ")();
        EnterNumber(number2, "Input number 2 robot for add: ")();
        cout << "Result of addition Polynoms\n";
        Robot rez = vectorOfAllRobots[number1] + vectorOfAllRobots[number2];
        cout << rez;
        cout << endl;
        // демонстрация работы конструктора преобразования
        Robot rez1 = vectorOfAllRobots[number1] + "10";
        cout << rez1;
        cout << endl;
    }
    else
        cerr << "Errror, list of Robots is empty\n";
}

void sumArrRobots() {
    //ввод количества элементов массива роботов
    unsigned count = 0;
    EnterNumber(count, "Input number of robots in array: ")();
    vector<Robot> VectrRob;
    for (size_t i = 0; i < count; ++i) {
        Robot v; // Создаем объект с помощью конструктора по умолчанию
        VectrRob.push_back(v);
    }
    showArrayRob(VectrRob)();
    //вычисление суммы 3-х роботов
    //Robot sum(VectrRob[0]);
    //for (size_t i = 1; i < count; i++) sum = sum + VectrRob[i];
    //вывод робота - результата суммирования
    //cout << "Summa: " << sum << endl;
}

#endif // _METHODS_H
