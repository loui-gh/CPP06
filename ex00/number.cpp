/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:38:16 by Loui :)           #+#    #+#             */
/*   Updated: 2023/02/07 12:38:19 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}


double atof_cpp(const char* str) {
   double val = 0.0;
   double sign = 1.0;
    bool decimal = false;
   double decimal_multiplier = 0.1;
    for (const char* p = str; *p != 'f'; p++) {
        if (*p == '-') {
            sign = -1.0;
        } else if (*p == '.') {
            decimal = true;
        } else if (*p >= '0' && *p <= '9') {
            if (decimal) {
                val += (*p - '0') * decimal_multiplier;
                decimal_multiplier *= 0.1;
            } else {
                val = val * 10 + (*p - '0');
            }
        } else {
            break;
        }
    }
    return sign * val;
}