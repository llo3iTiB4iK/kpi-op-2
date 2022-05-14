#pragma once

#include <iostream>
#include <string>
#include "TVector.h"
using namespace std;

class R2_Vector :public TVector
{
    float x, y;
public:
    R2_Vector(float a = 0, float b = 0) : x(a), y(b)  //конструктор з параметрами дл€ двовим≥рного вектора
    {
        float arr[2] = { a,b };
        initialize(2, arr);
    }
    void input(string s);  //метод введенн€ двовим≥рного вектора
    float Length() { return sqrt(pow(x, 2) + pow(y, 2)); }  //визначенн€ довжини двовим≥рного вектора
    bool Parallel(R2_Vector vec)  //встановленн€ паралельност≥ двох двовим≥рних вектор≥в
    {
        if (x / vec.x == y / vec.y) return 1;
        else return 0;
    }
    bool Perpendicular(R2_Vector vec) //встановленн€ перпендикул€рност≥ двох двовим≥рних вектор≥в
    {
        if (x * vec.x + y * vec.y == 0) return 1;
        else return 0;
    }
};
