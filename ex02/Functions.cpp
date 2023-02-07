/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:38:49 by Loui :)           #+#    #+#             */
/*   Updated: 2023/02/07 12:38:51 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Classes.hpp"

/*randomly instanciates A, B or C and returns the instance as a Base pointer. Feel free
to use anything you like for the random choice implementation.*/

Base * generate(void) {


	std::srand(std::time(0));
	int randomSelect = std::rand() % 3 + 1;

	Base *ptr = NULL;
	
	if (randomSelect == 1)
		ptr = new A;
	else if (randomSelect == 2)
		ptr = new B;
	else if (randomSelect == 3)
		ptr = new C;
	else
		std::cout << "Something went wrong is random selection. RandomSelect == " << randomSelect << std::endl;
	// switch (randomSelect) {
	// 	case 1:
	// 		ptr = new A();
	// 	case 2:
	// 		ptr = new B();
	// 	case 3:
	// 		ptr = new C();
	// 	default:
	// 		ptr = NULL;
	// }

	return ptr;
}

/*It prints the actual type of the object pointed to by pointer: "A", "B" or "C".*/
void identify(Base* p) {

	A *aClass = dynamic_cast<A*>(p);
	B *bClass = dynamic_cast<B*>(p);
	C *cClass = dynamic_cast<C*>(p);

	if (aClass != NULL)
		std::cout << "Object is A\n";
	else if (bClass != NULL)
		std::cout << "Object is B\n";
	else if (cClass != NULL)
		std::cout << "Object is C\n";
	else
		std::cout << "Something went wrong in identify function.\n";

	//delete ptr;
	
}

/*It prints the actual type of the object pointed to by p: "A", "B" or "C". 
!!!!!Using a pointer inside this function is forbidden!!!*/
void identify(Base& p) 
{
	try 
	{
		A& ClassA = dynamic_cast<A&>(p); (void)ClassA;
		std::cout << "Object is A\n";
		return;
	} 
	
	catch (...) {}

	try 
	{
		B& ClassB = dynamic_cast<B&>(p); (void)ClassB;
		std::cout << "Object is B\n";
		return;
	} 
	
	catch (...) {}

	try 
	{
		C& ClassC = dynamic_cast<C&>(p); (void)ClassC;
		std::cout << "Object is C\n";
		return;
	} 
	
	catch (...) {}

	std::cout << "Can't identify the class" << std::endl;
}