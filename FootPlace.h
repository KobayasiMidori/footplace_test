//
// Created by kobayasi on 23-4-26.
//

#ifndef BONNIE_CONTROL_FOOTPLACE_H
#define BONNIE_CONTROL_FOOTPLACE_H

#include <chrono>

class FootPlace_class{
public:
    FootPlace_class();
    void    cal(double *L, double *p, double s, double *v_des, double *p_des);
    void    get(double *sw_p);

    double  L_Tkf_t[3];
    double  L_des_Tk1f[3];
    double  psw_Tkf_t[3];

    double  L_Tkf_t_1[3];
    double  L_Tkf_t_2[3];
    double  L_des_Tk1f_1[3];
    double  L_des_Tk1f_2[3];
    double  psw_Tkf_t_1[3];
    double  psw_Tkf_t_2[3];

    double  t;
};

double sin_h(double x);
double cos_h(double x);

#endif //BONNIE_CONTROL_FOOTPLACE_H
