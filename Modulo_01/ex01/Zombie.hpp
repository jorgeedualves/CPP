#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include<string>
#include<iostream>

class Zombie
{
    private:
        std::string _name;
    public:
        Zombie() { }
        ~Zombie() { }
        void announce(void);
        void setName(std::string);
};

Zombie* zombieHorde( int N, std::string _name);

#endif