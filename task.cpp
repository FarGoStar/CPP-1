#include "task.h"

using namespace std;

fstream fill(unsigned n, int m, string fname, bool use_std_generate)
{
	list<double> l(n);
	if (use_std_generate)
		generate(l.begin(), l.end(), [m] {return rand() % (2 * m) - m; });
	else
		for (list<double>::iterator i = l.begin(); i != l.end(); ++i)
			*i = rand() % (2 * m) - m;
	fstream fs;
	fs.open(fname, ios::out);
	for (double num : l)
	{
		fs << num << " ";
	}
	fs.close();
	getchar();
	return fs;
}

list<double> get_list(string fname)
{
	ifstream ifs;
	ifs.open(fname, ios::in);
	if (!ifs)
		throw exception("Файл не существует");
	list<double> l;
	double num;
	while (ifs >> num)
		l.push_back(num);
	if (l.size() == 0)
		cout << "Файл пуст" << endl;
	return l;
}

void modify(list<double>& lin)
{
	double avg = average(lin);
	modify(lin.begin(), lin.end(), avg);
}

void modify(list<double>::iterator begin, list<double>::iterator end, double avg)
{
	for (list<double>::iterator i = begin; i != end; ++i)
		if (*i == 0)
			*i = avg;
}

void modify_transform(list<double>::iterator begin, list<double>::iterator end, double avg)
{
	transform(begin, end, begin, [avg](double num) {if (num == 0) return num += avg; else return num; });
}

void modify_foreach(list<double>::iterator begin, list<double>::iterator end, double avg)
{
	for_each(begin, end, [avg](double& num) {if (num == 0) return num += avg; else return num; });
}

double sum(const list<double>& lin)
{
	double s = 0;
	for (double num : lin)
		s += num;
	return s;
}

double average(const list<double>& lin)
{
	return (double)sum(lin) / lin.size();
}

void print(const list<double>& l, ostream& os)
{
	for (double num : l)
		os << num << " ";
}

void print(const list<double>& l)
{
	print(l, cout);
}

void print(const list<double>& l, string fname)
{
	ofstream of;
	of.open(fname, ios::app);
	print(l, of);
	of.close();
}
