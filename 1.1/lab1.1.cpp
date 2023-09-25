#include <iostream>
#include <string>

class Application {
public:
    int run() {
        std::string user;
        std::cout << "Введите имя пользователя: ";
        std::cin >> user;
        std::cout << "Привет, " << user << '!' << std::endl;
        return 0;
    }
};

int main() {
    Application application;
    int result = application.run();
    return result;
}