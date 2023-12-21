/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:58:52 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/25 11:36:23 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
			std::string _target;
			static const int _signGrade = 72;
			static const int _executeGrade = 45;
			
	public:
			RobotomyRequestForm( void );
			RobotomyRequestForm(std::string target);
			virtual ~RobotomyRequestForm( void );
			RobotomyRequestForm(const RobotomyRequestForm& src);
			RobotomyRequestForm& operator =(const RobotomyRequestForm& src);

			virtual void execute(Bureaucrat const & executor) const;
};

#endif