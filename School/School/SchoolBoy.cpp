#include "SchoolBoy.h"

SchoolBoy::SchoolBoy( std::string sName, std::string sLastName, int nAge, std::string strClass )
	: Pupil(sName, sLastName, nAge, strClass)
{
	setID( "M_" + getID() );
}
SchoolBoy::SchoolBoy( const SchoolBoy& sb ) : Pupil(sb)
{
}

void SchoolBoy::clothes() const
{
	std::cout << "Ubranie chlopca: biala lub niebieska koszula z krawatem, marynarka, polbuty, spodnie dowolne czarne lub granatowe. \n";
}


