#pragma once

#include "Complex.h"

// ComplexDlg dialog

class ComplexDlg : public CDialog
{
	DECLARE_DYNAMIC(ComplexDlg)

public:
	ComplexDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ComplexDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COMPLEX_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:

	void ShowResult( const Complex&, int,  bool = true );

private:
	double m_z1RE;
	double m_z1IM;
	double m_z2RE;
	double m_z2IM;
	int m_OperKat;
	BOOL m_bCoupledZ1;
	BOOL m_bCoupledZ2;
public:
	afx_msg void OnClickedEvaluate();
};
