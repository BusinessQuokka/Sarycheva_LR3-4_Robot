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

using namespace std;


namespace RobotMethods {

    // Глобальный вектор объектов Robot
    extern std::vector<Robot> vectorOfAllRobots;

    // Структура для пунктов меню
    struct MenuItem {
        std::string title;
        std::function<void()> action;
    };

    // Вспомогательные функции
    unsigned min(unsigned n, unsigned m) {
        return (n < m) ? n : m;
    }
    unsigned max(unsigned n, unsigned m) {
        return (n > m) ? n : m;
    }

    // Функция проверки корректности вводимых данных (для целых чисел)
    bool isValidNumber(const std::string& str) {
        if (str.empty()) return false;
        try {
            int number = stoi(str);
            if (number < 0) return false;
        }
        catch (...) {
            return false;
        }
        return true;
    }

    // Ввод числа с контролем корректности
    template <typename T>
    std::function<void()> EnterNumber(T& varLink, const std::string& prompt) {
        return [&varLink, prompt]() {
            std::string raw_input;
            std::cout << prompt;
            std::getline(std::cin >> std::ws, raw_input);

            while (!isValidNumber(raw_input)) {
                std::cout << "Некорректный ввод. Пожалуйста, введите целое неотрицательное число: ";
                std::getline(std::cin >> std::ws, raw_input);
            }
            varLink = std::stoi(raw_input);
        };
    }

    // Ввод строки
    std::function<void()> EnterString(std::string& varLink, const std::string& prompt) {
        return [&varLink, prompt]() {
            std::cout << prompt;
            std::getline(std::cin >> std::ws, varLink);
        };
    }

    // Создание Robot по умолчанию
    void createRobDefault() {
        Robot rob;
        vectorOfAllRobots.push_back(rob);
        std::cout << "Robot по умолчанию создан." << std::endl;
    }

    // Создание Robot с указанием степени
    void createRobDeg() {
        unsigned deg = 0;
        EnterNumber(deg, "Введите степень Robot: ")();
        Robot rob(deg);
        vectorOfAllRobots.push_back(rob);
        std::cout << "Robot со степенью " << deg << " создан." << std::endl;
    }

    // Создание Robot с указанием степени и коэффициентов
    void createRobDegCoeff() {
        unsigned k = 0;
        EnterNumber(k, "Введите степень Robot: ")();
        std::vector<double> coeffs(k);
        std::cout << "Введите коэффициенты (через пробел): ";
        for (int i = 0; i < k; ++i) {
            double coeff;
            EnterNumber(coeff, "")();
            coeffs[i] = coeff;
        }
        Robot rob(k, coeffs);
        vectorOfAllRobots.push_back(rob);
        std::cout << "Robot со степенью " << k << " и коэффициентами создан." << std::endl;
    }

    // Создание Robot с вводом с консоли
    void createRobCons() {
        Robot rob;
        std::cout << "Введите данные Robot:" << std::endl;
        std::cin >> rob;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // очистка буфера
        vectorOfAllRobots.push_back(rob);
        std::cout << "Robot создан с вводом с консоли." << std::endl;
    }

    // Вывод массива Robot
    void showArrayRob(const std::vector<Robot>& robots) {
        if (robots.empty()) {
            std::cout << "Массив Robot пуст." << std::endl;
            return;
        }
        std::cout << "Массив Robot:" << std::endl;
        for (size_t i = 0; i < robots.size(); ++i) {
            std::cout << "Robot [" << i << "]:" << std::endl << robots[i];
        }
    }

    // Вычисление значения Robot в точке x
    void calcvalRob() {
        if (vectorOfAllRobots.empty()) {
            std::cout << "Массив Robot пуст. Сначала создайте Robot." << std::endl;
            return;
        }
        double x = 0;
        EnterNumber(x, "Введите значение x: ")();
        std::cout << "Результат вычисления: " << vectorOfAllRobots[0].CalculateValue(x) << std::endl; // Используем первый Robot
    }

    // Сложение Robot
    void addRobots() {
        if (vectorOfAllRobots.size() < 2) {
            std::cout << "Нужно как минимум два Robot для сложения." << std::endl;
            return;
        }

        cout << "\n======= The list of Robots ========\n";
        for (auto it = vectorOfAllRobots.begin(); it != vectorOfAllRobots.end(); it++)
            cout << (it - vectorOfAllRobots.begin()) << ") " << *it << endl;
        cout << "====================================\n";

        // ввод номера 1-го полинома для сложения
        unsigned number1 = 0, number2 = 0;
        EnterNumber(number1, "Введите номер 1-го Robot для сложения: ")();
        EnterNumber(number2, "Введите номер 2-го Robot для сложения: ")();

        if (number1 >= vectorOfAllRobots.size() || number2 >= vectorOfAllRobots.size()) {
            cout << "Ошибка: некорректные номера Robot." << endl;
            return;
        }

        cout << "Result of addition Robots\n";
        Robot rez = vectorOfAllRobots[number1] + vectorOfAllRobots[number2];
        cout << "Robot " << number1 << ": " << vectorOfAllRobots[number1] << endl;
        cout << "Robot " << number2 << ": " << vectorOfAllRobots[number2] << endl;
        cout << "Sum: " << rez;
        cout << endl;
    }

    // Сумма массива Robot
    void sumArrRobots() {
        //ввод количества элементов массива роботов
        unsigned count = 0;
        EnterNumber(count, "Введите количество Robot в массиве: ")();

        if (count == 0) {
            std::cout << "Массив Robot пуст." << std::endl;
            return;
        }

        std::vector<Robot> VectorRob(count);

           // Ввод первого робота до цикла
    unsigned degree;
    EnterNumber(degree, "Введите степень Robot 1: ");
    VectorRob[0].setDegree(degree);
 

    std::cout << "Введите коэффициенты (через пробел) для Robot 1: " << std::endl;
    for (int j = 0; j <= degree; ++j) {
        double num = 0;
        EnterNumber(num, "");

        // Проверка на корректность ввода
        if (std::cin.fail()) {
            std::cerr << "Ошибка ввода. Пожалуйста, введите число." << std::endl;
            std::cin.clear();  // Сброс флагов ошибки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка буфера ввода
            --j; // Повторить ввод для этого коэффициента
        } else {
            VectorRob[0].setKoefElement(j, num);
        }
    }

    for (int i = 1; i < count; i++) {
        EnterNumber(degree, "Введите степень Robot " + std::to_string(i + 1) + ": ");
        VectorRob[i].setDegree(degree);


        std::cout << "Введите коэффициенты для Robot " + std::to_string(i + 1) + ": " << std::endl;
        for (int j = 0; j <= degree; ++j) {
            double num = 0;
            EnterNumber(num, "");

            // Проверка на корректность ввода
            if (std::cin.fail()) {
                std::cerr << "Ошибка ввода. Пожалуйста, введите число." << std::endl;
                std::cin.clear();  // Сброс флагов ошибки
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка буфера ввода
                --j; // Повторить ввод для этого коэффициента
            } else {
                VectorRob[i].setKoefElement(j, num);
            }
        }
    }
                 

       showArrayRob(VectorRob);

        Robot sum = VectorRob[0];  // инициализируем сумму первым роботом
            for (int i = 1; i < count; i++) {
                sum = sum + VectorRob[i];
            }

        std::cout << "Summa: " << sum << std::endl;
    }

       std::vector<Robot> getSortedRobotsByPrice(std::vector<Robot> robots) {
        std::sort(robots.begin(), robots.end(), [](const Robot& a, const Robot& b) {
            return a.CalculateValue(1.0) < b.CalculateValue(1.0);
        });
        return robots;
    }
} 

#endif