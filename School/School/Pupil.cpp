#include "Pupil.h"

Pupil::Pupil( std::string sName, std::string sLastName, int nAge, std::string strClass ) 
	: Person(sName, sLastName, nAge)
{
	static int nID = 1000;
	setID( std::to_string( nID ) );
	setClass( strClass );
	clearMarks();
	nID++;

}
Pupil::Pupil( const Pupil& pupil )
{
	*this = pupil;
}

Pupil& Pupil::operator = ( const Pupil& pupil )
{
	setPerson( pupil.getName(), pupil.getLastName(), pupil.getAge() );
	setID( pupil.getID() );
	setClass( pupil.getClass() );
	for( int i = 0; i < 7; i++ )
		this->m_dMarks[i] = pupil.m_dMarks[i];
	return *this;
}

double Pupil::avgMark() const
{
	double avg = 0;
	int count = 0;
	for( int i = 0; i < 7; i++ )
	{
		double t = this->m_dMarks[i];
		if( t >= 1e-16 )
		{
			avg += t;
			count++;
		}
	}
	return avg / count;
}
void Pupil::clearMarks()
{
	memset( this->m_dMarks, 0, sizeof( this->m_dMarks) );
}

std::ostream& operator << ( std::ostream& out, const Pupil& pupil )
{
	out << std::endl << "ID: " << pupil.getID() << std::endl;
	out << "Imie: " << pupil.getName() << std::endl;
	out << "Nazwisko: " << pupil.getLastName() << std::endl;
	out << "Srednia ocen: " << pupil.avgMark() << std::endl;
	out << "Klasa: " << pupil.getClass() << std::endl;
	out << "Ilosc lat: " << pupil.getAge() << std::endl;
	pupil.clothes();
	out << std::endl;

	return out;
}