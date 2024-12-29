#include "contact.hpp"

Contact::Contact() : first_name(""), last_name(""), nickname(""), phone_number(""), darkest_secret("") {}

void Contact::setFirstName(const std::string& first_name) {
    this->first_name = first_name;
}

void Contact::setLastName(const std::string& last_name) {
    this->last_name = last_name;
}

void Contact::setNickname(const std::string& nickname) {
    this->nickname = nickname;
}

void Contact::setPhoneNumber(const std::string& phone_number) {
    this->phone_number = phone_number;
}

void Contact::setDarkestSecret(const std::string& darkest_secret) {
    this->darkest_secret = darkest_secret;
}

std::string Contact::getFirstName() const {
    return this->first_name;
}

std::string Contact::getLastName() const {
    return this->last_name;
}

std::string Contact::getNickname() const {
    return this->nickname;
}

std::string Contact::getPhoneNumber() const {
    return this->phone_number;
}

std::string Contact::getDarkestSecret() const {
    return this->darkest_secret;
}
