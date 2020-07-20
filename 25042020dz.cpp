/*
Модуль 8.
Рядки
ДОМАШНЯ РОБОТА №
Реалізувати власні функції для роботи з рядками не використовуючи стандартні бібліотеки
1. int mystrlen(const char* str); -функція визначає довжину рядка.
int mystrlen(const char* str) { // 1. int mystrlen (const char * str); - функція визначає довжину рядка.
	const char* cur = str;
	for (; *cur; ++cur);
	return cur - str;
}

2. char* mystrcpy(char* str1, const char* str2); -функція копіює рядок str2 в буфер, що адресується через str1.Функція повертає покажчик на перший рядок str1.
#include <iostream>
#include <Windows.h>
using namespace std;
int mystrlen(const char* str) {
	const char* cur = str;
	for (; *cur; ++cur);
	return cur - str;
}
char* mystrcpy(char* str1, const char* str2) {
	for (size_t i = 0; i <= mystrlen(str2); i++)
		str1[i] = str2[i];
	return str1;
}
int main() {
	char str1[1000]{ "str number 1" };
	char str2[]{ "str number 2" };
	cout << str1 << endl;
	mystrcpy(str1, str2);
	cout << str1;
}

3. char* mystrcat(char* str1, const char* str2); -функція приєднує рядок str2 до рядка str1.Функція повертає покажчик на перший рядок str1.
char* mystrcpy(char* str1, const char* str2) {// 2. char* mystrcpy(char* str1, const char* str2); - функція копіює рядок str2 в буфер,  що адресується через str1. Функція повертає покажчик на перший рядок str1.
	size_t lenstr1 = mystrlen(str1);
	for (size_t i = 0; i < mystrlen(str2); i++)
		str1[lenstr1 + i] = str2[i];
	return str1;
}

4. char* mystrchr(char* str, char s); -функція здійснює пошук символу s в рядку str.Функція повертає покажчик на перше входження символу в рядок, в іншому випадку 0.
#include <iostream>
#include <Windows.h>
using namespace std;
char* mystrchr(char* str, char s) {
	for (; *str; ++str) {
		if (*str == s) break;
	}
	return (char*)str;
}
int main() {
	SetConsoleOutputCP(1251);
	char str[100]{ "str number 1" };
	char str2[]{ "str number 2" };
	cout << mystrchr(str, 'r');
}

5. char* mystrstr(char* str1, char* str2); -функція здійснює пошук підрядка str2 в рядку str1.Функція повертає покажчик на перше входження підрядка str2 в рядок str1, в іншому випадку 0.
#include <iostream>
#include <Windows.h>
using namespace std;
int mystrlen(const char* str) {
	const char* cur = str;
	for (; *cur; ++cur);
	return cur - str;
}
char* mystrstr(char* str1, char* str2) {
	int k = 0;
	while (*str1 != '\0') {
		for (int i = 0; i < strlen(str2); i++) {
			if (*(str1 + i) == *(str2 + i)) k++;
		}
		if (k == strlen(str2)) return str1;
		str1++;
	}
	return 0;
}
int main() {
	char str1[]{ "sTrInG nUmBer 1 5f4A6s4F3G5673 &a&F(g&A@a#$r" };
	char str2[]{ "1" };
	cout << str1 << endl;
	cout << str2 << endl;
	cout << mystrstr(str1, str2);
}

6. int mystrcmp(const char* str1, const char* str2); -функція порівнює два рядки, і, якщо рядки рівні повертає 0, якщо перший рядок більше другий, то повертає 1, інакше - 1.
#include <iostream>
#include <Windows.h>
#include <assert.h>
using namespace std;
int mystrcmp(const char* str1, const char* str2) {
	assert(str1 && str2);
	do
	{
		if (*str1 > * str2) return 1; //первая строка больше второй
		if (*str1 < *str2) return -1; // иначе
	} while (*str1++ && *str2++);
	return 0; //равны
}
int main() {
	char str1[]{ "sTrInG nUmBer 1 5f4A6s4F3G5673 &a&F(g&A@a#$r" };
	char str2[]{ "sTrInG nUmBer 1 5f4A6s4F3G5673 &a&F(g&A@a#$r" };
	cout << mystrcmp(str1, str2);
}
7. int StringToNumber(char* str); -функція конвертує рядок в число і повертає це число.
#include <iostream>
using namespace std;
int StringToNumber(char* str) {
	int temp = 0;
	int i = 0;
	while (str[i] >= 0x20 && str[i] <= 0x7f) { // для “Базовая таблица кодировки ASCII”, з 32гої по 127му позицію
		temp = temp + (int)(str[i]);
		i++;
	}
	return(temp);
}
int main() {
	char str[]{ "str nu 2" }; //115+116+114+32+110+117+32+50=686
	cout << str << endl;
	cout << StringToNumber(str) << endl;
}

8. char* NumberToString(int number); -функція конвертує число в рядок і повертає покажчик на цей рядок.

9. char* Uppercase(char* str1); -функція перетворює рядок у верхній регістр.
#include <iostream>
using namespace std;
int mystrlen(const char* str) {
	const char* cur = str;
	for (; *cur; ++cur);
	return cur - str;
}
char* Uppercase(char* str1) {
	size_t numberInASCII = 0;
	size_t newnumberInASCII = 0;
	size_t lenghtstr1 = mystrlen(str1);
	for (size_t i = 0; i < lenghtstr1; i++)
	{
		if (int(str1[i]) >= 97 && int(str1[i]) <= 122) {
			numberInASCII = int(str1[i]);
			newnumberInASCII = numberInASCII - 32;
			str1[i] = char(newnumberInASCII);
		}
	}
	return str1;
}
int main() {
	char str1[]{ "sTrInG nUmBer 1 5f4A6s4F3G5673 &a&F(g&A@a#$r" };
	cout << str1 << endl;
	Uppercase(str1);
	cout << str1;
}

10.char* Lowercase(char* str1); -функція перетворює рядок у нижній регістр.
#include <iostream>
using namespace std;
int mystrlen(const char* str) {
	const char* cur = str;
	for (; *cur; ++cur);
	return cur - str;
}
char* Uppercase(char* str1) {
	size_t numberInASCII = 0;
	size_t newnumberInASCII = 0;
	size_t lenghtstr1 = mystrlen(str1);
	for (size_t i = 0; i < lenghtstr1; i++)
	{
		if (int(str1[i]) >= 97 && int(str1[i]) <= 122) {
			numberInASCII = int(str1[i]);
			newnumberInASCII = numberInASCII - 32;
			str1[i] = char(newnumberInASCII);
		}
	}
	return str1;
}
int main() {
	char str1[]{ "sTrInG nUmBer 1 5f4A6s4F3G5673 &a&F(g&A@a#$r" };
	cout << str1 << endl;
	Uppercase(str1);
	cout << str1;
}

11.char* mystrrev(char* str); -функція реверсує рядок і повертає покажчик на новий рядок.
#include <iostream>
using namespace std;
int mystrlen(const char* str) {
	const char* cur = str;
	for (; *cur; ++cur);
	return cur - str;
}
char* mystrrev(char* str) {
	for (int i = 0, j = strlen(str) - 1; i < j; ++i, --j)
		swap(str[i], str[j]);
	return str;
}
int main() {
	char str[]{ "sTrInG nUmBer 1 5f4A6s4F3G5673 &a&F(g&A@a#$r" };
	cout << str << endl;
	mystrrev(str);
	cout << str;
}
*/

