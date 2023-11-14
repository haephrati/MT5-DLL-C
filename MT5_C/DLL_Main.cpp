#include <iostream>
#include <string>
#include <windows.h>

// this is the main file for the C dll wrapper (mt5flat.dll). All the exported
// functions should be wrapped with extern "C".
// It's a C++ file but serving as a bridge, that lets C code use
// C++ class Dll functions, from MT5APIManager.dll in this case.

// one needs this .lib, it's an import library for mt5apimanager64.dll

#pragma comment(lib, "mt5apimanager64.lib")

#if !defined(_MT5_FLAT_)
#define  _MT5_FLAT_
#endif

#include <MT5APIManager.h>

// Helper functions
std::wstring GetExecutableDirectory()
{
	wchar_t exePath[MAX_PATH];
	GetModuleFileName(NULL, exePath, MAX_PATH);

	// Find the position of the last backslash in the path
	size_t lastSlashPos = wcslen(exePath);
	while (lastSlashPos > 0 && exePath[lastSlashPos - 1] != L'\\')
	{
		lastSlashPos--;
	}

	// Extract the directory path, including the trailing backslash
	exePath[lastSlashPos] = L'\0';

	return std::wstring(exePath);
}
/* An optional entry point into a dynamic-link library (Dll).
 * When the system starts or terminates a process or thread,
 * it calls the entry-point function for each loaded DLL using
 * the first thread of the process.
 * The system also calls the entry-point function for a Dll,
 * when it is loaded or unloaded using the LoadLibrary and FreeLibrary functions.
 *
 * hinstDll - handle to DLL module
 * fdwReason - reason for calling function
 * lpvReserved - reserved

BOOL WINAPI DllMain(HINSTANCE hinstDll, DWORD fdwReason, LPVOID lpvReserved)
{
	// Perform actions based on the reason for calling.
	switch(fdwReason)
	{
		// Initialize once for each new process. Return FALSE to fail DLL load.
		case DLL_PROCESS_ATTACH:
			break;
		case DLL_THREAD_ATTACH:	// Do thread-specific initialization.
			break;
		case DLL_THREAD_DETACH:	// Do thread-specific cleanup.
			break;
		case DLL_PROCESS_DETACH:
			if(lpvReserved != nullptr)
			{
				break;	// do not do cleanup if process termination scenario
			}
			// Perform any necessary cleanup.
			break;
	}
	return TRUE;  // Successful DLL_PROCESS_ATTACH.
}
 */

 //typedef int (*MTAdminCreate_t)(UINT api_version, void** admin);
 //MTAdminCreate_t
 // ===============

 /*
 the below function names, are what mt5apimanager64.dll exports
 but they aren't exposed like that in the headers, so we have
 to take a defined function name, like e.g. MTAdminCreate_t
 and then dynamically load mt5apimanager64.dll via LoadLibraryW
 and then fill these 5 function pointers with valid function
 addresses, using GetProcAddress. This requires to define
 yet another function, that will do that and that should
 be called before using anything else from mt5apimanager64.dll
 NO WAY to put code, calling LoadLibraryW in DllMain!
 The Microsoft documentation clearly says, it's ask for crashes.
	 ordinal hint
		   1    0 00184BA0 MTAdminCreate
		   2    1 00184BC0 MTAdminCreateExt
		   3    2 00184BB0 MTManagerCreate
		   4    3 00184D60 MTManagerCreateExt
		   5    4 00184F20 MTManagerVersion
 */



extern "C" 
{
#include <mt5flat.h>

	HMODULE	g_hDll = NULL;

	MTAdminCreate_t			AdminCreate = NULL;
	MTAdminCreateExt_t		AdminCreateExt = NULL;
	MTManagerCreate_t		ManagerCreate = NULL;
	MTManagerCreateExt_t	ManagerCreateExt = NULL;
	MTManagerVersion_t		ManagerVersion = NULL;

	// 1 - success, 0 - fail.
	// we won't search mt5apimanager64.dll anywhere other, than in
	// the current directory. you are free to add as much searching
	// as you would be happy to add.
	UINT_PTR	MtWrapperInitialize() 
	{
		std::wstring MT5APIMANAGER64DLL = GetExecutableDirectory();
		MT5APIMANAGER64DLL += L"mt5apimanager64.dll";
		g_hDll = LoadLibraryW(MT5APIMANAGER64DLL.c_str());
		if (!g_hDll)
			return 0;
		
		return(g_hDll = LoadLibraryW(MT5APIMANAGER64DLL.c_str()))
			&& (AdminCreate = (MTAdminCreate_t)GetProcAddress(g_hDll, (LPCSTR)1))	// you can use name instead of ordinal
			&& (AdminCreateExt = (MTAdminCreateExt_t)GetProcAddress(g_hDll, (LPCSTR)2))
			&& (ManagerCreate = (MTManagerCreate_t)GetProcAddress(g_hDll, (LPCSTR)3))
			&& (ManagerCreateExt = (MTManagerCreateExt_t)GetProcAddress(g_hDll, (LPCSTR)4))
			&& (ManagerVersion = (MTManagerVersion_t)GetProcAddress(g_hDll, (LPCSTR)5));
	}
	////
	UINT MtManagerVersion(UINT* version) 
	{
		UINT	v = *version;
		return ManagerVersion(v);
	}

	UINT MtAdminCreate(UINT api_version, void** admin) 
	{
		return AdminCreate(api_version, (IMTAdminAPI**)admin);
	}

	UINT MtAdminCreateExt(UINT api_version, LPCWSTR datapath, void** admin) 
	{
		return AdminCreateExt(api_version, datapath, (IMTAdminAPI**)admin);
	}

	UINT MtManagerCreate(UINT api_version, void** manager) 
	{
		return ManagerCreate(api_version, (IMTManagerAPI**)manager);
	}

	UINT MtManagerCreateExt(UINT api_version, LPCWSTR datapath, void** manager) 
	{
		return ManagerCreateExt(api_version, datapath, (IMTManagerAPI**)manager);
	}
	////


	//// these are Admin variants
	void Release(void* admin) 
	{
		return ((IMTAdminAPI*)admin)->Release();
	}

	int SubscriptionHistoryReserved1(void* admin) 
	{
		return reinterpret_cast<IMTAdminAPI*>(admin)->SubscriptionHistoryReserved1();
	}

	int SubscriptionHistoryReserved2(void* admin) 
	{
		return reinterpret_cast<IMTAdminAPI*>(admin)->SubscriptionHistoryReserved2();
	}

	void* SubscriptionHistoryCreate(void* admin) 
	{
		return reinterpret_cast<IMTAdminAPI*>(admin)->SubscriptionHistoryCreate();
	}

	MTAPIRES SubscriptionHistoryUpdate(void* admin, void* SubscriptionHistoryCreate) 
	{
		return reinterpret_cast<IMTAdminAPI*>(admin)->SubscriptionHistoryUpdate(
			(IMTSubscriptionHistory*)SubscriptionHistoryCreate);
	}

} // extern "C"


