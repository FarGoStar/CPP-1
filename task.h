#pragma once
#include <list>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

fstream fill(unsigned n, int m, string fname = "output.bin", bool use_std_generate = false);

list<double> get_list(string fname = "input.bin");

void modify(list<double>& lin);

void modify(list<double>::iterator begin, list<double>::iterator end, double avg);

void modify_transform(list<double>::iterator begin, list<double>::iterator end, double avg);

void modify_foreach(list<double>::iterator begin, list<double>::iterator end, double avg);

double sum(const list<double>& lin);

double average(const list<double>& lin);

void print(const list<double>& l);

void print(const list<double>& l, string fname);