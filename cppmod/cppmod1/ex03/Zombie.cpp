#include "Zombie.hpp"

Zombie::Zombie(std::string nom, std::string type) : nom(nom), type(type), sound("Braiiiiiiinnnssss ...")
{
}

Zombie::Zombie(void) : nom("Jamie"), type("ATK")
{
}

void Zombie::setZombieName(std::string nom)
{
	this->nom = nom;
}

void	Zombie::advert()
{
	std::cout << "<" << this->nom << " (" << this->type << ")> " << this->sound << std::endl;
}

void	Zombie::announce()
{
	std::cout << "Hi I'm " << this->nom << std::endl;
}