#include "Studentas.hpp"
#include "Papildai.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    int c, k = 0, r = 0, paz_k;
    string failo_pav = "0"; 
    string duomenu_failas;

    if (argc > 1) {
        try {
            c = stoi(argv[1]);
            if (c !=  5) k = (argc > 2) ? stoi(argv[2]) : 0;
            else r = (argc > 2) ? stoi(argv[2]) : 0;
            if (c == 2 && argc > 3) duomenu_failas = argv[3];
            if (c == 2 && argc > 4) failo_pav = argv[4];
            if (c == 2 && argc > 5) r = stoi(argv[5]);
            if (c == 4 && argc > 3) failo_pav = argv[3];
            if ((c == 1 || c == 2 || c == 3 || c == 4 || c == 5) &&
                ((k >= 1 && k <= 3) ||
                (r >= 1 && r <= 3))) {
                goto skip_menu;
            } else {
                cout << "Netinkamas argumentas. Naudokite default meniu.\n";
            }
        } catch (...) {
            cout << "Netinkamas argumentas. Naudokite default meniu.\n";
        }
    }

    // gal iskelti meniu i papildus ar dar kur
    while (true) { // meniu
        cout << "\n1. Ivesti studentu duomenis ranka"
                "\n2. Apdoroti duomenis is failo"
                "\n3. Generuoti pazymius studentams"
                "\n4. Generuoti studentus (ir pazymius)"
                "\n5. Debug"
                "\nPasirinkite: ";
        string choice; cin >> choice;
        try {
            c = stoi(choice);
            if (c == 1 || c == 2 || c == 3 || c == 4 || c == 5) {break;} 
            else {cout << "\n\n\n"; continue;}
        } catch (...) {
            cout << "\n\n\n"; continue;
        }
    }
    while (true && c != 5) {
        cout << "Isvesti i terminal (1) ar i faila (2) ?: ";
        string choice; cin >> choice;
        try {
            k = stoi(choice);
            if (k == 1 || k == 2) {break;}
            else {cout << "\n\n\n"; continue;}
        } catch (...) {
            cout << "\n\n\n"; continue;
        }
    }
    skip_menu: // skip menu if command line arguments are valid
    if (k == 2) {
        if (argc <= 4) {
            cout << "Isvesties failo pavadinimas?:\n";
            while (true) {
                cin >> failo_pav;
                ofstream f(failo_pav);
                if (f.is_open()) {
                    f.close();
                    break;
                }
                cout << "nepavyko atidaryti failo: " << failo_pav << endl;
            }
        }
    }
    // while (true && c == 5) {
    //     cout << "Naudoti std::vector (1) ar std::list (2) ?: ";
    //     string choice; cin >> choice;
    //     try {
    //         l = stoi(choice);
    //         if (l == 1 || l == 2) {break;}
    //         else {cout << "\n\n\n"; continue;}
    //     } catch (...) {
    //         cout << "\n\n\n"; continue;
    //     }
    // }

    vector<Studentas> studentai;

    if (c == 3 || c == 4) { // pasirinkta generuoti, kiek studentu?
        cout << "pazymiu/ivertinimu kiekis: "; 
        while (true) if (!get_int_input(paz_k)) continue; else break;
    }
    else if (c == 2) { // pasirinkta skaityti is failo
        if (duomenu_failas.empty()) {
            cout << "iveskite duomenu failo pavadinima : ";
            cin >> duomenu_failas;
        }
        skaityti_is_failo(studentai, duomenu_failas);
    }   
    else if (c == 5) {// Testavimas su dideliu studentu kiekiu
        if (r == 0) kaip_rusiuoti(r);
        debugger(studentai, r);
        // else if (l == 2) debugger(l_studentai, r);        
        return 0;
    }
    if (c == 2 && r == 0) kaip_rusiuoti(r);
    if (c == 2) {
        sutvarkyti_studentus(studentai, k, failo_pav, r);
        return 0;
    }
    if (c == 4) { // jeigu pasirinkta generuoti viska
        generuoti_studentus(paz_k, k, failo_pav);
        return 0;
    }
    
    while (c == 1 || c == 3) { // while pats arba paz. generuoti
        Studentas studentas;
        cout << "vardas pavarde:\n";
        if (!get_name_input(studentas)) {
            if (studentai.size() == 0) {cout << "nera studentu, programa baigia darba.\n"; return 0;}
            break;
        }
        switch (c) {
            case 1:
                studentas.duomenu_ivedimas();
                break;
            case 3:
                studentas.randominiai_pazymiai(paz_k);
                break;
        }
        studentai.push_back(studentas);
        cerr << "objekto `student *` adresas: " << &studentai.back() << '\n';
    }
    sutvarkyti_studentus(studentai, k, failo_pav);
    return 0;
}