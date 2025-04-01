#include "Sarycheva_LR3-4_Robot.h"
#include <numeric>
#include <cmath>
#include <limits>
#include <iomanip>
using namespace std;

//переопределение оператора вывода на консоль
ostream& operator<<(ostream& mystream, const Robot& obj)
{
    bool firstTerm = true; // Флаг для первого члена полинома

    for (size_t i = 0; i <= obj.deg; i++) {
        double coeff = obj.koef[i];

        // Пропускаем нулевые коэффициенты
        if (abs(coeff) < 1e-10) continue;

        // Выводим знак коэффициента
        if (!firstTerm) mystream << (coeff > 0 ? " + " : " - ");
        else {
            if (coeff < 0) mystream << "-";
            firstTerm = false;
        }

        // Выводим коэффициент (без знака)
        double absCoeff = abs(coeff);

        if (absCoeff != 1.0 || i == 0) { // Выводим 1 только если это не x^0
            mystream << fixed << setprecision(2) << absCoeff;
        }
        else if (absCoeff == 1 && i==0)
            mystream << "1";
        
        // Выводим переменную x и степень
        if (i < obj.deg) {
            mystream << "x";
            if (i > 0) mystream << "^" << i;
        }
    }

    // Если все коэффициенты нулевые
    if (firstTerm) mystream << "0";
    mystream << endl;
    return mystream;
}

//переопределение оператора ввода с консоли
istream& operator>>(istream& mystream, Robot& obj)
{
    string st;
    cout << "Enter Degree: ";
    getline(mystream, st);
    try {
        obj.deg = stoi(st);
        if (obj.deg < 0) {
            throw std::invalid_argument("Degree must be non-negative");
        }
    }
    catch (const std::invalid_argument& e) {
        cerr << "Invalid input for degree. Please enter a non-negative integer." << endl;
        mystream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return mystream; // Вернуться, чтобы избежать дальнейших ошибок
    }
    catch (const std::out_of_range& e) {
        cerr << "Degree is too large. Please enter a smaller number." << endl;
        mystream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return mystream;
    }

    obj.koef.resize(obj.deg + 1);
    cout << "Enter coefficients (separated by spaces): ";
    for (int i = 0; i <= obj.deg; ++i) {
        try {
            getline(mystream >> std::ws, st); 
            obj.koef[i] = stod(st);
        }
        catch (const std::invalid_argument& e) {
            cerr << "Invalid input for coefficient at index " << i << ". Please enter a number." << endl;
            obj.koef.clear();  
            return mystream;
        }
        catch (const std::out_of_range& e) {
            cerr << "Coefficient is too large/small at index " << i << ". Please enter a smaller number." << endl;
            obj.koef.clear(); 
            return mystream;
        }
    }
     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return mystream;
}