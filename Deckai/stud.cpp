#include "Mylib.h"
#include "RandInt.hpp"

studentas pildik(int kiek_nd) {
  studentas temp;
  // Vardas, Pavarde -----------------------------------------
  cout << "Iveskite vardą ir pavardę." << endl;
  cin >> temp.vardas >> temp.pavarde;

  // Namu darbu vertinimai------------------------------------
  cout << "Iveskite " << kiek_nd << " pažymius." << endl;
  if (kiek_nd > 1) {
    int sk = 0, iv;
    while (sk < kiek_nd && cin >> iv) {
      if (iv < 0 || iv > 10) {
        cout << " Netaisyklinga ivestis int[0, 10]: " << endl;
        continue;
      }
      else {
        sk++;
        temp.paz.push_back(iv);
      }
    }
    cin.clear();
    cin.ignore(100, '\n');

    if (sk < kiek_nd) {
      for (int j = sk; j < kiek_nd; j++)
        temp.paz.push_back(0);
    }
  } 
  else if (kiek_nd == 1) {
    temp.paz.push_back(duok_man_int(0, 10));
  }

  // Egzamino vertinimai----------------------------------------
  cout << "Iveskite egzamino rezultatą." << endl;
  temp.egz = duok_man_int(0, 10);
  return temp;
}

void spausdink_stud(studentas &st) {
  cout << st.vardas << " " << st.pavarde << " ";
  for (int p = 0; p < st.paz.size(); p++) {
    cout << st.paz.at(p) << " ";
  }
  cout << ": " << st.egz << endl;
}


void prikurk_studentu (deque<studentas> &st, int kiek, int kiek_nd) {

  const int vardu_kiekis = 3;

  string vardai_m[3] = {"Singailas", "Odisejas", "Algintas"};
  string vardai_f[3] = {"Asta", "Alfreda", "Airine"};

  string pav_m[3] = {"Alton", "Alsenas", "Jakaitis"};
  string pav_f[3] = {"Joteika", "Sousa", "Tenorio"};

  //st.reserve(kiek);
  RandInt rnd_name{0, vardu_kiekis-1};
  RandInt rnd_mark{0, 10};
  RandInt rnd_bool{0, 1};

  for (int s = 0 ; s < kiek ; s++){
    studentas temp;
    if (rnd_bool()){
      temp.vardas = vardai_m[rnd_name()];
      temp.pavarde = pav_m[rnd_name()];

      for (int i = 0; i < kiek_nd; i++){
        temp.paz.push_back(rnd_mark());
      }
      temp.egz = rnd_mark();
    }
    else{
      temp.vardas = vardai_f[rnd_name()];
      temp.pavarde = pav_f[rnd_name()];

      for (int i = 0; i < kiek_nd; i++){
        temp.paz.push_back(rnd_mark());
      }
      temp.egz = rnd_mark();
    }
    st.push_back(temp);
  }
}

