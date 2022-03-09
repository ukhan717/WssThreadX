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
  *   $Id: selib.h 4871 2021-10-14 18:42:00Z wini $
  *
  *   COPYRIGHT:  Real Time Logic LLC, 2013 - 2020
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
  *               http://realtimelogic.com
  *               http://sharkssl.com
  ****************************************************************************
  *
  */
  
 #ifndef _selib_h
 #define _selib_h
  
 #include <SharkSSL.h>
 #include <SharkSslEx.h>
  
 /* secure version of selib */
//  #define MS_SEC
  
  
 #define INFINITE_TMO (~((U32)0))
  
 #include <selibplat.h>
  
 #ifndef XPRINTF
 #if HOST_PLATFORM
 #define XPRINTF 1
 #else
 #define XPRINTF 0
 #endif
 #endif
  
 #include <string.h>
 #if XPRINTF
 #include <stdarg.h>
 #endif
  
 #ifndef SE_CTX
 #define SeCtx void
 #endif
  
 #ifndef NO_BSD_SOCK
  
 #define SOCKET int
 #endif
  
 #ifndef SOCKET_constructor
 #define SOCKET_constructor(o, ctx) (void)ctx,memset(o,0,sizeof(SOCKET))
 #endif
  
  
 #ifdef __cplusplus
 extern "C" {
 #endif
  
 #if XPRINTF
 void se_disableTrace(int disable);
 #else
 #define se_disableTrace(disable)
 #endif
  
  
 #if XPRINTF && SHARKSSL_ENABLE_INFO_API
 void printCiphersuite(U16 cipherSuite);
 #else
 #define printCiphersuite(notused)
 #endif
  
  
 int seSec_handshake(SharkSslCon *s, SOCKET* sock, U32 timeout, const char* commonName);
  
 int seSec_read(SharkSslCon *s,SOCKET* sock,U8 **buf,U32 timeout);
  
 int seSec_write(SharkSslCon *s, SOCKET* sock, U8* buf, int maxLen);
  
 int se_connect(SOCKET* sock, const char* address, U16 port);
  
 int se_bind(NX_IP *ip_ptr, NX_TCP_SOCKET *socket_ptr, CHAR *name,
	        ULONG type_of_service, ULONG fragment, UINT time_to_live, ULONG window_size,
	        VOID (*tcp_urgent_data_callback)(NX_TCP_SOCKET *socket_ptr),
	        VOID (*tcp_disconnect_callback)(NX_TCP_SOCKET *socket_ptr),
	        UINT tcp_socket_size);
  
 int se_accept(NX_IP *ip_ptr,SOCKET** listenSock, U32 timeout, SOCKET** outSock);
  
 void se_close(SOCKET* sock);
  
 int se_sockValid(SOCKET* sock);
  
 S32 se_send(SOCKET* sock, const void* buf, U32 len);
  
 S32 se_recv(SOCKET* sock, void* buf, U32 len, U32 timeout);
  
  
 /* Macro function designed for IPv4
    sock: a pointer to SOCKET
    buf: a buf large enough to hold 4 bytes
    status: int pointer: out value is negative on error and 4 (len) on success
 */
 #ifndef se_getSockName
 #define se_getSockName(sock, buf, status) do {                  \
    struct sockaddr_in in; int size=sizeof(struct sockaddr_in);      \
    *(status) = getsockname(*(sock), (struct sockaddr *)&in, &size); \
    memcpy((buf), &in.sin_addr.s_addr, 4);                           \
    if(*(status) == 0) *(status) = 4;                                \
 } while(0)
 #endif
  
 #if XPRINTF == 1
  
 #define xprintf(data) _xprintf data
  
 #ifndef _xprintf  /* to handle #define _xprintf printf */
 void _xprintf(const char* fmt, ...);
 #endif
 #else
 #ifndef xprintf
 #define xprintf(data)
 #endif
 #endif
  
 void mainTask(NX_IP *ip_ptr, NX_TCP_SOCKET *socket_ptr, CHAR *name,
	        ULONG type_of_service, ULONG fragment, UINT time_to_live, ULONG window_size,
	        VOID (*tcp_urgent_data_callback)(NX_TCP_SOCKET *socket_ptr),
	        VOID (*tcp_disconnect_callback)(NX_TCP_SOCKET *socket_ptr),
	        UINT tcp_socket_size);
  
 #ifdef __cplusplus
 }
 #endif
  
  /* end group selib */ /* end group Examples */
  
 #endif
