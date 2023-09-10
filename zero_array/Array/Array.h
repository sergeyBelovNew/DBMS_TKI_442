#pragma once
#include "Container.cpp"

#include <iostream>
#include <exception>
#include <string>
#include <sstream>   
#include <fstream>

using namespace std;

/*----- Prototyping of Array class(heir of Container class) -----*/
class Array : public Container
{
public:
	/*----- Constructors && Destructor -----*/

	Array();
	Array(size_t size);
	Array(const Array& vector);
	~Array();

	/*----- Overwriting and overloading of operators -----*/

	int& operator[](int index);
	const int& operator[](int index) const;
	Array& operator+(Array& vector);
	Array& operator-(Array& vector);
	Array& operator=(Array& vector);

	/*----- Prototyping methods -----*/

	// data manipulations
	void push_back_element();
	void pop_back_element(int element);
	void insert_element(size_t index, int value);
	void clear_data() override;

	// sorting && get min/max elements
	void sort_bubble() override;
	void sort_fast_way(int low, int high) override; // qsort
	int get_max_element_of_array();
	int get_min_element_of_array();

	/*----- Utils -----*/

	string to_string_container() override; // method for output index - value array
	int get_hash_code() override; // get hash of all array
	static void show_info_custom_array(); // show my comments about class
	bool is_equel(Array& vector); // return is current array equel to param array

	/*----- Getters -----*/

	int* get_array() {return this->array;}
	size_t get_size() {return this->capabilty;}

private:
	/*----- Increase/decr size! -----*/
	void resize_array(size_t new_size); // simple way of resize array: creating new array and copying old data to new

	size_t current_size; // dont using currently(current using size of array (number of <active> sections of array))
	size_t capabilty; // max size of array (memory allocated)
	int* array; // body of array
};

