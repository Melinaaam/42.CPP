#pragma once
#ifndef __HUMANA_H__
#define __HUMANA_H__

#include<iostream>
#include<string>
#include"Weapon.hpp"

class HumanA
{
    public:
    HumanA(void);
    ~HumanA(void);
    void attack();

    private:
    Weapon      _weapon;
    std::string _name;
};

#endif
