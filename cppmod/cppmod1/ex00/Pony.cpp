#include "Pony.hpp"

Pony::Pony() {
	unicorn = false;
	legs = 4;
}

void Pony::neigh(){
	std::cout << "Hhhhhiiiiii\n";
}

Pony *ponyOnTheHeap() {
	return new Pony();
}

Pony ponyOnTheStack() {
	Pony pony;
	return pony;
}
