# CPP06

***RULE*** For each exercise, the type conversion must be solved using one specific type of casting.
Your choice will be checked during defense. (the eval sheet requires static_cast to be used)


/*Converting one data type into another data type is called type conversions. There are two types:

    Implicit type conversion
Aka, 'automatic' type conversion is a small-to-large conversion, 'promotion cast'.

There are some risks associated with implicit type conversion, such as;
-loss of information, such as sign (when signed is implicitly converted to unsigned)
-overflow, e.g. when long long converted to float //this is not promotion cast as long long > float

	Explicit type conversion
Aka, 'type-casting'. Done in one of two ways;
1) convert by assignment
int main()
{
    double x = 1.2;
  
    // Explicit conversion from double to int
    int sum = (int)x + 1;
  
    cout << "Sum = " << sum;
  
    return 0;
}

2) Convert using cast operator. examples: **static_cast; const_cast; reinterpret_cast; dynamic_cast

*static_cast** Used for conversion between basic data types, such as converting ints to char s and ints to enum s

#include <iostream>
using namespace std;
int main()
{
    float f = 3.5;
  
    // using cast operator
    int b = static_cast<int>(f);
  
    cout << b;
}

*/

/*EXAMPLE OF IMPLICIT CONVERSION*/

int	main() {

	int x;
	for(x=97; x<=122; x++){
		printf("%c", x); /*Implicit casting from int to char %c*/
}
}