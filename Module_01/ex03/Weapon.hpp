#pragma once
#ifndef __WEAPON_H__
# define __WEAPON_H__

# include <iostream>
# include <string>

class Weapon
{
  public:
	Weapon();
	~Weapon();

	const std::string &getType() const;
	void setType(const std::string &newType);

  private:
	std::string _type;
};

#endif
