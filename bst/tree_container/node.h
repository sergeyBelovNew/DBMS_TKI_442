#pragma once
#include <iostream>
#include <sstream>

namespace tree {
	/**
	* @brief Structure node, for implematation of BST
	*/
	struct Node {
		/**
		* @brief value
		*/
		int data;
		/**
		* @brief pointer on parent node
		*/
		Node* parent;
		/**
		* @brief pointer on left node
		*/
		Node* left;
		/**
		* @brief pointer on right node
		*/
		Node* right;
		/**
		 * @brief Constructor with param
		 * @param value - value of inserted node
		*/
		Node(const int& value);
		Node(const Node& node) = delete;
		Node& operator =(const Node& node) = delete;
		/**
		 * @brief Move constructor
		 * @param node
		*/
		Node(Node&& node) noexcept = default;
		/**
		 * @brief Move operator
		 * @param node
		*/
		Node& operator =(Node&& node) noexcept = default;
		/**
		 * @brief Destrucor.
		*/
		~Node();
		
		/**
		 * @brief Method for get info is current node root
		 * @return true/false root/not root
		*/
		bool is_root() const noexcept;
		/**
		 * @brief list check
		 * @return true/false is leaf or not
		*/
		bool is_leaf() const noexcept;

		/**
		 * @brief Operator to comparison 
		 * @param left - left node.
		 * @param right - right node, with that we compare
		 * @return result of comparison
		*/
		friend auto operator <=>(const Node& l, const Node& r) {
			if (std::less<int>()(l.data, r.data)) {
				return -1;
			}

			if (std::greater<int>()(l.data, r.data)) {
				return 1;
			}

			return 0;
		}

		/**
		 * @brief Operator to comparison
		 * @param left - left node.
		 * @param right - right node, with that we compare
		 * @return result of comparison
		*/
		friend bool operator ==(const Node& l, const Node& r) {
			return operator<=>(l, r) == 0;
		}

		/**
		 * @brief Operator for output node
		 * @param stream - input stream
		 * @param node, that we output
		 * @return output stream
		*/
		friend std::ostream& operator<<(std::ostream& stream, const Node& node) {
			std::ostringstream buffer{};
			buffer << node.data;
			stream << buffer.str();
			return stream;
		};
	};
}
