#include <iostream>
#include <conio.h>
using namespace std;
class complex
{
public:
    void input();
    int getr() { return a; }
    int geti() { return b; }
    friend complex sum(complex, complex);
    friend complex sub(complex, complex);
    friend complex multi(complex, complex);
private:
    int a; // real
    int b; // imaginary
};
void complex::input()
{

    cout << "please enter a:";
    cin >> a;
    cout << "please enter b:";
    cin >> b;
}
int menu()
{
    int z;
    system("cls");
    cout << "1)addition and sum" << endl;
    cout << "2)subtraction" << endl;
    cout << "3)multiplication" << endl;
    cout << "4)Exit" << endl;
    cout << "-------------------------------" << endl;
    cout << "please select:";
    cin >> z;
    return z;
}
int main()
{
    complex ob1, ob2, ob3;
    int z;
    while (true)
    {
        z = menu();
        switch (z)
        {
        case 1:
            system("cls");
            cout << "please enter ob1:" << endl;
            ob1.input();
            cout << "please enter ob2:" << endl;
            ob2.input();
            ob3 = sum(ob1, ob2);
            cout << "ob3:" << endl;
            cout << "result is: " << ob3.getr() << "+" << ob3.geti() << "i\n";
            system("pause");
            break;
        case 2:
            system("cls");
            cout << "please enter ob1:" << endl;
            ob1.input();
            cout << "please enter ob2:" << endl;
            ob2.input();
            ob3 = sub(ob1, ob2);
            cout << "ob3:" << endl;
            cout << "result is: " << ob3.getr() << "+" << ob3.geti() << "i\n";
            system("pause");
            break;
        case 3:
            system("cls");
            cout << "please enter ob1:" << endl;
            ob1.input();
            cout << "please enter ob2:" << endl;
            ob2.input();
            ob3 = multi(ob1, ob2);
            cout << "ob3:" << endl;
            cout << "result is: " << ob3.getr() << "+" << ob3.geti() << "i\n";
            system("pause");
            
            break;
        case 4:
            exit(0);
            break;

        default:
            cout << "Error...............";
            system("pause");
            break;
        }
    }

    return 0;
}
//------------------------------------------
complex sum(complex ob1, complex ob2)
{
    complex ob3;

    ob3.a = ob1.a + ob2.a;
    ob3.b = ob1.b + ob2.b;

    return ob3;
}
//------------------------------------------
complex sub(complex ob1, complex ob2)
{
    complex ob3;

    ob3.a = ob1.a - ob2.a;
    ob3.b = ob1.b - ob2.b;

    return ob3;
}
complex multi(complex ob1, complex ob2)
{
    complex ob3;

    ob3.a = (ob1.a*ob2.a)-(ob1.b*ob2.b);
    ob3.b = (ob1.a*ob2.b)+(ob1.b*ob2.a);

    return ob3;
}