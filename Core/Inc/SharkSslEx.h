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
  *   $Id: SharkSslEx.h 5100 2022-02-19 16:23:57Z wini $
  *
  *   COPYRIGHT:  Real Time Logic LLC, 2013 - 2022
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
 #ifndef _SharkSslEx_h
 #define _SharkSslEx_h
  
 #include "SharkSSL.h"
  
 /* Macro set if compiled together with BAS */
 #ifndef ThreadLib_hpp
 #ifndef BaTime
 #include <time.h>
 typedef time_t BaTime;
 #endif
 #endif
  
 typedef struct SubjectAltNameEnumerator
 {
    U8 *ptr, *dataptr; 
    U32 len,  datalen;
 }
 SubjectAltNameEnumerator;  
  
 typedef struct SubjectAltName
 {
    U8  *ptr;
    U16 len;
    U8  tag;
 } SubjectAltName;
  
 #define SubjectAltName_getTag(o)   ((o)->tag)
 #define SubjectAltName_getLen(o)   ((o)->len)
 #define SubjectAltName_getPtr(o)   ((o)->ptr)
 #define SubjectAltName_isValid(o)  (NULL != SubjectAltName_getPtr(o))
  
 SHARKSSL_API void SubjectAltNameEnumerator_constructor(SubjectAltNameEnumerator *o, U8 *ptr, U16 len);
 SHARKSSL_API void SubjectAltNameEnumerator_getElement(SubjectAltNameEnumerator *o, SubjectAltName *s);
 #define SubjectAltNameEnumerator_nextElement SubjectAltNameEnumerator_getElement
  
 #define SUBJECTALTNAME_OTHERNAME         0
 #define SUBJECTALTNAME_RFC822NAME        1
 #define SUBJECTALTNAME_DNSNAME           2
 #define SUBJECTALTNAME_X400ADDRESS       3
 #define SUBJECTALTNAME_DIRECTORYNAME     4
 #define SUBJECTALTNAME_EDIPARTYNAME      5
 #define SUBJECTALTNAME_URI               6
 #define SUBJECTALTNAME_IPADDRESS         7
  
  
 SHARKSSL_API int sharkStrCaseCmp(
    const char *a, int aLen, const char *b, int bLen);
  
  
 SHARKSSL_API int sharkSubjectSubjectAltCmp(
    const char *cn, U16 cnLen, U8 *subjAltPtr, U16 subjAltLen, const char* name, U16 nameLen);
  
 SHARKSSL_API BaTime sharkParseCertTime(const U8* utc, U8 len);
  
  
  
 typedef enum
 {
    SharkSslConTrust_NotSSL=10,
  
    SharkSslConTrust_None,
  
    SharkSslConTrust_Cert,
  
    SharkSslConTrust_Cn,
  
    SharkSslConTrust_CertCn,
  
    SharkSslConTrust_CertCnDate
 } SharkSslConTrust;
  
 #if SHARKSSL_CHECK_DATE == 0
 #define SharkSslConTrust_CertCnDate SharkSslConTrust_CertCn
 #endif
  
  /* end group SharkSslInfoAndCodes */ 
  
 #if (SHARKSSL_ENABLE_RSA || SHARKSSL_ENABLE_ECDSA)
 SHARKSSL_API SharkSslConTrust SharkSslCon_trusted(
    SharkSslCon* o, const char* name, SharkSslCertInfo** cPtr);
 #endif
  /* end group SharkSslApi */ 
  
 #endif