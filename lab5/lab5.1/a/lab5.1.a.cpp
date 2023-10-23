#include <iostream>
#include <list>
#include <algorithm>
#include <sstream>

using namespace std;

list<list<int>> perms(const list<int>& input) {
    list<list<int>> result;
    list<int> current(input);

    do {
        result.push_back(current);
    } while (next_permutation(current.begin(), current.end()));

    return result;
}

class Application {
public:
    void run() {
        list<int> input;
        string inputStr;

        cout << "введите числа: ";
        getline(cin, inputStr);

        istringstream inputS(inputStr);
        int num;

        while (inputS >> num) {
            input.push_back(num);
        }

        list<list<int>> permutations = perms(input);

        for (const list<int>& perm : permutations) {
            for (int num : perm) {
                cout << num << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Application application;
    application.run();
    return 0;
}
