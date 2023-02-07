/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:38:12 by Loui :)           #+#    #+#             */
/*   Updated: 2023/02/07 12:38:13 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

int	main(int argc, char **argv) {

	if (!err_check_content(argv) || !err_check_size(argc, argv))
		return 0;

	Converter	sample1(argv[1]);

	if (sample1.isChar() == true)
		sample1.convertChar();
	else if (sample1.isInt() == true)
		sample1.convertInt();
	else if (sample1.isFloat() == true)
		sample1.convertFloat();
	else if (sample1.isDouble() == true)
		sample1.convertDouble();
	else {
		std::cout << "Type conversion not possible\n";
		return 0;
	}
	std::cout << &sample1 << std::endl;
	return 0;
}
