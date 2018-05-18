/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurses.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 13:50:07 by msrun             #+#    #+#             */
/*   Updated: 2018/05/18 16:33:13 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSES_HPP
# define NCURSES_HPP

# include <ncurses.h>
# include "GameCore.hpp"

class Ncurses
{
	public:
		Ncurses(void);
		~Ncurses(void);
		Ncurses(Ncurses const &);
		Ncurses &	operator=(Ncurses const &);
		int	printMap(Data &);

	private:

};

#endif
