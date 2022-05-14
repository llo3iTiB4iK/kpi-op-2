#pragma once

#include <iostream>
#include <string>
#include "TVector.h"
using namespace std;

class R3_Vector :public TVector
{
    float x, y, z;
public:
    R3_Vector(float a = 0, float b = 0, float c = 0) : x(a), y(b), z(c) //����������� � ����������� ��� ����������� �������
    {
        float arr[3] = { a,b,c };
        initialize(3, arr);
    }
    void input(string s); //����� �������� ����������� �������
    float Length() { return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)); }  //����� ���������� ������� ����������� �������
    bool Parallel(R3_Vector vec)  //������������ ������������ ���� ���������� �������
    { 
        if (x / vec.x == y / vec.y == z / vec.z) return 1;
        else return 0;
    }
    bool Perpendicular(R3_Vector vec)  //������������ ����������������� ���� ���������� �������
    {
        if (x * vec.x + y * vec.y + z * vec.z == 0) return 1;
        else return 0;
    }
    const R3_Vector operator+=(const R3_Vector vec); //�������������� ��������� ����������� ��������� ��� ���� ���������� �������
};
