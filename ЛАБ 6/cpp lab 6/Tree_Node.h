#pragma once

#include <iostream>
using namespace std;

struct Tree_Node
{
private:
    char key;
    Tree_Node* left, * right; //��������� �� ���� � ������ ������� ����� ��������
public:
    Tree_Node(char symb) : key(symb) { left = nullptr; right = nullptr; } //����������� � ����������-������
    void insert(char s); //������� � ������ �������� � ������ s
    void Print_Tree(); //����������� ���� ������ (��� ��������) � ������� root
    int find_distance(char s, int counter = 0); //������ ������� ���� �� ��� ������ � node2
};