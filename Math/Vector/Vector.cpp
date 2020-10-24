//
// Created by cloud on 24.10.2020.
//

#include "Vector.h"


Vector Vector::operator*(const Vector& other) const {
    double i = y * other.z - z * other.y;
    double j = z * other.x - x * other.z;
    double k = x * other.y - y * other.x;
    return Vector{i, j, k};
}