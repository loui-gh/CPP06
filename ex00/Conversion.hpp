#ifndef CONVERSION_HPP
# define CONVERSION_HPP

#include <iostream>
#include <cctype>

#include <iomanip>
#include <stdlib.h>
#include <float.h>
#include <limits.h>


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
		
		// void	convertChar(char c);
		// void	convertInt(int i);
		// void	convertFloat(float f);
		// void	convertdouble(double d);

		// char	getChar() const;
		// int		getInt() const;
		// float	getFloat() const;
		// double	getDouble() const;

		//bool	isInside( const std::string & str, char c);

	private:

		char	_c;
		int		_i;
		float	_f;
		double	_d;

		char const *_userInput;
		std::string	_str;
};

std::ostream & operator<<(std::ostream & o, Converter const *obj);

#endif