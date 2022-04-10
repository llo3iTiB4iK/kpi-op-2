#include "Word.h"

int Word::findNumOfDigits()
{
	int num = 0;  //кількість цифр в поточному слові
	for (int i = 0; i < length; i++)
		if (isdigit(text[i])) num++;
	return num;
}