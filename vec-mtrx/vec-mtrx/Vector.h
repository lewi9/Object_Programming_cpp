#pragma once

#include <iostream>

#define VECTOR_ERROR		0x00
#define INDEX_OUT_OF_RANGE	0x01
#define ALLOCATION_ERROR	0x02
#define INCOMAPATIBLE_SIZES	0x04

typedef unsigned short int USINT;

//==================================================================
class VecException
{
public:
	inline VecException( USINT ErrCode = VECTOR_ERROR );
	inline const char* getReason();

private:
	USINT m_ErrCode;
};

inline VecException::VecException( USINT ErrCode )
{
	this->m_ErrCode = ErrCode;
}

inline const char* VecException::getReason()
{
	switch( this->m_ErrCode )
	{
	case INDEX_OUT_OF_RANGE:	return "ERROR: Index is out of range!";
	case ALLOCATION_ERROR:		return "ERROR: Allocation problem!";
	case INCOMAPATIBLE_SIZES:	return "ERROR: Sizes are incomapatible!";
	default:					return "ERROR: Vector error!!";
	}
}

//==================================================================

class Vector
{

	friend class Matrix;

public: //construction/destruction
	Vector( int nDim = 2, int nElem = 0 );
	Vector( const Vector& v );
	virtual ~Vector();

public: //some INLINE methods
	int getDim() const;
	void setDim( int nDim );
	operator int* () const;

public: //input/output
	friend std::istream& operator >> ( std::istream& in, Vector& v );
	friend std::ostream& operator << ( std::ostream& out, const Vector& v );

	//assigment
	Vector& operator = ( const Vector& v );

	//addition
	friend const Vector operator + ( const Vector& v1, const Vector& v2 ); // v1 + v2
	friend const Vector operator + ( const Vector& v, int x ); // v1 + x
	friend const Vector operator + ( int x, const Vector& v ); // x + v1
	Vector& operator += ( const Vector& v );
	Vector& operator += ( int x );

	//unary minus
	friend const Vector operator - ( const Vector& v );

	//substruction
	friend const Vector operator - ( const Vector& v1, const Vector& v2 ); // v1 - v2
	friend const Vector operator - ( const Vector& v, int x ); // v1 - x
	Vector& operator -= ( const Vector& v );
	Vector& operator -= ( int x );

	//multiplication
	friend const Vector operator * ( const Vector& v, int x ); // v1 * x
	friend const Vector operator * ( int x, const Vector& v ); // x * v1
	Vector& operator *= ( int x );
	
	//scalar multiplication
	friend const int operator * ( const Vector& v1, const Vector& v2 ); // int = v1 * v2

	//comparision
	friend const bool operator == ( const Vector& v1, const Vector& v2 );
	friend const bool operator != ( const Vector& v1, const Vector& v2 );

	//indexing
	int& operator [] ( int ix ); // v[2] = 1
	const int& operator [] ( int ix ) const; // int x = v[2];

private: //inline support methods
	void createVec( int nDim );
	void copyVec( const Vector& v );

private:
	int m_nDim;
	int* m_pCoord;
};

//=======INLINE FUNCTIONS=======//
inline int Vector::getDim() const
{
	return this->m_nDim;
}
inline void Vector::setDim( int nDim )
{
	this->m_nDim = nDim;
}
inline Vector::operator int* () const
{
	return this->m_pCoord;
}

inline void Vector::createVec( int nDim )
{
	if( nDim < 2 ) nDim = 2;
	this->setDim( nDim );
	this->m_pCoord = new ( std::nothrow ) int[nDim];
	if( !this->m_pCoord ) throw VecException( ALLOCATION_ERROR );
}

inline void Vector::copyVec( const Vector& v )
{
	memcpy( this->m_pCoord, (int*)v, v.getDim() * sizeof( int ) );
}
