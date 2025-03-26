#ifndef HUMANB_HPP
#define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>

class HumanB
{
  public:
	HumanB(std::string name);
	~HumanB(void);
	void attack();
	const std::string &getName() const;
	void setName(const std::string &newName);
	void setWeapon(Weapon &Weapon);

  private:
	std::string _name;
	Weapon*		_weapon;
};
#endif
