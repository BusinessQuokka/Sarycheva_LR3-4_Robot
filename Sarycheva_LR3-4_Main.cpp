#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
#include <map>
#include "Sarycheva_LR3-4_Robot.h"
#include "Sarycheva_LR3-4_Robot.cpp"
#include "Sarycheva_LR3-3_Methods.h"

using namespace std;



//Объявляем, что функции будут использоваться здесь.
extern vector<Robot> vectorOfAllRobots;
//Структура для описания пунктов меню, также должна быть доступна.
struct MenuItem;

//Сюда включаются объявления функций, связанных с меню
extern function<void()> EnterNumber(unsigned& varLink, string label);
extern function<void()> EnterString(string& varLink, string label);
extern void createRobDefault();
extern void createRobDeg();
extern void createRobCons();
extern void createRobDegCoeff();
extern function<void()> showArrayRob(vector<Robot>& v);
extern void calcValRob();
extern void addRobots();
extern void sumArrRobots();
extern vector<Robot> sortRobotsByAveragePrice(vector<Robot> robots);

using namespace std;

int main() {
    // Генерация начального случайного значения
    srand(time(nullptr));

    // Создание меню с использованием std::map
    map <int, MenuItem> menu = {
        {1, { "Create Robot Constructor default", createRobDefault }},
        {2, { "Create Robot Constructor  with degree", createRobDeg }},
        {3, { "Create Robot Constructor with degree & coefficients", createRobDegCoeff }},
        {4, { "Create Robot with consol", createRobCons }},
        {5, { "Show array of Robot", showArrayRob(vectorOfAllRobots) }},
        {6, { "Calculate value of Robot", calcValRob }},
        {7, { "Add of Robot", addRobots }},
        {8, { "Sum of array the Robot", sumArrRobots }},
        {9, { "Sort Robots by Average Price and display", [&]() { // Лямбда-функция для сортировки и вывода
                vector<Robot> sortedRobots = sortRobotsByAveragePrice(vectorOfAllRobots);
                showArrayRob(sortedRobots)();
        }}},
    };

    unsigned choice = 0; // Переменная для хранения выбора пользователя

    // Основной цикл программы
    while (true) {
        cout << "Меню:" << endl;

        // Вывод всех пунктов меню
        for (const auto& item : menu) {
            cout << "Task " << item.first << ". " << item.second.title << endl;
        }
        cout << "0. Выход" << endl; // Пункт для выхода из программы

        while (true) {
            EnterNumber(choice, "Введите номер пункта: ")();

            // Выход из программы, если выбран пункт 0
            if (choice == 0) {
                cout << "© 2025 FirstName LastName" << endl;
                break;
            }
            cout << endl << "=========Action:============" << endl;

            // Проверка, существует ли выбранный пункт меню
            if (menu.find(choice) != menu.end()) {
                menu[choice].action(); // Выполнение действия, связанного с пунктом меню
            }
            else {
                cout << "Некорректный ввод." << endl; // Сообщение об ошибке, если пункт не найден
            }
            cout << endl; // Отступ для красоты
            break;
        }
        if (choice == 0) break;
    }
    return 0; // Завершение программы
}
