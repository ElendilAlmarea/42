#include <iostream>

class Pony {
	public:
		Pony();
		void	ponyOnTheStack();
		void	ponyOnTheHeap();
	private:
		bool		unicorn;
		int			legs;
		std::string	sound;
};