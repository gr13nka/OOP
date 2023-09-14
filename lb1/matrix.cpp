#include "matrix.h"
#include "number.h"

void Matrix::change_matrix()
{
    std::cout << "Введите элементы матрицы 3x3:" << '\n';
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            std::cin >> matrix[i][j];
    }
}

void Matrix::det()
{
    int det=0;

    for(int i=0;i<3;i++)
        det = det + (matrix[0][i]*(matrix[1][(i+1)%3]*matrix[2][(i+2)%3] - matrix[1][(i+2)%3]*matrix[2][(i+1)%3]));
    std::cout << "Determinant is "<<det << '\n';
}

void Matrix::transpose()
{
    for (int i = 0; i < 3; i++){
        for (int j = i + 1; j < 3; j++){ // Проходим только по верхнему треугольнику матрицы
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}
int Matrix::rang()
{
    int rank = 3;

    for (int row = 0; row < rank; row++) {
        for (int col = 0; col < 3; col++) {
            if (matrix[row][col] != 0) {
                for (int i = row + 1; i < 3; i++) {
                    int multiplier = matrix[i][col] / matrix[row][col];
                    for (int j = col; j < 3; j++) {
                        matrix[i][j] -= multiplier * matrix[row][j];
                    }
                }
                break;
            }
        }
    }

    int nonZeroRows = 0;
    for (int row = 0; row < rank; row++) {
        bool isZeroRow = true;
        for (int col = 0; col < 3; col++) {
            if (matrix[row][col] != 0) {
                isZeroRow = false;
                break;
            }
        }
        if (!isZeroRow) {
            nonZeroRows++;
        }
    }

    return nonZeroRows;
}

void Matrix::show_matrix()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << '\n';
    }
}
