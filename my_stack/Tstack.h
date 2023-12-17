#pragma once
#include <iostream>
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
	TStack( int _max_size=10)
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
		if (CurrInd >= max_size-1)
		{
			throw("Stack Overflow");
		}
		pMem[CurrInd+1] = elem;
		CurrInd++;
	}
	T Pop()
	{
		if ( this->Empty()==true)
		{
			throw("Stack is empty");
		}
		CurrInd--;
		return pMem[CurrInd+1];
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
		std::cout <<")"<<std::endl;
	}

};

