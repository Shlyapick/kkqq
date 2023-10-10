#include <iostream>
#include <regex>
using namespace std;
class Application
{
public:
    bool emailVal(string input){
        static const regex emailReg("^[A-Za-z0-9]+([.]?[A-Za-z0-9]+)*[A-Za-z0-9]+@[A-Za-z0-9]+\\.[A-Za-z]{2,4}$");
        return regex_match(input, emailReg);
    }
    void run()
    {
        string email;
        cout << "Введите адрес электронной почты: ";
        cin >> email;

        if (emailVal(email))
        {
            cout << "Данная строка является адресом электронной почты." << endl;
        }
        else
        {
            cout << "Данная строка НЕ является адресом электронной почты." << endl;
        }
    }
};
int main()
{
    Application application;
    application.run();
    return 0;
}