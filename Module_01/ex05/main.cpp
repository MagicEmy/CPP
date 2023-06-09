/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:38:19 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/09 19:23:48 by emlicame         ###   ########.fr       */
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
	mrHarl.complain("debug");
	mrHarl.complain("info");
	mrHarl.complain("warning");
	mrHarl.complain("error");
	mrHarl.complain("randomgibberish");
	mrHarl.complain("");
	
	return (0);
}