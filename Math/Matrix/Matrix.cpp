//
// Created by cloud on 24.10.2020.
//

#include "Matrix.h"

Matrix Matrix::operator*(const Matrix& other) const {
    Matrix result{};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result.values[i][j] = 0;
            for (int k = 0; k < 3; ++k) result.values[i][j] += values[i][k] * other.values[k][j];
        }
    }
    return result;
}

Vector Matrix::operator*(const Vector& vector) {
    return Vector{
            values[0][0] * vector.x + values[0][1] * vector.y + values[0][2] * vector.z,
            values[1][0] * vector.x + values[1][1] * vector.y + values[1][2] * vector.z,
            values[2][0] * vector.x + values[2][1] * vector.y + values[2][2] * vector.z
    };
}

Matrix Matrix::transpose() {
    Matrix result{};
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) result.values[i][j] = values[j][i];
    return result;
}
