#ifdef WIN32

#ifdef __cplusplus

#ifdef DLL_EXPORTS
    #define SOUNDTOUCHDLL_API extern "C" __declspec(dllexport)
#else
    #define SOUNDTOUCHDLL_API extern "C" __declspec(dllimport)
#endif

#else

#ifdef DLL_EXPORTS
    #define SOUNDTOUCHDLL_API __declspec(dllexport)
#else
    #define SOUNDTOUCHDLL_API __declspec(dllimport)
#endif

#endif // __cplusplus

#define CDECL __cdecl

#else

#define SOUNDTOUCHDLL_API
#define CDECL

typedef unsigned long DWORD;
typedef unsigned short WORD;
typedef unsigned int UNINT32;

#endif // WIN32
