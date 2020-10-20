/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:28:41 by yvanat            #+#    #+#             */
/*   Updated: 2020/10/20 15:57:06 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include "Zombie.hpp"

class ZombieHorde
{
	public:
		ZombieHorde(int n);
		~ZombieHorde(void);
		Zombie	*newZombie(std::string name);
		void	announce(void);
		Zombie	*zombies;
	private:
		int		n;
};

#endif