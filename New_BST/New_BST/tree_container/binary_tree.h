#pragma once
#include "Node.h"
#include <vector>
#include <sstream>
#include <exception>

namespace tree {
	/**
	* @brief BST - binary search tree
	*/
	template <typename T>
	class BinaryTree {
	public:
		/**
		 * @brief default constructor
		*/
		BinaryTree();
		/**
		 * @brief param constructor
		 * @param list of values for node in bst
		*/
		BinaryTree(std::initializer_list<T> list);
		/**
		 * @brief copy constructor
		 * @param other - tree from what we copy
		*/
		BinaryTree(const BinaryTree& other);
		/**
		 * @brief move constructor
		 * @param other - tree from what we move
		*/
		BinaryTree(BinaryTree&& other) noexcept;
		/**
		 * @brief copy operator
		 * @param other - tree from what we copy
		*/
		BinaryTree& operator=(const BinaryTree& other);
		/**
		 * @brief move operator
		 * @param other - tree from what we move
		*/
		BinaryTree& operator=(BinaryTree&& other) noexcept;
		/**
		 * @brief Destructor
		*/
		virtual ~BinaryTree();
		/**
		 * @brief insert new node
		 * @param value - value of new node
		 * @return true/false result of working method(sussess or fail)
		*/
		bool add_node(const T& value);
		/**
		 * @brief remove selected node
		 * @param value - value of node for delete
		 * @return true/false result of working method(sussess or fail)
		*/
		bool remove_node(const T& value);
		/**
		 * @brief Exist node with value
		 * @param value - value of node.
		 * @return true/false result of working method(sussess or fail)
		*/
		bool has_value(const T value) const noexcept;
		/**
		 * @brief Method for check exist tree or not(exist root or not)
		 * @return true/false result of working method(sussess or fail)
		*/
		bool is_empty() const noexcept;
		/**
		 * @brief get number of nodes in tree
		*/
		size_t get_size() const noexcept;
		/**
		 * @brief Output of tree values
		 * @return string with values
		*/
		std::string in_order_print() const noexcept;
	protected:
		/**
		 * @brief root node
		*/
		Node<T>* root;
		/**
		 * @brief number of nodes in tree
		*/
		size_t size;
		/**
		 * @brief find node with min data
		 * @param current - node from what we start search
		 * @return adress of min node
		*/
		Node<T>* find_min_node(Node<T>* current) const noexcept;
		/**
		 * @brief find node with max data
		 * @param current - node from what we start search
		 * @return adress of min node
		*/
		Node<T>* find_max_node(Node<T>* current) const noexcept;
		/**
		 * @brief Change current node on son.
		 * @param deleted - old node
		 * @param son - new node
		*/
		void transplant(Node<T>* deleted, Node<T>* son);
		/**
		 * @brief swap nodes
		 * @param other tree
		*/
		void swap(BinaryTree& other) noexcept;
		/**
		 * @brief find node by value
		 * @param current - node for start search
		 * @param target - value of node target
		 * @return adress of node / nullptr, if not exist
		*/
		Node<T>* find_by_value(Node<T>* current, const T& target) const noexcept;
	private:
		/**
		 * @brief Recurse delete tree
		 * @param current - by default root
		*/
		void in_order_remove_tree(Node<T>* current);
		//
		/**
		 * @brief Recurse form values
		 * @param current node, from what we start values formation
		*/
		void in_order(Node<T>* current);
		/**
		 * @brief sort by data
		*/
		std::vector<T> values;
		/**
		 * @brief recurse call form values
		*/
		void make_values();
	};

	template <typename T>
	void BinaryTree<T>::in_order_remove_tree(Node<T>* current) {
		if (current == nullptr) {
			return;
		}

		--this->size;
		this->in_order_remove_tree(current->left);
		this->in_order_remove_tree(current->right);

		delete current;
		current = nullptr;
	}

	template <typename T>
	void BinaryTree<T>::in_order(Node<T>* current) {
		if (current == nullptr) {
			return;
		}

		this->in_order(current->left);
		this->values.push_back(current->data);
		this->in_order(current->right);
	}

	template <typename T>
	void BinaryTree<T>::make_values() {
		this->values.clear();
		this->in_order(root);
	}

	template <typename T>
	Node<T>* tree::BinaryTree<T>::find_min_node(Node<T>* current) const noexcept {
		Node<T>* min = current;
		while (min->left != nullptr) {
			min = min->left;
		}
		return min;
	}

	template <typename T>
	Node<T>* tree::BinaryTree<T>::find_max_node(Node<T>* current) const noexcept {
		Node* max = current;
		while (max->right != nullptr) {
			max = max->right;
		}
		return max;
	}

	template <typename T>
	void BinaryTree<T>::transplant(Node<T>* deleted, Node<T>* son) {
		if (deleted == son) {
			return;
		}

		int tree_data = son->data;
		Node<T>* tree_parent = son->parent;
		Node<T>* tree_right = son->right;
		delete son;

		if (tree_parent == deleted) {
			tree_parent->right = tree_right;
		}
		else {
			tree_parent->left = tree_right;
		}
		if (tree_right != nullptr) {
			tree_right->parent = tree_parent;
		}

		deleted->data = tree_data;
	}

	template <typename T>
	void BinaryTree<T>::swap(BinaryTree& other) noexcept {
		std::swap(this->root, other.root);
		std::swap(this->root->left, other.root->left);
		std::swap(this->root->right, other.root->right);
	}

	template <typename T>
	Node<T>* BinaryTree<T>::find_by_value(Node<T>* current, const T& target) const noexcept {
		if (current != nullptr) {
			Node<T>* node = new Node<T>(target);
			Node<T>* ptr = current;

			while (*node != *ptr && ptr != nullptr) {
				if (*node < *ptr) {
					if (ptr->left != nullptr)
						ptr = ptr->left;
					else
						return nullptr;
				}
				else if (*node > *ptr) {
					if (ptr->right != nullptr)
						ptr = ptr->right;
					else
						return nullptr;
				}
			}

			return ptr;
		}
		return nullptr;
	}

	template <typename T>
	BinaryTree<T>::BinaryTree() : root{ nullptr }, size{ 0 } {

	}

	template <typename T>
	BinaryTree<T>::BinaryTree(std::initializer_list<T> list) : BinaryTree() {
		for (auto& item : list) {
			this->add_node(item);
		}
	}

	template <typename T>
	BinaryTree<T>::BinaryTree(const BinaryTree& other) : BinaryTree() {
		for (auto& item : other.values) {
			this->add_node(item);
		}
	}

	template <typename T>
	BinaryTree<T>::BinaryTree(BinaryTree&& other) noexcept : BinaryTree() {
		*this = other;
	}

	template <typename T>
	BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree& other) {
		if (this != &other) {
			BinaryTree node{ other };
			this->swap(node);
		}

		return *this;
	}

	template <typename T>
	BinaryTree<T>& BinaryTree<T>::operator=(BinaryTree&& other) noexcept {
		if (this != &other) {
			this->swap(other);
		}

		return *this;
	}

	template <typename T>
	BinaryTree<T>::~BinaryTree() {
		this->in_order_remove_tree(this->root);
		this->root = nullptr;
	}

	template <typename T>
	bool BinaryTree<T>::add_node(const T& value) {
		Node<T>* new_node = new Node<T>( value );

		if (this->is_empty()) {
			this->root = new_node;
		}

		else {
			Node<T>* current = this->root;
			Node<T>* parent = nullptr;
			while (current != nullptr && *current != *new_node) {
				parent = current;
				if (*new_node < *current) {
					current = current->left;
				}
				else if (*new_node > *current) {
					current = current->right;
				}
			}

			if (*new_node < *parent) {
				parent->left = new_node;
			}
			else {
				parent->right = new_node;
			}

			new_node->parent = parent;
		}

		++this->size;
		this->make_values();
		return true;
	}

	template <typename T>
	bool BinaryTree<T>::remove_node(const T& value) {
		Node<T>* node = new Node<T>(value);

		if (this->is_empty()) {
			throw std::logic_error("Empty tree");
		}

		Node<T>* current = this->root;
		while (current != nullptr && *node != *current) {
			if (*node < *current) {
				current = current->left;
			}
			else if (*node > *current) {
				current = current->right;
			}
		}

		if (current == nullptr) {
			throw std::logic_error("Node with this value doesnt exist");
		}

		if (current->is_leaf() == false) {
			if (current->right != nullptr && current->left != nullptr) {
				Node<T>* min_right = this->find_min_node(current->right);
				transplant(current, min_right);
			}

			else {
				if (current->right != nullptr) {
					current = current->right;
				}
				else {
					current = current->left;
				}
				T data_in_tree = current->data;
				Node<T>* parent_node = current->parent;
				Node<T>* right_node = current->right;
				Node<T>* left_node = current->left;
				delete current;

				parent_node->data = data_in_tree;
				parent_node->right = right_node;
				parent_node->left = left_node;
			}
		}
		else {
			delete current;
			current = nullptr;
		}

		--this->size;
		this->make_values();
		return true;
	}

	template <typename T>
	bool BinaryTree<T>::has_value(const T value) const noexcept {
		return this->find_by_value(this->root, value) != nullptr;
	}

	template <typename T>
	bool BinaryTree<T>::is_empty() const noexcept {
		return this->root == nullptr;
	}

	template <typename T>
	size_t BinaryTree<T>::get_size() const noexcept {
		return this->size;
	}

	template <typename T>
	std::string BinaryTree<T>::in_order_print() const noexcept {
		std::ostringstream buffer{};
		if (this->size == 0) {
			buffer << "Empty tree";
		}
		else {
			buffer << "{ ";

			for (auto it = this->values.cbegin(); it != this->values.cend(); ++it) {
				buffer << (*it) << " ";
			}

			buffer << "}";
		}

		return buffer.str();
	}
}