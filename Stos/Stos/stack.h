#pragma once

#include <iostream>

#define STACK_UNDERFLOW 0x01
#define STACK_OVERFLOW	0x02
#define OTHER_ERROR		0x04
//==================================================================
class StackException
{
public:
	inline StackException( int ErrCode = OTHER_ERROR );
	inline const char* getReason();

private:
	int m_ErrCode;
};

inline StackException::StackException( int ErrCode )
{
	this->m_ErrCode = ErrCode;
}

inline const char* StackException::getReason()
{
	switch( this->m_ErrCode )
	{
	case STACK_UNDERFLOW:	return "ERROR: Stack is Underflow!";
	case STACK_OVERFLOW:	return "ERROR: Stack is Overflow!!";
	default:				return "There is another Error, not listed!!!!";
	}
}
//================================================================== 
template<class T>
class Stack;//ZapowiedŸ klasy

template<class T>
class StackItem
{
private:
	friend class Stack<T>;

private:
	inline	StackItem( T nKey, StackItem<T>* pNext = NULL);//nullptr
	virtual ~StackItem(){}

private:
	T m_nKey;
	StackItem<T>* m_pNext;
};

template<class T>
inline  StackItem<T>::StackItem( T nKey, StackItem<T>* pNext )
{
	this->m_nKey = nKey;
	this->m_pNext = pNext;
}
//==================================================================
template<class T>
class Stack
{
public:
	inline	Stack();
	virtual ~Stack();

	void push( T key ); 
	T pop();
	T top();
	void del();
	inline int isEmpty();//Tu nie ma potrzeby deklarowaæ inline
						 //Jednak kod siê samokomentuje - wiem te¿ 
						 //gdzie szukaæ cia³a funkcji
private:
	StackItem<T>* m_pHead;
};

template<class T>
inline Stack<T>::Stack()
{
	this->m_pHead = NULL;
}

template<class T>
Stack<T>::~Stack()
{
	while( !isEmpty() )
		del();
}

template<class T>
void Stack<T>::push( T key )
{
	StackItem<T>* p = new( std::nothrow ) StackItem<T>( key, this->m_pHead );
	if( !p )
		throw StackException( STACK_OVERFLOW );
	this->m_pHead = p;
}

template<class T>
T Stack<T>::pop()
{
	if( !isEmpty() )
	{
		T t = top();
		del();
		return t;
	}
	throw StackException( STACK_UNDERFLOW );
}

template<class T>
T Stack<T>::top()
{
	if( !isEmpty() )
		return this->m_pHead->m_nKey;
	throw StackException( STACK_UNDERFLOW );
}

template<class T>
void Stack<T>::del()
{
	if( isEmpty() )
		throw StackException( STACK_UNDERFLOW );
	StackItem<T>* p = this->m_pHead;
	this->m_pHead = p->m_pNext;
	delete p;
}

template<class T>
inline int Stack<T>::isEmpty()
{
	return !( this->m_pHead );
}
