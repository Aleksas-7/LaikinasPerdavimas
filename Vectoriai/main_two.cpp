#include "Mylib.h"

bool compareByGalutinis(const studentas &a, const studentas &b)
{
    return a.galutinis < b.galutinis;
}

bool findGalvocius (studentas t)
{
  return t.galutinis >= 5;
}

int main() {
  
  vector<studentas> st;
  char pasirinkimas;

  do {

    cout << "\nJei norite: " << endl;
    cout << "  suvesti studentus iš duomenų failo: iveskite f" << endl;
    cout << "  išvesti studentus i out.txt faila: iveskite i" << endl;
    cout << "  patys suvesti studentus consolėje: iveskite k" << endl;
    cout << "  sukurti atsitiktini studentu kieki: iveskite a" << endl;

    cout << "Versijos v0_4 func: " << endl;
    cout << "  sukurti atsitiktinių studentų failą, iveskite s" << endl;
    cout << "  padalinti studentu failą į galvočiu ir nuskriaustuku failus, iveskite p" << endl;

    cout << endl;
    cout << "  išeiti iš programos, iveskite n" << endl;

    pasirinkimas = duok_man_chara();

    if (pasirinkimas == 'f') 
    {
    cout << "Iveskite failo pavadinima: " << endl;
    string failo_pav;
    cin >> failo_pav;

    try{
      nuskaityk(st, failo_pav);

      for (auto &s : st){s.galutinis = rask_studento_galutini_vid(s.paz, s.egz);}
      sort(st.begin(), (st.end()), compareByGalutinis);

    }
    catch (std::exception &e){cout << "Atsitiko problema su failo nuskaitymu: " << e.what() << endl;}
    }

    else if (pasirinkimas == 'i')
    {
      spausd_v0_2(st);
      cout << "studentai atspausdinti i faila out.txt" << endl;
    }

    else if (pasirinkimas == 'k') 
    {
    cout << "Kiek namų darbų turės studentai: " << endl;
    int kiek_nd = duok_man_int(1, 20);

    do {
      st.push_back(pildik(kiek_nd));
      cout << " - Irašyti dar vieną studentą, iveskite a" << endl;
      cout << "Baigti studentų irašymą, iveskite n" << endl;
    } while (duok_man_char('a', 'n', '.') == 'a');

    spausd_v0_1(st);
    }

    else if (pasirinkimas == 'a')
    {
      cout << "Kiek namų darbų turės studentai: " << endl;
      int kiek_nd = duok_man_int(1, 20);
      
      cout << "Kiek atsitiktinių studentu norite sukurti?" << endl;
      int kiek = duok_man_int(1, 10000);
      prikurk_studentu(st, kiek, kiek_nd);
      spausd_v0_1(st);
    }
      
    else if (pasirinkimas == 's')
    {
      cout << "Kiek namų darbų turės studentai: " << endl;
      int kiek_nd = duok_man_int(1, 20);

      cout << "Kiek studentu turėtu būti šiame faile?: " << endl;
      int kiek_st = duok_man_int(1, 10000000);

      auto p1 = std::chrono::high_resolution_clock::now();;
      sukurk_v0_4(kiek_st, kiek_nd);
      auto p2 = std::chrono::high_resolution_clock::now();;
      cout << "Failo, dydzio: " << kiek_st << " kurimas, užtruko " 
      << 0.001 * std::chrono::duration_cast<std::chrono::milliseconds>(p2-p1).count() << " seconds\n";
    }

    else if (pasirinkimas == 'p')
    {
      string f_name, t;
      
      cout << "Iveskite studentų failo pavadinimą: " << endl;
      cin >> f_name;
      t = f_name;
      t.erase(0, 9);
      int stud_kiek = std::stoi(t);

      try {
        st.reserve(stud_kiek);

        auto a1 = std::chrono::high_resolution_clock::now();
        nuskaityk(st, f_name);
        auto t2 = std::chrono::high_resolution_clock::now();
        cout << "!!!: Failo nuskaitytas per " 
        << 0.001 * std::chrono::duration_cast<std::chrono::milliseconds>(t2-a1).count() << " seconds\n";
        
        for (auto &s : st){s.galutinis = rask_studento_galutini_vid(s.paz, s.egz);}

        auto t11 = std::chrono::high_resolution_clock::now();
        sort(st.begin(), st.end(), compareByGalutinis);
        auto t12 = std::chrono::high_resolution_clock::now();
        cout << "!!!: Failo surikiuotas per " 
        << 0.001 * std::chrono::duration_cast<std::chrono::milliseconds>(t12-t11).count() << " seconds\n";

        //st dalinimas:
        auto dal1 = std::chrono::high_resolution_clock::now();
        vector<studentas> galvociai;
        galvociai.reserve(stud_kiek);
        std::vector<studentas>::iterator it;
        it = std::find_if(st.begin(), st.end(),  findGalvocius);

        copy(it, st.end(), std::back_inserter(galvociai));
        st.resize(it - st.begin() - 1);
        auto dal2 = std::chrono::high_resolution_clock::now();
        cout << "!!!: Studentai padalinti per " 
        << 0.001 * std::chrono::duration_cast<std::chrono::milliseconds>(dal2-dal1).count() << " seconds\n";
        ///

        auto t21 = std::chrono::high_resolution_clock::now();
        studentu_padalinimas(st, galvociai, stud_kiek);
        auto t22 = std::chrono::high_resolution_clock::now();
        cout << "Pdalinti studentai israsyti per " 
        << 0.001 * std::chrono::duration_cast<std::chrono::milliseconds>(t22-t21).count() << " seconds\n";

        auto a2 = std::chrono::high_resolution_clock::now();
        cout << "Visas studentu skirstymas užtruko " 
        << 0.001 * std::chrono::duration_cast<std::chrono::milliseconds>(a2-a1).count() << " seconds\n";
        galvociai.clear();
        st.clear();

      }
      catch (std::exception &e){cout << "atsitiko problema su failo nuskaitymu: " << e.what() << endl;}
    }

    else if (pasirinkimas == 't'){

      int stud_kiek = 100;
      for (int i = 0 ; i < 5 ; i++){
        stud_kiek *= 10;
        st.reserve(stud_kiek);

        std::ostringstream ss;
        ss << stud_kiek;
        string f_name = "studentai" + ss.str() + ".txt";

        auto ta = std::chrono::high_resolution_clock::now();
        nuskaityk(st, f_name);
        auto tb = std::chrono::high_resolution_clock::now();
        cout << stud_kiek << " : Failo nuskaitytas per " 
        << 0.001 * std::chrono::duration_cast<std::chrono::milliseconds>(tb-ta).count() << " seconds\n";
        // Failas nuskaitytas baigtas

        for (auto &s : st){s.galutinis = rask_studento_galutini_vid(s.paz, s.egz);}

        auto tc = std::chrono::high_resolution_clock::now();
        sort(st.begin(), st.end(), compareByGalutinis);
        auto td = std::chrono::high_resolution_clock::now();
        cout << stud_kiek << " : Failo surikiuotas per " 
        << 0.001 * std::chrono::duration_cast<std::chrono::milliseconds>(td-tc).count() << " seconds\n";
        // Failo rikiavimas baigtas

        auto te = std::chrono::high_resolution_clock::now();
        vector<studentas> galvociai;
        galvociai.reserve(stud_kiek);
        std::vector<studentas>::iterator it;
        it = std::find_if(st.begin(), st.end(),  findGalvocius);
        copy(it, st.end(), std::back_inserter(galvociai));
        st.resize(it - st.begin() - 1);
        auto tf = std::chrono::high_resolution_clock::now();
        cout << stud_kiek << " : Konteineriai padalinti per " 
        << 0.001 * std::chrono::duration_cast<std::chrono::milliseconds>(tf-te).count() << " seconds\n";
        // Konteineriu padalinimas baigtas

        studentu_padalinimas(st, galvociai, stud_kiek);
        galvociai.clear();
        st.clear();
        cout << " |||||| Programos veikimas su failu dydzio: " << stud_kiek << " baigtas\n";
      }
    }

    else {cout << "Netaisyklinga įvestis." << endl;}

  } while (pasirinkimas != 'n');

  st.clear();
}