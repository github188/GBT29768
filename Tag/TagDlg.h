
// TagDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CTagDlg �Ի���
class CTagDlg : public CDialogEx
{
// ����
public:
	CTagDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TAG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	u32 m_TID1;
	u32 m_TID2;
	afx_msg void OnBnClickedConnect();
	afx_msg LRESULT OnListShow(WPARAM wParam,LPARAM lParam);
	u32 m_AKX;
	int m_AuthMode;
	CListBox m_List;
	CString csAKS1;
	CString csAKS2;
	CString csAKS3;
	CString csAKS4;
	afx_msg void OnBnClickedSet();
};
