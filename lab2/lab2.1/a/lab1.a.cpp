#include <iostream>
#include <string>
using namespace std;
class ageDeclension
{
public:
    static void declension(int age)
    {
        const string dev[3]{"год", "лет", "года"};
        int last_num = age % 10;
        int last_2num = age % 100; // для обработки чисел и больше 100
        cout << "Возраст: " << age << " ";
        if (last_2num >= 11 && last_2num <= 14)
        {
            cout << dev[1];
        }
        else
        {
            switch (last_num)
            {
            case 1:
                cout << dev[0];
                break;
            case 2:
            case 3:
            case 4:
                cout << dev[2];
                break;
            default:
                cout << dev[1];
            }
        }
        cout << endl;
    }
};
class Application
{
public:
    void run()
    {
        int age;
        cout << "Введите возраст: ";
        cin >> age;
        ageDeclension::declension(age);
    }
};
int main()
{
    Application application;
    application.run();
    return 0;
}
