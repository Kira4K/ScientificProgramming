#include "Matrix.h"
#include <stdexcept>

Matrix::Matrix(int n, int m)
    : rows(n), cols(m),
      data(n, std::vector<double>(m, 0.0))
{
    if (n <= 0 || m <= 0)
        throw std::invalid_argument("Invalid matrix size");
}

int Matrix::getRows() const {
    return rows;
}

int Matrix::getCols() const {
    return cols;
}

double& Matrix::operator()(int i, int j) {
    return data.at(i).at(j);
}

double Matrix::operator()(int i, int j) const {
    return data.at(i).at(j);
}

Matrix Matrix::operator+(const Matrix& B) const {
    if (rows != B.rows || cols != B.cols)
        throw std::invalid_argument("Different matrix sizes");

    Matrix C(rows, cols);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            C(i, j) = data[i][j] + B(i, j);

    return C;
}

Matrix Matrix::operator-(const Matrix& B) const {
    if (rows != B.rows || cols != B.cols)
        throw std::invalid_argument("Different matrix sizes");

    Matrix C(rows, cols);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            C(i, j) = data[i][j] - B(i, j);

    return C;
}

Vector Matrix::multiply(const Vector& x) const {
    if (static_cast<int>(x.size()) != cols)
        throw std::invalid_argument("Incorrect vector size");

    Vector result(rows, 0.0);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i] += data[i][j] * x[j];

    return result;
}

void Matrix::print() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            std::cout << data[i][j] << " ";
        std::cout << '\n';
    }
}
