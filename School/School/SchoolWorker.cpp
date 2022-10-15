#include "SchoolWorker.h"

SchoolWorker::SchoolWorker( std::string sName, std::string sLastName, int nAge, double nSalary )
	: Person(sName, sLastName, nAge)
{
	setSalary( nSalary );
}
SchoolWorker::SchoolWorker( const SchoolWorker& sw )
{
	*this = sw;
}

SchoolWorker& SchoolWorker::operator = ( const SchoolWorker& sw )
{
	setPerson( sw.getName(), sw.getLastName(), sw.getAge() );
	setSalary( sw.getSalary() );
	return *this;
}