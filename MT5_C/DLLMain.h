#pragma once
#include <windows.h>

// Declare the function with extern "C" for compatibility with C clients
extern "C" {
#if defined(_MT5_FLAT_)
    // this is for the library itself
#define DECLSPEC __declspec(dllexport) // __declspec(dllexport) here or .def file and ordinals
#else
    // the below is for the consumers
#define DECLSPEC __declspec(dllimport)
#endif

    DECLSPEC int MTAdminCreate(UINT api_version, void** admin);
    DECLSPEC void* Release(void* admin);
    DECLSPEC int SubscriptionHistoryReserved1(void* admin);
    DECLSPEC int SubscriptionHistoryReserved2(void* admin);
    DECLSPEC void* SubscriptionHistoryCreate(void* admin);
    DECLSPEC void* SubscriptionHistoryUpdate(void* admin, void* SubscriptionHistoryCreate);
}
