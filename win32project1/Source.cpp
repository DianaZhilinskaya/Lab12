#include <afxwin.h>

class CMyMainWnd : public CFrameWnd{
public:
	CMyMainWnd(){ // конструктор
		Create(NULL, L"Lab 12");
		SetTimer(1, 3000, NULL);
		strcpy_s(str, "");
	}
	~CMyMainWnd(){
		KillTimer(1);
	}
	afx_msg void OnChar(UINT ch, UINT, UINT);
	afx_msg void OnLButtonDown(UINT, CPoint);
	afx_msg void OnRButtonDown(UINT flags, CPoint Loc);
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT);

	char str[5];
	UINT m_ch = 10;

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CMyMainWnd, CFrameWnd)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_CHAR()
	ON_WM_PAINT()
	ON_WM_TIMER()
END_MESSAGE_MAP()

class CMyApp : public CWinApp{
public:
	CMyApp(){}; 
	virtual BOOL InitInstance(){
		m_pMainWnd = new CMyMainWnd();
		m_pMainWnd->ShowWindow(SW_RESTORE);
		m_pMainWnd->UpdateWindow();

		return TRUE;
	}
};

CMyApp theApp;

void CMyMainWnd::OnChar(UINT ch, UINT, UINT)
{
	m_ch = 0;
	sprintf_s(str, "%c", ch);
	m_ch = ch;
	OnPaint();
	this->InvalidateRect(0);
}
void CMyMainWnd::OnLButtonDown(UINT, CPoint){
	m_ch = 10;
	OnPaint();
	this->InvalidateRect(0);
}

void CMyMainWnd::OnRButtonDown(UINT, CPoint loc)
{
	m_ch = 1;
	OnPaint();
	this->InvalidateRect(0);
}

void CMyMainWnd::OnPaint(){
	CPaintDC dc(this);
	CBrush* brush = new CBrush();
	CFont font;
	
	switch (m_ch)
	{
	case 1:
		font.CreateFont(15, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, 0, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_MODERN, L"");
		dc.SelectObject(&font);
		dc.SetTextColor(RGB(255, 0, 255));
		dc.TextOut(50, 50, "Test");
		break;
	case 2:
		font.CreateFont(25, 0, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, 0, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_ROMAN, L"");
		dc.SelectObject(&font);
		dc.SetTextColor(RGB(0, 0, 255));
		dc.TextOut(100, 100, "Test");
		break;
	case 3:
		font.CreateFont(40, 0, 0, 0, FW_LIGHT, FALSE, FALSE, FALSE, 0, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SCRIPT, L"");
		dc.SelectObject(&font);
		dc.SetTextColor(RGB(255, 0, 0));
		dc.TextOut(150, 150, "Test");
		break;
	case 4:
		font.CreateFont(50, 0, 0, 0, FW_DEMIBOLD, FALSE, FALSE, FALSE, 0, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, L"");
		dc.SelectObject(&font);
		dc.SetTextColor(RGB(0, 255, 255));
		dc.TextOut(200, 200, "Test");
		break;
	case 5:
		font.CreateFont(60, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, 0, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DECORATIVE, L"");
		dc.SelectObject(&font);
		dc.SetTextColor(RGB(255, 100, 200));
		dc.TextOut(250, 250, "Test");
		break;
	case 49:
		brush = new CBrush(RGB(255, 0, 0));
		dc.SelectObject(brush);
		dc.Ellipse(1, 1, 50, 50);
		break;
	case 50:
		brush = new CBrush(RGB(255, 0, 255));
		dc.SelectObject(brush);
		dc.Ellipse(60, 60, 100, 150);
		break;
	case 51:
		brush = new CBrush(RGB(0, 0, 255));
		dc.SelectObject(brush);
		dc.Rectangle(70, 70, 200, 100);
		break;
	case 52:
		brush = new CBrush(RGB(0, 255, 255));
		dc.SelectObject(brush);
		dc.Rectangle(100, 100, 200, 200);
		break;
	case 53:
		brush = new CBrush(RGB(0, 100, 255));
		dc.SelectObject(brush);
		dc.Chord(50, 50, 200, 200, 200, 0, 0, 0);
		break;
	case 54:
		brush = new CBrush(RGB(100, 255, 255));
		dc.SelectObject(brush);
		CRect rectClient;
		GetClientRect(rectClient);
		dc.Pie(rectClient, CPoint(100, 100), CPoint(200, 200));
		break;
	}
	
	font.DeleteObject();
	brush->DeleteObject();

}
void CMyMainWnd::OnTimer(UINT nIDEvent){
	if (m_ch > 5) return;
	OnPaint();
	this->InvalidateRect(0);
	m_ch++;
}
