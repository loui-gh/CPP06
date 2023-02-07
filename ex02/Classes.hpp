/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classes.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:38:46 by Loui :)           #+#    #+#             */
/*   Updated: 2023/02/07 12:38:48 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSES_HPP
# define CLASSES_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
/*Implement a Base class that has a public virtual destructor only. Create three empty
classes A, B and C, that publicly inherit from Base.*/
class Base
{
	protected:
		/* data */
	public:
		Base(/* args */);
		virtual ~Base();
};


class A : public Base {

};

class B : public Base {

};

class C : public Base {

};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif