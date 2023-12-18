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
			Assert::AreEqual(expected, real_value);
			Assert::IsTrue(real_value);
		}

		TEST_METHOD(EQUEL_OPERATOR_NODE_SUCCESS)
		{
			//Arrange
			auto left_node = new tree::Node<int>(5);
			auto right_node = new tree::Node<int>(4);
			auto expected = false;

			//Act
			auto result = (left_node == right_node);

			//Assert

			Assert::IsTrue(result == expected);

		}

		TEST_METHOD(NOT_EQUEL_OPERATOR_NODE_SUCCESS)
		{
			//Arrange
			auto left_node = new tree::Node<int>(5);
			auto right_node = new tree::Node<int>(6);
			auto expected = true;

			//Act
			auto result = (left_node != right_node);

			//Assert
			Assert::AreEqual(expected, result);
			Assert::IsTrue(result);
		}

		TEST_METHOD(LESS_OPERATOR_NODE_SUCCESS)
		{
			//Arrange
			auto left_node = new tree::Node<int>(5);
			auto right_node = new tree::Node<int>(60);
			auto expected = true;

			//Act
			auto result = (left_node < right_node);

			//Assert
			Assert::IsTrue(result == expected);
		}

		TEST_METHOD(GREATER_OPERATOR_NODE_SUCCESS)
		{
			//Arrange
			auto left_node = new tree::Node<int>(4);
			auto right_node = new tree::Node<int>(6);
			auto expected = false;

			//Act
			auto result = (left_node > right_node);

			//Assert
			Assert::IsTrue(result == expected);
		}
	};
}
