#pragma once

#include "NtlPacketCommon.h"
#include "NtlPetition.h" // [ by sooshia 2008-10-18 ]


enum eOPCODE_UT
{
	UT_OPCODE_BEGIN = 6000,

	UT_ENTER_CHAT = UT_OPCODE_BEGIN,
	UT_CHAT_MESSAGE_SAY,
	UT_CHAT_MESSAGE_SHOUT,
	UT_CHAT_MESSAGE_WHISPER,
	UT_CHAT_MESSAGE_PARTY,
	UT_CHAT_MESSAGE_GUILD,

	UT_GUILD_DISBAND_REQ,								// ��� ��ü�ϱ�
	UT_GUILD_DISBAND_CANCEL_REQ,						// ��� ��ü ����ϱ�
	UT_GUILD_RESPONSE_INVITATION,						// ��� �ʴ뿡 ���� ��� ������
	UT_GUILD_LEAVE_REQ,									// ��� Ż���ϱ�
	UT_GUILD_KICK_OUT_REQ,								// ��� ��� ������ Ż���Ű��
	UT_GUILD_APPOINT_SECOND_MASTER_REQ,					// ��� ����� Second Master�� �Ӹ��ϱ�
	UT_GUILD_DISMISS_SECOND_MASTER_REQ,					// ��� Second Master�� ������ �����ϱ�
	UT_GUILD_CHANGE_GUILD_MASTER_REQ,					// ��� �����͸� �̾��ϱ�
	
	UT_CHAT_MESSAGE_PRIVATESHOP_BUSINESS,				// ���λ��� ���� ��ȭ [10/31/2007 SGpro]

	UT_FRIEND_ADD_REQ,		// ģ�� �߰�
	UT_FRIEND_DEL_REQ,		// ģ�� ����
	UT_FRIEND_MOVE_REQ,		// ģ�� -> ������Ʈ�� �̵�
	UT_FRIEND_BLACK_ADD_REQ,		// ģ�� �� ����Ʈ �߰�
	UT_FRIEND_BLACK_DEL_REQ,		// ģ�� �� ����Ʈ ����

	UT_RANKBATTLE_RANK_LIST_REQ,
	UT_RANKBATTLE_RANK_FIND_CHARACTER_REQ,
	UT_RANKBATTLE_RANK_COMPARE_DAY_REQ,

	UT_GUILD_CHANGE_NOTICE_REQ,
	UT_TMQ_RECORD_LIST_REQ,
	UT_TMQ_MEMBER_LIST_REQ,

	UT_BUDOKAI_TOURNAMENT_INDIVIDUAL_LIST_REQ,
	UT_BUDOKAI_TOURNAMENT_INDIVIDUAL_INFO_REQ,
	UT_BUDOKAI_TOURNAMENT_TEAM_LIST_REQ,
	UT_BUDOKAI_TOURNAMENT_TEAM_INFO_REQ,

	UT_PETITION_CHAT_START_RES,							// [ by sooshia 2008-10-15 ]
	UT_PETITION_CHAT_USER_SAY_REQ,						// ������ ���� ���� [ by sooshia 2008-10-16 ]
	UT_PETITION_CHAT_USER_END_NFY,						// [ by sooshia 2008-10-17 ]
	UT_PETITION_CHAT_GM_SAY_RES,						// [ by sooshia 2008-10-18 ]
	UT_PETITION_USER_INSERT_REQ,						// [ by sooshia 2008-10-18 ]
	UT_PETITION_CONTENT_MODIFY_REQ,						// [ by sooshia 2008-10-18 ]
	UT_PETITION_SATISFACTION_NFY,						// [ by sooshia 2008-10-18 ]
	UT_PETITION_USER_CANCEL_REQ,						// [ by sooshia 2008-10-18 ]

	UT_DOJO_BUDOKAI_SEED_ADD_REQ,
	UT_DOJO_BUDOKAI_SEED_DEL_REQ,
	UT_DOJO_NOTICE_CHANGE_REQ,

	UT_OPCODE_END_DUMMY,
	UT_OPCODE_END = UT_OPCODE_END_DUMMY - 1
};


//------------------------------------------------------------------
//
//------------------------------------------------------------------
const char * NtlGetPacketName_UT(WORD wOpCode);
//------------------------------------------------------------------


#pragma pack(1)

//------------------------------------------------------------------
BEGIN_PROTOCOL(UT_ENTER_CHAT)
	ACCOUNTID			accountId;
	BYTE				abyAuthKey[NTL_MAX_SIZE_AUTH_KEY];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UT_CHAT_MESSAGE_SAY)
	WORD				wMessageLengthInUnicode;
	WCHAR				awchMessage[NTL_MAX_LENGTH_OF_CHAT_MESSAGE_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UT_CHAT_MESSAGE_SHOUT)
	WORD				wMessageLengthInUnicode;
	WCHAR				awchMessage[NTL_MAX_LENGTH_OF_CHAT_MESSAGE_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UT_CHAT_MESSAGE_WHISPER)
	WCHAR				awchReceiverCharName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];
	//- yoshiki : I don't remember why "dwTellMessageID" was needed before.
//	DWORD				dwTellMessageID;
	WORD				wMessageLengthInUnicode;
	WCHAR				awchMessage[NTL_MAX_LENGTH_OF_CHAT_MESSAGE_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UT_CHAT_MESSAGE_PARTY)
	BYTE				byChattingType;		// eDBO_CHATTING_TYPE
	WORD				wMessageLengthInUnicode;
	WCHAR				awchMessage[NTL_MAX_LENGTH_OF_CHAT_MESSAGE_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UT_CHAT_MESSAGE_GUILD)
	BYTE				byChattingType;		// eDBO_CHATTING_TYPE
	WORD				wMessageLengthInUnicode;
	WCHAR				awchMessage[NTL_MAX_LENGTH_OF_CHAT_MESSAGE_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UT_GUILD_DISBAND_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UT_GUILD_DISBAND_CANCEL_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UT_GUILD_RESPONSE_INVITATION)
	BYTE				byResponse;		// eNTL_INVITATION_RESPONSE
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UT_GUILD_LEAVE_REQ)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UT_GUILD_KICK_OUT_REQ)
	CHARACTERID			targetMemberCharId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UT_GUILD_APPOINT_SECOND_MASTER_REQ)
	CHARACTERID			targetMemberCharId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UT_GUILD_DISMISS_SECOND_MASTER_REQ)
	CHARACTERID			targetMemberCharId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UT_GUILD_CHANGE_GUILD_MASTER_REQ)
	CHARACTERID			targetMemberCharId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UT_CHAT_MESSAGE_PRIVATESHOP_BUSINESS)
	WCHAR				awchReceiverCharName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];
	//- yoshiki : I don't remember why "dwTellMessageID" was needed before.
	//	DWORD				dwTellMessageID;
	WORD				wMessageLengthInUnicode;
	WCHAR				awchMessage[NTL_MAX_LENGTH_OF_CHAT_MESSAGE_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UT_FRIEND_ADD_REQ)	// ģ�� �߰�
	WCHAR				wchName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];	
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UT_FRIEND_DEL_REQ)	// ģ�� ����
	CHARACTERID			targetID;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UT_FRIEND_MOVE_REQ)	// ģ�� -> ������Ʈ�� �̵�
	CHARACTERID			targetID;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UT_FRIEND_BLACK_ADD_REQ )	// ģ�� �� ����Ʈ �߰�
	WCHAR				awchName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];	
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UT_FRIEND_BLACK_DEL_REQ )	// ģ�� �� ����Ʈ ����
	CHARACTERID			targetID;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UT_RANKBATTLE_RANK_LIST_REQ)
	DWORD				dwPage;
	BYTE				byCompareDay;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UT_RANKBATTLE_RANK_FIND_CHARACTER_REQ)
	DWORD				dwPage;
	BYTE				byCompareDay;

	WCHAR				wszCharName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];// ã�� character
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UT_RANKBATTLE_RANK_COMPARE_DAY_REQ)
	DWORD				dwPage;
	BYTE				byCompareDay;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UT_GUILD_CHANGE_NOTICE_REQ)
	WORD				wNoticeLengthInUnicode;	
	WCHAR				awchNotice[NTL_MAX_LENGTH_OF_GUILD_NOTICE_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UT_TMQ_RECORD_LIST_REQ)
	TBLIDX						tmqTblidx;
	BYTE						byDifficult;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UT_TMQ_MEMBER_LIST_REQ)
	TBLIDX						tmqTblidx;
	BYTE						byDifficult;
	BYTE						byRank;		// 0 : Best 1~5: ���緩ŷ
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UT_BUDOKAI_TOURNAMENT_INDIVIDUAL_LIST_REQ)
	// �ʱⰪ : INVALID_BYTE - ���� �����ڵ��� JoinId�� ���� ����
	// Ŭ���̾�Ʈ�� �����ϰ� �ִ� ����Ʈ(��� ����)�� ����
	BYTE						byReceivedListCount;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UT_BUDOKAI_TOURNAMENT_INDIVIDUAL_INFO_REQ)
	WORD						awJoinId[2];
END_PROTOCOL()
//------------------------------------------------------------------
//------------------------------------------------------------------
BEGIN_PROTOCOL(UT_BUDOKAI_TOURNAMENT_TEAM_LIST_REQ)
	// �ʱⰪ : INVALID_BYTE - ���� �����ڵ��� JoinId�� ���� ����
	// Ŭ���̾�Ʈ�� �����ϰ� �ִ� ����Ʈ(��� ����)�� ����
	BYTE						byReceivedListCount;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UT_BUDOKAI_TOURNAMENT_TEAM_INFO_REQ)
	WORD						awJoinId[2];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UT_PETITION_CHAT_START_RES )
	//PETITIONID					petitionID;
	WORD						wResultCode;
	ACCOUNTID					gmAccountID;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UT_PETITION_CHAT_USER_SAY_REQ )
	//PETITIONID					petitionID;
	ACCOUNTID					gmAccountID;
	WORD						wMessageLengthInUnicode;
	WCHAR						awchMessage[NTL_MAX_LENGTH_OF_CHAT_MESSAGE_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UT_PETITION_CHAT_USER_END_NFY )
	ACCOUNTID					gmAccountID;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UT_PETITION_CHAT_GM_SAY_RES )
	WORD						wResultCode;
	ACCOUNTID					gmAccountID;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UT_PETITION_USER_INSERT_REQ )
	WCHAR						awchUserCharName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];
	WCHAR						awchQuestionContent[NTL_MAX_SIZE_QUESTION_CONTENT_UNICODE + 1];
	PETITIONCATEGORY			nCategory1;//ePETITIONSYSTEM_CATEGORY_1
	PETITIONCATEGORY			nCategory2;//ePETITIONSYSTEM_CATEGORY_2
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UT_PETITION_CONTENT_MODIFY_REQ )
	PETITIONID					petitionID;
	WCHAR						awchQuestionContent[NTL_MAX_SIZE_QUESTION_CONTENT_UNICODE + 1];
	PETITIONCATEGORY			nCategory1;//ePETITIONSYSTEM_CATEGORY_1
	PETITIONCATEGORY			nCategory2;//ePETITIONSYSTEM_CATEGORY_2
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UT_PETITION_SATISFACTION_NFY )
	PETITIONID					petitionID;
	ACCOUNTID					gmAccountID;
	BYTE						bySatisfactionRate;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( UT_PETITION_USER_CANCEL_REQ )
	PETITIONID					petitionID;
	ACCOUNTID					gmAccountID;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UT_DOJO_BUDOKAI_SEED_ADD_REQ)
	WCHAR				wszCharName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];// ����� character
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UT_DOJO_BUDOKAI_SEED_DEL_REQ)	
	WCHAR				wszCharName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];// ������ character
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(UT_DOJO_NOTICE_CHANGE_REQ)
	WORD				wNoticeLengthInUnicode;	
	WCHAR				awchNotice[NTL_MAX_LENGTH_OF_GUILD_NOTICE_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
#pragma pack()
