#include "Header.h"
void File_Create(string name)
{
    bool mode;
    cout << "Do you want to append file (1) or create a clear file (0)? ";
    cin >> mode;
    ofstream outfile1;
    if (mode) outfile1.open(name, ios::app);
    else outfile1.open(name);
    cout << "Input text to the file. Press Ctrl+E to stop inputing\n";
    string str;
    bool flag = true;
    while (flag)
    {
        getline(cin, str);
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == 5)
            {
                flag = false;
                str.erase(i);
            }
        }
        if (str.size() > 0) outfile1 << str << endl;
    }
    outfile1.close();
}
void ReWrite(string name1, string name2)
{
    ifstream infile1(name1);
    ofstream file2(name2);
    string str;
    while (!infile1.eof())
    {
        getline(infile1, str);
        if (str.size() > 0)
        {
            if (str[str.size() - 1] == ' ' || str[str.size() - 1] == ',' || str[str.size() - 1] == '.') file2 << str << endl;
            else file2 << '-' << endl;
        }
    }
    infile1.close();
    file2.close();
}
void Output(string name)
{
    ifstream file(name);
    string str;
    while (!file.eof())
    {
        getline(file, str);
        cout << str << endl;
    }
    file.close();
}