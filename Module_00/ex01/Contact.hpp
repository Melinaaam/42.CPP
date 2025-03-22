#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include<string>
#include <limits>

class Contact
{
	public:
	Contact(void);
	void Create_First_Name();
	void Create_Last_Name();
	void Create_Nick_Name();
	void Create_Phone_Number();
	void Create_Darkest_Secret();
	void Create_One_Contact();

	std::string getFirstName() const;
	std::string getLastName () const;
	std::string getNickName () const;
	std::string getPhoneNumber () const;
	std::string getSecret () const;

	private :
	std::string FirstName;
	std::string LastName;
	std::string NickName;
	std::string PhoneNumber;
	std::string Secret;
};

#endif
