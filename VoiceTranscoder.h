#pragma once

#include <extdll.h>

#include <dllapi.h>
#include <meta_api.h>

#include "Util.h"

#include "VoiceCodec.h"
#include "VoiceCodec_Speex.h"
#include "VoiceCodec_Silk.h"

#include "DProtoAPI.h"
#include "EngineFuncs.h"

#define MAX_CLIENTS	32

enum voicecodec_t {
	VOICECODEC_NONE = NULL,
	VOICECODEC_MILES_SPEEX,
	VOICECODEC_SILK
};

struct playervcodec_t {
	voicecodec_t	m_vcodec;
	bool			m_fIsRequested;
	int				m_iRequestID;
};

extern void SV_ParseVoiceData( client_t *pClient );

extern size_t g_sizeClientStruct;

extern server_static_t *g_psvs;

extern playervcodec_t g_PlayerVCodec[ MAX_CLIENTS+1 ];

extern CSpeex *g_pVoiceSpeex[ MAX_CLIENTS ];
extern CSilk *g_pVoiceSilk[ MAX_CLIENTS ];

extern cvar_t *g_pcvarSvVoiceEnable;
extern cvar_t *g_pcvarSvVoiceCodec;
extern cvar_t *g_pcvarSvVoiceQuality;
extern cvar_t *g_pcvarVtcLogDir;
extern cvar_t *g_pcvarVtcLog;

extern qboolean VTC_Init( void );
extern qboolean VTC_End( void );

extern void ParseSizeClientStruct(void);

extern qboolean ClientConnect_Pre ( edict_t *pEntity, const char *pszName, const char *pszAddress, char szRejectReason[ 128 ] );
extern void StartFrame ( void );
extern void CvarValue2_Pre ( const edict_t *pEnt, int iRequestID, const char *pszCvarName, const char *pszValue );