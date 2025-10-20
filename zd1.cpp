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

class Valuta
{
private:
    string type;
    double selling;
    double buying;
public:
    Valuta(string tt, double by, double pr)
        : type(tt), buying(by), selling(pr) {
    }
    string getType() const {
        return type;
    }

    double getBuying() const {
        return buying;
    }

    double getSelling() const {
        return selling;
    }
    void setType(string newType) {
        type = newType;
    }
    void setBuying(double newBuying) {
        if (newBuying >= 0 && newBuying <= selling) {
            buying = newBuying;
        }
        else {
            cout << "�������: ������ ������� ���� ����'����� � ������ ��� ���������� ������� (" << selling << ")." << endl;
        }
    }
    void setSelling(double newSelling) {
        if (newSelling >= buying) {
            selling = newSelling;
        }
        else {
            cout << "�������: ������ �� ���� ������ ��� ���������� ����� (" << buying << ")." << endl;
        }
    }

    // ----- ���������� ��������� ������ ������� Input() ----
    //void Input()
    //{
    //    bool correct_input = false;
    //    while (!correct_input) {
    //        cout << "\n\n������ ��� ������ : ";
    //        cin >> type;
    //        cout << "������ ������ : ";
    //        cin >> buying;
    //        cout << "������ ������ : ";
    //        cin >> selling;
    //        if (selling < buying) {
    //            cout << "������ �� ���� ������ �� ������. �������� ����������� �����." << endl;
    //        }
    //        else if (selling < 0 || buying < 0) {
    //            cout << "�������� ������ ���� ��������. �������� ����������� �����." << endl;
    //        }
    //        else {
    //            correct_input = true;
    //        }
    //    }
    //}
    // ---- �� ��������� ������ �� ������������� �������� ������� -----

    void Input() {
        bool correct_input = false;
        while (!correct_input) {
            try {
                cout << "\n ������ ��� ������: ";
                cin >> type;
                cout << "������ ������: ";
                if (!(cin >> buying)) {
                    throw string("������������ ��� ��������! ������� ������ �������. ");
                }
                cout << "������ ������: ";
                if (!(cin >> selling)) {
                    throw string("������������ ��� ��������! ������� ������ �������. ");
                }
                if (selling < 0 || buying < 0) {
                    throw string("�������� ������ ���� ��������. �������� ����������� �����.");
                }
                if (selling < buying) {
                    throw string("������ �� ���� ������ �� ������. �������� ����������� �����.");
                }

                correct_input = true;
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

    void Output()
    {
        cout << "��� - " << type
            << ", ������ - " << buying
            << ", ������ - " << selling
            << ", ����� (������) - " << Diff() << endl;
    }

    double Diff()
    {
        return abs(selling - buying);
    }
};

class BankValuta : public Valuta
{
private:
    string bankName;

public:
    BankValuta(string tt, double by, double pr, string bn)
        : Valuta(tt, by, pr), bankName(bn) {
    }

    string getBankName() const {
        return bankName;
    }

    void setBankName(string newBankName) {
        bankName = newBankName;
    }

    void Output()
    {
        Valuta::Output();
        cout << "���� - " << bankName << endl;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //Valuta first("�����", 35.50, 41.20);
    //cout << "--- ���� Valuta ---" << endl;
    //first.Output();

    //cout << "\n--- ���� ������� ---" << endl;
    //first.setBuying(36.00);
    //first.setSelling(42.50);
    //first.setType("����");
    //first.Output();

    //cout << "\n--- ���� ������� ---" << endl;
    //cout << "������� ���� �������: " << first.getSelling() << endl;

    //cout << "\n--- ���� BankValuta ---" << endl;
    //BankValuta firstfirst("������", 9.50, 10.50, "����������");
    //firstfirst.Output();

    //firstfirst.setBankName("��������");
    //cout << "\n���� �����:" << endl;
    //firstfirst.Output();


    // -- �������� ������� --
    cout << "--- ���������� ������� ---" << endl;
    Valuta test("����", 0, 0);
    test.Input();
    cout << "-- ��������� --" << endl;
    test.Output();

    cout << endl << endl;
    system("pause");
}