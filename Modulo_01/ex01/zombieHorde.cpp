#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name)
{

    Zombie* array_zombie = new Zombie[N];  // [z1, z2, z3]
    for(int i=0; i < N; i++)
    {
        array_zombie[i].setName(name); //[jorge, jorge, jorge]
    }
    return array_zombie;
}