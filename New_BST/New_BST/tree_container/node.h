#pragma once
#include <iostream>
#include <sstream>

namespace tree {
	/**
	* @brief Structure node, for implematation of BST
	*/
	template <typename T>
	struct Node {
		/**
		* @brief value
		*/
		T data;
		/**
		* @brief pointer on parent node
		*/
		Node<T>* parent;
		/**
		* @brief pointer on left node
		*/
		Node<T>* left;
		/**
		* @brief pointer on right node
		*/
		Node<T>* right;
		/**
		 * @brief Constructor with param
		 * @param value - value of inserted node
		*/
		Node(const T& value);
		Node(const Node<T>& node) = delete;
		Node& operator =(const Node<T>& node) = delete;
		
		/**
		 * @brief Move constructor
		 * @param node
		*/
		Node(Node<T>&& node) noexcept = default;
		
		/**
		 * @brief Move operator
		 * @param node
		*/
		Node<T>& operator =(Node<T>&& node) noexcept = default;

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
		 * @brief leaf check
		 * @return true/false is leaf or not
		*/
		bool is_leaf() const noexcept;

		/**
		 * @brief Operator to comparison 
		 * @param left - left node.
		 * @param right - right node, with that we compare
		 * @return result of comparison
		*/
		friend auto operator <=>(const Node<T>& l, const Node<T>& r) {
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
		friend bool operator ==(const Node<T>& l, const Node<T>& r) {
			return operator<=>(l, r) == 0;
		}

		/**
		 * @brief Operator not equel
		 * @param left - left node.
		 * @param right - right node, with that we compare
		 * @return result of comparison
		*/
		friend bool operator !=(const Node<T>& l, const Node<T>& r) {
			return operator<=>(l, r) != 0;
		}

		/**
		 * @brief Operator for output node
		 * @param stream - input stream
		 * @param node, that we output
		 * @return output stream
		*/
		friend std::ostream& operator<<(std::ostream& stream, const Node<T>& node) {
			std::ostringstream buffer{};
			buffer << node.data;
			stream << buffer.str();
			return stream;
		};
	};

	template <typename T>
	Node<T>::Node(const T& value) : data{ value }, parent{ nullptr }, left{ nullptr }, right{ nullptr } {}
	
	template <typename T>
	Node<T>::~Node() {
		if (!this->is_root()) {
			if (this == this->parent->left) {
				this->parent->left = nullptr;
			}
			else {
				this->parent->right = nullptr;
			}

			this->parent = nullptr;
		}

		this->left = nullptr;
		this->right = nullptr;
	}

	template <typename T>
	bool Node<T>::is_root() const noexcept {
		return this->parent == nullptr;
	}

	template <typename T>
	bool Node<T>::is_leaf() const noexcept {
		return this->left == nullptr && this->right == nullptr;
	}
}
