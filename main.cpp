#include "Matrix.h"
#include "Solver.h"

#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdexcept>

int main() {
    try {
        int n;

        std::cout << "Enter system size n: ";
        std::cin >> n;

        if (!std::cin || n <= 0)
            throw std::invalid_argument("Invalid system size");

        Matrix A(n, n);

        std::cout << "Enter matrix A:\n";

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                std::cin >> A(i, j);

        if (!std::cin)
            throw std::invalid_argument("Invalid matrix input");

        Vector b(n);

        std::cout << "Enter vector b:\n";

        for (int i = 0; i < n; i++)
            std::cin >> b[i];

        if (!std::cin)
            throw std::invalid_argument("Invalid vector input");

        double alpha, eps;
        int maxIterations;

        std::cout << "Enter alpha: ";
        std::cin >> alpha;

        std::cout << "Enter eps: ";
        std::cin >> eps;

        std::cout << "Enter maximum iterations: ";
        std::cin >> maxIterations;

        if (!std::cin)
            throw std::invalid_argument("Invalid parameters");

        Vector x = Solver::solve(A, b, alpha, eps, maxIterations);

        std::cout << std::setprecision(10);
        std::cout << "\nSolution:\n";

        for (int i = 0; i < n; i++)
            std::cout << "x[" << i + 1 << "] = "
                      << x[i] << '\n';

        Vector Ax = A.multiply(x);
        double norm = 0.0;

        for (int i = 0; i < n; i++) {
            double r = Ax[i] - b[i];
            norm += r * r;
        }

        std::cout << "Residual norm = "
                  << std::sqrt(norm) << '\n';
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
