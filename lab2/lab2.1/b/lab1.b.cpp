#include <iostream>
#include <string>
using namespace std;
class infMonthDef
{
public:
    static void def(int num)
    {
        const string month[12]{"Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"};
        int dur[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        // Проверка на валидность номера месяца
        if (num < 1 || num > 12)
        {
            cout << "Неверный номер месяца. Введите число от 1 до 12." << endl;
            exit(1);
        }
        if (num != 2)
        {
            cout << "Месяц: " << month[num - 1] << ", "
                 << "количество дней в нем: " << dur[num - 1];
        }
        else
        {
            cout << "Месяц: " << month[num - 1] << ", "
                 << "количество дней в нем: " << dur[num - 1] << ", если год високосный: " << dur[num - 1] + 1;
        }
        cout << endl;
    }
};
class Application
{
public:
    void run()
    {
        int num;
        cout << "Введите номер месяца: " << endl;
        cin >> num;
        infMonthDef::def(num);
    }
};
int main()
{
    Application application;
    application.run();
    return 0;
}
