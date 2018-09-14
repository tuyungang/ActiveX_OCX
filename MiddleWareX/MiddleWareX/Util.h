#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
//#include <string.h>
//#include <conio.h>
#include <tchar.h>
#include <errno.h>
#include <assert.h>
#include <vector>
#include <memory>
#include <list>
#include <map>
#include <windows.h>

#include <process.h>
#include <strsafe.h>
#include <atlbase.h>
#include <atlstr.h>    
#include <locale.h>
#include <winuser.h>
#include <io.h>

#include "ProcDataDef.h"


using namespace std;

extern CRITICAL_SECTION g_cs_log;

inline void InitCS(CRITICAL_SECTION * cs){
	if (!::InitializeCriticalSectionAndSpinCount(cs, 4000))
		::InitializeCriticalSection(cs);
}

inline void DestCS(CRITICAL_SECTION * cs){
	::DeleteCriticalSection(cs);
}
inline void InitGlobalCS()
{
	InitCS(&g_cs_log);
}
inline void DestGlobalCS()
{
	DestCS(&g_cs_log);
}

class CSLock
{
public:
	CSLock(
		_Inout_ CRITICAL_SECTION& cs,
		_In_ bool bInitialLock = true,
		_In_ bool bInitialcs = false);
	~CSLock() throw();
	void Lock();
	void Unlock() throw();
private:
	CRITICAL_SECTION& m_cs;
	bool m_bLocked;
	// Private to avoid accidental use
	CSLock(_In_ const CSLock&) throw();
	CSLock& operator=(_In_ const CSLock&) throw();
};

inline CSLock::CSLock(
	_Inout_ CRITICAL_SECTION& cs,
	_In_ bool bInitialLock,
	_In_ bool bInitialcs) :
	m_cs(cs), m_bLocked(false)
{
	if (bInitialcs)
		InitCS(&m_cs);
	if (bInitialLock)
		Lock();
}
inline CSLock::~CSLock() throw()
{
	if (m_bLocked)
		Unlock();
}
inline void CSLock::Lock()
{
	::EnterCriticalSection(&m_cs);
	m_bLocked = true;
}
inline void CSLock::Unlock() throw()
{
	::LeaveCriticalSection(&m_cs);
	m_bLocked = false;
}

bool InitIniConfig();
void trim(char *str);

/* --------------------------------------------------------------------------*/
/**
* @brief GetIniKeyString
* @description 获取字符串值，按section和key值
*
* @param section
* @param key
* @param vaule
*/
/* ----------------------------------------------------------------------------*/
void GetIniKeyString(const char *section, const char *key, char *vaule);
void GetIniKeyInt(const char *section, const char *key, int vaule);
void GetIniKeyLong(const char *section, const char *key, long vaule);

string Decrypto_base64(string const& encoded_string);
string Encrypto_base64(unsigned char const* bytes_to_encode, unsigned int in_len);

