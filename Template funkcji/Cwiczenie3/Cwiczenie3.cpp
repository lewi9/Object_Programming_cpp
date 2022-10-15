#include <iostream>

template <class T1, typename T2> int howmany( T1* arr, int size, T2 min, T2 max )
{
    int count = 0;
    for( int i = 0; i < size; i++, arr++ )
        if( *arr > min && *arr < max )
            count++;
    std::cout << "T1=" << typeid( T1 ).name() << ' ';
    std::cout << "T2=" << typeid( T2 ).name() << '\n';
    return count;
}

int main()
{
    double mnd = 0;
    double mxd = 10;
    int mni = 0;
    int mxi = 10;
    double tabd[] = { -2, -1, 2, 5, 7, 11, 5, -5 };
    int tabi[] = { -2, -1, 2, 5, 7, 11, 5, -5 };

    int res = howmany( tabi, 8, mni, mxi );
    std::cout << "res=" << res << std::endl;

    res = howmany( tabd, 8, mnd, mxd );
    std::cout << "res=" << res << std::endl;

    return 0;
}

