//
// Created by kobayasi on 23-4-26.
//

#include "FootPlace.h"
#include "cppTypes.h"

FootPlace_class::FootPlace_class(){
    for (int i = 0; i<3; i++){
        L_Tkf_t[i] = 0;
        L_des_Tk1f[i] = 0;
        psw_Tkf_t[i] = 0;
    }
}

void FootPlace_class::cal(double *L, double *p, double s, double *v_des, double *p_des) {
    double      m = 14;
    double      g = 9.8;
    double      H = 0.53279;
    double      l = sqrt(g/H);
    double      Ts, Tw;

    Tw = 0.5;
    Ts = 0.001;
    t = s*500*Ts;

    //H = p[2];

    L_Tkf_t[1] = m*H*l*sinh(l*(Tw - t))*p[0] +
               cos_h(l*(Tw - t))*L[1];
    L_Tkf_t_1[1] = m*H*l*sinh(l*(Tw - t))*p[0];
    L_Tkf_t_2[1] = cos_h(l*(Tw - t))*L[1];

    L_des_Tk1f[1] = 0.5*m*H*v_des[0]*Tw*(l*sinh(l*Tw)/(1+cos_h(l*Tw)));
    psw_Tkf_t[0] = (L_des_Tk1f[1] - cos_h(l*Tw)*L_Tkf_t[1])/(m*H*l*sin_h(l*Tw));


    L_Tkf_t[0] = m*H*l*sin_h(l*(Tw - t))*p[1] +
               cos_h(l*(Tw - t))*L[0];
    L_Tkf_t_1[0] = m*H*l*sin_h(l*(Tw - t))*p[1];
    L_Tkf_t_2[0] = cos_h(l*(Tw - t))*L[0];

    L_des_Tk1f[0] =  m*H*p_des[1]*(l*sin_h(l*Tw)/(1+cos_h(l*Tw)));
    psw_Tkf_t[1] = (L_des_Tk1f[0] - cos_h(l*Tw)*L_Tkf_t[0])/(m*H*l*sin_h(l*Tw));

    psw_Tkf_t[2] = 0;
}

void FootPlace_class::get(double *sw_p) {
    sw_p[0] = psw_Tkf_t[0];
    sw_p[1] = psw_Tkf_t[1];
    sw_p[2] = psw_Tkf_t[2];
}

double sin_h(double x){
    return  (exp(x) - exp(-x))/2;
}

double cos_h(double x){
    return  (exp(x) + exp(-x))/2;
}

