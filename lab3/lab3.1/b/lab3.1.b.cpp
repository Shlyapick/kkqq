#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double shannonEntr(const string &text)
{
    int len = text.length();
    int freq[256] = {0};
    for (char a : text)
    {
        freq[static_cast<unsigned char>(a)]++;
    }
    double e = 0.0;
    for (int freqCount : freq)
    {
        if (freqCount > 0)
        {
            double prob = static_cast<double>(freqCount) / len;
            e -= prob * log2(prob);
        }
    }
    return e;
}
class Application
{
public:
    void run()
    {
        string text;
        cout << "Введите строку: ";
        cin >> text;
        double e = shannonEntr(text);
        cout << "Энтропия по Шеннону = " << fixed << setprecision(2) << e << endl;
    }
};
int main()
{
    Application application;
    application.run();
    return 0;
}