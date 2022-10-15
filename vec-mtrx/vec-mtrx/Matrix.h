#pragma once
#include "Vector.h"

#define MATRIX_ERROR		0x00
#define INDEX_OUT_OF_RANGE	0x01
#define ALLOCATION_ERROR	0x02
#define INCOMAPATIBLE_SIZES	0x04

//==================================================================
class MatException
{
public:
    inline MatException( USINT ErrCode = VECTOR_ERROR );
    inline const char* getReason();

private:
    USINT m_ErrCode;
};

inline MatException::MatException( USINT ErrCode )
{
    this->m_ErrCode = ErrCode;
}

inline const char* MatException::getReason()
{
    switch( this->m_ErrCode )
    {
    case INDEX_OUT_OF_RANGE:	return "ERROR: Index is out of range!";
    case ALLOCATION_ERROR:		return "ERROR: Allocation problem!";
    case INCOMAPATIBLE_SIZES:	return "ERROR: Sizes are incomapatible!";
    default:					return "ERROR: Matrix error!!";
    }
}

//==================================================================

class Matrix
{
public: //construction/destruction
    Matrix( int nRows = 2, int nCols = 2, int nElem = 0 );
    Matrix( const Matrix& m );
    virtual ~Matrix();

public: //some INLINE methods
    int getRowNo() const;
    int getColNo() const;
    void setRowNo( int nRows );

    //input/output
    friend std::istream& operator >> ( std::istream& in, Matrix& m );
    friend std::ostream& operator << ( std::ostream& out, const Matrix& m );

    //assigment
    Matrix& operator = ( const Matrix& m );

    //indexing
    Vector& operator [] ( int ix );
    const Vector& operator [] ( int ix ) const;

    operator Vector* ( ) const;

    friend const bool operator == ( const Matrix& m1, const Matrix& m2 );
    friend const bool operator != ( const Matrix& m1, const Matrix& m2 );

    friend const Matrix operator * ( const Matrix& m, int x ); // m * x
    friend const Matrix operator * ( int x, const Matrix& m ); // x * m
    Matrix& operator *= ( int x );

    friend const Vector operator * ( const Vector& v, const Matrix& m ); // v * m
    // m * v niemo¿liwe, poniewa¿ (mCols >=2 && vRows = 1) => mCols != vRows
    // Trzeba transponowaæ wektor!!
    friend const Vector operator * ( const Matrix& m, const Vector& v );// = ( m * v')'
    friend const Matrix operator * ( const Matrix& m1, const Matrix& m2 ); // = m1 * m2

private:
    void copyMat( const Matrix& m );
    void createMat( int nRows, int nCols, int nElem );

private: 
    int m_nRows;
    Vector* m_pRows;
};

inline int Matrix::getRowNo() const
{
    return this->m_nRows;
}
inline int Matrix::getColNo() const
{
    return this->m_pRows->getDim();
}
inline void Matrix::setRowNo( int nRows )
{
    this->m_nRows = nRows;
}
inline Matrix::operator Vector* ( ) const
{
    return this->m_pRows;
}
inline void Matrix::copyMat( const Matrix& m )
{
    int n = m.getRowNo();
    for( int i = 0; i < n; i++ )
    {
        this->m_pRows[i].copyVec( m.m_pRows[i] );
    }
    //memcpy( this->m_pRows, (Vector*)m, m.getColNo() * m.getRowNo() * sizeof( int ) );
}
