#include "Polynom.h"

Polynom::Polynom() //конструктор за замовчуванням
{
    size = 4;
    quots = new float[size];
    for (int i = 0; i < size; i++)
        quots[i] = 0;
}
Polynom::Polynom(const Polynom& P)  //конструктор копіювання
{
    size = P.size;
    quots = new float[P.size];
    for (int i = 0; i < size; i++)
        quots[i] = P.quots[i];
}
Polynom::Polynom(float* C, int n) //конструктор з параметрами
{
    size = n;
    quots = new float[size];
    for (int i = 0; i < size; i++)
        quots[i] = C[i];
}
Polynom::~Polynom() //деструктор класу
{
    delete[] quots;
}

float Polynom::value(float x)  //метод обчислення значення поліному в точці
{
    float val = quots[0];
    for (int i = 1; i < size; i++)
    {
        val += quots[i] * pow(x, i);
    }
    return val;
}
const Polynom Polynom::operator+=(const float k)
{
    for (int i = 0; i < size; i++)
        quots[i] += k;
    return *this;
}
const Polynom Polynom::operator-=(const float k)
{
    for (int i = 0; i < size; i++)
        quots[i] -= k;
    return *this;
}
bool Polynom::operator==(Polynom P)
{
    bool flag = 1;
    if (size != P.size) flag = 0;
    else
        for (int i = 0; i < size; i++)
            if (quots[i] != P.quots[i]) flag = 0;
    return flag;
}