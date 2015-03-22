
// RKtoAKDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RKtoAK.h"
#include "RKtoAKDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRKtoAKDlg �Ի���



CRKtoAKDlg::CRKtoAKDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRKtoAKDlg::IDD, pParent)
	, RK1(_T(""))
	, RK2(_T(""))
	, RK3(_T(""))
	, RK4(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRKtoAKDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, csRK1);
	DDX_Text(pDX, IDC_EDIT2, csRK2);
	DDX_Text(pDX, IDC_EDIT3, csRK3);
	DDX_Text(pDX, IDC_EDIT4, csRK4);
}

BEGIN_MESSAGE_MAP(CRKtoAKDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CRKtoAKDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CRKtoAKDlg ��Ϣ�������

BOOL CRKtoAKDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CRKtoAKDlg::OnPaint()
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
HCURSOR CRKtoAKDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CRKtoAKDlg::OnBnClickedButton1()
{
	UpdateData(true);
	unsigned int RKS[4];

	char *RKS1=(LPSTR)(LPCTSTR)csRK1;
	char *RKS2=(LPSTR)(LPCTSTR)csRK2;
	char *RKS3=(LPSTR)(LPCTSTR)csRK3;
	char *RKS4=(LPSTR)(LPCTSTR)csRK4;
	RKS[0]=strtoul(RKS1,NULL,16);
	RKS[1]=strtoul(RKS2,NULL,16);
	RKS[2]=strtoul(RKS3,NULL,16);
	RKS[3]=strtoul(RKS4,NULL,16);



	UpdateData(false);
}
