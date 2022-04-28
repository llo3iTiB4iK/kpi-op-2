#pragma once
#include <iostream>
#include <math.h>
using namespace std;

class Polynom
{
    int size; //розмірність полінома
    float* quots; //покажчик на масив коефіцієнтів полінома
public:
    Polynom(); //конструктор за замовчуванням
    Polynom(const Polynom& P);  //конструктор копіювання
    Polynom(float* C, int n); //конструктор з параметрами
    ~Polynom(); //деструктор класу
    float* get_quots() { return quots; } //геттер масиву коефіцієнтів полінома
    int get_size() { return size; } //геттер розмірності полінома
    float value(float); //метод обчислення значення поліному в точці
    const Polynom operator+=(const float);
    const Polynom operator-=(const float);
    bool operator==(Polynom);
};