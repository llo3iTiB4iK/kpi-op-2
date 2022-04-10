#pragma once

#include <iostream>
#include <stdio.h>
#include <string>
#include "Word.h"
using namespace std;

Word* Array_Create(unsigned int&);
void MemClear(Word*);
void Output(Word*, unsigned int);
void WordWithMostDigits(Word*, unsigned int);