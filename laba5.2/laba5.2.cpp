/*
Дан файл, содержащий русский текст, размер текста не превышает 10 К байт. 
Найти в тексте N (N ≤ 100) самых длинных слов, содержащих одинаковое количество гласных и согласных. 
Записать найденные слова в текстовый файл в порядке не возрастания длины. 
Все найденные слова должны быть разными. Число N вводить из файла.
*/

#include <iostream>
#include <fstream>
#include <windows.h>

int const N = 100;
using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); 
    int n;
    cin >> n;
    ifstream in("input.txt");
    ofstream out("output.txt");
    string curString;
    string vowelConsonantStrings[11000];
    int numberOfVowelConsonantStrings = 0;
    while (in >> curString) {
        int curVowelNumber = 0, curConsonantNumber = 0;
        for (int i = 0; i < curString.length(); ++i) {
            if (curString[i] == 'а' || curString[i] == 'у' || curString[i] == 'е' || curString[i] == 'ы' || curString[i] == 'о'
                || curString[i] == 'э' || curString[i] == 'я' || curString[i] == 'и' || curString[i] == 'ю') {
                ++curVowelNumber;
            }
            else {
                ++curConsonantNumber;
            }
        }
        if (curConsonantNumber == curVowelNumber) {
            vowelConsonantStrings[numberOfVowelConsonantStrings] = curString;
            ++numberOfVowelConsonantStrings;
        }
    }
    for (int i = 0; i < numberOfVowelConsonantStrings - 1; ++i) {
        for (int j = i + 1; j < numberOfVowelConsonantStrings; ++j) {
            if ((vowelConsonantStrings[i].length() < vowelConsonantStrings[j].length()) ||
                (vowelConsonantStrings[i].length() == vowelConsonantStrings[j].length() && vowelConsonantStrings[i] < vowelConsonantStrings[j])) {
                swap(vowelConsonantStrings[i], vowelConsonantStrings[j]);
            }
        }
    }
    if (numberOfVowelConsonantStrings == 0) {
        cout << "В тексте нет слов с одинаковым количеством гласных и согласных.\n";
        return 0;
    }
    int numberOfDifferentVowelConsonantStrings = 1;
    string differentVowelConsonantStrings[N];
    differentVowelConsonantStrings[0] = vowelConsonantStrings[0];
    for (int i = 1; i < numberOfVowelConsonantStrings && numberOfDifferentVowelConsonantStrings < N; ++i) {
        if (differentVowelConsonantStrings[numberOfDifferentVowelConsonantStrings - 1] != vowelConsonantStrings[i]) {
            differentVowelConsonantStrings[numberOfDifferentVowelConsonantStrings] = vowelConsonantStrings[i];
            ++numberOfDifferentVowelConsonantStrings;
        }
    }
    if (numberOfDifferentVowelConsonantStrings < n) {
        cout << "Нет " << n << " различных слов с одинаковым количеством гласных и согласных.\n";
    }
    else {
        for (int i = 0; i < n; ++i) {
            out << differentVowelConsonantStrings[i] << "\n";
        }
    }
}
