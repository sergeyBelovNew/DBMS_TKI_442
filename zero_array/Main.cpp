#include <iostream>
#include <string>

/**
 * @brief Create array.
 * @param size - size of your array
 * @return array(fill).
*/
int* input_array(const size_t size);

/**
 * @brief Simple bubble sort(2 param).
 * @param array - your "raw" array
 * @param size - size of your array
*/
void sort_bubble(int* array, const size_t size);

/**
 * @brief Find max element of array(2 param).
 * @param array - your "raw" array
 * @param size - size of your array
 * @return max element of array.
*/
int get_max_element_of_array(int* array, const size_t size);

/**
 * @brief Find min element of array(2 param).
 * @param array - your "raw" array
 * @param size - size of your array
 * @return min element of array.
*/
int get_min_element_of_array(int* array, const size_t size);

/**
 * @brief Output of array in index - array value format.
 * @param array - your "raw" array
 * @param size - size of your array
*/
std::string to_string_array(int* array, const size_t size);

/**
 * @brief Used to input array size(catch execept if bad).
 * @param size - size of your array
*/
size_t check_array_size(int size);

/**
 * @brief for see output of sorting, find max, min elements of array and custom func for output array.
*/
int main() {

	int unchecked_size;
	std::cout << "Input array size ";
	std::cin >> unchecked_size;
	size_t size = check_array_size(unchecked_size);

	int* example_array = new int[size];

	example_array = input_array(size);

	std::cout << to_string_array(example_array, size) << "\n";

	std::cout << "Max element: " << get_max_element_of_array(example_array, size) << "\n";

	std::cout << "Min element: " << get_min_element_of_array(example_array, size) << "\n";

	sort_bubble(example_array, size);

	std::cout << to_string_array(example_array, size) << "\n";

	if (example_array != nullptr) {
		delete[] example_array;
		example_array = nullptr;
	}

	return 0;
}

int* input_array(const size_t size) {
	int* array = new int[size];
	std::cout << "Input array data(int type)\n";
	for (size_t index = 0; index < size; index++)
		std::cin >> array[index];
	return array;
}

void sort_bubble(int* array, const size_t size) {
	for (size_t i = 0; i < size - 1; i++) {
		for (size_t j = i + 1; j < size; j++) {
			if (array[i] > array[j]) {
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}

int get_max_element_of_array(int* array, const size_t capability) {
	int max_element = array[0];
	for (size_t i = 0; i < capability - 1; i++) {
		if (array[i] < array[i + 1])
			max_element = array[i + 1];
	}
	return max_element;
}

int get_min_element_of_array(int* array, const size_t size) {
	int min_element = array[0];
	for (size_t i = 0; i < size - 1; i++) {
		if (array[i + 1] < array[i])
			min_element = array[i + 1];
		}
	return min_element;
}

std::string to_string_array(int* array, const size_t size) {
	std::string out;
	for (size_t i = 0; i < size; i++) 
		out += std::to_string(array[i]);
	return out;
}

size_t check_array_size(int size) {
	if (size <= 0) {
		std::cout << "You entered wrong size!\n";
		throw std::out_of_range(" Error!");
	}
	return (size_t)size;
}