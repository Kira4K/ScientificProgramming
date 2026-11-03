#ifndef SOLVER_H
#define SOLVER_H

#include "Matrix.h"

class Solver {
public:
    static Vector solve(
        const Matrix& A,
        const Vector& b,
        double alpha,
        double eps,
        int maxIterations
    );
};

#endif
