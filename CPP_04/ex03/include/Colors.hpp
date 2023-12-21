/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:44:09 by emanuela          #+#    #+#             */
/*   Updated: 2023/06/16 15:29:03 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_HPP
#define COLORS_HPP

#define RESET		"\x1b[0m"
#define BOLD		"\x1B[1m"
#define ITALIC		"\x1B[3m"
#define UP_DEL		"\033[F\x1b[0J"

/* ====================================||==================================== *\
||									Rainbow									  ||
\* ===============colors===============||==================================== */
#define LRED		"\x1b[38;2;255;128;128m"
#define RED			"\x1b[38;2;255;0;0m"
#define DRED		"\x1b[38;2;128;0;0m"
#define LORANGE		"\x1b[38;2;255;192;128m"
#define ORANGE		"\x1b[38;2;255;128;0m"
#define DORANGE		"\x1b[38;2;128;64;0m"
#define LYELLOW		"\x1b[38;2;255;255;128m"
#define YELLOW		"\x1b[38;2;255;255;0m"
#define DYELLOW		"\x1b[38;2;128;128;0m"
#define LCHRT		"\x1b[38;2;192;255;128m"
#define CHRT		"\x1b[38;2;128;255;0m"	//chartreuse
#define DCHRT		"\x1b[38;2;64;128;0m"
#define LGREEN		"\x1b[38;2;128;255;128m"
#define GREEN		"\x1b[38;2;0;255;0m"
#define DGREEN		"\x1b[38;2;0;128;0m"
#define LSPRGR		"\x1b[38;2;128;255;192m"
#define SPRGR		"\x1b[38;2;0;255;128m"	//spring green
#define DSPRGR		"\x1b[38;2;0;128;64m"
#define LCYAN		"\x1b[38;2;128;255;255m"
#define CYAN		"\x1b[38;2;0;255;255m"
#define DCYAN		"\x1b[38;2;0;128;128m"
#define LAZURE		"\x1b[38;2;0;192;255m"
#define AZURE		"\x1b[38;2;0;128;255m"
#define DAZURE		"\x1b[38;2;0;64;128m"
#define LBLUE		"\x1b[38;2;128;128;255m"
#define BLUE		"\x1b[38;2;0;0;255m"
#define DBLUE		"\x1b[38;2;0;0;128m"
#define LVIOLET		"\x1b[38;2;192;0;255m"
#define VIOLET		"\x1b[38;2;128;0;255m"
#define DVIOLET		"\x1b[38;2;64;0;255m"
#define LMGNT		"\x1b[38;2;255;128;255m"
#define MGNT		"\x1b[38;2;255;0;255m"	//magenta
#define DMGNT		"\x1b[38;2;128;0;128m"
#define LROSE		"\x1b[38;2;255;128;192m"
#define ROSE		"\x1b[38;2;255;0;128m"
#define DROSE		"\x1b[38;2;128;0;64m"

/* ====================================||==================================== *\
||																			  ||
||								  Backgrounds								  ||
||																			  ||
\* ===============colors===============||==================================== */

#define B_LRED		"\x1b[48;2;255;128;128m"
#define B_RED		"\x1b[48;2;255;0;0m"
#define B_DRED		"\x1b[48;2;128;0;0m"
#define B_LORANGE	"\x1b[48;2;255;192;128m"
#define B_ORANGE	"\x1b[48;2;255;128;0m"
#define B_DORANGE	"\x1b[48;2;128;64;0m"
#define B_LYELLOW	"\x1b[48;2;255;255;128m"
#define B_YELLOW	"\x1b[48;2;255;255;0m"
#define B_DYELLOW	"\x1b[48;2;128;128;0m"
#define B_LCHRT		"\x1b[48;2;192;255;128m"
#define B_CHRT		"\x1b[48;2;128;255;0m"	//chartreuse
#define B_DCHRT		"\x1b[48;2;64;128;0m"
#define B_LGREEN	"\x1b[48;2;128;255;128m"
#define B_GREEN		"\x1b[48;2;0;255;0m"
#define B_DGREEN	"\x1b[48;2;0;128;0m"
#define B_LSPRGR	"\x1b[48;2;128;255;192m"
#define B_SPRGR		"\x1b[48;2;0;255;128m"	//spring green
#define B_DSPRGR	"\x1b[48;2;0;128;64m"
#define B_LCYAN		"\x1b[48;2;128;255;255m"
#define B_CYAN		"\x1b[48;2;0;255;255m"
#define B_DCYAN		"\x1b[48;2;0;128;128m"
#define B_LAZURE	"\x1b[48;2;0;192;255m"
#define B_AZURE		"\x1b[48;2;0;128;255m"
#define B_DAZURE	"\x1b[48;2;0;64;128m"
#define B_LBLUE		"\x1b[48;2;128;128;255m"
#define B_BLUE		"\x1b[48;2;0;0;255m"
#define B_DBLUE		"\x1b[48;2;0;0;128m"
#define B_LVIOLET	"\x1b[48;2;192;0;255m"
#define B_VIOLET	"\x1b[48;2;128;0;255m"
#define B_DVIOLET	"\x1b[48;2;64;0;255m"
#define B_LMGNT		"\x1b[48;2;255;128;255m"
#define B_MGNT		"\x1b[48;2;255;0;255m"	//magenta
#define B_DMGNT		"\x1b[48;2;128;0;128m"
#define B_LROSE		"\x1b[48;2;255;128;192m"
#define B_ROSE		"\x1b[48;2;255;0;128m"
#define B_DROSE		"\x1b[48;2;128;0;64m"
#endif