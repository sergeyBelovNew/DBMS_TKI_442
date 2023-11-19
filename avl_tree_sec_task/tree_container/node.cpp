#include "node.h"
namespace tree
{
	/*
	* @brief basic node constractor
	*/
	Node::Node()
	{
		this->data = 0;
		this->height = 1;
		this->left = nullptr;
		this->right = nullptr;
	}

	/*
	* @brief node constractor with param
	* @param value - value of data field
	*/
	Node::Node(const int value)
	{
		this->data = value;
		this->height = 1;
		this->right = nullptr;
		this->left = nullptr;
	}

	/*
	* @brief node copy constractor 
	* @param node - orignal node(we copy this node fields)
	*/
	Node::Node(const Node & node)
	{
		this->data = node.data;
		this->height = 1;
		this->right = node.right;
		this->left = node.left;
	}

	/*
	* @brief denstractor, for deallocation dynamic given memory
	*/
	Node::~Node()
	{
		delete this->left;
		delete this->right;
	}

	/*
	* @brief For save get height in avl tree (used in situations like node->left->get_height_save)
	*/
	int Node::get_height_save()
	{
		if (this == nullptr)
			return NULL;
		return height;
	}

	/*
	* @brief overload ==
	* @param lha - left balue
	* @param rha - right balue
	*/
	bool operator==(const Node& lha, const Node& rha)
	{
		if (lha < rha || lha > rha)
			return true;
	}

	/*
	* @brief overload <
	* @param lha - left balue
	* @param rha - right balue
	*/
	bool operator<(const Node& lha, const Node& rha)
	{
		if (lha.data < rha.data)
			return true;
		return false;
	}

	/*
	* @brief overload >
	* @param lha - left balue
	* @param rha - right balue
	*/
	bool operator>(const Node& lha, const Node& rha)
	{
		if (lha.data > rha.data)
			return true;
		return false;
	}
}