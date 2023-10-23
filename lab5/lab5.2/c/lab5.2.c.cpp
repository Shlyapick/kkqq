#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int fibonacciClassic(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacciClassic(n - 1) + fibonacciClassic(n - 2);
    }
}

vector<int> c;

int fibonacciOptimized(int n) {
    if (n <= 1) {
        return n;
    }

    if (c[n] != -1) {
        return c[n];
    }

    c[n] = fibonacciOptimized(n - 1) + fibonacciOptimized(n - 2);
    return c[n];
}

class Application
{
public:
    void run(){
        int n;
        cin >> n;

        auto start = chrono::high_resolution_clock::now();
        int result1 = fibonacciClassic(n);
        auto end = chrono::high_resolution_clock::now();
        double duration1 = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1e6;

        c.resize(n + 1, -1);
        start = chrono::high_resolution_clock::now();
        int result2 = fibonacciOptimized(n);
        end = chrono::high_resolution_clock::now();
        double duration2 = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1e6;

        cout << "Число Фибоначчи для " << n << " (классический): " << result1 << ", время выполнения: " << (duration1) << endl;
        cout << "Число Фибоначчи для " << n << " (оптимизированный): " << result2 << ", время выполнения: " << (duration2) << endl;
    }


};

int main()
{
    Application application;
    application.run();
    return 0;
}
