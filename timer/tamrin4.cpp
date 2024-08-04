// shayan rezayi
#include <iostream>
#include <windows.h>
using namespace std;
class t
{
    int h, m, s; // h=saat m=dagige s=saniye
public:
    t(int = 0, int = 0, int = 0);
    void input();
    void sett(int, int, int);
    void output();
};
t::t(int hr, int mi, int sec)
{
    sett(hr, mi, sec);
}
void t::input()
{
    system("cls");
    cout << "pls enter time like h/m/s: \n";
    cin >> h >> m >> s;
    cout << "nice :) \n";
    system("pause");
}
void t::sett(int h, int m, int s)
{
    h = (h >= 0 && h < 24) ? h : 0;
    m = (m >= 0 && m < 60) ? m : 0;
    s = (s >= 0 && s < 60) ? s : 0;
}
void t::output()
{
    // dar inja zaman shuru mishe va ta vagri ke src code ra taghir nadadim 10 saniye mire
    for (int i = 0; i < 86400; i++)
    {
        system("cls");
        cout << "yor time is : \n";
        cout << ((h == 12 || h == 0) ? 12 : h % 12)
             << " : " << (m < 10 ? "0" : "") << m
             << " : " << (s < 10 ? "0" : "") << s
             << (h < 12 ? " am \n" : " pm\n");
        s++;
        Sleep(1000);
        if (s == 60)
        {
            s = 0;
            cout << ((h == 12 || h == 0) ? 12 : h % 12)
                 << " : " << (m < 10 ? "0" : "") << m
                 << " : " << (s < 10 ? "0" : "") << s
                 << (h < 12 ? " am \n" : " pm\n");
            m++;
            Sleep(1000);
        }
        if (m == 60)
        {
            m = 0;
            cout << ((h == 12 || h == 0) ? 12 : h % 12)
                 << " : " << (m < 10 ? "0" : "") << m
                 << " : " << (s < 10 ? "0" : "") << s
                 << (h < 12 ? " am \n" : " pm\n");
            h++;
            Sleep(1000);
        }
        if (h == 24)
        {
            h = 0;
            cout << ((h == 12 || h == 0) ? 12 : h % 12)
                 << " : " << (m < 10 ? "0" : "") << m
                 << " : " << (s < 10 ? "0" : "") << s
                 << (h < 12 ? " am \n" : " pm\n");
            Sleep(1000);
        }
    }
    system("pause");
}
int main()
{
    t a;
    a.input();
    a.output();
    return 0;
}
// 041