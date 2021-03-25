#include <iostream>
#include<Windows.h>
using namespace std;

void InputLine(char str[], const int n);
int StrLen(char str[]); // Возвращает размер строки
void to_upper(char str[]);	//Переводит строку в верхний регистр
void to_lower(char str[]);	//Переводит строку в нижний регистр
void capitalize(char str[]);	//Первую букву каждого слова в предложении делает заглавной
void shrink(char str[]);	//Убирает из строки лишние пробелы, например: Хорошо        живет    на   всете       Винни-Пух
                            //Хорошо живет на всете Винни-Пух
void remove_symbol(char str[], char symbol);
bool is_palindrome(char str[]);	//Определяет, является ли строка палиндромом
bool is_int_number(char str[]);	//Определяет, является ли строка целым числом, то есть, состоит только из цифр
int  to_int_number(char str[]);	//Если строка является числом, то функция возвращает значение этого числа
bool is_bin_number(char str[]); // Проверка того что является ли строка двоичным числом
int  bin_to_dec(char str[]);	//Если строка является двоичным числом, то функция возвращает его десятичное значение

void main()
{
	setlocale(LC_ALL, "RUS");
	{
		for (int i = 0; i < 256; i++)
		{
			cout << char(i) << "-" << i << " " << endl;
		}
	}
	
	const int n = 256;
	char str[n];
	cout << "Введите строку: ";
	InputLine(str, n);
	cout << str << endl; //CP866
	cout << "колличество символов:  " << sizeof(str) << endl;
	cout << "Длина введенной строки: " << StrLen(str) << " символов" << endl;
	to_upper(str);
	cout << str << endl;
	to_lower(str);
	cout << str << endl;
	capitalize(str);
	cout << str << endl;
	shrink(str);
	cout << str << endl;
	remove_symbol(str, ' ');
	cout << str << endl;
	cout << "Строка" << (is_palindrome(str) ? "" : "НЕ ") << "является полиндромом!" << endl;
	cout << str << endl;
	cout << "Строка" << (is_int_number(str) ? "" : "НЕ ") << "является числом!" << endl;
	cout << str << endl;
	cout << "Значение введеного числа" << (to_int_number(str) << endl;
	cout << str << endl;
	cout << "Строка" << (is_bin_number(str) ? "" : "НЕ ") << "является двоичным числом!" << endl;
	cout << str << "(bin) = " << bin_to_dec(str) << "(dec)" << endl;
}
void InputLine(char str[], const int n)
{
	SetConsoleCP(1251);
	cin.getline(str, n);
	SetConsoleCP(866);
}
int StrLen(char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}

void to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'а' && str[i] <= 'я')
		{
			str[i] -= 32;
		}
		else if (str[i] == 'ё')str[i] -= 16;
	}
	
}

void to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'А' && str[i] <= 'Я')
		{
			str[i] += 32;
		}
		else if (str[i] == 'Ё')str[i] += 16;
	}
}

void capitalize(char str[])
{
	to_lower(str);
	if (str[0] >= 'a' && str[0] <= 'z' || str[0] >= 'а' && str[0] <= 'я')str[0] -= 32;
	else if (str[0] == 'ё')str[0] -= 16;
	for (int i = 1; str[i]; i++)
	{
		if ((str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'а' && str[i] <= 'я') && str[i - 1] == ' ')str[i] -= 32;
		else if (str[i] == 'ё' && str[i - 1] == ' ')str[i] -= 16;
	}
}

void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && (str[i + 1] == ' '|| str[i + 1] = 0 || str[0] == ' ')
		{
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
}

void remove_symbol(char str[], char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++)str[j] = str[j + 1]; n--;
		}
	}
}

bool is_palindrome(char str[])
{
	int n = StrLen(str);
	char* buffer = new char[n + 1]{};
	strcpy_s(buffer, n + 1, str);// копирует строку str в строку буфер 
	to_lower(buffer);
	remove_symbol(buffer, ' ');
	n = strlen(buffer);
	for (int i = 0; i < n / 2; i++)
	{
		if (buffer[i] != buffer[n - 1 - i])
		{
			delete[] buffer;
			return false;
		}
	}
	delete[] buffer;
	return true;
}

bool is_int_number(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ' ')return false;
		if (str[i] == ' ' && str[i + 1] == ' ')return false;
	}
	return true;
}
int  to_int_number(char str[])
{
	if (!is_int_number(str))return 0;
	int number = 0; //значение числа
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != ' ')
		{
			number *= 10; //сдвигаем число на 1 разряд влево чтобы освободить младший разряд для следующей цифры 
			number += str[i] - 48; //48 ASCII код символа '0'
		}
	}
	return number;
}
bool is_bin_number(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != ' ')
			return false;
		if (str[i - 1] == ' ' && str[i] == ' ' && str[i + 1] == ' ')
			return false;
	}
	return true;
}
int  bin_to_dec(char str[])
{
	if (!is_bin_number(str))return 0;
	int n = StrLen(str);
	int decimal = 0;	
	int weight = 1;		
	for (int i = n - 1; i >= 0; i--)
	{
		if (str[i] != ' ')
		{
			decimal += (str[i] - 48) * weight;
			weight *= 2;
		}
	}
	return decimal;
}