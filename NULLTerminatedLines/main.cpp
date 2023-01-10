//NULLTerminatedLines
#include<iostream>
#include<Windows.h>
using namespace std;

//TODO:
//В проекте NULLTerminatedLines реализовать следующие функции :
int  string_length(char str[]);			//Принимает строку и возвращает размер строки
void to_upper(char str[]);				//Переводит строку в верхний регистр
void to_lower(char str[]);				//Переводит строку в нижний регистр
void shrink(char str[]);				//Удаляет лишние пробелы из предложения
										//Хорошо      живет     на     свете      Винни      Пух
										//Хорошо живет на свете Винни Пух

bool is_palindrome(char str[]);			//Проверяет, является ли строка палиндромом

bool is_int_number(char str[]);			//Проверяет, является ли строка целым десятичным числом
int  to_int_number(char str[]);			//Если строка является целым десятичным числом, возвращает ее числовое значение
bool is_bin_number(char str[]);			//Проверяет, является ли строка двоичным числом
int  bin_to_dec(char str[]);			//Если строка является двоичным числом, возвращает ее десятичное значение
bool is_hex_number(char str[]);			//Проверяет, является ли строка шестнадцатеричным числом
int  hex_to_dec(char str[]);			//Если строка является шестнадцатеричным числом, возвращает ее десятичное значение

void main()
{
	setlocale(LC_ALL, "");
	//cout << "Hello Strings" << endl;
	//char str[] = { 'H', 'e', 'l', 'l', 'o', 0 };
	//char str[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
	//char str[] = "Hello";
	//cout << str << endl;
	//cout << sizeof(str) << endl;

	const int n = 100;
	char str[n] = {};
	SetConsoleCP(1251);
	cout << "Введите строку: ";// cin >> str;
	cin.getline(str, n);
	//SetConsoleCP(866);
	//cout << str << endl;
	
	cout << "\nФункция \'string_length(str)\': принимает строку и возвращает размер строки.\n";
	cout << "\n\tВведенная Вами строка содержит " << string_length(str) << " символов.\n";

	cout << "\nФункция \'to_upper(str)\': переводит строку в верхний регистр.\n";
	cout << "\n\tВведенная Вами строка в верхнем регистре будет выглядеть так:\n\t";
	to_upper(str);
	cout << endl;

	cout << "\nФункция \'to_lower(str)\': переводит строку в нижний регистр.\n";
	cout << "\n\tВведенная Вами строка в нижнем регистре будет выглядеть так:\n\t";
	to_lower(str);
	cout << endl;

	cout << "\nФункция \'shrink(str)\': удаляет лишние пробелы в тексте.\n";
	cout << "\n\tВведенная Вами строка без лишних пробелов:\n\t";
	shrink(str);
	cout << endl;
	cout << '\t' << str;

	cout << "\nФункция \'is_palindrome\': проверяет, является ли строка палиндромом.\n";
	if (is_palindrome(str)) cout << "Эта строка: \"" << str << "\" - палиндром!";
	else cout << "Это НЕ палиндром!";
	cout << endl;

	cout << "\nФункция \'is_int_number\': проверяет, является ли введенная строка целым десятичным числом.\n";
	(is_int_number(str)) ? cout << "Эта строка является числом!" : cout << "Эта строка НЕ является числом!";
	cout << endl;

	cout << "\nФункция \'to_int_number\': проверяет, является ли введенная строка целым десятичным числом и возвращает это число.\n";
	(is_int_number(str)) ? cout << "Введенная строка является десятичным числом " << to_int_number(str) : cout << "Эта строка НЕ является числом!";
	cout << endl;

	cout << "\nФункция \'is_bin_number\': проверяет, является ли введенная строка двоичным числом.\n";
	(is_bin_number(str)) ? cout << "Эта строка " << str << " является двоичным числом!" : cout << "Эта строка " << str << " НЕ является двоичным числом!";
	cout << endl;

	cout << "\nфункция \'bin_to_dec(char str[])\': проверяет, является ли введенная строка двоичным числом и возвращает это число в десятичном виде.\n";
	(is_bin_number(str)) ? cout << "введенная строка " << str << " является двоичным числом: " << bin_to_dec(str) : cout << "эта строка не является числом!";
	cout << endl;

	cout << "\nФункция \'is_hex_number\': проверяет, является ли введенная строка шестнадцатиричным числом.\n";
	(is_hex_number(str)) ? cout << "Эта строка " << str << " является шестнадцатиричным числом!" : cout << "Эта строка " << str << " НЕ является шестнадцатиричным числом!";
	cout << endl;

	cout << "\nФункция \'hex_to_dec(char str[])\': проверяет, является ли введенная строка шестнадцатиричным числом и возвращает это число в десятичном виде.\n";
	(is_hex_number(str)) ? cout << "Введенная строка " << str << " является шестнадцатиричным числом: " << hex_to_dec(str) : cout << "Эта строка НЕ является числом!";
	cout << endl;
}

int  string_length(char str[])		//Принимает строку и возвращает размер строки
{
	int i = 0;
	while (str[i] != 0)	i++;
	return i;
}

void to_upper(char str[])				//Переводит строку в верхний регистр
{
	for (int i = 0; i < string_length(str); i++)
	{
		if ((char)str[i] >= 0 && (char)str[i] <= 96) cout << char(str[i]);			//оставляем латинские символы верхнего регистра и прочие символы
		if ((char)str[i] > 96 && (char)str[i] < 123) cout << char(str[i] - 32);		//переводим латинские символы нижнего регистра в верхний
		if ((char)str[i] >= 123 && (char)str[i] <= 223) cout << char(str[i]);		//оставляем латинские символы верхнего регистра и прочие символы
		if ((char)str[i] > -33 && (char)str[i] < 0) cout << char(str[i] - 32);		//переводим кириллические символы нижнего регистра в верхний
		if ((char)str[i] > -65 && (char)str[i] < -32) cout << char(str[i]);			//оставляем кириллические символы верхнего регистра
	}
}

void to_lower(char str[])				//Переводит строку в нижний регистр
{
	for (int i = 0; i < string_length(str); i++)
	{
		if ((char)str[i] >= 0 && (char)str[i] <= 64) cout << char(str[i]);			//оставляем прочие символы
		if ((char)str[i] > 64 && (char)str[i] <= 90) cout << char(str[i] + 32);		//переводим латинские символы верхнего регистра в нижний
		if ((char)str[i] > 90 && (char)str[i] <= 191) cout << char(str[i]);			//оставляем латинские символы верхнего регистра и прочие символы
		if ((char)str[i] > -33 && (char)str[i] < 0) cout << char(str[i]);			//переводим кириллические символы нижнего регистра в верхний
		if ((char)str[i] > -65 && (char)str[i] < -32) cout << char(str[i] + 32);	//оставляем кириллические символы верхнего регистра
	}
}

void shrink(char str[])				//Удаляет лишние пробелы из предложения
{
	for (int i = 0; i < string_length(str); i++)
	{
		if (str[i] == 32 && str[i] == str[i - 1]) continue;
		cout << str[i];
	}
}

bool is_palindrome(char str[])	//Проверяет, является ли строка палиндромом
{
	for (int i = 0; i <= (string_length(str) / 2); i++)
	{
		if ((char)str[i] != (char)str[string_length(str) - i - 1]) return false;
		else continue;
	}
	return true;
}

bool is_int_number(char str[])	//Проверяет, является ли строка целым десятичным числом
{
	for (int i = 0; i < string_length(str); i++)
	{
		if ((char)str[i] > 47 && (char)str[i] < 58) continue;
		else return false;
	}
	return true;
}

int  to_int_number(char str[])			//Если строка является целым десятичным числом, возвращает ее числовое значение
{
	if (is_int_number(str))
	{
		int number = 0;
		for (int i = 0; i < string_length(str); i++)
		{
			number *= 10;
			number += str[i] - 48;
		}
		return number;
	}
	else
	{
		cout << "Эта строка не является целым десятичным числом!\n";
		return false;
	}
}

bool is_bin_number(char str[])	//Проверяет, является ли строка двоичным числом
{
	for (int i = 0; i < string_length(str); i++)
	{
		if ((char)str[i] == 49 || (char)str[i] == 48) continue;
		else return false;
	}
	return true;
}

int  bin_to_dec(char str[])			//Если строка является двоичным числом, возвращает ее десятичное значение
{
	if (is_bin_number(str))
	{
		int number = 0;
		for (int i = 1; i <= string_length(str); i++)
		{
			number *= 2;
			number += (str[i - 1] - 48);
		}
		return number;
	}
	else cout << "Это число не является двоичным.\n"; return 0;
}

bool is_hex_number(char str[])	//Проверяет, является ли строка шестнадцатеричным числом
{
	for (int i = 0; i < string_length(str); i++)
	{
		if ((char)str[i] > 47 && (char)str[i] < 58 || (char)str[i] > 64 && (char)str[i] < 71) continue;
		else return false;
	}
	return true;
}

int  hex_to_dec(char str[])			//Если строка является шестнадцатеричным числом, возвращает ее десятичное значение
{
	if (is_hex_number(str))
	{
		int number = 0;
		for (int i = 1; i <= string_length(str); i++)
		{
			number *= 16;
			if (str[i - 1] > 64)
			{
				number += (str[i - 1] - 55);
				cout << number << " - " << str[i - 1] << endl;
			}
			else
			{
				number += (str[i - 1] - 48);
				cout << number << " - " << str[i - 1] << endl;
			}
		}
		return number;
	}
	else cout << "Это число не является шестнадцатиричным.\n"; return 0;
}
