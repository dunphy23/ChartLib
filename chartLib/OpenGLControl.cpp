#include "StdAfx.h"
#include "OpenGLControl.h"


COpenGLControl::COpenGLControl(void)
{
	m_fPosX = 0.0f;  // X position of model in camera view
	m_fPosY = 0.0f;  // Y position of model in camera view
	m_fZoom = 10.0f; // Zoom on model in camera view
	m_fRotX = 0.0f;  // Rotation on model in camera view
	m_fRotY = 0.0f;  // Rotation on model in camera view
	m_bIsMaximized = false;

}

COpenGLControl::~COpenGLControl(void)
{
}

void COpenGLControl::oglCreate(CRect rect, CWnd *parent)
{
	CString className = AfxRegisterWndClass(CS_HREDRAW |
		CS_VREDRAW | CS_OWNDC, NULL, static_cast<HBRUSH>(GetStockObject(BLACK_BRUSH), NULL));

	CreateEx(0, className, _T("OpenGL"), WS_CHILD | WS_VISIBLE | 
		WS_CLIPSIBLINGS | WS_CLIPCHILDREN, rect, parent, 0);

	m_oldWindow = rect;
	m_originalRect = rect;

	hWnd = parent;
	

	
	
}

BEGIN_MESSAGE_MAP(COpenGLControl, CWnd)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_SIZE()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

void COpenGLControl::OnPaint()
{
//	CPaintDC dc(this); // device context for painting
	
	ValidateRect(NULL);

}

void DrawMyShape(CDC *paramDC, CPoint point)
{
	//CPen객체를 굵기 1의 빨간색 실선으로 생성합니다.
	CPen redPen(PS_SOLID, 1, RGB(255, 0, 0));

	//이 전 색상을 저장하기 위해 CPen의 포인터 객체를 생성합니다.
	//CDC의 포인터에 접근하여 SelectObject() 함수를 호출하고,
	//인자값으로 redPen변수의 주소를 넘깁니다.
	//현재 선의 색상은 빨간색으로 지정되었고, oldPen에는 이 전 색상이 저장되어있습니다.
	CPen *oldPen = paramDC->SelectObject(&redPen);

	//사각형의 선부분을 빨간색으로 지정하며 그려낸다.
	paramDC->Rectangle(point.x, point.y, point.x + 20, point.y + 20);
	//CDC의 포인터에 접근하여 oldPen의 주소를 넘깁니다.
	//이 전의 색상으로 돌려놓는 작업입니다.
	paramDC->SelectObject(oldPen);
}//DrawMyShape


int COpenGLControl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	///////////////////////////////////////////////////////////
	// Initial Setup:   
	//    
	static PIXELFORMATDESCRIPTOR pfd =    
	{        
		sizeof(PIXELFORMATDESCRIPTOR),       
		1,       
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,       
		PFD_TYPE_RGBA,       
		32,    // bit depth       
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,       
		16,    // z-buffer depth       
		0, 0, 0, 0, 0, 0, 0,    
	};     
	// Get device context only once.    
	hdc = GetDC()->m_hDC;    
	// Pixel format.    
	m_nPixelFormat = ChoosePixelFormat(hdc, &pfd);    
	SetPixelFormat(hdc, m_nPixelFormat, &pfd);     
	// Create the OpenGL Rendering Context.    
	hrc = wglCreateContext(hdc);    
	wglMakeCurrent(hdc, hrc);     
	// Basic Setup:    
	//    
	// Set color to use when clearing the background.    
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);    
	//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);    
	glClearDepth(1.0f);     
	// Turn on backface culling    
	glFrontFace(GL_CCW);    
	glCullFace(GL_BACK);     
	// Turn on depth testing    
	glEnable(GL_DEPTH_TEST);   
	glDepthFunc(GL_LEQUAL);   

	// Send draw request    
	OnDraw(NULL);
	///////////////////////////////////////////////

	return 0;
}

void COpenGLControl::OnDraw(CDC *pDC)
{
	//TODO
	//if the current view is perspective

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -m_fZoom);
	glTranslatef(m_fPosX, m_fPosY, 0.0f);
	glRotatef(m_fRotX, 1.0f, 0.0f, 0.0f);
	glRotatef(m_fRotY, 0.0f, 1.0f, 0.0f);

}

void COpenGLControl::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	switch(nIDEvent)
	{
	case 1:
		//clear color and depth buffer bits
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Draw OpenGL scene
		oglDrawScene();

		//Swap buffers
		SwapBuffers(hdc);
		break;
	default:
		break;
	}

	CWnd::OnTimer(nIDEvent);
}


void COpenGLControl::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	if (0 >= cx || 0 >= cy || nType == SIZE_MINIMIZED) return;       

	printf("cx : %d, cy : %d\n", cx,cy);
	// Map the OpenGL coordinates.      
	glViewport(0, 0, cx, cy);       
	// Projection view      
	glMatrixMode(GL_PROJECTION);       
	glLoadIdentity();       
	// Set our current view perspective      
	gluPerspective(35.0f, (float)cx / (float)cy, 0.01f, 2000.0f);       
	// Model view      
	glMatrixMode(GL_MODELVIEW);

}

void COpenGLControl::oglDrawScene(void)
{  
	//DrawMyShape(this->GetDC(), *(new CPoint(359/2,267/2)));
	

	// Wireframe Mode    
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);      
	glBegin(GL_QUADS);       
	// Top Side       
	glVertex3f( 1.0f, 1.0f,  1.0f);       
	glVertex3f( 1.0f, 1.0f, -1.0f);       
	glVertex3f(-1.0f, 1.0f, -1.0f);       
	glVertex3f(-1.0f, 1.0f,  1.0f);        
	// Bottom Side       
	glVertex3f(-1.0f, -1.0f, -1.0f);       
	glVertex3f( 1.0f, -1.0f, -1.0f);       
	glVertex3f( 1.0f, -1.0f,  1.0f);       
	glVertex3f(-1.0f, -1.0f,  1.0f);         
	// Front Side       
	glVertex3f( 1.0f,  1.0f, 1.0f);       
	glVertex3f(-1.0f,  1.0f, 1.0f);       
	glVertex3f(-1.0f, -1.0f, 1.0f);       
	glVertex3f( 1.0f, -1.0f, 1.0f);         
	// Back Side       
	glVertex3f(-1.0f, -1.0f, -1.0f);       
	glVertex3f(-1.0f,  1.0f, -1.0f);       
	glVertex3f( 1.0f,  1.0f, -1.0f);       
	glVertex3f( 1.0f, -1.0f, -1.0f);       
	// Left Side       
	glVertex3f(-1.0f, -1.0f, -1.0f);       
	glVertex3f(-1.0f, -1.0f,  1.0f);       
	glVertex3f(-1.0f,  1.0f,  1.0f);       
	glVertex3f(-1.0f,  1.0f, -1.0f);        
	// Right Side       
	glVertex3f( 1.0f,  1.0f,  1.0f);      
	glVertex3f( 1.0f, -1.0f,  1.0f);      
	glVertex3f( 1.0f, -1.0f, -1.0f);      
	glVertex3f( 1.0f,  1.0f, -1.0f);     
	glEnd();

}

//마우스 움직일때 발생하는 이벤트
//조건문에서 MK_LBUTTON 등으로 플래그 조건을 통해
//클릭 된 상태로 움직이는지(드래그)를 판단하여 동작하도록 구성되있음
void COpenGLControl::OnMouseMove(UINT nFlags, CPoint point)
{
	//printf("gl move!\n");
	// TODO: Add your message handler code here and/or call default
	int diffX = (int)(point.x - m_fLastX);
	int diffY = (int)(point.y - m_fLastY);
	m_fLastX  = (float)point.x;
	m_fLastY  = (float)point.y;
	// Left mouse button
	if (nFlags & MK_LBUTTON)
	{
		m_fRotX += (float)0.5f * diffY;
		if ((m_fRotX > 360.0f) || (m_fRotX < -360.0f))
		{
			m_fRotX = 0.0f;
		}
		m_fRotY += (float)0.5f * diffX;
		if ((m_fRotY > 360.0f) || (m_fRotY < -360.0f))
		{
			m_fRotY = 0.0f;
		}
	}
	// Right mouse button
	else if (nFlags & MK_RBUTTON)
	{
		m_fZoom -= (float)0.1f * diffY;
	}
	// Middle mouse button
	else if (nFlags & MK_MBUTTON)
	{
		m_fPosX += (float)0.05f * diffX;
		m_fPosY -= (float)0.05f * diffY;
	}
	OnDraw(NULL);


	CWnd::OnMouseMove(nFlags, point);
}
