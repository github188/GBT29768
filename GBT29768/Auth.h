#pragma once
#include <WinSock2.h>
#include "type.h"

#define Tag2ReaderX 1
#define Tag2ReaderS 2
#define Reader2TagX 3
#define Reader2TagS 4
#define ExX	5
#define ExS 6
#define SecFunErr 15

#define SM7
#ifdef SM7
#define CryptLen	8
#define CryptKeyLen	16
#endif

class Auth
{
public:
	u32 TID[2];
	u16 THandle;
	u16 RNr;
	u16 RNt;
	u16 AKX;
	u32 RKS[4];
	u32 AKS[4];
	u32 SK[4];
	bool AKSgeted;
	SecPara secpara;
//	HWND hParentWnd;
	SOCKET ComSock;
	char RecvResponse[100];

	//��ȫ������ȡ����
	void Get_SecPara();
	//ѡ���������
	void selectAuthMode();

protected:
	bool TagPassed;
	//��ǩ�Զ�д��������
	void fnTag2ReaderX();
	//��ǩ�Զ�д���ԳƼ���
	void fnTag2ReaderS();
	//��д���Ա�ǩ������
	void fnReader2TagX();
	//��д���Ա�ǩ�ԳƼ���
	void fnReader2TagS();
	//˫��������
	void fnExX();
	//˫��ԳƼ���
	void fnExS();
	//���ð�ȫ����
	void SetSecPara(u16 * secpa);
	//��������������
	void	Req_XAuth();
	//����������
	void	XAuth();
	//��������������
	void	Get_XAuth();
	//˫������������
	void	Req_XAuth_EX();
	//�����������
	void	Req_SAuth();
	//��������
	void	SAuth();
	//�����������
	void	Get_SAuth();
	//˫���������
	void	Mul_Auth();
	//�ȴ�RDP
	void	waitRDP();
};




#define CRC				0xffff
#define On				0x5555

#define CGet_SecPara	0xae
#define CReq_XAuth		0xb5
#define CXAuth			0xb6
#define CGet_XAuth		0xb7
#define CReq_XAuth_Ex	0xb8
#define CReq_SAuth		0xa0
#define CSAuth			0xb3
#define CGet_SAuth		0xac
#define CMul_Auth		0xa1
