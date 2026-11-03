#include "Solver.h"
#include <cmath>
#include <stdexcept>

Vector Solver::solve(
    const Matrix& A,
    const Vector& b,
    double alpha,
    double eps,
    int maxIterations
) {
    int n = A.getRows();

    if (A.getCols() != n ||
        static_cast<int>(b.size()) != n)
        throw std::invalid_argument("Incorrect system dimensions");

    if (alpha <= 0 || eps <= 0 || maxIterations <= 0)
        throw std::invalid_argument("Incorrect parameters");

    Vector x(n, 0.0);

    for (int k = 0; k < maxIterations; k++) {
        Vector Ax = A.multiply(x);

        Vector r(n, 0.0);
        double norm = 0.0;

        for (int i = 0; i < n; i++) {
            r[i] = b[i] - Ax[i];
            norm += r[i] * r[i];
        }

        norm = std::sqrt(norm);

        if (norm < eps)
            return x;

        for (int i = 0; i < n; i++)
            x[i] += alpha * r[i];
    }

    throw std::runtime_error("Method did not converge");
}
