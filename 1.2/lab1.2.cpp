#include <iostream>
#include <limits>//библиотека для получения максимальных и минимальных значений 
//типов данных 
class Application {
public:
    void run() {
    using namespace std;
    cout << "Тип данных: signed char. Минимальное значение: " << numeric_limits<signed char>::min() << ". Максимальное значение: " << numeric_limits<signed char>::max() << endl;
    cout << "Тип данных: unsigned char. Минимальное значение: " << numeric_limits<unsigned char>::min() << ". Максимальное значение: " << numeric_limits<unsigned char>::max() << endl;
    cout << "Тип данных: char. Минимальное значение: " << numeric_limits<char>::min() << ". Максимальное значение: " << numeric_limits<char>::max() << endl;
    cout << "Тип данных: short. Минимальное значение: " << numeric_limits<short>::min() << ". Максимальное значение: " << numeric_limits<short>::max() << endl;
    cout << "Тип данных: unsigned short. Минимальное значение: " << numeric_limits<unsigned short>::min() << ". Максимальное значение: " << numeric_limits<unsigned short>::max() << endl;
    cout << "Тип данных: int. Минимальное значение: " << numeric_limits<int>::min() << ". Максимальное значение: " << numeric_limits<int>::max() << endl;
    cout << "Тип данных: unsigned int. Минимальное значение: " << numeric_limits<unsigned int>::min() << ". Максимальное значение: " << numeric_limits<unsigned int>::max() << endl;
    cout << "Тип данных: long. Минимальное значение: " << numeric_limits<long>::min() << ". Максимальное значение: " << numeric_limits<long>::max() << endl;
    cout << "Тип данных: unsigned long. Минимальное значение: " << numeric_limits<unsigned long>::min() << ". Максимальное значение: " << numeric_limits<unsigned long>::max() << endl;
    cout << "Тип данных: long long. Минимальное значение: " << numeric_limits<long long>::min() << ". Максимальное значение: " << numeric_limits<long long>::max() << endl;
    cout << "Тип данных: unsigned long long. Минимальное значение: " << numeric_limits<unsigned long long>::min() << ". Максимальное значение: " << numeric_limits<unsigned long long>::max() << endl;
    cout << "Тип данных: float. Минимальное значение: " << numeric_limits<float>::min() << ". Максимальное значение: " << numeric_limits<float>::max() << endl;
    cout << "Тип данных: double. Минимальное значение: " << numeric_limits<double>::min() << ". Максимальное значение: " << numeric_limits<double>::max() << endl;
    cout << "Тип данных: long double. Минимальное значение: " << numeric_limits<long double>::min() << ". Максимальное значение: " << numeric_limits<long double>::max() << endl;
    }    
}; 

int main() {
    Application application;
    application.run();
    return 0;
} //диапазон значений числовых типов данных определяется следующим образом:
//для беззнаковых(unsigned):от 0 до 2^(n -1)(-1 так как присутствует 0), где n-кол-во битов, занимаемых типом.
//для знаковых: от -2^(n-1) до 2^(n-1)-1 (-1 в стерепени т.к. диапазон знаковых чисел такой же, как и беззнаковых
// для одинакового n, но по модулю максимальное число в два раза меньше), (-1 так как есть 0).