#include "pch.h"
#include "CppUnitTest.h"
#include "../DBMS_FINAL/New_BST/tree_container/binary_tree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Nodetest
{
	TEST_CLASS(NODE)
	{
	public:

		TEST_METHOD(PARAM_INIT_NODE_SUCCESS)
		{
			//Arrange
			auto node = new tree::Node<int>(5);
			auto expected = 5;

			//Act
			auto real_value = node->data;

			//Assert
			Assert::IsTrue(real_value == expected);
		}

		TEST_METHOD(EQUEL_OPERATOR_NODE_SUCCESS)
		{
			//Arrange
			auto left_node = new tree::Node<int>(5);
			auto right_node = new tree::Node<int>(4);

			//Assert
			Assert::IsFalse(left_node == right_node);
		}

		TEST_METHOD(NOT_EQUEL_OPERATOR_NODE_SUCCESS)
		{
			//Arrange
			auto left_node = new tree::Node<int>(5);
			auto right_node = new tree::Node<int>(6);

			//Act
			auto result = (left_node != right_node);

			//Assert
			Assert::IsTrue(result);
		}

		TEST_METHOD(LESS_OPERATOR_NODE_SUCCESS)
		{
			//Arrange
			auto left_node = new tree::Node<int>(5);
			auto right_node = new tree::Node<int>(60);

			//Assert
			Assert::IsTrue(left_node < right_node);
		}

		TEST_METHOD(GREATER_OPERATOR_NODE_SUCCESS)
		{
			//Arrange
			auto left_node = new tree::Node<int>(4);
			auto right_node = new tree::Node<int>(6);

			//Assert
			Assert::IsFalse(left_node > right_node);
		}
	};
}
