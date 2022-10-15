/*
#include "stack.h"

Stack::~Stack()
{
	while( !isEmpty() )
		del();		
}

void Stack::push( int key )
{
	StackItem* p = new( std::nothrow ) StackItem( key, this->m_pHead );
	if( !p )
       throw StackException( STACK_OVERFLOW );
	this->m_pHead = p;
}

int Stack::pop()
{
	if( !isEmpty() )
	{
		int t = top();
		del();
		return t;
	}
	throw StackException( STACK_UNDERFLOW );
}

int Stack::top()
{
	if( !isEmpty() )
		return this->m_pHead->m_nKey;
	throw StackException( STACK_UNDERFLOW );
}

void Stack::del()
{
	if( isEmpty() )
		throw StackException( STACK_UNDERFLOW );
	StackItem * p = this->m_pHead;
	this->m_pHead = p->m_pNext;
	delete p;
}
*/