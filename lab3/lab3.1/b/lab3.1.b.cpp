#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double shannonEntr(const string &text)
{
    int len = text.length();
    int freq[256] = {0};
    for (unsigned char a : text)
    {
        freq[static_cast<unsigned char>(a)]++;
    }
    double entropy = 0.0;
    for (int freqCount : freq)
    {
        if (freqCount > 0)
        {
            double prob = static_cast<double>(freqCount) / len;
            entropy -= prob * log2(prob);
        }
    }
    return entropy;
}
class Application
{
public:
    void run()
    {
        string text;
        cout << "Введите строку: ";
        cin >> text;
        double entropy = shannonEntr(text);
        cout << "Энтропия по Шеннону = " << fixed << setprecision(2) << entropy << endl;
    }
};
int main()
{
    Application application;
    application.run();
    return 0;
}