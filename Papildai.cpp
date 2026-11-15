#include "Papildai.hpp"
#include "Studentas.hpp"

void skaityti_is_failo (std::vector<Studentas> &studentai, const std::string &failo_pav) const {
    auto start = std::chrono::high_resolution_clock::now();
    std::ifstream f(failo_pav);
    if (!f.is_open()) {
        std::cout << "nepavyko atidaryti failo: " << failo_pav << std::endl;
        return;
    }
    std::string line;
    std::getline(f, line); // skip header
    Studentas student;
    while (std::getline(f, line)) {
        if (line.empty()) continue;
        std::istringstream row(line);
        Studentas student;
        if (row >> student) {
            studentai.push_back(std::move(student));
        }
    }
    f.close();
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    std::cout << " | " << failo_pav << " Failo skaitymas uztruko: " << diff.count() << " s.\n";
}

void generuoti_studentus (const int &paz_k, const int &k, const std::string &failo_pav) {
    // negenruojame i vector - tiesiai i outputa
    int kiekis;
    cout << "iveskite studentu kieki: ";
    while (true) if (!get_int_input(kiekis)) continue; else break;
    bool to_file = (k == 2) ? 1 : 0;

    ifstream vv("assets/vardai_vyr"), pv("assets/pavardes_vyr");
    ifstream vm("assets/vardai_mot"), pm("assets/pavardes_mot");
    string line; dict v_p;
    while (getline(vv, line)) v_p.vardai_vyr.push_back(line);
    while (getline(pv, line)) v_p.pavardes_vyr.push_back(line);
    while (getline(vm, line)) v_p.vardai_mot.push_back(line);
    while (getline(pm, line)) v_p.pavardes_mot.push_back(line);
    vv.close(); pv.close(); vm.close(); pm.close();
    
    ofstream f;
    if (to_file) f.open(failo_pav);
    else f.close();

    for (int i = 0; i < kiekis; ++i) {
        Studentas s;
        s.imti_random_varda_pavarde(v_p);
        s.randominiai_pazymiai(paz_k);
        s.vidurkis(); s.mediana();
        
        if (to_file) f << s;
        else         cout << s;
    }
    if (to_file) f.close();
}

bool get_name_input (string &vard, string &pav) {
    cin >> vard >> pav;
    if (vard == "-1" || pav == "-1") {return 0;} else {return 1;}
}

bool get_int_input (int &balas, bool minusvienas) { // paima int inputa is userio, grazina `True` jeigu pavyko; `False` jeigu ne.
    string b; cin >> b;
    try {
        balas = stoi(b);
        if (balas > 0 || (minusvienas && balas == -1)) {return 1;} else {throw 1;}
    } catch (...) {
        cout << "turi priklausyti naturaliu skaiciu aibei.\n";
        return 0;
    }
}


int stulpelio_plotis (const string& tekstas, int plotis) {
    int simboliu_kiekis = 0;
    for (size_t i = 0; i < tekstas.size(); ++i) {
        if ((static_cast<unsigned char>(tekstas[i]) & 0xC0) != 0x80) {
            ++simboliu_kiekis;
        }
    }
    return plotis + static_cast<int>(tekstas.size()) - simboliu_kiekis;
}

// last flag = debugger or not
void spausdinti_i_faila (const vector<Studentas>& studentai, const string& failo_pav, bool debug) {
    auto start = chrono::high_resolution_clock::now();
    ofstream f(failo_pav);
    if (!f.is_open()) {
        cout << "neapvyko atidaryti failo: " << failo_pav << endl;
        return;
    }
    f << left << setw(30) << "Vardas"
         << setw(30) << "Pavarde"
         << setw(20) << "Galutinis (vid.)"
         << setw(20) << "Galutinis (med.)" << '\n';
    f << string(100, '-') << '\n';
    f << fixed << setprecision(2);
    for (const auto &i : studentai) {
        f << i;
    }
    f.close();
    if (debug) {
        chrono::duration<double> diff = chrono::high_resolution_clock::now() - start;
        cout << " | " << failo_pav << " Failo rasymas uztruko: " << diff.count() << " s.\n";
    } 
}

void spausdinti_i_terminal (vector<Studentas>& studentai) {
    cout << left << setw(30) << "Vardas"
         << setw(30) << "Pavarde"
         << setw(20) << "Galutinis (vid.)"
         << setw(20) << "Galutinis (med.)" << '\n';
    cout << string(100, '-') << '\n';
    cout << fixed << setprecision(2);
    for (const auto &i : studentai) {
        cout << i;
    }
}

void kaip_rusiuoti (int &c) {
    // rusiuoti pagal ka?
    // pagal pavardes (pritaikom)
    // pagal vidurki (pritaikom)
    while (true) {
        cout << "Kaip rusiuoti (1. Pagal pavardes [↑], 2. Pagal vidurki [↓]), 3. Nerusiuoti?: ";
        string choice; cin >> choice;
        try {
            c = stoi(choice);
            if (c == 1 || c == 2 || c == 3) {cout << '\n'; break;}
            else {throw;}
        } catch (...) {
            cout << "\n\n\n"; continue;
        }
    }
}
bool pagyrunas (const Studentas& s) {
    return s.vidurkis_val >= 5;
};
bool vargsunas (const Studentas& s) {
    return s.vidurkis_val < 5;
};
// `std::vector` to contemplate; `int`: `1` == to_terminal `2` == to_file; `string` file_name (optional); `int` (optional) sort: `1` by last_name, `2` by average, `3` no sort; 
void sutvarkyti_studentus (vector<Studentas>& studentai, const int &k, string failo_pav, int c) { 
    for (auto &s : studentai) {
        s.vidurkis();
        s.mediana();
    }
    // if c not passed, ask for c
    if (c == 0) kaip_rusiuoti(c);
    rusiuoti(studentai, c);

    if (k == 1) {
        spausdinti_i_terminal(studentai);
    } else if (k == 2) {
        spausdinti_i_faila(studentai, failo_pav);
    } else if (k == 3) {
        auto start = chrono::high_resolution_clock::now();

        // auto newEnd = std::remove_if(
        //     studentai.begin(),
        //     studentai.end(),
        //     vargsunas
        // );
        // vector<student> galutinis_below5;
        // std::copy(newEnd, studentai.end(), std::back_inserter(galutinis_below5));
        // studentai.erase(newEnd, studentai.end());

        auto middle = std::stable_partition(
            studentai.begin(),
            studentai.end(),
            pagyrunas
        );

        chrono::duration<double> diff = chrono::high_resolution_clock::now() - start;
        cout << " | Studentu skirstymas i dvi grupes uztruko: " << diff.count() << " s.\n";
        // spausdinti_i_faila(studentai, failo_pav + "_islaike.txt", 1);
        // spausdinti_i_faila(galutinis_below5, failo_pav + "_neislaike.txt", 1);
        spausdinti_i_faila(vector<Studentas>(studentai.begin(), middle), failo_pav + "_islaike.txt", 1);
        spausdinti_i_faila(vector<Studentas>(middle, studentai.end()), failo_pav + "_neislaike.txt", 1);
    }
}

void rusiuoti (vector<Studentas>& studentai, const int& c) {
    if (c == 1) {
        sort(studentai.begin(), studentai.end(),
            [](const Studentas &a, const Studentas &b) {return a.pavarde < b.pavarde;});
    } else if (c == 2) {
        sort(studentai.begin(), studentai.end(),
            [](const Studentas &a, const Studentas &b) {return a.vidurkis_val > b.vidurkis_val;});
    }
}

void debugger (vector<Studentas>& studentai, const int& c) {
    skaityti_is_failo(studentai, "./benchmark-data/studentai10000.txt");
    sutvarkyti_studentus(studentai, 3, "10000", c);
    studentai.clear();
    cout << "\n";
    skaityti_is_failo(studentai, "./benchmark-data/studentai100000.txt");
    sutvarkyti_studentus(studentai, 3, "100000", c);
    studentai.clear();
    cout << "\n";
    skaityti_is_failo(studentai, "./benchmark-data/studentai1000000.txt");
    sutvarkyti_studentus(studentai, 3, "1000000", c);
    studentai.clear();
}
