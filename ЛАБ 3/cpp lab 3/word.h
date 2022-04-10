#pragma once

#include <iostream>
#include <string>
using namespace std;

class Word
{
	int length;  //довжина слова
	string text;  //текст слово
public:
	void setLength(int len) { length = len; }  //сеттер довжини слова
	int getLength() { return length; }  //геттер довжини слова

	int findNumOfDigits();  //метод знаходження у слові кількості цифр

	void setText(string txt) { text = txt; }  //сеттер тексту слова
	string getText() { return text; }  //геттер тексту слова
};