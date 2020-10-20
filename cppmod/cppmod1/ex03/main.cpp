#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int main()
{
	ZombieHorde *horde;

	horde = new ZombieHorde(10);
	horde->announce();
	delete horde;
}