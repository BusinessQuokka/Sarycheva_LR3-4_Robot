#include <ctime>
#include <iostream>
#include <ctime>
#include <map>
#include "Sarycheva_LR3-3_Methods.h"
#include "Sarycheva_LR3-4_Robot.h"
using namespace std;
using namespace RobotMethods;

// Объявление глобального вектора
vector<Robot> RobotMethods::vectorOfAllRobots;

int main() {
    // генерация начального случайного значения
    srand(time(NULL));

    // Создание меню с использованием std::map
    map<int, MenuItem> menu = {
        {1, {"Create Robot Constructor default", createPolDefault}},
        {2, {"Create Robot Constructor with degree", createPolDeg}},
        {3, {"Create Robot Constructor with degree & coefficients", createPolDegCoeff}},
        {4, {"Create Robot with consol", createPolCons}},
        {5, {"Show array of Robot",  []() { showArrayPol(vectorOfAllRobots); }}},
        {6, {"Calculate value of Robot", calcvalPol}},
        {7, {"Add of Robots", addPolynoms}},
        {8, {"Sum of array the Robots", sumArrPolynoms}}
    };

    unsigned choice = 0; // Переменная для хранения выбора пользователя

    // Основной цикл программы
    while (true) {
        cout << "Меню:" << endl;

        // Вывод всех пунктов меню
        for (const auto& item : menu) {
            cout << item.first << ". " << item.second.title << endl;
        }
        cout << "0. Выход" << endl; // Пункт для выхода из программы

        EnterNumber(choice, "Введите номер пункта: ");

        // Выход из программы, если выбран пункт 0
        if (choice == 0) {
            cout << "© 2025 FirstName LastName" << endl;
            break;
        }

        cout << endl << "=========Action:=============" << endl;

        // Проверка, существует ли выбранный пункт меню
        if (menu.find(choice) != menu.end()) {
            menu[choice].action(); // Выполнение действия, связанного с пунктом меню
        } else {
            cout << "Некорректный ввод." << endl; // Сообщение об ошибке, если пункт не найден
        }

        cout << endl; // отступ для красоты
    }

    return 0; // Завершение программы
}