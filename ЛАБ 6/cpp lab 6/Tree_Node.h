#pragma once

#include <iostream>
using namespace std;

struct Tree_Node
{
private:
    char key;
    Tree_Node* left, * right; //покажчики на лівий і правий нащадок вузла відповідно
public:
    Tree_Node(char symb) : key(symb) { left = nullptr; right = nullptr; } //конструктор з параметром-ключем
    void insert(char s); //вставка в дерево елемента з ключем s
    void Print_Tree(); //симетричний вивід дерева (або піддерева) з коренем root
    int find_distance(char s, int counter = 0); //знайти кількість гілок між цим вузлом і node2
};