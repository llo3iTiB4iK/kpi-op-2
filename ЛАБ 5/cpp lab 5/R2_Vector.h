#pragma once

#include <iostream>
#include <string>
#include "TVector.h"
using namespace std;

class R2_Vector :public TVector
{
    float x, y;
public:
    R2_Vector(float a = 0, float b = 0) : x(a), y(b)  //����������� � ����������� ��� ����������� �������
    {
        float arr[2] = { a,b };
        initialize(2, arr);
    }
    void input(string s);  //����� �������� ����������� �������
    float Length() { return sqrt(pow(x, 2) + pow(y, 2)); }  //���������� ������� ����������� �������
    bool Parallel(R2_Vector vec)  //������������ ������������ ���� ���������� �������
    {
        if (x / vec.x == y / vec.y) return 1;
        else return 0;
    }
    bool Perpendicular(R2_Vector vec) //������������ ����������������� ���� ���������� �������
    {
        if (x * vec.x + y * vec.y == 0) return 1;
        else return 0;
    }
};
