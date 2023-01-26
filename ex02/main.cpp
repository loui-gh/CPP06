#include "Classes.hpp"

int	main() {

	Base *ptr = generate();

	identify(ptr);
	//for ref
	identify(*ptr);
	
	return 0;
}