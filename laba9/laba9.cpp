/*
Воспользуйтесь первым принципом ООП, абстракцией, и сформируйте класс, включив в него только минимальный набор переменных (полей) для заданного вашим вариантом объекта.

Используйте второй принцип ООП, инкапсуляцию, чтобы не допустить некорректного ввода параметров.

Добавьте в класс функции (методы), которые позволят решить задачу.

Найти площадь прямоугольника.

*/


#include <iostream>

using namespace std;


class rect {
public:
    int height;
    int width;
    rect(int h, int w) {
        this->width = w;
        this->height = h;
    }

    int Square() {
        return this->height * this->width;
    }
};


int main() {
    int w, h;
    cin >> w;
    cin >> h;

    rect rectangle(h, w);

    cout << rectangle.Square();
    return 0;
}
