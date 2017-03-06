
// chartLibDlg.h : header file
//

#pragma once
#include "OpenGLControl.h"

//17.03.03 by dhSeo for debug
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

// CchartLibDlg dialog
class CchartLibDlg : public CDialog
{
// Construction
public:
	CchartLibDlg(CWnd* pParent = NULL);	// standard constructor
// Dialog Data
	enum { IDD = IDD_CHARTLIB_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

private:
	COpenGLControl m_oglWindow;

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};


interface I_dataAdaptor
{


};
