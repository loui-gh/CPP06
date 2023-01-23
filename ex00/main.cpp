#include "Conversion.hpp"


// int	ft_atoi_cpp(const char *str)
// {
// 	int	minus;
// 	int	res;
// 	int	i;

// 	res = 0;
// 	minus = 1;
// 	i = 0;

// 	if (str[i] == '-')
// 	{
// 		minus = -1;
// 		i++;
// 	}
// 	else if (str[i] == '+')
// 		i++;
// 	while (str[i] >= 48 && str[i] <= 57)
// 	{
// 		if (isdigit(str[i]) != 0)
// 			return (0);
// 		res = (res * 10) + (str[i] - '0');
// 		i++;//12b
// 	}
// 	return (res * minus);
// }
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
		std::cout << "isDouble\n";
	else
		std::cout << "Type conversion not possible\n";
	std::cout << &sample1 << std::endl;
	return 0;
}
