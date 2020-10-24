//
// Created by cloud on 24.10.2020.
//

#ifndef WITCHMATH_MATRIX_H
#define WITCHMATH_MATRIX_H

#include "../Vector/Vector.h"

struct Matrix {
    double values[3][3];

    Matrix operator*(const Matrix& other) const;
    Vector operator*(const Vector& vector);
    Matrix transpose();
    Matrix reverse();
};


#endif //WITCHMATH_MATRIX_H
