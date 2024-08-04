#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
class Account
{
public:
    void creat();
    void Display();
    void deposit();
    void withdraw();
    void delet();

private:
    int an; // Account Number
    string f_name;
    string l_name;
    int balance;
};
void Account::delet()
{
    int ant;
    cout << "please enter Account Number:";
    cin >> ant;

    ifstream r("Bank.txt");
    ofstream w("Bank2.txt");
    system("cls");

    while (r >> an >> f_name >> l_name >> balance)
    { // این دستور خواندن اطلاعات را تکرار می‌کند
        // شرط برعکس شده است: در صورت عدم برابری، اطلاعات باید نوشته شوند
        if (an != ant)
        {
            w << an << endl;
            w << f_name << endl;
            w << l_name << endl;
            w << balance << endl;
        }
    }

    w.close();
    r.close();

    remove("Bank.txt");
    rename("Bank2.txt", "Bank.txt");
    system("pause");
    cin.get();
}
void Account::creat()
{
    system("cls");
    ofstream w("Bank.txt", ios::app);
    an = rand();
    cout << "Account Number is:" << an << endl;
    w << an << endl;

    cin.get();
    cout << "please enter f_name:";
    getline(cin, f_name);
    w << f_name << endl;

    cout << "please enter l_name:";
    getline(cin, l_name);
    w << l_name << endl;
    cout << "please enter balance:";
    cin >> balance;
    if (balance < 0)
        balance = 0;
    w << balance << endl;

    w.close();
}
int menu()
{
    int n;
    system("cls");
    cout << "1)Creat Account" << endl;
    cout << "2)deposit Account" << endl;
    cout << "3)withdraw Account" << endl;
    cout << "4)Display Account" << endl;
    cout << "5)delete" << endl;
    cout << "6)Exit" << endl;
    cout << "-------------------------------------" << endl;
    cout << "please select:";
    cin >> n;
    return n;
}
void Account::Display()
{
    ifstream r("Bank.txt");
    system("cls");
    cout << left << setw(20) << "Account Number" << setw(20) << "first name" << setw(20) << "last name" << setw(20) << "balance" << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    r >> an;
    r >> f_name;
    r >> l_name;
    r >> balance;
    while (!r.eof()) // end of file
    {
        cout << left << setw(20) << an << setw(20) << f_name << setw(20) << l_name << setw(20) << balance << endl;
        r >> an;
        r >> f_name;
        r >> l_name;
        r >> balance;
    }
    system("pause");
    r.close();
}
void Account::deposit()
{
    int an_t, bc; // an_t=ac   bc = balance
    system("cls");
    cout << "please enter Account Number:";
    cin >> an_t;

    ifstream r("Bank.txt");
    ofstream w("Bank2.txt", ios::app);
    system("cls");

    r >> an;
    r >> f_name;
    r >> l_name;
    r >> balance;
    while (!r.eof())
    {
        if (an == an_t)
        {
            system("cls");
            cout << "please enter account amount :";
            cin >> bc;
            balance += bc;
        }

        w << an << endl;
        w << f_name << endl;
        w << l_name << endl;
        w << balance << endl;

        r >> an;
        r >> f_name;
        r >> l_name;
        r >> balance;
    }
    r.close();
    w.close();
    remove("Bank.txt");
    rename("Bank2.txt", "Bank.txt");

    system("pause");
    r.close();
}
void Account::withdraw()
{
    int an_t, bc;
    system("cls");
    cout << "please enter Account Number:";
    cin >> an_t;

    ifstream r("Bank.txt");
    ofstream w("Bank2.txt", ios::app);
    system("cls");

    r >> an;
    r >> f_name;
    r >> l_name;
    r >> balance;
    while (!r.eof())
    {
        if (an == an_t)
        {
            system("cls");
            cout << "please enter account amount :";
            cin >> bc;
            balance -= bc;
        }

        w << an << endl;
        w << f_name << endl;
        w << l_name << endl;
        w << balance << endl;

        r >> an;
        r >> f_name;
        r >> l_name;
        r >> balance;
    }
    r.close();
    w.close();
    remove("Bank.txt");
    rename("Bank2.txt", "Bank.txt");

    system("pause");
    r.close();
}
int main()
{
    int z;
    Account temp;
    while (true)
    {
        z = menu();
        switch (z)
        {
        case 1:
            temp.creat();
            break;
        case 2:
            temp.deposit();
            break;

        case 3:
            temp.withdraw();
            break;

        case 4:
            temp.Display();
            break;
        case 5:
            temp.delet();
            break;
        case 6:
            exit(0);

            break;

        default:
            cout << "invaild choose" << endl;
            system("pause");
            break;
        }
    }

    return 0;
}