//
// Created by cloud on 24.10.2020.
//

#ifndef WITCHMATH_RIGIDBODY_H
#define WITCHMATH_RIGIDBODY_H

#include "../Math/Matrix/Matrix.h"
#include "../Math/Vector/Vector.h"
#include "../Math/Quaternion/Quaternion.h"

#define HEIGHT 20
#define WIDTH 40
#define DEPTH 1
#define MASS 2000

struct RigidBody {
    RigidBody();

    double M_Inv;
    Matrix I_Inv{};
    Matrix R{};
    Vector r{};
    Vector l{};
    Vector L{};
    Quaternion q{};

    RigidBody func();
};

void solve(RigidBody& body, double h);

#endif //WITCHMATH_RIGIDBODY_H
