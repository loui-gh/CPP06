#include "Serialisation.hpp"

int	main() {

	Data p = {"John Doe", 30, 'M'};
	Data *ptr = &p;
    std::cout << "Name: " << ptr->name << std::endl;
    std::cout << "Age: " << ptr->age << std::endl;
    std::cout << "Gender: " << ptr->gender << std::endl;

	/*serialise*/
	uintptr_t addy;
	addy = serialize(ptr);

	/*deserialise*/
	Data *scnd_ptr;
	scnd_ptr = deserialize(addy);

	std::cout << "The memory address of ptr is: " << ptr << std::endl;
	std::cout << "The memory address of addy is: "  << std::hex << addy << std::endl;
	std::cout << "The memory address of scnd_ptr is: "<< scnd_ptr << std::endl;

	return 0;
}