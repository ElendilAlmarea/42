/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 02:12:44 by yvanat            #+#    #+#             */
/*   Updated: 2020/02/13 02:52:50 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>

int main(int argc, char **argv) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    }
    else {
		for (int i = 1; i < argc; i++) {
			for (size_t j = 0; j < strlen(argv[i]); j++) {
				std::cout << (char)toupper(argv[i][j]);
			}
		}
		std::cout << "\n";
    }
    return 0;
}