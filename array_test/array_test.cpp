#include "pch.h"
#include "CppUnitTest.h"
#include "../zero_array/Array/Array.h"
#include "../zero_array/Array/Array.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace arraytest
{
	TEST_CLASS(array_test)
	{
	public:

		TEST_METHOD(unit_test_init_default_class) {
			Array array = Array();
			Assert::AreEqual(int(array.get_size()), 10);
		}
		TEST_METHOD(unit_test_init_param_class) {
			Array array = Array(14);
			Assert::AreEqual(int(array.get_size()), 14);
		}

		TEST_METHOD(unit_test_init_by_obj_class) {
			Array array_1 = Array(70);
			Array array_2 = Array(array_1);
			Assert::AreEqual(int(array_2.get_size()), 70);
		}

		TEST_METHOD(unit_test_sum_oper) {
			Array array_1 = Array();
			Array array_2 = Array();
			Array array_3 = Array();
			array_1[0] = 5;
			array_2[0] = 5;
			array_3 = array_1 + array_2;
			Assert::AreEqual(array_3[0], 10);
		}

		TEST_METHOD(unit_test_minus_oper) {
			Array array_1 = Array();
			Array array_2 = Array();
			Array array_3 = Array();
			array_1[0] = 6;
			array_2[0] = 5;
			array_3 = array_1 - array_2;
			Assert::AreEqual(array_3[0], 1);
		}

		TEST_METHOD(unit_test_single_equel_oper) {
			Array array_1 = Array();
			Array array_2 = Array();
			array_1[0] = 15;
			array_2[0] = 155;
			array_1 = array_2;
			Assert::AreEqual(array_1[0], 155);
		}

		TEST_METHOD(unit_test_is_equel_oper) {
			Array array_1 = Array();
			Array array_2 = Array();
			array_1[0] = 5;
			array_2[0] = 155;
			Assert::AreEqual(array_1.is_equel(array_2), false);
		}

		TEST_METHOD(unit_test_add_element) {
			Array array_1 = Array(1);
			array_1.pop_back_element(6);
			Assert::AreEqual(array_1[1], 6);
		}

		TEST_METHOD(unit_test_drop_element) {
			Array array_1 = Array(2);
			array_1.push_back_element();
			Assert::AreEqual(int(array_1.get_size()), 1);
		}

		TEST_METHOD(unit_test_insert_element) {
			Array array_1 = Array(1);
			array_1.insert_element(10, 8);
			Assert::AreEqual(int(array_1[10]), 8);
		}
	};
}
