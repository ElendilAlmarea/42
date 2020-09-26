#include "ZombieEvent.hpp"
#include "Zombie.hpp"

void ZombieEvent::setZombieType(std::string type)
{
	this->type = type;
}

Zombie ZombieEvent::*newZombie(std::string name)
{
	Zombie one = Zombie(name, ZombieEvent::type);
	return one;
}