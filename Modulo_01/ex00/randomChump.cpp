#include "Zombie.hpp"

void randomChump(std::string _name)
{   
    Zombie z(_name);
    z.announce();
}