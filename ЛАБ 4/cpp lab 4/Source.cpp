#include "Header.h"

void Polynom_Output(Polynom P)  //функція виведення поліному
{
    float* C = P.get_quots();
    int size = P.get_size();
    cout << C[0];
    for (int i = 1; i < size; i++)
        cout << " + " << C[i] << "*(x^" << i << ')';
    cout << '\n';
}