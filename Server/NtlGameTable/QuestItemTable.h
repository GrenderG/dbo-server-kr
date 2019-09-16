#pragma once
#include "table.h"

const DWORD		DBO_MAX_LENGTH_QUEST_ITEM_ICON_NAME = 32;

//-----------------------------------------------------------------------------------
// ����Ʈ ������ ��� Ÿ��
//-----------------------------------------------------------------------------------
enum eQUEST_ITEM_FUNC_TYPE
{
	QUEST_ITEM_FUNC_TYPE_DEL_FORBIDDEN,

};

//-----------------------------------------------------------------------------------
// ����Ʈ ������ ��� Ÿ�� �÷���
//-----------------------------------------------------------------------------------
enum eQUEST_ITEM_FUNC_BIT_FLAG
{
	QUEST_ITEM_FUNC_BIT_FLAG_DEL_FORBIDDEN  = 0x01 << QUEST_ITEM_FUNC_TYPE_DEL_FORBIDDEN,

};

// Object
#pragma pack(push, 4)
struct sQUESTITEM_TBLDAT : public sTBLDAT
{
public:
	TBLIDX			ItemName;		// ���ӻ� ǥ�õ� Item�� �̸�
//	std::string		strIconName;	// Icon�� File �̸�
	char			szIconName[ DBO_MAX_LENGTH_QUEST_ITEM_ICON_NAME + 1 ];		// Icon�� File �̸�
	TBLIDX			Note;		// Quest item�� ����
	BYTE			byFunctionBitFlag;
protected:

	virtual int GetDataSize()
	{
		return sizeof(*this) - sizeof(void*);
	}
};
#pragma pack(pop)

class CQuestItemTable : public CTable
{
// Member variables
protected:
	static WCHAR* m_pwszSheetList[];

// Constructions and Destructions
public:
	CQuestItemTable( void );
	virtual ~CQuestItemTable( void );

// Methods
public:
	bool			Create( DWORD dwCodePage );
	void			Destroy( void );

	sTBLDAT*		FindData( TBLIDX tblidx ); 

// Implementations
protected:
	void			Init( void );
	WCHAR**			GetSheetListInWChar( void ) { return &m_pwszSheetList[0]; }
	void*			AllocNewTable( WCHAR* pwszSheetName, DWORD dwCodePage );
	bool			DeallocNewTable( void* pvTable, WCHAR* pwszSheetName );
	bool			AddTable( void* pvTable, bool bReload );
	bool			SetTableData( void* pvTable, WCHAR* pwszSheetName, std::wstring* pstrDataName, BSTR bstrData );


public:

	virtual bool				LoadFromBinary(CNtlSerializer& serializer, bool bReload);

	virtual bool				SaveToBinary(CNtlSerializer& serializer);
};
