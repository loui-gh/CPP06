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


bool	Converter::isInt(void)
{
	if (_userInput[0] != '-' && _userInput[0] != '+' && !isdigit(_userInput[0]))
		return (false);
	for (unsigned long i = 1; _userInput[i]; i++)
	{
		if (isdigit(_userInput[i]) == false)
			return (false);
	}
	return (true);
}

// bool	Converter::isFloat(void)
// {
// 	std::string	const specialType[4] = {"inff", "-inff", "+inff", "nanf"};

// 	for (unsigned long i = 0; i < 4; i++)
// 	{
// 		if (_userInput == specialType[i])
// 		{
// 			this->_specialType = true;
// 			return (true);
// 		}
// 	}
// 	if (isNumber() && _userInput[_userInput.length() - 1] == 'f')
// 	{
// 		if (this->_precision > 1)
// 			this->_precision--;
// 		return (true);
// 	}
// 	return (false);
// }

// bool	Converter::isDouble(void)
// {
// 	std::string	const specialType[4] = {"inf", "-inf", "+inf", "nan"};

// 	for (int i = 0; i < 4; i++)
// 	{
// 		if (_userInput == specialType[i])
// 		{
// 			this->_specialType = true;
// 			return (true);
// 		}
// 	}
// 	if (isNumber() == false)
// 		return (false);
// 	return (true);
// }


// void	Converter::setAndConvert(void) {

// 	if (isChar() == true)
// 		convertChar(this->_c);
// 	else if (isInt() == true)
// 		convertInt(this->_i);
// 	//else if (is)
// }

/* wil always fail for NaN*/
bool isNumber(double x) 
{
	// This looks like it should always be true, 
	// but it's false if x is a NaN.
	return (x == x); 
}

bool isFiniteNumber(double x) 
    {
        return (x <= DBL_MAX && x >= -DBL_MAX); 
    }  

// bool	is_float(char *str) {

// }

// bool	is_double(char *str) {

// }



// void	Converter::convertChar(char c) {

// 		//i = c;//implicit type conversion!
// 		this->_i = static_cast<int>(c);//explicit type conversion
// 		this->_f = static_cast<float>(c);
// 		this->_d = static_cast<double>(c);

// }

// char	Converter::getChar() const {

// 	return this->_c;
// }

// int	Converter::getInt() const {

// 	return this->_i;
// }

// float	Converter::getFloat() const {

// 	return this->_f;
// }

// double	Converter::getDouble() const {

// 	return this->_d;
// }

// std::ostream & operator<<( std::ostream & o, Converter const *obj) {

// 	// YOU NEED TO SET PRECISION HERE
// 	//std::cout << std::fixed << std::setprecision(obj.getPrecision());
// 	o << "char: " << obj->getChar() << std::endl;
// 	o << "int: " << obj->getInt() << std::endl;
// 	o << "float: " << obj->getFloat() << std::endl;
// 	o << "double: " << obj->getDouble() << std::endl;
// 	return o;
// }
