#include <iostream>
#include <regex>
using namespace std;
class Application
{
public:
    void run()
    {
    string str;
    cout << "Введите символы: ";
    cin >> str;
    regex subStr3("(.)\\1{2,}");
    string result = regex_replace(str, subStr3, "$1");

    cout << "Исходное выражение: " << str << endl;
    cout << "Замененнное: " << result << endl;
}
};
int main(){
    Application application;
    application.run();
    return 0;
}