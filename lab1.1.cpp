#include <iostream>
#include <string>

int main() {
    std::string user;

    std::cout << "Введите имя пользователя: ";
    std::cin >> user;

    std::cout << "Привет, " << user << '!' << std::endl;

    return 0;

}