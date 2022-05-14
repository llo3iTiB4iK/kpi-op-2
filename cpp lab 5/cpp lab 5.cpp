#include "Header.h"

int main()
{
    const int n1 = 3, n2 = 4;
    R2_Vector Arr1[n1]; //масив двовимірних векторів
    R3_Vector Arr2[n2]; //масив тривимірних векторів
    for (int i = 0; i < n1; i++)                              //заповнення масивів
        Arr1[i].input("Arr1[" + to_string(i + 1) + ']');      //
    for (int i = 0; i < n2; i++)                              //
        Arr2[i].input("Arr2[" + to_string(i + 1) + ']');      //
    cout << "Array 1:" << endl;
    for (int i = 0; i < n1; i++)
        Arr1[i].show();
    cout << "Array 2:" << endl;
    for (int i = 0; i < n2; i++)
        Arr2[i].show();
    Task1(Arr1, n1); //знаходження суми довжин векторів, паралельних до першого у масиві
    Task2(Arr2, n2); //знаходження суми векторів, перпендикулярних до першого у масиві
    return 0;
}