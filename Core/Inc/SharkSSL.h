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
  *   $Id: SharkSSL.h 4915 2021-12-01 18:26:55Z wini $
  *
  *   COPYRIGHT:  Real Time Logic LLC, 2010 - 2021
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
 #ifndef _SharkSsl_h
 #define _SharkSsl_h
  
 #include "TargConfig.h"      /* platform dependencies  */
  
 /* Above TargConfig.h for BAS defines SHARKSSL_API, but not Shark's version */
 #ifndef SHARKSSL_API
 #define SHARKSSL_API
 #else  /* Barracuda */
 #define SHARKSSL_BA 1
 #include <ThreadLib.h>
 #include <BaServerLib.h>
 #endif
  
 #include "SharkSSL_cfg.h"    /* SharkSSL configuration */
 #ifdef __cplusplus
 #include <stddef.h>          /* size_t for new, delete */
 #endif
  
 #include "SharkSslCrypto.h"  /* Crypto API */
  
 #ifndef sharkCertSerialNumber2NetworkEndian
  
 typedef U64 SharkCertSerialNumber;
 #ifdef B_BIG_ENDIAN
 #define sharkCertSerialNumber2NetworkEndian(n)
 #else
 #define sharkCertSerialNumber2NetworkEndian(n)  \
    do {                                         \
       U64 nn=0;                                 \
       register U8* t=(U8*)&nn;                  \
       register U8* f=(U8*)&n;                   \
       t[7]=f[0];                                \
       t[6]=f[1];                                \
       t[5]=f[2];                                \
       t[4]=f[3];                                \
       t[3]=f[4];                                \
       t[2]=f[5];                                \
       t[1]=f[6];                                \
       t[0]=f[7];                                \
       n=nn;                                     \
    } while(0)
 #endif
 #endif
  
 /* Forward decl. */
 struct SharkSslCertDN;
 struct SharkSslASN1Create;
 struct SharkSslBitExtReq;
  
 #define SHARKSSL_ALERT_LEVEL_WARNING               1
  
 #define SHARKSSL_ALERT_LEVEL_FATAL                 2
  
 #define SHARKSSL_ALERT_CLOSE_NOTIFY                0
  
 #define SHARKSSL_ALERT_UNEXPECTED_MESSAGE          10
  
 #define SHARKSSL_ALERT_BAD_RECORD_MAC              20
  
 #define SHARKSSL_ALERT_DECRYPTION_FAILED           21
  
 #define SHARKSSL_ALERT_RECORD_OVERFLOW             22
  
 #define SHARKSSL_ALERT_DECOMPRESSION_FAILURE       30
  
 #define SHARKSSL_ALERT_HANDSHAKE_FAILURE           40
  
 #define SHARKSSL_ALERT_BAD_CERTIFICATE             42
  
 #define SHARKSSL_ALERT_UNSUPPORTED_CERTIFICATE     43
  
 #define SHARKSSL_ALERT_CERTIFICATE_REVOKED         44
  
 #define SHARKSSL_ALERT_CERTIFICATE_EXPIRED         45
  
 #define SHARKSSL_ALERT_CERTIFICATE_UNKNOWN         46
  
 #define SHARKSSL_ALERT_ILLEGAL_PARAMETER           47
  
 #define SHARKSSL_ALERT_UNKNOWN_CA                  48
  
 #define SHARKSSL_ALERT_ACCESS_DENIED               49
  
 #define SHARKSSL_ALERT_DECODE_ERROR                50
  
 #define SHARKSSL_ALERT_DECRYPT_ERROR               51
  
 #define SHARKSSL_ALERT_EXPORT_RESTRICTION          60
  
 #define SHARKSSL_ALERT_PROTOCOL_VERSION            70
  
 #define SHARKSSL_ALERT_INSUFFICIENT_SECURITY       71
  
 #define SHARKSSL_ALERT_INTERNAL_ERROR              80
  
 #define SHARKSSL_ALERT_USER_CANCELED               90
  
 #define SHARKSSL_ALERT_NO_RENEGOTIATION            100
  
 #define SHARKSSL_ALERT_UNRECOGNIZED_NAME           112
  
 #define SHARKSSL_ALERT_NO_APPLICATION_PROTOCOL     120  /* RFC 7301 */
  /* end group SharkSslAlertMsg */  /* end group SharkSslAlert */ 
  
  
 #define TLS_DHE_RSA_WITH_AES_128_GCM_SHA256                 0x009E
  
 #define TLS_DHE_RSA_WITH_AES_256_GCM_SHA384                 0x009F
  
 #define TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256             0xC02B
  
 #define TLS_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384             0xC02C
  
 #define TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256               0xC02F
  
 #define TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384               0xC030
  
 #define TLS_ECDHE_RSA_WITH_CHACHA20_POLY1305_SHA256         0xCCA8
  
 #define TLS_ECDHE_ECDSA_WITH_CHACHA20_POLY1305_SHA256       0xCCA9
  
 #define TLS_DHE_RSA_WITH_CHACHA20_POLY1305_SHA256           0xCCAA
  /* end group SharkSslCiphers */ 
  
  
 #define SHARKSSL_PROTOCOL_UNKNOWN                  0x00
  
 #define SHARKSSL_PROTOCOL_TLS_1_2                  0x03
  /* end group SharkSslProtocol */ 
  
  
 #if (SHARKSSL_ENABLE_RSA || SHARKSSL_ENABLE_ECDSA)
 #ifndef BA_API  /* standalone SharkSSL */
 #define BA_API SHARKSSL_API
 #ifdef _SHARKSSL_C_
 #define SingleListCode 1
 #endif
 #endif
 #include "SingleList.h"
 #endif
  
  
 #if SHARKSSL_ENABLE_SESSION_CACHE || SHARKSSL_NOPACK
  
 typedef struct SharkSslSession SharkSslSession;
  /* end group SharkSslSessionApi */ 
  
 #ifndef _DOXYGEN
 typedef struct SharkSslSessionCache
 {
    SharkSslSession *cache;
    ThreadMutexBase  cacheMutex;
    U16 cacheSize;
 } SharkSslSessionCache;
 #endif
 #endif
  
  
 typedef enum
 {
    SharkSsl_Unspecified,  
    SharkSsl_Server,       
    SharkSsl_Client        
 } SharkSsl_Role;
  /* end group SharkSslInfoAndCodes */
  
  
 #if (SHARKSSL_ENABLE_RSA || SHARKSSL_ENABLE_ECDSA)
  
 typedef U8* SharkSslKey;
  
  
 typedef const U8 *SharkSslCert;
  
 #ifdef __cplusplus
 extern "C" {
 #endif
  
 SHARKSSL_API U16 SharkSslCert_len(SharkSslCert cert);
  
 #ifdef __DOXYGEN__
 U32 baGetUnixTime(void);
 #endif
  
 #if SHARKSSL_ENABLE_CSR_CREATION
  
 SHARKSSL_API int
 SharkSslASN1Create_CSR(struct SharkSslASN1Create* o,
                        SharkSslKey privKey,
                        U8 hashID,
                        struct SharkSslCertDN* certDN,
                        const char *SAN,
                        struct SharkSslBitExtReq* keyUsage,
                        struct SharkSslBitExtReq* nsCertType);
 #endif
  
 #if SHARKSSL_ENABLE_CSR_SIGNING
  
 SHARKSSL_API int
 SharkSslCert_signCSR(SharkSslCert *signedCSR,
                      const U8 *csrData,
                      int csrDataLen,
                      const SharkSslCert caCert,
                      const SharkSslKey privKey,
                      const char *validFrom,
                      const char *validTo,
                      SharkCertSerialNumber serialNumber,
                      U8 hashID);
 #endif                                   
  
 #if SHARKSSL_ENABLE_ASN1_KEY_CREATION
  
 SHARKSSL_API int
 SharkSslASN1Create_key(struct SharkSslASN1Create *o, const SharkSslKey key);
 #endif
  
  
 #ifdef __cplusplus
 }
 #endif
  
  
 #if SHARKSSL_ENABLE_CA_LIST
  
 typedef const U8 *SharkSslCAList;
 #endif
  /* end group SharkSslInfoAndCodes */
 #endif
  
 #ifndef _DOXYGEN
 struct SharkSsl;
 #endif
  
  
 /* Non documented API used by SharkSslSCMgr when used indirectly by
    Lua code in the Barracuda Application Server. The code manages
    automatic destruction of SharkSslSCMgr.
  */
 #ifndef _DOXYGEN
 struct SharkSslIntf;
 typedef void (*SharkSslIntf_Terminate)(struct SharkSslIntf* o,
                                        struct SharkSsl* ssl); 
 typedef struct SharkSslIntf
 {
    SharkSslIntf_Terminate terminate;
 } SharkSslIntf;
 #define SharkSslIntf_constructor(o,terminateFunc) (o)->terminate=terminateFunc
 #endif
  
  
 typedef struct SharkSslCon SharkSslCon;
  
  
 typedef struct
 SharkSsl
 {
 #ifdef __cplusplus
    void *operator new(size_t s) { return ::baMalloc(s); }
    void operator delete(void* d) { if(d) ::baFree(d); }
    void *operator new(size_t, void *place) { return place; }
    void operator delete(void*, void *) { }
  
    SharkSsl() {};
  
    SharkSsl(SharkSsl_Role role,
             U16 cacheSize         = 0,
             U16 inBufStartSize    = 4096,
             U16 outBufSize        = 4096
             );
  
    ~SharkSsl();
    SharkSslCon *createCon(void);
    U8 setCAList(SharkSslCAList caList);
    U8 addCertificate(SharkSslCert cert);
    void terminateCon(SharkSslCon *sslCon);
 #endif
    #if (SHARKSSL_SSL_SERVER_CODE && SHARKSSL_SSL_CLIENT_CODE) || SHARKSSL_NOPACK
    SharkSsl_Role role;
    #endif
    U16 outBufSize;
    U16 inBufStartSize;
    U16 nCon;
    #if (SHARKSSL_ENABLE_RSA || (SHARKSSL_ENABLE_ECDSA))  || SHARKSSL_NOPACK
    SingleList certList;
    #if SHARKSSL_ENABLE_CA_LIST  || SHARKSSL_NOPACK
    SharkSslCAList caList;
    #endif
    #endif
    #if SHARKSSL_ENABLE_SESSION_CACHE  || SHARKSSL_NOPACK
    SharkSslSessionCache sessionCache;
    /* Reserved for use with one SharkSslSCMgr object  */
    SharkSslIntf* intf;
    #endif
 } SharkSsl;
  /* end group SharkSslInfoAndCodes */
  
 typedef enum
 {
    SharkSslCon_Error = 1, 
  
    SharkSslCon_AllocationError,
  
    SharkSslCon_Decrypted,
  
    SharkSslCon_Handshake,
  
    SharkSslCon_NeedMoreData,
  
    SharkSslCon_AlertSend,
  
    SharkSslCon_AlertRecv,
  
    SharkSslCon_Encrypted,
  
    SharkSslCon_HandshakeNotComplete,
  
    SharkSslCon_Certificate,
  
    SharkSslCon_CertificateError
  
 } SharkSslCon_RetVal;
  /* end group SharkSslCoreApi */
  
 #if (SHARKSSL_ENABLE_RSA || SHARKSSL_ENABLE_ECDSA)
  
 #if SHARKSSL_ENABLE_CERT_KEYUSAGE
 #define SHARKSSL_CERT_KEYUSAGE_DIGITALSIGNATURE     0x00000001
 #define SHARKSSL_CERT_KEYUSAGE_NONREPUDIATION       0x00000002
 #define SHARKSSL_CERT_KEYUSAGE_KEYENCIPHERMENT      0x00000004
 #define SHARKSSL_CERT_KEYUSAGE_DATAENCIPHERMENT     0x00000008
 #define SHARKSSL_CERT_KEYUSAGE_KEYAGREEMENT         0x00000010
 #define SHARKSSL_CERT_KEYUSAGE_KEYCERTSIGN          0x00000020
 #define SHARKSSL_CERT_KEYUSAGE_CRLSIGN              0x00000040
 #define SHARKSSL_CERT_KEYUSAGE_ENCIPHERONLY         0x00000080 
 #define SHARKSSL_CERT_KEYUSAGE_DECIPHERONLY         0x00000100
 #define SHARKSSL_CERT_KEYUSAGE_PRESENT              0x00000200
 #define SHARKSSL_CERT_KEYUSAGE_CRITICAL             0x00000400
  
 #define SHARKSSL_CERT_KEYPURPOSE_SERVERAUTH         0x00010000
 #define SHARKSSL_CERT_KEYPURPOSE_CLIENTAUTH         0x00020000
 #define SHARKSSL_CERT_KEYPURPOSE_CODESIGNING        0x00040000
 #define SHARKSSL_CERT_KEYPURPOSE_EMAILPROTECTION    0x00080000
 #define SHARKSSL_CERT_KEYPURPOSE_TIMESTAMPING       0x00100000
 #define SHARKSSL_CERT_KEYPURPOSE_OCSPSIGNING        0x00200000
  
 #define SharkSslCertInfo_KeyFlagSet(o,f)            ((o)->keyUsagePurposes & f)
  
 #define SharkSslCertInfo_isKeyUsagePresent(o)       SharkSslCertInfo_KeyFlagSet(o, SHARKSSL_CERT_KEYUSAGE_PRESENT)
 #define SharkSslCertInfo_isKeyUsageCritical(o)      SharkSslCertInfo_KeyFlagSet(o, SHARKSSL_CERT_KEYUSAGE_CRITICAL)
 #define SharkSslCertInfo_KU_digitalSignature(o)     SharkSslCertInfo_KeyFlagSet(o, SHARKSSL_CERT_KEYUSAGE_DIGITALSIGNATURE)
 #define SharkSslCertInfo_KU_nonRepudiation(o)       SharkSslCertInfo_KeyFlagSet(o, SHARKSSL_CERT_KEYUSAGE_NONREPUDIATION)
 #define SharkSslCertInfo_KU_keyEncipherment(o)      SharkSslCertInfo_KeyFlagSet(o, SHARKSSL_CERT_KEYUSAGE_KEYENCIPHERMENT)
 #define SharkSslCertInfo_KU_dataEncipherment(o)     SharkSslCertInfo_KeyFlagSet(o, SHARKSSL_CERT_KEYUSAGE_DATAENCIPHERMENT)
 #define SharkSslCertInfo_KU_keyAgreement(o)         SharkSslCertInfo_KeyFlagSet(o, SHARKSSL_CERT_KEYUSAGE_KEYAGREEMENT)
 #define SharkSslCertInfo_KU_keyCertSign(o)          SharkSslCertInfo_KeyFlagSet(o, SHARKSSL_CERT_KEYUSAGE_KEYCERTSIGN)
 #define SharkSslCertInfo_KU_cRLSign(o)              SharkSslCertInfo_KeyFlagSet(o, SHARKSSL_CERT_KEYUSAGE_CRLSIGN)
 #define SharkSslCertInfo_KU_encipherOnly(o)         SharkSslCertInfo_KeyFlagSet(o, SHARKSSL_CERT_KEYUSAGE_ENCIPHERONLY)
 #define SharkSslCertInfo_KU_decipherOnly(o)         SharkSslCertInfo_KeyFlagSet(o, SHARKSSL_CERT_KEYUSAGE_DECIPHERONLY)
  
 #define SharkSslCertInfo_kp_serverAuth(o)           SharkSslCertInfo_KeyFlagSet(o, SHARKSSL_CERT_KEYPURPOSE_SERVERAUTH)
 #define SharkSslCertInfo_kp_clientAuth(o)           SharkSslCertInfo_KeyFlagSet(o, SHARKSSL_CERT_KEYPURPOSE_CLIENTAUTH)
 #define SharkSslCertInfo_kp_codeSigning(o)          SharkSslCertInfo_KeyFlagSet(o, SHARKSSL_CERT_KEYPURPOSE_CODESIGNING)
 #define SharkSslCertInfo_kp_emailProtection(o)      SharkSslCertInfo_KeyFlagSet(o, SHARKSSL_CERT_KEYPURPOSE_EMAILPROTECTION)
 #define SharkSslCertInfo_kp_timeStamping(o)         SharkSslCertInfo_KeyFlagSet(o, SHARKSSL_CERT_KEYPURPOSE_TIMESTAMPING)
 #define SharkSslCertInfo_kp_OCSPSigning(o)          SharkSslCertInfo_KeyFlagSet(o, SHARKSSL_CERT_KEYPURPOSE_OCSPSIGNING)
 #endif
  
  
 typedef struct SharkSslCertDN
 {
    const U8 *countryName; 
    const U8 *province;  
    const U8 *locality; 
    const U8 *organization; 
    const U8 *unit; 
    const U8 *commonName;
    const U8 *emailAddress;
  
    U8 countryNameLen;   
    U8 provinceLen;      
    U8 localityLen;      
    U8 organizationLen;  
    U8 unitLen;          
    U8 commonNameLen;    
    U8 emailAddressLen;  
 } SharkSslCertDN;
  
 #define SharkSslCertDN_constructor(o) memset(o,0,sizeof(SharkSslCertDN))
  
 #define SharkSslCertDN_setCountryName(o, countryNameMA) \
    (o)->countryName=(const U8*)countryNameMA,(o)->countryNameLen=(U8)strlen(countryNameMA)
 #define SharkSslCertDN_setProvince(o, provinceMA) \
    (o)->province=(const U8*)provinceMA,(o)->provinceLen=(U8)strlen(provinceMA)
 #define SharkSslCertDN_setLocality(o, localityMA) \
    (o)->locality=(const U8*)localityMA,(o)->localityLen=(U8)strlen(localityMA)
 #define SharkSslCertDN_setOrganization(o, organizationMA) \
    (o)->organization=(const U8*)organizationMA,(o)->organizationLen=(U8)strlen(organizationMA)
 #define SharkSslCertDN_setUnit(o, unitMA) \
    (o)->unit=(const U8*)unitMA,(o)->unitLen=(U8)strlen(unitMA)
 #define SharkSslCertDN_setCommonName(o, commonNameMA) \
    (o)->commonName=(const U8*)commonNameMA,(o)->commonNameLen=(U8)strlen(commonNameMA)
 #define SharkSslCertDN_setEmailAddress(o, emailAddressMA) \
    (o)->emailAddress=(const U8*)emailAddressMA,(o)->emailAddressLen=(U8)strlen(emailAddressMA)
  
  
 typedef struct SharkSslCertInfo
 {
    U16 snLen;
  
    U8  version; 
  
    U8 CAflag;
  
    U8 *sn;
  
    U8 *timeFrom;  /* declaration of U8 timeFromLen below */
  
    U8 *timeTo;    /* declaration of U8 timeToLen below */
  
    SharkSslCertDN issuer;
  
    SharkSslCertDN subject;
  
    U8 *subjectAltNamesPtr;
    U16 subjectAltNamesLen;
  
    U8  timeFromLen;
  
    U8  timeToLen;
  
    #if SHARKSSL_ENABLE_CERT_KEYUSAGE
  
    U32 keyUsagePurposes; 
    #endif
  
    struct SharkSslCertInfo *parent;
 } SharkSslCertInfo;
  /* end group SharkSslCertInfo */ 
 #endif
  
 #ifdef __cplusplus
 extern "C" {
 #endif
  
 SHARKSSL_API void  SharkSsl_constructor(
                       SharkSsl *o,
                       SharkSsl_Role role,
                       U16 cacheSize,
                       U16 inBufStartSize,
                       U16 outBufSize
                       );
  
 SHARKSSL_API void  SharkSsl_destructor(SharkSsl *o);
  
  
 SharkSslCon *SharkSsl_createCon(SharkSsl *o);
  
  
 void SharkSsl_terminateCon(const SharkSsl *o, SharkSslCon* con);
  
  
 #if SHARKSSL_ENABLE_SESSION_CACHE
  
 SHARKSSL_API U16   SharkSsl_getCacheSize(SharkSsl *o);
  
 #define SharkSsl_setIntf(o, sharkSslIntf) (o)->intf=sharkSslIntf
 #define SharkSsl_getIntf(o) (o)->intf
  
 #endif
  
  
 #define SharkSslCon_terminate(o) SharkSsl_terminateCon(0, o)
  
 SharkSslCon_RetVal SharkSslCon_decrypt(SharkSslCon *o, U16 readLen);
  
  
 SharkSslCon_RetVal SharkSslCon_encrypt(SharkSslCon *o, U8 *buf, U16 maxLen);
  
  
 U8 SharkSslCon_isHandshakeComplete(SharkSslCon *o);
  
  
 U8  SharkSslCon_encryptMore(SharkSslCon *o);
  
  
 U8  SharkSslCon_decryptMore(SharkSslCon *o);
  
 U8 *SharkSslCon_getBuf(SharkSslCon *o);
  
  
 U16 SharkSslCon_getBufLen(SharkSslCon *o);
  
 U16 SharkSslCon_copyDecData(SharkSslCon *o, U8 *buf, U16 maxLen);
  
  
 SHARKSSL_API U16 SharkSslCon_getDecData(SharkSslCon *o, U8 **bufPtr);
  
  
 U8 *SharkSslCon_getHandshakeData(SharkSslCon *o);
  
  
 U16 SharkSslCon_getHandshakeDataLen(SharkSslCon *o);
  
  
 U8 *SharkSslCon_getEncData(SharkSslCon *o);
  
  
 U16 SharkSslCon_getEncDataLen(SharkSslCon *o);
  
  
 U8 *SharkSslCon_getEncBufPtr(SharkSslCon *o);
  
  
 U16 SharkSslCon_getEncBufSize(SharkSslCon *o);
  
  
 U8  SharkSslCon_getAlertLevel(SharkSslCon *o);
  
  
 U8  SharkSslCon_getAlertDescription(SharkSslCon *o);
  
  
 #define SharkSslCon_getAlertData(o)    SharkSslCon_getEncData(o)
  
  
 #define SharkSslCon_getAlertDataLen(o) SharkSslCon_getEncDataLen(o)
  /* end group SharkSslCoreApi */ 
  
 #if SHARKSSL_ENABLE_INFO_API
  
 SHARKSSL_API U16 SharkSslCon_getCiphersuite(SharkSslCon *o);
  
 #endif
  
 #if SHARKSSL_ENABLE_SNI
  
 #if SHARKSSL_SSL_CLIENT_CODE
  
 SHARKSSL_API U8  SharkSslCon_setSNI(SharkSslCon *o, const char *name, U16 length); 
 #endif
  
 #endif
  
  
 #if (SHARKSSL_ENABLE_RSA || SHARKSSL_ENABLE_ECDSA)
 #if (SHARKSSL_SSL_CLIENT_CODE && SHARKSSL_ENABLE_CLIENT_AUTH)
  
 U8  SharkSslCon_certificateRequested(SharkSslCon *o);
 #endif
  
 SHARKSSL_API SharkSslCertInfo  *SharkSslCon_getCertInfo(SharkSslCon *o);
  
  
 SHARKSSL_API U8 SharkSsl_addCertificate(SharkSsl *o, SharkSslCert cert);
  
 #if SHARKSSL_ENABLE_CA_LIST
  
 SHARKSSL_API U8  SharkSsl_setCAList(SharkSsl *o, SharkSslCAList caList);
  
 SHARKSSL_API U8  SharkSslCon_trustedCA(SharkSslCon *o);
  
 U8  SharkSslCon_isCAListEmpty(SharkSslCon *o);
 #endif  /* SHARKSSL_ENABLE_CA_LIST */
  
 #if (SHARKSSL_SSL_SERVER_CODE && SHARKSSL_ENABLE_RSA)
  
 /* to be used as 'flag' param */
 #define SHARKSSL_SET_FAVOR_RSA      1  
 #define SHARKSSL_CLEAR_FAVOR_RSA    0
  
 U8  SharkSslCon_favorRSA(SharkSslCon *o, U8 flag);
 #endif  /* SHARKSSL_SSL_SERVER_CODE */
 #endif  /* SHARKSSL_ENABLE_RSA || SHARKSSL_ENABLE_ECDSA */
  
 #if SHARKSSL_ENABLE_SESSION_CACHE
  
 SHARKSSL_API U8    SharkSslSession_release(SharkSslSession *o, SharkSsl *s);
  
 #if SHARKSSL_SSL_SERVER_CODE
  
 SHARKSSL_API U8    SharkSslCon_releaseSession(SharkSslCon *o);
 #endif
  
 #if SHARKSSL_SSL_CLIENT_CODE 
  
 SHARKSSL_API SharkSslSession *SharkSslCon_acquireSession(SharkSslCon *o);
  
  
 SHARKSSL_API U8 SharkSslCon_resumeSession(SharkSslCon *o, SharkSslSession *s); 
  
 SHARKSSL_API U32   SharkSslSession_getLatestAccessTime(SharkSslSession *o);
 #endif
 #endif
  /* end group SharkSslSessionApi */
  
 #if (SHARKSSL_SSL_SERVER_CODE && SHARKSSL_ENABLE_CLIENT_AUTH && \
     (SHARKSSL_ENABLE_RSA || SHARKSSL_ENABLE_ECDSA))
  
 SHARKSSL_API U8 SharkSslCon_requestClientCert(
    SharkSslCon *o, const void *caList);
 #endif
  
 #if SHARKSSL_ENABLE_ALPN_EXTENSION
 #if SHARKSSL_SSL_CLIENT_CODE
  
 SHARKSSL_API U8 SharkSslCon_setALPNProtocols(
    SharkSslCon* o, const char* protList);
  
 SHARKSSL_API const char *SharkSslCon_getALPNProtocol(SharkSslCon* o);
 #endif
 #if SHARKSSL_SSL_SERVER_CODE
 typedef int(*ALPNFunction)(SharkSslCon*, const char*, void *);
 SHARKSSL_API U8 SharkSslCon_setALPNFunction(
    SharkSslCon *o, ALPNFunction func, void *pvoid);
 #endif
 #endif  /* SHARKSSL_ENABLE_ALPN_EXTENSION */
  
 #if ((SHARKSSL_SSL_SERVER_CODE || SHARKSSL_SSL_CLIENT_CODE) && \
      SHARKSSL_ENABLE_SELECT_CIPHERSUITE)
  
 SHARKSSL_API U8 SharkSslCon_selectCiphersuite(SharkSslCon *o, U16 cipherSuite);
  
 SHARKSSL_API U8 SharkSslCon_clearCiphersuiteSelection(SharkSslCon *o); 
 #endif
  
 #if (SHARKSSL_SSL_SERVER_CODE && SHARKSSL_ENABLE_SECURE_RENEGOTIATION)
  
 SHARKSSL_API U8 SharkSslCon_renegotiate(SharkSslCon *o);
 #endif
  /* end group SharkSslApi */ 
  
  
 #if SHARKSSL_ENABLE_PEM_API
  
 typedef enum
 {
    SHARKSSL_PEM_OK = 0,
  
    SHARKSSL_PEM_OK_PUBLIC = 1,
  
    SHARKSSL_PEM_ALLOCATION_ERROR = - 3000,
  
    SHARKSSL_PEM_KEY_PARSE_ERROR,
  
    SHARKSSL_PEM_KEY_WRONG_IV,
  
    SHARKSSL_PEM_KEY_WRONG_LENGTH,
  
    SHARKSSL_PEM_KEY_PASSPHRASE_REQUIRED,
  
    SHARKSSL_PEM_KEY_UNRECOGNIZED_FORMAT,
  
    SHARKSSL_PEM_KEY_UNSUPPORTED_FORMAT,
  
    SHARKSSL_PEM_KEY_UNSUPPORTED_MODULUS_LENGTH,
  
    SHARKSSL_PEM_KEY_UNSUPPORTED_EXPONENT_LENGTH,
  
    SHARKSSL_PEM_KEY_UNSUPPORTED_ENCRYPTION_TYPE,
  
    SHARKSSL_PEM_KEY_CERT_MISMATCH,
  
    SHARKSSL_PEM_CERT_UNRECOGNIZED_FORMAT,
  
    SHARKSSL_PEM_CERT_UNSUPPORTED_TYPE,
  
    SHARKSSL_PEM_KEY_UNSUPPORTED_VERSION,
  
    SHARKSSL_PEM_KEY_REQUIRED,
  
    SHARKSSL_PEM_KEY_PRIVATE_KEY_REQUIRED,
  
    SHARKSSL_PEM_INTERNAL_ERROR
 } sharkssl_PEM_RetVal;
  
  
 SHARKSSL_API sharkssl_PEM_RetVal sharkssl_PEM(
    const char *certPEM, const char *keyPEM, 
    const char *passphrase, SharkSslCert *sharkSslCert);
  
 #if SHARKSSL_ENABLE_ENCRYPTED_PKCS8_SUPPORT
  
 SHARKSSL_API int sharkssl_PEM_PBKDF2(
    U8 *dk, const char *passphrase, 
    const char *salt, U32 saltLen, 
    U32 iterations, U16 dkLen, U8 hashID);
 #endif
  /* end group RayCryptoApi */
 #endif
  
 #if SHARKSSL_ENABLE_RSA
  
 #define SHARKSSL_RSA_NO_PADDING      0
  
  
 #define SHARKSSL_RSA_PKCS1_PADDING   1
  
  
 typedef enum
 {
    SHARKSSL_RSA_OK = 0,
  
    SHARKSSL_RSA_ALLOCATION_ERROR = -3000,
  
    SHARKSSL_RSA_INTERNAL_ERROR = -3100,
  
    SHARKSSL_RSA_WRONG_PARAMETERS,
  
    SHARKSSL_RSA_WRONG_KEY_FORMAT,
  
    SHARKSSL_RSA_WRONG_KEY_LENGTH,
  
    SHARKSSL_RSA_INPUT_DATA_LENGTH_TOO_BIG,
  
    SHARKSSL_RSA_INPUT_DATA_LENGTH_AND_KEY_LENGTH_MISMATCH,
  
    SHARKSSL_RSA_PKCS1_PADDING_ERROR
 } sharkssl_RSA_RetVal;
 #endif
  /* end group SharkSslInfoAndCodes */ 
  
 #if SHARKSSL_ENABLE_RSA_API
  
 typedef U8* SharkSslRSAKey;
  
 #if SHARKSSL_ENABLE_PEM_API
  
 SHARKSSL_API SharkSslRSAKey sharkssl_PEM_to_RSAKey(
    const char *PEMKey, const char *passphrase);
  
 SHARKSSL_API SharkSslKey
 sharkssl_PEM_extractPublicKey(const char *certPEM);
  
 SHARKSSL_API SharkSslKey
 sharkssl_PEM_extractPublicKey_ext(const char *certPEM, U8 *keyType);
 #endif  /* SHARKSSL_ENABLE_PEM_API */
  
 #if (SHARKSSL_ENABLE_PEM_API || (SHARKSSL_ENABLE_RSA && SHARKSSL_ENABLE_RSAKEY_CREATE))
  
 SHARKSSL_API void SharkSslRSAKey_free(SharkSslRSAKey key);
 #define _SHARKSSLRSAKEY_FREE 1
 #endif
  
 #if SHARKSSL_ENABLE_RSA
 #if SHARKSSL_ENABLE_RSAKEY_CREATE
  
 SHARKSSL_API int SharkSslRSAKey_create(SharkSslRSAKey *privKey, U16 keyLength);
  
 SHARKSSL_API U8 *SharkSslRSAKey_getPublic(SharkSslRSAKey privKey);
 #endif 
  
 SHARKSSL_API U16 SharkSslRSAKey_size(SharkSslRSAKey key);
  
 SHARKSSL_API sharkssl_RSA_RetVal sharkssl_RSA_public_encrypt(
    U16 len, U8 *in, U8 *out, SharkSslRSAKey key, U8 padding);
  
  
 SHARKSSL_API sharkssl_RSA_RetVal sharkssl_RSA_private_decrypt(
    U16 len, U8 *in, U8 *out, SharkSslRSAKey privkey, U8 padding);
  
  
 #if SHARKSSL_ENABLE_RSA_OAEP
 #if (!SHARKSSL_USE_SHA1)
 #error SHARKSSL_USE_SHA1 must be selected when SHARKSSL_ENABLE_RSA_OAEP is enabled
 #endif
  
 SHARKSSL_API sharkssl_RSA_RetVal sharkssl_RSA_private_decrypt_OAEP(
    U16 len, U8 *in, U8 *out, SharkSslRSAKey privkey, U8 hashID, char *label, U16 labelLen);
 #endif
  
  
 SHARKSSL_API sharkssl_RSA_RetVal sharkssl_RSA_private_encrypt(
    U16 len, U8 *in, U8 *out, SharkSslRSAKey privkey, U8 padding);
  
  
 SHARKSSL_API sharkssl_RSA_RetVal sharkssl_RSA_public_decrypt(
    U16 len, U8 *in, U8 *out, SharkSslRSAKey key, U8 padding);
  
 #endif
  /* end group RSA */
 #endif
  
  
 #if SHARKSSL_USE_ECC
  
 /*
  * NamedCurve, use as curveID parameter
  * SECPxxxR1       - RFC 4492 section 5.1.1
  * BRAINPOOLPxxxR1 - RFC 7027 section 2
  */
 #define SHARKSSL_EC_CURVE_ID_SECP256R1       23
 #define SHARKSSL_EC_CURVE_ID_SECP384R1       24
 #define SHARKSSL_EC_CURVE_ID_SECP521R1       25
 #define SHARKSSL_EC_CURVE_ID_BRAINPOOLP256R1 26
 #define SHARKSSL_EC_CURVE_ID_BRAINPOOLP384R1 27
 #define SHARKSSL_EC_CURVE_ID_BRAINPOOLP512R1 28
  
  
 typedef U8* SharkSslECCKey;
  
 #if SHARKSSL_ENABLE_PEM_API
  
 SHARKSSL_API SharkSslECCKey sharkssl_PEM_to_ECCKey(
    const char *PEMKey, const char *passphrase);
  
  
 #if (SHARKSSL_ENABLE_RSA || SHARKSSL_ENABLE_ECDSA)
  
 SHARKSSL_API U16 SharkSslKey_vectSize(const SharkSslKey key);
 #define SharkSslCert_vectSize(c) SharkSslKey_vectSize((const SharkSslCert)c)
 #if SHARKSSL_ENABLE_RSA
 #define SharkSslRSAKey_vectSize(k) SharkSslKey_vectSize(k)
 #endif
 #if SHARKSSL_ENABLE_ECDSA
 #define SharkSslECCKey_vectSize(k) SharkSslKey_vectSize(k)
 #endif
 #endif
 #endif
  
  
 #if SHARKSSL_ENABLE_ECCKEY_CREATE
  
 SHARKSSL_API int SharkSslECCKey_create(SharkSslECCKey *privKey, U16 curveID);
 #endif
  
  
 #if (SHARKSSL_ENABLE_PEM_API || SHARKSSL_ENABLE_ECCKEY_CREATE)
  
 SHARKSSL_API void SharkSslECCKey_free(SharkSslECCKey key);
 #define _SHARKSSLECCKEY_FREE 1
 #endif
  
  
 /*
  *-----------------------------------------------------------------------------
  * To free up the memory allocated by SharkSslECCKey_create and 
  * SharkSslRSAKey_create, the following macro is provided
  * For instance, this function could be called after saving the key to a file
  *-----------------------------------------------------------------------------
  * key: input parameter, points to a buffer allocated by either 
  *    SharkSslECCKey_create or SharkSslRSAKey_create
  */
 #if defined(_SHARKSSLRSAKEY_FREE)
 #define SharkSslKey_free SharkSslRSAKey_free
 #elif defined (_SHARKSSLECCKEY_FREE)
 #define SharkSslKey_free SharkSslECCKey_free
 #else
 #define SharkSslKey_free
 #endif
 #undef _SHARKSSLRSAKEY_FREE
 #undef _SHARKSSLECCKEY_FREE
  
  
 #if SHARKSSL_ENABLE_ECDSA 
  
 /* ECDSA API and also internal sharkssl_ECDSA_signASN1 */
 typedef enum
 {
    SHARKSSL_ECDSA_OK = 0,
  
    SHARKSSL_ECDSA_ALLOCATION_ERROR = -3200,
  
    SHARKSSL_ECDSA_INTERNAL_ERROR = -3300,
  
    SHARKSSL_ECDSA_WRONG_PARAMETERS,
  
    SHARKSSL_ECDSA_WRONG_KEY_FORMAT,
  
    SHARKSSL_ECDSA_KEY_NOT_PRIVATE,
  
    SHARKSSL_ECDSA_KEY_NOT_PUBLIC,
  
    SHARKSSL_ECDSA_SIGLEN_TOO_SMALL,
  
    SHARKSSL_ECDSA_VERIFICATION_FAIL,
  
    SHARKSSL_ECDSA_WRONG_SIGNATURE
 } sharkssl_ECDSA_RetVal;
  /* end group SharkSslInfoAndCodes */ 
  
 #if SHARKSSL_ENABLE_ECDSA_API
 #if (!SHARKSSL_ECDSA_ONLY_VERIFY)
  
 SHARKSSL_API U16 sharkssl_ECDSA_siglen(SharkSslECCKey privkey);
  
 SHARKSSL_API sharkssl_ECDSA_RetVal sharkssl_ECDSA_sign_hash(
    SharkSslECCKey privkey, U8 *sig, U16 *siglen, U8 *hash, U8 hashlen);
 #endif
  
 SHARKSSL_API sharkssl_ECDSA_RetVal sharkssl_ECDSA_verify_hash(
    SharkSslECCKey pubkey, U8 *sig, U16 siglen, U8 *hash, U8 hashlen);
  
 #endif  /* SHARKSSL_ENABLE_ECDSA_API */
 #endif  /* SHARKSSL_ENABLE_ECDSA */
  /* end group ECC */
 #endif
  
  
 #if (SHARKSSL_ENABLE_CA_LIST && SHARKSSL_ENABLE_CERTSTORE_API)
  
 #ifndef BA_API  /* standalone SharkSSL */
 #define BA_API SHARKSSL_API
 typedef U8 BaBool;
 #endif
 #include "DoubleList.h"
  
 typedef struct SharkSslCertStore
 {
    DoubleList certList;
    SharkSslCAList caList;
    U16 elements;  /* number of elements in list */
 } SharkSslCertStore;
  
 SHARKSSL_API void  SharkSslCertStore_constructor(SharkSslCertStore *o);
  
 SHARKSSL_API void  SharkSslCertStore_destructor(SharkSslCertStore* o);
  
 #define            SharkSslCertStore_release(o) SharkSslCertStore_destructor(o)
  
 SHARKSSL_API U16   SharkSslCertStore_add(
    SharkSslCertStore *o, const char *cert, U32 certlen);
  
 SHARKSSL_API U8  SharkSslCertStore_assemble(
    SharkSslCertStore *o, SharkSslCAList *outList);
  /* end group SharkSslCertApi */ 
 #endif  /* SHARKSSL_ENABLE_CA_LIST && SHARKSSL_ENABLE_CERTSTORE_API */
  
 #if ((SHARKSSL_ENABLE_PEM_API) || (SHARKSSL_ENABLE_CERTSTORE_API))
 SHARKSSL_API U32 sharkssl_B64Decode(
    U8 *outStr, U32 outStrSize, const char *b64beg, const char *b64end);
 #endif
  
  
  
 #ifdef __cplusplus
 }
  
 inline SharkSsl::SharkSsl(
    SharkSsl_Role role, U16 cacheSize, U16 inBufStartSize, U16 outBufSize) {
    SharkSsl_constructor(this, role, cacheSize, inBufStartSize, outBufSize);
 }
 inline SharkSsl::~SharkSsl() {
    SharkSsl_destructor(this);
 }
 inline SharkSslCon *SharkSsl::createCon(void) {
    return SharkSsl_createCon(this);
 }
 inline void SharkSsl::terminateCon(SharkSslCon *sslCon) {
    SharkSsl_terminateCon(this, sslCon);
 }
  
 #if (SHARKSSL_ENABLE_RSA || SHARKSSL_ENABLE_ECDSA)
 inline U8 SharkSsl::addCertificate(SharkSslCert cert) {
    return SharkSsl_addCertificate(this, cert);
 }
 #if SHARKSSL_ENABLE_CA_LIST
 inline U8 SharkSsl::setCAList(SharkSslCAList caList) {
    return SharkSsl_setCAList(this, caList);
 }
 #endif  /* SHARKSSL_ENABLE_CA_LIST */
 #endif  /* SHARKSSL_ENABLE_RSA || SHARKSSL_ENABLE_ECDSA */
  
 #endif  /* __cplusplus */
  
  
 #endif