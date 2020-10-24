//
// Created by cloud on 24.10.2020.
//

#include "Quaternion.h"


Quaternion Quaternion::operator*(const Quaternion& other) const {
    return Quaternion{
            r * other.r - i * other.i - j * other.j - k * other.k,
            r * other.i + i * other.r + j * other.k - k * other.j,
            r * other.j - i * other.k + j * other.r + k * other.i,
            r * other.k + i * other.j - j * other.i + k * other.r
    };
}

Matrix Quaternion::toMatrix() const {
    Matrix matrix{};
    matrix.values[0][0] = 1 - 2 * j * j - 2 * k * k;
    matrix.values[0][1] = 2 * i * j - 2 * r * k;
    matrix.values[0][2] = 2 * i * k + 2 * r * j;
    matrix.values[1][0] = 2 * i * j + 2 * r * k;
    matrix.values[1][1] = 1 - 2 * i * i - 2 * k * k;
    matrix.values[1][2] = 2 * j * k - 2 * r * i;
    matrix.values[2][0] = 2 * i * k - 2 * r * j;
    matrix.values[2][1] = 2 * j * k + 2 * r * i;
    matrix.values[2][2] = 1 - 2 * i * i - 2 * j * j;
    return matrix;
}

Quaternion Quaternion::normalize() const {
    double length = sqrt(r * r + i * i + j * j + k * k);
    return Quaternion{r / length, i / length, j / length, k / length};
}
