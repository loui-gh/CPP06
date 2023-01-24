/*
1) Recognise type of variable input as string
2) convert implicitly or explicity to that variable
3) from there, convert explicitly using static_cast to the three other variables*/
#include "Conversion.hpp"

Converter::Converter(char const * userInput) {

	this->_userInput = userInput;
	this->_str = userInput;
	this->overflowDouble = false;
	this->overflowFloat = false;
	this->overflowInt = false;
}

/*copy constructor*/
Converter::Converter(Converter const & obj) {

	this->_userInput = obj._userInput;
	this->_str = obj._str;
}

/*Assigment operator*/
Converter const & Converter::operator=(Converter const & obj)
{
	this->~Converter();
	new (this) Converter(obj);
	return (*this);
}

Converter::~Converter(void) {

	return;
}


bool	Converter::isChar(void) {

	if (_str.length() != 1 || !isascii(_userInput[0])) {
		return false;
	}
	char c = _userInput[0];
	if (!isprint(c))
		return false;
	if (c >= 48 && c <=  57)
		return false;
	this->_c = c;
	return true;
}
//CHECK THESE 3x funcitons!!

int		Converter::getPrecision() const {

	char const	*p;
	int			precision;
	int			i;
	
	p = this->_userInput;
	precision = 0;
	i = 0;
	while (p[i] != '\0' && p[i] != '.')
		i++;
	if (p[i] && p[i] == '.') {
		while (p[i] != '\0' && p[i] != 'f') {
			precision++;
			i++;
	}
	}
	if (precision == 0)
		precision++;
	else
		precision--;

	return precision;
}


bool	Converter::isInt(void)
{
	if (_userInput[0] != '-' && _userInput[0] != '+' && !isdigit(_userInput[0]))
		return (false);
	for (int i = 1; _userInput[i]; i++)
	{
		if (isdigit(_userInput[i]) == false || _userInput[i] == '.')
			return (false);
	}
	return (true);
}

bool	Converter::isFloat(void)
{
	std::string	const forScience[4] = {"inff", "-inff", "+inff", "nanf"};
	for (unsigned long i = 0; i < 4; i++)
	{
		if (_userInput == forScience[i])
		{
			this->forScienceFloat = true;
			return (true);
		}
	}

	/*does it contain a decimal point?*/
	char	ch = '.';
	if (getStr().find(ch) != std::string::npos && _userInput[_str.length() - 1] == 'f')
	{
		/*is it bigger than float?*/
		double convertFloat = atof_cpp(this->_userInput);
		if (convertFloat > FLT_MAX || convertFloat < FLT_MIN) {
			this->overflowFloat = true;
			this->overflowInt = true;
			return false;
		}
		else {
			this->_f = static_cast<float>(convertFloat);
			return (true);
		}
	}
	return (false);
}

bool	Converter::isDouble(void)
{
	std::string	const forScience[4] = {"inf", "-inf", "+inf", "nan"};

	for (int i = 0; i < 4; i++)
	{
		if (_userInput == forScience[i])
		{
			this->forScienceDouble = true;
			return (true);
		}
	}
	/*is it bigger than float?*/
	double convertDbl = atof_cpp(this->_userInput);
	if (convertDbl > DBL_MAX || convertDbl < DBL_MIN) {
		this->overflowDouble = true;
		this->overflowFloat = true;
		this->overflowInt = true;
		return false;
	}
	else
		this->_d = atof_cpp(this->_userInput);
	return (true);
}

void	Converter::convertChar(void) {

		std::cout << "IS CHAR\n";
		//i = c;//implicit type conversion!
		this->_i = static_cast<int>(this->_c);//explicit type conversion
		this->_f = static_cast<float>(this->_c);
		this->_d = static_cast<double>(this->_c);

}

void	Converter::convertInt(void) {

	std::cout << "IS INT\n";
	long int	longInt = atoi_impl<long int>(this->_userInput);
	if (this->getStr().length() > 11 || longInt > std::numeric_limits<int>::max() || longInt < std::numeric_limits<int>::min()) {
		this->overflowDouble = true;
		this->overflowFloat = true;
		this->overflowInt = true;
	}
	else {
		this->_i = 
		this->_c = static_cast<char>(this->_i);
		this->_f = static_cast<float>(this->_i);
		this->_d = static_cast<double>(this->_i);
	}
}

void	Converter::convertFloat() {

	std::cout << "IS FLOAT\n";
	if (forScienceFloat == true)
		return;
	this->_c = static_cast<char>(this->_f);
	this->_i = static_cast<float>(this->_f);
	this->_d = static_cast<double>(this->_f);
}

void	Converter::convertDouble() {

	std::cout << "IS DOUBLE\n";
	if (forScienceDouble == true)
		return;
	this->_c = static_cast<char>(this->_d);
	this->_i = static_cast<float>(this->_d);
	this->_f = static_cast<double>(this->_d);
}


char	Converter::getChar() const {

	return this->_c;
}

int	Converter::getInt() const {

	return this->_i;
}

float	Converter::getFloat() const {

	return this->_f;
}

double	Converter::getDouble() const {

	return this->_d;
}

std::string	Converter::getStr() const {
	return this->_str;
}
std::ostream & operator<<( std::ostream & o, Converter const *obj) {

	// YOU NEED TO SET PRECISION HERE
	//std::cout << std::fixed << std::setprecision(obj->getPrecision());

	if (obj->forScienceFloat == true) {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: " << obj->getStr() << std::endl;
		std::string d_string = obj->getStr().substr(0, obj->getStr().size()-1);
		std::cout << "double: " << d_string;
		return o;
	}
	else if (obj->forScienceDouble == true) {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: " << obj->getStr() << 'f' << std::endl;
		//std::string d_string = obj->getStr().substr(0, obj->getStr().size()-1);
		std::cout << "double: " << obj->getStr();
		return o;
	}
	if (obj->getChar() && ((obj->getChar() >= 'a' && obj->getChar() <= 'z') || \
								(obj->getChar() >= 'A' && obj->getChar() <= 'Z')))
		o << "char: " << obj->getChar() << std::endl;
	else
		std::cout << "char: Non displayable\n";
	if (obj->overflowInt == true)
		o << "int: overflow\n";
	else
		o << "int: " << obj->getInt() << std::endl;
	if (obj->overflowFloat == true)
		o << "float: overflow\n";
	else
		o << "float: " << std::setprecision(obj->getPrecision()) << std::fixed << obj->getFloat() << "f" << std::endl;
	if (obj->overflowDouble == true)
		o << "double: overflow\n";
	else
		o << "double: " << std::setprecision(obj->getPrecision()) << std::fixed << obj->getDouble();
	return o;
}
