#pragma once
#include "SchoolWorker.h"
class OfficeWorker:
    public SchoolWorker
{
public:
    OfficeWorker( std::string sName = "Name", std::string sLastName = "Nowak", int nAge = 25, double nSalary = 3000);
    virtual double calculateNetto() const;
};

