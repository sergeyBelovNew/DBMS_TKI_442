#pragma once
#include "Node.h"
#include <vector>
#include <sstream>
#include <exception>

namespace tree {
	/**
	* @brief BST - binary search tree
	*/
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
		BinaryTree(std::initializer_list<int> list);
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
		bool add_node(const int& value);
		/**
		 * @brief remove selected node
		 * @param value - value of node for delete
		 * @return true/false result of working method(sussess or fail)
		*/
		bool remove_node(const int& value);
		/**
		 * @brief Exist node with value
		 * @param value - value of node.
		 * @return true/false result of working method(sussess or fail)
		*/
		bool has_value(const int& value) const noexcept;
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
		Node* root;
		/**
		 * @brief number of nodes in tree
		*/
		size_t size;
		/**
		 * @brief find node with min data
		 * @param current - node from what we start search
		 * @return adress of min node
		*/
		Node* find_min_node(Node* current) const noexcept;
		/**
		 * @brief find node with max data
		 * @param current - node from what we start search
		 * @return adress of min node
		*/
		Node* find_max_node(Node* current) const noexcept;
		/**
		 * @brief Change current node on son.
		 * @param deleted - old node
		 * @param son - new node
		*/
		void transplant(Node* deleted, Node* son);
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
		Node* find_by_value(Node* current, const int& target) const noexcept;
	private:
		/**
		 * @brief Recurse delete tree
		 * @param current - by default root
		*/
		void in_order_remove_tree(Node* current);
		//
		/**
		 * @brief Recurse form values
		 * @param current node, from what we start values formation
		*/
		void in_order(Node* current);
		/**
		 * @brief sort by data
		*/
		std::vector<int> values;
		/**
		 * @brief recurse call form values
		*/
		void make_values();
	};
}