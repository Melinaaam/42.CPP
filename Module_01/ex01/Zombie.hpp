#pragma once
#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include<iostream>
#include<string>

class Zombie
{
	public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void announce( void );
	void setname(std::string name);
	private:
	std::string _name;
};

Zombie* zombieHorde( int N, std::string name );

#endif
