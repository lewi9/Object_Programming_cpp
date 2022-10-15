#pragma once
#include <iostream>

#include "FQueue.h"

int main()
{
	FQueue q;
	FQINFO* a = new FQINFO( 1, 1, 1 );
	FQINFO* b = new FQINFO( 2, 4 );
	FQINFO* c = new FQINFO( 3 );
	
	try
	{
		q.FQEnqueue( a );
		q.FQEnqueue( b );
		q.FQEnqueue( c );
		q.FQPrintQueue();
		FQINFO* t = q.FQDequeue();
		std::cout << *(t);
		delete t;
		q.FQClear();
		t = q.FQDequeue();
		delete t;
	}
	catch( FQueueException err )
	{
		std::cerr << err.getReason() << std::endl;
	}
	return 0;
}