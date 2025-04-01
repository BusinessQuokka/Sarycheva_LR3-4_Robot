#ifndef SARYCHEVA_LR3_3_METHODS_H
#define SARYCHEVA_LR3_3_METHODS_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits> 
#include <functional>
#include "Sarycheva_LR3-4_Robot.h"

using namespace std;

namespace RobotMethods {

    // Глобальный вектор объектов Robot
    extern vector<Robot> vectorOfAllRobots;

    // Структура для пунктов меню
    struct MenuItem {
        string title;
        function<void()> action;
    };

    // Проверка корректности ввода числа
    bool isValidNumber(const string& str) {
        stringstream ss(str);
        double num;
        ss >> num;
        return !ss.fail() && ss.eof();
    }

    // Ввод числа с контролем корректности
    template <typename T>
    T EnterNumber(T& variable, const string& prompt) {
        string input;
        while (true) {
            cout << prompt;
            getline(cin, input);
            if (isValidNumber(input)) {
                stringstream ss(input);
                if (ss >> variable) {
                    return variable;
                }
            }
            cout << "Ошибка: некорректный ввод. Пожалуйста, введите число." << endl;
        }
    }

    // Создание Robot по умолчанию
    void createPolDefault() {
        Robot pol;
        vectorOfAllRobots.push_back(pol);
        cout << "Robot по умолчанию создан." << endl;
    }

    // Создание Robot с указанием степени
    void createPolDeg() {
        unsigned k = 0;
        EnterNumber(k, "Введите степень Robot: ");
        Robot pol(k);
        vectorOfAllRobots.push_back(pol);
        cout << "Robot со степенью " << k << " создан." << endl;
    }

    // Создание Robot с указанием степени и коэффициентов
    void createPolDegCoeff() {
        unsigned k = 0;
        EnterNumber(k, "Введите степень Robot: ");
        vector<double> coeffs(k);
        cout << "Введите коэффициенты: ";
        for (int i = 0; i < k; ++i) {
            EnterNumber(coeffs[i], "");
        }
        Robot pol(k, coeffs);
        vectorOfAllRobots.push_back(pol);
        cout << "Robot со степенью " << k << " и коэффициентами создан." << endl;
    }

    // Создание Robot с вводом с консоли
    void createPolCons() {
        Robot pol;
        cin >> pol;
        vectorOfAllRobots.push_back(pol);
        cout << "Robot создан с вводом с консоли." << endl;
    }

    // Вывод массива Robot
    void showArrayPol(const vector<Robot>& robots) {
        if (robots.empty()) {
            cout << "Массив Robot пуст." << endl;
            return;
        }
        cout << "Массив Robot:" << endl;
        for (size_t i = 0; i < robots.size(); ++i) {
            cout << "Robot [" << i << "]:" << endl << robots[i];
        }
    }

    // Вычисление значения Robot в точке x
    void calcvalPol() {
        if (vectorOfAllRobots.empty()) {
            cout << "Массив Robot пуст. Сначала создайте Robot." << endl;
            return;
        }
        double x = 0;
        EnterNumber(x, "Введите значение x: ");
        vectorOfAllRobots[0].CalculateValue(x); // Используем первый Robot
    }

    // Сложение Robot
    void addPolynoms() {
        if (vectorOfAllRobots.size() < 2) {
            cout << "Нужно как минимум два Robot для сложения." << endl;
            return;
        }
        Robot result = vectorOfAllRobots[0] + vectorOfAllRobots[1];
        vectorOfAllRobots.push_back(result);
        cout << "Robot сложены, результат добавлен в массив." << endl;
    }

    // Сумма массива Robot
    void sumArrPolynoms() {
        if (vectorOfAllRobots.empty()) {
            cout << "Массив Robot пуст." << endl;
            return;
        }
        Robot sum;
        for (const Robot& pol : vectorOfAllRobots) {
            sum = sum + pol;
        }
        cout << "Сумма всех Robot в массиве:\n" << sum << endl;
    }

} 

#endif