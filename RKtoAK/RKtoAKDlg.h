
// RKtoAKDlg.h : ͷ�ļ�
//

#pragma once


// CRKtoAKDlg �Ի���
class CRKtoAKDlg : public CDialogEx
{
// ����
public:
	CRKtoAKDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_RKTOAK_DIALOG };

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
	afx_msg void OnBnClickedButton1();
	CString csRK1;
	CString csRK2;
	CString csRK3;
	CString csRK4;
};
