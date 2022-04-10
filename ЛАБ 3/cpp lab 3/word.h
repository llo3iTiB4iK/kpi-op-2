#pragma once

#include <iostream>
#include <string>
using namespace std;

class Word
{
	int length;  //������� �����
	string text;  //����� �����
public:
	void setLength(int len) { length = len; }  //������ ������� �����
	int getLength() { return length; }  //������ ������� �����

	int findNumOfDigits();  //����� ����������� � ���� ������� ����

	void setText(string txt) { text = txt; }  //������ ������ �����
	string getText() { return text; }  //������ ������ �����
};