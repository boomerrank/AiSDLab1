#include <iostream>
#include "DuoLinkedList.h"
using namespace std;

int main() {
	cout << "start\n";
	DouLinkedList list;
	for (int i = 1; i <= 10; i++) {
		list.push_back(i);
	}
	list.remove(5);
	list.set(2, 99);
	list.swap(0, 6);
	list.insert(999, 5);
	list.pop_back();
	list.pop_front();
	list.push_front(0);
	cout << list << " Size: " << list.get_size() << '\n';
	cout << "Index 3: " << list.at(3) << ' ' << list.isEmpty() << '\n';
	list.clear();
	cout << '.' << list << '.' << list.isEmpty() << ' ' << list.get_size() << '\n';
}