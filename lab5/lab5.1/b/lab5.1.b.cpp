#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int maxProfit(const list<int>& prices) {
    if (prices.empty()) {
        return 0;
    }

    list<int>::const_iterator i = prices.begin();
    int minPrice = *i;
    int maxProfit = 0;

    for (++i; i != prices.end(); ++i) {
        if (*i < minPrice) {
            minPrice = *i; 
        } else {
            int currentProfit = *i - minPrice;
            maxProfit = max(maxProfit, currentProfit);
        }
    }

    return maxProfit;
}

class Application
{
public:
    void run(){
        list<int> prices;
        int num;

        cout << "Введите цены на акции (0 для завершения ввода): ";
        while (cin >> num) {
            if (num == 0) {
                break; 
            }
            prices.push_back(num);
        }

        int profit = maxProfit(prices);
        cout << "Максимальная выгода: " << profit << endl;
    }
};

int main()
{
    Application application;
    application.run();
    return 0;
}