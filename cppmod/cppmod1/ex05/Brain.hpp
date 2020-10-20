#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <sstream>

class Brain
{
	public:
		Brain(void);
		std::string	identify(void);
	private:
		std::string	address;
};


#endif