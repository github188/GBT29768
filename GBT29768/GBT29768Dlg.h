
// GBT29768Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CGBT29768Dlg �Ի���
class CGBT29768Dlg : public CDialogEx
{
// ����
public:
	CGBT29768Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_GBT29768_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP();
	afx_msg LRESULT OnListShow(WPARAM wParam,LPARAM lParam);
public:
	CListBox m_List;
	afx_msg void OnBnClickedConnect();
	afx_msg void OnBnClickedAuthstart();
	u32 m_AKX;
	CString csRK1;
	CString csRK2;
	CString csRK3;
	CString csRK4;
	int RKorAK;
};
