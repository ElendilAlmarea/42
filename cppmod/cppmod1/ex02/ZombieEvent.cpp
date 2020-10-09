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
	zombie = new Zombie(names[rand() % sizeof(names)/sizeof(names[0])], this->type);
	(*zombie).announce();
	return (zombie);
}