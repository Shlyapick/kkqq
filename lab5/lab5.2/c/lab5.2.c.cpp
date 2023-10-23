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


int fibonacciOptimized(int n, vector<long long>& c) {
    if (n <= 1) {
        return n;
    }

    if (c[n] != -1) {
        return c[n];
    }

    c[n] = fibonacciOptimized(n - 1, c) + fibonacciOptimized(n - 2, c);
    return c[n];
}

class Application
{
public:
    void run(){
        int n;
        cin >> n;

        auto start1 = chrono::high_resolution_clock::now();
        int result1 = fibonacciClassic(n);
        auto end1 = chrono::high_resolution_clock::now();
        double duration1 = chrono::duration_cast<chrono::microseconds>(end1 - start1).count() / 1e6;

        vector<long long> c(n + 1, -1);
        auto start2 = chrono::high_resolution_clock::now();
        long long result2 = fibonacciOptimized(n, c);
        auto end2 = chrono::high_resolution_clock::now();
        double duration2 = chrono::duration_cast<chrono::microseconds>(end2 - start2).count() / 1e6;

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
