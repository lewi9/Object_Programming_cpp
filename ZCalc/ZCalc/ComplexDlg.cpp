// ComplexDlg.cpp : implementation file
//

#include "pch.h"
#include "ZCalc.h"
#include "ComplexDlg.h"
#include "afxdialogex.h"
#include "Complex.h"


#define ADD 0
#define SUB 1
#define MULT 2
#define DIV 3

// ComplexDlg dialog

IMPLEMENT_DYNAMIC(ComplexDlg, CDialog)

ComplexDlg::ComplexDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_COMPLEX_DLG, pParent)
	, m_z1RE( 0 )
	, m_z1IM( 0 )
	, m_z2RE( 0 )
	, m_z2IM( 0 )
	, m_OperKat( 0 )
	, m_bCoupledZ1( FALSE )
	, m_bCoupledZ2( FALSE )
{

}

ComplexDlg::~ComplexDlg()
{
}

void ComplexDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange( pDX );
	DDX_Text( pDX, IDC_Z1RE, m_z1RE );
	DDX_Text( pDX, IDC_Z1IM, m_z1IM );
	DDX_Text( pDX, IDC_Z2RE, m_z2RE );
	DDX_Text( pDX, IDC_Z2IM, m_z2IM );
	DDX_Radio( pDX, IDC_ADD, m_OperKat );
	DDX_Check( pDX, IDC_COUPLEDZ1, m_bCoupledZ1 );
	DDX_Check( pDX, IDC_COUPLEDZ2, m_bCoupledZ2 );
}


BEGIN_MESSAGE_MAP(ComplexDlg, CDialog)
	ON_BN_CLICKED( IDC_EVALUATE, &ComplexDlg::OnClickedEvaluate )
END_MESSAGE_MAP()


// ComplexDlg message handlers


void ComplexDlg::OnClickedEvaluate()
{
	UpdateData(); //ustawia wartoœci zmiennych w zale¿noœci od ustawieñ kontrolek
	Complex z1( m_z1RE, m_z1IM );
	Complex z2( m_z2RE, m_z2IM );
	Complex res;

	switch( m_OperKat )
	{
	case ADD: res = z1 + z2; break;
	case SUB: res = z1 - z2; break;
	case MULT:res = z1 * z2; break;
	case DIV: if( z2.getRE() == 0 && z2.getIM() == 0 )
					AfxMessageBox( L"Cholero nie dziel przez zero!11!" );
			  else res = z1 / z2;
			  break;
	}
	/*CString str;
	str.Format( L"%.2lf + (%.2lf)*i", res.getRE(), res.getIM() );
	CWnd* pWnd = GetDlgItem( IDC_RESULT );
	pWnd->SetWindowTextW( str );*/

	ShowResult( res, IDC_RESULT );
	if( m_bCoupledZ1 ) ShowResult( z1.Coupled(), IDC_Z1COUPLED );
	else ShowResult( z1.Coupled(), IDC_Z1COUPLED, FALSE );
	if( m_bCoupledZ2 ) ShowResult( z2.Coupled(), IDC_Z2COUPLED );
	else ShowResult( z2.Coupled(), IDC_Z2COUPLED, FALSE );
}

void ComplexDlg::ShowResult( const Complex& z, int ID, bool bErase )
{
	CString str(L"");
	if(bErase)
		str.Format( L"%.2lf + (%.2lf)*i", z.getRE(), z.getIM() );
	CWnd* pWnd = GetDlgItem( ID );
	pWnd->SetWindowTextW( str );
}
