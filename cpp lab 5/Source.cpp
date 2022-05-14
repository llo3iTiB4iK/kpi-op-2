#include "Header.h"

void Task1(R2_Vector arr[], const int size)
{
    float sum = 0;
    for (int i = 1; i < size; i++)
        if (arr[0].Parallel(arr[i])) sum += arr[i].Length();
    cout << "Sum of lengths of vectors', parallel to the first two-dimensional vector = ";
    cout << sum << endl;
}

void Task2(R3_Vector arr[], const int size)
{
    R3_Vector sum;
    for (int i = 1; i < size; i++)
        if (arr[0].Perpendicular(arr[i])) sum += arr[i];
    cout << "Sum of vectors, perpendicular to the first three-dimensional vector = ";
    sum.show();
}