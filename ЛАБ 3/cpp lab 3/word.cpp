#include "Word.h"

int Word::findNumOfDigits()
{
	int num = 0;  //������� ���� � ��������� ����
	for (int i = 0; i < length; i++)
		if (isdigit(text[i])) num++;
	return num;
}