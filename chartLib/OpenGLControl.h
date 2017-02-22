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
	// View information variables
	float  m_fLastX;
	float  m_fLastY;
	float  m_fPosX;
	float  m_fPosY;
	float  m_fZoom;
	float  m_fRotX;
	float  m_fRotY;
	bool  m_bIsMaximized;

	void oglCreate(CRect rect, CWnd *parent);

	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDraw(CDC *pDC);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	void oglDrawScene(void);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};
