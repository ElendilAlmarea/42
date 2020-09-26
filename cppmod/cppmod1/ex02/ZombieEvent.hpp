#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include <iostream>

class ZombieEvent
{
	public:
		void	setZombieType(std::string type);
		void	randomChump();
		Zombie *newZombie(std::string name);
	private:
		std::string type;
};

#endif