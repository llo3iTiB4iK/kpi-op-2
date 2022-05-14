#include "R3_Vector.h"

void R3_Vector::input(string s)
{
    cout << "Input coordinates for vector " << s << " : " << endl;
    cout << "x = "; float x1; cin >> x1;
    cout << "y = "; float y1; cin >> y1;
    cout << "z = "; float z1; cin >> z1;
    x = x1; y = y1; z = z1;
    float arr[3] = { x1,y1,z1 };
    initialize(3, arr);
}

const R3_Vector R3_Vector::operator+=(const R3_Vector vec)
{
    x += vec.x;
    y += vec.y;
    z += vec.z;
    coordinates[0] += vec.x;
    coordinates[1] += vec.y;
    coordinates[2] += vec.z;
    return *this;
}