#pragma once

#include <iostream>
using namespace std;

class TVector
{
protected:
    int n; //вимірність простору
    float* coordinates; //покажчик на динамічний масив координат вектор
protected:
    void initialize(int k, float* arr); //ініціалізація об'єкта TVector
public:
    TVector() : n(0), coordinates(nullptr) {}; //конструктор для об'єкта TVector за замовчуванням
    TVector(TVector& mem); //конструктор копіювання
    void show(); //метод виведення вектора будь-якої розмірності на екран
    virtual bool Parallel(TVector vec); //метод встановлення паралельності двох векторів будь-якої розмірності
    virtual bool Perpendicular(TVector vec); //метод встановлення перпендикудярності двох векторів будь-якої рзмірності
    virtual float Length(); //метод встановлення довжини вектора будь-якї розмірності
    ~TVector() { delete[] coordinates; }  //деструктор класу
};