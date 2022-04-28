#pragma once
#include <iostream>
#include <math.h>
using namespace std;

class Polynom
{
    int size; //��������� �������
    float* quots; //�������� �� ����� ����������� �������
public:
    Polynom(); //����������� �� �������������
    Polynom(const Polynom& P);  //����������� ���������
    Polynom(float* C, int n); //����������� � �����������
    ~Polynom(); //���������� �����
    float* get_quots() { return quots; } //������ ������ ����������� �������
    int get_size() { return size; } //������ ��������� �������
    float value(float); //����� ���������� �������� ������� � �����
    const Polynom operator+=(const float);
    const Polynom operator-=(const float);
    bool operator==(Polynom);
};