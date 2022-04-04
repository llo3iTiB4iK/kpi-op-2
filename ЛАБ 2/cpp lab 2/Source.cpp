#include "Header.h"
void File_Create(string name)
{
    bool mode;
    cout << "Do you want to append file (1) or create a clear file (0)? "; //запитати користувача в режим≥ перезапису чи дозапису в≥дкрити файл
    cin >> mode;
    ofstream outfile1;
    if (mode) outfile1.open(name, ios::app, ios::binary);
    else outfile1.open(name, ios::binary);
    Automobile A;
    cout << "Input the number of cars you want to add: ";  //запитати користувача ск≥льки автомоб≥л≥в хоче додати до списку
    int number; cin >> number;
    cin.ignore();
    for (int i = 0; i < number; i++) //дл€ кожного автомоб≥л€ зчитуЇмо модель, дату випуску ≥ дату надходженн€ у продаж, записуЇмо структуру з цим автомоб≥лем у файл
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
    while (file.read((char*)&A, sizeof(Automobile))) //поки можна, зчитати дан≥ про авто ≥ вивести на екран
        cout << A.Model << ' ' << A.ReleaseDate << ' ' << A.DateofSale << endl;
    file.close();
}
void NewAutosListCreate(string name1, string name2)
{
    ifstream file1(name1);
    ofstream file2(name2);
    Automobile A;
    string releaseYear="0000", releaseMonth="00", saleYear="0000", saleMonth="00"; //р≥к випуску, м≥с€ць випуску, р≥к надходженн€ у продаж, м≥с€ць надходженн€ у продаж
    while (file1.read((char*)&A, sizeof(Automobile)))
    {
        for (int i = 0; i < 2; i++) //м≥с€ць випуску чи надходженн€ у продаж при такому формат≥ запису буде зазначатись у першому-другому елементах р€дка
        {
            releaseMonth[i] = A.ReleaseDate[i];
            saleMonth[i] = A.DateofSale[i];
        }
        for (int i = 3; i < 7; i++) //р≥к випуску чи надходженн€ у продаж при такому формат≥ запису буде зазначатись у четвертому-сьомому по пор€дку елементах р€дка
        {
            releaseYear[i-3] = A.ReleaseDate[i];
            saleYear[i-3] = A.DateofSale[i];
        }
        if ((12*(stoi(saleYear)-stoi(releaseYear))+stoi(saleMonth)-stoi(releaseMonth))<=2) //щоб рахувати р≥зницю у м≥с€ц€х м≥ж датами випуску ≥ надходженн€ у продаж, треба р≥к другого м≥нус р≥к першого помножити на 12 (к≥льк≥сть м≥с€ц≥в у роц≥) додати м≥с€ць другого ≥ в≥дн€ти м≥с€ць першого
            file2.write((char*)&A, sizeof(Automobile));
    }
    file1.close();
    file2.close();
}
void AutosReleasedAfter(string name)
{
    cout << "\nInput the year to output autos released not earlier than: "; //запитати користувача, в≥д €кого року автомоб≥л≥ показати
    int X_year; cin >> X_year;
    ifstream file(name, ios::binary);
    Automobile A;
    string releaseYear="0000";  //р≥к випуску автомоб≥л€
    cout << "Autos released in or after " << X_year << ":"<<endl;
    while (file.read((char*)&A, sizeof(Automobile)))
    {
        for (int i=3; i<7; i++)  //таким же чином, €к ≥ в попередн≥й функц≥њ, д≥стаЇмо ≥з р€дка дату випуску автомоб≥л€
            releaseYear[i-3] = A.ReleaseDate[i];
        if (stoi(releaseYear) >= X_year)  //€кщо р≥к автомоб≥ль ≥з в≥дпов≥дного р€дка був випущений у вказаному роц≥ або ще нов≥ший, вивести дан≥ цього автомоб≥л€
        {
            cout << A.Model << ' ' << A.ReleaseDate << ' ' << A.DateofSale << endl;
        }
    }
    file.close();
}