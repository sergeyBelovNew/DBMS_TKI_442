#include "pch.h"
#include <list>
#include "CppUnitTest.h"

#include "../New_BST/tree_container/binary_tree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
{
	TEST_CLASS(BST)
	{
	public:

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

		TEST_METHOD(GET_SIZE_SUCCESS)
		{
			//Arrange
			std::initializer_list<int> list{ 1, 5 };
			auto tree = new tree::BinaryTree<int>(list);
			auto expected = 2;

			//Act
			auto actual_size = tree->get_size();

			//Assert
			Assert::AreEqual(expected, int(actual_size));
			Assert::IsTrue(actual_size);
		}

		TEST_METHOD(PRINT_SUCCESS)
		{
			//Arrange
			std::initializer_list<int> list{ 1, 5, 9 };
			auto tree = new tree::BinaryTree<int>(list);
			std::string expected = "{ 1 5 9 }"; 

			//Act
			auto print = tree->in_order_print();

			//Assert
			Assert::AreEqual(expected, print);
			Assert::IsTrue(tree);
		}

		TEST_METHOD(HAS_VALUE_SUCCESS)
		{
			//Arrange
			std::initializer_list<int> list{ 1, 5, 9 };
			auto tree = new tree::BinaryTree<int>(list);
			auto expected = true; // has value - true

			//Act
			auto actual = tree->has_value(5);

			//Assert
			Assert::AreEqual(expected, actual);
			Assert::IsTrue(actual);
		}
		TEST_METHOD(ADD_NODE_SUCCESS)
		{
			//Arrange
			auto tree = new tree::BinaryTree<int>();
			auto expected = true; // has value - true

			//Act
			auto added = tree->add_node(5);
			auto actual = tree->has_value(5); // tested upper

			//Assert
			Assert::AreEqual(expected, actual);
			Assert::IsTrue(added);
		}

		TEST_METHOD(REMOVE_NODE_SUCCESS)
		{
			//Arrange
			std::initializer_list<int> list{ 1, 5 };
			auto tree = new tree::BinaryTree<int>(list);
			auto expected = false; // has value - false

			//Act
			auto remove = tree->remove_node(5);
			auto actual = tree->has_value(5);

			//Assert
			Assert::AreEqual(expected, actual);
			Assert::IsTrue(remove);
		}
	};
}
