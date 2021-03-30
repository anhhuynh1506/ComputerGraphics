
// MidPoint_18520456View.cpp : implementation of the CMidPoint18520456View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MidPoint_18520456.h"
#endif

#include "MidPoint_18520456Doc.h"
#include "MidPoint_18520456View.h"
#include "MidPoint.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMidPoint18520456View

IMPLEMENT_DYNCREATE(CMidPoint18520456View, CView)

BEGIN_MESSAGE_MAP(CMidPoint18520456View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMidPoint18520456View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMidPoint18520456View construction/destruction

CMidPoint18520456View::CMidPoint18520456View() noexcept
{
	// TODO: add construction code here

}

CMidPoint18520456View::~CMidPoint18520456View()
{
}

BOOL CMidPoint18520456View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMidPoint18520456View drawing

void CMidPoint18520456View::OnDraw(CDC* pDC)
{
	CMidPoint18520456Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMidPoint18520456View printing


void CMidPoint18520456View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMidPoint18520456View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMidPoint18520456View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMidPoint18520456View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMidPoint18520456View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMidPoint18520456View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMidPoint18520456View diagnostics

#ifdef _DEBUG
void CMidPoint18520456View::AssertValid() const
{
	CView::AssertValid();
}

void CMidPoint18520456View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMidPoint18520456Doc* CMidPoint18520456View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMidPoint18520456Doc)));
	return (CMidPoint18520456Doc*)m_pDocument;
}
#endif //_DEBUG


// CMidPoint18520456View message handlers

int x_s = NULL;
int x_e = NULL;
int y_s = NULL;
int y_e = NULL;
int x_center;
int y_center;
int r;
bool isDraw = FALSE;

void CMidPoint18520456View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	x_s = point.x;
	y_s = point.y;
	isDraw = TRUE;
	CView::OnLButtonDown(nFlags, point);
}


void CMidPoint18520456View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC* pDC = new CClientDC(this);
	x_e = point.x;
	y_e = point.y;
	if (x_s != NULL && x_e != NULL && y_s != NULL && y_e != NULL && isDraw)
	{
		x_center = x_s + round(abs((x_e - x_s) / 2));
		y_center = y_s + round(abs((y_e - y_s) / 2));
		r = round((sqrt(pow(x_e - x_s, 2) + pow(y_e - y_s, 2)))/2);
		Invalidate();
		UpdateWindow();
		MidPoint::MidPoint_Algo(pDC, x_center, y_center, r, RGB(255, 0, 0));
	}
	CView::OnMouseMove(nFlags, point);
}


void CMidPoint18520456View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	isDraw = FALSE;
	CView::OnLButtonUp(nFlags, point);
}
