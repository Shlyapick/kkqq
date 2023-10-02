#include <iostream>
using namespace std;
class sieveErat
{
public:
    static void sieve(int n)
    {
        // Создаем массив булевых значений для хранения информации о простых числах
        bool prime[n + 1];
        for (int i = 0; i <= n; i++)
        {
            prime[i] = true;
        }
        for (int i = 2; i * i <= n; i++)
        {
            if (prime[i])
            {
                for (int j = i * i; j <= n; j += i)
                {
                    prime[j] = false;
                }
            }
        }
        cout << "Простые числа от 2 до " << n << " : ";
        for (int i = 2; i <= n; i++)
        {
            if (prime[i])
            {
                cout << i << " ";
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
        int n;
        cout << "Введите верхнюю границу для поиска простых чисел: ";
        cin >> n;
        sieveErat::sieve(n);
    }
};
int main()
{
    Application application;
    application.run();
    return 0;
}