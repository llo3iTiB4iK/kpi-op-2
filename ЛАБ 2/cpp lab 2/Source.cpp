#include "Header.h"
void File_Create(string name)
{
    bool mode;
    cout << "Do you want to append file (1) or create a clear file (0)? "; //�������� ����������� � ����� ���������� �� �������� ������� ����
    cin >> mode;
    ofstream outfile1;
    if (mode) outfile1.open(name, ios::app, ios::binary);
    else outfile1.open(name, ios::binary);
    Automobile A;
    cout << "Input the number of cars you want to add: ";  //�������� ����������� ������ ��������� ���� ������ �� ������
    int number; cin >> number;
    cin.ignore();
    for (int i = 0; i < number; i++) //��� ������� ��������� ������� ������, ���� ������� � ���� ����������� � ������, �������� ��������� � ��� ���������� � ����
    {
        cout << "Input car model: "; cin>>A.Model;
        cout << "Input release date (MM.YYYY): "; cin>>A.ReleaseDate;
        cout << "Input date of sale (MM.YYYY): "; cin>>A.DateofSale;
        outfile1.write((char*)&A, sizeof(Automobile));
    }
    outfile1.close();
}
void Output(string name)
{
    ifstream file(name, ios::binary);
    Automobile A;
    while (file.read((char*)&A, sizeof(Automobile))) //���� �����, ������� ��� ��� ���� � ������� �� �����
        cout << A.Model << ' ' << A.ReleaseDate << ' ' << A.DateofSale << endl;
    file.close();
}
void NewAutosListCreate(string name1, string name2)
{
    ifstream file1(name1);
    ofstream file2(name2);
    Automobile A;
    string releaseYear="0000", releaseMonth="00", saleYear="0000", saleMonth="00"; //�� �������, ����� �������, �� ����������� � ������, ����� ����������� � ������
    while (file1.read((char*)&A, sizeof(Automobile)))
    {
        for (int i = 0; i < 2; i++) //����� ������� �� ����������� � ������ ��� ������ ������ ������ ���� ����������� � �������-������� ��������� �����
        {
            releaseMonth[i] = A.ReleaseDate[i];
            saleMonth[i] = A.DateofSale[i];
        }
        for (int i = 3; i < 7; i++) //�� ������� �� ����������� � ������ ��� ������ ������ ������ ���� ����������� � ����������-������� �� ������� ��������� �����
        {
            releaseYear[i-3] = A.ReleaseDate[i];
            saleYear[i-3] = A.DateofSale[i];
        }
        if ((12*(stoi(saleYear)-stoi(releaseYear))+stoi(saleMonth)-stoi(releaseMonth))<=2) //��� �������� ������ � ������ �� ������ ������� � ����������� � ������, ����� �� ������� ���� �� ������� ��������� �� 12 (������� ������ � ����) ������ ����� ������� � ������ ����� �������
            file2.write((char*)&A, sizeof(Automobile));
    }
    file1.close();
    file2.close();
}
void AutosReleasedAfter(string name)
{
    cout << "\nInput the year to output autos released not earlier than: "; //�������� �����������, �� ����� ���� �������� ��������
    int X_year; cin >> X_year;
    ifstream file(name, ios::binary);
    Automobile A;
    string releaseYear="0000";  //�� ������� ���������
    cout << "Autos released in or after " << X_year << ":"<<endl;
    while (file.read((char*)&A, sizeof(Automobile)))
    {
        for (int i=3; i<7; i++)  //����� �� �����, �� � � ��������� �������, ������ �� ����� ���� ������� ���������
            releaseYear[i-3] = A.ReleaseDate[i];
        if (stoi(releaseYear) >= X_year)  //���� �� ��������� �� ���������� ����� ��� ��������� � ��������� ���� ��� �� ������, ������� ��� ����� ���������
        {
            cout << A.Model << ' ' << A.ReleaseDate << ' ' << A.DateofSale << endl;
        }
    }
    file.close();
}