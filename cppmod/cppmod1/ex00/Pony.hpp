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
};

Pony	ponyOnTheStack();
Pony	*ponyOnTheHeap();

#endif