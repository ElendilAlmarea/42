#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int	main(void)
{
	Zombie one = Zombie("Jean", "atk");
	one.advert();
	ZombieEvent control;
	control.setZombieType("def");
	Zombie *two = control.newZombie("Jack");
	two->announce();
	Zombie *three = control.randomChump();
	three->advert();
	control.randomChump();
	control.randomChump();
	delete two;
	delete three;

	return (0);
}