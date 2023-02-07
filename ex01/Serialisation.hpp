/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialisation.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:38:35 by Loui :)           #+#    #+#             */
/*   Updated: 2023/02/07 12:38:38 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALISATION_HPP
# define SERIALISATION_HPP

#include <stdint.h>
#include <iostream>

struct Data {
    std::string name;
    int age;
    char gender;

};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif