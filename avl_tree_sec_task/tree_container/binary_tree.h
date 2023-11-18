#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include "Node.h"

namespace tree 
{
	class BaseTree 
	{
	public:
		/*---- Constructors and destructor ----*/
		BaseTree();
		BaseTree(std::initializer_list<int> list);
		BaseTree(const BaseTree& other); //currently dont relise
		BaseTree(BaseTree&& other) noexcept; //currently dont relise
		virtual ~BaseTree();

		/*---- Basic not wrapped methods ----*/
		std::string print_values();
		Node* find_min_node();
		Node* find_max_node();
		Node* get_root() { return root; };

		/*---- "Wrapper" methods(wrapped them to hide node in recurse) ----*/
		void insert_node_wrapper(const int target);
		Node* find_node_by_value_wrapper(const int target);
		void remove_node_by_value_wrapper(const int target);  // util for destructor

	private:
		/*---- Inner methods, that needed to work of "wrappers" ----*/
		void destroy_recursive(Node* node);
		Node* find_node_by_value(Node* node, const int target); 
		Node* insert_node(Node* node, const int target);
		Node* remove_node_by_value(Node* node, const int target);
		
		/*---- Fields ----*/
		Node* root;
		size_t size;
		std::vector<int> values;
	};
}