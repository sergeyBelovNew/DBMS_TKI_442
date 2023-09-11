#include <iostream>
#include <string>


using namespace std;


/*----- Prototyping procedures -----*/


/**
 * \brief Create array.
 * \param size - size of your array
 * \return array(fill).
*/


int* input_array(const size_t size);


/**
 * \brief Simple bubble sort(2 param).
 * \param array - your "raw" array
 * \param size - size of your array
*/


void sort_bubble(int* array, const size_t size);


/**
 * \brief Find max element of array(2 param).
 * \param array - your "raw" array
 * \param size - size of your array
 * \return max element of array.
*/


int get_max_element_of_array(int* array, const size_t size);


/**
 * \brief Find min element of array(2 param).
 * \param array - your "raw" array
 * \param size - size of your array
 * \return min element of array.
*/


int get_min_element_of_array(int* array, const size_t size);


/**
 * \brief Output of array in index - array value format.
 * \param array - your "raw" array
 * \param size - size of your array
*/


void show_array_index_to_value(int* array, const size_t size);


/**
 * \brief for see output of sorting, find max, min elements of array and custom func for output array.
*/


int main() {
	size_t size;

	cout << "Input array size ";
	cin >> size;

	if (size <= 0) {
		cout << "You entered wrong size!\n";
		return 1;
	}

	int* example_array = new int[size];

	example_array = input_array(size);

	show_array_index_to_value(example_array, size);

	get_max_element_of_array(example_array, size);

	get_min_element_of_array(example_array, size);

	sort_bubble(example_array, size);

	show_array_index_to_value(example_array, size);

	delete[] example_array;
	return 0;
}


/* ----- Realization procedures ----- */


int* input_array(const size_t size) {
	int* array = new int[size];
	cout << "Input array data(int type)\n";
	for (size_t index = 0; index < size; index++) {
		cin >> array[index];
	}
	return array;
}


void sort_bubble(int* array, const size_t size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (array[i] > array[j]) {
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	cout << "Bubble sort complite";
}


int get_max_element_of_array(int* array, const size_t capability) {
	int max_element = array[0];
	for (int i = 0; i < capability - 1; i++) {
		if (array[i] < array[i + 1]) {
			max_element = array[i + 1];
		}
	}
	cout << "Finding max element complite\
             \nCurrent max element:" << max_element << "\n";
	return max_element;
}


int get_min_element_of_array(int* array, const size_t size) {
	int min_element = array[0];
	for (int i = 0; i < size - 1; i++) {
		if (array[i + 1] < array[i])
			min_element = array[i + 1];
		}
	cout << "Finding min element complite\
             \nCurrent min element:" << min_element << "\n";
	return min_element;
}


void show_array_index_to_value(int* array, const size_t size) {
	for (int i = 0; i < size; i++) {
		cout << "Element [" << to_string(i) << "] - value: " \
			 << to_string(array[i]) << "\n";
	}
}
