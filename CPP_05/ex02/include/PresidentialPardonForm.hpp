/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:07:01 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/25 11:36:10 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
			std::string _target;
			static const int _signGrade = 25;
			static const int _executeGrade = 5;
	
	public:
			PresidentialPardonForm( void );
			PresidentialPardonForm( std::string target );
			virtual ~PresidentialPardonForm( void );
			PresidentialPardonForm(const PresidentialPardonForm &src);
			PresidentialPardonForm& operator =(const PresidentialPardonForm &src);

			virtual void execute(Bureaucrat const & executor) const;
};

#endif