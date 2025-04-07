#include "phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>

PhoneBook::PhoneBook() : total_contacts(0) {}

std::string truncate(const std::string& str) {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    }
    return str;
}

void PhoneBook::searchContacts() {
    if (total_contacts == 0) {
        std::cout << "No contacts available." << std::endl;
        return;
    }

    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < 8 && i < total_contacts; i++) {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << truncate(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << truncate(contacts[i].getLastName()) << "|"
                  << std::setw(10) << truncate(contacts[i].getNickname()) << std::endl;
    }

    std::string input;
	std::cout << "Enter the index of the contact: ";
    std::getline(std::cin, input);
    
	bool is_number = true;
	for (size_t i = 0; i < input.length(); i++) {
		if (!isdigit(input[i])) {
			is_number = false;
			break ;
		}
	}

	if (!is_number || input.empty()) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }

	int index = atoi(input.c_str());

    if (index < 0 || index >= total_contacts || index >= 8) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }

    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}

static bool	isValidString(const std::string& str) {
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isalpha(str[i]) && !isdigit(str[i]) && str[i] != ' ' && str[i] != '\'' && str[i] != '.' && str[i] != '-') {
			return (false);
		}
	}
	return (true);
}

void PhoneBook::addContact() {
    int index = total_contacts % 8;
    std::string input;

    std::cout << "Enter first name: ";
    std::getline(std::cin, input);
	if (input.empty() || !isValidString(input)) {
		std::cout << "Error: First name cannot be empty or contain invalid character!" << std::endl;
		return ;
	}
    contacts[index].setFirstName(input);

    std::cout << "Enter last name: ";
    std::getline(std::cin, input);
	if (input.empty() || !isValidString(input)) {
		std::cout << "Error: Last name cannot be empty or contain invalid character!" << std::endl;
		return ;
	}
    contacts[index].setLastName(input);

    std::cout << "Enter nickname: ";
    std::getline(std::cin, input);
	if (input.empty() || !isValidString(input)) {
		std::cout << "Error: Nickname cannot be empty or contain invalid character!" << std::endl;
		return ;
	}
    contacts[index].setNickname(input);

    std::cout << "Enter phone number: ";
    std::getline(std::cin, input);
	if (input.empty() || !isValidString(input)) {
		std::cout << "Error: Phone number cannot be empty or contain invalid character!" << std::endl;
		return ;
	}
    contacts[index].setPhoneNumber(input);

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, input);
	if (input.empty() || !isValidString(input)) {
		std::cout << "Error: Darkest secret name cannot be empty or contain invalid character!" << std::endl;
		return ;
	}
    contacts[index].setDarkestSecret(input);

    total_contacts++;
    std::cout << "Contact added successfully!" << std::endl;
}
