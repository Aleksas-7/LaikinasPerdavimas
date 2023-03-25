# include "Mylib.h"

// Ivesties tikrinimas:
// https://www.itcodar.com/c-plus-1/how-to-do-input-validation-in-c-with-cin.html

double rask_studento_galutini_vid(deque<int> paz, int egz) 
{
  double vidurkis = accumulate(paz.begin(), paz.end(), 0);
  vidurkis /= paz.size();
  return (0.4 * vidurkis) + (0.6 * egz);
}

double rask_studento_galutine_med(deque<int> paz, int egz) 
{
  double galutinis;
  sort(paz.begin(), paz.end());

  if (paz.size() % 2 == 0) {
    // Lyginio sk mediana
    galutinis = (1.0 * paz.at(paz.size() / 2) + paz.at((paz.size() / 2) - 1)) / 2.0;
  } 
  else {
    // Nelyginio sk mediana
    galutinis = paz.at((paz.size() - 1) / 2);
  }
  return (0.4 * galutinis) + (0.6 * egz);
}

int duok_man_int(int from, int to)
{
  int ats;
  while (true) {
    if (cin >> ats) {
      if (ats >= from && ats <= to) {
        return ats;
      }
      cout << "Iveskite skaičių nuo ";
      cout << from << " iki " << to << endl;
    } else {
      cout << "Iveskite skaičių nuo ";
      cout << from << " iki " << to << endl;
      cin.clear();
      cin.ignore(50, '\n');
    }
  }
}

char duok_man_char(char a = '.', char b = '.', char c = '.') 
{
  char ats;
  while (true) {
    if (cin >> ats) {
      if ((ats == a || ats == b || ats == c) && (ats != '.')) {
        return ats;
      }
      cout << "Ivestis turi būti " << a << " " << b << " " << c << endl;
    } else {
      cout << "Ivestis turi būti " << a << " " << b << " " << c << endl;
      cin.clear();
      cin.ignore(50, '\n');
    }
  }
  return ats;
}

void spausd_v0_1(deque<studentas> &st) 
{
  cout << " | Jei norite matyti" << endl;
  cout << "vidurkius, iveskite v" << endl;
  cout << "medianas, iveskite m" << endl;
  char pasirinkimas = duok_man_char('v', 'm', '.');

  cout << endl << "Pavardė" << setw(10) << "Vardas";
  if (pasirinkimas == 'v') {
    cout << setw(20) << "Galutinis(Vid.)" << endl;
  } else {
    cout << setw(20) << "Galutinis(Med.)" << endl;
  }

  cout << "--------------------------------------" << endl;
  // Skaičiuojama studentu info
  double galutinis;

  // Eiti per visus studentus:
  for (auto &nr : st) {

    // Susirandu Galutini vidurki rez: (jei pasi == 'v')
    if (pasirinkimas == 'v') {
      galutinis = rask_studento_galutini_vid(nr.paz, nr.egz);
    }
    else {
      galutinis = rask_studento_galutine_med(nr.paz, nr.egz);
    }

    cout << nr.pavarde << setw(10) << nr.vardas;
    cout << setw(18) << setprecision(3) << galutinis << endl;
  }
}

char duok_man_chara() 
{
  char ats;
  while (true) {
    if (cin >> ats) {
      return ats;
    } else {
      cout << "Ivestis neteisinga. " << endl;
      cin.clear();
      cin.ignore(50, '\n');
    }
  }
}