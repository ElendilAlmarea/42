#include "ZombieEvent.hpp"
#include "Zombie.hpp"
#include <cstdlib>

void ZombieEvent::setZombieType(std::string type)
{
	this->type = type;
}

Zombie *ZombieEvent::newZombie(std::string name)
{
	return (new Zombie(name, this->type));
}

Zombie	*ZombieEvent::randomChump(void)
{
	std::string names[] = {"Jean", "Jamie", "Micheline", "Pierre", "Yves", "Jack", "Euclide", "Vera"};

	Zombie *zombie;
	zombie = new Zombie(this->type, names[rand() % sizeof(names)]);
	(*zombie).announce();
	return (zombie);
}