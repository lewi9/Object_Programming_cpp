#include "Matrix.h"

//construction/destruction
Matrix::Matrix( int nRows, int nCols, int nElem )
{
	this->m_pRows = NULL;
	try
	{
		createMat( nRows, nCols, nElem );
	}
	catch( MatException e )
	{
		std::cerr << e.getReason() << '\n';
	}
}
Matrix::Matrix( const Matrix& m )
{
	this->setRowNo( 0 );
	this->m_pRows = NULL;
	*this = m;
}
Matrix::~Matrix()
{
	delete[] this->m_pRows;
}

//input/output
std::istream& operator >> ( std::istream& in, Matrix& m )
{
	int n = m.getRowNo();
	for( int i = 0; i < n; i++ )
		in >> m[i];
	return in;
}
std::ostream& operator << ( std::ostream& out, const Matrix& m )
{
	int n = m.getRowNo();
	for( int i = 0; i < n; i++ )
	{
		out << "\n";
		out << m[i];
	}
		
	return out;
}

//assigment
Matrix& Matrix::operator = ( const Matrix& m )
{
	if( this->m_nRows != m.getRowNo() )
	{
		if( this->m_pRows ) delete[] this->m_pRows;
		try
		{
			createMat( m.getRowNo(), m.getColNo(), NULL );
		}
		catch( MatException e )
		{
			std::cerr << e.getReason() << '\n';
			return *this;
		}

	}
	copyMat( m );
	return *this;
}

//indexing
Vector& Matrix::operator [] ( int ix )
{
	if( ix >= 0 && ix < this->getRowNo() )
		return this->m_pRows[ix];
	throw MatException( INDEX_OUT_OF_RANGE );
}
const Vector& Matrix::operator [] ( int ix ) const
{
	if( ix >= 0 && ix < this->getRowNo() )
		return this->m_pRows[ix];
	throw MatException( INDEX_OUT_OF_RANGE );
}

const bool operator == ( const Matrix& m1, const Matrix& m2 )
{
	int n = m1.getRowNo();
	if( n != m2.getRowNo() )
		return false;
	if( m1.getColNo() != m2.getColNo() )
		return false;
	for( int i = 0; i < n; i++ )
		if( m1[i] != m2[i] ) return false;

	return true;
}
const bool operator != ( const Matrix& m1, const Matrix& m2 )
{
	return !( m1 == m2 );
}

const Matrix operator * ( const Matrix& m, int x )
{
	Matrix res( m );
	return res *= x;
} // m * x
const Matrix operator * ( int x, const Matrix& m )
{
	return m * x;
} // x * m
Matrix& Matrix::operator *= ( int x )
{
	int n = this->getRowNo();
	for( int i = 0; i < n; i++ )
		this->m_pRows[i] *= x;
	return *this;
}

const Vector operator * ( const Vector& v, const Matrix& m )
{
	int n = m.getColNo();
	int k = m.getRowNo();
	if( v.getDim() != k ) throw MatException( INCOMAPATIBLE_SIZES );
	Vector w( n );
	for( int i = 0; i < n; i++ )
		for(int j=0; j<k; j++ )
			w[i] += v[j] * m[j][i];
	return w;
} // v * m
// m * v niemo¿liwe, poniewa¿ (mCols >=2 && vRows = 1) => mCols != vRows
// Trzeba transponowaæ wektor!!
const Vector operator * ( const Matrix& m, const Vector& v )
{
	int n = m.getRowNo();
	if( m.getColNo() != v.getDim() ) throw MatException( INCOMAPATIBLE_SIZES );
	Vector w( n );
	for( int i = 0; i < n; i++ )
		w[i] = m[i] * v;
	return w;
} // = (m * v')'

const Matrix operator * ( const Matrix& m1, const Matrix& m2 )
{
	if( m1.getColNo() != m2.getRowNo() )throw MatException( INCOMAPATIBLE_SIZES );
	Matrix m( m1.getRowNo(), m2.getColNo(), 0 );
	int n = m.getRowNo();
	for( int i = 0; i < n; i++ )
		m[i] = m1[i] * m2;
	return m;
}// = m1 * m2

void Matrix::createMat( int nRows, int nCols, int nElem )
{
	if( nRows < 2 ) nRows = 2;
	this->setRowNo( nRows );
	this->m_pRows = new( std::nothrow ) Vector[nRows];
	if( !this->m_pRows ) throw MatException( ALLOCATION_ERROR );
	try
	{
		for( int i = 0; i < nRows; i++ )
			this->m_pRows[i] = Vector( nCols, nElem );
	}
	catch( VecException e )
	{
		std::cerr << e.getReason() << '\n';
	}
}