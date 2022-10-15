#include "pch.h"
#include "Complex.h"

Complex::Complex( double RE, double IM )
{
	SetComplex( RE, IM );
}
Complex::Complex( const Complex& z )
{
	*this = z;
}

Complex& Complex::operator = ( const Complex& z )
{
	SetComplex( z );
	return *this;
}

const Complex operator + ( const Complex& z1, const Complex& z2 )
{
	Complex r( z1 );
	return r += z2;
}
const Complex operator - ( const Complex& z1, const Complex& z2 )
{
	Complex r( z1 );
	return r += -z2;
}
const Complex operator * ( const Complex& z1, const Complex& z2 )
{
	Complex r( z1 );
	return r *= z2;
}
const Complex operator / ( const Complex& z1, const Complex& z2 )
{
	Complex r( z1 );
	return r /= z2;
}

Complex& Complex::operator += ( const Complex& z )
{
	this->setRE( this->getRE() + z.getRE() );
	this->setIM( this->getIM() + z.getIM() );
	return *this;
}
Complex& Complex::operator -= ( const Complex& z )
{
	return *this += -z;
}
Complex& Complex::operator *= ( const Complex& z )
{
	double RE = this->getRE() * z.getRE() - this->getIM() * z.getIM();
	double IM = this->getRE() * z.getIM() + this->getIM() * z.getRE();
	this->SetComplex( RE, IM );
	return *this;
}
Complex& Complex::operator /= ( const Complex& z )
{
	double dzielnik = z.sqr();
	if( dzielnik <= 1E-300 )
	{
		std::cerr << "Nie mozna wykonac operacji dzielenia" << std::endl;
		return *this;
	}
	double RE = ( this->getRE() * z.getRE() + this->getIM() * z.getIM() ) / dzielnik;
	double IM = ( this->getIM() * z.getRE() + this->getRE() * z.getIM() ) / dzielnik;
	this->SetComplex( RE, IM );
	return *this;
}

const Complex operator - ( const Complex& z )
{
	Complex t;
	t.setRE( -z.getRE() );
	t.setIM( -z.getIM() );
	return t;
}

bool operator == ( const Complex& z1, const Complex& z2 )
{
	return ( z1.getRE() == z2.getRE() && z1.getIM() == z2.getIM() ) ? true : false;
}

bool operator != ( const Complex& z1, const Complex& z2 )
{
	//return ( z1.getRE() == z2.getRE() && z1.getIM() == z2.getIM() ) ? 0 : 1;
	return !( z1 == z2 );
}

std::istream& operator >> ( std::istream& in, Complex& z )
{
	//separator spacja: RE IM
	double temp;
	in >> temp;
	z.setRE( temp );
	in >> temp;
	z.setIM( temp );
	return in;

}
std::ostream& operator << ( std::ostream& out, const Complex& z )
{
	out << "RE = " << z.getRE() << "  IM = " << z.getIM();
	return out;
}


void Complex::SetComplex( double RE, double IM )
{
	this->setRE( RE );
	this->setIM( IM );
}
void Complex::SetComplex( const Complex& z )
{
	SetComplex( z.getRE(), z.getIM() );
}

// *************
// CANON COMPLEX
// *************

CanonComplex::CanonComplex( const Complex& z ): Complex( z )
{ //implementacja pusta
}

std::ostream& operator << ( std::ostream& out, const CanonComplex& z )
{
	out << z.getRE();
	double t = z.getIM();
	/*if( t >= 1E-300 )
		out << " + ";
	else
		out << " - ";*/
	( t >= 1E-300 ) ? out << " + " : out << " - ";
	out << abs(t) << "i" << std::endl;
	return out;
}