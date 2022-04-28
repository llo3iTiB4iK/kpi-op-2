#include "Header.h"

int main()
{
    setlocale(LC_ALL, "ukr");
    const int n = 4;
    cout << "Полiном вигляду C0 + C1*(x^1) + C2*(x^2) + C3*(x^3)" << endl;
    float quots[n]; //масив коефіцієнтів поліному 1
    cout << "Коефiцiєнти для P1:"<<endl;
    for (int i = 0; i < n; i++) //ініціалізація масиву коефіцієнтів для Р1
    {
        cout << "C" << i << " = ";
        cin >> quots[i];
    }
    Polynom P1(quots,n); //виклик конструктора з параметрами для ініціалізації Р1
    Polynom P2; //виклик конструктора за замовчуванням для ініціалізації Р2
    Polynom P3(P1); //виклик конструктора копіювання для Р3
    cout << "P1 = ";
    Polynom_Output(P1);
    cout << "P2 = ";
    Polynom_Output(P2);
    cout << "P3 = ";
    Polynom_Output(P3);
    cout << "На яку величину будемо збiльшувати Р1 i зменшувати Р2? k = ";
    float k;
    cin >> k;
    P1 += k;
    P2 -= k;
    cout << "P1 = ";
    Polynom_Output(P1);
    cout << "P2 = ";
    Polynom_Output(P2);
    if (P1 == P2) cout << "Полiноми Р1 i Р2 рiвнi\n";
    else cout << "Полiноми Р1 i Р2 НЕ рiвнi\n";
    cout << "Значення полiнома Р3 будемо обчислювати в точцi х = ";
    float x; cin >> x;
    cout << "P3(" << x << ") = " << P3.value(x) << endl;;
    return 0;
}