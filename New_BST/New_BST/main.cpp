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
	auto node = new tree::Node<int>(8);
	auto tree = new tree::BinaryTree<int>();
	tree->add_node(8);
	tree->add_node(10);
	tree->add_node(11);
	tree->add_node(4);
	std::cout << "Sorted bst: " << tree->in_order_print();
	std::cout << "\nSize:" << tree->get_size();
	tree->remove_node(4);
	std::cout << "\nSorted bst(after delete node 4): " << tree->in_order_print();
	bool has_val = tree->has_value(4);
	std::cout << "\nHas value 4: " << has_val;
}