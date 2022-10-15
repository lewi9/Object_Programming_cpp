#pragma once
#include "SchoolWorker.h"

class Teacher:
    public SchoolWorker
{
public:
    Teacher( std::string sName = "Anna", std::string sLastName = "Nowak", int nAge = 25, double nSalary = 4000,
             int nSeniority = 0, bool isTutor = 0, std::string strClass = NULL,
             std::string strSubject = "Polski");
    //Teacher( const Teacher& t );

    Teacher& operator = ( const Teacher& t );

    virtual double calculateNetto() const;

    inline int getSeniority() const;
    inline bool isTutor() const;
    inline std::string getClass() const;
    inline std::string getSubject() const;

    inline void setSeniority( int nSeniority );
    inline void setTutor( bool tutoring );
    inline void setClass( std::string strClass );
    inline void setSubject( std::string strSubject );

private: 
    int m_nSeniority;
    bool m_isTutor;
    std::string m_strClass;
    std::string m_strSubject;
};

inline int Teacher::getSeniority() const
{
    return this->m_nSeniority;
}
inline bool Teacher::isTutor() const
{
    return this->m_isTutor;
}
inline std::string Teacher::getClass() const
{
    return this->m_strClass;
}
inline std::string Teacher::getSubject() const
{
    return this->m_strSubject;
}

inline void Teacher::setSeniority( int nSeniority )
{
    this->m_nSeniority = nSeniority;
}
inline void Teacher::setTutor( bool tutoring )
{
    this->m_isTutor = tutoring;
}
inline void Teacher::setClass( std::string strClass )
{
    if( isTutor() )
        this->m_strClass = strClass;
    else
        std::cout << getName() << " " << getLastName() << " isn't tutor\n";
}
inline void Teacher::setSubject( std::string strSubject )
{
    this->m_strSubject = strSubject;
}