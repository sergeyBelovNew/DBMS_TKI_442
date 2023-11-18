#pragma once
#include <algorithm>
#include "binary_tree.h"

namespace tree {
	class AvlTree : public BaseTree 
	{
	private:
		/*---- Overwrite insert/remove to get lesser o(calculations difficulty) ----*/
		Node* insert_node(Node* node, const int target);
		Node* remove_node_by_value(Node* node, const int target);

		/*---- Util methods, that needed for work "insert/remove" ----*/
		Node* rotate_right(Node* node);
		Node* rotate_left(Node* node);
		int balance_tree(Node* node);
	};
}