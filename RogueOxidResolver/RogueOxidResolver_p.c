

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 04:14:07 2038
 */
/* Compiler settings for RogueOxidResolver.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#if defined(_M_AMD64)


#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#include "ndr64types.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif /* __RPCPROXY_H_VERSION__ */


#include "RogueOxidResolver_h.h"

#define TYPE_FORMAT_STRING_SIZE   345                               
#define PROC_FORMAT_STRING_SIZE   579                               
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _RogueOxidResolver_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } RogueOxidResolver_MIDL_TYPE_FORMAT_STRING;

typedef struct _RogueOxidResolver_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } RogueOxidResolver_MIDL_PROC_FORMAT_STRING;

typedef struct _RogueOxidResolver_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } RogueOxidResolver_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};

static const RPC_SYNTAX_IDENTIFIER  _NDR64_RpcTransferSyntax = 
{{0x71710533,0xbeba,0x4937,{0x83,0x19,0xb5,0xdb,0xef,0x9c,0xcc,0x36}},{1,0}};



extern const RogueOxidResolver_MIDL_TYPE_FORMAT_STRING RogueOxidResolver__MIDL_TypeFormatString;
extern const RogueOxidResolver_MIDL_PROC_FORMAT_STRING RogueOxidResolver__MIDL_ProcFormatString;
extern const RogueOxidResolver_MIDL_EXPR_FORMAT_STRING RogueOxidResolver__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRemUnknown_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRemUnknown_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRemUnknown2_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRemUnknown2_ProxyInfo;



#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

static const RogueOxidResolver_MIDL_PROC_FORMAT_STRING RogueOxidResolver__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure ResolveOxid */

			0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/*  2 */	NdrFcLong( 0x1 ),	/* 1 */
/*  6 */	NdrFcShort( 0x0 ),	/* 0 */
/*  8 */	NdrFcShort( 0x40 ),	/* X64 Stack size/offset = 64 */
/* 10 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 12 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 14 */	NdrFcShort( 0x2a ),	/* 42 */
/* 16 */	NdrFcShort( 0x68 ),	/* 104 */
/* 18 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 20 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 22 */	NdrFcShort( 0x1 ),	/* 1 */
/* 24 */	NdrFcShort( 0x1 ),	/* 1 */
/* 26 */	NdrFcShort( 0x0 ),	/* 0 */
/* 28 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pOxid */

/* 30 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 32 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 34 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter cRequestedProtseqs */

/* 36 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 38 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 40 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter arRequestedProtseqs */

/* 42 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 44 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 46 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Parameter ppdsaOxidBindings */

/* 48 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 50 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 52 */	NdrFcShort( 0x12 ),	/* Type Offset=18 */

	/* Parameter pipidRemUnknown */

/* 54 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 56 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 58 */	NdrFcShort( 0x3a ),	/* Type Offset=58 */

	/* Parameter pAuthnHint */

/* 60 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 62 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 64 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 66 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 68 */	NdrFcShort( 0x38 ),	/* X64 Stack size/offset = 56 */
/* 70 */	0x10,		/* FC_ERROR_STATUS_T */
			0x0,		/* 0 */

	/* Procedure SimplePing */

/* 72 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 74 */	NdrFcLong( 0x1 ),	/* 1 */
/* 78 */	NdrFcShort( 0x1 ),	/* 1 */
/* 80 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 82 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 84 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 86 */	NdrFcShort( 0x24 ),	/* 36 */
/* 88 */	NdrFcShort( 0x8 ),	/* 8 */
/* 90 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 92 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 94 */	NdrFcShort( 0x0 ),	/* 0 */
/* 96 */	NdrFcShort( 0x0 ),	/* 0 */
/* 98 */	NdrFcShort( 0x0 ),	/* 0 */
/* 100 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSetId */

/* 102 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 104 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 106 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 108 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 110 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 112 */	0x10,		/* FC_ERROR_STATUS_T */
			0x0,		/* 0 */

	/* Procedure ComplexPing */

/* 114 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 116 */	NdrFcLong( 0x1 ),	/* 1 */
/* 120 */	NdrFcShort( 0x2 ),	/* 2 */
/* 122 */	NdrFcShort( 0x48 ),	/* X64 Stack size/offset = 72 */
/* 124 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 126 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 128 */	NdrFcShort( 0x36 ),	/* 54 */
/* 130 */	NdrFcShort( 0x46 ),	/* 70 */
/* 132 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 134 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 138 */	NdrFcShort( 0x1 ),	/* 1 */
/* 140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 142 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSetId */

/* 144 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 146 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 148 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter SequenceNum */

/* 150 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 152 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 154 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter cAddToSet */

/* 156 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 158 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 160 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter cDelFromSet */

/* 162 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 164 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 166 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter AddToSet */

/* 168 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 170 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 172 */	NdrFcShort( 0x4a ),	/* Type Offset=74 */

	/* Parameter DelFromSet */

/* 174 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 176 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 178 */	NdrFcShort( 0x5a ),	/* Type Offset=90 */

	/* Parameter pPingBackoffFactor */

/* 180 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 182 */	NdrFcShort( 0x38 ),	/* X64 Stack size/offset = 56 */
/* 184 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 186 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 188 */	NdrFcShort( 0x40 ),	/* X64 Stack size/offset = 64 */
/* 190 */	0x10,		/* FC_ERROR_STATUS_T */
			0x0,		/* 0 */

	/* Procedure ServerAlive */

/* 192 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 194 */	NdrFcLong( 0x1 ),	/* 1 */
/* 198 */	NdrFcShort( 0x3 ),	/* 3 */
/* 200 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 202 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 204 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 206 */	NdrFcShort( 0x0 ),	/* 0 */
/* 208 */	NdrFcShort( 0x8 ),	/* 8 */
/* 210 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 212 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 220 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 222 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 224 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 226 */	0x10,		/* FC_ERROR_STATUS_T */
			0x0,		/* 0 */

	/* Procedure ResolveOxid2 */

/* 228 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 230 */	NdrFcLong( 0x1 ),	/* 1 */
/* 234 */	NdrFcShort( 0x4 ),	/* 4 */
/* 236 */	NdrFcShort( 0x48 ),	/* X64 Stack size/offset = 72 */
/* 238 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 240 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 242 */	NdrFcShort( 0x2a ),	/* 42 */
/* 244 */	NdrFcShort( 0x90 ),	/* 144 */
/* 246 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 248 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 250 */	NdrFcShort( 0x1 ),	/* 1 */
/* 252 */	NdrFcShort( 0x1 ),	/* 1 */
/* 254 */	NdrFcShort( 0x0 ),	/* 0 */
/* 256 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pOxid */

/* 258 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 260 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 262 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter cRequestedProtseqs */

/* 264 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 266 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 268 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter arRequestedProtseqs */

/* 270 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 272 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 274 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Parameter ppdsaOxidBindings */

/* 276 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 278 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 280 */	NdrFcShort( 0x12 ),	/* Type Offset=18 */

	/* Parameter pipidRemUnknown */

/* 282 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 284 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 286 */	NdrFcShort( 0x3a ),	/* Type Offset=58 */

	/* Parameter pAuthnHint */

/* 288 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 290 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 292 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pComVersion */

/* 294 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 296 */	NdrFcShort( 0x38 ),	/* X64 Stack size/offset = 56 */
/* 298 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 300 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 302 */	NdrFcShort( 0x40 ),	/* X64 Stack size/offset = 64 */
/* 304 */	0x10,		/* FC_ERROR_STATUS_T */
			0x0,		/* 0 */

	/* Procedure ServerAlive2 */

/* 306 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 308 */	NdrFcLong( 0x1 ),	/* 1 */
/* 312 */	NdrFcShort( 0x5 ),	/* 5 */
/* 314 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 316 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 318 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 320 */	NdrFcShort( 0x0 ),	/* 0 */
/* 322 */	NdrFcShort( 0x4c ),	/* 76 */
/* 324 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 326 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 328 */	NdrFcShort( 0x1 ),	/* 1 */
/* 330 */	NdrFcShort( 0x0 ),	/* 0 */
/* 332 */	NdrFcShort( 0x0 ),	/* 0 */
/* 334 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pComVersion */

/* 336 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 338 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 340 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter ppdsaOrBindings */

/* 342 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 344 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 346 */	NdrFcShort( 0x12 ),	/* Type Offset=18 */

	/* Parameter pReserved */

/* 348 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 350 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 352 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 354 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 356 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 358 */	0x10,		/* FC_ERROR_STATUS_T */
			0x0,		/* 0 */

	/* Procedure RemQueryInterface */

/* 360 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 362 */	NdrFcLong( 0x0 ),	/* 0 */
/* 366 */	NdrFcShort( 0x3 ),	/* 3 */
/* 368 */	NdrFcShort( 0x38 ),	/* X64 Stack size/offset = 56 */
/* 370 */	NdrFcShort( 0x52 ),	/* 82 */
/* 372 */	NdrFcShort( 0x8 ),	/* 8 */
/* 374 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 376 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 378 */	NdrFcShort( 0x1 ),	/* 1 */
/* 380 */	NdrFcShort( 0x1 ),	/* 1 */
/* 382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 384 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ripid */

/* 386 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 388 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 390 */	NdrFcShort( 0x3a ),	/* Type Offset=58 */

	/* Parameter cRefs */

/* 392 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 394 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 396 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter cIids */

/* 398 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 400 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 402 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter iids */

/* 404 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 406 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 408 */	NdrFcShort( 0x82 ),	/* Type Offset=130 */

	/* Parameter ppQIResults */

/* 410 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 412 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 414 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Return value */

/* 416 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 418 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 420 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemAddRef */

/* 422 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 424 */	NdrFcLong( 0x0 ),	/* 0 */
/* 428 */	NdrFcShort( 0x4 ),	/* 4 */
/* 430 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 432 */	NdrFcShort( 0x6 ),	/* 6 */
/* 434 */	NdrFcShort( 0x8 ),	/* 8 */
/* 436 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 438 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 440 */	NdrFcShort( 0x1 ),	/* 1 */
/* 442 */	NdrFcShort( 0x1 ),	/* 1 */
/* 444 */	NdrFcShort( 0x0 ),	/* 0 */
/* 446 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cInterfaceRefs */

/* 448 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 450 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 452 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter InterfaceRefs */

/* 454 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 456 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 458 */	NdrFcShort( 0xe0 ),	/* Type Offset=224 */

	/* Parameter pResults */

/* 460 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 462 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 464 */	NdrFcShort( 0xf4 ),	/* Type Offset=244 */

	/* Return value */

/* 466 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 468 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 470 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemRelease */

/* 472 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 474 */	NdrFcLong( 0x0 ),	/* 0 */
/* 478 */	NdrFcShort( 0x5 ),	/* 5 */
/* 480 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 482 */	NdrFcShort( 0x6 ),	/* 6 */
/* 484 */	NdrFcShort( 0x8 ),	/* 8 */
/* 486 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 488 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 490 */	NdrFcShort( 0x0 ),	/* 0 */
/* 492 */	NdrFcShort( 0x1 ),	/* 1 */
/* 494 */	NdrFcShort( 0x0 ),	/* 0 */
/* 496 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cInterfaceRefs */

/* 498 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 500 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 502 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter InterfaceRefs */

/* 504 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 506 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 508 */	NdrFcShort( 0xe0 ),	/* Type Offset=224 */

	/* Return value */

/* 510 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 512 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 514 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemQueryInterface2 */

/* 516 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 518 */	NdrFcLong( 0x0 ),	/* 0 */
/* 522 */	NdrFcShort( 0x6 ),	/* 6 */
/* 524 */	NdrFcShort( 0x38 ),	/* X64 Stack size/offset = 56 */
/* 526 */	NdrFcShort( 0x4a ),	/* 74 */
/* 528 */	NdrFcShort( 0x8 ),	/* 8 */
/* 530 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 532 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 534 */	NdrFcShort( 0x1 ),	/* 1 */
/* 536 */	NdrFcShort( 0x1 ),	/* 1 */
/* 538 */	NdrFcShort( 0x0 ),	/* 0 */
/* 540 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ripid */

/* 542 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 544 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 546 */	NdrFcShort( 0x3a ),	/* Type Offset=58 */

	/* Parameter cIids */

/* 548 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 550 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 552 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter iids */

/* 554 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 556 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 558 */	NdrFcShort( 0x104 ),	/* Type Offset=260 */

	/* Parameter phr */

/* 560 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 562 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 564 */	NdrFcShort( 0x11e ),	/* Type Offset=286 */

	/* Parameter ppMIF */

/* 566 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 568 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 570 */	NdrFcShort( 0x142 ),	/* Type Offset=322 */

	/* Return value */

/* 572 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 574 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 576 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const RogueOxidResolver_MIDL_TYPE_FORMAT_STRING RogueOxidResolver__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/*  4 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/*  6 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/*  8 */	NdrFcShort( 0x2 ),	/* 2 */
/* 10 */	0x27,		/* Corr desc:  parameter, FC_USHORT */
			0x0,		/*  */
/* 12 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 14 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 16 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 18 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 20 */	NdrFcShort( 0x2 ),	/* Offset= 2 (22) */
/* 22 */	
			0x12, 0x0,	/* FC_UP */
/* 24 */	NdrFcShort( 0xe ),	/* Offset= 14 (38) */
/* 26 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 28 */	NdrFcShort( 0x2 ),	/* 2 */
/* 30 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 32 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 34 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 36 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 38 */	
			0x17,		/* FC_CSTRUCT */
			0x1,		/* 1 */
/* 40 */	NdrFcShort( 0x4 ),	/* 4 */
/* 42 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (26) */
/* 44 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 46 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 48 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 50 */	NdrFcShort( 0x8 ),	/* Offset= 8 (58) */
/* 52 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 54 */	NdrFcShort( 0x8 ),	/* 8 */
/* 56 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 58 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 60 */	NdrFcShort( 0x10 ),	/* 16 */
/* 62 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 64 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 66 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (52) */
			0x5b,		/* FC_END */
/* 70 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 72 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 74 */	
			0x12,		/* FC_UP */
			0x0,		/* 0 */
/* 76 */	NdrFcShort( 0x2 ),	/* Offset= 2 (78) */
/* 78 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 80 */	NdrFcShort( 0x8 ),	/* 8 */
/* 82 */	0x27,		/* Corr desc:  parameter, FC_USHORT */
			0x0,		/*  */
/* 84 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 86 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 88 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 90 */	
			0x12,		/* FC_UP */
			0x0,		/* 0 */
/* 92 */	NdrFcShort( 0x2 ),	/* Offset= 2 (94) */
/* 94 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 96 */	NdrFcShort( 0x8 ),	/* 8 */
/* 98 */	0x27,		/* Corr desc:  parameter, FC_USHORT */
			0x0,		/*  */
/* 100 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 102 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 104 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 106 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 108 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 110 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 112 */	NdrFcShort( 0x2 ),	/* Offset= 2 (114) */
/* 114 */	
			0x15,		/* FC_STRUCT */
			0x1,		/* 1 */
/* 116 */	NdrFcShort( 0x4 ),	/* 4 */
/* 118 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 120 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 122 */	
			0x11, 0x0,	/* FC_RP */
/* 124 */	NdrFcShort( 0xffbe ),	/* Offset= -66 (58) */
/* 126 */	
			0x11, 0x0,	/* FC_RP */
/* 128 */	NdrFcShort( 0x2 ),	/* Offset= 2 (130) */
/* 130 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 134 */	0x27,		/* Corr desc:  parameter, FC_USHORT */
			0x0,		/*  */
/* 136 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 138 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 140 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 144 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 146 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 148 */	NdrFcShort( 0xffa6 ),	/* Offset= -90 (58) */
/* 150 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 152 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 154 */	NdrFcShort( 0x2 ),	/* Offset= 2 (156) */
/* 156 */	
			0x13, 0x0,	/* FC_OP */
/* 158 */	NdrFcShort( 0x20 ),	/* Offset= 32 (190) */
/* 160 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 162 */	NdrFcShort( 0x28 ),	/* 40 */
/* 164 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 166 */	0xb,		/* FC_HYPER */
			0xb,		/* FC_HYPER */
/* 168 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 170 */	NdrFcShort( 0xff90 ),	/* Offset= -112 (58) */
/* 172 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 174 */	0xb1,		/* FC_FORCED_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 176 */	NdrFcShort( 0x30 ),	/* 48 */
/* 178 */	NdrFcShort( 0x0 ),	/* 0 */
/* 180 */	NdrFcShort( 0x0 ),	/* Offset= 0 (180) */
/* 182 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 184 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 186 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (160) */
/* 188 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 190 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x7,		/* 7 */
/* 192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 194 */	0x27,		/* Corr desc:  parameter, FC_USHORT */
			0x0,		/*  */
/* 196 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 198 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 200 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 204 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 206 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 208 */	NdrFcShort( 0xffde ),	/* Offset= -34 (174) */
/* 210 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 212 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 214 */	NdrFcShort( 0x18 ),	/* 24 */
/* 216 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 218 */	NdrFcShort( 0xff60 ),	/* Offset= -160 (58) */
/* 220 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 222 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 224 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 226 */	NdrFcShort( 0x18 ),	/* 24 */
/* 228 */	0x27,		/* Corr desc:  parameter, FC_USHORT */
			0x0,		/*  */
/* 230 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 232 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 234 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 236 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (212) */
/* 238 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 240 */	
			0x11, 0x0,	/* FC_RP */
/* 242 */	NdrFcShort( 0x2 ),	/* Offset= 2 (244) */
/* 244 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 246 */	NdrFcShort( 0x4 ),	/* 4 */
/* 248 */	0x27,		/* Corr desc:  parameter, FC_USHORT */
			0x0,		/*  */
/* 250 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 252 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 254 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 256 */	
			0x11, 0x0,	/* FC_RP */
/* 258 */	NdrFcShort( 0x2 ),	/* Offset= 2 (260) */
/* 260 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 262 */	NdrFcShort( 0x0 ),	/* 0 */
/* 264 */	0x27,		/* Corr desc:  parameter, FC_USHORT */
			0x0,		/*  */
/* 266 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 268 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 270 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 274 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 276 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 278 */	NdrFcShort( 0xff24 ),	/* Offset= -220 (58) */
/* 280 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 282 */	
			0x11, 0x0,	/* FC_RP */
/* 284 */	NdrFcShort( 0x2 ),	/* Offset= 2 (286) */
/* 286 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 288 */	NdrFcShort( 0x4 ),	/* 4 */
/* 290 */	0x27,		/* Corr desc:  parameter, FC_USHORT */
			0x0,		/*  */
/* 292 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 294 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 296 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 298 */	
			0x11, 0x0,	/* FC_RP */
/* 300 */	NdrFcShort( 0x16 ),	/* Offset= 22 (322) */
/* 302 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 304 */	NdrFcShort( 0x1 ),	/* 1 */
/* 306 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 308 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 310 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 312 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 314 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 316 */	NdrFcShort( 0x4 ),	/* 4 */
/* 318 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (302) */
/* 320 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 322 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 324 */	NdrFcShort( 0x0 ),	/* 0 */
/* 326 */	0x27,		/* Corr desc:  parameter, FC_USHORT */
			0x0,		/*  */
/* 328 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 330 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 332 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 336 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 338 */	
			0x13, 0x0,	/* FC_OP */
/* 340 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (314) */
/* 342 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */

			0x0
        }
    };


/* Standard interface: __MIDL_itf_RogueOxidResolver_0000_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Standard interface: IObjectExporter, ver. 0.0,
   GUID={0x99fcfec4,0x5260,0x101b,{0xbb,0xcb,0x00,0xaa,0x00,0x21,0x34,0x7a}} */


/* Standard interface: __MIDL_itf_RogueOxidResolver_0000_0001, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IRemUnknown, ver. 0.0,
   GUID={0x00000131,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IRemUnknown_FormatStringOffsetTable[] =
    {
    360,
    422,
    472
    };



/* Object interface: IRemUnknown2, ver. 0.0,
   GUID={0x00000143,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IRemUnknown2_FormatStringOffsetTable[] =
    {
    360,
    422,
    472,
    516
    };



/* Standard interface: __MIDL_itf_RogueOxidResolver_0000_0003, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


#endif /* defined(_M_AMD64)*/



/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 04:14:07 2038
 */
/* Compiler settings for RogueOxidResolver.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#if defined(_M_AMD64)




#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif


#include "ndr64types.h"
#include "pshpack8.h"


typedef 
NDR64_FORMAT_CHAR
__midl_frag50_t;
extern const __midl_frag50_t __midl_frag50;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag49_t;
extern const __midl_frag49_t __midl_frag49;

typedef 
NDR64_FORMAT_CHAR
__midl_frag48_t;
extern const __midl_frag48_t __midl_frag48;

typedef 
struct 
{
    NDR64_FORMAT_UINT32 frag1;
    struct _NDR64_EXPR_VAR frag2;
}
__midl_frag47_t;
extern const __midl_frag47_t __midl_frag47;

typedef 
struct 
{
    struct _NDR64_CONF_ARRAY_HEADER_FORMAT frag1;
    struct _NDR64_ARRAY_ELEMENT_INFO frag2;
}
__midl_frag46_t;
extern const __midl_frag46_t __midl_frag46;

typedef 
struct 
{
    struct _NDR64_CONF_STRUCTURE_HEADER_FORMAT frag1;
}
__midl_frag45_t;
extern const __midl_frag45_t __midl_frag45;

typedef 
struct 
{
    NDR64_FORMAT_UINT32 frag1;
    struct _NDR64_EXPR_VAR frag2;
}
__midl_frag44_t;
extern const __midl_frag44_t __midl_frag44;

typedef 
struct 
{
    struct _NDR64_CONF_ARRAY_HEADER_FORMAT frag1;
    struct 
    {
        struct _NDR64_REPEAT_FORMAT frag1;
        struct 
        {
            struct _NDR64_POINTER_INSTANCE_HEADER_FORMAT frag1;
            struct _NDR64_POINTER_FORMAT frag2;
        } frag2;
        NDR64_FORMAT_CHAR frag3;
    } frag2;
    struct _NDR64_ARRAY_ELEMENT_INFO frag3;
}
__midl_frag43_t;
extern const __midl_frag43_t __midl_frag43;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag42_t;
extern const __midl_frag42_t __midl_frag42;

typedef 
struct 
{
    struct _NDR64_CONF_ARRAY_HEADER_FORMAT frag1;
    struct _NDR64_ARRAY_ELEMENT_INFO frag2;
}
__midl_frag39_t;
extern const __midl_frag39_t __midl_frag39;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag38_t;
extern const __midl_frag38_t __midl_frag38;

typedef 
struct 
{
    struct _NDR64_CONF_ARRAY_HEADER_FORMAT frag1;
    struct _NDR64_ARRAY_ELEMENT_INFO frag2;
}
__midl_frag36_t;
extern const __midl_frag36_t __midl_frag36;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag35_t;
extern const __midl_frag35_t __midl_frag35;

typedef 
NDR64_FORMAT_CHAR
__midl_frag34_t;
extern const __midl_frag34_t __midl_frag34;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag33_t;
extern const __midl_frag33_t __midl_frag33;

typedef 
struct 
{
    struct _NDR64_PROC_FORMAT frag1;
    struct _NDR64_PARAM_FORMAT frag2;
    struct _NDR64_PARAM_FORMAT frag3;
    struct _NDR64_PARAM_FORMAT frag4;
    struct _NDR64_PARAM_FORMAT frag5;
    struct _NDR64_PARAM_FORMAT frag6;
    struct _NDR64_PARAM_FORMAT frag7;
}
__midl_frag32_t;
extern const __midl_frag32_t __midl_frag32;

typedef 
struct 
{
    NDR64_FORMAT_UINT32 frag1;
    struct _NDR64_EXPR_VAR frag2;
}
__midl_frag30_t;
extern const __midl_frag30_t __midl_frag30;

typedef 
struct 
{
    struct _NDR64_CONF_ARRAY_HEADER_FORMAT frag1;
    struct _NDR64_ARRAY_ELEMENT_INFO frag2;
}
__midl_frag29_t;
extern const __midl_frag29_t __midl_frag29;

typedef 
struct 
{
    struct _NDR64_PROC_FORMAT frag1;
    struct _NDR64_PARAM_FORMAT frag2;
    struct _NDR64_PARAM_FORMAT frag3;
    struct _NDR64_PARAM_FORMAT frag4;
}
__midl_frag27_t;
extern const __midl_frag27_t __midl_frag27;

typedef 
struct 
{
    struct _NDR64_CONF_ARRAY_HEADER_FORMAT frag1;
    struct _NDR64_ARRAY_ELEMENT_INFO frag2;
}
__midl_frag23_t;
extern const __midl_frag23_t __midl_frag23;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag22_t;
extern const __midl_frag22_t __midl_frag22;

typedef 
struct 
{
    struct _NDR64_STRUCTURE_HEADER_FORMAT frag1;
}
__midl_frag21_t;
extern const __midl_frag21_t __midl_frag21;

typedef 
struct 
{
    struct _NDR64_PROC_FORMAT frag1;
    struct _NDR64_PARAM_FORMAT frag2;
    struct _NDR64_PARAM_FORMAT frag3;
    struct _NDR64_PARAM_FORMAT frag4;
    struct _NDR64_PARAM_FORMAT frag5;
}
__midl_frag17_t;
extern const __midl_frag17_t __midl_frag17;

typedef 
struct 
{
    struct _NDR64_FIX_ARRAY_HEADER_FORMAT frag1;
}
__midl_frag15_t;
extern const __midl_frag15_t __midl_frag15;

typedef 
struct 
{
    struct _NDR64_BOGUS_STRUCTURE_HEADER_FORMAT frag1;
    struct 
    {
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag1;
        struct _NDR64_MEMPAD_FORMAT frag2;
        struct _NDR64_BUFFER_ALIGN_FORMAT frag3;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag4;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag5;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag6;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag7;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag8;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag9;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag10;
        struct _NDR64_EMBEDDED_COMPLEX_FORMAT frag11;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag12;
    } frag2;
}
__midl_frag14_t;
extern const __midl_frag14_t __midl_frag14;

typedef 
struct 
{
    NDR64_FORMAT_UINT32 frag1;
    struct _NDR64_EXPR_VAR frag2;
}
__midl_frag13_t;
extern const __midl_frag13_t __midl_frag13;

typedef 
struct 
{
    struct _NDR64_CONF_VAR_BOGUS_ARRAY_HEADER_FORMAT frag1;
}
__midl_frag12_t;
extern const __midl_frag12_t __midl_frag12;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag11_t;
extern const __midl_frag11_t __midl_frag11;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag10_t;
extern const __midl_frag10_t __midl_frag10;

typedef 
struct 
{
    struct _NDR64_CONF_ARRAY_HEADER_FORMAT frag1;
    struct _NDR64_ARRAY_ELEMENT_INFO frag2;
}
__midl_frag8_t;
extern const __midl_frag8_t __midl_frag8;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag7_t;
extern const __midl_frag7_t __midl_frag7;

typedef 
struct 
{
    struct _NDR64_STRUCTURE_HEADER_FORMAT frag1;
}
__midl_frag4_t;
extern const __midl_frag4_t __midl_frag4;

typedef 
struct 
{
    struct _NDR64_PROC_FORMAT frag1;
    struct _NDR64_PARAM_FORMAT frag2;
    struct _NDR64_PARAM_FORMAT frag3;
    struct _NDR64_PARAM_FORMAT frag4;
    struct _NDR64_PARAM_FORMAT frag5;
    struct _NDR64_PARAM_FORMAT frag6;
    struct _NDR64_PARAM_FORMAT frag7;
}
__midl_frag2_t;
extern const __midl_frag2_t __midl_frag2;

typedef 
NDR64_FORMAT_UINT32
__midl_frag1_t;
extern const __midl_frag1_t __midl_frag1;

static const __midl_frag50_t __midl_frag50 =
0x5    /* FC64_INT32 */;

static const __midl_frag49_t __midl_frag49 =
{ 
/* *MInterfacePointer */
    0x22,    /* FC64_OP */
    (NDR64_UINT8) 0 /* 0x0 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag45
};

static const __midl_frag48_t __midl_frag48 =
0x2    /* FC64_INT8 */;

static const __midl_frag47_t __midl_frag47 =
{ 
/*  */
    (NDR64_UINT32) 1 /* 0x1 */,
    { 
    /* struct _NDR64_EXPR_VAR */
        0x3,    /* FC_EXPR_VAR */
        0x6,    /* FC64_UINT32 */
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT32) 0 /* 0x0 */
    }
};

static const __midl_frag46_t __midl_frag46 =
{ 
/*  */
    { 
    /* struct _NDR64_CONF_ARRAY_HEADER_FORMAT */
        0x41,    /* FC64_CONF_ARRAY */
        (NDR64_UINT8) 0 /* 0x0 */,
        { 
        /* struct _NDR64_CONF_ARRAY_HEADER_FORMAT */
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 1 /* 0x1 */,
        &__midl_frag47
    },
    { 
    /* struct _NDR64_ARRAY_ELEMENT_INFO */
        (NDR64_UINT32) 1 /* 0x1 */,
        &__midl_frag48
    }
};

static const __midl_frag45_t __midl_frag45 =
{ 
/* MInterfacePointer */
    { 
    /* MInterfacePointer */
        0x32,    /* FC64_CONF_STRUCT */
        (NDR64_UINT8) 3 /* 0x3 */,
        { 
        /* MInterfacePointer */
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 4 /* 0x4 */,
        &__midl_frag46
    }
};

static const __midl_frag44_t __midl_frag44 =
{ 
/*  */
    (NDR64_UINT32) 1 /* 0x1 */,
    { 
    /* struct _NDR64_EXPR_VAR */
        0x3,    /* FC_EXPR_VAR */
        0x3,    /* FC64_UINT16 */
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT32) 16 /* 0x10 */  /* Offset */
    }
};

static const __midl_frag43_t __midl_frag43 =
{ 
/* **MInterfacePointer */
    { 
    /* **MInterfacePointer */
        0x41,    /* FC64_CONF_ARRAY */
        (NDR64_UINT8) 7 /* 0x7 */,
        { 
        /* **MInterfacePointer */
            1,
            0,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 8 /* 0x8 */,
        &__midl_frag44
    },
    { 
    /*  */
        { 
        /* struct _NDR64_REPEAT_FORMAT */
            0x82,    /* FC64_VARIABLE_REPEAT */
            { 
            /* struct _NDR64_REPEAT_FORMAT */
                (NDR64_UINT8) 0 /* 0x0 */,
                (NDR64_UINT8) 0 /* 0x0 */
            },
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 8 /* 0x8 */,
            (NDR64_UINT32) 0 /* 0x0 */,
            (NDR64_UINT32) 1 /* 0x1 */
        },
        { 
        /*  */
            { 
            /* struct _NDR64_POINTER_INSTANCE_HEADER_FORMAT */
                (NDR64_UINT32) 0 /* 0x0 */,
                (NDR64_UINT32) 0 /* 0x0 */
            },
            { 
            /* *MInterfacePointer */
                0x22,    /* FC64_OP */
                (NDR64_UINT8) 0 /* 0x0 */,
                (NDR64_UINT16) 0 /* 0x0 */,
                &__midl_frag45
            }
        },
        0x93    /* FC64_END */
    },
    { 
    /* struct _NDR64_ARRAY_ELEMENT_INFO */
        (NDR64_UINT32) 8 /* 0x8 */,
        &__midl_frag49
    }
};

static const __midl_frag42_t __midl_frag42 =
{ 
/* **MInterfacePointer */
    0x20,    /* FC64_RP */
    (NDR64_UINT8) 0 /* 0x0 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag43
};

static const __midl_frag39_t __midl_frag39 =
{ 
/* *HRESULT */
    { 
    /* *HRESULT */
        0x41,    /* FC64_CONF_ARRAY */
        (NDR64_UINT8) 3 /* 0x3 */,
        { 
        /* *HRESULT */
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 4 /* 0x4 */,
        &__midl_frag44
    },
    { 
    /* struct _NDR64_ARRAY_ELEMENT_INFO */
        (NDR64_UINT32) 4 /* 0x4 */,
        &__midl_frag50
    }
};

static const __midl_frag38_t __midl_frag38 =
{ 
/* *HRESULT */
    0x20,    /* FC64_RP */
    (NDR64_UINT8) 0 /* 0x0 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag39
};

static const __midl_frag36_t __midl_frag36 =
{ 
/* *IID */
    { 
    /* *IID */
        0x41,    /* FC64_CONF_ARRAY */
        (NDR64_UINT8) 3 /* 0x3 */,
        { 
        /* *IID */
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 16 /* 0x10 */,
        &__midl_frag44
    },
    { 
    /* struct _NDR64_ARRAY_ELEMENT_INFO */
        (NDR64_UINT32) 16 /* 0x10 */,
        &__midl_frag4
    }
};

static const __midl_frag35_t __midl_frag35 =
{ 
/* *IID */
    0x20,    /* FC64_RP */
    (NDR64_UINT8) 0 /* 0x0 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag36
};

static const __midl_frag34_t __midl_frag34 =
0x4    /* FC64_INT16 */;

static const __midl_frag33_t __midl_frag33 =
{ 
/* *IID */
    0x20,    /* FC64_RP */
    (NDR64_UINT8) 0 /* 0x0 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag4
};

static const __midl_frag32_t __midl_frag32 =
{ 
/* RemQueryInterface2 */
    { 
    /* RemQueryInterface2 */      /* procedure RemQueryInterface2 */
        (NDR64_UINT32) 7209283 /* 0x6e0143 */,    /* auto handle */ /* IsIntrepreted, [object], ServerMustSize, ClientMustSize, HasReturn, ServerCorrelation, ClientCorrelation */
        (NDR64_UINT32) 56 /* 0x38 */ ,  /* Stack size */
        (NDR64_UINT32) 78 /* 0x4e */,
        (NDR64_UINT32) 8 /* 0x8 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 6 /* 0x6 */,
        (NDR64_UINT16) 0 /* 0x0 */
    },
    { 
    /* ripid */      /* parameter ripid */
        &__midl_frag4,
        { 
        /* ripid */
            0,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* MustFree, [in], SimpleRef */
        (NDR64_UINT16) 0 /* 0x0 */,
        8 /* 0x8 */,   /* Stack offset */
    },
    { 
    /* cIids */      /* parameter cIids */
        &__midl_frag34,
        { 
        /* cIids */
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [in], Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        16 /* 0x10 */,   /* Stack offset */
    },
    { 
    /* iids */      /* parameter iids */
        &__midl_frag36,
        { 
        /* iids */
            1,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* MustSize, MustFree, [in], SimpleRef */
        (NDR64_UINT16) 0 /* 0x0 */,
        24 /* 0x18 */,   /* Stack offset */
    },
    { 
    /* phr */      /* parameter phr */
        &__midl_frag39,
        { 
        /* phr */
            1,
            1,
            0,
            0,
            1,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* MustSize, MustFree, [out], SimpleRef */
        (NDR64_UINT16) 0 /* 0x0 */,
        32 /* 0x20 */,   /* Stack offset */
    },
    { 
    /* ppMIF */      /* parameter ppMIF */
        &__midl_frag43,
        { 
        /* ppMIF */
            1,
            1,
            0,
            0,
            1,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* MustSize, MustFree, [out], SimpleRef */
        (NDR64_UINT16) 0 /* 0x0 */,
        40 /* 0x28 */,   /* Stack offset */
    },
    { 
    /* HRESULT */      /* parameter HRESULT */
        &__midl_frag50,
        { 
        /* HRESULT */
            0,
            0,
            0,
            0,
            1,
            1,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [out], IsReturn, Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        48 /* 0x30 */,   /* Stack offset */
    }
};

static const __midl_frag30_t __midl_frag30 =
{ 
/*  */
    (NDR64_UINT32) 1 /* 0x1 */,
    { 
    /* struct _NDR64_EXPR_VAR */
        0x3,    /* FC_EXPR_VAR */
        0x3,    /* FC64_UINT16 */
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT32) 8 /* 0x8 */  /* Offset */
    }
};

static const __midl_frag29_t __midl_frag29 =
{ 
/*  */
    { 
    /* struct _NDR64_CONF_ARRAY_HEADER_FORMAT */
        0x41,    /* FC64_CONF_ARRAY */
        (NDR64_UINT8) 3 /* 0x3 */,
        { 
        /* struct _NDR64_CONF_ARRAY_HEADER_FORMAT */
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 24 /* 0x18 */,
        &__midl_frag30
    },
    { 
    /* struct _NDR64_ARRAY_ELEMENT_INFO */
        (NDR64_UINT32) 24 /* 0x18 */,
        &__midl_frag21
    }
};

static const __midl_frag27_t __midl_frag27 =
{ 
/* RemRelease */
    { 
    /* RemRelease */      /* procedure RemRelease */
        (NDR64_UINT32) 2883907 /* 0x2c0143 */,    /* auto handle */ /* IsIntrepreted, [object], ClientMustSize, HasReturn, ServerCorrelation */
        (NDR64_UINT32) 32 /* 0x20 */ ,  /* Stack size */
        (NDR64_UINT32) 6 /* 0x6 */,
        (NDR64_UINT32) 8 /* 0x8 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 3 /* 0x3 */,
        (NDR64_UINT16) 0 /* 0x0 */
    },
    { 
    /* cInterfaceRefs */      /* parameter cInterfaceRefs */
        &__midl_frag34,
        { 
        /* cInterfaceRefs */
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [in], Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        8 /* 0x8 */,   /* Stack offset */
    },
    { 
    /* InterfaceRefs */      /* parameter InterfaceRefs */
        &__midl_frag29,
        { 
        /* InterfaceRefs */
            1,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* MustSize, MustFree, [in] */
        (NDR64_UINT16) 0 /* 0x0 */,
        16 /* 0x10 */,   /* Stack offset */
    },
    { 
    /* HRESULT */      /* parameter HRESULT */
        &__midl_frag50,
        { 
        /* HRESULT */
            0,
            0,
            0,
            0,
            1,
            1,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [out], IsReturn, Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        24 /* 0x18 */,   /* Stack offset */
    }
};

static const __midl_frag23_t __midl_frag23 =
{ 
/* *HRESULT */
    { 
    /* *HRESULT */
        0x41,    /* FC64_CONF_ARRAY */
        (NDR64_UINT8) 3 /* 0x3 */,
        { 
        /* *HRESULT */
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 4 /* 0x4 */,
        &__midl_frag30
    },
    { 
    /* struct _NDR64_ARRAY_ELEMENT_INFO */
        (NDR64_UINT32) 4 /* 0x4 */,
        &__midl_frag50
    }
};

static const __midl_frag22_t __midl_frag22 =
{ 
/* *HRESULT */
    0x20,    /* FC64_RP */
    (NDR64_UINT8) 0 /* 0x0 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag23
};

static const __midl_frag21_t __midl_frag21 =
{ 
/* REMINTERFACEREF */
    { 
    /* REMINTERFACEREF */
        0x30,    /* FC64_STRUCT */
        (NDR64_UINT8) 3 /* 0x3 */,
        { 
        /* REMINTERFACEREF */
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 24 /* 0x18 */
    }
};

static const __midl_frag17_t __midl_frag17 =
{ 
/* RemAddRef */
    { 
    /* RemAddRef */      /* procedure RemAddRef */
        (NDR64_UINT32) 7209283 /* 0x6e0143 */,    /* auto handle */ /* IsIntrepreted, [object], ServerMustSize, ClientMustSize, HasReturn, ServerCorrelation, ClientCorrelation */
        (NDR64_UINT32) 40 /* 0x28 */ ,  /* Stack size */
        (NDR64_UINT32) 6 /* 0x6 */,
        (NDR64_UINT32) 8 /* 0x8 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 4 /* 0x4 */,
        (NDR64_UINT16) 0 /* 0x0 */
    },
    { 
    /* cInterfaceRefs */      /* parameter cInterfaceRefs */
        &__midl_frag34,
        { 
        /* cInterfaceRefs */
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [in], Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        8 /* 0x8 */,   /* Stack offset */
    },
    { 
    /* InterfaceRefs */      /* parameter InterfaceRefs */
        &__midl_frag29,
        { 
        /* InterfaceRefs */
            1,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* MustSize, MustFree, [in] */
        (NDR64_UINT16) 0 /* 0x0 */,
        16 /* 0x10 */,   /* Stack offset */
    },
    { 
    /* pResults */      /* parameter pResults */
        &__midl_frag23,
        { 
        /* pResults */
            1,
            1,
            0,
            0,
            1,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* MustSize, MustFree, [out], SimpleRef */
        (NDR64_UINT16) 0 /* 0x0 */,
        24 /* 0x18 */,   /* Stack offset */
    },
    { 
    /* HRESULT */      /* parameter HRESULT */
        &__midl_frag50,
        { 
        /* HRESULT */
            0,
            0,
            0,
            0,
            1,
            1,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [out], IsReturn, Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        32 /* 0x20 */,   /* Stack offset */
    }
};

static const __midl_frag15_t __midl_frag15 =
{ 
/*  */
    { 
    /* struct _NDR64_FIX_ARRAY_HEADER_FORMAT */
        0x40,    /* FC64_FIX_ARRAY */
        (NDR64_UINT8) 0 /* 0x0 */,
        { 
        /* struct _NDR64_FIX_ARRAY_HEADER_FORMAT */
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 8 /* 0x8 */
    }
};

static const __midl_frag14_t __midl_frag14 =
{ 
/* REMQIRESULT */
    { 
    /* REMQIRESULT */
        0x35,    /* FC64_FORCED_BOGUS_STRUCT */
        (NDR64_UINT8) 7 /* 0x7 */,
        { 
        /* REMQIRESULT */
            0,
            1,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 48 /* 0x30 */,
        0,
        0,
        0,
    },
    { 
    /*  */
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x5,    /* FC64_INT32 */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_MEMPAD_FORMAT */
            0x90,    /* FC64_STRUCTPADN */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 4 /* 0x4 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* STDOBJREF */
            0x92,    /* FC64_BUFFER_ALIGN */
            (NDR64_UINT8) 7 /* 0x7 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x5,    /* FC64_INT32 */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x5,    /* FC64_INT32 */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x7,    /* FC64_INT64 */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x7,    /* FC64_INT64 */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x5,    /* FC64_INT32 */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x4,    /* FC64_INT16 */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x4,    /* FC64_INT16 */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_EMBEDDED_COMPLEX_FORMAT */
            0x91,    /* FC64_EMBEDDED_COMPLEX */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            &__midl_frag15
        },
        { 
        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
            0x93,    /* FC64_END */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        }
    }
};

static const __midl_frag13_t __midl_frag13 =
{ 
/*  */
    (NDR64_UINT32) 1 /* 0x1 */,
    { 
    /* struct _NDR64_EXPR_VAR */
        0x3,    /* FC_EXPR_VAR */
        0x3,    /* FC64_UINT16 */
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT32) 24 /* 0x18 */  /* Offset */
    }
};

static const __midl_frag12_t __midl_frag12 =
{ 
/* *REMQIRESULT */
    { 
    /* *REMQIRESULT */
        { 
        /* *REMQIRESULT */
            0x46,    /* FC64_FORCED_BOGUS_ARRAY */
            (NDR64_UINT8) 7 /* 0x7 */,
            { 
            /* *REMQIRESULT */
                0,
                1,
                0,
                0,
                0,
                0,
                0,
                0
            },
            (NDR64_UINT8) 1 /* 0x1 */,
            (NDR64_UINT32) 0 /* 0x0 */,
            &__midl_frag14
        },
        &__midl_frag13,
        0,
        0
    }
};

static const __midl_frag11_t __midl_frag11 =
{ 
/* *REMQIRESULT */
    0x22,    /* FC64_OP */
    (NDR64_UINT8) 0 /* 0x0 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag12
};

static const __midl_frag10_t __midl_frag10 =
{ 
/* **REMQIRESULT */
    0x20,    /* FC64_RP */
    (NDR64_UINT8) 20 /* 0x14 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag11
};

static const __midl_frag8_t __midl_frag8 =
{ 
/* *IID */
    { 
    /* *IID */
        0x41,    /* FC64_CONF_ARRAY */
        (NDR64_UINT8) 3 /* 0x3 */,
        { 
        /* *IID */
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 16 /* 0x10 */,
        &__midl_frag13
    },
    { 
    /* struct _NDR64_ARRAY_ELEMENT_INFO */
        (NDR64_UINT32) 16 /* 0x10 */,
        &__midl_frag4
    }
};

static const __midl_frag7_t __midl_frag7 =
{ 
/* *IID */
    0x20,    /* FC64_RP */
    (NDR64_UINT8) 0 /* 0x0 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag8
};

static const __midl_frag4_t __midl_frag4 =
{ 
/* IID */
    { 
    /* IID */
        0x30,    /* FC64_STRUCT */
        (NDR64_UINT8) 3 /* 0x3 */,
        { 
        /* IID */
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 16 /* 0x10 */
    }
};

static const __midl_frag2_t __midl_frag2 =
{ 
/* RemQueryInterface */
    { 
    /* RemQueryInterface */      /* procedure RemQueryInterface */
        (NDR64_UINT32) 7209283 /* 0x6e0143 */,    /* auto handle */ /* IsIntrepreted, [object], ServerMustSize, ClientMustSize, HasReturn, ServerCorrelation, ClientCorrelation */
        (NDR64_UINT32) 56 /* 0x38 */ ,  /* Stack size */
        (NDR64_UINT32) 86 /* 0x56 */,
        (NDR64_UINT32) 8 /* 0x8 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 6 /* 0x6 */,
        (NDR64_UINT16) 0 /* 0x0 */
    },
    { 
    /* ripid */      /* parameter ripid */
        &__midl_frag4,
        { 
        /* ripid */
            0,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* MustFree, [in], SimpleRef */
        (NDR64_UINT16) 0 /* 0x0 */,
        8 /* 0x8 */,   /* Stack offset */
    },
    { 
    /* cRefs */      /* parameter cRefs */
        &__midl_frag50,
        { 
        /* cRefs */
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [in], Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        16 /* 0x10 */,   /* Stack offset */
    },
    { 
    /* cIids */      /* parameter cIids */
        &__midl_frag34,
        { 
        /* cIids */
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [in], Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        24 /* 0x18 */,   /* Stack offset */
    },
    { 
    /* iids */      /* parameter iids */
        &__midl_frag8,
        { 
        /* iids */
            1,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* MustSize, MustFree, [in], SimpleRef */
        (NDR64_UINT16) 0 /* 0x0 */,
        32 /* 0x20 */,   /* Stack offset */
    },
    { 
    /* ppQIResults */      /* parameter ppQIResults */
        &__midl_frag10,
        { 
        /* ppQIResults */
            1,
            1,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            1
        },    /* MustSize, MustFree, [out], UseCache */
        (NDR64_UINT16) 0 /* 0x0 */,
        40 /* 0x28 */,   /* Stack offset */
    },
    { 
    /* HRESULT */      /* parameter HRESULT */
        &__midl_frag50,
        { 
        /* HRESULT */
            0,
            0,
            0,
            0,
            1,
            1,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [out], IsReturn, Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        48 /* 0x30 */,   /* Stack offset */
    }
};

static const __midl_frag1_t __midl_frag1 =
(NDR64_UINT32) 0 /* 0x0 */;


#include "poppack.h"



/* Standard interface: __MIDL_itf_RogueOxidResolver_0000_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Standard interface: IObjectExporter, ver. 0.0,
   GUID={0x99fcfec4,0x5260,0x101b,{0xbb,0xcb,0x00,0xaa,0x00,0x21,0x34,0x7a}} */


/* Standard interface: __MIDL_itf_RogueOxidResolver_0000_0001, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IRemUnknown, ver. 0.0,
   GUID={0x00000131,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const FormatInfoRef IRemUnknown_Ndr64ProcTable[] =
    {
    &__midl_frag2,
    &__midl_frag17,
    &__midl_frag27
    };


static const MIDL_SYNTAX_INFO IRemUnknown_SyntaxInfo [  2 ] = 
    {
    {
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    0,
    RogueOxidResolver__MIDL_ProcFormatString.Format,
    &IRemUnknown_FormatStringOffsetTable[-3],
    RogueOxidResolver__MIDL_TypeFormatString.Format,
    0,
    0,
    0
    }
    ,{
    {{0x71710533,0xbeba,0x4937,{0x83,0x19,0xb5,0xdb,0xef,0x9c,0xcc,0x36}},{1,0}},
    0,
    0 ,
    (unsigned short *) &IRemUnknown_Ndr64ProcTable[-3],
    0,
    0,
    0,
    0
    }
    };

static const MIDL_STUBLESS_PROXY_INFO IRemUnknown_ProxyInfo =
    {
    &Object_StubDesc,
    RogueOxidResolver__MIDL_ProcFormatString.Format,
    &IRemUnknown_FormatStringOffsetTable[-3],
    (RPC_SYNTAX_IDENTIFIER*)&_RpcTransferSyntax,
    2,
    (MIDL_SYNTAX_INFO*)IRemUnknown_SyntaxInfo
    
    };


static const MIDL_SERVER_INFO IRemUnknown_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    RogueOxidResolver__MIDL_ProcFormatString.Format,
    (unsigned short *) &IRemUnknown_FormatStringOffsetTable[-3],
    0,
    (RPC_SYNTAX_IDENTIFIER*)&_NDR64_RpcTransferSyntax,
    2,
    (MIDL_SYNTAX_INFO*)IRemUnknown_SyntaxInfo
    };
CINTERFACE_PROXY_VTABLE(6) _IRemUnknownProxyVtbl = 
{
    &IRemUnknown_ProxyInfo,
    &IID_IRemUnknown,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IRemUnknown::RemQueryInterface */ ,
    (void *) (INT_PTR) -1 /* IRemUnknown::RemAddRef */ ,
    (void *) (INT_PTR) -1 /* IRemUnknown::RemRelease */
};

const CInterfaceStubVtbl _IRemUnknownStubVtbl =
{
    &IID_IRemUnknown,
    &IRemUnknown_ServerInfo,
    6,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IRemUnknown2, ver. 0.0,
   GUID={0x00000143,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const FormatInfoRef IRemUnknown2_Ndr64ProcTable[] =
    {
    &__midl_frag2,
    &__midl_frag17,
    &__midl_frag27,
    &__midl_frag32
    };


static const MIDL_SYNTAX_INFO IRemUnknown2_SyntaxInfo [  2 ] = 
    {
    {
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    0,
    RogueOxidResolver__MIDL_ProcFormatString.Format,
    &IRemUnknown2_FormatStringOffsetTable[-3],
    RogueOxidResolver__MIDL_TypeFormatString.Format,
    0,
    0,
    0
    }
    ,{
    {{0x71710533,0xbeba,0x4937,{0x83,0x19,0xb5,0xdb,0xef,0x9c,0xcc,0x36}},{1,0}},
    0,
    0 ,
    (unsigned short *) &IRemUnknown2_Ndr64ProcTable[-3],
    0,
    0,
    0,
    0
    }
    };

static const MIDL_STUBLESS_PROXY_INFO IRemUnknown2_ProxyInfo =
    {
    &Object_StubDesc,
    RogueOxidResolver__MIDL_ProcFormatString.Format,
    &IRemUnknown2_FormatStringOffsetTable[-3],
    (RPC_SYNTAX_IDENTIFIER*)&_RpcTransferSyntax,
    2,
    (MIDL_SYNTAX_INFO*)IRemUnknown2_SyntaxInfo
    
    };


static const MIDL_SERVER_INFO IRemUnknown2_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    RogueOxidResolver__MIDL_ProcFormatString.Format,
    (unsigned short *) &IRemUnknown2_FormatStringOffsetTable[-3],
    0,
    (RPC_SYNTAX_IDENTIFIER*)&_NDR64_RpcTransferSyntax,
    2,
    (MIDL_SYNTAX_INFO*)IRemUnknown2_SyntaxInfo
    };
CINTERFACE_PROXY_VTABLE(7) _IRemUnknown2ProxyVtbl = 
{
    &IRemUnknown2_ProxyInfo,
    &IID_IRemUnknown2,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IRemUnknown::RemQueryInterface */ ,
    (void *) (INT_PTR) -1 /* IRemUnknown::RemAddRef */ ,
    (void *) (INT_PTR) -1 /* IRemUnknown::RemRelease */ ,
    (void *) (INT_PTR) -1 /* IRemUnknown2::RemQueryInterface2 */
};

const CInterfaceStubVtbl _IRemUnknown2StubVtbl =
{
    &IID_IRemUnknown2,
    &IRemUnknown2_ServerInfo,
    7,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Standard interface: __MIDL_itf_RogueOxidResolver_0000_0003, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    RogueOxidResolver__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x60001, /* Ndr library version */
    0,
    0x801026e, /* MIDL Version 8.1.622 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    0x2000001, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * const _RogueOxidResolver_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IRemUnknownProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRemUnknown2ProxyVtbl,
    0
};

const CInterfaceStubVtbl * const _RogueOxidResolver_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IRemUnknownStubVtbl,
    ( CInterfaceStubVtbl *) &_IRemUnknown2StubVtbl,
    0
};

PCInterfaceName const _RogueOxidResolver_InterfaceNamesList[] = 
{
    "IRemUnknown",
    "IRemUnknown2",
    0
};


#define _RogueOxidResolver_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _RogueOxidResolver, pIID, n)

int __stdcall _RogueOxidResolver_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _RogueOxidResolver, 2, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _RogueOxidResolver, 2, *pIndex )
    
}

const ExtendedProxyFileInfo RogueOxidResolver_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _RogueOxidResolver_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _RogueOxidResolver_StubVtblList,
    (const PCInterfaceName * ) & _RogueOxidResolver_InterfaceNamesList,
    0, /* no delegation */
    & _RogueOxidResolver_IID_Lookup, 
    2,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* defined(_M_AMD64)*/

