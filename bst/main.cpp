#include "tree_container/binary_tree.h"

#include <iostream>

void show_work();

int main() 
{
	show_work();
	return 0;
}

void show_work()
{
	tree::Node* node = new tree::Node(8);
	tree::BinaryTree* tree = new tree::BinaryTree();
	tree->add_node(8);
	tree->add_node(10);
	tree->add_node(11);
	tree->add_node(4);
	std::cout << "Sorted bst: " << tree->in_order_print();
	std::cout << "\nSize:" << tree->get_size();
	tree->remove_node(4);
	std::cout << "\nSorted bst(after delete node 4): " << tree->in_order_print();
}