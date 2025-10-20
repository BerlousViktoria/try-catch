#include <iostream>
#include <string>
#include <iomanip>
#include <cmath> 
#include <limits> 
#define NOMINMAX
#include <windows.h> 

using namespace std;

// додано вивід помилки окремим кіном (як вказано у прикладі)
void ShowErrorWindow(const string& message) {
    MessageBoxA(NULL, message.c_str(), "Помилка вводу", MB_ICONERROR | MB_OK);
}

class Car {
private:
    string Brand;
    string Model;
    int Year;
    double Price;
    bool IsAutomatic;
    string Color;
    int Mileage;

public:
    Car()
        : Brand(""), Model(""), Year(2000), Price(0.0), IsAutomatic(false), Color(""), Mileage(0) {
    }


    // --- вся перевірка помилок відбувається у функції виведення  ---
    void InputData() {
        bool correct_input = false;
        while (!correct_input) {
            try {
                cout << "\n=== Введення даних про автомобіль ===\n";
                cout << "Марка: ";
                cin >> Brand;
                cout << "Модель: ";
                cin >> Model;

                cout << "Рік випуску: ";
                if (!(cin >> Year)) {
                    throw string("Рік випуску має бути цілим числом.");
                }
                if (Year < 1900 || Year > 2025) {
                    throw string("Рік випуску має бути в межах 1900-2025.");
                }

                cout << "Ціна (USD): ";
                if (!(cin >> Price)) {
                    throw string("Ціна повинна бути додатнім цілим або дійсним числом.");
                }
                if (Price <= 0) {
                    throw string("Ціна повинна бути додатнім цілим або дійсним числом.");
                }

                cout << "Колір: ";
                cin >> Color;

                cout << "Пробіг (км): ";
                if (!(cin >> Mileage)) {
                    throw string("Пробіг має бути цілим числом.");
                }
                if (Mileage < 0) {
                    throw string("Пробіг не може бути від'ємним.");
                }

                cout << "Автоматична коробка (1 - так, 0 - ні): ";
                if (!(cin >> IsAutomatic)) {
                    throw string("Введіть 1 або 0.");
                }
                if (IsAutomatic != 0 && IsAutomatic != 1) {
                    throw string("Введіть 1 або 0 для автоматичної коробки.");
                }

                correct_input = true;
                cout << "Дані успішно введено!" << endl;

            }
            catch (string error) {
                ShowErrorWindow(error);

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
        }
    }


    double CalculateDepreciation() const {
        int age = 2025 - Year;
        if (age <= 0) return Price;

        double depreciationRate = 0.15;
        double currentValue = Price * pow(1 - depreciationRate, age);

        return currentValue > 0 ? currentValue : 0;
    }

    void DisplayInfo() const {
        cout << "\n=== Інформація про автомобіль ===\n";
        cout << "Марка: " << Brand << '\n';
        cout << "Модель: " << Model << '\n';
        cout << "Рік випуску: " << Year << '\n';
        cout << "Ціна: " << fixed << setprecision(2) << Price << " USD\n";
        cout << "Колір: " << Color << '\n';
        cout << "Пробіг: " << Mileage << " км\n";
        cout << "Автоматична коробка: " << (IsAutomatic ? "Так" : "Ні") << '\n';
        cout << "Поточна вартість (з урахуванням зносу): "
            << fixed << setprecision(2) << CalculateDepreciation() << " USD\n";
    }

    string getBrand() const { return Brand; }
    string getModel() const { return Model; }
    int getYear() const { return Year; }
    double getPrice() const { return Price; }
    bool isAutomatic() const { return IsAutomatic; }
    string getColor() const { return Color; }
    int getMileage() const { return Mileage; }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Car myCar;

    myCar.InputData();

    myCar.DisplayInfo();

    system("pause");
    return 0;
}