#include <iostream>
#include <set>
#include <queue>

using namespace std;

// функция для удаления дубликатов из входного массива
void RemoveDuplicates(queue<int>& inputQueue, set<int>& uniqueSet) {
    queue<int> tempQueue; // создаем временную очередь для уникальных элементов
    while (!inputQueue.empty()) {
        int element = inputQueue.front();
        inputQueue.pop();
        if (uniqueSet.find(element) == uniqueSet.end()) {
            tempQueue.push(element);
            uniqueSet.insert(element);
        }
    }
    inputQueue = tempQueue; //заменяем входную очередь уникальными элементами
}

class Application
{
public:
    void run(){
        int n;
        cin >> n;

        queue<int> inputQueue;
        set<int> uniqueSet;

        for (int i = 0; i < n; i++) {
            int element;
            cin >> element;
            inputQueue.push(element);
        }

        //удаление дубликатов
        RemoveDuplicates(inputQueue, uniqueSet);

        //вывод уникальных элементов с пробелами
        while (!inputQueue.empty()) {
            int element = inputQueue.front();
            inputQueue.pop();
            cout << element << " ";
        }

    }
};

int main()
{
    Application application;
    application.run();
    return 0;
}
