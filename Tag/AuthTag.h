#pragma once
#include <WinSock2.h>
#include "type.h"

#define SM7
#ifdef SM7
#define CryptLen	8
#define CryptKeyLen	16
#endif

class AuthTag
{
public:
	u32 TID[2];
	u16 RNt;
	u16 RNr;
	u16 THandle;
	u16 RKindex;
	u16 AKX;
	u32 AKS[4];
	u8 AuthMode;
	SOCKET ComSock;
	u16 SecParaTag[3];
	void response();
protected:
//	char recommand[100];
	char RecvCommand[100];
	int SwitchCommand();
	//��Ӧ��ȫ������ȡ
	void reGet_SecPara();
	//��Ӧ��������������
	void reReq_XAuth();
	//��Ӧ����������
	void reXAuth();
	//��Ӧ��������������
	void reGet_XAuth();
	//��Ӧ˫������������
	void reReq_XAuth_EX();
	//��Ӧ�����������
	void reReq_SAuth();
	//��Ӧ��������
	void reSAuth();
	//��Ӧ�����������
	void reGet_SAuth();
	//��Ӧ˫���������
	void reMul_Auth();
	void RDPF();
	void RDPT();
};
#define CRC				0xffff
#define On				0x5555