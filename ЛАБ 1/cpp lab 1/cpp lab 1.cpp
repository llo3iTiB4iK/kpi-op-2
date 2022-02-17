#include "Header.h"
int main()
{
    string name1 = "source file.txt", name2 = "created file.txt";
    File_Create(name1);
    ReWrite(name1, name2);
    cout << "\nFile 1 content:" << endl; 
    Output(name1);
    cout << "\nFile 2 content:" << endl;
    Output(name2);
    return 0;
}

/*Створити текстовий файл. Переписати його вміст у новий текстовий файл, замінюючи кожен рядок символом '-', якщо 
він у вихідному файлі закінчується на літеру, відмінну від символа пропуску, коми або крапки. Вивести вміст вихідного і створеного файлів.
*/