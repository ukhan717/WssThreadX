 /*
  *     ____             _________                __                _
  *    / __ \___  ____ _/ /_  __(_)___ ___  ___  / /   ____  ____ _(_)____
  *   / /_/ / _ \/ __ `/ / / / / / __ `__ \/ _ \/ /   / __ \/ __ `/ / ___/
  *  / _, _/  __/ /_/ / / / / / / / / / / /  __/ /___/ /_/ / /_/ / / /__
  * /_/ |_|\___/\__,_/_/ /_/ /_/_/ /_/ /_/\___/_____/\____/\__, /_/\___/
  *                                                       /____/
  *
  *                 SharkSSL Embedded SSL/TLS Stack
  ****************************************************************************
  *   PROGRAM MODULE
  *
  *   $Id: SharkSslSCMgr.h 4915 2021-12-01 18:26:55Z wini $
  *
  *   COPYRIGHT:  Real Time Logic LLC, 2013
  *
  *   This software is copyrighted by and is the sole property of Real
  *   Time Logic LLC.  All rights, title, ownership, or other interests in
  *   the software remain the property of Real Time Logic LLC.  This
  *   software may only be used in accordance with the terms and
  *   conditions stipulated in the corresponding license agreement under
  *   which the software has been supplied.  Any unauthorized use,
  *   duplication, transmission, distribution, or disclosure of this
  *   software is expressly forbidden.
  *
  *   This Copyright notice may not be removed or modified without prior
  *   written consent of Real Time Logic LLC.
  *
  *   Real Time Logic LLC. reserves the right to modify this software
  *   without notice.
  *
  *               http://www.realtimelogic.com
  *               http://www.sharkssl.com
  ****************************************************************************
  *
  */
 #ifndef _SharkSslSCMgr_h
 #define _SharkSslSCMgr_h
  
 #include <SharkSslEx.h>
 #include "SplayTree.h"
 #include "DoubleList.h"
  
 #ifndef SHARKSSL_API
 #define SHARKSSL_API
 #else  /* Barracuda */
 #define SHARKSSL_BA 1
 #endif 
  
  
 typedef struct
 {
    SplayTreeNode super;
    DoubleLink dlink;
    SharkSslSession* ss;
    const char* host;
    U16 hostLen;
    U16 port;
 } SharkSslSCMgrNode;
  
  
  
 typedef struct
 {
    SharkSslIntf super;
    SplayTree stree;
    DoubleList dlist;
    SharkSsl* ssl;
    U32 maxTime;
    int noOfSessions;
 } SharkSslSCMgr;
  
  
 #ifdef __cplusplus
 extern "C" {
 #endif
  
 SHARKSSL_API void SharkSslSCMgr_constructor(
    SharkSslSCMgr* o, SharkSsl* ssl, U32 maxTime);
  
 SHARKSSL_API SharkSslSCMgrNode* SharkSslSCMgr_get(
    SharkSslSCMgr* o,SharkSslCon* scon,const char* host,U16 port);
  
 SHARKSSL_API void SharkSslSCMgr_save(
    SharkSslSCMgr* o, SharkSslCon* scon,
    const char* host, U16 port,  SharkSslSCMgrNode* n);
  
 #ifdef __cplusplus
 }
 #endif
  /* end group SharkSslSCMgr */ 
  
 #endif