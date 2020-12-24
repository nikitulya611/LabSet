#include <iostream>
#include <conio.h>
#include "Set.h"
#include <exception>

using namespace std;

void inputSet(Set& s)
{
	cout << "Введите мощность множества: ";
	int size;
	cin >> size;
	s = Set(size);
	cout << "Введите элементы множества\n";
	cin >> s;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	Set s1(1);
	Set s2(1);

	inputSet(s1);

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
				inputSet(s1);
				break;

			case 2:
				cout << "В виде множества: " << s1 << endl;
				cout << "В виде битового поля: " << s1.getBitField();
				break;

			case 3:
				cout << "Введите значение элемента: ";
				cin >> val;
				s1.turnOn(val);
				break;

			case 4:
				cout << "Введите значение элемента: ";
				cin >> val;
				s1.turnOff(val);
				break;

			case 5:
				cout << "Введите значение элемента: ";
				cin >> val;
				if (s1.getValue(val))
					cout << "Элемент " << val << " находится в множестве";
				else cout << "Элемент " << val << " не находится в множестве";
				break;

			case 6:
				inputSet(s2);
				if ((s1 + s2).isEmpty())
					cout << "Пустое множество";
				else cout << (s1 + s2);
				break;

			case 7:
				inputSet(s2);
				if ((s1 * s2).isEmpty())
					cout << "Пустое множество";
				else cout << (s1 * s2);
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