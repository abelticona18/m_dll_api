// Shared library
#if defined(DLL_TO_BUILD) && defined(DLL_TO_SHARE)
	#error "You must not have both DLL_TO_BUILD and DLL_TO_SHARE defined"
#endif

#ifdef DLL_TO_BUILD
	// Exports
	#ifdef _MSC_VER
		#define DLL_API __declspec(dllexport)
	#else
		#define DLL_API __attribute__((visibility("default")))
	#endif
#else
	// Imports
	#if defined(DLL_TO_SHARE) && defined(_MSC_VER)
		#define DLL_API __declspec(dllimport)
	#else
		#define DLL_API
	#endif
#endif