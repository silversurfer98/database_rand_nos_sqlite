#pragma once

# define MAX_PRECISION_TRIG 7

class trignometry
{
public:
    double invf[21] =
    {
        1.000000000000000E+00,
        1.000000000000000E+00,
        5.000000000000000E-01,
        1.666666666666670E-01,
        4.166666666666670E-02,
        8.333333333333330E-03,
        1.388888888888890E-03,
        1.984126984126980E-04,
        2.480158730158730E-05,
        2.755731922398590E-06,
        2.755731922398590E-07,
        2.505210838544170E-08,
        2.087675698786810E-09,
        1.605904383682160E-10,
        1.147074559772970E-11,
        7.647163731819820E-13,
        4.779477332387390E-14,
        2.811457254345520E-15,
        1.561920696858620E-16,
        8.220635246624330E-18,
        4.110317623312160E-19
    };
    int iter, pof1;
    char c;
    double PI_doub = 3.1415926535897932384650288;
    float p, s, PI = (float)PI_doub, sign;
    trignometry(int iterations, char choice);
    float mypower(float base, int exp);
    void rad2rad(float* rad);
    void deg2rad(float* deg);
    float sin(float x);
    float cos(float x);
};