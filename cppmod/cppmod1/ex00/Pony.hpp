#ifndef PONY_HPP
# define PONY_HPP

#include <iostream>

class Pony {
	public:
		Pony();
		void	neigh();
	private:
		bool		unicorn;
		int			legs;
		std::string	sound;
};

Pony	ponyOnTheStack();
Pony	*ponyOnTheHeap();

#endif