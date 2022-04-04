#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Automobile
{
    char Model[20], ReleaseDate[8], DateofSale[8];   //модель, дата випуску і дата надходження у продаж
};

void File_Create(string);
void NewAutosListCreate(string, string);
void Output(string);
void AutosReleasedAfter(string);