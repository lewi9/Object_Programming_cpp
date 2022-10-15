// Stos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "stack.h"

template <class T>
void naStos( Stack<T>&, T t );

template <class T>
void testStos(T f);

int main()
{
    testStos<int>(0);
    testStos<double>(0.1);
    testStos<char>(65);

    return 0;
}

template <class T>
void naStos( Stack<T>& stos, T t )
{
    try
    {
        stos.push( t );
    }
    catch( StackException& err )
    {
        std::cerr << err.getReason();
    }
}

template <class T>
void testStos( T f )
{
    Stack<T> stos;
    for( T i = f; i < f+4; i++ )
        naStos( stos, i );

    for( int i = 0; i < 5; i++ )
    {
        try
        {
            std::cout << stos.pop() << std::endl;
        }
        catch( StackException& err )
        {
            std::cerr << err.getReason() << std::endl;
        }

    }
}