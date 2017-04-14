// CntrItem.cpp : implementation of the CContainerAppCntrItem class
//

#include "stdafx.h"
#include "ContainerApp.h"

#include "ContainerAppDoc.h"
#include "ContainerAppView.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CContainerAppCntrItem implementation

IMPLEMENT_SERIAL(CContainerAppCntrItem, COleClientItem, 0)

CContainerAppCntrItem::CContainerAppCntrItem(CContainerAppDoc* pContainer)
	: COleClientItem(pContainer)
{
	// TODO: add one-time construction code here

	m_objectRect.SetRect(20, 20, 150, 150);
}

CContainerAppCntrItem::~CContainerAppCntrItem()
{
	// TODO: add cleanup code here
	
}

void CContainerAppCntrItem::OnChange(OLE_NOTIFICATION nCode, DWORD dwParam)
{
	ASSERT_VALID(this);

	COleClientItem::OnChange(nCode, dwParam);

	// When an item is being edited (either in-place or fully open)
	//  it sends OnChange notifications for changes in the state of the
	//  item or visual appearance of its content.

	// TODO: invalidate the item by calling UpdateAllViews
	//  (with hints appropriate to your application)

	GetDocument()->UpdateAllViews(NULL);
		// for now just update ALL views/no hints
}

BOOL CContainerAppCntrItem::OnChangeItemPosition(const CRect& rectPos)
{
	ASSERT_VALID(this);

	// During in-place activation CContainerAppCntrItem::OnChangeItemPosition
	//  is called by the server to change the position of the in-place
	//  window.  Usually, this is a result of the data in the server
	//  document changing such that the extent has changed or as a result
	//  of in-place resizing.
	//
	// The default here is to call the base class, which will call
	//  COleClientItem::SetItemRects to move the item
	//  to the new position.

	if (!COleClientItem::OnChangeItemPosition(rectPos))
		return FALSE;

	// TODO: update any cache you may have of the item's rectangle/extent

	m_objectRect = rectPos;
	CContainerAppDoc* pDoc = GetDocument();
	pDoc->SetModifiedFlag();
	pDoc->UpdateAllViews(NULL);

	return TRUE;
}

void CContainerAppCntrItem::OnGetItemPosition(CRect& rPosition)
{
	ASSERT_VALID(this);

	// During in-place activation, CContainerAppCntrItem::OnGetItemPosition
	//  will be called to determine the location of this item.  The default
	//  implementation created from AppWizard simply returns a hard-coded
	//  rectangle.  Usually, this rectangle would reflect the current
	//  position of the item relative to the view used for activation.
	//  You can obtain the view by calling CContainerAppCntrItem::GetActiveView.

	// TODO: return correct rectangle (in pixels) in rPosition

	rPosition = m_objectRect;
}

void CContainerAppCntrItem::OnActivate()
{
    // Allow only one inplace activate item per frame
    CContainerAppView* pView = GetActiveView();
    ASSERT_VALID(pView);
    COleClientItem* pItem = GetDocument()->GetInPlaceActiveItem(pView);
    if (pItem != NULL && pItem != this)
        pItem->Close();
    
    COleClientItem::OnActivate();
}

void CContainerAppCntrItem::OnDeactivateUI(BOOL bUndoable)
{
	COleClientItem::OnDeactivateUI(bUndoable);

    // Hide the object if it is not an outside-in object
    DWORD dwMisc = 0;
    m_lpObject->GetMiscStatus(GetDrawAspect(), &dwMisc);
    if (dwMisc & OLEMISC_INSIDEOUT)
        DoVerb(OLEIVERB_HIDE, NULL);
}

void CContainerAppCntrItem::Serialize(CArchive& ar)
{
	ASSERT_VALID(this);

	// Call base class first to read in COleClientItem data.
	// Since this sets up the m_pDocument pointer returned from
	//  CContainerAppCntrItem::GetDocument, it is a good idea to call
	//  the base class Serialize first.
	COleClientItem::Serialize(ar);

	// now store/retrieve data specific to CContainerAppCntrItem
	if (ar.IsStoring())
	{
		// TODO: add storing code here

		ar << m_objectRect;
	}
	else
	{
		// TODO: add loading code here

		ar >> m_objectRect;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CContainerAppCntrItem diagnostics

#ifdef _DEBUG
void CContainerAppCntrItem::AssertValid() const
{
	COleClientItem::AssertValid();
}

void CContainerAppCntrItem::Dump(CDumpContext& dc) const
{
	COleClientItem::Dump(dc);
}
#endif

/////////////////////////////////////////////////////////////////////////////
