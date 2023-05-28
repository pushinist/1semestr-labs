/*
Дано целое число типа long long,
выведите на экран содержимое каждого из его байтов,
используя знания по указателям. Дайте обоснование полученному результату.
*/

#include <iostream>

using namespace std;

int main() {
    long long number;
    cin >> number;
    unsigned char* bytes = (unsigned char*)(&number);
    for (int i = 0; i < sizeof(number); i++) {
        cout << int(*(bytes + i)) << " ";
    }
    return 0;
}