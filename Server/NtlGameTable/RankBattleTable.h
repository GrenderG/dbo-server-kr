//***********************************************************************************
//
//	File		:	TimeQuestTable.h
//
//	Begin		:	2007-06-07
//
//	Copyright	:	�� NTL-Inc Co., Ltd
//
//	Author		:	Ju-hyung Lee ( niam@ntl-inc.com )
//
//	Desc		:	
//
//***********************************************************************************

#pragma once


#include "table.h"

#include "NtlRankBattle.h"


//-----------------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------------
#pragma pack(push, 4)
struct sRANKBATTLE_TBLDAT : public sTBLDAT
{
public:

	sRANKBATTLE_TBLDAT( void ) { }

public:

	BYTE			byRuleType;				// ��� �� eGAMERULE_TYPE
	BYTE			byBattleMode;			// ���� Ÿ�� 0 = ����, 1 = party
	WCHAR			wszName[ DBO_RANKBATTLE_NAME_LENGTH + 1 ];
	TBLIDX			worldTblidx;			// World_Table Index
	TBLIDX			needItemTblidx;			// �����ϱ� ���� �ʿ��� ������
	DWORD			dwZenny;				// �����ϱ� ���� �ʿ��� ����
	BYTE			byMinLevel;				// �ּ� ����
	BYTE			byMaxLevel;				// �ִ� ����
	BYTE			byBattleCount;			// ���� Ƚ��

	DWORD			dwWaitTime;				// ���� ��� �ð�
	DWORD			dwDirectionTime;		// ���� �ð�
	DWORD			dwMatchReadyTime;		// ��� �غ� �ð�
	DWORD			dwStageReadyTime;		// �������� �غ� �ð�
	DWORD			dwStageRunTime;			// �������� ��� �ð�
	DWORD			dwStageFinishTime;		// �������� ���� �ð�
	DWORD			dwMatchFinishTime;		// ��� ���� �ð�
	DWORD			dwBossDirectionTime;	// ������ ����
	DWORD			dwBossKillTime;			// ������ ��� �ð�
	DWORD			dwBossEndingTime;		// ���� �ð�
	DWORD			dwEndTime;				// ����

	char			chScoreKO;				// KO�½� ����
	char			chScoreOutOfArea;		// ��ܽ½� ����
	char			chScorePointWin;		// �����½� ����
	char			chScoreDraw;			// ������� ����
	char			chScoreLose;			// �й�� ����

	char			chResultExcellent;		// ��� ��� ���,  >= chResultExcellent
	char			chResultGreate;			// ��� ��� ���,  < chResultExcellent, >= chResultGreate
	char			chResultGood;			// ��� ��� ���,  < chResultGreate, >= chResultDraw
	char			chResultDraw;			// ��� ��� ���,  == chResultDraw
	char			chResultLose;			// ��� ��� ���,  == chResultLost

	char			chBonusPerfectWinner;	// �Ͻ����� �������� ��� �߰� ����
	char			chBonusNormalWinner;	// �Ϲ����� ������ �������� �߰� ����

protected:

	virtual int GetDataSize()
	{
		return sizeof(*this) - sizeof(void*);
	}
};
#pragma pack(pop)

//-----------------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------------
class CRankBattleTable : public CTable
{
public:

	CRankBattleTable( void );

	virtual ~CRankBattleTable( void );

public:

	virtual bool			LoadFromBinary(CNtlSerializer& serializer, bool bReload);

	virtual bool			SaveToBinary(CNtlSerializer& serializer);

public:

	bool					Create( DWORD dwCodePage );

	void					Destroy( void );

public:

	sTBLDAT*				FindData(TBLIDX tblidx); 

protected:

	void					Init( void );

	WCHAR**					GetSheetListInWChar( void ) { return &m_pwszSheetList[0]; }

	void*					AllocNewTable( WCHAR* pwszSheetName, DWORD dwCodePage );

	bool					DeallocNewTable( void* pvTable, WCHAR* pwszSheetName );

	bool					AddTable( void* pvTable, bool bReload );

	bool					SetTableData( void* pvTable, WCHAR* pwszSheetName, std::wstring* pstrDataName, BSTR bstrData );


protected:

	static WCHAR*			m_pwszSheetList[];

};
