#include "CSLL.h"
#include<iostream>
using namespace std;

template<typename T>
CSLL<T>::CSLL()
{
	head = tail = nullptr;
}
template<typename T>
void CSLL<T>::insertAtHead(T h)
{
	if (!head)
	{
		head = tail = new Node<T>(h);
		head->next = head;
		return;
	}
	Node<T>* temp = new Node<T>(h);
	temp->next = head;
	head = temp;
	if (tail)
		tail->next = head;
	else
		tail = head;
}

template<typename T>
CSLL<T>::CSLL(const CSLL<T>& ref)
{
	if (!ref.head)
	{
		head = tail = nullptr;
		return;
	}
	Node<T>* refPtr = ref.head;
	Node<T>* objPtr = new Node<T>(refPtr->info);
	head = objPtr;
	while (refPtr->next != ref.head)
	{
		refPtr = refPtr->next;
		objPtr->next = new Node<T>(refPtr->info);
		objPtr = objPtr->next;
	}
	objPtr->next = head;
	tail = objPtr;
}

template<typename T>
CSLL<T>& CSLL<T>::operator=(const CSLL<T>& ref)
{
	if (&ref == this)
		return *this;
	this->~CSLL<T>();
	if (!ref.head)
		return *this;
	Node<T>* refPtr = ref.head;
	Node<T>* objPtr = new Node<T>(refPtr->info);
	head = objPtr;
	while (refPtr->next != ref.head)
	{
		refPtr = refPtr->next;
		objPtr->next = new Node<T>(refPtr->info);
		objPtr = objPtr->next;
	}
	objPtr->next = head;
	tail = objPtr;
	return *this;
}
template <typename T>
CSLL<T>::~CSLL()
{
	if (!head)
		return;
	Node<T>* temp = head;
	Node<T>* traverse;
	do
	{
		traverse = temp->next;
		delete temp;
		temp = traverse;
	}while (temp != head);
	head = tail = nullptr;
}
template <typename T>
void CSLL<T>::insertAtTail(T t)
{
	if (!head)
	{
		insertAtHead(t);
		return;
	}
	tail->next = new Node<T>(t);
	tail = tail->next;
	tail->next = head;
}
template<typename T>
void CSLL<T>::removeAtHead()
{
	if (!head)
		return;
	if (head == tail)
	{
		delete head;
		head = tail = nullptr;
		return;
	}
	Node<T>* temp = head->next;
	delete head;
	head = temp;
	tail->next = head;
}
template<typename T>
void CSLL<T>::removeAtTail()
{
	if (!head)
		return;
	if(head == tail)
	{
		delete head;
		head = tail = nullptr;
		return;
	}
	Node<T>* traverse = head;
	while (traverse->next->next != head)
		traverse = traverse->next;
	delete traverse->next;
	traverse->next = head;
	tail = traverse;
}
template<typename T>
void CSLL<T>:: remove(T obj)
{
	if (!head)
		return;
	if (head->info == obj)
	{
		removeAtHead();
		return;
	}
	Node<T>* traverse = head->next;
	Node<T>* prev = head;
	while (traverse)
	{
		if (traverse->info == obj)
		{
			prev->next = traverse->next;
			delete traverse;
			if (traverse == tail)
				tail = prev;
			return;
		}
		prev = traverse;
		traverse = traverse->next;
	}
}
template<typename T>
void CSLL<T> :: insertAfter(T key, T val)
{
	if (!head)
		return;
	Node<T>* traverse = head;
	do
	{
		if (traverse->info == key)
		{
			Node<T>* temp = new Node<T>(val);
			temp->next = traverse->next;
			traverse->next = temp;
			if (traverse == tail)
				tail = temp;
			return;
		}
		traverse = traverse->next;
	}while (traverse != head);
}
template<typename T>
void CSLL<T> ::insertBefore(T key, T val)
{
	if (!head)
		return;
	if (head->info == key)
	{
		insertAtHead(val);
		return;
	}
	Node<T>* traverse = head->next;
	Node<T>* prev = head;
	while (traverse != head)
	{
		if (traverse->info == key)
		{
			Node<T>* temp = new Node<T>(val);
			temp->next = traverse;
			prev->next = temp;
			return;
		}
		prev = traverse;
		traverse = traverse->next;
	}
}
template<typename T>
void CSLL<T> :: removeAfter(T key)
{
	if (!head || (head == tail))
		return;
	if (tail->info == key)
	{
		removeAtHead();
		return;
	}
	Node<T>* traverse = head;
	do
	{
		if (traverse->info == key)
		{
			Node<T>* temp = traverse->next->next;
			delete traverse->next;
			if (traverse->next == tail)
				tail = traverse;
			traverse->next = temp;
			return;
		}
		traverse = traverse->next;
	} while (traverse != tail);
}
template<typename T>
void CSLL<T> :: removeBefore(T key)
{
	if (!head)
		return;
	if (head->info == key)
	{
		removeAtTail();
		return;
	}
	if (head != tail)
	{
		if (head->next->info == key)
		{
			removeAtHead();
			return;
		}
	}
	else
		return;
	Node<T>* traverse = head->next->next;
	Node<T>* prevOfPrev = head;
	while (traverse != head)
	{
		if (traverse->info == key)
		{
			delete prevOfPrev->next;
			prevOfPrev->next = traverse;
			return;
		}
		prevOfPrev = prevOfPrev->next;
		traverse = traverse->next;
	}
}
template<typename T>
void CSLL<T> ::display()
{
	if (!head)
		return;
	Node<T>* temp = head;
	do
	{
		cout << temp->info << " ";
		temp = temp->next;
	} while (temp != head);
	cout << '\n';
}
