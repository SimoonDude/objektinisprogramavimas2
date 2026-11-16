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
    Studentas () = default; // default constructor, initializes egz_ to 0 and nd_ to an empty vector
    explicit Studentas (std::istream& is) { readStudent(is); }; // constructor that reads student data from an input stream
    // setters
    inline void setVardas (const std::string& vardas) { vardas_ = vardas; }
    inline void setPavarde (const std::string& pavarde) { pavarde_ = pavarde; }
    inline void setEgz (int egz) { egz_ = egz; }
    inline void setNd (const std::vector<int>& nd) { nd_ = nd; }
    // getters
    inline std::string vardas () const { return vardas_; }
    inline std::string pavarde () const { return pavarde_; }
    inline int egz () const { return egz_; }
    inline const std::vector<int>& nd () const { return nd_; }
    inline double vidurkis_val () const { return vidurkis_val_; }
    inline double mediana_val () const { return mediana_val_; }

    void randominiai_pazymiai (const int &k = 10); // generates random grades for the student
    void imti_random_varda_pavarde (dict& v_p); // assigns a random name and surname to the student

    // i dont think i'll use this one
    // why is vector<double> passed here? isn't it already a member of the class? maybe it's for flexibility, to allow calculating the final score based on different sets of grades, not just the member variable nd_.
    // but in this case, it might be better to have a default parameter that uses nd_
    // double galutinisBalas (double (*) () = vidurkis) const; // calculates the final score based on the provided function (default is average)

    // vidurkis and mediana defintions:
    double vidurkis ();
    double mediana ();


    void print (std::ostream& os) const;
    
    std::istream& readStudent(std::istream&); // reads student data from an input stream
    void duomenu_ivedimas ();
    friend std::istream& operator>>(std::istream& is, Studentas& s) { return s.readStudent(is); } // overloads the >> operator for input streams
    friend std::ostream& operator<<(std::ostream& os, const Studentas& s) { s.print(os); return os; } // overloads the << operator for output streams
    
    friend bool get_name_input (Studentas& s); // get input string; if `-1` break loop 

    friend bool vargsunas (const Studentas& s);
    friend bool pagyrunas (const Studentas& s);
    // finish writing the rest of the class definition,
    // according to files 1uzd_def.h,
    // including any necessary member functions and operators
};

bool get_int_input (int &balas, bool minusvienas = false); // paima int inputa is userio, grazina `True` jeigu pavyko; `False` jeigu ne.

// unused ig
bool compare(const Studentas& a, const Studentas& b);
bool comparebyLastname(const Studentas& a, const Studentas& b);
bool comparebyEgzaminas(const Studentas& a, const Studentas& b);