#include "Header.h"

Tree_Node Tree_Fill()
{
    cout << "����i�� ������-���i�� ������:";
    char s;
    cin >> s;
    Tree_Node root(s); //����� ������
    cout << "����i�� '.' ��� ���i����� ��������" << endl;
    while (true)
    {
        cout << "����i�� ������: ";
        cin >> s;
        if (s != '.') root.insert(s);
        else break;
    }
    return root;
}

void Distance(Tree_Node root)
{
    char s;
    cout << "�� ����� ������� ���������� �i������ �i� ������? -> ";
    cin >> s;
    if (root.find_distance(s) != NULL)
        cout << "�i������ = " << root.find_distance(s) << endl;
}