//
// Created by kobayasi on 23-4-7.
//

#ifndef KALMAN_KALMAN_H
#define KALMAN_KALMAN_H

#include "stdint.h"
#include <eigen3/Eigen/Dense>

class Angular_Momentum_class {
    public:
        Angular_Momentum_class();
        void init();
        void cal(Eigen::Matrix<double, 3, 1> p, Eigen::Matrix<double, 3, 1> w,
                 Eigen::Matrix<double, 3, 1> v, Eigen::Matrix<double, 3, 3> I);

        Eigen::Matrix<double, 3, 3>  I;
        Eigen::Matrix<double, 3, 1>  L, Lcom, Lm, Loff;

        Eigen::Matrix<double, 6, 1>    x0b;
        Eigen::Matrix<double, 3, 1>    u0, y1;
        Eigen::Matrix<double, 6, 6>    A;
        Eigen::Matrix<double, 6, 3>    B;
        Eigen::Matrix<double, 3, 6>    C;
        Eigen::Matrix<double, 6, 6>    Q, Qu;
        Eigen::Matrix<double, 3, 3>    R;
        Eigen::Matrix<double, 6, 6>    P0b;
        bool startFlag;

        double  Ts = 0.001;
        double  m = 14;
        double  g = -9.8;
};


#endif //KALMAN_KALMAN_H
