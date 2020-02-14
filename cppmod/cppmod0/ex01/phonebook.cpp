/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 03:59:38 by yvanat            #+#    #+#             */
/*   Updated: 2020/02/14 20:00:18 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.cpp"

int	main(void) {
	Contact phone_cont;
	std::string cmd = "";
	std::cout << "Welcome in my marvelous phonebook. Enter 'ADD' to add a user, 'SEARCH' to display users, 'EXIT' to quit";
	while (cmd.compare("EXIT")) {
		std::cout << "\nEnter your command : ";
		std::cin >> cmd;
		if (!cmd.compare("ADD")) {
			phone_cont.add_contact();
		}
		else if (!cmd.compare("SEARCH")) {
			phone_cont.search_contact();
		}
	}
	return (0);
}