#include "task.h"
#include <list>
#include <iostream>
#include <limits>

using namespace std;

inline void display_menu()
{
	cout << "\n1 - ��������� ��������� ���� ���������� �������\n";
	cout << "2 - ������ ������ �� �����\n";
	cout << "3 - ���������� ��������������\n";
	cout << "4 - ��������� ����� ��������� �������\n";
	cout << "5 - ��������� ������� �������������� ��������� �������\n";
	cout << "6 - ������� ������\n";
	cout << "\n0 - �����\n";
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
				cout << "������� ��� �����: ";
				char fname[1024];
				cin.getline(fname, 1024);
				unsigned n; int m; char use;
				cout << "\n������� ���-�� �����: "; cin >> n;
				cout << "\n������� ������ �������� �����: "; cin >> m;
				cout << "\n1 - ������������ std::generate, ���� ���� - �� ������������: "; cin >> use;
				try {
					fill(n, m, fname, !(use - '1'));
				}
				catch (exception e)
				{
					cout << "������ ���������� �����\n" << e.what() << "\n";
				}
				cout << "���������\n<enter, ����� ����������>";
				getchar();
				break;
			}

			case '2':
			{
				try {
					cout << "������� ��� �����: ";
					char fname[1024];
					cin.getline(fname, 1024);
					l = get_list(fname);
					exists = true;
				}
				catch (exception e)
				{
					cout << "������ ������ �����\n" << e.what() << "\n";
				}
				cout << "���������\n<enter, ����� ����������>";
				getchar();
				break;
			}

			case '3':
			{
				if (!exists)
				{
					cout << "������ �� ����� <enter, ����� ����������>";
					getchar();
					continue;
				}
				cout << "�������� ������ ��������������: \n"\
					"1 - �������\n"\
					"2 - transform\n"\
					"3 - foreach\n";
				char c1, c2;
				cin >> c1;
				cout << "������� ���������� ���������? (1 - ��)\n";
				cin >> c2;
				list<double>::iterator b, e;
				b = l.begin();
				e = l.end();
				double avg = average(l);
				if (c2 == '1')
				{
					int i1, i2;
					cout << "������� ������� ������ ��������� (������������)\n";
					cout << "������ ������: "; cin >> i1;
					cout << "������ �����: "; cin >> i2;
					if ((i1 < 0) || (i1 > i2) || (i2 >= l.size()))
					{
						cout << "������� ������ ������� <enter, ����� ����������>";
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
						cout << "��� ������ �������� ������, ������ ��������� <enter, ����� ����������>";
						getchar();
					}
				}
				catch (exception e)
				{
					cout << "������ ��������� ������\n" << e.what() << "\n";
				}
				cout << "���������\n<enter, ����� ����������>";
				cin.getline(s, 256);
				getchar();
				break;
			}

			case '4':
			{
				if (!exists)
				{
					cout << "������ �� ����� <enter, ����� ����������>";
					getchar();
					continue;
				}
				cout << "����� ��������� ������: " << sum(l) << "\n<enter, ����� ����������>";
				getchar();
				break;
			}

			case '5':
			{
				if (!exists)
				{
					cout << "������ �� ����� <enter, ����� ����������>";
					getchar();
					continue;
				}
				cout << "������� �������������� ��������� ������: " << average(l) << "\n<enter, ����� ����������>";
				getchar();
				break;
			}

			case '6':
			{
				if (!exists)
				{
					cout << "������ �� ����� <enter, ����� ����������>";
					getchar();
					continue;
				}
				cout << "�������� ������ ������: \n"\
					"1 - ����� � ����\n"\
					"2 - ����� �� �����\n";
				char c;
				cin >> c;
				getchar();
				if (c == '1')
				{
					try {

						cout << "������� ��� �����: ";
						char fname[1024];
						cin.getline(fname, 1024);
						print(l, fname);
					}
					catch (...)
					{
						cout << "������ ���������� �����\n";
					}
				}
				else
					print(l);
				cout << "\n���������\n<enter, ����� ����������>";
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