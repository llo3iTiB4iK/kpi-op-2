#include "Header.h"

int main()
{
    setlocale(LC_ALL, "ukr");
    Tree_Node Tree = Tree_Fill(); //створюємо і заповнюємо бінарне дерево Tree
    cout << "Введене дерево: ";
    Tree.Print_Tree(); //виводимо наше дерево, починаючи від кореня
    Distance(Tree);  //знаходимо відстань від кореня до введеного символа
    return 0;
}