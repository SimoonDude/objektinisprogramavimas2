#include "Studentas.hpp"

#include <algorithm>
#include <iomanip>
#include <chrono>
#include <iostream>
#include <fstream>




void debugger (std::vector<Studentas>& studentai, const int& c);

void kaip_rusiuoti (int &c);
void rusiuoti (std::vector<Studentas>& studentai, const int& c);

void generuoti_studentus (const int &paz_k, const int &k, const std::string &failo_pav);

void spausdinti_i_terminal (const std::vector<Studentas>& studentai);
void spausdinti_i_faila (const std::vector<Studentas>& studentai, const std::string& failo_pav, bool debug = false);
void spausdinti_i_faila (const Studentas* begin, const Studentas* end, const std::string& failo_pav, bool debug = false);

void skaityti_is_failo (std::vector<Studentas> &studentai, const std::string &failo_pav);

int stulpelio_plotis (const std::string& tekstas, int plotis);

void sutvarkyti_studentus (std::vector<Studentas>& studenta, const int &k, std::string failo_pav = "output", int c = 0);