#include "stdafx.h"

	//---- возвращается индекс скобки " {" для пары с максимальной глубиной

void initString(char c[]);
int findBrace(char c[]);
int findEnd(char c[], int begin);
void extractSubstring(char c[], char b[], int begin, int end);
void printResult(char c[], char b[]);

void main()
{
	char c[255];
	char b[255] = { '\0' };
	initString(c);
	extractSubstring(c, b, findBrace(c), findEnd(c, findBrace(c)));
	printResult(c, b);
}

void initString(char c[])
{
	scanf("%s", c);
}
int findBrace(char c[])
{
	int k = 0;                                         // Счетчик вложенности
	int max = 0;                                    // Максимум вложенности
	int index = -1;                                         // Индекс максимальной " {"
	for (int i = 0; c[i] != 0; i++)
	{
		if (c[i] == '}')
		{
			k--;
		}
		if (c[i] == '{')
		{
			k++;
			if (k > max)
			{
				max = k;
				index = i;
			}
		}
	}
	if (k != 0)
	{
		return 0;                        // Защита " от дурака" , нет парных скобок
	}
	return index;
}
int findEnd(char c[], int begin)
{
	int i = begin;
	while (c[i] != '}')
	{
		i++;
	}
	return i;
}
void extractSubstring(char c[], char b[], int begin, int end)
{
	int i = 0;
	for (i = 0; i < end - begin - 1 && c[i] != '\0'; i++)
	{
		b[i] = c[i + begin + 1];
	}
	for (i = 0; c[i] != '\0'; i++)
	{
		c[begin + i] = c[end + 1 + i];
	}
}
void printResult(char c[], char b[])
{
	printf("%s\n", c);
	printf("%s\n", b);
}
