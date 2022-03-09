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
  *   $Id: SharkSSL_cfg.h 5100 2022-02-19 16:23:57Z wini $
  *
  *   COPYRIGHT:  Real Time Logic LLC, 2010 - 2022
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
  
  
  Do not directly edit the options in this file. Instead, add your
  custom options in SharkSSL_opts.h
  
  */
 #ifndef _SharkSsl_cfg_h
 #define _SharkSsl_cfg_h
  
 #include "SharkSSL_opts.h"
  
 #ifndef SHARKSSL_USE_AES_256
 #define SHARKSSL_USE_AES_256                             1
 #endif
  
 #ifndef SHARKSSL_USE_AES_128
 #define SHARKSSL_USE_AES_128                             1
 #endif
  
 #ifndef SHARKSSL_USE_AES_192
 #define SHARKSSL_USE_AES_192                             0
 #endif
  
 #ifndef SHARKSSL_ENABLE_AES_GCM
 #define SHARKSSL_ENABLE_AES_GCM                          1
 #endif
  
 #ifndef SHARKSSL_ENABLE_AES_CCM
 #define SHARKSSL_ENABLE_AES_CCM                          0
 #endif
  
 #ifndef SHARKSSL_ENABLE_AES_CBC
 #define SHARKSSL_ENABLE_AES_CBC                          0
 #endif
  
 #ifndef SHARKSSL_USE_CHACHA20
 #define SHARKSSL_USE_CHACHA20                            1
 #endif
  
  
 #ifndef SHARKSSL_USE_SHA_256
 #define SHARKSSL_USE_SHA_256                             1
 #endif
  
 #ifndef SHARKSSL_USE_SHA_384
 #define SHARKSSL_USE_SHA_384                             1
 #endif
  
 #ifndef SHARKSSL_USE_SHA_512
 #define SHARKSSL_USE_SHA_512                             0
 #endif
  
  
 #ifndef SHARKSSL_USE_SHA1
 #define SHARKSSL_USE_SHA1                                1
 #endif
  
 #ifndef SHARKSSL_USE_MD5
 #define SHARKSSL_USE_MD5                                 0
 #endif
  
 #ifndef SHARKSSL_USE_POLY1305
 #define SHARKSSL_USE_POLY1305                            1
 #endif
  /* end group SharkSslCfgHash */
  
  
 #ifndef SHARKSSL_SSL_SERVER_CODE
 #define SHARKSSL_SSL_SERVER_CODE                         1
 #endif
  
  
 #ifndef SHARKSSL_ENABLE_CLIENT_AUTH
 #define SHARKSSL_ENABLE_CLIENT_AUTH                      1
 #endif
  
  
 #ifndef SHARKSSL_SSL_CLIENT_CODE
 #define SHARKSSL_SSL_CLIENT_CODE                         1
 #endif
  
  
 #ifndef SHARKSSL_ENABLE_SNI
 #define SHARKSSL_ENABLE_SNI                              1
 #endif
  
  
 #ifndef SHARKSSL_ENABLE_RSA
 #define SHARKSSL_ENABLE_RSA                              1
 #endif
  
  
 #ifndef SHARKSSL_ENABLE_SESSION_CACHE
 #define SHARKSSL_ENABLE_SESSION_CACHE                    1
 #endif
  
  
 #ifndef SHARKSSL_ENABLE_SECURE_RENEGOTIATION
 #define SHARKSSL_ENABLE_SECURE_RENEGOTIATION             1
 #endif
  
  
 /*
  * TLS 1.2 requires SHA-256, do not modify the following settings
  * DES and ClientHello v2.0 are deprecated in TLS 1.2 - RFC5246
  */
 #undef  SHARKSSL_USE_SHA_256
 #define SHARKSSL_USE_SHA_256                             1
  
  
 #ifndef SHARKSSL_ENABLE_DHE_RSA
 #define SHARKSSL_ENABLE_DHE_RSA                          1
 #endif
  
  
 #ifndef SHARKSSL_ENABLE_SELECT_CIPHERSUITE
 #define SHARKSSL_ENABLE_SELECT_CIPHERSUITE               1
 #endif
  
  
 #ifndef SHARKSSL_SELECT_CIPHERSUITE_LIST_DEPTH
 #define SHARKSSL_SELECT_CIPHERSUITE_LIST_DEPTH           8
 #endif
  
  
 #ifndef SHARKSSL_ENABLE_ALPN_EXTENSION
 #define SHARKSSL_ENABLE_ALPN_EXTENSION                   1
 #endif
  
  
 #ifndef SHARKSSL_ENABLE_RSA_API
 #define SHARKSSL_ENABLE_RSA_API                          1
 #endif
  
  
 #ifndef SHARKSSL_ENABLE_RSA_PKCS1
 #define SHARKSSL_ENABLE_RSA_PKCS1                        1
 #endif
  
  
 #ifndef SHARKSSL_ENABLE_RSA_OAEP
 #define SHARKSSL_ENABLE_RSA_OAEP                         0
 #endif
  
  
 #ifndef SHARKSSL_ENABLE_ECDSA_API
 #define SHARKSSL_ENABLE_ECDSA_API                        1
 #endif
  
  
 #ifndef SHARKSSL_ECDSA_ONLY_VERIFY
 #define SHARKSSL_ECDSA_ONLY_VERIFY                       0
 #endif
  
  
 #ifndef SHARKSSL_ENABLE_PEM_API
 #define SHARKSSL_ENABLE_PEM_API                          1
 #endif
  
  
 #ifndef SHARKSSL_ENABLE_ENCRYPTED_PKCS8_SUPPORT
 #define SHARKSSL_ENABLE_ENCRYPTED_PKCS8_SUPPORT          0
 #endif
  
  
 #ifndef SHARKSSL_ENABLE_INFO_API
 #define SHARKSSL_ENABLE_INFO_API                         1
 #endif
  
  
 #ifndef SHARKSSL_ENABLE_CERT_CHAIN
 #define SHARKSSL_ENABLE_CERT_CHAIN                       1
 #endif
  
  
 #ifndef SHARKSSL_ENABLE_CA_LIST
 #define SHARKSSL_ENABLE_CA_LIST                          1
 #endif
  
  
 #ifndef SHARKSSL_ENABLE_CERTSTORE_API
 #define SHARKSSL_ENABLE_CERTSTORE_API                    1
 #endif
  
  
 #ifndef SHARKSSL_ENABLE_CLONE_CERTINFO
 #define SHARKSSL_ENABLE_CLONE_CERTINFO                   1
 #endif
  
  
 #ifndef SHARKSSL_ENABLE_CERT_KEYUSAGE
 #define SHARKSSL_ENABLE_CERT_KEYUSAGE                    0
 #endif
  
  
 #ifndef SHARKSSL_MD5_SMALL_FOOTPRINT
 #define SHARKSSL_MD5_SMALL_FOOTPRINT                     0
 #endif
  
 #ifndef SHARKSSL_SHA1_SMALL_FOOTPRINT
 #define SHARKSSL_SHA1_SMALL_FOOTPRINT                    0
 #endif
  
 #ifndef SHARKSSL_SHA256_SMALL_FOOTPRINT
 #define SHARKSSL_SHA256_SMALL_FOOTPRINT                  0
 #endif
  
  
 #ifndef SHARKSSL_BIGINT_EXP_SLIDING_WINDOW_K
 #define SHARKSSL_BIGINT_EXP_SLIDING_WINDOW_K             4
 #endif
  
  
 #ifndef SHARKSSL_BIGINT_MULT_LOOP_UNROLL
 #define SHARKSSL_BIGINT_MULT_LOOP_UNROLL                 1
 #endif
  
  
 #ifndef SHARKSSL_ENABLE_AES_CTR_MODE
 #define SHARKSSL_ENABLE_AES_CTR_MODE                     1
 #endif
  
  
 #ifndef SHARKSSL_AES_CIPHER_LOOP_UNROLL
 #define SHARKSSL_AES_CIPHER_LOOP_UNROLL                  1
 #endif
  
  
 #ifndef SHARKSSL_UNALIGNED_ACCESS
 #ifdef UNALIGNED_ACCESS
 #define SHARKSSL_UNALIGNED_ACCESS                        1
 #else
 #define SHARKSSL_UNALIGNED_ACCESS                        0
 #endif
 #endif
  
  
 #ifndef SHARKSSL_BIGINT_WORDSIZE
 #define SHARKSSL_BIGINT_WORDSIZE                         32
 #endif
  
  
 #ifndef SHARKSSL_USE_ECC
 #define SHARKSSL_USE_ECC                                 1
 #endif
  
  
 #ifndef SHARKSSL_ENABLE_ECDSA
 #define SHARKSSL_ENABLE_ECDSA                            1
 #endif
  
  
 #ifndef SHARKSSL_ECC_VERIFY_POINT
 #define SHARKSSL_ECC_VERIFY_POINT                        1
 #endif
  
  
 #ifndef SHARKSSL_ECC_TIMING_RESISTANT
 #define SHARKSSL_ECC_TIMING_RESISTANT                    0
 #endif
  
 #ifndef SHARKSSL_ECC_USE_SECP256R1
 #define SHARKSSL_ECC_USE_SECP256R1                       1
 #endif
  
 #ifndef SHARKSSL_ECC_USE_SECP384R1
 #define SHARKSSL_ECC_USE_SECP384R1                       1
 #endif
  
 #ifndef SHARKSSL_ECC_USE_SECP521R1
 #define SHARKSSL_ECC_USE_SECP521R1                       1
 #endif
  
  
 #ifndef SHARKSSL_ECC_USE_BRAINPOOLP256R1
 #define SHARKSSL_ECC_USE_BRAINPOOLP256R1                 1
 #endif
  
 #ifndef SHARKSSL_ECC_USE_BRAINPOOLP384R1
 #define SHARKSSL_ECC_USE_BRAINPOOLP384R1                 1
 #endif
  
 #ifndef SHARKSSL_ECC_USE_BRAINPOOLP512R1
 #define SHARKSSL_ECC_USE_BRAINPOOLP512R1                 1
 #endif
  
  
 #ifndef SHARKSSL_ENABLE_ECDHE_RSA
 #define SHARKSSL_ENABLE_ECDHE_RSA                        1
 #endif
  
  
 #ifndef SHARKSSL_ENABLE_ECDHE_ECDSA
 #define SHARKSSL_ENABLE_ECDHE_ECDSA                      1
 #endif
  
  
 #ifndef SHARKSSL_OPTIMIZED_BIGINT_ASM
 #define SHARKSSL_OPTIMIZED_BIGINT_ASM                    0
 #endif
  
 #ifndef SHARKSSL_OPTIMIZED_CHACHA_ASM
 #define SHARKSSL_OPTIMIZED_CHACHA_ASM                    0
 #endif
  
 #ifndef SHARKSSL_OPTIMIZED_POLY1305_ASM
 #define SHARKSSL_OPTIMIZED_POLY1305_ASM                  0
 #endif
  
  
 #ifndef SHARKSSL_USE_RNG_TINYMT
 #define SHARKSSL_USE_RNG_TINYMT                          0
 #endif
  
 #ifndef SHARKSSL_USE_RNG_FORTUNA
 #define SHARKSSL_USE_RNG_FORTUNA                         0
 #endif
  
  
 #ifndef SHARKSSL_RNG_MULTITHREADED
 #define SHARKSSL_RNG_MULTITHREADED                       1
 #endif
  
 #ifndef SHARKSSL_NOPACK
 #define SHARKSSL_NOPACK                                  0
 #endif
  
 #ifdef __DOXYGEN__
 #define SHARKSSL_CHECK_DATE                               0
 #endif
 #ifndef SHARKSSL_CHECK_DATE
 #ifdef SHARKSSL_BA /* if SharkSSL embedded in BAS */
 #define SHARKSSL_CHECK_DATE                               1
 #else
 #define SHARKSSL_CHECK_DATE                               0
 #endif
 #endif
  
  /* end group SharkSslCfg */
  
 #endif