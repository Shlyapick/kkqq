#include <iostream>
#include <cmath> // для извлечения модуля
using namespace std;
double sqRoot(double a, double eps = 1e-12)
{
    if (a < 0)
    {
        cout << "Введено отрицательное число, извлечение корня невозможно" << endl;
        exit(1);
    }
    else
    {
        double gs = a / 2.0;
        while (fabs(gs * gs - a) > eps)
        {
            gs = 0.5 * (gs + a / gs);
        }
        return gs;
    }
}
class Application
{
public:
    void run()
    {
        double num;
        cout << "Введите число для извлечения корня: " << endl;
        cin >> num;
        double sqr = sqRoot(num);
        cout << "Квадратный корень из числа " << num << " = " << sqr << endl;
    }
};
int main()
{
    Application application;
    application.run();
    return 0;
}