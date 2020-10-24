//
// Created by cloud on 24.10.2020.
//

#include "RigidBody.h"


RigidBody RigidBody::func() {
    RigidBody result{};
    result.M_Inv = M_Inv;
    result.I_Inv = I_Inv;
    result.r.x = l.x * M_Inv;
    result.r.y = l.y * M_Inv;
    result.r.z = l.z * M_Inv;
    Vector omega = ((R * I_Inv) * R.transpose()) * L;
    result.q = Quaternion{0, omega.x, omega.y, omega.z} * q;
    result.q.i *= 0.5;
    result.q.j *= 0.5;
    result.q.k *= 0.5;
    result.R = result.q.normalize().toMatrix();
    result.l = Vector{0, 0, 0};
    result.L = Vector{0, 0, 0};
    return result;
}

RigidBody::RigidBody() {
    M_Inv = MASS;
    I_Inv = {0, 0, 0, 0, 0, 0, 0, 0, 0};;
    I_Inv.values[0][0] = (1.0 / 12) * M_Inv * (WIDTH * WIDTH + DEPTH * DEPTH);
    I_Inv.values[1][1] = (1.0 / 12) * M_Inv * (HEIGHT * HEIGHT + DEPTH * DEPTH);
    I_Inv.values[2][2] = (1.0 / 12) * M_Inv * (HEIGHT * HEIGHT + WIDTH * WIDTH);
    q = {cos(0), 1, 0, 0};
    R = q.toMatrix();
    L = Vector{1, 1, 1};
}

void solve(RigidBody& body, double h) {
    RigidBody dt1 = body.func();
    RigidBody dt2 = dt1.func();

    body.r.x = body.r.x + h * dt1.r.x + h * h / 2 * dt2.r.x;
    body.r.y = body.r.y + h * dt1.r.y + h * h / 2 * dt2.r.y;
    body.r.z = body.r.z + h * dt1.r.z + h * h / 2 * dt2.r.z;

    body.l.x = body.l.x + h * dt1.l.x + h * h / 2 * dt2.l.x;
    body.l.y = body.l.y + h * dt1.l.y + h * h / 2 * dt2.l.y;
    body.l.z = body.l.z + h * dt1.l.z + h * h / 2 * dt2.l.z;

    body.L.x = body.L.x + h * dt1.L.x + h * h / 2 * dt2.L.x;
    body.L.y = body.L.y + h * dt1.L.y + h * h / 2 * dt2.L.y;
    body.L.z = body.L.z + h * dt1.L.z + h * h / 2 * dt2.L.z;

    body.q.r = body.q.r + h * dt1.q.r + h * h / 2 * dt2.q.r;
    body.q.i = body.q.i + h * dt1.q.i + h * h / 2 * dt2.q.i;
    body.q.j = body.q.j + h * dt1.q.j + h * h / 2 * dt2.q.j;
    body.q.k = body.q.k + h * dt1.q.k + h * h / 2 * dt2.q.k;

    body.q = body.q.normalize();
    body.R = body.q.toMatrix();
}
