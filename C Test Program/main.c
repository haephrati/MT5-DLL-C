/* 0:02 13.11.2023
 *
 *
 *
 *
 *
 *
 */
#define WIN32_LEAN_AND_MEAN

#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif

#include<windows.h>
#include"stdio.h"

 /* this is a test C program, that knows nothing about C++ class dll and imports flat C functions
  * from the C wrapper dll (called mt5flat.dll)
  *
  */

  // the line below instructs compiler to include into .obj a comment, that will help linker
  // to find out the import .lib of the wrapper library
#pragma comment(lib, "mt5flat.lib")

// it's our wrapper dll SDK header
#include <mt5flat.h>

int wmain(int argc, wchar_t** wargv) 
{
	void* admin = NULL;	// handle to the IMTAdminAPI
	UINT		res, ver = 0x0b00b135;

	if (!MtWrapperInitialize()) 
	{
		wprintf(L"MtWrapperInitialize failed.\r\n");
		return 0;
	}
	wprintf(L"Loaded mt5apimanager64.dll successfully.\r\n");
	res = MtManagerVersion(&ver);
	wprintf(
		L"res = MtManagerVersion(&ver) returned, res: 0x%x, *ver: 0x%x.\r\n"
		L"And who knows what this means...\r\n",
		res, ver
	);
	res = MtAdminCreate(0xb7c, &admin);
	if (res) // this is our flat C wrapper function call example
	{	
		wprintf(L"MtAdminCreate failed, code: 0x%x.\r\n", res);
		return 0;
	}
	else 
	{
		wprintf(L"MtAdminCreate succeeded.\r\n", res);
	}

	wprintf(L"SubscriptionHistoryReserved1: %d\r\n", SubscriptionHistoryReserved1(admin));	// call to another function
	wprintf(L"SubscriptionHistoryReserved2: %d\r\n", SubscriptionHistoryReserved2(admin));	// yet one
	Release(admin);	// and this is too

	return 0;
}