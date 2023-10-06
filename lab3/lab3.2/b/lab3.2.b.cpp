#include <iostream>
#include <regex>
#include <string>
using namespace std;
class Application
{
public:
    void run()
    {
        string inpIpv6;
        cout << "Введите адрес IPv6 в полной форме: ";
        cin >> inpIpv6;

        regex ipv6Reg("^([0-9a-f]{1,4}:){7}[0-9a-f]{1,4}$");

        if (regex_match(inpIpv6, ipv6Reg))
        {
            cout << "Данная строка является адресом IPv6." << endl;
        }
        else
        {
            cout << "Данная строка НЕ является адресом IPv6." << endl;
        }
    }
};
int main()
{
    Application application;
    application.run();
    return 0;
}