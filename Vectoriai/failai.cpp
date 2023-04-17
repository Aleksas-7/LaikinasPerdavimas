#include "Mylib.h"

void nuskaityk(vector<studentas> &st, string f_pav){

  std::stringstream buffer;
  ifstream fin (f_pav);
  if (!fin.is_open()){
    throw std::runtime_error("Tokio failo neradau.");
  }
  buffer << fin.rdbuf();
  fin.close();

  string line;
  int nd_sk = 0;

  getline(buffer, line);

  stringstream ss (line);
  string part;

  while (ss >> part){
    nd_sk++;
  }
  nd_sk -= 3;
  if (nd_sk == 0){
    throw std::runtime_error("Studentai irase neturi namu darbu informacijos.");
  }
  // Susiskaiciavome namu darbu sk is pirmines eil.
  
  studentas temp;

  while(buffer){
    if(!buffer.eof()){

      getline(buffer, line);
      stringstream ss (line);
      ss >> temp.vardas;
      ss >> temp.pavarde;

      int t;
      for (int i = 0 ; i < nd_sk ; i++){
        ss >> t;
        temp.paz.push_back(t);
      }
      ss >> temp.egz;
      st.push_back(temp);
      temp.paz.clear();
      
      ss.str("");
      
    }
    else {break;}
    
  }
}

void spausd_v0_2(vector<studentas> &st){

  std::ostringstream ss;

  ofstream fout("out.txt");
  
  fout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis(Vid.) / " << setw(25) << "Galutine(Med.)" << "\n";
  fout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
  string outputas;
  for (auto &s : st){
    ss << left << setw(15) << s.vardas  << setw(15) << s.pavarde;
    ss << left << setw(20) << setprecision(3) << rask_studento_galutini_vid(s.paz, s.egz);
    ss << left << setw(20) << setprecision(3) << rask_studento_galutine_med(s.paz, s.egz);
    ss << " \n";
    outputas += ss.str();
    ss.str("");
  }
  fout << outputas;
  fout.close();
}

void sukurk_v0_4(int dydis, int kiek_nd){

  std::ostringstream ss;
  std::ostringstream nss;
  ss << dydis;
  string f_name = "studentai" + ss.str() + ".txt";
  ss.str("");

  ss << left << setw(15) << "Vardas"  << setw(15) << "Pavarde";
  for (int i = 1 ; i < kiek_nd+1 ; i++){
    nss << i;
    string n_s = "ND" + nss.str();
    ss << left << setw(5) << n_s;
    nss.str("");
  }
  ss << left << setw(5) << "Egzaminas";

  vector<studentas> temp;

  string outputas = ss.str();
  ss.str("");
  prikurk_studentu(temp, dydis, kiek_nd);

  ofstream fout (f_name);
  int del = 0;
  for (auto &s : temp){
    if (del == 100000){
      fout << outputas;
      outputas = "";
      del = 0;
    }
    del++;
    ss << "\n" << left << setw(15) << s.vardas << setw(15) << s.pavarde;
    for (auto &p : s.paz){
      ss << left << setw(5) << p;
    }
    ss << left << setw(5) << s.egz;
    outputas += ss.str();
    ss.str("");
  }

  temp.clear();
  fout << outputas;
  fout.close();
}



void studentu_padalinimas(vector<studentas> &nusk, vector<studentas> &galv, int dydis){

  std::ostringstream ss;
  ss << dydis;
  string f_name_g = "galvociai" + ss.str() + ".txt";
  string f_name_n = "nuskriaustukai" + ss.str() + ".txt";
  
  ss.str("");

  ofstream fout(f_name_g);
  fout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis\n";
  fout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -";
  ofstream foutn(f_name_n);
  foutn << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis\n";
  foutn << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -";

  int count = 0;
  string outputas;

  for (auto &s : nusk){
    if (count == 10000){
      foutn << outputas;
      outputas = "";
      count = 0;
    }
    ss << "\n" << left << setw(15) << s.vardas  << setw(15) << s.pavarde;
    ss << left << setw(20) << setprecision(3) << s.galutinis;
    outputas += ss.str();
    ss.str("");
  }
  foutn << outputas;
  foutn.close();

  count = 0;
  outputas = "";

  for (auto &s : galv){
    if (count == 10000){
      fout << outputas;
      outputas = "";
      count = 0;
    }
    ss << "\n" << left << setw(15) << s.vardas  << setw(15) << s.pavarde;
    ss << left << setw(20) << setprecision(3) << s.galutinis;
    outputas += ss.str();
    ss.str("");
  }
  fout << outputas;
  fout.close();



  /*
  std::vector<studentas>::iterator it;
  it = std::find_if(st.begin(), st.end(),  findGalvocius);

  int count = 0;
  string outputas;



  for (int n = 0 ; n < it - st.begin() ; n++){
    if (count == 10000){
      foutn << outputas;
      outputas = "";
      count = 0;
    }
    ss << "\n" << left << setw(15) << st.at(n).vardas  << setw(15) << st.at(n).pavarde;
    ss << left << setw(20) << setprecision(3) << st.at(n).galutinis;
    outputas += ss.str();
    ss.str("");
  }
  foutn << outputas;
  foutn.close();

  outputas = "";
  count = 0;

  for (int n = it - st.begin() ; n < st.size() ; n++){
    if (count == 10000){
      fout << outputas;
      outputas = "";
      count = 0;
    }
    ss << "\n" << left << setw(15) << st.at(n).vardas  << setw(15) << st.at(n).pavarde;
    ss << left << setw(20) << setprecision(3) << st.at(n).galutinis;
    outputas += ss.str();
    ss.str("");
  }
  fout << outputas;
  fout.close();*/
}
