#include <iostream>
using namespace std;
class complex
{
private:
    int real, img;
public:
    complex(int r = 0, int i = 0)
    {
        real = r;
        img = i;
    }
    void input()
    {
        cout << "pls enter real\n";
        cin >> real;
        cout << "pls enter imaginere\n";
        cin >> img;
    }
    complex operator+(complex Aobj)
    {
        complex obj;
        obj.real = real + Aobj.real;
        obj.img = img + Aobj.img;
        return obj;
    }
    complex operator-(complex Aobj)
    {
        complex obj;
        obj.real = real - Aobj.real;
        obj.img = img - Aobj.img;
        return obj;
    }
    complex operator*(complex Aobj)
    {
        complex obj;
        obj.real = real * Aobj.real;
        obj.img = img * Aobj.img;
        return obj;
    }
    void show()
    {
        cout << "real: " << real << " " << "img: " << img << "i \n";
    }
};
int menu()
{
    int num;
    cout << "1)sum\n"
         << "2)sub\n"
         << "3)multi\n"
         << "4)exit\n"
         << "please select:\n";
    cin >> num;
    return num;
}
int main()
{
    system("cls");
    complex c1, c2;
    int n;
    while (true)
    {
        system("cls");
        n = menu();
        switch (n)
        {
        case 1:
            c1.input();
            c2.input();
            c1 = c1 + c2;
            c1.show();
            system("pause");
            break;
        case 2:
            c1.input();
            c2.input();
            c1 = c1 - c2;
            c1.show();
            system("pause");
            break;
        case 3:
            c1.input();
            c2.input();
            c1 = c1 * c2;
            c1.show();
            system("pause");
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "pls try again!!\n";
            break;
        }
    }
    return 0;
}