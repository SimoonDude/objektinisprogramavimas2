#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <random>

#include "Zmogus.hpp"

#include "Dict.h"

class Studentas : public Zmogus {
private:
    // std::string vardas_;
    // std::string pavarde_;
    int egz_ = 0;
    std::vector<int> nd_;
    double vidurkis_val_ = 0.0;
    double mediana_val_ = 0.0;
public:
    Studentas () {
        egz_ = 0;
        nd_ = std::vector<int>();
    }
    // Studentas(inputstream) => constructs and reads student data from inputstream
    explicit Studentas (std::istream& is) { readStudent(is); }; // constructor that reads student data from an input stream
    /*
    Rule of three realizacija labai paprasta:
    1. Destruktorius defaultinis nes Studentas naudoja tik std::string ir std::vector, kurie turi savo destruktorius;
    2. Kopijavimo konstruktorius ima argumenta ana, ir inicializuoja narius su to objekto nariais;
    3. Kopijavimo priskyrimo operatorius patikrina ar objektai vienodi, jei ne, priskiria narius is kito objekto.
    */
    // destructor
    ~Studentas() {};
    // copy constructor
    Studentas (const Studentas& other) : 
        Zmogus(other), 
        egz_(other.egz_), 
        nd_(other.nd_), 
        vidurkis_val_(other.vidurkis_val_), 
        mediana_val_(other.mediana_val_) 
    {}
    // copy assignment operator
    Studentas& operator=(const Studentas& other) {
        if (this != &other) {
            Zmogus::operator=(other);
            egz_ = other.egz_;
            nd_ = other.nd_;
            vidurkis_val_ = other.vidurkis_val_;
            mediana_val_ = other.mediana_val_;
        }
        return *this;
    }
    // setters
    // inline void setVardas (const std::string& vardas) { vardas_ = vardas; }
    // inline void setPavarde (const std::string& pavarde) { pavarde_ = pavarde; }
    inline void setEgz (int egz) { egz_ = egz; }
    inline void setNd (const std::vector<int>& nd) { nd_ = nd; }
    // getters
    // inline const std::string& vardas () const { return vardas_; }
    // inline const std::string& pavarde () const { return pavarde_; }
    inline int egz () const { return egz_; }
    inline const std::vector<int>& nd () const { return nd_; }
    inline double vidurkis_val () const { return vidurkis_val_; }
    inline double mediana_val () const { return mediana_val_; }

    void randominiai_pazymiai (const int &k = 10); // generates random grades for the student
    void imti_random_varda_pavarde (dict& v_p); // assigns a random name and surname to the student

    // vidurkis and mediana defintions:
    double vidurkis ();
    double mediana ();


    void spausdinti (std::ostream& os) const override;
    
    std::istream& readStudent(std::istream&); // reads student data from an input stream
    void duomenu_ivedimas ();
    friend std::istream& operator>>(std::istream& is, Studentas& s) { return s.readStudent(is); } // overloads the >> operator for input streams
    friend std::ostream& operator<<(std::ostream& os, const Studentas& s) { s.spausdinti(os); return os; } // overloads the << operator for output streams
    


    friend bool vargsunas (const Studentas& s);
    friend bool pagyrunas (const Studentas& s);
};

bool get_int_input (int &balas, bool minusvienas = false); // paima int inputa is userio, grazina `True` jeigu pavyko; `False` jeigu ne.