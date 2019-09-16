//***********************************************************************************
//
//	File		:	CSkillTable.h
//
//	Begin		:	2006-03-31
//
//	Copyright	:	�� NTL-Inc Co., Ltd
//
//	Author		:	Doo Sup, Chung   ( john@ntl-inc.com )
//
//	Desc		:	
//
//***********************************************************************************

#pragma once

#include "Table.h"

#include "Vector.h"
#include "Skill.h"

const DWORD		DBO_MAX_LENGTH_SKILL_NAME_TEXT = 40;
const DWORD		DBO_MAX_LENGTH_SKILL_ICON_NAME = 32;

#pragma pack(push, 4)
struct sSKILL_TBLDAT : public sTBLDAT
{
	sSKILL_TBLDAT()
	{
		bValidity_Able = true;
	};

public:
	TBLIDX			Skill_Name;
	WCHAR			wszNameText[ DBO_MAX_LENGTH_SKILL_NAME_TEXT + 1 ];
	bool			bValidity_Able;

	DWORD			dwPC_Class_Bit_Flag;		// ePC_CLASS_FLAG
	BYTE			bySkill_Class;				// eSKILL_CLASS
	BYTE			bySkill_Type;				// eSKILL_TYPE
	BYTE			bySkill_Active_Type;
	BYTE			byBuff_Group;
	BYTE			bySlot_Index;
	BYTE			bySkill_Grade;
	WORD			wFunction_Bit_Flag;

	BYTE			byAppoint_Target;
	BYTE			byApply_Target;
	BYTE			byApply_Target_Max;
	BYTE			byApply_Range;
	BYTE			byApply_Area_Size_1;
	BYTE			byApply_Area_Size_2;
	TBLIDX			skill_Effect[NTL_MAX_EFFECT_IN_SKILL];
	BYTE			bySkill_Effect_Type[NTL_MAX_EFFECT_IN_SKILL];
	float			fSkill_Effect_Value[NTL_MAX_EFFECT_IN_SKILL];
	WORD			wAdditional_Aggro_Point;

	BYTE			abyRpEffect[DBO_MAX_RP_BONUS_COUNT_PER_SKILL];		// eDBO_RP_BONUS_TYPE
	DWORD			adwRpEffectValue[DBO_MAX_RP_BONUS_COUNT_PER_SKILL];

	BYTE			byRequire_Train_Level;
	DWORD			dwRequire_Zenny;
	WORD			wNext_Skill_Train_Exp;
	WORD			wRequireSP;
	bool			bSelfTrain;
	TBLIDX			uiRequire_Skill_Tblidx_Min_1;
	TBLIDX			uiRequire_Skill_Tblidx_Max_1;
	TBLIDX			uiRequire_Skill_Tblidx_Min_2;
	TBLIDX			uiRequire_Skill_Tblidx_Max_2;
	TBLIDX			Root_Skill;

	BYTE			byRequire_Epuip_Slot_Type;
	BYTE			byRequire_Item_Type;
//	std::string		 strIcon_Name;
	char			szIcon_Name[ DBO_MAX_LENGTH_SKILL_ICON_NAME + 1 ];
	WORD			wRequire_LP;
	WORD			wRequire_EP;
	BYTE			byRequire_RP_Ball;
	float			fCasting_Time;
	DWORD			dwCastingTimeInMilliSecs;
	WORD			wCool_Time;
	DWORD			dwCoolTimeInMilliSecs;
	WORD			wKeep_Time;
	DWORD			dwKeepTimeInMilliSecs;
	bool			bKeep_Effect;
	BYTE			byUse_Range_Min;
	float			fUse_Range_Min;
	BYTE			byUse_Range_Max;
	float			fUse_Range_Max;
	TBLIDX			Note;

	DWORD			dwNextSkillTblidx;
	bool			bDefaultDisplayOff;

	ANIMATIONID		wCasting_Animation_Start;
	ANIMATIONID		wCasting_Animation_Loop;
	ANIMATIONID		wAction_Animation_Index;
	ANIMATIONID		wAction_Loop_Animation_Index;
	ANIMATIONID		wAction_End_Animation_Index;
	bool			bDash_Able;

	DWORD			dwTransform_Use_Info_Bit_Flag;
	float			fSuccess_Rate;

	BYTE			byPC_Class_Change;

public:

	virtual int GetDataSize()
	{
		return sizeof(*this) - sizeof(void*);
	}
};
#pragma pack(pop)

enum eSKILL_FUNCTION
{
	SKILL_FUNCTION_VOLATILE_BUFF = 0,				// ������ �ÿ� ȿ���� ������� Buff
	SKILL_FUNCTION_ONLY_LOW_LP,						// ���� LP�� �ִ� LP�� 50% ������ ���� ��� ����
	SKILL_FUNCTION_IGNORE_AFFECT_TIME,				// Affecting time�� �ִϸ��̼ǿ� ���� ���� ������ 0���� ����
	SKILL_FUNCTION_OVERWRITE_IF_SAME_GROUP,			// Buff group�� ���� buff�� ������ �� �ֽ��� buff�� ������ ��ü
	SKILL_FUNCTION_STRONG_CASTING,					// ������ �޾Ƶ� Casting �ð��� �������� �ʴ� ��ų
	SKILL_FUNCTION_SPECIAL_COOL_TIME_RULE,			// Cooling time count�� ������ ���� ����
	SKILL_FUNCTION_SPECIAL_TARGET,					// ��ų ����� ������ �÷��̾�� ǥ��
	SKILL_FUNCTION_FORCED_KNOCKDOWN,				// Skill ability�� ���� ���� ������ knockdown �߻�
	SKILL_FUNCTION_CANT_BE_TARGETTED,				// Ÿ������ ������ �� ����
	SKILL_FUNCTION_APPLY_NOT_ME,					// ��ų ȿ���� ����Ǵ� ��� ���� �� �ڽ��� ������
	SKILL_FUNCTION_STOP_AUTO_ATTACK,				// ��ų ��� �� �ڵ� ���� ��带 ��
	SKILL_FUNCTION_SET_INVINCIBLE,					// ��ų�� ����ϴ� ���ȿ��� ���� ����
	SKILL_FUNCTION_FAINTING_AFTER_APPLYING,			// ��ų ȿ�� ���� �� �ǽ� ���°� �Ǵ� ��ų

	SKILL_FUNCTION_COUNT,

	SKILL_FUNCTION_FIRST = SKILL_FUNCTION_VOLATILE_BUFF,
	SKILL_FUNCTION_LAST = SKILL_FUNCTION_COUNT - 1
};

enum eSKILL_FUNCTION_FLAG
{
	SKILL_FUNCTION_FLAG_VOLATILE_BUFF					= 1 << SKILL_FUNCTION_VOLATILE_BUFF,
	SKILL_FUNCTION_FLAG_ONLY_LOW_LP						= 1 << SKILL_FUNCTION_ONLY_LOW_LP,
	SKILL_FUNCTION_FLAG_IGNORE_AFFECT_TIME				= 1 << SKILL_FUNCTION_IGNORE_AFFECT_TIME,
	SKILL_FUNCTION_FLAG_OVERWRITE_IF_SAME_GROUP			= 1 << SKILL_FUNCTION_OVERWRITE_IF_SAME_GROUP,
	SKILL_FUNCTION_FLAG_STRONG_CASTING					= 1 << SKILL_FUNCTION_STRONG_CASTING,
	SKILL_FUNCTION_FLAG_SPECIAL_COOL_TIME_RULE			= 1 << SKILL_FUNCTION_SPECIAL_COOL_TIME_RULE,
	SKILL_FUNCTION_FLAG_SPECIAL_TARGET					= 1 << SKILL_FUNCTION_SPECIAL_TARGET,
	SKILL_FUNCTION_FLAG_FORCED_KNOCKDOWN				= 1 << SKILL_FUNCTION_FORCED_KNOCKDOWN,
	SKILL_FUNCTION_FLAG_CANT_BE_TARGETTED				= 1 << SKILL_FUNCTION_CANT_BE_TARGETTED,
	SKILL_FUNCTION_FLAG_APPLY_NOT_ME					= 1 << SKILL_FUNCTION_APPLY_NOT_ME,
	SKILL_FUNCTION_FLAG_STOP_AUTO_ATTACK				= 1 << SKILL_FUNCTION_STOP_AUTO_ATTACK,
	SKILL_FUNCTION_FLAG_SET_INVINCIBLE					= 1 << SKILL_FUNCTION_SET_INVINCIBLE,
	SKILL_FUNCTION_FLAG_FAINTING_AFTER_APPLYING			= 1 << SKILL_FUNCTION_FAINTING_AFTER_APPLYING,
};

enum eSKILL_TRANSFORM_USE_INFO
{
	SKILL_TRANSFORM_USE_INFO_ABLE_WHEN_NORMAL = 0,
	SKILL_TRANSFORM_USE_INFO_ABLE_WHEN_GREAT_NAMEK,
	SKILL_TRANSFORM_USE_INFO_ABLE_WHEN_SUPER_SAIYAN,
	SKILL_TRANSFORM_USE_INFO_ABLE_WHEN_PURE_MAJIN,
	SKILL_TRANSFORM_USE_INFO_ABLE_WHEN_KAIOKEN,
	SKILL_TRANSFORM_USE_INFO_ABLE_WHEN_SPINNING_ATTACK,
	SKILL_TRANSFORM_USE_INFO_ABLE_WHEN_VEHICLE,

	SKILL_TRANSFORM_USE_INFO_COUNT,

	SKILL_TRANSFORM_USE_INFO_FIRST = SKILL_TRANSFORM_USE_INFO_ABLE_WHEN_NORMAL,
	SKILL_TRANSFORM_USE_INFO_LAST = SKILL_TRANSFORM_USE_INFO_COUNT - 1
};

enum eSKILL_TRANSFORM_USE_INFO_FLAG
{
	SKILL_TRANSFORM_USE_INFO_FLAG_ABLE_WHEN_NORMAL				= 1 << SKILL_TRANSFORM_USE_INFO_ABLE_WHEN_NORMAL,
	SKILL_TRANSFORM_USE_INFO_FLAG_ABLE_WHEN_GREAT_NAMEK			= 1 << SKILL_TRANSFORM_USE_INFO_ABLE_WHEN_GREAT_NAMEK,
	SKILL_TRANSFORM_USE_INFO_FLAG_ABLE_WHEN_SUPER_SAIYAN		= 1 << SKILL_TRANSFORM_USE_INFO_ABLE_WHEN_SUPER_SAIYAN,
	SKILL_TRANSFORM_USE_INFO_FLAG_ABLE_WHEN_PURE_MAJIN			= 1 << SKILL_TRANSFORM_USE_INFO_ABLE_WHEN_PURE_MAJIN,
	SKILL_TRANSFORM_USE_INFO_FLAG_ABLE_WHEN_KAIOKEN				= 1 << SKILL_TRANSFORM_USE_INFO_ABLE_WHEN_KAIOKEN,
	SKILL_TRANSFORM_USE_INFO_FLAG_ABLE_WHEN_SPINNING_ATTACK		= 1 << SKILL_TRANSFORM_USE_INFO_ABLE_WHEN_SPINNING_ATTACK,
	SKILL_TRANSFORM_USE_INFO_FLAG_ABLE_WHEN_VEHICLE				= 1 << SKILL_TRANSFORM_USE_INFO_ABLE_WHEN_VEHICLE,
};

class CSkillTable : public CTable
{
public:

	CSkillTable(void);
	virtual ~CSkillTable(void);

	/*
	public:

	BOOL				Check() { return TRUE; }*/
public:

	typedef std::map<TBLIDX, TBLIDX> PRE_TABLE;
	typedef PRE_TABLE::iterator PRE_TABLE_IT;
	typedef PRE_TABLE::value_type PRE_TABLE_VAL;

public:
	bool Create(DWORD dwCodePage);
	void Destroy();

protected:
	void Init();

public:
	sTBLDAT *			FindData(TBLIDX tblidx); 
	TBLIDX 				FindPreSkillTblidx(TBLIDX tblidx); 
	TBLIDX 				FindBasicSkillTblidx(TBLIDX tblidx); 
protected:
	WCHAR** GetSheetListInWChar() { return &(CSkillTable::m_pwszSheetList[0]); }
	void* AllocNewTable(WCHAR* pwszSheetName, DWORD dwCodePage);
	bool DeallocNewTable(void* pvTable, WCHAR* pwszSheetName);
	bool AddTable(void * pvTable, bool bReload);
	bool SetTableData(void* pvTable, WCHAR* pwszSheetName, std::wstring* pstrDataName, BSTR bstrData);


public:

	virtual bool				LoadFromBinary(CNtlSerializer& serializer, bool bReload);

	virtual bool				SaveToBinary(CNtlSerializer& serializer);

protected:

	PRE_TABLE					m_mapPreTableList;

private:
	static WCHAR* m_pwszSheetList[];
};
