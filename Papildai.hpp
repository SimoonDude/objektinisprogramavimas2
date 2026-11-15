#include "Studentas.hpp"

struct dict {
    std::vector<std::string> vardai_vyr;
    std::vector<std::string> pavardes_vyr;
    std::vector<std::string> vardai_mot;
    std::vector<std::string> pavardes_mot;
};

bool get_name_input (string &vard, string &pav);
bool get_int_input (int &balas, bool minusvienas);

void skaityti_is_failo (std::vector<Studentas> &studentai, const std::string &failo_pav) const;

void debugger (vector<Studentas>& studentai, const int& c);
void kaip_rusiuoti (int &c);
void rusiuoti (vector<Studentas>& studentai, const int& c);
void generuoti_studentus (const int &paz_k, const int &k, const std::string &failo_pav);
void sutvarkyti_studentus (vector<Studentas>& studentai, const int &k, string failo_pav, int c);
void spausdinti_i_terminal (const vector<Studentas>& studentai);
void spausdinti_i_faila (const vector<Studentas>& studentai, const string