#pragma once
#include <ostream>
#include <sstream>
#include <utility>

namespace  tree 
{
	struct  Node 
	{
		Node();
		Node(const int value);
		Node(const Node& node);
		Node(const Node&& other) noexcept : data(std::move(other.data)) {};
		~Node();

		friend bool operator==(const Node& lha, const Node& rha);
		friend bool operator<(const Node& lha, const Node& rha); // Visual studio doesnt seen operator<=>, so I use standart <
		friend bool operator>(const Node& lha, const Node& rha); // Visual studio doesnt seen operator<=>, so I use standart >

		int get_height_save(); // for situation when left or right node doesnt exist (avl tree)

		int data;
		int height; // using in avl tree
		Node* left;
		Node* right;
	};
}

