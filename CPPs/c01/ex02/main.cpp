/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:38:12 by mignavar          #+#    #+#             */
/*   Updated: 2025/05/28 12:28:23 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string stringREF = brain;

	std::cout << "Memory address string:\t" << &brain << std::endl
			<< "Memory address PTR:\t" << &stringPTR << std::endl
			<< "Memory address REF:\t" << &stringREF << std::endl
			<< std::endl << "------------------------\n" << std::endl
			<< "Value string:\t" << brain << std::endl
			<< "Value PTR:\t" << stringPTR << std::endl
			<< "Value REF:\t" << stringREF << std::endl;
	return (0);
}