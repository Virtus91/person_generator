#ifndef person_hpp
#define person_hpp

#include "personIf.hpp"
#include <string>

class Person : public PersonIf {
    std::string name;
	std::string surname;
	std::string pesel;
	std::string address;
	int age;
	std::string date_of_birth;
	
public:
    const std::string& get_name() const {return name;};
    const std::string& get_surname() const {return surname;};
    const std::string& get_address() const {return address;};
    const int get_age() const {return age;};
    const std::string get_date_of_birth() const {return date_of_birth;};
    const std::string get_pesel() const {return pesel;};

    Person(std::string n,std::string s, std::string p, std::string a, int ag, std::string d_o_b);
    Person() = default;
    friend std::ostream& operator<<(std::ostream& s, const Person& p);
};

#endif
