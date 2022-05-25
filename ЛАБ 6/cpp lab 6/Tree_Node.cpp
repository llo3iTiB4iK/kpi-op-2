#include "Tree_Node.h"

void Tree_Node::insert(char s)
{
    if (s < key)
    {
        if (left == nullptr) left = new Tree_Node(s);
        else (*left).insert(s);
    }
    else if (s > key)
    {
        if (right == nullptr) right = new Tree_Node(s);
        else (*right).insert(s);
    }
    else cout << "������� � ����� ������ ��� � � �����i" << endl;
}

void Tree_Node::Print_Tree()
{
    if (left != nullptr) (*left).Print_Tree();
    cout << key << ' ';
    if (right != nullptr) (*right).Print_Tree();
}

int Tree_Node::find_distance(char s, int counter)
{
    if (key == s) return counter;
    else if (s < key)
    {
        if (left == nullptr) { cout << "�������� � ����� ������ � �����i ����..." << endl; return NULL; }
        else (*left).find_distance(s, ++counter);
    }
    else if (s > key)
    {
        if (right == nullptr) { cout << "�������� � ����� ������ � �����i ����..." << endl; return NULL; }
        else (*right).find_distance(s, ++counter);
    }

}