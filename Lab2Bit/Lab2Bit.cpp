#include <iostream>
#include <conio.h>
#include "Set.h"
#include "BitField.h"
#include <exception>

using namespace std;

int main()
{
	Set* s1 = new Set(100);
	Set* s2 = new Set(100);

	setlocale(LC_ALL, "RUS");
	while (true)
	{
		int val;
		_getch();
		system("cls");
		cout << "1. Ввести множество\n2. Вывести множество\n3. Добавить элемент в множество\n4. Исключить элемент из множества.\n5. Проверить наличие элемента в множестве\n6. Объединение множеств\
			\n7. Пересечение множеств\n0. Выход\n";
		int choose;
		cin >> choose;
		try {
			switch (choose)
			{
			case 0:
				exit(0);

			case 1:
				cin >> *s1;
				break;

			case 2:
				cout << *s1;
				break;

			case 3:
				cout << "Введите значение элемента: ";
				cin >> val;
				s1->turnOn(val);
				break;

			case 4:
				cout << "Введите значение элемента: ";
				cin >> val;
				s1->turnOff(val);
				break;

			case 5:
				cout << "Введите значение элемента: ";
				cin >> val;
				if (s1->getValue(val))
					cout << "Элемент " << val << " находится в множестве";
				else cout << "Элемент " << val << " не находится в множестве";
				break;

			case 6:
				cout << "Введите 2-е множество\n";
				cin >> *s2;
				cout << *s1 + *s2;
				break;

			case 7:
				cout << "Введите 2-е множество\n";
				cin >> *s2;
				cout << *s1 * *s2;
				break;

			default:
				continue;
			}
		}
		catch (exception e)
		{
			cout << e.what() << endl;
		}
	}

	return 0;
}