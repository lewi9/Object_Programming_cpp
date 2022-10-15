#include <iostream>
#include "SchoolBoy.h"
#include "SchoolGirl.h"
#include "Teacher.h"
#include "OfficeWorker.h"

#define UCZNIOWIE 2

void printPupil( Pupil** t, int nSize );

int main()
{
    SchoolBoy boy;
    SchoolGirl girl( "Anastazja", "Kowalska", 18, "2c" );
    boy.addMark( 3, ANGIELSKI );
    boy.addMark( 4.5, NIEMIECKI );
    boy.addMark( 3.75, INFORMATYKA );
    boy.addMark( 5, MATEMATYKA );
    //std::cout << boy;
    //std::cout << girl;
    girl.clothes();
    girl.addMark( 5, CHEMIA );
    std::cout << "Ocena z chemii: " << girl.getMark(CHEMIA) << std::endl;
    Pupil* t[ UCZNIOWIE ] = { &boy, &girl };
    printPupil( t, UCZNIOWIE );
    girl.clearMarks();
    std::cout << "Ocena z chemii: " << girl.getMark( CHEMIA ) << std::endl;
    SchoolBoy a;
    SchoolBoy b;
    SchoolBoy aa;
    SchoolBoy c;
    SchoolBoy d;
    std::cout << d;

    Teacher abc( "Monika", "Antosiewicz", 30, 8000, 8, 1, "2a", "Chemia" );
    Teacher abcd( "Monika", "Antosiewicz", 30, 2000, 8, 0, "2a", "Chemia" );
    OfficeWorker cba( "Maciej", "Chuchro", 30, 8000 );

    std::cout << "Pensja netto Moniki Antosiewicz, staz pracy = 8: " << abc.calculateNetto() << std::endl;
    std::cout << "Pensja netto Macieja Chuchro: " << cba.calculateNetto() << std::endl;
    abc.setSeniority( 3 );
    std::cout << "Pensja netto Moniki Antosiewicz, staz pracy = 3: " << abc.calculateNetto() << std::endl;
    abc.setSeniority( 20 );
    std::cout << "Pensja netto Moniki Antosiewicz, staz pracy = 20: " << abc.calculateNetto() << std::endl;
    abc.setSeniority( 25 );
    std::cout << "Pensja netto Moniki Antosiewicz, staz pracy = 25: " << abc.calculateNetto() << std::endl;
    //Pupil dwa;
    //SchoolWorker trzy;

    return 0;
}

void printPupil( Pupil** t, int nSize )
{
    for( int i=0; i<nSize; i++ )
    {
        std::cout << *t[i];
    }
}
