// SrvrItem.cpp : implementation of the CAutoServerSrvrItem class
//

#include "stdafx.h"
#include "AutoServer.h"

#include "AutoServerDoc.h"
#include "SrvrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAutoServerSrvrItem implementation

IMPLEMENT_DYNAMIC(CAutoServerSrvrItem, COleServerItem)

CAutoServerSrvrItem::CAutoServerSrvrItem(CAutoServerDoc* pContainerDoc)
	: COleServerItem(pContainerDoc, TRUE)
{
	// TODO: add one-time construction code here
	//  (eg, adding additional clipboard formats to the item's data source)
}

CAutoServerSrvrItem::~CAutoServerSrvrItem()
{
	// TODO: add cleanup code here
}

void CAutoServerSrvrItem::Serialize(CArchive& ar)
{
	// CAutoServerSrvrItem::Serialize will be called by the framework if
	//  the item is copied to the clipboard.  This can happen automatically
	//  through the OLE callback OnGetClipboardData.  A good default for
	//  the embedded item is simply to delegate to the document's Serialize
	//  function.  If you support links, then you will want to serialize
	//  just a portion of the document.

	if (!IsLinkedItem())
	{
		CAutoServerDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pDoc->Serialize(ar);
	}
}

BOOL CAutoServerSrvrItem::OnGetExtent(DVASPECT dwDrawAspect, CSize& rSize)
{
	// Most applications, like this one, only handle drawing the content
	//  aspect of the item.  If you wish to support other aspects, such
	//  as DVASPECT_THUMBNAIL (by overriding OnDrawEx), then this
	//  implementation of OnGetExtent should be modified to handle the
	//  additional aspect(s).

	if (dwDrawAspect != DVASPECT_CONTENT)
		return COleServerItem::OnGetExtent(dwDrawAspect, rSize);

	// CAutoServerSrvrItem::OnGetExtent is called to get the extent in
	//  HIMETRIC units of the entire item.  The default implementation
	//  here simply returns a hard-coded number of units.

	CAutoServerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: replace this arbitrary size

	rSize = CSize(3000, 3000);   // 3000 x 3000 HIMETRIC units

	return TRUE;
}

BOOL CAutoServerSrvrItem::OnDraw(CDC* pDC, CSize& rSize)
{
	// Remove this if you use rSize
	UNREFERENCED_PARAMETER(rSize);

	CAutoServerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: set mapping mode and extent
	//  (The extent is usually the same as the size returned from OnGetExtent)
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowOrg(0,0);
	pDC->SetWindowExt(3000, 3000);

	// TODO: add drawing code here.  Optionally, fill in the HIMETRIC extent.
	//  All drawing takes place in the metafile device context (pDC).

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CAutoServerSrvrItem diagnostics

#ifdef _DEBUG
void CAutoServerSrvrItem::AssertValid() const
{
	COleServerItem::AssertValid();
}

void CAutoServerSrvrItem::Dump(CDumpContext& dc) const
{
	COleServerItem::Dump(dc);
}
#endif

/////////////////////////////////////////////////////////////////////////////
