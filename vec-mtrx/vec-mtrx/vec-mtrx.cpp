#include <iostream>
#include "Vector.h"
#include "Matrix.h"

int main()
{
    try{
        Vector w1( 3 );
        Vector w2( 4, 1 );
        Vector w3( 4, 2 );
        Vector w4( w2 );
        w1 = w3;
        std::cout << "w1 = " << w1 << std::endl;
        std::cout << "w2 = " << w2 << std::endl;
        std::cout << "w3 = " << w3 << std::endl;
        std::cout << "w4 = " << w4 << std::endl;
        std::cout << "w3 + w4 = " << w3+w4 << std::endl;
        std::cout << "w3 - w4 = " << w3-w4 << std::endl;
        std::cout << "w2 * w3 = " << w2*w3 << std::endl;
        w1 = 2 + w1;
        int* p = (int*)w3;
        std::cout << "\np[1] = " << *( p + 1 ) << "\n\n";
        w3[0] += 3;
        w3[1] = 4;
        w3[1] = w3[2] + w3[0];
        std::cout << "w3 = " << w3 << std::endl;
        w1[12] = 8;
        std::cout << "=======================================" << std::endl;
    }
    catch (VecException e )
    {
        std::cerr << e.getReason() << '\n';
    }
    try{
        Vector w1( 3,2 );
        Matrix m1( 3,2,3 );
        Matrix m2( 3,3,2 );
        Matrix m3( 1 );
        Matrix m4( m2 );
        m3 = m1;
        std::cout << "Podaj wartosci wektora o rozmiarze 3: ";
        std::cin >> w1;
        std::cout << "Podaj wartosci macierzy o rozmiarze 3x3: ";
        std::cin >> m2;
        Vector* v = (Vector*)m2;
        std::cout << "\nv[1] = " << *( v + 1 ) << "\n\n";
        std::cout << "w1 = " << w1 << std::endl;
        std::cout << "m1 = " << m1 << std::endl;
        std::cout << "m2 = " << m2 << std::endl;
        std::cout << "m3 = " << m3 << std::endl;
        std::cout << "m4 = " << m4 << std::endl;
        std::cout << "w1 * m2 = " << w1 * m2 << std::endl;
        std::cout << "m2 * w1 = " << m2 * w1 << std::endl;
        std::cout << "m2 * 2 = " << m2 * 2 << std::endl;
        std::cout << "3 * m2 = " << 3 * m2 << std::endl;
        std::cout << "=======================================" << std::endl;
        Matrix m5( 2, 3, 2 );
        Matrix m6( 3, 2, -1 );
        Matrix m7( 4, 4, 1 );
        std::cout << "m5 = " << m5 << std::endl;
        std::cout << "m6 = " << m6 << std::endl;
        std::cout << "m7 = " << m7 << std::endl;
        std::cout << "m5 * m6 = " << m5 * m6 << std::endl;
        std::cout << "m6 * m5 = " << m6 * m5 << std::endl;
        std::cout << "m5 * m7 = ";
        std::cout << m5 * m7 << std::endl;
    }
    catch( MatException e )
    {
        std::cerr << e.getReason() << '\n';
    }
    return 0;
}