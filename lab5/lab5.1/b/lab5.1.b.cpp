#include <iostream>
#include <list>
#include <algorithm>
#include <sstream>

using namespace std;

int maxProfit(const list<int>& prices) {
    if (prices.empty()) {
        return 0;
    }

    list<int>::const_iterator i = prices.begin(); //const-iterator-для работы со списком только для чтения
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

        cout << "введите цены на акции: ";
        string inputStr;
        getline(cin, inputStr);
        istringstream input(inputStr);
        while (input >> num) {
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