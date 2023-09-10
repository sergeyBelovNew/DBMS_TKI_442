#include "Menu.h"


// Show what I want to add
void Menu::show_intro() {
	string line;
	ifstream myfile("current_status.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << line << '\n';
		}
		myfile.close();
	}

	else cout << "Unable to open file";
}


// Basix example of program running
void Menu::run_default() {
	Array vector_basic = Array();
	vector_basic.show_info_custom_array();
	cout << "Entry\nBasic init array successful, size " << vector_basic.get_size();

	for (int i = 0; i < vector_basic.get_size(); i++) {
		vector_basic[i] = rand();
	}

	cout << "\nBasic array\n" << vector_basic.to_string_container();
	vector_basic.sort_bubble();
	cout << "\nBasic array(sort)\n" << vector_basic.to_string_container();

	vector_basic.get_min_element_of_array();
	cout << "\n";
	vector_basic.get_max_element_of_array();

	vector_basic.pop_back_element(7);
	vector_basic.push_back_element();
	vector_basic.insert_element(14, 5);

	cout << "\nBasic array\n" << vector_basic.to_string_container();
	getchar();
}
