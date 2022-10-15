#include "OfficeWorker.h"

OfficeWorker::OfficeWorker( std::string sName, std::string sLastName, int nAge, double nSalary )
	:SchoolWorker(sName, sLastName, nAge, nSalary)
{
}
double OfficeWorker::calculateNetto() const{
	double t;
	( t = WOLNA + UZYSK - getSalary() ) < 0 ? t *= PODATEK : 0;
	return getSalary() + t;
}