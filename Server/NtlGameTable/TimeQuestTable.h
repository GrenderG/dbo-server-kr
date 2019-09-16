//***********************************************************************************
//
//	File		:	TimeQuestTable.h
//
//	Begin		:	2007-06-01
//
//	Copyright	:	�� NTL-Inc Co., Ltd
//
//	Author		:	Hyun Woo, Koo   ( zeroera@ntl-inc.com )
//
//	Desc		:	
//
//***********************************************************************************

#pragma once

#include "table.h"

#include "NtlTimeQuest.h"

#include "Vector.h"
#include "SharedDef.h"

const DWORD		DBO_MAX_LENGTH_PROLOGUE_DIRECTION = 32;
const DWORD		DBO_MAX_LENGTH_BGM_STRING = 32;
//-----------------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------------
#pragma pack(push, 4)
struct sTIMEQUEST_DATASET
{
	TBLIDX			nameTblidx; // ����Ʈ ���� �ؽ�Ʈ �ε���
	TBLIDX			questStringTblidx; // ����Ʈ ���� �ؽ�Ʈ �ε���
	TBLIDX			worldTblidx; // ���� �ε���
	TBLIDX			scriptTblidx; // ��ũ��Ʈ �ε���

	BYTE			byMinMemberCount; // �ּ� �ο�
	BYTE			byMaxMemberCount; // �ִ� �ο�
	BYTE			byMinMemberLevel; // �ּ� ����
	BYTE			byMaxMemberLevel; // �ִ� ����

	DWORD			dwLimitTime; // ���ѽð�
	DWORD			dwNeedZenny; // �����
	TBLIDX			needItemTblidx; // �ʿ� ������ �ε���
	BYTE			byMaxKillCount; // �ִ� ų ī��Ʈ

	BYTE			byWorldCount;		// world count

	TBLIDX			dayRecordRewardTblidx;
	TBLIDX			bestRecordRewardTblidx;
	
	
};
#pragma pack(pop)

#pragma pack(push, 4)
struct sTIMEQUEST_TBLDAT : public sTBLDAT
{
public:

	sTIMEQUEST_TBLDAT( void ) { }

public:

	BYTE			byTimeQuestType; // Ÿ������Ʈ Ÿ�� ( eTIMEQUEST_TYPE )
	BYTE			byDifficultyFlag; // ���̵� �÷���( eTIMEQUEST_DIFFICULTY_FLAG )
	DWORD			dwStartTime; // ���۽ð� ( �Ϸ� 00:00 �� �������� ���۵Ǵ� �д����� �ִ´� )
	TBLIDX			startCharacterDirection;
	TBLIDX			startObjectIndex;
	TBLIDX			startTriggerId;
	TBLIDX			arriveCharacterDirection;
	TBLIDX			arriveObjectIndex;
	TBLIDX			arriveTriggerId;
	TBLIDX			leaveCharacterDirection;	
	TBLIDX			leaveObjectIndex;	
	TBLIDX			leaveTriggerId;
	TBLIDX			dayRecordMailTblidx;
	TBLIDX			bestRecordMailTblidx;
	BYTE			byResetTime;				// ���� ��Ű�� �ð� 0~23 ���
	WCHAR			wszPrologueDirection[ DBO_MAX_LENGTH_PROLOGUE_DIRECTION + 1 ];
	sTIMEQUEST_DATASET sTimeQuestDataset[ MAX_TIMEQUEST_DIFFICULTY ];
	TBLIDX			openCine;
	TBLIDX			Note;
	WCHAR			wszStageBgm1[ DBO_MAX_LENGTH_BGM_STRING + 1 ];
	WCHAR			wszStageBgm2[ DBO_MAX_LENGTH_BGM_STRING + 1 ];
	WCHAR			wszLastBgm[ DBO_MAX_LENGTH_BGM_STRING + 1 ];
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
class CTimeQuestTable : public CTable
{
public:

	CTimeQuestTable( void );

	virtual ~CTimeQuestTable( void );

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