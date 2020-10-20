#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	public:
		Zombie(std::string nom, std::string type);
		Zombie(void);
		void	advert(void);
		void	announce(void);
		void	setZombieName(std::string nom);
	private:
		std::string	nom;
		std::string type;
		std::string	sound;
};


#endif