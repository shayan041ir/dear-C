//shayan rezayi
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
struct contacts
{
    string l_name, f_name;
    int phone = 0;
} tell;
int menu()    //for select
{

    int z;
    system("cls");
    cout << "********************" << endl;
    cout << "1)*Insert*"
         << "        **" << endl;
    cout << "2)*Search*"
         << "        **" << endl;
    cout << "3)*Delete*"
         << "        **" << endl;
    cout << "4)*Display*"
         << "       **" << endl;
    cout << "5)*exit*"
         << "          **" << endl;
    cout << "********************" << endl;
    cout << "Please Select:";
    cin >> z;
    return z;
}
void Search()    //for search
{
    ifstream file("file.txt");
    string search;
    cout << "Enter a f_name to search for: ";
    cin >> search;
    file >> tell.f_name;
    file >> tell.l_name;
    file >> tell.phone;
    while (!file.eof())
    {
        if (search == tell.f_name)
        {
            cout << tell.f_name << "\t" << tell.l_name << "\t" << tell.phone << '\n';
        }
        file >> tell.f_name;
        file >> tell.l_name;
        file >> tell.phone;
    }
    file.close();

    system("pause");
}
void Insert()    //for add
{
    system("cls");
    ofstream cf("file.txt", ios::app);
    cin.get();

    cout << "please enter f_name:";
    getline(cin, tell.f_name);
    cf << tell.f_name << endl;

    cout << "please enter l_name:";
    getline(cin, tell.l_name);
    cf << tell.l_name << endl;

    cout << "please enter phone:";
    cin >> tell.phone;
    cf << tell.phone << endl;
    cf.close();
    system("pause");
}
void Delete()    //for delete 
{
    //importent
    string name;
    cout << "enter the contact name for delete:";
    cin>>name;
    cin.get();

    ifstream file("file.txt");
    ofstream file2("file2.txt");
    file >> tell.f_name;
    file >> tell.l_name;
    file >> tell.phone;
    while (!file.eof())
    {
        if (name != tell.f_name)
        {
            file2 << tell.f_name << endl;
            file2 << tell.l_name << endl;
            file2 << tell.phone << endl;
        }
        file >> tell.f_name;
        file >> tell.l_name;
        file >> tell.phone;
    }
    file.close();
    file2.close();
    remove("file.txt");
    rename("file2.txt", "file.txt");
    system("pause");
}
void Display()    //for show
{
    ifstream rf("file.txt");
    cout << left << setw(10) << "f_name" << setw(10) << "l_name" << setw(10) << "phone" << endl;
    cout << "*****************************" << endl;
    while (rf >> tell.f_name >> tell.l_name >> tell.phone)
    {
        cout << left << setw(10) << tell.f_name << setw(10) << tell.l_name << setw(10) << tell.phone << endl;
    }

    rf.close();
}
int main()
{
    int z;
    while (true)
    {
        z = menu();
        switch (z)
        {
        case 1:
            Insert();
            break;
        case 2:
            Search();
            break;
        case 3:
            Display();
            Delete();
            break;
        case 4:
            Display();
            system("pause");
            break;
        case 5:
            exit(0);
            break;

        default:
            cout << "enter the right number" << endl;
            system("pause");
            break;
        }
    }

    return 0;
}
//sh041
