#include "Func.hpp"


namespace pu {
    int get_rows() {
        int n;
        cin >> n;
        return n;
    }

    int get_columns() {
        int n;
        cin >> n;
        return n;
    }


    int** create_matrix(int rows, int columns) {
        int** matrix;
        matrix = new int* [rows];

        for (int i = 0; i < rows; i++) {
            matrix[i] = new int[columns];

            for (int j = 0; j < columns; j++) {
                cin >> matrix[i][j];
            }
        }
        return matrix;
    }

    void print_matrix(int** matrix, int rows, int columns) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }


    int find_min(int** matrix, int rows, int columns) {
        int min = INT_MAX;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (matrix[i][j] < min) {
                    min = matrix[i][j];
                }
            }
        }
        return min;
    }

    int find_max(int** matrix, int rows, int columns) {
        int max = INT_MIN;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (matrix[i][j] > max) {
                    max = matrix[i][j];
                }
            }
        }
        return max;
    }

    bool contains8(int number) {
        while (number % 10 != 8 and number > 0) {
            number /= 10;
        }
        return number % 10 == 8;
    }

    void handle_matrix(int** matrix, int rows, int columns, int min, int max) {
        if (min + max == 0) {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    if (contains8(matrix[i][j])) {
                        for (int k = 0; k < columns - 1; k++) {
                            for (int l = k + 1; l < columns; l++) {
                                if (matrix[i][k] > matrix[i][l]) {
                                    swap(matrix[i][k], matrix[i][l]);
                                }
                            }
                        }
                    }
                }

            }
        }
    }
}