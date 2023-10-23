#include <iostream>
#include <stack>

using namespace std;

bool isValid(const string &s) {
    stack<char> brackets;
    for (char a : s) {
        switch (a) {
        case '[': brackets.push(']'); break;
        case '(': brackets.push(')'); break;
        case '{': brackets.push('}'); break;
        case ']':
        case ')':
        case '}':
            if (brackets.empty() || brackets.top() != a) {
                return false;
            }
            brackets.pop();
            break;
        default:
            break;
        }
    }
    return brackets.empty();
}

class Application
{
public:
    void run(){

    string input;
    
    cout << "введите строку: ";
    cin >> input;
    
    if (isValid(input)) {
        cout << "строка корректна" << endl;
    } else {
        cout << "строка не корректна " << endl;
    }
    
    }
};

int main()
{
    Application application;
    application.run();
    return 0;
}