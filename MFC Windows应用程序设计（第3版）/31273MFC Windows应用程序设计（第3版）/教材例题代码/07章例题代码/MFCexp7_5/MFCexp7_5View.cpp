// MFCexp7_5View.cpp : implementation of the CMFCexp7_5View class
//

#include "stdafx.h"
#include "MFCexp7_5.h"

#include "MFCexp7_5Doc.h"
#include "MFCexp7_5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCexp7_5View

IMPLEMENT_DYNCREATE(CMFCexp7_5View, CView)

BEGIN_MESSAGE_MAP(CMFCexp7_5View, CView)
	//{{AFX_MSG_MAP(CMFCexp7_5View)
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCexp7_5View construction/destruction

CMFCexp7_5View::CMFCexp7_5View()
{
	// TODO: add construction code here

}

CMFCexp7_5View::~CMFCexp7_5View()
{
}

BOOL CMFCexp7_5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMFCexp7_5View drawing

void CMFCexp7_5View::OnDraw(CDC* pDC)
{
	CMFCexp7_5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->Ellipse (pDoc->m_crlRect);
}

/////////////////////////////////////////////////////////////////////////////
// CMFCexp7_5View diagnostics

#ifdef _DEBUG
void CMFCexp7_5View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCexp7_5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCexp7_5Doc* CMFCexp7_5View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCexp7_5Doc)));
	return (CMFCexp7_5Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFCexp7_5View message handlers

void CMFCexp7_5View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	CMFCexp7_5Doc*pDoc=GetDocument();
	CRect clientRec;
	GetClientRect(&clientRec);
	switch(nChar)
	{
	case VK_LEFT:
		if(pDoc->m_crlRect.left>0)
		{
			pDoc->m_crlRect.left-=5;
			pDoc->m_crlRect.right-=5;
		}
		break;
	case VK_RIGHT:
		if(pDoc->m_crlRect.right
					<=(clientRec.right-clientRec.left))
		{
			pDoc->m_crlRect.left+=5;
			pDoc->m_crlRect.right+=5;
		}
		break;
	}
	InvalidateRect(NULL,TRUE);
	
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
