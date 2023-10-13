#include <iostream>
#include <string>
using namespace std;
class typeConvert {
public:
    static int toI(const string& str) {
        return stoi(str);
    }

    static long toL(const string& str) {
        return stol(str);
    }

    static unsigned long toUL(const string& str) {
        return stoul(str);
    }

    static char toC(const string& str) {
        if (str.size() != 1) {
            throw invalid_argument("Длина строки должна быть равна 1");
        }
        return str[0];
    }
};

class Application{
    public:
    void run(){
        string userStr;
        string userType;

        cout << "Введите сообщение: "<<endl;
        cin >> userStr;
        cout << "Выберите тип преобразования сообщения(int,long,unsigned long,char): ";
        cin >> userType;
        
        try{
            if(userType=="int"){
                cout<<"Результат преобразования: " << typeConvert::toI(userStr) << endl;
            }

            else if(userType=="long"){
                cout<<"Результат преобразования: " << typeConvert::toL(userStr) << endl;
            }

            else if(userType=="unsigned long"){
                cout<<"Результат преобразования: " << typeConvert::toUL(userStr) << endl;
            }

            else if(userType=="char"&& userStr.size()==1){
                cout<<"Результат преобразования: " << typeConvert::toC(userStr) << endl;
            }

            else{
                throw invalid_argument("Преобразование невозможно: выбран некорректный тип");
            }
        }catch(const out_of_range &err) {
            cerr<<"Error: переполнение"<<endl;
        }catch(const invalid_argument &err) {
            cerr<<"Error: выбран некорректный тип или длина строки не равна 1"<<endl;
        }catch(const runtime_error &err) {
            cerr<<"Error: ошибка времени выполнения"<<endl;
        }catch(const exception &err) {
            cerr<<"Error"<<endl;
        }
    }
};

int main(){
    Application application;
    application.run();
    return 0;
}


    


