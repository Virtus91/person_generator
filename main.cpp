#include "person.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <memory>
#include <string>
#include <map>


std::shared_ptr<Person> generate();
void get_data(const int, const int , const int);
extern std::map<std::string,  std::shared_ptr<Person>> baza;


int main(int argc, char *argv[])
{
    if (argc < 5) {
        std::cout << "Podano zla liczbe argumentow. Minimum to 4. Program konczy prace." << std::endl;
        return 0;
    } else if (argc > 32) {
        std::cout << "Podano zbyt duza liczbe argumentow. Max to 31.";
        return 0;
    } else if (argc % 3 == 2) {
	    extern int how_many;
	    extern time_t now;
	    how_many = atoi(argv[1]);
	    if (how_many < 1 || how_many > 1000000){
	        std::cout << "liczba tworzonych osob powinna miescic sie w zakresie 1 - 1 000 000";
		    return 0;
	    }
        srand(time(nullptr));
    
        //pobranie aktualnego czasu
        time(& now);
        for (int i = 0; i < how_many; i++)
        {
            std::shared_ptr<Person> temp = generate();
            baza.insert({temp->get_pesel(), temp});
        }
    
        int loop_count = (argc - 2) / 3;
        for (int i = 0; i < loop_count; i++)
        {
            get_data(atoi(argv[2 + i * 3]), atoi(argv[3 + i * 3]), atoi(argv[4 + i * 3]));
            std::cout << std::endl << std::endl;
        }
    } else {
        std::cout << "Podano zla liczbe argumentow. Program konczy prace.";
        return 0;
    }
    return 0;
}
