#include "avl_tree.h"

namespace tree
{
	/*
	* @brief inner method for insert (with balance)
	* @param node - node for recurse
	* @param target - value of node to insert
	*/
	Node* AvlTree::insert_node(Node* node, int target)
	{
		// Standart insert like in BST
		if (node == nullptr)
			return new Node(target);
		else if (target <= node->data)
			node->left = insert_node(node->left, target);
		else if (target > node->data)
			node->right = insert_node(node->right, target);

		// Update height of this ancestor node
		node->height = 1 + std::max(node->left->get_height_save(),
			node->right->get_height_save());

		// Get the balance factor of this ancestor node (to find unbalanced node)
		int balance = balance_tree(node);

		// If this node becomes unbalanced (4 ways)
		if (balance > 1 && target < node->left->data)
			return rotate_right(node);

		if (balance < -1 && target > node->right->data)
			return rotate_left(node);

		if (balance > 1 && target > node->left->data)
		{
			node->left = rotate_left(node->left);
			return rotate_right(node);
		}
 
		if (balance < -1 && target < node->right->data)
		{
			node->right = rotate_right(node->right);
			return rotate_left(node);
		}

		// return the unchanged node pointer 
		return node;
	}

	/*
	* @brief inner method for remove (with balance)
	* @param node - node for recurse
	* @param target - value of node to delete
	*/
	Node* AvlTree::remove_node_by_value(Node* node, const int target)
	{
		if (node == nullptr)
		{
			return NULL;
		}

		else
		{
			// node is found and needs to be deleted 
			if (target == node->data)
			{
				if (node->left == nullptr && node->right == nullptr)
				{
					delete node;
					return nullptr;
				}
				else if (node->left == nullptr)
				{
					Node* temp = node->right;
					delete node;
					return temp;
				}
				else if (node->right == nullptr)
				{
					Node* temp = node->left;
					delete node;
					return temp;
				}
				else
				{
					// finding the minimum value in the right subtree
					Node* min_right_subtree;
					Node* current = node->right;
					while (current->left != nullptr)
					{
						current = current->left;
					}

					min_right_subtree = current;
					node->data = min_right_subtree->data;
					node->right = remove_node_by_value(node->right, min_right_subtree->data);
				}
			}

			// keep searching for node
			else
			{
				if (target < node->data)
				{
					node->left = remove_node_by_value(node->left, target);
				}

				else if (target > node->data)
				{
					node->right = remove_node_by_value(node->right, target);
				}
			}

			// Balancing if needed
			int balance_factor = balance_tree(node);

			if (balance_factor > 1 &&
				balance_tree(node->left) >= 0)
				return this->rotate_right(node);

			// Left Right Case 
			if (balance_factor > 1 &&
				balance_tree(node->left) < 0)
			{
				node->left = this->rotate_left(node->left);
				return this->rotate_right(node);
			}

			// Right Right Case 
			if (balance_factor < -1 &&
				balance_tree(node->right) <= 0)
				return this->rotate_left(node);

			// Right Left Case 
			if (balance_factor < -1 &&
				balance_tree(node->right) > 0)
			{
				node->right = this->rotate_right(node->right);
				return this->rotate_left(node);
			}

			return node;
		}
	}

	/*
	* @brief inner method for insert
	* @param node - node for recurse
	*/
	Node* AvlTree::rotate_right(Node* node)
	{
		Node* new_root = node->left;
		Node* right_root_node = new_root->right;

		// Perform rotation  
		new_root->right = node;
		node->left = right_root_node;

		// Update heights  
		node->height = std::max(node->left->get_height_save(),
			node->right->get_height_save()) + 1;
		new_root->height = std::max(new_root->left->get_height_save(),
			new_root->right->get_height_save()) + 1;

		// Return new root  
		return new_root;
	}

	/*
	* @brief inner method for insert
	* @param node - node for recurse
	*/
	Node* AvlTree::rotate_left(Node* node)
	{
		Node* new_root = node->right;
		Node* left_root_node = new_root->left;

		// Perform rotation  
		new_root->left = node;
		node->right = left_root_node;

		// Update heights  
		node->height = std::max(node->left->get_height_save(),
			node->right->get_height_save()) + 1;
		new_root->height = std::max(new_root->left->get_height_save(),
			new_root->right->get_height_save()) + 1;

		// Return new root  
		return new_root;
	}

	/*
	* @brief inner method for insert
	* @param node - node for recurse
	*/
	int AvlTree::balance_tree(Node* node)
	{
		if (node == nullptr)
			return 0;
		return node->left->get_height_save() - node->right->get_height_save();
	}
}