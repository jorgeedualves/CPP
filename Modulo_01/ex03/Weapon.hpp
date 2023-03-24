#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon{
    private:
        std::string _weapon;

    public:
        explicit Weapon(std::string);
        ~Weapon() {}
        const std::string &getType();
        void setType(std::string);
};

#endif