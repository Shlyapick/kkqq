#include <iostream>
#include <ctime>

using namespace std;

int fibonacciClassic(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacciClassic(n - 1) + fibonacciClassic(n - 2);
    }
}

int fibonacciOptimized(int n) {
    if (n <= 1) {
        return n;
    }

    int prev = 0;
    int current = 1;

    for (int i = 2; i <= n; i++) {
        int next = prev + current;
        prev = current;
        current = next;
    }

    return current;
}

class Application
{
public:
    void run(){
        int n;
        cin >> n;

        clock_t start = clock();
        int result1 = fibonacciClassic(n);
        clock_t end = clock();
        double duration1 = double(end - start) / CLOCKS_PER_SEC;

        start = clock();
        int result2 = fibonacciOptimized(n);
        end = clock();
        double duration2 = double(end - start) / CLOCKS_PER_SEC;

        cout << "Число Фибоначчи для " << n << " (классический): " << result1 << ", время выполнения: " << duration1 << " секунд" << endl;
        cout << "Число Фибоначчи для " << n << " (оптимизированный): " << result2 << ", время выполнения: " << duration2 << " секунд" << endl;

    }
};

int main()
{
    Application application;
    application.run();
    return 0;
}
