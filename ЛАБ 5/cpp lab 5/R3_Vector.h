#pragma once

#include <iostream>
#include <string>
#include "TVector.h"
using namespace std;

class R3_Vector :public TVector
{
    float x, y, z;
public:
    R3_Vector(float a = 0, float b = 0, float c = 0) : x(a), y(b), z(c) //конструктор з параметрами дл€ тривим≥рного вектора
    {
        float arr[3] = { a,b,c };
        initialize(3, arr);
    }
    void input(string s); //метод введенн€ тривим≥рного вектора
    float Length() { return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)); }  //метод визначенн€ довжини тривим≥рного вектора
    bool Parallel(R3_Vector vec)  //встановленн€ паралельност≥ двох тривим≥рних вектор≥в
    { 
        if (x / vec.x == y / vec.y == z / vec.z) return 1;
        else return 0;
    }
    bool Perpendicular(R3_Vector vec)  //встановленн€ перпендикул€рност≥ двох двовим≥рних вектор≥в
    {
        if (x * vec.x + y * vec.y + z * vec.z == 0) return 1;
        else return 0;
    }
    const R3_Vector operator+=(const R3_Vector vec); //перевизначенн€ оператора скороченого додаванн€ дл€ двох тривим≥рних вектор≥в
};
