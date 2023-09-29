#include <iostream>
using namespace std;
// функция для слияния двух подмассивов left и right в один отсортированный массив
void merge(double arr[], double left[], double right[], int leftSize, int rightSize) {
    int i = 0, j = 0, k = 0;
    // сравниваем элементы левого и правого подмассивов и добавляем их в основной массив
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    // добавляем оставшиеся элементы левого подмассива (если есть)
    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }
    // добавляем оставшиеся элементы правого подмассива (если есть)
    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}
// функция для сортировки массива слиянием
void mergeSort(double arr[], int size) {
    if (size < 2) {
        return; // массив уже отсортирован нечего делить
    }
    int middle = size / 2;
    // создаем левый и правый подмассивы
    double left[middle];
    double right[size - middle];
    // копируем элементы в левый и правый подмассивы
    for (int i = 0; i < middle; i++) {
        left[i] = arr[i];
    }
    for (int i = middle; i < size; i++) {
        right[i - middle] = arr[i];
    }
    // рекурсивно сортируем левый и правый подмассивы
    mergeSort(left, middle);
    mergeSort(right, size - middle);
    // слив отсортированныx подмассивов
    merge(arr, left, right, middle, size - middle);
}
class Application {
public:
    void run() {
        int size;
        cout << "Введите размер массива: ";
        cin >> size;
        double arr[size];
        cout << "Введите элементы массива: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
        mergeSort(arr, size);
        cout << "Отсортированный массив: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main(){
    Application application;
    application.run();
    return 0;
}