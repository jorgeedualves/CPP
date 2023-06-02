#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie{
	
	public:
		Zombie(std::string);
		~Zombie(void);
		void announce(void);
	private:
    	std::string _name;
};

Zombie* newZombie(std::string);
void randomChump(std::string);

#endif