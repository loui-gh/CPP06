#ifndef CONVERSION_HPP
# define CONVERSION_HPP

#include <iostream>
#include <iomanip> //set precision
#include <cfloat> //to find float max&min
#include <limits.h> //to find int max and min
#include <cmath> //to infinity and beyond!!
#include <cstdlib>
#include <cerrno>

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

		bool	overflow;

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