// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>



template <typename T>
class MyList {

private:
	template <typename T>
	class Node {
	public:
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr)
		{
			this->pNext = pNext;
			this->data = data;
		}

		~Node() {}
	};
public:
	MyList() { size = 0; pHead = nullptr; }

	bool IsEmpty() const { return pHead == nullptr; }

	void Pop()
	{ 
		if (this->IsEmpty())
		{
			return;
		}

		Node<T>* tmp = pHead;
		Node<T>* pp = pHead;
		while (tmp->pNext != nullptr)
		{
			pp = tmp;
			tmp = tmp->pNext;
		}
		pp->pNext = nullptr;
		delete tmp;

		size--;
	}

	void Push(T t)
	{
		size++;
		if (this->IsEmpty())
		{
			pHead = new Node<T>(t);
			return;
		}

		Node<T>* tmp = pHead;
		Node<T> *p = new Node<T>();
		p->data = t;
		while (tmp->pNext != nullptr)
		{
			tmp = tmp->pNext;
		}
		tmp->pNext = p;
		p->pNext = nullptr;
		
	}

	~MyList() 
	{
		while (pHead->pNext != nullptr)
		{
			Node<T>* tmp = pHead;
			pHead = pHead->pNext;
			delete tmp;
		}
		delete pHead;
		size = 0;
	}

private:
	Node<T>* pHead;
	int size;
	};

int main()
{
	int a = 1, b = 3;
	MyList<int> list;
	list.Push(a);
	list.Push(b);
	list.Push(5);
	list.Pop();

}

