#pragma once
#include "table.h"
#include "Vector.h"
#include "Quest.h"

#include "SharedDef.h"

const DWORD		DBO_MAX_LENGTH_CLICK_SOUND_NAME = 64;
// Object
#pragma pack(push, 4)
struct sOBJECT_TBLDAT : public sTBLDAT
{
public:
	sOBJECT_TBLDAT( void )
	{
		byStateType = INVALID_TOBJECT_STATE_TYPE;
		byDefMainState = TOBJECT_STATE_NONE;
		byDefSubState = 0;
		memset( abyState, 0xff, sizeof( abyState ) );
		contentsTblidx = INVALID_TBLIDX;
	}

public:

	DWORD			dwName;
	WORD			wFunction;

	CNtlVector		vMin;
	CNtlVector		vMax;
	CNtlVector		vLoc;
	CNtlVector		vDir;

	// Object state ���� ������
	BYTE			byStateType;
	BYTE			byDefMainState;
	BYTE			byDefSubState;
	BYTE			abyState[DBO_MAX_OBJECT_STATE][DBO_MAX_OBJECT_STATE_ANIMATION];
	char			achClickSound[DBO_MAX_OBJECT_STATE][DBO_MAX_LENGTH_CLICK_SOUND_NAME];
	// �ε� ����Ÿ
	char			szModelName[ NTL_MAX_LENGTH_MODEL_NAME + 1 ];

	// �ε��� ���Ǵ� ������
	float			fRadius; // �ε��ÿ� ����ϴ� ����
	DWORD			dwSequence; // �ε��ÿ� ����ϴ� ���� �� ( Ŭ���̾�Ʈ�� ������ �ڵ鰪 ������ ��� )

	TBLIDX			contentsTblidx; // ������Ʈ���� ���� �ִ� ��ũ ���̺� �ε���
	TBLIDX			objectDirectionIndex;
	BYTE			byBoundaryDistance;
	QUESTID			minQuestId;
	QUESTID			maxQuestId;
public:

	virtual int GetDataSize()
	{
		return sizeof(*this) - sizeof(void*);
	}
};
#pragma pack(pop)

class CObjectTable : public CTable
{
// Member variables
protected:
	static WCHAR* m_pwszSheetList[];

// Constructions and Destructions
public:
	CObjectTable( void );
	virtual ~CObjectTable( void );

// Methods
public:
	bool			Create( DWORD dwCodePage );
	void			Destroy( void );

	sTBLDAT*		FindData(TBLIDX tblidx); 

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

private:

	DWORD			m_dwObjectSequence;
};