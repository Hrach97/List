#include <iostream>
#include "List.h"

int main() {
        List<int> * list = new List<int>();
        list->insertion(14);
        list->insertion(25);
        list->insertion(36);
        list->insertion(48);
	list->insert_at(4, 1000);
//	list->deletion(5);
//       	std::cout << list->search(36);
	list->print();
      	delete list;
}

