#include "Vector.h"

int mult( int* p1, int* p2, int nSize );

Vector::Vector( int nDim, int nElem )
{
	this->m_pCoord = NULL;
	try
	{
		createVec( nDim );
		int n = getDim();
		for( int i = 0; i < n; i++ )
			this->m_pCoord[i] = nElem;
	}
	catch( VecException e )
	{
		std::cerr << e.getReason() << '\n';
	}
}
Vector::Vector( const Vector& v )
{
	this->setDim( 0 );
	this->m_pCoord = NULL;
	*this = v;
}
Vector::~Vector()
{
	delete[] this->m_pCoord;
}

std::istream& operator >> ( std::istream& in, Vector& v )
{
	int n = v.getDim();
	for( int i = 0; i < n; i++ )
		in >> v[i];
	return in;
}
std::ostream& operator << ( std::ostream& out, const Vector& v )
{
	out << '[';
	int n = v.getDim();
	for( int i = 0; i < n; i++ )
		out << v[i] << ( ( i < n - 1 ) ? "," : "" );
	out << ']';
	return out;
}

//assigment
Vector& Vector::operator = ( const Vector& v )
{
	if( this->getDim() != v.getDim() )
	{
		if( this->m_pCoord ) delete[] this->m_pCoord;
		try
		{
			createVec( v.getDim() );
		}
		catch( VecException e )
		{
			std::cerr << e.getReason() << '\n';
			return *this;
		}

	}
	copyVec( v );
	return *this;
}

//addition
const Vector operator + ( const Vector& v1, const Vector& v2 )
{
	Vector res( v1 );
	return res += v2;
} // v1 + v2
const Vector operator + ( const Vector& v, int x )
{
	Vector res( v );
	return res += x;
} // v1 + x
const Vector operator + ( int x, const Vector& v )
{
	return v + x;
} // x + v1
Vector& Vector::operator += ( const Vector& v )
{
	int n = this->getDim();
	if( n != v.getDim() ) throw VecException( INCOMAPATIBLE_SIZES );
	for( int i = 0; i < n; i++ )
		this->m_pCoord[i] += v[i];
	return *this;
}
Vector& Vector::operator += ( int x )
{
	int n = this->getDim();
	for( int i = 0; i < n; i++ )
		this->m_pCoord[i] += x;
	return *this;
}

//unary minus
const Vector operator - ( const Vector& v )
{
	int n = v.getDim();
	Vector res( v );
	for( int i = 0; i < n; i++ )
		res[i] = -res[i];
	return res;
}

//substruction
const Vector operator - ( const Vector& v1, const Vector& v2 )
{
	return v1 + ( -v2 );
} // v1 - v2
const Vector operator - ( const Vector& v, int x )
{
	return v + ( -x );
} // v1 - x
Vector& Vector::operator -= ( const Vector& v )
{
	return *this += -v;
}
Vector& Vector::operator -= ( int x )
{
	return *this += -x;
}

//multiplication
const Vector operator * ( const Vector& v, int x )
{
	Vector res( v );
	return res *= x;
} // v1 * x
const Vector operator * ( int x, const Vector& v )
{
	return v * x;
} // x * v1
Vector& Vector::operator *= ( int x )
{
	int n = this->getDim();
	for( int i = 0; i < n; i++ )
		this->m_pCoord[i] *= x;
	return *this;
}

//scalar multiplication
const int operator * ( const Vector& v1, const Vector& v2 )
{
	if(v1.getDim() != v2.getDim() ) throw VecException( INCOMAPATIBLE_SIZES );
	return mult( (int*)v1, (int*)v2, v1.getDim() );
} // int = v1 * v2

//comparision
const bool operator == ( const Vector& v1, const Vector& v2 )
{
	int n = v1.getDim();
	if( n != v2.getDim() )
		return false;
	for( int i = 0; i < n; i++ )
		if( v1[i] != v2[i] ) return false;

	return true;
}
const bool operator != ( const Vector& v1, const Vector& v2 )
{
	return!( v1 == v2 );
}

//indexing
int& Vector::operator [] ( int ix )
{
	if( ix >= 0 && ix < this->getDim() )
		return this->m_pCoord[ix];
	throw VecException( INDEX_OUT_OF_RANGE );
} // v[2] = 1
const int& Vector::operator [] ( int ix ) const
{
	if( ix >= 0 && ix < this->getDim() )
		return this->m_pCoord[ix];
	throw VecException( INDEX_OUT_OF_RANGE );
} // int x = v[2];

//==================================================================

int mult( int* p1, int* p2, int nSize )
{
	int res = 0;
	for( int i = 0; i < nSize; i++ )
		res += *p1++ * *p2++;
	return res;
}