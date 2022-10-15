#pragma once
#include "Person.h"

#define UZYSK 250
#define PODATEK 0.17
#define WOLNA 30000/12.


class SchoolWorker:
    public Person
{
public:
    SchoolWorker( std::string sName = "Name", std::string sLastName = "Nowak", int nAge = 25, double nSalary = 4000);
    SchoolWorker( const SchoolWorker& sw );

    SchoolWorker& operator = ( const SchoolWorker& sw );

    inline void setSalary( double nSalary );
    inline double getSalary() const;

    virtual double calculateNetto() const = 0;

private:
    double m_nSalary;
};

inline void SchoolWorker::setSalary( double nSalary )
{
    this->m_nSalary = nSalary;
}
inline double SchoolWorker::getSalary() const
{
    return this->m_nSalary;
}
