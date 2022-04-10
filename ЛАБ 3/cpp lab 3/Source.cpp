#include "Header.h"

Word* Array_Create(unsigned int &n)
{
	cout << "How much words you want to create? ";
	cin >> n;  //�������� ������� ���
	Word* Arr = new Word[n];  //��������� ���������� ���������� ������
	srand(time(NULL));
	string str;  //���������� �����
	for (int i = 0; i < n; i++)
	{
		int len = rand() % 30 + 1; //�������� ����� �� 1 �� 30 - ������� �����
		Arr[i].setLength(len);
		for (int k = 0; k < len; k++)
			str+=(char)(48+rand() % 75);  //������ �� ���������� ����������� ����� len �������, �� ����������� �������� � ���� ������� ������� ASCII, �� �������� �������� ������� � ���������� ������ �� ����� 
		Arr[i].setText(str);  //�������� ���������� ����� � ����� �����
		str = "";
	}
	return Arr;
}

void Output(Word* Array, unsigned int size)
{
	cout << "\n";
	for (int i = 0; i < size; i++)
	{
		cout<<"Word "<<i+1<<": "<<Array[i].getText()<<endl;
	}
}

void WordWithMostDigits(Word* Array, unsigned int size)
{
	int MaxDigitsIndex = 0;  //������ �����, �� ������ �������� ������� ����
	for (int i = 1; i < size; i++)
		if (Array[i].findNumOfDigits() > Array[MaxDigitsIndex].findNumOfDigits()) MaxDigitsIndex = i;
	cout << "\nWord " << MaxDigitsIndex + 1 << " contains the biggest number of digits(" << Array[MaxDigitsIndex].findNumOfDigits() << ")\n";
}

void MemClear(Word* Array)
{
	delete[] Array;
}
