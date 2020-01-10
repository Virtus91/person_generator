#ifndef struct_hpp
#define struct_hpp

#include "person.hpp"
#include <memory>

//struktury porownawcze do sortowania w "set"
struct cmp_name {
  bool operator() (std::shared_ptr<Person> const & p1, std::shared_ptr<Person> const & p2) const
  {
    if (p1->get_name() !=  p2->get_name())
        return (p1->get_name() < p2->get_name());
    else if (p1->get_surname() != p2->get_surname())
        return (p1->get_surname() < p2->get_surname());
    else if (p1->get_age() != p2->get_age())
        return (p1->get_age() < p2->get_age());
    else
        return (p1->get_pesel() < p2->get_pesel());
  }
};

struct cmp_surname {
  bool operator() (std::shared_ptr<Person> const & p1, std::shared_ptr<Person> const & p2) const
  {
    if (p1->get_surname() != p2->get_surname())
        return (p1->get_surname() < p2->get_surname());
    else if (p1->get_name() !=  p2->get_name())
        return (p1->get_name() < p2->get_name());
    else if (p1->get_age() != p2->get_age())
        return (p1->get_age() < p2->get_age());
    else 
        return (p1->get_pesel() < p2->get_pesel());
  }
};

struct cmp_address {
  bool operator() (std::shared_ptr<Person> const & p1, std::shared_ptr<Person> const & p2) const
  {
    if (p1->get_address() != p2->get_address())
        return (p1->get_address() < p2->get_address());
    else if (p1->get_name() != p2->get_name())
        return (p1->get_name() < p2->get_name());
    else if (p1->get_surname() != p2->get_surname())
        return (p1->get_surname() < p2->get_surname());
    else if (p1->get_age() != p2->get_age())
        return (p1->get_age() < p2->get_age());
    else
        return (p1->get_pesel() < p2->get_pesel());
  }
};

struct cmp_age {
  bool operator() (std::shared_ptr<Person> const & p1, std::shared_ptr<Person> const & p2) const
  {
    if (p1->get_age() != p2->get_age())
        return (p1->get_age() < p2->get_age());
    else if (p1->get_name() !=  p2->get_name())
        return (p1->get_name() < p2->get_name());
    else if (p1->get_surname() != p2->get_surname())
        return (p1->get_surname() < p2->get_surname());
    else
        return (p1->get_pesel() < p2->get_pesel());
  }
};

struct cmp_dob {
  bool operator() (std::shared_ptr<Person> const & p1, std::shared_ptr<Person> const & p2) const
  {
    if (p1->get_date_of_birth() != p2->get_date_of_birth())
        return (p1->get_date_of_birth() < p2->get_date_of_birth());
    else if (p1->get_name() !=  p2->get_name())
        return (p1->get_name() < p2->get_name());
    else if (p1->get_surname() != p2->get_surname())
        return (p1->get_surname() < p2->get_surname());
    else 
        return (p1->get_pesel() < p2->get_pesel());
  }
};

#endif
