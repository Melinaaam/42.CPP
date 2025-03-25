#pragma once
#ifndef __HUMANB_H__
# define __HUMANB_H__

# include "Weapon.hpp"
# include <iostream>
# include <string>

//attribut pour stocker un Weapon (l'arme).
//Un attribut pour stocker un name (le nom).

// inclure une instance de Weapon.

class HumanB
{
  public:
	HumanB(std::string name);
	~HumanB(void);
	void attack();
	const std::string &getName() const;
	void setName(const std::string &newName);
	void setWeapon(Weapon Weapon);

  private:
	std::string _name;
};
#endif
