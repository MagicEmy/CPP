/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:52:25 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/24 17:55:59 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
			std::string _target;
			static const int _signGrade = 145;
			static const int _executeGrade = 137;
	public:
			ShrubberyCreationForm( void );
			ShrubberyCreationForm(std::string target);
			virtual ~ShrubberyCreationForm( void );
			ShrubberyCreationForm(const ShrubberyCreationForm &src);
			ShrubberyCreationForm& operator =(const ShrubberyCreationForm &src);

			virtual void execute(Bureaucrat const & executor) const;
};

#endif 
