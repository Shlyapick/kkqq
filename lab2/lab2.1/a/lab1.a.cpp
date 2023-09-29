#include <iostream>
using namespace std;
class Application {
public:
    void run() {
        const char* dev[3] {"год","лет","года"};
        int age;
        cout << "Введите возраст: ";
        cin >> age;
        int last_num = age%10;
        int last_2num =age%100;//для обработки чисел и больше 100 
        cout << "Возраст :"<< age << " ";
        if (last_2num >= 11 && last_2num <= 14){
            cout<<dev[1];
        }
        else{
            switch(last_num){
                case 1:
                    cout<<dev[0];
                    break;
                case 2:
                case 3:
                case 4:
                    cout<<dev[2];
                    break;
                default:
                    cout<<dev[1];
            }
        }
    cout << endl; 
    }
};
int main(){
    Application application;
    application.run();
    return 0;
}
