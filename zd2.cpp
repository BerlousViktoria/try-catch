#include <iostream>
#include <string>
#include <iomanip>
#include <cmath> 
#include <limits> 
#define NOMINMAX
#include <windows.h> 

using namespace std;

// ������ ���� ������� ������� ���� (�� ������� � �������)
void ShowErrorWindow(const string& message) {
    MessageBoxA(NULL, message.c_str(), "������� �����", MB_ICONERROR | MB_OK);
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


    // --- ��� �������� ������� ���������� � ������� ���������  ---
    void InputData() {
        bool correct_input = false;
        while (!correct_input) {
            try {
                cout << "\n=== �������� ����� ��� ��������� ===\n";
                cout << "�����: ";
                cin >> Brand;
                cout << "������: ";
                cin >> Model;

                cout << "г� �������: ";
                if (!(cin >> Year)) {
                    throw string("г� ������� �� ���� ����� ������.");
                }
                if (Year < 1900 || Year > 2025) {
                    throw string("г� ������� �� ���� � ����� 1900-2025.");
                }

                cout << "ֳ�� (USD): ";
                if (!(cin >> Price)) {
                    throw string("ֳ�� ������� ���� ������� ����� ��� ������ ������.");
                }
                if (Price <= 0) {
                    throw string("ֳ�� ������� ���� ������� ����� ��� ������ ������.");
                }

                cout << "����: ";
                cin >> Color;

                cout << "����� (��): ";
                if (!(cin >> Mileage)) {
                    throw string("����� �� ���� ����� ������.");
                }
                if (Mileage < 0) {
                    throw string("����� �� ���� ���� ��'�����.");
                }

                cout << "����������� ������� (1 - ���, 0 - �): ";
                if (!(cin >> IsAutomatic)) {
                    throw string("������ 1 ��� 0.");
                }
                if (IsAutomatic != 0 && IsAutomatic != 1) {
                    throw string("������ 1 ��� 0 ��� ����������� �������.");
                }

                correct_input = true;
                cout << "��� ������ �������!" << endl;

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
        cout << "\n=== ���������� ��� ��������� ===\n";
        cout << "�����: " << Brand << '\n';
        cout << "������: " << Model << '\n';
        cout << "г� �������: " << Year << '\n';
        cout << "ֳ��: " << fixed << setprecision(2) << Price << " USD\n";
        cout << "����: " << Color << '\n';
        cout << "�����: " << Mileage << " ��\n";
        cout << "����������� �������: " << (IsAutomatic ? "���" : "ͳ") << '\n';
        cout << "������� ������� (� ����������� �����): "
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