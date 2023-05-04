//
// Created by kobayasi on 23-4-7.
//
#include "Kalman.h"

Angular_Momentum_class::Angular_Momentum_class()  {
    I.setZero();
    L.setZero();
    Lcom.setZero();
    Lm.setZero();

    x0b.setZero();
    u0.setZero();
    y1.setZero();
    A.setZero();
    B.setZero();
    C.setZero();

    Q.setZero();
    Qu.setZero();
    R.setZero();

    P0b.setZero();
    startFlag = false;
}

void Angular_Momentum_class::init(){
    A << 1, 0, 0,
            0, 1, 0,
            0, 0, 1;
    B << 0, Ts*m*g, 0,
            -Ts*m*g, 0, 0,
            0, 0, 0;
    C << 1, 0, 0,
            0, 1, 0,
            0, 0, 1;

    Eigen::Matrix<double,3, 3> Cu, Qx;
    Cu << 8.698940917230453e-08, 0, 0,
            0, 3.925033562397060e-09, 0,
            0, 0, 1.852578958119684e-12;
    Qu = B*Cu*B.transpose();
    Qx << 1e-8, 0, 0,
            0, 5e-6, 0,
            0, 0, 1e-8;
    Q = Qx + Qu;
    R << 8.462057579429161e-05, 0, 0,
            0, 2.511103693685685e-04, 0,
            0, 0, 1.004434228773781e-05;
    startFlag = true;
};

void Angular_Momentum_class::cal(Eigen::Matrix<double, 3, 1> p, Eigen::Matrix<double, 3, 1> w,
                                 Eigen::Matrix<double, 3, 1> v, Eigen::Matrix<double, 3, 3> I) {
    Eigen::Matrix<double, 3, 1> x1f, x1b;
    Eigen::Matrix<double, 3, 3> P1f, P1b, S, K;
    Eigen::Matrix<double, 3, 3> E;

    x1f.setZero();
    x1b.setZero();
    P1f.setZero();
    P1b.setZero();
    S.setZero();
    K.setZero();
    E << 1, 0, 0, 0, 1, 0, 0, 0, 1;

    if (startFlag == true) {
        Lcom = I*w;
        Lm = Lcom + m*p.cross(v);

        x1f = A * x0b + B * p;
        P1f = A * P0b * A.transpose() + Q;

        S = R + C * P1f * C.transpose();
        K = P1f * C.transpose() * S.inverse();
        x1b = x1f + K * (Lm - C * x1f);
        P1b = (E - K * C) * P1f;
    }
    else{
        x1b = x0b;
        P1b = P0b;
    }
    x0b = x1b;
    P0b = P1b;

    L = x1b;
}

