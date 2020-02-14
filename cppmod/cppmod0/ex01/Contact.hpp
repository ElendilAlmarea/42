#include <iostream>

class Contact{
	public:
		Contact();
		void	add_contact();
		void	search_contact();
	private:
		std::string contact_list[8][11];
		std::string fields[11];
		int index;
};