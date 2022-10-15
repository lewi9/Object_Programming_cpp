#pragma once
#include "Pupil.h"
class SchoolBoy:
    public Pupil
{
public:
    SchoolBoy( std::string sName = "Adam", std::string sLastName = "Nowak", int nAge = 13, std::string strClass = "1a");
    SchoolBoy( const SchoolBoy& sb );

    virtual void clothes() const;

};

