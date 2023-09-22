#include <iostream>
#include <limits>//библиотека для получения максимальных и минимальных значений 
//типов данных 
#include <functional>//библиотека для создания функций
int main() {
    using namespace std;
    //массив с типами данных
    const char* dataTypes[] = { "signed char", "unsigned char", "char", "short", "unsigned short", "int", "unsigned int", "long", "unsigned long", "long long", " unsigned long long", "float", "double", "long double" };
    //Массив функций для получения минимальных значений
    function<int()> getMin[] = {
        numeric_limits<signed char>::min,
        numeric_limits<unsigned char>::min,
        numeric_limits<char>::min,
        numeric_limits<short>::min,
        numeric_limits<unsigned short>::min,
        numeric_limits<int>::min,
        numeric_limits<unsigned int>::min,
        numeric_limits<long>::min,
        numeric_limits<unsigned long>::min,
        numeric_limits<long long>::min,
        numeric_limits<unsigned long long>::min,
        numeric_limits<float>::min,
        numeric_limits<double>::min,
        numeric_limits<long double>::min
    };
    //Массив функций для получения максимальных значений
    function<int()> getMax[] = {
        numeric_limits<signed char>::max,
        numeric_limits<unsigned char>::max,
        numeric_limits<char>::max,
        numeric_limits<short>::max,
        numeric_limits<unsigned short>::max,
        numeric_limits<int>::max,
        numeric_limits<unsigned int>::max,
        numeric_limits<long>::max,
        numeric_limits<unsigned long>::max,
        numeric_limits<long long>::max,
        numeric_limits<unsigned long long>::max,
        numeric_limits<float>::max,
        numeric_limits<double>::max,
        numeric_limits<long double>::max
    };     
    for (int i = 0; i < sizeof(getMax) / sizeof(getMax[0]); ++i) {
        cout << "Тип данных: " << dataTypes[i] << endl;
        cout << "Минимальное значение: " << getMin[i]() << endl;
        cout << "Максимальное значение: " << getMax[i]() << endl;
    }
    return 0;
}   //диапазон значений числовых типов данных определяется следующим образом:
//для беззнаковых(unsigned):от 0 до 2^(n -1)(-1 так как присутствует 0), где n-кол-во битов, занимаемых типом.
//для знаковых: от -2^(n-1) до 2^(n-1)-1 (-1 в стерепени т.к. диапазон знаковых чисел такой же, как и беззнаковых
// для одинакового n, но по модулю максимальное число в два раза меньше), (-1 так как есть 0).