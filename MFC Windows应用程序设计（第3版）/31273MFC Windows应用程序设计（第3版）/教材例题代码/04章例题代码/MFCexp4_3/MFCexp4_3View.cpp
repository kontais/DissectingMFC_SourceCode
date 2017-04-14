// MFCexp4_3View.cpp : implementation of the CMFCexp4_3View class
//

#include "stdafx.h"
#include "MFCexp4_3.h"

#include "MFCexp4_3Doc.h"
#include "MFCexp4_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCexp4_3View

IMPLEMENT_DYNCREATE(CMFCexp4_3View, CView)

BEGIN_MESSAGE_MAP(CMFCexp4_3View, CView)
	//{{AFX_MSG_MAP(CMFCexp4_3View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCexp4_3View construction/destruction

CMFCexp4_3View::CMFCexp4_3View()
{
	// TODO: add construction code here

}

CMFCexp4_3View::~CMFCexp4_3View()
{
}

BOOL CMFCexp4_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMFCexp4_3View drawing

void CMFCexp4_3View::OnDraw(CDC* pDC)
{
	CMFCexp4_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	int style[]={PS_SOLID,PS_DASH,PS_DOT,PS_DASHDOT,PS_DASHDOTDOT};
	int row=20;
	for(int s=0;s<5;s++)
	{
		CPen newPen(style[s],1,RGB(0,0,0));
		CPen*oldPen=pDC->SelectObject(&newPen);
		pDC->MoveTo(20,row);
		pDC->LineTo(300,row);
		pDC->SelectObject(oldPen);
		row+=30;
	}
}


/////////////////////////////////////////////////////////////////////////////
// CMFCexp4_3View diagnostics

#ifdef _DEBUG
void CMFCexp4_3View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCexp4_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCexp4_3Doc* CMFCexp4_3View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCexp4_3Doc)));
	return (CMFCexp4_3Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFCexp4_3View message handlers
