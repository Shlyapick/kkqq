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

class StringLengthException : public exception {
private:
    string message;
public:
    StringLengthException(int length) {
        if (length < 3) {
            message = "В одной или более пар данных отсутсвует значение температуры";
        } else {
            message = "В одной или более пар данных некорректное значение температуры(слишком длинное число)";
        }
    }

    const char* what() const throw() {
        return message.c_str();
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
            if (fSort.length() < 3 || fSort.length() > 5)
            {
                throw StringLengthException(fSort.length());
            }
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
        } catch (const StringLengthException& err) {
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
