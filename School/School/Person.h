#pragma once
#include <string>
#include <iostream>

class Person
{
public:
	Person( std::string strName = "Name", std::string strLastName = "Nowak", int nAge = 18 );
	Person( const Person& p );

	Person& operator = ( const Person& p );

public:
	inline void setName( std::string strName );
	inline void setLastName( std::string strLastName );
	inline void setAge( int nAge );
	inline void setPerson( std::string strName, std::string srLastName, int nAge );

	inline std::string getName() const;
	inline std::string getLastName() const;
	inline int getAge() const;

private:
	std::string m_strName;
	std::string m_strLastName;
	int m_Age;
};

inline void Person::setName( std::string strName )
{
	this->m_strName = strName;
}
inline void Person::setLastName( std::string strLastName )
{
	this->m_strLastName = strLastName;
}
inline void Person::setAge( int nAge )
{
	this->m_Age = nAge;
}

inline void Person::setPerson( std::string strName, std::string strLastName, int nAge )
{
	setName( strName );
	setLastName( strLastName );
	setAge( nAge );
}

inline std::string Person::getName() const
{
	return this->m_strName;
}
inline std::string Person::getLastName() const
{
	return this->m_strLastName;
}
inline int Person::getAge() const
{
	return this->m_Age;
}