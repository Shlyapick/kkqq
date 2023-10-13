#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class eCheck {
    public:
    void ifErr (string inFile){
    ifstream file(inFile);
    try{
        if (!file.is_open()){
            throw ifstream::failure("Ошибка открытия файла");
        }
        char ch;
        while (file.get(ch)){
            cout<<ch;
        }
    }
    catch (const ifstream::failure){
        cerr<<"Ошибка ввода/вывода"<<endl;
        exit(1);
        }
    }
};
int main(){
    string fileName;
    cout<<"Введите полное имя файла для чтения (name.txt):"<<endl;
    cin>> fileName;
    if (fileName.empty()){
        cerr<<"Имя файла не было введено"<<endl;
        return 1;
    }
    eCheck filecheck;
    filecheck.ifErr(fileName);
    return 0;
}