#include "Teacher.h"

Teacher::Teacher( std::string sName, std::string sLastName, int nAge, double nSalary,
         int nSeniority, bool isTutor, std::string strClass, std::string strSubject ) 
    : SchoolWorker(sName, sLastName, nAge, nSalary)
{
    setSeniority( nSeniority );
    setTutor( isTutor );
    setClass( strClass );
    setSubject( strSubject );
}
/*Teacher::Teacher(const Teacher& t)
{
    *this = t;
}*/

Teacher& Teacher::operator = ( const Teacher& t )
{
    setPerson( t.getName(), t.getLastName(), t.getAge() );
    setSalary( t.getSalary() );
    setSeniority( t.getSeniority() );
    setTutor( t.isTutor() );
    setClass( t.getClass() );
    setSubject( t.getSubject() );
    return *this;
}

double Teacher::calculateNetto() const
{
    int nSeniority = getSeniority();
    if( nSeniority < 5 )
        nSeniority = 0;
    else if( nSeniority > 20 )
        nSeniority = 20;
    double biggerSalary = getSalary() * ( 1 + nSeniority / 100. );
    double t;
    ( t = WOLNA + UZYSK - biggerSalary ) < 0 ? t *= PODATEK : 0;
    return biggerSalary + t;
}