/*
    1. Дана строка длиной не более 100 символов. Посчитать количество букв в ней
*/

#include <iostream>

int main() {
    char str[101];
    std::cin >> str;
    int current = 0;
    while (str[current] != '\0') {
        ++current;
    }
    std::cout << current;
}