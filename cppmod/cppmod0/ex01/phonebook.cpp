/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 03:59:38 by yvanat            #+#    #+#             */
/*   Updated: 2020/02/13 07:26:51 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Contact {
	public:
		Contact() {
			index = 0;
			fields[0] = "first name", fields[1] = "last name", fields[2] = "nickname", fields[3] = "login";
			fields[4] = "postal address", fields[5] = "email address", fields[6] = "phone number";
			fields[7] = "birthday date", fields[8] = "favorite meal", fields[9] = "underwear color";
			fields[10] = "darkest secret";
		}
		void add_contact() {
			if (index >= 8) {
				std::cout << "Only 8 contacts can be stored in this little phonebook\n";
				return ;
			}
			for (int i = 0; i < 11; i++) {
				std::cout << "Enter " + fields[i] + " : ";
				std::cin >> contact_list[index][i];
			}
			index++;
		}
		void search_contact() {
			int id;
			bool check = true;
			if (index == 0) {
				std::cout << "There are no contacts yet, add one with 'ADD'\n";
				return ;
			}
			std::cout << "\n     index|      name| last name|  nickname\n";
			for (int i = 0; i < index; i++) {
				std::cout << "         ";
				std::cout << i;
				std::cout << "|";
				for (int j = 0; j < 3; j++) {
					for (int k = 0; k < 10 - (int)contact_list[i][j].length(); k++) {
						std::cout << " ";
					}
					for (int k = 0; k < (int)contact_list[i][j].length() && k < 10; k++) {
						if (k == 9) {
							std::cout << ".";
						}
						else {
							std::cout << contact_list[i][j][k];
						}
					}
					if (j != 2) {
						std::cout << "|";
					}
				}
				std::cout << "\n";
			}
			while (check) {
				check = false;
				std::cout << "\nEnter the contact's index whom you want more infos : ";
				std::cin >> id;
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					std::cout << "Bad index\n";
					check = true;
					continue ;
				}
				else {
					std::cin.ignore(32767, '\n');
				}
				if (id >= index) {
					std::cout << "Bad index\n";
					check = true;
					continue ;
				}
			}
			for (int i = 0; i < 11; i++) {
				std::cout << fields[i] + " : ";
				for (size_t j = 0; j < contact_list[id][i].length(); j++) {
					std::cout << contact_list[id][i][j];
				}
				std::cout << "\n";
			}
		}
	private:
		std::string contact_list[8][11];
		std::string fields[11];
		int index;
};

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