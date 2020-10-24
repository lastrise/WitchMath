//
// Created by cloud on 24.10.2020.
//

#ifndef WITCHMATH_QUATERNION_H
#define WITCHMATH_QUATERNION_H

#include "../Matrix/Matrix.h"
#include <cmath>

struct Quaternion {
    double r;
    double i;
    double j;
    double k;

    Quaternion operator*(const Quaternion& other) const;
    Matrix toMatrix() const;
    Quaternion normalize() const;
};


#endif //WITCHMATH_QUATERNION_H
