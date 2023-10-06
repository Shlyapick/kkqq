#include <iostream>
#include <string>
using namespace std;
class subStrFind
{
public:
    static void find(string str, string subStr)
    {
        size_t fnd = str.find(subStr);
        int count = 0;
        while (fnd != string::npos)
        {
            count++;
            fnd = str.find(subStr, fnd + 1);
        }
        if (count > 0)
        {
            cout << "Подстрока '" << subStr << "' в строке '" << str << "'. Найдено вхождений: " << count << endl;
        }
        else
        {
            cout << "Подстроки не найдено" << endl;
        }
    }
};
class Application
{
public:
    void run()
    {
        string str;
        string subStr;
        cout << "Введите строку, в которой будет производиться поиск количества вхождений" << endl;
        cin >> str;
        cout << "Введите подстроку, количество вхождений которой необходимо определить" << endl;
        cin >> subStr;
        subStrFind::find(str, subStr);
    }
};
int main()
{
    Application application;
    application.run();
    return 0;
}