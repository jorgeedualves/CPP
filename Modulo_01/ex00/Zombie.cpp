#include "Zombie.hpp"

Zombie::Zombie(std::string n)
{
      _name = n;
}

void Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}