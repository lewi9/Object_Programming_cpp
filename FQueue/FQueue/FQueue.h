#pragma once

#include <iostream>
#include "Global.h"

#define FQUEUE_UNDERFLOW	0x01
#define FQUEUE_OVERFLOW		0x02
#define OTHER_ERROR			0x04
//==================================================================
class FQueueException
{
public:
	inline FQueueException( int ErrCode = OTHER_ERROR );
	inline const char* getReason();

private:
	int m_ErrCode;
};

inline FQueueException::FQueueException( int ErrCode )
{
	this->m_ErrCode = ErrCode;
}

inline const char* FQueueException::getReason()
{
	switch( this->m_ErrCode )
	{
	case FQUEUE_UNDERFLOW:	return "ERROR: FQUEUE is Underflow!";
	case FQUEUE_OVERFLOW:	return "ERROR: FQUEUE is Overflow!!";
	default:				return "There is another Error, not listed!!!!";
	}
}
//==================================================================
class FQueue;

class FQItem
{
private:
	friend class FQueue;
	inline FQItem( FQINFO* pInfo = NULL );
	virtual ~FQItem();
	FQINFO* m_pInfo;
	FQItem* m_pNext;
};

inline FQItem::FQItem( FQINFO* pInfo )
{
	this->m_pInfo = pInfo;
	this->m_pNext = NULL;
}

inline FQItem::~FQItem()
{
	delete m_pInfo;
}

class FQueue
{
public:
	inline FQueue();
	inline ~FQueue();
	inline bool FQEmpty();
	void FQEnqueue( FQINFO* pInfo );
	FQINFO* FQDequeue();
	void FQClear();
	void FQPrintQueue();
private:
	void FQDel();
	FQItem* m_pHead;
	FQItem* m_pTail;
};

inline FQueue::FQueue()
{
	this->m_pHead = NULL;
	this->m_pTail = NULL;
}

inline FQueue::~FQueue()
{
	FQClear();
}

inline bool FQueue::FQEmpty()
{
	return !( this->m_pHead );
}