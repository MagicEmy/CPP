/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:38:19 by emlicame          #+#    #+#             */
/*   Updated: 2023/05/22 17:28:50 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main (void)
{
	Harl mrHarl;
	
	mrHarl.complain("DEBUG");
	mrHarl.complain("INFO");
	mrHarl.complain("WARNING");
	mrHarl.complain("ERROR");
	
	return (0);
}