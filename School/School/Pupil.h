#pragma once
#include "Person.h"

#define MARKS 7

enum m_subject {
    POLSKI = 0, MATEMATYKA = 1, FIZYKA = 2, CHEMIA = 3,
    INFORMATYKA = 4, ANGIELSKI = 5, NIEMIECKI = 6
};

class Pupil:
    public Person
{
public:
    Pupil( std::string sName = "Name", std::string sLastName = "Nowak", int nAge = 13, std::string strClass = "1a");
    Pupil( const Pupil& pupil );
    
    Pupil& operator = ( const Pupil& pupil );

public:
    inline void addMark( double dMark, m_subject subject );
    inline void setID( std::string strID);
    inline void setClass( std::string strClass );

    inline double getMark( m_subject subject ) const;
    inline std::string getID() const;
    inline std::string getClass() const;

public:
    double avgMark() const;
    void clearMarks();

    //!!
    virtual void clothes() const = 0;

    friend std::ostream& operator << ( std::ostream& out, const Pupil& pupil );

protected:
    std::string m_strID;

private:
    std::string m_strClass;
    double m_dMarks[MARKS];
};


inline void Pupil::addMark( double dMark, m_subject subject )
{
    if( dMark == 2.0 || dMark == 3.0 || dMark == 3.5 || dMark == 4.0
        || dMark == 4.5 || dMark == 5.0|| dMark == 0 )
        this->m_dMarks[subject] = dMark;
    else
        std::cout << "Usage: range of marks 2:5, you can use also 2.5, 3.5, 4.5\n";
}
inline void Pupil::setID( std::string strID )
{
    if( strID.length() <= 4 )
        strID = '0' + strID;
    this->m_strID = strID;
}
inline void Pupil::setClass( std::string strClass )
{
    this->m_strClass = strClass;
}

inline double Pupil::getMark( m_subject subject ) const
{
    return this->m_dMarks[subject];
}
inline std::string Pupil::getID() const
{
    return this->m_strID;
}
inline std::string Pupil::getClass() const
{
    return this->m_strClass;
}