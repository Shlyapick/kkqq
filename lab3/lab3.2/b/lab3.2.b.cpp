#include <iostream>
#include <regex>
#include <string>
using namespace std;
class Application
{
public:
    bool ipv6Val(string input){
        static const regex ipv6Val("^([0-9a-f]{1,4}:){7}[0-9a-f]{1,4}$");
        return regex_match(input, ipv6Val);
    }
    void run()
    {
        string inpIpv6;
        cout << "Введите адрес IPv6 в полной форме: ";
        cin >> inpIpv6;

        if (ipv6Val(inpIpv6))
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