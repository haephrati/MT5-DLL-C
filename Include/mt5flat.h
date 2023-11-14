/* this is header, intended to be used both by the C consumers and the wrapper implementation
 * itself, so it needs to distinguish the declspecs
 */

#if defined(_MT5_FLAT_)
		// this is for the library itself
	#define DECLSPEC __declspec(dllexport) // __declspec(dllexport) here or .def file and ordinals
#else	// the below is for the consumers
	#define DECLSPEC __declspec(dllimport)
#endif

//// this is a wrapped specific function to load MT5APIManager.dll and get addresses of the
// exported functions
DECLSPEC	UINT_PTR	MtWrapperInitialize();
////
//// these are C wrapper functions for the functions, that are exported from MT5APIManager.dll
//typedef MTAPIRES(*MTManagerVersion_t)   (UINT &version);
DECLSPEC	UINT	MtManagerVersion(UINT *version);
//typedef MTAPIRES(*MTManagerCreate_t)    (UINT api_version,IMTManagerAPI **manager);
DECLSPEC	UINT	MtManagerCreate(UINT api_version, void **manager);
//typedef MTAPIRES(*MTManagerCreateExt_t) (UINT api_version,LPCWSTR datapath,IMTManagerAPI **manager);
DECLSPEC	UINT	MtManagerCreateExt(UINT api_version, LPCWSTR datapath, void **manager);
//typedef MTAPIRES(*MTAdminCreate_t)      (UINT api_version,IMTAdminAPI **admin);
DECLSPEC	UINT	MtAdminCreate(UINT api_version, void **admin);
//typedef MTAPIRES(*MTAdminCreateExt_t)   (UINT api_version,LPCWSTR datapath,IMTAdminAPI **admin);
DECLSPEC	UINT	MtAdminCreateExt(UINT api_version, LPCWSTR datapath, void **admin);
////

//// and this is just an attempt to use MT5APIManager.dll interfaces via obtained pointers
// and their API
// these are Admin variants
DECLSPEC	void	Release(void* admin);
DECLSPEC	int		SubscriptionHistoryReserved1(void* admin);
DECLSPEC	int		SubscriptionHistoryReserved2(void* admin);
DECLSPEC	void*	SubscriptionHistoryCreate(void* admin);
DECLSPEC	UINT	SubscriptionHistoryUpdate(void* admin, void* SubscriptionHistoryCreate);


