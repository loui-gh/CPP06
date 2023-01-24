#ifndef CONVERSION_HPP
# define CONVERSION_HPP

#include <iostream>
#include <cctype>

#include <iomanip>
#include <stdlib.h>
#include <float.h>
#include <cmath>
#include <limits.h>
#include <limits>
# include <cerrno>

template<typename T>
T atoi_impl(const char* str)
{
    while (std::isspace(static_cast<unsigned char>(*str)))
    {
        ++str;
    }
    bool negative = false;
    if (*str == '+')
    {
        ++str;
    }
    else if (*str == '-')
    {
        ++str;
        negative = true;
    }
    T result = 0;
    for (; std::isdigit(static_cast<unsigned char>(*str)); ++str)
    {
		int digit = *str - '0';
        result *= 10;
        result -= digit; // calculate in negatives to support INT_MIN, LONG_MIN,..
    }
	return negative ? result : -result;
}

class	Converter
{
	public:

		Converter(char const *);
		Converter(Converter const & input);
		Converter const & operator=(Converter const & input);
		~Converter(void);
	
		bool	isChar(void);
		bool	isInt(void);
		bool	isFloat(void);
		bool	isDouble(void);

		// void	setAndConvert(void);
		
		void	convertChar();
		void	convertInt();
		void	convertFloat();
		void	convertDouble();

		int		getPrecision() const;
		std::string	getStr() const;
		char	getChar() const;
		int		getInt() const;
		float	getFloat() const;
		double	getDouble() const;

		//bool	isInside( const std::string & str, char c);
		bool	forScienceFloat;
		bool	forScienceDouble;
		bool	isFiniteNumber(double x);

		bool	overflowInt;
		bool	overflowDouble;
		bool	overflowFloat;

	private:

		char	_c;
		int		_i;
		float	_f;
		double	_d;

		char const	*_userInput;
		std::string	_str;

};

std::ostream & operator<<(std::ostream & o, Converter const *obj);

int			err_check_content(char **argv);
int			err_check_size(int argc, char **argv);
double	atof_cpp(const char* str);

#endif