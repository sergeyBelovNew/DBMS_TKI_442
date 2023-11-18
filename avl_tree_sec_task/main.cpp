#include <iostream>
#include "tree_container/binary_tree.h"
#include "tree_container/avl_tree.h"
using namespace tree;


static void viev_binary_tree_work()
{
	BaseTree* tree = new BaseTree();
	tree->insert_node_wrapper(7);
	tree->insert_node_wrapper(9);
	tree->insert_node_wrapper(2);
	tree->insert_node_wrapper(1);
	tree->insert_node_wrapper(10);

	std::cout << "Binary tree work:\n" << tree->print_values();
	std::cout << "\n" << tree->find_max_node()->data;
	std::cout << "\n" << tree->find_min_node()->data;
	std::cout << "\n" << tree->find_node_by_value_wrapper(10)->data;
	tree->remove_node_by_value_wrapper(10);
	std::cout << "\n" << tree->print_values();
}


static void viev_avl_tree_work()
{
	AvlTree* tree = new AvlTree();
	tree->insert_node_wrapper(7);
	tree->insert_node_wrapper(9);
	tree->insert_node_wrapper(2);
	tree->insert_node_wrapper(1);
	tree->insert_node_wrapper(10);

	std::cout << "\nAvl tree work:\n" << tree->print_values();
	std::cout << "\n" << tree->find_max_node()->data;
	std::cout << "\n" << tree->find_min_node()->data;
	std::cout << "\n" << tree->find_node_by_value_wrapper(10)->data;
	tree->remove_node_by_value_wrapper(10);
	std::cout << "\n" << tree->print_values();
}

int main() 
{
	viev_binary_tree_work();
	viev_avl_tree_work();
	return 0;
}
