#pragma once
#include <iostream>

c = sum();
d = sum( 4 );

int sum( int a = 2, int b = 3 )
{
	return a + b;
}


class Complex
{
public:
	Complex( double RE = 0, double IM = 0 );
	Complex( const Complex& z );

public:
	Complex& operator = ( const Complex& z );
	friend const Complex operator + ( const Complex& z1, const Complex& z2 );
	friend const Complex operator - ( const Complex& z1, const Complex& z2 );
	friend const Complex operator * ( const Complex& z1, const Complex& z2 );
	friend const Complex operator / ( const Complex& z1, const Complex& z2 );

	Complex& operator += ( const Complex& z );
	Complex& operator -= ( const Complex& z );
	Complex& operator *= ( const Complex& z );
	Complex& operator /= ( const Complex& z );

	friend const Complex operator - ( const Complex& z );

	friend bool operator == ( const Complex& z1, const Complex& z2 );
	friend bool operator != ( const Complex& z1, const Complex& z2 );

	friend std::istream& operator >> ( std::istream& in, Complex& z );
	friend std::ostream& operator << ( std::ostream& out, const Complex& z );

	inline double Module();
	inline Complex Coupled();
	inline operator int();
	inline operator double();

	inline double getRE() const;
	inline double getIM() const;

	inline void setRE( double RE );
	inline void setIM( double IM );

	void SetComplex( double RE, double IM);
	void SetComplex( const Complex& z );

private:

	inline double sqr() const; // re^2 + im^2

protected:

	double m_RE;
	double m_IM;
};

//inline funkcje

inline double Complex::Module()
{
	return sqrt( this->sqr() );
}
inline Complex Complex::Coupled()
{
	return Complex( this->getRE(), -this->getIM() );
}
inline Complex::operator int()
{
	return int( this->getRE() );
}
inline Complex::operator double()
{
	return double( this->getRE() );
}

inline double Complex::getRE() const
{
	return this->m_RE;
}

inline double Complex::getIM() const
{
	return this->m_IM;
}

inline void Complex::setRE( double RE )
{
	this->m_RE = RE;
}
inline void Complex::setIM( double IM )
{
	this->m_IM = IM;
}
inline double Complex::sqr() const
{
	return this->getRE() * this->getRE() + this->getIM() * this->getIM();
}

// *************
// CANON COMPLEX
// *************

class CanonComplex: public Complex
{
public:
	CanonComplex( const Complex& );
	friend std::ostream& operator << ( std::ostream& out, const CanonComplex& z );
};