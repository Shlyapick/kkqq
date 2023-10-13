#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stdexcept> // Для исключений
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

class IDException : public exception {
public:
    const char* what() const throw() {
        return "ID не может быть 00 или оканчиваться на 3";
    }
};

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

                if (dataPair[count].id == 0 || dataPair[count].id % 10 == 3) {
                    throw IDException(); 
                }

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

        this->count = count; 
    }

    const datPair* getDataPairs() const {
        return dataPair;
    }

    int getCount() const {
        return count;
    }

private:
    datPair dataPair[maxNumbers];
    int count;
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
        try {
            process.processDat(input);
            const datPair* data = process.getDataPairs();
            int count = process.getCount();
            
            cout << "Показания с датчиков: " << endl;
            for (int i = 0; i < count; i++) {
                cout << data[i].id << " ";
                cout << fixed << setprecision(1) << data[i].temperature << " ";
                cout << endl;
            }
        } catch (const IDException& err) {
            cerr << "Ошибка: " << err.what() << endl;
        }
    }
};

int main()
{
    Application application;
    application.run();
    return 0;
}
