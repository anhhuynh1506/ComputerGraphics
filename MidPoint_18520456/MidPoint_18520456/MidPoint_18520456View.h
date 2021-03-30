
// MidPoint_18520456View.h : interface of the CMidPoint18520456View class
//

#pragma once


class CMidPoint18520456View : public CView
{
protected: // create from serialization only
	CMidPoint18520456View() noexcept;
	DECLARE_DYNCREATE(CMidPoint18520456View)

// Attributes
public:
	CMidPoint18520456Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMidPoint18520456View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in MidPoint_18520456View.cpp
inline CMidPoint18520456Doc* CMidPoint18520456View::GetDocument() const
   { return reinterpret_cast<CMidPoint18520456Doc*>(m_pDocument); }
#endif

