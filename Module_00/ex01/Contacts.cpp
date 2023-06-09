#include "PhoneBook.hpp"

/*using the initialization list is more efficient as it directly initializes the 
member variables instead of first default initializing them and then assigning new values.*/
Contacts::Contacts() : _firstName(""), _lastName(""), _nickName(""), _phoneNumber(""), _darkSecret("")
{}

/* since the class Contacts does not have any dynamically allocated resources, 
a destructor is not necessary in this case.*/
Contacts::~Contacts()
{}

void Contacts::setFirstName(std::string setFirstName)
{
	this->_firstName = setFirstName;
}

void Contacts::setLastName(std::string setLastName)
{
	this->_lastName = setLastName;
}

void Contacts::setNickName(std::string setNickName)
{
	this->_nickName = setNickName;
}

void Contacts::setPhoneNumber(std::string setPhoneNumber)
{
	this->_phoneNumber = setPhoneNumber;
}

void Contacts::setDarkSecret(std::string setDarkSecret)
{
	this->_darkSecret = setDarkSecret;
}

std::string Contacts::getFirstName()
{
	return (this->_firstName);
}

std::string Contacts::getLastName()
{
	return (this->_lastName);
}

std::string Contacts::getNickName()
{
	return (this->_nickName);
}

std::string Contacts::getPhoneNumber()
{
	return (this->_phoneNumber);
}

std::string Contacts::getDarkSecret()
{
	return (this->_darkSecret);
}
