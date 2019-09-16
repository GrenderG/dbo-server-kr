//***********************************************************************************
//
//	File		:	ExcellentDropTable.h
//
//	Begin		:	2007-07-20
//
//	Copyright	:	�� NTL-Inc Co., Ltd
//
//	Author		:	Doo  Sup, Chung   ( john@ntl-inc.com )
//
//	Desc		:	
//
//***********************************************************************************

#include "StdAfx.h"
#include "ExcellentDropTable.h"
#include "NtlDebug.h"
#include "NtlSerializer.h"

WCHAR* CExcellentDropTable::m_pwszSheetList[] =
{
	L"Table_Data_KOR",
	NULL
};

CExcellentDropTable::CExcellentDropTable(void)
{
	Init();
}

CExcellentDropTable::~CExcellentDropTable(void)
{
	Destroy();
}

bool CExcellentDropTable::Create(DWORD dwCodePage)
{
	return CTable::Create(dwCodePage);
}

void CExcellentDropTable::Destroy()
{
	CTable::Destroy();
}

void CExcellentDropTable::Init()
{
}

void* CExcellentDropTable::AllocNewTable(WCHAR* pwszSheetName, DWORD dwCodePage)
{
	if (0 == wcscmp(pwszSheetName, L"Table_Data_KOR"))
	{
		sEXCELLENT_DROP_TBLDAT* pDrop = new sEXCELLENT_DROP_TBLDAT;
		if (NULL == pDrop)
			return NULL;

		CPINFO cpInfo;
		if(false == GetCPInfo(dwCodePage, &cpInfo))
		{
			delete pDrop;
			return NULL;
		}

		m_dwCodePage = dwCodePage;
		return pDrop;
	}

	return NULL;
}

bool CExcellentDropTable::DeallocNewTable(void* pvTable, WCHAR* pwszSheetName)
{
	if (0 == wcscmp(pwszSheetName, L"Table_Data_KOR"))
	{
		sEXCELLENT_DROP_TBLDAT* pDrop = (sEXCELLENT_DROP_TBLDAT*)pvTable;
		if (FALSE != IsBadReadPtr(pDrop, sizeof(*pDrop)))
			return false;

		delete pDrop;

		return true;
	}

	return false;
}

bool CExcellentDropTable::AddTable(void * pvTable, bool bReload)
{
	sEXCELLENT_DROP_TBLDAT * pTbldat = (sEXCELLENT_DROP_TBLDAT*)pvTable;
	sEXCELLENT_DROP_TBLDAT * pExistTbldat = NULL;

	if( bReload )
	{
		pExistTbldat = (sEXCELLENT_DROP_TBLDAT*) FindData( pTbldat->tblidx );
		if( pExistTbldat )
		{
			CopyMemory( pTbldat, pExistTbldat, pTbldat->GetDataSize() );
			// return false for release reloaded table data
			return true; 
		}
	}

	if ( false == m_mapTableList.insert( std::map<TBLIDX, sTBLDAT*>::value_type(pTbldat->tblidx, pTbldat)).second )
	{
		CTable::CallErrorCallbackFunction(L"[File] : %s\r\n Table Tblidx[%u] is Duplicated ",m_wszXmlFileName, pTbldat->tblidx );
		_ASSERTE( 0 );
		return false;
	}

	return true;
}

bool CExcellentDropTable::SetTableData(void* pvTable, WCHAR* pwszSheetName, std::wstring* pstrDataName, BSTR bstrData)
{
	if (0 == wcscmp(pwszSheetName, L"Table_Data_KOR"))
	{
		sEXCELLENT_DROP_TBLDAT* pDrop = (sEXCELLENT_DROP_TBLDAT*)pvTable;

		if (0 == wcscmp(pstrDataName->c_str(), L"Tblidx"))
		{
			pDrop->tblidx = READ_DWORD(bstrData); 
		}
		else if ( 0 == wcsncmp(pstrDataName->c_str(), L"Item_Tblidx_", wcslen(L"Item_Tblidx_") ) )
		{
			bool bFound = false;

			WCHAR szBuffer[1024] = { 0x00, };
			for( int i = 0; i < NTL_MAX_EXCELLENT_DROP; i++ )
			{
				swprintf( szBuffer, 1024, L"Item_Tblidx_%d", i + 1 );

				if( 0 == wcscmp(pstrDataName->c_str(), szBuffer) )
				{
					pDrop->aItem_Tblidx[ i ] = READ_DWORD( bstrData );

					bFound = true;
					break;
				}
			}

			if( false == bFound )
			{
				CTable::CallErrorCallbackFunction(L"[File] : %s\n[Error] : Unknown field name found!(Field Name = %s)", m_wszXmlFileName, pstrDataName->c_str());
				return false;
			}
		}
		else if ( 0 == wcsncmp(pstrDataName->c_str(), L"Drop_Rate_", wcslen(L"Drop_Rate_") ) )
		{
			bool bFound = false;

			WCHAR szBuffer[1024] = { 0x00, };
			for( int i = 0; i < NTL_MAX_EXCELLENT_DROP; i++ )
			{
				swprintf( szBuffer, 1024, L"Drop_Rate_%d", i + 1 );

				if( 0 == wcscmp(pstrDataName->c_str(), szBuffer) )
				{
					pDrop->afDrop_Rate[ i ] = READ_FLOAT( bstrData, pstrDataName->c_str(), 0.0f );

					bFound = true;
					break;
				}
			}

			if( false == bFound )
			{
				CTable::CallErrorCallbackFunction(L"[File] : %s\n[Error] : Unknown field name found!(Field Name = %s)", m_wszXmlFileName, pstrDataName->c_str());
				return false;
			}
		}
		else
		{
			CTable::CallErrorCallbackFunction(L"[File] : %s\n[Error] : Unknown field name found!(Field Name = %s)", m_wszXmlFileName, pstrDataName->c_str());
			return false;
		}
	}
	else
	{
		return false;
	}

	return true;
}


sTBLDAT* CExcellentDropTable::FindData(TBLIDX tblidx)
{
	if (0 == tblidx)
		return NULL;

	TABLEIT iter;
	iter = m_mapTableList.find(tblidx);
	if (End() == iter)
		return NULL;

	return (sTBLDAT*)(iter->second); 
}

TBLIDX CExcellentDropTable::FindDropIndex( sEXCELLENT_DROP_TBLDAT* psTblData, BYTE byIndex)
{
	if ( NTL_MAX_EXCELLENT_DROP <= byIndex || 0 > byIndex )
		return INVALID_TBLIDX;

	return psTblData->aItem_Tblidx[byIndex];
}

float CExcellentDropTable::FindDropRate( sEXCELLENT_DROP_TBLDAT* psTblData, BYTE byIndex)
{
	if ( NTL_MAX_EXCELLENT_DROP <= byIndex || 0 > byIndex )
		return 0.0f;

	return psTblData->afDrop_Rate[byIndex];
}

bool CExcellentDropTable::LoadFromBinary(CNtlSerializer& serializer, bool bReload)
{
	if( false == bReload )
	{
		Reset();
	}

	BYTE byMargin = 1;
	serializer >> byMargin;

	bool bLoop = true;
	do
	{
		sEXCELLENT_DROP_TBLDAT* pTableData = new sEXCELLENT_DROP_TBLDAT;
		if (NULL == pTableData)
		{
			//- yoshiki : To log system!
			Destroy();
			return false;
		}

		if (false == pTableData->LoadFromBinary(serializer))
		{
			delete pTableData;
			bLoop = false;
			break;
		}

		//  [4/26/2008 zeroera] : ���� : �����ϴ��� Load�� ���Ῡ�δ� File Loading���� �����Ѵ�
		if( false == AddTable(pTableData, bReload) )
		{
			delete pTableData;
		}

	} while (false != bLoop);

	return true;
}

bool CExcellentDropTable::SaveToBinary(CNtlSerializer& serializer)
{
	serializer.Refresh();

	BYTE byMargin = 1;
	serializer << byMargin;

	TABLE::iterator iter;
	for (iter = Begin() ; End() != iter ; iter++)
	{
		sEXCELLENT_DROP_TBLDAT* pTableData = (sEXCELLENT_DROP_TBLDAT*)(iter->second);

		pTableData->SaveToBinary(serializer);
	}

	return true;
}