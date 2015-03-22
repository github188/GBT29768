
// TagDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Tag.h"
#include "TagDlg.h"
#include "SOCK.h"
#include "afxdialogex.h"
#include "type.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

DWORD WINAPI TagConThread(LPVOID lpParameter)
{
	HWND hParentWnd=HWND(lpParameter);
	SendMessage(hParentWnd,WM_ListShow,IDS_Connecting,0);
	authtag.ComSock=ComStart();
	SendMessage(hParentWnd,WM_ListShow,IDS_Connected,0);
	return 0;
}
// CTagDlg �Ի���
DWORD WINAPI TagAuthThread(LPVOID lpParameter)
{
	SendMessage(hParentWnd,WM_ListShow,IDS_Waiting,0);
	authtag.response();
	return 0;
}



CTagDlg::CTagDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTagDlg::IDD, pParent)
	, m_AuthMode(0)
	, csAKS1(_T(""))
	, csAKS2(_T(""))
	, csAKS3(_T(""))
	, csAKS4(_T(""))
	, csTID1(_T(""))
	, csTID2(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTagDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//	DDX_Text(pDX, IDC_TID1, m_TID1);
	//	DDX_Text(pDX, IDC_TID2, m_TID2);
	DDX_Text(pDX, IDC_AK, m_AKX);
	DDX_Radio(pDX, IDC_RADIO1, m_AuthMode);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Text(pDX, IDC_EDITAKS1, csAKS1);
	DDX_Text(pDX, IDC_EDITAKS2, csAKS2);
	DDX_Text(pDX, IDC_EDITAKS3, csAKS3);
	DDX_Text(pDX, IDC_EDITAKS4, csAKS4);
	DDX_Text(pDX, IDC_TID1, csTID1);
	DDX_Text(pDX, IDC_TID2, csTID2);
}

BEGIN_MESSAGE_MAP(CTagDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_ListShow,&CTagDlg::OnListShow)
	ON_BN_CLICKED(IDC_Connect, &CTagDlg::OnBnClickedConnect)
	ON_BN_CLICKED(IDC_Set, &CTagDlg::OnBnClickedSet)
END_MESSAGE_MAP()


// CTagDlg ��Ϣ�������

BOOL CTagDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_TID1=0;
	m_TID2=0;
	csTID1.Format("12345678");
	csTID2.Format("90abcdef");
	csAKS1.Format("511ab853");
	csAKS2.Format("b231a79a");
	csAKS3.Format("36508464");
	csAKS4.Format("e1858e50");
	m_AKX=0;
	UpdateData(FALSE);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTagDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CTagDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTagDlg::OnBnClickedConnect()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	hParentWnd=m_hWnd;
	HANDLE hthread1;
	hthread1=CreateThread(NULL,0,TagConThread,this->m_hWnd,0,NULL);
	CloseHandle(hthread1);
}
void CTagDlg::OnBnClickedSet()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	//	authtag.TID[0]=m_TID1;
	//	authtag.TID[1]=m_TID2;
	char *cTID1=(LPSTR)(LPCTSTR)csTID1;
	char *cTID2=(LPSTR)(LPCTSTR)csTID2;
	authtag.TID[0]=strtoul(cTID1,NULL,16);
	authtag.TID[1]=strtoul(cTID2,NULL,16);
	authtag.AKX=m_AKX&0xffff;
	char * AKS1=(LPSTR)(LPCTSTR)csAKS1;
	char * AKS2=(LPSTR)(LPCTSTR)csAKS2;
	char * AKS3=(LPSTR)(LPCTSTR)csAKS3;
	char * AKS4=(LPSTR)(LPCTSTR)csAKS4;
	authtag.AKS[0]=strtoul(AKS1,NULL,16);
	authtag.AKS[1]=strtoul(AKS2,NULL,16);
	authtag.AKS[2]=strtoul(AKS3,NULL,16);
	authtag.AKS[3]=strtoul(AKS4,NULL,16);
	authtag.AuthMode=m_AuthMode+1;
	HANDLE hthread2;
	hthread2=CreateThread(NULL,0,TagAuthThread,this->m_hWnd,0,NULL);
	CloseHandle(hthread2);
}

afx_msg LRESULT CTagDlg::OnListShow(WPARAM wParam,LPARAM lParam)
{
	CString showstring;
	showstring.LoadString(wParam);
	m_List.InsertString(-1,showstring);
	return 1;
	/*
	switch (wParam)
	{
	case IDS_Connecting:
	showstring.LoadString(IDS_Connecting);
	m_List.InsertString(-1,showstring);
	return 1;
	break;
	case IDS_Connected:
	showstring.LoadString(IDS_Connected);
	m_List.InsertString(-1,showstring);
	return 1;
	break;
	case IDS_Waiting:
	showstring.LoadString(IDS_Waiting);
	m_List.InsertString(-1,showstring);
	return 1;
	break;
	case IDS_recvGet_SecPara:
	showstring.LoadString(IDS_recvGet_SecPara);
	m_List.InsertString(-1,showstring);
	return 1;
	break;
	case IDS_recvReq_XAuth:
	showstring.LoadString(IDS_recvReq_XAuth);
	m_List.InsertString(-1,showstring);
	return 1;
	break;
	case IDS_recvXAuth:
	showstring.LoadString(IDS_recvXAuth);
	m_List.InsertString(-1,showstring);
	return 1;
	break;
	case IDS_recvGet_XAuth:
	showstring.LoadString(IDS_recvGet_XAuth);
	m_List.InsertString(-1,showstring);
	return 1;
	break;
	case IDS_recvReq_XAuth_EX:
	showstring.LoadString(IDS_recvReq_XAuth_EX);
	m_List.InsertString(-1,showstring);
	return 1;
	break;
	case IDS_recvReq_SAuth:
	showstring.LoadString(IDS_recvReq_SAuth);
	m_List.InsertString(-1,showstring);
	return 1;
	break;
	case IDS_recvGet_SAuth:
	showstring.LoadString(IDS_recvGet_SAuth);
	m_List.InsertString(-1,showstring);
	return 1;
	break;
	case IDS_recvAuth_EX:
	showstring.LoadString(IDS_recvAuth_EX);
	m_List.InsertString(-1,showstring);
	return 1;
	break;
	case IDS_reGet_SecPara:
	showstring.LoadString(IDS_reGet_SecPara);
	m_List.InsertString(-1,showstring);
	return 1;
	break;
	case IDS_DisConnected:
	showstring.LoadString(IDS_DisConnected);
	m_List.InsertString(-1,showstring);
	return 1;
	break;
	case IDS_reReq_XAuth:
	showstring.LoadString(IDS_reReq_XAuth);
	m_List.InsertString(-1,showstring);
	return 1;
	break;
	case IDS_reXAuth:
	showstring.LoadString(IDS_reXAuth);
	m_List.InsertString(-1,showstring);
	return 1;
	break;
	case IDS_AuthSucceed:
	showstring.LoadString(IDS_AuthSucceed);
	m_List.InsertString(-1,showstring);
	return 1;
	break;
	case IDS_AuthFailed:
	showstring.LoadString(IDS_AuthFailed);
	m_List.InsertString(-1,showstring);
	return 1;
	break;
	case IDS_reGet_XAuth:
	showstring.LoadString(IDS_reGet_XAuth);
	m_List.InsertString(-1,showstring);
	return 1;
	break;
	default:
	return 0;
	break;
	}
	*/
}



