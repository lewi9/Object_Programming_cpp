
// ZCalcView.cpp : implementation of the CZCalcView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ZCalc.h"
#endif

#include "ZCalcDoc.h"
#include "ZCalcView.h"
#include "ComplexDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CZCalcView

IMPLEMENT_DYNCREATE(CZCalcView, CView)

BEGIN_MESSAGE_MAP(CZCalcView, CView)
	ON_COMMAND( ID_CALCUL, &CZCalcView::OnCalcul )
END_MESSAGE_MAP()

// CZCalcView construction/destruction

CZCalcView::CZCalcView() noexcept
{
	// TODO: add construction code here

}

CZCalcView::~CZCalcView()
{
}

BOOL CZCalcView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CZCalcView drawing

void CZCalcView::OnDraw(CDC* /*pDC*/)
{
	CZCalcDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CZCalcView diagnostics

#ifdef _DEBUG
void CZCalcView::AssertValid() const
{
	CView::AssertValid();
}

void CZCalcView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CZCalcDoc* CZCalcView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CZCalcDoc)));
	return (CZCalcDoc*)m_pDocument;
}
#endif //_DEBUG


// CZCalcView message handlers


void CZCalcView::OnCalcul()
{
	//::AfxMessageBox( L"Wybrano przycisk kalkulatora" );
	ComplexDlg dlg;
	dlg.DoModal();
}
