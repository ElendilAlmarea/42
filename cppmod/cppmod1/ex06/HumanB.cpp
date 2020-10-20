#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
}

void	HumanB::setWeapon(Weapon weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack(void)
{
	if (!this->weapon)
	{
		std::cout << this->name << " attacks with his " << "nail" <<std::endl;
	}
	else
	{
		std::cout << this->name << " attacks with his " << this->weapon->getType() <<std::endl;
	}
}