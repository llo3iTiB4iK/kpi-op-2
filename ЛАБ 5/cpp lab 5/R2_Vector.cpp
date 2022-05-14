#include "R2_Vector.h"

void R2_Vector::input(string s)
{
    cout << "Input coordinates for vector " << s << " : " << endl;
    cout << "x = "; float x1; cin >> x1;
    cout << "y = "; float y1; cin >> y1;
    x = x1; y = y1;
    float arr[2] = { x1,y1 };
    initialize(2, arr);
}