#pragma once

template <class T>
class LLNode
{
public:
	//ref al siguiente nodo de la lista
	LLNode<T> *next;

	//dato contenido
	T* data;

	//dos constructores 
	//recordar el polymorfismo de OOP
	LLNode(T* _data) :data(_data), next(nullptr){}
	LLNode(T* d, LLNode<T>* nxt) : data(d), next(nxt) {}
};

