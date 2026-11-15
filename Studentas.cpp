#include "Studentas.hpp"
#include "Papildai.hpp"

std::istream& Studentas :: readStudent(std::istream& is) {
    std::string vardas, pavarde;
    if(!(is >> vardas >> pavarde)) {
        return is;
    }
    std::vector<int> nd;
    int nd_value;
    while (is >> nd_value) {
        nd.push_back(nd_value);
    }
    if (nd.empty()) {
        is.setstate(std::ios::failbit);
        return is;
    }
    vardas_ = std::move(vardas);
    pavarde_ = std::move(pavarde);

    egz_ = nd.back();
    nd.pop_back();
    nd_ = std::move(nd);

    vidurkis();
    mediana();

    return is;
}


void Studentas::duomenu_ivedimas () {
    std::cout << "veskite namu darbu pazymius, baige iveskite -1:\n";
    while(true) {
        int balas;
        if (!get_int_input(balas, 1)) continue;
        if (balas == -1) break;
        nd_.push_back(balas);
    }
    std::cout << "egzamino rez.:\n";
    get_int_input(egz_);
}

void Studentas::randominiai_pazymiai (const int &k) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);

    for (int i = 0; i < k; i++) {
        nd_.push_back(dis(gen));
    }
}

void Studentas::imti_random_varda_pavarde (const dict &v_p) {
    std::random_device rd;  // a seed source for the random number engine
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(0, 1); // cia istraukiau is cppreference.com
    if (distrib(gen) == 0) { // vyras
        std::uniform_int_distribution<> distrib_vardas(0, v_p.vardai_vyr.size() - 1);
        std::uniform_int_distribution<> distrib_pavarde(0, v_p.pavardes_vyr.size() - 1);
        vardas_ = v_p.vardai_vyr[distrib_vardas(gen)];
        pavarde_ = v_p.pavardes_vyr[distrib_pavarde(gen)];
    } else { // moteris
        std::uniform_int_distribution<> distrib_vardas(0, v_p.vardai_mot.size() - 1);
        std::uniform_int_distribution<> distrib_pavarde(0, v_p.pavardes_mot.size() - 1);
        vardas_ = v_p.vardai_mot[distrib_vardas(gen)];
        pavarde_ = v_p.pavardes_mot[distrib_pavarde(gen)];
    }
}

void Studentas::print (std::ostream& os) const {
    os << left << setw(stulpelio_plotis(vardas_, 30)) << vardas_
            << setw(stulpelio_plotis(pavarde_, 30)) << pavarde_
            << setw(20) << vidurkis_val_
            << setw(20) << mediana_val_ << '\n';
}

void Studentas::vidurkis () {
    if (nd_.empty()) {vidurkis_val_ = egz_ * .6; return;}
    double galutinis = 0;
    for (int pazymys : nd_) galutinis += pazymys;
    galutinis /= nd_.size();
    vidurkis_val_ = galutinis * .4 + egz_ * .6;
}

void Studentas::mediana () { // ikelti funkcijas i struktura ?
    if (nd_.empty()) {mediana_val_ = egz_ * .6; return;}
    auto pazymiai = nd_;
    sort(pazymiai.begin(), pazymiai.end());\
    double mediana;
    if (pazymiai.size() % 2 == 1) {
        mediana = pazymiai[pazymiai.size() / 2];
    } else {
        size_t vidurys = pazymiai.size() / 2;
        mediana = (pazymiai[vidurys - 1] + pazymiai[vidurys]) / 2.0;
    }
    mediana_val_ = mediana * .4 + egz_ * .6;
}