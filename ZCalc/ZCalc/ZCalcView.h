
// ZCalcView.h : interface of the CZCalcView class
//

#pragma once


class CZCalcView : public CView
{
protected: // create from serialization only
	CZCalcView() noexcept;
	DECLARE_DYNCREATE(CZCalcView)

// Attributes
public:
	CZCalcDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CZCalcView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCalcul();
};

#ifndef _DEBUG  // debug version in ZCalcView.cpp
inline CZCalcDoc* CZCalcView::GetDocument() const
   { return reinterpret_cast<CZCalcDoc*>(m_pDocument); }
#endif

