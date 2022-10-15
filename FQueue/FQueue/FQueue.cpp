#pragma once
#include "FQueue.h"

void FQueue::FQEnqueue( FQINFO* pInfo )
{
    FQItem* p = new( std::nothrow ) FQItem( pInfo );
    if( !p )
        throw FQueueException( FQUEUE_OVERFLOW );
    ( this->FQEmpty() ) ? this->m_pHead = p : this->m_pTail->m_pNext = p;
    this->m_pTail = p;
}

FQINFO* FQueue::FQDequeue()
{
    if( this->FQEmpty() )
        throw FQueueException( FQUEUE_UNDERFLOW );
    FQINFO* pInfo = this->m_pHead->m_pInfo;
    this->FQDel();
    return pInfo;
}

void FQueue::FQClear()
{
    while( !( this->FQEmpty() ) )
        delete this->FQDequeue();
}

void FQueue::FQPrintQueue()
{
    if( this->FQEmpty() )
        throw FQueueException( FQUEUE_UNDERFLOW );
    FQItem* p = this->m_pHead;
    while( p != this->m_pTail )
    {
        std::cout << *(p->m_pInfo);
        p = p->m_pNext;
    }
    std::cout << *(p->m_pInfo);
}

//

void FQueue::FQDel()
{
    FQItem* p = this->m_pHead;
    this->m_pHead = p->m_pNext;
    if( this->FQEmpty() ) this->m_pTail = NULL;
    delete p;
}