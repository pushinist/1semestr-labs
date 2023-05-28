/* Дана целочисленная матрица {Aij}i=1..n,j=1..m (n,m<=100).
 * Найти столбец, в котором меньше всего чисел, заканчивающихся цифрой 3, и
 * заменить все элементы матрицы кроме элементов этого столбца числом -17.
*/


#include <iostream>

using namespace std;

int main() {
    int const N = 100;
    int const M = 100;

    int n, m;
    cin >> n;
    cin >> m;

    int matrix[N][M];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int min3 = n;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            if (matrix[j][i] % 10 == 3) {
                cnt++;
            }
        }
        if (cnt < min3) {
            min3 = cnt;
        }
    }

    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            if (matrix[j][i] % 10 == 3) {
                cnt++;
            }
        }
        if (cnt != min3) {
            for (int j = 0; j < m; j++) {
                matrix[j][i] = -17;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}
