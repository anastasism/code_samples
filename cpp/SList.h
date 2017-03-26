#include "stdafx.h"
#include <iostream>
using namespace std;
template <class T>class List {
private:
	struct SingleNode {

		T value;
		SingleNode *next;
		SingleNode(T a){ value = a; }
		SingleNode(){}

	};
	SingleNode *head;
	SingleNode *tail;
	SingleNode* Sort(SingleNode*first, SingleNode*last);
	SingleNode* Merge(SingleNode*first, SingleNode*mid, SingleNode*last);
public:
	class Iterator
	{
	private:
		SingleNode *current;
	public:
		Iterator(SingleNode*cur) : current(cur){};
		T& operator *();
		Iterator& operator ++();
		Iterator operator ++(int);
		Iterator operator +(int);
		const int operator -(const Iterator&);
		const bool operator ==(const Iterator&);
		const bool operator !=(const Iterator&);
	};

	Iterator begin();
	Iterator end();
	List();
	List(T value);
	List(const List<T> &list);
	void Add(T value);
	bool isEmpty() const;
	bool Find(T);
	int Size();
	void Show();
	T& GetValueByIndex(int index);
	T RemoveFirst1();
	void Sort();
	~List();
	T&Top();
	List<T>& operator=(const List<T>&);
};
template <class T>
typename List<T>::SingleNode* List<T>::Sort(SingleNode*first, SingleNode*last)
{
	int lng = 0;
	SingleNode*tmp = first;
	while (tmp != last)
	{
		lng++;
		tmp = tmp->next;
	}
	SingleNode*oldmid = first;
	for (int i = 0; i<(lng / 2) - 1; i++, oldmid = oldmid->next);
	SingleNode*mid = oldmid->next;
	oldmid->next = last;
	if (lng > 1)
	{
		return Merge(Sort(first, last), Sort(mid, last), last);
	}
	return first;
}
template <class T>
typename List<T>::SingleNode* List<T>::Merge(SingleNode*first, SingleNode*mid, SingleNode*last)
{
	SingleNode*newhead;
	SingleNode*q;
	if (first->value < mid->value)
	{
		q = first;
		first = first->next;
	}
	else
	{
		q = mid;
		mid = mid->next;
	}
	newhead = q;
	while (first != last && mid != last)
	{
		if (first->value < mid->value)
		{
			q->next = first;
			first = first->next;
		}
		else
		{
			q->next = mid;
			mid = mid->next;
		}
		q = q->next;
	}
	q->next = first == last ? mid : first;
/*	if (first == last)
	{
		q->next = mid;
	}
	if (mid == last)
	{
		q->next = first;
	}*/
	return newhead;
}
template <class T>
void List<T>::Sort()
{
	head = Sort(head, tail);
}
////////////////////класс итератор//////////////////////////////
template <class T>
T& List<T>::Iterator::operator *()
{
	return current->value;
}
template <class T>
typename List<T>::Iterator List<T>::Iterator::operator ++(int)
{
	Iterator z = *this;
	current = current->next;
	return z;
}
template <class T>
typename List<T>::Iterator& List<T>::Iterator::operator ++()
{
	current = current->next;
	return *this;
}
template <class T>
typename List<T>::Iterator List<T>::Iterator::operator +(int n)//функция исправлена
{
	SingleNode* tmp = current;
	for (int i = 0; i < n; i++)
	{
		tmp = tmp->next;
	}
	return tmp;
}
template <class T>
const int List<T>::Iterator::operator -(const Iterator& q)//функция исправлена
{
	SingleNode* a = q.current;
	int result = 0;
	while (a != current)
	{
		result++;
		a = a->next;
	}
	return result;
}
template <class T>
const bool List<T>::Iterator::operator ==(const Iterator& q)
{
	return (current == q.current);
}
template <class T>
const bool List<T>::Iterator::operator !=(const Iterator& q)
{
	return !(*this == q);
}
template <class T>
typename List<T>::Iterator List<T>::begin()
{
	return Iterator(head);
}
template <class T>
typename List<T>::Iterator List<T>::end()
{
	Iterator i(tail);
	return i;
}
////////////////////////////////////////////////////////////////////////////////////////////
void error(bool check);
template <class T>
List<T>::List()
{
	head = tail = new SingleNode;
}

template <class T>
List<T>::List(T value)
{
	tail = new SingleNode;
	head = new SingleNode(value);
	head->next = tail;
}

template <class T>
List<T>::List(const List<T>& list)
{
	//head = tail = new SingleNode;
	////head->next = tail;
	//SingleNode* temp = list.head;
	//while (temp != tail)
	//{
	//	//SingleNode *tmp = new SingleNode(temp->value);
	//	tail->value = temp->value;
	//	tail->next = new SingleNode();
	//	temp = temp->next;
	//}
	head = tail = new SingleNode();
	SingleNode *temp = list.head;
	while (temp != list.tail){
		SingleNode *t = new SingleNode;
		tail->value = temp->value;
		tail->next = t;
		tail = t;
		temp = temp->next;
	}
}

template <class T>void List<T>::Add(T value)
{
	SingleNode *tmp = new SingleNode(value);
	tmp->next = head;
	head = tmp;
}

template <class T>bool List<T>::isEmpty() const
{
	return head == tail;
}

template <class T>bool List<T>::Find(T value)
{
	for (SingleNode *a = head; a != tail; a = a->next)
	if (a->value == value)
		return true;
	return false;
}
template <class T>int List<T>::Size()
{
	SingleNode *m = head;
	int count = 0;
	while (m != tail)
	{
		m = m->next;
		count++;
	}
	return count;
}
template <class T>void List<T>::Show()
{
	SingleNode *m = head;
	while (m != tail)
	{
		cout << m->value << " ";
		m = m->next;
	}
	cout << endl;
}
template <class T>T& List<T>::GetValueByIndex(int index)
{
	SingleNode *m = head;
	for (int i = 0; i < index; i++)
	{
		m = m->next;
	}
	return m->value;
}
template <class T>T List<T>::RemoveFirst1()
{
	T val = head->value;
	SingleNode *m = head->next;
	delete head;
	head = m;
	return val;
}

template <class T>List<T>::~List()
{
	SingleNode *tmp = head;
	while (head != tail)
	{
		tmp = tmp->next;
		delete head;
		head = tmp;
	}
	delete tail;
}

template <class T>void Print_slist(List <T>&d){
	int n = d.Size();
	for (int i = 0; i < n; i++)
	{
		cout << d.GetValueByIndex(i) << " ";
	}
	cout << endl;
}

template <class T>T&List<T>::Top()
{
	return head->value;
}
template <class T>List<T>& List<T>::operator=(const List<T>& l)
{
	SingleNode* tmp = head;
	while (head != tail)
	{
		head = head->next;
		delete tmp;
		tmp = head;
	}
	if (!l.isEmpty())
	{

		head = new SingleNode(l.head->value);
		head->next = tail;
		SingleNode* temp = l.head->next;
		tmp = head;
		while (temp != l.tail)
		{
			SingleNode* t = new SingleNode(temp->value);
			tmp->next = t;
			t->next = tail;
			tmp = tmp->next;
			temp = temp->next;
		}
	}
	return *this;
}
void error(bool check)
{
	if (!check)
		cerr << "ERROR!" << endl;
}
