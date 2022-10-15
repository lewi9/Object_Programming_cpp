#include <iostream>
#include "Complex.h"


int main()
{
    Complex z1;
    Complex z2( 2.5, 2 );
    Complex z3( z2 );
    Complex z4;

    z4.setIM( 4 );
    z4.setRE( 1 );

    std::cout << "Test dodawania " << z3 + z2 << std::endl;
    std::cout << "Test odejmowania " << z3 - z2 << std::endl;
    std::cout << "Test odejmowania2 " << z3 - z4 << std::endl;
    std::cout << "Test mnozenia " << z3 * z2 << std::endl;
    std::cout << "Test dzielenia przez zero " << z3 / z1 << std::endl;
    std::cout << "Test dzielenia " << z3 / z2 << std::endl;
    std::cout << "Test porownania " << (z3 == z2) << std::endl;
    std::cout << "Test roznosci " << (z3 != z2) << std::endl;
    std::cout << "Test modul " << z3.Module() << std::endl;
    std::cout << "Test sprzezenie " << z3 << " sprzezenie: " << z3.Coupled() << std::endl;
    std::cout << "Test int rzutowanie " << (int)z3 << std::endl;
    std::cout << "Test double rzutowanie " << (double)z3 << std::endl;

    std::cin >> z1;
    std::cout << CanonComplex(z1);

    return 0;
}

