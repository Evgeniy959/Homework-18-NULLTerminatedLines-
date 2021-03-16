#include <iostream>
#include<Windows.h>
#include<ctype.h>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;

void InputLine(char str[], const int n);
int StrLen(char str[]); // Возвращает размер строки
void to_upper(char str[]);	//Переводит строку в верхний регистр
void to_lower(char str[]);	//Переводит строку в нижний регистр
void capitalize(char str[]);	//Первую букву каждого слова в предложении делает заглавной
void shrink(char str[]);	//Убирает из строки лишние пробелы, например: Хорошо        живет    на   всете       Винни-Пух
                            //Хорошо живет на всете Винни-Пух
//bool is_palindrome(char str[]);	//Определяет, является ли строка палиндромом

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
	/*to_lower(str);
	cout << str << endl;*/
	capitalize(str);
	cout << str << endl;
	shrink(str);
	cout << str << endl;
	//cout << (is_palindrome(str) ? " " : " ") << endl;
	//cout << str << endl;

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
		//else if (str[i] == ' ')str[i] -= 16;
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
		//else if (str[i] == ' ')str[i] += 16;
	}
}

void capitalize(char str[])
{
	to_lower(str);
	if (str[0] >= 'a' && str[0] <= 'z' || str[0] >= 'а' && str[0] <= 'я')str[0] -= 32;
	else if (str[0] == '¸')str[0] -= 16;
	for (int i = 1; str[i]; i++)
	{
		if ((str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'а' && str[i] <= 'я') && str[i - 1] == ' ')str[i] -= 32;
		else if (str[i] == '¸' && str[i - 1] == ' ')str[i] -= 16;
	}
}

void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
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
			for (int j = i; str[j]; j++)str[j] = str[j + 1];
		}
	}
}

bool is_palindrome(char str[])
{
	int size = StrLen(str);
	char* buffer = new char[size + 1]{};
	strcpy(buffer, str);// копирует строку str в строку буфер 
	to_lower(buffer);
	remove_symbol(buffer, ' ');
	size = strlen(buffer);
	for (int i = 0; i < size / 2; i++)
	{
		if (buffer[i] != buffer[size - 1 - i])
		{
			delete[] buffer;
			return false;
		}
	}
	delete[] buffer;
	return true;
}