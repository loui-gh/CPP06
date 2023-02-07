/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:38:29 by Loui :)           #+#    #+#             */
/*   Updated: 2023/02/07 12:38:30 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialisation.hpp"

/*It takes a pointer and converts it to the unsigned integer type uintptr_t.*/
uintptr_t serialize(Data* ptr) {

	uintptr_t i = reinterpret_cast<uintptr_t>(ptr);

	return i;
}


/*
It takes an unsigned integer parameter and converts it to a pointer to Data.*/

Data* deserialize(uintptr_t raw) {

	Data *ptr;

	ptr = reinterpret_cast<Data*>(raw);

	return ptr;
}