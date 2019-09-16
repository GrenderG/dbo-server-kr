#pragma once

#include "Table.h"
#include "Vector.h"

const DWORD		DBO_MAX_LENGTH_LAND_MARK_NAME = 40;
const DWORD		DBO_MAX_LENGTH_LAND_MARK_ICON_NAME = 32;

#pragma pack(push, 4)
struct sLAND_MARK_TBLDAT : public sTBLDAT
{
public:
	
	WCHAR			wszNameText[ DBO_MAX_LENGTH_LAND_MARK_NAME + 1 ];
	TBLIDX			LandmarkName;
	BYTE			byLandmarkType;
	bool			bValidityAble;
	BYTE			byLandmarkBitflag;
	BYTE			byLandmarkDisplayBitFlag;
	CNtlVector		LandmarkLoc;
	TBLIDX			LinkMapIdx;
	WORD			wLinkWarfogIdx;
	WCHAR			wszIconName[ DBO_MAX_LENGTH_LAND_MARK_ICON_NAME + 1 ];
	BYTE			byIconSize;
	TBLIDX			Note;

protected:

	virtual int GetDataSize()
	{
		return sizeof(*this) - sizeof(void*);
	}
};
#pragma pack(pop)

class CLandMarkTable : public CTable
{
public:
	CLandMarkTable(void);
	virtual ~CLandMarkTable(void);

	bool Create(DWORD dwCodePage);
	void Destroy();

protected:
	void Init();

public:
	sTBLDAT* FindData(TBLIDX tblidx);

protected:
	WCHAR** GetSheetListInWChar() { return &(CLandMarkTable::m_pwszSheetList[0]); }
	void* AllocNewTable(WCHAR* pwszSheetName, DWORD dwCodePage);
	bool DeallocNewTable(void* pvTable, WCHAR* pwszSheetName);
	bool AddTable(void * pvTable, bool bReload);
	bool SetTableData(void* pvTable, WCHAR* pwszSheetName, std::wstring* pstrDataName, BSTR bstrData);


public:

	virtual bool				LoadFromBinary(CNtlSerializer& serializer, bool bReload);

	virtual bool				SaveToBinary(CNtlSerializer& serializer);


private:
	static WCHAR* m_pwszSheetList[];
};