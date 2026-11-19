#include <string>

class Zmogus {
    std::string vardas_;
    std::string pavarde_;
public:
    Zmogus () = default; // strings automatiskai tusti
    Zmogus (const std::string& vardas, const std::string& pavarde) : vardas_(vardas), pavarde_(pavarde) {}
    virtual ~Zmogus() = default; 

    virtual void spausdinti(std::ostream& os) const = 0;

    // getters
    inline const std::string& vardas () const { return vardas_; }
    inline const std::string& pavarde () const { return pavarde_; }

    // setters
    inline void setVardas (const std::string& vardas) { vardas_ = vardas; }
    inline void setPavarde (const std::string& pavarde) { pavarde_ = pavarde; }

    friend bool get_name_input (Zmogus& s); // get input string; if `-1` break loop 
};