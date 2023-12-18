#include "pch.h"
#include <list>
#include "CppUnitTest.h"

#include "../DBMS_FINAL/New_BST/tree_container/binary_tree.h"

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

			//Act
			auto is_empty = tree->is_empty();

			//Assert
			Assert::IsTrue(is_empty);
		}

		TEST_METHOD(GET_SIZE_SUCCESS)
		{
			//Arrange
			std::initializer_list<int> list{ 1, 5 };
			auto tree = new tree::BinaryTree<int>(list);
			size_t expected = 2;

			//Act
			size_t actual_size = tree->get_size();

			//Assert
			Assert::AreEqual(expected, actual_size);
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
		}

		TEST_METHOD(HAS_INT_VALUE_SUCCESS)
		{
			//Arrange
			std::initializer_list<int> list{ 1, 5, 9 };
			auto tree = new tree::BinaryTree<int>(list);

			//Act
			auto actual = tree->has_value(5);

			//Assert
			Assert::IsTrue(actual);
		}
		TEST_METHOD(ADD_INT_NODE_SUCCESS)
		{
			//Arrange
			auto tree = new tree::BinaryTree<int>();

			//Act
			auto added = tree->add_node(5);
			auto actual = tree->has_value(5); // tested upper

			//Assert
			Assert::IsTrue(actual);
		}

		TEST_METHOD(REMOVE_INT_NODE_SUCCESS)
		{
			//Arrange
			std::initializer_list<int> list{ 1, 5 };
			auto tree = new tree::BinaryTree<int>(list);

			//Act
			auto remove = tree->remove_node(5);
			auto actual = tree->has_value(5);

			//Assert
			Assert::IsFalse(actual);
		}

		TEST_METHOD(HAS_DOUBLE_VALUE_SUCCESS)
		{
			//Arrange
			std::initializer_list<double> list{ 1.1, 5.1, 9.1 };
			auto tree = new tree::BinaryTree<double>(list);

			//Act
			auto actual = tree->has_value(5.1);

			//Assert
			Assert::IsTrue(actual);
		}
		TEST_METHOD(ADD_DOUBLE_NODE_SUCCESS)
		{
			//Arrange
			auto tree = new tree::BinaryTree<double>();

			//Act
			auto added = tree->add_node(5.1);
			auto actual = tree->has_value(5.1); // tested upper

			//Assert
			Assert::IsTrue(actual);
		}

		TEST_METHOD(REMOVE_DOUBLE_NODE_SUCCESS)
		{
			//Arrange
			std::initializer_list<double> list{ 1.1, 5.1};
			auto tree = new tree::BinaryTree<double>(list);

			//Act
			auto remove = tree->remove_node(5.1);
			auto actual = tree->has_value(5.1);

			//Assert
			Assert::IsFalse(actual);
		}
	};
}
