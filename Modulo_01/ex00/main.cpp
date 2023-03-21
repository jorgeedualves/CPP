#include "Zombie.hpp"

int main()
{
    Zombie z1("jorge");
    z1.announce();

    Zombie *ptr_z2 = newZombie("\nZumbie Alocado");
    ptr_z2->announce();
    delete ptr_z2;

    randomChump("\nZumbiRandom");

    return 0;
}