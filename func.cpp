#include "person.hpp"
#include "struct.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <array>
#include <memory>
#include <map>
#include <set>
#include <string>
#include <cmath>


std::array<std::string,20> names{"Andrzej" ,"Piotr", "Olaf", "Kornel", "Aleksander", "Pawel", "Krzysztof", "Marek", "Kamil", "Artur", "Adrian", "Adolf","Bartek","Blazej","Bonifacy", "Dawid","Zygmunt", "Wiktor", "Zygfryd", "Dominik"};
std::array<std::string,20> surnames{"Nowak" ,"Jagodzinski", "Gadzala", "Kijak", "Slon", "Zlotnicki", "Krzysztofiak", "Urban", "Wojewodzki", "Pogodny", "Berowski","Makowski", "Kowal", "Bernicki", "Augustynski", "Monkowski", "Bonkowski", "Chlebowski", "Piecykowski", "Graczyk"};
std::array<std::string,20> addresses{"Szczecin", "Gdansk", "Mielec", "Gdynia", "Radom", "Gorzow", "Zielona Gora", "Kalisz", "Drawsko Pomorskie", "Warszawa", "Krakow", "Poznan", "Gryfice", "Resko", "Ploty", "Barlinek", "Czestochowa", "Swinoujscie", "Kolobrzeg", "Miedzyzdroje"};


std::ostream& operator<<(std::ostream& s,const Person& p){
    s << "Imie: " << p.name <<",  Nazwisko: " << p.surname << ", Wiek: " << p.age <<  ", pesel: " << p.pesel << std::endl;
    s << "Adres: " << p.address <<", Data urodzenia: " <<  p.date_of_birth << std::endl;
	return s;
}

Person::Person(std::string n, std::string s, std::string p, std::string a, int ag, std::string d_o_b):
name(n), surname(s), pesel(p), address(a), age(ag), date_of_birth(d_o_b){}

time_t now;
int how_many;

//FUNCKJA GENERUJACA OSOBY
std::shared_ptr<Person> generate(){
    
    //miesiace majace po 31 dni
    std::set<int> m31d{0,2,4,6,7,9,11};
    
    struct tm birth_date = {0};
    birth_date.tm_year = rand() % 100 + 20;
    birth_date.tm_mon = rand() % 12;
    const bool is_in = m31d.find(birth_date.tm_mon) != m31d.end();
    
    if (is_in)
         birth_date.tm_mday = rand() % 31 + 1;
    else if (birth_date.tm_mon == 1)
         birth_date.tm_mday = rand() % 28 + 1;
    else
         birth_date.tm_mday = rand() % 30 + 1;
    
    std::string birth_year = std::to_string(birth_date.tm_year + 1900);
    
    std::string birth_month;
    if (birth_date.tm_mon < 9)
    {
        birth_month = std::to_string(birth_date.tm_mon + 1);
        birth_month = "0" + birth_month;
    }
    else
        birth_month = std::to_string(birth_date.tm_mon + 1);
        
    std::string birth_day;
    if (birth_date.tm_mday < 10)
    {
        birth_day = std::to_string(birth_date.tm_mday);
        birth_day = "0" + birth_day;
    }
    else
        birth_day = std::to_string(birth_date.tm_mday);
   
    std::string d_o_b = birth_year + "." + birth_month + "." + birth_day;
    
    //liczenie wieku
    time_t tt_birth_date = mktime(& birth_date);
    double diff_seconds = difftime(now, tt_birth_date);
    double age = floor(diff_seconds/31536000);

    //generator peselu
    std::string pesel = {};
    pesel = birth_year;
    pesel.erase(0,2);
    if (birth_date.tm_year < 100)
        pesel += birth_month; 
    else
        pesel += std::to_string(birth_date.tm_mon + 21);
    pesel += birth_day;
    for (int i = 0; i<5; i++)
        pesel += std::to_string(rand()%10);
    
    return std::make_shared<Person>(names[rand()%20], surnames[rand()%20], pesel, addresses[rand()%20], age, d_o_b);
}

std::map<std::string,  std::shared_ptr<Person>> baza;
std::set<std::shared_ptr<Person>, cmp_name> sort_name;
std::set<std::shared_ptr<Person>, cmp_surname> sort_surname;
std::set<std::shared_ptr<Person>, cmp_address> sort_address;
std::set<std::shared_ptr<Person>, cmp_age> sort_age;
std::set<std::shared_ptr<Person>, cmp_dob> sort_dob;


//FUNKCJA DO WYSWIETLANIA DANYCH
void get_data(const int type, const int start_position, const int amount)
{
switch (type){
case 0:
    {
    std::cout << "Lista " << amount << " osob z wygenerowanej bazy " << how_many << " osob, " << std::endl;
    std::cout <<"zaczynajac od pozycji " << start_position << ", w kolejnosci wg peselu przedstawia sie nastepujaco: " << std::endl << std::endl;
    auto it = baza.begin();
    auto start = std::next(it,(start_position -1));
    auto end = std::next(it, (start_position + amount - 1));
    for (; start != end; start++)
        std::cout << *(start->second) << std::endl;
    }
    break;   
case 1:
    {
    for (auto it = baza.begin(); it != baza.end(); it++)
        sort_name.insert(it->second);
    std::cout << "Lista " << amount << " osob z wygenerowanej bazy " << how_many << " osob, " << std::endl;
    std::cout <<"zaczynajac od pozycji " << start_position << ", w kolejnosci wg imienia przedstawia sie nastepujaco: " << std::endl << std::endl;
    auto it = sort_name.begin();
    auto start = std::next(it,(start_position -1));
    auto end = std::next(it, (start_position + amount - 1));
    for (; start != end; start++)
        std::cout << **start << std::endl;
    }
    break;
case 2:
{
    for (auto it = baza.begin(); it != baza.end(); it++)
        sort_surname.insert(it->second);
    std::cout << "Lista " << amount << " osob z wygenerowanej bazy " << how_many << " osob, " << std::endl;
    std::cout <<"zaczynajac od pozycji " << start_position << ", w kolejnosci wg nazwiska przedstawia sie nastepujaco: " << std::endl << std::endl;
    auto it = sort_surname.begin();
    auto start = std::next(it,(start_position -1));
    auto end = std::next(it, (start_position + amount - 1));
    for (; start != end; start++)
        std::cout << **start << std::endl;
    }
    break;
case 3:
{
    for (auto it = baza.begin(); it != baza.end(); it++)
        sort_address.insert(it->second);
    std::cout << "Lista " << amount << " osob z wygenerowanej bazy " << how_many << " osob, " << std::endl;
    std::cout <<"zaczynajac od pozycji " << start_position << ", w kolejnosci wg adresu przedstawia sie nastepujaco: " << std::endl << std::endl;
    auto it = sort_address.begin();
    auto start = std::next(it,(start_position -1));
    auto end = std::next(it, (start_position + amount - 1));
    for (; start != end; start++)
        std::cout << **start << std::endl;
    }
    break;
case 4:
{
    for (auto it = baza.begin(); it != baza.end(); it++)
        sort_age.insert(it->second);
    std::cout << "Lista " << amount << " osob z wygenerowanej bazy " << how_many << " osob, " << std::endl;
    std::cout <<"zaczynajac od pozycji " << start_position << ", w kolejnosci wg wieku przedstawia sie nastepujaco: " << std::endl << std::endl;
    auto it = sort_age.begin();
    auto start = std::next(it,(start_position -1));
    auto end = std::next(it, (start_position + amount - 1));
    for (; start != end; start++)
        std::cout << **start << std::endl;
    }
    break; 
case 5:
{
    for (auto it = baza.begin(); it != baza.end(); it++)
        sort_dob.insert(it->second);
    std::cout << "Lista " << amount << " osob z wygenerowanej bazy " << how_many << " osob, " << std::endl;
    std::cout <<"zaczynajac od pozycji " << start_position << ", w kolejnosci wg daty urodzenia przedstawia sie nastepujaco: " << std::endl << std::endl;
    auto it = sort_dob.begin();
    auto start = std::next(it,(start_position -1));
    auto end = std::next(it, (start_position + amount - 1));
    for (; start != end; start++)
        std::cout << **start << std::endl;
    }
    break;
default: 
    std::cout << "dokonano zlego wyboru kategorii sortowania" << std::endl;
    break;
}
}
