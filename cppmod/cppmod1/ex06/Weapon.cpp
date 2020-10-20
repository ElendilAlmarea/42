#include "Weapon.hpp"

Weapon::Weapon(std::string type) : ref(this->type)
{
	this->type = type;
}

std::string	&Weapon::getType(void)
{
	return (this->ref);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}