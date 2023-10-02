#include <iostream>
using namespace std;
class medSearch
{
public:
    static void search(int n)
    {
        if (n < 0)
        {
            cout << "Введено неположительное число для размера массива" << endl;
            exit(1);
        }
        if (n == 0)
        {
            cout << "Массив пустой или было введено не число" << endl;
            exit(1);
        }
        double numbers[n];
        cout << "Введите числа которыми должен быть заполнен массив: ";
        for (int i = 0; i < n; i++)
        {
            cin >> numbers[i];
        }
        double med;
        if (n % 2 == 0)
        {
            med = (numbers[n / 2] + numbers[(n / 2) - 1]) / 2.0;
        }
        else
        {
            med = numbers[n / 2];
        }
        cout << "Медиана заданного набора чисел: " << med << endl;
    }
};
class Application
{
public:
    void run()
    {
        int n;
        cout << "Введите количество чисел в массиве: ";
        cin >> n;
        medSearch::search(n);
    }
};
int main()
{
    Application application;
    application.run();
    return 0;
}