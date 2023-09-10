#include <iostream>
#include <string>

using namespace std;

/*----- Abstract class with basic methods for all containers -----*/
class Container
{
public:

	/*----- Methods -----*/

	// data manipulations
	virtual void clear_data() = 0;

	// sorting elements
	virtual void sort_bubble() = 0;
	virtual void sort_fast_way(int low, int high) = 0; // qsort

	/*----- Utils -----*/

	virtual string to_string_container() = 0; // method for output index - value container
	virtual int get_hash_code() = 0; // get hash of all array
};

