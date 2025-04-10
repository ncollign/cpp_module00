#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>

class PhoneBook {
private:
    Contact contacts[8];
    int total_contacts;

public:
    PhoneBook();
    void addContact();
    void searchContacts();
};

#endif
