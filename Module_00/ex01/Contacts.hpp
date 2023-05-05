#ifndef CONTACTS_HPP
#define CONTACTS_HPP

#include <string>

class Contacts
{
	private:
			std::string _firstName;
			std::string _lastName;
			std::string _nickName;
			std::string _phoneNumber;
			std::string _darkSecret;

	public:

			void setFirstName(std::string setFirstName);
			void setLastName(std::string setLastName);
			void setNickName(std::string setNickname);
			void setPhoneNumber(std::string setPhoneNumber);
			void setDarkSecret(std::string setDarkSecret);

			std::string getFirstName();
			std::string getLastName();
			std::string getNickName();
			std::string getPhoneNumber();
			std::string getDarkSecret();
			Contacts();
			~Contacts();
};

#endif