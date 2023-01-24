#include "Conversion.hpp"

int atoi(const char* str)
{
    return atoi_impl<int>(str);
}

double atod(const char *str) {

	return atoi_impl<double>(str);
}

int	main(int argc, char **argv) {

	if (!err_check_content(argv) || !err_check_size(argc, argv))
		return 0;

	Converter	sample1(argv[1]);

	if (sample1.isChar() == true)
		sample1.convertChar();
	else if (sample1.isInt() == true)
		sample1.convertInt();
	else if (sample1.isFloat() == true)
		sample1.convertFloat();
	else if (sample1.isDouble() == true)
		sample1.convertDouble();
	else {
		std::cout << "Type conversion not possible\n";
		return 0;
	}
	std::cout << &sample1 << std::endl;
	return 0;
}
