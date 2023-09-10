#include "Array.h"

/*----- Realization of Array class constructors && destructor -----*/
Array::Array() {
	this->capabilty = 10;
	this->current_size = 0;
	this->array = new int[this->capabilty];
	this->clear_data();
}

Array::Array(size_t size) {
	this->capabilty = size;
	this->current_size = 0;
	this->array = new int[this->capabilty];
	this->clear_data();
}

Array::Array(const Array& vector) {
	this->capabilty = vector.capabilty;
	this->array = new int [this->capabilty];
	for (int i = 0; i < this->capabilty; i++) {
		this->array[i] = vector[i];
	}
}

Array::~Array() {
	cout << "Delete obj of Array class";
	delete[] this->array;
}

/*----- Realization of Array class overwrite && overloading operators -----*/

int& Array::operator[](int index) {
	return this->array[index];
}

const int& Array::operator[](int index) const {
	return this->array[index];
}

Array& Array::operator+(Array& vector) {
	if (this->capabilty == vector.get_size())
		for (int i = 0; i < this->capabilty; i++)
			this->array[i] += vector[i];
	else
		cout << "Not comparable size(dimensions)";
	return *this;
}

Array& Array::operator-(Array& vector) {
	if (this->capabilty == vector.get_size())
		for (int i = 0; i < this->capabilty; i++)
			this->array[i] -= vector[i];
	else
		cout << "Not comparable size(dimensions)";
	return *this;
}

Array& Array::operator=(Array& vector) {
	if (this->capabilty == vector.get_size())
		for (int i = 0; i < this->capabilty; i++)
			this->array[i] = vector[i];
	else
		cout << "Not comparable size(dimensions)";

	return *this;
}

/*----- Realization of Array class methods -----*/

// decr size by 1
void Array::push_back_element() {
	this->capabilty = this->capabilty - 1;
	this->resize_array(this->capabilty);
}

// add new element
void Array::pop_back_element(int element) {
	this->capabilty = this->capabilty + 1;
	this->resize_array(this->capabilty);
	this->array[this->capabilty - 1] = element;
}

void Array::insert_element(size_t index, int value) {
	if (index > this->capabilty) {
		this->capabilty = index + 1;
		this->resize_array(this->capabilty);
	}
	this->array[index] = value;
}

// fill data with 0
void Array::clear_data() {
	for (int i = 0; i < this->capabilty; i++)
		this->array[i] = NULL;
}

// simple sort
void Array::sort_bubble()
{
	try {
		for (int i = 0; i < this->capabilty - 1; i++) {
			for (int j = i + 1; j < this->capabilty; j++) {
				if (this->array[i] > this->array[j]){
					int temp = this->array[i];
					this->array[i] = this->array[j];
					this->array[j] = temp;
				}
			}
		}
		cout << "Bubble sort complite"; // log needed
	}
	catch (const exception& ex) {
		cerr << "Unknown exception in bubble sort" << ex.what();
	}
}
/*   
      Quicksort is an efficient, general - purpose sorting algorithm.
      Quicksort was developed by British computer scientist Tony Hoare in 1959
      and published in 1961. It is still a commonly used algorithm for sorting.
	  Overall, it is slightly faster than merge sortand heapsort for randomized data, 
      particularly on larger distributions.
*/

// fast recursive sort
void Array::sort_fast_way(int low, int high) {
	int i = low;
	int j = high;
	int pivot = this->array[(i + j) / 2];
	int temp;

	while (i <= j)
	{
		while (this->array[i] < pivot)
			i++;
		while (this->array[j] > pivot)
			j--;
		if (i <= j)
		{
			temp = this->array[i];
			this->array[i] = this->array[j];
			this->array[j] = temp;
			i++;
			j--;
		}
	}
	if (j > low)
		sort_fast_way(low, j);
	if (i < high)
		sort_fast_way(i, high);
}

int Array::get_max_element_of_array() {
	try {
		int max_element = this->array[0];
		for (int i = 0; i < this->capabilty - 1; i++) {
			if (this->array[i] < this->array[i + 1]) {
				max_element = this->array[i + 1];
			}
		}
		cout << "Finding max element complite\
                 \nCurrent max element:" << max_element; // log needed
		return max_element;
	}
	catch (const exception& ex) {
		cerr << "Unknown exception in get_max_element_of_array" << ex.what();
	}
}

int Array::get_min_element_of_array() {
	try {
		int min_element = this->array[0];
		for (int i = 0; i < this-> capabilty - 1; i++) {
			if (this->array[i + 1] < this->array[i]) 
				min_element = this->array[i + 1];
		}
		cout << "Finding min element complite\
                 \nCurrent min element:" << min_element; // log needed
		return min_element;
	}
	catch (const exception& ex) {
		cerr << "Unknown exception in get_min_element_of_array" << ex.what();
	}
}

/*----- Get string of index - array value(Maybe rewrite as lymbda) -----*/
string Array::to_string_container() {
	string to_string_container;
	for (int i = 0; i < this->capabilty; i++) {
		to_string_container += "Element [" + to_string(i) + "] - value: " \
			+ to_string(this->array[i]) + "\n";
	}
	return to_string_container;
}

//Maybe rewrite using boosty
int Array::get_hash_code() {
	return hash<string>()(this->to_string_container());
}

// show current "options" of Array class
void Array::show_info_custom_array() {
	string line;
	ifstream myfile("Array/array_info.txt");
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

//method for comparing arrays
bool Array::is_equel(Array& vector) {
	bool is_equel = false;
	if (this->capabilty == vector.get_size())
		for (int i = 0; i < this->capabilty; i++)
			if (this->array[i] != vector[i])
				return is_equel;
			else {
				is_equel = true;
				return is_equel;
			}
	else
		cout << "Not comparable size(dimensions)";
	return is_equel;
}

/*----- Increase/decr size! -----*/
void Array::resize_array(size_t new_size) {
	try {
		int* new_array = new int[new_size];

		// copy old elements to new array
		for (int i = 0; i < this->capabilty; i++) 
			new_array[i] = this->array[i];

		this->array = new_array;
		this->capabilty = new_size;
	} 
	catch (bad_alloc& ex) {
			cerr << "Exception in resize of array" << ex.what();
	}
}
