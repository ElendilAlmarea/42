/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:28:34 by yvanat            #+#    #+#             */
/*   Updated: 2020/10/20 16:14:49 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n)
{
	std::string names[] = {"Jean", "Jamie", "Micheline", "Pierre", "Yves", "Jack", "Euclide", "Vera"};
	
	this->n = n;
	this->zombies = new Zombie[n];
	for (int i = 0; i < n; i++)
	{
		this->zombies[i].setZombieName(names[rand() % sizeof(names)/sizeof(names[0])]);
	}
}

ZombieHorde::~ZombieHorde(void)
{
	delete []this->zombies;
}

void	ZombieHorde::announce(void)
{
	for (int i = 0; i < this->n; i++)
	{
		this->zombies[i].announce();
	}
}