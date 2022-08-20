#include<iostream>
using namespace std;
#include "CSLL.h"

int main()
{
	CSLL<int> l1;
	l1.insertAtHead(14);
	l1.display();
	l1.insertAfter(14, 10);
	l1.display();
	l1.insertAtTail(13);
	l1.display();
	l1.insertBefore(14, 12);
	l1.display();
	cout << "Critical Point: " << "\n";
	l1.insertBefore(14, 17);
	l1.display();
	l1.insertAfter(13, 11);
	l1.display();
	l1.insertAfter(13, 9);
	l1.display();
	CSLL<int>a(l1);
	a.display();
	l1.removeAfter(13);
	l1.display();
	l1.removeAtHead();
	l1.display();

	l1.removeBefore(14);
	l1.display();


	l1.removeAfter(10);
	l1.display();
	l1.removeAfter(14);
	l1.display();
	l1.removeAfter(11);
	l1.display();
	l1.removeAtTail();
	l1.display();
	l1.removeAtTail();
	l1.display();
	l1.removeAtTail();
	l1.display();
	l1.removeAtTail();
	l1.display();
	l1.removeAtTail();
	l1.display();
	cout << "separate: \n";
	l1.removeAtTail();
	l1.display();

	
	return 0;
}