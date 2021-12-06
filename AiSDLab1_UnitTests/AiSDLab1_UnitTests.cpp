#include "pch.h"
#include "CppUnitTest.h"
#include "../AiSDLab1/DuoLinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AiSDLab1UnitTests
{
	TEST_CLASS(NodeUnitTests) 
	{
	public:
		TEST_METHOD(Construtor_Test) {
			Node test(1);
			Assert::IsTrue(test.getNext() == nullptr); 
			Assert::IsTrue(test.getPrevious() == nullptr);
			Assert::IsTrue(test.getData() == 1); 
		}

		TEST_METHOD(getData_Test) {
			Node test(0);
			Assert::IsTrue(test.getData() == 0);
		}

		TEST_METHOD(getNext_Test) {
			Node test1(1);
			Assert::IsTrue(test1.getNext() == nullptr);
			Node test2(2);
			test1.setNext(&test2);
			Assert::IsTrue(test1.getNext() == &test2);
		}

		TEST_METHOD(getPrevious_Test) {
			Node test1(1);
			Assert::IsTrue(test1.getPrevious() == nullptr);
			Node test2(2);
			test1.setPrevious(&test2);
			Assert::IsTrue(test1.getPrevious() == &test2);
		}

		TEST_METHOD(setData_Test) {
			Node test(1);
			test.setData(5);
			Assert::IsTrue(test.getData() == 5);
			test.setData(0);
			Assert::IsTrue(test.getData() == 0);
		}

		TEST_METHOD(setNext_Test) {
			Node test1(0);
			Node test2(0);
			test1.setNext(&test2);
			Assert::IsTrue(test1.getNext() == &test2);
		}

		TEST_METHOD(setPrevious_Test) {
			Node test1(0);
			Node test2(0);
			test1.setPrevious(&test2);
			Assert::IsTrue(test1.getPrevious() == &test2);
		}
	};

	TEST_CLASS(DouLinkedListUnitTests)
	{
	public:
		TEST_METHOD(push_back_Test)
		{
			DouLinkedList list;
			for (int i = 0; i < 5; i++) {
				list.push_back(i);
			}
			for (int i = 0; i < 5; i++) {
				Assert::IsTrue(list.at(i) == i);
			}
		}

		TEST_METHOD(push_front_Test) {
			DouLinkedList list;
			for (int i = 0; i < 5; i++) {
				list.push_front(i);
			}
			for (int i = 0; i < 5; i++) {
				Assert::IsTrue(list.at(i) == 4 - i);
			}
		}

		TEST_METHOD(pop_back_Test) {
			DouLinkedList list;
			for (int i = 0; i < 5; i++) {
				list.push_back(i);
			}
			list.pop_back();
			for (int i = 0; i < 4; i++) {
				Assert::IsTrue(list.at(i) == i);
			}
			Assert::IsTrue(list.get_size() == 4);
		}

		TEST_METHOD(pop_front_Test) {
			DouLinkedList list;
			for (int i = 0; i < 5; i++) {
				list.push_back(i);
			}
			list.pop_front();
			for (int i = 0; i < 4; i++) {
				Assert::IsTrue(list.at(i) == i+1);
			}
			Assert::IsTrue(list.get_size() == 4);
		}

		TEST_METHOD(insert_Test) {
			DouLinkedList list;
			for (int i = 0; i < 3; i++) {
				list.push_back(i);
			}
			list.insert(99, 1);
			Assert::IsTrue((list.at(0) == 0) && (list.at(1) == 99) && (list.at(2) == 1) && (list.at(3) == 2));
			list.insert(999, -1);
			Assert::IsTrue((list.at(0) == 0) && (list.at(1) == 99) && (list.at(2) == 1) && (list.at(3) == 2));
			list.insert(9999, 5);
			Assert::IsTrue((list.at(0) == 0) && (list.at(1) == 99) && (list.at(2) == 1) && (list.at(3) == 2) && (list.at(4) == 9999));
			list.clear();
			list.insert(5,0);
			Assert::IsTrue(list.at(0) == 5);
		}

		TEST_METHOD(at_Test) {
			DouLinkedList list;
			for (int i = 0; i < 3; i++) {
				list.push_back(i+5);
			}
			Assert::IsTrue(list.at(1)==6);
		}

		TEST_METHOD(remove_Test) {
			DouLinkedList list;
			for (int i = 0; i < 5; i++) {
				list.push_back(i);
			}
			list.remove(2);
			Assert::IsTrue((list.at(0) == 0) && (list.at(1) == 1) && (list.at(2) == 3) && (list.at(3) == 4));
			list.remove(5);
			Assert::IsTrue((list.at(0) == 0) && (list.at(1) == 1) && (list.at(2) == 3) && (list.at(3) == 4));
			list.remove(-5);
			Assert::IsTrue((list.at(0) == 0) && (list.at(1) == 1) && (list.at(2) == 3) && (list.at(3) == 4));
		}

		TEST_METHOD(get_size_Test) {
			DouLinkedList list;
			Assert::IsTrue(list.get_size() == 0);
			for (int i = 0; i < 5; i++) {
				list.push_back(i);
			}
			Assert::IsTrue(list.get_size() == 5);
		}

		TEST_METHOD(clear_Test) {
			DouLinkedList list;
			for (int i = 0; i < 5; i++) {
				list.push_back(i);
			}
			list.clear();
			Assert::IsTrue(list.get_size() == 0);
			list.clear();
			Assert::IsTrue(list.get_size() == 0);
		}

		TEST_METHOD(set_Test) {
			DouLinkedList list;
			for (int i = 0; i < 3; i++) {
				list.push_back(i);
			}
			list.set(1, 99);
			Assert::IsTrue((list.at(0) == 0) && (list.at(1) == 99) && (list.at(2) == 2));
			list.set(5, 99);
			Assert::IsTrue((list.at(0) == 0) && (list.at(1) == 99) && (list.at(2) == 2));
			list.set(-5, 99);
			Assert::IsTrue((list.at(0) == 0) && (list.at(1) == 99) && (list.at(2) == 2));
		}

		TEST_METHOD(isEmpty_Test) {
			DouLinkedList list;
			Assert::IsTrue(list.isEmpty());
			for (int i = 0; i < 3; i++) {
				list.push_back(i);
			}
			Assert::IsTrue(!list.isEmpty());
		}

		TEST_METHOD(swap_Test) {
			DouLinkedList list;
			for (int i = 0; i < 4; i++) {
				list.push_back(i);
			}
			list.swap(1, 3);
			Assert::IsTrue((list.at(0) == 0) && (list.at(1) == 3) && (list.at(2) == 2) && (list.at(3) == 1));
			list.swap(2, 2);
			Assert::IsTrue((list.at(0) == 0) && (list.at(1) == 3) && (list.at(2) == 2) && (list.at(3) == 1));
			list.swap(-1, 3);
			Assert::IsTrue((list.at(0) == 0) && (list.at(1) == 3) && (list.at(2) == 2) && (list.at(3) == 1));
			list.swap(1, -1);
			Assert::IsTrue((list.at(0) == 0) && (list.at(1) == 3) && (list.at(2) == 2) && (list.at(3) == 1));
			list.swap(-1, -1);
			Assert::IsTrue((list.at(0) == 0) && (list.at(1) == 3) && (list.at(2) == 2) && (list.at(3) == 1));
			list.swap(100, 100);
			Assert::IsTrue((list.at(0) == 0) && (list.at(1) == 3) && (list.at(2) == 2) && (list.at(3) == 1));
			list.clear();
			list.swap(1, 3);
			Assert::IsTrue(list.isEmpty());
		}
	};
}
