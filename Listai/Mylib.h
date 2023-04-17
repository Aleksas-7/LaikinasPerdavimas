#ifndef MYLIB_H
#define MYLIB_H

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <fstream>
#include <sstream>
#include <random>
#include <chrono>

#include <list>


using std::cin;
using std::copy;
using std::cout;
using std::endl;
using std::left;
using std::setprecision;
using std::setw;
using std::string;
using std::vector;
using std::sort;
using std::accumulate;
using std::ifstream;
using std::stringstream;
using std::swap;
using std::ofstream;

using std::list;

struct studentas {
  string vardas, pavarde;
  list<int> paz;
  int egz;
  double galutinis;
};


// func.cpp:
double rask_studento_galutini_vid(list<int> &paz, int egz);
double rask_studento_galutine_med(list<int> &paz, int egz);
int duok_man_int(int from, int to);
char duok_man_char(char a, char b, char c);
void spausd_v0_1(list<studentas> &st);
char duok_man_chara();

// failai.cpp:
void nuskaityk(list<studentas> &st, string f_pav);
void spausd_v0_2(list<studentas> &st);
void studentu_padalinimas(list<studentas> &nusk, list<studentas> &galv, int dydis);
void sukurk_v0_4(int dydis, int kiek_nd);

// stud.cpp:
studentas pildik(int kiek_nd);
void spausdink_stud(studentas &st);
void prikurk_studentu (list<studentas> &st, int kiek, int kiek_nd);

#endif