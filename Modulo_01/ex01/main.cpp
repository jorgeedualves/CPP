#include "Zombie.hpp"

int main()
{
    Zombie* zumbi;

    zumbi = zombieHorde(3, "jose");

    for (int i=0; i < 3; i++)
    {
        zumbi[i].announce();
    }
    delete[] zumbi;
    return 0;
}