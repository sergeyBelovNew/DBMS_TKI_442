#include "Node.h"

namespace tree {
	Node::Node(const int& d) : data{ d }, parent{ nullptr }, left{ nullptr }, right{ nullptr } {}

	Node::~Node() {
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

	bool Node::is_root() const noexcept {
		return this->parent == nullptr;
	}

	bool Node::is_leaf() const noexcept {
		return this->left == nullptr && this->right == nullptr;
	}
}
