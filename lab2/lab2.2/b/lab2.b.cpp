#include <iostream>
#include <cmath>// для извлечения модуля
using namespace std;
double Sq_Root(double a,double eps = 1e-12){
    double gs = a/2.0;
    while (fabs(gs*gs-a)>eps){
        gs=0.5*(gs+a/gs);
    }
    return gs;
}
class Application {
public:
    void run() {
        double num;
        cout<<"Введите число для извлечения корня: "<<endl;
        cin>>num;
        if(num<0){
            cout<<"Введено отрицательное число, невозможно извлечь корень"<<endl;
        }
        else{
            double sqr=Sq_Root(num);
            cout<<"Квадратный корень из числа "<< num<< "= "<<sqr<<endl;
        }
    }
};
int main(){
    Application application;
    application.run();
    return 0;
}