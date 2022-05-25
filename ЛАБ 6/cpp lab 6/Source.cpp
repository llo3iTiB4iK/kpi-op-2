#include "Header.h"

Tree_Node Tree_Fill()
{
    cout << "Введiть символ-корiнь дерева:";
    char s;
    cin >> s;
    Tree_Node root(s); //корінь дерева
    cout << "Введiть '.' щоб закiнчити введення" << endl;
    while (true)
    {
        cout << "Введiть символ: ";
        cin >> s;
        if (s != '.') root.insert(s);
        else break;
    }
    return root;
}

void Distance(Tree_Node root)
{
    char s;
    cout << "До якого символа шукатимемо вiдстань вiд кореня? -> ";
    cin >> s;
    if (root.find_distance(s) != NULL)
        cout << "Вiдстань = " << root.find_distance(s) << endl;
}