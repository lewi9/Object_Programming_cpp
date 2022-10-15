#pragma once
#include <iostream>

class FQInfo
{
public:
	inline FQInfo( int nKey = 0, int p_1 = 0, int p_2 = 0 );
	inline virtual ~FQInfo();
	friend std::ostream& operator << ( std::ostream& out, const FQInfo& FQI );
private:
	int* m_p;
	int m_nKey;
};

#define FQINFO FQInfo

inline FQInfo::FQInfo( int nKey, int p_1, int p_2 )
{
	this->m_nKey = nKey;
	m_p = new ( std::nothrow ) int[2];
	m_p[0] = p_1;
	m_p[1] = p_2;
}

inline FQInfo::~FQInfo()
{
	delete [] m_p;
}

inline std::ostream& operator << ( std::ostream& out, const FQInfo& FQI )
{
	out << "Key = " << FQI.m_nKey << ", p1 = " << FQI.m_p[0] << ", p1 = " << FQI.m_p[1] << '\n';
	return out;
}