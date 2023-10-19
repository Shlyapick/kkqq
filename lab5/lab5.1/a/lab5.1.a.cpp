#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

list<list<int>> perms(const list<int>& input) { // объявление списка списков
    list<list<int>> result;
    list<int> current(input); //  входной список в текущий список 

    do {
        result.push_back(current); // сохранение результата перестановки 
    } while (next_permutation(current.begin(), current.end())); // создание след. перестановки

    return result;
}

class Application
{
public:
    void run(){
        list<int> input;
        int num;

        cout << "Введите числа(нечисловой-окончание ввода): ";
        while (cin >> num) {
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

int main()
{
    Application application;
    application.run();
    return 0;
}

