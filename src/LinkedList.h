#pragma once
#include <iostream>
#include "LLNode.h"

template <class T>
class LinkedList
{

protected:
	LLNode<T> *head;


public:
	//lista vacia
	LinkedList() :head(nullptr){}
	LinkedList(LLNode<T> *_hd) : head(_hd) {};

	//imprimir el contenido 
	//void PrintElements();

	//agrega elemento al final de la lista ligada
	LLNode<T>* AddNode(T* _data)
	{
		//si la lista esta vacia
		if (head == nullptr)
		{
			head = new LLNode<T>(_data);
			return head;
		}
		//si no, iterar hasta el final
		LLNode<T>* iter = head;
		while (iter->next != nullptr)
			iter = iter->next;
		iter->next = new LLNode<T>(_data);

		return iter->next;
	}

	//remover el ultimo nodo
	void RemoveLastNode()
	{
		if (head == nullptr)
			return;
		//si solo hay un nodo
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			return;
		}
		//iterar hasta el penultimo
		LLNode<T>* iter = head;
		while (iter->next->next != nullptr)
			iter = iter->next;
		delete iter->next;
		iter->next = nullptr;
	}


};

