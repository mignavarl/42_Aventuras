/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:22:30 by mignavar          #+#    #+#             */
/*   Updated: 2025/07/30 11:10:45 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <ostream>
# include <sstream>
# include <cstdlib>
# include <cstring>
# include <unistd.h>

# define MAX_CONTACTS 9 //Número de reseteo
# define BLACK   "\033[1;30m"
# define RED     "\033[1;31m"
# define GREEN   "\033[1;32m"
# define YELLOW  "\033[1;33m"
# define BLUE    "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN    "\033[1;36m"
# define WHITE   "\033[1;37m"
# define NC      "\033[0m"

#include "Contact.hpp"
class PhoneBook
{
	private:
		Contact people[MAX_CONTACTS];
	
	public:
		PhoneBook(/* args */);
		~PhoneBook();
		Contact *getContact(int cont);
		bool	add_person(Contact *person);
		void	search_people(PhoneBook book);
		void	print_name(std::string name, bool final);
};

#endif