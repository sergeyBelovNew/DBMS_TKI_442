#include "binary_tree.h"
namespace tree 
{
	/*
	* @brief default constructor
	*/
	BaseTree::BaseTree()
	{
		Node* node = new Node(0);
		this->root = node;
		this->size = 1;
		this->values.push_back(node->data);
	}

	/*
	* @brief constructor with parametrer
	* @param list of node values
	*/
	BaseTree::BaseTree(std::initializer_list<int> list)
	{
		Node* node = new Node(0);
		for (auto& item : list)
		{
			node->data = item;
			this->insert_node(node, item);
		}
	}

	/*
	* @brief recursive_destructor
	*/
	BaseTree::~BaseTree()
	{
		destroy_recursive(this->root);
	}

	/*
	* @brief output values method
	*/
	std::string BaseTree::print_values()
	{
		std::ostringstream buffer{};
		buffer << "{ ";
		for (auto it = this->values.cbegin(); it != this->values.cend(); ++it)
		{
			buffer << (*it) << " ";
		}
		buffer << "}";

		return buffer.str();
	}

	/*
	* @brief get node with min data(just go left)
	*/
	Node* BaseTree::find_min_node()
	{
		Node* min_value_node = this->root;
		while (min_value_node->left != nullptr) {
			min_value_node = min_value_node->left;
		}
		return min_value_node;
	}

	/*
	* @brief get node with max data(just go right)
	*/
	Node* BaseTree::find_max_node()
	{
		Node* max_value_node = this->root;
		while (max_value_node->right != nullptr) {
			max_value_node = max_value_node->right;
		}
		return max_value_node;
	}

	/*
	* @brief "wrapper" that insert new node to tree
	* @param target - value of the searched node
	*/
	void BaseTree::insert_node_wrapper(const int target)
	{
		insert_node(this->root, target);
		values.push_back(target);
	}

	/*
	* @brief "wrapper" for remove node
	* @param target - value of the searched node
	*/
	void BaseTree::remove_node_by_value_wrapper(const int target)
	{
		remove_node_by_value(root, target);
		values.erase(std::remove(values.begin(), values.end(), target), values.end());
	}

	/*
	* @brief "wrapper" for find value
	* @param target - value of the searched node
	*/
	Node* BaseTree::find_node_by_value_wrapper(const int target)
	{
		return find_node_by_value(this->root, target);
	}

	/*
	* @brief "inner" method to insert new node inside tree
	* @param node - node for recurse, def equels root
	* @param target - value of new inserted node
	*/
	Node* BaseTree::insert_node(Node* node, const int target)
	{
		if (node == nullptr)
			return new Node(target);
		else if (target <= node->data)
			node->left = insert_node(node->left, target);
		else if (target > node->data)
			node->right = insert_node(node->right, target);
	}

	/*
	* @brief "inner" method to delete node(work for 3 sitautions: 0, 1, 2 hiers)
	*/
	Node* BaseTree::remove_node_by_value(Node* node, const int target)
	{
		// If node hasnt any children
		if (node == nullptr)
			return node;

		if (node->data > target) {
			node->left = remove_node_by_value(node->left, target);
			return node;
		}
		else if (node->data < target) {
			node->right = remove_node_by_value(node->right, target);
			return node;
		}

		// If one of the children is empty
		if (node->left == nullptr) {
			Node* temp = node->right;
			delete node;
			return temp;
		}
		else if (node->right == nullptr) {
			Node* temp = node->left;
			delete node;
			return temp;
		}

		// If both children exist
		else {

			Node* succ_parent = node;

			Node* successor = node->right;
			while (successor->left != nullptr) {
				succ_parent = successor;
				successor = successor->left;
			}

			if (succ_parent != node)
				succ_parent->left = successor->right;
			else
				succ_parent->right = successor->right;

			node->data = successor->data;

			delete successor;
			return node;
		}
	}

	/*
	* @brief inner method to find node by value
	* @param target - value of searched node
	* @param node - node for resurce, by default root
	*/
	Node* BaseTree::find_node_by_value(Node * node, const int target)
	{
		if (node == nullptr)
			return NULL; 
		else if (target < node->data)
			return find_node_by_value(node->left, target);
		else if (target > node->data)
			return find_node_by_value(node->right, target);
		else
			return node;
	}
	

	/*
	* @brief util method for destructor
	* @param node - node for recurse
	*/
	void BaseTree::destroy_recursive(Node * node)
	{
		if (node)
		{
			destroy_recursive(node->left);
			destroy_recursive(node->right);
			delete node;
		}
	}
}
