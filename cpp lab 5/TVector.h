#pragma once

#include <iostream>
using namespace std;

class TVector
{
protected:
    int n; //�������� ��������
    float* coordinates; //�������� �� ��������� ����� ��������� ������
protected:
    void initialize(int k, float* arr); //����������� ��'���� TVector
public:
    TVector() : n(0), coordinates(nullptr) {}; //����������� ��� ��'���� TVector �� �������������
    TVector(TVector& mem); //����������� ���������
    void show(); //����� ��������� ������� ����-��� ��������� �� �����
    virtual bool Parallel(TVector vec); //����� ������������ ������������ ���� ������� ����-��� ���������
    virtual bool Perpendicular(TVector vec); //����� ������������ ����������������� ���� ������� ����-��� ��������
    virtual float Length(); //����� ������������ ������� ������� ����-�� ���������
    ~TVector() { delete[] coordinates; }  //���������� �����
};