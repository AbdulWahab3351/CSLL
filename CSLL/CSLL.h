#ifndef LSLL_H
#define LSLL_H
#include"Node.h"

template<typename T>
class CSLL
{
	Node<T>* head;
	Node<T>* tail;
public:
	CSLL();
	void insertAtHead(T h);
	void insertAtTail(T t);
	void insertAfter(T key, T val);
	void insertBefore(T key, T val);
	void removeAtHead();
	void removeAtTail();
	void removeAfter(T key);
	void removeBefore(T key);
	void remove(T obj);
	~CSLL();
	CSLL(const CSLL<T>& ref);
	CSLL<T>& operator=(const CSLL<T>& ref);
	void display();
};

#endif // !LSLL_H


