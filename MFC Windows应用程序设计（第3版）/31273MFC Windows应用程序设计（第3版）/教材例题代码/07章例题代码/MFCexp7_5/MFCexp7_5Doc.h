// MFCexp7_5Doc.h : interface of the CMFCexp7_5Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCEXP7_5DOC_H__281E97BD_3B80_44B8_9D40_9F1A2A6D7198__INCLUDED_)
#define AFX_MFCEXP7_5DOC_H__281E97BD_3B80_44B8_9D40_9F1A2A6D7198__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFCexp7_5Doc : public CDocument
{
protected: // create from serialization only
	CMFCexp7_5Doc();
	DECLARE_DYNCREATE(CMFCexp7_5Doc)

// Attributes
public:

// Operations
public:
	CRect m_crlRect;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCexp7_5Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMFCexp7_5Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFCexp7_5Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCEXP7_5DOC_H__281E97BD_3B80_44B8_9D40_9F1A2A6D7198__INCLUDED_)
