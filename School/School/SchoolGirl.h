#pragma once
#include "Pupil.h"
class SchoolGirl:
    public Pupil
{
public:
    SchoolGirl( std::string sName = "Anna", std::string sLastName = "Nowak", int nAge = 13, std::string strClass = "1b");
    SchoolGirl( const SchoolGirl& sg );

    virtual void clothes() const;
};

