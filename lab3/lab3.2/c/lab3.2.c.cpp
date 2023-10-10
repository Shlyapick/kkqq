#include <iostream>
#include <regex>
using namespace std;
class Application
{
public:
    string subStrRep(string input){
        string subStr;
        static const regex subStrRep("(.)\\1{2,}");
        subStr=regex_replace(input,subStrRep,"$1");
        return subStr;
    }
    void run()
    {
        string str;
        cout << "Введите символы: ";
        cin >> str;
        cout << "Исходное выражение: " << str << endl;
        cout << "Замененнное: " << subStrRep(str) << endl;
    }
};
int main()
{
    Application application;
    application.run();
    return 0;
}