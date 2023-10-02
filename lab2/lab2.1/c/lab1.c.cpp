#include <iostream>
using namespace std;
class playCheck
{
public:
    static void check(int day, int temptre, int prec, int wind, int wet)
    {
        if (day < 1 || day > 7 || temptre < 1 || temptre > 3 || prec < 1 || prec > 5 || wind < 1 || wind > 2 || wet < 1 || wet > 2)
        {
            cout << "Введены некорректные данные." << endl;
            exit(1);
        }
        else
        {
            bool playBadmtn = false;
            if (day >= 6 && temptre <= 2 && prec <= 2 && wind == 2 && wet == 2)
            {
                playBadmtn = true;
            }
            if (playBadmtn)
            {
                cout << "Да" << endl;
            }
            else
            {
                cout << "Нет" << endl;
            }
        }
    }
};
class Application
{
public:
    void run()
    {
        int day, temptre, prec, wind, wet;
        cout << "Пойдете ли вы играть в бадминтон? Введите параметры: " << endl;
        cout << "День недели(число от 1 до 7, номер дня недели соответственно): " << endl;
        cin >> day;
        cout << "Температура (1-жарко,2-тепло,3-холодно): " << endl;
        cin >> temptre;
        cout << "Осадки(1-ясно,2-облачно,3-дождь,4-снег,5-град): " << endl;
        cin >> prec;
        cout << "Ветер(1-есть,2-нет): " << endl;
        cin >> wind;
        cout << "Влажность (1-высокая,2-низкая): " << endl;
        cin >> wet;
        playCheck::check(day, temptre, prec, wind, wet);
    }
};
int main()
{
    Application application;
    application.run();
    return 0;
}
