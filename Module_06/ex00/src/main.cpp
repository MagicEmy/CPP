/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:23:10 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/25 18:28:46 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main() {

    ScalarConverter::convert("c");
    ScalarConverter::convert("42");
    ScalarConverter::convert("4.2f");
    ScalarConverter::convert("3.14159");
    ScalarConverter::convert("-inff");
    ScalarConverter::convert("nanf");

    return 0;
}
