#pragma once
#include "afxwin.h"

#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>

class COpenGLControl : public CWnd
{
private:       
	// Window information       
	CWnd    *hWnd;       
	HDC     hdc;       
	HGLRC   hrc;       
	int     m_nPixelFormat;       
	CRect   m_rect;       
	CRect   m_oldWindow;       
	CRect   m_originalRect;

public:
	COpenGLControl(void);
	~COpenGLControl(void);
	// Timer         
	UINT_PTR m_unpTimer;    

	void oglCreate(CRect rect, CWnd *parent);

	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDraw(CDC *pDC);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
