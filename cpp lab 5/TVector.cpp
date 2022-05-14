#include "TVector.h"

void TVector::initialize(int k, float* arr)
{
    n = k;
    coordinates = new float[n];
    for (int i = 0; i < n; i++)
        coordinates[i] = arr[i];
}

TVector::TVector(TVector& mem)
{
    n = mem.n;
    coordinates = new float[n];
    for (int i = 0; i < n; i++)
        coordinates[i] = mem.coordinates[i];
}

void TVector::show()
{
    cout << "(";
    for (int i = 0; i < n - 1; i++)
        cout << coordinates[i] << ':';
    cout << coordinates[n - 1] << ')' << endl;
}

bool TVector::Parallel(TVector vec)
{
    if ((*this).n != vec.n) { cout << "Vectors of different size...\n"; return 0; }
    else
    {
        bool flag = true;
        for (int i = 0; i < n; i++)
            if (coordinates[0] / vec.coordinates[0] != coordinates[i] / vec.coordinates[i]) flag = 0;
        return flag;
    }
}

bool TVector::Perpendicular(TVector vec)
{
    if ((*this).n != vec.n) { cout << "Vectors of different size...\n"; return 0; }
    else
    {
        float scalar = 0;
        for (int i = 0; i < n; i++)
            scalar += coordinates[i] * vec.coordinates[i];
        if (scalar == 0) return 1;
        else return 0;
    }
}

float TVector::Length()
{
    float len_square = 0;
    for (int i = 0; i < n; i++)
    {
        len_square += pow(coordinates[i], 2);
    }
    return sqrt(len_square);
}