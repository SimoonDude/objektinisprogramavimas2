#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <random>

#include "Dict.h"

class Studentas {
private:
    std::string vardas_;
    std::string pavarde_;
    int egz_ = 0;
    std::vector<int> nd_;
    double vidurkis_val_ = 0.0;
    double mediana_val_ = 0.0;
public:
    Studentas () {
        egz_ = 0;
        nd_ = std::vector<int>();
    }
    explicit Studentas (std::istream& is) { readStudent(is); }; // constructor that reads student data from an input stream
    // rule of three II.
    // copy constructor
    Studentas (const Studentas& other) : 
        vardas_(other.vardas_), 
        pavarde_(other.pavarde_), 
        egz_(other.egz_), 
        nd_(other.nd_), 
        vidurkis_val_(other.vidurkis_val_), 
        mediana_val_(other.mediana_val_) 
    {}
    // setters
    inline void setVardas (const std::string& vardas) { vardas_ = vardas; }
    inline void setPavarde (const std::string& pavarde) { pavarde_ = pavarde; }
    inline void setEgz (int egz) { egz_ = egz; }
    inline void setNd (const std::vector<int>& nd) { nd_ = nd; }
    // getters
    inline const std::string& vardas () const { return vardas_; }
    inline const std::string& pavarde () const { return pavarde_; }
    inline int egz () const { return egz_; }
    inline const std::vector<int>& nd () const { return nd_; }
    inline double vidurkis_val () const { return vidurkis_val_; }
    inline double mediana_val () const { return mediana_val_; }

    void randominiai_pazymiai (const int &k = 10); // generates random grades for the student
    void imti_random_varda_pavarde (dict& v_p); // assigns a random name and surname to the student

    // vidurkis and mediana defintions:
    double vidurkis ();
    double mediana ();


    void print (std::ostream& os) const;
    
    std::istream& readStudent(std::istream&); // reads student data from an input stream
    void duomenu_ivedimas ();
    friend std::istream& operator>>(std::istream& is, Studentas& s) { return s.readStudent(is); } // overloads the >> operator for input streams
    friend std::ostream& operator<<(std::ostream& os, const Studentas& s) { s.print(os); return os; } // overloads the << operator for output streams
    
    // rule of three III.
    // copy assignment operator
    Studentas& operator=(const Studentas& other) {
        if (this != &other) {
            vardas_ = other.vardas_;
            pavarde_ = other.pavarde_;
            egz_ = other.egz_;
            nd_ = other.nd_;
            vidurkis_val_ = other.vidurkis_val_;
            mediana_val_ = other.mediana_val_;
        }
        return *this;
    }
    
    friend bool get_name_input (Studentas& s); // get input string; if `-1` break loop 

    friend bool vargsunas (const Studentas& s);
    friend bool pagyrunas (const Studentas& s);

    // rule of three I.
    ~Studentas() {}
};

bool get_int_input (int &balas, bool minusvienas = false); // paima int inputa is userio, grazina `True` jeigu pavyko; `False` jeigu ne.