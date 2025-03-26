#ifndef HUMANA_HPP
#define HUMANA_HPP

#include<iostream>
#include<string>
#include"Weapon.hpp"
#include"HumanB.hpp"

class HumanA
{
    public:
    HumanA(std::string name, Weapon& weapon);
    ~HumanA(void);
    void attack();

	const std::string &getName() const;
	void setName(const std::string &newName);

    private:
    std::string _name;
    Weapon&     _weapon;
};

#endif
