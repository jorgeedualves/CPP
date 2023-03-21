#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name)
{

    Zombie* array_zombie = new Zombie[N]; 
    for(int i=0; i < N; i++)
    {
        array_zombie[i].setName(name);
    }
    return array_zombie;
}