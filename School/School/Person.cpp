#include "Person.h"


Person::Person( std::string strName, std::string strLastName, int nAge )
{
	setPerson( strName, strLastName, nAge );
}

Person::Person( const Person& p )
{
	*this = p;
}

Person& Person::operator = ( const Person& p )
{
	setPerson( p.getName(), p.getLastName(), p.getAge() );
	return *this;
}