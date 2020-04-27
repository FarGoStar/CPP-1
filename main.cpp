#include "task.h"
#include <list>
#include <iostream>
#include <limits>

using namespace std;

inline void display_menu()
{
	cout << "\n1 - Заполнить текстовый файл случайными числами\n";
	cout << "2 - Ввести список из файла\n";
	cout << "3 - Произвести преобразование\n";
	cout << "4 - Вычислить сумму элементов вектора\n";
	cout << "5 - Вычислить среднее арифметическое элементов вектора\n";
	cout << "6 - Вывести список\n";
	cout << "\n0 - Выход\n";
}

void menu()
{
	list<double> l;
	bool exists = false;

	char c;
	string s;

	do {

		system("cls");
		display_menu();

		char s[256];
		cin.getline(s, 256);
		c = s[0];

		switch (c)
		{
			case '1':
			{
				cout << "Введите имя файла: ";
				char fname[1024];
				cin.getline(fname, 1024);
				unsigned n; int m; char use;
				cout << "\nВведите кол-во чисел: "; cin >> n;
				cout << "\nВведите радиус разброса чисел: "; cin >> m;
				cout << "\n1 - использовать std::generate, иной ввод - не использовать: "; cin >> use;
				try {
					fill(n, m, fname, !(use - '1'));
				}
				catch (exception e)
				{
					cout << "Ошибка заполнения файла\n" << e.what() << "\n";
				}
				cout << "Завершено\n<enter, чтобы продолжить>";
				getchar();
				break;
			}

			case '2':
			{
				try {
					cout << "Введите имя файла: ";
					char fname[1024];
					cin.getline(fname, 1024);
					l = get_list(fname);
					exists = true;
				}
				catch (exception e)
				{
					cout << "Ошибка чтения файла\n" << e.what() << "\n";
				}
				cout << "Завершено\n<enter, чтобы продолжить>";
				getchar();
				break;
			}

			case '3':
			{
				if (!exists)
				{
					cout << "Список не задан <enter, чтобы продолжить>";
					getchar();
					continue;
				}
				cout << "Выберите способ преобразования: \n"\
					"1 - обычное\n"\
					"2 - transform\n"\
					"3 - foreach\n";
				char c1, c2;
				cin >> c1;
				cout << "Указать промежуток обработки? (1 - да)\n";
				cin >> c2;
				list<double>::iterator b, e;
				b = l.begin();
				e = l.end();
				double avg = average(l);
				if (c2 == '1')
				{
					int i1, i2;
					cout << "Введите индексы границ обработки (включительно)\n";
					cout << "Индекс начала: "; cin >> i1;
					cout << "Индекс конца: "; cin >> i2;
					if ((i1 < 0) || (i1 > i2) || (i2 >= l.size()))
					{
						cout << "Индексы заданы неверно <enter, чтобы продолжить>";
						cin.getline(s, 256);
						getchar();
						continue;
					}
					i2 -= i1;
					for (; (b != e) && (i1 > 0); --i1, ++b);
					list<double>::iterator i = b;
					for (; (i != e) && (i2 > 0); --i2, ++i);
					e = i++;
				}

				try {
					switch (c1)
					{
					case '1':
						modify(b, e, avg);
						break;
					case '2':
						modify_transform(b, e, avg);
						break;
					case '3':
						modify_foreach(b, e, avg);
						break;
					default:
						cout << "Нет такого варианта ответа, отмена обработки <enter, чтобы продолжить>";
						getchar();
					}
				}
				catch (exception e)
				{
					cout << "Ошибка обработки списка\n" << e.what() << "\n";
				}
				cout << "Завершено\n<enter, чтобы продолжить>";
				cin.getline(s, 256);
				getchar();
				break;
			}

			case '4':
			{
				if (!exists)
				{
					cout << "Список не задан <enter, чтобы продолжить>";
					getchar();
					continue;
				}
				cout << "Сумма элементов списка: " << sum(l) << "\n<enter, чтобы продолжить>";
				getchar();
				break;
			}

			case '5':
			{
				if (!exists)
				{
					cout << "Список не задан <enter, чтобы продолжить>";
					getchar();
					continue;
				}
				cout << "Среднее арифметическое элементов списка: " << average(l) << "\n<enter, чтобы продолжить>";
				getchar();
				break;
			}

			case '6':
			{
				if (!exists)
				{
					cout << "Список не задан <enter, чтобы продолжить>";
					getchar();
					continue;
				}
				cout << "Выберите способ вывода: \n"\
					"1 - вывод в файл\n"\
					"2 - вывод на экран\n";
				char c;
				cin >> c;
				getchar();
				if (c == '1')
				{
					try {

						cout << "Введите имя файла: ";
						char fname[1024];
						cin.getline(fname, 1024);
						print(l, fname);
					}
					catch (...)
					{
						cout << "Ошибка заполнения файла\n";
					}
				}
				else
					print(l);
				cout << "\nЗавершено\n<enter, чтобы продолжить>";
				getchar();
				break;
			}
		}

	} while (c != '0');
}



int main()
{
	setlocale(0, "RUS");
	menu();

	return 0;
}