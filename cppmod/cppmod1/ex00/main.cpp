#include "Pony.hpp"

int	main(void) {
	Pony *heap = ponyOnTheHeap();
	Pony stack = ponyOnTheStack();

	heap->neigh();
	stack.neigh();

	delete heap;
	
	return (0);
}