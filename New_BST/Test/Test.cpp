#include "pch.h"
#include "CppUnitTest.h"

#include "../New_BST/tree_container/binary_tree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
{
	TEST_CLASS(BST)
	{
	public:

		TEST_METHOD(ADD_NODE_SUCCESS)
		{
			//Arrange
			auto tree = new tree::BinaryTree<int>();
			auto expected = true; // has 5 - true

			//Act
			auto added = tree->add_node(5);
			auto actual = tree->has_value(5);

			//Assert
			Assert::AreEqual(expected, actual);
			Assert::IsTrue(added);
		}

		TEST_METHOD(REMOVE_NODE_SUCCESS)
		{
			//Arrange
			auto tree = new tree::BinaryTree<int>();
			auto expected = false; // has  5 - false

			//Act
			tree->add_node(5);
			tree->add_node(7);
			auto remove = tree->remove_node(5);
			auto actual = tree->has_value(5);

			//Assert
			Assert::AreEqual(expected, actual);
			Assert::IsTrue(remove);
		}

		TEST_METHOD(GET_SIZE_SUCCESS)
		{
			//Arrange
			auto tree = new tree::BinaryTree<int>();
			auto expected = 2;

			//Act
			tree->add_node(5);
			auto change_size = tree->add_node(7);
			auto actual_size = tree->get_size();

			//Assert
			Assert::AreEqual(expected, int(actual_size));
			Assert::IsTrue(change_size);
		}

		TEST_METHOD(IS_EMPTY_SUCCESS)
		{
			//Arrange
			auto tree = new tree::BinaryTree<int>();
			auto expected = true; // default init - empty tree

			//Act
			auto is_empty = tree->is_empty();

			//Assert
			Assert::AreEqual(expected, is_empty);
			Assert::IsTrue(is_empty);
		}

		TEST_METHOD(PRINT_SUCCESS)
		{
			//Arrange
			auto tree = new tree::BinaryTree<int>();
			std::string expected = "{ 1 5 9 }"; // default init - empty tree

			//Act
			auto added_1 = tree->add_node(5);
			auto added_2 = tree->add_node(9);
			auto added_3 = tree->add_node(1);
			auto print = tree->in_order_print();

			//Assert
			Assert::AreEqual(expected, print);
			Assert::IsTrue(added_3);
		}
	};
}
