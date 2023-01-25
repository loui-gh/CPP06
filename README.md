# CPP06
//check isfloat, handle float min and max according to gpt3 hints
//same for double

***RULE*** For each exercise, the type conversion must be solved using ONE specific type of casting.

ex00: convert scalar types

What is a scalar type? - a basic data type that represents a single value (as opposed to a complex one such as an array or struct). Examples of scalar types in C++ include int, char, double and float :)

What is type conversion? - also known as type casitng, type conversion is when you convert one data type into another, e.g. int to char and vice versa. Char -> int would be 'type promotion', as we are converting a smaller variable to a larger and can by done implicitly (by the compiler), e.g.

char c = '0';
int i = c; //value of i is 48, as 48 is the ascii value of '0'

There are some risks associated with implicit type conversion, such as;
-loss of information, such as sign (when signed is implicitly converted to unsigned)
-overflow, e.g. when long long converted to float //this is not promotion cast as long long > float

Explicit type conversion uses a cast operator. Examples of cast operators are: **static_cast; const_cast; reinterpret_cast; dynamic_cast

*static_cast** Used for conversion between basic data types, such as converting ints to char s and ints to enum s


Whilst it was tempting to use std::numeric_limits to check for overflows, it is forbidden to use templates from the standard template library (STL) in this project series until you get to CPP08.


