#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

//  для считывания данных
void readData(map<pair<string, string>, int>& customers) {
    string line;
    while (true) {
        getline(cin, line);

        if (line == "exit" || line.empty()) {
            break;
        }

        string customer, product;
        int quantity;
        istringstream iss(line);
        iss >> customer >> product >> quantity;

        pair<string, string> key = {customer, product};

        // если комбинация уже существует добавляем к существующему количеству
        if (customers.find(key) != customers.end()) {
            customers[key] += quantity;
        } else {
            //или создаем новую запись
            customers[key] = quantity;
        }
    }
}

//  для вывода списка покупателей и суммарного количества купленных товаров
void displayCustomers(const map<pair<string, string>, int>& customers) {
    string current_customer = "";
    for (const auto& customer_product : customers) {
        if (customer_product.first.first != current_customer) {
            if (current_customer != "") {
                cout << endl;
            }
            cout << "Покупатель: " << customer_product.first.first << endl;
            current_customer = customer_product.first.first;
        }
        cout << "Товар: " << customer_product.first.second << " количество: " << customer_product.second << endl;
    }
}

class Application
{
public:
    void run(){
        map<pair<string, string>, int> customers;

        readData(customers);
        displayCustomers(customers);

    }
};

int main()
{
    Application application;
    application.run();
    return 0;
}