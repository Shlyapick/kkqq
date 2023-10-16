#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class eCheck
{
public:
    int ifErr(string inFile)
    {
        ifstream file(inFile);
        if (!file.is_open())
        {
            cerr << "Ошибка открытия файла" << endl;
            return 1; // Возвращаем 1 в случае ошибки
        }
        return 0; // Возвращаем 0, если файл успешно открыт
    }
};

class Application
{
public:
    int run()
    {
        string fileName;
        cout << "Введите полное имя файла для чтения (name.txt):" << endl;
        cin >> fileName;

        if (fileName.empty())
        {
            cerr << "Имя файла не было введено" << endl;
            return 1;
        }

        eCheck filecheck;
        int result = filecheck.ifErr(fileName);

        if (result == 0)
        {
            ifstream file(fileName);
            char ch;
            while (file.get(ch))
            {
                cout << ch;
            }
            file.close();
        }

        return result; // Возвращаем 1 в случае ошибки, 0 если файл успешно прочитан
    }
};

int main()
{
    Application application;
    application.run();
}