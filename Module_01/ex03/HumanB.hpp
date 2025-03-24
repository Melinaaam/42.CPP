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
	HumanB(void);
	~HumanB(void);
	void attack();

  private:
	Weapon      _weapon;
	std::string _name;
};
#endif
