#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>

using Vector = std::vector<double>;

class Matrix {
private:
    int rows;
    int cols;
    std::vector<std::vector<double>> data;

public:
    Matrix(int n, int m);

    int getRows() const;
    int getCols() const;

    double& operator()(int i, int j);
    double operator()(int i, int j) const;

    Matrix operator+(const Matrix& B) const;
    Matrix operator-(const Matrix& B) const;

    Vector multiply(const Vector& x) const;

    void print() const;
};

#endif
