#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

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
