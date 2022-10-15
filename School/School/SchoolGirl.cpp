#include "SchoolGirl.h"

SchoolGirl::SchoolGirl( std::string sName, std::string sLastName, int nAge, std::string strClass )
	: Pupil( sName, sLastName, nAge, strClass )
{
	setID( "F_" + getID() );
}
SchoolGirl::SchoolGirl( const SchoolGirl& sg ) : Pupil( sg )
{
}

void SchoolGirl::clothes() const
{
	std::cout << "Ubranie dziewczynki: biala bluzka z krawatem (opcjonalnie dodatkowo granatowy lub czarny sweterek, granatowa( lub czarna ) spodniczka, plaskie obuwie\n";
}