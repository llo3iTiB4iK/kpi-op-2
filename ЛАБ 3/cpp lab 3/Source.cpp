#include "Header.h"

Word* Array_Create(unsigned int &n)
{
	cout << "How much words you want to create? ";
	cin >> n;  //введення кількості слів
	Word* Arr = new Word[n];  //створення відповідного динамічного масиву
	srand(time(NULL));
	string str;  //тимчасовий рядок
	for (int i = 0; i < n; i++)
	{
		int len = rand() % 30 + 1; //генеруємо число від 1 до 30 - довжину слова
		Arr[i].setLength(len);
		for (int k = 0; k < len; k++)
			str+=(char)(48+rand() % 75);  //додаємо до порожнього тимчасового рядка len символів, що генеруються рандомно з того проміжку таблиці ASCII, де основною частиною символів є англійський алфавіт та цифри 
		Arr[i].setText(str);  //записуємо тимчасовий рядок у текст слова
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
	int MaxDigitsIndex = 0;  //індекс слова, що містить найбільшу кількість цифр
	for (int i = 1; i < size; i++)
		if (Array[i].findNumOfDigits() > Array[MaxDigitsIndex].findNumOfDigits()) MaxDigitsIndex = i;
	cout << "\nWord " << MaxDigitsIndex + 1 << " contains the biggest number of digits(" << Array[MaxDigitsIndex].findNumOfDigits() << ")\n";
}

void MemClear(Word* Array)
{
	delete[] Array;
}
