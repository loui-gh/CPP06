# CPP06
/*SUMMARY: static_cast, reinterpret_cast, dynamic_cast applied in different projects*/

***RULE*** For each exercise, the type conversion must be solved using ONE specific type of casting.
__________________________________________________________________________________________________________

ex00: convert scalar types | static_cast

What is a scalar type? - a basic data type that represents a single value (as opposed to a complex one such as an array or struct). Examples of scalar types in C++ include int, char, double and float.

What is type conversion? - also known as type casitng, type conversion is when you convert one data type into another, e.g. int to char and vice versa. Char -> int would be 'type promotion', as we are converting a smaller variable to a larger and can by done implicitly (by the compiler), e.g.

char c = '0';
int i = c; //value of i is 48, as 48 is the ascii value of '0'

There are some risks associated with implicit type conversion, such as;
-loss of information, such as sign (when signed is implicitly converted to unsigned)
-overflow, e.g. when long long converted to float //this is not promotion cast as long long > float

Explicit type conversion uses a cast operator. Examples of cast operators are: **static_cast; const_cast; reinterpret_cast; dynamic_cast

*static_cast** Used for conversion between basic data types, such as converting ints to char s and ints to enum s
**NOTE** it is possible to lose precision when using static_cast to cast a double to a float.

HANDLING OVERFLOWS
Whilst it was tempting to use std::numeric_limits to check for overflows, it is forbidden to use templates from the standard template library (STL) in this project series until you get to CPP08.
Functions from the standard library, however, are permitted. I used std::strtod to convert the userinput saved as a string into float, double and int, using FLT_MAX, INT_MIN, etc to test for overflows and catching double overflows with errno = ERANGE)  

_________________________________________________________________________________________________________________________

ex01: serialisation--yes, that's Australian spelling ;) | reinterpret_cast

Create a Data structure, and use the following two functions on the address of the Data object.

uintptr_t serialize(Data* ptr); --> takes a pointer and converts it to the unsigned integer type uintptr_t.

Data* deserialize(uintptr_t raw); --> takes an unsigned integer parameter and converts it to a pointer to Data

uintptr_t  - unsigned integer type that is large enough to store memory addresses. You can also use it to work out the distance between two memory addresses.

uintptr_t is a platform-independent type, which means that it's guaranteed to be large enough to hold a pointer value on any platform, so it can be used in cross-platform code.

Usually found in the <cstdint> library for later C++ versions, I had to use <stdint.h> as all the projects in this series must be written with C++98

reinterpret_cast was used in both functions, as it can be used to convert a pointer or reference to an object of one type to a pointer or reference to an object of a completely different type. It can also be used to convert a pointer to a base class to a pointer to a derived class.


__________________________________________________________________________________________________________

ex02: Identify real type | dynamic_cast

!typeinfo header forbidden!

**Requirements** a base class, and three derived classes (A, B, C). The base class' destructor must be virtual. Why?

When a derived class object is deleted through a pointer or reference to the base class, and the base class destructor is not virtual, the base class destructor will be called instead of the derived class destructor. This can cause a problem known as "memory leak" which means that the resources allocated by the derived class will not be properly deallocated. By making the base class destructor virtual, the correct derived class destructor will be called when the object is deleted, ensuring that all resources are properly deallocated

**dynamic_cast**
The dynamic_cast operator is used to perform a runtime type check, and it returns a pointer to the object of the specified type, if the object is of that type, or a null pointer if it is not.