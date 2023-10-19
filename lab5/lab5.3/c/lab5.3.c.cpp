#include <iostream>
#include <set>
#include <queue>

using namespace std;

class bracketValidator {
private:
bool AreMatchingBrackets(char open, char close) {
    return (open == '(' && close == ')') ||
            (open == '{' && close == '}') ||
            (open == '[' && close == ']');
}

public:
    bool isValid(const string& input) {
        set<char> openingBrackets = {'(', '{', '['};
        set<char> closingBrackets = {')', '}', ']'};
        queue<char> bracketQueue;

        for (char c : input) {
            if (openingBrackets.count(c) > 0) {
                bracketQueue.push(c);
            } else if (closingBrackets.count(c) > 0) {
                if (bracketQueue.empty()) {
                    // если очередь пуста - невалидная строка
                    return false;
                } else {
                    char openBracket = bracketQueue.front();
                    bracketQueue.pop();

                    if (!AreMatchingBrackets(openBracket, c)) {
                        // если закрывающая скобка не соответствует открывающей это невалидная строка
                        return false;
                    }
                }
            }
        }

        // очередь не пуста в конце- строка некорректна
        return bracketQueue.empty();
    }

};

class Application
{
public:
    void run(){
        bracketValidator validator;
        string input;
        cout << "Введите строку: ";
        cin >> input;

        if (validator.isValid(input)) {
            cout << "Входная строка валидна" << endl;
        } else {
            cout << "Входная строка не валидна" << endl;
        }

    }
};

int main()
{
    Application application;
    application.run();
    return 0;
}