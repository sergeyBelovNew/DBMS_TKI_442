#include "binary_tree.h"

namespace tree {
	void BinaryTree::in_order_remove_tree(Node* current) {
		if (current == nullptr) {
			return;
		}
		
		--this->size;
		this->in_order_remove_tree(current->left);
		this->in_order_remove_tree(current->right);

		delete current;
		current = nullptr;
	}

	void BinaryTree::in_order(Node* current) {
		if (current == nullptr) {
			return;
		}

		this->in_order(current->left);
		this->values.push_back(current->data);
		this->in_order(current->right);
	}

	void BinaryTree::make_values() {
		this->values.clear();
		this->in_order(root);
	}

	Node* tree::BinaryTree::find_min_node(Node* current) const noexcept {
		Node* min = current;
		while (min->left != nullptr) {
			min = min->left;
		}
		return min;
	}

	Node* tree::BinaryTree::find_max_node(Node* current) const noexcept {
		Node* max = current;
		while (max->right != nullptr) {
			max = max->right;
		}
		return max;
	}

	void BinaryTree::transplant(Node* deleted, Node* son) {
		if (deleted == son) {
			return;
		}

		int tree_data = son->data;
		Node* tree_parent = son->parent;
		Node* tree_right = son->right;
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

	void BinaryTree::swap(BinaryTree& other) noexcept {
		std::swap(this->root, other.root);
		std::swap(this->root->left, other.root->left);
		std::swap(this->root->right, other.root->right);
	}

	Node* BinaryTree::find_by_value(Node* current, const int& target) const noexcept {
		Node node{target};
		Node* ptr = current;
		
		while (node != *ptr && ptr != nullptr) {
			if (node < *ptr) {
				ptr = ptr->left;
			}
			else if (node > *ptr) {
				ptr = ptr->right;
			}
		}

		return ptr;
	}

	BinaryTree::BinaryTree() : root{nullptr}, size{0} {

	}

	BinaryTree::BinaryTree(std::initializer_list<int> list) : BinaryTree() {
		for (auto& item : list) {
			this->add_node(item);
		}
	}

	BinaryTree::BinaryTree(const BinaryTree& other): BinaryTree() {
		for (auto& item : other.values) {
			this->add_node(item);
		}
	}

	BinaryTree::BinaryTree(BinaryTree&& other) noexcept : BinaryTree() {
		*this = other;
	}

	BinaryTree& BinaryTree::operator=(const BinaryTree& other)  {
		if (this != &other) {
			BinaryTree node{ other };
			this->swap(node);
		}

		return *this;
	}

	BinaryTree& BinaryTree::operator=(BinaryTree&& other) noexcept {
		if (this != &other) {
			this->swap(other);
		}

		return *this;
	}

	BinaryTree::~BinaryTree() {
		this->in_order_remove_tree(this->root);
		this->root = nullptr;
	}

	bool BinaryTree::add_node(const int& value) {
		Node* new_node = new Node{ value };

		if (this->is_empty()) {
			this->root = new_node;
		}

		else {
			Node* current = this->root;
			Node* parent = nullptr;
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

	bool BinaryTree::remove_node(const int& value) {
		auto node = Node{value};

		if (this->is_empty()) {
			throw std::logic_error("Empty tree");
		}

		Node* current = this->root;
		while (current != nullptr && node != *current) {
			if (node < *current) {
				current = current->left;
			}
			else if (node > *current) {
				current = current->right;
			}
		}

		if (current == nullptr) {
			throw std::logic_error("Node with this value doesnt exist");
		}
		
		if (!current->is_leaf()) {
			if (current->right != nullptr && current->left != nullptr) {
				Node* min_right = this->find_min_node(current->right);
				transplant(current, min_right);
			}

			else {
				if (current->right != nullptr) {
					current = current->right;
				}
				else {
					current = current->left;
				}					
				int data_in_tree = current->data;
				Node* parent_node = current->parent;
				Node* right_node = current->right;
				Node* left_node = current->left;
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

	bool BinaryTree::has_value(const int value) const noexcept {
		return this->find_by_value(this->root, value) != nullptr;
	}

	bool BinaryTree::is_empty() const noexcept {
		return this->root == nullptr;
	}

	size_t BinaryTree::get_size() const noexcept {
		return this->size;
	}

	std::string BinaryTree::in_order_print() const noexcept {
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