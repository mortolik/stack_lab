#pragma once
#include <iostream>

namespace ArrayStack
{
	template <class T>
	class TStack
	{
		T* pMem;
		int max_size;
		int CurrInd;
	public:
		TStack& operator = (const TStack& s)
		{
			if (*this == s)
			{
				return *this;
			}
			delete[] pMem;
			CurrInd = s.CurrInd;
			max_size = s.max_size;
			pMem = new T[s.max_size];
			std::copy(s.pMem, s.pMem + CurrInd, pMem);
			return *this;

		}
		~TStack()
		{
			delete[] pMem;
		}
		TStack(int _max_size = 10)
		{
			if (_max_size < 1)
			{
				throw "bad size";
			}
			max_size = _max_size;
			pMem = new T[max_size];
			CurrInd = -1;
		}
		TStack(const TStack& s)
		{
			max_size = s.max_size;
			CurrInd = s.CurrInd;
			delete[]pMem;
			pMem = new T[max_size];

			for (int i = 0; i <= CurrInd; i++)
			{
				pMem[i] = s.pMem[i];
			}
		}
		bool Empty()
		{
			return CurrInd == -1;
		}
		bool Full()
		{
			return CurrInd == max_size - 1;
		}
		void Push(T elem)
		{
			if (CurrInd >= max_size - 1)
			{
				throw("Stack Overflow");
			}
			pMem[CurrInd + 1] = elem;
			CurrInd++;
		}
		T Pop()
		{
			if (this->Empty() == true)
			{
				throw("Stack is empty");
			}
			CurrInd--;
			return pMem[CurrInd + 1];
		}
		int get_CurrInd()
		{
			return CurrInd;
		}
		T IndEl()
		{
			if (CurrInd == -1)
				throw ("Stack is empty");
			return pMem[CurrInd];
		}
		void Clear()
		{
			while (!this->Empty())
			{
				this->Pop();
			}
		}
		void Output()
		{
			if (CurrInd == -1)
			{
				std::cout << "stack is empty" << std::endl;
			}
			std::cout << '(';
			for (int i = 0; i <= CurrInd; i++)
			{
				std::cout << pMem[i] << "";

			}
			std::cout << ")" << std::endl;
		}

	};

};

namespace ListStack
{
	using namespace std;
	template <class T>
	struct TNode
	{
		T val;
		TNode <T>* pNext;
	};
	template<class T>
	class TStack
	{
		TNode<T>* pFirst;
	public:
		TStack() { pFirst = NULL; }
		TStack(const TStack<T>& a);
		TStack& operator=(const TStack& a);
		void Clear();
		bool IsEmpty() { return pFirst == NULL; }
		void Push(T a);
		T Top();
		T Pop();
		~TStack();
		bool IsFull();
		int GetNum();
	};
	template<class T>
	TStack<T>::TStack(const TStack<T>& a)
	{
		TNode<T>* tmp = new TNode<T>;
		tmp = a.pFirst;
		while (tmp != 0)
		{
			pFirst = tmp;
			tmp = tmp->pNext;
		}

	}
	template<class T>
	TStack<T>& TStack<T>:: operator=(const TStack& a)
	{
		TNode<T>* tmp = new TNode<T>;
		tmp = a.pFirst;
		while (tmp != 0)
		{
			pFirst = tmp;
			tmp = tmp->pNext;
		}
		return *this;
	}
	template<class T>
	void TStack<T>::Clear()
	{
		TNode <T>* tmp = pFirst;
		while (pFirst != NULL)
		{
			pFirst = pFirst->pNext;
			delete tmp;
			tmp = pFirst;
		}
	}
	template<class T>
	void TStack<T>::Push(T a)
	{
		TNode <T>* TMP;
		TMP = new TNode<T>;
		TMP->pNext = pFirst;
		TMP->val = a;
		pFirst = TMP;
	}
	template<class T>
	T TStack<T>::Top()
	{
		if (IsEmpty())throw - 1;
		return pFirst->val;
	}
	template<class T>
	T TStack<T>::Pop()
	{
		if (IsEmpty())throw - 1;
		T res = pFirst->val;
		TNode<T>* tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
		return res;
	}
	template<class T>
	TStack<T>::~TStack()
	{
		TNode <T>* tmp = pFirst;
		while (pFirst != NULL)
		{
			pFirst = pFirst->pNext;
			delete tmp;
			tmp = pFirst;
		}
	}
	template<class T>
	bool TStack<T>::IsFull()
	{
		TNode<T>* p = new TNode<T>;
		if (p)
		{
			delete p;
			return true;
		}
		else
		{
			return false;
		}
	}
	template<class T>
	int TStack<T>::GetNum()
	{
		TNode<T>* p = pFirst;
		int i = 0;
		while (p != NULL)
		{
			i++;
			p = (*p).pNext;
		}
		return i;
	}
};

