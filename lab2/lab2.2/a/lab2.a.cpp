#include <iostream>
using namespace std;
class pyrBuild
{
public:
    static void build(int height)
    {
        // Внешний цикл для уровней пирамиды
        for (int i = 1; i <= height; i++)
        {
            // Вложенный цикл для пробелов перед символами
            for (int j = 1; j <= height - i; j++)
            {
                cout << " ";
            }
            // Вложенный цикл для вывода символов пирамиды
            for (int k = 1; k <= 2 * i + 1; k++)
            {
                if (k == i + 1)
                {
                    cout << " ";
                }
                else
                {
                    cout << "#";
                }
            }

            // Переход на следующую строку после каждого уровня
            cout << endl;
        }
    }
};

class Application
{
public:
    void run()
    {
        int Pyramid_height;
        cout << "Введите высоту пирамиды: ";
        cin >> Pyramid_height;
        pyrBuild::build(Pyramid_height);
    }
};
int main()
{
    Application application;
    application.run();
    return 0;
}