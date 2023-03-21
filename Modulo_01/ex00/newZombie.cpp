#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    return new Zombie(name);
}

Zombie::~Zombie()
{
     std::cout << this->_name << " was destroyed!" << std::endl;
}