#include <iostream>
#include <vector>
using namespace std;
class Application {
public:
    void run() {
        int n;
        cout << "Введите верхнюю границу для поиска простых чисел: ";
        cin >> n;
        vector<bool> prime(n + 1, true);
        for (int i = 2; i <= n; i++) {
            if (prime[i]) {
                for (int j = 2 * i; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }
        cout << "Простые числа от 2 до " << n << ": ";
        for (int i = 2; i <= n; i++) {
            if (prime[i]) {
                cout << i << " ";
            }
        }
        cout << endl;
    
    }
};
int main(){
    Application application;
    application.run();
    return 0;
}