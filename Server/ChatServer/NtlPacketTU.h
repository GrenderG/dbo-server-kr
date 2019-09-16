#pragma once

#include "NtlPacketCommon.h"
#include "Guild.h"
#include "NtlFriend.h"
#include "NtlRankBattle.h"
#include "NtlTimeQuest.h"
#include "NtlBudokai.h"
#include "NtlPetition.h" // [ by sooshia 2008-10-18 ]
#include "NtlDojo.h"

enum eOPCODE_TU
{
	TU_OPCODE_BEGIN = 7000,

	TU_ENTER_CHAT_RES = TU_OPCODE_BEGIN,
	TU_DISCONNECT,
	TU_DISCONNECTED_NFY,
	TU_HEARTBEAT,

	TU_SYSTEM_DISPLAY_TEXT,

	TU_CHAT_MESSAGE_SAY,
	TU_CHAT_MESSAGE_SHOUT,
	TU_CHAT_MESSAGE_WHISPER,
	TU_CHAT_MESSAGE_WHISPER_FAILED_NFY,
	TU_CHAT_MESSAGE_PARTY,
	TU_CHAT_MESSAGE_GUILD,

	// Guild Creation/Disbanding
	TU_GUILD_CREATED_NFY,						// ��尡 �����Ǿ����� ����
	TU_GUILD_INFO,								// ��� ����
	TU_GUILD_MEMBER_INFO,						// ��� ��� ����

	// Guild Member Invitation/Leaving/Kicking Out
	TU_GUILD_DISBAND_RES,						// ��� ��ü ��û ���
	TU_GUILD_BEING_DISBANDED_NFY,				// ��� ��ü ��� ���� ����
	TU_GUILD_DISBAND_CANCEL_RES,				// ��� ��ü ��� ��û ���
	TU_GUILD_DISBAND_CANCELED_NFY,				// ��� ��ü�� ��ҵǾ����� ����
	TU_GUILD_DISBANDED_NFY,						// ���� ��尡 ��ü�Ǿ����� ����
	TU_GUILD_INVITED_NFY,						// ��忡 �ʴ�޾����� �˸�
	TU_GUILD_RESPONSE_INVITATION_RES,			// ��� �ʴ뿡 ���� ��� ���
	TU_GUILD_MEMBER_JOINED_NFY,					// �� ���� ���� ����
	TU_GUILD_INVITATION_DECLINED_NFY,			// ��� �ʴ븦 ����
	TU_GUILD_INVITATION_EXPIRED_NFY,			// ��� �ʴ��� ��ȿ �ð� ���
	TU_GUILD_LEAVE_RES,							// ��� Ż�� ��û ���
	TU_GUILD_MEMBER_LEFT_NFY,					// ���� Ż�� ����
	TU_GUILD_KICK_OUT_RES,						// ������ ���� Ż�� ��û ���
	TU_GUILD_MEMBER_KICKED_OUT_NFY,				// ���� ���� Ż�� ����

	// Appointment of Guild Master/Guild Second Master
	TU_GUILD_APPOINT_SECOND_MASTER_RES,			// Second Master�� �Ӹ� ���
	TU_GUILD_SECOND_MASTER_APPOINTED_NFY,		// Second Master�� �Ӹ� ����
	TU_GUILD_DISMISS_SECOND_MASTER_RES,			// Second Master�� ���� ���� ���
	TU_GUILD_SECOND_MASTER_DISMISSED_NFY,		// Second Master�� ���� ���� ����
	TU_GUILD_CHANGE_GUILD_MASTER_RES,			// Guild Master�� �̾� ���
	TU_GUILD_GUILD_MASTER_CHANGED_NFY,			// Guild Master�� ���� ����

	// Sync. of Guild Members' Info
	TU_GUILD_MEMBER_POSITION_CHANGED_NFY,		// ���� ��ġ ���� �˸�
	TU_GUILD_MEMBER_CLASS_CHANGED_NFY,			// ���� ���� ���� �˸�
	TU_GUILD_MEMBER_LEVEL_CHANGED_NFY,			// ���� ���� ���� �˸�
	TU_GUILD_MEMBER_REPUTATION_CHANGED_NFY,		// ���� ���� ���� �˸�
	TU_GUILD_MEMBER_ONLINE_NFY,					// ���� ���� ���� �˸�
	TU_GUILD_MEMBER_OFFLINE_NFY,				// ���� ���� ���� �˸�
	
	TU_CHAT_MESSAGE_PRIVATESHOP_BUSINESS,		// ���λ��� ���� ä�� [10/31/2007 SGpro]

	TU_FRIEND_ADD_RES,		// ģ�� �߰�
	TU_FRIEND_DEL_RES,		// ģ�� ����
	TU_FRIEND_MOVE_RES,		// ģ�� -> ������Ʈ�� �̵�
	TU_FRIEND_LIST_INFO,	// ģ�� ����Ʈ ����
	TU_FRIEND_BLACK_ADD_RES,		// ģ�� �� ����Ʈ �߰�
	TU_FRIEND_BLACK_DEL_RES,		// ģ�� �� ����Ʈ ����
	TU_FRIEND_INFO,					// �¶��� ģ�� �� ����
	TU_FRIEND_INFO_CHANGE,			// ģ�� ���º��� �˸�

	TU_RANKBATTLE_RANK_LIST_RES,
	TU_RANKBATTLE_RANK_FIND_CHARACTER_RES,
	TU_RANKBATTLE_RANK_COMPARE_DAY_RES,	

	TU_GUILD_REPUTATION_CHANGE_NFY,					// ���� ���� �˸�
	TU_GUILD_FUNCTION_CHANGE_NFY,
	TU_GUILD_CHANGE_NOTICE_NFY,
	TU_GUILD_CHANGE_NOTICE_RES,
	TU_GUILD_GIVE_ZENNY_NFY,
		
	TU_TMQ_RECORD_LIST_RES,
	TU_TMQ_MEMBER_LIST_RES,

	TU_BUDOKAI_NOTICE_NFY,						// õ�����Ϲ���ȸ ����

	TU_BUDOKAI_TOURNAMENT_INDIVIDUAL_LIST_RES,
	TU_BUDOKAI_TOURNAMENT_INDIVIDUAL_INFO_RES,
	TU_BUDOKAI_TOURNAMENT_TEAM_LIST_RES,
	TU_BUDOKAI_TOURNAMENT_TEAM_INFO_RES,

	TU_PETITION_CHAT_START_REQ,						// ���� ä�� ��û [ by sooshia 2008-10-15 ]
	TU_PETITION_CHAT_GM_SAY_REQ,				// GM�� ���� ���� [ by sooshia 2008-10-16 ]
	TU_PETITION_CHAT_USER_SAY_RES,				// [ by sooshia 2008-10-16 ]
	TU_PETITION_CHAT_GM_END_NFY,					// [ by sooshia 2008-10-17 ]
	TU_PETITION_USER_INSERT_RES,					// [ by sooshia 2008-10-18 ]
	TU_PETITION_CONTENT_MODIFY_RES,					// [ by sooshia 2008-10-18 ]
	//TU_PETITION_SATISFACTION_RES,					// [ by sooshia 2008-10-18 ]
	TU_PETITION_USER_CANCEL_RES,					// [ by sooshia 2008-10-18 ]
	TU_PETITION_FINISH_NFY,

	TU_DOJO_CREATED_NFY,
	TU_DOJO_DESTROYED_NFY,
	
	TU_DOJO_BRIEF_NFY,
	TU_DOJO_SCRAMBLE_NFY,							// ��帮���� �ۿ� ������ �԰ų� ������ �ʿ��� ���� �϶� �ٽ� �˷��ش�.
	TU_DOJO_SCRAMBLE_INFORM_NFY,					// ������ ��� �޼���
	TU_DOJO_SCRAMBLE_REJECT_NFY,					// ��û�ߴ� ���Ŀ��� �����Ͽ�����
	
	TU_DOJO_BUDOKAI_SEED_ADD_RES,
	TU_DOJO_BUDOKAI_SEED_DEL_RES,
	TU_DOJO_SCRAMBLE_POINT_NFY,						// ���� ���� ��� �޼���
	TU_DOJO_SCRAMBLE_SHIEFT_SEAL_STATE_NFY,			// ���� ���� ȹ�� ���

	TU_DOJO_NOTICE_CHANGE_RES,
	TU_DOJO_NOTICE_CHANGE_NFY,

	TU_DOJO_SCRAMBLE_RECEIVE_NFY,					// ��û�ߴ� ���Ŀ��� �¶��Ǿ�����
	TU_DOJO_SCRAMBLE_RECEIVE_INFO_NFY,
	TU_DOJO_SCRAMBLE_REWARD_NFY,
	TU_DOJO_SCRAMBLE_RESULT_NFY,

	TU_OPCODE_END_DUMMY,
	TU_OPCODE_END = TU_OPCODE_END_DUMMY - 1
};


//------------------------------------------------------------------
//
//------------------------------------------------------------------
const char * NtlGetPacketName_TU(WORD wOpCode);
//------------------------------------------------------------------

#pragma pack(1)

//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_ENTER_CHAT_RES)
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_DISCONNECT)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_DISCONNECTED_NFY)
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_HEARTBEAT)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_SYSTEM_DISPLAY_TEXT)
	WCHAR				wszGmCharName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];
	BYTE				byDisplayType;
	WORD				wMessageLengthInUnicode;
	WCHAR				wszMessage[NTL_MAX_LENGTH_OF_CHAT_MESSAGE_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_CHAT_MESSAGE_SAY)
	HOBJECT				hSubject;
	WCHAR				awchSenderCharName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];
	WORD				wMessageLengthInUnicode;
	WCHAR				awchMessage[NTL_MAX_LENGTH_OF_CHAT_MESSAGE_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_CHAT_MESSAGE_SHOUT)
	HOBJECT				hSubject;
	WCHAR				awchSenderCharName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];
	WORD				wMessageLengthInUnicode;
	WCHAR				awchMessage[NTL_MAX_LENGTH_OF_CHAT_MESSAGE_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_CHAT_MESSAGE_WHISPER)
	WCHAR				awchSenderCharName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];
	WORD				wMessageLengthInUnicode;
	WCHAR				awchMessage[NTL_MAX_LENGTH_OF_CHAT_MESSAGE_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_CHAT_MESSAGE_WHISPER_FAILED_NFY)
	WCHAR				awchReceiverCharName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_CHAT_MESSAGE_PARTY)
	HOBJECT				hSubject;
	WCHAR				awchSenderCharName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];
	BYTE				byChattingType;		// eDBO_CHATTING_TYPE
	WORD				wMessageLengthInUnicode;
	WCHAR				awchMessage[NTL_MAX_LENGTH_OF_CHAT_MESSAGE_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_CHAT_MESSAGE_GUILD)
	WCHAR				wszSenderCharName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];
	BYTE				byChattingType;		// eDBO_CHATTING_TYPE
	WORD				wMessageLengthInUnicode;
	WCHAR				awchMessage[NTL_MAX_LENGTH_OF_CHAT_MESSAGE_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_GUILD_CREATED_NFY)
	WCHAR						wszGuildName[NTL_MAX_SIZE_GUILD_NAME_IN_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_GUILD_INFO)
	sDBO_GUILD_INFO				guildInfo;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_GUILD_MEMBER_INFO)
	sDBO_GUILD_MEMBER_INFO		guildMemberInfo;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_GUILD_DISBAND_RES)
	WORD						wResultCode;
	time_t						timeToDisband;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_GUILD_BEING_DISBANDED_NFY)
	time_t						timeToDisband;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_GUILD_DISBAND_CANCEL_RES)
	WORD						wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_GUILD_DISBAND_CANCELED_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_GUILD_DISBANDED_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_GUILD_INVITED_NFY)
	WCHAR						wszGuildName[NTL_MAX_SIZE_GUILD_NAME_IN_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_GUILD_RESPONSE_INVITATION_RES)
	WORD						wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_GUILD_MEMBER_JOINED_NFY)
	sDBO_GUILD_MEMBER_INFO		memberInfo;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_GUILD_INVITATION_DECLINED_NFY)
	WCHAR						wszTargetName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_GUILD_INVITATION_EXPIRED_NFY)
	WCHAR						wszTargetName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_GUILD_LEAVE_RES)
	WORD						wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_GUILD_MEMBER_LEFT_NFY)
	CHARACTERID					memberCharId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_GUILD_KICK_OUT_RES)
	WORD						wResultCode;
	CHARACTERID					kickedOutMemberCharId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_GUILD_MEMBER_KICKED_OUT_NFY)
	CHARACTERID					memberCharId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_GUILD_APPOINT_SECOND_MASTER_RES)
	WORD						wResultCode;
	CHARACTERID					secondMasterCharId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_GUILD_SECOND_MASTER_APPOINTED_NFY)
	CHARACTERID					memberCharId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_GUILD_DISMISS_SECOND_MASTER_RES)
	WORD						wResultCode;
	CHARACTERID					secondMasterCharId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_GUILD_SECOND_MASTER_DISMISSED_NFY)
	CHARACTERID					memberCharId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_GUILD_CHANGE_GUILD_MASTER_RES)
	WORD						wResultCode;
	CHARACTERID					newMasterCharId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_GUILD_GUILD_MASTER_CHANGED_NFY)
	CHARACTERID					memberCharId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_GUILD_MEMBER_POSITION_CHANGED_NFY)
	CHARACTERID					memberCharId;
	TBLIDX						newMapNameTblidx;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_GUILD_MEMBER_CLASS_CHANGED_NFY)
	CHARACTERID					memberCharId;
	BYTE						byNewClass;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_GUILD_MEMBER_LEVEL_CHANGED_NFY)
	CHARACTERID					memberCharId;
	BYTE						byNewLevel;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_GUILD_MEMBER_REPUTATION_CHANGED_NFY)
	CHARACTERID					memberCharId;
	DWORD						dwNewReputation;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_GUILD_MEMBER_ONLINE_NFY)
	CHARACTERID					memberCharId;
	TBLIDX						newMapNameTblidx;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_GUILD_MEMBER_OFFLINE_NFY)
	CHARACTERID					memberCharId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_CHAT_MESSAGE_PRIVATESHOP_BUSINESS)
	WCHAR				awchSenderCharName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];
	WORD				wMessageLengthInUnicode;
	WCHAR				awchMessage[NTL_MAX_LENGTH_OF_CHAT_MESSAGE_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_FRIEND_ADD_RES)
	WORD						wResultCode;
	WCHAR						wchName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];
	CHARACTERID					targetID;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_FRIEND_DEL_RES)
	WORD						wResultCode;
	CHARACTERID					targetID;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_FRIEND_MOVE_RES)
	WORD						wResultCode;
	CHARACTERID					targetID;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_FRIEND_LIST_INFO)
	BYTE						byCount;
	sFRIEND_FULL_INFO			asInfo[NTL_MAX_COUNT_FRIEND + NTL_MAX_COUNT_FRIEND];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_FRIEND_BLACK_ADD_RES)
	WORD						wResultCode;
	WCHAR						wchName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];
	CHARACTERID					targetID;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_FRIEND_BLACK_DEL_RES)
	WORD						wResultCode;
	CHARACTERID					targetID;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_FRIEND_INFO)
	sFRIEND_INFO				sInfo;
	bool						bIsFirst;		// true : ó�� false : ���� 
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_FRIEND_INFO_CHANGE)
	CHARACTERID					targetID;
	BYTE						byChangeType;	// NtlFriend.h eFRIEND_CHANGE_TYPE
	DWORD						dwChangeValue;	// Online 1:On 2:Off , Class , Level , Channel, PositionMapTblidx
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_RANKBATTLE_RANK_LIST_RES)
	WORD						wResultCode;
	DWORD						dwPage;
	BYTE						byCompareDay;

	BYTE						byRankInfoCount;
	WORD						wRankInfo;		// sRANKBATTLE_RANK_INFO []

	sVARIABLE_DATA				sData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_RANKBATTLE_RANK_FIND_CHARACTER_RES)
	WORD						wResultCode;
	DWORD						dwPage;
	BYTE						byCompareDay;

	WCHAR						wszCharName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];

	BYTE						byRankInfoCount;
	WORD						wRankInfo;		// sRANKBATTLE_RANK_INFO asRankInfo []

	sVARIABLE_DATA				sData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_RANKBATTLE_RANK_COMPARE_DAY_RES)
	WORD						wResultCode;
	DWORD						dwPage;
	BYTE						byCompareDay;

	bool						bIsFullList;	// true = wRankInfo ���� | false = wCompareInfo ����
	BYTE						byInfoCount;
	union
	{
		WORD					wRankInfo;		// sRANKBATTLE_RANK_INFO asRankInfo []
		WORD					wCompareInfo;	// DWORD adwCompareRank []
	};

	sVARIABLE_DATA				sData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_GUILD_REPUTATION_CHANGE_NFY)
	DWORD						dwReputation;
	DWORD						dwMaxGuildPointEver;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_GUILD_FUNCTION_CHANGE_NFY)
	DWORD64						qwGuildFunctionFlag;
	BYTE						byNewFunc;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_GUILD_CHANGE_NOTICE_NFY)
	WCHAR						awchCharName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];
	WORD						wNoticeLengthInUnicode;	
	WCHAR						awchNotice[NTL_MAX_LENGTH_OF_GUILD_NOTICE_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_GUILD_CHANGE_NOTICE_RES)
	WORD						wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_GUILD_GIVE_ZENNY_NFY)
	CHARACTERID					charId; 
	DWORD						dwZenny;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( TU_TMQ_RECORD_LIST_RES )
	WORD						wResultCode;
	TBLIDX						tmqTblidx;
	BYTE						byDifficult;
	BYTE						byTeamCount;
	sTIMEQUEST_TEAM_RANK_DATA	asTeam[DBO_TIMEQUEST_DEFAULT_TOTAL_RANK_COUNT];		// �뷮 ����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( TU_TMQ_MEMBER_LIST_RES )
	WORD						wResultCode;
	TBLIDX						tmqTblidx;
	BYTE						byDifficult;
	BYTE						byRank;
	sTIMEQUEST_TEAM_MEMBER_DATA	sTeam;		
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_BUDOKAI_NOTICE_NFY)
	BYTE			byNoticeType;		// eBUDOKAI_NOTICE_TYPE

	union
	{
		// byNoticeType == BUDOKAI_NOTICE_SYSTEM ���
		TBLIDX		tblidxNotice;		

		// byNoticeType == BUDOKAI_NOTICE_GM ���
		struct sGM_NOTICE
		{
			BYTE		byNoticeLength;
			WCHAR		wszNotice[BUDOKAI_MAX_NOTICE_LENGTH + 1];
		};
		sGM_NOTICE	sGmNotice;
	};
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( TU_BUDOKAI_TOURNAMENT_INDIVIDUAL_LIST_RES )
	WORD									wResultCode;
	WORD									wEntryTeam;			// sBUDOKAI_TOURNAMENT_ENTRY_TEAM_INFO_VAR	asEntryTeam[BUDOKAI_MAJOR_MATCH_PLAYER_NUMBER];
	BYTE									byMatchDataCount;
	WORD									wMatchData;			// sBUDOKAI_TOURNAMENT_MATCH_DATA aMatchData[BUDOKAI_MAJOR_MATCH_PLAYER_NUMBER * 2 - 1];
	sVARIABLE_DATA							sData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( TU_BUDOKAI_TOURNAMENT_INDIVIDUAL_INFO_RES )
	WORD										wResultCode;
	TEAMTYPE									awTeamType[2];		// sBUDOKAI_TOURNAMENT_INDIVIDUAL_ENTRY_DATA_VAR asEntryData[2];
	sVARIABLE_DATA								sData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( TU_BUDOKAI_TOURNAMENT_TEAM_LIST_RES )
	WORD									wResultCode;
	WORD									wEntryTeam;			// sBUDOKAI_TOURNAMENT_ENTRY_TEAM_INFO_VAR	asEntryTeam[BUDOKAI_MAJOR_MATCH_TEAM_NUMBER];
	BYTE									byMatchDataCount;
	WORD									wMatchData;			// sBUDOKAI_TOURNAMENT_MATCH_DATA aMatchData[BUDOKAI_MAJOR_MATCH_TEAM_NUMBER * 2 - 1];
	sVARIABLE_DATA							sData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( TU_BUDOKAI_TOURNAMENT_TEAM_INFO_RES )
	WORD								wResultCode;
	TEAMTYPE							awTeamType[2];			//	sBUDOKAI_TOURNAMENT_TEAM_ENTRY_DATA_VAR	asEntryData[2];
	sVARIABLE_DATA						sData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( TU_PETITION_CHAT_START_REQ )
	PETITIONID			petitionID;
	bool				bNeedSatisfactionRate;
	ACCOUNTID			gmAccountID;
	WCHAR				awchGMCharName_Consult[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( TU_PETITION_CHAT_GM_SAY_REQ )
	ACCOUNTID			gmAccountID;
	WORD				wMessageLengthInUnicode;
	WCHAR				awchMessage[NTL_MAX_LENGTH_OF_CHAT_MESSAGE_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( TU_PETITION_CHAT_USER_SAY_RES )
	WORD				wResultCode;
	//ACCOUNTID			gmAccountID;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( TU_PETITION_CHAT_GM_END_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( TU_PETITION_USER_INSERT_RES )
	WORD				wResultCode;
	PETITIONID			petitionID;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( TU_PETITION_CONTENT_MODIFY_RES )
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
//BEGIN_PROTOCOL( TU_PETITION_SATISFACTION_RES )
//	WORD				wResultCode;
//END_PROTOCOL()
////----------------------------------------------------------------
BEGIN_PROTOCOL( TU_PETITION_USER_CANCEL_RES )
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------ 
BEGIN_PROTOCOL( TU_PETITION_FINISH_NFY )
END_PROTOCOL()
//------------------------------------------------------------------ 
BEGIN_PROTOCOL( TU_DOJO_CREATED_NFY )
	sDBO_DOJO_DATA		sDojoData;	
END_PROTOCOL()
//------------------------------------------------------------------ 
BEGIN_PROTOCOL( TU_DOJO_DESTROYED_NFY )
	TBLIDX				dojoTblidx;
END_PROTOCOL()
//------------------------------------------------------------------ 
BEGIN_PROTOCOL( TU_DOJO_BRIEF_NFY )
	sDBO_DOJO_BRIEF		sDojoData;	
END_PROTOCOL()
//------------------------------------------------------------------ 
BEGIN_PROTOCOL( TU_DOJO_SCRAMBLE_NFY )			// ��帮���� �ۿ� ������ �԰ų� ������ �ʿ��� ���� �϶� �ٽ� �˷��ش�.
	WCHAR				wszName[NTL_MAX_SIZE_GUILD_NAME_IN_UNICODE + 1]; // ��û����
END_PROTOCOL()
//------------------------------------------------------------------	
BEGIN_PROTOCOL( TU_DOJO_SCRAMBLE_INFORM_NFY )
	TBLIDX						dojoTblidx;
	BYTE						byState;	// ������Ż�� ����
	DOJOTIME					tmNextStepTime;
END_PROTOCOL()
//------------------------------------------------------------------ 
BEGIN_PROTOCOL( TU_DOJO_SCRAMBLE_REJECT_NFY )   // ��û�ߴ� ������ ����������
END_PROTOCOL()
//------------------------------------------------------------------	
BEGIN_PROTOCOL(TU_DOJO_BUDOKAI_SEED_ADD_RES)
	WORD				wResultCode;
	TBLIDX				dojoTblidx;
	WCHAR				wszCharName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];// ����� character
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(TU_DOJO_BUDOKAI_SEED_DEL_RES)	
	WORD				wResultCode;
	WCHAR				wszCharName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];// ������ character
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( TU_DOJO_SCRAMBLE_POINT_NFY )
	sDOJO_SCRAMBLE_POINT sData;
END_PROTOCOL()
//------------------------------------------------------------------ 
BEGIN_PROTOCOL( TU_DOJO_SCRAMBLE_SHIEFT_SEAL_STATE_NFY )
	TBLIDX								dojoTblidx;
	TBLIDX								objectTblidx;
	GUILDID								guildId;
END_PROTOCOL()
//------------------------------------------------------------------ 
BEGIN_PROTOCOL( TU_DOJO_NOTICE_CHANGE_RES )
	WORD						wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( TU_DOJO_NOTICE_CHANGE_NFY )
	TBLIDX						dojoTblidx;
	WCHAR						awchCharName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];
	WORD						wNoticeLengthInUnicode;	
	WCHAR						awchNotice[NTL_MAX_LENGTH_OF_GUILD_NOTICE_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( TU_DOJO_SCRAMBLE_RECEIVE_NFY )
	TBLIDX								dojoTblidx;
	GUILDID								guildId;
END_PROTOCOL()
//------------------------------------------------------------------ 
BEGIN_PROTOCOL( TU_DOJO_SCRAMBLE_RECEIVE_INFO_NFY )
	TBLIDX								dojoTblidx;
	GUILDID								defGuildId;
	GUILDID								attGuildId;
	WCHAR								wszDefGuildName[NTL_MAX_SIZE_GUILD_NAME_IN_UNICODE + 1];
	WCHAR								wszAttGuildName[NTL_MAX_SIZE_GUILD_NAME_IN_UNICODE + 1];
	sDBO_GUILD_MARK						sDefMark;
	sDBO_GUILD_MARK						sAttMark;
END_PROTOCOL()
//------------------------------------------------------------------ 
BEGIN_PROTOCOL( TU_DOJO_SCRAMBLE_REWARD_NFY )
	DWORD						dwAddGuildReputation;
	TBLIDX						itemTblidx;
	BYTE						byCount;
END_PROTOCOL()
//------------------------------------------------------------------ 
BEGIN_PROTOCOL( TU_DOJO_SCRAMBLE_RESULT_NFY )
	GUILDID						winGuildId;	
END_PROTOCOL()
//------------------------------------------------------------------ 
#pragma pack()
