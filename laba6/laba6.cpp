/*
 * Дана целочисленная матрица {Aij}i=1...n;j=1..n , n<=100.
 * Если сумма наибольшего и наименьшего элементов матрицы равна нулю,
 * упорядочить элементы строк, в которых есть хотя бы один элемент,
 * содержащий цифру 8, по неубыванию.
 */


#include "Func.hpp"
int main() {
    int rows = pu::get_rows();
    int columns = pu::get_columns();
    int** matrix = pu::create_matrix(rows, columns);
    int min = pu::find_min(matrix, rows, columns);
    int max = pu::find_max(matrix, rows, columns);
    pu::handle_matrix(matrix, rows, columns, min, max);
    pu::print_matrix(matrix, rows, columns);

    return 0;
}
