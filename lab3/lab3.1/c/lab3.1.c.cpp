#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
using namespace std;

const int maxNumbers = 128; // Максимальное количество чисел в строке

struct datPair
{
    int id;
    double temperature;
};

bool compId(const datPair &a, const datPair &b)
{
    return a.id < b.id;
}

bool compTemperature(const datPair &a, const datPair &b)
{
    return a.temperature < b.temperature;
}

class sensDatProcess
{
public:
    void processDat(const string &input)
    {
        int len = input.length();
        if (len > 512)
        {
            cout << "Слишком много данных" << endl;
            exit(1);
        }

        int count = 0;
        stringstream ss(input);
        string fSort;

        while (getline(ss, fSort, '@'))
        {
            if (fSort.length() >= 2 && count < maxNumbers)
            {
                dataPair[count].id = (fSort[0] - '0') * 10 + (fSort[1] - '0');
                double cTemp = stod(fSort.substr(2));
                if (cTemp < -50.0 || cTemp > 50.0)
                {
                    cout << "Получено некорректное значение температуры" << endl;
                    exit(1);
                }
                dataPair[count].temperature = cTemp;
                count++;
            }
        }

        cout << "Выберите критерий сортировки данных(1-id,2-temperature): " << endl;
        int sortK;
        cin >> sortK;

        if (sortK == 1)
        {
            sort(dataPair, dataPair + count, compId);
        }
        else if (sortK == 2)
        {
            sort(dataPair, dataPair + count, compTemperature);
        }

        cout << "Показания с датчиков: " << endl;
        for (int i = 0; i < count; i++)
        {
            cout << dataPair[i].id << " ";
            cout << fixed << setprecision(1) << dataPair[i].temperature << " ";
            cout << endl;
        }
    }

private:
    datPair dataPair[maxNumbers];
};
class Application
{
public:
    void run()
    {
        string input;
        cout << "Введите показания с датчиков: ";
        getline(cin, input);

        sensDatProcess process;
        process.processDat(input);
    }
};
int main()
{
    Application application;
    application.run();
    return 0;
}
