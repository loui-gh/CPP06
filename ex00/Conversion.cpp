/*
1) Recognise type of variable input as string
2) convert implicitly or explicity to that variable
3) from there, convert explicitly using static_cast to the three other variables*/
#include "Conversion.hpp"

Converter::Converter(char const * userInput) {

	this->_userInput = userInput;
	this->_str = userInput;
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
	i++;
	if (p[i] && p[i] == '.') {
		while (p[i] != '\0' && p[i] != 'f') {
			precision++;
			i++;
	}
	}
	if (precision == 0)
		precision++;
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
	this->_i = atoi_impl<int>(this->_userInput);
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
	if (_userInput[_str.length() - 1] == 'f')
	{
		this->_f = atof_cpp(this->_userInput);
		return (true);
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
	if (isFiniteNumber(atof_cpp(this->_userInput)) == false)
		return (false);
	this->_d = atof_cpp(this->_userInput);
	return (true);
}


bool Converter::isFiniteNumber(double x) {

	return (x <= DBL_MAX && x >= -DBL_MAX); 
}

void	Converter::convertChar(void) {

		//i = c;//implicit type conversion!
		this->_i = static_cast<int>(this->_c);//explicit type conversion
		this->_f = static_cast<float>(this->_c);
		this->_d = static_cast<double>(this->_c);

}

void	Converter::convertInt(void) {

	this->_c = static_cast<char>(this->_i);
	this->_f = static_cast<float>(this->_i);
	this->_d = static_cast<double>(this->_i);
}

void	Converter::convertFloat() {

	if (forScienceFloat == true)
		return;
	this->_c = static_cast<char>(this->_f);
	this->_i = static_cast<float>(this->_f);
	this->_d = static_cast<double>(this->_f);
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

	//std::cout << "precision = " << obj->getPrecision() << std::endl;
	if (obj->forScienceFloat == true) {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: " << obj->getStr() << std::endl;
		std::string d_string = obj->getStr().substr(0, obj->getStr().size()-1);
		std::cout << "double: " << d_string;
	}
	else if (obj->forScienceDouble == true) {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: " << obj->getStr() << 'f' << std::endl;
		//std::string d_string = obj->getStr().substr(0, obj->getStr().size()-1);
		std::cout << "double: " << obj->getStr();
	}
	else {
		if (obj->getChar())
		o << "char: " << obj->getChar() << std::endl;
	else
		std::cout << "char: Non displayable\n";
	o << "int: " << obj->getInt() << std::endl;
	o << "float: " << std::setprecision(obj->getPrecision()) << std::fixed << obj->getFloat() << "f" << std::endl;
	o << "double: " << std::setprecision(obj->getPrecision()) << std::fixed << obj->getDouble();
	}
	return o;
}
