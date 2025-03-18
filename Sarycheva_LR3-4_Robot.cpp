#include <ctime>
#include <C:\\Users\\pc\\OneDrive\\Documenti\\Sarycheva_LR3-4_Robot\\Sarycheva_LR3-3_Methods.h>

using namespace std;

int main()
{

//генерация начального случайного значения

srand(time(NULL));

// Создание меню с использованием std::map

map<int, MenuItem> menu = {

{1, {"Create Polynom Constructor default", createPolDefault}},

{2, {"Create Polynom Constructor with degree", createPolDeg}},

{3, {"Create Polynom Constructor with degree & coefficients", createPol DegCoeff}},

{4, {"Create Polynom with consol", createPolCons}},

{5, {"Show array of Polynom", showArrayPol (vectorOfAllPolynoms)}},

{6, {"Calculate value of Polynom", calcvalPol}},

{7, {"Add of Polynoms", addPolynoms}},

{8, {"Sum of array the Polynoms", sumArrPolynoms}},

};

unsigned choiсе = 0; // Переменная для хранения выбора пользователя

// Основной цикл программ

//while (true) {

cout << "Меню: " << endl;

// Вывод всех пунктов меню

for (const auto& item menu) {

cout << "Task " << item.first << "." << item.second.title << endl;
}
cout << "0. Выход" << endl; // Пункт для выхода из программы


    while (true) {

        EnterNumber (choice, "Введите номер пункта: ")();
        
        // Выход из программы, если выбран пункт 0
        
        if (choice == 0) {
        
        cout << "© 2025 FirstName LastName" << endl;
        
        break;
        }
        cout << endl <<"=========Action:=============" << endl;
        
        //cout << endl;
        
        // Проверка, существует ли выбранный пункт меню
        
        if (menu.find(choice) != menu.end()) {
        
        menu [choice].action(); // Выполнение действия, связанного с пунктом меню 
        } else {
        
        cout << "Некорректный ввод."; // Сообщение об ошибке, если пункт не найден
        
        }
        
        cout << endl; // отступ для красоты
        
        }
        
        return 0; // Завершение программы

}