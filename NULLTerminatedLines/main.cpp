//NULLTerminatedLines
#include<iostream>
#include<Windows.h>
using namespace std;

//TODO:
//� ������� NULLTerminatedLines ����������� ��������� ������� :
int  string_length(char str[]);			//��������� ������ � ���������� ������ ������
void to_upper(char str[]);				//��������� ������ � ������� �������
void to_lower(char str[]);				//��������� ������ � ������ �������
void shrink(char str[]);				//������� ������ ������� �� �����������
										//������      �����     ��     �����      �����      ���
										//������ ����� �� ����� ����� ���

bool is_palindrome(char str[]);			//���������, �������� �� ������ �����������

bool is_int_number(char str[]);			//���������, �������� �� ������ ����� ���������� ������
int  to_int_number(char str[]);			//���� ������ �������� ����� ���������� ������, ���������� �� �������� ��������
bool is_bin_number(char str[]);			//���������, �������� �� ������ �������� ������
int  bin_to_dec(char str[]);			//���� ������ �������� �������� ������, ���������� �� ���������� ��������
bool is_hex_number(char str[]);			//���������, �������� �� ������ ����������������� ������
int  hex_to_dec(char str[]);			//���� ������ �������� ����������������� ������, ���������� �� ���������� ��������

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
	cout << "������� ������: ";// cin >> str;
	cin.getline(str, n);
	//SetConsoleCP(866);
	//cout << str << endl;
	
	cout << "\n������� \'string_length(str)\': ��������� ������ � ���������� ������ ������.\n"
	cout << "\n\t��������� ���� ������ �������� " << string_length(str) << " ��������.\n";

	cout << "\n������� \'to_upper(str)\': ��������� ������ � ������� �������.\n";
	cout << "\n\t��������� ���� ������ � ������� �������� ����� ��������� ���:\n\t";
	to_upper(str);
	cout << endl;

	cout << "\n������� \'to_lower(str)\': ��������� ������ � ������ �������.\n";
	cout << "\n\t��������� ���� ������ � ������ �������� ����� ��������� ���:\n\t";
	to_lower(str);
	cout << endl;

	cout << "\n������� \'shrink(str)\': ������� ������ ������� � ������.\n";
	cout << "\n\t��������� ���� ������ ��� ������ ��������:\n\t";
	shrink(str);
	cout << endl;
	cout << '\t' << str;

	cout << "\n������� \'is_palindrome\': ���������, �������� �� ������ �����������.\n";
	if (is_palindrome(str)) cout << "��� ������: \"" << str << "\" - ���������!";
	else cout << "��� �� ���������!";
	cout << endl;

	cout << "\n������� \'is_int_number\': ���������, �������� �� ��������� ������ ����� ���������� ������.\n";
	(is_int_number(str)) ? cout << "��� ������ �������� ������!" : cout << "��� ������ �� �������� ������!";
	cout << endl;

	cout << "\n������� \'to_int_number\': ���������, �������� �� ��������� ������ ����� ���������� ������ � ���������� ��� �����.\n";
	(is_int_number(str)) ? cout << "��������� ������ �������� ���������� ������ " << to_int_number(str) : cout << "��� ������ �� �������� ������!";
	cout << endl;

	cout << "\n������� \'is_bin_number\': ���������, �������� �� ��������� ������ �������� ������.\n";
	(is_bin_number(str)) ? cout << "��� ������ " << str << " �������� �������� ������!" : cout << "��� ������ " << str << " �� �������� �������� ������!";
	cout << endl;

	cout << "\n������� \'bin_to_dec(char str[])\': ���������, �������� �� ��������� ������ �������� ������ � ���������� ��� ����� � ���������� ����.\n";
	(is_bin_number(str)) ? cout << "��������� ������ " << str << " �������� �������� ������: " << bin_to_dec(str) : cout << "��� ������ �� �������� ������!";
	cout << endl;

	cout << "\n������� \'is_hex_number\': ���������, �������� �� ��������� ������ ����������������� ������.\n";
	(is_hex_number(str)) ? cout << "��� ������ " << str << " �������� ����������������� ������!" : cout << "��� ������ " << str << " �� �������� ����������������� ������!";
	cout << endl;

	cout << "\n������� \'hex_to_dec(char str[])\': ���������, �������� �� ��������� ������ ����������������� ������ � ���������� ��� ����� � ���������� ����.\n";
	(is_hex_number(str)) ? cout << "��������� ������ " << str << " �������� ����������������� ������: " << hex_to_dec(str) : cout << "��� ������ �� �������� ������!";
	cout << endl;
}

int  string_length(char str[])		//��������� ������ � ���������� ������ ������
{
	int i = 0;
	while (str[i] != 0)	i++;
	return i;
}

void to_upper(char str[])				//��������� ������ � ������� �������
{
	for (int i = 0; i < string_length(str); i++)
	{
		if ((char)str[i] >= 0 && (char)str[i] <= 96) cout << char(str[i]);			//��������� ��������� ������� �������� �������� � ������ �������
		if ((char)str[i] > 96 && (char)str[i] < 123) cout << char(str[i] - 32);		//��������� ��������� ������� ������� �������� � �������
		if ((char)str[i] >= 123 && (char)str[i] <= 223) cout << char(str[i]);		//��������� ��������� ������� �������� �������� � ������ �������
		if ((char)str[i] > -33 && (char)str[i] < 0) cout << char(str[i] - 32);		//��������� ������������� ������� ������� �������� � �������
		if ((char)str[i] > -65 && (char)str[i] < -32) cout << char(str[i]);			//��������� ������������� ������� �������� ��������
	}
}

void to_lower(char str[])				//��������� ������ � ������ �������
{
	for (int i = 0; i < string_length(str); i++)
	{
		if ((char)str[i] >= 0 && (char)str[i] <= 64) cout << char(str[i]);			//��������� ������ �������
		if ((char)str[i] > 64 && (char)str[i] <= 90) cout << char(str[i] + 32);		//��������� ��������� ������� �������� �������� � ������
		if ((char)str[i] > 90 && (char)str[i] <= 191) cout << char(str[i]);			//��������� ��������� ������� �������� �������� � ������ �������
		if ((char)str[i] > -33 && (char)str[i] < 0) cout << char(str[i]);			//��������� ������������� ������� ������� �������� � �������
		if ((char)str[i] > -65 && (char)str[i] < -32) cout << char(str[i] + 32);	//��������� ������������� ������� �������� ��������
	}
}

void shrink(char str[])				//������� ������ ������� �� �����������
{
	for (int i = 0; i < string_length(str); i++)
	{
		if (str[i] == 32 && str[i] == str[i - 1]) continue;
		cout << str[i];
	}
}

bool is_palindrome(char str[])	//���������, �������� �� ������ �����������
{
	for (int i = 0; i <= (string_length(str) / 2); i++)
	{
		if ((char)str[i] != (char)str[string_length(str) - i - 1]) return false;
		else continue;
	}
	return true;
}

bool is_int_number(char str[])	//���������, �������� �� ������ ����� ���������� ������
{
	for (int i = 0; i < string_length(str); i++)
	{
		if ((char)str[i] > 47 && (char)str[i] < 58) continue;
		else return false;
	}
	return true;
}

int  to_int_number(char str[])			//���� ������ �������� ����� ���������� ������, ���������� �� �������� ��������
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
		cout << "��� ������ �� �������� ����� ���������� ������!\n";
		return false;
	}
}

bool is_bin_number(char str[])	//���������, �������� �� ������ �������� ������
{
	for (int i = 0; i < string_length(str); i++)
	{
		if ((char)str[i] == 49 || (char)str[i] == 48) continue;
		else return false;
	}
	return true;
}

int  bin_to_dec(char str[])			//���� ������ �������� �������� ������, ���������� �� ���������� ��������
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
	else cout << "��� ����� �� �������� ��������.\n"; return 0;
}

bool is_hex_number(char str[])	//���������, �������� �� ������ ����������������� ������
{
	for (int i = 0; i < string_length(str); i++)
	{
		if ((char)str[i] > 47 && (char)str[i] < 58 || (char)str[i] > 64 && (char)str[i] < 71) continue;
		else return false;
	}
	return true;
}

int  hex_to_dec(char str[])			//���� ������ �������� ����������������� ������, ���������� �� ���������� ��������
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
	else cout << "��� ����� �� �������� �����������������.\n"; return 0;
}
