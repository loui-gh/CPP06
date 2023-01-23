#include "Conversion.hpp"

/*checks if specific character inside a string*/
bool isInside(const std::string & str, char c)
{
    return str.find(c) != std::string::npos;
}

/* checks for;
1. only one string input
2. with stringlen of at least 1 char
*/
int	err_check_size(int argc, char **argv) {

	if (argc != 2) {
		std::cout << "Error: incorrect number of arguments\n";
		return 0;
	}
	std::string str = argv[1];
	if (str.length() == 0) 
	{
		std::cout << "Error: no input found\n";
		return 0;
	}
	if (str.length() != 1 && isInside(str, ' '))
	{
		std::cout << "No spaces in the string input plz\n";
		return 0;
	}
	if(argv[1][0] == '0' && isdigit(argv[1][1])) {
		std::cout << "Give me easier input, please :)\n";
		return 0;
	}
	return 1;
}


/* checks for:
3. no spaces inside argv (if argv = "1 and 2 and 3")
4. that there is only one decimal point if at all
5. that there is no combination of letters and number */
#include "Conversion.hpp"

int	err_check_content(char **argv) {

	int i = 0;
	int d = 0;
	int k = 0;
	int j = 0;

	if (argv[1][i] == '-')
		i++;
	while (argv[1][i]) {
		if (argv[1][i] == '.')
			d++;
		if ((argv[1][i] == '.' && !argv[1][i+1]) || (argv[1][i] == '.' && !argv[1][i+1])){
			std::cout << "Decimal point must be followed by a number!\n";
			return 0;
		}
		if (d >= 2) {
			std::cout << "One decimal point only!\n";
			return 0;
		}
		j += isalpha(argv[1][i]);
		k += isdigit(argv[1][i]);
		i++;
	}
	if (j > 0 && k > 0 && argv[1][--i] != 'f') {
		std::cout << "Combination of letters and numbers not permitted\n";
		return 0;
	}
	return 1;
}