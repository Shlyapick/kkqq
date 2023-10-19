#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int maxArea(const list<int>& height) {
    list<int>::const_iterator left = height.begin();
    list<int>::const_iterator right = prev(height.end()); 
    int maxVol = 0;

    while (left != right) {// вычисление объема осуществляется с концов, указатели равномерно сближаются в центре списка
        int h = min(*left, *right);
        int w = distance(left, right);
        int vol = h * w;
        maxVol = max(maxVol, vol);

        if (*left < *right) {
            ++left;
        } else {
            --right;
        }
    }

    return maxVol;
}

class Application
{
public:
    void run(){
        cout << "Введите высоты столбцов через пробел (0 для завершения ввода): ";
        list<int> height;
        int num;

        while (cin >> num && num != 0) {
            height.push_back(num);
        }

        int maxWater = maxArea(height);
        cout << "Максимальный объем жидкости: " << maxWater << endl;

    }
};

int main()
{
    Application application;
    application.run();
    return 0;
}