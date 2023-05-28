#include <iostream>
using namespace std;

namespace pu {
    int get_rows();
    int get_columns();
    int** create_matrix(int rows, int columns);
    void print_matrix(int** matrix, int rows, int columns);
    int find_min(int** matrix, int rows, int columns);
    int find_max(int** matrix, int rows, int columns);
    bool contains8(int number);
    void handle_matrix(int** matrix, int rows, int columns, int min, int max);
}