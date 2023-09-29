#include<iostream>
using namespace std;
class Application {
public:
    void run() {
        int n;
        cout<<"Введите количество чисел в массиве: ";
        cin>>n;
        if (n<0){
            cout<<"Введено неположительное число для размера массива"<<endl;
            exit(1);
        }
        if (n==0){
            cout<<"Массив пустой или было введено не число"<<endl;
            exit(1);
        }
        double numbers[n];
        cout<<"Введите числа которомы должен быть заполнен массив: ";
        for(int i=0;i<n;i++){
            cin>>numbers[i];
        }
        double maxEm=numbers[0];
        int cMax=1;
        for (int i=1;i<n;i++){
            if(numbers[i]>maxEm){
                maxEm=numbers[i];
                cMax=1;
            }
            else if(numbers[i]==maxEm){
                cMax++;
            }
        }
        cout<<"Максимальное число в заданном массиве: "<<maxEm<<endl;
        cout<<"Количество максимальных чисел в заданном массиве: "<<cMax<<endl;
    }   
};
int main(){
    Application application;
    application.run();
    return 0;
}