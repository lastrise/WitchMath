//
// Created by cloud on 24.10.2020.
//

#ifndef WITCHMATH_VECTOR_H
#define WITCHMATH_VECTOR_H


struct Vector {
    double x;
    double y;
    double z;

    Vector operator*(const Vector& other) const;
};


#endif //WITCHMATH_VECTOR_H
