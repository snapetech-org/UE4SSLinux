#include <stdint.h>
#include <stddef.h>

#define WINAPI
#define CALLBACK
#define CDECL __cdecl

typedef void *HANDLE;
typedef void *HMODULE;
typedef void *HINSTANCE;
typedef void *LPVOID;
typedef const char *LPCSTR;
typedef char *LPSTR;
typedef unsigned short WCHAR;
typedef const WCHAR *LPCWSTR;
typedef unsigned long DWORD;
typedef int BOOL;
typedef uintptr_t SIZE_T;

#define TRUE 1
#define FALSE 0
#define DLL_PROCESS_ATTACH 1
#define DLL_PROCESS_DETACH 0
#define FILE_APPEND_DATA 0x00000004UL
#define GENERIC_READ 0x80000000UL
#define FILE_SHARE_READ 0x00000001UL
#define FILE_SHARE_WRITE 0x00000002UL
#define FILE_SHARE_DELETE 0x00000004UL
#define OPEN_EXISTING 3UL
#define OPEN_ALWAYS 4UL
#define FILE_ATTRIBUTE_NORMAL 0x00000080UL
#define INVALID_HANDLE_VALUE ((HANDLE)(intptr_t)-1)
#define MEM_COMMIT 0x00001000UL
#define MEM_RESERVE 0x00002000UL
#define MEM_RELEASE 0x00008000UL
#define MEM_IMAGE 0x01000000UL
#define MEM_PRIVATE 0x00020000UL
#define PAGE_NOACCESS 0x01UL
#define PAGE_READONLY 0x02UL
#define PAGE_READWRITE 0x04UL
#define PAGE_WRITECOPY 0x08UL
#define PAGE_EXECUTE 0x10UL
#define PAGE_EXECUTE_READ 0x20UL
#define PAGE_EXECUTE_READWRITE 0x40UL
#define PAGE_EXECUTE_WRITECOPY 0x80UL
#define PAGE_GUARD 0x100UL
#define FILE_ATTRIBUTE_DIRECTORY 0x00000010UL
#define MAX_PATH_WIN 260

#define MAX_NEEDLES 160
#define MAX_NEEDLE_LEN 192
#define MAX_FILTERS 40
#define MAX_PATTERNS 256
#define MAX_PATTERN_BYTES 256
#define MAX_PATTERN_NAME 128
#define MAX_UE_ANCHORS 32
#define MAX_UE_ANCHOR_NAME 128
#define MAX_UE_LAYOUT_SLOTS 64
#define DEFAULT_UE_LAYOUT_SLOTS 8
#define INLINE_HOOK_PATCH_LEN 12
#define MAX_HOOK_DISPATCH_CALLBACKS 8
#define MAX_MOD_DISPATCH_ENTRIES 16
#define MAX_LUA_MOD_SCRIPTS 32
#define MAX_LUA_HOOK_REGISTRATIONS 32
#define MAX_LUA_NOTIFY_ON_NEW_OBJECT_REGISTRATIONS 32
#define MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS 32
#define MAX_LUA_OBJECT_HANDLES 64
#define MAX_LUA_CLASS_METADATA 64
#define MAX_LUA_SCRIPT_PATH 1024
#define MAX_LUA_SCRIPT_NAME 128
#define MAX_LUA_OBJECT_PATH 256
#define MAX_LUA_OBJECT_NAME 128
#define MAX_LUA_CLASS_NAME 128
#define MAX_LUA_SCRIPT_BYTES (256UL * 1024UL)
#define MAX_SIGNATURE_FILE_BYTES (128UL * 1024UL)
#define DEFAULT_UE_OBJECT_ITEM_SIZE 24
#define DEFAULT_UE_OBJECT_CHUNK_SIZE 65536
#define DEFAULT_UE_OBJECT_ARRAY_MAX_OBJECTS 128
#define MAX_UE_OBJECT_ARRAY_SCAN_OBJECTS 4096
#define DEFAULT_UE_FNAME_BLOCKS_OFFSET 0x10
#define DEFAULT_UE_FNAME_STRIDE 2
#define DEFAULT_UE_FNAME_MAX_LENGTH 128
#define MAX_UE_FNAME_LENGTH 512
#define DEFAULT_UE_REFLECTION_NEXT_OFFSET 0x28
#define DEFAULT_UE_REFLECTION_SUPER_OFFSET 0x30
#define DEFAULT_UE_REFLECTION_CHILDREN_OFFSET 0x38
#define DEFAULT_UE_REFLECTION_CHILD_PROPERTIES_OFFSET 0x40
#define DEFAULT_UE_REFLECTION_PROPERTY_LINK_OFFSET 0x48
#define DEFAULT_UE_REFLECTION_FUNCTION_LINK_OFFSET 0x50
#define DEFAULT_UE_REFLECTION_FIELD_NEXT_OFFSET 0x28
#define DEFAULT_UE_REFLECTION_MAX_FIELDS 16
#define DEFAULT_UE_REFLECTION_PROPERTY_ARRAY_DIM_OFFSET 0x30
#define DEFAULT_UE_REFLECTION_PROPERTY_ELEMENT_SIZE_OFFSET 0x34
#define DEFAULT_UE_REFLECTION_PROPERTY_FLAGS_OFFSET 0x38
#define DEFAULT_UE_REFLECTION_PROPERTY_OFFSET_INTERNAL_OFFSET 0x44
#define DEFAULT_UE_REFLECTION_FUNCTION_FLAGS_OFFSET 0x58
#define DEFAULT_UE_REFLECTION_VALUE_MAX_BYTES 16
#define DEFAULT_UE_REFLECTION_CONTAINER_CHILD_SCAN_START 0x48
#define DEFAULT_UE_REFLECTION_CONTAINER_CHILD_SCAN_END 0xa0
#define MAX_UE_REFLECTION_SLOT_OFFSET 0x400
#define MAX_UE_REFLECTION_FIELDS 256
#define MAX_UE_REFLECTION_VALUE_BYTES 64
#define MAX_UE_REFLECTION_PROPERTY_CANDIDATES 256
#define MAX_UE_FUNCTION_PARAM_DESCRIPTORS 256
#define MAX_PROCESS_EVENT_LIVE_PARAM_LOGS 8
#define UE_PROPERTY_FLAG_PARM 0x80ULL
#define UE_PROPERTY_FLAG_OUT_PARM 0x100ULL
#define UE_PROPERTY_FLAG_RETURN_PARM 0x400ULL
#define UE_INTERNAL_OBJECT_FLAG_NATIVE 0x02000000U
#define SELF_TEST_FNAME_INDEX 1234U
#define SELF_TEST_FNAME_VALUE "SelfTestUObjectName"
#define SELF_TEST_FNAME_VALUE_PARAM_INDEX 1250U
#define SELF_TEST_FNAME_ORIGINAL_RESULT_PARAM_INDEX 1260U
#define SELF_TEST_FNAME_TOUCHED_PARAM_INDEX 1270U
#define SELF_TEST_FNAME_INT_PROPERTY_INDEX 1280U
#define SELF_TEST_FNAME_NAME_TOKEN_PARAM_INDEX 1290U
#define SELF_TEST_FNAME_MESSAGE_PARAM_INDEX 1300U
#define SELF_TEST_FNAME_NAME_PROPERTY_INDEX 1310U
#define SELF_TEST_FNAME_STR_PROPERTY_INDEX 1320U
#define SELF_TEST_FNAME_LOCATION_PARAM_INDEX 1330U
#define SELF_TEST_FNAME_STRUCT_PROPERTY_INDEX 1340U
#define SELF_TEST_FSTRING_MESSAGE "desert-message"
#define SELF_TEST_RAW_LIVE_VALUE 13
#define SELF_TEST_RAW_SET_VALUE 17
#define MAX_PROCESS_EVENT_STRING_CHARS 4096
#define MAX_PROCESS_EVENT_PARAM_BYTES 64
#define MAX_LINE 8192
#define MAX_CONFIG_BYTES 8192
#define MAX_CONFIG_ENTRIES 96
#define MAX_CONFIG_KEY 128
#define MAX_CONFIG_VALUE 2048
#define DEFAULT_MAX_HITS 16
#define DEFAULT_MAX_REGION_BYTES (256ULL * 1024ULL * 1024ULL)

typedef struct {
  LPVOID BaseAddress;
  LPVOID AllocationBase;
  DWORD AllocationProtect;
  unsigned short PartitionId;
  SIZE_T RegionSize;
  DWORD State;
  DWORD Protect;
  DWORD Type;
} MEMORY_BASIC_INFORMATION_WIN64;

typedef struct {
  union {
    DWORD dwOemId;
    struct {
      unsigned short wProcessorArchitecture;
      unsigned short wReserved;
    };
  };
  DWORD dwPageSize;
  LPVOID lpMinimumApplicationAddress;
  LPVOID lpMaximumApplicationAddress;
  uintptr_t dwActiveProcessorMask;
  DWORD dwNumberOfProcessors;
  DWORD dwProcessorType;
  DWORD dwAllocationGranularity;
  unsigned short wProcessorLevel;
  unsigned short wProcessorRevision;
} SYSTEM_INFO_WIN;

typedef struct {
  unsigned short wYear;
  unsigned short wMonth;
  unsigned short wDayOfWeek;
  unsigned short wDay;
  unsigned short wHour;
  unsigned short wMinute;
  unsigned short wSecond;
  unsigned short wMilliseconds;
} SYSTEMTIME_WIN;

typedef struct {
  DWORD dwLowDateTime;
  DWORD dwHighDateTime;
} FILETIME_WIN;

typedef struct {
  DWORD dwFileAttributes;
  FILETIME_WIN ftCreationTime;
  FILETIME_WIN ftLastAccessTime;
  FILETIME_WIN ftLastWriteTime;
  DWORD nFileSizeHigh;
  DWORD nFileSizeLow;
  DWORD dwReserved0;
  DWORD dwReserved1;
  char cFileName[MAX_PATH_WIN];
  char cAlternateFileName[14];
} WIN32_FIND_DATAA_WIN;

typedef struct {
  char name[MAX_PATTERN_NAME];
  int bytes[MAX_PATTERN_BYTES];
  size_t length;
} BytePattern;

typedef struct {
  char name[MAX_UE_ANCHOR_NAME];
  uintptr_t address;
} UeAnchor;

typedef struct {
  uintptr_t vtable;
  uint32_t object_flags;
  int32_t internal_index;
  uintptr_t class_private;
  uint32_t name_comparison_index;
  uint32_t name_number;
  uintptr_t outer_private;
} UeSelfTestObject;

typedef struct {
  uintptr_t chunks;
  uintptr_t preallocated;
  uint32_t max_elements;
  uint32_t num_elements;
  uint32_t max_chunks;
  uint32_t num_chunks;
} UeSelfTestChunkedObjectArray;

typedef struct {
  uintptr_t lock;
  uint32_t current_block;
  uint32_t current_byte_cursor;
  uintptr_t blocks[1];
} UeSelfTestFNamePool;

typedef struct {
  uint32_t comparison_index;
  uint32_t number;
} UeFNameValue;

typedef struct {
  uintptr_t data;
  int32_t count;
  int32_t capacity;
} UeFStringValue;

typedef struct {
  uintptr_t data;
  int32_t num;
  int32_t max;
} UeFScriptContainerHeader;

typedef struct {
  double x;
  double y;
  double z;
} UeFVectorValue;

typedef struct {
  UeSelfTestObject object;
  uintptr_t next;
  int32_t array_dim;
  int32_t element_size;
  uint64_t property_flags;
  uint16_t rep_index;
  uint8_t blueprint_replication_condition;
  uint8_t property_padding;
  int32_t offset_internal;
} UeSelfTestField;

typedef struct {
  UeSelfTestObject object;
  uintptr_t next;
  uintptr_t super_struct;
  uintptr_t children;
  uintptr_t child_properties;
  uintptr_t property_link;
  uintptr_t function_link;
  uint32_t function_flags;
} UeSelfTestClass;

typedef struct {
  void *target;
  void *replacement;
  void *trampoline;
  unsigned char original[INLINE_HOOK_PATCH_LEN];
  size_t patch_len;
  size_t trampoline_len;
  DWORD original_protect;
  int installed;
} InlineHookPatch;

typedef int (*HookSelfTestFn)(int);
typedef void (*ProcessEventSelfTestFn)(void *, void *, void *);
typedef void LuaState;
typedef LuaState *(CDECL *LuaNewStateFn)(void);
typedef void (CDECL *LuaOpenLibsFn)(LuaState *);
typedef int (CDECL *LuaLoadStringFn)(LuaState *, const char *);
typedef int (CDECL *LuaPCallKFn)(LuaState *, int, int, int, intptr_t, void *);
typedef int (CDECL *LuaPCallFn)(LuaState *, int, int, int);
typedef long long (CDECL *LuaToIntegerXFn)(LuaState *, int, int *);
typedef long long (CDECL *LuaToIntegerFn)(LuaState *, int);
typedef double (CDECL *LuaToNumberXFn)(LuaState *, int, int *);
typedef double (CDECL *LuaToNumberFn)(LuaState *, int);
typedef const char *(CDECL *LuaToLStringFn)(LuaState *, int, size_t *);
typedef int (CDECL *LuaToBooleanFn)(LuaState *, int);
typedef int (CDECL *LuaCFunction)(LuaState *);
typedef void (CDECL *LuaPushCClosureFn)(LuaState *, LuaCFunction, int);
typedef void (CDECL *LuaSetGlobalFn)(LuaState *, const char *);
typedef void (CDECL *LuaPushIntegerFn)(LuaState *, long long);
typedef void (CDECL *LuaPushNumberFn)(LuaState *, double);
typedef void (CDECL *LuaPushNilFn)(LuaState *);
typedef void (CDECL *LuaPushStringFn)(LuaState *, const char *);
typedef void (CDECL *LuaPushBooleanFn)(LuaState *, int);
typedef void (CDECL *LuaCreateTableFn)(LuaState *, int, int);
typedef void (CDECL *LuaSetFieldFn)(LuaState *, int, const char *);
typedef int (CDECL *LuaTypeFn)(LuaState *, int);
typedef void (CDECL *LuaPushValueFn)(LuaState *, int);
typedef int (CDECL *LuaLRefFn)(LuaState *, int);
typedef void (CDECL *LuaRawGetIFn)(LuaState *, int, long long);
typedef void (CDECL *LuaLUnrefFn)(LuaState *, int, int);
typedef void (CDECL *LuaSetTopFn)(LuaState *, int);
typedef void (CDECL *LuaGetFieldFn)(LuaState *, int, const char *);
typedef void (CDECL *LuaCloseFn)(LuaState *);

#define LUA_REGISTRYINDEX_COMPAT (-1001000)
#define LUA_TNIL_COMPAT 0
#define LUA_TBOOLEAN_COMPAT 1
#define LUA_TNUMBER_COMPAT 3
#define LUA_TSTRING_COMPAT 4
#define LUA_TFUNCTION_COMPAT 6
#define LUA_TTABLE_COMPAT 5
#define LUA_REFNIL_COMPAT (-1)
#define LUA_NOREF_COMPAT (-2)

typedef enum {
  HOOK_DISPATCH_PRE = 0,
  HOOK_DISPATCH_POST = 1,
} HookDispatchStage;

typedef struct {
  int value;
  int original_result;
  int result;
  int pre_callbacks;
  int post_callbacks;
} HookDispatchContext;

typedef void (*HookDispatchCallback)(HookDispatchContext *ctx, void *user);

typedef struct {
  HookDispatchStage stage;
  HookDispatchCallback callback;
  void *user;
} HookDispatchSlot;

typedef struct {
  void *object;
  void *function;
  void *params;
  const char *function_path;
  int call_index;
  int original_called;
  int pre_callbacks;
  int post_callbacks;
} ProcessEventDispatchContext;

typedef void (*ProcessEventDispatchCallback)(ProcessEventDispatchContext *ctx, void *user);

typedef struct {
  HookDispatchStage stage;
  ProcessEventDispatchCallback callback;
  void *user;
} ProcessEventDispatchSlot;

static uintptr_t process_event_self_test_function_address(void);

typedef struct {
  const char *name;
  void (*on_load)(void *user);
  HookDispatchCallback on_pre_hook;
  HookDispatchCallback on_post_hook;
  void (*on_unload)(void *user);
  void *user;
  int loaded;
} ModDispatchEntry;

typedef struct {
  char path[MAX_LUA_SCRIPT_PATH];
  char name[MAX_LUA_SCRIPT_NAME];
} LuaModScript;

typedef struct {
  LuaModScript scripts[MAX_LUA_MOD_SCRIPTS];
  size_t count;
  size_t skipped;
} LuaModScriptList;

typedef struct {
  char path[MAX_LUA_OBJECT_PATH];
  char name[MAX_LUA_OBJECT_NAME];
  char class_name[MAX_LUA_CLASS_NAME];
  uintptr_t address;
  uintptr_t class_address;
  uintptr_t outer_address;
  uintptr_t super_address;
  uint32_t object_flags;
  int32_t internal_index;
  int has_object_metadata;
  uint32_t internal_flags;
  int has_internal_flags;
  uint32_t function_flags;
  int has_function_flags;
} LuaObjectHandle;

typedef struct {
  char name[MAX_LUA_OBJECT_NAME];
  uintptr_t address;
  uintptr_t super_address;
} LuaClassMetadata;

typedef struct {
  char name[256];
  int pre_ref;
  int post_ref;
  int pre_calls;
  int post_calls;
  long long pre_result;
  long long post_result;
  int pre_is_number;
  int post_is_number;
} LuaHookRegistration;

typedef struct {
  char filter[MAX_LUA_OBJECT_PATH];
  int ref;
  int calls;
  long long result;
  int is_number;
  int status;
} LuaNotifyOnNewObjectRegistration;

typedef struct {
  char name[128];
  int ref;
  int global;
  int calls;
  int handled;
} LuaConsoleCommandRegistration;

typedef struct {
  int ref;
  int calls;
  int handled;
  int status;
} LuaConsoleExecHookRegistration;

typedef struct {
  int ref;
  int calls;
  int handled;
  int status;
} LuaCallFunctionHookRegistration;

typedef struct {
  char name[128];
  int ref;
  int calls;
  int handled;
  int status;
} LuaCustomEventRegistration;

typedef struct {
  uintptr_t object;
  char property_name[64];
  char field_name[64];
  int32_t offset_internal;
  int32_t element_size;
  int32_t array_dim;
  size_t read_bytes;
  uint64_t raw_le;
} UeReflectionPropertyCandidate;

typedef struct {
  int present;
  uintptr_t field;
  uintptr_t property_class;
  uintptr_t container_offset;
  char role[16];
  char name[64];
  char class_name[64];
  char type[32];
  int32_t offset_internal;
  int32_t element_size;
  int32_t array_dim;
  uint64_t property_flags;
} UeFunctionParamChildDescriptor;

typedef struct {
  uintptr_t function;
  uintptr_t field;
  char function_name[MAX_LUA_OBJECT_NAME];
  char function_path[MAX_LUA_OBJECT_PATH];
  char property_name[64];
  char field_name[64];
  char class_name[64];
  char chain_name[32];
  size_t index;
  int32_t offset_internal;
  int32_t element_size;
  int32_t array_dim;
  uint64_t property_flags;
  uint32_t function_flags;
  int function_flags_readable;
  size_t child_count;
  UeFunctionParamChildDescriptor children[2];
} UeFunctionParamDescriptor;

typedef struct {
  char name[64];
  char type[32];
  char class_name[64];
  char inner_name[64];
  char inner_type[32];
  char inner_class_name[64];
  size_t inner_size;
  size_t offset;
  size_t size;
  int valid;
} LuaParamDescriptorView;

#define MAX_LUA_SHARED_VARIABLES 16
#define MAX_LUA_SHARED_VARIABLE_NAME 64
#define MAX_LUA_SHARED_VARIABLE_STRING 256

typedef struct {
  char name[MAX_LUA_SHARED_VARIABLE_NAME];
  int type;
  long long integer_value;
  int boolean_value;
  uintptr_t object_address;
  char string_value[MAX_LUA_SHARED_VARIABLE_STRING];
} LuaSharedVariable;

typedef struct {
  int value;
  int original_result;
  int touched;
  uint8_t flag;
  int8_t signed_byte;
  uint16_t unsigned_short;
  int64_t signed_large;
  float float_value;
  double double_value;
  uintptr_t target_object;
  UeFNameValue name_token;
  UeFStringValue message;
  UeFVectorValue location;
} ProcessEventSelfTestParams;

typedef struct {
  const char *name;
  const char *alias1;
  const char *alias2;
  size_t offset;
  size_t size;
  const char *type;
  const char *class_name;
} ProcessEventParamDescriptor;

static const ProcessEventParamDescriptor process_event_self_test_param_descriptors[] = {
  {"Value", "value", 0, offsetof(ProcessEventSelfTestParams, value), sizeof(int), "int32", "FIntProperty"},
  {"OriginalResult", "original_result", "originalResult", offsetof(ProcessEventSelfTestParams, original_result), sizeof(int), "int32", "FIntProperty"},
  {"Touched", "touched", 0, offsetof(ProcessEventSelfTestParams, touched), sizeof(int), "int32", "FIntProperty"},
  {"Flag", "flag", 0, offsetof(ProcessEventSelfTestParams, flag), sizeof(uint8_t), "bool", "FBoolProperty"},
  {"SignedByte", "signed_byte", "signedByte", offsetof(ProcessEventSelfTestParams, signed_byte), sizeof(int8_t), "int8", "FInt8Property"},
  {"UnsignedShort", "unsigned_short", "unsignedShort", offsetof(ProcessEventSelfTestParams, unsigned_short), sizeof(uint16_t), "uint16", "FUInt16Property"},
  {"SignedLarge", "signed_large", "signedLarge", offsetof(ProcessEventSelfTestParams, signed_large), sizeof(int64_t), "int64", "FInt64Property"},
  {"FloatValue", "float_value", "floatValue", offsetof(ProcessEventSelfTestParams, float_value), sizeof(float), "float", "FFloatProperty"},
  {"DoubleValue", "double_value", "doubleValue", offsetof(ProcessEventSelfTestParams, double_value), sizeof(double), "double", "FDoubleProperty"},
  {"TargetObject", "target_object", "targetObject", offsetof(ProcessEventSelfTestParams, target_object), sizeof(uintptr_t), "object", "FObjectProperty"},
  {"NameToken", "name_token", "nameToken", offsetof(ProcessEventSelfTestParams, name_token), sizeof(UeFNameValue), "fname", "FNameProperty"},
  {"Message", "message", 0, offsetof(ProcessEventSelfTestParams, message), sizeof(UeFStringValue), "string", "FStrProperty"},
  {"Location", "location", 0, offsetof(ProcessEventSelfTestParams, location), sizeof(UeFVectorValue), "vector", "FStructProperty"},
};
static const size_t process_event_self_test_param_descriptor_count =
  sizeof(process_event_self_test_param_descriptors) / sizeof(process_event_self_test_param_descriptors[0]);

typedef struct {
  HMODULE module;
  char library[256];
  LuaNewStateFn new_state;
  LuaOpenLibsFn open_libs;
  LuaLoadStringFn load_string;
  LuaPCallKFn pcallk;
  LuaPCallFn pcall;
  LuaToIntegerXFn to_integerx;
  LuaToIntegerFn to_integer;
  LuaToNumberXFn to_numberx;
  LuaToNumberFn to_number;
  LuaToLStringFn to_lstring;
  LuaToBooleanFn to_boolean;
  LuaPushCClosureFn push_cclosure;
  LuaSetGlobalFn set_global;
  LuaPushIntegerFn push_integer;
  LuaPushNumberFn push_number;
  LuaPushNilFn push_nil;
  LuaPushStringFn push_string;
  LuaPushBooleanFn push_boolean;
  LuaCreateTableFn create_table;
  LuaSetFieldFn set_field;
  LuaTypeFn type;
  LuaPushValueFn push_value;
  LuaLRefFn ref;
  LuaRawGetIFn rawgeti;
  LuaLUnrefFn unref;
  LuaSetTopFn set_top;
  LuaGetFieldFn get_field;
  LuaCloseFn close;
} LuaApi;

typedef struct {
  char text[MAX_LINE];
  size_t len;
} Line;

typedef struct {
  char key[MAX_CONFIG_KEY];
  char value[MAX_CONFIG_VALUE];
} ConfigEntry;

__declspec(dllimport) DWORD __stdcall GetCurrentProcessId(void);
__declspec(dllimport) DWORD __stdcall GetEnvironmentVariableA(LPCSTR, LPSTR, DWORD);
__declspec(dllimport) DWORD __stdcall GetModuleFileNameA(HMODULE, LPSTR, DWORD);
__declspec(dllimport) void __stdcall GetSystemTime(SYSTEMTIME_WIN *);
__declspec(dllimport) void __stdcall GetNativeSystemInfo(SYSTEM_INFO_WIN *);
__declspec(dllimport) SIZE_T __stdcall VirtualQuery(const void *, MEMORY_BASIC_INFORMATION_WIN64 *, SIZE_T);
__declspec(dllimport) HANDLE __stdcall CreateFileA(LPCSTR, DWORD, DWORD, LPVOID, DWORD, DWORD, HANDLE);
__declspec(dllimport) BOOL __stdcall ReadFile(HANDLE, void *, DWORD, DWORD *, LPVOID);
__declspec(dllimport) BOOL __stdcall WriteFile(HANDLE, const void *, DWORD, DWORD *, LPVOID);
__declspec(dllimport) BOOL __stdcall CloseHandle(HANDLE);
__declspec(dllimport) BOOL __stdcall DisableThreadLibraryCalls(HMODULE);
__declspec(dllimport) HANDLE __stdcall CreateThread(LPVOID, SIZE_T, DWORD (__stdcall *)(LPVOID), LPVOID, DWORD, DWORD *);
__declspec(dllimport) void __stdcall Sleep(DWORD);
__declspec(dllimport) HMODULE __stdcall LoadLibraryA(LPCSTR);
__declspec(dllimport) BOOL __stdcall FreeLibrary(HMODULE);
__declspec(dllimport) void *__stdcall GetProcAddress(HMODULE, LPCSTR);
__declspec(dllimport) BOOL __stdcall VirtualProtect(LPVOID, SIZE_T, DWORD, DWORD *);
__declspec(dllimport) BOOL __stdcall FlushInstructionCache(HANDLE, const void *, SIZE_T);
__declspec(dllimport) LPVOID __stdcall VirtualAlloc(LPVOID, SIZE_T, DWORD, DWORD);
__declspec(dllimport) BOOL __stdcall VirtualFree(LPVOID, SIZE_T, DWORD);
__declspec(dllimport) HANDLE __stdcall FindFirstFileA(LPCSTR, WIN32_FIND_DATAA_WIN *);
__declspec(dllimport) BOOL __stdcall FindNextFileA(HANDLE, WIN32_FIND_DATAA_WIN *);
__declspec(dllimport) BOOL __stdcall FindClose(HANDLE);

static HMODULE self_module;
static HMODULE real_version_module;
static volatile int probe_started;
static uintptr_t ue_self_test_target[4];
static uintptr_t ue_self_test_anchor;
static UeSelfTestFNamePool ue_self_test_fname_pool;
static unsigned char ue_self_test_fname_block[4096];
static UeSelfTestClass ue_self_test_class;
static UeSelfTestClass ue_self_test_int_property_class;
static UeSelfTestClass ue_self_test_name_property_class;
static UeSelfTestClass ue_self_test_str_property_class;
static UeSelfTestClass ue_self_test_struct_property_class;
static uintptr_t ue_self_test_fvector_script_struct_anchor;
static UeSelfTestClass ue_self_test_function;
static UeSelfTestField ue_self_test_children_field;
static UeSelfTestField ue_self_test_property_field;
static UeSelfTestField ue_self_test_value_param_field;
static UeSelfTestField ue_self_test_original_result_param_field;
static UeSelfTestField ue_self_test_touched_param_field;
static UeSelfTestField ue_self_test_name_token_param_field;
static UeSelfTestField ue_self_test_message_param_field;
static UeSelfTestField ue_self_test_location_param_field;
static UeSelfTestObject ue_self_test_object;
static char ue_self_test_process_event_message[] = SELF_TEST_FSTRING_MESSAGE;
static uintptr_t ue_self_test_uobject_anchor;
static unsigned char ue_self_test_object_items[DEFAULT_UE_OBJECT_ITEM_SIZE * 2];
static uintptr_t ue_self_test_object_chunks[1];
static UeSelfTestChunkedObjectArray ue_self_test_object_array;
static uintptr_t ue_self_test_object_array_anchor;
static HookSelfTestFn volatile hook_self_test_entry;
static HookSelfTestFn volatile hook_self_test_original;
static ProcessEventSelfTestFn volatile process_event_self_test_entry;
static ProcessEventSelfTestFn volatile process_event_self_test_original;
static ProcessEventSelfTestFn volatile process_event_live_probe_original;
static ProcessEventSelfTestFn volatile process_event_live_hook_original;
static InlineHookPatch process_event_live_hook;
static int process_event_live_hook_installed;
static int process_event_live_hook_calls;
static int process_event_live_hook_original_calls;
static int process_event_live_hook_log_calls;
static int process_event_live_hook_call_log_limit;
static LuaApi process_event_live_lua_api;
static LuaState *process_event_live_lua_state;
static int process_event_live_lua_loaded;
static int process_event_live_lua_enabled;
static int process_event_live_lua_load_status;
static int process_event_live_lua_call_status;
static int process_event_live_lua_pre_status;
static int process_event_live_lua_post_status;
static long long process_event_live_lua_result;
static int process_event_live_lua_is_number;
static int process_event_live_lua_object_handle_hits;
static int process_event_live_lua_function_handle_hits;
static int process_event_live_lua_params_handle_hits;
static HookDispatchSlot hook_dispatch_slots[MAX_HOOK_DISPATCH_CALLBACKS];
static ProcessEventDispatchSlot process_event_dispatch_slots[MAX_HOOK_DISPATCH_CALLBACKS];
static size_t hook_dispatch_slot_count;
static size_t process_event_dispatch_slot_count;
static int hook_self_test_last_original;
static int hook_self_test_last_pre_callbacks;
static int hook_self_test_last_post_callbacks;
static ModDispatchEntry mod_dispatch_entries[MAX_MOD_DISPATCH_ENTRIES];
static size_t mod_dispatch_entry_count;
static int mod_self_test_load_callbacks;
static int mod_self_test_unload_callbacks;
static LuaApi *active_lua_api;
static int lua_hook_registration_count;
static LuaHookRegistration lua_hook_registrations[MAX_LUA_HOOK_REGISTRATIONS];
static int lua_console_command_registration_count;
static LuaConsoleCommandRegistration lua_console_command_registrations[MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS];
static int lua_process_console_exec_pre_hook_registration_count;
static int lua_process_console_exec_post_hook_registration_count;
static LuaConsoleExecHookRegistration
  lua_process_console_exec_pre_hook_registrations[MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS];
static LuaConsoleExecHookRegistration
  lua_process_console_exec_post_hook_registrations[MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS];
static int lua_local_player_exec_pre_hook_registration_count;
static int lua_local_player_exec_post_hook_registration_count;
static LuaConsoleExecHookRegistration
  lua_local_player_exec_pre_hook_registrations[MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS];
static LuaConsoleExecHookRegistration
  lua_local_player_exec_post_hook_registrations[MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS];
static int lua_call_function_pre_hook_registration_count;
static int lua_call_function_post_hook_registration_count;
static LuaCallFunctionHookRegistration
  lua_call_function_pre_hook_registrations[MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS];
static LuaCallFunctionHookRegistration
  lua_call_function_post_hook_registrations[MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS];
static int lua_custom_event_registration_count;
static LuaCustomEventRegistration lua_custom_event_registrations[MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS];
static int lua_load_map_pre_hook_registration_count;
static int lua_load_map_post_hook_registration_count;
static LuaConsoleExecHookRegistration lua_load_map_pre_hook_registrations[MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS];
static LuaConsoleExecHookRegistration lua_load_map_post_hook_registrations[MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS];
static int lua_begin_play_pre_hook_registration_count;
static int lua_begin_play_post_hook_registration_count;
static LuaConsoleExecHookRegistration lua_begin_play_pre_hook_registrations[MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS];
static LuaConsoleExecHookRegistration lua_begin_play_post_hook_registrations[MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS];
static int lua_init_game_state_pre_hook_registration_count;
static int lua_init_game_state_post_hook_registration_count;
static LuaConsoleExecHookRegistration lua_init_game_state_pre_hook_registrations[MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS];
static LuaConsoleExecHookRegistration lua_init_game_state_post_hook_registrations[MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS];
static char lua_hook_registration_name[256];
static int lua_hook_pre_ref = LUA_NOREF_COMPAT;
static int lua_hook_post_ref = LUA_NOREF_COMPAT;
static int lua_hook_pre_calls;
static int lua_hook_post_calls;
static long long lua_hook_pre_result;
static long long lua_hook_post_result;
static int lua_hook_pre_is_number;
static int lua_hook_post_is_number;
static int lua_static_find_object_calls;
static int lua_static_find_object_hits;
static int lua_find_object_calls;
static int lua_find_object_hits;
static int lua_find_first_of_calls;
static int lua_find_first_of_hits;
static int lua_get_known_objects_calls;
static int lua_get_known_objects_hits;
static int lua_find_objects_calls;
static int lua_find_objects_hits;
static int lua_find_all_of_calls;
static int lua_find_all_of_hits;
static int lua_for_each_uobject_calls;
static int lua_for_each_uobject_callbacks;
static int lua_for_each_function_calls;
static int lua_for_each_function_callbacks;
static int lua_is_a_calls;
static int lua_is_a_hits;
static int lua_load_asset_calls;
static int lua_load_asset_hits;
static int lua_static_construct_object_calls;
static int lua_static_construct_object_hits;
static int lua_static_construct_object_outer_hits;
static int lua_get_world_calls;
static int lua_get_world_hits;
static int lua_get_cdo_calls;
static int lua_get_cdo_hits;
static int lua_get_level_calls;
static int lua_get_level_hits;
static int lua_notify_on_new_object_calls;
static int lua_notify_on_new_object_callbacks;
static long long lua_notify_on_new_object_result;
static int lua_notify_on_new_object_is_number;
static int lua_notify_on_new_object_status;
static int lua_notify_on_new_object_registration_count;
static int lua_execute_in_game_thread_calls;
static int lua_execute_in_game_thread_callbacks;
static long long lua_execute_in_game_thread_result;
static int lua_execute_in_game_thread_is_number;
static int lua_compat_registration_count;
static int lua_key_bind_registration_count;
static LuaSharedVariable lua_shared_variables[MAX_LUA_SHARED_VARIABLES];
static size_t lua_shared_variable_count;
static int lua_reflection_get_property_calls;
static int lua_reflection_get_property_hits;
static int lua_reflection_set_property_calls;
static int lua_reflection_set_property_hits;
static int lua_reflection_call_function_calls;
static int lua_reflection_call_function_hits;
static int lua_reflection_raw_property_hits;
static long long lua_reflection_raw_property_value;
static int lua_reflection_named_property_hits;
static int lua_reflection_raw_property_set_hits;
static long long lua_reflection_raw_property_set_value;
static int lua_reflection_array_inner_property_hits;
static int lua_reflection_enum_property_hits;
static int lua_reflection_enum_underlying_property_hits;
static int lua_reflection_set_element_property_hits;
static int lua_reflection_map_key_property_hits;
static int lua_reflection_map_value_property_hits;
static int lua_reflection_import_text_hits;
static int lua_reflection_export_text_hits;
static int lua_reflection_property_metadata_hits;
static int lua_reflection_descriptor_value_get_hits;
static int lua_reflection_descriptor_value_set_hits;
static int lua_process_event_param_get_calls;
static int lua_process_event_param_get_hits;
static int lua_process_event_param_set_calls;
static int lua_process_event_param_set_hits;
static int lua_process_event_param_descriptor_hits;
static int lua_process_event_param_descriptor_lookup_calls;
static int lua_process_event_param_descriptor_lookup_hits;
static int lua_process_event_function_param_descriptor_calls;
static int lua_process_event_function_param_descriptor_hits;
static uintptr_t active_process_event_lua_params_address;
static long long lua_reflection_probe_value;
static int lua_reflection_probe_bool_value;
static float lua_reflection_probe_float_value;
static double lua_reflection_probe_double_value;
static UeFNameValue lua_reflection_probe_name_value;
static char lua_reflection_probe_name_string[64];
static char lua_reflection_probe_string_value[64];
static char lua_reflection_probe_text_value[64];
static int32_t lua_reflection_probe_array_values[3];
static uint8_t lua_reflection_probe_enum_value;
static int32_t lua_reflection_probe_set_values[2];
static int32_t lua_reflection_probe_map_key_value;
static char lua_reflection_probe_map_value[64];
static uintptr_t lua_reflection_probe_object_address;
static LuaNotifyOnNewObjectRegistration
  lua_notify_on_new_object_registrations[MAX_LUA_NOTIFY_ON_NEW_OBJECT_REGISTRATIONS];
static LuaObjectHandle lua_object_handles[MAX_LUA_OBJECT_HANDLES];
static size_t lua_object_handle_count;
static LuaObjectHandle ue_candidate_object_handles[MAX_LUA_OBJECT_HANDLES];
static size_t ue_candidate_object_handle_count;
static LuaClassMetadata lua_class_metadata[MAX_LUA_CLASS_METADATA];
static size_t lua_class_metadata_count;
static UeReflectionPropertyCandidate ue_reflection_property_candidates[MAX_UE_REFLECTION_PROPERTY_CANDIDATES];
static size_t ue_reflection_property_candidate_count;
static UeFunctionParamDescriptor ue_function_param_descriptors[MAX_UE_FUNCTION_PARAM_DESCRIPTORS];
static size_t ue_function_param_descriptor_count;
static LuaApi *process_event_lua_api;
static LuaState *process_event_lua_state;
static int process_event_self_test_hook_calls;
static int process_event_self_test_original_calls;
static int process_event_live_probe_calls;
static int process_event_live_hook_last_pre_callbacks;
static int process_event_live_hook_last_post_callbacks;
static int process_event_self_test_pre_status;
static int process_event_self_test_post_status;
static uintptr_t process_event_self_test_last_object;
static uintptr_t process_event_self_test_last_function;
static uintptr_t process_event_self_test_last_params;
static int config_loaded;
static int config_file_found;
static char config_path[1024];
static ConfigEntry config_entries[MAX_CONFIG_ENTRIES];
static size_t config_entry_count;

static size_t cstr_len(const char *value) {
  size_t len = 0;
  if (!value) {
    return 0;
  }
  while (value[len]) {
    ++len;
  }
  return len;
}

static char ascii_lower(char ch) {
  if (ch >= 'A' && ch <= 'Z') {
    return (char)(ch - 'A' + 'a');
  }
  return ch;
}

static int str_equal(const char *a, const char *b) {
  size_t i = 0;
  while (a[i] && b[i]) {
    if (a[i] != b[i]) {
      return 0;
    }
    ++i;
  }
  return a[i] == b[i];
}

static long long parse_signed_decimal(const char *value, int *consumed) {
  long long sign = 1;
  long long result = 0;
  size_t i = 0;
  int digits = 0;
  if (consumed) {
    *consumed = 0;
  }
  if (!value) {
    return 0;
  }
  if (value[i] == '-') {
    sign = -1;
    ++i;
  } else if (value[i] == '+') {
    ++i;
  }
  while (value[i] >= '0' && value[i] <= '9') {
    result = result * 10 + (long long)(value[i] - '0');
    ++i;
    ++digits;
  }
  if (consumed) {
    *consumed = digits > 0 ? (int)i : 0;
  }
  return result * sign;
}

static double parse_simple_double(const char *value, int *consumed) {
  double sign = 1.0;
  double result = 0.0;
  double scale = 0.1;
  size_t i = 0;
  int digits = 0;
  if (consumed) {
    *consumed = 0;
  }
  if (!value) {
    return 0.0;
  }
  if (value[i] == '-') {
    sign = -1.0;
    ++i;
  } else if (value[i] == '+') {
    ++i;
  }
  while (value[i] >= '0' && value[i] <= '9') {
    result = result * 10.0 + (double)(value[i] - '0');
    ++i;
    ++digits;
  }
  if (value[i] == '.') {
    ++i;
    while (value[i] >= '0' && value[i] <= '9') {
      result += (double)(value[i] - '0') * scale;
      scale *= 0.1;
      ++i;
      ++digits;
    }
  }
  if (consumed) {
    *consumed = digits > 0 ? (int)i : 0;
  }
  return result * sign;
}

static int str_equal_ci(const char *a, const char *b) {
  size_t i = 0;
  while (a[i] && b[i]) {
    if (ascii_lower(a[i]) != ascii_lower(b[i])) {
      return 0;
    }
    ++i;
  }
  return a[i] == b[i];
}

static int contains_ci(const char *haystack, const char *needle) {
  size_t hay_len = cstr_len(haystack);
  size_t needle_len = cstr_len(needle);
  if (needle_len == 0 || hay_len < needle_len) {
    return 0;
  }
  for (size_t i = 0; i + needle_len <= hay_len; ++i) {
    size_t j = 0;
    while (j < needle_len && ascii_lower(haystack[i + j]) == ascii_lower(needle[j])) {
      ++j;
    }
    if (j == needle_len) {
      return 1;
    }
  }
  return 0;
}

static void copy_string(char *dst, size_t dst_size, const char *src) {
  if (dst_size == 0) {
    return;
  }
  size_t i = 0;
  while (src && src[i] && i + 1 < dst_size) {
    dst[i] = src[i];
    ++i;
  }
  dst[i] = '\0';
}

static void export_append_char_to_buffer(char *dst, size_t dst_size, size_t *len, char ch) {
  if (!dst || !len || *len + 1 >= dst_size) {
    return;
  }
  dst[(*len)++] = ch;
  dst[*len] = '\0';
}

static void export_append_unsigned_to_buffer(char *dst, size_t dst_size, size_t *len, unsigned long long value) {
  char digits[32];
  size_t count = 0;
  if (value == 0) {
    export_append_char_to_buffer(dst, dst_size, len, '0');
    return;
  }
  while (value > 0 && count < sizeof(digits)) {
    digits[count++] = (char)('0' + (value % 10ULL));
    value /= 10ULL;
  }
  while (count > 0) {
    export_append_char_to_buffer(dst, dst_size, len, digits[--count]);
  }
}

static void export_format_signed_dec(char *dst, size_t dst_size, long long value) {
  if (!dst || dst_size == 0) {
    return;
  }
  dst[0] = '\0';
  size_t len = 0;
  if (value < 0) {
    export_append_char_to_buffer(dst, dst_size, &len, '-');
    export_append_unsigned_to_buffer(dst, dst_size, &len, (unsigned long long)(-(value + 1)) + 1ULL);
    return;
  }
  export_append_unsigned_to_buffer(dst, dst_size, &len, (unsigned long long)value);
}

static void export_format_fixed3(char *dst, size_t dst_size, double value) {
  if (!dst || dst_size == 0) {
    return;
  }
  dst[0] = '\0';
  size_t len = 0;
  if (value < 0.0) {
    export_append_char_to_buffer(dst, dst_size, &len, '-');
    value = -value;
  }
  unsigned long long scaled = (unsigned long long)(value * 1000.0 + 0.5);
  unsigned long long whole = scaled / 1000ULL;
  unsigned fraction = (unsigned)(scaled % 1000ULL);
  export_append_unsigned_to_buffer(dst, dst_size, &len, whole);
  export_append_char_to_buffer(dst, dst_size, &len, '.');
  export_append_char_to_buffer(dst, dst_size, &len, (char)('0' + ((fraction / 100U) % 10U)));
  export_append_char_to_buffer(dst, dst_size, &len, (char)('0' + ((fraction / 10U) % 10U)));
  export_append_char_to_buffer(dst, dst_size, &len, (char)('0' + (fraction % 10U)));
}

static char *trim(char *value) {
  while (*value == ' ' || *value == '\t' || *value == '\r' || *value == '\n') {
    ++value;
  }
  size_t len = cstr_len(value);
  while (len > 0) {
    char ch = value[len - 1];
    if (ch != ' ' && ch != '\t' && ch != '\r' && ch != '\n') {
      break;
    }
    value[--len] = '\0';
  }
  return value;
}

static void lower_inplace(char *value) {
  for (size_t i = 0; value[i]; ++i) {
    value[i] = ascii_lower(value[i]);
  }
}

static void safe_value(const char *value, char *out, size_t out_size) {
  if (out_size == 0) {
    return;
  }
  size_t written = 0;
  for (size_t i = 0; value && value[i] && written + 1 < out_size; ++i) {
    unsigned char ch = (unsigned char)value[i];
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
        (ch >= '0' && ch <= '9') || ch == '_' || ch == '-' ||
        ch == '.' || ch == '/' || ch == '\\' || ch == ':' || ch == '+') {
      out[written++] = (char)ch;
    } else if (ch >= 32 && ch < 127) {
      out[written++] = '_';
    } else {
      out[written++] = '?';
    }
  }
  out[written] = '\0';
}

static void line_init(Line *line) {
  line->len = 0;
  line->text[0] = '\0';
}

static void line_append_char(Line *line, char ch) {
  if (line->len + 1 >= sizeof(line->text)) {
    return;
  }
  line->text[line->len++] = ch;
  line->text[line->len] = '\0';
}

static void line_append(Line *line, const char *value) {
  for (size_t i = 0; value && value[i]; ++i) {
    line_append_char(line, value[i]);
  }
}

static void line_append_dec(Line *line, unsigned long long value) {
  char digits[32];
  size_t count = 0;
  if (value == 0) {
    line_append_char(line, '0');
    return;
  }
  while (value > 0 && count < sizeof(digits)) {
    digits[count++] = (char)('0' + (value % 10ULL));
    value /= 10ULL;
  }
  while (count > 0) {
    line_append_char(line, digits[--count]);
  }
}

static void line_append_signed_dec(Line *line, long long value) {
  if (value < 0) {
    line_append_char(line, '-');
    line_append_dec(line, (unsigned long long)(-(value + 1)) + 1ULL);
    return;
  }
  line_append_dec(line, (unsigned long long)value);
}

static void line_append_fixed3(Line *line, double value) {
  if (value < 0.0) {
    line_append_char(line, '-');
    value = -value;
  }
  unsigned long long scaled = (unsigned long long)(value * 1000.0 + 0.5);
  unsigned long long whole = scaled / 1000ULL;
  unsigned fraction = (unsigned)(scaled % 1000ULL);
  line_append_dec(line, whole);
  line_append_char(line, '.');
  line_append_char(line, (char)('0' + ((fraction / 100U) % 10U)));
  line_append_char(line, (char)('0' + ((fraction / 10U) % 10U)));
  line_append_char(line, (char)('0' + (fraction % 10U)));
}

static void line_append_hex(Line *line, unsigned long long value) {
  static const char hex[] = "0123456789abcdef";
  char digits[32];
  size_t count = 0;
  line_append(line, "0x");
  if (value == 0) {
    line_append_char(line, '0');
    return;
  }
  while (value > 0 && count < sizeof(digits)) {
    digits[count++] = hex[value & 0xfULL];
    value >>= 4;
  }
  while (count > 0) {
    line_append_char(line, digits[--count]);
  }
}

static void append_two_digits(Line *line, unsigned value) {
  line_append_char(line, (char)('0' + ((value / 10U) % 10U)));
  line_append_char(line, (char)('0' + (value % 10U)));
}

static void append_four_digits(Line *line, unsigned value) {
  line_append_char(line, (char)('0' + ((value / 1000U) % 10U)));
  line_append_char(line, (char)('0' + ((value / 100U) % 10U)));
  line_append_char(line, (char)('0' + ((value / 10U) % 10U)));
  line_append_char(line, (char)('0' + (value % 10U)));
}

static int module_dir_path(char *out, size_t out_size, const char *leaf) {
  if (out_size == 0) {
    return 0;
  }
  static char module_path[1024];
  module_path[0] = '\0';
  if (GetModuleFileNameA(self_module, module_path, sizeof(module_path)) == 0) {
    out[0] = '\0';
    return 0;
  }
  size_t len = cstr_len(module_path);
  size_t cut = len;
  while (cut > 0 && module_path[cut - 1] != '\\' && module_path[cut - 1] != '/') {
    --cut;
  }
  size_t written = 0;
  while (written < cut && written + 1 < out_size) {
    out[written] = module_path[written];
    ++written;
  }
  for (size_t i = 0; leaf && leaf[i] && written + 1 < out_size; ++i) {
    out[written++] = leaf[i];
  }
  out[written] = '\0';
  return written > 0;
}

static int module_path_with_suffix(char *out, size_t out_size, const char *suffix) {
  if (out_size == 0) {
    return 0;
  }
  if (GetModuleFileNameA(self_module, out, (DWORD)out_size) == 0) {
    out[0] = '\0';
    return 0;
  }
  size_t written = cstr_len(out);
  for (size_t i = 0; suffix && suffix[i] && written + 1 < out_size; ++i) {
    out[written++] = suffix[i];
  }
  out[written] = '\0';
  return written > 0;
}

static int read_config_file(const char *path, char *buffer, size_t buffer_size, size_t *length) {
  if (buffer_size == 0) {
    return 0;
  }
  HANDLE file = CreateFileA(
    path,
    GENERIC_READ,
    FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
    0,
    OPEN_EXISTING,
    FILE_ATTRIBUTE_NORMAL,
    0
  );
  if (file == INVALID_HANDLE_VALUE) {
    return 0;
  }
  DWORD got = 0;
  BOOL ok = ReadFile(file, buffer, (DWORD)(buffer_size - 1), &got, 0);
  CloseHandle(file);
  if (!ok) {
    return 0;
  }
  buffer[got] = '\0';
  if (length) {
    *length = (size_t)got;
  }
  return 1;
}

static void config_add(const char *key, const char *value) {
  if (!key || !key[0] || config_entry_count >= MAX_CONFIG_ENTRIES) {
    return;
  }
  for (size_t i = 0; i < config_entry_count; ++i) {
    if (str_equal(config_entries[i].key, key)) {
      copy_string(config_entries[i].value, sizeof(config_entries[i].value), value);
      return;
    }
  }
  copy_string(config_entries[config_entry_count].key, sizeof(config_entries[config_entry_count].key), key);
  copy_string(config_entries[config_entry_count].value, sizeof(config_entries[config_entry_count].value), value);
  ++config_entry_count;
}

static void strip_matching_quotes(char **value) {
  char *raw = *value;
  size_t len = cstr_len(raw);
  if (len >= 2 &&
      ((raw[0] == '"' && raw[len - 1] == '"') || (raw[0] == '\'' && raw[len - 1] == '\''))) {
    raw[len - 1] = '\0';
    *value = raw + 1;
  }
}

static void parse_config_buffer(char *buffer) {
  char *line = buffer;
  while (line && *line) {
    char *next = line;
    while (*next && *next != '\n') {
      ++next;
    }
    if (*next) {
      *next = '\0';
      ++next;
    } else {
      next = 0;
    }

    char *item = trim(line);
    if (item[0] && item[0] != '#') {
      if (item[0] == 'e' && item[1] == 'x' && item[2] == 'p' && item[3] == 'o' &&
          item[4] == 'r' && item[5] == 't' && (item[6] == ' ' || item[6] == '\t')) {
        item = trim(item + 7);
      }
      char *separator = item;
      while (*separator && *separator != '=') {
        ++separator;
      }
      if (*separator == '=') {
        *separator = '\0';
        char *key = trim(item);
        char *value = trim(separator + 1);
        strip_matching_quotes(&value);
        config_add(key, value);
      }
    }
    line = next;
  }
}

static int load_config_path(const char *path) {
  static char buffer[MAX_CONFIG_BYTES];
  size_t length = 0;
  if (!read_config_file(path, buffer, sizeof(buffer), &length) || length == 0) {
    return 0;
  }
  config_file_found = 1;
  copy_string(config_path, sizeof(config_path), path);
  parse_config_buffer(buffer);
  return 1;
}

static void load_probe_config_once(void) {
  if (config_loaded) {
    return;
  }
  config_loaded = 1;

  static char path[1024];
  if (module_dir_path(path, sizeof(path), "ue4ssl-win.env") && load_config_path(path)) {
    return;
  }
  if (module_path_with_suffix(path, sizeof(path), ".env")) {
    load_config_path(path);
  }
}

static DWORD config_get(const char *name, char *buffer, size_t size) {
  load_probe_config_once();
  for (size_t i = 0; i < config_entry_count; ++i) {
    if (str_equal(config_entries[i].key, name)) {
      copy_string(buffer, size, config_entries[i].value);
      return (DWORD)cstr_len(config_entries[i].value);
    }
  }
  return 0;
}

static DWORD env_get(const char *name, char *buffer, size_t size) {
  if (size == 0) {
    return 0;
  }
  DWORD got = GetEnvironmentVariableA(name, buffer, (DWORD)size);
  if (got >= size) {
    buffer[size - 1] = '\0';
    return got;
  }
  if (got > 0) {
    return got;
  }
  return config_get(name, buffer, size);
}

static void default_log_path(char *buffer, size_t size) {
  if (env_get("UE4SSL_WIN_LOG", buffer, size) > 0) {
    return;
  }
  copy_string(buffer, size, "Z:\\tmp\\ue4ssl-win-loader.log");
}

static void emit_line(Line *line) {
  static char path[512];
  default_log_path(path, sizeof(path));

  HANDLE file = CreateFileA(
    path,
    FILE_APPEND_DATA,
    FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
    0,
    OPEN_ALWAYS,
    FILE_ATTRIBUTE_NORMAL,
    0
  );
  if (file == INVALID_HANDLE_VALUE) {
    return;
  }

  static Line prefix;
  line_init(&prefix);
  SYSTEMTIME_WIN st;
  GetSystemTime(&st);
  append_four_digits(&prefix, st.wYear);
  line_append_char(&prefix, '-');
  append_two_digits(&prefix, st.wMonth);
  line_append_char(&prefix, '-');
  append_two_digits(&prefix, st.wDay);
  line_append_char(&prefix, 'T');
  append_two_digits(&prefix, st.wHour);
  line_append_char(&prefix, ':');
  append_two_digits(&prefix, st.wMinute);
  line_append_char(&prefix, ':');
  append_two_digits(&prefix, st.wSecond);
  line_append(&prefix, "Z pid=");
  line_append_dec(&prefix, GetCurrentProcessId());
  line_append(&prefix, " loader=win-client ");

  DWORD written = 0;
  WriteFile(file, prefix.text, (DWORD)prefix.len, &written, 0);
  WriteFile(file, line->text, (DWORD)line->len, &written, 0);
  WriteFile(file, "\r\n", 2, &written, 0);
  CloseHandle(file);
}

static int parse_unsigned(const char *raw, int base, unsigned long long *out) {
  if (!raw || !raw[0]) {
    return 0;
  }
  if (base == 16 && raw[0] == '0' && (raw[1] == 'x' || raw[1] == 'X')) {
    raw += 2;
  }
  unsigned long long parsed = 0;
  for (size_t i = 0; raw[i]; ++i) {
    int digit = -1;
    if (raw[i] >= '0' && raw[i] <= '9') {
      digit = raw[i] - '0';
    } else if (base == 16 && raw[i] >= 'a' && raw[i] <= 'f') {
      digit = raw[i] - 'a' + 10;
    } else if (base == 16 && raw[i] >= 'A' && raw[i] <= 'F') {
      digit = raw[i] - 'A' + 10;
    }
    if (digit < 0 || digit >= base) {
      return 0;
    }
    parsed = parsed * (unsigned long long)base + (unsigned long long)digit;
  }
  *out = parsed;
  return 1;
}

static int parse_unsigned_auto(const char *raw, unsigned long long *out) {
  if (!raw || !raw[0]) {
    return 0;
  }
  int base = 10;
  if (raw[0] == '0' && (raw[1] == 'x' || raw[1] == 'X')) {
    base = 16;
  } else {
    for (size_t i = 0; raw[i]; ++i) {
      if ((raw[i] >= 'a' && raw[i] <= 'f') || (raw[i] >= 'A' && raw[i] <= 'F')) {
        base = 16;
        break;
      }
    }
  }
  return parse_unsigned(raw, base, out);
}

static int env_bool(const char *name, int default_value) {
  char raw[32];
  if (env_get(name, raw, sizeof(raw)) == 0 || raw[0] == '\0') {
    return default_value;
  }
  lower_inplace(raw);
  return str_equal(raw, "1") || str_equal(raw, "true") || str_equal(raw, "yes") || str_equal(raw, "on");
}

static size_t env_size(const char *name, size_t default_value) {
  char raw[64];
  unsigned long long parsed = 0;
  if (env_get(name, raw, sizeof(raw)) == 0 || !parse_unsigned(raw, 10, &parsed) || parsed == 0) {
    return default_value;
  }
  return (size_t)parsed;
}

static size_t env_size_auto(const char *name, size_t default_value) {
  char raw[64];
  unsigned long long parsed = 0;
  if (env_get(name, raw, sizeof(raw)) == 0 || !parse_unsigned_auto(raw, &parsed) || parsed == 0) {
    return default_value;
  }
  return (size_t)parsed;
}

static uintptr_t env_address_auto(const char *name, uintptr_t default_value) {
  char raw[64];
  unsigned long long parsed = 0;
  if (env_get(name, raw, sizeof(raw)) == 0 || !parse_unsigned_auto(raw, &parsed) || parsed == 0) {
    return default_value;
  }
  return (uintptr_t)parsed;
}

static int env_int(const char *name, int default_value) {
  char raw[64];
  unsigned long long parsed = 0;
  if (env_get(name, raw, sizeof(raw)) == 0 || !parse_unsigned(raw, 10, &parsed) || parsed > 3600ULL) {
    return default_value;
  }
  return (int)parsed;
}

static void add_needle(char needles[][MAX_NEEDLE_LEN], size_t *count, const char *needle) {
  if (!needle || !needle[0] || *count >= MAX_NEEDLES) {
    return;
  }
  for (size_t i = 0; i < *count; ++i) {
    if (str_equal(needles[i], needle)) {
      return;
    }
  }
  copy_string(needles[*count], MAX_NEEDLE_LEN, needle);
  ++(*count);
}

static void append_preset(const char *preset, char needles[][MAX_NEEDLE_LEN], size_t *count) {
  if (str_equal(preset, "core")) {
    const char *items[] = {"TargetGame", "TargetGame-Win64-Shipping", "/Script/TargetGame", "/Script/Engine", "EngineVersion"};
    for (size_t i = 0; i < sizeof(items) / sizeof(items[0]); ++i) add_needle(needles, count, items[i]);
  } else if (str_equal(preset, "ue") || str_equal(preset, "unreal")) {
    const char *items[] = {"GUObjectArray", "GObjectArray", "FNamePool", "GName", "GWorld", "ProcessEvent", "StaticFindObject", "UObject", "UFunction", "UClass", "FProperty"};
    for (size_t i = 0; i < sizeof(items) / sizeof(items[0]); ++i) add_needle(needles, count, items[i]);
  } else if (str_equal(preset, "client")) {
    const char *items[] = {"LocalPlayer", "PlayerController", "GameViewport", "ViewportClient", "ConsoleKey", "ConsoleKeys", "InputSettings", "ClientTravel", "ClientRestart"};
    for (size_t i = 0; i < sizeof(items) / sizeof(items[0]); ++i) add_needle(needles, count, items[i]);
  } else if (str_equal(preset, "cheat")) {
    const char *items[] = {"CheatManager", "CheatClass", "/Script/Engine.CheatManager", "EnableCheats", "AdminLogin", "ServerCheat", "ClientMessage"};
    for (size_t i = 0; i < sizeof(items) / sizeof(items[0]); ++i) add_needle(needles, count, items[i]);
  } else if (str_equal(preset, "brt")) {
    const char *items[] = {"m_BaseBackupToolMapRestriction", "ServerRequestBaseBackup", "BaseBackupActionPlace", "UGameItemBaseBackupToolActions", "PerformCanBePlaced", "Fail_InvalidMap", "BaseBackupTool"};
    for (size_t i = 0; i < sizeof(items) / sizeof(items[0]); ++i) add_needle(needles, count, items[i]);
  } else if (str_equal(preset, "deep-desert")) {
    const char *items[] = {"DeepDesert", "DeepDesert_1", "m_DeepDesertGameplay", "m_ShiftingSands", "m_PerMapSystemSettings", "m_SpiceFieldTypeSettings"};
    for (size_t i = 0; i < sizeof(items) / sizeof(items[0]); ++i) add_needle(needles, count, items[i]);
  }
}

static void parse_delimited_needles(char *raw, char delimiter, char needles[][MAX_NEEDLE_LEN], size_t *count, int presets) {
  char *start = raw;
  while (start && *start) {
    char *end = start;
    while (*end && *end != delimiter) {
      ++end;
    }
    int has_delimiter = *end == delimiter;
    if (*end) {
      *end = '\0';
    }
    char *item = trim(start);
    if (item[0]) {
      if (presets) {
        lower_inplace(item);
        append_preset(item, needles, count);
      } else {
        add_needle(needles, count, item);
      }
    }
    start = has_delimiter ? end + 1 : 0;
  }
}

static void collect_needles(char needles[][MAX_NEEDLE_LEN], size_t *count) {
  static char presets[2048];
  static char extras[4096];
  DWORD got_presets = env_get("UE4SSL_WIN_SCAN_PRESETS", presets, sizeof(presets));
  DWORD got_extras = env_get("UE4SSL_WIN_SCAN_STRINGS", extras, sizeof(extras));
  if (got_presets == 0 && got_extras == 0) {
    copy_string(presets, sizeof(presets), "core,ue,client,cheat,brt,deep-desert");
    got_presets = (DWORD)cstr_len(presets);
  }
  if (got_presets > 0) {
    parse_delimited_needles(presets, ',', needles, count, 1);
  }
  if (got_extras > 0) {
    parse_delimited_needles(extras, ';', needles, count, 0);
  }
}

static char *next_token(char **cursor) {
  char *p = *cursor;
  while (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n') {
    ++p;
  }
  if (!*p) {
    *cursor = p;
    return 0;
  }
  char *start = p;
  while (*p && *p != ' ' && *p != '\t' && *p != '\r' && *p != '\n') {
    ++p;
  }
  if (*p) {
    *p++ = '\0';
  }
  *cursor = p;
  return start;
}

static void parse_pattern_item(char *item, BytePattern *patterns, size_t *count) {
  if (*count >= MAX_PATTERNS) {
    return;
  }
  char *separator = item;
  while (*separator && *separator != '=' && *separator != ':') {
    ++separator;
  }
  if (!*separator) {
    return;
  }
  *separator = '\0';
  char *name = trim(item);
  char *body = trim(separator + 1);
  if (!name[0] || !body[0]) {
    return;
  }

  BytePattern *pattern = &patterns[*count];
  for (size_t i = 0; i < sizeof(*pattern); ++i) {
    ((char *)pattern)[i] = 0;
  }
  copy_string(pattern->name, sizeof(pattern->name), name);

  char *cursor = body;
  char *token = 0;
  while ((token = next_token(&cursor)) != 0) {
    if (pattern->length >= MAX_PATTERN_BYTES) {
      pattern->length = 0;
      return;
    }
    if (str_equal(token, "?") || str_equal(token, "??")) {
      pattern->bytes[pattern->length++] = -1;
      continue;
    }
    unsigned long long parsed = 0;
    if (!parse_unsigned(token, 16, &parsed) || parsed > 255ULL) {
      pattern->length = 0;
      return;
    }
    pattern->bytes[pattern->length++] = (int)parsed;
  }
  if (pattern->length > 0) {
    ++(*count);
  }
}

static void collect_patterns(BytePattern *patterns, size_t *count) {
  static char raw[4096];
  if (env_get("UE4SSL_WIN_SCAN_SIGNATURES", raw, sizeof(raw)) > 0) {
    char *start = raw;
    while (start && *start) {
      char *end = start;
      while (*end && *end != ';' && *end != '\n' && *end != '\r') {
        ++end;
      }
      int has_delimiter = *end != '\0';
      if (*end) {
        *end = '\0';
      }
      char *item = trim(start);
      if (item[0] && item[0] != '#') {
        parse_pattern_item(item, patterns, count);
      }
      start = has_delimiter ? end + 1 : 0;
      while (start && (*start == '\n' || *start == '\r')) {
        ++start;
      }
    }
  }

  static char path[2048];
  if (env_get("UE4SSL_WIN_SCAN_SIGNATURES_FILE", path, sizeof(path)) == 0) {
    return;
  }
  static char file_raw[MAX_SIGNATURE_FILE_BYTES + 1];
  size_t length = 0;
  static char safe_path[2048];
  safe_value(path, safe_path, sizeof(safe_path));
  if (!read_config_file(path, file_raw, sizeof(file_raw), &length)) {
    static Line line;
    line_init(&line);
    line_append(&line, "event=signature-file-skip reason=open-failed path=");
    line_append(&line, safe_path);
    emit_line(&line);
    return;
  }
  size_t before = *count;
  char *start = file_raw;
  while (start && *start) {
    char *end = start;
    while (*end && *end != ';' && *end != '\n' && *end != '\r') {
      ++end;
    }
    int has_delimiter = *end != '\0';
    if (*end) {
      *end = '\0';
    }
    char *item = trim(start);
    if (item[0] && item[0] != '#') {
      parse_pattern_item(item, patterns, count);
    }
    start = has_delimiter ? end + 1 : 0;
    while (start && (*start == '\n' || *start == '\r')) {
      ++start;
    }
  }
  static Line line;
  line_init(&line);
  line_append(&line, "event=signature-file path=");
  line_append(&line, safe_path);
  line_append(&line, " bytes=");
  line_append_dec(&line, length);
  line_append(&line, " patterns=");
  line_append_dec(&line, *count - before);
  emit_line(&line);
}

static const unsigned char *find_pattern(const unsigned char *begin, const unsigned char *end, const BytePattern *pattern);
static void parse_filters(char filters[][MAX_NEEDLE_LEN], size_t *count);
static int module_path_matches(const char *module_path, const char *exe_path, char filters[][MAX_NEEDLE_LEN], size_t filter_count);

static void parse_ue_anchor_item(char *item, UeAnchor *anchors, size_t *count) {
  if (*count >= MAX_UE_ANCHORS) {
    return;
  }
  char *separator = item;
  while (*separator && *separator != '=' && *separator != ':') {
    ++separator;
  }
  if (!*separator) {
    static char safe_item[256];
    safe_value(item, safe_item, sizeof(safe_item));
    static Line line;
    line_init(&line);
    line_append(&line, "event=ue-anchor-skip reason=missing-address item=");
    line_append(&line, safe_item);
    emit_line(&line);
    return;
  }
  *separator = '\0';
  char *name = trim(item);
  char *raw_address = trim(separator + 1);
  unsigned long long parsed = 0;
  if (!name[0] || !parse_unsigned(raw_address, 16, &parsed)) {
    static char safe_name[256];
    safe_value(name, safe_name, sizeof(safe_name));
    static Line line;
    line_init(&line);
    line_append(&line, "event=ue-anchor-skip reason=bad-address name=");
    line_append(&line, safe_name);
    emit_line(&line);
    return;
  }
  copy_string(anchors[*count].name, sizeof(anchors[*count].name), name);
  anchors[*count].address = (uintptr_t)parsed;
  ++(*count);
}

static void seed_self_test_fname_entry(uint32_t comparison_index, const char *name, uint32_t *cursor) {
  if (!name) {
    return;
  }
  size_t name_len = cstr_len(name);
  uint16_t header = (uint16_t)(name_len << 1);
  size_t entry_offset = (size_t)comparison_index * DEFAULT_UE_FNAME_STRIDE;
  size_t entry_end = entry_offset + sizeof(header) + name_len;
  if (entry_end + 1 >= sizeof(ue_self_test_fname_block)) {
    return;
  }
  ue_self_test_fname_block[entry_offset] = (unsigned char)(header & 0xffU);
  ue_self_test_fname_block[entry_offset + 1] = (unsigned char)((header >> 8) & 0xffU);
  for (size_t i = 0; i < name_len; ++i) {
    ue_self_test_fname_block[entry_offset + sizeof(header) + i] = (unsigned char)name[i];
  }
  if (cursor && entry_end > *cursor) {
    *cursor = (uint32_t)entry_end;
  }
}

static size_t collect_ue_anchors(UeAnchor *anchors) {
  static char raw[4096];
  size_t count = 0;
  if (env_get("UE4SSL_WIN_UE_ANCHORS", raw, sizeof(raw)) > 0) {
    char *start = raw;
    while (start && *start) {
      char *end = start;
      while (*end && *end != ';' && *end != '\n' && *end != '\r') {
        ++end;
      }
      int has_delimiter = *end != '\0';
      if (*end) {
        *end = '\0';
      }
      char *item = trim(start);
      if (item[0] && item[0] != '#') {
        parse_ue_anchor_item(item, anchors, &count);
      }
      start = has_delimiter ? end + 1 : 0;
      while (start && (*start == '\n' || *start == '\r')) {
        ++start;
      }
    }
  }
  if (env_bool("UE4SSL_WIN_UE_SELF_TEST_ANCHOR", 0) && count < MAX_UE_ANCHORS) {
    ue_self_test_target[0] = (uintptr_t)&ue_self_test_target[1];
    ue_self_test_target[1] = 0;
    ue_self_test_target[2] = (uintptr_t)&ue_self_test_anchor;
    ue_self_test_target[3] = 0;
    ue_self_test_anchor = (uintptr_t)&ue_self_test_target[0];
    copy_string(anchors[count].name, sizeof(anchors[count].name), "SelfTest");
    anchors[count].address = (uintptr_t)&ue_self_test_anchor;
    ++count;
    if (count < MAX_UE_ANCHORS) {
      unsigned char *pool_bytes = (unsigned char *)&ue_self_test_fname_pool;
      for (size_t i = 0; i < sizeof(ue_self_test_fname_pool); ++i) {
        pool_bytes[i] = 0;
      }
      for (size_t i = 0; i < sizeof(ue_self_test_fname_block); ++i) {
        ue_self_test_fname_block[i] = 0;
      }
      uint32_t fname_cursor = 0;
      seed_self_test_fname_entry(SELF_TEST_FNAME_INDEX, SELF_TEST_FNAME_VALUE, &fname_cursor);
      seed_self_test_fname_entry(SELF_TEST_FNAME_VALUE_PARAM_INDEX, "Value", &fname_cursor);
      seed_self_test_fname_entry(SELF_TEST_FNAME_ORIGINAL_RESULT_PARAM_INDEX, "OriginalResult", &fname_cursor);
      seed_self_test_fname_entry(SELF_TEST_FNAME_TOUCHED_PARAM_INDEX, "Touched", &fname_cursor);
      seed_self_test_fname_entry(SELF_TEST_FNAME_INT_PROPERTY_INDEX, "FIntProperty", &fname_cursor);
      seed_self_test_fname_entry(SELF_TEST_FNAME_NAME_TOKEN_PARAM_INDEX, "NameToken", &fname_cursor);
      seed_self_test_fname_entry(SELF_TEST_FNAME_MESSAGE_PARAM_INDEX, "Message", &fname_cursor);
      seed_self_test_fname_entry(SELF_TEST_FNAME_NAME_PROPERTY_INDEX, "FNameProperty", &fname_cursor);
      seed_self_test_fname_entry(SELF_TEST_FNAME_STR_PROPERTY_INDEX, "FStrProperty", &fname_cursor);
      seed_self_test_fname_entry(SELF_TEST_FNAME_LOCATION_PARAM_INDEX, "Location", &fname_cursor);
      seed_self_test_fname_entry(SELF_TEST_FNAME_STRUCT_PROPERTY_INDEX, "FStructProperty", &fname_cursor);
      ue_self_test_fname_pool.lock = 0;
      ue_self_test_fname_pool.current_block = 0;
      ue_self_test_fname_pool.current_byte_cursor = fname_cursor;
      ue_self_test_fname_pool.blocks[0] = (uintptr_t)&ue_self_test_fname_block[0];
      copy_string(anchors[count].name, sizeof(anchors[count].name), "SelfTestFNamePool");
      anchors[count].address = (uintptr_t)&ue_self_test_fname_pool;
      ++count;
    }
    if (count < MAX_UE_ANCHORS) {
      unsigned char *class_bytes = (unsigned char *)&ue_self_test_class;
      for (size_t i = 0; i < sizeof(ue_self_test_class); ++i) {
        class_bytes[i] = 0;
      }
      unsigned char *int_property_class_bytes = (unsigned char *)&ue_self_test_int_property_class;
      for (size_t i = 0; i < sizeof(ue_self_test_int_property_class); ++i) {
        int_property_class_bytes[i] = 0;
      }
      unsigned char *name_property_class_bytes = (unsigned char *)&ue_self_test_name_property_class;
      for (size_t i = 0; i < sizeof(ue_self_test_name_property_class); ++i) {
        name_property_class_bytes[i] = 0;
      }
      unsigned char *str_property_class_bytes = (unsigned char *)&ue_self_test_str_property_class;
      for (size_t i = 0; i < sizeof(ue_self_test_str_property_class); ++i) {
        str_property_class_bytes[i] = 0;
      }
      unsigned char *struct_property_class_bytes = (unsigned char *)&ue_self_test_struct_property_class;
      for (size_t i = 0; i < sizeof(ue_self_test_struct_property_class); ++i) {
        struct_property_class_bytes[i] = 0;
      }
      unsigned char *function_bytes = (unsigned char *)&ue_self_test_function;
      for (size_t i = 0; i < sizeof(ue_self_test_function); ++i) {
        function_bytes[i] = 0;
      }
      unsigned char *children_field_bytes = (unsigned char *)&ue_self_test_children_field;
      for (size_t i = 0; i < sizeof(ue_self_test_children_field); ++i) {
        children_field_bytes[i] = 0;
      }
      unsigned char *property_field_bytes = (unsigned char *)&ue_self_test_property_field;
      for (size_t i = 0; i < sizeof(ue_self_test_property_field); ++i) {
        property_field_bytes[i] = 0;
      }
      unsigned char *value_param_field_bytes = (unsigned char *)&ue_self_test_value_param_field;
      for (size_t i = 0; i < sizeof(ue_self_test_value_param_field); ++i) {
        value_param_field_bytes[i] = 0;
      }
      unsigned char *original_result_param_field_bytes = (unsigned char *)&ue_self_test_original_result_param_field;
      for (size_t i = 0; i < sizeof(ue_self_test_original_result_param_field); ++i) {
        original_result_param_field_bytes[i] = 0;
      }
      unsigned char *touched_param_field_bytes = (unsigned char *)&ue_self_test_touched_param_field;
      for (size_t i = 0; i < sizeof(ue_self_test_touched_param_field); ++i) {
        touched_param_field_bytes[i] = 0;
      }
      unsigned char *name_token_param_field_bytes = (unsigned char *)&ue_self_test_name_token_param_field;
      for (size_t i = 0; i < sizeof(ue_self_test_name_token_param_field); ++i) {
        name_token_param_field_bytes[i] = 0;
      }
      unsigned char *message_param_field_bytes = (unsigned char *)&ue_self_test_message_param_field;
      for (size_t i = 0; i < sizeof(ue_self_test_message_param_field); ++i) {
        message_param_field_bytes[i] = 0;
      }
      unsigned char *location_param_field_bytes = (unsigned char *)&ue_self_test_location_param_field;
      for (size_t i = 0; i < sizeof(ue_self_test_location_param_field); ++i) {
        location_param_field_bytes[i] = 0;
      }
      ue_self_test_class.object.vtable = (uintptr_t)&ue_self_test_target[1];
      ue_self_test_class.object.object_flags = 0x11;
      ue_self_test_class.object.internal_index = 8;
      ue_self_test_class.object.class_private = (uintptr_t)&ue_self_test_class;
      ue_self_test_class.object.name_comparison_index = SELF_TEST_FNAME_INDEX;
      ue_self_test_class.object.name_number = 1;
      ue_self_test_class.object.outer_private = 0;
      ue_self_test_class.children = (uintptr_t)&ue_self_test_children_field;
      ue_self_test_class.super_struct = (uintptr_t)&ue_self_test_int_property_class;
      ue_self_test_class.child_properties = (uintptr_t)&ue_self_test_property_field;
      ue_self_test_class.property_link = (uintptr_t)&ue_self_test_property_field;
      ue_self_test_class.function_link = (uintptr_t)&ue_self_test_function;
      ue_self_test_int_property_class.object.vtable = (uintptr_t)&ue_self_test_target[1];
      ue_self_test_int_property_class.object.object_flags = 0x11;
      ue_self_test_int_property_class.object.internal_index = 15;
      ue_self_test_int_property_class.object.class_private = (uintptr_t)&ue_self_test_class;
      ue_self_test_int_property_class.object.name_comparison_index = SELF_TEST_FNAME_INT_PROPERTY_INDEX;
      ue_self_test_int_property_class.object.name_number = 0;
      ue_self_test_name_property_class.object = ue_self_test_int_property_class.object;
      ue_self_test_name_property_class.object.internal_index = 16;
      ue_self_test_name_property_class.object.name_comparison_index = SELF_TEST_FNAME_NAME_PROPERTY_INDEX;
      ue_self_test_str_property_class.object = ue_self_test_int_property_class.object;
      ue_self_test_str_property_class.object.internal_index = 17;
      ue_self_test_str_property_class.object.name_comparison_index = SELF_TEST_FNAME_STR_PROPERTY_INDEX;
      ue_self_test_struct_property_class.object = ue_self_test_int_property_class.object;
      ue_self_test_struct_property_class.object.internal_index = 18;
      ue_self_test_struct_property_class.object.name_comparison_index = SELF_TEST_FNAME_STRUCT_PROPERTY_INDEX;
      ue_self_test_children_field.object.vtable = (uintptr_t)&ue_self_test_target[1];
      ue_self_test_children_field.object.object_flags = 0x11;
      ue_self_test_children_field.object.internal_index = 9;
      ue_self_test_children_field.object.class_private = (uintptr_t)&ue_self_test_class;
      ue_self_test_children_field.object.name_comparison_index = SELF_TEST_FNAME_INDEX;
      ue_self_test_children_field.object.name_number = 1;
      ue_self_test_property_field.object = ue_self_test_children_field.object;
      ue_self_test_property_field.object.internal_index = 10;
      ue_self_test_property_field.object.class_private = (uintptr_t)&ue_self_test_int_property_class;
      ue_self_test_property_field.array_dim = 1;
      ue_self_test_property_field.element_size = 4;
      ue_self_test_property_field.property_flags = 0x1ULL;
      ue_self_test_property_field.offset_internal = 12;
      ue_self_test_function.object = ue_self_test_children_field.object;
      ue_self_test_function.object.internal_index = 11;
      ue_self_test_function.child_properties = (uintptr_t)&ue_self_test_value_param_field;
      ue_self_test_function.property_link = (uintptr_t)&ue_self_test_value_param_field;
      ue_self_test_function.function_flags = 0x400;
      ue_self_test_value_param_field.object = ue_self_test_children_field.object;
      ue_self_test_value_param_field.object.internal_index = 12;
      ue_self_test_value_param_field.object.class_private = (uintptr_t)&ue_self_test_int_property_class;
      ue_self_test_value_param_field.object.name_comparison_index = SELF_TEST_FNAME_VALUE_PARAM_INDEX;
      ue_self_test_value_param_field.object.name_number = 0;
      ue_self_test_value_param_field.next = (uintptr_t)&ue_self_test_original_result_param_field;
      ue_self_test_value_param_field.array_dim = 1;
      ue_self_test_value_param_field.element_size = 4;
      ue_self_test_value_param_field.property_flags = 0x80ULL;
      ue_self_test_value_param_field.offset_internal = (int32_t)offsetof(ProcessEventSelfTestParams, value);
      ue_self_test_original_result_param_field.object = ue_self_test_children_field.object;
      ue_self_test_original_result_param_field.object.internal_index = 13;
      ue_self_test_original_result_param_field.object.class_private = (uintptr_t)&ue_self_test_int_property_class;
      ue_self_test_original_result_param_field.object.name_comparison_index = SELF_TEST_FNAME_ORIGINAL_RESULT_PARAM_INDEX;
      ue_self_test_original_result_param_field.object.name_number = 0;
      ue_self_test_original_result_param_field.next = (uintptr_t)&ue_self_test_touched_param_field;
      ue_self_test_original_result_param_field.array_dim = 1;
      ue_self_test_original_result_param_field.element_size = 4;
      ue_self_test_original_result_param_field.property_flags = 0x80ULL;
      ue_self_test_original_result_param_field.offset_internal = (int32_t)offsetof(ProcessEventSelfTestParams, original_result);
      ue_self_test_touched_param_field.object = ue_self_test_children_field.object;
      ue_self_test_touched_param_field.object.internal_index = 14;
      ue_self_test_touched_param_field.object.class_private = (uintptr_t)&ue_self_test_int_property_class;
      ue_self_test_touched_param_field.object.name_comparison_index = SELF_TEST_FNAME_TOUCHED_PARAM_INDEX;
      ue_self_test_touched_param_field.object.name_number = 0;
      ue_self_test_touched_param_field.next = (uintptr_t)&ue_self_test_name_token_param_field;
      ue_self_test_touched_param_field.array_dim = 1;
      ue_self_test_touched_param_field.element_size = 4;
      ue_self_test_touched_param_field.property_flags = 0x80ULL;
      ue_self_test_touched_param_field.offset_internal = (int32_t)offsetof(ProcessEventSelfTestParams, touched);
      ue_self_test_name_token_param_field.object = ue_self_test_children_field.object;
      ue_self_test_name_token_param_field.object.internal_index = 19;
      ue_self_test_name_token_param_field.object.class_private = (uintptr_t)&ue_self_test_name_property_class;
      ue_self_test_name_token_param_field.object.name_comparison_index = SELF_TEST_FNAME_NAME_TOKEN_PARAM_INDEX;
      ue_self_test_name_token_param_field.object.name_number = 0;
      ue_self_test_name_token_param_field.next = (uintptr_t)&ue_self_test_message_param_field;
      ue_self_test_name_token_param_field.array_dim = 1;
      ue_self_test_name_token_param_field.element_size = (int32_t)sizeof(UeFNameValue);
      ue_self_test_name_token_param_field.property_flags = 0x80ULL;
      ue_self_test_name_token_param_field.offset_internal = (int32_t)offsetof(ProcessEventSelfTestParams, name_token);
      ue_self_test_message_param_field.object = ue_self_test_children_field.object;
      ue_self_test_message_param_field.object.internal_index = 20;
      ue_self_test_message_param_field.object.class_private = (uintptr_t)&ue_self_test_str_property_class;
      ue_self_test_message_param_field.object.name_comparison_index = SELF_TEST_FNAME_MESSAGE_PARAM_INDEX;
      ue_self_test_message_param_field.object.name_number = 0;
      ue_self_test_message_param_field.next = (uintptr_t)&ue_self_test_location_param_field;
      ue_self_test_message_param_field.array_dim = 1;
      ue_self_test_message_param_field.element_size = (int32_t)sizeof(UeFStringValue);
      ue_self_test_message_param_field.property_flags = 0x80ULL;
      ue_self_test_message_param_field.offset_internal = (int32_t)offsetof(ProcessEventSelfTestParams, message);
      ue_self_test_location_param_field.object = ue_self_test_children_field.object;
      ue_self_test_location_param_field.object.internal_index = 21;
      ue_self_test_location_param_field.object.class_private = (uintptr_t)&ue_self_test_struct_property_class;
      ue_self_test_location_param_field.object.name_comparison_index = SELF_TEST_FNAME_LOCATION_PARAM_INDEX;
      ue_self_test_location_param_field.object.name_number = 0;
      ue_self_test_location_param_field.array_dim = 1;
      ue_self_test_location_param_field.element_size = (int32_t)sizeof(UeFVectorValue);
      ue_self_test_location_param_field.property_flags = 0x80ULL;
      ue_self_test_location_param_field.offset_internal = (int32_t)offsetof(ProcessEventSelfTestParams, location);
      ue_self_test_object.vtable = (uintptr_t)&ue_self_test_target[1];
      ue_self_test_object.object_flags = 0x11;
      ue_self_test_object.internal_index = 7;
      ue_self_test_object.class_private = (uintptr_t)&ue_self_test_class;
      ue_self_test_object.name_comparison_index = SELF_TEST_FNAME_INDEX;
      ue_self_test_object.name_number = 1;
      ue_self_test_object.outer_private = 0;
      ue_self_test_uobject_anchor = (uintptr_t)&ue_self_test_object;
      copy_string(anchors[count].name, sizeof(anchors[count].name), "SelfTestUObject");
      anchors[count].address = (uintptr_t)&ue_self_test_uobject_anchor;
      ++count;
    }
    if (count < MAX_UE_ANCHORS) {
      for (size_t i = 0; i < sizeof(ue_self_test_object_items); ++i) {
        ue_self_test_object_items[i] = 0;
      }
      for (size_t i = 0; i < sizeof(ue_self_test_uobject_anchor); ++i) {
        ue_self_test_object_items[i] = ((const unsigned char *)&ue_self_test_uobject_anchor)[i];
      }
      uint32_t self_test_internal_flags = UE_INTERNAL_OBJECT_FLAG_NATIVE;
      for (size_t i = 0; i < sizeof(self_test_internal_flags); ++i) {
        ue_self_test_object_items[sizeof(uintptr_t) + i] = ((const unsigned char *)&self_test_internal_flags)[i];
      }
      ue_self_test_object_chunks[0] = (uintptr_t)&ue_self_test_object_items[0];
      ue_self_test_object_array.chunks = (uintptr_t)&ue_self_test_object_chunks[0];
      ue_self_test_object_array.preallocated = 0;
      ue_self_test_object_array.max_elements = 2;
      ue_self_test_object_array.num_elements = 1;
      ue_self_test_object_array.max_chunks = 1;
      ue_self_test_object_array.num_chunks = 1;
      ue_self_test_object_array_anchor = (uintptr_t)&ue_self_test_object_array;
      copy_string(anchors[count].name, sizeof(anchors[count].name), "SelfTestObjectArray");
      anchors[count].address = (uintptr_t)&ue_self_test_object_array_anchor;
      ++count;
    }
  }
  return count;
}

static int writable_protect(DWORD protect) {
  DWORD base = protect & 0xffUL;
  return base == PAGE_READWRITE ||
         base == PAGE_WRITECOPY ||
         base == PAGE_EXECUTE_READWRITE ||
         base == PAGE_EXECUTE_WRITECOPY;
}

static int executable_protect(DWORD protect) {
  DWORD base = protect & 0xffUL;
  return base == PAGE_EXECUTE ||
         base == PAGE_EXECUTE_READ ||
         base == PAGE_EXECUTE_READWRITE ||
         base == PAGE_EXECUTE_WRITECOPY;
}

static int readable_protect(DWORD protect);

static int region_contains_range(const MEMORY_BASIC_INFORMATION_WIN64 *mbi, uintptr_t address, size_t size) {
  uintptr_t start = (uintptr_t)mbi->BaseAddress;
  uintptr_t end = start + (uintptr_t)mbi->RegionSize;
  return start <= address && address <= end && size <= end - address;
}

static int read_pointer_at(const MEMORY_BASIC_INFORMATION_WIN64 *mbi, uintptr_t address, uintptr_t *value) {
  if (!region_contains_range(mbi, address, sizeof(uintptr_t)) || !readable_protect(mbi->Protect)) {
    return 0;
  }
  uintptr_t read_value = 0;
  const unsigned char *source = (const unsigned char *)address;
  unsigned char *dest = (unsigned char *)&read_value;
  for (size_t i = 0; i < sizeof(read_value); ++i) {
    dest[i] = source[i];
  }
  *value = read_value;
  return 1;
}

static int read_u32_at(const MEMORY_BASIC_INFORMATION_WIN64 *mbi, uintptr_t address, uint32_t *value) {
  if (!region_contains_range(mbi, address, sizeof(uint32_t)) || !readable_protect(mbi->Protect)) {
    return 0;
  }
  uint32_t read_value = 0;
  const unsigned char *source = (const unsigned char *)address;
  unsigned char *dest = (unsigned char *)&read_value;
  for (size_t i = 0; i < sizeof(read_value); ++i) {
    dest[i] = source[i];
  }
  *value = read_value;
  return 1;
}

static int read_u64_at(const MEMORY_BASIC_INFORMATION_WIN64 *mbi, uintptr_t address, uint64_t *value) {
  if (!region_contains_range(mbi, address, sizeof(uint64_t)) || !readable_protect(mbi->Protect)) {
    return 0;
  }
  uint64_t read_value = 0;
  const unsigned char *source = (const unsigned char *)address;
  unsigned char *dest = (unsigned char *)&read_value;
  for (size_t i = 0; i < sizeof(read_value); ++i) {
    dest[i] = source[i];
  }
  *value = read_value;
  return 1;
}

static int ue_anchor_signatures_configured(void) {
  static char raw[8];
  if (env_get("UE4SSL_WIN_UE_ANCHOR_SIGNATURES", raw, sizeof(raw)) > 0) {
    return 1;
  }
  if (env_get("UE4SSL_WIN_UE_ANCHOR_SIGNATURES_FILE", raw, sizeof(raw)) > 0) {
    return 1;
  }
  return 0;
}

static void parse_ue_anchor_signature_buffer(char *raw, BytePattern *patterns, size_t *count) {
  char *start = raw;
  while (start && *start) {
    char *end = start;
    while (*end && *end != ';' && *end != '\n' && *end != '\r') {
      ++end;
    }
    int has_delimiter = *end != '\0';
    if (*end) {
      *end = '\0';
    }
    char *item = trim(start);
    if (item[0] && item[0] != '#') {
      parse_pattern_item(item, patterns, count);
    }
    start = has_delimiter ? end + 1 : 0;
    while (start && (*start == '\n' || *start == '\r')) {
      ++start;
    }
  }
}

static void collect_ue_anchor_signature_patterns(BytePattern *patterns, size_t *count) {
  static char raw[4096];
  if (env_get("UE4SSL_WIN_UE_ANCHOR_SIGNATURES", raw, sizeof(raw)) > 0) {
    parse_ue_anchor_signature_buffer(raw, patterns, count);
  }

  static char path[2048];
  if (env_get("UE4SSL_WIN_UE_ANCHOR_SIGNATURES_FILE", path, sizeof(path)) == 0) {
    return;
  }
  static char file_raw[MAX_SIGNATURE_FILE_BYTES + 1];
  size_t length = 0;
  static char safe_path[2048];
  safe_value(path, safe_path, sizeof(safe_path));
  if (!read_config_file(path, file_raw, sizeof(file_raw), &length)) {
    static Line line;
    line_init(&line);
    line_append(&line, "event=ue-anchor-signature-file-skip reason=open-failed path=");
    line_append(&line, safe_path);
    emit_line(&line);
    return;
  }
  size_t before = *count;
  parse_ue_anchor_signature_buffer(file_raw, patterns, count);
  static Line line;
  line_init(&line);
  line_append(&line, "event=ue-anchor-signature-file path=");
  line_append(&line, safe_path);
  line_append(&line, " bytes=");
  line_append_dec(&line, length);
  line_append(&line, " signatures=");
  line_append_dec(&line, *count - before);
  emit_line(&line);
}

static int ue_anchor_name_exists(const UeAnchor *anchors, size_t count, const char *name) {
  for (size_t i = 0; i < count; ++i) {
    if (str_equal(anchors[i].name, name)) {
      return 1;
    }
  }
  return 0;
}

typedef enum {
  UE_ANCHOR_SIGNATURE_HIT = 0,
  UE_ANCHOR_SIGNATURE_RIPREL32 = 1,
  UE_ANCHOR_SIGNATURE_PTR = 2,
} UeAnchorSignatureMode;

typedef struct {
  char anchor_name[MAX_UE_ANCHOR_NAME];
  char transform[128];
  UeAnchorSignatureMode mode;
  size_t offset;
} UeAnchorSignatureSpec;

static int parse_ue_anchor_signature_spec(const char *raw_name, UeAnchorSignatureSpec *spec) {
  unsigned char *bytes = (unsigned char *)spec;
  for (size_t i = 0; i < sizeof(*spec); ++i) {
    bytes[i] = 0;
  }
  spec->mode = UE_ANCHOR_SIGNATURE_HIT;
  copy_string(spec->transform, sizeof(spec->transform), "hit");

  const char *at = 0;
  size_t name_len = 0;
  while (raw_name && raw_name[name_len]) {
    if (raw_name[name_len] == '@') {
      at = raw_name + name_len;
      break;
    }
    ++name_len;
  }
  if (name_len == 0 || name_len >= sizeof(spec->anchor_name)) {
    return 0;
  }
  for (size_t i = 0; i < name_len; ++i) {
    spec->anchor_name[i] = raw_name[i];
  }
  spec->anchor_name[name_len] = '\0';
  if (!at) {
    return 1;
  }

  char transform[64];
  char original_transform[64];
  for (size_t i = 0; i < sizeof(transform); ++i) {
    transform[i] = 0;
    original_transform[i] = 0;
  }
  copy_string(transform, sizeof(transform), at + 1);
  copy_string(original_transform, sizeof(original_transform), at + 1);
  char *plus = 0;
  for (size_t i = 0; transform[i]; ++i) {
    if (transform[i] == '+') {
      plus = &transform[i];
      break;
    }
  }
  int explicit_offset = plus != 0;
  if (plus) {
    *plus = '\0';
    unsigned long long parsed = 0;
    if (!parse_unsigned_auto(plus + 1, &parsed) || parsed > 4096ULL) {
      return 0;
    }
    spec->offset = (size_t)parsed;
  }

  if (str_equal(transform, "hit")) {
    spec->mode = UE_ANCHOR_SIGNATURE_HIT;
  } else if (str_equal(transform, "riprel32")) {
    spec->mode = UE_ANCHOR_SIGNATURE_RIPREL32;
    if (!explicit_offset) {
      spec->offset = 3;
    }
  } else if (str_equal(transform, "callrel32")) {
    spec->mode = UE_ANCHOR_SIGNATURE_RIPREL32;
    if (!explicit_offset) {
      spec->offset = 1;
    }
  } else if (str_equal(transform, "ptr")) {
    spec->mode = UE_ANCHOR_SIGNATURE_PTR;
  } else {
    return 0;
  }
  copy_string(spec->transform, sizeof(spec->transform), original_transform);
  return 1;
}

static int resolve_ue_anchor_signature_hit(
  const MEMORY_BASIC_INFORMATION_WIN64 *mbi,
  uintptr_t hit,
  const UeAnchorSignatureSpec *spec,
  uintptr_t *address
) {
  uintptr_t operand = hit + spec->offset;
  if (spec->mode == UE_ANCHOR_SIGNATURE_HIT) {
    if (!region_contains_range(mbi, operand, 1)) {
      return 0;
    }
    *address = operand;
    return 1;
  }
  if (spec->mode == UE_ANCHOR_SIGNATURE_RIPREL32) {
    if (!region_contains_range(mbi, operand, sizeof(int32_t))) {
      return 0;
    }
    int32_t displacement = 0;
    const unsigned char *source = (const unsigned char *)operand;
    unsigned char *dest = (unsigned char *)&displacement;
    for (size_t i = 0; i < sizeof(displacement); ++i) {
      dest[i] = source[i];
    }
    *address = (uintptr_t)((intptr_t)(operand + sizeof(displacement)) + (intptr_t)displacement);
    return 1;
  }
  if (spec->mode == UE_ANCHOR_SIGNATURE_PTR) {
    if (!region_contains_range(mbi, operand, sizeof(uintptr_t))) {
      return 0;
    }
    uintptr_t value = 0;
    const unsigned char *source = (const unsigned char *)operand;
    unsigned char *dest = (unsigned char *)&value;
    for (size_t i = 0; i < sizeof(value); ++i) {
      dest[i] = source[i];
    }
    *address = value;
    return value != 0;
  }
  return 0;
}

static void log_ue_anchor_signature_line(
  const char *name,
  const char *status,
  uintptr_t hit,
  uintptr_t address,
  const char *transform,
  uintptr_t allocation_base,
  uintptr_t region_base,
  DWORD protect,
  DWORD type,
  const char *module_path
) {
  static char safe_name[256];
  static char safe_module[1024];
  safe_value(name, safe_name, sizeof(safe_name));
  safe_value(module_path, safe_module, sizeof(safe_module));
  static Line line;
  line_init(&line);
  line_append(&line, "event=ue-anchor-signature name=");
  line_append(&line, safe_name);
  line_append(&line, " status=");
  line_append(&line, status);
  if (address) {
    if (hit) {
      line_append(&line, " hit=");
      line_append_hex(&line, hit);
    }
    line_append(&line, " addr=");
    line_append_hex(&line, address);
    if (transform && transform[0]) {
      line_append(&line, " transform=");
      line_append(&line, transform);
    }
    line_append(&line, " rva=");
    line_append_hex(&line, allocation_base ? address - allocation_base : 0);
    line_append(&line, " allocationBase=");
    line_append_hex(&line, allocation_base);
    line_append(&line, " regionBase=");
    line_append_hex(&line, region_base);
    line_append(&line, " protect=");
    line_append_hex(&line, protect);
    line_append(&line, " type=");
    line_append_hex(&line, type);
    line_append(&line, " module=");
    line_append(&line, safe_module);
  }
  emit_line(&line);
}

static size_t collect_ue_anchor_signature_anchors(UeAnchor *anchors, size_t anchor_count, const char *phase) {
  static BytePattern patterns[MAX_PATTERNS];
  static char filters[MAX_FILTERS][MAX_NEEDLE_LEN];
  for (size_t i = 0; i < sizeof(patterns); ++i) {
    ((char *)patterns)[i] = 0;
  }
  for (size_t i = 0; i < sizeof(filters); ++i) {
    ((char *)filters)[i] = 0;
  }

  size_t pattern_count = 0;
  size_t filter_count = 0;
  collect_ue_anchor_signature_patterns(patterns, &pattern_count);
  parse_filters(filters, &filter_count);

  size_t max_region_bytes = env_size("UE4SSL_WIN_SCAN_MAX_REGION_BYTES", DEFAULT_MAX_REGION_BYTES);
  int scan_private = env_bool("UE4SSL_WIN_SCAN_PRIVATE", 0);
  static Line line;
  line_init(&line);
  line_append(&line, "event=ue-anchor-signature-start phase=");
  line_append(&line, phase);
  line_append(&line, " signatures=");
  line_append_dec(&line, pattern_count);
  line_append(&line, " filters=");
  line_append_dec(&line, filter_count);
  line_append(&line, " maxRegionBytes=");
  line_append_dec(&line, max_region_bytes);
  emit_line(&line);

  static char exe_path[1024];
  GetModuleFileNameA(0, exe_path, sizeof(exe_path));
  SYSTEM_INFO_WIN system_info;
  GetNativeSystemInfo(&system_info);
  size_t resolved = 0;

  for (size_t p = 0; p < pattern_count; ++p) {
    UeAnchorSignatureSpec spec;
    if (!parse_ue_anchor_signature_spec(patterns[p].name, &spec)) {
      log_ue_anchor_signature_line(patterns[p].name, "bad-transform", 0, 0, "", 0, 0, 0, 0, "");
      continue;
    }
    static char safe_name[256];
    safe_value(spec.anchor_name, safe_name, sizeof(safe_name));
    if (ue_anchor_name_exists(anchors, anchor_count, spec.anchor_name)) {
      log_ue_anchor_signature_line(spec.anchor_name, "duplicate", 0, 0, "", 0, 0, 0, 0, "");
      continue;
    }

    size_t hits = 0;
    size_t unresolved_hits = 0;
    size_t oversized_regions = 0;
    uintptr_t first_hit = 0;
    uintptr_t first_address = 0;
    uintptr_t first_allocation_base = 0;
    uintptr_t first_region_base = 0;
    DWORD first_protect = 0;
    DWORD first_type = 0;
    static char first_module_path[1024];
    first_module_path[0] = '\0';

    uintptr_t cursor = (uintptr_t)system_info.lpMinimumApplicationAddress;
    uintptr_t max_address = (uintptr_t)system_info.lpMaximumApplicationAddress;
    while (cursor < max_address && hits < 2) {
      MEMORY_BASIC_INFORMATION_WIN64 mbi;
      SIZE_T got = VirtualQuery((const void *)cursor, &mbi, sizeof(mbi));
      if (got == 0) {
        cursor += 0x10000ULL;
        continue;
      }

      uintptr_t region_base = (uintptr_t)mbi.BaseAddress;
      uintptr_t allocation_base = (uintptr_t)mbi.AllocationBase;
      uintptr_t next = region_base + (uintptr_t)mbi.RegionSize;
      if (next <= cursor) {
        break;
      }
      cursor = next;

      if (allocation_base == (uintptr_t)self_module ||
          mbi.State != MEM_COMMIT ||
          !readable_protect(mbi.Protect) ||
          mbi.RegionSize == 0 ||
          (mbi.Type != MEM_IMAGE && !(scan_private && mbi.Type == MEM_PRIVATE))) {
        continue;
      }
      if (mbi.RegionSize > max_region_bytes) {
        ++oversized_regions;
        continue;
      }

      static char module_path[1024];
      module_path[0] = '\0';
      GetModuleFileNameA((HMODULE)allocation_base, module_path, sizeof(module_path));
      if (!module_path_matches(module_path, exe_path, filters, filter_count)) {
        continue;
      }

      const unsigned char *scan = (const unsigned char *)region_base;
      const unsigned char *end = scan + mbi.RegionSize;
      while (hits < 2) {
        const unsigned char *hit = find_pattern(scan, end, &patterns[p]);
        if (!hit) {
          break;
        }
        uintptr_t resolved_address = 0;
        if (resolve_ue_anchor_signature_hit(&mbi, (uintptr_t)hit, &spec, &resolved_address)) {
          ++hits;
          if (hits == 1) {
            first_hit = (uintptr_t)hit;
            first_address = resolved_address;
            first_allocation_base = allocation_base;
            first_region_base = region_base;
            first_protect = mbi.Protect;
            first_type = mbi.Type;
            copy_string(first_module_path, sizeof(first_module_path), module_path);
          }
        } else {
          ++unresolved_hits;
        }
        scan = hit + 1;
      }
    }

    if (hits == 0) {
      line_init(&line);
      line_append(&line, "event=ue-anchor-signature name=");
      line_append(&line, safe_name);
      line_append(&line, " status=missing oversizedRegions=");
      line_append_dec(&line, oversized_regions);
      emit_line(&line);
      if (unresolved_hits > 0) {
        line_init(&line);
        line_append(&line, "event=ue-anchor-signature name=");
        line_append(&line, safe_name);
        line_append(&line, " status=unresolved hits=");
        line_append_dec(&line, unresolved_hits);
        line_append(&line, " transform=");
        line_append(&line, spec.transform);
        emit_line(&line);
      }
      continue;
    }
    if (hits > 1) {
      line_init(&line);
      line_append(&line, "event=ue-anchor-signature name=");
      line_append(&line, safe_name);
      line_append(&line, " status=ambiguous hits=");
      line_append_dec(&line, hits);
      line_append(&line, " firstAddr=");
      line_append_hex(&line, first_address);
      line_append(&line, " firstHit=");
      line_append_hex(&line, first_hit);
      line_append(&line, " transform=");
      line_append(&line, spec.transform);
      emit_line(&line);
      continue;
    }
    if (anchor_count >= MAX_UE_ANCHORS) {
      log_ue_anchor_signature_line(spec.anchor_name, "capacity-exhausted", first_hit, first_address, spec.transform, first_allocation_base, first_region_base, first_protect, first_type, first_module_path);
      continue;
    }

    copy_string(anchors[anchor_count].name, sizeof(anchors[anchor_count].name), spec.anchor_name);
    anchors[anchor_count].address = first_address;
    ++anchor_count;
    ++resolved;
    log_ue_anchor_signature_line(spec.anchor_name, "resolved", first_hit, first_address, spec.transform, first_allocation_base, first_region_base, first_protect, first_type, first_module_path);
  }

  line_init(&line);
  line_append(&line, "event=ue-anchor-signature-finish phase=");
  line_append(&line, phase);
  line_append(&line, " resolved=");
  line_append_dec(&line, resolved);
  line_append(&line, " anchors=");
  line_append_dec(&line, anchor_count);
  emit_line(&line);
  return anchor_count;
}

static int read_u16_at(const MEMORY_BASIC_INFORMATION_WIN64 *mbi, uintptr_t address, uint16_t *value) {
  if (!region_contains_range(mbi, address, sizeof(uint16_t)) || !readable_protect(mbi->Protect)) {
    return 0;
  }
  uint16_t read_value = 0;
  const unsigned char *source = (const unsigned char *)address;
  unsigned char *dest = (unsigned char *)&read_value;
  for (size_t i = 0; i < sizeof(read_value); ++i) {
    dest[i] = source[i];
  }
  *value = read_value;
  return 1;
}

static int read_i32_at(const MEMORY_BASIC_INFORMATION_WIN64 *mbi, uintptr_t address, int32_t *value) {
  uint32_t raw = 0;
  if (!read_u32_at(mbi, address, &raw)) {
    return 0;
  }
  unsigned char *dest = (unsigned char *)value;
  unsigned char *source = (unsigned char *)&raw;
  for (size_t i = 0; i < sizeof(raw); ++i) {
    dest[i] = source[i];
  }
  return 1;
}

typedef struct {
  uintptr_t pool_address;
  size_t pool_offset;
  size_t blocks_offset;
  size_t stride;
  size_t max_length;
} UeFNameOptions;

typedef struct {
  uintptr_t pool;
  char source[MAX_UE_ANCHOR_NAME];
  int available;
} UeFNameResolver;

static UeFNameOptions active_lua_fname_options;
static UeFNameResolver active_lua_fname_resolver;
static int active_lua_fname_resolver_available;

typedef struct {
  size_t array_offset;
  size_t item_size;
  size_t object_offset;
  size_t chunk_size;
  size_t max_objects;
} UeObjectArrayOptions;

typedef struct {
  size_t next_offset;
  size_t super_offset;
  size_t children_offset;
  size_t child_properties_offset;
  size_t property_link_offset;
  size_t function_link_offset;
  size_t field_next_offset;
  size_t property_array_dim_offset;
  size_t property_element_size_offset;
  size_t property_flags_offset;
  size_t property_offset_internal_offset;
  size_t function_flags_offset;
  size_t container_child_scan_start;
  size_t container_child_scan_end;
  size_t value_max_bytes;
  size_t max_fields;
} UeReflectionOptions;

static int add_ue_candidate_object_handle(const char *path, const char *name, const char *class_name, uintptr_t address);

static UeFNameOptions ue_fname_options(void) {
  UeFNameOptions options;
  options.pool_address = env_address_auto("UE4SSL_WIN_UE_FNAME_POOL", 0);
  if (!options.pool_address) {
    options.pool_address = env_address_auto("UE4SSL_WIN_UE_FNAME_POOL_ADDR", 0);
  }
  options.pool_offset = env_size_auto("UE4SSL_WIN_UE_FNAME_POOL_OFFSET", 0);
  options.blocks_offset = env_size_auto("UE4SSL_WIN_UE_FNAME_BLOCKS_OFFSET", DEFAULT_UE_FNAME_BLOCKS_OFFSET);
  options.stride = env_size_auto("UE4SSL_WIN_UE_FNAME_STRIDE", DEFAULT_UE_FNAME_STRIDE);
  options.max_length = env_size("UE4SSL_WIN_UE_FNAME_MAX_LENGTH", DEFAULT_UE_FNAME_MAX_LENGTH);
  if (options.blocks_offset > 0x4000) {
    options.blocks_offset = DEFAULT_UE_FNAME_BLOCKS_OFFSET;
  }
  if (options.stride == 0 || options.stride > 8) {
    options.stride = DEFAULT_UE_FNAME_STRIDE;
  }
  if (options.max_length == 0 || options.max_length > MAX_UE_FNAME_LENGTH) {
    options.max_length = DEFAULT_UE_FNAME_MAX_LENGTH;
  }
  return options;
}

static UeObjectArrayOptions ue_object_array_options(void) {
  UeObjectArrayOptions options;
  options.array_offset = env_size("UE4SSL_WIN_UE_OBJECT_ARRAY_OFFSET", 0);
  options.item_size = env_size("UE4SSL_WIN_UE_OBJECT_ARRAY_ITEM_SIZE", DEFAULT_UE_OBJECT_ITEM_SIZE);
  options.object_offset = env_size("UE4SSL_WIN_UE_OBJECT_ARRAY_OBJECT_OFFSET", 0);
  options.chunk_size = env_size("UE4SSL_WIN_UE_OBJECT_ARRAY_CHUNK_SIZE", DEFAULT_UE_OBJECT_CHUNK_SIZE);
  options.max_objects = env_size("UE4SSL_WIN_UE_OBJECT_ARRAY_MAX_OBJECTS", DEFAULT_UE_OBJECT_ARRAY_MAX_OBJECTS);
  if (options.item_size < sizeof(uintptr_t) || options.item_size > 256) {
    options.item_size = DEFAULT_UE_OBJECT_ITEM_SIZE;
  }
  if (options.object_offset + sizeof(uintptr_t) > options.item_size) {
    options.object_offset = 0;
  }
  if (options.chunk_size == 0 || options.chunk_size > DEFAULT_UE_OBJECT_CHUNK_SIZE) {
    options.chunk_size = DEFAULT_UE_OBJECT_CHUNK_SIZE;
  }
  if (options.max_objects == 0 || options.max_objects > MAX_UE_OBJECT_ARRAY_SCAN_OBJECTS) {
    options.max_objects = DEFAULT_UE_OBJECT_ARRAY_MAX_OBJECTS;
  }
  return options;
}

static size_t sane_reflection_offset(size_t value, size_t fallback) {
  return value <= MAX_UE_REFLECTION_SLOT_OFFSET ? value : fallback;
}

static UeReflectionOptions ue_reflection_options(void) {
  UeReflectionOptions options;
  options.next_offset = sane_reflection_offset(
    env_size_auto("UE4SSL_WIN_UE_REFLECTION_NEXT_OFFSET", DEFAULT_UE_REFLECTION_NEXT_OFFSET),
    DEFAULT_UE_REFLECTION_NEXT_OFFSET
  );
  options.super_offset = sane_reflection_offset(
    env_size_auto("UE4SSL_WIN_UE_REFLECTION_SUPER_OFFSET", DEFAULT_UE_REFLECTION_SUPER_OFFSET),
    DEFAULT_UE_REFLECTION_SUPER_OFFSET
  );
  options.children_offset = sane_reflection_offset(
    env_size_auto("UE4SSL_WIN_UE_REFLECTION_CHILDREN_OFFSET", DEFAULT_UE_REFLECTION_CHILDREN_OFFSET),
    DEFAULT_UE_REFLECTION_CHILDREN_OFFSET
  );
  options.child_properties_offset = sane_reflection_offset(
    env_size_auto("UE4SSL_WIN_UE_REFLECTION_CHILD_PROPERTIES_OFFSET", DEFAULT_UE_REFLECTION_CHILD_PROPERTIES_OFFSET),
    DEFAULT_UE_REFLECTION_CHILD_PROPERTIES_OFFSET
  );
  options.property_link_offset = sane_reflection_offset(
    env_size_auto("UE4SSL_WIN_UE_REFLECTION_PROPERTY_LINK_OFFSET", DEFAULT_UE_REFLECTION_PROPERTY_LINK_OFFSET),
    DEFAULT_UE_REFLECTION_PROPERTY_LINK_OFFSET
  );
  options.function_link_offset = sane_reflection_offset(
    env_size_auto("UE4SSL_WIN_UE_REFLECTION_FUNCTION_LINK_OFFSET", DEFAULT_UE_REFLECTION_FUNCTION_LINK_OFFSET),
    DEFAULT_UE_REFLECTION_FUNCTION_LINK_OFFSET
  );
  options.field_next_offset = sane_reflection_offset(
    env_size_auto("UE4SSL_WIN_UE_REFLECTION_FIELD_NEXT_OFFSET", DEFAULT_UE_REFLECTION_FIELD_NEXT_OFFSET),
    DEFAULT_UE_REFLECTION_FIELD_NEXT_OFFSET
  );
  options.property_array_dim_offset = sane_reflection_offset(
    env_size_auto("UE4SSL_WIN_UE_REFLECTION_PROPERTY_ARRAY_DIM_OFFSET", DEFAULT_UE_REFLECTION_PROPERTY_ARRAY_DIM_OFFSET),
    DEFAULT_UE_REFLECTION_PROPERTY_ARRAY_DIM_OFFSET
  );
  options.property_element_size_offset = sane_reflection_offset(
    env_size_auto("UE4SSL_WIN_UE_REFLECTION_PROPERTY_ELEMENT_SIZE_OFFSET", DEFAULT_UE_REFLECTION_PROPERTY_ELEMENT_SIZE_OFFSET),
    DEFAULT_UE_REFLECTION_PROPERTY_ELEMENT_SIZE_OFFSET
  );
  options.property_flags_offset = sane_reflection_offset(
    env_size_auto("UE4SSL_WIN_UE_REFLECTION_PROPERTY_FLAGS_OFFSET", DEFAULT_UE_REFLECTION_PROPERTY_FLAGS_OFFSET),
    DEFAULT_UE_REFLECTION_PROPERTY_FLAGS_OFFSET
  );
  options.property_offset_internal_offset = sane_reflection_offset(
    env_size_auto("UE4SSL_WIN_UE_REFLECTION_PROPERTY_OFFSET_INTERNAL_OFFSET", DEFAULT_UE_REFLECTION_PROPERTY_OFFSET_INTERNAL_OFFSET),
    DEFAULT_UE_REFLECTION_PROPERTY_OFFSET_INTERNAL_OFFSET
  );
  options.function_flags_offset = sane_reflection_offset(
    env_size_auto("UE4SSL_WIN_UE_REFLECTION_FUNCTION_FLAGS_OFFSET", DEFAULT_UE_REFLECTION_FUNCTION_FLAGS_OFFSET),
    DEFAULT_UE_REFLECTION_FUNCTION_FLAGS_OFFSET
  );
  options.container_child_scan_start = sane_reflection_offset(
    env_size_auto("UE4SSL_WIN_UE_REFLECTION_CONTAINER_CHILD_SCAN_START", DEFAULT_UE_REFLECTION_CONTAINER_CHILD_SCAN_START),
    DEFAULT_UE_REFLECTION_CONTAINER_CHILD_SCAN_START
  );
  options.container_child_scan_end = sane_reflection_offset(
    env_size_auto("UE4SSL_WIN_UE_REFLECTION_CONTAINER_CHILD_SCAN_END", DEFAULT_UE_REFLECTION_CONTAINER_CHILD_SCAN_END),
    DEFAULT_UE_REFLECTION_CONTAINER_CHILD_SCAN_END
  );
  if (options.container_child_scan_end <= options.container_child_scan_start ||
      options.container_child_scan_end - options.container_child_scan_start > 0x100) {
    options.container_child_scan_start = DEFAULT_UE_REFLECTION_CONTAINER_CHILD_SCAN_START;
    options.container_child_scan_end = DEFAULT_UE_REFLECTION_CONTAINER_CHILD_SCAN_END;
  }
  options.max_fields = env_size("UE4SSL_WIN_UE_REFLECTION_MAX_FIELDS", DEFAULT_UE_REFLECTION_MAX_FIELDS);
  if (options.max_fields == 0 || options.max_fields > MAX_UE_REFLECTION_FIELDS) {
    options.max_fields = DEFAULT_UE_REFLECTION_MAX_FIELDS;
  }
  options.value_max_bytes = env_size("UE4SSL_WIN_UE_REFLECTION_VALUE_MAX_BYTES", DEFAULT_UE_REFLECTION_VALUE_MAX_BYTES);
  if (options.value_max_bytes == 0 || options.value_max_bytes > MAX_UE_REFLECTION_VALUE_BYTES) {
    options.value_max_bytes = DEFAULT_UE_REFLECTION_VALUE_MAX_BYTES;
  }
  return options;
}

static int register_lua_object_candidate(const char *source, const char *safe_name, const char *class_name, uintptr_t target) {
  static char object_path[MAX_LUA_OBJECT_PATH];
  copy_string(object_path, sizeof(object_path), "/RuntimeProbe/");
  size_t prefix_len = cstr_len(object_path);
  size_t name_len = cstr_len(safe_name);
  for (size_t i = 0; i < name_len && prefix_len + i + 1 < sizeof(object_path); ++i) {
    object_path[prefix_len + i] = safe_name[i];
    object_path[prefix_len + i + 1] = '\0';
  }
  int registered_candidate = add_ue_candidate_object_handle(object_path, safe_name, class_name, target);
  static Line line;
  line_init(&line);
  line_append(&line, "event=lua-object-registry source=");
  line_append(&line, source);
  line_append(&line, " status=");
  line_append(&line, registered_candidate ? "added" : "skipped");
  line_append(&line, " name=");
  line_append(&line, safe_name);
  line_append(&line, " path=");
  line_append(&line, object_path);
  line_append(&line, " class=");
  line_append(&line, class_name);
  line_append(&line, " address=");
  line_append_hex(&line, target);
  line_append(&line, " registryCount=");
  line_append_dec(&line, ue_candidate_object_handle_count);
  emit_line(&line);
  return registered_candidate;
}

static int is_fname_pool_anchor_name(const char *name) {
  return contains_ci(name, "FNamePool") ||
         contains_ci(name, "GName") ||
         contains_ci(name, "NamePool") ||
         contains_ci(name, "SelfTestFNamePool");
}

static int fname_pool_candidate_readable(uintptr_t pool, const UeFNameOptions *options) {
  MEMORY_BASIC_INFORMATION_WIN64 mbi;
  SIZE_T got = VirtualQuery((const void *)(pool + options->blocks_offset), &mbi, sizeof(mbi));
  uintptr_t first_block = 0;
  return got && mbi.State == MEM_COMMIT && read_pointer_at(&mbi, pool + options->blocks_offset, &first_block);
}

static void copy_resolver_source(char *out, size_t out_size, const char *name, const char *mode) {
  static Line line;
  line_init(&line);
  line_append(&line, name);
  line_append_char(&line, ':');
  line_append(&line, mode);
  copy_string(out, out_size, line.text);
}

static int find_ue_fname_resolver(
  const UeAnchor *anchors,
  size_t anchor_count,
  const UeFNameOptions *options,
  UeFNameResolver *resolver
) {
  unsigned char *bytes = (unsigned char *)resolver;
  for (size_t i = 0; i < sizeof(*resolver); ++i) {
    bytes[i] = 0;
  }
  if (options->pool_address) {
    uintptr_t pool = options->pool_address + options->pool_offset;
    if (fname_pool_candidate_readable(pool, options)) {
      resolver->pool = pool;
      resolver->available = 1;
      copy_string(resolver->source, sizeof(resolver->source), "env");
      return 1;
    }
  }
  for (size_t i = 0; i < anchor_count; ++i) {
    if (!is_fname_pool_anchor_name(anchors[i].name)) {
      continue;
    }
    uintptr_t direct = anchors[i].address + options->pool_offset;
    if (fname_pool_candidate_readable(direct, options)) {
      resolver->pool = direct;
      resolver->available = 1;
      copy_resolver_source(resolver->source, sizeof(resolver->source), anchors[i].name, "direct");
      return 1;
    }
    MEMORY_BASIC_INFORMATION_WIN64 anchor_mbi;
    SIZE_T anchor_got = VirtualQuery((const void *)anchors[i].address, &anchor_mbi, sizeof(anchor_mbi));
    uintptr_t indirect = 0;
    if (anchor_got && read_pointer_at(&anchor_mbi, anchors[i].address, &indirect) && indirect != 0) {
      uintptr_t pool = indirect + options->pool_offset;
      if (fname_pool_candidate_readable(pool, options)) {
        resolver->pool = pool;
        resolver->available = 1;
        copy_resolver_source(resolver->source, sizeof(resolver->source), anchors[i].name, "indirect");
        return 1;
      }
    }
  }
  return 0;
}

static void cache_lua_fname_resolver(
  const UeFNameResolver *resolver,
  const UeFNameOptions *options
) {
  if (!resolver || !options || !resolver->available || resolver->pool == 0) {
    return;
  }
  const unsigned char *option_source = (const unsigned char *)options;
  unsigned char *option_dest = (unsigned char *)&active_lua_fname_options;
  for (size_t i = 0; i < sizeof(active_lua_fname_options); ++i) {
    option_dest[i] = option_source[i];
  }
  const unsigned char *resolver_source = (const unsigned char *)resolver;
  unsigned char *resolver_dest = (unsigned char *)&active_lua_fname_resolver;
  for (size_t i = 0; i < sizeof(active_lua_fname_resolver); ++i) {
    resolver_dest[i] = resolver_source[i];
  }
  active_lua_fname_resolver_available = 1;
}

static void copy_decoded_fname_char(char *out, size_t out_size, size_t *written, unsigned int ch) {
  if (*written + 1 >= out_size) {
    return;
  }
  if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
      (ch >= '0' && ch <= '9') || ch == '_' || ch == '-' || ch == '.') {
    out[(*written)++] = (char)ch;
  } else if (ch >= 32 && ch < 127) {
    out[(*written)++] = '_';
  } else {
    out[(*written)++] = '?';
  }
  out[*written] = '\0';
}

static void append_uint_to_buffer(char *out, size_t out_size, size_t *written, unsigned int value) {
  char digits[16];
  size_t count = 0;
  if (value == 0) {
    copy_decoded_fname_char(out, out_size, written, '0');
    return;
  }
  while (value > 0 && count < sizeof(digits)) {
    digits[count++] = (char)('0' + (value % 10U));
    value /= 10U;
  }
  while (count > 0) {
    copy_decoded_fname_char(out, out_size, written, (unsigned int)digits[--count]);
  }
}

static int decode_ue_fname(
  const UeFNameResolver *resolver,
  const UeFNameOptions *options,
  uint32_t comparison_index,
  uint32_t number,
  char *decoded,
  size_t decoded_size,
  uintptr_t *entry_out,
  uint32_t *block_out,
  uint32_t *offset_out,
  int *wide_out,
  const char **status_out
) {
  if (decoded_size > 0) {
    decoded[0] = '\0';
  }
  if (entry_out) *entry_out = 0;
  if (block_out) *block_out = 0;
  if (offset_out) *offset_out = 0;
  if (wide_out) *wide_out = 0;
  if (status_out) *status_out = "unavailable";
  if (!resolver || !resolver->available || resolver->pool == 0) {
    return 0;
  }
  uint32_t block = comparison_index >> 16;
  uint32_t offset = comparison_index & 0xffffU;
  if (block_out) *block_out = block;
  if (offset_out) *offset_out = offset;
  uintptr_t block_slot = resolver->pool + options->blocks_offset + (uintptr_t)block * sizeof(uintptr_t);
  MEMORY_BASIC_INFORMATION_WIN64 slot_mbi;
  SIZE_T slot_got = VirtualQuery((const void *)block_slot, &slot_mbi, sizeof(slot_mbi));
  uintptr_t block_base = 0;
  if (!slot_got || !read_pointer_at(&slot_mbi, block_slot, &block_base) || block_base == 0) {
    if (status_out) *status_out = "block-unreadable";
    return 0;
  }
  uintptr_t entry = block_base + (uintptr_t)offset * options->stride;
  if (entry_out) *entry_out = entry;
  MEMORY_BASIC_INFORMATION_WIN64 entry_mbi;
  SIZE_T entry_got = VirtualQuery((const void *)entry, &entry_mbi, sizeof(entry_mbi));
  uint16_t header = 0;
  if (!entry_got || !read_u16_at(&entry_mbi, entry, &header)) {
    if (status_out) *status_out = "entry-unreadable";
    return 0;
  }
  int is_wide = (header & 1U) ? 1 : 0;
  size_t length = (size_t)(header >> 1);
  if (wide_out) *wide_out = is_wide;
  if (length == 0 || length > options->max_length) {
    if (status_out) *status_out = "length-invalid";
    return 0;
  }
  size_t bytes = is_wide ? length * sizeof(uint16_t) : length;
  if (!region_contains_range(&entry_mbi, entry + sizeof(uint16_t), bytes)) {
    if (status_out) *status_out = "name-truncated";
    return 0;
  }
  size_t written = 0;
  for (size_t i = 0; i < length; ++i) {
    unsigned int ch = 0;
    if (is_wide) {
      const unsigned char *source = (const unsigned char *)(entry + sizeof(uint16_t) + i * sizeof(uint16_t));
      ch = (unsigned int)source[0] | ((unsigned int)source[1] << 8);
    } else {
      ch = *(const unsigned char *)(entry + sizeof(uint16_t) + i);
    }
    copy_decoded_fname_char(decoded, decoded_size, &written, ch);
  }
  if (number > 0 && written + 2 < decoded_size) {
    copy_decoded_fname_char(decoded, decoded_size, &written, '_');
    append_uint_to_buffer(decoded, decoded_size, &written, number - 1);
  }
  if (status_out) *status_out = "decoded";
  return 1;
}

static void log_ue_fname_for_object(
  const char *object_name,
  const char *source,
  uintptr_t object,
  uint32_t comparison_index,
  uint32_t number,
  const UeFNameResolver *resolver,
  const UeFNameOptions *options
) {
  static Line line;
  if (!resolver || !resolver->available) {
    line_init(&line);
    line_append(&line, "event=ue-fname source=");
    line_append(&line, source);
    line_append(&line, " objectName=");
    line_append(&line, object_name);
    line_append(&line, " status=pool-unavailable object=");
    line_append_hex(&line, object);
    line_append(&line, " comparisonIndex=");
    line_append_dec(&line, comparison_index);
    line_append(&line, " number=");
    line_append_dec(&line, number);
    emit_line(&line);
    return;
  }
  static char decoded[MAX_LUA_OBJECT_NAME];
  uintptr_t entry = 0;
  uint32_t block = 0;
  uint32_t offset = 0;
  int is_wide = 0;
  const char *status = "unknown";
  int ok = decode_ue_fname(
    resolver,
    options,
    comparison_index,
    number,
    decoded,
    sizeof(decoded),
    &entry,
    &block,
    &offset,
    &is_wide,
    &status
  );
  static char safe_decoded[MAX_LUA_OBJECT_NAME];
  safe_value(decoded, safe_decoded, sizeof(safe_decoded));
  line_init(&line);
  line_append(&line, "event=ue-fname source=");
  line_append(&line, source);
  line_append(&line, " objectName=");
  line_append(&line, object_name);
  line_append(&line, " status=");
  line_append(&line, ok ? "decoded" : status);
  line_append(&line, " object=");
  line_append_hex(&line, object);
  line_append(&line, " pool=");
  line_append_hex(&line, resolver->pool);
  line_append(&line, " resolver=");
  line_append(&line, resolver->source);
  line_append(&line, " comparisonIndex=");
  line_append_dec(&line, comparison_index);
  line_append(&line, " number=");
  line_append_dec(&line, number);
  line_append(&line, " block=");
  line_append_dec(&line, block);
  line_append(&line, " offset=");
  line_append_hex(&line, offset);
  line_append(&line, " entry=");
  line_append_hex(&line, entry);
  line_append(&line, " wide=");
  line_append(&line, is_wide ? "true" : "false");
  line_append(&line, " decoded=");
  line_append(&line, ok ? safe_decoded : "");
  emit_line(&line);
}

static int register_lua_object_decoded_candidate(
  const char *source,
  const char *alias_of,
  const char *class_name,
  uintptr_t target,
  const char *decoded_name
) {
  if (!decoded_name || !decoded_name[0]) {
    return 0;
  }
  static char object_path[MAX_LUA_OBJECT_PATH];
  copy_string(object_path, sizeof(object_path), "/RuntimeProbe/");
  size_t prefix_len = cstr_len(object_path);
  size_t name_len = cstr_len(decoded_name);
  for (size_t i = 0; i < name_len && prefix_len + i + 1 < sizeof(object_path); ++i) {
    object_path[prefix_len + i] = decoded_name[i];
    object_path[prefix_len + i + 1] = '\0';
  }
  int registered_candidate = add_ue_candidate_object_handle(object_path, decoded_name, class_name, target);
  static Line line;
  line_init(&line);
  line_append(&line, "event=lua-object-registry source=");
  line_append(&line, source);
  line_append(&line, " status=");
  line_append(&line, registered_candidate ? "added" : "skipped");
  line_append(&line, " name=");
  line_append(&line, decoded_name);
  line_append(&line, " path=");
  line_append(&line, object_path);
  line_append(&line, " aliasOf=");
  line_append(&line, alias_of && alias_of[0] ? alias_of : "");
  line_append(&line, " class=");
  line_append(&line, class_name);
  line_append(&line, " address=");
  line_append_hex(&line, target);
  line_append(&line, " registryCount=");
  line_append_dec(&line, ue_candidate_object_handle_count);
  emit_line(&line);
  return registered_candidate;
}

__attribute__((noinline, used)) static int hook_self_test_target(int value) {
#if defined(__x86_64__) || defined(__amd64__) || defined(_M_X64)
  __asm__ __volatile__(
    ".rept 16\n"
    "nop\n"
    ".endr\n"
  );
#endif
  return value + 1;
}

static void reset_hook_dispatch_slots(void) {
  unsigned char *bytes = (unsigned char *)hook_dispatch_slots;
  for (size_t i = 0; i < sizeof(hook_dispatch_slots); ++i) {
    bytes[i] = 0;
  }
  hook_dispatch_slot_count = 0;
  hook_self_test_last_original = 0;
  hook_self_test_last_pre_callbacks = 0;
  hook_self_test_last_post_callbacks = 0;
}

static int register_hook_dispatch_callback(HookDispatchStage stage, HookDispatchCallback callback, void *user) {
  if (!callback || hook_dispatch_slot_count >= MAX_HOOK_DISPATCH_CALLBACKS) {
    return 0;
  }
  hook_dispatch_slots[hook_dispatch_slot_count].stage = stage;
  hook_dispatch_slots[hook_dispatch_slot_count].callback = callback;
  hook_dispatch_slots[hook_dispatch_slot_count].user = user;
  ++hook_dispatch_slot_count;
  return 1;
}

static void hook_self_test_pre_callback(HookDispatchContext *ctx, void *user) {
  (void)user;
  ++ctx->pre_callbacks;
}

static void hook_self_test_post_callback(HookDispatchContext *ctx, void *user) {
  (void)user;
  ++ctx->post_callbacks;
}

static void reset_mod_dispatch_entries(void) {
  unsigned char *bytes = (unsigned char *)mod_dispatch_entries;
  for (size_t i = 0; i < sizeof(mod_dispatch_entries); ++i) {
    bytes[i] = 0;
  }
  mod_dispatch_entry_count = 0;
  mod_self_test_load_callbacks = 0;
  mod_self_test_unload_callbacks = 0;
}

static int register_mod_dispatch_entry(const ModDispatchEntry *entry) {
  if (!entry || !entry->name || mod_dispatch_entry_count >= MAX_MOD_DISPATCH_ENTRIES) {
    return 0;
  }
  mod_dispatch_entries[mod_dispatch_entry_count++] = *entry;
  return 1;
}

static int load_mod_dispatch_entries(void) {
  int loaded = 0;
  for (size_t i = 0; i < mod_dispatch_entry_count; ++i) {
    ModDispatchEntry *entry = &mod_dispatch_entries[i];
    if (entry->on_load) {
      entry->on_load(entry->user);
    }
    if (entry->on_pre_hook && !register_hook_dispatch_callback(HOOK_DISPATCH_PRE, entry->on_pre_hook, entry->user)) {
      continue;
    }
    if (entry->on_post_hook && !register_hook_dispatch_callback(HOOK_DISPATCH_POST, entry->on_post_hook, entry->user)) {
      continue;
    }
    entry->loaded = 1;
    ++loaded;
  }
  return loaded;
}

static int unload_mod_dispatch_entries(void) {
  int unloaded = 0;
  for (size_t i = 0; i < mod_dispatch_entry_count; ++i) {
    ModDispatchEntry *entry = &mod_dispatch_entries[i];
    if (!entry->loaded) {
      continue;
    }
    if (entry->on_unload) {
      entry->on_unload(entry->user);
    }
    entry->loaded = 0;
    ++unloaded;
  }
  return unloaded;
}

static void mod_self_test_load(void *user) {
  (void)user;
  ++mod_self_test_load_callbacks;
}

static void mod_self_test_unload(void *user) {
  (void)user;
  ++mod_self_test_unload_callbacks;
}

static void run_dispatch_callbacks(HookDispatchStage stage, HookDispatchContext *ctx) {
  for (size_t i = 0; i < hook_dispatch_slot_count; ++i) {
    if (hook_dispatch_slots[i].stage == stage && hook_dispatch_slots[i].callback) {
      hook_dispatch_slots[i].callback(ctx, hook_dispatch_slots[i].user);
    }
  }
}

static void reset_process_event_dispatch_slots(void) {
  unsigned char *bytes = (unsigned char *)process_event_dispatch_slots;
  for (size_t i = 0; i < sizeof(process_event_dispatch_slots); ++i) {
    bytes[i] = 0;
  }
  process_event_dispatch_slot_count = 0;
  process_event_live_hook_last_pre_callbacks = 0;
  process_event_live_hook_last_post_callbacks = 0;
}

static int register_process_event_dispatch_callback(HookDispatchStage stage, ProcessEventDispatchCallback callback, void *user) {
  if (!callback || process_event_dispatch_slot_count >= MAX_HOOK_DISPATCH_CALLBACKS) {
    return 0;
  }
  process_event_dispatch_slots[process_event_dispatch_slot_count].stage = stage;
  process_event_dispatch_slots[process_event_dispatch_slot_count].callback = callback;
  process_event_dispatch_slots[process_event_dispatch_slot_count].user = user;
  ++process_event_dispatch_slot_count;
  return 1;
}

static void process_event_dispatch_self_test_pre(ProcessEventDispatchContext *ctx, void *user) {
  (void)user;
  ++ctx->pre_callbacks;
}

static void process_event_dispatch_self_test_post(ProcessEventDispatchContext *ctx, void *user) {
  (void)user;
  ++ctx->post_callbacks;
}

static void run_process_event_dispatch_callbacks(HookDispatchStage stage, ProcessEventDispatchContext *ctx) {
  for (size_t i = 0; i < process_event_dispatch_slot_count; ++i) {
    if (process_event_dispatch_slots[i].stage == stage && process_event_dispatch_slots[i].callback) {
      process_event_dispatch_slots[i].callback(ctx, process_event_dispatch_slots[i].user);
    }
  }
}

static int dispatch_hook_self_test(int value) {
  HookDispatchContext ctx;
  unsigned char *bytes = (unsigned char *)&ctx;
  for (size_t i = 0; i < sizeof(ctx); ++i) {
    bytes[i] = 0;
  }
  ctx.value = value;
  run_dispatch_callbacks(HOOK_DISPATCH_PRE, &ctx);

  HookSelfTestFn original = hook_self_test_original;
  ctx.original_result = original ? original(ctx.value) : ctx.value + 1;
  ctx.result = ctx.original_result + 1000;

  run_dispatch_callbacks(HOOK_DISPATCH_POST, &ctx);
  hook_self_test_last_original = ctx.original_result;
  hook_self_test_last_pre_callbacks = ctx.pre_callbacks;
  hook_self_test_last_post_callbacks = ctx.post_callbacks;
  return ctx.result;
}

static void run_mod_dispatch_self_test(const char *phase) {
  if (!env_bool("UE4SSL_WIN_MOD_SELF_TEST", 0)) {
    return;
  }
  reset_hook_dispatch_slots();
  reset_mod_dispatch_entries();
  ModDispatchEntry entry = {
    "SelfTestMod",
    mod_self_test_load,
    hook_self_test_pre_callback,
    hook_self_test_post_callback,
    mod_self_test_unload,
    0,
    0,
  };
  int registered = register_mod_dispatch_entry(&entry);
  int loaded = load_mod_dispatch_entries();
  hook_self_test_original = hook_self_test_target;
  int result = dispatch_hook_self_test(41);
  hook_self_test_original = 0;
  int unloaded = unload_mod_dispatch_entries();
  const char *status = registered && loaded == 1 && result == 1042 &&
                       hook_self_test_last_original == 42 &&
                       hook_self_test_last_pre_callbacks == 1 &&
                       hook_self_test_last_post_callbacks == 1 &&
                       mod_self_test_load_callbacks == 1 &&
                       mod_self_test_unload_callbacks == 1 &&
                       unloaded == 1 ? "passed" : "failed";

  static Line line;
  line_init(&line);
  line_append(&line, "event=mod-dispatch-self-test phase=");
  line_append(&line, phase);
  line_append(&line, " status=");
  line_append(&line, status);
  line_append(&line, " mods=");
  line_append_dec(&line, mod_dispatch_entry_count);
  line_append(&line, " loaded=");
  line_append_signed_dec(&line, loaded);
  line_append(&line, " unloaded=");
  line_append_signed_dec(&line, unloaded);
  line_append(&line, " result=");
  line_append_signed_dec(&line, result);
  line_append(&line, " original=");
  line_append_signed_dec(&line, hook_self_test_last_original);
  line_append(&line, " callbacks=");
  line_append_dec(&line, hook_dispatch_slot_count);
  line_append(&line, " preCallbacks=");
  line_append_signed_dec(&line, hook_self_test_last_pre_callbacks);
  line_append(&line, " postCallbacks=");
  line_append_signed_dec(&line, hook_self_test_last_post_callbacks);
  line_append(&line, " loadCallbacks=");
  line_append_signed_dec(&line, mod_self_test_load_callbacks);
  line_append(&line, " unloadCallbacks=");
  line_append_signed_dec(&line, mod_self_test_unload_callbacks);
  emit_line(&line);
}

#define LOAD_LUA_SYMBOL(api, field, type, symbol_name) \
  do { \
    union { void *ptr; type fn; } lua_symbol; \
    lua_symbol.ptr = GetProcAddress((api)->module, (symbol_name)); \
    (api)->field = lua_symbol.fn; \
  } while (0)

static void zero_lua_api(LuaApi *api) {
  unsigned char *bytes = (unsigned char *)api;
  for (size_t i = 0; i < sizeof(*api); ++i) {
    bytes[i] = 0;
  }
}

static int load_lua_api_from_library(const char *library, LuaApi *api) {
  if (!library || !library[0] || !api) {
    return 0;
  }
  HMODULE module = LoadLibraryA(library);
  if (!module) {
    return 0;
  }
  zero_lua_api(api);
  api->module = module;
  copy_string(api->library, sizeof(api->library), library);
  LOAD_LUA_SYMBOL(api, new_state, LuaNewStateFn, "luaL_newstate");
  LOAD_LUA_SYMBOL(api, open_libs, LuaOpenLibsFn, "luaL_openlibs");
  LOAD_LUA_SYMBOL(api, load_string, LuaLoadStringFn, "luaL_loadstring");
  LOAD_LUA_SYMBOL(api, pcallk, LuaPCallKFn, "lua_pcallk");
  LOAD_LUA_SYMBOL(api, pcall, LuaPCallFn, "lua_pcall");
  LOAD_LUA_SYMBOL(api, to_integerx, LuaToIntegerXFn, "lua_tointegerx");
  LOAD_LUA_SYMBOL(api, to_integer, LuaToIntegerFn, "lua_tointeger");
  LOAD_LUA_SYMBOL(api, to_numberx, LuaToNumberXFn, "lua_tonumberx");
  LOAD_LUA_SYMBOL(api, to_number, LuaToNumberFn, "lua_tonumber");
  LOAD_LUA_SYMBOL(api, to_lstring, LuaToLStringFn, "lua_tolstring");
  LOAD_LUA_SYMBOL(api, to_boolean, LuaToBooleanFn, "lua_toboolean");
  LOAD_LUA_SYMBOL(api, push_cclosure, LuaPushCClosureFn, "lua_pushcclosure");
  LOAD_LUA_SYMBOL(api, set_global, LuaSetGlobalFn, "lua_setglobal");
  LOAD_LUA_SYMBOL(api, push_integer, LuaPushIntegerFn, "lua_pushinteger");
  LOAD_LUA_SYMBOL(api, push_number, LuaPushNumberFn, "lua_pushnumber");
  LOAD_LUA_SYMBOL(api, push_nil, LuaPushNilFn, "lua_pushnil");
  LOAD_LUA_SYMBOL(api, push_string, LuaPushStringFn, "lua_pushstring");
  LOAD_LUA_SYMBOL(api, push_boolean, LuaPushBooleanFn, "lua_pushboolean");
  LOAD_LUA_SYMBOL(api, create_table, LuaCreateTableFn, "lua_createtable");
  LOAD_LUA_SYMBOL(api, set_field, LuaSetFieldFn, "lua_setfield");
  LOAD_LUA_SYMBOL(api, type, LuaTypeFn, "lua_type");
  LOAD_LUA_SYMBOL(api, push_value, LuaPushValueFn, "lua_pushvalue");
  LOAD_LUA_SYMBOL(api, ref, LuaLRefFn, "luaL_ref");
  LOAD_LUA_SYMBOL(api, rawgeti, LuaRawGetIFn, "lua_rawgeti");
  LOAD_LUA_SYMBOL(api, unref, LuaLUnrefFn, "luaL_unref");
  LOAD_LUA_SYMBOL(api, set_top, LuaSetTopFn, "lua_settop");
  LOAD_LUA_SYMBOL(api, get_field, LuaGetFieldFn, "lua_getfield");
  LOAD_LUA_SYMBOL(api, close, LuaCloseFn, "lua_close");
  if (!api->new_state || !api->open_libs || !api->load_string || (!api->pcallk && !api->pcall) ||
      (!api->to_integerx && !api->to_integer) || (!api->to_numberx && !api->to_number) ||
      !api->to_lstring ||
      !api->push_cclosure || !api->set_global || !api->push_integer || !api->push_number || !api->push_nil ||
      !api->to_boolean || !api->push_string || !api->push_boolean || !api->create_table || !api->set_field ||
      !api->type || !api->push_value || !api->ref || !api->rawgeti || !api->set_top ||
      !api->get_field ||
      !api->close) {
    FreeLibrary(module);
    zero_lua_api(api);
    return 0;
  }
  return 1;
}

static int load_lua_api(LuaApi *api) {
  static char configured[512];
  if (env_get("UE4SSL_WIN_LUA_DLL", configured, sizeof(configured)) > 0 &&
      configured[0] && load_lua_api_from_library(configured, api)) {
    return 1;
  }
  static const char *candidates[] = {
    "lua54.dll",
    "lua5.4.dll",
    "lua.dll",
    "luajit.dll",
  };
  for (size_t i = 0; i < sizeof(candidates) / sizeof(candidates[0]); ++i) {
    if (load_lua_api_from_library(candidates[i], api)) {
      return 1;
    }
  }
  return 0;
}

static int lua_call(LuaApi *api, LuaState *state, int nargs, int nresults, int errfunc) {
  if (api->pcallk) {
    return api->pcallk(state, nargs, nresults, errfunc, 0, 0);
  }
  return api->pcall(state, nargs, nresults, errfunc);
}

static long long lua_to_integer(LuaApi *api, LuaState *state, int index, int *is_number) {
  if (api->to_integerx) {
    return api->to_integerx(state, index, is_number);
  }
  if (is_number) {
    *is_number = 1;
  }
  return api->to_integer(state, index);
}

static double lua_to_number(LuaApi *api, LuaState *state, int index, int *is_number) {
  if (is_number) {
    *is_number = 0;
  }
  if (!api || !state) {
    return 0.0;
  }
  if (api->to_numberx) {
    return api->to_numberx(state, index, is_number);
  }
  if (api->type && api->type(state, index) != LUA_TNUMBER_COMPAT) {
    return 0.0;
  }
  if (is_number) {
    *is_number = 1;
  }
  return api->to_number ? api->to_number(state, index) : 0.0;
}

static int lua_to_boolean(LuaApi *api, LuaState *state, int index, int *is_boolean) {
  if (is_boolean) {
    *is_boolean = 0;
  }
  if (!api || !state) {
    return 0;
  }
  if (api->type && api->type(state, index) == LUA_TBOOLEAN_COMPAT && api->to_boolean) {
    if (is_boolean) {
      *is_boolean = 1;
    }
    return api->to_boolean(state, index) != 0;
  }
  int is_number = 0;
  long long value = lua_to_integer(api, state, index, &is_number);
  if (is_number) {
    if (is_boolean) {
      *is_boolean = 1;
    }
    return value != 0;
  }
  return 0;
}

static const char *path_basename_win(const char *path);

static int add_object_handle_to(
  LuaObjectHandle *handles,
  size_t *count,
  const char *path,
  const char *name,
  const char *class_name,
  uintptr_t address
) {
  if (!handles || !count || !path || !path[0] || *count >= MAX_LUA_OBJECT_HANDLES) {
    return 0;
  }
  LuaObjectHandle *object = &handles[(*count)++];
  copy_string(object->path, sizeof(object->path), path);
  copy_string(object->name, sizeof(object->name), (name && name[0]) ? name : path_basename_win(path));
  copy_string(object->class_name, sizeof(object->class_name), (class_name && class_name[0]) ? class_name : "UObject");
  object->address = address;
  object->class_address = 0;
  object->outer_address = 0;
  object->super_address = 0;
  object->object_flags = 0;
  object->internal_index = 0;
  object->has_object_metadata = 0;
  object->internal_flags = 0;
  object->has_internal_flags = 0;
  object->function_flags = 0;
  object->has_function_flags = 0;
  return 1;
}

static int add_lua_object_handle(const char *path, const char *name, const char *class_name, uintptr_t address) {
  return add_object_handle_to(&lua_object_handles[0], &lua_object_handle_count, path, name, class_name, address);
}

static int add_ue_candidate_object_handle(const char *path, const char *name, const char *class_name, uintptr_t address) {
  const char *candidate_name = (name && name[0]) ? name : path_basename_win(path);
  for (size_t i = 0; i < ue_candidate_object_handle_count; ++i) {
    const LuaObjectHandle *object = &ue_candidate_object_handles[i];
    if (object->address == address &&
        (str_equal(object->path, path) || str_equal(object->name, candidate_name))) {
      return 0;
    }
  }
  return add_object_handle_to(&ue_candidate_object_handles[0], &ue_candidate_object_handle_count, path, name, class_name, address);
}

static void update_ue_candidate_object_metadata(uintptr_t address, uintptr_t class_address, uintptr_t outer_address, uintptr_t super_address) {
  if (!address) {
    return;
  }
  for (size_t i = 0; i < ue_candidate_object_handle_count; ++i) {
    LuaObjectHandle *object = &ue_candidate_object_handles[i];
    if (object->address != address) {
      continue;
    }
    if (class_address) {
      object->class_address = class_address;
    }
    if (outer_address) {
      object->outer_address = outer_address;
    }
    if (super_address) {
      object->super_address = super_address;
    }
  }
}

static void update_ue_candidate_object_layout_metadata(uintptr_t address, uint32_t object_flags, int32_t internal_index) {
  if (!address) {
    return;
  }
  for (size_t i = 0; i < ue_candidate_object_handle_count; ++i) {
    LuaObjectHandle *object = &ue_candidate_object_handles[i];
    if (object->address != address) {
      continue;
    }
    object->object_flags = object_flags;
    object->internal_index = internal_index;
    object->has_object_metadata = 1;
  }
}

static void update_ue_candidate_object_internal_flags(uintptr_t address, uint32_t internal_flags, int has_internal_flags) {
  if (!address || !has_internal_flags) {
    return;
  }
  for (size_t i = 0; i < ue_candidate_object_handle_count; ++i) {
    LuaObjectHandle *object = &ue_candidate_object_handles[i];
    if (object->address != address) {
      continue;
    }
    object->internal_flags = internal_flags;
    object->has_internal_flags = 1;
  }
}

static const LuaClassMetadata *find_lua_class_metadata_by_address(uintptr_t address) {
  if (!address) {
    return 0;
  }
  for (size_t i = 0; i < lua_class_metadata_count; ++i) {
    if (lua_class_metadata[i].address == address) {
      return &lua_class_metadata[i];
    }
  }
  return 0;
}

static void record_lua_class_metadata(uintptr_t address, uintptr_t super_address, const char *name) {
  if (!address) {
    return;
  }
  for (size_t i = 0; i < lua_class_metadata_count; ++i) {
    LuaClassMetadata *metadata = &lua_class_metadata[i];
    if (metadata->address != address) {
      continue;
    }
    if (super_address) {
      metadata->super_address = super_address;
    }
    if (name && name[0]) {
      copy_string(metadata->name, sizeof(metadata->name), name);
    }
    return;
  }
  if (lua_class_metadata_count >= MAX_LUA_CLASS_METADATA) {
    return;
  }
  LuaClassMetadata *metadata = &lua_class_metadata[lua_class_metadata_count++];
  for (size_t i = 0; i < sizeof(*metadata); ++i) {
    ((unsigned char *)metadata)[i] = 0;
  }
  metadata->address = address;
  metadata->super_address = super_address;
  if (name && name[0]) {
    copy_string(metadata->name, sizeof(metadata->name), name);
  }
}

static void seed_lua_object_handles(void) {
  lua_object_handle_count = 0;
  if (add_lua_object_handle(
        "/Script/UE4SSLProbe.SelfTestObject",
        "SelfTestObject",
        "UE4SSLProbeSelfTestClass",
        (uintptr_t)&ue_self_test_object
      )) {
    LuaObjectHandle *object = &lua_object_handles[lua_object_handle_count - 1];
    object->internal_flags = UE_INTERNAL_OBJECT_FLAG_NATIVE;
    object->has_internal_flags = 1;
  }
  for (size_t i = 0; i < ue_candidate_object_handle_count; ++i) {
    const LuaObjectHandle *candidate = &ue_candidate_object_handles[i];
    if (add_lua_object_handle(candidate->path, candidate->name, candidate->class_name, candidate->address)) {
      LuaObjectHandle *object = &lua_object_handles[lua_object_handle_count - 1];
      object->class_address = candidate->class_address;
      object->outer_address = candidate->outer_address;
      object->super_address = candidate->super_address;
      object->object_flags = candidate->object_flags;
      object->internal_index = candidate->internal_index;
      object->has_object_metadata = candidate->has_object_metadata;
      object->internal_flags = candidate->internal_flags;
      object->has_internal_flags = candidate->has_internal_flags;
      object->function_flags = candidate->function_flags;
      object->has_function_flags = candidate->has_function_flags;
    }
  }
}

static const LuaObjectHandle *find_lua_object_by_path_or_name(const char *query) {
  if (!query || !query[0]) {
    return 0;
  }
  for (size_t i = 0; i < lua_object_handle_count; ++i) {
    const LuaObjectHandle *object = &lua_object_handles[i];
    if (str_equal(object->path, query) || str_equal(object->name, query)) {
      return object;
    }
  }
  return 0;
}

static const LuaObjectHandle *find_lua_object_by_class(const char *class_name) {
  if (!class_name || !class_name[0]) {
    return 0;
  }
  for (size_t i = 0; i < lua_object_handle_count; ++i) {
    const LuaObjectHandle *object = &lua_object_handles[i];
    if (str_equal(object->class_name, class_name)) {
      return object;
    }
  }
  return 0;
}

static const LuaObjectHandle *find_lua_object_by_address(uintptr_t address) {
  if (!address) {
    return 0;
  }
  for (size_t i = 0; i < lua_object_handle_count; ++i) {
    const LuaObjectHandle *object = &lua_object_handles[i];
    if (object->address == address) {
      return object;
    }
  }
  return 0;
}

static int lua_object_handle_is_world_like(const LuaObjectHandle *object) {
  if (!object) {
    return 0;
  }
  return str_equal(object->name, "GWorld") ||
         contains_ci(object->path, "/GWorld") ||
         contains_ci(object->class_name, "World");
}

static int lua_object_handle_is_level_like(const LuaObjectHandle *object) {
  if (!object) {
    return 0;
  }
  return str_equal(object->name, "PersistentLevel") ||
         contains_ci(object->path, "/PersistentLevel") ||
         contains_ci(object->class_name, "Level");
}

static int lua_object_class_has_world_context(const char *class_name) {
  return class_name && (
    contains_ci(class_name, "Actor") ||
    contains_ci(class_name, "Component") ||
    contains_ci(class_name, "Controller") ||
    contains_ci(class_name, "Pawn") ||
    contains_ci(class_name, "Player") ||
    contains_ci(class_name, "GameMode") ||
    contains_ci(class_name, "GameState") ||
    contains_ci(class_name, "GameInstance") ||
    contains_ci(class_name, "Level") ||
    contains_ci(class_name, "World") ||
    contains_ci(class_name, "Subsystem")
  );
}

static const LuaObjectHandle *find_lua_registered_world_handle(void) {
  const LuaObjectHandle *fallback = 0;
  for (size_t i = 0; i < lua_object_handle_count; ++i) {
    const LuaObjectHandle *object = &lua_object_handles[i];
    if (str_equal(object->name, "GWorld") || contains_ci(object->path, "/GWorld")) {
      return object;
    }
    if (!fallback && lua_object_handle_is_world_like(object)) {
      fallback = object;
    }
  }
  return fallback;
}

static const LuaObjectHandle *find_lua_world_from_outer_chain(uintptr_t outer_address) {
  for (size_t depth = 0; depth < 16 && outer_address; ++depth) {
    const LuaObjectHandle *outer = find_lua_object_by_address(outer_address);
    if (!outer) {
      return 0;
    }
    if (lua_object_handle_is_world_like(outer)) {
      return outer;
    }
    outer_address = outer->outer_address;
  }
  return 0;
}

static const LuaObjectHandle *find_lua_level_from_outer_chain(uintptr_t outer_address) {
  for (size_t depth = 0; depth < 16 && outer_address; ++depth) {
    const LuaObjectHandle *outer = find_lua_object_by_address(outer_address);
    if (!outer) {
      return 0;
    }
    if (lua_object_handle_is_level_like(outer)) {
      return outer;
    }
    outer_address = outer->outer_address;
  }
  return 0;
}

static const LuaObjectHandle *find_lua_class_default_object(const char *class_name, uintptr_t class_address) {
  if (!class_name || !class_name[0]) {
    return 0;
  }
  for (size_t i = 0; i < lua_object_handle_count; ++i) {
    const LuaObjectHandle *object = &lua_object_handles[i];
    if ((object->object_flags & 0x00000010u) == 0) {
      continue;
    }
    if (class_address && object->class_address && object->class_address == class_address) {
      return object;
    }
    if (str_equal(object->class_name, class_name)) {
      return object;
    }
  }
  return 0;
}

static const LuaObjectHandle *find_or_add_lua_class_default_object(const char *class_name, uintptr_t class_address) {
  const LuaObjectHandle *existing = find_lua_class_default_object(class_name, class_address);
  if (existing) {
    return existing;
  }
  if (!class_name || !class_name[0] || lua_object_handle_count >= MAX_LUA_OBJECT_HANDLES) {
    return 0;
  }
  char name[MAX_LUA_OBJECT_NAME];
  char path[MAX_LUA_OBJECT_PATH];
  copy_string(name, sizeof(name), "Default__");
  size_t used = cstr_len(name);
  if (used < sizeof(name)) {
    copy_string(name + used, sizeof(name) - used, class_name);
  }
  copy_string(path, sizeof(path), "/RuntimeProbe/CDO/");
  used = cstr_len(path);
  if (used < sizeof(path)) {
    copy_string(path + used, sizeof(path) - used, class_name);
  }
  uintptr_t address = (uintptr_t)&lua_object_handles[lua_object_handle_count];
  if (!add_lua_object_handle(path, name, class_name, address)) {
    return 0;
  }
  LuaObjectHandle *object = &lua_object_handles[lua_object_handle_count - 1];
  object->class_address = class_address;
  object->object_flags = 0x00000010u;
  object->internal_index = -1;
  object->has_object_metadata = 1;
  return object;
}

static const char *lua_object_lookup_query_arg(LuaState *state) {
  if (!active_lua_api || !state || !active_lua_api->to_lstring) {
    return 0;
  }
  const char *query = 0;
  for (int i = 1; i <= 4; ++i) {
    const char *candidate = active_lua_api->to_lstring(state, i, 0);
    if (candidate && candidate[0]) {
      query = candidate;
    }
  }
  return query;
}

static int lua_object_class_matches(const LuaObjectHandle *object, const char *class_name) {
  if (!object || !class_name || !class_name[0]) {
    return 1;
  }
  return str_equal(class_name, "UObject") || str_equal(object->class_name, class_name);
}

static void reset_ue_reflection_property_candidates(void) {
  ue_reflection_property_candidate_count = 0;
  ue_function_param_descriptor_count = 0;
}

static void append_unsigned_to_buffer(char *dst, size_t dst_size, unsigned long long value) {
  if (!dst || dst_size == 0) {
    return;
  }
  size_t used = cstr_len(dst);
  if (used + 1 >= dst_size) {
    return;
  }
  char digits[32];
  size_t count = 0;
  do {
    digits[count++] = (char)('0' + (value % 10ULL));
    value /= 10ULL;
  } while (value && count < sizeof(digits));
  while (count && used + 1 < dst_size) {
    dst[used++] = digits[--count];
  }
  dst[used] = '\0';
}

static void make_ue_reflection_property_name(char *out, size_t out_size, const char *chain_name, size_t index) {
  if (!out || out_size == 0) {
    return;
  }
  copy_string(out, out_size, chain_name && chain_name[0] ? chain_name : "property");
  size_t used = cstr_len(out);
  if (used + 1 < out_size) {
    out[used++] = '[';
    out[used] = '\0';
  }
  append_unsigned_to_buffer(out, out_size, (unsigned long long)index);
  used = cstr_len(out);
  if (used + 1 < out_size) {
    out[used++] = ']';
    out[used] = '\0';
  }
}

static void make_ue_function_identity(
  char *name_out,
  size_t name_out_size,
  char *path_out,
  size_t path_out_size,
  const char *owner_name,
  size_t function_index,
  const char *decoded_name
) {
  if (name_out && name_out_size > 0) {
    if (decoded_name && decoded_name[0]) {
      copy_string(name_out, name_out_size, decoded_name);
    } else {
      static Line name_line;
      line_init(&name_line);
      line_append(&name_line, "Function_");
      line_append_dec(&name_line, function_index);
      copy_string(name_out, name_out_size, name_line.text);
    }
  }
  if (path_out && path_out_size > 0) {
    static Line path_line;
    line_init(&path_line);
    line_append(&path_line, "/RuntimeProbe/");
    line_append(&path_line, owner_name && owner_name[0] ? owner_name : "Unknown");
    line_append_char(&path_line, '.');
    line_append(&path_line, name_out && name_out[0] ? name_out : "Function");
    line_append(&path_line, ":Function");
    copy_string(path_out, path_out_size, path_line.text);
  }
}

static void add_ue_reflection_property_candidate(
  uintptr_t object,
  const char *chain_name,
  size_t index,
  const char *field_name,
  int32_t array_dim,
  int32_t element_size,
  int32_t offset_internal,
  size_t read_bytes,
  uint64_t raw_le
) {
  if (object == 0 || ue_reflection_property_candidate_count >= MAX_UE_REFLECTION_PROPERTY_CANDIDATES ||
      array_dim != 1 || (element_size != 1 && element_size != 2 && element_size != 4 && element_size != 8) ||
      read_bytes < (size_t)element_size || offset_internal < 0) {
    return;
  }
  UeReflectionPropertyCandidate *candidate = &ue_reflection_property_candidates[ue_reflection_property_candidate_count++];
  candidate->object = object;
  make_ue_reflection_property_name(candidate->property_name, sizeof(candidate->property_name), chain_name, index);
  copy_string(candidate->field_name, sizeof(candidate->field_name), field_name && field_name[0] ? field_name : "");
  candidate->offset_internal = offset_internal;
  candidate->element_size = element_size;
  candidate->array_dim = array_dim;
  candidate->read_bytes = read_bytes;
  candidate->raw_le = raw_le;
}

static const char *ue_param_scalar_type(int32_t element_size) {
  switch (element_size) {
    case 1:
      return "uint8";
    case 2:
      return "uint16";
    case 4:
      return "int32";
    case 8:
      return "int64";
    default:
      return "unknown";
  }
}

static const char *ue_param_class_name_or_default(const char *class_name) {
  return class_name && class_name[0] ? class_name : "FProperty";
}

static const char *ue_param_value_type(const char *class_name, int32_t element_size) {
  const char *resolved_class = ue_param_class_name_or_default(class_name);
  if (contains_ci(resolved_class, "BoolProperty")) {
    return "bool";
  }
  if (contains_ci(resolved_class, "ObjectProperty") ||
      contains_ci(resolved_class, "ClassProperty") ||
      contains_ci(resolved_class, "InterfaceProperty")) {
    return "object";
  }
  if (contains_ci(resolved_class, "StrProperty") || contains_ci(resolved_class, "TextProperty")) {
    return "string";
  }
  if (contains_ci(resolved_class, "NameProperty")) {
    return "fname";
  }
  if (contains_ci(resolved_class, "FloatProperty")) {
    return "float";
  }
  if (contains_ci(resolved_class, "DoubleProperty")) {
    return "double";
  }
  if (contains_ci(resolved_class, "ArrayProperty")) {
    return "array";
  }
  if (contains_ci(resolved_class, "StructProperty")) {
    return "struct";
  }
  if (contains_ci(resolved_class, "MapProperty")) {
    return "map";
  }
  if (contains_ci(resolved_class, "SetProperty")) {
    return "set";
  }
  return ue_param_scalar_type(element_size);
}

static int ue_param_descriptor_size_supported(const char *class_name, int32_t element_size) {
  const char *resolved_class = ue_param_class_name_or_default(class_name);
  if (element_size <= 0 || element_size > MAX_PROCESS_EVENT_PARAM_BYTES) {
    return 0;
  }
  if (contains_ci(resolved_class, "NameProperty")) {
    return element_size == (int32_t)sizeof(UeFNameValue);
  }
  if (contains_ci(resolved_class, "StrProperty")) {
    return element_size >= (int32_t)sizeof(UeFStringValue);
  }
  if (contains_ci(resolved_class, "FloatProperty")) {
    return element_size == 4;
  }
  if (contains_ci(resolved_class, "DoubleProperty")) {
    return element_size == 8;
  }
  if (contains_ci(resolved_class, "TextProperty") ||
      contains_ci(resolved_class, "ArrayProperty") ||
      contains_ci(resolved_class, "StructProperty") ||
      contains_ci(resolved_class, "MapProperty") ||
      contains_ci(resolved_class, "SetProperty")) {
    return element_size <= MAX_PROCESS_EVENT_PARAM_BYTES;
  }
  return element_size == 1 || element_size == 2 || element_size == 4 || element_size == 8;
}

static int lua_param_descriptor_is_bool(const LuaParamDescriptorView *descriptor) {
  return descriptor &&
         (contains_ci(descriptor->class_name, "BoolProperty") || contains_ci(descriptor->type, "bool"));
}

static int lua_param_descriptor_is_object(const LuaParamDescriptorView *descriptor) {
  return descriptor &&
         (contains_ci(descriptor->class_name, "ObjectProperty") ||
          contains_ci(descriptor->class_name, "ClassProperty") ||
          contains_ci(descriptor->class_name, "InterfaceProperty") ||
          contains_ci(descriptor->type, "object"));
}

static int lua_param_descriptor_is_fname(const LuaParamDescriptorView *descriptor) {
  return descriptor &&
         (contains_ci(descriptor->class_name, "NameProperty") || contains_ci(descriptor->type, "fname"));
}

static int lua_param_descriptor_is_string(const LuaParamDescriptorView *descriptor) {
  return descriptor &&
         (contains_ci(descriptor->class_name, "StrProperty") ||
          (!descriptor->class_name[0] && contains_ci(descriptor->type, "string")));
}

static int lua_param_descriptor_is_array(const LuaParamDescriptorView *descriptor) {
  return descriptor &&
         (contains_ci(descriptor->class_name, "ArrayProperty") ||
          contains_ci(descriptor->type, "array"));
}

static int lua_param_descriptor_is_set(const LuaParamDescriptorView *descriptor) {
  return descriptor &&
         (contains_ci(descriptor->class_name, "SetProperty") ||
          contains_ci(descriptor->type, "set"));
}

static int lua_param_descriptor_is_map(const LuaParamDescriptorView *descriptor) {
  return descriptor &&
         (contains_ci(descriptor->class_name, "MapProperty") ||
          contains_ci(descriptor->type, "map"));
}

static int lua_param_descriptor_is_container(const LuaParamDescriptorView *descriptor) {
  return lua_param_descriptor_is_array(descriptor) ||
         lua_param_descriptor_is_set(descriptor) ||
         lua_param_descriptor_is_map(descriptor);
}

static const char *lua_param_descriptor_container_kind(const LuaParamDescriptorView *descriptor) {
  if (lua_param_descriptor_is_array(descriptor)) {
    return "FScriptArray";
  }
  if (lua_param_descriptor_is_set(descriptor)) {
    return "FScriptSetHeader";
  }
  if (lua_param_descriptor_is_map(descriptor)) {
    return "FScriptMapHeader";
  }
  return "FScriptContainerHeader";
}

static int lua_param_descriptor_is_struct(const LuaParamDescriptorView *descriptor) {
  return descriptor &&
         (contains_ci(descriptor->class_name, "StructProperty") || contains_ci(descriptor->type, "struct") ||
          contains_ci(descriptor->type, "vector"));
}

static int lua_param_descriptor_is_vector_struct(const LuaParamDescriptorView *descriptor) {
  return lua_param_descriptor_is_struct(descriptor) &&
         (descriptor->size == sizeof(UeFVectorValue) || descriptor->size == sizeof(float) * 3);
}

static int lua_param_descriptor_is_float(const LuaParamDescriptorView *descriptor) {
  return descriptor &&
         (contains_ci(descriptor->class_name, "FloatProperty") || contains_ci(descriptor->type, "float"));
}

static int lua_param_descriptor_is_double(const LuaParamDescriptorView *descriptor) {
  return descriptor &&
         (contains_ci(descriptor->class_name, "DoubleProperty") || contains_ci(descriptor->type, "double"));
}

static int lua_param_descriptor_is_signed_integer(const LuaParamDescriptorView *descriptor) {
  if (!descriptor || lua_param_descriptor_is_bool(descriptor) || lua_param_descriptor_is_object(descriptor) ||
      lua_param_descriptor_is_float(descriptor) || lua_param_descriptor_is_double(descriptor)) {
    return 0;
  }
  if (contains_ci(descriptor->class_name, "UInt") ||
      contains_ci(descriptor->class_name, "ByteProperty") ||
      contains_ci(descriptor->type, "uint")) {
    return 0;
  }
  return contains_ci(descriptor->class_name, "Int") || contains_ci(descriptor->type, "int");
}

static int lua_param_descriptor_size_supported(const LuaParamDescriptorView *descriptor) {
  return descriptor && ue_param_descriptor_size_supported(descriptor->class_name, (int32_t)descriptor->size);
}

static void add_ue_function_param_descriptor(
  uintptr_t function,
  uintptr_t field,
  const char *owner_name,
  size_t function_index,
  const char *function_name,
  const char *chain_name,
  size_t index,
  const char *field_name,
  const char *class_name,
  int32_t array_dim,
  int32_t element_size,
  uint64_t property_flags,
  int32_t offset_internal,
  uint32_t function_flags,
  int function_flags_readable
) {
  if (function == 0 || field == 0 ||
      ue_function_param_descriptor_count >= MAX_UE_FUNCTION_PARAM_DESCRIPTORS ||
      array_dim <= 0 || array_dim > 1024 ||
      !ue_param_descriptor_size_supported(class_name, element_size) ||
      offset_internal < 0) {
    return;
  }
  for (size_t i = 0; i < ue_function_param_descriptor_count; ++i) {
    const UeFunctionParamDescriptor *existing = &ue_function_param_descriptors[i];
    if (existing->function == function && existing->field == field) {
      return;
    }
  }
  UeFunctionParamDescriptor *descriptor = &ue_function_param_descriptors[ue_function_param_descriptor_count++];
  for (size_t i = 0; i < sizeof(*descriptor); ++i) {
    ((unsigned char *)descriptor)[i] = 0;
  }
  descriptor->function = function;
  descriptor->field = field;
  make_ue_function_identity(
    descriptor->function_name,
    sizeof(descriptor->function_name),
    descriptor->function_path,
    sizeof(descriptor->function_path),
    owner_name,
    function_index,
    function_name
  );
  make_ue_reflection_property_name(descriptor->property_name, sizeof(descriptor->property_name), chain_name, index);
  copy_string(
    descriptor->field_name,
    sizeof(descriptor->field_name),
    field_name && field_name[0] ? field_name : descriptor->property_name
  );
  copy_string(
    descriptor->class_name,
    sizeof(descriptor->class_name),
    class_name && class_name[0] ? class_name : "FProperty"
  );
  copy_string(
    descriptor->chain_name,
    sizeof(descriptor->chain_name),
    chain_name && chain_name[0] ? chain_name : "params"
  );
  descriptor->index = index;
  descriptor->offset_internal = offset_internal;
  descriptor->element_size = element_size;
  descriptor->array_dim = array_dim;
  descriptor->property_flags = property_flags;
  descriptor->function_flags = function_flags;
  descriptor->function_flags_readable = function_flags_readable != 0;
}

static void set_ue_function_param_container_child_descriptor(
  uintptr_t function,
  uintptr_t field,
  const char *role,
  uintptr_t child,
  uintptr_t child_class,
  uintptr_t container_offset,
  const char *child_name,
  const char *child_class_name,
  int32_t child_array_dim,
  int32_t child_element_size,
  uint64_t child_property_flags,
  int32_t child_offset_internal
) {
  if (!function || !field || !child || !role || !role[0]) {
    return;
  }
  UeFunctionParamDescriptor *descriptor = NULL;
  for (size_t i = 0; i < ue_function_param_descriptor_count; ++i) {
    if (ue_function_param_descriptors[i].function == function &&
        ue_function_param_descriptors[i].field == field) {
      descriptor = &ue_function_param_descriptors[i];
      break;
    }
  }
  if (!descriptor) {
    return;
  }
  UeFunctionParamChildDescriptor *slot = NULL;
  for (size_t i = 0; i < descriptor->child_count && i < 2; ++i) {
    if (str_equal(descriptor->children[i].role, role) || descriptor->children[i].field == child) {
      slot = &descriptor->children[i];
      break;
    }
  }
  if (!slot) {
    if (descriptor->child_count >= 2) {
      return;
    }
    slot = &descriptor->children[descriptor->child_count++];
  }
  for (size_t i = 0; i < sizeof(*slot); ++i) {
    ((unsigned char *)slot)[i] = 0;
  }
  slot->present = 1;
  slot->field = child;
  slot->property_class = child_class;
  slot->container_offset = container_offset;
  copy_string(slot->role, sizeof(slot->role), role);
  copy_string(slot->name, sizeof(slot->name), child_name && child_name[0] ? child_name : role);
  copy_string(slot->class_name, sizeof(slot->class_name), child_class_name && child_class_name[0] ? child_class_name : "FProperty");
  copy_string(slot->type, sizeof(slot->type), ue_param_value_type(slot->class_name, child_element_size > 0 ? child_element_size : 0));
  slot->array_dim = child_array_dim > 0 ? child_array_dim : 1;
  slot->element_size = child_element_size > 0 ? child_element_size : 0;
  slot->property_flags = child_property_flags;
  slot->offset_internal = child_offset_internal >= 0 ? child_offset_internal : 0;
}

static int read_live_ue_reflection_property_candidate(const UeReflectionPropertyCandidate *candidate, long long *value) {
  if (!candidate || candidate->object == 0 || candidate->offset_internal < 0) {
    return 0;
  }
  uintptr_t address = candidate->object + (uintptr_t)candidate->offset_internal;
  if (address < candidate->object) {
    return 0;
  }
  MEMORY_BASIC_INFORMATION_WIN64 mbi;
  for (size_t i = 0; i < sizeof(mbi); ++i) {
    ((char *)&mbi)[i] = 0;
  }
  SIZE_T got = VirtualQuery((const void *)address, &mbi, sizeof(mbi));
  if (!got || mbi.State != MEM_COMMIT || !readable_protect(mbi.Protect)) {
    return 0;
  }
  uint64_t raw = 0;
  int ok = 0;
  if (candidate->element_size == 1) {
    if (region_contains_range(&mbi, address, 1)) {
      raw = *(const unsigned char *)address;
      ok = 1;
    }
  } else if (candidate->element_size == 2) {
    uint16_t read_value = 0;
    ok = read_u16_at(&mbi, address, &read_value);
    raw = read_value;
  } else if (candidate->element_size == 4) {
    uint32_t read_value = 0;
    ok = read_u32_at(&mbi, address, &read_value);
    raw = read_value;
  } else if (candidate->element_size == 8) {
    uint64_t read_value = 0;
    ok = read_u64_at(&mbi, address, &read_value);
    raw = read_value;
  }
  if (ok && value) {
    *value = (long long)raw;
  }
  return ok;
}

static int read_ue_reflection_property_candidate(uintptr_t object, const char *property_name, long long *value, int *matched_field_name) {
  if (object == 0 || !property_name || !property_name[0]) {
    return 0;
  }
  for (size_t i = 0; i < ue_reflection_property_candidate_count; ++i) {
    const UeReflectionPropertyCandidate *candidate = &ue_reflection_property_candidates[i];
    int named_match = candidate->field_name[0] && str_equal(candidate->field_name, property_name);
    if (candidate->object == object && (str_equal(candidate->property_name, property_name) || named_match)) {
      if (matched_field_name) {
        *matched_field_name = named_match;
      }
      return read_live_ue_reflection_property_candidate(candidate, value);
    }
  }
  return 0;
}

static int scalar_value_fits_property_size(int32_t element_size, long long value, uint64_t *raw) {
  if (value < 0) {
    return 0;
  }
  uint64_t unsigned_value = (uint64_t)value;
  if ((element_size == 1 && unsigned_value > 0xffULL) ||
      (element_size == 2 && unsigned_value > 0xffffULL) ||
      (element_size == 4 && unsigned_value > 0xffffffffULL) ||
      (element_size != 1 && element_size != 2 && element_size != 4 && element_size != 8)) {
    return 0;
  }
  if (raw) {
    *raw = unsigned_value;
  }
  return 1;
}

static int write_live_ue_reflection_property_candidate(const UeReflectionPropertyCandidate *candidate, long long value) {
  uint64_t raw = 0;
  if (!candidate || candidate->object == 0 || candidate->offset_internal < 0 ||
      !scalar_value_fits_property_size(candidate->element_size, value, &raw)) {
    return 0;
  }
  uintptr_t address = candidate->object + (uintptr_t)candidate->offset_internal;
  if (address < candidate->object) {
    return 0;
  }
  MEMORY_BASIC_INFORMATION_WIN64 mbi;
  for (size_t i = 0; i < sizeof(mbi); ++i) {
    ((char *)&mbi)[i] = 0;
  }
  SIZE_T got = VirtualQuery((const void *)address, &mbi, sizeof(mbi));
  if (!got || mbi.State != MEM_COMMIT || !writable_protect(mbi.Protect) ||
      !region_contains_range(&mbi, address, (size_t)candidate->element_size)) {
    return 0;
  }
  unsigned char *dest = (unsigned char *)address;
  unsigned char *source = (unsigned char *)&raw;
  for (size_t i = 0; i < (size_t)candidate->element_size; ++i) {
    dest[i] = source[i];
  }
  return 1;
}

static int write_ue_reflection_property_candidate(uintptr_t object, const char *property_name, long long value) {
  if (object == 0 || !property_name || !property_name[0]) {
    return 0;
  }
  for (size_t i = 0; i < ue_reflection_property_candidate_count; ++i) {
    const UeReflectionPropertyCandidate *candidate = &ue_reflection_property_candidates[i];
    if (candidate->object == object &&
        (str_equal(candidate->property_name, property_name) ||
         (candidate->field_name[0] && str_equal(candidate->field_name, property_name)))) {
      return write_live_ue_reflection_property_candidate(candidate, value);
    }
  }
  return 0;
}

static uintptr_t lua_object_address_arg(LuaApi *api, LuaState *state, int index);
static uintptr_t lua_object_uintptr_field_arg(LuaApi *api, LuaState *state, int index, const char *field);
static int push_remote_unreal_param_for_process_descriptor(
  LuaApi *api,
  LuaState *state,
  uintptr_t params,
  const ProcessEventParamDescriptor *descriptor
);
static int push_remote_unreal_param_for_ue_descriptor(
  LuaApi *api,
  LuaState *state,
  uintptr_t params,
  const UeFunctionParamDescriptor *descriptor
);
static int CDECL lua_is_a_callback(LuaState *state);
static int CDECL lua_get_property_value_callback(LuaState *state);
static int CDECL lua_set_property_value_callback(LuaState *state);
static int CDECL lua_call_function_callback(LuaState *state);
static int CDECL lua_object_get_full_name_callback(LuaState *state);
static int CDECL lua_object_get_name_callback(LuaState *state);
static int CDECL lua_object_get_path_name_callback(LuaState *state);
static int CDECL lua_object_get_address_callback(LuaState *state);
static int CDECL lua_object_is_valid_callback(LuaState *state);
static int CDECL lua_object_get_class_callback(LuaState *state);
static int CDECL lua_object_get_outer_callback(LuaState *state);
static int CDECL lua_object_type_callback(LuaState *state);
static int CDECL lua_object_is_class_callback(LuaState *state);
static int CDECL lua_object_is_any_class_callback(LuaState *state);
static int CDECL lua_object_get_fname_callback(LuaState *state);
static int CDECL lua_object_get_world_callback(LuaState *state);
static int CDECL lua_object_reflection_callback(LuaState *state);
static int CDECL lua_object_has_all_flags_callback(LuaState *state);
static int CDECL lua_object_has_any_flags_callback(LuaState *state);
static int CDECL lua_object_has_any_internal_flags_callback(LuaState *state);
static int CDECL lua_object_process_console_exec_callback(LuaState *state);
static int CDECL lua_object_local_player_exec_callback(LuaState *state);
static int CDECL lua_function_get_function_flags_callback(LuaState *state);
static int CDECL lua_function_set_function_flags_callback(LuaState *state);
static int CDECL lua_struct_get_super_struct_callback(LuaState *state);
static int CDECL lua_struct_for_each_function_callback(LuaState *state);
static int CDECL lua_struct_for_each_property_callback(LuaState *state);
static int CDECL lua_class_get_cdo_callback(LuaState *state);
static int CDECL lua_class_is_child_of_callback(LuaState *state);
static int CDECL lua_actor_get_level_callback(LuaState *state);
static int CDECL lua_fname_to_string_callback(LuaState *state);
static int CDECL lua_fname_get_comparison_index_callback(LuaState *state);
static int CDECL lua_fname_type_callback(LuaState *state);
static int CDECL lua_reflection_get_property_callback(LuaState *state);
static int CDECL lua_reflection_type_callback(LuaState *state);
static int CDECL lua_property_get_full_name_callback(LuaState *state);
static int CDECL lua_property_get_fname_callback(LuaState *state);
static int CDECL lua_property_is_a_callback(LuaState *state);
static int CDECL lua_property_get_class_callback(LuaState *state);
static int CDECL lua_property_container_ptr_to_value_ptr_callback(LuaState *state);
static int CDECL lua_property_get_value_callback(LuaState *state);
static int CDECL lua_property_set_value_callback(LuaState *state);
static int CDECL lua_property_import_text_callback(LuaState *state);
static int CDECL lua_property_export_text_callback(LuaState *state);
static int CDECL lua_property_get_offset_internal_callback(LuaState *state);
static int CDECL lua_property_get_element_size_callback(LuaState *state);
static int CDECL lua_property_get_size_callback(LuaState *state);
static int CDECL lua_property_get_array_dim_callback(LuaState *state);
static int CDECL lua_property_get_property_flags_callback(LuaState *state);
static int CDECL lua_property_has_any_property_flags_callback(LuaState *state);
static int CDECL lua_property_get_property_class_callback(LuaState *state);
static int CDECL lua_bool_property_get_byte_mask_callback(LuaState *state);
static int CDECL lua_bool_property_get_byte_offset_callback(LuaState *state);
static int CDECL lua_bool_property_get_field_mask_callback(LuaState *state);
static int CDECL lua_bool_property_get_field_size_callback(LuaState *state);
static int CDECL lua_struct_property_get_struct_callback(LuaState *state);
static int CDECL lua_array_property_get_inner_callback(LuaState *state);
static int CDECL lua_enum_property_get_enum_callback(LuaState *state);
static int CDECL lua_enum_property_get_underlying_property_callback(LuaState *state);
static int CDECL lua_set_property_get_element_property_callback(LuaState *state);
static int CDECL lua_map_property_get_key_property_callback(LuaState *state);
static int CDECL lua_map_property_get_value_property_callback(LuaState *state);
static int CDECL lua_property_type_callback(LuaState *state);
static int CDECL lua_remote_unreal_param_get_callback(LuaState *state);
static int CDECL lua_remote_unreal_param_set_callback(LuaState *state);
static int CDECL lua_remote_unreal_param_type_callback(LuaState *state);
static int CDECL lua_script_array_get_num_callback(LuaState *state);
static int CDECL lua_script_array_get_data_callback(LuaState *state);
static int CDECL lua_script_array_get_data_sample_bytes_callback(LuaState *state);
static int CDECL lua_script_array_get_raw_element_callback(LuaState *state);
static int CDECL lua_script_array_get_element_callback(LuaState *state);
static int push_process_event_object_param_or_nil(LuaApi *api, LuaState *state, uintptr_t address);
static int push_process_event_fname_param_or_nil(LuaApi *api, LuaState *state, const UeFNameValue *value);
static int lua_table_string_field(LuaApi *api, LuaState *state, int index, const char *field, char *out, size_t out_size);
static int push_lua_fname_table(
  LuaApi *api,
  LuaState *state,
  const char *name,
  long long comparison_index,
  long long number,
  int decoded
);
static int push_lua_ftext_table(LuaApi *api, LuaState *state, const char *text);
static int push_lua_fvector_struct_handle(LuaApi *api, LuaState *state);

static void set_lua_object_method(LuaApi *api, LuaState *state, const char *name, LuaCFunction callback) {
  if (!api || !state || !name || !callback || !api->push_cclosure || !api->set_field) {
    return;
  }
  api->push_cclosure(state, callback, 0);
  api->set_field(state, -2, name);
}

static void lua_copy_join(char *out, size_t out_size, const char *a, const char *b, const char *c) {
  if (!out || out_size == 0) {
    return;
  }
  copy_string(out, out_size, a ? a : "");
  size_t used = cstr_len(out);
  if (used < out_size) {
    copy_string(out + used, out_size - used, b ? b : "");
  }
  used = cstr_len(out);
  if (used < out_size) {
    copy_string(out + used, out_size - used, c ? c : "");
  }
}

static int push_lua_object_handle(LuaApi *api, LuaState *state, const LuaObjectHandle *object) {
  if (!api || !state || !object || !api->create_table || !api->push_string || !api->push_integer ||
      !api->push_boolean || !api->set_field || !api->push_cclosure) {
    return 0;
  }
  api->create_table(state, 0, 31);
  api->push_string(state, object->path);
  api->set_field(state, -2, "PathName");
  api->push_string(state, object->name);
  api->set_field(state, -2, "Name");
  api->push_string(state, object->class_name);
  api->set_field(state, -2, "ClassName");
  api->push_integer(state, (long long)object->address);
  api->set_field(state, -2, "Address");
  api->push_integer(state, (long long)object->class_address);
  api->set_field(state, -2, "ClassAddress");
  api->push_integer(state, (long long)object->outer_address);
  api->set_field(state, -2, "OuterAddress");
  api->push_integer(state, (long long)object->super_address);
  api->set_field(state, -2, "SuperAddress");
  api->push_integer(state, (long long)object->object_flags);
  api->set_field(state, -2, "ObjectFlags");
  api->push_integer(state, (long long)object->internal_index);
  api->set_field(state, -2, "InternalIndex");
  api->push_boolean(state, object->has_object_metadata != 0);
  api->set_field(state, -2, "HasObjectMetadata");
  api->push_integer(state, (long long)object->internal_flags);
  api->set_field(state, -2, "InternalFlags");
  api->push_boolean(state, object->has_internal_flags != 0);
  api->set_field(state, -2, "HasInternalFlags");
  api->push_integer(state, (long long)object->function_flags);
  api->set_field(state, -2, "FunctionFlags");
  api->push_boolean(state, object->has_function_flags != 0);
  api->set_field(state, -2, "HasFunctionFlags");
  api->push_boolean(state, object->address != 0);
  api->set_field(state, -2, "Valid");
  api->push_string(state, "probe-registry");
  api->set_field(state, -2, "Source");
  set_lua_object_method(api, state, "GetFullName", lua_object_get_full_name_callback);
  set_lua_object_method(api, state, "GetName", lua_object_get_name_callback);
  set_lua_object_method(api, state, "GetPathName", lua_object_get_path_name_callback);
  set_lua_object_method(api, state, "GetAddress", lua_object_get_address_callback);
  set_lua_object_method(api, state, "IsValid", lua_object_is_valid_callback);
  set_lua_object_method(api, state, "GetClass", lua_object_get_class_callback);
  set_lua_object_method(api, state, "GetOuter", lua_object_get_outer_callback);
  set_lua_object_method(api, state, "type", lua_object_type_callback);
  set_lua_object_method(api, state, "IsClass", lua_object_is_class_callback);
  set_lua_object_method(api, state, "IsAnyClass", lua_object_is_any_class_callback);
  set_lua_object_method(api, state, "GetFName", lua_object_get_fname_callback);
  set_lua_object_method(api, state, "GetWorld", lua_object_get_world_callback);
  set_lua_object_method(api, state, "Reflection", lua_object_reflection_callback);
  set_lua_object_method(api, state, "IsA", lua_is_a_callback);
  set_lua_object_method(api, state, "HasAllFlags", lua_object_has_all_flags_callback);
  set_lua_object_method(api, state, "HasAnyFlags", lua_object_has_any_flags_callback);
  set_lua_object_method(api, state, "HasAnyInternalFlags", lua_object_has_any_internal_flags_callback);
  set_lua_object_method(api, state, "GetPropertyValue", lua_get_property_value_callback);
  set_lua_object_method(api, state, "SetPropertyValue", lua_set_property_value_callback);
  set_lua_object_method(api, state, "CallFunction", lua_call_function_callback);
  set_lua_object_method(api, state, "ProcessConsoleExec", lua_object_process_console_exec_callback);
  set_lua_object_method(api, state, "ULocalPlayerExec", lua_object_local_player_exec_callback);
  set_lua_object_method(api, state, "GetFunctionFlags", lua_function_get_function_flags_callback);
  set_lua_object_method(api, state, "SetFunctionFlags", lua_function_set_function_flags_callback);
  set_lua_object_method(api, state, "GetSuperStruct", lua_struct_get_super_struct_callback);
  set_lua_object_method(api, state, "ForEachFunction", lua_struct_for_each_function_callback);
  set_lua_object_method(api, state, "ForEachProperty", lua_struct_for_each_property_callback);
  set_lua_object_method(api, state, "GetCDO", lua_class_get_cdo_callback);
  set_lua_object_method(api, state, "IsChildOf", lua_class_is_child_of_callback);
  set_lua_object_method(api, state, "GetLevel", lua_actor_get_level_callback);
  return 1;
}

static int push_lua_fvector_struct_handle(LuaApi *api, LuaState *state) {
  if (!api || !state) {
    return 0;
  }
  LuaObjectHandle synthetic;
  for (size_t i = 0; i < sizeof(synthetic); ++i) {
    ((unsigned char *)&synthetic)[i] = 0;
  }
  copy_string(synthetic.path, sizeof(synthetic.path), "/Script/CoreUObject.Vector");
  copy_string(synthetic.name, sizeof(synthetic.name), "Vector");
  copy_string(synthetic.class_name, sizeof(synthetic.class_name), "UScriptStruct");
  synthetic.address = (uintptr_t)&ue_self_test_fvector_script_struct_anchor;
  synthetic.class_address = (uintptr_t)&ue_self_test_class;
  synthetic.has_object_metadata = 1;
  return push_lua_object_handle(api, state, &synthetic);
}

static int push_known_lua_object_handles(
  LuaApi *api,
  LuaState *state,
  const char *class_filter,
  size_t *out_count
) {
  if (!api || !state || !api->create_table || !api->set_field || !api->push_integer) {
    return 0;
  }
  api->create_table(state, 0, (int)lua_object_handle_count + 1);
  size_t count = 0;
  for (size_t i = 0; i < lua_object_handle_count; ++i) {
    const LuaObjectHandle *object = &lua_object_handles[i];
    if (!lua_object_class_matches(object, class_filter)) {
      continue;
    }
    if (push_lua_object_handle(api, state, object)) {
      api->set_field(state, -2, object->path);
      ++count;
    }
  }
  api->push_integer(state, (long long)count);
  api->set_field(state, -2, "Count");
  if (out_count) {
    *out_count = count;
  }
  return 1;
}

static size_t count_ue_function_param_descriptors(uintptr_t function);
static const UeFunctionParamDescriptor *find_ue_function_descriptor(uintptr_t function);
static const UeFunctionParamDescriptor *find_ue_function_descriptor_by_path_or_name(const char *query);

static int push_ue_function_handle_from_descriptor(
  LuaApi *api,
  LuaState *state,
  const UeFunctionParamDescriptor *descriptor
) {
  if (!descriptor) {
    return 0;
  }
  LuaObjectHandle synthetic;
  for (size_t i = 0; i < sizeof(synthetic); ++i) {
    ((unsigned char *)&synthetic)[i] = 0;
  }
  copy_string(
    synthetic.path,
    sizeof(synthetic.path),
    descriptor->function_path[0] ? descriptor->function_path : "/RuntimeProbe/UFunction"
  );
  copy_string(
    synthetic.name,
    sizeof(synthetic.name),
    descriptor->function_name[0] ? descriptor->function_name : "UFunction"
  );
  copy_string(synthetic.class_name, sizeof(synthetic.class_name), "UFunction");
  synthetic.address = descriptor->function;
  synthetic.function_flags = descriptor->function_flags;
  synthetic.has_function_flags = descriptor->function_flags_readable;
  return push_lua_object_handle(api, state, &synthetic);
}

static int push_process_event_context_handle_or_nil(LuaApi *api, LuaState *state, uintptr_t address) {
  if (!api || !state || !api->push_nil) {
    return 0;
  }
  const LuaObjectHandle *object = find_lua_object_by_address(address);
  if (object && push_lua_object_handle(api, state, object)) {
    return 2;
  }
  const UeFunctionParamDescriptor *function_descriptor = find_ue_function_descriptor(address);
  if (function_descriptor) {
    LuaObjectHandle synthetic;
    for (size_t i = 0; i < sizeof(synthetic); ++i) {
      ((unsigned char *)&synthetic)[i] = 0;
    }
    copy_string(
      synthetic.path,
      sizeof(synthetic.path),
      function_descriptor->function_path[0] ? function_descriptor->function_path : "/RuntimeProbe/UFunction"
    );
    copy_string(
      synthetic.name,
      sizeof(synthetic.name),
      function_descriptor->function_name[0] ? function_descriptor->function_name : "UFunction"
    );
    copy_string(synthetic.class_name, sizeof(synthetic.class_name), "UFunction");
    synthetic.address = address;
    synthetic.function_flags = function_descriptor->function_flags;
    synthetic.has_function_flags = function_descriptor->function_flags_readable;
    if (push_lua_object_handle(api, state, &synthetic)) {
      return 2;
    }
  }
  if (address == (uintptr_t)&lua_hook_registration_name[0] && lua_hook_registration_name[0]) {
    LuaObjectHandle synthetic;
    for (size_t i = 0; i < sizeof(synthetic); ++i) {
      ((unsigned char *)&synthetic)[i] = 0;
    }
    copy_string(synthetic.path, sizeof(synthetic.path), lua_hook_registration_name);
    copy_string(synthetic.name, sizeof(synthetic.name), path_basename_win(lua_hook_registration_name));
    copy_string(synthetic.class_name, sizeof(synthetic.class_name), "UFunction");
    synthetic.address = address;
    if (push_lua_object_handle(api, state, &synthetic)) {
      return 2;
    }
  }
  api->push_nil(state);
  return 1;
}

static int push_lua_property_descriptor(
  LuaApi *api,
  LuaState *state,
  const char *owner_path,
  uintptr_t owner_address,
  const char *name,
  const char *class_name,
  const char *type,
  long long offset,
  long long size,
  long long property_flags,
  uintptr_t property_address,
  const char *source
);

static int push_process_event_param_descriptor(
  LuaApi *api,
  LuaState *state,
  const ProcessEventParamDescriptor *descriptor
) {
  if (!api || !state || !descriptor || !api->create_table || !api->push_string ||
      !api->push_integer || !api->push_boolean || !api->set_field) {
    return 0;
  }
  api->create_table(state, 0, 12);
  api->push_string(state, descriptor->name);
  api->set_field(state, -2, "Name");
  char path[MAX_LUA_OBJECT_PATH];
  lua_copy_join(path, sizeof(path), "/RuntimeProbe/ProcessEventParams/", descriptor->name, "");
  api->push_string(state, path);
  api->set_field(state, -2, "PathName");
  api->push_string(state, descriptor->type);
  api->set_field(state, -2, "Type");
  api->push_string(state, descriptor->class_name);
  api->set_field(state, -2, "ClassName");
  api->push_string(state, "process-event-param");
  api->set_field(state, -2, "Source");
  api->push_integer(state, (long long)descriptor->offset);
  api->set_field(state, -2, "Address");
  api->push_integer(state, 0);
  api->set_field(state, -2, "OwnerAddress");
  api->push_integer(state, (long long)descriptor->offset);
  api->set_field(state, -2, "Offset");
  api->push_integer(state, (long long)descriptor->offset);
  api->set_field(state, -2, "OffsetInternal");
  api->push_integer(state, (long long)descriptor->size);
  api->set_field(state, -2, "Size");
  api->push_integer(state, (long long)descriptor->size);
  api->set_field(state, -2, "ElementSize");
  api->push_integer(state, 1);
  api->set_field(state, -2, "ArrayDim");
  api->push_integer(state, UE_PROPERTY_FLAG_PARM);
  api->set_field(state, -2, "PropertyFlags");
  api->push_boolean(state, 1);
  api->set_field(state, -2, "IsParm");
  api->push_boolean(state, 0);
  api->set_field(state, -2, "IsOutParm");
  api->push_boolean(state, 0);
  api->set_field(state, -2, "IsReturnParm");
  if (contains_ci(descriptor->class_name, "StructProperty") && contains_ci(descriptor->type, "vector")) {
    api->push_string(state, "Vector");
    api->set_field(state, -2, "StructName");
    api->push_string(state, "/Script/CoreUObject.Vector");
    api->set_field(state, -2, "StructPath");
    api->push_integer(state, (long long)(uintptr_t)&ue_self_test_fvector_script_struct_anchor);
    api->set_field(state, -2, "StructAddress");
  }
  set_lua_object_method(api, state, "GetFullName", lua_property_get_full_name_callback);
  set_lua_object_method(api, state, "GetFName", lua_property_get_fname_callback);
  set_lua_object_method(api, state, "IsA", lua_property_is_a_callback);
  set_lua_object_method(api, state, "GetClass", lua_property_get_class_callback);
  set_lua_object_method(api, state, "ContainerPtrToValuePtr", lua_property_container_ptr_to_value_ptr_callback);
  set_lua_object_method(api, state, "GetValue", lua_property_get_value_callback);
  set_lua_object_method(api, state, "SetValue", lua_property_set_value_callback);
  set_lua_object_method(api, state, "ImportText", lua_property_import_text_callback);
  set_lua_object_method(api, state, "ExportText", lua_property_export_text_callback);
  set_lua_object_method(api, state, "ExportTextItem", lua_property_export_text_callback);
  set_lua_object_method(api, state, "GetOffset_Internal", lua_property_get_offset_internal_callback);
  set_lua_object_method(api, state, "GetOffsetInternal", lua_property_get_offset_internal_callback);
  set_lua_object_method(api, state, "GetElementSize", lua_property_get_element_size_callback);
  set_lua_object_method(api, state, "GetSize", lua_property_get_size_callback);
  set_lua_object_method(api, state, "GetArrayDim", lua_property_get_array_dim_callback);
  set_lua_object_method(api, state, "GetPropertyFlags", lua_property_get_property_flags_callback);
  set_lua_object_method(api, state, "HasAnyPropertyFlags", lua_property_has_any_property_flags_callback);
  set_lua_object_method(api, state, "GetPropertyClass", lua_property_get_property_class_callback);
  set_lua_object_method(api, state, "GetByteMask", lua_bool_property_get_byte_mask_callback);
  set_lua_object_method(api, state, "GetByteOffset", lua_bool_property_get_byte_offset_callback);
  set_lua_object_method(api, state, "GetFieldMask", lua_bool_property_get_field_mask_callback);
  set_lua_object_method(api, state, "GetFieldSize", lua_bool_property_get_field_size_callback);
  set_lua_object_method(api, state, "GetStruct", lua_struct_property_get_struct_callback);
  set_lua_object_method(api, state, "GetInner", lua_array_property_get_inner_callback);
  set_lua_object_method(api, state, "type", lua_property_type_callback);
  return 1;
}

static void set_ue_function_param_child_fields(
  LuaApi *api,
  LuaState *state,
  const UeFunctionParamChildDescriptor *child
) {
  if (!api || !state || !child || !child->present) {
    return;
  }
  const char *prefix = NULL;
  if (str_equal(child->role, "inner")) {
    prefix = "Inner";
  } else if (str_equal(child->role, "element")) {
    prefix = "Element";
  } else if (str_equal(child->role, "key")) {
    prefix = "Key";
  } else if (str_equal(child->role, "value")) {
    prefix = "Value";
  }
  if (!prefix) {
    return;
  }
  char field[64];
  lua_copy_join(field, sizeof(field), prefix, "Name", "");
  api->push_string(state, child->name);
  api->set_field(state, -2, field);
  lua_copy_join(field, sizeof(field), prefix, "ClassName", "");
  api->push_string(state, child->class_name);
  api->set_field(state, -2, field);
  lua_copy_join(field, sizeof(field), prefix, "Type", "");
  api->push_string(state, child->type);
  api->set_field(state, -2, field);
  lua_copy_join(field, sizeof(field), prefix, "ElementSize", "");
  api->push_integer(state, (long long)child->element_size);
  api->set_field(state, -2, field);
  lua_copy_join(field, sizeof(field), prefix, "Address", "");
  api->push_integer(state, (long long)child->field);
  api->set_field(state, -2, field);
  if (str_equal(child->role, "element")) {
    api->push_integer(state, (long long)child->element_size);
    api->set_field(state, -2, "ElementSize");
    api->push_integer(state, (long long)child->field);
    api->set_field(state, -2, "ElementAddress");
  }
}

static int push_ue_function_param_child_descriptor(
  LuaApi *api,
  LuaState *state,
  const UeFunctionParamDescriptor *owner,
  const UeFunctionParamChildDescriptor *child
) {
  if (!api || !state || !owner || !child || !child->present || !api->create_table ||
      !api->push_string || !api->push_integer || !api->set_field) {
    return 0;
  }
  char owner_path[MAX_LUA_OBJECT_PATH];
  lua_copy_join(
    owner_path,
    sizeof(owner_path),
    owner->function_path[0] ? owner->function_path : "/RuntimeProbe/UFunction",
    ".",
    owner->field_name[0] ? owner->field_name : owner->property_name
  );
  return push_lua_property_descriptor(
    api,
    state,
    owner_path,
    owner->function,
    child->name,
    child->class_name,
    child->type,
    child->offset_internal,
    child->element_size > 0 ? child->element_size : 1,
    (long long)child->property_flags,
    child->field,
    "ue-function-param-container-child"
  );
}

static int push_ue_function_param_descriptor(
  LuaApi *api,
  LuaState *state,
  const UeFunctionParamDescriptor *descriptor
) {
  if (!api || !state || !descriptor || !api->create_table || !api->push_string ||
      !api->push_integer || !api->push_boolean || !api->set_field) {
    return 0;
  }
  api->create_table(state, 0, 24);
  const char *class_name = ue_param_class_name_or_default(descriptor->class_name);
  api->push_string(state, descriptor->field_name[0] ? descriptor->field_name : descriptor->property_name);
  api->set_field(state, -2, "Name");
  char path[MAX_LUA_OBJECT_PATH];
  lua_copy_join(
    path,
    sizeof(path),
    descriptor->function_path[0] ? descriptor->function_path : "/RuntimeProbe/UFunction",
    ".",
    descriptor->field_name[0] ? descriptor->field_name : descriptor->property_name
  );
  api->push_string(state, path);
  api->set_field(state, -2, "PathName");
  api->push_string(state, ue_param_value_type(class_name, descriptor->element_size));
  api->set_field(state, -2, "Type");
  api->push_string(state, class_name);
  api->set_field(state, -2, "ClassName");
  api->push_string(state, "ue-function-param");
  api->set_field(state, -2, "Source");
  api->push_integer(state, (long long)descriptor->function);
  api->set_field(state, -2, "Function");
  api->push_string(state, descriptor->function_name);
  api->set_field(state, -2, "FunctionName");
  api->push_string(state, descriptor->function_path);
  api->set_field(state, -2, "FunctionPath");
  api->push_integer(state, (long long)descriptor->field);
  api->set_field(state, -2, "Field");
  api->push_integer(state, (long long)descriptor->field);
  api->set_field(state, -2, "Address");
  api->push_integer(state, (long long)descriptor->function);
  api->set_field(state, -2, "OwnerAddress");
  api->push_string(state, descriptor->chain_name);
  api->set_field(state, -2, "Chain");
  api->push_integer(state, (long long)descriptor->index);
  api->set_field(state, -2, "Index");
  api->push_integer(state, (long long)descriptor->offset_internal);
  api->set_field(state, -2, "Offset");
  api->push_integer(state, (long long)descriptor->offset_internal);
  api->set_field(state, -2, "OffsetInternal");
  api->push_integer(state, (long long)descriptor->element_size);
  api->set_field(state, -2, "Size");
  api->push_integer(state, (long long)descriptor->element_size);
  api->set_field(state, -2, "ElementSize");
  api->push_integer(state, (long long)descriptor->array_dim);
  api->set_field(state, -2, "ArrayDim");
  api->push_integer(state, (long long)descriptor->property_flags);
  api->set_field(state, -2, "PropertyFlags");
  api->push_boolean(state, (descriptor->property_flags & UE_PROPERTY_FLAG_PARM) != 0);
  api->set_field(state, -2, "IsParm");
  api->push_boolean(state, (descriptor->property_flags & UE_PROPERTY_FLAG_OUT_PARM) != 0);
  api->set_field(state, -2, "IsOutParm");
  api->push_boolean(state, (descriptor->property_flags & UE_PROPERTY_FLAG_RETURN_PARM) != 0);
  api->set_field(state, -2, "IsReturnParm");
  if (contains_ci(class_name, "StructProperty") && descriptor->element_size == (int32_t)sizeof(UeFVectorValue)) {
    api->push_string(state, "Vector");
    api->set_field(state, -2, "StructName");
    api->push_string(state, "/Script/CoreUObject.Vector");
    api->set_field(state, -2, "StructPath");
    api->push_integer(state, (long long)(uintptr_t)&ue_self_test_fvector_script_struct_anchor);
    api->set_field(state, -2, "StructAddress");
  }
  api->push_integer(state, (long long)descriptor->child_count);
  api->set_field(state, -2, "ContainerChildCount");
  if (descriptor->child_count > 0) {
    api->create_table(state, 0, (int)descriptor->child_count);
    for (size_t i = 0; i < descriptor->child_count && i < 2; ++i) {
      const UeFunctionParamChildDescriptor *child = &descriptor->children[i];
      if (!child->present) {
        continue;
      }
      if (push_ue_function_param_child_descriptor(api, state, descriptor, child)) {
        api->push_string(state, child->role);
        api->set_field(state, -2, "Role");
        api->push_integer(state, (long long)child->container_offset);
        api->set_field(state, -2, "ContainerOffset");
        api->push_integer(state, (long long)child->property_class);
        api->set_field(state, -2, "PropertyClass");
        api->set_field(state, -2, child->role);
      }
    }
    api->set_field(state, -2, "ContainerChildren");
    for (size_t i = 0; i < descriptor->child_count && i < 2; ++i) {
      set_ue_function_param_child_fields(api, state, &descriptor->children[i]);
    }
  }
  set_lua_object_method(api, state, "GetFullName", lua_property_get_full_name_callback);
  set_lua_object_method(api, state, "GetFName", lua_property_get_fname_callback);
  set_lua_object_method(api, state, "IsA", lua_property_is_a_callback);
  set_lua_object_method(api, state, "GetClass", lua_property_get_class_callback);
  set_lua_object_method(api, state, "ContainerPtrToValuePtr", lua_property_container_ptr_to_value_ptr_callback);
  set_lua_object_method(api, state, "GetValue", lua_property_get_value_callback);
  set_lua_object_method(api, state, "SetValue", lua_property_set_value_callback);
  set_lua_object_method(api, state, "ImportText", lua_property_import_text_callback);
  set_lua_object_method(api, state, "ExportText", lua_property_export_text_callback);
  set_lua_object_method(api, state, "ExportTextItem", lua_property_export_text_callback);
  set_lua_object_method(api, state, "GetOffset_Internal", lua_property_get_offset_internal_callback);
  set_lua_object_method(api, state, "GetOffsetInternal", lua_property_get_offset_internal_callback);
  set_lua_object_method(api, state, "GetElementSize", lua_property_get_element_size_callback);
  set_lua_object_method(api, state, "GetSize", lua_property_get_size_callback);
  set_lua_object_method(api, state, "GetArrayDim", lua_property_get_array_dim_callback);
  set_lua_object_method(api, state, "GetPropertyFlags", lua_property_get_property_flags_callback);
  set_lua_object_method(api, state, "HasAnyPropertyFlags", lua_property_has_any_property_flags_callback);
  set_lua_object_method(api, state, "GetPropertyClass", lua_property_get_property_class_callback);
  set_lua_object_method(api, state, "GetByteMask", lua_bool_property_get_byte_mask_callback);
  set_lua_object_method(api, state, "GetByteOffset", lua_bool_property_get_byte_offset_callback);
  set_lua_object_method(api, state, "GetFieldMask", lua_bool_property_get_field_mask_callback);
  set_lua_object_method(api, state, "GetFieldSize", lua_bool_property_get_field_size_callback);
  set_lua_object_method(api, state, "GetStruct", lua_struct_property_get_struct_callback);
  set_lua_object_method(api, state, "GetInner", lua_array_property_get_inner_callback);
  set_lua_object_method(api, state, "GetElementProperty", lua_set_property_get_element_property_callback);
  set_lua_object_method(api, state, "GetElementProp", lua_set_property_get_element_property_callback);
  set_lua_object_method(api, state, "GetKeyProperty", lua_map_property_get_key_property_callback);
  set_lua_object_method(api, state, "GetKeyProp", lua_map_property_get_key_property_callback);
  set_lua_object_method(api, state, "GetValueProperty", lua_map_property_get_value_property_callback);
  set_lua_object_method(api, state, "GetValueProp", lua_map_property_get_value_property_callback);
  set_lua_object_method(api, state, "type", lua_property_type_callback);
  return 1;
}

static size_t count_ue_function_param_descriptors(uintptr_t function) {
  size_t count = 0;
  if (!function) {
    return 0;
  }
  for (size_t i = 0; i < ue_function_param_descriptor_count; ++i) {
    if (ue_function_param_descriptors[i].function == function) {
      ++count;
    }
  }
  return count;
}

static const UeFunctionParamDescriptor *find_ue_function_descriptor(uintptr_t function) {
  if (!function) {
    return 0;
  }
  for (size_t i = 0; i < ue_function_param_descriptor_count; ++i) {
    if (ue_function_param_descriptors[i].function == function) {
      return &ue_function_param_descriptors[i];
    }
  }
  return 0;
}

static const char *ue_function_path_for_address(uintptr_t function) {
  const UeFunctionParamDescriptor *descriptor = find_ue_function_descriptor(function);
  return descriptor && descriptor->function_path[0] ? descriptor->function_path : 0;
}

static const UeFunctionParamDescriptor *find_ue_function_descriptor_by_path_or_name(const char *query) {
  if (!query || !query[0]) {
    return 0;
  }
  for (size_t i = 0; i < ue_function_param_descriptor_count; ++i) {
    const UeFunctionParamDescriptor *descriptor = &ue_function_param_descriptors[i];
    if ((descriptor->function_path[0] && str_equal(descriptor->function_path, query)) ||
        (descriptor->function_name[0] && str_equal(descriptor->function_name, query))) {
      return descriptor;
    }
  }
  return 0;
}

static int ue_function_descriptor_seen_before(size_t descriptor_index) {
  if (descriptor_index >= ue_function_param_descriptor_count) {
    return 1;
  }
  uintptr_t function = ue_function_param_descriptors[descriptor_index].function;
  for (size_t i = 0; i < descriptor_index; ++i) {
    if (ue_function_param_descriptors[i].function == function) {
      return 1;
    }
  }
  return 0;
}

static int push_known_ue_function_handles(LuaApi *api, LuaState *state, size_t *out_count) {
  if (!api || !state || !api->create_table || !api->set_field || !api->push_integer) {
    return 0;
  }
  api->create_table(state, 0, (int)ue_function_param_descriptor_count + 1);
  size_t count = 0;
  for (size_t i = 0; i < ue_function_param_descriptor_count; ++i) {
    const UeFunctionParamDescriptor *descriptor = &ue_function_param_descriptors[i];
    const char *key = descriptor->function_path[0] ? descriptor->function_path : descriptor->function_name;
    if (!key || !key[0] || ue_function_descriptor_seen_before(i)) {
      continue;
    }
    if (push_ue_function_handle_from_descriptor(api, state, descriptor)) {
      api->set_field(state, -2, key);
      ++count;
    }
  }
  api->push_integer(state, (long long)count);
  api->set_field(state, -2, "Count");
  if (out_count) {
    *out_count = count;
  }
  return 1;
}

static int push_process_event_params_context_or_nil(
  LuaApi *api,
  LuaState *state,
  uintptr_t address,
  uintptr_t function
) {
  if (!api || !state || !api->push_nil || !api->create_table || !api->push_integer ||
      !api->push_boolean || !api->push_string || !api->set_field) {
    return 0;
  }
  if (!address) {
    api->push_nil(state);
    return 1;
  }
  size_t live_descriptor_count = count_ue_function_param_descriptors(function);
  int force_self_test_descriptors =
    function == (uintptr_t)&ue_self_test_function ||
    function == (uintptr_t)&lua_hook_registration_name[0];
  int use_live_descriptors = live_descriptor_count > 0 && !force_self_test_descriptors;
  size_t property_count = use_live_descriptors ?
    live_descriptor_count :
    process_event_self_test_param_descriptor_count;
  api->create_table(state, 0, 8 + (int)property_count);
  api->push_integer(state, (long long)address);
  api->set_field(state, -2, "Address");
  api->push_boolean(state, 1);
  api->set_field(state, -2, "IsValid");
  api->push_string(state, "ProcessEventParams");
  api->set_field(state, -2, "Kind");
  api->push_string(state, "process-event");
  api->set_field(state, -2, "Source");
  api->push_integer(state, (long long)property_count);
  api->set_field(state, -2, "PropertyCount");
  api->create_table(state, 0, (int)property_count);
  if (use_live_descriptors) {
    for (size_t i = 0; i < ue_function_param_descriptor_count; ++i) {
      const UeFunctionParamDescriptor *descriptor = &ue_function_param_descriptors[i];
      if (descriptor->function != function) {
        continue;
      }
      if (push_ue_function_param_descriptor(api, state, descriptor)) {
        api->set_field(state, -2, descriptor->field_name[0] ? descriptor->field_name : descriptor->property_name);
      }
    }
  } else {
    for (size_t i = 0; i < process_event_self_test_param_descriptor_count; ++i) {
      const ProcessEventParamDescriptor *descriptor = &process_event_self_test_param_descriptors[i];
      if (push_process_event_param_descriptor(api, state, descriptor)) {
        api->set_field(state, -2, descriptor->name);
      }
    }
  }
  api->set_field(state, -2, "Properties");
  api->create_table(state, 0, (int)property_count);
  if (use_live_descriptors) {
    for (size_t i = 0; i < ue_function_param_descriptor_count; ++i) {
      const UeFunctionParamDescriptor *descriptor = &ue_function_param_descriptors[i];
      if (descriptor->function != function) {
        continue;
      }
      const char *name = descriptor->field_name[0] ? descriptor->field_name : descriptor->property_name;
      if (push_remote_unreal_param_for_ue_descriptor(api, state, address, descriptor)) {
        api->set_field(state, -2, name);
      }
    }
  } else {
    for (size_t i = 0; i < process_event_self_test_param_descriptor_count; ++i) {
      const ProcessEventParamDescriptor *descriptor = &process_event_self_test_param_descriptors[i];
      if (push_remote_unreal_param_for_process_descriptor(api, state, address, descriptor)) {
        api->set_field(state, -2, descriptor->name);
      }
    }
  }
  api->set_field(state, -2, "Values");
  if (use_live_descriptors) {
    for (size_t i = 0; i < ue_function_param_descriptor_count; ++i) {
      const UeFunctionParamDescriptor *descriptor = &ue_function_param_descriptors[i];
      if (descriptor->function != function) {
        continue;
      }
      const char *name = descriptor->field_name[0] ? descriptor->field_name : descriptor->property_name;
      if (push_remote_unreal_param_for_ue_descriptor(api, state, address, descriptor)) {
        api->set_field(state, -2, name);
      }
    }
  } else {
    for (size_t i = 0; i < process_event_self_test_param_descriptor_count; ++i) {
      const ProcessEventParamDescriptor *descriptor = &process_event_self_test_param_descriptors[i];
      if (push_remote_unreal_param_for_process_descriptor(api, state, address, descriptor)) {
        api->set_field(state, -2, descriptor->name);
      }
    }
  }
  ++lua_process_event_param_descriptor_hits;
  return 2;
}

static int push_live_function_param_descriptors_or_nil(
  LuaApi *api,
  LuaState *state,
  uintptr_t function
) {
  size_t descriptor_count = count_ue_function_param_descriptors(function);
  if (descriptor_count == 0) {
    return 0;
  }
  const UeFunctionParamDescriptor *function_descriptor = find_ue_function_descriptor(function);
  api->create_table(state, 0, 7);
  api->push_integer(state, (long long)function);
  api->set_field(state, -2, "Address");
  api->push_string(state, function_descriptor && function_descriptor->function_path[0] ? function_descriptor->function_path : "");
  api->set_field(state, -2, "PathName");
  api->push_string(state, function_descriptor && function_descriptor->function_name[0] ? function_descriptor->function_name : "");
  api->set_field(state, -2, "Name");
  api->push_string(state, "UFunction");
  api->set_field(state, -2, "ClassName");
  api->push_string(state, "ue-function-param");
  api->set_field(state, -2, "Source");
  api->push_integer(state, (long long)descriptor_count);
  api->set_field(state, -2, "PropertyCount");
  api->create_table(state, 0, (int)descriptor_count);
  for (size_t i = 0; i < ue_function_param_descriptor_count; ++i) {
    const UeFunctionParamDescriptor *descriptor = &ue_function_param_descriptors[i];
    if (descriptor->function != function) {
      continue;
    }
    if (push_ue_function_param_descriptor(api, state, descriptor)) {
      api->set_field(state, -2, descriptor->field_name[0] ? descriptor->field_name : descriptor->property_name);
    }
  }
  api->set_field(state, -2, "Properties");
  ++lua_process_event_function_param_descriptor_hits;
  return 1;
}

static int push_process_event_function_param_descriptors_or_nil(
  LuaApi *api,
  LuaState *state,
  uintptr_t function
) {
  if (!api || !state || !api->push_nil || !api->create_table || !api->push_integer ||
      !api->push_string || !api->set_field) {
    return 0;
  }
  if (!function) {
    api->push_nil(state);
    return 1;
  }
  if (push_live_function_param_descriptors_or_nil(api, state, function)) {
    return 1;
  }
  if (function != (uintptr_t)&lua_hook_registration_name[0] || !lua_hook_registration_name[0]) {
    api->push_nil(state);
    return 1;
  }
  api->create_table(state, 0, 7);
  api->push_integer(state, (long long)function);
  api->set_field(state, -2, "Address");
  api->push_string(state, lua_hook_registration_name);
  api->set_field(state, -2, "PathName");
  api->push_string(state, path_basename_win(lua_hook_registration_name));
  api->set_field(state, -2, "Name");
  api->push_string(state, "UFunction");
  api->set_field(state, -2, "ClassName");
  api->push_string(state, "process-event-function");
  api->set_field(state, -2, "Source");
  api->push_integer(state, (long long)process_event_self_test_param_descriptor_count);
  api->set_field(state, -2, "PropertyCount");
  api->create_table(state, 0, (int)process_event_self_test_param_descriptor_count);
  for (size_t i = 0; i < process_event_self_test_param_descriptor_count; ++i) {
    const ProcessEventParamDescriptor *descriptor = &process_event_self_test_param_descriptors[i];
    push_process_event_param_descriptor(api, state, descriptor);
    api->set_field(state, -2, descriptor->name);
  }
  api->set_field(state, -2, "Properties");
  ++lua_process_event_function_param_descriptor_hits;
  return 1;
}

static void reset_lua_hook_registration(void) {
  active_lua_api = 0;
  lua_hook_registration_count = 0;
  lua_console_command_registration_count = 0;
  lua_process_console_exec_pre_hook_registration_count = 0;
  lua_process_console_exec_post_hook_registration_count = 0;
  lua_local_player_exec_pre_hook_registration_count = 0;
  lua_local_player_exec_post_hook_registration_count = 0;
  lua_call_function_pre_hook_registration_count = 0;
  lua_call_function_post_hook_registration_count = 0;
  lua_custom_event_registration_count = 0;
  lua_load_map_pre_hook_registration_count = 0;
  lua_load_map_post_hook_registration_count = 0;
  lua_begin_play_pre_hook_registration_count = 0;
  lua_begin_play_post_hook_registration_count = 0;
  lua_init_game_state_pre_hook_registration_count = 0;
  lua_init_game_state_post_hook_registration_count = 0;
  for (size_t i = 0; i < sizeof(lua_hook_registrations); ++i) {
    ((unsigned char *)lua_hook_registrations)[i] = 0;
  }
  for (size_t i = 0; i < sizeof(lua_console_command_registrations); ++i) {
    ((unsigned char *)lua_console_command_registrations)[i] = 0;
  }
  for (size_t i = 0; i < sizeof(lua_process_console_exec_pre_hook_registrations); ++i) {
    ((unsigned char *)lua_process_console_exec_pre_hook_registrations)[i] = 0;
  }
  for (size_t i = 0; i < sizeof(lua_process_console_exec_post_hook_registrations); ++i) {
    ((unsigned char *)lua_process_console_exec_post_hook_registrations)[i] = 0;
  }
  for (size_t i = 0; i < sizeof(lua_local_player_exec_pre_hook_registrations); ++i) {
    ((unsigned char *)lua_local_player_exec_pre_hook_registrations)[i] = 0;
  }
  for (size_t i = 0; i < sizeof(lua_local_player_exec_post_hook_registrations); ++i) {
    ((unsigned char *)lua_local_player_exec_post_hook_registrations)[i] = 0;
  }
  for (size_t i = 0; i < sizeof(lua_call_function_pre_hook_registrations); ++i) {
    ((unsigned char *)lua_call_function_pre_hook_registrations)[i] = 0;
  }
  for (size_t i = 0; i < sizeof(lua_call_function_post_hook_registrations); ++i) {
    ((unsigned char *)lua_call_function_post_hook_registrations)[i] = 0;
  }
  for (size_t i = 0; i < sizeof(lua_custom_event_registrations); ++i) {
    ((unsigned char *)lua_custom_event_registrations)[i] = 0;
  }
  for (size_t i = 0; i < sizeof(lua_load_map_pre_hook_registrations); ++i) {
    ((unsigned char *)lua_load_map_pre_hook_registrations)[i] = 0;
  }
  for (size_t i = 0; i < sizeof(lua_load_map_post_hook_registrations); ++i) {
    ((unsigned char *)lua_load_map_post_hook_registrations)[i] = 0;
  }
  for (size_t i = 0; i < sizeof(lua_begin_play_pre_hook_registrations); ++i) {
    ((unsigned char *)lua_begin_play_pre_hook_registrations)[i] = 0;
  }
  for (size_t i = 0; i < sizeof(lua_begin_play_post_hook_registrations); ++i) {
    ((unsigned char *)lua_begin_play_post_hook_registrations)[i] = 0;
  }
  for (size_t i = 0; i < sizeof(lua_init_game_state_pre_hook_registrations); ++i) {
    ((unsigned char *)lua_init_game_state_pre_hook_registrations)[i] = 0;
  }
  for (size_t i = 0; i < sizeof(lua_init_game_state_post_hook_registrations); ++i) {
    ((unsigned char *)lua_init_game_state_post_hook_registrations)[i] = 0;
  }
  for (size_t i = 0; i < MAX_LUA_HOOK_REGISTRATIONS; ++i) {
    lua_hook_registrations[i].pre_ref = LUA_NOREF_COMPAT;
    lua_hook_registrations[i].post_ref = LUA_NOREF_COMPAT;
  }
  for (size_t i = 0; i < MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS; ++i) {
    lua_console_command_registrations[i].ref = LUA_NOREF_COMPAT;
    lua_process_console_exec_pre_hook_registrations[i].ref = LUA_NOREF_COMPAT;
    lua_process_console_exec_post_hook_registrations[i].ref = LUA_NOREF_COMPAT;
    lua_local_player_exec_pre_hook_registrations[i].ref = LUA_NOREF_COMPAT;
    lua_local_player_exec_post_hook_registrations[i].ref = LUA_NOREF_COMPAT;
    lua_call_function_pre_hook_registrations[i].ref = LUA_NOREF_COMPAT;
    lua_call_function_post_hook_registrations[i].ref = LUA_NOREF_COMPAT;
    lua_custom_event_registrations[i].ref = LUA_NOREF_COMPAT;
    lua_load_map_pre_hook_registrations[i].ref = LUA_NOREF_COMPAT;
    lua_load_map_post_hook_registrations[i].ref = LUA_NOREF_COMPAT;
    lua_begin_play_pre_hook_registrations[i].ref = LUA_NOREF_COMPAT;
    lua_begin_play_post_hook_registrations[i].ref = LUA_NOREF_COMPAT;
    lua_init_game_state_pre_hook_registrations[i].ref = LUA_NOREF_COMPAT;
    lua_init_game_state_post_hook_registrations[i].ref = LUA_NOREF_COMPAT;
  }
  lua_hook_registration_name[0] = '\0';
  lua_hook_pre_ref = LUA_NOREF_COMPAT;
  lua_hook_post_ref = LUA_NOREF_COMPAT;
  lua_hook_pre_calls = 0;
  lua_hook_post_calls = 0;
  lua_hook_pre_result = 0;
  lua_hook_post_result = 0;
  lua_hook_pre_is_number = 0;
  lua_hook_post_is_number = 0;
  lua_static_find_object_calls = 0;
  lua_static_find_object_hits = 0;
  lua_find_object_calls = 0;
  lua_find_object_hits = 0;
  lua_find_first_of_calls = 0;
  lua_find_first_of_hits = 0;
  lua_get_known_objects_calls = 0;
  lua_get_known_objects_hits = 0;
  lua_find_objects_calls = 0;
  lua_find_objects_hits = 0;
  lua_find_all_of_calls = 0;
  lua_find_all_of_hits = 0;
  lua_for_each_uobject_calls = 0;
  lua_for_each_uobject_callbacks = 0;
  lua_for_each_function_calls = 0;
  lua_for_each_function_callbacks = 0;
  lua_is_a_calls = 0;
  lua_is_a_hits = 0;
  lua_load_asset_calls = 0;
  lua_load_asset_hits = 0;
  lua_static_construct_object_calls = 0;
  lua_static_construct_object_hits = 0;
  lua_static_construct_object_outer_hits = 0;
  lua_get_world_calls = 0;
  lua_get_world_hits = 0;
  lua_get_cdo_calls = 0;
  lua_get_cdo_hits = 0;
  lua_get_level_calls = 0;
  lua_get_level_hits = 0;
  lua_notify_on_new_object_calls = 0;
  lua_notify_on_new_object_callbacks = 0;
  lua_notify_on_new_object_result = 0;
  lua_notify_on_new_object_is_number = 0;
  lua_notify_on_new_object_status = 0;
  lua_notify_on_new_object_registration_count = 0;
  for (size_t i = 0; i < sizeof(lua_notify_on_new_object_registrations); ++i) {
    ((unsigned char *)lua_notify_on_new_object_registrations)[i] = 0;
  }
  for (size_t i = 0; i < MAX_LUA_NOTIFY_ON_NEW_OBJECT_REGISTRATIONS; ++i) {
    lua_notify_on_new_object_registrations[i].ref = LUA_NOREF_COMPAT;
  }
  lua_execute_in_game_thread_calls = 0;
  lua_execute_in_game_thread_callbacks = 0;
  lua_execute_in_game_thread_result = 0;
  lua_execute_in_game_thread_is_number = 0;
  lua_compat_registration_count = 0;
  lua_key_bind_registration_count = 0;
  for (size_t i = 0; i < sizeof(lua_shared_variables); ++i) {
    ((unsigned char *)lua_shared_variables)[i] = 0;
  }
  lua_shared_variable_count = 0;
  lua_reflection_get_property_calls = 0;
  lua_reflection_get_property_hits = 0;
  lua_reflection_set_property_calls = 0;
  lua_reflection_set_property_hits = 0;
  lua_reflection_call_function_calls = 0;
  lua_reflection_call_function_hits = 0;
  lua_reflection_raw_property_hits = 0;
  lua_reflection_raw_property_value = 0;
  lua_reflection_named_property_hits = 0;
  lua_reflection_raw_property_set_hits = 0;
  lua_reflection_raw_property_set_value = 0;
  lua_reflection_array_inner_property_hits = 0;
  lua_reflection_enum_property_hits = 0;
  lua_reflection_enum_underlying_property_hits = 0;
  lua_reflection_set_element_property_hits = 0;
  lua_reflection_map_key_property_hits = 0;
  lua_reflection_map_value_property_hits = 0;
  lua_reflection_import_text_hits = 0;
  lua_reflection_export_text_hits = 0;
  lua_reflection_property_metadata_hits = 0;
  lua_reflection_descriptor_value_get_hits = 0;
  lua_reflection_descriptor_value_set_hits = 0;
  lua_process_event_param_get_calls = 0;
  lua_process_event_param_get_hits = 0;
  lua_process_event_param_set_calls = 0;
  lua_process_event_param_set_hits = 0;
  lua_process_event_param_descriptor_hits = 0;
  lua_process_event_param_descriptor_lookup_calls = 0;
  lua_process_event_param_descriptor_lookup_hits = 0;
  lua_process_event_function_param_descriptor_calls = 0;
  lua_process_event_function_param_descriptor_hits = 0;
  active_process_event_lua_params_address = 0;
  lua_reflection_probe_value = 7;
  lua_reflection_probe_bool_value = 1;
  lua_reflection_probe_float_value = 12.5f;
  lua_reflection_probe_double_value = -45.25;
  lua_reflection_probe_name_value.comparison_index = SELF_TEST_FNAME_INDEX;
  lua_reflection_probe_name_value.number = 1;
  copy_string(lua_reflection_probe_name_string, sizeof(lua_reflection_probe_name_string), "SelfTestUObjectName_0");
  copy_string(lua_reflection_probe_string_value, sizeof(lua_reflection_probe_string_value), "spice");
  copy_string(lua_reflection_probe_text_value, sizeof(lua_reflection_probe_text_value), "ProbeText");
  lua_reflection_probe_array_values[0] = 11;
  lua_reflection_probe_array_values[1] = 22;
  lua_reflection_probe_array_values[2] = 33;
  lua_reflection_probe_enum_value = 2;
  lua_reflection_probe_set_values[0] = 101;
  lua_reflection_probe_set_values[1] = 202;
  lua_reflection_probe_map_key_value = 303;
  copy_string(lua_reflection_probe_map_value, sizeof(lua_reflection_probe_map_value), "sietch");
  lua_reflection_probe_object_address = (uintptr_t)&ue_self_test_object;
  seed_lua_object_handles();
}

static int lua_ref_is_valid(int ref) {
  return ref > LUA_REFNIL_COMPAT;
}

static void lua_unref_hook_ref(LuaApi *api, LuaState *state, int *ref) {
  if (!api || !state || !ref || !lua_ref_is_valid(*ref) || !api->unref) {
    return;
  }
  api->unref(state, LUA_REGISTRYINDEX_COMPAT, *ref);
  *ref = LUA_NOREF_COMPAT;
}

static int lua_store_hook_ref(LuaApi *api, LuaState *state, int stack_index, int *ref) {
  if (!api || !state || !ref || !api->type || !api->push_value || !api->ref) {
    return 0;
  }
  if (api->type(state, stack_index) != LUA_TFUNCTION_COMPAT) {
    return 0;
  }
  lua_unref_hook_ref(api, state, ref);
  api->push_value(state, stack_index);
  *ref = api->ref(state, LUA_REGISTRYINDEX_COMPAT);
  return lua_ref_is_valid(*ref);
}

static void lua_unref_hook_registrations(LuaApi *api, LuaState *state) {
  for (size_t i = 0; i < MAX_LUA_HOOK_REGISTRATIONS; ++i) {
    lua_unref_hook_ref(api, state, &lua_hook_registrations[i].pre_ref);
    lua_unref_hook_ref(api, state, &lua_hook_registrations[i].post_ref);
  }
  for (size_t i = 0; i < MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS; ++i) {
    lua_unref_hook_ref(api, state, &lua_console_command_registrations[i].ref);
    lua_unref_hook_ref(api, state, &lua_process_console_exec_pre_hook_registrations[i].ref);
    lua_unref_hook_ref(api, state, &lua_process_console_exec_post_hook_registrations[i].ref);
    lua_unref_hook_ref(api, state, &lua_local_player_exec_pre_hook_registrations[i].ref);
    lua_unref_hook_ref(api, state, &lua_local_player_exec_post_hook_registrations[i].ref);
    lua_unref_hook_ref(api, state, &lua_call_function_pre_hook_registrations[i].ref);
    lua_unref_hook_ref(api, state, &lua_call_function_post_hook_registrations[i].ref);
    lua_unref_hook_ref(api, state, &lua_custom_event_registrations[i].ref);
    lua_unref_hook_ref(api, state, &lua_load_map_pre_hook_registrations[i].ref);
    lua_unref_hook_ref(api, state, &lua_load_map_post_hook_registrations[i].ref);
    lua_unref_hook_ref(api, state, &lua_begin_play_pre_hook_registrations[i].ref);
    lua_unref_hook_ref(api, state, &lua_begin_play_post_hook_registrations[i].ref);
    lua_unref_hook_ref(api, state, &lua_init_game_state_pre_hook_registrations[i].ref);
    lua_unref_hook_ref(api, state, &lua_init_game_state_post_hook_registrations[i].ref);
  }
  lua_hook_pre_ref = LUA_NOREF_COMPAT;
  lua_hook_post_ref = LUA_NOREF_COMPAT;
  lua_console_command_registration_count = 0;
  lua_process_console_exec_pre_hook_registration_count = 0;
  lua_process_console_exec_post_hook_registration_count = 0;
  lua_local_player_exec_pre_hook_registration_count = 0;
  lua_local_player_exec_post_hook_registration_count = 0;
  lua_call_function_pre_hook_registration_count = 0;
  lua_call_function_post_hook_registration_count = 0;
  lua_custom_event_registration_count = 0;
  lua_load_map_pre_hook_registration_count = 0;
  lua_load_map_post_hook_registration_count = 0;
  lua_begin_play_pre_hook_registration_count = 0;
  lua_begin_play_post_hook_registration_count = 0;
  lua_init_game_state_pre_hook_registration_count = 0;
  lua_init_game_state_post_hook_registration_count = 0;
}

static void lua_unref_notify_on_new_object_registrations(LuaApi *api, LuaState *state) {
  for (size_t i = 0; i < MAX_LUA_NOTIFY_ON_NEW_OBJECT_REGISTRATIONS; ++i) {
    lua_unref_hook_ref(api, state, &lua_notify_on_new_object_registrations[i].ref);
  }
  lua_notify_on_new_object_registration_count = 0;
}

static int invoke_lua_hook_ref(
  LuaApi *api,
  LuaState *state,
  int ref,
  int *calls,
  long long *result,
  int *is_number
) {
  if (!api || !state || !lua_ref_is_valid(ref) || !api->rawgeti || !api->set_top) {
    return -1;
  }
  api->rawgeti(state, LUA_REGISTRYINDEX_COMPAT, ref);
  int status = lua_call(api, state, 0, 1, 0);
  if (status != 0) {
    return status;
  }
  int local_is_number = 0;
  long long local_result = lua_to_integer(api, state, -1, &local_is_number);
  api->set_top(state, -2);
  if (calls) {
    ++*calls;
  }
  if (result) {
    *result = local_result;
  }
  if (is_number) {
    *is_number = local_is_number;
  }
  return 0;
}

static int lua_notify_filter_matches(const char *filter, const LuaObjectHandle *object) {
  if (!object || !filter || !filter[0]) {
    return object != 0;
  }
  return str_equal(filter, object->path) ||
         str_equal(filter, object->name) ||
         str_equal(filter, object->class_name) ||
         contains_ci(filter, object->path) ||
         contains_ci(filter, object->name) ||
         contains_ci(filter, object->class_name) ||
         contains_ci(object->path, filter) ||
         contains_ci(object->name, filter) ||
         contains_ci(object->class_name, filter);
}

static int invoke_lua_notify_on_new_object(
  LuaApi *api,
  LuaState *state,
  const LuaObjectHandle *object
) {
  if (!api || !state || !object) {
    return 0;
  }
  if (!api->rawgeti || !api->set_top) {
    lua_notify_on_new_object_status = -1;
    return -1;
  }
  int final_status = 0;
  int limit = lua_notify_on_new_object_registration_count;
  if (limit > MAX_LUA_NOTIFY_ON_NEW_OBJECT_REGISTRATIONS) {
    limit = MAX_LUA_NOTIFY_ON_NEW_OBJECT_REGISTRATIONS;
  }
  for (int i = 0; i < limit; ++i) {
    LuaNotifyOnNewObjectRegistration *registration = &lua_notify_on_new_object_registrations[i];
    if (!lua_ref_is_valid(registration->ref) ||
        !lua_notify_filter_matches(registration->filter, object)) {
      continue;
    }
    api->rawgeti(state, LUA_REGISTRYINDEX_COMPAT, registration->ref);
    if (!push_lua_object_handle(api, state, object)) {
      api->set_top(state, -2);
      registration->status = -1;
      lua_notify_on_new_object_status = -1;
      final_status = final_status ? final_status : -1;
      continue;
    }
    int status = lua_call(api, state, 1, 1, 0);
    registration->status = status;
    lua_notify_on_new_object_status = status;
    if (status != 0) {
      api->set_top(state, -2);
      final_status = final_status ? final_status : status;
      continue;
    }
    registration->result = lua_to_integer(api, state, -1, &registration->is_number);
    registration->calls++;
    lua_notify_on_new_object_result = registration->result;
    lua_notify_on_new_object_is_number = registration->is_number;
    api->set_top(state, -2);
    ++lua_notify_on_new_object_callbacks;
  }
  return final_status;
}

static void push_lua_process_event_context(
  LuaApi *api,
  LuaState *state,
  ProcessEventDispatchContext *ctx,
  const char *stage
) {
  api->create_table(state, 0, 12);
  api->push_string(state, stage ? stage : "");
  api->set_field(state, -2, "stage");
  api->push_string(state, ctx && ctx->function_path ? ctx->function_path : "");
  api->set_field(state, -2, "functionPath");
  api->push_integer(state, (long long)(uintptr_t)(ctx ? ctx->object : 0));
  api->set_field(state, -2, "object");
  api->push_integer(state, (long long)(uintptr_t)(ctx ? ctx->function : 0));
  api->set_field(state, -2, "function");
  api->push_integer(state, (long long)(uintptr_t)(ctx ? ctx->params : 0));
  api->set_field(state, -2, "params");
  if (push_process_event_params_context_or_nil(
        api,
        state,
        (uintptr_t)(ctx ? ctx->params : 0),
        (uintptr_t)(ctx ? ctx->function : 0)
      ) == 2) {
    ++process_event_live_lua_params_handle_hits;
  }
  api->set_field(state, -2, "Params");
  if (push_process_event_context_handle_or_nil(api, state, (uintptr_t)(ctx ? ctx->object : 0)) == 2) {
    ++process_event_live_lua_object_handle_hits;
  }
  api->set_field(state, -2, "Object");
  if (push_process_event_context_handle_or_nil(api, state, (uintptr_t)(ctx ? ctx->function : 0)) == 2) {
    ++process_event_live_lua_function_handle_hits;
  }
  api->set_field(state, -2, "Function");
  api->push_integer(state, ctx ? ctx->call_index : 0);
  api->set_field(state, -2, "call");
  api->push_boolean(state, ctx && ctx->original_called);
  api->set_field(state, -2, "originalCalled");
  api->push_integer(state, ctx ? ctx->pre_callbacks : 0);
  api->set_field(state, -2, "preCallbacks");
  api->push_integer(state, ctx ? ctx->post_callbacks : 0);
  api->set_field(state, -2, "postCallbacks");
}

static int invoke_lua_hook_ref_with_process_event_context(
  LuaApi *api,
  LuaState *state,
  int ref,
  int *calls,
  long long *result,
  int *is_number,
  ProcessEventDispatchContext *ctx,
  const char *stage
) {
  if (!api || !state || !lua_ref_is_valid(ref) || !api->rawgeti || !api->set_top ||
      !api->create_table || !api->set_field || !api->push_nil) {
    return -1;
  }
  LuaApi *previous_active_lua_api = active_lua_api;
  uintptr_t previous_params_address = active_process_event_lua_params_address;
  active_lua_api = api;
  active_process_event_lua_params_address = (uintptr_t)(ctx ? ctx->params : 0);
  api->rawgeti(state, LUA_REGISTRYINDEX_COMPAT, ref);
  push_lua_process_event_context(api, state, ctx, stage);
  int status = lua_call(api, state, 1, 1, 0);
  active_process_event_lua_params_address = previous_params_address;
  active_lua_api = previous_active_lua_api;
  if (status != 0) {
    return status;
  }
  int local_is_number = 0;
  long long local_result = lua_to_integer(api, state, -1, &local_is_number);
  api->set_top(state, -2);
  if (calls) {
    ++*calls;
  }
  if (result) {
    *result = local_result;
  }
  if (is_number) {
    *is_number = local_is_number;
  }
  return 0;
}

static int lua_hook_registration_matches_process_event(
  const LuaHookRegistration *registration,
  ProcessEventDispatchContext *ctx
) {
  if (!registration) {
    return 0;
  }
  if (!ctx || !ctx->function_path || !ctx->function_path[0]) {
    return 1;
  }
  return registration->name[0] && str_equal(registration->name, ctx->function_path);
}

static int invoke_lua_hook_refs(LuaApi *api, LuaState *state) {
  int final_status = lua_hook_registration_count > 0 ? 0 : -1;
  for (int i = 0; i < lua_hook_registration_count && i < MAX_LUA_HOOK_REGISTRATIONS; ++i) {
    LuaHookRegistration *registration = &lua_hook_registrations[i];
    int status = invoke_lua_hook_ref(
      api,
      state,
      registration->pre_ref,
      &registration->pre_calls,
      &registration->pre_result,
      &registration->pre_is_number
    );
    if (status != 0) {
      final_status = status;
      continue;
    }
    ++lua_hook_pre_calls;
    lua_hook_pre_result = registration->pre_result;
    lua_hook_pre_is_number = registration->pre_is_number;
  }
  for (int i = 0; i < lua_hook_registration_count && i < MAX_LUA_HOOK_REGISTRATIONS; ++i) {
    LuaHookRegistration *registration = &lua_hook_registrations[i];
    int status = invoke_lua_hook_ref(
      api,
      state,
      registration->post_ref,
      &registration->post_calls,
      &registration->post_result,
      &registration->post_is_number
    );
    if (status != 0) {
      final_status = status;
      continue;
    }
    ++lua_hook_post_calls;
    lua_hook_post_result = registration->post_result;
    lua_hook_post_is_number = registration->post_is_number;
  }
  return final_status;
}

static int invoke_lua_hook_registrations_with_process_event_context(
  LuaApi *api,
  LuaState *state,
  ProcessEventDispatchContext *ctx,
  const char *stage,
  int pre
) {
  int final_status = lua_hook_registration_count > 0 ? 0 : -1;
  for (int i = 0; i < lua_hook_registration_count && i < MAX_LUA_HOOK_REGISTRATIONS; ++i) {
    LuaHookRegistration *registration = &lua_hook_registrations[i];
    if (!lua_hook_registration_matches_process_event(registration, ctx)) {
      continue;
    }
    int status = invoke_lua_hook_ref_with_process_event_context(
      api,
      state,
      pre ? registration->pre_ref : registration->post_ref,
      pre ? &registration->pre_calls : &registration->post_calls,
      pre ? &registration->pre_result : &registration->post_result,
      pre ? &registration->pre_is_number : &registration->post_is_number,
      ctx,
      stage
    );
    if (status != 0) {
      final_status = status;
      continue;
    }
    if (pre) {
      ++lua_hook_pre_calls;
      lua_hook_pre_result = registration->pre_result;
      lua_hook_pre_is_number = registration->pre_is_number;
      if (ctx) {
        ++ctx->pre_callbacks;
      }
    } else {
      ++lua_hook_post_calls;
      lua_hook_post_result = registration->post_result;
      lua_hook_post_is_number = registration->post_is_number;
      if (ctx) {
        ++ctx->post_callbacks;
      }
    }
  }
  return final_status;
}

static int lua_hook_pre_id_for_index(size_t index) {
  return 2 + (int)(index * 2);
}

static int lua_hook_post_id_for_index(size_t index) {
  return lua_hook_pre_id_for_index(index) + 1;
}

static void refresh_lua_primary_hook_registration(void) {
  if (lua_hook_registration_count > 0) {
    LuaHookRegistration *registration = &lua_hook_registrations[lua_hook_registration_count - 1];
    copy_string(lua_hook_registration_name, sizeof(lua_hook_registration_name), registration->name);
    lua_hook_pre_ref = registration->pre_ref;
    lua_hook_post_ref = registration->post_ref;
  } else {
    lua_hook_registration_name[0] = '\0';
    lua_hook_pre_ref = LUA_NOREF_COMPAT;
    lua_hook_post_ref = LUA_NOREF_COMPAT;
  }
}

static int CDECL lua_register_hook_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_integer) {
    return 0;
  }
  size_t name_len = 0;
  const char *name = active_lua_api->to_lstring ? active_lua_api->to_lstring(state, 1, &name_len) : 0;
  if (!name) {
    name = "";
    name_len = 0;
  }
  if (lua_hook_registration_count >= MAX_LUA_HOOK_REGISTRATIONS) {
    active_lua_api->push_integer(state, 0);
    return 1;
  }
  LuaHookRegistration *registration = &lua_hook_registrations[lua_hook_registration_count];
  for (size_t i = 0; i < sizeof(*registration); ++i) {
    ((unsigned char *)registration)[i] = 0;
  }
  registration->pre_ref = LUA_NOREF_COMPAT;
  registration->post_ref = LUA_NOREF_COMPAT;
  size_t copy_len = name_len;
  if (copy_len + 1 > sizeof(registration->name)) {
    copy_len = sizeof(registration->name) - 1;
  }
  for (size_t i = 0; i < copy_len; ++i) {
    registration->name[i] = name[i];
  }
  registration->name[copy_len] = '\0';
  if (!lua_store_hook_ref(active_lua_api, state, 2, &registration->pre_ref) ||
      !lua_store_hook_ref(active_lua_api, state, 3, &registration->post_ref)) {
    lua_unref_hook_ref(active_lua_api, state, &registration->pre_ref);
    lua_unref_hook_ref(active_lua_api, state, &registration->post_ref);
    active_lua_api->push_integer(state, 0);
    return 1;
  }
  ++lua_hook_registration_count;
  refresh_lua_primary_hook_registration();
  active_lua_api->push_integer(state, lua_hook_pre_id_for_index((size_t)lua_hook_registration_count - 1));
  active_lua_api->push_integer(state, lua_hook_post_id_for_index((size_t)lua_hook_registration_count - 1));
  return 2;
}

static int CDECL lua_unregister_hook_callback(LuaState *state) {
  if (!active_lua_api) {
    return 0;
  }
  const char *name = active_lua_api->to_lstring ? active_lua_api->to_lstring(state, 1, 0) : 0;
  int pre_is_number = 0;
  int post_is_number = 0;
  long long pre_id = lua_to_integer(active_lua_api, state, 2, &pre_is_number);
  long long post_id = lua_to_integer(active_lua_api, state, 3, &post_is_number);
  if (!pre_is_number || !post_is_number || pre_id < 2 || post_id != pre_id + 1) {
    return 0;
  }
  size_t index = (size_t)((pre_id - 2) / 2);
  if (index >= (size_t)lua_hook_registration_count || pre_id != lua_hook_pre_id_for_index(index) ||
      post_id != lua_hook_post_id_for_index(index)) {
    return 0;
  }
  LuaHookRegistration *registration = &lua_hook_registrations[index];
  if (name && name[0] && !str_equal(name, registration->name)) {
    return 0;
  }
  lua_unref_hook_ref(active_lua_api, state, &registration->pre_ref);
  lua_unref_hook_ref(active_lua_api, state, &registration->post_ref);
  for (size_t i = index + 1; i < (size_t)lua_hook_registration_count; ++i) {
    unsigned char *dst = (unsigned char *)&lua_hook_registrations[i - 1];
    unsigned char *src = (unsigned char *)&lua_hook_registrations[i];
    for (size_t j = 0; j < sizeof(lua_hook_registrations[i]); ++j) {
      dst[j] = src[j];
    }
  }
  if (lua_hook_registration_count > 0) {
    --lua_hook_registration_count;
  }
  for (size_t i = 0; i < sizeof(lua_hook_registrations[lua_hook_registration_count]); ++i) {
    ((unsigned char *)&lua_hook_registrations[lua_hook_registration_count])[i] = 0;
  }
  lua_hook_registrations[lua_hook_registration_count].pre_ref = LUA_NOREF_COMPAT;
  lua_hook_registrations[lua_hook_registration_count].post_ref = LUA_NOREF_COMPAT;
  refresh_lua_primary_hook_registration();
  return 0;
}

static int CDECL lua_static_find_object_callback(LuaState *state) {
  ++lua_static_find_object_calls;
  if (!active_lua_api || !active_lua_api->push_nil) {
    return 0;
  }
  const char *query = lua_object_lookup_query_arg(state);
  const LuaObjectHandle *object = find_lua_object_by_path_or_name(query);
  if (object && push_lua_object_handle(active_lua_api, state, object)) {
    ++lua_static_find_object_hits;
    return 1;
  }
  active_lua_api->push_nil(state);
  return 1;
}

static int CDECL lua_find_object_callback(LuaState *state) {
  ++lua_find_object_calls;
  if (!active_lua_api || !active_lua_api->push_nil) {
    return 0;
  }
  const char *query = lua_object_lookup_query_arg(state);
  const LuaObjectHandle *object = find_lua_object_by_path_or_name(query);
  if (object && push_lua_object_handle(active_lua_api, state, object)) {
    ++lua_find_object_hits;
    return 1;
  }
  active_lua_api->push_nil(state);
  return 1;
}

static int CDECL lua_find_first_of_callback(LuaState *state) {
  ++lua_find_first_of_calls;
  if (!active_lua_api || !active_lua_api->push_nil) {
    return 0;
  }
  size_t class_len = 0;
  const char *class_name = active_lua_api->to_lstring ? active_lua_api->to_lstring(state, 1, &class_len) : 0;
  const LuaObjectHandle *object = find_lua_object_by_class(class_name);
  if (object && push_lua_object_handle(active_lua_api, state, object)) {
    ++lua_find_first_of_hits;
    return 1;
  }
  active_lua_api->push_nil(state);
  return 1;
}

static int CDECL lua_get_known_objects_callback(LuaState *state) {
  ++lua_get_known_objects_calls;
  if (!active_lua_api || !active_lua_api->push_nil) {
    return 0;
  }
  size_t count = 0;
  if (push_known_lua_object_handles(active_lua_api, state, 0, &count)) {
    if (count > 0) {
      ++lua_get_known_objects_hits;
    }
    return 1;
  }
  active_lua_api->push_nil(state);
  return 1;
}

static int CDECL lua_find_objects_callback(LuaState *state) {
  ++lua_find_objects_calls;
  if (!active_lua_api || !active_lua_api->push_nil) {
    return 0;
  }
  const char *class_filter = active_lua_api->to_lstring ? active_lua_api->to_lstring(state, 1, 0) : 0;
  size_t count = 0;
  if (push_known_lua_object_handles(active_lua_api, state, class_filter, &count)) {
    if (count > 0) {
      ++lua_find_objects_hits;
    }
    return 1;
  }
  active_lua_api->push_nil(state);
  return 1;
}

static int CDECL lua_find_all_of_callback(LuaState *state) {
  ++lua_find_all_of_calls;
  if (!active_lua_api || !active_lua_api->push_nil) {
    return 0;
  }
  const char *class_filter = active_lua_api->to_lstring ? active_lua_api->to_lstring(state, 1, 0) : 0;
  size_t count = 0;
  if (push_known_lua_object_handles(active_lua_api, state, class_filter, &count)) {
    if (count > 0) {
      ++lua_find_all_of_hits;
    }
    return 1;
  }
  active_lua_api->push_nil(state);
  return 1;
}

static int CDECL lua_for_each_uobject_callback(LuaState *state) {
  ++lua_for_each_uobject_calls;
  if (!active_lua_api || !active_lua_api->type || !active_lua_api->push_value || !active_lua_api->set_top) {
    return 0;
  }
  if (active_lua_api->type(state, 1) != LUA_TFUNCTION_COMPAT) {
    return 0;
  }
  const char *class_filter = active_lua_api->to_lstring ? active_lua_api->to_lstring(state, 2, 0) : 0;
  for (size_t i = 0; i < lua_object_handle_count; ++i) {
    const LuaObjectHandle *object = &lua_object_handles[i];
    if (!lua_object_class_matches(object, class_filter)) {
      continue;
    }
    active_lua_api->push_value(state, 1);
    if (!push_lua_object_handle(active_lua_api, state, object) ||
        lua_call(active_lua_api, state, 1, 1, 0) != 0) {
      active_lua_api->set_top(state, 0);
      return 0;
    }
    ++lua_for_each_uobject_callbacks;
    int is_boolean = 0;
    int stop = lua_to_boolean(active_lua_api, state, -1, &is_boolean) && is_boolean;
    active_lua_api->set_top(state, -2);
    if (stop) {
      break;
    }
  }
  return 0;
}

static int CDECL lua_is_a_callback(LuaState *state) {
  ++lua_is_a_calls;
  if (!active_lua_api || !active_lua_api->push_boolean) {
    return 0;
  }
  uintptr_t address = lua_object_address_arg(active_lua_api, state, 1);
  const char *class_name = active_lua_api->to_lstring ? active_lua_api->to_lstring(state, 2, 0) : 0;
  const LuaObjectHandle *object = find_lua_object_by_address(address);
  int ok = object && class_name && class_name[0] && lua_object_class_matches(object, class_name);
  if (ok) {
    ++lua_is_a_hits;
  }
  active_lua_api->push_boolean(state, ok);
  return 1;
}

static int CDECL lua_find_function_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_nil) {
    return 0;
  }
  const char *query = lua_object_lookup_query_arg(state);
  const UeFunctionParamDescriptor *descriptor = find_ue_function_descriptor_by_path_or_name(query);
  if (descriptor && push_ue_function_handle_from_descriptor(active_lua_api, state, descriptor)) {
    return 1;
  }
  active_lua_api->push_nil(state);
  return 1;
}

static int CDECL lua_find_first_function_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_nil) {
    return 0;
  }
  for (size_t i = 0; i < ue_function_param_descriptor_count; ++i) {
    if (!ue_function_descriptor_seen_before(i) &&
        push_ue_function_handle_from_descriptor(active_lua_api, state, &ue_function_param_descriptors[i])) {
      return 1;
    }
  }
  active_lua_api->push_nil(state);
  return 1;
}

static int CDECL lua_get_known_functions_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_nil) {
    return 0;
  }
  if (push_known_ue_function_handles(active_lua_api, state, 0)) {
    return 1;
  }
  active_lua_api->push_nil(state);
  return 1;
}

static int CDECL lua_load_asset_callback(LuaState *state) {
  ++lua_load_asset_calls;
  if (!active_lua_api || !active_lua_api->push_nil) {
    return 0;
  }
  const char *query = active_lua_api->to_lstring ? active_lua_api->to_lstring(state, 1, 0) : 0;
  const LuaObjectHandle *object = find_lua_object_by_path_or_name(query);
  if (object && push_lua_object_handle(active_lua_api, state, object)) {
    ++lua_load_asset_hits;
    return 1;
  }
  active_lua_api->push_nil(state);
  return 1;
}

static void lua_copy_string_arg_or_field(
  LuaApi *api,
  LuaState *state,
  int index,
  const char *field,
  char *out,
  size_t out_size,
  const char *fallback
) {
  if (!out || out_size == 0) {
    return;
  }
  out[0] = '\0';
  const char *value = 0;
  if (api && state && field && api->type && api->type(state, index) == LUA_TTABLE_COMPAT && api->get_field && api->set_top) {
    api->get_field(state, index, field);
    value = api->to_lstring ? api->to_lstring(state, -1, 0) : 0;
    if (value && value[0]) {
      copy_string(out, out_size, value);
    }
    api->set_top(state, -2);
  } else if (api && state && api->to_lstring) {
    value = api->to_lstring(state, index, 0);
    if (value && value[0]) {
      copy_string(out, out_size, value);
    }
  }
  if (!out[0] && fallback) {
    copy_string(out, out_size, fallback);
  }
}

static void append_unsigned_to_cstr(char *dst, size_t dst_size, unsigned long long value) {
  if (!dst || dst_size == 0) {
    return;
  }
  size_t used = cstr_len(dst);
  if (used + 1 >= dst_size) {
    return;
  }
  char digits[32];
  size_t count = 0;
  do {
    digits[count++] = (char)('0' + (value % 10ULL));
    value /= 10ULL;
  } while (value && count < sizeof(digits));
  while (count && used + 1 < dst_size) {
    dst[used++] = digits[--count];
  }
  dst[used] = '\0';
}

static int CDECL lua_static_construct_object_callback(LuaState *state) {
  ++lua_static_construct_object_calls;
  if (!active_lua_api || !active_lua_api->push_nil || lua_object_handle_count >= MAX_LUA_OBJECT_HANDLES) {
    if (active_lua_api && active_lua_api->push_nil) {
      active_lua_api->push_nil(state);
      return 1;
    }
    return 0;
  }
  char class_name[MAX_LUA_CLASS_NAME];
  lua_copy_string_arg_or_field(active_lua_api, state, 1, "ClassName", class_name, sizeof(class_name), "ConstructedObjectClass");
  uintptr_t class_address = lua_object_uintptr_field_arg(active_lua_api, state, 1, "ClassAddress");
  if (str_equal(class_name, "UClass")) {
    class_address = lua_object_address_arg(active_lua_api, state, 1);
    lua_copy_string_arg_or_field(active_lua_api, state, 1, "Name", class_name, sizeof(class_name), "UClass");
  }
  char name[MAX_LUA_OBJECT_NAME];
  char default_name[MAX_LUA_OBJECT_NAME];
  copy_string(default_name, sizeof(default_name), "ConstructedObject");
  append_unsigned_to_cstr(default_name, sizeof(default_name), (unsigned long long)lua_static_construct_object_calls);
  lua_copy_string_arg_or_field(active_lua_api, state, 3, 0, name, sizeof(name), default_name);
  char path[MAX_LUA_OBJECT_PATH];
  if (name[0] == '/') {
    copy_string(path, sizeof(path), name);
  } else {
    copy_string(path, sizeof(path), "/RuntimeProbe/Constructed/");
    size_t used = cstr_len(path);
    if (used < sizeof(path)) {
      copy_string(path + used, sizeof(path) - used, name);
    }
  }
  uintptr_t address = (uintptr_t)&lua_object_handles[lua_object_handle_count];
  if (add_lua_object_handle(path, name, class_name, address)) {
    ++lua_static_construct_object_hits;
    LuaObjectHandle *constructed = &lua_object_handles[lua_object_handle_count - 1];
    constructed->class_address = class_address;
    constructed->outer_address = lua_object_address_arg(active_lua_api, state, 2);
    if (constructed->outer_address && find_lua_object_by_address(constructed->outer_address)) {
      ++lua_static_construct_object_outer_hits;
    }
    invoke_lua_notify_on_new_object(active_lua_api, state, constructed);
    return push_lua_object_handle(active_lua_api, state, constructed) ? 1 : 0;
  }
  active_lua_api->push_nil(state);
  return 1;
}

static int CDECL lua_notify_on_new_object_callback(LuaState *state) {
  ++lua_notify_on_new_object_calls;
  if (!active_lua_api) {
    return 0;
  }
  if (lua_notify_on_new_object_registration_count >= MAX_LUA_NOTIFY_ON_NEW_OBJECT_REGISTRATIONS) {
    return 0;
  }
  int callback_index = 2;
  char filter[MAX_LUA_OBJECT_PATH];
  filter[0] = '\0';
  if (active_lua_api->type && active_lua_api->type(state, 1) == LUA_TFUNCTION_COMPAT) {
    callback_index = 1;
  } else {
    lua_copy_string_arg_or_field(
      active_lua_api,
      state,
      1,
      "ClassName",
      filter,
      sizeof(filter),
      ""
    );
  }
  LuaNotifyOnNewObjectRegistration *registration =
    &lua_notify_on_new_object_registrations[lua_notify_on_new_object_registration_count];
  for (size_t i = 0; i < sizeof(*registration); ++i) {
    ((unsigned char *)registration)[i] = 0;
  }
  registration->ref = LUA_NOREF_COMPAT;
  copy_string(registration->filter, sizeof(registration->filter), filter);
  if (lua_store_hook_ref(active_lua_api, state, callback_index, &registration->ref)) {
    ++lua_notify_on_new_object_registration_count;
  }
  return 0;
}

static int CDECL lua_execute_in_game_thread_callback(LuaState *state) {
  ++lua_execute_in_game_thread_calls;
  if (!active_lua_api || !active_lua_api->type || !active_lua_api->push_value || !active_lua_api->ref) {
    return 0;
  }
  if (active_lua_api->type(state, 1) != LUA_TFUNCTION_COMPAT) {
    return 0;
  }
  active_lua_api->push_value(state, 1);
  int callback_ref = active_lua_api->ref(state, LUA_REGISTRYINDEX_COMPAT);
  int callback_status = invoke_lua_hook_ref(
    active_lua_api,
    state,
    callback_ref,
    &lua_execute_in_game_thread_callbacks,
    &lua_execute_in_game_thread_result,
    &lua_execute_in_game_thread_is_number
  );
  if (callback_status != 0) {
    lua_execute_in_game_thread_is_number = 0;
  }
  lua_unref_hook_ref(active_lua_api, state, &callback_ref);
  return 0;
}

static int lua_first_function_arg(LuaState *state) {
  if (!active_lua_api || !active_lua_api->type) {
    return 0;
  }
  for (int i = 1; i <= 3; ++i) {
    if (active_lua_api->type(state, i) == LUA_TFUNCTION_COMPAT) {
      return i;
    }
  }
  return 0;
}

static int lua_invoke_callback_arg(LuaState *state, int index) {
  if (!active_lua_api || index <= 0) {
    return 0;
  }
  int callback_ref = LUA_NOREF_COMPAT;
  if (!lua_store_hook_ref(active_lua_api, state, index, &callback_ref)) {
    return 0;
  }
  int status = invoke_lua_hook_ref(active_lua_api, state, callback_ref, 0, 0, 0);
  lua_unref_hook_ref(active_lua_api, state, &callback_ref);
  return status == 0;
}

static int CDECL lua_execute_async_callback(LuaState *state) {
  lua_invoke_callback_arg(state, lua_first_function_arg(state));
  return 0;
}

static int CDECL lua_execute_with_delay_callback(LuaState *state) {
  int callback_index = active_lua_api && active_lua_api->type &&
                       active_lua_api->type(state, 2) == LUA_TFUNCTION_COMPAT ? 2 : lua_first_function_arg(state);
  lua_invoke_callback_arg(state, callback_index);
  return 0;
}

static int CDECL lua_loop_async_callback(LuaState *state) {
  int callback_index = active_lua_api && active_lua_api->type &&
                       active_lua_api->type(state, 2) == LUA_TFUNCTION_COMPAT ? 2 : lua_first_function_arg(state);
  lua_invoke_callback_arg(state, callback_index);
  if (active_lua_api && active_lua_api->push_integer) {
    active_lua_api->push_integer(state, ++lua_compat_registration_count);
    return 1;
  }
  return 0;
}

static int CDECL lua_fname_callback(LuaState *state) {
  if (!active_lua_api) {
    return 0;
  }
  const char *name = active_lua_api->to_lstring ? active_lua_api->to_lstring(state, 1, 0) : 0;
  int is_number = 0;
  long long comparison_index = lua_to_integer(active_lua_api, state, 1, &is_number);
  return push_lua_fname_table(
    active_lua_api,
    state,
    name && name[0] ? name : "",
    is_number && (!name || !name[0]) ? comparison_index : 0,
    0,
    name && name[0]
  ) ? 1 : 0;
}

static int push_lua_ftext_table(LuaApi *api, LuaState *state, const char *text) {
  if (!api || !state || !api->create_table || !api->set_field || !api->push_string) {
    return 0;
  }
  const char *safe_text = text ? text : "";
  api->create_table(state, 0, 4);
  api->push_string(state, "FText");
  api->set_field(state, -2, "Kind");
  api->push_string(state, "text");
  api->set_field(state, -2, "Type");
  api->push_string(state, safe_text);
  api->set_field(state, -2, "Text");
  api->push_string(state, safe_text);
  api->set_field(state, -2, "ToString");
  return 1;
}

static int CDECL lua_ftext_callback(LuaState *state) {
  if (!active_lua_api) {
    return 0;
  }
  const char *text = active_lua_api->to_lstring ? active_lua_api->to_lstring(state, 1, 0) : 0;
  if (!push_lua_ftext_table(active_lua_api, state, text)) {
    return 0;
  }
  return 1;
}

static int CDECL lua_register_key_bind_callback(LuaState *state) {
  int callback_index = active_lua_api && active_lua_api->type &&
                       active_lua_api->type(state, 3) == LUA_TFUNCTION_COMPAT ? 3 : lua_first_function_arg(state);
  if (!active_lua_api || !active_lua_api->push_integer || callback_index == 0) {
    return 0;
  }
  active_lua_api->push_integer(state, ++lua_key_bind_registration_count);
  return 1;
}

static int CDECL lua_is_key_bind_registered_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_boolean) {
    return 0;
  }
  active_lua_api->push_boolean(state, lua_key_bind_registration_count > 0);
  return 1;
}

static int ascii_is_space(char ch) {
  return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r' || ch == '\f' || ch == '\v';
}

static void lua_split_console_command(
  const char *raw,
  char *command,
  size_t command_size,
  char *args,
  size_t args_size
) {
  if (command_size > 0) {
    command[0] = '\0';
  }
  if (args_size > 0) {
    args[0] = '\0';
  }
  if (!raw) {
    return;
  }
  while (ascii_is_space(*raw)) {
    ++raw;
  }
  size_t command_len = 0;
  while (raw[command_len] && !ascii_is_space(raw[command_len])) {
    ++command_len;
  }
  if (command && command_size > 0) {
    size_t copy_len = command_len < command_size ? command_len : command_size - 1;
    for (size_t i = 0; i < copy_len; ++i) {
      command[i] = raw[i];
    }
    command[copy_len] = '\0';
  }
  const char *arg_start = raw + command_len;
  while (ascii_is_space(*arg_start)) {
    ++arg_start;
  }
  if (args && args_size > 0 && arg_start[0]) {
    copy_string(args, args_size, arg_start);
  }
}

static int lua_console_command_matches(const LuaConsoleCommandRegistration *registration, const char *command) {
  if (!registration || !command || !command[0]) {
    return 0;
  }
  return registration->global ||
         !registration->name[0] ||
         str_equal(registration->name, command);
}

static int CDECL lua_register_console_command_handler_impl(LuaState *state, int global) {
  if (!active_lua_api || !active_lua_api->push_integer) {
    return 0;
  }
  int callback_index = lua_first_function_arg(state);
  if (callback_index == 0 || lua_console_command_registration_count >= MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS) {
    active_lua_api->push_integer(state, 0);
    return 1;
  }
  LuaConsoleCommandRegistration *registration =
    &lua_console_command_registrations[lua_console_command_registration_count];
  for (size_t i = 0; i < sizeof(*registration); ++i) {
    ((unsigned char *)registration)[i] = 0;
  }
  registration->ref = LUA_NOREF_COMPAT;
  registration->global = global;
  const char *name = active_lua_api->to_lstring ? active_lua_api->to_lstring(state, 1, 0) : 0;
  if (name && name[0] && callback_index != 1) {
    copy_string(registration->name, sizeof(registration->name), name);
  }
  if (!lua_store_hook_ref(active_lua_api, state, callback_index, &registration->ref)) {
    active_lua_api->push_integer(state, 0);
    return 1;
  }
  ++lua_console_command_registration_count;
  active_lua_api->push_integer(state, ++lua_compat_registration_count);
  return 1;
}

static int CDECL lua_register_console_command_handler_callback(LuaState *state) {
  return lua_register_console_command_handler_impl(state, 0);
}

static int CDECL lua_register_console_command_global_handler_callback(LuaState *state) {
  return lua_register_console_command_handler_impl(state, 1);
}

static int CDECL lua_register_process_console_exec_hook_impl(LuaState *state, int pre) {
  if (!active_lua_api || !active_lua_api->push_integer) {
    return 0;
  }
  int callback_index = lua_first_function_arg(state);
  LuaConsoleExecHookRegistration *registrations = pre
    ? lua_process_console_exec_pre_hook_registrations
    : lua_process_console_exec_post_hook_registrations;
  int *count = pre
    ? &lua_process_console_exec_pre_hook_registration_count
    : &lua_process_console_exec_post_hook_registration_count;
  if (callback_index == 0 || !count || *count >= MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS) {
    active_lua_api->push_integer(state, 0);
    return 1;
  }
  LuaConsoleExecHookRegistration *registration = &registrations[*count];
  for (size_t i = 0; i < sizeof(*registration); ++i) {
    ((unsigned char *)registration)[i] = 0;
  }
  registration->ref = LUA_NOREF_COMPAT;
  if (!lua_store_hook_ref(active_lua_api, state, callback_index, &registration->ref)) {
    active_lua_api->push_integer(state, 0);
    return 1;
  }
  ++*count;
  active_lua_api->push_integer(state, ++lua_compat_registration_count);
  return 1;
}

static int CDECL lua_register_process_console_exec_pre_hook_callback(LuaState *state) {
  return lua_register_process_console_exec_hook_impl(state, 1);
}

static int CDECL lua_register_process_console_exec_post_hook_callback(LuaState *state) {
  return lua_register_process_console_exec_hook_impl(state, 0);
}

static int CDECL lua_register_local_player_exec_hook_impl(LuaState *state, int pre) {
  if (!active_lua_api || !active_lua_api->push_integer) {
    return 0;
  }
  int callback_index = lua_first_function_arg(state);
  LuaConsoleExecHookRegistration *registrations = pre
    ? lua_local_player_exec_pre_hook_registrations
    : lua_local_player_exec_post_hook_registrations;
  int *count = pre
    ? &lua_local_player_exec_pre_hook_registration_count
    : &lua_local_player_exec_post_hook_registration_count;
  if (callback_index == 0 || !count || *count >= MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS) {
    active_lua_api->push_integer(state, 0);
    return 1;
  }
  LuaConsoleExecHookRegistration *registration = &registrations[*count];
  for (size_t i = 0; i < sizeof(*registration); ++i) {
    ((unsigned char *)registration)[i] = 0;
  }
  registration->ref = LUA_NOREF_COMPAT;
  if (!lua_store_hook_ref(active_lua_api, state, callback_index, &registration->ref)) {
    active_lua_api->push_integer(state, 0);
    return 1;
  }
  ++*count;
  active_lua_api->push_integer(state, ++lua_compat_registration_count);
  return 1;
}

static int CDECL lua_register_local_player_exec_pre_hook_callback(LuaState *state) {
  return lua_register_local_player_exec_hook_impl(state, 1);
}

static int CDECL lua_register_local_player_exec_post_hook_callback(LuaState *state) {
  return lua_register_local_player_exec_hook_impl(state, 0);
}

static int CDECL lua_register_call_function_hook_impl(LuaState *state, int pre) {
  if (!active_lua_api || !active_lua_api->push_integer) {
    return 0;
  }
  int callback_index = lua_first_function_arg(state);
  LuaCallFunctionHookRegistration *registrations = pre
    ? lua_call_function_pre_hook_registrations
    : lua_call_function_post_hook_registrations;
  int *count = pre
    ? &lua_call_function_pre_hook_registration_count
    : &lua_call_function_post_hook_registration_count;
  if (callback_index == 0 || !count || *count >= MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS) {
    active_lua_api->push_integer(state, 0);
    return 1;
  }
  LuaCallFunctionHookRegistration *registration = &registrations[*count];
  for (size_t i = 0; i < sizeof(*registration); ++i) {
    ((unsigned char *)registration)[i] = 0;
  }
  registration->ref = LUA_NOREF_COMPAT;
  if (!lua_store_hook_ref(active_lua_api, state, callback_index, &registration->ref)) {
    active_lua_api->push_integer(state, 0);
    return 1;
  }
  ++*count;
  active_lua_api->push_integer(state, ++lua_compat_registration_count);
  return 1;
}

static int CDECL lua_register_call_function_pre_hook_callback(LuaState *state) {
  return lua_register_call_function_hook_impl(state, 1);
}

static int CDECL lua_register_call_function_post_hook_callback(LuaState *state) {
  return lua_register_call_function_hook_impl(state, 0);
}

static void lua_push_arg_or_nil(LuaState *state, int index) {
  if (!active_lua_api || !active_lua_api->push_value || !active_lua_api->push_nil) {
    return;
  }
  int type = active_lua_api->type ? active_lua_api->type(state, index) : LUA_TNIL_COMPAT;
  if (type > LUA_TNIL_COMPAT) {
    active_lua_api->push_value(state, index);
  } else {
    active_lua_api->push_nil(state);
  }
}

static int lua_register_lifecycle_hook_impl(
  LuaState *state,
  LuaConsoleExecHookRegistration *registrations,
  int *count
) {
  if (!active_lua_api || !active_lua_api->push_integer || !registrations || !count) {
    return 0;
  }
  int callback_index = lua_first_function_arg(state);
  if (callback_index == 0 || *count >= MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS) {
    active_lua_api->push_integer(state, 0);
    return 1;
  }
  LuaConsoleExecHookRegistration *registration = &registrations[*count];
  for (size_t i = 0; i < sizeof(*registration); ++i) {
    ((unsigned char *)registration)[i] = 0;
  }
  registration->ref = LUA_NOREF_COMPAT;
  if (!lua_store_hook_ref(active_lua_api, state, callback_index, &registration->ref)) {
    active_lua_api->push_integer(state, 0);
    return 1;
  }
  ++*count;
  active_lua_api->push_integer(state, ++lua_compat_registration_count);
  return 1;
}

static int CDECL lua_register_load_map_pre_hook_callback(LuaState *state) {
  return lua_register_lifecycle_hook_impl(
    state,
    lua_load_map_pre_hook_registrations,
    &lua_load_map_pre_hook_registration_count
  );
}

static int CDECL lua_register_load_map_post_hook_callback(LuaState *state) {
  return lua_register_lifecycle_hook_impl(
    state,
    lua_load_map_post_hook_registrations,
    &lua_load_map_post_hook_registration_count
  );
}

static int CDECL lua_register_begin_play_pre_hook_callback(LuaState *state) {
  return lua_register_lifecycle_hook_impl(
    state,
    lua_begin_play_pre_hook_registrations,
    &lua_begin_play_pre_hook_registration_count
  );
}

static int CDECL lua_register_begin_play_post_hook_callback(LuaState *state) {
  return lua_register_lifecycle_hook_impl(
    state,
    lua_begin_play_post_hook_registrations,
    &lua_begin_play_post_hook_registration_count
  );
}

static int CDECL lua_register_init_game_state_pre_hook_callback(LuaState *state) {
  return lua_register_lifecycle_hook_impl(
    state,
    lua_init_game_state_pre_hook_registrations,
    &lua_init_game_state_pre_hook_registration_count
  );
}

static int CDECL lua_register_init_game_state_post_hook_callback(LuaState *state) {
  return lua_register_lifecycle_hook_impl(
    state,
    lua_init_game_state_post_hook_registrations,
    &lua_init_game_state_post_hook_registration_count
  );
}

static int CDECL lua_register_custom_event_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_integer) {
    return 0;
  }
  int callback_index = lua_first_function_arg(state);
  if (callback_index == 0 || lua_custom_event_registration_count >= MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS) {
    active_lua_api->push_integer(state, 0);
    return 1;
  }
  LuaCustomEventRegistration *registration = &lua_custom_event_registrations[lua_custom_event_registration_count];
  for (size_t i = 0; i < sizeof(*registration); ++i) {
    ((unsigned char *)registration)[i] = 0;
  }
  registration->ref = LUA_NOREF_COMPAT;
  const char *name = active_lua_api->to_lstring ? active_lua_api->to_lstring(state, 1, 0) : 0;
  if (name && name[0] && callback_index != 1) {
    copy_string(registration->name, sizeof(registration->name), name);
  }
  if (!lua_store_hook_ref(active_lua_api, state, callback_index, &registration->ref)) {
    active_lua_api->push_integer(state, 0);
    return 1;
  }
  ++lua_custom_event_registration_count;
  active_lua_api->push_integer(state, ++lua_compat_registration_count);
  return 1;
}

static int invoke_lua_console_command_handlers(LuaState *state, const char *raw_command) {
  if (!active_lua_api || !state || !raw_command || !raw_command[0] ||
      !active_lua_api->rawgeti || !active_lua_api->push_value || !active_lua_api->push_string ||
      !active_lua_api->set_top) {
    return 0;
  }
  char command[128];
  char args[MAX_LUA_OBJECT_PATH];
  lua_split_console_command(raw_command, command, sizeof(command), args, sizeof(args));
  for (int i = 0; i < lua_console_command_registration_count; ++i) {
    LuaConsoleCommandRegistration *registration = &lua_console_command_registrations[i];
    if (!lua_ref_is_valid(registration->ref) || !lua_console_command_matches(registration, command)) {
      continue;
    }
    active_lua_api->rawgeti(state, LUA_REGISTRYINDEX_COMPAT, registration->ref);
    active_lua_api->push_value(state, 1);
    active_lua_api->push_string(state, command);
    active_lua_api->push_string(state, args);
    int status = lua_call(active_lua_api, state, 3, 1, 0);
    if (status != 0) {
      active_lua_api->set_top(state, -2);
      continue;
    }
    ++registration->calls;
    int is_boolean = 0;
    int handled = lua_to_boolean(active_lua_api, state, -1, &is_boolean);
    active_lua_api->set_top(state, -2);
    if (is_boolean && handled) {
      ++registration->handled;
      return 1;
    }
  }
  return 0;
}

static int invoke_lua_process_console_exec_hooks(
  LuaState *state,
  int pre,
  const char *raw_command,
  const char *command,
  const char *args,
  int handled_so_far
) {
  if (!active_lua_api || !state || !active_lua_api->rawgeti || !active_lua_api->push_value ||
      !active_lua_api->push_string || !active_lua_api->push_boolean || !active_lua_api->set_top) {
    return 0;
  }
  LuaConsoleExecHookRegistration *registrations = pre
    ? lua_process_console_exec_pre_hook_registrations
    : lua_process_console_exec_post_hook_registrations;
  int count = pre
    ? lua_process_console_exec_pre_hook_registration_count
    : lua_process_console_exec_post_hook_registration_count;
  if (count > MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS) {
    count = MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS;
  }
  int handled = 0;
  for (int i = 0; i < count; ++i) {
    LuaConsoleExecHookRegistration *registration = &registrations[i];
    if (!lua_ref_is_valid(registration->ref)) {
      continue;
    }
    active_lua_api->rawgeti(state, LUA_REGISTRYINDEX_COMPAT, registration->ref);
    active_lua_api->push_value(state, 1);
    active_lua_api->push_string(state, raw_command ? raw_command : "");
    active_lua_api->push_string(state, command ? command : "");
    active_lua_api->push_string(state, args ? args : "");
    active_lua_api->push_boolean(state, handled_so_far || handled);
    registration->status = lua_call(active_lua_api, state, 5, 1, 0);
    if (registration->status != 0) {
      active_lua_api->set_top(state, -2);
      continue;
    }
    ++registration->calls;
    int is_boolean = 0;
    int hook_handled = lua_to_boolean(active_lua_api, state, -1, &is_boolean);
    active_lua_api->set_top(state, -2);
    if (is_boolean && hook_handled) {
      ++registration->handled;
      handled = 1;
    }
  }
  return handled;
}

static int invoke_lua_local_player_exec_hooks(
  LuaState *state,
  int pre,
  const char *raw_command,
  const char *command,
  const char *args,
  int handled_so_far
) {
  if (!active_lua_api || !state || !active_lua_api->rawgeti || !active_lua_api->push_value ||
      !active_lua_api->push_string || !active_lua_api->push_boolean || !active_lua_api->set_top) {
    return 0;
  }
  LuaConsoleExecHookRegistration *registrations = pre
    ? lua_local_player_exec_pre_hook_registrations
    : lua_local_player_exec_post_hook_registrations;
  int count = pre
    ? lua_local_player_exec_pre_hook_registration_count
    : lua_local_player_exec_post_hook_registration_count;
  if (count > MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS) {
    count = MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS;
  }
  int handled = 0;
  for (int i = 0; i < count; ++i) {
    LuaConsoleExecHookRegistration *registration = &registrations[i];
    if (!lua_ref_is_valid(registration->ref)) {
      continue;
    }
    active_lua_api->rawgeti(state, LUA_REGISTRYINDEX_COMPAT, registration->ref);
    active_lua_api->push_value(state, 1);
    active_lua_api->push_string(state, raw_command ? raw_command : "");
    active_lua_api->push_string(state, command ? command : "");
    active_lua_api->push_string(state, args ? args : "");
    active_lua_api->push_boolean(state, handled_so_far || handled);
    registration->status = lua_call(active_lua_api, state, 5, 1, 0);
    if (registration->status != 0) {
      active_lua_api->set_top(state, -2);
      continue;
    }
    ++registration->calls;
    int is_boolean = 0;
    int hook_handled = lua_to_boolean(active_lua_api, state, -1, &is_boolean);
    active_lua_api->set_top(state, -2);
    if (is_boolean && hook_handled) {
      ++registration->handled;
      handled = 1;
    }
  }
  return handled;
}

static int invoke_lua_call_function_hooks(
  LuaState *state,
  int pre,
  const char *function,
  const char *args,
  int handled_so_far,
  int result_is_on_stack
) {
  if (!active_lua_api || !state || !active_lua_api->rawgeti || !active_lua_api->push_value ||
      !active_lua_api->push_string || !active_lua_api->push_boolean || !active_lua_api->push_nil ||
      !active_lua_api->set_top) {
    return 0;
  }
  LuaCallFunctionHookRegistration *registrations = pre
    ? lua_call_function_pre_hook_registrations
    : lua_call_function_post_hook_registrations;
  int count = pre ? lua_call_function_pre_hook_registration_count : lua_call_function_post_hook_registration_count;
  if (count > MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS) {
    count = MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS;
  }
  for (int i = 0; i < count; ++i) {
    LuaCallFunctionHookRegistration *registration = &registrations[i];
    if (!lua_ref_is_valid(registration->ref)) {
      continue;
    }
    active_lua_api->rawgeti(state, LUA_REGISTRYINDEX_COMPAT, registration->ref);
    active_lua_api->push_value(state, 1);
    active_lua_api->push_string(state, function ? function : "");
    active_lua_api->push_string(state, args ? args : "");
    active_lua_api->push_boolean(state, handled_so_far);
    if (result_is_on_stack) {
      active_lua_api->push_value(state, -6);
    } else {
      active_lua_api->push_nil(state);
    }
    registration->status = lua_call(active_lua_api, state, 5, 2, 0);
    if (registration->status != 0) {
      active_lua_api->set_top(state, -2);
      continue;
    }
    ++registration->calls;
    int is_boolean = 0;
    int hook_handled = lua_to_boolean(active_lua_api, state, -1, &is_boolean);
    if (is_boolean && hook_handled) {
      ++registration->handled;
      active_lua_api->push_value(state, -2);
      return 1;
    }
    active_lua_api->set_top(state, -3);
  }
  return 0;
}

static int invoke_lua_lifecycle_hooks(
  LuaState *state,
  LuaConsoleExecHookRegistration *registrations,
  int count,
  int context_index,
  const char *event_name,
  const char *payload,
  int handled_so_far
) {
  if (!active_lua_api || !state || !registrations || !active_lua_api->rawgeti ||
      !active_lua_api->push_string || !active_lua_api->push_boolean || !active_lua_api->set_top) {
    return 0;
  }
  if (count > MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS) {
    count = MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS;
  }
  int handled = 0;
  for (int i = 0; i < count; ++i) {
    LuaConsoleExecHookRegistration *registration = &registrations[i];
    if (!lua_ref_is_valid(registration->ref)) {
      continue;
    }
    active_lua_api->rawgeti(state, LUA_REGISTRYINDEX_COMPAT, registration->ref);
    lua_push_arg_or_nil(state, context_index);
    active_lua_api->push_string(state, event_name ? event_name : "");
    active_lua_api->push_string(state, payload ? payload : "");
    active_lua_api->push_boolean(state, handled_so_far || handled);
    registration->status = lua_call(active_lua_api, state, 4, 1, 0);
    if (registration->status != 0) {
      active_lua_api->set_top(state, -2);
      continue;
    }
    ++registration->calls;
    int is_boolean = 0;
    int hook_handled = lua_to_boolean(active_lua_api, state, -1, &is_boolean);
    active_lua_api->set_top(state, -2);
    if (is_boolean && hook_handled) {
      ++registration->handled;
      handled = 1;
    }
  }
  return handled;
}

static int lua_custom_event_matches(const LuaCustomEventRegistration *registration, const char *event_name) {
  if (!registration || !event_name || !event_name[0]) {
    return 0;
  }
  return !registration->name[0] || str_equal(registration->name, event_name);
}

static int invoke_lua_custom_events(
  LuaState *state,
  const char *event_name,
  int context_index,
  const char *payload
) {
  if (!active_lua_api || !state || !event_name || !event_name[0] ||
      !active_lua_api->rawgeti || !active_lua_api->push_string ||
      !active_lua_api->push_boolean || !active_lua_api->set_top) {
    return 0;
  }
  int count = lua_custom_event_registration_count;
  if (count > MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS) {
    count = MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS;
  }
  int handled = 0;
  for (int i = 0; i < count; ++i) {
    LuaCustomEventRegistration *registration = &lua_custom_event_registrations[i];
    if (!lua_ref_is_valid(registration->ref) || !lua_custom_event_matches(registration, event_name)) {
      continue;
    }
    active_lua_api->rawgeti(state, LUA_REGISTRYINDEX_COMPAT, registration->ref);
    lua_push_arg_or_nil(state, context_index);
    active_lua_api->push_string(state, event_name);
    active_lua_api->push_string(state, payload ? payload : "");
    active_lua_api->push_boolean(state, handled);
    registration->status = lua_call(active_lua_api, state, 4, 1, 0);
    if (registration->status != 0) {
      active_lua_api->set_top(state, -2);
      continue;
    }
    ++registration->calls;
    int is_boolean = 0;
    int event_handled = lua_to_boolean(active_lua_api, state, -1, &is_boolean);
    active_lua_api->set_top(state, -2);
    if (is_boolean && event_handled) {
      ++registration->handled;
      handled = 1;
    }
  }
  return handled;
}

static int lua_dispatch_lifecycle_event_impl(
  LuaState *state,
  const char *event_name,
  LuaConsoleExecHookRegistration *pre_registrations,
  int pre_count,
  LuaConsoleExecHookRegistration *post_registrations,
  int post_count
) {
  if (!active_lua_api || !active_lua_api->push_boolean) {
    return 0;
  }
  const char *payload = active_lua_api->to_lstring ? active_lua_api->to_lstring(state, 2, 0) : 0;
  int handled = invoke_lua_lifecycle_hooks(
    state,
    pre_registrations,
    pre_count,
    1,
    event_name,
    payload,
    0
  );
  int post_handled = invoke_lua_lifecycle_hooks(
    state,
    post_registrations,
    post_count,
    1,
    event_name,
    payload,
    handled
  );
  active_lua_api->push_boolean(state, handled || post_handled);
  return 1;
}

static int CDECL lua_ue4ssl_probe_load_map_callback(LuaState *state) {
  return lua_dispatch_lifecycle_event_impl(
    state,
    "LoadMap",
    lua_load_map_pre_hook_registrations,
    lua_load_map_pre_hook_registration_count,
    lua_load_map_post_hook_registrations,
    lua_load_map_post_hook_registration_count
  );
}

static int CDECL lua_ue4ssl_probe_begin_play_callback(LuaState *state) {
  return lua_dispatch_lifecycle_event_impl(
    state,
    "BeginPlay",
    lua_begin_play_pre_hook_registrations,
    lua_begin_play_pre_hook_registration_count,
    lua_begin_play_post_hook_registrations,
    lua_begin_play_post_hook_registration_count
  );
}

static int CDECL lua_ue4ssl_probe_init_game_state_callback(LuaState *state) {
  return lua_dispatch_lifecycle_event_impl(
    state,
    "InitGameState",
    lua_init_game_state_pre_hook_registrations,
    lua_init_game_state_pre_hook_registration_count,
    lua_init_game_state_post_hook_registrations,
    lua_init_game_state_post_hook_registration_count
  );
}

static int CDECL lua_ue4ssl_probe_dispatch_custom_event_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_boolean) {
    return 0;
  }
  const char *event_name = active_lua_api->to_lstring ? active_lua_api->to_lstring(state, 1, 0) : 0;
  const char *payload = active_lua_api->to_lstring ? active_lua_api->to_lstring(state, 3, 0) : 0;
  int handled = invoke_lua_custom_events(state, event_name, 2, payload);
  active_lua_api->push_boolean(state, handled);
  return 1;
}

static int lua_console_exec_hook_call_sum(const LuaConsoleExecHookRegistration *registrations, int count) {
  if (!registrations || count <= 0) {
    return 0;
  }
  if (count > MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS) {
    count = MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS;
  }
  int sum = 0;
  for (int i = 0; i < count; ++i) {
    sum += registrations[i].calls;
  }
  return sum;
}

static int lua_console_exec_hook_handled_sum(const LuaConsoleExecHookRegistration *registrations, int count) {
  if (!registrations || count <= 0) {
    return 0;
  }
  if (count > MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS) {
    count = MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS;
  }
  int sum = 0;
  for (int i = 0; i < count; ++i) {
    sum += registrations[i].handled;
  }
  return sum;
}

static int lua_call_function_hook_call_sum(const LuaCallFunctionHookRegistration *registrations, int count) {
  if (!registrations || count <= 0) {
    return 0;
  }
  if (count > MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS) {
    count = MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS;
  }
  int sum = 0;
  for (int i = 0; i < count; ++i) {
    sum += registrations[i].calls;
  }
  return sum;
}

static int lua_call_function_hook_handled_sum(const LuaCallFunctionHookRegistration *registrations, int count) {
  if (!registrations || count <= 0) {
    return 0;
  }
  if (count > MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS) {
    count = MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS;
  }
  int sum = 0;
  for (int i = 0; i < count; ++i) {
    sum += registrations[i].handled;
  }
  return sum;
}

static int lua_custom_event_call_sum(const LuaCustomEventRegistration *registrations, int count) {
  if (!registrations || count <= 0) {
    return 0;
  }
  if (count > MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS) {
    count = MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS;
  }
  int sum = 0;
  for (int i = 0; i < count; ++i) {
    sum += registrations[i].calls;
  }
  return sum;
}

static int lua_custom_event_handled_sum(const LuaCustomEventRegistration *registrations, int count) {
  if (!registrations || count <= 0) {
    return 0;
  }
  if (count > MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS) {
    count = MAX_LUA_CONSOLE_COMMAND_REGISTRATIONS;
  }
  int sum = 0;
  for (int i = 0; i < count; ++i) {
    sum += registrations[i].handled;
  }
  return sum;
}

static int CDECL lua_register_custom_property_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_integer) {
    return 0;
  }
  if (!active_lua_api->type || active_lua_api->type(state, 1) != LUA_TTABLE_COMPAT) {
    return 0;
  }
  active_lua_api->push_integer(state, ++lua_compat_registration_count);
  return 1;
}

static int CDECL lua_ue4ss_get_version_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_integer) {
    return 0;
  }
  active_lua_api->push_integer(state, 3);
  active_lua_api->push_integer(state, 0);
  active_lua_api->push_integer(state, 0);
  return 3;
}

static int lua_unreal_version_major(void) {
  return env_int("UE4SSL_WIN_UNREAL_VERSION_MAJOR", 5);
}

static int lua_unreal_version_minor(void) {
  return env_int("UE4SSL_WIN_UNREAL_VERSION_MINOR", 0);
}

static int lua_unreal_version_arg_offset(LuaState *state) {
  return active_lua_api && active_lua_api->type &&
         active_lua_api->type(state, 1) == LUA_TTABLE_COMPAT ? 1 : 0;
}

static int CDECL lua_unreal_version_get_major_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_integer) {
    return 0;
  }
  active_lua_api->push_integer(state, lua_unreal_version_major());
  return 1;
}

static int CDECL lua_unreal_version_get_minor_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_integer) {
    return 0;
  }
  active_lua_api->push_integer(state, lua_unreal_version_minor());
  return 1;
}

static int lua_unreal_version_compare_args(LuaState *state, int *major, int *minor) {
  if (!active_lua_api || !major || !minor) {
    return 0;
  }
  int offset = lua_unreal_version_arg_offset(state);
  int major_is_number = 0;
  int minor_is_number = 0;
  long long major_value = lua_to_integer(active_lua_api, state, 1 + offset, &major_is_number);
  long long minor_value = lua_to_integer(active_lua_api, state, 2 + offset, &minor_is_number);
  if (!major_is_number) {
    return 0;
  }
  *major = (int)major_value;
  *minor = minor_is_number ? (int)minor_value : 0;
  return 1;
}

static int lua_unreal_version_push_compare(LuaState *state, int mode) {
  if (!active_lua_api || !active_lua_api->push_boolean) {
    return 0;
  }
  int want_major = 0;
  int want_minor = 0;
  int ok = lua_unreal_version_compare_args(state, &want_major, &want_minor);
  int have_major = lua_unreal_version_major();
  int have_minor = lua_unreal_version_minor();
  int cmp = (have_major == want_major) ? (have_minor - want_minor) : (have_major - want_major);
  int result = 0;
  if (ok) {
    if (mode == 0) result = (cmp == 0);
    if (mode == 1) result = (cmp >= 0);
    if (mode == 2) result = (cmp <= 0);
    if (mode == 3) result = (cmp < 0);
    if (mode == 4) result = (cmp > 0);
  }
  active_lua_api->push_boolean(state, result);
  return 1;
}

static int CDECL lua_unreal_version_is_equal_callback(LuaState *state) {
  return lua_unreal_version_push_compare(state, 0);
}

static int CDECL lua_unreal_version_is_at_least_callback(LuaState *state) {
  return lua_unreal_version_push_compare(state, 1);
}

static int CDECL lua_unreal_version_is_at_most_callback(LuaState *state) {
  return lua_unreal_version_push_compare(state, 2);
}

static int CDECL lua_unreal_version_is_below_callback(LuaState *state) {
  return lua_unreal_version_push_compare(state, 3);
}

static int CDECL lua_unreal_version_is_above_callback(LuaState *state) {
  return lua_unreal_version_push_compare(state, 4);
}

static LuaSharedVariable *find_lua_shared_variable(const char *name, int create) {
  if (!name || !name[0]) {
    return 0;
  }
  for (size_t i = 0; i < lua_shared_variable_count; ++i) {
    if (str_equal(lua_shared_variables[i].name, name)) {
      return &lua_shared_variables[i];
    }
  }
  if (!create || lua_shared_variable_count >= MAX_LUA_SHARED_VARIABLES) {
    return 0;
  }
  LuaSharedVariable *slot = &lua_shared_variables[lua_shared_variable_count++];
  for (size_t i = 0; i < sizeof(*slot); ++i) {
    ((unsigned char *)slot)[i] = 0;
  }
  copy_string(slot->name, sizeof(slot->name), name);
  return slot;
}

static int lua_modref_name_arg_index(LuaState *state) {
  return active_lua_api && active_lua_api->type &&
         active_lua_api->type(state, 1) == LUA_TTABLE_COMPAT ? 2 : 1;
}

static int CDECL lua_modref_set_shared_variable_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->type) {
    return 0;
  }
  int name_index = lua_modref_name_arg_index(state);
  const char *name = active_lua_api->to_lstring ? active_lua_api->to_lstring(state, name_index, 0) : 0;
  LuaSharedVariable *slot = find_lua_shared_variable(name, 1);
  if (!slot) {
    return 0;
  }
  int value_index = name_index + 1;
  int value_type = active_lua_api->type(state, value_index);
  slot->type = value_type;
  slot->integer_value = 0;
  slot->boolean_value = 0;
  slot->object_address = 0;
  slot->string_value[0] = '\0';
  if (value_type == LUA_TNIL_COMPAT) {
    return 0;
  }
  if (value_type == LUA_TBOOLEAN_COMPAT) {
    int is_boolean = 0;
    slot->boolean_value = lua_to_boolean(active_lua_api, state, value_index, &is_boolean);
    slot->type = is_boolean ? LUA_TBOOLEAN_COMPAT : LUA_TNIL_COMPAT;
    return 0;
  }
  if (value_type == LUA_TNUMBER_COMPAT) {
    int is_number = 0;
    slot->integer_value = lua_to_integer(active_lua_api, state, value_index, &is_number);
    slot->type = is_number ? LUA_TNUMBER_COMPAT : LUA_TNIL_COMPAT;
    return 0;
  }
  if (value_type == LUA_TTABLE_COMPAT) {
    slot->object_address = lua_object_address_arg(active_lua_api, state, value_index);
    slot->type = slot->object_address ? LUA_TTABLE_COMPAT : LUA_TNIL_COMPAT;
    return 0;
  }
  const char *value = active_lua_api->to_lstring ? active_lua_api->to_lstring(state, value_index, 0) : 0;
  if (value) {
    copy_string(slot->string_value, sizeof(slot->string_value), value);
    slot->type = LUA_TSTRING_COMPAT;
  }
  return 0;
}

static int CDECL lua_modref_get_shared_variable_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_nil) {
    return 0;
  }
  int name_index = lua_modref_name_arg_index(state);
  const char *name = active_lua_api->to_lstring ? active_lua_api->to_lstring(state, name_index, 0) : 0;
  LuaSharedVariable *slot = find_lua_shared_variable(name, 0);
  if (!slot || slot->type == LUA_TNIL_COMPAT) {
    active_lua_api->push_nil(state);
    return 1;
  }
  if (slot->type == LUA_TBOOLEAN_COMPAT && active_lua_api->push_boolean) {
    active_lua_api->push_boolean(state, slot->boolean_value);
    return 1;
  }
  if (slot->type == LUA_TNUMBER_COMPAT && active_lua_api->push_integer) {
    active_lua_api->push_integer(state, slot->integer_value);
    return 1;
  }
  if (slot->type == LUA_TTABLE_COMPAT) {
    const LuaObjectHandle *object = find_lua_object_by_address(slot->object_address);
    if (object && push_lua_object_handle(active_lua_api, state, object)) {
      return 1;
    }
    active_lua_api->push_nil(state);
    return 1;
  }
  if (slot->type == LUA_TSTRING_COMPAT && active_lua_api->push_string) {
    active_lua_api->push_string(state, slot->string_value);
    return 1;
  }
  active_lua_api->push_nil(state);
  return 1;
}

static int CDECL lua_modref_type_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_string) {
    return 0;
  }
  active_lua_api->push_string(state, "ModRef");
  return 1;
}

static void lua_join_win_path(char *out, size_t out_size, const char *base, const char *leaf) {
  if (!out || out_size == 0) {
    return;
  }
  static Line line;
  line_init(&line);
  line_append(&line, base && base[0] ? base : ".");
  size_t len = line.len;
  if (len > 0 && line.text[len - 1] != '\\' && line.text[len - 1] != '/') {
    line_append_char(&line, '\\');
  }
  line_append(&line, leaf ? leaf : "");
  copy_string(out, out_size, line.text);
}

static int CDECL lua_iterate_game_directories_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->create_table || !active_lua_api->set_field ||
      !active_lua_api->push_string) {
    return 0;
  }
  static char game_dir[MAX_LUA_SCRIPT_PATH];
  if (env_get("UE4SSL_WIN_GAME_DIR", game_dir, sizeof(game_dir)) == 0 || !game_dir[0]) {
    if (GetModuleFileNameA(0, game_dir, (DWORD)sizeof(game_dir)) == 0) {
      copy_string(game_dir, sizeof(game_dir), ".");
    } else {
      size_t len = cstr_len(game_dir);
      int stripped = 0;
      while (len > 0) {
        --len;
        if (game_dir[len] == '\\' || game_dir[len] == '/') {
          game_dir[len] = '\0';
          stripped = 1;
          break;
        }
      }
      if (!stripped || !game_dir[0]) {
        copy_string(game_dir, sizeof(game_dir), ".");
      }
    }
  }
  static char binaries_dir[MAX_LUA_SCRIPT_PATH];
  static char linux_dir[MAX_LUA_SCRIPT_PATH];
  static char win64_dir[MAX_LUA_SCRIPT_PATH];
  lua_join_win_path(binaries_dir, sizeof(binaries_dir), game_dir, "Binaries");
  lua_join_win_path(linux_dir, sizeof(linux_dir), binaries_dir, "Linux");
  lua_join_win_path(win64_dir, sizeof(win64_dir), binaries_dir, "Win64");

  active_lua_api->create_table(state, 0, 1);
  active_lua_api->create_table(state, 0, 4);
  active_lua_api->push_string(state, "Game");
  active_lua_api->set_field(state, -2, "__name");
  active_lua_api->push_string(state, game_dir);
  active_lua_api->set_field(state, -2, "__absolute_path");
  active_lua_api->create_table(state, 0, 4);
  active_lua_api->push_string(state, "Binaries");
  active_lua_api->set_field(state, -2, "__name");
  active_lua_api->push_string(state, binaries_dir);
  active_lua_api->set_field(state, -2, "__absolute_path");
  active_lua_api->create_table(state, 0, 2);
  active_lua_api->push_string(state, "Linux");
  active_lua_api->set_field(state, -2, "__name");
  active_lua_api->push_string(state, linux_dir);
  active_lua_api->set_field(state, -2, "__absolute_path");
  active_lua_api->set_field(state, -2, "Linux");
  active_lua_api->create_table(state, 0, 2);
  active_lua_api->push_string(state, "Win64");
  active_lua_api->set_field(state, -2, "__name");
  active_lua_api->push_string(state, win64_dir);
  active_lua_api->set_field(state, -2, "__absolute_path");
  active_lua_api->set_field(state, -2, "Win64");
  active_lua_api->set_field(state, -2, "Binaries");
  active_lua_api->set_field(state, -2, "Game");
  return 1;
}

static void lua_set_integer_field(LuaApi *api, LuaState *state, const char *name, long long value) {
  if (!api || !state || !name || !api->push_integer || !api->set_field) {
    return;
  }
  api->push_integer(state, value);
  api->set_field(state, -2, name);
}

static void lua_set_string_field(LuaApi *api, LuaState *state, const char *name, const char *value) {
  if (!api || !state || !name || !value || !api->push_string || !api->set_field) {
    return;
  }
  api->push_string(state, value);
  api->set_field(state, -2, name);
}

static void register_lua_compat_constant_tables(LuaApi *api, LuaState *state) {
  if (!api || !state || !api->create_table || !api->set_global) {
    return;
  }
  api->create_table(state, 0, 28);
  lua_set_integer_field(api, state, "RF_NoFlags", 0x00000000LL);
  lua_set_integer_field(api, state, "RF_Public", 0x00000001LL);
  lua_set_integer_field(api, state, "RF_Standalone", 0x00000002LL);
  lua_set_integer_field(api, state, "RF_MarkAsNative", 0x00000004LL);
  lua_set_integer_field(api, state, "RF_Transactional", 0x00000008LL);
  lua_set_integer_field(api, state, "RF_ClassDefaultObject", 0x00000010LL);
  lua_set_integer_field(api, state, "RF_ArchetypeObject", 0x00000020LL);
  lua_set_integer_field(api, state, "RF_Transient", 0x00000040LL);
  lua_set_integer_field(api, state, "RF_MarkAsRootSet", 0x00000080LL);
  lua_set_integer_field(api, state, "RF_TagGarbageTemp", 0x00000100LL);
  lua_set_integer_field(api, state, "RF_NeedInitialization", 0x00000200LL);
  lua_set_integer_field(api, state, "RF_NeedLoad", 0x00000400LL);
  lua_set_integer_field(api, state, "RF_KeepForCooker", 0x00000800LL);
  lua_set_integer_field(api, state, "RF_NeedPostLoad", 0x00001000LL);
  lua_set_integer_field(api, state, "RF_NeedPostLoadSubobjects", 0x00002000LL);
  lua_set_integer_field(api, state, "RF_NewerVersionExists", 0x00004000LL);
  lua_set_integer_field(api, state, "RF_BeginDestroyed", 0x00008000LL);
  lua_set_integer_field(api, state, "RF_FinishDestroyed", 0x00010000LL);
  lua_set_integer_field(api, state, "RF_BeingRegenerated", 0x00020000LL);
  lua_set_integer_field(api, state, "RF_DefaultSubObject", 0x00040000LL);
  lua_set_integer_field(api, state, "RF_WasLoaded", 0x00080000LL);
  lua_set_integer_field(api, state, "RF_TextExportTransient", 0x00100000LL);
  lua_set_integer_field(api, state, "RF_LoadCompleted", 0x00200000LL);
  lua_set_integer_field(api, state, "RF_InheritableComponentTemplate", 0x00400000LL);
  lua_set_integer_field(api, state, "RF_DuplicateTransient", 0x00800000LL);
  lua_set_integer_field(api, state, "RF_StrongRefOnFrame", 0x01000000LL);
  lua_set_integer_field(api, state, "RF_NonPIEDuplicateTransient", 0x01000000LL);
  lua_set_integer_field(api, state, "RF_Dynamic", 0x02000000LL);
  lua_set_integer_field(api, state, "RF_WillBeLoaded", 0x04000000LL);
  lua_set_integer_field(api, state, "RF_HasExternalPackage", 0x08000000LL);
  lua_set_integer_field(api, state, "RF_AllFlags", 0x0fffffffLL);
  api->set_global(state, "EObjectFlags");

  api->create_table(state, 0, 10);
  lua_set_integer_field(api, state, "ReachableInCluster", 0x00800000LL);
  lua_set_integer_field(api, state, "ClusterRoot", 0x01000000LL);
  lua_set_integer_field(api, state, "Native", UE_INTERNAL_OBJECT_FLAG_NATIVE);
  lua_set_integer_field(api, state, "Async", 0x04000000LL);
  lua_set_integer_field(api, state, "AsyncLoading", 0x08000000LL);
  lua_set_integer_field(api, state, "Unreachable", 0x10000000LL);
  lua_set_integer_field(api, state, "PendingKill", 0x20000000LL);
  lua_set_integer_field(api, state, "RootSet", 0x40000000LL);
  lua_set_integer_field(api, state, "GarbageCollectionKeepFlags", 0x0e000000LL);
  lua_set_integer_field(api, state, "AllFlags", 0x7f800000LL);
  api->set_global(state, "EInternalObjectFlags");

  api->create_table(state, 0, 22);
  const char *property_types[] = {
    "ObjectProperty", "ObjectPtrProperty", "Int8Property", "Int16Property",
    "IntProperty", "Int64Property", "NameProperty", "FloatProperty",
    "DoubleProperty",
    "StrProperty", "ByteProperty", "UInt16Property", "UIntProperty",
    "UInt64Property", "BoolProperty", "ArrayProperty", "MapProperty",
    "StructProperty", "ClassProperty", "WeakObjectProperty", "EnumProperty",
    "TextProperty"
  };
  for (size_t i = 0; i < sizeof(property_types) / sizeof(property_types[0]); ++i) {
    lua_set_string_field(api, state, property_types[i], property_types[i]);
  }
  api->set_global(state, "PropertyTypes");

  api->create_table(state, 0, 48);
  for (int ch = 'A'; ch <= 'Z'; ++ch) {
    char key_name[2] = {(char)ch, '\0'};
    lua_set_integer_field(api, state, key_name, ch);
  }
  lua_set_integer_field(api, state, "SPACE", 0x20);
  lua_set_integer_field(api, state, "ENTER", 0x0d);
  lua_set_integer_field(api, state, "ESCAPE", 0x1b);
  lua_set_integer_field(api, state, "TAB", 0x09);
  lua_set_integer_field(api, state, "F1", 0x70);
  lua_set_integer_field(api, state, "F2", 0x71);
  lua_set_integer_field(api, state, "F3", 0x72);
  lua_set_integer_field(api, state, "F4", 0x73);
  api->set_global(state, "Key");

  api->create_table(state, 0, 5);
  lua_set_integer_field(api, state, "SHIFT", 0x10);
  lua_set_integer_field(api, state, "CONTROL", 0x11);
  lua_set_integer_field(api, state, "CTRL", 0x11);
  lua_set_integer_field(api, state, "ALT", 0x12);
  api->set_global(state, "ModifierKey");
  api->create_table(state, 0, 5);
  lua_set_integer_field(api, state, "SHIFT", 0x10);
  lua_set_integer_field(api, state, "CONTROL", 0x11);
  lua_set_integer_field(api, state, "CTRL", 0x11);
  lua_set_integer_field(api, state, "ALT", 0x12);
  api->set_global(state, "ModifierKeys");
}

static void register_lua_compat_metadata_tables(LuaApi *api, LuaState *state) {
  if (!api || !state || !api->create_table || !api->set_field || !api->set_global ||
      !api->push_cclosure || !api->push_string || !api->push_integer) {
    return;
  }
  api->create_table(state, 0, 4);
  set_lua_object_method(api, state, "GetVersion", lua_ue4ss_get_version_callback);
  lua_set_string_field(api, state, "Version", "3.0.0-ue4sslinux");
  lua_set_string_field(api, state, "Compatibility", "ue4ss-lua-shim");
  api->set_global(state, "UE4SS");

  api->create_table(state, 0, 8);
  lua_set_integer_field(api, state, "Major", lua_unreal_version_major());
  lua_set_integer_field(api, state, "Minor", lua_unreal_version_minor());
  set_lua_object_method(api, state, "GetMajor", lua_unreal_version_get_major_callback);
  set_lua_object_method(api, state, "GetMinor", lua_unreal_version_get_minor_callback);
  set_lua_object_method(api, state, "IsEqual", lua_unreal_version_is_equal_callback);
  set_lua_object_method(api, state, "IsAtLeast", lua_unreal_version_is_at_least_callback);
  set_lua_object_method(api, state, "IsAtMost", lua_unreal_version_is_at_most_callback);
  set_lua_object_method(api, state, "IsBelow", lua_unreal_version_is_below_callback);
  set_lua_object_method(api, state, "IsAbove", lua_unreal_version_is_above_callback);
  api->set_global(state, "UnrealVersion");

  api->create_table(state, 0, 8);
  lua_set_string_field(api, state, "Name", "UE4SSLProbeCompatMod");
  lua_set_string_field(api, state, "Source", "probe-compat");
  set_lua_object_method(api, state, "SetSharedVariable", lua_modref_set_shared_variable_callback);
  set_lua_object_method(api, state, "GetSharedVariable", lua_modref_get_shared_variable_callback);
  set_lua_object_method(api, state, "type", lua_modref_type_callback);
  set_lua_object_method(api, state, "GetWorld", lua_object_get_world_callback);
  set_lua_object_method(api, state, "CallFunction", lua_call_function_callback);
  api->set_global(state, "ModRef");
}

static uintptr_t lua_object_address_arg(LuaApi *api, LuaState *state, int index) {
  if (!api || !state) {
    return 0;
  }
  if (api->type && api->type(state, index) == LUA_TTABLE_COMPAT && api->get_field && api->set_top) {
    api->get_field(state, index, "Address");
    int is_number = 0;
    long long address = lua_to_integer(api, state, -1, &is_number);
    api->set_top(state, -2);
    return is_number && address > 0 ? (uintptr_t)address : 0;
  }
  const char *query = api->to_lstring ? api->to_lstring(state, index, 0) : 0;
  if (query && query[0]) {
    const LuaObjectHandle *object = find_lua_object_by_path_or_name(query);
    return object ? object->address : 0;
  }
  int is_number = 0;
  long long address = lua_to_integer(api, state, index, &is_number);
  return is_number && address > 0 ? (uintptr_t)address : 0;
}

static uintptr_t lua_object_uintptr_field_arg(LuaApi *api, LuaState *state, int index, const char *field) {
  if (!api || !state || !field || !api->type || !api->get_field || !api->set_top ||
      api->type(state, index) != LUA_TTABLE_COMPAT) {
    return 0;
  }
  api->get_field(state, index, field);
  int is_number = 0;
  long long value = lua_to_integer(api, state, -1, &is_number);
  api->set_top(state, -2);
  return is_number && value > 0 ? (uintptr_t)value : 0;
}

static int CDECL lua_push_self_string_field_or_nil(LuaState *state, const char *field) {
  if (!active_lua_api || !active_lua_api->push_nil || !active_lua_api->push_string ||
      !active_lua_api->get_field || !active_lua_api->set_top || !field) {
    return 0;
  }
  active_lua_api->get_field(state, 1, field);
  const char *value = active_lua_api->to_lstring ? active_lua_api->to_lstring(state, -1, 0) : 0;
  char out[MAX_LUA_OBJECT_PATH];
  out[0] = '\0';
  if (value && value[0]) {
    copy_string(out, sizeof(out), value);
  }
  active_lua_api->set_top(state, -2);
  if (out[0]) {
    active_lua_api->push_string(state, out);
    return 1;
  }
  active_lua_api->push_nil(state);
  return 1;
}

static int lua_read_self_string_field(LuaState *state, const char *field, char *out, size_t out_size) {
  if (!active_lua_api || !state || !field || !out || out_size == 0 ||
      !active_lua_api->get_field || !active_lua_api->set_top) {
    return 0;
  }
  out[0] = '\0';
  active_lua_api->get_field(state, 1, field);
  const char *value = active_lua_api->to_lstring ? active_lua_api->to_lstring(state, -1, 0) : 0;
  if (value && value[0]) {
    copy_string(out, out_size, value);
  }
  active_lua_api->set_top(state, -2);
  return out[0] != '\0';
}

static int CDECL lua_object_get_full_name_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_string) {
    return 0;
  }
  char path[MAX_LUA_OBJECT_PATH];
  char class_name[MAX_LUA_CLASS_NAME];
  lua_read_self_string_field(state, "PathName", path, sizeof(path));
  lua_read_self_string_field(state, "ClassName", class_name, sizeof(class_name));
  char full_name[MAX_LUA_OBJECT_PATH + MAX_LUA_CLASS_NAME + 2];
  full_name[0] = '\0';
  if (class_name[0] && path[0]) {
    copy_string(full_name, sizeof(full_name), class_name);
    size_t used = cstr_len(full_name);
    if (used + 1 < sizeof(full_name)) {
      full_name[used++] = ' ';
      full_name[used] = '\0';
      copy_string(full_name + used, sizeof(full_name) - used, path);
    }
  } else {
    copy_string(full_name, sizeof(full_name), path[0] ? path : class_name);
  }
  active_lua_api->push_string(state, full_name);
  return 1;
}

static int CDECL lua_object_get_name_callback(LuaState *state) {
  return lua_push_self_string_field_or_nil(state, "Name");
}

static int CDECL lua_object_get_path_name_callback(LuaState *state) {
  return lua_push_self_string_field_or_nil(state, "PathName");
}

static int CDECL lua_object_get_address_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_integer) {
    return 0;
  }
  active_lua_api->push_integer(state, (long long)lua_object_address_arg(active_lua_api, state, 1));
  return 1;
}

static int CDECL lua_object_is_valid_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_boolean) {
    return 0;
  }
  active_lua_api->push_boolean(state, lua_object_address_arg(active_lua_api, state, 1) != 0);
  return 1;
}

static int CDECL lua_object_get_class_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_nil) {
    return 0;
  }
  char class_name[MAX_LUA_CLASS_NAME];
  if (!lua_read_self_string_field(state, "ClassName", class_name, sizeof(class_name))) {
    active_lua_api->push_nil(state);
    return 1;
  }
  LuaObjectHandle synthetic;
  for (size_t i = 0; i < sizeof(synthetic); ++i) {
    ((unsigned char *)&synthetic)[i] = 0;
  }
  copy_string(synthetic.path, sizeof(synthetic.path), "/RuntimeProbe/Class/");
  size_t used = cstr_len(synthetic.path);
  if (used < sizeof(synthetic.path)) {
    copy_string(synthetic.path + used, sizeof(synthetic.path) - used, class_name);
  }
  copy_string(synthetic.name, sizeof(synthetic.name), class_name);
  copy_string(synthetic.class_name, sizeof(synthetic.class_name), "UClass");
  uintptr_t class_address = lua_object_uintptr_field_arg(active_lua_api, state, 1, "ClassAddress");
  synthetic.address = class_address;
  synthetic.super_address = lua_object_uintptr_field_arg(active_lua_api, state, 1, "SuperAddress");
  const LuaClassMetadata *metadata = find_lua_class_metadata_by_address(class_address);
  if (metadata && metadata->super_address) {
    synthetic.super_address = metadata->super_address;
  }
  return push_lua_object_handle(active_lua_api, state, &synthetic) ? 1 : 0;
}

static int CDECL lua_object_get_outer_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_nil) {
    return 0;
  }
  uintptr_t outer_address = lua_object_uintptr_field_arg(active_lua_api, state, 1, "OuterAddress");
  const LuaObjectHandle *outer = find_lua_object_by_address(outer_address);
  if (outer && push_lua_object_handle(active_lua_api, state, outer)) {
    return 1;
  }
  active_lua_api->push_nil(state);
  return 1;
}

static int CDECL lua_object_type_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_string) {
    return 0;
  }
  char class_name[MAX_LUA_CLASS_NAME];
  lua_read_self_string_field(state, "ClassName", class_name, sizeof(class_name));
  if (str_equal(class_name, "UFunction") || str_equal(class_name, "UClass")) {
    active_lua_api->push_string(state, class_name);
  } else {
    active_lua_api->push_string(state, "UObject");
  }
  return 1;
}

static int CDECL lua_object_is_class_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_boolean) {
    return 0;
  }
  char class_name[MAX_LUA_CLASS_NAME];
  lua_read_self_string_field(state, "ClassName", class_name, sizeof(class_name));
  active_lua_api->push_boolean(state, str_equal(class_name, "UClass"));
  return 1;
}

static int CDECL lua_object_is_any_class_callback(LuaState *state) {
  return lua_object_is_class_callback(state);
}

static int CDECL lua_object_get_fname_callback(LuaState *state) {
  return lua_push_self_string_field_or_nil(state, "Name");
}

static int CDECL lua_object_get_world_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_nil) {
    return 0;
  }
  ++lua_get_world_calls;
  uintptr_t address = lua_object_address_arg(active_lua_api, state, 1);
  const LuaObjectHandle *self = find_lua_object_by_address(address);
  if (self && lua_object_handle_is_world_like(self) && push_lua_object_handle(active_lua_api, state, self)) {
    ++lua_get_world_hits;
    return 1;
  }
  uintptr_t outer_address = lua_object_uintptr_field_arg(active_lua_api, state, 1, "OuterAddress");
  const LuaObjectHandle *outer_world = find_lua_world_from_outer_chain(outer_address);
  if (outer_world && push_lua_object_handle(active_lua_api, state, outer_world)) {
    ++lua_get_world_hits;
    return 1;
  }
  char class_name[MAX_LUA_CLASS_NAME];
  lua_read_self_string_field(state, "ClassName", class_name, sizeof(class_name));
  if (lua_object_class_has_world_context(class_name)) {
    const LuaObjectHandle *registered_world = find_lua_registered_world_handle();
    if (registered_world && push_lua_object_handle(active_lua_api, state, registered_world)) {
      ++lua_get_world_hits;
      return 1;
    }
  }
  active_lua_api->push_nil(state);
  return 1;
}

static int CDECL lua_object_has_all_flags_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_boolean) {
    return 0;
  }
  int is_number = 0;
  long long flags = lua_to_integer(active_lua_api, state, 2, &is_number);
  uint32_t object_flags = (uint32_t)lua_object_uintptr_field_arg(active_lua_api, state, 1, "ObjectFlags");
  uint32_t requested = (uint32_t)flags;
  active_lua_api->push_boolean(state, is_number && ((object_flags & requested) == requested));
  return 1;
}

static int CDECL lua_object_has_any_flags_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_boolean) {
    return 0;
  }
  int is_number = 0;
  long long flags = lua_to_integer(active_lua_api, state, 2, &is_number);
  uint32_t object_flags = (uint32_t)lua_object_uintptr_field_arg(active_lua_api, state, 1, "ObjectFlags");
  uint32_t requested = (uint32_t)flags;
  active_lua_api->push_boolean(state, is_number && requested != 0 && ((object_flags & requested) != 0));
  return 1;
}

static int CDECL lua_object_has_any_internal_flags_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_boolean) {
    return 0;
  }
  int is_number = 0;
  long long flags = lua_to_integer(active_lua_api, state, 2, &is_number);
  uint32_t internal_flags = (uint32_t)lua_object_uintptr_field_arg(active_lua_api, state, 1, "InternalFlags");
  uint32_t requested = (uint32_t)flags;
  active_lua_api->push_boolean(state, is_number && requested != 0 && ((internal_flags & requested) != 0));
  return 1;
}

static int push_lua_fname_table(
  LuaApi *api,
  LuaState *state,
  const char *name,
  long long comparison_index,
  long long number,
  int decoded
) {
  if (!api || !state || !api->create_table || !api->push_string || !api->push_integer ||
      !api->push_boolean || !api->set_field || !api->push_cclosure) {
    return 0;
  }
  const char *safe_name = name ? name : "";
  api->create_table(state, 0, 10);
  api->push_string(state, "FName");
  api->set_field(state, -2, "Kind");
  api->push_string(state, "fname");
  api->set_field(state, -2, "Type");
  api->push_string(state, safe_name);
  api->set_field(state, -2, "Name");
  api->push_string(state, safe_name);
  api->set_field(state, -2, "String");
  api->push_integer(state, comparison_index);
  api->set_field(state, -2, "ComparisonIndex");
  api->push_integer(state, number);
  api->set_field(state, -2, "Number");
  api->push_boolean(state, decoded);
  api->set_field(state, -2, "IsDecoded");
  set_lua_object_method(api, state, "ToString", lua_fname_to_string_callback);
  set_lua_object_method(api, state, "GetComparisonIndex", lua_fname_get_comparison_index_callback);
  set_lua_object_method(api, state, "type", lua_fname_type_callback);
  return 1;
}

static int CDECL lua_fname_to_string_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_string) {
    return 0;
  }
  char name[MAX_LUA_OBJECT_NAME];
  lua_read_self_string_field(state, "Name", name, sizeof(name));
  active_lua_api->push_string(state, name);
  return 1;
}

static int CDECL lua_fname_get_comparison_index_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_integer || !active_lua_api->get_field || !active_lua_api->set_top) {
    return 0;
  }
  active_lua_api->get_field(state, 1, "ComparisonIndex");
  int is_number = 0;
  long long value = lua_to_integer(active_lua_api, state, -1, &is_number);
  active_lua_api->set_top(state, -2);
  active_lua_api->push_integer(state, is_number ? value : 0);
  return 1;
}

static int CDECL lua_fname_type_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_string) {
    return 0;
  }
  active_lua_api->push_string(state, "FName");
  return 1;
}

static int push_lua_property_descriptor(
  LuaApi *api,
  LuaState *state,
  const char *owner_path,
  uintptr_t owner_address,
  const char *name,
  const char *class_name,
  const char *type,
  long long offset,
  long long size,
  long long property_flags,
  uintptr_t property_address,
  const char *source
) {
  if (!api || !state || !name || !api->create_table || !api->push_string || !api->push_integer ||
      !api->push_boolean || !api->set_field || !api->push_cclosure) {
    return 0;
  }
  const char *safe_class = class_name && class_name[0] ? class_name : "FProperty";
  const char *safe_type = type && type[0] ? type : ue_param_value_type(safe_class, (int32_t)size);
  const char *safe_source = source && source[0] ? source : "probe-reflection";
  char path[MAX_LUA_OBJECT_PATH];
  if (owner_path && owner_path[0]) {
    lua_copy_join(path, sizeof(path), owner_path, ".", name);
  } else {
    lua_copy_join(path, sizeof(path), "/RuntimeProbe/Property/", name, "");
  }
  api->create_table(state, 0, 24);
  api->push_string(state, name);
  api->set_field(state, -2, "Name");
  api->push_string(state, path);
  api->set_field(state, -2, "PathName");
  api->push_string(state, safe_type);
  api->set_field(state, -2, "Type");
  api->push_string(state, safe_class);
  api->set_field(state, -2, "ClassName");
  api->push_string(state, safe_source);
  api->set_field(state, -2, "Source");
  api->push_integer(state, (long long)(property_address ? property_address : owner_address + (uintptr_t)(offset > 0 ? offset : 0)));
  api->set_field(state, -2, "Address");
  api->push_integer(state, (long long)owner_address);
  api->set_field(state, -2, "OwnerAddress");
  api->push_integer(state, offset);
  api->set_field(state, -2, "Offset");
  api->push_integer(state, offset);
  api->set_field(state, -2, "OffsetInternal");
  api->push_integer(state, size);
  api->set_field(state, -2, "Size");
  api->push_integer(state, size);
  api->set_field(state, -2, "ElementSize");
  api->push_integer(state, 1);
  api->set_field(state, -2, "ArrayDim");
  api->push_integer(state, property_flags);
  api->set_field(state, -2, "PropertyFlags");
  api->push_boolean(state, (property_flags & UE_PROPERTY_FLAG_PARM) != 0);
  api->set_field(state, -2, "IsParm");
  api->push_boolean(state, (property_flags & UE_PROPERTY_FLAG_OUT_PARM) != 0);
  api->set_field(state, -2, "IsOutParm");
  api->push_boolean(state, (property_flags & UE_PROPERTY_FLAG_RETURN_PARM) != 0);
  api->set_field(state, -2, "IsReturnParm");
  if (contains_ci(safe_class, "StructProperty") && contains_ci(safe_type, "vector")) {
    api->push_string(state, "Vector");
    api->set_field(state, -2, "StructName");
    api->push_string(state, "/Script/CoreUObject.Vector");
    api->set_field(state, -2, "StructPath");
    api->push_integer(state, (long long)(uintptr_t)&ue_self_test_fvector_script_struct_anchor);
    api->set_field(state, -2, "StructAddress");
  }
  if (contains_ci(safe_class, "ArrayProperty")) {
    api->push_string(state, "Inner");
    api->set_field(state, -2, "InnerName");
    api->push_string(state, "FIntProperty");
    api->set_field(state, -2, "InnerClassName");
    api->push_string(state, "int32");
    api->set_field(state, -2, "InnerType");
    api->push_integer(state, 4);
    api->set_field(state, -2, "InnerElementSize");
    api->push_integer(state, (long long)(uintptr_t)&lua_reflection_probe_array_values[0]);
    api->set_field(state, -2, "InnerAddress");
  }
  if (contains_ci(safe_class, "EnumProperty")) {
    api->push_string(state, "EProbeMode");
    api->set_field(state, -2, "EnumName");
    api->push_string(state, "/Script/UE4SSLProbe.EProbeMode");
    api->set_field(state, -2, "EnumPath");
    api->push_integer(state, (long long)(uintptr_t)&lua_reflection_probe_enum_value);
    api->set_field(state, -2, "EnumAddress");
    api->push_string(state, "Underlying");
    api->set_field(state, -2, "UnderlyingName");
    api->push_string(state, "FByteProperty");
    api->set_field(state, -2, "UnderlyingClassName");
    api->push_string(state, "uint8");
    api->set_field(state, -2, "UnderlyingType");
    api->push_integer(state, 1);
    api->set_field(state, -2, "UnderlyingElementSize");
    api->push_integer(state, (long long)(uintptr_t)&lua_reflection_probe_enum_value);
    api->set_field(state, -2, "UnderlyingAddress");
  }
  if (contains_ci(safe_class, "SetProperty")) {
    api->push_string(state, "Element");
    api->set_field(state, -2, "ElementName");
    api->push_string(state, "FIntProperty");
    api->set_field(state, -2, "ElementClassName");
    api->push_string(state, "int32");
    api->set_field(state, -2, "ElementType");
    api->push_integer(state, 4);
    api->set_field(state, -2, "ElementSize");
    api->push_integer(state, (long long)(uintptr_t)&lua_reflection_probe_set_values[0]);
    api->set_field(state, -2, "ElementAddress");
  }
  if (contains_ci(safe_class, "MapProperty")) {
    api->push_string(state, "Key");
    api->set_field(state, -2, "KeyName");
    api->push_string(state, "FIntProperty");
    api->set_field(state, -2, "KeyClassName");
    api->push_string(state, "int32");
    api->set_field(state, -2, "KeyType");
    api->push_integer(state, 4);
    api->set_field(state, -2, "KeyElementSize");
    api->push_integer(state, (long long)(uintptr_t)&lua_reflection_probe_map_key_value);
    api->set_field(state, -2, "KeyAddress");
    api->push_string(state, "Value");
    api->set_field(state, -2, "ValueName");
    api->push_string(state, "FStrProperty");
    api->set_field(state, -2, "ValueClassName");
    api->push_string(state, "string");
    api->set_field(state, -2, "ValueType");
    api->push_integer(state, (long long)sizeof(UeFStringValue));
    api->set_field(state, -2, "ValueElementSize");
    api->push_integer(state, (long long)(uintptr_t)&lua_reflection_probe_map_value[0]);
    api->set_field(state, -2, "ValueAddress");
  }
  set_lua_object_method(api, state, "GetFullName", lua_property_get_full_name_callback);
  set_lua_object_method(api, state, "GetFName", lua_property_get_fname_callback);
  set_lua_object_method(api, state, "IsA", lua_property_is_a_callback);
  set_lua_object_method(api, state, "GetClass", lua_property_get_class_callback);
  set_lua_object_method(api, state, "ContainerPtrToValuePtr", lua_property_container_ptr_to_value_ptr_callback);
  set_lua_object_method(api, state, "GetValue", lua_property_get_value_callback);
  set_lua_object_method(api, state, "SetValue", lua_property_set_value_callback);
  set_lua_object_method(api, state, "ImportText", lua_property_import_text_callback);
  set_lua_object_method(api, state, "ExportText", lua_property_export_text_callback);
  set_lua_object_method(api, state, "ExportTextItem", lua_property_export_text_callback);
  set_lua_object_method(api, state, "GetOffset_Internal", lua_property_get_offset_internal_callback);
  set_lua_object_method(api, state, "GetOffsetInternal", lua_property_get_offset_internal_callback);
  set_lua_object_method(api, state, "GetElementSize", lua_property_get_element_size_callback);
  set_lua_object_method(api, state, "GetSize", lua_property_get_size_callback);
  set_lua_object_method(api, state, "GetArrayDim", lua_property_get_array_dim_callback);
  set_lua_object_method(api, state, "GetPropertyFlags", lua_property_get_property_flags_callback);
  set_lua_object_method(api, state, "HasAnyPropertyFlags", lua_property_has_any_property_flags_callback);
  set_lua_object_method(api, state, "GetPropertyClass", lua_property_get_property_class_callback);
  set_lua_object_method(api, state, "GetByteMask", lua_bool_property_get_byte_mask_callback);
  set_lua_object_method(api, state, "GetByteOffset", lua_bool_property_get_byte_offset_callback);
  set_lua_object_method(api, state, "GetFieldMask", lua_bool_property_get_field_mask_callback);
  set_lua_object_method(api, state, "GetFieldSize", lua_bool_property_get_field_size_callback);
  set_lua_object_method(api, state, "GetStruct", lua_struct_property_get_struct_callback);
  set_lua_object_method(api, state, "GetInner", lua_array_property_get_inner_callback);
  set_lua_object_method(api, state, "GetEnum", lua_enum_property_get_enum_callback);
  set_lua_object_method(api, state, "GetUnderlyingProperty", lua_enum_property_get_underlying_property_callback);
  set_lua_object_method(api, state, "GetElementProperty", lua_set_property_get_element_property_callback);
  set_lua_object_method(api, state, "GetElementProp", lua_set_property_get_element_property_callback);
  set_lua_object_method(api, state, "GetKeyProperty", lua_map_property_get_key_property_callback);
  set_lua_object_method(api, state, "GetKeyProp", lua_map_property_get_key_property_callback);
  set_lua_object_method(api, state, "GetValueProperty", lua_map_property_get_value_property_callback);
  set_lua_object_method(api, state, "GetValueProp", lua_map_property_get_value_property_callback);
  set_lua_object_method(api, state, "type", lua_property_type_callback);
  return 1;
}

static int push_self_test_property_descriptor(
  LuaApi *api,
  LuaState *state,
  uintptr_t owner_address,
  const char *owner_path,
  const char *property
) {
  if (owner_address != (uintptr_t)&ue_self_test_object || !property || !property[0]) {
    return 0;
  }
  if (str_equal(property, "ProbeValue")) {
    return push_lua_property_descriptor(api, state, owner_path, owner_address, property, "FIntProperty", "int32", 0, 4, 0, (uintptr_t)&lua_reflection_probe_value, "probe-self-test");
  }
  if (str_equal(property, "ProbeBool")) {
    return push_lua_property_descriptor(api, state, owner_path, owner_address, property, "FBoolProperty", "bool", 0, 1, 0, (uintptr_t)&lua_reflection_probe_bool_value, "probe-self-test");
  }
  if (str_equal(property, "ProbeFloat")) {
    return push_lua_property_descriptor(api, state, owner_path, owner_address, property, "FFloatProperty", "float", 0, (long long)sizeof(float), 0, (uintptr_t)&lua_reflection_probe_float_value, "probe-self-test");
  }
  if (str_equal(property, "ProbeDouble")) {
    return push_lua_property_descriptor(api, state, owner_path, owner_address, property, "FDoubleProperty", "double", 0, (long long)sizeof(double), 0, (uintptr_t)&lua_reflection_probe_double_value, "probe-self-test");
  }
  if (str_equal(property, "ProbeName")) {
    return push_lua_property_descriptor(api, state, owner_path, owner_address, property, "FNameProperty", "fname", 0, (long long)sizeof(UeFNameValue), 0, (uintptr_t)&lua_reflection_probe_name_value, "probe-self-test");
  }
  if (str_equal(property, "ProbeString")) {
    return push_lua_property_descriptor(api, state, owner_path, owner_address, property, "FStrProperty", "string", 0, (long long)sizeof(UeFStringValue), 0, (uintptr_t)&lua_reflection_probe_string_value[0], "probe-self-test");
  }
  if (str_equal(property, "ProbeText")) {
    return push_lua_property_descriptor(api, state, owner_path, owner_address, property, "FTextProperty", "text", 0, (long long)sizeof(UeFStringValue), 0, (uintptr_t)&lua_reflection_probe_text_value[0], "probe-self-test");
  }
  if (str_equal(property, "ProbeObject")) {
    return push_lua_property_descriptor(api, state, owner_path, owner_address, property, "FObjectProperty", "object", 0, (long long)sizeof(uintptr_t), 0, (uintptr_t)&lua_reflection_probe_object_address, "probe-self-test");
  }
  if (str_equal(property, "ProbeArray")) {
    return push_lua_property_descriptor(api, state, owner_path, owner_address, property, "FArrayProperty", "array", 0, (long long)sizeof(lua_reflection_probe_array_values), 0, (uintptr_t)&lua_reflection_probe_array_values[0], "probe-self-test");
  }
  if (str_equal(property, "ProbeEnum")) {
    return push_lua_property_descriptor(api, state, owner_path, owner_address, property, "FEnumProperty", "enum", 0, 1, 0, (uintptr_t)&lua_reflection_probe_enum_value, "probe-self-test");
  }
  if (str_equal(property, "ProbeSet")) {
    return push_lua_property_descriptor(api, state, owner_path, owner_address, property, "FSetProperty", "set", 0, (long long)sizeof(lua_reflection_probe_set_values), 0, (uintptr_t)&lua_reflection_probe_set_values[0], "probe-self-test");
  }
  if (str_equal(property, "ProbeMap")) {
    return push_lua_property_descriptor(api, state, owner_path, owner_address, property, "FMapProperty", "map", 0, (long long)(sizeof(lua_reflection_probe_map_key_value) + sizeof(UeFStringValue)), 0, (uintptr_t)&lua_reflection_probe_map_key_value, "probe-self-test");
  }
  if (str_equal(property, "ClassName")) {
    return push_lua_property_descriptor(api, state, owner_path, owner_address, property, "FStrProperty", "string", 0, (long long)sizeof(UeFStringValue), 0, 0, "probe-self-test");
  }
  return 0;
}

static int push_ue_function_property_descriptor(
  LuaApi *api,
  LuaState *state,
  uintptr_t owner_address,
  const char *property
) {
  if (!property || !property[0]) {
    return 0;
  }
  for (size_t i = 0; i < ue_function_param_descriptor_count; ++i) {
    const UeFunctionParamDescriptor *descriptor = &ue_function_param_descriptors[i];
    int name_match = str_equal(descriptor->property_name, property) ||
                     (descriptor->field_name[0] && str_equal(descriptor->field_name, property));
    if (descriptor->function == owner_address && name_match) {
      const char *field_name = descriptor->field_name[0] ? descriptor->field_name : descriptor->property_name;
      return push_lua_property_descriptor(
        api,
        state,
        descriptor->function_path,
        owner_address,
        field_name,
        descriptor->class_name,
        ue_param_value_type(descriptor->class_name, descriptor->element_size),
        descriptor->offset_internal,
        descriptor->element_size,
        (long long)descriptor->property_flags,
        descriptor->field,
        "ue-function-param"
      );
    }
  }
  return 0;
}

static int push_live_reflection_property_descriptor(
  LuaApi *api,
  LuaState *state,
  uintptr_t owner_address,
  const char *owner_path,
  const char *property
) {
  if (!property || !property[0]) {
    return 0;
  }
  for (size_t i = 0; i < ue_reflection_property_candidate_count; ++i) {
    const UeReflectionPropertyCandidate *candidate = &ue_reflection_property_candidates[i];
    int name_match = str_equal(candidate->property_name, property) ||
                     (candidate->field_name[0] && str_equal(candidate->field_name, property));
    if (candidate->object == owner_address && name_match) {
      const char *name = candidate->field_name[0] ? candidate->field_name : candidate->property_name;
      return push_lua_property_descriptor(
        api,
        state,
        owner_path,
        owner_address,
        name,
        "FProperty",
        ue_param_scalar_type(candidate->element_size),
        candidate->offset_internal,
        candidate->element_size,
        0,
        owner_address + (uintptr_t)candidate->offset_internal,
        "ue-reflection-scan"
      );
    }
  }
  return 0;
}

static int CDECL lua_object_reflection_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->create_table || !active_lua_api->push_integer ||
      !active_lua_api->push_string || !active_lua_api->set_field || !active_lua_api->push_cclosure) {
    return 0;
  }
  uintptr_t address = lua_object_address_arg(active_lua_api, state, 1);
  char name[MAX_LUA_OBJECT_NAME];
  char path[MAX_LUA_OBJECT_PATH];
  char class_name[MAX_LUA_CLASS_NAME];
  lua_read_self_string_field(state, "Name", name, sizeof(name));
  lua_read_self_string_field(state, "PathName", path, sizeof(path));
  lua_read_self_string_field(state, "ClassName", class_name, sizeof(class_name));
  active_lua_api->create_table(state, 0, 8);
  active_lua_api->push_integer(state, (long long)address);
  active_lua_api->set_field(state, -2, "ObjectAddress");
  active_lua_api->push_string(state, name);
  active_lua_api->set_field(state, -2, "ObjectName");
  active_lua_api->push_string(state, path);
  active_lua_api->set_field(state, -2, "ObjectPath");
  active_lua_api->push_string(state, class_name);
  active_lua_api->set_field(state, -2, "ClassName");
  active_lua_api->push_string(state, "UObjectReflection");
  active_lua_api->set_field(state, -2, "Kind");
  set_lua_object_method(active_lua_api, state, "GetProperty", lua_reflection_get_property_callback);
  set_lua_object_method(active_lua_api, state, "type", lua_reflection_type_callback);
  return 1;
}

static int CDECL lua_reflection_get_property_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_nil || !active_lua_api->get_field || !active_lua_api->set_top) {
    return 0;
  }
  active_lua_api->get_field(state, 1, "ObjectAddress");
  int is_number = 0;
  long long address_value = lua_to_integer(active_lua_api, state, -1, &is_number);
  active_lua_api->set_top(state, -2);
  char owner_path[MAX_LUA_OBJECT_PATH];
  owner_path[0] = '\0';
  lua_table_string_field(active_lua_api, state, 1, "ObjectPath", owner_path, sizeof(owner_path));
  const char *property = active_lua_api->to_lstring ? active_lua_api->to_lstring(state, 2, 0) : 0;
  uintptr_t owner_address = is_number && address_value > 0 ? (uintptr_t)address_value : 0;
  if ((push_self_test_property_descriptor(active_lua_api, state, owner_address, owner_path, property) ||
       push_ue_function_property_descriptor(active_lua_api, state, owner_address, property) ||
       push_live_reflection_property_descriptor(active_lua_api, state, owner_address, owner_path, property))) {
    return 1;
  }
  active_lua_api->push_nil(state);
  return 1;
}

static int CDECL lua_reflection_type_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_string) {
    return 0;
  }
  active_lua_api->push_string(state, "UObjectReflection");
  return 1;
}

static int CDECL lua_property_get_full_name_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_string) {
    return 0;
  }
  char path[MAX_LUA_OBJECT_PATH];
  char class_name[MAX_LUA_CLASS_NAME];
  char full_name[MAX_LUA_OBJECT_PATH + MAX_LUA_CLASS_NAME + 2];
  lua_read_self_string_field(state, "PathName", path, sizeof(path));
  lua_read_self_string_field(state, "ClassName", class_name, sizeof(class_name));
  full_name[0] = '\0';
  if (class_name[0] && path[0]) {
    copy_string(full_name, sizeof(full_name), class_name);
    size_t used = cstr_len(full_name);
    if (used + 1 < sizeof(full_name)) {
      full_name[used++] = ' ';
      full_name[used] = '\0';
      copy_string(full_name + used, sizeof(full_name) - used, path);
    }
  } else {
    copy_string(full_name, sizeof(full_name), path[0] ? path : class_name);
  }
  active_lua_api->push_string(state, full_name);
  return 1;
}

static int CDECL lua_property_get_fname_callback(LuaState *state) {
  if (!active_lua_api) {
    return 0;
  }
  char name[MAX_LUA_OBJECT_NAME];
  lua_read_self_string_field(state, "Name", name, sizeof(name));
  return push_lua_fname_table(active_lua_api, state, name, 0, 0, name[0] != '\0') ? 1 : 0;
}

static int lua_property_type_matches(const char *class_name, const char *query) {
  if (!class_name || !class_name[0] || !query || !query[0]) {
    return 0;
  }
  if (str_equal(class_name, query)) {
    return 1;
  }
  if (class_name[0] == 'F' && str_equal(class_name + 1, query)) {
    return 1;
  }
  if (query[0] == 'F' && str_equal(class_name, query + 1)) {
    return 1;
  }
  return contains_ci(class_name, query);
}

static int CDECL lua_property_is_a_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_boolean) {
    return 0;
  }
  char class_name[MAX_LUA_CLASS_NAME];
  lua_read_self_string_field(state, "ClassName", class_name, sizeof(class_name));
  const char *query = active_lua_api->to_lstring ? active_lua_api->to_lstring(state, 2, 0) : 0;
  active_lua_api->push_boolean(state, lua_property_type_matches(class_name, query));
  return 1;
}

static int CDECL lua_property_get_class_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_nil) {
    return 0;
  }
  char class_name[MAX_LUA_CLASS_NAME];
  if (!lua_read_self_string_field(state, "ClassName", class_name, sizeof(class_name))) {
    active_lua_api->push_nil(state);
    return 1;
  }
  LuaObjectHandle synthetic;
  for (size_t i = 0; i < sizeof(synthetic); ++i) {
    ((unsigned char *)&synthetic)[i] = 0;
  }
  lua_copy_join(synthetic.path, sizeof(synthetic.path), "/RuntimeProbe/PropertyClass/", class_name, "");
  copy_string(synthetic.name, sizeof(synthetic.name), class_name);
  copy_string(synthetic.class_name, sizeof(synthetic.class_name), "PropertyClass");
  synthetic.address = 0;
  return push_lua_object_handle(active_lua_api, state, &synthetic) ? 1 : 0;
}

static int CDECL lua_property_container_ptr_to_value_ptr_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_integer || !active_lua_api->get_field || !active_lua_api->set_top) {
    return 0;
  }
  uintptr_t container = lua_object_address_arg(active_lua_api, state, 2);
  if (!container) {
    active_lua_api->get_field(state, 1, "OwnerAddress");
    int owner_is_number = 0;
    long long owner = lua_to_integer(active_lua_api, state, -1, &owner_is_number);
    active_lua_api->set_top(state, -2);
    container = owner_is_number && owner > 0 ? (uintptr_t)owner : 0;
  }
  active_lua_api->get_field(state, 1, "OffsetInternal");
  int offset_is_number = 0;
  long long offset = lua_to_integer(active_lua_api, state, -1, &offset_is_number);
  active_lua_api->set_top(state, -2);
  active_lua_api->get_field(state, 1, "ElementSize");
  int size_is_number = 0;
  long long size = lua_to_integer(active_lua_api, state, -1, &size_is_number);
  active_lua_api->set_top(state, -2);
  int index_is_number = 0;
  long long index = lua_to_integer(active_lua_api, state, 3, &index_is_number);
  if (!index_is_number || index < 0) {
    index = 0;
  }
  uintptr_t value = container && offset_is_number && size_is_number && offset >= 0 && size > 0 ?
                    container + (uintptr_t)offset + (uintptr_t)(index * size) : 0;
  active_lua_api->push_integer(state, (long long)value);
  return 1;
}

static int CDECL lua_property_get_value_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_nil) {
    return 0;
  }
  char name[MAX_LUA_OBJECT_NAME];
  lua_read_self_string_field(state, "Name", name, sizeof(name));
  uintptr_t owner = lua_object_uintptr_field_arg(active_lua_api, state, 1, "OwnerAddress");
  if (owner != (uintptr_t)&ue_self_test_object) {
    active_lua_api->push_nil(state);
    return 1;
  }
  if (str_equal(name, "ProbeValue")) {
    ++lua_reflection_descriptor_value_get_hits;
    active_lua_api->push_integer(state, lua_reflection_probe_value);
    return 1;
  }
  if (str_equal(name, "ProbeBool")) {
    ++lua_reflection_descriptor_value_get_hits;
    active_lua_api->push_boolean(state, lua_reflection_probe_bool_value);
    return 1;
  }
  if (str_equal(name, "ProbeFloat")) {
    ++lua_reflection_descriptor_value_get_hits;
    active_lua_api->push_number(state, (double)lua_reflection_probe_float_value);
    return 1;
  }
  if (str_equal(name, "ProbeDouble")) {
    ++lua_reflection_descriptor_value_get_hits;
    active_lua_api->push_number(state, lua_reflection_probe_double_value);
    return 1;
  }
  if (str_equal(name, "ProbeName")) {
    if (push_lua_fname_table(
          active_lua_api,
          state,
          lua_reflection_probe_name_string,
          (long long)lua_reflection_probe_name_value.comparison_index,
          (long long)lua_reflection_probe_name_value.number,
          lua_reflection_probe_name_string[0] != '\0')) {
      ++lua_reflection_descriptor_value_get_hits;
      return 1;
    }
  }
  if (str_equal(name, "ProbeString")) {
    ++lua_reflection_descriptor_value_get_hits;
    active_lua_api->push_string(state, lua_reflection_probe_string_value);
    return 1;
  }
  if (str_equal(name, "ProbeText")) {
    if (push_lua_ftext_table(active_lua_api, state, lua_reflection_probe_text_value)) {
      ++lua_reflection_descriptor_value_get_hits;
      return 1;
    }
  }
  if (str_equal(name, "ProbeObject")) {
    const LuaObjectHandle *object = find_lua_object_by_path_or_name("/Script/UE4SSLProbe.SelfTestObject");
    if (object && object->address == lua_reflection_probe_object_address &&
        push_lua_object_handle(active_lua_api, state, object)) {
      ++lua_reflection_descriptor_value_get_hits;
      return 1;
    }
  }
  active_lua_api->push_nil(state);
  return 1;
}

static int CDECL lua_property_set_value_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_boolean) {
    return 0;
  }
  char name[MAX_LUA_OBJECT_NAME];
  lua_read_self_string_field(state, "Name", name, sizeof(name));
  uintptr_t owner = lua_object_uintptr_field_arg(active_lua_api, state, 1, "OwnerAddress");
  int is_number = 0;
  long long value = lua_to_integer(active_lua_api, state, 2, &is_number);
  int is_real_number = 0;
  double number_value = lua_to_number(active_lua_api, state, 2, &is_real_number);
  if (owner == (uintptr_t)&ue_self_test_object && str_equal(name, "ProbeValue") && is_number) {
    lua_reflection_probe_value = value;
    ++lua_reflection_descriptor_value_set_hits;
    active_lua_api->push_boolean(state, 1);
    return 1;
  }
  if (owner == (uintptr_t)&ue_self_test_object && str_equal(name, "ProbeBool")) {
    int is_boolean = 0;
    int bool_value = lua_to_boolean(active_lua_api, state, 2, &is_boolean);
    if (is_boolean) {
      lua_reflection_probe_bool_value = bool_value;
      ++lua_reflection_descriptor_value_set_hits;
      active_lua_api->push_boolean(state, 1);
      return 1;
    }
  }
  if (owner == (uintptr_t)&ue_self_test_object && str_equal(name, "ProbeFloat") && is_real_number) {
    lua_reflection_probe_float_value = (float)number_value;
    ++lua_reflection_descriptor_value_set_hits;
    active_lua_api->push_boolean(state, 1);
    return 1;
  }
  if (owner == (uintptr_t)&ue_self_test_object && str_equal(name, "ProbeDouble") && is_real_number) {
    lua_reflection_probe_double_value = number_value;
    ++lua_reflection_descriptor_value_set_hits;
    active_lua_api->push_boolean(state, 1);
    return 1;
  }
  if (owner == (uintptr_t)&ue_self_test_object && str_equal(name, "ProbeName")) {
    char name_value[sizeof(lua_reflection_probe_name_string)];
    name_value[0] = '\0';
    lua_copy_string_arg_or_field(active_lua_api, state, 2, "Name", name_value, sizeof(name_value), 0);
    if (!name_value[0]) {
      lua_copy_string_arg_or_field(active_lua_api, state, 2, "String", name_value, sizeof(name_value), 0);
    }
    if (name_value[0]) {
      copy_string(lua_reflection_probe_name_string, sizeof(lua_reflection_probe_name_string), name_value);
      lua_reflection_probe_name_value.comparison_index = (uint32_t)lua_object_uintptr_field_arg(active_lua_api, state, 2, "ComparisonIndex");
      lua_reflection_probe_name_value.number = (uint32_t)lua_object_uintptr_field_arg(active_lua_api, state, 2, "Number");
      ++lua_reflection_descriptor_value_set_hits;
      active_lua_api->push_boolean(state, 1);
      return 1;
    }
  }
  if (owner == (uintptr_t)&ue_self_test_object && str_equal(name, "ProbeString")) {
    size_t value_len = 0;
    const char *string_value = active_lua_api->to_lstring ? active_lua_api->to_lstring(state, 2, &value_len) : 0;
    if (string_value) {
      size_t copy_len = value_len;
      size_t max_copy = sizeof(lua_reflection_probe_string_value) - 1;
      if (copy_len > max_copy) {
        copy_len = max_copy;
      }
      for (size_t i = 0; i < copy_len; ++i) {
        lua_reflection_probe_string_value[i] = string_value[i];
      }
      lua_reflection_probe_string_value[copy_len] = '\0';
      ++lua_reflection_descriptor_value_set_hits;
      active_lua_api->push_boolean(state, 1);
      return 1;
    }
  }
  if (owner == (uintptr_t)&ue_self_test_object && str_equal(name, "ProbeText")) {
    char text_value[sizeof(lua_reflection_probe_text_value)];
    text_value[0] = '\0';
    lua_copy_string_arg_or_field(active_lua_api, state, 2, "Text", text_value, sizeof(text_value), 0);
    if (text_value[0]) {
      copy_string(lua_reflection_probe_text_value, sizeof(lua_reflection_probe_text_value), text_value);
      ++lua_reflection_descriptor_value_set_hits;
      active_lua_api->push_boolean(state, 1);
      return 1;
    }
  }
  if (owner == (uintptr_t)&ue_self_test_object && str_equal(name, "ProbeObject")) {
    uintptr_t object_address = lua_object_address_arg(active_lua_api, state, 2);
    if (object_address) {
      lua_reflection_probe_object_address = object_address;
      ++lua_reflection_descriptor_value_set_hits;
      active_lua_api->push_boolean(state, 1);
      return 1;
    }
  }
  active_lua_api->push_boolean(state, 0);
  return 1;
}

static int lua_property_push_integer_field_callback(LuaState *state, const char *field) {
  if (!active_lua_api || !active_lua_api->push_integer || !active_lua_api->get_field || !active_lua_api->set_top) {
    return 0;
  }
  active_lua_api->get_field(state, 1, field);
  int is_number = 0;
  long long value = lua_to_integer(active_lua_api, state, -1, &is_number);
  active_lua_api->set_top(state, -2);
  if (!is_number) {
    value = 0;
  }
  ++lua_reflection_property_metadata_hits;
  active_lua_api->push_integer(state, value);
  return 1;
}

static int CDECL lua_property_get_offset_internal_callback(LuaState *state) {
  return lua_property_push_integer_field_callback(state, "OffsetInternal");
}

static int CDECL lua_property_get_element_size_callback(LuaState *state) {
  return lua_property_push_integer_field_callback(state, "ElementSize");
}

static int CDECL lua_property_get_size_callback(LuaState *state) {
  return lua_property_push_integer_field_callback(state, "Size");
}

static int CDECL lua_property_get_array_dim_callback(LuaState *state) {
  return lua_property_push_integer_field_callback(state, "ArrayDim");
}

static int CDECL lua_property_get_property_flags_callback(LuaState *state) {
  return lua_property_push_integer_field_callback(state, "PropertyFlags");
}

static int CDECL lua_property_has_any_property_flags_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_boolean || !active_lua_api->get_field || !active_lua_api->set_top) {
    return 0;
  }
  active_lua_api->get_field(state, 1, "PropertyFlags");
  int flags_is_number = 0;
  long long flags = lua_to_integer(active_lua_api, state, -1, &flags_is_number);
  active_lua_api->set_top(state, -2);
  int mask_is_number = 0;
  long long mask = lua_to_integer(active_lua_api, state, 2, &mask_is_number);
  ++lua_reflection_property_metadata_hits;
  active_lua_api->push_boolean(state, flags_is_number && mask_is_number && ((flags & mask) != 0));
  return 1;
}

static int CDECL lua_property_import_text_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_boolean) {
    return 0;
  }
  char name[MAX_LUA_OBJECT_NAME];
  char class_name[MAX_LUA_CLASS_NAME];
  lua_read_self_string_field(state, "Name", name, sizeof(name));
  lua_read_self_string_field(state, "ClassName", class_name, sizeof(class_name));
  uintptr_t owner = lua_object_uintptr_field_arg(active_lua_api, state, 1, "OwnerAddress");
  size_t value_len = 0;
  const char *text = active_lua_api->to_lstring ? active_lua_api->to_lstring(state, 2, &value_len) : 0;
  int ok = 0;
  if (owner == (uintptr_t)&ue_self_test_object && text) {
    if (str_equal(name, "ProbeValue") && contains_ci(class_name, "IntProperty")) {
      int consumed = 0;
      long long value = parse_signed_decimal(text, &consumed);
      ok = consumed > 0;
      if (ok) {
        lua_reflection_probe_value = value;
      }
    } else if (str_equal(name, "ProbeBool") && contains_ci(class_name, "BoolProperty")) {
      if (str_equal(text, "true") || str_equal(text, "True") || str_equal(text, "1")) {
        lua_reflection_probe_bool_value = 1;
        ok = 1;
      } else if (str_equal(text, "false") || str_equal(text, "False") || str_equal(text, "0")) {
        lua_reflection_probe_bool_value = 0;
        ok = 1;
      }
    } else if (str_equal(name, "ProbeFloat") && contains_ci(class_name, "FloatProperty")) {
      int consumed = 0;
      double value = parse_simple_double(text, &consumed);
      ok = consumed > 0;
      if (ok) {
        lua_reflection_probe_float_value = (float)value;
      }
    } else if (str_equal(name, "ProbeDouble") && contains_ci(class_name, "DoubleProperty")) {
      int consumed = 0;
      double value = parse_simple_double(text, &consumed);
      ok = consumed > 0;
      if (ok) {
        lua_reflection_probe_double_value = value;
      }
    } else if (str_equal(name, "ProbeString") && contains_ci(class_name, "StrProperty")) {
      size_t copy_len = value_len;
      size_t max_copy = sizeof(lua_reflection_probe_string_value) - 1;
      if (copy_len > max_copy) {
        copy_len = max_copy;
      }
      for (size_t i = 0; i < copy_len; ++i) {
        lua_reflection_probe_string_value[i] = text[i];
      }
      lua_reflection_probe_string_value[copy_len] = '\0';
      ok = 1;
    } else if (str_equal(name, "ProbeName") && contains_ci(class_name, "NameProperty")) {
      copy_string(lua_reflection_probe_name_string, sizeof(lua_reflection_probe_name_string), text);
      lua_reflection_probe_name_value.comparison_index = 0;
      lua_reflection_probe_name_value.number = 0;
      ok = 1;
    } else if (str_equal(name, "ProbeText") && contains_ci(class_name, "TextProperty")) {
      copy_string(lua_reflection_probe_text_value, sizeof(lua_reflection_probe_text_value), text);
      ok = 1;
    }
  }
  if (ok) {
    ++lua_reflection_import_text_hits;
  }
  active_lua_api->push_boolean(state, ok);
  return 1;
}

static int CDECL lua_property_export_text_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_nil || !active_lua_api->push_string) {
    return 0;
  }
  char name[MAX_LUA_OBJECT_NAME];
  char class_name[MAX_LUA_CLASS_NAME];
  char out[128];
  out[0] = '\0';
  lua_read_self_string_field(state, "Name", name, sizeof(name));
  lua_read_self_string_field(state, "ClassName", class_name, sizeof(class_name));
  uintptr_t owner = lua_object_uintptr_field_arg(active_lua_api, state, 1, "OwnerAddress");
  if (owner != (uintptr_t)&ue_self_test_object) {
    active_lua_api->push_nil(state);
    return 1;
  }
  if (str_equal(name, "ProbeValue") && contains_ci(class_name, "IntProperty")) {
    export_format_signed_dec(out, sizeof(out), lua_reflection_probe_value);
  } else if (str_equal(name, "ProbeBool") && contains_ci(class_name, "BoolProperty")) {
    copy_string(out, sizeof(out), lua_reflection_probe_bool_value ? "true" : "false");
  } else if (str_equal(name, "ProbeFloat") && contains_ci(class_name, "FloatProperty")) {
    export_format_fixed3(out, sizeof(out), (double)lua_reflection_probe_float_value);
  } else if (str_equal(name, "ProbeDouble") && contains_ci(class_name, "DoubleProperty")) {
    export_format_fixed3(out, sizeof(out), lua_reflection_probe_double_value);
  } else if (str_equal(name, "ProbeString") && contains_ci(class_name, "StrProperty")) {
    copy_string(out, sizeof(out), lua_reflection_probe_string_value);
  } else if (str_equal(name, "ProbeName") && contains_ci(class_name, "NameProperty")) {
    copy_string(out, sizeof(out), lua_reflection_probe_name_string);
  } else if (str_equal(name, "ProbeText") && contains_ci(class_name, "TextProperty")) {
    copy_string(out, sizeof(out), lua_reflection_probe_text_value);
  } else {
    active_lua_api->push_nil(state);
    return 1;
  }
  ++lua_reflection_export_text_hits;
  active_lua_api->push_string(state, out);
  return 1;
}

static int CDECL lua_property_get_property_class_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_nil) {
    return 0;
  }
  char class_name[MAX_LUA_CLASS_NAME];
  lua_read_self_string_field(state, "ClassName", class_name, sizeof(class_name));
  if (!contains_ci(class_name, "ObjectProperty") &&
      !contains_ci(class_name, "ClassProperty") &&
      !contains_ci(class_name, "InterfaceProperty")) {
    active_lua_api->push_nil(state);
    return 1;
  }
  LuaObjectHandle synthetic;
  for (size_t i = 0; i < sizeof(synthetic); ++i) {
    ((unsigned char *)&synthetic)[i] = 0;
  }
  copy_string(synthetic.path, sizeof(synthetic.path), "/RuntimeProbe/Class/UObject");
  copy_string(synthetic.name, sizeof(synthetic.name), "UObject");
  copy_string(synthetic.class_name, sizeof(synthetic.class_name), "UClass");
  synthetic.address = 0;
  return push_lua_object_handle(active_lua_api, state, &synthetic) ? 1 : 0;
}

static int CDECL lua_bool_property_get_byte_mask_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_integer) {
    return 0;
  }
  active_lua_api->push_integer(state, 1);
  return 1;
}

static int CDECL lua_bool_property_get_byte_offset_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_integer) {
    return 0;
  }
  active_lua_api->push_integer(state, 0);
  return 1;
}

static int CDECL lua_bool_property_get_field_mask_callback(LuaState *state) {
  return lua_bool_property_get_byte_mask_callback(state);
}

static int CDECL lua_bool_property_get_field_size_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_integer || !active_lua_api->get_field || !active_lua_api->set_top) {
    return 0;
  }
  active_lua_api->get_field(state, 1, "ElementSize");
  int is_number = 0;
  long long size = lua_to_integer(active_lua_api, state, -1, &is_number);
  active_lua_api->set_top(state, -2);
  active_lua_api->push_integer(state, is_number && size > 0 ? size : 1);
  return 1;
}

static int CDECL lua_struct_property_get_struct_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_nil) {
    return 0;
  }
  char class_name[MAX_LUA_CLASS_NAME];
  char type_name[MAX_LUA_CLASS_NAME];
  char property_name[MAX_LUA_OBJECT_NAME];
  lua_read_self_string_field(state, "ClassName", class_name, sizeof(class_name));
  lua_read_self_string_field(state, "Type", type_name, sizeof(type_name));
  lua_read_self_string_field(state, "Name", property_name, sizeof(property_name));
  long long element_size = 0;
  if (active_lua_api->get_field && active_lua_api->set_top) {
    active_lua_api->get_field(state, 1, "ElementSize");
    int is_number = 0;
    element_size = lua_to_integer(active_lua_api, state, -1, &is_number);
    active_lua_api->set_top(state, -2);
    if (!is_number) {
      element_size = 0;
    }
  }
  if (contains_ci(class_name, "StructProperty") &&
      (contains_ci(type_name, "vector") ||
       str_equal(property_name, "Location") ||
       element_size == (long long)sizeof(UeFVectorValue) ||
       element_size == (long long)(sizeof(float) * 3))) {
    return push_lua_fvector_struct_handle(active_lua_api, state) ? 1 : 0;
  }
  active_lua_api->push_nil(state);
  return 1;
}

static int CDECL lua_array_property_get_inner_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_nil) {
    return 0;
  }
  char class_name[MAX_LUA_CLASS_NAME];
  char inner_name[MAX_LUA_OBJECT_NAME];
  char inner_class_name[MAX_LUA_CLASS_NAME];
  char inner_type[MAX_LUA_CLASS_NAME];
  long long inner_size = (long long)lua_object_uintptr_field_arg(active_lua_api, state, 1, "InnerElementSize");
  uintptr_t inner_address = lua_object_uintptr_field_arg(active_lua_api, state, 1, "InnerAddress");
  lua_read_self_string_field(state, "ClassName", class_name, sizeof(class_name));
  lua_read_self_string_field(state, "InnerName", inner_name, sizeof(inner_name));
  lua_read_self_string_field(state, "InnerClassName", inner_class_name, sizeof(inner_class_name));
  lua_read_self_string_field(state, "InnerType", inner_type, sizeof(inner_type));
  if (contains_ci(class_name, "ArrayProperty")) {
    if (!inner_name[0]) {
      copy_string(inner_name, sizeof(inner_name), "Inner");
    }
    if (!inner_class_name[0]) {
      copy_string(inner_class_name, sizeof(inner_class_name), "FIntProperty");
    }
    if (!inner_type[0]) {
      copy_string(inner_type, sizeof(inner_type), "int32");
    }
    if (inner_size <= 0) {
      inner_size = 4;
    }
    if (!inner_address) {
      inner_address = (uintptr_t)&lua_reflection_probe_array_values[0];
    }
    ++lua_reflection_array_inner_property_hits;
    return push_lua_property_descriptor(
      active_lua_api,
      state,
      "/RuntimeProbe/Property/ArrayInner",
      0,
      inner_name,
      inner_class_name,
      inner_type,
      0,
      inner_size,
      0,
      inner_address,
      "array-inner"
    );
  }
  active_lua_api->push_nil(state);
  return 1;
}

static int CDECL lua_enum_property_get_enum_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_nil) {
    return 0;
  }
  char class_name[MAX_LUA_CLASS_NAME];
  char enum_name[MAX_LUA_OBJECT_NAME];
  char enum_path[MAX_LUA_OBJECT_PATH];
  lua_read_self_string_field(state, "ClassName", class_name, sizeof(class_name));
  lua_read_self_string_field(state, "EnumName", enum_name, sizeof(enum_name));
  lua_read_self_string_field(state, "EnumPath", enum_path, sizeof(enum_path));
  if (contains_ci(class_name, "EnumProperty")) {
    LuaObjectHandle synthetic;
    for (size_t i = 0; i < sizeof(synthetic); ++i) {
      ((unsigned char *)&synthetic)[i] = 0;
    }
    copy_string(synthetic.path, sizeof(synthetic.path), enum_path[0] ? enum_path : "/Script/UE4SSLProbe.EProbeMode");
    copy_string(synthetic.name, sizeof(synthetic.name), enum_name[0] ? enum_name : "EProbeMode");
    copy_string(synthetic.class_name, sizeof(synthetic.class_name), "UEnum");
    synthetic.address = (uintptr_t)&lua_reflection_probe_enum_value;
    ++lua_reflection_enum_property_hits;
    return push_lua_object_handle(active_lua_api, state, &synthetic) ? 1 : 0;
  }
  active_lua_api->push_nil(state);
  return 1;
}

static int CDECL lua_enum_property_get_underlying_property_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_nil) {
    return 0;
  }
  char class_name[MAX_LUA_CLASS_NAME];
  char underlying_name[MAX_LUA_OBJECT_NAME];
  char underlying_class_name[MAX_LUA_CLASS_NAME];
  char underlying_type[MAX_LUA_CLASS_NAME];
  lua_read_self_string_field(state, "ClassName", class_name, sizeof(class_name));
  lua_read_self_string_field(state, "UnderlyingName", underlying_name, sizeof(underlying_name));
  lua_read_self_string_field(state, "UnderlyingClassName", underlying_class_name, sizeof(underlying_class_name));
  lua_read_self_string_field(state, "UnderlyingType", underlying_type, sizeof(underlying_type));
  if (contains_ci(class_name, "EnumProperty")) {
    if (!underlying_name[0]) {
      copy_string(underlying_name, sizeof(underlying_name), "Underlying");
    }
    if (!underlying_class_name[0]) {
      copy_string(underlying_class_name, sizeof(underlying_class_name), "FByteProperty");
    }
    if (!underlying_type[0]) {
      copy_string(underlying_type, sizeof(underlying_type), "uint8");
    }
    ++lua_reflection_enum_underlying_property_hits;
    return push_lua_property_descriptor(
      active_lua_api,
      state,
      "/RuntimeProbe/Property/EnumUnderlying",
      0,
      underlying_name,
      underlying_class_name,
      underlying_type,
      0,
      1,
      0,
      (uintptr_t)&lua_reflection_probe_enum_value,
      "enum-underlying"
    );
  }
  active_lua_api->push_nil(state);
  return 1;
}

static int CDECL lua_set_property_get_element_property_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_nil) {
    return 0;
  }
  char class_name[MAX_LUA_CLASS_NAME];
  char element_name[MAX_LUA_OBJECT_NAME];
  char element_class_name[MAX_LUA_CLASS_NAME];
  char element_type[MAX_LUA_CLASS_NAME];
  long long element_size = (long long)lua_object_uintptr_field_arg(active_lua_api, state, 1, "ElementElementSize");
  uintptr_t element_address = lua_object_uintptr_field_arg(active_lua_api, state, 1, "ElementAddress");
  if (element_size <= 0) {
    element_size = (long long)lua_object_uintptr_field_arg(active_lua_api, state, 1, "ElementSize");
  }
  lua_read_self_string_field(state, "ClassName", class_name, sizeof(class_name));
  lua_read_self_string_field(state, "ElementName", element_name, sizeof(element_name));
  lua_read_self_string_field(state, "ElementClassName", element_class_name, sizeof(element_class_name));
  lua_read_self_string_field(state, "ElementType", element_type, sizeof(element_type));
  if (contains_ci(class_name, "SetProperty")) {
    if (!element_name[0]) {
      copy_string(element_name, sizeof(element_name), "Element");
    }
    if (!element_class_name[0]) {
      copy_string(element_class_name, sizeof(element_class_name), "FIntProperty");
    }
    if (!element_type[0]) {
      copy_string(element_type, sizeof(element_type), "int32");
    }
    if (element_size <= 0) {
      element_size = 4;
    }
    if (!element_address) {
      element_address = (uintptr_t)&lua_reflection_probe_set_values[0];
    }
    ++lua_reflection_set_element_property_hits;
    return push_lua_property_descriptor(active_lua_api, state, "/RuntimeProbe/Property/SetElement", 0, element_name, element_class_name, element_type, 0, element_size, 0, element_address, "set-element");
  }
  active_lua_api->push_nil(state);
  return 1;
}

static int CDECL lua_map_property_get_key_property_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_nil) {
    return 0;
  }
  char class_name[MAX_LUA_CLASS_NAME];
  char key_name[MAX_LUA_OBJECT_NAME];
  char key_class_name[MAX_LUA_CLASS_NAME];
  char key_type[MAX_LUA_CLASS_NAME];
  long long key_size = (long long)lua_object_uintptr_field_arg(active_lua_api, state, 1, "KeyElementSize");
  uintptr_t key_address = lua_object_uintptr_field_arg(active_lua_api, state, 1, "KeyAddress");
  lua_read_self_string_field(state, "ClassName", class_name, sizeof(class_name));
  lua_read_self_string_field(state, "KeyName", key_name, sizeof(key_name));
  lua_read_self_string_field(state, "KeyClassName", key_class_name, sizeof(key_class_name));
  lua_read_self_string_field(state, "KeyType", key_type, sizeof(key_type));
  if (contains_ci(class_name, "MapProperty")) {
    if (!key_name[0]) {
      copy_string(key_name, sizeof(key_name), "Key");
    }
    if (!key_class_name[0]) {
      copy_string(key_class_name, sizeof(key_class_name), "FIntProperty");
    }
    if (!key_type[0]) {
      copy_string(key_type, sizeof(key_type), "int32");
    }
    if (key_size <= 0) {
      key_size = 4;
    }
    if (!key_address) {
      key_address = (uintptr_t)&lua_reflection_probe_map_key_value;
    }
    ++lua_reflection_map_key_property_hits;
    return push_lua_property_descriptor(active_lua_api, state, "/RuntimeProbe/Property/MapKey", 0, key_name, key_class_name, key_type, 0, key_size, 0, key_address, "map-key");
  }
  active_lua_api->push_nil(state);
  return 1;
}

static int CDECL lua_map_property_get_value_property_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_nil) {
    return 0;
  }
  char class_name[MAX_LUA_CLASS_NAME];
  char value_name[MAX_LUA_OBJECT_NAME];
  char value_class_name[MAX_LUA_CLASS_NAME];
  char value_type[MAX_LUA_CLASS_NAME];
  long long value_size = (long long)lua_object_uintptr_field_arg(active_lua_api, state, 1, "ValueElementSize");
  uintptr_t value_address = lua_object_uintptr_field_arg(active_lua_api, state, 1, "ValueAddress");
  lua_read_self_string_field(state, "ClassName", class_name, sizeof(class_name));
  lua_read_self_string_field(state, "ValueName", value_name, sizeof(value_name));
  lua_read_self_string_field(state, "ValueClassName", value_class_name, sizeof(value_class_name));
  lua_read_self_string_field(state, "ValueType", value_type, sizeof(value_type));
  if (contains_ci(class_name, "MapProperty")) {
    if (!value_name[0]) {
      copy_string(value_name, sizeof(value_name), "Value");
    }
    if (!value_class_name[0]) {
      copy_string(value_class_name, sizeof(value_class_name), "FStrProperty");
    }
    if (!value_type[0]) {
      copy_string(value_type, sizeof(value_type), "string");
    }
    if (value_size <= 0) {
      value_size = (long long)sizeof(UeFStringValue);
    }
    if (!value_address) {
      value_address = (uintptr_t)&lua_reflection_probe_map_value[0];
    }
    ++lua_reflection_map_value_property_hits;
    return push_lua_property_descriptor(active_lua_api, state, "/RuntimeProbe/Property/MapValue", 0, value_name, value_class_name, value_type, 0, value_size, 0, value_address, "map-value");
  }
  active_lua_api->push_nil(state);
  return 1;
}

static int CDECL lua_property_type_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_string) {
    return 0;
  }
  char class_name[MAX_LUA_CLASS_NAME];
  lua_read_self_string_field(state, "ClassName", class_name, sizeof(class_name));
  active_lua_api->push_string(state, class_name[0] ? class_name : "Property");
  return 1;
}

static int CDECL lua_object_process_console_exec_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_boolean) {
    return 0;
  }
  const char *raw_command = active_lua_api->to_lstring ? active_lua_api->to_lstring(state, 2, 0) : 0;
  char command[128];
  char args[MAX_LUA_OBJECT_PATH];
  lua_split_console_command(raw_command, command, sizeof(command), args, sizeof(args));
  int handled = invoke_lua_process_console_exec_hooks(state, 1, raw_command, command, args, 0);
  if (!handled) {
    handled = invoke_lua_console_command_handlers(state, raw_command);
  }
  if (invoke_lua_process_console_exec_hooks(state, 0, raw_command, command, args, handled)) {
    handled = 1;
  }
  active_lua_api->push_boolean(state, handled);
  return 1;
}

static int CDECL lua_object_local_player_exec_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_boolean) {
    return 0;
  }
  const char *raw_command = active_lua_api->to_lstring ? active_lua_api->to_lstring(state, 2, 0) : 0;
  char command[128];
  char args[MAX_LUA_OBJECT_PATH];
  lua_split_console_command(raw_command, command, sizeof(command), args, sizeof(args));
  int handled = invoke_lua_local_player_exec_hooks(state, 1, raw_command, command, args, 0);
  if (invoke_lua_local_player_exec_hooks(state, 0, raw_command, command, args, handled)) {
    handled = 1;
  }
  active_lua_api->push_boolean(state, handled);
  return 1;
}

static int CDECL lua_function_get_function_flags_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_integer) {
    return 0;
  }
  active_lua_api->push_integer(
    state,
    (long long)lua_object_uintptr_field_arg(active_lua_api, state, 1, "FunctionFlags")
  );
  return 1;
}

static int CDECL lua_function_set_function_flags_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_integer || !active_lua_api->push_boolean ||
      !active_lua_api->set_field) {
    return 0;
  }
  int is_number = 0;
  long long value = lua_to_integer(active_lua_api, state, 2, &is_number);
  if (!is_number) {
    return 0;
  }
  uint32_t flags = (uint32_t)value;
  active_lua_api->push_integer(state, (long long)flags);
  active_lua_api->set_field(state, 1, "FunctionFlags");
  active_lua_api->push_boolean(state, 1);
  active_lua_api->set_field(state, 1, "HasFunctionFlags");
  uintptr_t address = lua_object_address_arg(active_lua_api, state, 1);
  if (address) {
    for (size_t i = 0; i < lua_object_handle_count; ++i) {
      LuaObjectHandle *object = &lua_object_handles[i];
      if (object->address == address) {
        object->function_flags = flags;
        object->has_function_flags = 1;
      }
    }
  }
  return 0;
}

static int CDECL lua_struct_get_super_struct_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_nil) {
    return 0;
  }
  char name[MAX_LUA_OBJECT_NAME];
  char class_name[MAX_LUA_CLASS_NAME];
  lua_read_self_string_field(state, "Name", name, sizeof(name));
  lua_read_self_string_field(state, "ClassName", class_name, sizeof(class_name));
  uintptr_t super_address = lua_object_uintptr_field_arg(active_lua_api, state, 1, "SuperAddress");
  if (!super_address) {
    const LuaClassMetadata *self_metadata = find_lua_class_metadata_by_address(lua_object_address_arg(active_lua_api, state, 1));
    if (self_metadata) {
      super_address = self_metadata->super_address;
    }
  }
  if (super_address) {
    const LuaObjectHandle *super = find_lua_object_by_address(super_address);
    if (super && push_lua_object_handle(active_lua_api, state, super)) {
      return 1;
    }
    const LuaClassMetadata *metadata = find_lua_class_metadata_by_address(super_address);
    LuaObjectHandle synthetic;
    for (size_t i = 0; i < sizeof(synthetic); ++i) {
      ((unsigned char *)&synthetic)[i] = 0;
    }
    static Line text;
    line_init(&text);
    line_append(&text, "/RuntimeProbe/Class/");
    line_append_hex(&text, super_address);
    copy_string(synthetic.path, sizeof(synthetic.path), text.text);
    line_init(&text);
    line_append(&text, "UClass_");
    line_append_hex(&text, super_address);
    copy_string(synthetic.name, sizeof(synthetic.name), metadata && metadata->name[0] ? metadata->name : text.text);
    copy_string(synthetic.class_name, sizeof(synthetic.class_name), "UClass");
    synthetic.address = super_address;
    synthetic.super_address = metadata ? metadata->super_address : 0;
    return push_lua_object_handle(active_lua_api, state, &synthetic) ? 1 : 0;
  }
  if (str_equal(class_name, "UClass") &&
      name[0] && !str_equal(name, "UObject") && !str_equal(name, "Object")) {
    LuaObjectHandle synthetic;
    for (size_t i = 0; i < sizeof(synthetic); ++i) {
      ((unsigned char *)&synthetic)[i] = 0;
    }
    copy_string(synthetic.path, sizeof(synthetic.path), "/RuntimeProbe/Class/UObject");
    copy_string(synthetic.name, sizeof(synthetic.name), "UObject");
    copy_string(synthetic.class_name, sizeof(synthetic.class_name), "UClass");
    synthetic.address = 0;
    return push_lua_object_handle(active_lua_api, state, &synthetic) ? 1 : 0;
  }
  active_lua_api->push_nil(state);
  return 1;
}

static int CDECL lua_struct_for_each_function_callback(LuaState *state) {
  ++lua_for_each_function_calls;
  if (!active_lua_api || !active_lua_api->type || !active_lua_api->rawgeti ||
      !active_lua_api->set_top || !active_lua_api->push_value || !active_lua_api->ref ||
      !active_lua_api->unref) {
    return 0;
  }
  if (active_lua_api->type(state, 2) != LUA_TFUNCTION_COMPAT) {
    return 0;
  }
  uintptr_t address = lua_object_address_arg(active_lua_api, state, 1);
  char name[MAX_LUA_OBJECT_NAME];
  char class_name[MAX_LUA_CLASS_NAME];
  name[0] = '\0';
  class_name[0] = '\0';
  lua_read_self_string_field(state, "Name", name, sizeof(name));
  lua_read_self_string_field(state, "ClassName", class_name, sizeof(class_name));
  int can_iterate =
    address == (uintptr_t)&ue_self_test_object ||
    str_equal(class_name, "UE4SSLProbeSelfTestClass") ||
    str_equal(name, "UE4SSLProbeSelfTestClass");
  if (!can_iterate) {
    return 0;
  }
  int callback_ref = LUA_NOREF_COMPAT;
  if (!lua_store_hook_ref(active_lua_api, state, 2, &callback_ref)) {
    return 0;
  }
  for (size_t i = 0; i < ue_function_param_descriptor_count; ++i) {
    if (ue_function_descriptor_seen_before(i)) {
      continue;
    }
    active_lua_api->rawgeti(state, LUA_REGISTRYINDEX_COMPAT, callback_ref);
    if (!push_ue_function_handle_from_descriptor(active_lua_api, state, &ue_function_param_descriptors[i])) {
      active_lua_api->set_top(state, -2);
      continue;
    }
    int status = lua_call(active_lua_api, state, 1, 1, 0);
    if (status != 0) {
      active_lua_api->set_top(state, -2);
      break;
    }
    ++lua_for_each_function_callbacks;
    int is_boolean = 0;
    int stop = lua_to_boolean(active_lua_api, state, -1, &is_boolean);
    active_lua_api->set_top(state, -2);
    if (is_boolean && stop) {
      break;
    }
  }
  lua_unref_hook_ref(active_lua_api, state, &callback_ref);
  return 0;
}

static int CDECL lua_struct_for_each_property_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->type || !active_lua_api->rawgeti ||
      !active_lua_api->set_top || !active_lua_api->push_value || !active_lua_api->ref ||
      !active_lua_api->unref) {
    return 0;
  }
  if (active_lua_api->type(state, 2) != LUA_TFUNCTION_COMPAT) {
    return 0;
  }
  int callback_ref = LUA_NOREF_COMPAT;
  if (!lua_store_hook_ref(active_lua_api, state, 2, &callback_ref)) {
    return 0;
  }
  uintptr_t address = lua_object_address_arg(active_lua_api, state, 1);
  char owner_path[MAX_LUA_OBJECT_PATH];
  owner_path[0] = '\0';
  lua_read_self_string_field(state, "PathName", owner_path, sizeof(owner_path));
  const char *self_test_properties[] = {"ProbeValue", "ProbeBool", "ProbeFloat", "ProbeDouble", "ProbeName", "ProbeString", "ProbeText", "ProbeObject", "ProbeArray", "ProbeEnum", "ProbeSet", "ProbeMap", "ClassName"};
  if (address == (uintptr_t)&ue_self_test_object) {
    for (size_t i = 0; i < sizeof(self_test_properties) / sizeof(self_test_properties[0]); ++i) {
      active_lua_api->rawgeti(state, LUA_REGISTRYINDEX_COMPAT, callback_ref);
      if (!push_self_test_property_descriptor(active_lua_api, state, address, owner_path, self_test_properties[i])) {
        active_lua_api->set_top(state, -2);
        continue;
      }
      int status = lua_call(active_lua_api, state, 1, 1, 0);
      if (status != 0) {
        active_lua_api->set_top(state, -2);
        break;
      }
      int is_boolean = 0;
      int stop = lua_to_boolean(active_lua_api, state, -1, &is_boolean);
      active_lua_api->set_top(state, -2);
      if (is_boolean && stop) {
        break;
      }
    }
  }
  for (size_t i = 0; i < ue_function_param_descriptor_count; ++i) {
    const UeFunctionParamDescriptor *descriptor = &ue_function_param_descriptors[i];
    if (descriptor->function != address) {
      continue;
    }
    active_lua_api->rawgeti(state, LUA_REGISTRYINDEX_COMPAT, callback_ref);
    const char *field_name = descriptor->field_name[0] ? descriptor->field_name : descriptor->property_name;
    if (!push_lua_property_descriptor(
          active_lua_api,
          state,
          descriptor->function_path,
          address,
          field_name,
          descriptor->class_name,
          ue_param_value_type(descriptor->class_name, descriptor->element_size),
          descriptor->offset_internal,
          descriptor->element_size,
          (long long)descriptor->property_flags,
          descriptor->field,
          "ue-function-param")) {
      active_lua_api->set_top(state, -2);
      continue;
    }
    int status = lua_call(active_lua_api, state, 1, 1, 0);
    if (status != 0) {
      active_lua_api->set_top(state, -2);
      break;
    }
    int is_boolean = 0;
    int stop = lua_to_boolean(active_lua_api, state, -1, &is_boolean);
    active_lua_api->set_top(state, -2);
    if (is_boolean && stop) {
      break;
    }
  }
  for (size_t i = 0; i < ue_reflection_property_candidate_count; ++i) {
    const UeReflectionPropertyCandidate *candidate = &ue_reflection_property_candidates[i];
    if (candidate->object != address) {
      continue;
    }
    active_lua_api->rawgeti(state, LUA_REGISTRYINDEX_COMPAT, callback_ref);
    const char *name = candidate->field_name[0] ? candidate->field_name : candidate->property_name;
    if (!push_lua_property_descriptor(
          active_lua_api,
          state,
          owner_path,
          address,
          name,
          "FProperty",
          ue_param_scalar_type(candidate->element_size),
          candidate->offset_internal,
          candidate->element_size,
          0,
          address + (uintptr_t)candidate->offset_internal,
          "ue-reflection-scan")) {
      active_lua_api->set_top(state, -2);
      continue;
    }
    int status = lua_call(active_lua_api, state, 1, 1, 0);
    if (status != 0) {
      active_lua_api->set_top(state, -2);
      break;
    }
    int is_boolean = 0;
    int stop = lua_to_boolean(active_lua_api, state, -1, &is_boolean);
    active_lua_api->set_top(state, -2);
    if (is_boolean && stop) {
      break;
    }
  }
  lua_unref_hook_ref(active_lua_api, state, &callback_ref);
  return 0;
}

static int CDECL lua_class_get_cdo_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_nil) {
    return 0;
  }
  ++lua_get_cdo_calls;
  char self_class_name[MAX_LUA_CLASS_NAME];
  lua_read_self_string_field(state, "ClassName", self_class_name, sizeof(self_class_name));
  if (!str_equal(self_class_name, "UClass")) {
    active_lua_api->push_nil(state);
    return 1;
  }
  char class_name[MAX_LUA_CLASS_NAME];
  if (!lua_read_self_string_field(state, "Name", class_name, sizeof(class_name)) || !class_name[0]) {
    active_lua_api->push_nil(state);
    return 1;
  }
  uintptr_t class_address = lua_object_address_arg(active_lua_api, state, 1);
  const LuaObjectHandle *cdo = find_or_add_lua_class_default_object(class_name, class_address);
  if (cdo && push_lua_object_handle(active_lua_api, state, cdo)) {
    ++lua_get_cdo_hits;
    return 1;
  }
  active_lua_api->push_nil(state);
  return 1;
}

static const char *lua_class_query_leaf(const char *query) {
  const char *leaf = query;
  if (!query) {
    return "";
  }
  for (const char *p = query; *p; ++p) {
    if (*p == '/' || *p == '\\' || *p == '.' || *p == ':' || *p == ' ') {
      leaf = p + 1;
    }
  }
  return leaf;
}

static int lua_class_name_equal(const char *a, const char *b) {
  if (!a || !a[0] || !b || !b[0]) {
    return 0;
  }
  if (str_equal(a, b)) {
    return 1;
  }
  if (a[0] == 'U' && str_equal(a + 1, b)) {
    return 1;
  }
  if (b[0] == 'U' && str_equal(a, b + 1)) {
    return 1;
  }
  return 0;
}

static int lua_read_class_query_arg(LuaState *state, int index, char *out, size_t out_size) {
  if (!active_lua_api || !state || !out || out_size == 0) {
    return 0;
  }
  out[0] = '\0';
  if (active_lua_api->type && active_lua_api->type(state, index) == LUA_TTABLE_COMPAT) {
    char arg_name[MAX_LUA_OBJECT_NAME];
    char arg_class[MAX_LUA_CLASS_NAME];
    arg_name[0] = '\0';
    arg_class[0] = '\0';
    lua_table_string_field(active_lua_api, state, index, "Name", arg_name, sizeof(arg_name));
    lua_table_string_field(active_lua_api, state, index, "ClassName", arg_class, sizeof(arg_class));
    if (lua_class_name_equal(arg_class, "UClass") && arg_name[0]) {
      copy_string(out, out_size, arg_name);
      return 1;
    }
    if (arg_class[0]) {
      copy_string(out, out_size, arg_class);
      return 1;
    }
    if (arg_name[0]) {
      copy_string(out, out_size, arg_name);
      return 1;
    }
  }
  const char *query = active_lua_api->to_lstring ? active_lua_api->to_lstring(state, index, 0) : 0;
  if (query && query[0]) {
    copy_string(out, out_size, query);
    return 1;
  }
  return 0;
}

static int lua_class_child_query_matches(const char *self_name, const char *self_class, const char *query) {
  if (!query || !query[0]) {
    return 0;
  }
  const char *leaf = lua_class_query_leaf(query);
  int query_is_uobject = lua_class_name_equal(query, "UObject") || lua_class_name_equal(leaf, "UObject");
  int query_is_self_name = lua_class_name_equal(query, self_name) || lua_class_name_equal(leaf, self_name);
  if (lua_class_name_equal(self_class, "UClass")) {
    return query_is_uobject || query_is_self_name;
  }
  return query_is_uobject ||
         query_is_self_name ||
         lua_class_name_equal(query, self_class) ||
         lua_class_name_equal(leaf, self_class);
}

static int lua_class_address_is_child_of(uintptr_t self_address, uintptr_t query_address) {
  if (!self_address || !query_address) {
    return 0;
  }
  uintptr_t current = self_address;
  for (size_t depth = 0; depth <= MAX_LUA_CLASS_METADATA; ++depth) {
    if (current == query_address) {
      return 1;
    }
    const LuaClassMetadata *metadata = find_lua_class_metadata_by_address(current);
    if (!metadata || !metadata->super_address || metadata->super_address == current) {
      break;
    }
    current = metadata->super_address;
  }
  return 0;
}

static int CDECL lua_class_is_child_of_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_boolean) {
    return 0;
  }
  char self_name[MAX_LUA_OBJECT_NAME];
  char self_class[MAX_LUA_CLASS_NAME];
  char query[MAX_LUA_OBJECT_PATH];
  lua_read_self_string_field(state, "Name", self_name, sizeof(self_name));
  lua_read_self_string_field(state, "ClassName", self_class, sizeof(self_class));
  int ok = 0;
  if (lua_read_class_query_arg(state, 2, query, sizeof(query))) {
    ok = lua_class_child_query_matches(self_name, self_class, query);
  }
  if (!ok) {
    ok = lua_class_address_is_child_of(
      lua_object_address_arg(active_lua_api, state, 1),
      lua_object_address_arg(active_lua_api, state, 2)
    );
  }
  active_lua_api->push_boolean(state, ok);
  return 1;
}

static int CDECL lua_actor_get_level_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_nil) {
    return 0;
  }
  ++lua_get_level_calls;
  uintptr_t address = lua_object_address_arg(active_lua_api, state, 1);
  const LuaObjectHandle *self = find_lua_object_by_address(address);
  if (self && lua_object_handle_is_level_like(self) && push_lua_object_handle(active_lua_api, state, self)) {
    ++lua_get_level_hits;
    return 1;
  }
  uintptr_t outer_address = lua_object_uintptr_field_arg(active_lua_api, state, 1, "OuterAddress");
  const LuaObjectHandle *level = find_lua_level_from_outer_chain(outer_address);
  if (level && push_lua_object_handle(active_lua_api, state, level)) {
    ++lua_get_level_hits;
    return 1;
  }
  active_lua_api->push_nil(state);
  return 1;
}

static int CDECL lua_get_property_value_callback(LuaState *state) {
  ++lua_reflection_get_property_calls;
  if (!active_lua_api || !active_lua_api->push_nil) {
    return 0;
  }
  uintptr_t address = lua_object_address_arg(active_lua_api, state, 1);
  const char *property = active_lua_api->to_lstring ? active_lua_api->to_lstring(state, 2, 0) : 0;
  if (address == (uintptr_t)&ue_self_test_object && property && str_equal(property, "ProbeValue")) {
    ++lua_reflection_get_property_hits;
    active_lua_api->push_integer(state, lua_reflection_probe_value);
    return 1;
  }
  if (address == (uintptr_t)&ue_self_test_object && property && str_equal(property, "ProbeBool")) {
    ++lua_reflection_get_property_hits;
    active_lua_api->push_boolean(state, lua_reflection_probe_bool_value);
    return 1;
  }
  if (address == (uintptr_t)&ue_self_test_object && property && str_equal(property, "ProbeFloat")) {
    ++lua_reflection_get_property_hits;
    active_lua_api->push_number(state, (double)lua_reflection_probe_float_value);
    return 1;
  }
  if (address == (uintptr_t)&ue_self_test_object && property && str_equal(property, "ProbeDouble")) {
    ++lua_reflection_get_property_hits;
    active_lua_api->push_number(state, lua_reflection_probe_double_value);
    return 1;
  }
  if (address == (uintptr_t)&ue_self_test_object && property && str_equal(property, "ProbeName")) {
    if (push_lua_fname_table(
          active_lua_api,
          state,
          lua_reflection_probe_name_string,
          (long long)lua_reflection_probe_name_value.comparison_index,
          (long long)lua_reflection_probe_name_value.number,
          lua_reflection_probe_name_string[0] != '\0')) {
      ++lua_reflection_get_property_hits;
      return 1;
    }
  }
  if (address == (uintptr_t)&ue_self_test_object && property && str_equal(property, "ProbeString")) {
    ++lua_reflection_get_property_hits;
    active_lua_api->push_string(state, lua_reflection_probe_string_value);
    return 1;
  }
  if (address == (uintptr_t)&ue_self_test_object && property && str_equal(property, "ProbeText")) {
    if (push_lua_ftext_table(active_lua_api, state, lua_reflection_probe_text_value)) {
      ++lua_reflection_get_property_hits;
      return 1;
    }
  }
  if (address == (uintptr_t)&ue_self_test_object && property && str_equal(property, "ProbeObject")) {
    const LuaObjectHandle *object = find_lua_object_by_path_or_name("/Script/UE4SSLProbe.SelfTestObject");
    if (object && object->address == lua_reflection_probe_object_address &&
        push_lua_object_handle(active_lua_api, state, object)) {
      ++lua_reflection_get_property_hits;
      return 1;
    }
  }
  if (address == (uintptr_t)&ue_self_test_object && property && str_equal(property, "ClassName")) {
    ++lua_reflection_get_property_hits;
    active_lua_api->push_string(state, "UE4SSLProbeSelfTestClass");
    return 1;
  }
  long long raw_property_value = 0;
  int matched_field_name = 0;
  if (read_ue_reflection_property_candidate(address, property, &raw_property_value, &matched_field_name)) {
    ++lua_reflection_get_property_hits;
    ++lua_reflection_raw_property_hits;
    if (matched_field_name) {
      ++lua_reflection_named_property_hits;
    }
    lua_reflection_raw_property_value = raw_property_value;
    active_lua_api->push_integer(state, raw_property_value);
    return 1;
  }
  active_lua_api->push_nil(state);
  return 1;
}

static int CDECL lua_set_property_value_callback(LuaState *state) {
  ++lua_reflection_set_property_calls;
  if (!active_lua_api || !active_lua_api->push_boolean) {
    return 0;
  }
  uintptr_t address = lua_object_address_arg(active_lua_api, state, 1);
  const char *property = active_lua_api->to_lstring ? active_lua_api->to_lstring(state, 2, 0) : 0;
  int is_number = 0;
  long long value = lua_to_integer(active_lua_api, state, 3, &is_number);
  int is_real_number = 0;
  double number_value = lua_to_number(active_lua_api, state, 3, &is_real_number);
  if (address == (uintptr_t)&ue_self_test_object && property && str_equal(property, "ProbeValue") && is_number) {
    lua_reflection_probe_value = value;
    ++lua_reflection_set_property_hits;
    active_lua_api->push_boolean(state, 1);
    return 1;
  }
  if (address == (uintptr_t)&ue_self_test_object && property && str_equal(property, "ProbeBool")) {
    int is_boolean = 0;
    int bool_value = lua_to_boolean(active_lua_api, state, 3, &is_boolean);
    if (is_boolean) {
      lua_reflection_probe_bool_value = bool_value;
      ++lua_reflection_set_property_hits;
      active_lua_api->push_boolean(state, 1);
      return 1;
    }
  }
  if (address == (uintptr_t)&ue_self_test_object && property && str_equal(property, "ProbeFloat") && is_real_number) {
    lua_reflection_probe_float_value = (float)number_value;
    ++lua_reflection_set_property_hits;
    active_lua_api->push_boolean(state, 1);
    return 1;
  }
  if (address == (uintptr_t)&ue_self_test_object && property && str_equal(property, "ProbeDouble") && is_real_number) {
    lua_reflection_probe_double_value = number_value;
    ++lua_reflection_set_property_hits;
    active_lua_api->push_boolean(state, 1);
    return 1;
  }
  if (address == (uintptr_t)&ue_self_test_object && property && str_equal(property, "ProbeName")) {
    char name_value[sizeof(lua_reflection_probe_name_string)];
    name_value[0] = '\0';
    lua_copy_string_arg_or_field(active_lua_api, state, 3, "Name", name_value, sizeof(name_value), 0);
    if (!name_value[0]) {
      lua_copy_string_arg_or_field(active_lua_api, state, 3, "String", name_value, sizeof(name_value), 0);
    }
    if (name_value[0]) {
      copy_string(lua_reflection_probe_name_string, sizeof(lua_reflection_probe_name_string), name_value);
      lua_reflection_probe_name_value.comparison_index = (uint32_t)lua_object_uintptr_field_arg(active_lua_api, state, 3, "ComparisonIndex");
      lua_reflection_probe_name_value.number = (uint32_t)lua_object_uintptr_field_arg(active_lua_api, state, 3, "Number");
      ++lua_reflection_set_property_hits;
      active_lua_api->push_boolean(state, 1);
      return 1;
    }
  }
  if (address == (uintptr_t)&ue_self_test_object && property && str_equal(property, "ProbeString")) {
    size_t value_len = 0;
    const char *string_value = active_lua_api->to_lstring ? active_lua_api->to_lstring(state, 3, &value_len) : 0;
    if (string_value) {
      size_t copy_len = value_len;
      size_t max_copy = sizeof(lua_reflection_probe_string_value) - 1;
      if (copy_len > max_copy) {
        copy_len = max_copy;
      }
      for (size_t i = 0; i < copy_len; ++i) {
        lua_reflection_probe_string_value[i] = string_value[i];
      }
      lua_reflection_probe_string_value[copy_len] = '\0';
      ++lua_reflection_set_property_hits;
      active_lua_api->push_boolean(state, 1);
      return 1;
    }
  }
  if (address == (uintptr_t)&ue_self_test_object && property && str_equal(property, "ProbeText")) {
    char text_value[sizeof(lua_reflection_probe_text_value)];
    text_value[0] = '\0';
    lua_copy_string_arg_or_field(active_lua_api, state, 3, "Text", text_value, sizeof(text_value), 0);
    if (text_value[0]) {
      copy_string(lua_reflection_probe_text_value, sizeof(lua_reflection_probe_text_value), text_value);
      ++lua_reflection_set_property_hits;
      active_lua_api->push_boolean(state, 1);
      return 1;
    }
  }
  if (address == (uintptr_t)&ue_self_test_object && property && str_equal(property, "ProbeObject")) {
    uintptr_t object_address = lua_object_address_arg(active_lua_api, state, 3);
    if (object_address) {
      lua_reflection_probe_object_address = object_address;
      ++lua_reflection_set_property_hits;
      active_lua_api->push_boolean(state, 1);
      return 1;
    }
  }
  if (env_bool("UE4SSL_WIN_LUA_REFLECTION_RAW_SET_ENABLED", 0) && is_number &&
      write_ue_reflection_property_candidate(address, property, value)) {
    ++lua_reflection_set_property_hits;
    ++lua_reflection_raw_property_set_hits;
    lua_reflection_raw_property_set_value = value;
    active_lua_api->push_boolean(state, 1);
    return 1;
  }
  active_lua_api->push_boolean(state, 0);
  return 1;
}

static int CDECL lua_call_function_callback(LuaState *state) {
  ++lua_reflection_call_function_calls;
  if (!active_lua_api || !active_lua_api->push_nil) {
    return 0;
  }
  uintptr_t address = lua_object_address_arg(active_lua_api, state, 1);
  const char *function = active_lua_api->to_lstring ? active_lua_api->to_lstring(state, 2, 0) : 0;
  const char *args = active_lua_api->to_lstring ? active_lua_api->to_lstring(state, 3, 0) : 0;
  if (invoke_lua_call_function_hooks(state, 1, function, args, 0, 0)) {
    ++lua_reflection_call_function_hits;
    return 1;
  }
  if (address == (uintptr_t)&ue_self_test_object && function && str_equal(function, "DoubleProbeValue")) {
    ++lua_reflection_call_function_hits;
    active_lua_api->push_integer(state, lua_reflection_probe_value * 2);
    if (invoke_lua_call_function_hooks(state, 0, function, args, 1, 1)) {
      return 1;
    }
    return 1;
  }
  if (address == (uintptr_t)&ue_self_test_object && function && str_equal(function, "IsProbeBoolSet")) {
    ++lua_reflection_call_function_hits;
    active_lua_api->push_boolean(state, lua_reflection_probe_bool_value);
    if (invoke_lua_call_function_hooks(state, 0, function, args, 1, 1)) {
      return 1;
    }
    return 1;
  }
  active_lua_api->push_nil(state);
  if (invoke_lua_call_function_hooks(state, 0, function, args, 0, 1)) {
    ++lua_reflection_call_function_hits;
    return 1;
  }
  return 1;
}

static int lua_process_event_param_name_matches(const char *param, const char *canonical) {
  if (!param || !canonical) {
    return 0;
  }
  if (str_equal(param, canonical)) {
    return 1;
  }
  if (str_equal(canonical, "Value") && str_equal(param, "value")) {
    return 1;
  }
  if (str_equal(canonical, "OriginalResult") &&
      (str_equal(param, "original_result") || str_equal(param, "originalResult"))) {
    return 1;
  }
  if (str_equal(canonical, "Touched") && str_equal(param, "touched")) {
    return 1;
  }
  return 0;
}

static const ProcessEventParamDescriptor *find_process_event_param_descriptor(const char *param) {
  for (size_t i = 0; i < process_event_self_test_param_descriptor_count; ++i) {
    const ProcessEventParamDescriptor *descriptor = &process_event_self_test_param_descriptors[i];
    if (lua_process_event_param_name_matches(param, descriptor->name) ||
        (descriptor->alias1 && str_equal(param, descriptor->alias1)) ||
        (descriptor->alias2 && str_equal(param, descriptor->alias2))) {
      return descriptor;
    }
  }
  return 0;
}

static const ProcessEventParamDescriptor *find_process_event_param_descriptor_arg(LuaState *state, int index) {
  if (!active_lua_api || !state) {
    return 0;
  }
  char name[64];
  name[0] = '\0';
  if (active_lua_api->type && active_lua_api->type(state, index) == LUA_TTABLE_COMPAT &&
      active_lua_api->get_field && active_lua_api->set_top) {
    active_lua_api->get_field(state, index, "Name");
    const char *field_name = active_lua_api->to_lstring ? active_lua_api->to_lstring(state, -1, 0) : 0;
    if (field_name && field_name[0]) {
      copy_string(name, sizeof(name), field_name);
    }
    active_lua_api->set_top(state, -2);
  } else {
    const char *field_name = active_lua_api->to_lstring ? active_lua_api->to_lstring(state, index, 0) : 0;
    if (field_name && field_name[0]) {
      copy_string(name, sizeof(name), field_name);
    }
  }
  return name[0] ? find_process_event_param_descriptor(name) : 0;
}

static int lua_table_integer_field(LuaApi *api, LuaState *state, int index, const char *field, long long *out) {
  if (!api || !state || !field || !out || !api->get_field || !api->set_top) {
    return 0;
  }
  api->get_field(state, index, field);
  int is_number = 0;
  long long value = lua_to_integer(api, state, -1, &is_number);
  api->set_top(state, -2);
  if (!is_number) {
    return 0;
  }
  *out = value;
  return 1;
}

static int lua_table_number_field(LuaApi *api, LuaState *state, int index, const char *field, double *out) {
  if (!api || !state || !field || !out || !api->get_field || !api->set_top) {
    return 0;
  }
  api->get_field(state, index, field);
  int is_number = 0;
  double value = lua_to_number(api, state, -1, &is_number);
  api->set_top(state, -2);
  if (!is_number) {
    return 0;
  }
  *out = value;
  return 1;
}

static int lua_table_number_field_alias(
  LuaApi *api,
  LuaState *state,
  int index,
  const char *primary,
  const char *fallback,
  double *out
) {
  return lua_table_number_field(api, state, index, primary, out) ||
         lua_table_number_field(api, state, index, fallback, out);
}

static int lua_table_string_field(LuaApi *api, LuaState *state, int index, const char *field, char *out, size_t out_size) {
  if (!api || !state || !field || !out || out_size == 0 || !api->get_field || !api->set_top) {
    return 0;
  }
  api->get_field(state, index, field);
  const char *value = api->to_lstring ? api->to_lstring(state, -1, 0) : 0;
  if (value && value[0]) {
    copy_string(out, out_size, value);
  }
  api->set_top(state, -2);
  return value && value[0];
}

static int lua_param_descriptor_view_arg(LuaState *state, int index, LuaParamDescriptorView *out) {
  if (!active_lua_api || !state || !out) {
    return 0;
  }
  for (size_t i = 0; i < sizeof(*out); ++i) {
    ((unsigned char *)out)[i] = 0;
  }
  if (active_lua_api->type && active_lua_api->type(state, index) == LUA_TTABLE_COMPAT &&
      active_lua_api->get_field && active_lua_api->set_top) {
    active_lua_api->get_field(state, index, "Name");
    const char *field_name = active_lua_api->to_lstring ? active_lua_api->to_lstring(state, -1, 0) : 0;
	    if (field_name && field_name[0]) {
	      copy_string(out->name, sizeof(out->name), field_name);
	    }
    active_lua_api->set_top(state, -2);
    lua_table_string_field(active_lua_api, state, index, "Type", out->type, sizeof(out->type));
    lua_table_string_field(active_lua_api, state, index, "ClassName", out->class_name, sizeof(out->class_name));
    lua_table_string_field(active_lua_api, state, index, "InnerName", out->inner_name, sizeof(out->inner_name));
    lua_table_string_field(active_lua_api, state, index, "InnerType", out->inner_type, sizeof(out->inner_type));
    lua_table_string_field(active_lua_api, state, index, "InnerClassName", out->inner_class_name, sizeof(out->inner_class_name));
    long long offset = 0;
    long long size = 0;
    long long inner_size = 0;
    if (!lua_table_integer_field(active_lua_api, state, index, "OffsetInternal", &offset)) {
      lua_table_integer_field(active_lua_api, state, index, "Offset", &offset);
    }
    if (!lua_table_integer_field(active_lua_api, state, index, "ElementSize", &size)) {
      lua_table_integer_field(active_lua_api, state, index, "Size", &size);
    }
    if (lua_table_integer_field(active_lua_api, state, index, "InnerElementSize", &inner_size) && inner_size > 0) {
      out->inner_size = (size_t)inner_size;
    }
    if (offset >= 0 && size > 0 && size <= MAX_PROCESS_EVENT_PARAM_BYTES) {
      out->offset = (size_t)offset;
      out->size = (size_t)size;
      out->valid = lua_param_descriptor_size_supported(out);
      return out->valid;
    }
    return 0;
  }
  const ProcessEventParamDescriptor *descriptor = find_process_event_param_descriptor_arg(state, index);
  if (!descriptor) {
    return 0;
	  }
  copy_string(out->name, sizeof(out->name), descriptor->name);
  copy_string(out->type, sizeof(out->type), descriptor->type);
  copy_string(out->class_name, sizeof(out->class_name), descriptor->class_name);
	  out->offset = descriptor->offset;
  out->size = descriptor->size;
  out->valid = 1;
  return 1;
}

static int ue_function_param_descriptor_to_view(
  const UeFunctionParamDescriptor *descriptor,
  LuaParamDescriptorView *out
) {
  if (!descriptor || !out || descriptor->offset_internal < 0 || descriptor->element_size <= 0) {
    return 0;
  }
  for (size_t i = 0; i < sizeof(*out); ++i) {
    ((unsigned char *)out)[i] = 0;
  }
  const char *class_name = ue_param_class_name_or_default(descriptor->class_name);
  const char *name = descriptor->field_name[0] ? descriptor->field_name : descriptor->property_name;
  copy_string(out->name, sizeof(out->name), name ? name : "");
  copy_string(out->class_name, sizeof(out->class_name), class_name);
  copy_string(out->type, sizeof(out->type), ue_param_value_type(class_name, descriptor->element_size));
  out->offset = (size_t)descriptor->offset_internal;
  out->size = (size_t)descriptor->element_size;
  for (size_t i = 0; i < descriptor->child_count && i < 2; ++i) {
    const UeFunctionParamChildDescriptor *child = &descriptor->children[i];
    if (child->present && str_equal(child->role, "inner")) {
      copy_string(out->inner_name, sizeof(out->inner_name), child->name);
      copy_string(out->inner_type, sizeof(out->inner_type), child->type);
      copy_string(out->inner_class_name, sizeof(out->inner_class_name), child->class_name);
      out->inner_size = child->element_size > 0 ? (size_t)child->element_size : 0;
      break;
    }
  }
  out->valid = lua_param_descriptor_size_supported(out);
  return out->valid;
}

static uintptr_t lua_process_event_params_address_arg(LuaState *state) {
  uintptr_t address = lua_object_address_arg(active_lua_api, state, 1);
  if (!address || address != active_process_event_lua_params_address) {
    return 0;
  }
  return address;
}

static int read_process_event_param_bytes(
  uintptr_t params,
  const LuaParamDescriptorView *descriptor,
  void *buffer,
  size_t buffer_size
) {
  if (!params || !descriptor || !descriptor->valid || !buffer ||
      descriptor->size == 0 || descriptor->size > buffer_size ||
      descriptor->size > MAX_PROCESS_EVENT_PARAM_BYTES) {
    return 0;
  }
  uintptr_t address = params + descriptor->offset;
  if (address < params) {
    return 0;
  }
  MEMORY_BASIC_INFORMATION_WIN64 mbi;
  for (size_t i = 0; i < sizeof(mbi); ++i) {
    ((char *)&mbi)[i] = 0;
  }
  SIZE_T got = VirtualQuery((const void *)address, &mbi, sizeof(mbi));
  if (!got || mbi.State != MEM_COMMIT || !readable_protect(mbi.Protect) ||
      !region_contains_range(&mbi, address, descriptor->size)) {
    return 0;
  }
  const unsigned char *source = (const unsigned char *)address;
  unsigned char *dest = (unsigned char *)buffer;
  for (size_t i = 0; i < descriptor->size; ++i) {
    dest[i] = source[i];
  }
  return 1;
}

static int write_process_event_param_bytes(
  uintptr_t params,
  const LuaParamDescriptorView *descriptor,
  const void *buffer,
  size_t buffer_size
) {
  if (!params || !descriptor || !descriptor->valid || !buffer ||
      descriptor->size == 0 || descriptor->size > buffer_size ||
      descriptor->size > MAX_PROCESS_EVENT_PARAM_BYTES) {
    return 0;
  }
  uintptr_t address = params + descriptor->offset;
  if (address < params) {
    return 0;
  }
  MEMORY_BASIC_INFORMATION_WIN64 mbi;
  for (size_t i = 0; i < sizeof(mbi); ++i) {
    ((char *)&mbi)[i] = 0;
  }
  SIZE_T got = VirtualQuery((const void *)address, &mbi, sizeof(mbi));
  if (!got || mbi.State != MEM_COMMIT || (mbi.Protect & PAGE_GUARD) ||
      !writable_protect(mbi.Protect) ||
      !region_contains_range(&mbi, address, descriptor->size)) {
    return 0;
  }
  const unsigned char *source = (const unsigned char *)buffer;
  unsigned char *dest = (unsigned char *)address;
  for (size_t i = 0; i < descriptor->size; ++i) {
    dest[i] = source[i];
  }
  return 1;
}

static int read_process_event_param_scalar(uintptr_t params, const LuaParamDescriptorView *descriptor, long long *value) {
  if (!params || !descriptor || !descriptor->valid || !value ||
      (descriptor->size != 1 && descriptor->size != 2 && descriptor->size != 4 && descriptor->size != 8)) {
    return 0;
  }
  uint64_t raw = 0;
  if (!read_process_event_param_bytes(params, descriptor, &raw, sizeof(raw))) {
    return 0;
  }
  if (lua_param_descriptor_is_signed_integer(descriptor)) {
    switch (descriptor->size) {
      case 1:
        *value = (long long)(int8_t)(uint8_t)raw;
        return 1;
      case 2:
        *value = (long long)(int16_t)(uint16_t)raw;
        return 1;
      case 4:
        *value = (long long)(int32_t)(uint32_t)raw;
        return 1;
      case 8:
        *value = (long long)(int64_t)raw;
        return 1;
      default:
        return 0;
    }
  }
  *value = (long long)raw;
  return 1;
}

static int process_event_scalar_value_to_raw(const LuaParamDescriptorView *descriptor, long long value, uint64_t *raw) {
  size_t size = descriptor ? descriptor->size : 0;
  int signed_integer = lua_param_descriptor_is_signed_integer(descriptor);
  if ((size == 1 && signed_integer && (value < -128LL || value > 127LL)) ||
      (size == 1 && !signed_integer && (value < 0 || value > 0xffLL)) ||
      (size == 2 && signed_integer && (value < -32768LL || value > 32767LL)) ||
      (size == 2 && !signed_integer && (value < 0 || value > 0xffffLL)) ||
      (size == 4 && signed_integer && (value < -2147483647LL - 1LL || value > 2147483647LL)) ||
      (size == 4 && !signed_integer && (value < 0 || value > 0xffffffffLL)) ||
      (size != 1 && size != 2 && size != 4 && size != 8)) {
    return 0;
  }
  if (raw) {
    *raw = (uint64_t)value;
  }
  return 1;
}

static int write_process_event_param_scalar(uintptr_t params, const LuaParamDescriptorView *descriptor, long long value) {
  uint64_t raw = 0;
  if (!params || !descriptor || !descriptor->valid ||
      !process_event_scalar_value_to_raw(descriptor, value, &raw)) {
    return 0;
  }
  uintptr_t address = params + descriptor->offset;
  if (address < params) {
    return 0;
  }
  MEMORY_BASIC_INFORMATION_WIN64 mbi;
  for (size_t i = 0; i < sizeof(mbi); ++i) {
    ((char *)&mbi)[i] = 0;
  }
  SIZE_T got = VirtualQuery((const void *)address, &mbi, sizeof(mbi));
  if (!got || mbi.State != MEM_COMMIT || (mbi.Protect & PAGE_GUARD) ||
      !writable_protect(mbi.Protect) ||
      !region_contains_range(&mbi, address, descriptor->size)) {
    return 0;
  }
  const unsigned char *source = (const unsigned char *)&raw;
  unsigned char *dest = (unsigned char *)address;
  for (size_t i = 0; i < descriptor->size; ++i) {
    dest[i] = source[i];
  }
  return 1;
}

static int read_process_event_param_number(uintptr_t params, const LuaParamDescriptorView *descriptor, double *value) {
  if (!params || !descriptor || !descriptor->valid || !value) {
    return 0;
  }
  if (lua_param_descriptor_is_float(descriptor) && descriptor->size == sizeof(float)) {
    float raw = 0.0f;
    if (!read_process_event_param_bytes(params, descriptor, &raw, sizeof(raw))) {
      return 0;
    }
    *value = (double)raw;
    return 1;
  }
  if (lua_param_descriptor_is_double(descriptor) && descriptor->size == sizeof(double)) {
    double raw = 0.0;
    if (!read_process_event_param_bytes(params, descriptor, &raw, sizeof(raw))) {
      return 0;
    }
    *value = raw;
    return 1;
  }
  return 0;
}

static int write_process_event_param_number(uintptr_t params, const LuaParamDescriptorView *descriptor, double value) {
  if (!params || !descriptor || !descriptor->valid) {
    return 0;
  }
  if (lua_param_descriptor_is_float(descriptor) && descriptor->size == sizeof(float)) {
    float raw = (float)value;
    return write_process_event_param_bytes(params, descriptor, &raw, sizeof(raw));
  }
  if (lua_param_descriptor_is_double(descriptor) && descriptor->size == sizeof(double)) {
    double raw = value;
    return write_process_event_param_bytes(params, descriptor, &raw, sizeof(raw));
  }
  return 0;
}

static int write_process_event_param_fname_from_stack(
  LuaApi *api,
  LuaState *state,
  uintptr_t params,
  const LuaParamDescriptorView *descriptor,
  int value_index
) {
  if (!api || !state || !params || !descriptor || !descriptor->valid ||
      descriptor->size != sizeof(UeFNameValue)) {
    return 0;
  }
  UeFNameValue raw;
  for (size_t i = 0; i < sizeof(raw); ++i) {
    ((unsigned char *)&raw)[i] = 0;
  }
  if (api->type && api->type(state, value_index) == LUA_TTABLE_COMPAT) {
    raw.comparison_index = (uint32_t)lua_object_uintptr_field_arg(api, state, value_index, "ComparisonIndex");
    raw.number = (uint32_t)lua_object_uintptr_field_arg(api, state, value_index, "Number");
  } else {
    int is_number = 0;
    long long comparison_index = lua_to_integer(api, state, value_index, &is_number);
    if (!is_number || comparison_index < 0 || comparison_index > 0xffffffffLL) {
      return 0;
    }
    raw.comparison_index = (uint32_t)comparison_index;
    raw.number = 0;
  }
  if (write_process_event_param_bytes(params, descriptor, &raw, sizeof(raw))) {
    ++lua_process_event_param_set_hits;
    return 1;
  }
  return 0;
}

static int write_process_event_param_string_from_stack(
  LuaApi *api,
  LuaState *state,
  uintptr_t params,
  const LuaParamDescriptorView *descriptor,
  int value_index
) {
  if (!api || !state || !params || !descriptor || !descriptor->valid || !api->to_lstring) {
    return 0;
  }
  size_t value_len = 0;
  const char *value = api->to_lstring(state, value_index, &value_len);
  if (!value || value_len + 1 > MAX_PROCESS_EVENT_STRING_CHARS) {
    return 0;
  }
  UeFStringValue string_value;
  for (size_t i = 0; i < sizeof(string_value); ++i) {
    ((unsigned char *)&string_value)[i] = 0;
  }
  if (!read_process_event_param_bytes(params, descriptor, &string_value, sizeof(string_value)) ||
      string_value.data == 0 || string_value.capacity <= 0 ||
      string_value.capacity > MAX_PROCESS_EVENT_STRING_CHARS ||
      value_len + 1 > (size_t)string_value.capacity) {
    return 0;
  }
  size_t write_len = value_len + 1;
  MEMORY_BASIC_INFORMATION_WIN64 mbi;
  for (size_t i = 0; i < sizeof(mbi); ++i) {
    ((unsigned char *)&mbi)[i] = 0;
  }
  SIZE_T got = VirtualQuery((const void *)string_value.data, &mbi, sizeof(mbi));
  if (!got || mbi.State != MEM_COMMIT || (mbi.Protect & PAGE_GUARD) ||
      !writable_protect(mbi.Protect) ||
      !region_contains_range(&mbi, string_value.data, write_len)) {
    return 0;
  }
  unsigned char *dest = (unsigned char *)string_value.data;
  for (size_t i = 0; i < value_len; ++i) {
    dest[i] = (unsigned char)value[i];
  }
  dest[value_len] = '\0';
  string_value.count = (int32_t)write_len;
  if (write_process_event_param_bytes(params, descriptor, &string_value, sizeof(string_value))) {
    ++lua_process_event_param_set_hits;
    return 1;
  }
  return 0;
}

static int read_process_event_param_vector(
  uintptr_t params,
  const LuaParamDescriptorView *descriptor,
  double *x,
  double *y,
  double *z
) {
  if (!params || !descriptor || !descriptor->valid || !x || !y || !z ||
      !lua_param_descriptor_is_vector_struct(descriptor)) {
    return 0;
  }
  if (descriptor->size == sizeof(UeFVectorValue)) {
    UeFVectorValue raw;
    for (size_t i = 0; i < sizeof(raw); ++i) {
      ((unsigned char *)&raw)[i] = 0;
    }
    if (!read_process_event_param_bytes(params, descriptor, &raw, sizeof(raw))) {
      return 0;
    }
    *x = raw.x;
    *y = raw.y;
    *z = raw.z;
    return 1;
  }
  if (descriptor->size == sizeof(float) * 3) {
    float raw[3] = {0.0f, 0.0f, 0.0f};
    if (!read_process_event_param_bytes(params, descriptor, raw, sizeof(raw))) {
      return 0;
    }
    *x = (double)raw[0];
    *y = (double)raw[1];
    *z = (double)raw[2];
    return 1;
  }
  return 0;
}

static int push_lua_fvector_table(LuaApi *api, LuaState *state, double x, double y, double z) {
  if (!api || !state || !api->create_table || !api->push_string ||
      !api->push_number || !api->set_field) {
    return 0;
  }
  api->create_table(state, 0, 8);
  api->push_string(state, "FVector");
  api->set_field(state, -2, "Kind");
  api->push_number(state, x);
  api->set_field(state, -2, "X");
  api->push_number(state, y);
  api->set_field(state, -2, "Y");
  api->push_number(state, z);
  api->set_field(state, -2, "Z");
  api->push_number(state, x);
  api->set_field(state, -2, "x");
  api->push_number(state, y);
  api->set_field(state, -2, "y");
  api->push_number(state, z);
  api->set_field(state, -2, "z");
  return 1;
}

static void bytes_to_hex_string(const unsigned char *bytes, size_t byte_count, char *out, size_t out_size) {
  static const char hex[] = "0123456789abcdef";
  if (!out || out_size == 0) {
    return;
  }
  out[0] = '\0';
  if (!bytes || byte_count == 0) {
    return;
  }
  size_t max_bytes = (out_size - 1) / 2;
  if (byte_count > max_bytes) {
    byte_count = max_bytes;
  }
  for (size_t i = 0; i < byte_count; ++i) {
    out[i * 2] = hex[(bytes[i] >> 4) & 0xfU];
    out[i * 2 + 1] = hex[bytes[i] & 0xfU];
  }
  out[byte_count * 2] = '\0';
}

static int read_process_event_param_raw_bytes(
  uintptr_t params,
  const LuaParamDescriptorView *descriptor,
  unsigned char *buffer,
  size_t buffer_size,
  size_t *out_size
) {
  if (out_size) {
    *out_size = 0;
  }
  if (!params || !descriptor || !descriptor->valid || !buffer || buffer_size == 0 ||
      descriptor->size == 0 || descriptor->size > MAX_PROCESS_EVENT_PARAM_BYTES) {
    return 0;
  }
  size_t read_size = descriptor->size;
  if (read_size > buffer_size) {
    read_size = buffer_size;
  }
  if (!read_process_event_param_bytes(params, descriptor, buffer, read_size)) {
    return 0;
  }
  if (out_size) {
    *out_size = read_size;
  }
  return 1;
}

static int push_process_event_raw_param_table(
  LuaApi *api,
  LuaState *state,
  uintptr_t params,
  const LuaParamDescriptorView *descriptor
) {
  if (!api || !state || !descriptor || !api->push_nil || !api->create_table ||
      !api->push_string || !api->push_integer || !api->set_field) {
    return 0;
  }
  unsigned char raw[MAX_PROCESS_EVENT_PARAM_BYTES];
  for (size_t i = 0; i < sizeof(raw); ++i) {
    raw[i] = 0;
  }
  size_t read_size = 0;
  if (!read_process_event_param_raw_bytes(params, descriptor, raw, sizeof(raw), &read_size)) {
    api->push_nil(state);
    return 1;
  }
  char hex[MAX_PROCESS_EVENT_PARAM_BYTES * 2 + 1];
  bytes_to_hex_string(raw, read_size, hex, sizeof(hex));
  uintptr_t address = params + descriptor->offset;
  if (address < params) {
    address = 0;
  }
  api->create_table(state, 0, 9);
  api->push_string(state, "RawUnrealParam");
  api->set_field(state, -2, "Kind");
  api->push_string(state, descriptor->name);
  api->set_field(state, -2, "Name");
  api->push_string(state, descriptor->type);
  api->set_field(state, -2, "Type");
  api->push_string(state, descriptor->class_name);
  api->set_field(state, -2, "ClassName");
  api->push_integer(state, (long long)address);
  api->set_field(state, -2, "Address");
  api->push_integer(state, (long long)descriptor->offset);
  api->set_field(state, -2, "OffsetInternal");
  api->push_integer(state, (long long)descriptor->size);
  api->set_field(state, -2, "Size");
  api->push_integer(state, (long long)read_size);
  api->set_field(state, -2, "ReadSize");
  api->push_string(state, hex);
  api->set_field(state, -2, "BytesHex");
  return 1;
}

static int read_process_event_container_header(
  uintptr_t params,
  const LuaParamDescriptorView *descriptor,
  UeFScriptContainerHeader *header,
  unsigned char *raw,
  size_t raw_size,
  size_t *out_size
) {
  if (out_size) {
    *out_size = 0;
  }
  if (!params || !descriptor || !descriptor->valid || !lua_param_descriptor_is_container(descriptor) ||
      !header || !raw || raw_size < sizeof(*header) || descriptor->size < sizeof(*header)) {
    return 0;
  }
  if (!read_process_event_param_raw_bytes(params, descriptor, raw, raw_size, out_size)) {
    return 0;
  }
  for (size_t i = 0; i < sizeof(*header); ++i) {
    ((unsigned char *)header)[i] = raw[i];
  }
  if (header->num < 0 || header->max < header->num || header->max > 1000000) {
    return 0;
  }
  if (!header->data && header->num > 0) {
    return 0;
  }
  return 1;
}

static int read_process_event_array_data_sample(
  const UeFScriptContainerHeader *header,
  unsigned char *sample,
  size_t sample_size,
  size_t *out_size
) {
  if (out_size) {
    *out_size = 0;
  }
  if (!header || !sample || sample_size == 0 || !header->data || header->num <= 0) {
    return 0;
  }
  size_t read_size = sample_size;
  if (read_size > 16) {
    read_size = 16;
  }
  MEMORY_BASIC_INFORMATION_WIN64 mbi;
  for (size_t i = 0; i < sizeof(mbi); ++i) {
    ((unsigned char *)&mbi)[i] = 0;
  }
  SIZE_T got = VirtualQuery((const void *)header->data, &mbi, sizeof(mbi));
  if (!got || mbi.State != MEM_COMMIT || !readable_protect(mbi.Protect) ||
      !region_contains_range(&mbi, header->data, read_size)) {
    return 0;
  }
  const unsigned char *source = (const unsigned char *)header->data;
  for (size_t i = 0; i < read_size; ++i) {
    sample[i] = source[i];
  }
  if (out_size) {
    *out_size = read_size;
  }
  return 1;
}

static int read_process_event_array_data_bytes(uintptr_t data, size_t offset, unsigned char *buffer, size_t size) {
  if (!data || !buffer || size == 0 || size > MAX_PROCESS_EVENT_PARAM_BYTES) {
    return 0;
  }
  uintptr_t address = data + offset;
  if (address < data) {
    return 0;
  }
  MEMORY_BASIC_INFORMATION_WIN64 mbi;
  for (size_t i = 0; i < sizeof(mbi); ++i) {
    ((unsigned char *)&mbi)[i] = 0;
  }
  SIZE_T got = VirtualQuery((const void *)address, &mbi, sizeof(mbi));
  if (!got || mbi.State != MEM_COMMIT || !readable_protect(mbi.Protect) ||
      !region_contains_range(&mbi, address, size)) {
    return 0;
  }
  const unsigned char *source = (const unsigned char *)address;
  for (size_t i = 0; i < size; ++i) {
    buffer[i] = source[i];
  }
  return 1;
}

static int CDECL lua_script_array_get_num_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_integer) {
    return 0;
  }
  long long num = 0;
  lua_table_integer_field(active_lua_api, state, 1, "Num", &num);
  active_lua_api->push_integer(state, num);
  return 1;
}

static int CDECL lua_script_array_get_data_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_integer) {
    return 0;
  }
  long long data = 0;
  lua_table_integer_field(active_lua_api, state, 1, "Data", &data);
  active_lua_api->push_integer(state, data);
  return 1;
}

static int CDECL lua_script_array_get_data_sample_bytes_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_nil || !active_lua_api->push_string) {
    return 0;
  }
  if (!active_lua_api->get_field || !active_lua_api->set_top) {
    active_lua_api->push_nil(state);
    return 1;
  }
  active_lua_api->get_field(state, 1, "DataSampleBytesHex");
  const char *value = active_lua_api->to_lstring ? active_lua_api->to_lstring(state, -1, 0) : 0;
  if (value && value[0]) {
    active_lua_api->push_string(state, value);
    active_lua_api->set_top(state, -3);
    return 1;
  }
  active_lua_api->set_top(state, -2);
  active_lua_api->push_nil(state);
  return 1;
}

static int CDECL lua_script_array_get_raw_element_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_nil || !active_lua_api->push_string) {
    return 0;
  }
  long long data_value = 0;
  long long num_value = 0;
  if (!lua_table_integer_field(active_lua_api, state, 1, "Data", &data_value) ||
      !lua_table_integer_field(active_lua_api, state, 1, "Num", &num_value) ||
      data_value <= 0 || num_value <= 0) {
    active_lua_api->push_nil(state);
    return 1;
  }
  int index_ok = 0;
  long long index_value = lua_to_integer(active_lua_api, state, 2, &index_ok);
  int size_ok = 0;
  long long byte_count_value = lua_to_integer(active_lua_api, state, 3, &size_ok);
  if (!index_ok || !size_ok || index_value <= 0 || index_value > num_value ||
      byte_count_value <= 0 || byte_count_value > MAX_PROCESS_EVENT_PARAM_BYTES) {
    active_lua_api->push_nil(state);
    return 1;
  }
  size_t byte_count = (size_t)byte_count_value;
  size_t offset = (size_t)(index_value - 1) * byte_count;
  unsigned char raw[MAX_PROCESS_EVENT_PARAM_BYTES];
  for (size_t i = 0; i < sizeof(raw); ++i) {
    raw[i] = 0;
  }
  if (!read_process_event_array_data_bytes((uintptr_t)data_value, offset, raw, byte_count)) {
    active_lua_api->push_nil(state);
    return 1;
  }
  char hex[MAX_PROCESS_EVENT_PARAM_BYTES * 2 + 1];
  bytes_to_hex_string(raw, byte_count, hex, sizeof(hex));
  active_lua_api->push_string(state, hex);
  return 1;
}

static int CDECL lua_script_array_get_element_callback(LuaState *state) {
  if (!active_lua_api || !active_lua_api->push_nil) {
    return 0;
  }
  long long data_value = 0;
  long long num_value = 0;
  long long element_size_value = 0;
  if (!lua_table_integer_field(active_lua_api, state, 1, "Data", &data_value) ||
      !lua_table_integer_field(active_lua_api, state, 1, "Num", &num_value) ||
      !lua_table_integer_field(active_lua_api, state, 1, "InnerElementSize", &element_size_value) ||
      data_value <= 0 || num_value <= 0 ||
      element_size_value <= 0 || element_size_value > MAX_PROCESS_EVENT_PARAM_BYTES) {
    active_lua_api->push_nil(state);
    return 1;
  }
  int index_ok = 0;
  long long index_value = lua_to_integer(active_lua_api, state, 2, &index_ok);
  if (!index_ok || index_value <= 0 || index_value > num_value) {
    active_lua_api->push_nil(state);
    return 1;
  }
  size_t element_size = (size_t)element_size_value;
  size_t offset = (size_t)(index_value - 1) * element_size;
  unsigned char raw[MAX_PROCESS_EVENT_PARAM_BYTES];
  for (size_t i = 0; i < sizeof(raw); ++i) {
    raw[i] = 0;
  }
  if (!read_process_event_array_data_bytes((uintptr_t)data_value, offset, raw, element_size)) {
    active_lua_api->push_nil(state);
    return 1;
  }
  char inner_class_name[MAX_LUA_CLASS_NAME];
  char inner_type[MAX_LUA_CLASS_NAME];
  inner_class_name[0] = '\0';
  inner_type[0] = '\0';
  lua_read_self_string_field(state, "InnerClassName", inner_class_name, sizeof(inner_class_name));
  lua_read_self_string_field(state, "InnerType", inner_type, sizeof(inner_type));
  if (contains_ci(inner_class_name, "BoolProperty") || str_equal(inner_type, "bool")) {
    active_lua_api->push_boolean(state, raw[0] != 0);
    return 1;
  }
  if (contains_ci(inner_class_name, "FloatProperty") && element_size == sizeof(float) && active_lua_api->push_number) {
    float value = 0.0f;
    for (size_t i = 0; i < sizeof(value); ++i) {
      ((unsigned char *)&value)[i] = raw[i];
    }
    active_lua_api->push_number(state, (double)value);
    return 1;
  }
  if (contains_ci(inner_class_name, "DoubleProperty") && element_size == sizeof(double) && active_lua_api->push_number) {
    double value = 0.0;
    for (size_t i = 0; i < sizeof(value); ++i) {
      ((unsigned char *)&value)[i] = raw[i];
    }
    active_lua_api->push_number(state, value);
    return 1;
  }
  if (contains_ci(inner_class_name, "ObjectProperty") && element_size == sizeof(uintptr_t)) {
    uintptr_t object_address = 0;
    for (size_t i = 0; i < sizeof(object_address); ++i) {
      ((unsigned char *)&object_address)[i] = raw[i];
    }
    return push_process_event_object_param_or_nil(active_lua_api, state, object_address);
  }
  if (contains_ci(inner_class_name, "NameProperty") && element_size == sizeof(UeFNameValue)) {
    UeFNameValue value;
    for (size_t i = 0; i < sizeof(value); ++i) {
      ((unsigned char *)&value)[i] = raw[i];
    }
    return push_process_event_fname_param_or_nil(active_lua_api, state, &value);
  }
  if ((contains_ci(inner_class_name, "Int") || contains_ci(inner_type, "int")) && element_size <= sizeof(uint64_t)) {
    uint64_t unsigned_value = 0;
    for (size_t i = 0; i < element_size; ++i) {
      ((unsigned char *)&unsigned_value)[i] = raw[i];
    }
    active_lua_api->push_integer(state, (long long)unsigned_value);
    return 1;
  }
  char hex[MAX_PROCESS_EVENT_PARAM_BYTES * 2 + 1];
  bytes_to_hex_string(raw, element_size, hex, sizeof(hex));
  if (!active_lua_api->create_table || !active_lua_api->push_string || !active_lua_api->push_integer || !active_lua_api->set_field) {
    active_lua_api->push_string(state, hex);
    return 1;
  }
  active_lua_api->create_table(state, 0, 5);
  active_lua_api->push_string(state, "RawUnrealArrayElement");
  active_lua_api->set_field(state, -2, "Kind");
  active_lua_api->push_string(state, inner_class_name);
  active_lua_api->set_field(state, -2, "ClassName");
  active_lua_api->push_integer(state, index_value);
  active_lua_api->set_field(state, -2, "Index");
  active_lua_api->push_integer(state, element_size_value);
  active_lua_api->set_field(state, -2, "ElementSize");
  active_lua_api->push_string(state, hex);
  active_lua_api->set_field(state, -2, "BytesHex");
  return 1;
}

static int push_process_event_container_header_table(
  LuaApi *api,
  LuaState *state,
  uintptr_t params,
  const LuaParamDescriptorView *descriptor
) {
  if (!api || !state || !descriptor || !api->push_nil || !api->create_table ||
      !api->push_string || !api->push_integer || !api->set_field) {
    return 0;
  }
  unsigned char raw[MAX_PROCESS_EVENT_PARAM_BYTES];
  for (size_t i = 0; i < sizeof(raw); ++i) {
    raw[i] = 0;
  }
  UeFScriptContainerHeader header;
  for (size_t i = 0; i < sizeof(header); ++i) {
    ((unsigned char *)&header)[i] = 0;
  }
  size_t read_size = 0;
  if (!read_process_event_container_header(params, descriptor, &header, raw, sizeof(raw), &read_size)) {
    api->push_nil(state);
    return 1;
  }
  char hex[MAX_PROCESS_EVENT_PARAM_BYTES * 2 + 1];
  bytes_to_hex_string(raw, read_size, hex, sizeof(hex));
  uintptr_t address = params + descriptor->offset;
  if (address < params) {
    address = 0;
  }
  unsigned char data_sample[16];
  for (size_t i = 0; i < sizeof(data_sample); ++i) {
    data_sample[i] = 0;
  }
  size_t data_sample_size = 0;
  int data_sample_ok = lua_param_descriptor_is_array(descriptor) &&
                       read_process_event_array_data_sample(&header, data_sample, sizeof(data_sample), &data_sample_size);
  char data_sample_hex[sizeof(data_sample) * 2 + 1];
  data_sample_hex[0] = '\0';
  if (data_sample_ok) {
    bytes_to_hex_string(data_sample, data_sample_size, data_sample_hex, sizeof(data_sample_hex));
  }
  api->create_table(state, 0, 16);
  api->push_string(state, lua_param_descriptor_container_kind(descriptor));
  api->set_field(state, -2, "Kind");
  api->push_string(state, descriptor->name);
  api->set_field(state, -2, "Name");
  api->push_string(state, descriptor->type);
  api->set_field(state, -2, "Type");
  api->push_string(state, descriptor->class_name);
  api->set_field(state, -2, "ClassName");
  if (descriptor->inner_class_name[0]) {
    api->push_string(state, descriptor->inner_name[0] ? descriptor->inner_name : "Inner");
    api->set_field(state, -2, "InnerName");
    api->push_string(state, descriptor->inner_class_name);
    api->set_field(state, -2, "InnerClassName");
    api->push_string(state, descriptor->inner_type[0] ? descriptor->inner_type : ue_param_value_type(descriptor->inner_class_name, (int32_t)descriptor->inner_size));
    api->set_field(state, -2, "InnerType");
    api->push_integer(state, (long long)descriptor->inner_size);
    api->set_field(state, -2, "InnerElementSize");
  }
  api->push_integer(state, (long long)address);
  api->set_field(state, -2, "Address");
  api->push_integer(state, (long long)descriptor->offset);
  api->set_field(state, -2, "OffsetInternal");
  api->push_integer(state, (long long)descriptor->size);
  api->set_field(state, -2, "Size");
  api->push_integer(state, (long long)read_size);
  api->set_field(state, -2, "ReadSize");
  api->push_integer(state, (long long)header.data);
  api->set_field(state, -2, "Data");
  api->push_integer(state, (long long)header.num);
  api->set_field(state, -2, "Num");
  api->push_integer(state, (long long)header.max);
  api->set_field(state, -2, "Max");
  api->push_string(state, hex);
  api->set_field(state, -2, "BytesHex");
  if (data_sample_ok) {
    api->push_integer(state, (long long)(header.data));
    api->set_field(state, -2, "DataSampleAddress");
    api->push_integer(state, (long long)data_sample_size);
    api->set_field(state, -2, "DataSampleReadSize");
    api->push_string(state, data_sample_hex);
    api->set_field(state, -2, "DataSampleBytesHex");
  }
  if (lua_param_descriptor_is_array(descriptor)) {
    set_lua_object_method(api, state, "GetNum", lua_script_array_get_num_callback);
    set_lua_object_method(api, state, "NumElements", lua_script_array_get_num_callback);
    set_lua_object_method(api, state, "GetData", lua_script_array_get_data_callback);
    set_lua_object_method(api, state, "GetDataSampleBytes", lua_script_array_get_data_sample_bytes_callback);
    set_lua_object_method(api, state, "GetRawElement", lua_script_array_get_raw_element_callback);
    set_lua_object_method(api, state, "GetElement", lua_script_array_get_element_callback);
  }
  return 1;
}

static int write_process_event_param_vector_from_stack(
  LuaApi *api,
  LuaState *state,
  uintptr_t params,
  const LuaParamDescriptorView *descriptor,
  int value_index
) {
  if (!api || !state || !params || !descriptor || !descriptor->valid ||
      !lua_param_descriptor_is_vector_struct(descriptor) ||
      !api->type || api->type(state, value_index) != LUA_TTABLE_COMPAT) {
    return 0;
  }
  double x = 0.0;
  double y = 0.0;
  double z = 0.0;
  if (!lua_table_number_field_alias(api, state, value_index, "X", "x", &x) ||
      !lua_table_number_field_alias(api, state, value_index, "Y", "y", &y) ||
      !lua_table_number_field_alias(api, state, value_index, "Z", "z", &z)) {
    return 0;
  }
  if (descriptor->size == sizeof(UeFVectorValue)) {
    UeFVectorValue raw;
    raw.x = x;
    raw.y = y;
    raw.z = z;
    if (write_process_event_param_bytes(params, descriptor, &raw, sizeof(raw))) {
      ++lua_process_event_param_set_hits;
      return 1;
    }
    return 0;
  }
  if (descriptor->size == sizeof(float) * 3) {
    float raw[3];
    raw[0] = (float)x;
    raw[1] = (float)y;
    raw[2] = (float)z;
    if (write_process_event_param_bytes(params, descriptor, raw, sizeof(raw))) {
      ++lua_process_event_param_set_hits;
      return 1;
    }
  }
  return 0;
}

static int push_process_event_object_param_or_nil(LuaApi *api, LuaState *state, uintptr_t address) {
  if (!api || !state || !api->push_nil) {
    return 0;
  }
  if (!address) {
    api->push_nil(state);
    return 1;
  }
  const LuaObjectHandle *object = find_lua_object_by_address(address);
  if (object && push_lua_object_handle(api, state, object)) {
    return 1;
  }
  LuaObjectHandle synthetic;
  for (size_t i = 0; i < sizeof(synthetic); ++i) {
    ((unsigned char *)&synthetic)[i] = 0;
  }
  static Line text;
  line_init(&text);
  line_append(&text, "/RuntimeProbe/UObject/");
  line_append_hex(&text, address);
  copy_string(synthetic.path, sizeof(synthetic.path), text.text);
  line_init(&text);
  line_append(&text, "UObject_");
  line_append_hex(&text, address);
  copy_string(synthetic.name, sizeof(synthetic.name), text.text);
  copy_string(synthetic.class_name, sizeof(synthetic.class_name), "UObject");
  synthetic.address = address;
  if (push_lua_object_handle(api, state, &synthetic)) {
    return 1;
  }
  api->push_nil(state);
  return 1;
}

static int push_process_event_fname_param_or_nil(
  LuaApi *api,
  LuaState *state,
  const UeFNameValue *value
) {
  if (!api || !state || !value || !api->push_nil) {
    return 0;
  }
  int decoded = 0;
  char decoded_name[MAX_LUA_OBJECT_NAME];
  decoded_name[0] = '\0';
  if (active_lua_fname_resolver_available) {
    decoded = decode_ue_fname(
      &active_lua_fname_resolver,
      &active_lua_fname_options,
      value->comparison_index,
      value->number,
      decoded_name,
      sizeof(decoded_name),
      0,
      0,
      0,
      0,
      0
    );
  }
  return push_lua_fname_table(
    api,
    state,
    decoded ? decoded_name : "",
    (long long)value->comparison_index,
    (long long)value->number,
    decoded
  ) ? 1 : 0;
}

static int push_process_event_string_param_or_nil(
  LuaApi *api,
  LuaState *state,
  uintptr_t params,
  const LuaParamDescriptorView *descriptor
) {
  if (!api || !state || !descriptor || !api->push_string || !api->push_nil) {
    return 0;
  }
  UeFStringValue value;
  for (size_t i = 0; i < sizeof(value); ++i) {
    ((unsigned char *)&value)[i] = 0;
  }
  if (!read_process_event_param_bytes(params, descriptor, &value, sizeof(value)) ||
      value.data == 0 || value.count <= 0 || value.capacity < value.count ||
      value.count > MAX_PROCESS_EVENT_STRING_CHARS) {
    api->push_nil(state);
    return 1;
  }
  MEMORY_BASIC_INFORMATION_WIN64 mbi;
  for (size_t i = 0; i < sizeof(mbi); ++i) {
    ((unsigned char *)&mbi)[i] = 0;
  }
  SIZE_T got = VirtualQuery((const void *)value.data, &mbi, sizeof(mbi));
  size_t byte_count = (size_t)value.count;
  if (!got || mbi.State != MEM_COMMIT || !readable_protect(mbi.Protect) ||
      !region_contains_range(&mbi, value.data, byte_count)) {
    api->push_nil(state);
    return 1;
  }
  char out[MAX_LUA_OBJECT_PATH];
  out[0] = '\0';
  const unsigned char *source = (const unsigned char *)value.data;
  size_t chars = byte_count;
  if (chars > 0 && source[chars - 1] == '\0') {
    --chars;
  }
  if (chars >= sizeof(out)) {
    chars = sizeof(out) - 1;
  }
  for (size_t i = 0; i < chars; ++i) {
    unsigned char ch = source[i];
    out[i] = (ch >= 32 && ch < 127) ? (char)ch : '?';
  }
  out[chars] = '\0';
  api->push_string(state, out);
  return 1;
}

static int push_process_event_param_value_or_nil(
  LuaApi *api,
  LuaState *state,
  uintptr_t params,
  const LuaParamDescriptorView *descriptor
) {
  long long value = 0;
  if (!api || !state || !descriptor || !api->push_nil) {
    return 0;
  }
  if (!params || !descriptor->valid) {
    api->push_nil(state);
    return 1;
  }
  if (lua_param_descriptor_is_fname(descriptor)) {
    UeFNameValue fname_value;
    for (size_t i = 0; i < sizeof(fname_value); ++i) {
      ((unsigned char *)&fname_value)[i] = 0;
    }
    if (read_process_event_param_bytes(params, descriptor, &fname_value, sizeof(fname_value))) {
      ++lua_process_event_param_get_hits;
      return push_process_event_fname_param_or_nil(api, state, &fname_value);
    }
    api->push_nil(state);
    return 1;
  }
  if (lua_param_descriptor_is_string(descriptor)) {
    ++lua_process_event_param_get_hits;
    return push_process_event_string_param_or_nil(api, state, params, descriptor);
  }
  if (lua_param_descriptor_is_container(descriptor)) {
    ++lua_process_event_param_get_hits;
    return push_process_event_container_header_table(api, state, params, descriptor);
  }
  if (lua_param_descriptor_is_struct(descriptor)) {
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
    if (read_process_event_param_vector(params, descriptor, &x, &y, &z)) {
      ++lua_process_event_param_get_hits;
      return push_lua_fvector_table(api, state, x, y, z);
    }
    ++lua_process_event_param_get_hits;
    return push_process_event_raw_param_table(api, state, params, descriptor);
  }
  if (lua_param_descriptor_is_float(descriptor) || lua_param_descriptor_is_double(descriptor)) {
    double number_value = 0.0;
    if (!api->push_number || !read_process_event_param_number(params, descriptor, &number_value)) {
      api->push_nil(state);
      return 1;
    }
    ++lua_process_event_param_get_hits;
    api->push_number(state, number_value);
    return 1;
  }
  if (!read_process_event_param_scalar(params, descriptor, &value)) {
    ++lua_process_event_param_get_hits;
    return push_process_event_raw_param_table(api, state, params, descriptor);
  }
  ++lua_process_event_param_get_hits;
  if (lua_param_descriptor_is_bool(descriptor)) {
    api->push_boolean(state, value != 0);
    return 1;
  }
  if (lua_param_descriptor_is_object(descriptor)) {
    return push_process_event_object_param_or_nil(api, state, (uintptr_t)value);
  }
  api->push_integer(state, value);
  return 1;
}

static int write_process_event_param_value_from_stack(
  LuaApi *api,
  LuaState *state,
  uintptr_t params,
  const LuaParamDescriptorView *descriptor,
  int value_index
) {
  if (!api || !state || !params || !descriptor || !descriptor->valid) {
    return 0;
  }
  if (lua_param_descriptor_is_fname(descriptor)) {
    return write_process_event_param_fname_from_stack(api, state, params, descriptor, value_index);
  }
  if (lua_param_descriptor_is_string(descriptor)) {
    return write_process_event_param_string_from_stack(api, state, params, descriptor, value_index);
  }
  if (lua_param_descriptor_is_struct(descriptor)) {
    return write_process_event_param_vector_from_stack(api, state, params, descriptor, value_index);
  }
  if (lua_param_descriptor_is_bool(descriptor)) {
    int is_boolean = 0;
    int value = lua_to_boolean(api, state, value_index, &is_boolean);
    if (is_boolean && write_process_event_param_scalar(params, descriptor, value ? 1 : 0)) {
      ++lua_process_event_param_set_hits;
      return 1;
    }
    return 0;
  }
  if (lua_param_descriptor_is_object(descriptor)) {
    uintptr_t object_address = lua_object_address_arg(api, state, value_index);
    int is_number = 0;
    long long raw_value = lua_to_integer(api, state, value_index, &is_number);
    if ((object_address || (is_number && raw_value == 0)) &&
        write_process_event_param_scalar(params, descriptor, object_address ? (long long)object_address : 0)) {
      ++lua_process_event_param_set_hits;
      return 1;
	  }
	  return 0;
	}
  if (lua_param_descriptor_is_float(descriptor) || lua_param_descriptor_is_double(descriptor)) {
    int is_number = 0;
    double value = lua_to_number(api, state, value_index, &is_number);
    if (is_number && write_process_event_param_number(params, descriptor, value)) {
      ++lua_process_event_param_set_hits;
      return 1;
    }
    return 0;
  }
  int is_number = 0;
  long long value = lua_to_integer(api, state, value_index, &is_number);
  if (is_number && write_process_event_param_scalar(params, descriptor, value)) {
    ++lua_process_event_param_set_hits;
    return 1;
  }
  return 0;
}

static uintptr_t lua_remote_unreal_param_params_address_arg(LuaState *state) {
  if (!active_lua_api || !state || !active_lua_api->get_field || !active_lua_api->set_top) {
    return 0;
  }
  active_lua_api->get_field(state, 1, "ParamsAddress");
  int is_number = 0;
  long long value = lua_to_integer(active_lua_api, state, -1, &is_number);
  active_lua_api->set_top(state, -2);
  uintptr_t address = is_number ? (uintptr_t)value : 0;
  return address && address == active_process_event_lua_params_address ? address : 0;
}

static int lua_remote_unreal_param_descriptor_view_arg(LuaState *state, LuaParamDescriptorView *out) {
  if (!active_lua_api || !state || !out || !active_lua_api->get_field || !active_lua_api->set_top) {
    return 0;
  }
  active_lua_api->get_field(state, 1, "Descriptor");
  int ok = lua_param_descriptor_view_arg(state, -1, out);
  active_lua_api->set_top(state, -2);
  return ok;
}

static int CDECL lua_remote_unreal_param_get_callback(LuaState *state) {
  ++lua_process_event_param_get_calls;
  if (!active_lua_api || !active_lua_api->push_nil) {
    return 0;
  }
  uintptr_t params = lua_remote_unreal_param_params_address_arg(state);
  LuaParamDescriptorView descriptor;
  if (params && lua_remote_unreal_param_descriptor_view_arg(state, &descriptor)) {
    return push_process_event_param_value_or_nil(active_lua_api, state, params, &descriptor);
  }
  active_lua_api->push_nil(state);
  return 1;
}

static int CDECL lua_remote_unreal_param_set_callback(LuaState *state) {
  ++lua_process_event_param_set_calls;
  if (!active_lua_api || !active_lua_api->push_boolean) {
    return 0;
  }
  uintptr_t params = lua_remote_unreal_param_params_address_arg(state);
  LuaParamDescriptorView descriptor;
  int ok = params &&
           lua_remote_unreal_param_descriptor_view_arg(state, &descriptor) &&
           write_process_event_param_value_from_stack(active_lua_api, state, params, &descriptor, 2);
  active_lua_api->push_boolean(state, ok);
  return 1;
}

static int CDECL lua_remote_unreal_param_type_callback(LuaState *state) {
  (void)state;
  if (!active_lua_api || !active_lua_api->push_string) {
    return 0;
  }
  active_lua_api->push_string(state, "RemoteUnrealParam");
  return 1;
}

static int push_remote_unreal_param_base(
  LuaApi *api,
  LuaState *state,
  uintptr_t params,
  const char *name,
  const char *type,
  const char *class_name,
  size_t offset,
  size_t size
) {
  if (!api || !state || !name || !api->create_table || !api->push_string ||
      !api->push_integer || !api->push_boolean || !api->set_field || !api->push_cclosure) {
    return 0;
  }
  uintptr_t value_address = params + offset;
  if (value_address < params) {
    value_address = 0;
  }
  api->create_table(state, 0, 16);
  api->push_string(state, name);
  api->set_field(state, -2, "Name");
  api->push_string(state, "RemoteUnrealParam");
  api->set_field(state, -2, "Kind");
  api->push_string(state, type ? type : "");
  api->set_field(state, -2, "Type");
  api->push_string(state, class_name ? class_name : "");
  api->set_field(state, -2, "ClassName");
  api->push_integer(state, (long long)params);
  api->set_field(state, -2, "ParamsAddress");
  api->push_integer(state, (long long)value_address);
  api->set_field(state, -2, "Address");
  api->push_integer(state, (long long)offset);
  api->set_field(state, -2, "Offset");
  api->push_integer(state, (long long)offset);
  api->set_field(state, -2, "OffsetInternal");
  api->push_integer(state, (long long)size);
  api->set_field(state, -2, "Size");
  api->push_integer(state, (long long)size);
  api->set_field(state, -2, "ElementSize");
  api->push_boolean(state, params && params == active_process_event_lua_params_address && value_address != 0);
  api->set_field(state, -2, "IsValid");
  set_lua_object_method(api, state, "get", lua_remote_unreal_param_get_callback);
  set_lua_object_method(api, state, "Get", lua_remote_unreal_param_get_callback);
  set_lua_object_method(api, state, "set", lua_remote_unreal_param_set_callback);
  set_lua_object_method(api, state, "Set", lua_remote_unreal_param_set_callback);
  set_lua_object_method(api, state, "type", lua_remote_unreal_param_type_callback);
  return 1;
}

static int push_remote_unreal_param_for_process_descriptor(
  LuaApi *api,
  LuaState *state,
  uintptr_t params,
  const ProcessEventParamDescriptor *descriptor
) {
  if (!descriptor ||
      !push_remote_unreal_param_base(
        api,
        state,
        params,
        descriptor->name,
        descriptor->type,
        descriptor->class_name,
        descriptor->offset,
        descriptor->size
      )) {
    return 0;
  }
  if (push_process_event_param_descriptor(api, state, descriptor)) {
    api->set_field(state, -2, "Descriptor");
  }
  return 1;
}

static int push_remote_unreal_param_for_ue_descriptor(
  LuaApi *api,
  LuaState *state,
  uintptr_t params,
  const UeFunctionParamDescriptor *descriptor
) {
  if (!descriptor) {
    return 0;
  }
  const char *class_name = ue_param_class_name_or_default(descriptor->class_name);
  const char *name = descriptor->field_name[0] ? descriptor->field_name : descriptor->property_name;
  size_t offset = descriptor->offset_internal >= 0 ? (size_t)descriptor->offset_internal : 0;
  size_t size = descriptor->element_size > 0 ? (size_t)descriptor->element_size : 0;
  if (!push_remote_unreal_param_base(
        api,
        state,
        params,
        name,
        ue_param_value_type(class_name, descriptor->element_size),
        class_name,
        offset,
        size
      )) {
    return 0;
  }
  if (push_ue_function_param_descriptor(api, state, descriptor)) {
    api->set_field(state, -2, "Descriptor");
  }
  return 1;
}

static int CDECL lua_get_param_value_callback(LuaState *state) {
  ++lua_process_event_param_get_calls;
  if (!active_lua_api || !active_lua_api->push_nil) {
    return 0;
  }
  uintptr_t params = lua_process_event_params_address_arg(state);
  LuaParamDescriptorView descriptor;
  if (params && lua_param_descriptor_view_arg(state, 2, &descriptor)) {
    return push_process_event_param_value_or_nil(active_lua_api, state, params, &descriptor);
  }
  active_lua_api->push_nil(state);
  return 1;
}

static int CDECL lua_set_param_value_callback(LuaState *state) {
  ++lua_process_event_param_set_calls;
  if (!active_lua_api || !active_lua_api->push_boolean) {
    return 0;
  }
  uintptr_t params = lua_process_event_params_address_arg(state);
  LuaParamDescriptorView descriptor;
  if (params && lua_param_descriptor_view_arg(state, 2, &descriptor)) {
    if (write_process_event_param_value_from_stack(active_lua_api, state, params, &descriptor, 3)) {
      active_lua_api->push_boolean(state, 1);
      return 1;
    }
  }
  active_lua_api->push_boolean(state, 0);
  return 1;
}

static int CDECL lua_get_param_descriptor_callback(LuaState *state) {
  ++lua_process_event_param_descriptor_lookup_calls;
  if (!active_lua_api || !active_lua_api->push_nil) {
    return 0;
  }
  uintptr_t params = lua_process_event_params_address_arg(state);
  const ProcessEventParamDescriptor *descriptor = find_process_event_param_descriptor_arg(state, 2);
  if (params && descriptor && push_process_event_param_descriptor(active_lua_api, state, descriptor)) {
    ++lua_process_event_param_descriptor_lookup_hits;
    return 1;
  }
  active_lua_api->push_nil(state);
  return 1;
}

static int CDECL lua_get_function_param_descriptors_callback(LuaState *state) {
  ++lua_process_event_function_param_descriptor_calls;
  if (!active_lua_api || !active_lua_api->push_nil) {
    return 0;
  }
  uintptr_t function = lua_object_address_arg(active_lua_api, state, 1);
  return push_process_event_function_param_descriptors_or_nil(active_lua_api, state, function);
}

static void register_lua_probe_api(LuaApi *api, LuaState *state) {
  active_lua_api = api;
  register_lua_compat_constant_tables(api, state);
  register_lua_compat_metadata_tables(api, state);
  api->push_cclosure(state, lua_register_hook_callback, 0);
  api->set_global(state, "RegisterHook");
  api->push_cclosure(state, lua_unregister_hook_callback, 0);
  api->set_global(state, "UnregisterHook");
  api->push_cclosure(state, lua_static_find_object_callback, 0);
  api->set_global(state, "StaticFindObject");
  api->push_cclosure(state, lua_find_object_callback, 0);
  api->set_global(state, "FindObject");
  api->push_cclosure(state, lua_find_first_of_callback, 0);
  api->set_global(state, "FindFirstOf");
  api->push_cclosure(state, lua_get_known_objects_callback, 0);
  api->set_global(state, "GetKnownObjects");
  api->push_cclosure(state, lua_find_objects_callback, 0);
  api->set_global(state, "FindObjects");
  api->push_cclosure(state, lua_find_all_of_callback, 0);
  api->set_global(state, "FindAllOf");
  api->push_cclosure(state, lua_for_each_uobject_callback, 0);
  api->set_global(state, "ForEachUObject");
  api->push_cclosure(state, lua_is_a_callback, 0);
  api->set_global(state, "IsA");
  api->push_cclosure(state, lua_find_function_callback, 0);
  api->set_global(state, "FindFunction");
  api->push_cclosure(state, lua_find_first_function_callback, 0);
  api->set_global(state, "FindFirstFunction");
  api->push_cclosure(state, lua_get_known_functions_callback, 0);
  api->set_global(state, "GetKnownFunctions");
  api->push_cclosure(state, lua_static_construct_object_callback, 0);
  api->set_global(state, "StaticConstructObject");
  api->push_cclosure(state, lua_register_custom_property_callback, 0);
  api->set_global(state, "RegisterCustomProperty");
  api->push_cclosure(state, lua_load_asset_callback, 0);
  api->set_global(state, "LoadAsset");
  api->push_cclosure(state, lua_notify_on_new_object_callback, 0);
  api->set_global(state, "NotifyOnNewObject");
  api->push_cclosure(state, lua_execute_in_game_thread_callback, 0);
  api->set_global(state, "ExecuteInGameThread");
  api->push_cclosure(state, lua_execute_async_callback, 0);
  api->set_global(state, "ExecuteAsync");
  api->push_cclosure(state, lua_execute_with_delay_callback, 0);
  api->set_global(state, "ExecuteWithDelay");
  api->push_cclosure(state, lua_loop_async_callback, 0);
  api->set_global(state, "LoopAsync");
  api->push_cclosure(state, lua_iterate_game_directories_callback, 0);
  api->set_global(state, "IterateGameDirectories");
  api->push_cclosure(state, lua_fname_callback, 0);
  api->set_global(state, "FName");
  api->push_cclosure(state, lua_ftext_callback, 0);
  api->set_global(state, "FText");
  api->push_cclosure(state, lua_register_key_bind_callback, 0);
  api->set_global(state, "RegisterKeyBind");
  api->push_cclosure(state, lua_is_key_bind_registered_callback, 0);
  api->set_global(state, "IsKeyBindRegistered");
  api->push_cclosure(state, lua_register_console_command_handler_callback, 0);
  api->set_global(state, "RegisterConsoleCommandHandler");
  api->push_cclosure(state, lua_register_console_command_global_handler_callback, 0);
  api->set_global(state, "RegisterConsoleCommandGlobalHandler");
  api->push_cclosure(state, lua_register_custom_event_callback, 0);
  api->set_global(state, "RegisterCustomEvent");
  api->push_cclosure(state, lua_ue4ssl_probe_dispatch_custom_event_callback, 0);
  api->set_global(state, "UE4SSLProbeDispatchCustomEvent");
  api->push_cclosure(state, lua_register_load_map_pre_hook_callback, 0);
  api->set_global(state, "RegisterLoadMapPreHook");
  api->push_cclosure(state, lua_register_load_map_post_hook_callback, 0);
  api->set_global(state, "RegisterLoadMapPostHook");
  api->push_cclosure(state, lua_ue4ssl_probe_load_map_callback, 0);
  api->set_global(state, "UE4SSLProbeLoadMap");
  api->push_cclosure(state, lua_register_begin_play_pre_hook_callback, 0);
  api->set_global(state, "RegisterBeginPlayPreHook");
  api->push_cclosure(state, lua_register_begin_play_post_hook_callback, 0);
  api->set_global(state, "RegisterBeginPlayPostHook");
  api->push_cclosure(state, lua_ue4ssl_probe_begin_play_callback, 0);
  api->set_global(state, "UE4SSLProbeBeginPlay");
  api->push_cclosure(state, lua_register_init_game_state_pre_hook_callback, 0);
  api->set_global(state, "RegisterInitGameStatePreHook");
  api->push_cclosure(state, lua_register_init_game_state_post_hook_callback, 0);
  api->set_global(state, "RegisterInitGameStatePostHook");
  api->push_cclosure(state, lua_ue4ssl_probe_init_game_state_callback, 0);
  api->set_global(state, "UE4SSLProbeInitGameState");
  api->push_cclosure(state, lua_register_process_console_exec_pre_hook_callback, 0);
  api->set_global(state, "RegisterProcessConsoleExecPreHook");
  api->push_cclosure(state, lua_register_process_console_exec_post_hook_callback, 0);
  api->set_global(state, "RegisterProcessConsoleExecPostHook");
  api->push_cclosure(state, lua_register_call_function_pre_hook_callback, 0);
  api->set_global(state, "RegisterCallFunctionByNameWithArgumentsPreHook");
  api->push_cclosure(state, lua_register_call_function_post_hook_callback, 0);
  api->set_global(state, "RegisterCallFunctionByNameWithArgumentsPostHook");
  api->push_cclosure(state, lua_register_local_player_exec_pre_hook_callback, 0);
  api->set_global(state, "RegisterULocalPlayerExecPreHook");
  api->push_cclosure(state, lua_register_local_player_exec_post_hook_callback, 0);
  api->set_global(state, "RegisterULocalPlayerExecPostHook");
  api->push_cclosure(state, lua_object_local_player_exec_callback, 0);
  api->set_global(state, "ULocalPlayerExec");
  api->push_cclosure(state, lua_get_property_value_callback, 0);
  api->set_global(state, "GetPropertyValue");
  api->push_cclosure(state, lua_set_property_value_callback, 0);
  api->set_global(state, "SetPropertyValue");
  api->push_cclosure(state, lua_call_function_callback, 0);
  api->set_global(state, "CallFunction");
  api->push_cclosure(state, lua_get_function_param_descriptors_callback, 0);
  api->set_global(state, "GetFunctionParamDescriptors");
  api->push_cclosure(state, lua_get_function_param_descriptors_callback, 0);
  api->set_global(state, "GetFunctionParams");
  api->push_cclosure(state, lua_get_param_descriptor_callback, 0);
  api->set_global(state, "GetParamDescriptor");
  api->push_cclosure(state, lua_get_param_value_callback, 0);
  api->set_global(state, "GetParamValue");
  api->push_cclosure(state, lua_set_param_value_callback, 0);
  api->set_global(state, "SetParamValue");
  active_lua_api = 0;
}

static const char *path_basename_win(const char *path) {
  if (!path) {
    return "";
  }
  const char *base = path;
  for (size_t i = 0; path[i]; ++i) {
    if (path[i] == '\\' || path[i] == '/') {
      base = path + i + 1;
    }
  }
  return base;
}

static int lua_path_ends_with_lua(const char *path) {
  size_t len = cstr_len(path);
  return len >= 4 &&
         ascii_lower(path[len - 4]) == '.' &&
         ascii_lower(path[len - 3]) == 'l' &&
         ascii_lower(path[len - 2]) == 'u' &&
         ascii_lower(path[len - 1]) == 'a';
}

static int lua_join_path(char *out, size_t out_size, const char *base, const char *first, const char *second, const char *third) {
  if (!out || out_size == 0 || !base || !base[0]) {
    return 0;
  }
  copy_string(out, out_size, base);
  const char *parts[] = {first, second, third};
  for (size_t i = 0; i < sizeof(parts) / sizeof(parts[0]); ++i) {
    const char *part = parts[i];
    if (!part || !part[0]) {
      continue;
    }
    size_t len = cstr_len(out);
    if (len + 1 >= out_size) {
      out[0] = '\0';
      return 0;
    }
    char last = len > 0 ? out[len - 1] : '\0';
    if (last != '\\' && last != '/') {
      out[len++] = '\\';
      out[len] = '\0';
    }
    size_t part_len = cstr_len(part);
    if (len + part_len >= out_size) {
      out[0] = '\0';
      return 0;
    }
    for (size_t j = 0; j < part_len; ++j) {
      out[len + j] = part[j];
    }
    out[len + part_len] = '\0';
  }
  return 1;
}

static int file_exists_readable_win(const char *path) {
  HANDLE file = CreateFileA(
    path,
    GENERIC_READ,
    FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
    0,
    OPEN_EXISTING,
    FILE_ATTRIBUTE_NORMAL,
    0
  );
  if (file == INVALID_HANDLE_VALUE) {
    return 0;
  }
  CloseHandle(file);
  return 1;
}

static int add_lua_mod_script(LuaModScriptList *list, const char *path, const char *name) {
  if (!list || !path || !path[0]) {
    return 0;
  }
  if (list->count >= MAX_LUA_MOD_SCRIPTS) {
    ++list->skipped;
    return 0;
  }
  LuaModScript *script = &list->scripts[list->count++];
  copy_string(script->path, sizeof(script->path), path);
  copy_string(script->name, sizeof(script->name), (name && name[0]) ? name : path_basename_win(path));
  return 1;
}

static void collect_lua_mod_scripts_from_env(LuaModScriptList *list) {
  static char raw[MAX_CONFIG_VALUE];
  if (env_get("UE4SSL_WIN_LUA_MOD_SCRIPTS", raw, sizeof(raw)) == 0 || !raw[0]) {
    return;
  }
  char *start = raw;
  while (start && *start) {
    char *end = start;
    while (*end && *end != ';') {
      ++end;
    }
    int has_delimiter = *end == ';';
    if (*end) {
      *end = '\0';
    }
    char *item = trim(start);
    if (item[0]) {
      add_lua_mod_script(list, item, path_basename_win(item));
    }
    start = has_delimiter ? end + 1 : 0;
  }
}

static void collect_lua_mod_scripts_from_root(LuaModScriptList *list) {
  static char root[MAX_LUA_SCRIPT_PATH];
  if (env_get("UE4SSL_WIN_LUA_MOD_ROOT", root, sizeof(root)) == 0 || !root[0]) {
    return;
  }
  char pattern[MAX_LUA_SCRIPT_PATH];
  if (!lua_join_path(pattern, sizeof(pattern), root, "*", 0, 0)) {
    return;
  }
  WIN32_FIND_DATAA_WIN data;
  HANDLE find = FindFirstFileA(pattern, &data);
  if (find == INVALID_HANDLE_VALUE) {
    static Line line;
    char safe_root[MAX_LUA_SCRIPT_PATH];
    safe_value(root, safe_root, sizeof(safe_root));
    line_init(&line);
    line_append(&line, "event=lua-mod-scan phase=smoke status=root-open-failed root=");
    line_append(&line, safe_root);
    emit_line(&line);
    return;
  }
  do {
    if (data.cFileName[0] == '.') {
      continue;
    }
    if ((data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0 && lua_path_ends_with_lua(data.cFileName)) {
      char direct[MAX_LUA_SCRIPT_PATH];
      if (lua_join_path(direct, sizeof(direct), root, data.cFileName, 0, 0) && file_exists_readable_win(direct)) {
        add_lua_mod_script(list, direct, data.cFileName);
      }
      continue;
    }
    if ((data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0) {
      char main_lua[MAX_LUA_SCRIPT_PATH];
      if (lua_join_path(main_lua, sizeof(main_lua), root, data.cFileName, "Scripts", "main.lua") &&
          file_exists_readable_win(main_lua)) {
        add_lua_mod_script(list, main_lua, data.cFileName);
      }
    }
  } while (FindNextFileA(find, &data));
  FindClose(find);
}

static char *read_lua_script_file(const char *path, size_t *length, const char **reason) {
  if (length) {
    *length = 0;
  }
  if (reason) {
    *reason = "unknown";
  }
  HANDLE file = CreateFileA(
    path,
    GENERIC_READ,
    FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
    0,
    OPEN_EXISTING,
    FILE_ATTRIBUTE_NORMAL,
    0
  );
  if (file == INVALID_HANDLE_VALUE) {
    if (reason) {
      *reason = "open-failed";
    }
    return 0;
  }
  char *buffer = (char *)VirtualAlloc(0, MAX_LUA_SCRIPT_BYTES + 1, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
  if (!buffer) {
    CloseHandle(file);
    if (reason) {
      *reason = "allocation-failed";
    }
    return 0;
  }
  size_t total = 0;
  for (;;) {
    if (total >= MAX_LUA_SCRIPT_BYTES) {
      DWORD extra = 0;
      char ch = '\0';
      if (ReadFile(file, &ch, 1, &extra, 0) && extra > 0) {
        VirtualFree(buffer, 0, MEM_RELEASE);
        CloseHandle(file);
        if (reason) {
          *reason = "too-large";
        }
        return 0;
      }
      break;
    }
    DWORD got = 0;
    DWORD want = (DWORD)(MAX_LUA_SCRIPT_BYTES - total);
    if (want > 4096U) {
      want = 4096U;
    }
    if (!ReadFile(file, buffer + total, want, &got, 0)) {
      VirtualFree(buffer, 0, MEM_RELEASE);
      CloseHandle(file);
      if (reason) {
        *reason = "read-failed";
      }
      return 0;
    }
    if (got == 0) {
      break;
    }
    total += (size_t)got;
  }
  CloseHandle(file);
  buffer[total] = '\0';
  if (length) {
    *length = total;
  }
  if (reason) {
    *reason = "ok";
  }
  return buffer;
}

static int run_lua_mod_script(LuaApi *api, LuaState *state, const char *phase, const LuaModScript *script) {
  static char safe_path[MAX_LUA_SCRIPT_PATH];
  static char safe_name[MAX_LUA_SCRIPT_NAME];
  safe_value(script->path, safe_path, sizeof(safe_path));
  safe_value(script->name, safe_name, sizeof(safe_name));
  const char *reason = "unknown";
  size_t script_len = 0;
  char *source = read_lua_script_file(script->path, &script_len, &reason);
  if (!source) {
    static Line read_line;
    static char safe_reason[64];
    safe_value(reason, safe_reason, sizeof(safe_reason));
    line_init(&read_line);
    line_append(&read_line, "event=lua-mod-script phase=");
    line_append(&read_line, phase);
    line_append(&read_line, " status=read-failed name=");
    line_append(&read_line, safe_name);
    line_append(&read_line, " path=");
    line_append(&read_line, safe_path);
    line_append(&read_line, " reason=");
    line_append(&read_line, safe_reason);
    emit_line(&read_line);
    return 0;
  }
  int hooks_before = lua_hook_registration_count;
  active_lua_api = api;
  int load_status = api->load_string(state, source);
  int call_status = load_status == 0 ? lua_call(api, state, 0, 0, 0) : load_status;
  active_lua_api = 0;
  static char safe_error[256];
  safe_error[0] = '\0';
  if ((load_status != 0 || call_status != 0) && api->to_lstring && api->set_top) {
    const char *message = api->to_lstring(state, -1, 0);
    safe_value(message ? message : "", safe_error, sizeof(safe_error));
    api->set_top(state, -2);
  }
  VirtualFree(source, 0, MEM_RELEASE);

  static Line line;
  line_init(&line);
  line_append(&line, "event=lua-mod-script phase=");
  line_append(&line, phase);
  line_append(&line, " status=");
  line_append(&line, load_status == 0 && call_status == 0 ? "passed" : "failed");
  line_append(&line, " name=");
  line_append(&line, safe_name);
  line_append(&line, " path=");
  line_append(&line, safe_path);
  line_append(&line, " loadStatus=");
  line_append_signed_dec(&line, load_status);
  line_append(&line, " callStatus=");
  line_append_signed_dec(&line, call_status);
  line_append(&line, " error=");
  line_append(&line, safe_error);
  line_append(&line, " hooksBefore=");
  line_append_signed_dec(&line, hooks_before);
  line_append(&line, " hooksAfter=");
  line_append_signed_dec(&line, lua_hook_registration_count);
  line_append(&line, " scriptBytes=");
  line_append_dec(&line, script_len);
  emit_line(&line);
  return load_status == 0 && call_status == 0;
}

static void run_lua_mod_entrypoints(const char *phase) {
  if (!env_bool("UE4SSL_WIN_LUA_MODS_ENABLED", 0)) {
    return;
  }
  reset_lua_hook_registration();
  LuaApi api;
  zero_lua_api(&api);
  if (!load_lua_api(&api)) {
    static Line missing_line;
    line_init(&missing_line);
    line_append(&missing_line, "event=lua-mod-finish phase=");
    line_append(&missing_line, phase);
    line_append(&missing_line, " status=library-missing");
    emit_line(&missing_line);
    return;
  }
  LuaState *state = api.new_state();
  if (!state) {
    static Line state_line;
    line_init(&state_line);
    line_append(&state_line, "event=lua-mod-finish phase=");
    line_append(&state_line, phase);
    line_append(&state_line, " status=state-failed library=");
    line_append(&state_line, api.library);
    emit_line(&state_line);
    FreeLibrary(api.module);
    return;
  }
  api.open_libs(state);
  register_lua_probe_api(&api, state);

  static LuaModScriptList list;
  for (size_t i = 0; i < sizeof(list); ++i) {
    ((unsigned char *)&list)[i] = 0;
  }
  collect_lua_mod_scripts_from_env(&list);
  collect_lua_mod_scripts_from_root(&list);

  static Line start_line;
  line_init(&start_line);
  line_append(&start_line, "event=lua-mod-start phase=");
  line_append(&start_line, phase);
  line_append(&start_line, " status=running library=");
  line_append(&start_line, api.library);
  line_append(&start_line, " scripts=");
  line_append_dec(&start_line, list.count);
  line_append(&start_line, " skipped=");
  line_append_dec(&start_line, list.skipped);
  emit_line(&start_line);

  size_t loaded = 0;
  size_t failed = 0;
  for (size_t i = 0; i < list.count; ++i) {
    if (run_lua_mod_script(&api, state, phase, &list.scripts[i])) {
      ++loaded;
    } else {
      ++failed;
    }
  }

  if (env_bool("UE4SSL_WIN_LUA_MOD_DISPATCH_SELF_TEST", 0) && lua_hook_registration_count > 0) {
    int callback_status = invoke_lua_hook_refs(&api, state);
    static char safe_hook[256];
    safe_value(lua_hook_registration_name, safe_hook, sizeof(safe_hook));
    const char *dispatch_status = callback_status == 0 &&
                                  lua_hook_registration_count > 0 &&
                                  lua_hook_pre_calls == lua_hook_registration_count &&
                                  lua_hook_post_calls == lua_hook_registration_count &&
                                  lua_hook_pre_is_number && lua_hook_post_is_number &&
                                  lua_hook_pre_result == 11 && lua_hook_post_result == 31 ? "passed" : "failed";
    static Line dispatch_line;
    line_init(&dispatch_line);
    line_append(&dispatch_line, "event=lua-mod-dispatch-self-test phase=");
    line_append(&dispatch_line, phase);
    line_append(&dispatch_line, " status=");
    line_append(&dispatch_line, dispatch_status);
    line_append(&dispatch_line, " callbackStatus=");
    line_append_signed_dec(&dispatch_line, callback_status);
    line_append(&dispatch_line, " hooks=");
    line_append_signed_dec(&dispatch_line, lua_hook_registration_count);
    line_append(&dispatch_line, " hook=");
    line_append(&dispatch_line, safe_hook);
    line_append(&dispatch_line, " preCalls=");
    line_append_signed_dec(&dispatch_line, lua_hook_pre_calls);
    line_append(&dispatch_line, " postCalls=");
    line_append_signed_dec(&dispatch_line, lua_hook_post_calls);
    line_append(&dispatch_line, " preResult=");
    line_append_signed_dec(&dispatch_line, lua_hook_pre_result);
    line_append(&dispatch_line, " postResult=");
    line_append_signed_dec(&dispatch_line, lua_hook_post_result);
    line_append(&dispatch_line, " preIsNumber=");
    line_append(&dispatch_line, lua_hook_pre_is_number ? "true" : "false");
    line_append(&dispatch_line, " postIsNumber=");
    line_append(&dispatch_line, lua_hook_post_is_number ? "true" : "false");
    emit_line(&dispatch_line);
  }

  const char *status = list.count > 0 && failed == 0 ? "passed" : (list.count == 0 ? "no-scripts" : "failed");
  static Line finish_line;
  line_init(&finish_line);
  line_append(&finish_line, "event=lua-mod-finish phase=");
  line_append(&finish_line, phase);
  line_append(&finish_line, " status=");
  line_append(&finish_line, status);
  line_append(&finish_line, " library=");
  line_append(&finish_line, api.library);
  line_append(&finish_line, " scripts=");
  line_append_dec(&finish_line, list.count);
  line_append(&finish_line, " loaded=");
  line_append_dec(&finish_line, loaded);
  line_append(&finish_line, " failed=");
  line_append_dec(&finish_line, failed);
  line_append(&finish_line, " hooks=");
  line_append_signed_dec(&finish_line, lua_hook_registration_count);
  line_append(&finish_line, " customEvents=");
  line_append_signed_dec(&finish_line, lua_custom_event_registration_count);
  line_append(&finish_line, " customEventCalls=");
  line_append_signed_dec(&finish_line, lua_custom_event_call_sum(lua_custom_event_registrations, lua_custom_event_registration_count));
  line_append(&finish_line, " customEventHandled=");
  line_append_signed_dec(&finish_line, lua_custom_event_handled_sum(lua_custom_event_registrations, lua_custom_event_registration_count));
  line_append(&finish_line, " loadMapPreHooks=");
  line_append_signed_dec(&finish_line, lua_load_map_pre_hook_registration_count);
  line_append(&finish_line, " loadMapPostHooks=");
  line_append_signed_dec(&finish_line, lua_load_map_post_hook_registration_count);
  line_append(&finish_line, " loadMapPreCalls=");
  line_append_signed_dec(
    &finish_line,
    lua_console_exec_hook_call_sum(lua_load_map_pre_hook_registrations, lua_load_map_pre_hook_registration_count)
  );
  line_append(&finish_line, " loadMapPostCalls=");
  line_append_signed_dec(
    &finish_line,
    lua_console_exec_hook_call_sum(lua_load_map_post_hook_registrations, lua_load_map_post_hook_registration_count)
  );
  line_append(&finish_line, " loadMapPreHandled=");
  line_append_signed_dec(
    &finish_line,
    lua_console_exec_hook_handled_sum(lua_load_map_pre_hook_registrations, lua_load_map_pre_hook_registration_count)
  );
  line_append(&finish_line, " loadMapPostHandled=");
  line_append_signed_dec(
    &finish_line,
    lua_console_exec_hook_handled_sum(lua_load_map_post_hook_registrations, lua_load_map_post_hook_registration_count)
  );
  line_append(&finish_line, " beginPlayPreHooks=");
  line_append_signed_dec(&finish_line, lua_begin_play_pre_hook_registration_count);
  line_append(&finish_line, " beginPlayPostHooks=");
  line_append_signed_dec(&finish_line, lua_begin_play_post_hook_registration_count);
  line_append(&finish_line, " beginPlayPreCalls=");
  line_append_signed_dec(
    &finish_line,
    lua_console_exec_hook_call_sum(lua_begin_play_pre_hook_registrations, lua_begin_play_pre_hook_registration_count)
  );
  line_append(&finish_line, " beginPlayPostCalls=");
  line_append_signed_dec(
    &finish_line,
    lua_console_exec_hook_call_sum(lua_begin_play_post_hook_registrations, lua_begin_play_post_hook_registration_count)
  );
  line_append(&finish_line, " beginPlayPreHandled=");
  line_append_signed_dec(
    &finish_line,
    lua_console_exec_hook_handled_sum(lua_begin_play_pre_hook_registrations, lua_begin_play_pre_hook_registration_count)
  );
  line_append(&finish_line, " beginPlayPostHandled=");
  line_append_signed_dec(
    &finish_line,
    lua_console_exec_hook_handled_sum(lua_begin_play_post_hook_registrations, lua_begin_play_post_hook_registration_count)
  );
  line_append(&finish_line, " initGameStatePreHooks=");
  line_append_signed_dec(&finish_line, lua_init_game_state_pre_hook_registration_count);
  line_append(&finish_line, " initGameStatePostHooks=");
  line_append_signed_dec(&finish_line, lua_init_game_state_post_hook_registration_count);
  line_append(&finish_line, " initGameStatePreCalls=");
  line_append_signed_dec(
    &finish_line,
    lua_console_exec_hook_call_sum(lua_init_game_state_pre_hook_registrations, lua_init_game_state_pre_hook_registration_count)
  );
  line_append(&finish_line, " initGameStatePostCalls=");
  line_append_signed_dec(
    &finish_line,
    lua_console_exec_hook_call_sum(lua_init_game_state_post_hook_registrations, lua_init_game_state_post_hook_registration_count)
  );
  line_append(&finish_line, " initGameStatePreHandled=");
  line_append_signed_dec(
    &finish_line,
    lua_console_exec_hook_handled_sum(lua_init_game_state_pre_hook_registrations, lua_init_game_state_pre_hook_registration_count)
  );
  line_append(&finish_line, " initGameStatePostHandled=");
  line_append_signed_dec(
    &finish_line,
    lua_console_exec_hook_handled_sum(lua_init_game_state_post_hook_registrations, lua_init_game_state_post_hook_registration_count)
  );
  line_append(&finish_line, " processConsoleExecPreHooks=");
  line_append_signed_dec(&finish_line, lua_process_console_exec_pre_hook_registration_count);
  line_append(&finish_line, " processConsoleExecPostHooks=");
  line_append_signed_dec(&finish_line, lua_process_console_exec_post_hook_registration_count);
  line_append(&finish_line, " processConsoleExecPreCalls=");
  line_append_signed_dec(
    &finish_line,
    lua_console_exec_hook_call_sum(
      lua_process_console_exec_pre_hook_registrations,
      lua_process_console_exec_pre_hook_registration_count
    )
  );
  line_append(&finish_line, " processConsoleExecPostCalls=");
  line_append_signed_dec(
    &finish_line,
    lua_console_exec_hook_call_sum(
      lua_process_console_exec_post_hook_registrations,
      lua_process_console_exec_post_hook_registration_count
    )
  );
  line_append(&finish_line, " processConsoleExecPreHandled=");
  line_append_signed_dec(
    &finish_line,
    lua_console_exec_hook_handled_sum(
      lua_process_console_exec_pre_hook_registrations,
      lua_process_console_exec_pre_hook_registration_count
    )
  );
  line_append(&finish_line, " processConsoleExecPostHandled=");
  line_append_signed_dec(
    &finish_line,
    lua_console_exec_hook_handled_sum(
      lua_process_console_exec_post_hook_registrations,
      lua_process_console_exec_post_hook_registration_count
    )
  );
  line_append(&finish_line, " localPlayerExecPreHooks=");
  line_append_signed_dec(&finish_line, lua_local_player_exec_pre_hook_registration_count);
  line_append(&finish_line, " localPlayerExecPostHooks=");
  line_append_signed_dec(&finish_line, lua_local_player_exec_post_hook_registration_count);
  line_append(&finish_line, " localPlayerExecPreCalls=");
  line_append_signed_dec(
    &finish_line,
    lua_console_exec_hook_call_sum(
      lua_local_player_exec_pre_hook_registrations,
      lua_local_player_exec_pre_hook_registration_count
    )
  );
  line_append(&finish_line, " localPlayerExecPostCalls=");
  line_append_signed_dec(
    &finish_line,
    lua_console_exec_hook_call_sum(
      lua_local_player_exec_post_hook_registrations,
      lua_local_player_exec_post_hook_registration_count
    )
  );
  line_append(&finish_line, " localPlayerExecPreHandled=");
  line_append_signed_dec(
    &finish_line,
    lua_console_exec_hook_handled_sum(
      lua_local_player_exec_pre_hook_registrations,
      lua_local_player_exec_pre_hook_registration_count
    )
  );
  line_append(&finish_line, " localPlayerExecPostHandled=");
  line_append_signed_dec(
    &finish_line,
    lua_console_exec_hook_handled_sum(
      lua_local_player_exec_post_hook_registrations,
      lua_local_player_exec_post_hook_registration_count
    )
  );
  line_append(&finish_line, " callFunctionPreHooks=");
  line_append_signed_dec(&finish_line, lua_call_function_pre_hook_registration_count);
  line_append(&finish_line, " callFunctionPostHooks=");
  line_append_signed_dec(&finish_line, lua_call_function_post_hook_registration_count);
  line_append(&finish_line, " callFunctionPreCalls=");
  line_append_signed_dec(
    &finish_line,
    lua_call_function_hook_call_sum(
      lua_call_function_pre_hook_registrations,
      lua_call_function_pre_hook_registration_count
    )
  );
  line_append(&finish_line, " callFunctionPostCalls=");
  line_append_signed_dec(
    &finish_line,
    lua_call_function_hook_call_sum(
      lua_call_function_post_hook_registrations,
      lua_call_function_post_hook_registration_count
    )
  );
  line_append(&finish_line, " callFunctionPreHandled=");
  line_append_signed_dec(
    &finish_line,
    lua_call_function_hook_handled_sum(
      lua_call_function_pre_hook_registrations,
      lua_call_function_pre_hook_registration_count
    )
  );
  line_append(&finish_line, " callFunctionPostHandled=");
  line_append_signed_dec(
    &finish_line,
    lua_call_function_hook_handled_sum(
      lua_call_function_post_hook_registrations,
      lua_call_function_post_hook_registration_count
    )
  );
  line_append(&finish_line, " skipped=");
  line_append_dec(&finish_line, list.skipped);
  line_append(&finish_line, " objectHandles=");
  line_append_dec(&finish_line, lua_object_handle_count);
  line_append(&finish_line, " ueObjectHandles=");
  line_append_dec(&finish_line, ue_candidate_object_handle_count);
  line_append(&finish_line, " staticFindObjectCalls=");
  line_append_signed_dec(&finish_line, lua_static_find_object_calls);
  line_append(&finish_line, " staticFindObjectHits=");
  line_append_signed_dec(&finish_line, lua_static_find_object_hits);
  line_append(&finish_line, " findObjectCalls=");
  line_append_signed_dec(&finish_line, lua_find_object_calls);
  line_append(&finish_line, " findObjectHits=");
  line_append_signed_dec(&finish_line, lua_find_object_hits);
  line_append(&finish_line, " findFirstOfCalls=");
  line_append_signed_dec(&finish_line, lua_find_first_of_calls);
  line_append(&finish_line, " findFirstOfHits=");
  line_append_signed_dec(&finish_line, lua_find_first_of_hits);
  line_append(&finish_line, " getKnownObjectsCalls=");
  line_append_signed_dec(&finish_line, lua_get_known_objects_calls);
  line_append(&finish_line, " getKnownObjectsHits=");
  line_append_signed_dec(&finish_line, lua_get_known_objects_hits);
  line_append(&finish_line, " findObjectsCalls=");
  line_append_signed_dec(&finish_line, lua_find_objects_calls);
  line_append(&finish_line, " findObjectsHits=");
  line_append_signed_dec(&finish_line, lua_find_objects_hits);
  line_append(&finish_line, " findAllOfCalls=");
  line_append_signed_dec(&finish_line, lua_find_all_of_calls);
  line_append(&finish_line, " findAllOfHits=");
  line_append_signed_dec(&finish_line, lua_find_all_of_hits);
  line_append(&finish_line, " forEachUObjectCalls=");
  line_append_signed_dec(&finish_line, lua_for_each_uobject_calls);
  line_append(&finish_line, " forEachUObjectCallbacks=");
  line_append_signed_dec(&finish_line, lua_for_each_uobject_callbacks);
  line_append(&finish_line, " forEachFunctionCalls=");
  line_append_signed_dec(&finish_line, lua_for_each_function_calls);
  line_append(&finish_line, " forEachFunctionCallbacks=");
  line_append_signed_dec(&finish_line, lua_for_each_function_callbacks);
  line_append(&finish_line, " isACalls=");
  line_append_signed_dec(&finish_line, lua_is_a_calls);
  line_append(&finish_line, " isAHits=");
  line_append_signed_dec(&finish_line, lua_is_a_hits);
  line_append(&finish_line, " loadAssetCalls=");
  line_append_signed_dec(&finish_line, lua_load_asset_calls);
  line_append(&finish_line, " loadAssetHits=");
  line_append_signed_dec(&finish_line, lua_load_asset_hits);
  line_append(&finish_line, " staticConstructObjectCalls=");
  line_append_signed_dec(&finish_line, lua_static_construct_object_calls);
  line_append(&finish_line, " staticConstructObjectHits=");
  line_append_signed_dec(&finish_line, lua_static_construct_object_hits);
  line_append(&finish_line, " notifyOnNewObjectCalls=");
  line_append_signed_dec(&finish_line, lua_notify_on_new_object_calls);
  line_append(&finish_line, " executeInGameThreadCalls=");
  line_append_signed_dec(&finish_line, lua_execute_in_game_thread_calls);
  line_append(&finish_line, " executeInGameThreadCallbacks=");
  line_append_signed_dec(&finish_line, lua_execute_in_game_thread_callbacks);
  line_append(&finish_line, " executeInGameThreadResult=");
  line_append_signed_dec(&finish_line, lua_execute_in_game_thread_result);
  line_append(&finish_line, " executeInGameThreadIsNumber=");
  line_append(&finish_line, lua_execute_in_game_thread_is_number ? "true" : "false");
  line_append(&finish_line, " notifyOnNewObjectCallbacks=");
  line_append_signed_dec(&finish_line, lua_notify_on_new_object_callbacks);
  line_append(&finish_line, " notifyOnNewObjectResult=");
  line_append_signed_dec(&finish_line, lua_notify_on_new_object_result);
  line_append(&finish_line, " notifyOnNewObjectIsNumber=");
  line_append(&finish_line, lua_notify_on_new_object_is_number ? "true" : "false");
  line_append(&finish_line, " notifyOnNewObjectStatus=");
  line_append_signed_dec(&finish_line, lua_notify_on_new_object_status);
  line_append(&finish_line, " staticConstructObjectOuterHits=");
  line_append_signed_dec(&finish_line, lua_static_construct_object_outer_hits);
  line_append(&finish_line, " getWorldCalls=");
  line_append_signed_dec(&finish_line, lua_get_world_calls);
  line_append(&finish_line, " getWorldHits=");
  line_append_signed_dec(&finish_line, lua_get_world_hits);
  line_append(&finish_line, " getCdoCalls=");
  line_append_signed_dec(&finish_line, lua_get_cdo_calls);
  line_append(&finish_line, " getCdoHits=");
  line_append_signed_dec(&finish_line, lua_get_cdo_hits);
  line_append(&finish_line, " getLevelCalls=");
  line_append_signed_dec(&finish_line, lua_get_level_calls);
  line_append(&finish_line, " getLevelHits=");
  line_append_signed_dec(&finish_line, lua_get_level_hits);
  emit_line(&finish_line);

  lua_unref_hook_registrations(&api, state);
  lua_unref_notify_on_new_object_registrations(&api, state);
  api.close(state);
  FreeLibrary(api.module);
}

static void run_lua_dispatch_self_test(const char *phase) {
  if (!env_bool("UE4SSL_WIN_LUA_SELF_TEST", 0)) {
    return;
  }
  reset_lua_hook_registration();
  LuaApi api;
  zero_lua_api(&api);
  if (!load_lua_api(&api)) {
    static Line missing_line;
    line_init(&missing_line);
    line_append(&missing_line, "event=lua-dispatch-self-test phase=");
    line_append(&missing_line, phase);
    line_append(&missing_line, " status=library-missing");
    emit_line(&missing_line);
    return;
  }

  static char script[8192];
  if (env_get("UE4SSL_WIN_LUA_SELF_TEST_SCRIPT", script, sizeof(script)) == 0 || !script[0]) {
    copy_string(
      script,
      sizeof(script),
      "local o=StaticFindObject('/Script/UE4SSLProbe.SelfTestObject'); local fo=FindObject('SelfTestObject'); local f=FindFirstOf('UE4SSLProbeSelfTestClass'); local known=GetKnownObjects(); local matches=FindObjects('UE4SSLProbeSelfTestClass'); local allOf=FindAllOf('UE4SSLProbeSelfTestClass'); local asset=LoadAsset('/Script/UE4SSLProbe.SelfTestObject'); local seen=0; ForEachUObject(function(x) if x and IsA(x,'UE4SSLProbeSelfTestClass') then seen=seen+1 end end); local cls=o and o:GetClass(); local methodOk=o and cls and o:GetName()=='SelfTestObject' and o:GetPathName()==o.PathName and o:GetAddress()==o.Address and o:IsValid() and o:GetFullName()=='UE4SSLProbeSelfTestClass /Script/UE4SSLProbe.SelfTestObject' and o:type()=='UObject' and o:GetFName()=='SelfTestObject' and o:GetOuter()==nil and o:GetWorld()==nil and cls.Name=='UE4SSLProbeSelfTestClass' and cls.ClassName=='UClass' and cls:type()=='UClass' and not cls:IsValid() and o:HasAllFlags(0) and not o:HasAnyFlags(1) and not o:HasAnyInternalFlags(1); local async=0; ExecuteAsync(function() async=async+1 end); ExecuteWithDelay(1,function() async=async+1 end); local loopId=LoopAsync(1,function() async=async+1 return false end); local fn=FName('ProbeName'); local ft=FText('ProbeText'); local kb=RegisterKeyBind('P',function() end); local compatOk=async==3 and loopId and fn.Name=='ProbeName' and fn:ToString()=='ProbeName' and fn:GetComparisonIndex()==0 and ft.Text=='ProbeText' and kb and IsKeyBindRegistered('P') and RegisterConsoleCommandHandler('probe',function() return true end) and RegisterCustomEvent('probe',function() end) and RegisterLoadMapPreHook(function() end) and RegisterLoadMapPostHook(function() end) and RegisterBeginPlayPreHook(function() end) and RegisterBeginPlayPostHook(function() end) and RegisterInitGameStatePreHook(function() end) and RegisterInitGameStatePostHook(function() end) and RegisterProcessConsoleExecPreHook(function() end) and RegisterProcessConsoleExecPostHook(function() end) and RegisterCallFunctionByNameWithArgumentsPreHook(function() end) and RegisterCallFunctionByNameWithArgumentsPostHook(function() end); local up,uq=RegisterHook('/Script/UE4SSLProbe.Temp:Function',function()return -1 end,function()return -1 end); local unregOk=up and uq and uq==up+1; UnregisterHook('/Script/UE4SSLProbe.Temp:Function',up,uq); local c=StaticConstructObject(f,o,'ConstructedProbe'); NotifyOnNewObject('/Script/UE4SSLProbe.Missing', function() return 7 end); ExecuteInGameThread(function() return 9 end); local ok=o and fo and f and known and matches and allOf and asset and c and methodOk and compatOk and unregOk and o.PathName=='/Script/UE4SSLProbe.SelfTestObject' and fo.Address==o.Address and asset.Address==o.Address and f.ClassName=='UE4SSLProbeSelfTestClass' and known[o.PathName] and known.Count>=1 and matches.Count>=1 and allOf.Count>=1 and seen>=1 and IsA(o,'UE4SSLProbeSelfTestClass') and IsA(o,'UObject') and c.Name=='ConstructedProbe' and c.ClassName=='UE4SSLProbeSelfTestClass'; return (ok and 40 or -100) + RegisterHook('/Script/UE4SSLProbe.SelfTest:Function', function() return 11 end, function() return 31 end)"
    );
  }
  LuaState *state = api.new_state();
  if (!state) {
    static Line state_line;
    line_init(&state_line);
    line_append(&state_line, "event=lua-dispatch-self-test phase=");
    line_append(&state_line, phase);
    line_append(&state_line, " status=state-failed library=");
    line_append(&state_line, api.library);
    emit_line(&state_line);
    FreeLibrary(api.module);
    return;
  }
  api.open_libs(state);
  register_lua_probe_api(&api, state);
  int load_status = api.load_string(state, script);
  active_lua_api = &api;
  int call_status = load_status == 0 ? lua_call(&api, state, 0, 1, 0) : load_status;
  active_lua_api = 0;
  int is_number = 0;
  long long result = call_status == 0 ? lua_to_integer(&api, state, -1, &is_number) : 0;
  int callback_status = call_status == 0 ? invoke_lua_hook_refs(&api, state) : call_status;
  static char safe_hook[256];
  safe_value(lua_hook_registration_name, safe_hook, sizeof(safe_hook));
  const char *status = load_status == 0 && call_status == 0 && is_number && result == 42 &&
                       lua_hook_registration_count > 0 &&
                       callback_status == 0 &&
                       lua_ref_is_valid(lua_hook_pre_ref) && lua_ref_is_valid(lua_hook_post_ref) &&
                       lua_hook_pre_calls == 1 && lua_hook_post_calls == 1 &&
                       lua_hook_pre_is_number && lua_hook_post_is_number &&
                       lua_hook_pre_result == 11 && lua_hook_post_result == 31 &&
                       lua_static_find_object_calls == 1 && lua_find_object_calls == 1 &&
                       lua_find_first_of_calls == 1 && lua_get_known_objects_calls == 1 &&
                       lua_find_objects_calls == 1 && lua_find_all_of_calls == 1 &&
                       lua_for_each_uobject_calls == 1 &&
                       lua_static_find_object_hits == 1 && lua_find_object_hits == 1 &&
                       lua_find_first_of_hits == 1 && lua_get_known_objects_hits == 1 &&
                       lua_find_objects_hits == 1 && lua_find_all_of_hits == 1 &&
                       lua_for_each_uobject_callbacks >= 1 &&
                       lua_is_a_calls >= 2 && lua_is_a_hits >= 2 &&
                       lua_load_asset_calls == 1 && lua_load_asset_hits == 1 &&
                       lua_static_construct_object_calls == 1 &&
                       lua_static_construct_object_hits == 1 &&
                       lua_notify_on_new_object_calls == 1 &&
                       lua_execute_in_game_thread_calls == 1 &&
                       lua_execute_in_game_thread_callbacks == 1 &&
                       lua_execute_in_game_thread_is_number &&
                       lua_execute_in_game_thread_result == 9 ? "passed" : "failed";

  static Line line;
  line_init(&line);
  line_append(&line, "event=lua-dispatch-self-test phase=");
  line_append(&line, phase);
  line_append(&line, " status=");
  line_append(&line, status);
  line_append(&line, " library=");
  line_append(&line, api.library);
  line_append(&line, " loadStatus=");
  line_append_signed_dec(&line, load_status);
  line_append(&line, " callStatus=");
  line_append_signed_dec(&line, call_status);
  line_append(&line, " callbackStatus=");
  line_append_signed_dec(&line, callback_status);
  line_append(&line, " result=");
  line_append_signed_dec(&line, result);
  line_append(&line, " isNumber=");
  line_append(&line, is_number ? "true" : "false");
  line_append(&line, " hooks=");
  line_append_signed_dec(&line, lua_hook_registration_count);
  line_append(&line, " hook=");
  line_append(&line, safe_hook);
  line_append(&line, " preRef=");
  line_append_signed_dec(&line, lua_hook_pre_ref);
  line_append(&line, " postRef=");
  line_append_signed_dec(&line, lua_hook_post_ref);
  line_append(&line, " preCalls=");
  line_append_signed_dec(&line, lua_hook_pre_calls);
  line_append(&line, " postCalls=");
  line_append_signed_dec(&line, lua_hook_post_calls);
  line_append(&line, " preResult=");
  line_append_signed_dec(&line, lua_hook_pre_result);
  line_append(&line, " postResult=");
  line_append_signed_dec(&line, lua_hook_post_result);
  line_append(&line, " preIsNumber=");
  line_append(&line, lua_hook_pre_is_number ? "true" : "false");
  line_append(&line, " postIsNumber=");
  line_append(&line, lua_hook_post_is_number ? "true" : "false");
  line_append(&line, " objectHandles=");
  line_append_dec(&line, lua_object_handle_count);
  line_append(&line, " ueObjectHandles=");
  line_append_dec(&line, ue_candidate_object_handle_count);
  line_append(&line, " staticFindObjectCalls=");
  line_append_signed_dec(&line, lua_static_find_object_calls);
  line_append(&line, " staticFindObjectHits=");
  line_append_signed_dec(&line, lua_static_find_object_hits);
  line_append(&line, " findObjectCalls=");
  line_append_signed_dec(&line, lua_find_object_calls);
  line_append(&line, " findObjectHits=");
  line_append_signed_dec(&line, lua_find_object_hits);
  line_append(&line, " findFirstOfCalls=");
  line_append_signed_dec(&line, lua_find_first_of_calls);
  line_append(&line, " findFirstOfHits=");
  line_append_signed_dec(&line, lua_find_first_of_hits);
  line_append(&line, " getKnownObjectsCalls=");
  line_append_signed_dec(&line, lua_get_known_objects_calls);
  line_append(&line, " getKnownObjectsHits=");
  line_append_signed_dec(&line, lua_get_known_objects_hits);
  line_append(&line, " findObjectsCalls=");
  line_append_signed_dec(&line, lua_find_objects_calls);
  line_append(&line, " findObjectsHits=");
  line_append_signed_dec(&line, lua_find_objects_hits);
  line_append(&line, " findAllOfCalls=");
  line_append_signed_dec(&line, lua_find_all_of_calls);
  line_append(&line, " findAllOfHits=");
  line_append_signed_dec(&line, lua_find_all_of_hits);
  line_append(&line, " forEachUObjectCalls=");
  line_append_signed_dec(&line, lua_for_each_uobject_calls);
  line_append(&line, " forEachUObjectCallbacks=");
  line_append_signed_dec(&line, lua_for_each_uobject_callbacks);
  line_append(&line, " forEachFunctionCalls=");
  line_append_signed_dec(&line, lua_for_each_function_calls);
  line_append(&line, " forEachFunctionCallbacks=");
  line_append_signed_dec(&line, lua_for_each_function_callbacks);
  line_append(&line, " isACalls=");
  line_append_signed_dec(&line, lua_is_a_calls);
  line_append(&line, " isAHits=");
  line_append_signed_dec(&line, lua_is_a_hits);
  line_append(&line, " loadAssetCalls=");
  line_append_signed_dec(&line, lua_load_asset_calls);
  line_append(&line, " loadAssetHits=");
  line_append_signed_dec(&line, lua_load_asset_hits);
  line_append(&line, " staticConstructObjectCalls=");
  line_append_signed_dec(&line, lua_static_construct_object_calls);
  line_append(&line, " staticConstructObjectHits=");
  line_append_signed_dec(&line, lua_static_construct_object_hits);
  line_append(&line, " notifyOnNewObjectCalls=");
  line_append_signed_dec(&line, lua_notify_on_new_object_calls);
  line_append(&line, " executeInGameThreadCalls=");
  line_append_signed_dec(&line, lua_execute_in_game_thread_calls);
  line_append(&line, " executeInGameThreadCallbacks=");
  line_append_signed_dec(&line, lua_execute_in_game_thread_callbacks);
  line_append(&line, " executeInGameThreadResult=");
  line_append_signed_dec(&line, lua_execute_in_game_thread_result);
  line_append(&line, " executeInGameThreadIsNumber=");
  line_append(&line, lua_execute_in_game_thread_is_number ? "true" : "false");
  line_append(&line, " notifyOnNewObjectCallbacks=");
  line_append_signed_dec(&line, lua_notify_on_new_object_callbacks);
  line_append(&line, " notifyOnNewObjectResult=");
  line_append_signed_dec(&line, lua_notify_on_new_object_result);
  line_append(&line, " notifyOnNewObjectIsNumber=");
  line_append(&line, lua_notify_on_new_object_is_number ? "true" : "false");
  line_append(&line, " notifyOnNewObjectStatus=");
  line_append_signed_dec(&line, lua_notify_on_new_object_status);
  line_append(&line, " staticConstructObjectOuterHits=");
  line_append_signed_dec(&line, lua_static_construct_object_outer_hits);
  line_append(&line, " getWorldCalls=");
  line_append_signed_dec(&line, lua_get_world_calls);
  line_append(&line, " getWorldHits=");
  line_append_signed_dec(&line, lua_get_world_hits);
  line_append(&line, " getCdoCalls=");
  line_append_signed_dec(&line, lua_get_cdo_calls);
  line_append(&line, " getCdoHits=");
  line_append_signed_dec(&line, lua_get_cdo_hits);
  line_append(&line, " getLevelCalls=");
  line_append_signed_dec(&line, lua_get_level_calls);
  line_append(&line, " getLevelHits=");
  line_append_signed_dec(&line, lua_get_level_hits);
  line_append(&line, " scriptBytes=");
  line_append_dec(&line, cstr_len(script));
  emit_line(&line);
  lua_unref_hook_registrations(&api, state);
  lua_unref_notify_on_new_object_registrations(&api, state);
  api.close(state);
  FreeLibrary(api.module);
}

static void append_lua_reflection_script_chunk(char *script, size_t script_size, const char *chunk) {
  if (!script || script_size == 0 || !chunk) {
    return;
  }
  size_t used = cstr_len(script);
  if (used >= script_size - 1) {
    return;
  }
  size_t available = script_size - used - 1;
  size_t chunk_len = cstr_len(chunk);
  if (chunk_len > available) {
    chunk_len = available;
  }
  for (size_t i = 0; i < chunk_len; ++i) {
    script[used + i] = chunk[i];
  }
  script[used + chunk_len] = '\0';
}

static void build_lua_reflection_self_test_script(char *script, size_t script_size, int raw_set_self_test) {
  if (!script || script_size == 0) {
    return;
  }
  script[0] = '\0';
  append_lua_reflection_script_chunk(
    script,
    script_size,
    "local o=StaticFindObject('/Script/UE4SSLProbe.SelfTestObject');local ro=StaticFindObject('/RuntimeProbe/SelfTestUObject')or o;local prop='SelfTestUObjectName_0';"
    "local a=GetPropertyValue(o,'ProbeValue');local cls=GetPropertyValue(o,'ClassName');local ab=GetPropertyValue(o,'ProbeBool');local as=GetPropertyValue(o,'ProbeString');local ao=GetPropertyValue(o,'ProbeObject');local af=GetPropertyValue(o,'ProbeFloat');local ad=GetPropertyValue(o,'ProbeDouble');local an=GetPropertyValue(o,'ProbeName');local at=GetPropertyValue(o,'ProbeText');"
    "local ar=o and o:Reflection():GetProperty('ProbeArray');local ai=ar and ar:GetInner();local ae=o and o:Reflection():GetProperty('ProbeEnum');local ev=ae and ae:GetEnum();local eu=ae and ae:GetUnderlyingProperty();local ss=o and o:Reflection():GetProperty('ProbeSet');local se=ss and ss:GetElementProperty();local mp=o and o:Reflection():GetProperty('ProbeMap');local mk=mp and mp:GetKeyProperty();local mv=mp and mp:GetValueProperty();"
  );
  append_lua_reflection_script_chunk(
    script,
    script_size,
    "local pv=o and o:Reflection():GetProperty('ProbeValue');local metadataOk=pv and pv:GetOffset_Internal()==0 and pv:GetOffsetInternal()==0 and pv:GetElementSize()==4 and pv:GetSize()==4 and pv:GetArrayDim()==1 and pv:GetPropertyFlags()==0 and pv:HasAnyPropertyFlags(1)==false;"
    "local pb=o and o:Reflection():GetProperty('ProbeBool');local pf=o and o:Reflection():GetProperty('ProbeFloat');local pd=o and o:Reflection():GetProperty('ProbeDouble');local pn=o and o:Reflection():GetProperty('ProbeName');local psd=o and o:Reflection():GetProperty('ProbeString');local ptd=o and o:Reflection():GetProperty('ProbeText');local pod=o and o:Reflection():GetProperty('ProbeObject');"
    "local dname=pn and pn:GetValue();local dtext=ptd and ptd:GetValue();local dobj=pod and pod:GetValue();"
    "local descriptorOk=pv and pb and pf and pd and pn and psd and ptd and pod and pv:GetValue()==7 and pb:GetValue()==true and math.abs(pf:GetValue()-12.5)<0.001 and math.abs(pd:GetValue()+45.25)<0.001 and dname and dname.Name=='SelfTestUObjectName_0' and psd:GetValue()=='spice' and dtext and dtext.Text=='ProbeText' and dobj and dobj.Address==o.Address "
  );
  append_lua_reflection_script_chunk(
    script,
    script_size,
    "and pv:SetValue(31) and pb:SetValue(false) and pf:SetValue(1.25) and pd:SetValue(-2.5) and pn:SetValue(FName('DescriptorName')) and psd:SetValue('descriptor-spice') and ptd:SetValue(FText('DescriptorText')) and pod:SetValue(o) "
    "and pv:GetValue()==31 and pb:GetValue()==false and math.abs(pf:GetValue()-1.25)<0.001 and math.abs(pd:GetValue()+2.5)<0.001 and pn:GetValue().Name=='DescriptorName' and psd:GetValue()=='descriptor-spice' and ptd:GetValue().Text=='DescriptorText' and pod:GetValue().Address==o.Address;"
  );
  append_lua_reflection_script_chunk(
    script,
    script_size,
    "local raw=GetPropertyValue(ro,prop);if raw==nil then prop='propertyLink[0]';raw=GetPropertyValue(ro,prop);end;local ps=o and o:Reflection():GetProperty('ProbeString');local exportText=ps and ps:ImportText('imported-spice') and ps:ExportText();local importOk=exportText=='imported-spice' and GetPropertyValue(o,'ProbeString')=='imported-spice';"
  );
  if (raw_set_self_test) {
    append_lua_reflection_script_chunk(
      script,
      script_size,
      "local rawSetOk=true;local raw2=raw;if raw~=nil then rawSetOk=SetPropertyValue(ro,prop,17);raw2=GetPropertyValue(ro,prop);end;"
    );
  }
  append_lua_reflection_script_chunk(
    script,
    script_size,
    "local ok1=SetPropertyValue(o,'ProbeValue',21);local ok2=SetPropertyValue(o,'ProbeBool',false);local ok3=SetPropertyValue(o,'ProbeString','melange');local ok4=SetPropertyValue(o,'ProbeObject',o);local ok5=SetPropertyValue(o,'ProbeFloat',13.75);local ok6=SetPropertyValue(o,'ProbeDouble',-47.5);local ok7=SetPropertyValue(o,'ProbeName',FName('ArrakisName'));local ok8=SetPropertyValue(o,'ProbeText',FText('WaterDebt'));"
    "local b=GetPropertyValue(o,'ProbeValue');local bb=GetPropertyValue(o,'ProbeBool');local bs=GetPropertyValue(o,'ProbeString');local bo=GetPropertyValue(o,'ProbeObject');local bf=GetPropertyValue(o,'ProbeFloat');local bd=GetPropertyValue(o,'ProbeDouble');local bn=GetPropertyValue(o,'ProbeName');local bt=GetPropertyValue(o,'ProbeText');local c=CallFunction(o,'DoubleProbeValue');local cb=CallFunction(o,'IsProbeBoolSet');"
  );
  append_lua_reflection_script_chunk(
    script,
    script_size,
    raw_set_self_test ?
      "local rawOk=(raw==nil or(raw==13 and rawSetOk and raw2==17));" :
      "local rawOk=(raw==nil or raw==13);"
  );
  append_lua_reflection_script_chunk(
    script,
    script_size,
    "return(o and ro and a==7 and cls=='UE4SSLProbeSelfTestClass' and ab==true and as=='spice' and ao and ao.Address==o.Address and math.abs(af-12.5)<0.001 and math.abs(ad+45.25)<0.001 and an and an.Kind=='FName' and an.Name=='SelfTestUObjectName_0' and an.ComparisonIndex==1234 and an.Number==1 and at and at.Kind=='FText' and at.Text=='ProbeText' "
    "and ar and ar.ClassName=='FArrayProperty' and ai and ai.ClassName=='FIntProperty' and ai.ElementSize==4 and ae and ae.ClassName=='FEnumProperty' and ev and ev.Name=='EProbeMode' and ev.ClassName=='UEnum' and eu and eu.ClassName=='FByteProperty' and eu.ElementSize==1 and ss and ss.ClassName=='FSetProperty' and se and se.ClassName=='FIntProperty' and se.ElementSize==4 and mp and mp.ClassName=='FMapProperty' and mk and mk.ClassName=='FIntProperty' and mk.ElementSize==4 and mv and mv.ClassName=='FStrProperty' "
  );
  append_lua_reflection_script_chunk(
    script,
    script_size,
    "and metadataOk and descriptorOk and rawOk and importOk and ok1 and ok2 and ok3 and ok4 and ok5 and ok6 and ok7 and ok8 and b==21 and bb==false and bs=='melange' and bo and bo.Address==o.Address and math.abs(bf-13.75)<0.001 and math.abs(bd+47.5)<0.001 and bn and bn.Name=='ArrakisName' and bn.ComparisonIndex==0 and bn.Number==0 and bt and bt.Text=='WaterDebt' and c==42 and cb==false)and 42 or -100"
  );
}

static void run_lua_reflection_self_test(const char *phase) {
  if (!env_bool("UE4SSL_WIN_LUA_REFLECTION_SELF_TEST", 0)) {
    return;
  }
  reset_lua_hook_registration();
  LuaApi api;
  zero_lua_api(&api);
  if (!load_lua_api(&api)) {
    static Line missing_line;
    line_init(&missing_line);
    line_append(&missing_line, "event=lua-reflection-self-test phase=");
    line_append(&missing_line, phase);
    line_append(&missing_line, " status=library-missing");
    emit_line(&missing_line);
    return;
  }

  static char script[12288];
  int raw_set_self_test = env_bool("UE4SSL_WIN_LUA_REFLECTION_RAW_SET_ENABLED", 0);
  if (env_get("UE4SSL_WIN_LUA_REFLECTION_SELF_TEST_SCRIPT", script, sizeof(script)) == 0 || !script[0]) {
    build_lua_reflection_self_test_script(script, sizeof(script), raw_set_self_test);
  }
  if (ue_reflection_property_candidate_count > 0) {
    ue_self_test_object.internal_index = SELF_TEST_RAW_LIVE_VALUE;
  }
  LuaState *state = api.new_state();
  if (!state) {
    static Line state_line;
    line_init(&state_line);
    line_append(&state_line, "event=lua-reflection-self-test phase=");
    line_append(&state_line, phase);
    line_append(&state_line, " status=state-failed library=");
    line_append(&state_line, api.library);
    emit_line(&state_line);
    FreeLibrary(api.module);
    return;
  }
  api.open_libs(state);
  register_lua_probe_api(&api, state);
  int load_status = api.load_string(state, script);
  active_lua_api = &api;
  int call_status = load_status == 0 ? lua_call(&api, state, 0, 1, 0) : load_status;
  active_lua_api = 0;
  int is_number = 0;
  long long result = call_status == 0 ? lua_to_integer(&api, state, -1, &is_number) : 0;
  int raw_value_ok = lua_reflection_raw_property_hits == 0 ||
                     lua_reflection_raw_property_value == SELF_TEST_RAW_LIVE_VALUE ||
                     lua_reflection_raw_property_value == SELF_TEST_RAW_SET_VALUE;
  int raw_set_ok = lua_reflection_raw_property_set_hits == 0 ||
                   (lua_reflection_raw_property_set_hits == 1 &&
                    lua_reflection_raw_property_set_value == SELF_TEST_RAW_SET_VALUE &&
                    lua_reflection_raw_property_value == SELF_TEST_RAW_SET_VALUE);
  const char *status = load_status == 0 && call_status == 0 && is_number && result == 42 &&
                       lua_static_find_object_calls >= 1 && lua_static_find_object_calls <= 2 &&
                       lua_static_find_object_hits >= 1 &&
                       lua_reflection_get_property_calls >= 18 + lua_reflection_raw_property_hits &&
                       lua_reflection_get_property_hits == 18 + lua_reflection_raw_property_hits &&
                       lua_reflection_array_inner_property_hits == 1 &&
                       lua_reflection_enum_property_hits == 1 &&
                       lua_reflection_enum_underlying_property_hits == 1 &&
                       lua_reflection_set_element_property_hits == 1 &&
                       lua_reflection_map_key_property_hits == 1 &&
                       lua_reflection_map_value_property_hits == 1 &&
                       lua_reflection_import_text_hits == 1 &&
                       lua_reflection_export_text_hits == 1 &&
                       lua_reflection_property_metadata_hits == 7 &&
                       lua_reflection_descriptor_value_get_hits == 16 &&
                       lua_reflection_descriptor_value_set_hits == 8 &&
                       raw_value_ok && raw_set_ok &&
                       lua_reflection_set_property_calls == 8 + lua_reflection_raw_property_set_hits &&
                       lua_reflection_set_property_hits == 8 + lua_reflection_raw_property_set_hits &&
                       lua_reflection_call_function_calls == 2 && lua_reflection_call_function_hits == 2 &&
                       lua_reflection_probe_value == 21 && lua_reflection_probe_bool_value == 0 &&
                       lua_reflection_probe_float_value == 13.75f &&
                       lua_reflection_probe_double_value == -47.5 &&
                       str_equal(lua_reflection_probe_name_string, "ArrakisName") &&
                       str_equal(lua_reflection_probe_string_value, "melange") &&
                       str_equal(lua_reflection_probe_text_value, "WaterDebt") &&
                       lua_reflection_probe_object_address == (uintptr_t)&ue_self_test_object ? "passed" : "failed";

  static Line line;
  line_init(&line);
  line_append(&line, "event=lua-reflection-self-test phase=");
  line_append(&line, phase);
  line_append(&line, " status=");
  line_append(&line, status);
  line_append(&line, " library=");
  line_append(&line, api.library);
  line_append(&line, " loadStatus=");
  line_append_signed_dec(&line, load_status);
  line_append(&line, " callStatus=");
  line_append_signed_dec(&line, call_status);
  line_append(&line, " result=");
  line_append_signed_dec(&line, result);
  line_append(&line, " isNumber=");
  line_append(&line, is_number ? "true" : "false");
  line_append(&line, " staticFindObjectCalls=");
  line_append_signed_dec(&line, lua_static_find_object_calls);
  line_append(&line, " staticFindObjectHits=");
  line_append_signed_dec(&line, lua_static_find_object_hits);
  line_append(&line, " getPropertyCalls=");
  line_append_signed_dec(&line, lua_reflection_get_property_calls);
  line_append(&line, " getPropertyHits=");
  line_append_signed_dec(&line, lua_reflection_get_property_hits);
  line_append(&line, " rawPropertyHits=");
  line_append_signed_dec(&line, lua_reflection_raw_property_hits);
  line_append(&line, " rawPropertyValue=");
  line_append_signed_dec(&line, lua_reflection_raw_property_value);
  line_append(&line, " namedPropertyHits=");
  line_append_signed_dec(&line, lua_reflection_named_property_hits);
  line_append(&line, " rawPropertySetHits=");
  line_append_signed_dec(&line, lua_reflection_raw_property_set_hits);
  line_append(&line, " rawPropertySetValue=");
  line_append_signed_dec(&line, lua_reflection_raw_property_set_value);
  line_append(&line, " arrayInnerPropertyHits=");
  line_append_signed_dec(&line, lua_reflection_array_inner_property_hits);
  line_append(&line, " enumPropertyHits=");
  line_append_signed_dec(&line, lua_reflection_enum_property_hits);
  line_append(&line, " enumUnderlyingPropertyHits=");
  line_append_signed_dec(&line, lua_reflection_enum_underlying_property_hits);
  line_append(&line, " setElementPropertyHits=");
  line_append_signed_dec(&line, lua_reflection_set_element_property_hits);
  line_append(&line, " mapKeyPropertyHits=");
  line_append_signed_dec(&line, lua_reflection_map_key_property_hits);
  line_append(&line, " mapValuePropertyHits=");
  line_append_signed_dec(&line, lua_reflection_map_value_property_hits);
  line_append(&line, " importTextHits=");
  line_append_signed_dec(&line, lua_reflection_import_text_hits);
  line_append(&line, " exportTextHits=");
  line_append_signed_dec(&line, lua_reflection_export_text_hits);
  line_append(&line, " propertyMetadataHits=");
  line_append_signed_dec(&line, lua_reflection_property_metadata_hits);
  line_append(&line, " descriptorValueGetHits=");
  line_append_signed_dec(&line, lua_reflection_descriptor_value_get_hits);
  line_append(&line, " descriptorValueSetHits=");
  line_append_signed_dec(&line, lua_reflection_descriptor_value_set_hits);
  line_append(&line, " setPropertyCalls=");
  line_append_signed_dec(&line, lua_reflection_set_property_calls);
  line_append(&line, " setPropertyHits=");
  line_append_signed_dec(&line, lua_reflection_set_property_hits);
  line_append(&line, " callFunctionCalls=");
  line_append_signed_dec(&line, lua_reflection_call_function_calls);
  line_append(&line, " callFunctionHits=");
  line_append_signed_dec(&line, lua_reflection_call_function_hits);
  line_append(&line, " probeValue=");
  line_append_signed_dec(&line, lua_reflection_probe_value);
  line_append(&line, " probeBool=");
  line_append(&line, lua_reflection_probe_bool_value ? "true" : "false");
  line_append(&line, " probeFloat=");
  line_append_fixed3(&line, (double)lua_reflection_probe_float_value);
  line_append(&line, " probeDouble=");
  line_append_fixed3(&line, lua_reflection_probe_double_value);
  line_append(&line, " probeName=");
  line_append(&line, lua_reflection_probe_name_string);
  line_append(&line, " probeString=");
  line_append(&line, lua_reflection_probe_string_value);
  line_append(&line, " probeText=");
  line_append(&line, lua_reflection_probe_text_value);
  line_append(&line, " probeObject=");
  line_append_hex(&line, lua_reflection_probe_object_address);
  line_append(&line, " objectHandles=");
  line_append_dec(&line, lua_object_handle_count);
  line_append(&line, " ueObjectHandles=");
  line_append_dec(&line, ue_candidate_object_handle_count);
  line_append(&line, " scriptBytes=");
  line_append_dec(&line, cstr_len(script));
  emit_line(&line);

  lua_unref_hook_registrations(&api, state);
  lua_unref_notify_on_new_object_registrations(&api, state);
  api.close(state);
  FreeLibrary(api.module);
}

__attribute__((noinline, used)) static int hook_self_test_replacement(int value) {
  return dispatch_hook_self_test(value);
}

static void copy_bytes(unsigned char *dst, const unsigned char *src, size_t count) {
  for (size_t i = 0; i < count; ++i) {
    dst[i] = src[i];
  }
}

static void *hook_function_pointer(HookSelfTestFn fn) {
  union {
    HookSelfTestFn fn;
    void *ptr;
  } value;
  value.fn = fn;
  return value.ptr;
}

static HookSelfTestFn hook_pointer_function(void *ptr) {
  union {
    HookSelfTestFn fn;
    void *ptr;
  } value;
  value.ptr = ptr;
  return value.fn;
}

static void *process_event_function_pointer(ProcessEventSelfTestFn fn) {
  union {
    ProcessEventSelfTestFn fn;
    void *ptr;
  } value;
  value.fn = fn;
  return value.ptr;
}

static ProcessEventSelfTestFn process_event_pointer_function(void *ptr) {
  union {
    ProcessEventSelfTestFn fn;
    void *ptr;
  } value;
  value.ptr = ptr;
  return value.fn;
}

static void *allocate_trampoline(size_t length) {
  return VirtualAlloc(0, length, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
}

static int protect_trampoline_executable(void *memory, size_t length) {
  DWORD old_protect = 0;
  return VirtualProtect(memory, length, PAGE_EXECUTE_READ, &old_protect);
}

static void free_trampoline(void *memory) {
  if (memory) {
    VirtualFree(memory, 0, MEM_RELEASE);
  }
}

static void zero_hook(InlineHookPatch *hook) {
  unsigned char *bytes = (unsigned char *)hook;
  for (size_t i = 0; i < sizeof(*hook); ++i) {
    bytes[i] = 0;
  }
}

static void write_absolute_jump(unsigned char *patch, void *destination) {
  uintptr_t address = (uintptr_t)destination;
  patch[0] = 0x48;
  patch[1] = 0xb8;
  for (size_t i = 0; i < sizeof(address); ++i) {
    patch[2 + i] = ((const unsigned char *)&address)[i];
  }
  patch[10] = 0xff;
  patch[11] = 0xe0;
}

static int install_inline_hook(InlineHookPatch *hook, const char *name) {
#if defined(__x86_64__) || defined(__amd64__) || defined(_M_X64)
  static Line line;
  if (!hook || !hook->target || !hook->replacement) {
    line_init(&line);
    line_append(&line, "event=hook-dispatch name=");
    line_append(&line, name);
    line_append(&line, " status=invalid-argument");
    emit_line(&line);
    return 0;
  }
  hook->patch_len = INLINE_HOOK_PATCH_LEN;
  hook->trampoline_len = hook->patch_len + INLINE_HOOK_PATCH_LEN;
  hook->trampoline = allocate_trampoline(hook->trampoline_len);
  if (!hook->trampoline) {
    line_init(&line);
    line_append(&line, "event=hook-dispatch name=");
    line_append(&line, name);
    line_append(&line, " status=trampoline-allocation-failed target=");
    line_append_hex(&line, (uintptr_t)hook->target);
    emit_line(&line);
    return 0;
  }

  DWORD old_protect = 0;
  if (!VirtualProtect(hook->target, hook->patch_len, PAGE_EXECUTE_READWRITE, &old_protect)) {
    line_init(&line);
    line_append(&line, "event=hook-dispatch name=");
    line_append(&line, name);
    line_append(&line, " status=protect-failed target=");
    line_append_hex(&line, (uintptr_t)hook->target);
    emit_line(&line);
    free_trampoline(hook->trampoline);
    hook->trampoline = 0;
    hook->trampoline_len = 0;
    return 0;
  }

  hook->original_protect = old_protect;
  copy_bytes(hook->original, (const unsigned char *)hook->target, hook->patch_len);
  copy_bytes((unsigned char *)hook->trampoline, hook->original, hook->patch_len);
  write_absolute_jump((unsigned char *)hook->trampoline + hook->patch_len, (void *)((uintptr_t)hook->target + hook->patch_len));
  FlushInstructionCache((HANDLE)(intptr_t)-1, hook->trampoline, hook->trampoline_len);
  if (!protect_trampoline_executable(hook->trampoline, hook->trampoline_len)) {
    line_init(&line);
    line_append(&line, "event=hook-dispatch name=");
    line_append(&line, name);
    line_append(&line, " status=trampoline-protect-failed target=");
    line_append_hex(&line, (uintptr_t)hook->target);
    emit_line(&line);
    DWORD ignored_protect = 0;
    VirtualProtect(hook->target, hook->patch_len, old_protect, &ignored_protect);
    free_trampoline(hook->trampoline);
    hook->trampoline = 0;
    hook->trampoline_len = 0;
    return 0;
  }

  unsigned char patch[INLINE_HOOK_PATCH_LEN];
  write_absolute_jump(patch, hook->replacement);
  copy_bytes((unsigned char *)hook->target, patch, sizeof(patch));
  FlushInstructionCache((HANDLE)(intptr_t)-1, hook->target, hook->patch_len);
  DWORD restored_protect = 0;
  if (!VirtualProtect(hook->target, hook->patch_len, old_protect, &restored_protect)) {
    line_init(&line);
    line_append(&line, "event=hook-dispatch name=");
    line_append(&line, name);
    line_append(&line, " status=restore-protect-failed target=");
    line_append_hex(&line, (uintptr_t)hook->target);
    emit_line(&line);
    free_trampoline(hook->trampoline);
    hook->trampoline = 0;
    hook->trampoline_len = 0;
    return 0;
  }

  hook->installed = 1;
  line_init(&line);
  line_append(&line, "event=hook-dispatch name=");
  line_append(&line, name);
  line_append(&line, " status=installed target=");
  line_append_hex(&line, (uintptr_t)hook->target);
  line_append(&line, " replacement=");
  line_append_hex(&line, (uintptr_t)hook->replacement);
  line_append(&line, " trampoline=");
  line_append_hex(&line, (uintptr_t)hook->trampoline);
  line_append(&line, " patchBytes=");
  line_append_dec(&line, hook->patch_len);
  emit_line(&line);
  return 1;
#else
  static Line line;
  line_init(&line);
  line_append(&line, "event=hook-dispatch name=");
  line_append(&line, name);
  line_append(&line, " status=unsupported-arch");
  emit_line(&line);
  return 0;
#endif
}

static int remove_inline_hook(InlineHookPatch *hook, const char *name) {
#if defined(__x86_64__) || defined(__amd64__) || defined(_M_X64)
  static Line line;
  if (!hook || !hook->installed) {
    line_init(&line);
    line_append(&line, "event=hook-dispatch name=");
    line_append(&line, name);
    line_append(&line, " status=restore-skip");
    emit_line(&line);
    return 0;
  }
  DWORD old_protect = 0;
  if (!VirtualProtect(hook->target, hook->patch_len, PAGE_EXECUTE_READWRITE, &old_protect)) {
    line_init(&line);
    line_append(&line, "event=hook-dispatch name=");
    line_append(&line, name);
    line_append(&line, " status=restore-protect-failed target=");
    line_append_hex(&line, (uintptr_t)hook->target);
    emit_line(&line);
    return 0;
  }
  copy_bytes((unsigned char *)hook->target, hook->original, hook->patch_len);
  FlushInstructionCache((HANDLE)(intptr_t)-1, hook->target, hook->patch_len);
  DWORD restored_protect = 0;
  if (!VirtualProtect(hook->target, hook->patch_len, hook->original_protect, &restored_protect)) {
    line_init(&line);
    line_append(&line, "event=hook-dispatch name=");
    line_append(&line, name);
    line_append(&line, " status=restore-final-protect-failed target=");
    line_append_hex(&line, (uintptr_t)hook->target);
    emit_line(&line);
    return 0;
  }
  hook->installed = 0;
  free_trampoline(hook->trampoline);
  hook->trampoline = 0;
  hook->trampoline_len = 0;
  line_init(&line);
  line_append(&line, "event=hook-dispatch name=");
  line_append(&line, name);
  line_append(&line, " status=restored target=");
  line_append_hex(&line, (uintptr_t)hook->target);
  emit_line(&line);
  return 1;
#else
  (void)hook;
  static Line line;
  line_init(&line);
  line_append(&line, "event=hook-dispatch name=");
  line_append(&line, name);
  line_append(&line, " status=restore-unsupported-arch");
  emit_line(&line);
  return 0;
#endif
}

static void run_hook_dispatch_self_test(const char *phase) {
  if (!env_bool("UE4SSL_WIN_HOOK_SELF_TEST", 0)) {
    return;
  }
  reset_hook_dispatch_slots();
  int registered_pre = register_hook_dispatch_callback(HOOK_DISPATCH_PRE, hook_self_test_pre_callback, 0);
  int registered_post = register_hook_dispatch_callback(HOOK_DISPATCH_POST, hook_self_test_post_callback, 0);
  if (!hook_self_test_entry) {
    hook_self_test_entry = hook_self_test_target;
  }
  int before = hook_self_test_entry(41);
  InlineHookPatch hook;
  zero_hook(&hook);
  hook.target = hook_function_pointer(hook_self_test_target);
  hook.replacement = hook_function_pointer(hook_self_test_replacement);
  int installed = install_inline_hook(&hook, "SelfTestHook");
  hook_self_test_original = installed ? hook_pointer_function(hook.trampoline) : 0;
  void *trampoline = hook.trampoline;
  int after = hook_self_test_entry(41);
  int restored = remove_inline_hook(&hook, "SelfTestHook");
  hook_self_test_original = 0;
  int final = hook_self_test_entry(41);
  const char *status = before == 42 && registered_pre && registered_post && installed && after == 1042 &&
                       hook_self_test_last_original == 42 && hook_self_test_last_pre_callbacks == 1 &&
                       hook_self_test_last_post_callbacks == 1 && restored && final == 42 ? "passed" : "failed";

  static Line line;
  line_init(&line);
  line_append(&line, "event=hook-dispatch-self-test phase=");
  line_append(&line, phase);
  line_append(&line, " status=");
  line_append(&line, status);
  line_append(&line, " before=");
  line_append_signed_dec(&line, before);
  line_append(&line, " after=");
  line_append_signed_dec(&line, after);
  line_append(&line, " final=");
  line_append_signed_dec(&line, final);
  line_append(&line, " original=");
  line_append_signed_dec(&line, hook_self_test_last_original);
  line_append(&line, " callbacks=");
  line_append_dec(&line, hook_dispatch_slot_count);
  line_append(&line, " preCallbacks=");
  line_append_signed_dec(&line, hook_self_test_last_pre_callbacks);
  line_append(&line, " postCallbacks=");
  line_append_signed_dec(&line, hook_self_test_last_post_callbacks);
  line_append(&line, " installed=");
  line_append(&line, installed ? "true" : "false");
  line_append(&line, " restored=");
  line_append(&line, restored ? "true" : "false");
  line_append(&line, " target=");
  line_append_hex(&line, (uintptr_t)hook.target);
  line_append(&line, " replacement=");
  line_append_hex(&line, (uintptr_t)hook.replacement);
  line_append(&line, " trampoline=");
  line_append_hex(&line, (uintptr_t)trampoline);
  emit_line(&line);
}

__attribute__((noinline, used)) static void process_event_self_test_target(void *object, void *function, void *params) {
#if defined(__x86_64__) || defined(__amd64__) || defined(_M_X64)
  __asm__ __volatile__(
    ".rept 16\n"
    "nop\n"
    ".endr\n"
  );
#endif
  (void)object;
  (void)function;
  ++process_event_self_test_original_calls;
  ProcessEventSelfTestParams *typed = (ProcessEventSelfTestParams *)params;
  if (typed) {
    typed->original_result = typed->value + 1;
    ++typed->touched;
  }
}

static void process_event_self_test_replacement(void *object, void *function, void *params) {
  ++process_event_self_test_hook_calls;
  process_event_self_test_last_object = (uintptr_t)object;
  process_event_self_test_last_function = (uintptr_t)function;
  process_event_self_test_last_params = (uintptr_t)params;

  ProcessEventDispatchContext ctx;
  unsigned char *ctx_bytes = (unsigned char *)&ctx;
  for (size_t i = 0; i < sizeof(ctx); ++i) {
    ctx_bytes[i] = 0;
  }
  ctx.object = object;
  ctx.function = function;
  ctx.params = params;
  if ((uintptr_t)function == process_event_self_test_function_address()) {
    ctx.function_path = "/Script/UE4SSLProbe.SelfTest:Function";
  }
  ctx.call_index = process_event_self_test_hook_calls;

  process_event_self_test_pre_status = invoke_lua_hook_registrations_with_process_event_context(
    process_event_lua_api,
    process_event_lua_state,
    &ctx,
    "pre",
    1
  );

  ProcessEventSelfTestFn original = process_event_self_test_original;
  if (original) {
    original(object, function, params);
  }
  ctx.original_called = original ? 1 : 0;

  process_event_self_test_post_status = invoke_lua_hook_registrations_with_process_event_context(
    process_event_lua_api,
    process_event_lua_state,
    &ctx,
    "post",
    0
  );
}

static void process_event_live_probe_replacement(void *object, void *function, void *params) {
  ++process_event_live_probe_calls;
  process_event_self_test_last_object = (uintptr_t)object;
  process_event_self_test_last_function = (uintptr_t)function;
  process_event_self_test_last_params = (uintptr_t)params;
  ProcessEventSelfTestFn original = process_event_live_probe_original;
  if (original) {
    original(object, function, params);
  }
}

static void close_process_event_live_lua_dispatch(const char *phase) {
  if (!process_event_live_lua_loaded && !process_event_live_lua_state && !process_event_live_lua_api.module) {
    return;
  }
  lua_unref_hook_registrations(&process_event_live_lua_api, process_event_live_lua_state);
  lua_unref_notify_on_new_object_registrations(&process_event_live_lua_api, process_event_live_lua_state);
  if (process_event_live_lua_api.close && process_event_live_lua_state) {
    process_event_live_lua_api.close(process_event_live_lua_state);
  }
  if (process_event_live_lua_api.module) {
    FreeLibrary(process_event_live_lua_api.module);
  }
  static Line line;
  line_init(&line);
  line_append(&line, "event=ue-process-event-live-lua-dispatch phase=");
  line_append(&line, phase);
  line_append(&line, " status=closed preCalls=");
  line_append_signed_dec(&line, lua_hook_pre_calls);
  line_append(&line, " postCalls=");
  line_append_signed_dec(&line, lua_hook_post_calls);
  line_append(&line, " preResult=");
  line_append_signed_dec(&line, lua_hook_pre_result);
  line_append(&line, " postResult=");
  line_append_signed_dec(&line, lua_hook_post_result);
  line_append(&line, " preStatus=");
  line_append_signed_dec(&line, process_event_live_lua_pre_status);
  line_append(&line, " postStatus=");
  line_append_signed_dec(&line, process_event_live_lua_post_status);
  emit_line(&line);
  zero_lua_api(&process_event_live_lua_api);
  process_event_live_lua_state = 0;
  process_event_live_lua_loaded = 0;
  process_event_live_lua_enabled = 0;
}

static void process_event_live_lua_pre_callback(ProcessEventDispatchContext *ctx, void *user) {
  (void)user;
  process_event_live_lua_pre_status = invoke_lua_hook_registrations_with_process_event_context(
    &process_event_live_lua_api,
    process_event_live_lua_state,
    ctx,
    "pre",
    1
  );
}

static void process_event_live_lua_post_callback(ProcessEventDispatchContext *ctx, void *user) {
  (void)user;
  process_event_live_lua_post_status = invoke_lua_hook_registrations_with_process_event_context(
    &process_event_live_lua_api,
    process_event_live_lua_state,
    ctx,
    "post",
    0
  );
}

static void build_process_event_live_lua_script(char *script, size_t script_size) {
  if (!script || script_size == 0) {
    return;
  }
  script[0] = '\0';
  append_lua_reflection_script_chunk(
    script,
    script_size,
    "local G=GetParamDescriptor;local H=GetFunctionParams;local V=GetParamValue;local S=SetParamValue;"
    "RegisterHook('/Script/UE4SSLProbe.NotTarget:Function',function()return -99 end,function()return -99 end);"
    "return RegisterHook('/Script/UE4SSLProbe.LiveProcessEvent:Function',function(c)local p=c and c.Params;local d=c and c.Function and H(c.Function);local q=d and d.Properties;"
    "local v=p and G(p,'Value');local fv=q and q.Value;local g=p and G(p,'Flag');local sb=p and G(p,'SignedByte');local us=p and G(p,'UnsignedShort');local sl=p and G(p,'SignedLarge');"
  );
  append_lua_reflection_script_chunk(
    script,
    script_size,
    "local fl=p and G(p,'FloatValue');local db=p and G(p,'DoubleValue');local o=p and G(p,'TargetObject');local ov=o and V(p,o);"
    "local n=p and G(p,'NameToken');local fn=q and q.NameToken;local nv=fn and V(p,fn);local m=p and G(p,'Message');local fm=q and q.Message;local mv=fm and V(p,fm);"
    "local l=p and G(p,'Location');local fc=q and q.Location;local lv=fc and V(p,fc);local st=fc and fc:GetStruct();local rp=p and p.Location;local rpv=rp and rp:get();"
    "local rv=p and p.Value;local rv2=p and p.Values and p.Values.Value;"
  );
  append_lua_reflection_script_chunk(
    script,
    script_size,
    "if c and c.stage=='pre'and p and d and p.PropertyCount==13 and d.PropertyCount==6 and v and fv and fv.OffsetInternal==v.OffsetInternal "
    "and rv and rv:type()=='RemoteUnrealParam'and rv.IsValid and rv.Descriptor and rv.Descriptor.OffsetInternal==v.OffsetInternal and rv2 and rv2.Address==rv.Address "
    "and V(p,fv)==61 and rv:get()==61 and g and g.ClassName=='FBoolProperty'and V(p,g)==true and sb and sb.ClassName=='FInt8Property'and V(p,sb)==-7 "
    "and us and us.ClassName=='FUInt16Property'and V(p,us)==65530 and sl and sl.ClassName=='FInt64Property'and V(p,sl)==-1234567890123 "
  );
  append_lua_reflection_script_chunk(
    script,
    script_size,
    "and fl and fl.ClassName=='FFloatProperty'and math.abs(V(p,fl)-12.5)<0.001 and db and db.ClassName=='FDoubleProperty'and p.DoubleValue and math.abs(p.DoubleValue:get()+45.25)<0.001 "
    "and o and o.ClassName=='FObjectProperty'and ov and ov.Address==c.object and n and fn and fn.ClassName=='FNameProperty'and nv and nv.Name=='SelfTestUObjectName_0'and nv.ComparisonIndex==1234 and nv.Number==1 "
    "and m and fm and fm.ClassName=='FStrProperty'and mv=='desert-message'and l and fc and fc.ClassName=='FStructProperty'and fc.OffsetInternal==l.OffsetInternal and st and st.Name=='Vector'and st.ClassName=='UScriptStruct' "
  );
  append_lua_reflection_script_chunk(
    script,
    script_size,
    "and lv and lv.Kind=='FVector'and math.abs(lv.X-1.25)<0.001 and rpv and math.abs(rpv.Z-3.75)<0.001 "
    "and S(p,fn,{ComparisonIndex=1250,Number=0})and S(p,fm,'spice-message')and S(p,fc,{X=7.25,Y=8.5,Z=9.75})"
    "and V(p,fn).ComparisonIndex==1250 and V(p,fm)=='spice-message'and math.abs(V(p,fc).Z-9.75)<0.001 then return 11 end return -11 end,"
  );
  append_lua_reflection_script_chunk(
    script,
    script_size,
    "function(c)local p=c and c.Params;local d=c and c.Function and H(c.Function);local q=d and d.Properties;local r=p and G(p,'OriginalResult');local t=p and G(p,'Touched');"
    "local fr=q and q.OriginalResult;local ft=q and q.Touched;local wt=p and p.Touched;local wv=wt and wt:get();local wf=p and p.FloatValue;local db=p and p.Properties and p.Properties.DoubleValue;"
    "if c and c.stage=='post'and c.originalCalled==true and p and d and d.PropertyCount==6 and r and t and fr and ft and fr.OffsetInternal==r.OffsetInternal and ft.OffsetInternal==t.OffsetInternal "
  );
  append_lua_reflection_script_chunk(
    script,
    script_size,
    "and V(p,fr)==62 and wt and wt:type()=='RemoteUnrealParam'and wv==V(p,ft)and wt:set(wv)and S(p,ft,wv)"
    "and wf and wf:set(13.75)and math.abs(wf:get()-13.75)<0.001 and db and S(p,db,-47.5)and math.abs(V(p,db)+47.5)<0.001 then return 31 end return -31 end)"
  );
}

static int prepare_process_event_live_lua_dispatch(const char *phase) {
  process_event_live_lua_enabled = env_bool("UE4SSL_WIN_UE_PROCESS_EVENT_LIVE_LUA_DISPATCH", 0);
  process_event_live_lua_load_status = -1;
  process_event_live_lua_call_status = -1;
  process_event_live_lua_pre_status = -1;
  process_event_live_lua_post_status = -1;
  process_event_live_lua_result = 0;
  process_event_live_lua_is_number = 0;
  process_event_live_lua_object_handle_hits = 0;
  process_event_live_lua_function_handle_hits = 0;
  process_event_live_lua_params_handle_hits = 0;
  if (!process_event_live_lua_enabled) {
    return 1;
  }

  reset_lua_hook_registration();
  zero_lua_api(&process_event_live_lua_api);
  process_event_live_lua_state = 0;
  process_event_live_lua_loaded = 0;
  if (!load_lua_api(&process_event_live_lua_api)) {
    static Line missing_line;
    line_init(&missing_line);
    line_append(&missing_line, "event=ue-process-event-live-lua-dispatch phase=");
    line_append(&missing_line, phase);
    line_append(&missing_line, " status=library-missing");
    emit_line(&missing_line);
    return 0;
  }
  process_event_live_lua_state = process_event_live_lua_api.new_state();
  if (!process_event_live_lua_state) {
    static Line state_line;
    line_init(&state_line);
    line_append(&state_line, "event=ue-process-event-live-lua-dispatch phase=");
    line_append(&state_line, phase);
    line_append(&state_line, " status=state-failed library=");
    line_append(&state_line, process_event_live_lua_api.library);
    emit_line(&state_line);
    FreeLibrary(process_event_live_lua_api.module);
    zero_lua_api(&process_event_live_lua_api);
    return 0;
  }
  process_event_live_lua_api.open_libs(process_event_live_lua_state);
  seed_lua_object_handles();
  register_lua_probe_api(&process_event_live_lua_api, process_event_live_lua_state);
  static char script[8192];
  if (env_get("UE4SSL_WIN_UE_PROCESS_EVENT_LIVE_LUA_SCRIPT", script, sizeof(script)) == 0 || !script[0]) {
    build_process_event_live_lua_script(script, sizeof(script));
  }
  process_event_live_lua_load_status = process_event_live_lua_api.load_string(process_event_live_lua_state, script);
  active_lua_api = &process_event_live_lua_api;
  process_event_live_lua_call_status = process_event_live_lua_load_status == 0 ?
    lua_call(&process_event_live_lua_api, process_event_live_lua_state, 0, 1, 0) :
    process_event_live_lua_load_status;
  active_lua_api = 0;
  process_event_live_lua_result = process_event_live_lua_call_status == 0 ?
    lua_to_integer(&process_event_live_lua_api, process_event_live_lua_state, -1, &process_event_live_lua_is_number) :
    0;
  static char safe_hook[256];
  safe_value(lua_hook_registration_name, safe_hook, sizeof(safe_hook));
  int ready = process_event_live_lua_load_status == 0 &&
              process_event_live_lua_call_status == 0 &&
              process_event_live_lua_is_number &&
              process_event_live_lua_result == 4 &&
              lua_hook_registration_count > 0 &&
              lua_ref_is_valid(lua_hook_pre_ref) &&
              lua_ref_is_valid(lua_hook_post_ref) &&
              register_process_event_dispatch_callback(HOOK_DISPATCH_PRE, process_event_live_lua_pre_callback, 0) &&
              register_process_event_dispatch_callback(HOOK_DISPATCH_POST, process_event_live_lua_post_callback, 0);
  process_event_live_lua_loaded = ready;
  static Line line;
  line_init(&line);
  line_append(&line, "event=ue-process-event-live-lua-dispatch phase=");
  line_append(&line, phase);
  line_append(&line, " status=");
  line_append(&line, ready ? "armed" : "failed");
  line_append(&line, " library=");
  line_append(&line, process_event_live_lua_api.library);
  line_append(&line, " loadStatus=");
  line_append_signed_dec(&line, process_event_live_lua_load_status);
  line_append(&line, " callStatus=");
  line_append_signed_dec(&line, process_event_live_lua_call_status);
  line_append(&line, " result=");
  line_append_signed_dec(&line, process_event_live_lua_result);
  line_append(&line, " isNumber=");
  line_append(&line, process_event_live_lua_is_number ? "true" : "false");
  line_append(&line, " hooks=");
  line_append_signed_dec(&line, lua_hook_registration_count);
  line_append(&line, " hook=");
  line_append(&line, safe_hook);
  line_append(&line, " callbacks=");
  line_append_signed_dec(&line, (long long)process_event_dispatch_slot_count);
  line_append(&line, " scriptBytes=");
  line_append_dec(&line, cstr_len(script));
  emit_line(&line);
  if (!ready) {
    close_process_event_live_lua_dispatch(phase);
  }
  return ready;
}

static int format_process_event_param_sample(
  uintptr_t params,
  const LuaParamDescriptorView *descriptor,
  char *out,
  size_t out_size
) {
  if (!params || !descriptor || !descriptor->valid || !out || out_size == 0) {
    return 0;
  }
  out[0] = '\0';
  if (lua_param_descriptor_is_fname(descriptor)) {
    UeFNameValue fname_value;
    for (size_t i = 0; i < sizeof(fname_value); ++i) {
      ((unsigned char *)&fname_value)[i] = 0;
    }
    if (!read_process_event_param_bytes(params, descriptor, &fname_value, sizeof(fname_value))) {
      return 0;
    }
    char decoded_name[MAX_LUA_OBJECT_NAME];
    decoded_name[0] = '\0';
    int decoded = 0;
    if (active_lua_fname_resolver_available) {
      decoded = decode_ue_fname(
        &active_lua_fname_resolver,
        &active_lua_fname_options,
        fname_value.comparison_index,
        fname_value.number,
        decoded_name,
        sizeof(decoded_name),
        0,
        0,
        0,
        0,
        0
      );
    }
    char safe_name[MAX_LUA_OBJECT_NAME];
    safe_value(decoded ? decoded_name : "", safe_name, sizeof(safe_name));
    static Line fname_line;
    line_init(&fname_line);
    line_append(&fname_line, "comparisonIndex=");
    line_append_dec(&fname_line, fname_value.comparison_index);
    line_append(&fname_line, ",number=");
    line_append_dec(&fname_line, fname_value.number);
    line_append(&fname_line, ",decoded=");
    line_append(&fname_line, safe_name);
    copy_string(out, out_size, fname_line.text);
    return 1;
  }
  if (lua_param_descriptor_is_string(descriptor)) {
    UeFStringValue value;
    for (size_t i = 0; i < sizeof(value); ++i) {
      ((unsigned char *)&value)[i] = 0;
    }
    if (!read_process_event_param_bytes(params, descriptor, &value, sizeof(value)) ||
        value.data == 0 || value.count <= 0 || value.capacity < value.count ||
        value.count > MAX_PROCESS_EVENT_STRING_CHARS) {
      return 0;
    }
    MEMORY_BASIC_INFORMATION_WIN64 mbi;
    for (size_t i = 0; i < sizeof(mbi); ++i) {
      ((unsigned char *)&mbi)[i] = 0;
    }
    SIZE_T got = VirtualQuery((const void *)value.data, &mbi, sizeof(mbi));
    size_t byte_count = (size_t)value.count;
    if (!got || mbi.State != MEM_COMMIT || !readable_protect(mbi.Protect) ||
        !region_contains_range(&mbi, value.data, byte_count)) {
      return 0;
    }
    char raw[MAX_LUA_OBJECT_PATH];
    const unsigned char *source = (const unsigned char *)value.data;
    size_t chars = byte_count;
    if (chars > 0 && source[chars - 1] == '\0') {
      --chars;
    }
    if (chars >= sizeof(raw)) {
      chars = sizeof(raw) - 1;
    }
    for (size_t i = 0; i < chars; ++i) {
      unsigned char ch = source[i];
      raw[i] = (ch >= 32 && ch < 127) ? (char)ch : '?';
    }
    raw[chars] = '\0';
    safe_value(raw, out, out_size);
    return 1;
  }
  if (lua_param_descriptor_is_container(descriptor)) {
    unsigned char raw[MAX_PROCESS_EVENT_PARAM_BYTES];
    for (size_t i = 0; i < sizeof(raw); ++i) {
      raw[i] = 0;
    }
    size_t read_size = 0;
    UeFScriptContainerHeader header;
    for (size_t i = 0; i < sizeof(header); ++i) {
      ((unsigned char *)&header)[i] = 0;
    }
    if (!read_process_event_container_header(params, descriptor, &header, raw, sizeof(raw), &read_size)) {
      return 0;
    }
    char hex[MAX_PROCESS_EVENT_PARAM_BYTES * 2 + 1];
    bytes_to_hex_string(raw, read_size, hex, sizeof(hex));
    unsigned char data_sample[16];
    for (size_t i = 0; i < sizeof(data_sample); ++i) {
      data_sample[i] = 0;
    }
    size_t data_sample_size = 0;
    int data_sample_ok = lua_param_descriptor_is_array(descriptor) &&
                         read_process_event_array_data_sample(&header, data_sample, sizeof(data_sample), &data_sample_size);
    char data_sample_hex[sizeof(data_sample) * 2 + 1];
    data_sample_hex[0] = '\0';
    if (data_sample_ok) {
      bytes_to_hex_string(data_sample, data_sample_size, data_sample_hex, sizeof(data_sample_hex));
    }
    static Line container_line;
    line_init(&container_line);
    line_append(&container_line, "kind=");
    line_append(&container_line, lua_param_descriptor_container_kind(descriptor));
    line_append(&container_line, ",data=");
    line_append_hex(&container_line, header.data);
    line_append(&container_line, ",num=");
    line_append_signed_dec(&container_line, header.num);
    line_append(&container_line, ",max=");
    line_append_signed_dec(&container_line, header.max);
    line_append(&container_line, ",rawHex=");
    line_append(&container_line, hex);
    if (data_sample_ok) {
      line_append(&container_line, ",dataSampleHex=");
      line_append(&container_line, data_sample_hex);
    }
    copy_string(out, out_size, container_line.text);
    return 3;
  }
  if (lua_param_descriptor_is_struct(descriptor)) {
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
    if (read_process_event_param_vector(params, descriptor, &x, &y, &z)) {
      static Line vector_line;
      line_init(&vector_line);
      line_append(&vector_line, "x=");
      line_append_fixed3(&vector_line, x);
      line_append(&vector_line, ",y=");
      line_append_fixed3(&vector_line, y);
      line_append(&vector_line, ",z=");
      line_append_fixed3(&vector_line, z);
      copy_string(out, out_size, vector_line.text);
      return 1;
    }
    unsigned char raw[MAX_PROCESS_EVENT_PARAM_BYTES];
    for (size_t i = 0; i < sizeof(raw); ++i) {
      raw[i] = 0;
    }
    size_t read_size = 0;
    if (!read_process_event_param_raw_bytes(params, descriptor, raw, sizeof(raw), &read_size)) {
      return 0;
    }
    char hex[MAX_PROCESS_EVENT_PARAM_BYTES * 2 + 1];
    bytes_to_hex_string(raw, read_size, hex, sizeof(hex));
    static Line raw_line;
    line_init(&raw_line);
    line_append(&raw_line, "rawHex=");
    line_append(&raw_line, hex);
    copy_string(out, out_size, raw_line.text);
    return 2;
  }
  if (lua_param_descriptor_is_float(descriptor) || lua_param_descriptor_is_double(descriptor)) {
    double value = 0.0;
    if (!read_process_event_param_number(params, descriptor, &value)) {
      return 0;
    }
    static Line number_line;
    line_init(&number_line);
    line_append_fixed3(&number_line, value);
    copy_string(out, out_size, number_line.text);
    return 1;
  }
  long long value = 0;
  if (!read_process_event_param_scalar(params, descriptor, &value)) {
    unsigned char raw[MAX_PROCESS_EVENT_PARAM_BYTES];
    for (size_t i = 0; i < sizeof(raw); ++i) {
      raw[i] = 0;
    }
    size_t read_size = 0;
    if (!read_process_event_param_raw_bytes(params, descriptor, raw, sizeof(raw), &read_size)) {
      return 0;
    }
    char hex[MAX_PROCESS_EVENT_PARAM_BYTES * 2 + 1];
    bytes_to_hex_string(raw, read_size, hex, sizeof(hex));
    static Line raw_line;
    line_init(&raw_line);
    line_append(&raw_line, "rawHex=");
    line_append(&raw_line, hex);
    copy_string(out, out_size, raw_line.text);
    return 2;
  }
  if (lua_param_descriptor_is_bool(descriptor)) {
    copy_string(out, out_size, value ? "true" : "false");
    return 1;
  }
  if (lua_param_descriptor_is_object(descriptor)) {
    const LuaObjectHandle *object = find_lua_object_by_address((uintptr_t)value);
    if (object && object->path[0]) {
      char safe_path[MAX_LUA_OBJECT_PATH];
      safe_value(object->path, safe_path, sizeof(safe_path));
      static Line object_line;
      line_init(&object_line);
      line_append_hex(&object_line, (uintptr_t)value);
      line_append(&object_line, ":");
      line_append(&object_line, safe_path);
      copy_string(out, out_size, object_line.text);
    } else {
      static Line object_line;
      line_init(&object_line);
      line_append_hex(&object_line, (uintptr_t)value);
      copy_string(out, out_size, object_line.text);
    }
    return 1;
  }
  static Line scalar_line;
  line_init(&scalar_line);
  line_append_signed_dec(&scalar_line, value);
  copy_string(out, out_size, scalar_line.text);
  return 1;
}

static void log_process_event_live_param_samples(const ProcessEventDispatchContext *ctx) {
  if (!ctx || !ctx->params || !ctx->function) {
    return;
  }
  size_t logged = 0;
  for (size_t i = 0; i < ue_function_param_descriptor_count && logged < MAX_PROCESS_EVENT_LIVE_PARAM_LOGS; ++i) {
    const UeFunctionParamDescriptor *descriptor = &ue_function_param_descriptors[i];
    if (descriptor->function != (uintptr_t)ctx->function) {
      continue;
    }
    LuaParamDescriptorView view;
    int descriptor_ok = ue_function_param_descriptor_to_view(descriptor, &view);
    char safe_function_path[256];
    char safe_name[128];
    char safe_class[128];
    char safe_type[64];
    char value[256];
    safe_value(ctx->function_path ? ctx->function_path : "", safe_function_path, sizeof(safe_function_path));
    safe_value(descriptor->field_name[0] ? descriptor->field_name : descriptor->property_name, safe_name, sizeof(safe_name));
    safe_value(descriptor->class_name, safe_class, sizeof(safe_class));
    safe_value(descriptor_ok ? view.type : "", safe_type, sizeof(safe_type));
    int value_status = descriptor_ok ?
      format_process_event_param_sample((uintptr_t)ctx->params, &view, value, sizeof(value)) :
      0;
    if (!value_status) {
      value[0] = '\0';
    }
    static Line line;
    line_init(&line);
    line_append(&line, "event=ue-process-event-live-param status=");
    line_append(&line, value_status == 3 ? "container" : (value_status == 2 ? "raw" : (value_status == 1 ? "read" : "unreadable")));
    line_append(&line, " call=");
    line_append_signed_dec(&line, ctx->call_index);
    line_append(&line, " function=");
    line_append_hex(&line, (uintptr_t)ctx->function);
    line_append(&line, " functionPath=");
    line_append(&line, safe_function_path);
    line_append(&line, " param=");
    line_append(&line, safe_name);
    line_append(&line, " className=");
    line_append(&line, safe_class);
    line_append(&line, " type=");
    line_append(&line, safe_type);
    line_append(&line, " offset=");
    line_append_dec(&line, descriptor_ok ? view.offset : 0);
    line_append(&line, " size=");
    line_append_dec(&line, descriptor_ok ? view.size : 0);
    line_append(&line, " value=");
    line_append(&line, value);
    emit_line(&line);
    ++logged;
  }
}

static void log_process_event_live_context(const ProcessEventDispatchContext *ctx) {
  if (!ctx) {
    return;
  }
  const LuaObjectHandle *object = find_lua_object_by_address((uintptr_t)ctx->object);
  size_t param_count = count_ue_function_param_descriptors((uintptr_t)ctx->function);
  const char *function_path = ctx->function_path ? ctx->function_path : "";
  static char safe_object_path[256];
  static char safe_object_class[128];
  static char safe_function_path[256];
  safe_value(object ? object->path : "", safe_object_path, sizeof(safe_object_path));
  safe_value(object ? object->class_name : "", safe_object_class, sizeof(safe_object_class));
  safe_value(function_path, safe_function_path, sizeof(safe_function_path));
  static Line line;
  line_init(&line);
  line_append(&line, "event=ue-process-event-live-context status=");
  line_append(&line, object && function_path[0] && param_count > 0 && ctx->params ? "resolved" : "partial");
  line_append(&line, " call=");
  line_append_signed_dec(&line, ctx->call_index);
  line_append(&line, " object=");
  line_append_hex(&line, (uintptr_t)ctx->object);
  line_append(&line, " objectResolved=");
  line_append(&line, object ? "true" : "false");
  line_append(&line, " objectPath=");
  line_append(&line, safe_object_path);
  line_append(&line, " objectClass=");
  line_append(&line, safe_object_class);
  line_append(&line, " function=");
  line_append_hex(&line, (uintptr_t)ctx->function);
  line_append(&line, " functionPath=");
  line_append(&line, safe_function_path);
  line_append(&line, " functionParamDescriptors=");
  line_append_dec(&line, param_count);
  line_append(&line, " params=");
  line_append_hex(&line, (uintptr_t)ctx->params);
  line_append(&line, " paramsPresent=");
  line_append(&line, ctx->params ? "true" : "false");
  emit_line(&line);
}

static void process_event_live_hook_replacement(void *object, void *function, void *params) {
  int call_index = ++process_event_live_hook_calls;
  process_event_self_test_last_object = (uintptr_t)object;
  process_event_self_test_last_function = (uintptr_t)function;
  process_event_self_test_last_params = (uintptr_t)params;
  static Line line;
  if (process_event_live_hook_log_calls &&
      (process_event_live_hook_call_log_limit <= 0 || call_index <= process_event_live_hook_call_log_limit)) {
    line_init(&line);
    line_append(&line, "event=ue-process-event-live-hook-call status=entered call=");
    line_append_signed_dec(&line, call_index);
    line_append(&line, " object=");
    line_append_hex(&line, (uintptr_t)object);
    line_append(&line, " function=");
    line_append_hex(&line, (uintptr_t)function);
    line_append(&line, " params=");
    line_append_hex(&line, (uintptr_t)params);
    emit_line(&line);
  }
  ProcessEventDispatchContext ctx;
  for (size_t i = 0; i < sizeof(ctx); ++i) {
    ((unsigned char *)&ctx)[i] = 0;
  }
  ctx.object = object;
  ctx.function = function;
  ctx.params = params;
  if ((uintptr_t)function == process_event_self_test_function_address()) {
    ctx.function_path = "/Script/UE4SSLProbe.LiveProcessEvent:Function";
  } else {
    ctx.function_path = ue_function_path_for_address((uintptr_t)function);
  }
  ctx.call_index = call_index;
  if (process_event_live_hook_log_calls &&
      (process_event_live_hook_call_log_limit <= 0 || call_index <= process_event_live_hook_call_log_limit)) {
    log_process_event_live_context(&ctx);
    log_process_event_live_param_samples(&ctx);
  }
  run_process_event_dispatch_callbacks(HOOK_DISPATCH_PRE, &ctx);
  ProcessEventSelfTestFn original = process_event_live_hook_original;
  if (original) {
    original(object, function, params);
    ++process_event_live_hook_original_calls;
  }
  ctx.original_called = original ? 1 : 0;
  run_process_event_dispatch_callbacks(HOOK_DISPATCH_POST, &ctx);
  process_event_live_hook_last_pre_callbacks = ctx.pre_callbacks;
  process_event_live_hook_last_post_callbacks = ctx.post_callbacks;
  if (process_event_live_hook_log_calls &&
      (process_event_live_hook_call_log_limit <= 0 || call_index <= process_event_live_hook_call_log_limit)) {
    line_init(&line);
    line_append(&line, "event=ue-process-event-live-hook-call status=returned call=");
    line_append_signed_dec(&line, call_index);
    line_append(&line, " originalCalled=");
    line_append(&line, original ? "true" : "false");
    line_append(&line, " preCallbacks=");
    line_append_signed_dec(&line, ctx.pre_callbacks);
    line_append(&line, " postCallbacks=");
    line_append_signed_dec(&line, ctx.post_callbacks);
    emit_line(&line);
  }
}

static void reset_process_event_self_test_state(void) {
  process_event_self_test_original = 0;
  process_event_live_probe_original = 0;
  process_event_lua_api = 0;
  process_event_lua_state = 0;
  process_event_self_test_hook_calls = 0;
  process_event_self_test_original_calls = 0;
  process_event_live_probe_calls = 0;
  process_event_self_test_pre_status = -1;
  process_event_self_test_post_status = -1;
  process_event_self_test_last_object = 0;
  process_event_self_test_last_function = 0;
  process_event_self_test_last_params = 0;
}

static uintptr_t process_event_self_test_function_address(void) {
  uintptr_t function = (uintptr_t)&ue_self_test_function;
  if (count_ue_function_param_descriptors(function) > 0) {
    return function;
  }
  return (uintptr_t)&lua_hook_registration_name[0];
}

static int process_event_anchor_name_matches(const char *name) {
  return name && (str_equal(name, "ProcessEvent") || contains_ci(name, "ProcessEvent"));
}

static void zero_process_event_params(ProcessEventSelfTestParams *params);
static void seed_process_event_self_test_params(ProcessEventSelfTestParams *params, int value, uintptr_t target_object);

static uintptr_t configured_process_event_hook_target(const char *phase, int *self_test_target) {
  if (self_test_target) {
    *self_test_target = 0;
  }
  if (env_bool("UE4SSL_WIN_UE_PROCESS_EVENT_HOOK_SELF_TEST_TARGET", 0)) {
    if (self_test_target) {
      *self_test_target = 1;
    }
    return (uintptr_t)process_event_function_pointer(process_event_self_test_target);
  }

  uintptr_t target = env_address_auto("UE4SSL_WIN_UE_PROCESS_EVENT_HOOK_ADDRESS", 0);
  if (!target) {
    target = env_address_auto("UE4SSL_WIN_UE_PROCESS_EVENT_ADDRESS", 0);
  }
  if (target) {
    return target;
  }

  static UeAnchor anchors[MAX_UE_ANCHORS];
  for (size_t i = 0; i < sizeof(anchors); ++i) {
    ((char *)anchors)[i] = 0;
  }
  size_t anchor_count = collect_ue_anchors(anchors);
  if (ue_anchor_signatures_configured()) {
    anchor_count = collect_ue_anchor_signature_anchors(anchors, anchor_count, phase);
  }
  for (size_t i = 0; i < anchor_count; ++i) {
    if (process_event_anchor_name_matches(anchors[i].name)) {
      return anchors[i].address;
    }
  }
  return 0;
}

static void run_process_event_hook_probe(const char *phase) {
  if (!env_bool("UE4SSL_WIN_UE_PROCESS_EVENT_HOOK_PROBE", 0)) {
    return;
  }

  int self_test_target = 0;
  uintptr_t target = configured_process_event_hook_target(phase, &self_test_target);
  int install = env_bool("UE4SSL_WIN_UE_PROCESS_EVENT_HOOK_INSTALL", 0);
  int call_self_test = env_bool("UE4SSL_WIN_UE_PROCESS_EVENT_HOOK_CALL_SELF_TEST", self_test_target);
  static Line line;
  if (!target) {
    line_init(&line);
    line_append(&line, "event=ue-process-event-hook phase=");
    line_append(&line, phase);
    line_append(&line, " status=target-missing install=");
    line_append(&line, install ? "true" : "false");
    emit_line(&line);
    return;
  }

  MEMORY_BASIC_INFORMATION_WIN64 mbi;
  SIZE_T got = VirtualQuery((const void *)target, &mbi, sizeof(mbi));
  if (!got || mbi.State != MEM_COMMIT || !region_contains_range(&mbi, target, INLINE_HOOK_PATCH_LEN)) {
    line_init(&line);
    line_append(&line, "event=ue-process-event-hook phase=");
    line_append(&line, phase);
    line_append(&line, " status=target-unmapped target=");
    line_append_hex(&line, target);
    line_append(&line, " install=");
    line_append(&line, install ? "true" : "false");
    emit_line(&line);
    return;
  }

  static char module_path[1024];
  static char safe_module[1024];
  module_path[0] = '\0';
  GetModuleFileNameA((HMODULE)mbi.AllocationBase, module_path, sizeof(module_path));
  safe_value(module_path, safe_module, sizeof(safe_module));
  line_init(&line);
  line_append(&line, "event=ue-process-event-hook phase=");
  line_append(&line, phase);
  line_append(&line, " status=target-mapped target=");
  line_append_hex(&line, target);
  line_append(&line, " readable=");
  line_append(&line, readable_protect(mbi.Protect) ? "true" : "false");
  line_append(&line, " writable=");
  line_append(&line, writable_protect(mbi.Protect) ? "true" : "false");
  line_append(&line, " executable=");
  line_append(&line, executable_protect(mbi.Protect) ? "true" : "false");
  line_append(&line, " rva=");
  line_append_hex(&line, (uintptr_t)mbi.AllocationBase ? target - (uintptr_t)mbi.AllocationBase : 0);
  line_append(&line, " allocationBase=");
  line_append_hex(&line, (uintptr_t)mbi.AllocationBase);
  line_append(&line, " regionBase=");
  line_append_hex(&line, (uintptr_t)mbi.BaseAddress);
  line_append(&line, " protect=");
  line_append_hex(&line, mbi.Protect);
  line_append(&line, " type=");
  line_append_hex(&line, mbi.Type);
  line_append(&line, " module=");
  line_append(&line, safe_module);
  line_append(&line, " selfTestTarget=");
  line_append(&line, self_test_target ? "true" : "false");
  line_append(&line, " install=");
  line_append(&line, install ? "true" : "false");
  emit_line(&line);

  if (!executable_protect(mbi.Protect)) {
    line_init(&line);
    line_append(&line, "event=ue-process-event-hook phase=");
    line_append(&line, phase);
    line_append(&line, " status=target-not-executable target=");
    line_append_hex(&line, target);
    line_append(&line, " install=");
    line_append(&line, install ? "true" : "false");
    emit_line(&line);
    return;
  }

  if (!install) {
    line_init(&line);
    line_append(&line, "event=ue-process-event-hook phase=");
    line_append(&line, phase);
    line_append(&line, " status=dry-run target=");
    line_append_hex(&line, target);
    line_append(&line, " selfTestTarget=");
    line_append(&line, self_test_target ? "true" : "false");
    emit_line(&line);
    return;
  }

  reset_process_event_self_test_state();
  InlineHookPatch hook;
  zero_hook(&hook);
  hook.target = (void *)target;
  hook.replacement = process_event_function_pointer(process_event_live_probe_replacement);
  int installed = install_inline_hook(&hook, "ProcessEventHookProbe");
  int call_result = 0;
  ProcessEventSelfTestParams params;
  seed_process_event_self_test_params(&params, 61, (uintptr_t)&ue_self_test_object);
  if (installed) {
    process_event_live_probe_original = process_event_pointer_function(hook.trampoline);
    if (!process_event_self_test_entry) {
      process_event_self_test_entry = process_event_self_test_target;
    }
    if (call_self_test && self_test_target) {
      process_event_self_test_entry(&ue_self_test_object, (void *)process_event_self_test_function_address(), &params);
      call_result = params.original_result == 62 && params.touched == 1 && process_event_live_probe_calls == 1;
    }
  }
  void *trampoline = hook.trampoline;
  int restored = installed ? remove_inline_hook(&hook, "ProcessEventHookProbe") : 0;
  process_event_live_probe_original = 0;
  const char *status = installed && restored && (!call_self_test || call_result) ? "passed" : "failed";
  line_init(&line);
  line_append(&line, "event=ue-process-event-hook phase=");
  line_append(&line, phase);
  line_append(&line, " status=");
  line_append(&line, status);
  line_append(&line, " target=");
  line_append_hex(&line, target);
  line_append(&line, " installed=");
  line_append(&line, installed ? "true" : "false");
  line_append(&line, " restored=");
  line_append(&line, restored ? "true" : "false");
  line_append(&line, " selfTestTarget=");
  line_append(&line, self_test_target ? "true" : "false");
  line_append(&line, " callSelfTest=");
  line_append(&line, call_self_test ? "true" : "false");
  line_append(&line, " liveCalls=");
  line_append_signed_dec(&line, process_event_live_probe_calls);
  line_append(&line, " originalCalls=");
  line_append_signed_dec(&line, process_event_self_test_original_calls);
  line_append(&line, " paramsResult=");
  line_append_signed_dec(&line, params.original_result);
  line_append(&line, " paramsTouched=");
  line_append_signed_dec(&line, params.touched);
  line_append(&line, " trampoline=");
  line_append_hex(&line, (uintptr_t)trampoline);
  emit_line(&line);
}

static uintptr_t configured_process_event_live_hook_target(const char *phase, int *self_test_target) {
  if (self_test_target) {
    *self_test_target = 0;
  }
  if (env_bool("UE4SSL_WIN_UE_PROCESS_EVENT_LIVE_HOOK_SELF_TEST_TARGET", 0)) {
    if (self_test_target) {
      *self_test_target = 1;
    }
    return (uintptr_t)process_event_function_pointer(process_event_self_test_target);
  }

  uintptr_t target = env_address_auto("UE4SSL_WIN_UE_PROCESS_EVENT_LIVE_HOOK_ADDRESS", 0);
  if (!target) {
    target = env_address_auto("UE4SSL_WIN_UE_PROCESS_EVENT_HOOK_ADDRESS", 0);
  }
  if (!target) {
    target = env_address_auto("UE4SSL_WIN_UE_PROCESS_EVENT_ADDRESS", 0);
  }
  if (target) {
    return target;
  }

  static UeAnchor anchors[MAX_UE_ANCHORS];
  for (size_t i = 0; i < sizeof(anchors); ++i) {
    ((char *)anchors)[i] = 0;
  }
  size_t anchor_count = collect_ue_anchors(anchors);
  if (ue_anchor_signatures_configured()) {
    anchor_count = collect_ue_anchor_signature_anchors(anchors, anchor_count, phase);
  }
  for (size_t i = 0; i < anchor_count; ++i) {
    if (process_event_anchor_name_matches(anchors[i].name)) {
      return anchors[i].address;
    }
  }
  return 0;
}

static void install_process_event_live_hook(const char *phase) {
  if (!env_bool("UE4SSL_WIN_UE_PROCESS_EVENT_LIVE_HOOK", 0)) {
    return;
  }
  static Line line;
  if (process_event_live_hook_installed) {
    line_init(&line);
    line_append(&line, "event=ue-process-event-live-hook phase=");
    line_append(&line, phase);
    line_append(&line, " status=already-installed target=");
    line_append_hex(&line, (uintptr_t)process_event_live_hook.target);
    emit_line(&line);
    return;
  }

  int self_test_target = 0;
  uintptr_t target = configured_process_event_live_hook_target(phase, &self_test_target);
  int call_self_test = env_bool("UE4SSL_WIN_UE_PROCESS_EVENT_LIVE_HOOK_CALL_SELF_TEST", self_test_target);
  process_event_live_hook_log_calls = env_bool("UE4SSL_WIN_UE_PROCESS_EVENT_LIVE_HOOK_LOG_CALLS", 0);
  process_event_live_hook_call_log_limit = env_int("UE4SSL_WIN_UE_PROCESS_EVENT_LIVE_HOOK_CALL_LOG_LIMIT", 8);
  int dispatch_self_test = env_bool("UE4SSL_WIN_UE_PROCESS_EVENT_DISPATCH_SELF_TEST", 0);
  reset_process_event_dispatch_slots();
  if (dispatch_self_test) {
    int pre_registered = register_process_event_dispatch_callback(HOOK_DISPATCH_PRE, process_event_dispatch_self_test_pre, 0);
    int post_registered = register_process_event_dispatch_callback(HOOK_DISPATCH_POST, process_event_dispatch_self_test_post, 0);
    line_init(&line);
    line_append(&line, "event=ue-process-event-dispatch-self-test phase=");
    line_append(&line, phase);
    line_append(&line, " status=");
    line_append(&line, pre_registered && post_registered ? "armed" : "failed");
    line_append(&line, " preRegistered=");
    line_append(&line, pre_registered ? "true" : "false");
    line_append(&line, " postRegistered=");
    line_append(&line, post_registered ? "true" : "false");
    line_append(&line, " callbacks=");
    line_append_signed_dec(&line, (long long)process_event_dispatch_slot_count);
    emit_line(&line);
  }
  if (!target) {
    line_init(&line);
    line_append(&line, "event=ue-process-event-live-hook phase=");
    line_append(&line, phase);
    line_append(&line, " status=target-missing");
    emit_line(&line);
    return;
  }

  MEMORY_BASIC_INFORMATION_WIN64 mbi;
  SIZE_T got = VirtualQuery((const void *)target, &mbi, sizeof(mbi));
  if (!got || mbi.State != MEM_COMMIT || !region_contains_range(&mbi, target, INLINE_HOOK_PATCH_LEN)) {
    line_init(&line);
    line_append(&line, "event=ue-process-event-live-hook phase=");
    line_append(&line, phase);
    line_append(&line, " status=target-unmapped target=");
    line_append_hex(&line, target);
    emit_line(&line);
    return;
  }

  static char module_path[1024];
  static char safe_module[1024];
  module_path[0] = '\0';
  GetModuleFileNameA((HMODULE)mbi.AllocationBase, module_path, sizeof(module_path));
  safe_value(module_path, safe_module, sizeof(safe_module));
  line_init(&line);
  line_append(&line, "event=ue-process-event-live-hook phase=");
  line_append(&line, phase);
  line_append(&line, " status=target-mapped target=");
  line_append_hex(&line, target);
  line_append(&line, " readable=");
  line_append(&line, readable_protect(mbi.Protect) ? "true" : "false");
  line_append(&line, " writable=");
  line_append(&line, writable_protect(mbi.Protect) ? "true" : "false");
  line_append(&line, " executable=");
  line_append(&line, executable_protect(mbi.Protect) ? "true" : "false");
  line_append(&line, " rva=");
  line_append_hex(&line, (uintptr_t)mbi.AllocationBase ? target - (uintptr_t)mbi.AllocationBase : 0);
  line_append(&line, " allocationBase=");
  line_append_hex(&line, (uintptr_t)mbi.AllocationBase);
  line_append(&line, " regionBase=");
  line_append_hex(&line, (uintptr_t)mbi.BaseAddress);
  line_append(&line, " protect=");
  line_append_hex(&line, mbi.Protect);
  line_append(&line, " type=");
  line_append_hex(&line, mbi.Type);
  line_append(&line, " module=");
  line_append(&line, safe_module);
  line_append(&line, " selfTestTarget=");
  line_append(&line, self_test_target ? "true" : "false");
  line_append(&line, " logCalls=");
  line_append(&line, process_event_live_hook_log_calls ? "true" : "false");
  line_append(&line, " callLogLimit=");
  line_append_signed_dec(&line, process_event_live_hook_call_log_limit);
  emit_line(&line);

  if (!executable_protect(mbi.Protect)) {
    line_init(&line);
    line_append(&line, "event=ue-process-event-live-hook phase=");
    line_append(&line, phase);
    line_append(&line, " status=target-not-executable target=");
    line_append_hex(&line, target);
    emit_line(&line);
    return;
  }

  int live_lua_ready = prepare_process_event_live_lua_dispatch(phase);
  if (!live_lua_ready) {
    return;
  }

  zero_hook(&process_event_live_hook);
  process_event_live_hook.target = (void *)target;
  process_event_live_hook.replacement = process_event_function_pointer(process_event_live_hook_replacement);
  process_event_live_hook_calls = 0;
  process_event_live_hook_original_calls = 0;
  process_event_self_test_original_calls = 0;
  int installed = install_inline_hook(&process_event_live_hook, "ProcessEventLiveHook");
  ProcessEventSelfTestParams params;
  seed_process_event_self_test_params(&params, 61, (uintptr_t)&ue_self_test_object);
  int call_result = 0;
  if (installed) {
    process_event_live_hook_original = process_event_pointer_function(process_event_live_hook.trampoline);
    process_event_live_hook_installed = 1;
    if (!process_event_self_test_entry) {
      process_event_self_test_entry = process_event_self_test_target;
    }
    if (call_self_test && self_test_target) {
      process_event_self_test_entry(&ue_self_test_object, (void *)process_event_self_test_function_address(), &params);
      call_result = params.original_result == 62 && params.touched == 1 &&
                    process_event_live_hook_calls == 1 && process_event_live_hook_original_calls == 1;
      int expected_pre_callbacks = (dispatch_self_test ? 1 : 0) + (process_event_live_lua_enabled ? 1 : 0);
      int expected_post_callbacks = (dispatch_self_test ? 1 : 0) + (process_event_live_lua_enabled ? 1 : 0);
      if (expected_pre_callbacks || expected_post_callbacks) {
        call_result = call_result &&
                      process_event_live_hook_last_pre_callbacks == expected_pre_callbacks &&
                      process_event_live_hook_last_post_callbacks == expected_post_callbacks;
      }
      if (process_event_live_lua_enabled) {
        call_result = call_result &&
                      process_event_live_lua_pre_status == 0 &&
                      process_event_live_lua_post_status == 0 &&
                      lua_hook_pre_calls == 1 && lua_hook_post_calls == 1 &&
                      lua_hook_pre_result == 11 && lua_hook_post_result == 31 &&
                      lua_hook_pre_is_number && lua_hook_post_is_number;
      }
    }
  }
  const char *status = installed && (!call_self_test || call_result) ? "installed" : "failed";
  line_init(&line);
  line_append(&line, "event=ue-process-event-live-hook phase=");
  line_append(&line, phase);
  line_append(&line, " status=");
  line_append(&line, status);
  line_append(&line, " target=");
  line_append_hex(&line, target);
  line_append(&line, " selfTestTarget=");
  line_append(&line, self_test_target ? "true" : "false");
  line_append(&line, " callSelfTest=");
  line_append(&line, call_self_test ? "true" : "false");
  line_append(&line, " dispatchCallbacks=");
  line_append_signed_dec(&line, (long long)process_event_dispatch_slot_count);
  line_append(&line, " luaDispatch=");
  line_append(&line, process_event_live_lua_enabled ? "true" : "false");
  line_append(&line, " luaPreStatus=");
  line_append_signed_dec(&line, process_event_live_lua_pre_status);
  line_append(&line, " luaPostStatus=");
  line_append_signed_dec(&line, process_event_live_lua_post_status);
  line_append(&line, " luaPreCalls=");
  line_append_signed_dec(&line, lua_hook_pre_calls);
  line_append(&line, " luaPostCalls=");
  line_append_signed_dec(&line, lua_hook_post_calls);
  line_append(&line, " luaObjectHandleHits=");
  line_append_signed_dec(&line, process_event_live_lua_object_handle_hits);
  line_append(&line, " luaFunctionHandleHits=");
  line_append_signed_dec(&line, process_event_live_lua_function_handle_hits);
  line_append(&line, " luaParamsHandleHits=");
  line_append_signed_dec(&line, process_event_live_lua_params_handle_hits);
  line_append(&line, " luaParamDescriptorHits=");
  line_append_signed_dec(&line, lua_process_event_param_descriptor_hits);
  line_append(&line, " luaParamDescriptorLookupCalls=");
  line_append_signed_dec(&line, lua_process_event_param_descriptor_lookup_calls);
  line_append(&line, " luaParamDescriptorLookupHits=");
  line_append_signed_dec(&line, lua_process_event_param_descriptor_lookup_hits);
  line_append(&line, " luaFunctionParamDescriptorCalls=");
  line_append_signed_dec(&line, lua_process_event_function_param_descriptor_calls);
  line_append(&line, " luaFunctionParamDescriptorHits=");
  line_append_signed_dec(&line, lua_process_event_function_param_descriptor_hits);
  line_append(&line, " luaParamGetCalls=");
  line_append_signed_dec(&line, lua_process_event_param_get_calls);
  line_append(&line, " luaParamGetHits=");
  line_append_signed_dec(&line, lua_process_event_param_get_hits);
  line_append(&line, " luaParamSetCalls=");
  line_append_signed_dec(&line, lua_process_event_param_set_calls);
  line_append(&line, " luaParamSetHits=");
  line_append_signed_dec(&line, lua_process_event_param_set_hits);
  line_append(&line, " preCallbacks=");
  line_append_signed_dec(&line, process_event_live_hook_last_pre_callbacks);
  line_append(&line, " postCallbacks=");
  line_append_signed_dec(&line, process_event_live_hook_last_post_callbacks);
  line_append(&line, " liveCalls=");
  line_append_signed_dec(&line, process_event_live_hook_calls);
  line_append(&line, " originalCalls=");
  line_append_signed_dec(&line, process_event_live_hook_original_calls);
  line_append(&line, " paramsResult=");
  line_append_signed_dec(&line, params.original_result);
  line_append(&line, " paramsTouched=");
  line_append_signed_dec(&line, params.touched);
  line_append(&line, " trampoline=");
  line_append_hex(&line, (uintptr_t)process_event_live_hook.trampoline);
  emit_line(&line);
  if (!installed || (call_self_test && !call_result)) {
    close_process_event_live_lua_dispatch(phase);
  }
}

static void restore_process_event_live_hook(const char *phase) {
  if (!process_event_live_hook_installed) {
    return;
  }
  uintptr_t target = (uintptr_t)process_event_live_hook.target;
  int restored = remove_inline_hook(&process_event_live_hook, "ProcessEventLiveHook");
  static Line line;
  line_init(&line);
  line_append(&line, "event=ue-process-event-live-hook phase=");
  line_append(&line, phase);
  line_append(&line, " status=");
  line_append(&line, restored ? "restored" : "restore-failed");
  line_append(&line, " target=");
  line_append_hex(&line, target);
  line_append(&line, " liveCalls=");
  line_append_signed_dec(&line, process_event_live_hook_calls);
  line_append(&line, " originalCalls=");
  line_append_signed_dec(&line, process_event_live_hook_original_calls);
  emit_line(&line);
  if (restored) {
    process_event_live_hook_original = 0;
    process_event_live_hook_installed = 0;
    close_process_event_live_lua_dispatch(phase);
  }
}

static void zero_process_event_params(ProcessEventSelfTestParams *params) {
  unsigned char *bytes = (unsigned char *)params;
  for (size_t i = 0; i < sizeof(*params); ++i) {
    bytes[i] = 0;
  }
}

static void seed_process_event_self_test_params(
  ProcessEventSelfTestParams *params,
  int value,
  uintptr_t target_object
) {
  if (!params) {
    return;
  }
  zero_process_event_params(params);
  params->value = value;
  params->flag = 1;
  params->signed_byte = -7;
  params->unsigned_short = 65530U;
  params->signed_large = -1234567890123LL;
  params->float_value = 12.5f;
  params->double_value = -45.25;
  params->target_object = target_object;
  params->name_token.comparison_index = SELF_TEST_FNAME_INDEX;
  params->name_token.number = 1;
  copy_string(ue_self_test_process_event_message, sizeof(ue_self_test_process_event_message), SELF_TEST_FSTRING_MESSAGE);
  params->message.data = (uintptr_t)&ue_self_test_process_event_message[0];
  params->message.count = (int32_t)cstr_len(ue_self_test_process_event_message) + 1;
  params->message.capacity = (int32_t)sizeof(ue_self_test_process_event_message);
  params->location.x = 1.25;
  params->location.y = -2.5;
  params->location.z = 3.75;
}

static void run_lua_process_event_self_test(const char *phase) {
  if (!env_bool("UE4SSL_WIN_LUA_PROCESS_EVENT_SELF_TEST", 0)) {
    return;
  }
  reset_lua_hook_registration();
  reset_process_event_self_test_state();
  LuaApi api;
  zero_lua_api(&api);
  if (!load_lua_api(&api)) {
    static Line missing_line;
    line_init(&missing_line);
    line_append(&missing_line, "event=lua-process-event-self-test phase=");
    line_append(&missing_line, phase);
    line_append(&missing_line, " status=library-missing");
    emit_line(&missing_line);
    return;
  }

  static char script[8192];
  if (env_get("UE4SSL_WIN_LUA_PROCESS_EVENT_SELF_TEST_SCRIPT", script, sizeof(script)) == 0 || !script[0]) {
    copy_string(
      script,
      sizeof(script),
      "local G=GetParamDescriptor;local H=GetFunctionParams;local V=GetParamValue;local S=SetParamValue;RegisterHook('/Script/UE4SSLProbe.NotTarget:Function',function()return -99 end,function()return -99 end);return RegisterHook('/Script/UE4SSLProbe.SelfTest:Function',function(c)local p=c and c.Params;local d=c and c.Function and H(c.Function);local q=d and d.Properties;local v=p and G(p,'Value');local fv=q and q.Value;local g=p and G(p,'Flag');local sb=p and G(p,'SignedByte');local us=p and G(p,'UnsignedShort');local sl=p and G(p,'SignedLarge');local fl=p and G(p,'FloatValue');local db=p and G(p,'DoubleValue');local o=p and G(p,'TargetObject');local ov=o and V(p,o);local n=p and G(p,'NameToken');local fn=q and q.NameToken;local nv=fn and V(p,fn);local m=p and G(p,'Message');local fm=q and q.Message;local mv=fm and V(p,fm);local l=p and G(p,'Location');local fc=q and q.Location;local lv=fc and V(p,fc);local st=fc and fc:GetStruct();local rp=p and p.Location;local rpv=rp and rp:get();local rv=p and p.Value;local rv2=p and p.Values and p.Values.Value;if p and d and p.PropertyCount==13 and d.PropertyCount==6 and v and fv and fv.OffsetInternal==v.OffsetInternal and rv and rv:type()=='RemoteUnrealParam'and rv.IsValid and rv.Descriptor and rv.Descriptor.OffsetInternal==v.OffsetInternal and rv2 and rv2.Address==rv.Address and V(p,fv)==41 and rv:get()==41 and g and g.ClassName=='FBoolProperty'and V(p,g)==true and sb and sb.ClassName=='FInt8Property'and V(p,sb)==-7 and us and us.ClassName=='FUInt16Property'and V(p,us)==65530 and sl and sl.ClassName=='FInt64Property'and V(p,sl)==-1234567890123 and fl and fl.ClassName=='FFloatProperty'and math.abs(V(p,fl)-12.5)<0.001 and db and db.ClassName=='FDoubleProperty'and p.DoubleValue and math.abs(p.DoubleValue:get()+45.25)<0.001 and o and o.ClassName=='FObjectProperty'and ov and ov.Address==c.object and n and fn and fn.ClassName=='FNameProperty'and nv and nv.Name=='SelfTestUObjectName_0'and nv.ComparisonIndex==1234 and nv.Number==1 and m and fm and fm.ClassName=='FStrProperty'and mv=='desert-message'and l and fc and fc.ClassName=='FStructProperty'and fc.OffsetInternal==l.OffsetInternal and st and st.Name=='Vector'and st.ClassName=='UScriptStruct'and lv and lv.Kind=='FVector'and math.abs(lv.X-1.25)<0.001 and rpv and math.abs(rpv.Z-3.75)<0.001 and S(p,fn,{ComparisonIndex=1250,Number=0})and S(p,fm,'spice-message')and S(p,fc,{X=7.25,Y=8.5,Z=9.75})and V(p,fn).ComparisonIndex==1250 and V(p,fm)=='spice-message'and math.abs(V(p,fc).Z-9.75)<0.001 then return 11 end return -11 end,function(c)local p=c and c.Params;local d=c and c.Function and H(c.Function);local q=d and d.Properties;local r=p and G(p,'OriginalResult');local t=p and G(p,'Touched');local fr=q and q.OriginalResult;local ft=q and q.Touched;local wt=p and p.Touched;local wv=wt and wt:get();local wf=p and p.FloatValue;local db=p and p.Properties and p.Properties.DoubleValue;if c and c.originalCalled==true and p and d and d.PropertyCount==6 and r and t and fr and ft and fr.OffsetInternal==r.OffsetInternal and ft.OffsetInternal==t.OffsetInternal and V(p,fr)==42 and wt and wt:type()=='RemoteUnrealParam'and wv==V(p,ft)and wt:set(wv)and S(p,ft,wv)and wf and wf:set(13.75)and math.abs(wf:get()-13.75)<0.001 and db and S(p,db,-47.5)and math.abs(V(p,db)+47.5)<0.001 then return 31 end return -31 end)"
    );
  }
  LuaState *state = api.new_state();
  if (!state) {
    static Line state_line;
    line_init(&state_line);
    line_append(&state_line, "event=lua-process-event-self-test phase=");
    line_append(&state_line, phase);
    line_append(&state_line, " status=state-failed library=");
    line_append(&state_line, api.library);
    emit_line(&state_line);
    FreeLibrary(api.module);
    return;
  }
  api.open_libs(state);
  register_lua_probe_api(&api, state);
  int load_status = api.load_string(state, script);
  active_lua_api = &api;
  int call_status = load_status == 0 ? lua_call(&api, state, 0, 1, 0) : load_status;
  active_lua_api = 0;
  int is_number = 0;
  long long result = call_status == 0 ? lua_to_integer(&api, state, -1, &is_number) : 0;

  InlineHookPatch hook;
  zero_hook(&hook);
  hook.target = process_event_function_pointer(process_event_self_test_target);
  hook.replacement = process_event_function_pointer(process_event_self_test_replacement);
  int installed = 0;
  int restored = 0;
  int original_after_hook = 0;
  ProcessEventSelfTestParams params;
  ProcessEventSelfTestParams final_params;
  seed_process_event_self_test_params(&params, 41, (uintptr_t)&ue_self_test_object);
  seed_process_event_self_test_params(&final_params, 51, (uintptr_t)&ue_self_test_object);
  uintptr_t fake_function = process_event_self_test_function_address();
  void *trampoline = 0;

  if (load_status == 0 && call_status == 0 && lua_hook_registration_count > 0 &&
      lua_ref_is_valid(lua_hook_pre_ref) && lua_ref_is_valid(lua_hook_post_ref)) {
    installed = install_inline_hook(&hook, "ProcessEventSelfTest");
    process_event_self_test_original = installed ? process_event_pointer_function(hook.trampoline) : 0;
    trampoline = hook.trampoline;
    process_event_lua_api = &api;
    process_event_lua_state = state;
    if (!process_event_self_test_entry) {
      process_event_self_test_entry = process_event_self_test_target;
    }
    if (installed) {
      process_event_self_test_entry(&ue_self_test_object, (void *)fake_function, &params);
    }
    process_event_lua_api = 0;
    process_event_lua_state = 0;
    original_after_hook = process_event_self_test_original_calls;
    restored = remove_inline_hook(&hook, "ProcessEventSelfTest");
    process_event_self_test_original = 0;
    process_event_self_test_entry(&ue_self_test_object, (void *)fake_function, &final_params);
  }

  static char safe_hook[256];
  safe_value(lua_hook_registration_name, safe_hook, sizeof(safe_hook));
  const char *status = load_status == 0 && call_status == 0 && is_number && result == 4 &&
                       lua_hook_registration_count > 0 &&
                       installed && restored &&
                       process_event_self_test_hook_calls == 1 &&
                       original_after_hook == 1 &&
                       process_event_self_test_original_calls == 2 &&
                       params.original_result == 42 && params.touched == 1 &&
                       final_params.original_result == 52 && final_params.touched == 1 &&
                       process_event_self_test_pre_status == 0 &&
                       process_event_self_test_post_status == 0 &&
                       lua_hook_pre_calls == 1 && lua_hook_post_calls == 1 &&
                       lua_hook_pre_is_number && lua_hook_post_is_number &&
                       lua_hook_pre_result == 11 && lua_hook_post_result == 31 ? "passed" : "failed";

  static Line line;
  line_init(&line);
  line_append(&line, "event=lua-process-event-self-test phase=");
  line_append(&line, phase);
  line_append(&line, " status=");
  line_append(&line, status);
  line_append(&line, " library=");
  line_append(&line, api.library);
  line_append(&line, " loadStatus=");
  line_append_signed_dec(&line, load_status);
  line_append(&line, " callStatus=");
  line_append_signed_dec(&line, call_status);
  line_append(&line, " result=");
  line_append_signed_dec(&line, result);
  line_append(&line, " isNumber=");
  line_append(&line, is_number ? "true" : "false");
  line_append(&line, " hooks=");
  line_append_signed_dec(&line, lua_hook_registration_count);
  line_append(&line, " hook=");
  line_append(&line, safe_hook);
  line_append(&line, " installed=");
  line_append(&line, installed ? "true" : "false");
  line_append(&line, " restored=");
  line_append(&line, restored ? "true" : "false");
  line_append(&line, " hookCalls=");
  line_append_signed_dec(&line, process_event_self_test_hook_calls);
  line_append(&line, " originalCalls=");
  line_append_signed_dec(&line, process_event_self_test_original_calls);
  line_append(&line, " originalAfterHook=");
  line_append_signed_dec(&line, original_after_hook);
  line_append(&line, " preStatus=");
  line_append_signed_dec(&line, process_event_self_test_pre_status);
  line_append(&line, " postStatus=");
  line_append_signed_dec(&line, process_event_self_test_post_status);
  line_append(&line, " preCalls=");
  line_append_signed_dec(&line, lua_hook_pre_calls);
  line_append(&line, " postCalls=");
  line_append_signed_dec(&line, lua_hook_post_calls);
  line_append(&line, " preResult=");
  line_append_signed_dec(&line, lua_hook_pre_result);
  line_append(&line, " postResult=");
  line_append_signed_dec(&line, lua_hook_post_result);
  line_append(&line, " preIsNumber=");
  line_append(&line, lua_hook_pre_is_number ? "true" : "false");
  line_append(&line, " postIsNumber=");
  line_append(&line, lua_hook_post_is_number ? "true" : "false");
  line_append(&line, " paramDescriptorHits=");
  line_append_signed_dec(&line, lua_process_event_param_descriptor_hits);
  line_append(&line, " paramDescriptorLookupCalls=");
  line_append_signed_dec(&line, lua_process_event_param_descriptor_lookup_calls);
  line_append(&line, " paramDescriptorLookupHits=");
  line_append_signed_dec(&line, lua_process_event_param_descriptor_lookup_hits);
  line_append(&line, " functionParamDescriptorCalls=");
  line_append_signed_dec(&line, lua_process_event_function_param_descriptor_calls);
  line_append(&line, " functionParamDescriptorHits=");
  line_append_signed_dec(&line, lua_process_event_function_param_descriptor_hits);
  line_append(&line, " paramGetCalls=");
  line_append_signed_dec(&line, lua_process_event_param_get_calls);
  line_append(&line, " paramGetHits=");
  line_append_signed_dec(&line, lua_process_event_param_get_hits);
  line_append(&line, " paramSetCalls=");
  line_append_signed_dec(&line, lua_process_event_param_set_calls);
  line_append(&line, " paramSetHits=");
  line_append_signed_dec(&line, lua_process_event_param_set_hits);
  line_append(&line, " paramsResult=");
  line_append_signed_dec(&line, params.original_result);
  line_append(&line, " paramsTouched=");
  line_append_signed_dec(&line, params.touched);
  line_append(&line, " finalResult=");
  line_append_signed_dec(&line, final_params.original_result);
  line_append(&line, " finalTouched=");
  line_append_signed_dec(&line, final_params.touched);
  line_append(&line, " object=");
  line_append_hex(&line, process_event_self_test_last_object);
  line_append(&line, " function=");
  line_append_hex(&line, process_event_self_test_last_function);
  line_append(&line, " params=");
  line_append_hex(&line, process_event_self_test_last_params);
  line_append(&line, " trampoline=");
  line_append_hex(&line, (uintptr_t)trampoline);
  line_append(&line, " scriptBytes=");
  line_append_dec(&line, cstr_len(script));
  emit_line(&line);

  lua_unref_hook_registrations(&api, state);
  lua_unref_notify_on_new_object_registrations(&api, state);
  api.close(state);
  FreeLibrary(api.module);
}

static size_t ue_layout_slots(void) {
  size_t slots = env_size("UE4SSL_WIN_UE_LAYOUT_SLOTS", DEFAULT_UE_LAYOUT_SLOTS);
  if (slots > MAX_UE_LAYOUT_SLOTS) {
    slots = MAX_UE_LAYOUT_SLOTS;
  }
  return slots;
}

static void log_ue_pointer_probe(
  const UeAnchor *anchor,
  const char *safe_name,
  const MEMORY_BASIC_INFORMATION_WIN64 *anchor_mbi,
  const MEMORY_BASIC_INFORMATION_WIN64 *target_mbi,
  uintptr_t value
) {
  static Line line;
  line_init(&line);
  line_append(&line, "event=ue-pointer name=");
  line_append(&line, safe_name);
  if (!anchor_mbi || anchor_mbi->State != MEM_COMMIT) {
    line_append(&line, " status=anchor-unmapped anchor=");
    line_append_hex(&line, anchor->address);
    emit_line(&line);
    return;
  }
  if (!readable_protect(anchor_mbi->Protect)) {
    line_append(&line, " status=anchor-not-readable anchor=");
    line_append_hex(&line, anchor->address);
    line_append(&line, " protect=");
    line_append_hex(&line, anchor_mbi->Protect);
    emit_line(&line);
    return;
  }
  if (!region_contains_range(anchor_mbi, anchor->address, sizeof(uintptr_t))) {
    line_append(&line, " status=anchor-truncated anchor=");
    line_append_hex(&line, anchor->address);
    line_append(&line, " protect=");
    line_append_hex(&line, anchor_mbi->Protect);
    emit_line(&line);
    return;
  }
  if (value == 0) {
    line_append(&line, " status=null anchor=");
    line_append_hex(&line, anchor->address);
    line_append(&line, " value=0x0");
    emit_line(&line);
    return;
  }
  if (!target_mbi || target_mbi->State != MEM_COMMIT) {
    line_append(&line, " status=target-unmapped anchor=");
    line_append_hex(&line, anchor->address);
    line_append(&line, " value=");
    line_append_hex(&line, value);
    emit_line(&line);
    return;
  }

  static char module_path[1024];
  static char safe_module[1024];
  module_path[0] = '\0';
  GetModuleFileNameA((HMODULE)target_mbi->AllocationBase, module_path, sizeof(module_path));
  safe_value(module_path, safe_module, sizeof(safe_module));

  line_append(&line, " status=target-mapped anchor=");
  line_append_hex(&line, anchor->address);
  line_append(&line, " value=");
  line_append_hex(&line, value);
  line_append(&line, " readable=");
  line_append(&line, readable_protect(target_mbi->Protect) ? "true" : "false");
  line_append(&line, " writable=");
  line_append(&line, writable_protect(target_mbi->Protect) ? "true" : "false");
  line_append(&line, " executable=");
  line_append(&line, executable_protect(target_mbi->Protect) ? "true" : "false");
  line_append(&line, " rva=");
  line_append_hex(&line, (uintptr_t)target_mbi->AllocationBase ? value - (uintptr_t)target_mbi->AllocationBase : 0);
  line_append(&line, " allocationBase=");
  line_append_hex(&line, (uintptr_t)target_mbi->AllocationBase);
  line_append(&line, " regionBase=");
  line_append_hex(&line, (uintptr_t)target_mbi->BaseAddress);
  line_append(&line, " protect=");
  line_append_hex(&line, target_mbi->Protect);
  line_append(&line, " type=");
  line_append_hex(&line, target_mbi->Type);
  line_append(&line, " module=");
  line_append(&line, safe_module);
  emit_line(&line);
}

static void log_ue_layout_probe(
  const UeAnchor *anchor,
  const char *safe_name,
  const MEMORY_BASIC_INFORMATION_WIN64 *target_mbi,
  uintptr_t target,
  size_t slots
) {
  static Line line;
  if (!target_mbi || target_mbi->State != MEM_COMMIT) {
    line_init(&line);
    line_append(&line, "event=ue-layout name=");
    line_append(&line, safe_name);
    line_append(&line, " status=target-unmapped target=");
    line_append_hex(&line, target);
    emit_line(&line);
    return;
  }
  if (!readable_protect(target_mbi->Protect)) {
    line_init(&line);
    line_append(&line, "event=ue-layout name=");
    line_append(&line, safe_name);
    line_append(&line, " status=target-not-readable target=");
    line_append_hex(&line, target);
    line_append(&line, " protect=");
    line_append_hex(&line, target_mbi->Protect);
    emit_line(&line);
    return;
  }

  static char module_path[1024];
  static char safe_module[1024];
  module_path[0] = '\0';
  GetModuleFileNameA((HMODULE)target_mbi->AllocationBase, module_path, sizeof(module_path));
  safe_value(module_path, safe_module, sizeof(safe_module));

  line_init(&line);
  line_append(&line, "event=ue-layout name=");
  line_append(&line, safe_name);
  line_append(&line, " status=target-readable anchor=");
  line_append_hex(&line, anchor->address);
  line_append(&line, " target=");
  line_append_hex(&line, target);
  line_append(&line, " slots=");
  line_append_dec(&line, slots);
  line_append(&line, " protect=");
  line_append_hex(&line, target_mbi->Protect);
  line_append(&line, " module=");
  line_append(&line, safe_module);
  emit_line(&line);

  for (size_t slot = 0; slot < slots; ++slot) {
    uintptr_t slot_addr = target + slot * sizeof(uintptr_t);
    if (!region_contains_range(target_mbi, slot_addr, sizeof(uintptr_t))) {
      line_init(&line);
      line_append(&line, "event=ue-layout-slot name=");
      line_append(&line, safe_name);
      line_append(&line, " status=slot-truncated target=");
      line_append_hex(&line, target);
      line_append(&line, " offset=");
      line_append_hex(&line, slot * sizeof(uintptr_t));
      emit_line(&line);
      break;
    }

    uintptr_t value = 0;
    read_pointer_at(target_mbi, slot_addr, &value);
    line_init(&line);
    line_append(&line, "event=ue-layout-slot name=");
    line_append(&line, safe_name);
    line_append(&line, " target=");
    line_append_hex(&line, target);
    line_append(&line, " offset=");
    line_append_hex(&line, slot * sizeof(uintptr_t));
    line_append(&line, " value=");
    line_append_hex(&line, value);
    if (value == 0) {
      line_append(&line, " status=null");
      emit_line(&line);
      continue;
    }

    MEMORY_BASIC_INFORMATION_WIN64 slot_mbi;
    for (size_t clear = 0; clear < sizeof(slot_mbi); ++clear) {
      ((char *)&slot_mbi)[clear] = 0;
    }
    SIZE_T got = VirtualQuery((const void *)value, &slot_mbi, sizeof(slot_mbi));
    if (!got || slot_mbi.State != MEM_COMMIT) {
      line_append(&line, " status=target-unmapped");
      emit_line(&line);
      continue;
    }
    line_append(&line, " status=target-mapped readable=");
    line_append(&line, readable_protect(slot_mbi.Protect) ? "true" : "false");
    line_append(&line, " writable=");
    line_append(&line, writable_protect(slot_mbi.Protect) ? "true" : "false");
    line_append(&line, " executable=");
    line_append(&line, executable_protect(slot_mbi.Protect) ? "true" : "false");
    line_append(&line, " protect=");
    line_append_hex(&line, slot_mbi.Protect);
    emit_line(&line);
  }
}

static void log_ue_reflection_slot(
  const char *safe_name,
  const char *slot_name,
  const MEMORY_BASIC_INFORMATION_WIN64 *class_mbi,
  uintptr_t class_address,
  size_t offset
) {
  static Line line;
  uintptr_t slot_addr = class_address + offset;
  if (!region_contains_range(class_mbi, slot_addr, sizeof(uintptr_t))) {
    line_init(&line);
    line_append(&line, "event=ue-reflection-slot name=");
    line_append(&line, safe_name);
    line_append(&line, " slot=");
    line_append(&line, slot_name);
    line_append(&line, " status=slot-truncated class=");
    line_append_hex(&line, class_address);
    line_append(&line, " offset=");
    line_append_hex(&line, offset);
    emit_line(&line);
    return;
  }
  uintptr_t value = 0;
  read_pointer_at(class_mbi, slot_addr, &value);
  line_init(&line);
  line_append(&line, "event=ue-reflection-slot name=");
  line_append(&line, safe_name);
  line_append(&line, " slot=");
  line_append(&line, slot_name);
  line_append(&line, " class=");
  line_append_hex(&line, class_address);
  line_append(&line, " offset=");
  line_append_hex(&line, offset);
  line_append(&line, " value=");
  line_append_hex(&line, value);
  if (value == 0) {
    line_append(&line, " status=null");
    emit_line(&line);
    return;
  }
  MEMORY_BASIC_INFORMATION_WIN64 value_mbi;
  for (size_t clear = 0; clear < sizeof(value_mbi); ++clear) {
    ((char *)&value_mbi)[clear] = 0;
  }
  SIZE_T got = VirtualQuery((const void *)value, &value_mbi, sizeof(value_mbi));
  if (!got || value_mbi.State != MEM_COMMIT) {
    line_append(&line, " status=target-unmapped");
    emit_line(&line);
    return;
  }
  line_append(&line, " status=target-mapped readable=");
  line_append(&line, readable_protect(value_mbi.Protect) ? "true" : "false");
  line_append(&line, " writable=");
  line_append(&line, writable_protect(value_mbi.Protect) ? "true" : "false");
  line_append(&line, " executable=");
  line_append(&line, executable_protect(value_mbi.Protect) ? "true" : "false");
  line_append(&line, " protect=");
  line_append_hex(&line, value_mbi.Protect);
  emit_line(&line);
}

static int is_ue_reflection_property_chain(const char *chain_name) {
  return str_equal(chain_name, "childProperties") || str_equal(chain_name, "propertyLink");
}

static void log_ue_reflection_value_detail(
  const char *safe_name,
  const char *chain_name,
  size_t index,
  const char *field_name,
  uintptr_t object,
  const MEMORY_BASIC_INFORMATION_WIN64 *object_mbi,
  int32_t array_dim,
  int32_t element_size,
  int32_t offset_internal,
  const UeReflectionOptions *options
) {
  static Line line;
  if (array_dim <= 0 || element_size <= 0 || offset_internal < 0) {
    line_init(&line);
    line_append(&line, "event=ue-reflection-value name=");
    line_append(&line, safe_name);
    line_append(&line, " chain=");
    line_append(&line, chain_name);
    line_append(&line, " index=");
    line_append_dec(&line, index);
    line_append(&line, " status=descriptor-invalid object=");
    line_append_hex(&line, object);
    line_append(&line, " arrayDim=");
    line_append_signed_dec(&line, array_dim);
    line_append(&line, " elementSize=");
    line_append_signed_dec(&line, element_size);
    line_append(&line, " offsetInternal=");
    line_append_signed_dec(&line, offset_internal);
    emit_line(&line);
    return;
  }
  if (!object_mbi || object_mbi->State != MEM_COMMIT || !readable_protect(object_mbi->Protect)) {
    line_init(&line);
    line_append(&line, "event=ue-reflection-value name=");
    line_append(&line, safe_name);
    line_append(&line, " chain=");
    line_append(&line, chain_name);
    line_append(&line, " index=");
    line_append_dec(&line, index);
    line_append(&line, " status=object-unreadable object=");
    line_append_hex(&line, object);
    line_append(&line, " offsetInternal=");
    line_append_signed_dec(&line, offset_internal);
    emit_line(&line);
    return;
  }

  uint64_t requested = (uint64_t)(uint32_t)array_dim * (uint64_t)(uint32_t)element_size;
  size_t bytes_to_read = requested > options->value_max_bytes ? options->value_max_bytes : (size_t)requested;
  uintptr_t value_address = object + (uintptr_t)(uint32_t)offset_internal;
  if (!region_contains_range(object_mbi, value_address, bytes_to_read)) {
    line_init(&line);
    line_append(&line, "event=ue-reflection-value name=");
    line_append(&line, safe_name);
    line_append(&line, " chain=");
    line_append(&line, chain_name);
    line_append(&line, " index=");
    line_append_dec(&line, index);
    line_append(&line, " status=value-truncated object=");
    line_append_hex(&line, object);
    line_append(&line, " address=");
    line_append_hex(&line, value_address);
    line_append(&line, " offsetInternal=");
    line_append_signed_dec(&line, offset_internal);
    line_append(&line, " requestedBytes=");
    line_append_dec(&line, requested);
    line_append(&line, " readBytes=");
    line_append_dec(&line, bytes_to_read);
    emit_line(&line);
    return;
  }

  unsigned char raw[MAX_UE_REFLECTION_VALUE_BYTES];
  const unsigned char *value_bytes = (const unsigned char *)value_address;
  for (size_t i = 0; i < bytes_to_read; ++i) {
    raw[i] = value_bytes[i];
  }
  static char raw_hex[MAX_UE_REFLECTION_VALUE_BYTES * 2 + 1];
  static const char hex[] = "0123456789abcdef";
  for (size_t i = 0; i < bytes_to_read; ++i) {
    raw_hex[i * 2] = hex[(raw[i] >> 4) & 0xfU];
    raw_hex[i * 2 + 1] = hex[raw[i] & 0xfU];
  }
  raw_hex[bytes_to_read * 2] = '\0';
  uint64_t raw_le = 0;
  size_t scalar_bytes = bytes_to_read < sizeof(raw_le) ? bytes_to_read : sizeof(raw_le);
  for (size_t i = 0; i < scalar_bytes; ++i) {
    raw_le |= (uint64_t)raw[i] << (i * 8U);
  }
  add_ue_reflection_property_candidate(
    object,
    chain_name,
    index,
    field_name,
    array_dim,
    element_size,
    offset_internal,
    bytes_to_read,
    raw_le
  );

  line_init(&line);
  line_append(&line, "event=ue-reflection-value name=");
  line_append(&line, safe_name);
  line_append(&line, " chain=");
  line_append(&line, chain_name);
  line_append(&line, " index=");
  line_append_dec(&line, index);
  line_append(&line, " fieldName=");
  line_append(&line, field_name && field_name[0] ? field_name : "");
  line_append(&line, " status=read object=");
  line_append_hex(&line, object);
  line_append(&line, " address=");
  line_append_hex(&line, value_address);
  line_append(&line, " offsetInternal=");
  line_append_signed_dec(&line, offset_internal);
  line_append(&line, " elementSize=");
  line_append_signed_dec(&line, element_size);
  line_append(&line, " arrayDim=");
  line_append_signed_dec(&line, array_dim);
  line_append(&line, " requestedBytes=");
  line_append_dec(&line, requested);
  line_append(&line, " readBytes=");
  line_append_dec(&line, bytes_to_read);
  line_append(&line, " raw=");
  line_append(&line, raw_hex);
  line_append(&line, " rawLe=");
  line_append_hex(&line, raw_le);
  line_append(&line, " truncated=");
  line_append(&line, requested > bytes_to_read ? "true" : "false");
  emit_line(&line);
}

static void log_ue_reflection_property_detail(
  const char *safe_name,
  const char *chain_name,
  size_t index,
  uintptr_t field,
  const MEMORY_BASIC_INFORMATION_WIN64 *field_mbi,
  const UeReflectionOptions *options,
  uintptr_t object,
  const MEMORY_BASIC_INFORMATION_WIN64 *object_mbi,
  int value_probe,
  const char *field_name
) {
  static Line line;
  int32_t array_dim = 0;
  int32_t element_size = 0;
  uint64_t property_flags = 0;
  int32_t offset_internal = 0;
  int array_dim_readable = read_i32_at(field_mbi, field + options->property_array_dim_offset, &array_dim);
  int element_size_readable = read_i32_at(field_mbi, field + options->property_element_size_offset, &element_size);
  int property_flags_readable = read_u64_at(field_mbi, field + options->property_flags_offset, &property_flags);
  int offset_internal_readable = read_i32_at(field_mbi, field + options->property_offset_internal_offset, &offset_internal);

  line_init(&line);
  line_append(&line, "event=ue-reflection-property name=");
  line_append(&line, safe_name);
  line_append(&line, " chain=");
  line_append(&line, chain_name);
  line_append(&line, " index=");
  line_append_dec(&line, index);
  line_append(&line, " status=candidate field=");
  line_append_hex(&line, field);
  line_append(&line, " arrayDim=");
  line_append_signed_dec(&line, array_dim);
  line_append(&line, " elementSize=");
  line_append_signed_dec(&line, element_size);
  line_append(&line, " propertyFlags=");
  line_append_hex(&line, property_flags);
  line_append(&line, " offsetInternal=");
  line_append_signed_dec(&line, offset_internal);
  line_append(&line, " arrayDimReadable=");
  line_append(&line, array_dim_readable ? "true" : "false");
  line_append(&line, " elementSizeReadable=");
  line_append(&line, element_size_readable ? "true" : "false");
  line_append(&line, " propertyFlagsReadable=");
  line_append(&line, property_flags_readable ? "true" : "false");
  line_append(&line, " offsetInternalReadable=");
  line_append(&line, offset_internal_readable ? "true" : "false");
  line_append(&line, " arrayDimOffset=");
  line_append_hex(&line, options->property_array_dim_offset);
  line_append(&line, " elementSizeOffset=");
  line_append_hex(&line, options->property_element_size_offset);
  line_append(&line, " propertyFlagsOffset=");
  line_append_hex(&line, options->property_flags_offset);
  line_append(&line, " offsetInternalOffset=");
  line_append_hex(&line, options->property_offset_internal_offset);
  emit_line(&line);
  if (value_probe) {
    if (array_dim_readable && element_size_readable && offset_internal_readable) {
      log_ue_reflection_value_detail(
        safe_name,
        chain_name,
        index,
        field_name,
        object,
        object_mbi,
        array_dim,
        element_size,
        offset_internal,
        options
      );
    } else {
      line_init(&line);
      line_append(&line, "event=ue-reflection-value name=");
      line_append(&line, safe_name);
      line_append(&line, " chain=");
      line_append(&line, chain_name);
      line_append(&line, " index=");
      line_append_dec(&line, index);
      line_append(&line, " status=descriptor-unreadable object=");
      line_append_hex(&line, object);
      line_append(&line, " field=");
      line_append_hex(&line, field);
      emit_line(&line);
    }
  }
}

static void log_ue_function_param_container_children(
  const char *safe_name,
  size_t function_index,
  uintptr_t function,
  const char *param_chain_name,
  size_t param_index,
  uintptr_t param,
  const MEMORY_BASIC_INFORMATION_WIN64 *param_mbi,
  const char *container_class_name,
  const UeReflectionOptions *options,
  const UeFNameResolver *fname_resolver,
  const UeFNameOptions *fname_options
) {
  if (!param_mbi || !container_class_name || !container_class_name[0] || !options ||
      (!contains_ci(container_class_name, "ArrayProperty") &&
       !contains_ci(container_class_name, "SetProperty") &&
       !contains_ci(container_class_name, "MapProperty"))) {
    return;
  }
  size_t found = 0;
  for (size_t offset = options->container_child_scan_start;
       offset + sizeof(uintptr_t) <= options->container_child_scan_end && found < 2;
       offset += sizeof(uintptr_t)) {
    if (!region_contains_range(param_mbi, param + offset, sizeof(uintptr_t))) {
      continue;
    }
    uintptr_t child = 0;
    read_pointer_at(param_mbi, param + offset, &child);
    if (!child || child == param) {
      continue;
    }
    MEMORY_BASIC_INFORMATION_WIN64 child_mbi;
    for (size_t clear = 0; clear < sizeof(child_mbi); ++clear) {
      ((char *)&child_mbi)[clear] = 0;
    }
    SIZE_T child_got = VirtualQuery((const void *)child, &child_mbi, sizeof(child_mbi));
    if (!child_got || child_mbi.State != MEM_COMMIT || !readable_protect(child_mbi.Protect) ||
        !region_contains_range(&child_mbi, child, 0x20)) {
      continue;
    }
    uintptr_t child_class = 0;
    uint32_t child_name_comparison_index = 0;
    uint32_t child_name_number = 0;
    int32_t child_array_dim = 0;
    int32_t child_element_size = 0;
    uint64_t child_property_flags = 0;
    int32_t child_offset_internal = -1;
    read_pointer_at(&child_mbi, child + 0x10, &child_class);
    read_u32_at(&child_mbi, child + 0x18, &child_name_comparison_index);
    read_u32_at(&child_mbi, child + 0x1c, &child_name_number);
    if (region_contains_range(&child_mbi, child + 0x48, sizeof(uint64_t))) {
      read_i32_at(&child_mbi, child + options->property_array_dim_offset, &child_array_dim);
      read_i32_at(&child_mbi, child + options->property_element_size_offset, &child_element_size);
      read_u64_at(&child_mbi, child + options->property_flags_offset, &child_property_flags);
      read_i32_at(&child_mbi, child + options->property_offset_internal_offset, &child_offset_internal);
    }
    MEMORY_BASIC_INFORMATION_WIN64 child_class_mbi;
    for (size_t clear = 0; clear < sizeof(child_class_mbi); ++clear) {
      ((char *)&child_class_mbi)[clear] = 0;
    }
    SIZE_T child_class_got = child_class ? VirtualQuery((const void *)child_class, &child_class_mbi, sizeof(child_class_mbi)) : 0;
    char child_name[MAX_LUA_OBJECT_NAME];
    char child_class_name[MAX_LUA_CLASS_NAME];
    child_name[0] = '\0';
    child_class_name[0] = '\0';
    if (fname_options && fname_resolver && fname_resolver->available) {
      char decoded[MAX_LUA_OBJECT_NAME];
      uintptr_t entry = 0;
      uint32_t block = 0;
      uint32_t name_offset = 0;
      int is_wide = 0;
      const char *decode_status = "unknown";
      if (decode_ue_fname(fname_resolver, fname_options, child_name_comparison_index, child_name_number,
            decoded, sizeof(decoded), &entry, &block, &name_offset, &is_wide, &decode_status)) {
        safe_value(decoded, child_name, sizeof(child_name));
      }
      if (child_class_got && child_class_mbi.State == MEM_COMMIT && readable_protect(child_class_mbi.Protect) &&
          region_contains_range(&child_class_mbi, child_class, 0x20)) {
        uint32_t class_name_comparison_index = 0;
        uint32_t class_name_number = 0;
        read_u32_at(&child_class_mbi, child_class + 0x18, &class_name_comparison_index);
        read_u32_at(&child_class_mbi, child_class + 0x1c, &class_name_number);
        if (decode_ue_fname(fname_resolver, fname_options, class_name_comparison_index, class_name_number,
              decoded, sizeof(decoded), &entry, &block, &name_offset, &is_wide, &decode_status)) {
          safe_value(decoded, child_class_name, sizeof(child_class_name));
        }
      }
    }
    const char *role = "child";
    if (contains_ci(container_class_name, "ArrayProperty")) {
      role = "inner";
    } else if (contains_ci(container_class_name, "SetProperty")) {
      role = "element";
    } else if (contains_ci(container_class_name, "MapProperty")) {
      role = found == 0 ? "key" : "value";
    }
    static Line line;
    line_init(&line);
    line_append(&line, "event=ue-function-param-container-child name=");
    line_append(&line, safe_name);
    line_append(&line, " functionIndex=");
    line_append_dec(&line, function_index);
    line_append(&line, " chain=");
    line_append(&line, param_chain_name);
    line_append(&line, " index=");
    line_append_dec(&line, param_index);
    line_append(&line, " status=candidate field=");
    line_append_hex(&line, param);
    line_append(&line, " containerClassName=");
    line_append(&line, container_class_name);
    line_append(&line, " role=");
    line_append(&line, role);
    line_append(&line, " child=");
    line_append_hex(&line, child);
    line_append(&line, " childOffset=");
    line_append_hex(&line, offset);
    line_append(&line, " childClass=");
    line_append_hex(&line, child_class);
    line_append(&line, " childClassMapped=");
    line_append(&line, child_class_got && child_class_mbi.State == MEM_COMMIT ? "true" : "false");
    line_append(&line, " childClassName=");
    line_append(&line, child_class_name);
    line_append(&line, " childNameComparisonIndex=");
    line_append_dec(&line, child_name_comparison_index);
    line_append(&line, " childNameNumber=");
    line_append_dec(&line, child_name_number);
    line_append(&line, " childName=");
    line_append(&line, child_name);
    emit_line(&line);
    set_ue_function_param_container_child_descriptor(
      function,
      param,
      role,
      child,
      child_class,
      offset,
      child_name,
      child_class_name,
      child_array_dim,
      child_element_size,
      child_property_flags,
      child_offset_internal
    );
    ++found;
  }
}

static void log_ue_function_param_chain(
  const char *safe_name,
  size_t function_index,
  const char *function_name,
  uintptr_t function,
  const MEMORY_BASIC_INFORMATION_WIN64 *function_mbi,
  const char *param_chain_name,
  size_t root_offset,
  const UeReflectionOptions *options,
  const UeFNameResolver *fname_resolver,
  const UeFNameOptions *fname_options
) {
  static Line line;
  static char function_identity_name[MAX_LUA_OBJECT_NAME];
  static char function_identity_path[MAX_LUA_OBJECT_PATH];
  make_ue_function_identity(
    function_identity_name,
    sizeof(function_identity_name),
    function_identity_path,
    sizeof(function_identity_path),
    safe_name,
    function_index,
    function_name
  );
  uint32_t function_flags = 0;
  int function_flags_readable = read_u32_at(
    function_mbi,
    function + options->function_flags_offset,
    &function_flags
  );
  uintptr_t root_slot = function + root_offset;
  if (!region_contains_range(function_mbi, root_slot, sizeof(uintptr_t))) {
    line_init(&line);
    line_append(&line, "event=ue-function-param-root name=");
    line_append(&line, safe_name);
    line_append(&line, " functionIndex=");
    line_append_dec(&line, function_index);
    line_append(&line, " chain=");
    line_append(&line, param_chain_name);
    line_append(&line, " status=slot-truncated function=");
    line_append_hex(&line, function);
    line_append(&line, " offset=");
    line_append_hex(&line, root_offset);
    emit_line(&line);
    return;
  }

  uintptr_t param = 0;
  read_pointer_at(function_mbi, root_slot, &param);
  if (param == 0) {
    line_init(&line);
    line_append(&line, "event=ue-function-param-root name=");
    line_append(&line, safe_name);
    line_append(&line, " functionIndex=");
    line_append_dec(&line, function_index);
    line_append(&line, " chain=");
    line_append(&line, param_chain_name);
    line_append(&line, " status=null-root function=");
    line_append_hex(&line, function);
    line_append(&line, " offset=");
    line_append_hex(&line, root_offset);
    emit_line(&line);
    return;
  }

  line_init(&line);
  line_append(&line, "event=ue-function-param-root name=");
  line_append(&line, safe_name);
  line_append(&line, " functionIndex=");
  line_append_dec(&line, function_index);
  line_append(&line, " chain=");
  line_append(&line, param_chain_name);
  line_append(&line, " status=root function=");
  line_append_hex(&line, function);
  line_append(&line, " offset=");
  line_append_hex(&line, root_offset);
  line_append(&line, " root=");
  line_append_hex(&line, param);
  line_append(&line, " functionFlags=");
  line_append_hex(&line, function_flags);
  line_append(&line, " functionFlagsReadable=");
  line_append(&line, function_flags_readable ? "true" : "false");
  line_append(&line, " functionFlagsOffset=");
  line_append_hex(&line, options->function_flags_offset);
  emit_line(&line);

  for (size_t index = 0; index < options->max_fields && param != 0; ++index) {
    MEMORY_BASIC_INFORMATION_WIN64 param_mbi;
    for (size_t clear = 0; clear < sizeof(param_mbi); ++clear) {
      ((char *)&param_mbi)[clear] = 0;
    }
    SIZE_T param_got = VirtualQuery((const void *)param, &param_mbi, sizeof(param_mbi));
    if (!param_got || param_mbi.State != MEM_COMMIT) {
      line_init(&line);
      line_append(&line, "event=ue-function-param name=");
      line_append(&line, safe_name);
      line_append(&line, " functionIndex=");
      line_append_dec(&line, function_index);
      line_append(&line, " chain=");
      line_append(&line, param_chain_name);
      line_append(&line, " index=");
      line_append_dec(&line, index);
      line_append(&line, " status=field-unmapped function=");
      line_append_hex(&line, function);
      line_append(&line, " field=");
      line_append_hex(&line, param);
      emit_line(&line);
      return;
    }
    if (!readable_protect(param_mbi.Protect)) {
      line_init(&line);
      line_append(&line, "event=ue-function-param name=");
      line_append(&line, safe_name);
      line_append(&line, " functionIndex=");
      line_append_dec(&line, function_index);
      line_append(&line, " chain=");
      line_append(&line, param_chain_name);
      line_append(&line, " index=");
      line_append_dec(&line, index);
      line_append(&line, " status=field-not-readable function=");
      line_append_hex(&line, function);
      line_append(&line, " field=");
      line_append_hex(&line, param);
      line_append(&line, " protect=");
      line_append_hex(&line, param_mbi.Protect);
      emit_line(&line);
      return;
    }
    if (!region_contains_range(&param_mbi, param, 0x28)) {
      line_init(&line);
      line_append(&line, "event=ue-function-param name=");
      line_append(&line, safe_name);
      line_append(&line, " functionIndex=");
      line_append_dec(&line, function_index);
      line_append(&line, " chain=");
      line_append(&line, param_chain_name);
      line_append(&line, " index=");
      line_append_dec(&line, index);
      line_append(&line, " status=field-truncated function=");
      line_append_hex(&line, function);
      line_append(&line, " field=");
      line_append_hex(&line, param);
      line_append(&line, " protect=");
      line_append_hex(&line, param_mbi.Protect);
      emit_line(&line);
      return;
    }

    uintptr_t field_class = 0;
    uint32_t name_comparison_index = 0;
    uint32_t name_number = 0;
    uintptr_t next = 0;
    int32_t array_dim = 0;
    int32_t element_size = 0;
    uint64_t property_flags = 0;
    int32_t offset_internal = 0;
    read_pointer_at(&param_mbi, param + 0x10, &field_class);
    read_u32_at(&param_mbi, param + 0x18, &name_comparison_index);
    read_u32_at(&param_mbi, param + 0x1c, &name_number);
    int next_readable = region_contains_range(&param_mbi, param + options->field_next_offset, sizeof(uintptr_t));
    if (next_readable) {
      read_pointer_at(&param_mbi, param + options->field_next_offset, &next);
    }
    int array_dim_readable = read_i32_at(&param_mbi, param + options->property_array_dim_offset, &array_dim);
    int element_size_readable = read_i32_at(&param_mbi, param + options->property_element_size_offset, &element_size);
    int property_flags_readable = read_u64_at(&param_mbi, param + options->property_flags_offset, &property_flags);
    int offset_internal_readable = read_i32_at(&param_mbi, param + options->property_offset_internal_offset, &offset_internal);

    MEMORY_BASIC_INFORMATION_WIN64 field_class_mbi;
    for (size_t clear = 0; clear < sizeof(field_class_mbi); ++clear) {
      ((char *)&field_class_mbi)[clear] = 0;
    }
    SIZE_T field_class_got = field_class ? VirtualQuery((const void *)field_class, &field_class_mbi, sizeof(field_class_mbi)) : 0;
    MEMORY_BASIC_INFORMATION_WIN64 next_mbi;
    for (size_t clear = 0; clear < sizeof(next_mbi); ++clear) {
      ((char *)&next_mbi)[clear] = 0;
    }
	    SIZE_T next_got = next ? VirtualQuery((const void *)next, &next_mbi, sizeof(next_mbi)) : 0;
	    char field_alias_name[64];
	    field_alias_name[0] = '\0';
	    char field_class_name[64];
	    field_class_name[0] = '\0';
	    if (fname_options && fname_resolver && fname_resolver->available) {
	      char decoded[MAX_LUA_OBJECT_NAME];
      uintptr_t entry = 0;
      uint32_t block = 0;
      uint32_t offset = 0;
      int is_wide = 0;
      const char *decode_status = "unknown";
      if (decode_ue_fname(
            fname_resolver,
            fname_options,
            name_comparison_index,
            name_number,
            decoded,
            sizeof(decoded),
            &entry,
            &block,
            &offset,
            &is_wide,
            &decode_status
	      )) {
	        safe_value(decoded, field_alias_name, sizeof(field_alias_name));
	      }
	      if (field_class_got && field_class_mbi.State == MEM_COMMIT &&
	          readable_protect(field_class_mbi.Protect) &&
	          region_contains_range(&field_class_mbi, field_class, 0x20)) {
	        uint32_t class_name_comparison_index = 0;
	        uint32_t class_name_number = 0;
	        read_u32_at(&field_class_mbi, field_class + 0x18, &class_name_comparison_index);
	        read_u32_at(&field_class_mbi, field_class + 0x1c, &class_name_number);
	        if (decode_ue_fname(
	              fname_resolver,
	              fname_options,
	              class_name_comparison_index,
	              class_name_number,
	              decoded,
	              sizeof(decoded),
	              &entry,
	              &block,
	              &offset,
	              &is_wide,
	              &decode_status
	            )) {
	          safe_value(decoded, field_class_name, sizeof(field_class_name));
	        }
	      }
	    }

    if (fname_options) {
      static Line field_name_line;
      static char field_object_name[MAX_LUA_OBJECT_NAME];
      line_init(&field_name_line);
      line_append(&field_name_line, safe_name);
      line_append(&field_name_line, ".function");
      line_append_dec(&field_name_line, function_index);
      line_append_char(&field_name_line, '.');
      line_append(&field_name_line, param_chain_name);
      line_append_char(&field_name_line, '_');
      line_append_dec(&field_name_line, index);
      copy_string(field_object_name, sizeof(field_object_name), field_name_line.text);
      log_ue_fname_for_object(
        field_object_name,
        "ue-function-param",
        param,
        name_comparison_index,
        name_number,
        fname_resolver,
        fname_options
      );
    }

    line_init(&line);
    line_append(&line, "event=ue-function-param name=");
    line_append(&line, safe_name);
    line_append(&line, " functionIndex=");
    line_append_dec(&line, function_index);
    line_append(&line, " chain=");
    line_append(&line, param_chain_name);
    line_append(&line, " index=");
    line_append_dec(&line, index);
    line_append(&line, " status=candidate function=");
    line_append_hex(&line, function);
    line_append(&line, " functionName=");
    line_append(&line, function_identity_name);
    line_append(&line, " functionPath=");
    line_append(&line, function_identity_path);
    line_append(&line, " field=");
    line_append_hex(&line, param);
    line_append(&line, " class=");
	    line_append_hex(&line, field_class);
	    line_append(&line, " classMapped=");
	    line_append(&line, field_class_got && field_class_mbi.State == MEM_COMMIT ? "true" : "false");
	    line_append(&line, " fieldClassName=");
	    line_append(&line, field_class_name);
	    line_append(&line, " nameComparisonIndex=");
    line_append_dec(&line, name_comparison_index);
    line_append(&line, " nameNumber=");
    line_append_dec(&line, name_number);
    line_append(&line, " fieldName=");
    line_append(&line, field_alias_name);
    line_append(&line, " arrayDim=");
    line_append_signed_dec(&line, array_dim);
    line_append(&line, " elementSize=");
    line_append_signed_dec(&line, element_size);
    line_append(&line, " propertyFlags=");
    line_append_hex(&line, property_flags);
    line_append(&line, " offsetInternal=");
    line_append_signed_dec(&line, offset_internal);
    line_append(&line, " arrayDimReadable=");
    line_append(&line, array_dim_readable ? "true" : "false");
    line_append(&line, " elementSizeReadable=");
    line_append(&line, element_size_readable ? "true" : "false");
    line_append(&line, " propertyFlagsReadable=");
    line_append(&line, property_flags_readable ? "true" : "false");
    line_append(&line, " offsetInternalReadable=");
    line_append(&line, offset_internal_readable ? "true" : "false");
    line_append(&line, " functionFlags=");
    line_append_hex(&line, function_flags);
    line_append(&line, " functionFlagsReadable=");
    line_append(&line, function_flags_readable ? "true" : "false");
    line_append(&line, " next=");
    line_append_hex(&line, next);
    line_append(&line, " nextReadable=");
    line_append(&line, next_readable ? "true" : "false");
	    line_append(&line, " nextMapped=");
	    line_append(&line, next_got && next_mbi.State == MEM_COMMIT ? "true" : "false");
	    emit_line(&line);
	    if (array_dim_readable && element_size_readable && property_flags_readable && offset_internal_readable) {
	      add_ue_function_param_descriptor(
	        function,
	        param,
	        safe_name,
	        function_index,
	        function_name,
	        param_chain_name,
	        index,
	        field_alias_name,
	        field_class_name,
	        array_dim,
		        element_size,
		        property_flags,
		        offset_internal,
		        function_flags,
		        function_flags_readable
		      );
	    }
	    log_ue_function_param_container_children(
	      safe_name,
	      function_index,
	      function,
	      param_chain_name,
	      index,
	      param,
	      &param_mbi,
	      field_class_name,
	      options,
	      fname_resolver,
	      fname_options
	    );
	    if (!next_readable || next == 0) {
	      return;
	    }
    param = next;
  }

  if (param != 0) {
    line_init(&line);
    line_append(&line, "event=ue-function-param name=");
    line_append(&line, safe_name);
    line_append(&line, " functionIndex=");
    line_append_dec(&line, function_index);
    line_append(&line, " chain=");
    line_append(&line, param_chain_name);
    line_append(&line, " status=limit-reached limit=");
    line_append_dec(&line, options->max_fields);
    line_append(&line, " next=");
    line_append_hex(&line, param);
    emit_line(&line);
  }
}

static void log_ue_reflection_field_chain(
  const char *safe_name,
  const char *chain_name,
  const MEMORY_BASIC_INFORMATION_WIN64 *class_mbi,
  uintptr_t class_address,
  size_t root_offset,
  const UeReflectionOptions *options,
  uintptr_t object,
  const MEMORY_BASIC_INFORMATION_WIN64 *object_mbi,
  const UeFNameResolver *fname_resolver,
  const UeFNameOptions *fname_options,
  int property_probe,
  int value_probe
) {
  static Line line;
  uintptr_t root_slot = class_address + root_offset;
  if (!region_contains_range(class_mbi, root_slot, sizeof(uintptr_t))) {
    line_init(&line);
    line_append(&line, "event=ue-reflection-field name=");
    line_append(&line, safe_name);
    line_append(&line, " chain=");
    line_append(&line, chain_name);
    line_append(&line, " status=slot-truncated class=");
    line_append_hex(&line, class_address);
    line_append(&line, " offset=");
    line_append_hex(&line, root_offset);
    emit_line(&line);
    return;
  }

  uintptr_t field = 0;
  read_pointer_at(class_mbi, root_slot, &field);
  if (field == 0) {
    line_init(&line);
    line_append(&line, "event=ue-reflection-field name=");
    line_append(&line, safe_name);
    line_append(&line, " chain=");
    line_append(&line, chain_name);
    line_append(&line, " status=null-root class=");
    line_append_hex(&line, class_address);
    line_append(&line, " offset=");
    line_append_hex(&line, root_offset);
    emit_line(&line);
    return;
  }

  for (size_t index = 0; index < options->max_fields && field != 0; ++index) {
    MEMORY_BASIC_INFORMATION_WIN64 field_mbi;
    for (size_t clear = 0; clear < sizeof(field_mbi); ++clear) {
      ((char *)&field_mbi)[clear] = 0;
    }
    SIZE_T field_got = VirtualQuery((const void *)field, &field_mbi, sizeof(field_mbi));
    if (!field_got || field_mbi.State != MEM_COMMIT) {
      line_init(&line);
      line_append(&line, "event=ue-reflection-field name=");
      line_append(&line, safe_name);
      line_append(&line, " chain=");
      line_append(&line, chain_name);
      line_append(&line, " index=");
      line_append_dec(&line, index);
      line_append(&line, " status=field-unmapped field=");
      line_append_hex(&line, field);
      emit_line(&line);
      return;
    }
    if (!readable_protect(field_mbi.Protect)) {
      line_init(&line);
      line_append(&line, "event=ue-reflection-field name=");
      line_append(&line, safe_name);
      line_append(&line, " chain=");
      line_append(&line, chain_name);
      line_append(&line, " index=");
      line_append_dec(&line, index);
      line_append(&line, " status=field-not-readable field=");
      line_append_hex(&line, field);
      line_append(&line, " protect=");
      line_append_hex(&line, field_mbi.Protect);
      emit_line(&line);
      return;
    }
    if (!region_contains_range(&field_mbi, field, 0x28)) {
      line_init(&line);
      line_append(&line, "event=ue-reflection-field name=");
      line_append(&line, safe_name);
      line_append(&line, " chain=");
      line_append(&line, chain_name);
      line_append(&line, " index=");
      line_append_dec(&line, index);
      line_append(&line, " status=field-truncated field=");
      line_append_hex(&line, field);
      line_append(&line, " protect=");
      line_append_hex(&line, field_mbi.Protect);
      emit_line(&line);
      return;
    }

    uintptr_t field_class = 0;
    uint32_t name_comparison_index = 0;
    uint32_t name_number = 0;
    uintptr_t next = 0;
    read_pointer_at(&field_mbi, field + 0x10, &field_class);
    read_u32_at(&field_mbi, field + 0x18, &name_comparison_index);
    read_u32_at(&field_mbi, field + 0x1c, &name_number);
    int next_readable = region_contains_range(&field_mbi, field + options->field_next_offset, sizeof(uintptr_t));
    if (next_readable) {
      read_pointer_at(&field_mbi, field + options->field_next_offset, &next);
    }

    MEMORY_BASIC_INFORMATION_WIN64 field_class_mbi;
    for (size_t clear = 0; clear < sizeof(field_class_mbi); ++clear) {
      ((char *)&field_class_mbi)[clear] = 0;
    }
    SIZE_T field_class_got = field_class ? VirtualQuery((const void *)field_class, &field_class_mbi, sizeof(field_class_mbi)) : 0;
    MEMORY_BASIC_INFORMATION_WIN64 next_mbi;
    for (size_t clear = 0; clear < sizeof(next_mbi); ++clear) {
      ((char *)&next_mbi)[clear] = 0;
    }
    SIZE_T next_got = next ? VirtualQuery((const void *)next, &next_mbi, sizeof(next_mbi)) : 0;
    char field_alias_name[64];
    field_alias_name[0] = '\0';
    if (fname_options && fname_resolver && fname_resolver->available) {
      char decoded[MAX_LUA_OBJECT_NAME];
      uintptr_t entry = 0;
      uint32_t block = 0;
      uint32_t offset = 0;
      int is_wide = 0;
      const char *decode_status = "unknown";
      if (decode_ue_fname(
            fname_resolver,
            fname_options,
            name_comparison_index,
            name_number,
            decoded,
            sizeof(decoded),
            &entry,
            &block,
            &offset,
            &is_wide,
            &decode_status
          )) {
        safe_value(decoded, field_alias_name, sizeof(field_alias_name));
      }
    }

    if (fname_options) {
      static Line field_name_line;
      static char field_object_name[MAX_LUA_OBJECT_NAME];
      line_init(&field_name_line);
      line_append(&field_name_line, safe_name);
      line_append_char(&field_name_line, '.');
      line_append(&field_name_line, chain_name);
      line_append_char(&field_name_line, '_');
      line_append_dec(&field_name_line, index);
      copy_string(field_object_name, sizeof(field_object_name), field_name_line.text);
      log_ue_fname_for_object(
        field_object_name,
        "ue-reflection-field",
        field,
        name_comparison_index,
        name_number,
        fname_resolver,
        fname_options
      );
    }

    line_init(&line);
    line_append(&line, "event=ue-reflection-field name=");
    line_append(&line, safe_name);
    line_append(&line, " chain=");
    line_append(&line, chain_name);
    line_append(&line, " index=");
    line_append_dec(&line, index);
    line_append(&line, " status=candidate field=");
    line_append_hex(&line, field);
    line_append(&line, " class=");
    line_append_hex(&line, field_class);
    line_append(&line, " classMapped=");
    line_append(&line, field_class_got && field_class_mbi.State == MEM_COMMIT ? "true" : "false");
    line_append(&line, " nameComparisonIndex=");
    line_append_dec(&line, name_comparison_index);
    line_append(&line, " nameNumber=");
    line_append_dec(&line, name_number);
    line_append(&line, " next=");
    line_append_hex(&line, next);
    line_append(&line, " nextReadable=");
    line_append(&line, next_readable ? "true" : "false");
    line_append(&line, " nextMapped=");
    line_append(&line, next_got && next_mbi.State == MEM_COMMIT ? "true" : "false");
    emit_line(&line);
    if (property_probe && is_ue_reflection_property_chain(chain_name)) {
      log_ue_reflection_property_detail(
        safe_name,
        chain_name,
        index,
        field,
        &field_mbi,
        options,
        object,
        object_mbi,
        value_probe,
        field_alias_name
      );
    }
    if (property_probe && str_equal(chain_name, "functionLink")) {
      log_ue_function_param_chain(
        safe_name,
        index,
        field_alias_name,
        field,
        &field_mbi,
        "childProperties",
        options->child_properties_offset,
        options,
        fname_resolver,
        fname_options
      );
      log_ue_function_param_chain(
        safe_name,
        index,
        field_alias_name,
        field,
        &field_mbi,
        "propertyLink",
        options->property_link_offset,
        options,
        fname_resolver,
        fname_options
      );
    }
    if (!next_readable || next == 0) {
      return;
    }
    field = next;
  }

  if (field != 0) {
    line_init(&line);
    line_append(&line, "event=ue-reflection-field name=");
    line_append(&line, safe_name);
    line_append(&line, " chain=");
    line_append(&line, chain_name);
    line_append(&line, " status=limit-reached limit=");
    line_append_dec(&line, options->max_fields);
    line_append(&line, " next=");
    line_append_hex(&line, field);
    emit_line(&line);
  }
}

static void log_ue_reflection_probe(
  const char *safe_name,
  const MEMORY_BASIC_INFORMATION_WIN64 *target_mbi,
  uintptr_t target,
  const UeReflectionOptions *options,
  const UeFNameResolver *fname_resolver,
  const UeFNameOptions *fname_options,
  int field_walk,
  int property_probe,
  int value_probe
) {
  static Line line;
  if (!target_mbi || target_mbi->State != MEM_COMMIT || !readable_protect(target_mbi->Protect) ||
      !region_contains_range(target_mbi, target + 0x10, sizeof(uintptr_t))) {
    line_init(&line);
    line_append(&line, "event=ue-reflection name=");
    line_append(&line, safe_name);
    line_append(&line, " status=object-unreadable object=");
    line_append_hex(&line, target);
    emit_line(&line);
    return;
  }
  uintptr_t class_private = 0;
  read_pointer_at(target_mbi, target + 0x10, &class_private);
  MEMORY_BASIC_INFORMATION_WIN64 class_mbi;
  for (size_t clear = 0; clear < sizeof(class_mbi); ++clear) {
    ((char *)&class_mbi)[clear] = 0;
  }
  SIZE_T class_got = class_private ? VirtualQuery((const void *)class_private, &class_mbi, sizeof(class_mbi)) : 0;
  if (!class_got || class_mbi.State != MEM_COMMIT) {
    line_init(&line);
    line_append(&line, "event=ue-reflection name=");
    line_append(&line, safe_name);
    line_append(&line, " status=class-unmapped object=");
    line_append_hex(&line, target);
    line_append(&line, " class=");
    line_append_hex(&line, class_private);
    emit_line(&line);
    return;
  }
  if (!readable_protect(class_mbi.Protect)) {
    line_init(&line);
    line_append(&line, "event=ue-reflection name=");
    line_append(&line, safe_name);
    line_append(&line, " status=class-not-readable object=");
    line_append_hex(&line, target);
    line_append(&line, " class=");
    line_append_hex(&line, class_private);
    line_append(&line, " protect=");
    line_append_hex(&line, class_mbi.Protect);
    emit_line(&line);
    return;
  }
  if (!region_contains_range(&class_mbi, class_private, 0x28)) {
    line_init(&line);
    line_append(&line, "event=ue-reflection name=");
    line_append(&line, safe_name);
    line_append(&line, " status=class-truncated object=");
    line_append_hex(&line, target);
    line_append(&line, " class=");
    line_append_hex(&line, class_private);
    line_append(&line, " protect=");
    line_append_hex(&line, class_mbi.Protect);
    emit_line(&line);
    return;
  }

  uintptr_t class_vtable = 0;
  uint32_t class_name_comparison_index = 0;
  uint32_t class_name_number = 0;
  read_pointer_at(&class_mbi, class_private + 0x0, &class_vtable);
  read_u32_at(&class_mbi, class_private + 0x18, &class_name_comparison_index);
  read_u32_at(&class_mbi, class_private + 0x1c, &class_name_number);
  MEMORY_BASIC_INFORMATION_WIN64 class_vtable_mbi;
  for (size_t clear = 0; clear < sizeof(class_vtable_mbi); ++clear) {
    ((char *)&class_vtable_mbi)[clear] = 0;
  }
  SIZE_T class_vtable_got = class_vtable ? VirtualQuery((const void *)class_vtable, &class_vtable_mbi, sizeof(class_vtable_mbi)) : 0;
  if (fname_options) {
    log_ue_fname_for_object(
      safe_name,
      "ue-reflection-class",
      class_private,
      class_name_comparison_index,
      class_name_number,
      fname_resolver,
      fname_options
    );
  }
  line_init(&line);
  line_append(&line, "event=ue-reflection name=");
  line_append(&line, safe_name);
  line_append(&line, " status=class-mapped object=");
  line_append_hex(&line, target);
  line_append(&line, " class=");
  line_append_hex(&line, class_private);
  line_append(&line, " classVtable=");
  line_append_hex(&line, class_vtable);
  line_append(&line, " classVtableMapped=");
  line_append(&line, class_vtable_got && class_vtable_mbi.State == MEM_COMMIT ? "true" : "false");
  line_append(&line, " classNameComparisonIndex=");
  line_append_dec(&line, class_name_comparison_index);
  line_append(&line, " classNameNumber=");
  line_append_dec(&line, class_name_number);
  line_append(&line, " slots=6 nextOffset=");
  line_append_hex(&line, options->next_offset);
  line_append(&line, " superOffset=");
  line_append_hex(&line, options->super_offset);
  line_append(&line, " childrenOffset=");
  line_append_hex(&line, options->children_offset);
  line_append(&line, " childPropertiesOffset=");
  line_append_hex(&line, options->child_properties_offset);
  line_append(&line, " propertyLinkOffset=");
  line_append_hex(&line, options->property_link_offset);
  line_append(&line, " functionLinkOffset=");
  line_append_hex(&line, options->function_link_offset);
  line_append(&line, " fieldNextOffset=");
  line_append_hex(&line, options->field_next_offset);
  line_append(&line, " maxFields=");
  line_append_dec(&line, options->max_fields);
  line_append(&line, " fieldWalk=");
  line_append(&line, field_walk ? "true" : "false");
  line_append(&line, " propertyProbe=");
  line_append(&line, property_probe ? "true" : "false");
  line_append(&line, " valueProbe=");
  line_append(&line, value_probe ? "true" : "false");
  line_append(&line, " valueMaxBytes=");
  line_append_dec(&line, options->value_max_bytes);
  line_append(&line, " propertyArrayDimOffset=");
  line_append_hex(&line, options->property_array_dim_offset);
  line_append(&line, " propertyElementSizeOffset=");
  line_append_hex(&line, options->property_element_size_offset);
  line_append(&line, " propertyFlagsOffset=");
  line_append_hex(&line, options->property_flags_offset);
  line_append(&line, " propertyOffsetInternalOffset=");
  line_append_hex(&line, options->property_offset_internal_offset);
  line_append(&line, " functionFlagsOffset=");
  line_append_hex(&line, options->function_flags_offset);
  emit_line(&line);

  uintptr_t super_struct = 0;
  uintptr_t super_slot_addr = class_private + options->super_offset;
  if (region_contains_range(&class_mbi, super_slot_addr, sizeof(uintptr_t))) {
    read_pointer_at(&class_mbi, super_slot_addr, &super_struct);
    if (super_struct) {
      MEMORY_BASIC_INFORMATION_WIN64 super_mbi;
      for (size_t clear = 0; clear < sizeof(super_mbi); ++clear) {
        ((char *)&super_mbi)[clear] = 0;
      }
      SIZE_T super_got = VirtualQuery((const void *)super_struct, &super_mbi, sizeof(super_mbi));
      if (!super_got || super_mbi.State != MEM_COMMIT) {
        super_struct = 0;
      }
    }
  }
  update_ue_candidate_object_metadata(target, class_private, 0, super_struct);
  record_lua_class_metadata(class_private, super_struct, safe_name);

  log_ue_reflection_slot(safe_name, "next", &class_mbi, class_private, options->next_offset);
  log_ue_reflection_slot(safe_name, "super", &class_mbi, class_private, options->super_offset);
  log_ue_reflection_slot(safe_name, "children", &class_mbi, class_private, options->children_offset);
  log_ue_reflection_slot(safe_name, "childProperties", &class_mbi, class_private, options->child_properties_offset);
  log_ue_reflection_slot(safe_name, "propertyLink", &class_mbi, class_private, options->property_link_offset);
  log_ue_reflection_slot(safe_name, "functionLink", &class_mbi, class_private, options->function_link_offset);

  if (field_walk) {
    log_ue_reflection_field_chain(safe_name, "children", &class_mbi, class_private, options->children_offset, options, target, target_mbi, fname_resolver, fname_options, property_probe, value_probe);
    log_ue_reflection_field_chain(safe_name, "childProperties", &class_mbi, class_private, options->child_properties_offset, options, target, target_mbi, fname_resolver, fname_options, property_probe, value_probe);
    log_ue_reflection_field_chain(safe_name, "propertyLink", &class_mbi, class_private, options->property_link_offset, options, target, target_mbi, fname_resolver, fname_options, property_probe, value_probe);
    log_ue_reflection_field_chain(safe_name, "functionLink", &class_mbi, class_private, options->function_link_offset, options, target, target_mbi, fname_resolver, fname_options, property_probe, value_probe);
  }
}

static void log_ue_uobject_probe(
  const UeAnchor *anchor,
  const char *safe_name,
  const MEMORY_BASIC_INFORMATION_WIN64 *target_mbi,
  uintptr_t target,
  const UeFNameResolver *fname_resolver,
  const UeFNameOptions *fname_options
) {
  static Line line;
  if (!target_mbi || target_mbi->State != MEM_COMMIT) {
    line_init(&line);
    line_append(&line, "event=ue-uobject name=");
    line_append(&line, safe_name);
    line_append(&line, " status=target-unmapped target=");
    line_append_hex(&line, target);
    emit_line(&line);
    return;
  }
  if (!readable_protect(target_mbi->Protect)) {
    line_init(&line);
    line_append(&line, "event=ue-uobject name=");
    line_append(&line, safe_name);
    line_append(&line, " status=target-not-readable target=");
    line_append_hex(&line, target);
    line_append(&line, " protect=");
    line_append_hex(&line, target_mbi->Protect);
    emit_line(&line);
    return;
  }
  if (!region_contains_range(target_mbi, target, 0x28)) {
    line_init(&line);
    line_append(&line, "event=ue-uobject name=");
    line_append(&line, safe_name);
    line_append(&line, " status=target-truncated target=");
    line_append_hex(&line, target);
    line_append(&line, " protect=");
    line_append_hex(&line, target_mbi->Protect);
    emit_line(&line);
    return;
  }

  uintptr_t vtable = 0;
  uintptr_t class_private = 0;
  uintptr_t outer_private = 0;
  uint32_t object_flags = 0;
  uint32_t name_comparison_index = 0;
  uint32_t name_number = 0;
  int32_t internal_index = 0;
  read_pointer_at(target_mbi, target + 0x0, &vtable);
  read_u32_at(target_mbi, target + 0x8, &object_flags);
  read_i32_at(target_mbi, target + 0xc, &internal_index);
  read_pointer_at(target_mbi, target + 0x10, &class_private);
  read_u32_at(target_mbi, target + 0x18, &name_comparison_index);
  read_u32_at(target_mbi, target + 0x1c, &name_number);
  read_pointer_at(target_mbi, target + 0x20, &outer_private);

  MEMORY_BASIC_INFORMATION_WIN64 vtable_mbi;
  MEMORY_BASIC_INFORMATION_WIN64 class_mbi;
  MEMORY_BASIC_INFORMATION_WIN64 outer_mbi;
  SIZE_T vtable_got = vtable ? VirtualQuery((const void *)vtable, &vtable_mbi, sizeof(vtable_mbi)) : 0;
  SIZE_T class_got = class_private ? VirtualQuery((const void *)class_private, &class_mbi, sizeof(class_mbi)) : 0;
  SIZE_T outer_got = outer_private ? VirtualQuery((const void *)outer_private, &outer_mbi, sizeof(outer_mbi)) : 0;
  if (class_got && class_mbi.State == MEM_COMMIT) {
    register_lua_object_candidate("ue-uobject", safe_name, "UObjectCandidate", target);
  }
  if (fname_options) {
    static char decoded_name[MAX_LUA_OBJECT_NAME];
    if (decode_ue_fname(
          fname_resolver,
          fname_options,
          name_comparison_index,
          name_number,
          decoded_name,
          sizeof(decoded_name),
          0,
          0,
          0,
          0,
          0
        )) {
      register_lua_object_decoded_candidate("ue-uobject-fname", safe_name, "UObjectCandidate", target, decoded_name);
    }
    log_ue_fname_for_object(
      safe_name,
      "ue-uobject",
      target,
      name_comparison_index,
      name_number,
      fname_resolver,
      fname_options
    );
  }

  update_ue_candidate_object_metadata(target, class_private, outer_private, 0);
  update_ue_candidate_object_layout_metadata(target, object_flags, internal_index);
  record_lua_class_metadata(class_private, 0, "UObjectCandidate");

  line_init(&line);
  line_append(&line, "event=ue-uobject name=");
  line_append(&line, safe_name);
  line_append(&line, " status=candidate anchor=");
  line_append_hex(&line, anchor->address);
  line_append(&line, " target=");
  line_append_hex(&line, target);
  line_append(&line, " vtable=");
  line_append_hex(&line, vtable);
  line_append(&line, " vtableMapped=");
  line_append(&line, vtable_got && vtable_mbi.State == MEM_COMMIT ? "true" : "false");
  line_append(&line, " objectFlags=");
  line_append_hex(&line, object_flags);
  line_append(&line, " internalIndex=");
  line_append_signed_dec(&line, (long long)internal_index);
  line_append(&line, " class=");
  line_append_hex(&line, class_private);
  line_append(&line, " classMapped=");
  line_append(&line, class_got && class_mbi.State == MEM_COMMIT ? "true" : "false");
  line_append(&line, " nameComparisonIndex=");
  line_append_dec(&line, name_comparison_index);
  line_append(&line, " nameNumber=");
  line_append_dec(&line, name_number);
  line_append(&line, " outer=");
  line_append_hex(&line, outer_private);
  line_append(&line, " outerMapped=");
  line_append(&line, outer_got && outer_mbi.State == MEM_COMMIT ? "true" : "false");
  emit_line(&line);
}

static int register_object_array_candidate(
  const char *array_name,
  size_t index,
  uintptr_t item_addr,
  uintptr_t object,
  const UeFNameResolver *fname_resolver,
  const UeFNameOptions *fname_options
) {
  MEMORY_BASIC_INFORMATION_WIN64 object_mbi;
  SIZE_T object_got = VirtualQuery((const void *)object, &object_mbi, sizeof(object_mbi));
  static Line item_name_line;
  static char item_name[MAX_LUA_OBJECT_NAME];
  line_init(&item_name_line);
  line_append(&item_name_line, array_name);
  line_append_char(&item_name_line, '_');
  line_append_dec(&item_name_line, index);
  copy_string(item_name, sizeof(item_name), item_name_line.text);

  static Line line;
  if (!object_got || object_mbi.State != MEM_COMMIT || !readable_protect(object_mbi.Protect) ||
      !region_contains_range(&object_mbi, object, 0x28)) {
    line_init(&line);
    line_append(&line, "event=ue-object-array-item name=");
    line_append(&line, array_name);
    line_append(&line, " index=");
    line_append_dec(&line, index);
    line_append(&line, " status=object-unreadable object=");
    line_append_hex(&line, object);
    emit_line(&line);
    return 0;
  }
  uintptr_t class_private = 0;
  uint32_t object_flags = 0;
  uint32_t internal_flags = 0;
  int32_t internal_index = 0;
  int has_internal_flags = 0;
  uint32_t name_comparison_index = 0;
  uint32_t name_number = 0;
  MEMORY_BASIC_INFORMATION_WIN64 item_flags_mbi;
  SIZE_T item_flags_got = item_addr ? VirtualQuery((const void *)(item_addr + sizeof(uintptr_t)), &item_flags_mbi, sizeof(item_flags_mbi)) : 0;
  if (item_flags_got && item_flags_mbi.State == MEM_COMMIT &&
      read_u32_at(&item_flags_mbi, item_addr + sizeof(uintptr_t), &internal_flags)) {
    has_internal_flags = 1;
  }
  read_u32_at(&object_mbi, object + 0x8, &object_flags);
  read_i32_at(&object_mbi, object + 0xc, &internal_index);
  read_pointer_at(&object_mbi, object + 0x10, &class_private);
  read_u32_at(&object_mbi, object + 0x18, &name_comparison_index);
  read_u32_at(&object_mbi, object + 0x1c, &name_number);
  MEMORY_BASIC_INFORMATION_WIN64 class_mbi;
  SIZE_T class_got = class_private ? VirtualQuery((const void *)class_private, &class_mbi, sizeof(class_mbi)) : 0;
  if (!class_got || class_mbi.State != MEM_COMMIT) {
    line_init(&line);
    line_append(&line, "event=ue-object-array-item name=");
    line_append(&line, array_name);
    line_append(&line, " index=");
    line_append_dec(&line, index);
    line_append(&line, " status=class-unmapped object=");
    line_append_hex(&line, object);
    line_append(&line, " class=");
    line_append_hex(&line, class_private);
    emit_line(&line);
    return 0;
  }
  if (fname_options) {
    static char decoded_name[MAX_LUA_OBJECT_NAME];
    if (decode_ue_fname(
          fname_resolver,
          fname_options,
          name_comparison_index,
          name_number,
          decoded_name,
          sizeof(decoded_name),
          0,
          0,
          0,
          0,
          0
        )) {
      register_lua_object_decoded_candidate("ue-object-array-fname", item_name, "UObjectArrayItem", object, decoded_name);
    }
    log_ue_fname_for_object(
      item_name,
      "ue-object-array",
      object,
      name_comparison_index,
      name_number,
      fname_resolver,
      fname_options
    );
  }
  int registered = register_lua_object_candidate("ue-object-array", item_name, "UObjectArrayItem", object);
  update_ue_candidate_object_metadata(object, class_private, 0, 0);
  update_ue_candidate_object_layout_metadata(object, object_flags, internal_index);
  update_ue_candidate_object_internal_flags(object, internal_flags, has_internal_flags);
  record_lua_class_metadata(class_private, 0, "UObjectArrayItem");
  line_init(&line);
  line_append(&line, "event=ue-object-array-item name=");
  line_append(&line, array_name);
  line_append(&line, " index=");
  line_append_dec(&line, index);
  line_append(&line, " status=");
  line_append(&line, registered ? "registered" : "skipped");
  line_append(&line, " object=");
  line_append_hex(&line, object);
  line_append(&line, " class=");
  line_append_hex(&line, class_private);
  line_append(&line, " internalFlags=");
  line_append_hex(&line, internal_flags);
  line_append(&line, " internalFlagsReadable=");
  line_append(&line, has_internal_flags ? "true" : "false");
  emit_line(&line);
  return registered;
}

static size_t probe_chunked_object_array_base(
  const char *safe_name,
  const char *mode,
  uintptr_t base,
  const UeObjectArrayOptions *options,
  const UeFNameResolver *fname_resolver,
  const UeFNameOptions *fname_options
) {
  MEMORY_BASIC_INFORMATION_WIN64 base_mbi;
  SIZE_T base_got = VirtualQuery((const void *)base, &base_mbi, sizeof(base_mbi));
  static Line line;
  if (!base_got || base_mbi.State != MEM_COMMIT || !readable_protect(base_mbi.Protect)) {
    line_init(&line);
    line_append(&line, "event=ue-object-array name=");
    line_append(&line, safe_name);
    line_append(&line, " mode=");
    line_append(&line, mode);
    line_append(&line, " status=base-unreadable base=");
    line_append_hex(&line, base);
    emit_line(&line);
    return 0;
  }
  uintptr_t chunks = 0;
  uint32_t max_elements = 0;
  uint32_t num_elements = 0;
  uint32_t max_chunks = 0;
  uint32_t num_chunks = 0;
  if (!read_pointer_at(&base_mbi, base + 0x0, &chunks) ||
      !read_u32_at(&base_mbi, base + 0x10, &max_elements) ||
      !read_u32_at(&base_mbi, base + 0x14, &num_elements) ||
      !read_u32_at(&base_mbi, base + 0x18, &max_chunks) ||
      !read_u32_at(&base_mbi, base + 0x1c, &num_chunks)) {
    line_init(&line);
    line_append(&line, "event=ue-object-array name=");
    line_append(&line, safe_name);
    line_append(&line, " mode=");
    line_append(&line, mode);
    line_append(&line, " status=header-unreadable base=");
    line_append_hex(&line, base);
    emit_line(&line);
    return 0;
  }
  if (chunks == 0 || num_elements == 0 || num_chunks == 0) {
    line_init(&line);
    line_append(&line, "event=ue-object-array name=");
    line_append(&line, safe_name);
    line_append(&line, " mode=");
    line_append(&line, mode);
    line_append(&line, " status=empty base=");
    line_append_hex(&line, base);
    line_append(&line, " chunks=");
    line_append_hex(&line, chunks);
    line_append(&line, " maxElements=");
    line_append_dec(&line, max_elements);
    line_append(&line, " numElements=");
    line_append_dec(&line, num_elements);
    line_append(&line, " maxChunks=");
    line_append_dec(&line, max_chunks);
    line_append(&line, " numChunks=");
    line_append_dec(&line, num_chunks);
    emit_line(&line);
    return 0;
  }
  size_t limit = num_elements;
  if (limit > options->max_objects) {
    limit = options->max_objects;
  }
  line_init(&line);
  line_append(&line, "event=ue-object-array name=");
  line_append(&line, safe_name);
  line_append(&line, " mode=");
  line_append(&line, mode);
  line_append(&line, " status=scanning base=");
  line_append_hex(&line, base);
  line_append(&line, " chunks=");
  line_append_hex(&line, chunks);
  line_append(&line, " maxElements=");
  line_append_dec(&line, max_elements);
  line_append(&line, " numElements=");
  line_append_dec(&line, num_elements);
  line_append(&line, " maxChunks=");
  line_append_dec(&line, max_chunks);
  line_append(&line, " numChunks=");
  line_append_dec(&line, num_chunks);
  line_append(&line, " limit=");
  line_append_dec(&line, limit);
  line_append(&line, " itemSize=");
  line_append_dec(&line, options->item_size);
  line_append(&line, " chunkSize=");
  line_append_dec(&line, options->chunk_size);
  emit_line(&line);

  size_t registered = 0;
  size_t scanned = 0;
  for (size_t index = 0; index < limit; ++index) {
    size_t chunk_index = index / options->chunk_size;
    if (chunk_index >= num_chunks) {
      break;
    }
    uintptr_t chunk_slot = chunks + chunk_index * sizeof(uintptr_t);
    MEMORY_BASIC_INFORMATION_WIN64 chunks_mbi;
    SIZE_T chunks_got = VirtualQuery((const void *)chunk_slot, &chunks_mbi, sizeof(chunks_mbi));
    uintptr_t chunk = 0;
    if (!chunks_got || !read_pointer_at(&chunks_mbi, chunk_slot, &chunk) || chunk == 0) {
      continue;
    }
    size_t index_in_chunk = index % options->chunk_size;
    uintptr_t item_addr = chunk + index_in_chunk * options->item_size + options->object_offset;
    MEMORY_BASIC_INFORMATION_WIN64 item_mbi;
    SIZE_T item_got = VirtualQuery((const void *)item_addr, &item_mbi, sizeof(item_mbi));
    uintptr_t object = 0;
    if (!item_got || !read_pointer_at(&item_mbi, item_addr, &object) || object == 0) {
      continue;
    }
    ++scanned;
    registered += register_object_array_candidate(
      safe_name,
      index,
      item_addr,
      object,
      fname_resolver,
      fname_options
    ) ? 1U : 0U;
  }
  line_init(&line);
  line_append(&line, "event=ue-object-array name=");
  line_append(&line, safe_name);
  line_append(&line, " mode=");
  line_append(&line, mode);
  line_append(&line, " status=finished base=");
  line_append_hex(&line, base);
  line_append(&line, " scanned=");
  line_append_dec(&line, scanned);
  line_append(&line, " registered=");
  line_append_dec(&line, registered);
  emit_line(&line);
  return registered;
}

static void probe_ue_object_array_anchor(
  const UeAnchor *anchor,
  const char *safe_name,
  const MEMORY_BASIC_INFORMATION_WIN64 *anchor_mbi,
  const UeObjectArrayOptions *options,
  const UeFNameResolver *fname_resolver,
  const UeFNameOptions *fname_options
) {
  uintptr_t direct_base = anchor->address + options->array_offset;
  probe_chunked_object_array_base(safe_name, "direct", direct_base, options, fname_resolver, fname_options);
  uintptr_t indirect = 0;
  if (read_pointer_at(anchor_mbi, anchor->address, &indirect) && indirect != 0) {
    uintptr_t indirect_base = indirect + options->array_offset;
    probe_chunked_object_array_base(safe_name, "indirect", indirect_base, options, fname_resolver, fname_options);
  } else {
    static Line line;
    line_init(&line);
    line_append(&line, "event=ue-object-array name=");
    line_append(&line, safe_name);
    line_append(&line, " mode=indirect status=anchor-pointer-unreadable anchor=");
    line_append_hex(&line, anchor->address);
    emit_line(&line);
  }
}

static void validate_ue_anchors(const char *phase) {
  static UeAnchor anchors[MAX_UE_ANCHORS];
  for (size_t i = 0; i < sizeof(anchors); ++i) {
    ((char *)anchors)[i] = 0;
  }
  size_t anchor_count = collect_ue_anchors(anchors);
  int signature_configured = ue_anchor_signatures_configured();
  if (anchor_count == 0 && !signature_configured) {
    return;
  }
  if (signature_configured) {
    anchor_count = collect_ue_anchor_signature_anchors(anchors, anchor_count, phase);
  }
  if (anchor_count == 0) {
    static Line skip_line;
    line_init(&skip_line);
    line_append(&skip_line, "event=ue-anchor-skip phase=");
    line_append(&skip_line, phase);
    line_append(&skip_line, " reason=no-resolved-anchors");
    emit_line(&skip_line);
    return;
  }

  static Line line;
  line_init(&line);
  line_append(&line, "event=ue-anchor-start phase=");
  line_append(&line, phase);
  line_append(&line, " anchors=");
  line_append_dec(&line, anchor_count);
  emit_line(&line);
  int layout_probe = env_bool("UE4SSL_WIN_UE_LAYOUT_PROBE", 0);
  int uobject_probe = env_bool("UE4SSL_WIN_UE_UOBJECT_PROBE", 0);
  int object_array_probe = env_bool("UE4SSL_WIN_UE_OBJECT_ARRAY_PROBE", 0);
  int fname_probe = env_bool("UE4SSL_WIN_UE_FNAME_PROBE", 0);
  int reflection_probe = env_bool("UE4SSL_WIN_UE_REFLECTION_PROBE", 0);
  int reflection_field_walk = env_bool("UE4SSL_WIN_UE_REFLECTION_FIELD_WALK", 0);
  int reflection_property_probe = env_bool("UE4SSL_WIN_UE_REFLECTION_PROPERTY_PROBE", 0);
  int reflection_value_probe = env_bool("UE4SSL_WIN_UE_REFLECTION_VALUE_PROBE", 0);
  if (reflection_value_probe) {
    reflection_property_probe = 1;
  }
  if (reflection_property_probe) {
    reflection_field_walk = 1;
  }
  int pointer_probe = env_bool("UE4SSL_WIN_UE_POINTER_PROBE", 0) || layout_probe || uobject_probe || reflection_probe;
  UeFNameOptions fname_options = ue_fname_options();
  UeFNameResolver fname_resolver;
  unsigned char *resolver_bytes = (unsigned char *)&fname_resolver;
  for (size_t i = 0; i < sizeof(fname_resolver); ++i) {
    resolver_bytes[i] = 0;
  }
  if (fname_probe) {
    find_ue_fname_resolver(anchors, anchor_count, &fname_options, &fname_resolver);
    cache_lua_fname_resolver(&fname_resolver, &fname_options);
  }
  UeObjectArrayOptions object_array_options = ue_object_array_options();
  UeReflectionOptions reflection_options = ue_reflection_options();
  size_t layout_slots = ue_layout_slots();
  if (reflection_probe) {
    reset_ue_reflection_property_candidates();
  }
  if (uobject_probe || object_array_probe) {
    ue_candidate_object_handle_count = 0;
  }
  if (uobject_probe || object_array_probe || reflection_probe) {
    lua_class_metadata_count = 0;
  }
  if (pointer_probe) {
    line_init(&line);
    line_append(&line, "event=ue-pointer-start phase=");
    line_append(&line, phase);
    line_append(&line, " anchors=");
    line_append_dec(&line, anchor_count);
    emit_line(&line);
  }
  if (layout_probe) {
    line_init(&line);
    line_append(&line, "event=ue-layout-start phase=");
    line_append(&line, phase);
    line_append(&line, " anchors=");
    line_append_dec(&line, anchor_count);
    line_append(&line, " slots=");
    line_append_dec(&line, layout_slots);
    emit_line(&line);
  }
  if (uobject_probe) {
    line_init(&line);
    line_append(&line, "event=ue-uobject-start phase=");
    line_append(&line, phase);
    line_append(&line, " anchors=");
    line_append_dec(&line, anchor_count);
    emit_line(&line);
  }
  if (reflection_probe) {
    line_init(&line);
    line_append(&line, "event=ue-reflection-start phase=");
    line_append(&line, phase);
    line_append(&line, " anchors=");
    line_append_dec(&line, anchor_count);
    line_append(&line, " nextOffset=");
    line_append_hex(&line, reflection_options.next_offset);
    line_append(&line, " superOffset=");
    line_append_hex(&line, reflection_options.super_offset);
    line_append(&line, " childrenOffset=");
    line_append_hex(&line, reflection_options.children_offset);
    line_append(&line, " childPropertiesOffset=");
    line_append_hex(&line, reflection_options.child_properties_offset);
    line_append(&line, " propertyLinkOffset=");
    line_append_hex(&line, reflection_options.property_link_offset);
    line_append(&line, " functionLinkOffset=");
    line_append_hex(&line, reflection_options.function_link_offset);
    line_append(&line, " fieldNextOffset=");
    line_append_hex(&line, reflection_options.field_next_offset);
    line_append(&line, " maxFields=");
    line_append_dec(&line, reflection_options.max_fields);
    line_append(&line, " fieldWalk=");
    line_append(&line, reflection_field_walk ? "true" : "false");
    line_append(&line, " propertyProbe=");
    line_append(&line, reflection_property_probe ? "true" : "false");
    line_append(&line, " valueProbe=");
    line_append(&line, reflection_value_probe ? "true" : "false");
    line_append(&line, " valueMaxBytes=");
    line_append_dec(&line, reflection_options.value_max_bytes);
    line_append(&line, " propertyArrayDimOffset=");
    line_append_hex(&line, reflection_options.property_array_dim_offset);
    line_append(&line, " propertyElementSizeOffset=");
    line_append_hex(&line, reflection_options.property_element_size_offset);
    line_append(&line, " propertyFlagsOffset=");
    line_append_hex(&line, reflection_options.property_flags_offset);
    line_append(&line, " propertyOffsetInternalOffset=");
    line_append_hex(&line, reflection_options.property_offset_internal_offset);
    line_append(&line, " functionFlagsOffset=");
    line_append_hex(&line, reflection_options.function_flags_offset);
    emit_line(&line);
  }
  if (object_array_probe) {
    line_init(&line);
    line_append(&line, "event=ue-object-array-start phase=");
    line_append(&line, phase);
    line_append(&line, " anchors=");
    line_append_dec(&line, anchor_count);
    line_append(&line, " maxObjects=");
    line_append_dec(&line, object_array_options.max_objects);
    line_append(&line, " itemSize=");
    line_append_dec(&line, object_array_options.item_size);
    line_append(&line, " chunkSize=");
    line_append_dec(&line, object_array_options.chunk_size);
    line_append(&line, " offset=");
    line_append_hex(&line, object_array_options.array_offset);
    emit_line(&line);
  }
  if (fname_probe) {
    line_init(&line);
    line_append(&line, "event=ue-fname-start phase=");
    line_append(&line, phase);
    line_append(&line, " status=");
    line_append(&line, fname_resolver.available ? "ready" : "pool-unavailable");
    line_append(&line, " pool=");
    line_append_hex(&line, fname_resolver.pool);
    line_append(&line, " source=");
    line_append(&line, fname_resolver.available ? fname_resolver.source : "");
    line_append(&line, " blocksOffset=");
    line_append_hex(&line, fname_options.blocks_offset);
    line_append(&line, " stride=");
    line_append_dec(&line, fname_options.stride);
    line_append(&line, " maxLength=");
    line_append_dec(&line, fname_options.max_length);
    emit_line(&line);
  }

  for (size_t i = 0; i < anchor_count; ++i) {
    MEMORY_BASIC_INFORMATION_WIN64 mbi;
    SIZE_T got = VirtualQuery((const void *)anchors[i].address, &mbi, sizeof(mbi));
    static char safe_name[256];
    safe_value(anchors[i].name, safe_name, sizeof(safe_name));
    if (got == 0 || mbi.State != MEM_COMMIT) {
      line_init(&line);
      line_append(&line, "event=ue-anchor name=");
      line_append(&line, safe_name);
      line_append(&line, " status=unmapped addr=");
      line_append_hex(&line, anchors[i].address);
      emit_line(&line);
      if (pointer_probe) {
        log_ue_pointer_probe(&anchors[i], safe_name, 0, 0, 0);
      }
      if (object_array_probe) {
        line_init(&line);
        line_append(&line, "event=ue-object-array name=");
        line_append(&line, safe_name);
        line_append(&line, " status=anchor-unmapped anchor=");
        line_append_hex(&line, anchors[i].address);
        emit_line(&line);
      }
      continue;
    }

    static char module_path[1024];
    static char safe_module[1024];
    module_path[0] = '\0';
    GetModuleFileNameA((HMODULE)mbi.AllocationBase, module_path, sizeof(module_path));
    safe_value(module_path, safe_module, sizeof(safe_module));

    line_init(&line);
    line_append(&line, "event=ue-anchor name=");
    line_append(&line, safe_name);
    line_append(&line, " status=mapped addr=");
    line_append_hex(&line, anchors[i].address);
    line_append(&line, " readable=");
    line_append(&line, readable_protect(mbi.Protect) ? "true" : "false");
    line_append(&line, " writable=");
    line_append(&line, writable_protect(mbi.Protect) ? "true" : "false");
    line_append(&line, " executable=");
    line_append(&line, executable_protect(mbi.Protect) ? "true" : "false");
    line_append(&line, " rva=");
    line_append_hex(&line, (uintptr_t)mbi.AllocationBase ? anchors[i].address - (uintptr_t)mbi.AllocationBase : 0);
    line_append(&line, " allocationBase=");
    line_append_hex(&line, (uintptr_t)mbi.AllocationBase);
    line_append(&line, " regionBase=");
    line_append_hex(&line, (uintptr_t)mbi.BaseAddress);
    line_append(&line, " protect=");
    line_append_hex(&line, mbi.Protect);
    line_append(&line, " type=");
    line_append_hex(&line, mbi.Type);
    line_append(&line, " module=");
    line_append(&line, safe_module);
    emit_line(&line);
    if (pointer_probe) {
      uintptr_t value = 0;
      MEMORY_BASIC_INFORMATION_WIN64 target_mbi;
      SIZE_T target_got = 0;
      for (size_t clear = 0; clear < sizeof(target_mbi); ++clear) {
        ((char *)&target_mbi)[clear] = 0;
      }
      if (read_pointer_at(&mbi, anchors[i].address, &value) && value != 0) {
        target_got = VirtualQuery((const void *)value, &target_mbi, sizeof(target_mbi));
      }
      log_ue_pointer_probe(&anchors[i], safe_name, &mbi, target_got ? &target_mbi : 0, value);
      if (layout_probe && target_got) {
        log_ue_layout_probe(&anchors[i], safe_name, &target_mbi, value, layout_slots);
      }
      if (uobject_probe && target_got) {
        log_ue_uobject_probe(
          &anchors[i],
          safe_name,
          &target_mbi,
          value,
          fname_probe ? &fname_resolver : 0,
          fname_probe ? &fname_options : 0
        );
      }
      if (reflection_probe && target_got) {
        log_ue_reflection_probe(
          safe_name,
          &target_mbi,
          value,
          &reflection_options,
          fname_probe ? &fname_resolver : 0,
          fname_probe ? &fname_options : 0,
          reflection_field_walk,
          reflection_property_probe,
          reflection_value_probe
        );
      }
    }
    if (object_array_probe) {
      probe_ue_object_array_anchor(
        &anchors[i],
        safe_name,
        &mbi,
        &object_array_options,
        fname_probe ? &fname_resolver : 0,
        fname_probe ? &fname_options : 0
      );
    }
  }

  line_init(&line);
  line_append(&line, "event=ue-anchor-finish phase=");
  line_append(&line, phase);
  emit_line(&line);
  if (pointer_probe) {
    line_init(&line);
    line_append(&line, "event=ue-pointer-finish phase=");
    line_append(&line, phase);
    emit_line(&line);
  }
  if (layout_probe) {
    line_init(&line);
    line_append(&line, "event=ue-layout-finish phase=");
    line_append(&line, phase);
    emit_line(&line);
  }
  if (uobject_probe) {
    line_init(&line);
    line_append(&line, "event=ue-uobject-finish phase=");
    line_append(&line, phase);
    emit_line(&line);
  }
  if (reflection_probe) {
    line_init(&line);
    line_append(&line, "event=ue-reflection-finish phase=");
    line_append(&line, phase);
    emit_line(&line);
  }
  if (object_array_probe) {
    line_init(&line);
    line_append(&line, "event=ue-object-array-finish phase=");
    line_append(&line, phase);
    line_append(&line, " registryCount=");
    line_append_dec(&line, ue_candidate_object_handle_count);
    emit_line(&line);
  }
  if (fname_probe) {
    line_init(&line);
    line_append(&line, "event=ue-fname-finish phase=");
    line_append(&line, phase);
    line_append(&line, " status=");
    line_append(&line, fname_resolver.available ? "ready" : "pool-unavailable");
    line_append(&line, " pool=");
    line_append_hex(&line, fname_resolver.pool);
    line_append(&line, " source=");
    line_append(&line, fname_resolver.available ? fname_resolver.source : "");
    emit_line(&line);
  }
}

static void parse_filters(char filters[][MAX_NEEDLE_LEN], size_t *count) {
  static char raw[2048];
  if (env_get("UE4SSL_WIN_SCAN_PATH_FILTER", raw, sizeof(raw)) == 0) {
    return;
  }
  char *start = raw;
  while (start && *start && *count < MAX_FILTERS) {
    char *end = start;
    while (*end && *end != ';') {
      ++end;
    }
    int has_delimiter = *end == ';';
    if (*end) {
      *end = '\0';
    }
    char *item = trim(start);
    if (item[0]) {
      copy_string(filters[*count], MAX_NEEDLE_LEN, item);
      ++(*count);
    }
    start = has_delimiter ? end + 1 : 0;
  }
}

static const unsigned char *find_bytes(const unsigned char *begin, const unsigned char *end, const unsigned char *needle, size_t needle_size) {
  if (needle_size == 0 || (size_t)(end - begin) < needle_size) {
    return 0;
  }
  for (const unsigned char *cursor = begin; cursor + needle_size <= end; ++cursor) {
    size_t i = 0;
    while (i < needle_size && cursor[i] == needle[i]) {
      ++i;
    }
    if (i == needle_size) {
      return cursor;
    }
  }
  return 0;
}

static int pattern_matches_at(const unsigned char *cursor, const BytePattern *pattern) {
  for (size_t i = 0; i < pattern->length; ++i) {
    if (pattern->bytes[i] >= 0 && cursor[i] != (unsigned char)pattern->bytes[i]) {
      return 0;
    }
  }
  return 1;
}

static const unsigned char *find_pattern(const unsigned char *begin, const unsigned char *end, const BytePattern *pattern) {
  if (pattern->length == 0 || (size_t)(end - begin) < pattern->length) {
    return 0;
  }
  for (const unsigned char *cursor = begin; cursor + pattern->length <= end; ++cursor) {
    if (pattern_matches_at(cursor, pattern)) {
      return cursor;
    }
  }
  return 0;
}

static int readable_protect(DWORD protect) {
  if ((protect & PAGE_GUARD) || (protect & PAGE_NOACCESS)) {
    return 0;
  }
  DWORD base = protect & 0xffUL;
  return base == PAGE_READONLY ||
         base == PAGE_READWRITE ||
         base == PAGE_WRITECOPY ||
         base == PAGE_EXECUTE_READ ||
         base == PAGE_EXECUTE_READWRITE ||
         base == PAGE_EXECUTE_WRITECOPY;
}

static int module_path_matches(const char *module_path, const char *exe_path, char filters[][MAX_NEEDLE_LEN], size_t filter_count) {
  if (!module_path[0]) {
    return 0;
  }
  if (str_equal_ci(module_path, exe_path)) {
    return 1;
  }
  if (filter_count == 0) {
    return contains_ci(module_path, "\\TargetGame\\") ||
           contains_ci(module_path, "\\TargetGame\\") ||
           contains_ci(module_path, "\\Engine\\Binaries\\Win64\\") ||
           contains_ci(module_path, "/TargetGame/") ||
           contains_ci(module_path, "/TargetGame/") ||
           contains_ci(module_path, "/Engine/Binaries/Win64/");
  }
  for (size_t i = 0; i < filter_count; ++i) {
    if (contains_ci(module_path, filters[i])) {
      return 1;
    }
  }
  return 0;
}

static int seen_module(uintptr_t *seen, size_t count, uintptr_t value) {
  for (size_t i = 0; i < count; ++i) {
    if (seen[i] == value) {
      return 1;
    }
  }
  return 0;
}

static void log_modules(void) {
  if (!env_bool("UE4SSL_WIN_LOG_MODULES", 1)) {
    return;
  }

  static uintptr_t seen[1024];
  static char module_path[1024];
  static char safe_module[1024];
  static Line line;
  size_t seen_count = 0;

  SYSTEM_INFO_WIN system_info;
  GetNativeSystemInfo(&system_info);
  uintptr_t cursor = (uintptr_t)system_info.lpMinimumApplicationAddress;
  uintptr_t max_address = (uintptr_t)system_info.lpMaximumApplicationAddress;

  while (cursor < max_address) {
    MEMORY_BASIC_INFORMATION_WIN64 mbi;
    SIZE_T got = VirtualQuery((const void *)cursor, &mbi, sizeof(mbi));
    if (got == 0) {
      cursor += 0x10000ULL;
      continue;
    }

    uintptr_t region_base = (uintptr_t)mbi.BaseAddress;
    uintptr_t allocation_base = (uintptr_t)mbi.AllocationBase;
    uintptr_t next = region_base + (uintptr_t)mbi.RegionSize;
    if (next <= cursor) {
      break;
    }
    cursor = next;

    if (mbi.State != MEM_COMMIT ||
        mbi.Type != MEM_IMAGE ||
        allocation_base == 0 ||
        seen_module(seen, seen_count, allocation_base)) {
      continue;
    }
    if (seen_count < sizeof(seen) / sizeof(seen[0])) {
      seen[seen_count++] = allocation_base;
    }

    module_path[0] = '\0';
    GetModuleFileNameA((HMODULE)allocation_base, module_path, sizeof(module_path));
    safe_value(module_path, safe_module, sizeof(safe_module));

    line_init(&line);
    line_append(&line, "event=module base=");
    line_append_hex(&line, allocation_base);
    line_append(&line, " firstRegion=");
    line_append_hex(&line, region_base);
    line_append(&line, " protect=");
    line_append_hex(&line, mbi.Protect);
    line_append(&line, " path=");
    line_append(&line, safe_module);
    emit_line(&line);
  }
}

static void log_scan_hit(const char *kind, const char *name, uintptr_t address, uintptr_t allocation_base, uintptr_t region_base, DWORD protect, DWORD type, const char *module_path) {
  static char safe_name[256];
  static char safe_module[1024];
  safe_value(name, safe_name, sizeof(safe_name));
  safe_value(module_path, safe_module, sizeof(safe_module));

  static Line line;
  line_init(&line);
  line_append(&line, "event=scan-hit kind=");
  line_append(&line, kind);
  line_append(&line, " name=");
  line_append(&line, safe_name);
  line_append(&line, " addr=");
  line_append_hex(&line, address);
  line_append(&line, " rva=");
  line_append_hex(&line, allocation_base ? address - allocation_base : 0);
  line_append(&line, " allocationBase=");
  line_append_hex(&line, allocation_base);
  line_append(&line, " regionBase=");
  line_append_hex(&line, region_base);
  line_append(&line, " protect=");
  line_append_hex(&line, protect);
  line_append(&line, " type=");
  line_append_hex(&line, type);
  line_append(&line, " module=");
  line_append(&line, safe_module);
  emit_line(&line);
}

static void run_scans(void) {
  if (!env_bool("UE4SSL_WIN_SCAN_ENABLED", 0)) {
    return;
  }

  static char needles[MAX_NEEDLES][MAX_NEEDLE_LEN];
  static char filters[MAX_FILTERS][MAX_NEEDLE_LEN];
  static BytePattern patterns[MAX_PATTERNS];
  size_t needle_count = 0;
  size_t filter_count = 0;
  size_t pattern_count = 0;
  collect_needles(needles, &needle_count);
  parse_filters(filters, &filter_count);
  collect_patterns(patterns, &pattern_count);

  size_t max_hits = env_size("UE4SSL_WIN_SCAN_MAX_HITS_PER_NEEDLE", DEFAULT_MAX_HITS);
  size_t max_region_bytes = env_size("UE4SSL_WIN_SCAN_MAX_REGION_BYTES", DEFAULT_MAX_REGION_BYTES);
  int scan_private = env_bool("UE4SSL_WIN_SCAN_PRIVATE", 0);

  static Line line;
  line_init(&line);
  line_append(&line, "event=scan-start strings=");
  line_append_dec(&line, needle_count);
  line_append(&line, " signatures=");
  line_append_dec(&line, pattern_count);
  line_append(&line, " filters=");
  line_append_dec(&line, filter_count);
  line_append(&line, " maxHits=");
  line_append_dec(&line, max_hits);
  line_append(&line, " maxRegionBytes=");
  line_append_dec(&line, max_region_bytes);
  emit_line(&line);

  static char exe_path[1024];
  GetModuleFileNameA(0, exe_path, sizeof(exe_path));

  SYSTEM_INFO_WIN system_info;
  GetNativeSystemInfo(&system_info);
  uintptr_t cursor = (uintptr_t)system_info.lpMinimumApplicationAddress;
  uintptr_t max_address = (uintptr_t)system_info.lpMaximumApplicationAddress;

  while (cursor < max_address) {
    MEMORY_BASIC_INFORMATION_WIN64 mbi;
    SIZE_T got = VirtualQuery((const void *)cursor, &mbi, sizeof(mbi));
    if (got == 0) {
      cursor += 0x10000ULL;
      continue;
    }

    uintptr_t region_base = (uintptr_t)mbi.BaseAddress;
    uintptr_t allocation_base = (uintptr_t)mbi.AllocationBase;
    uintptr_t next = region_base + (uintptr_t)mbi.RegionSize;
    if (next <= cursor) {
      break;
    }
    cursor = next;

    if (allocation_base == (uintptr_t)self_module ||
        mbi.State != MEM_COMMIT ||
        !readable_protect(mbi.Protect) ||
        mbi.RegionSize == 0 ||
        mbi.RegionSize > max_region_bytes ||
        (mbi.Type != MEM_IMAGE && !(scan_private && mbi.Type == MEM_PRIVATE))) {
      continue;
    }

    static char module_path[1024];
    module_path[0] = '\0';
    GetModuleFileNameA((HMODULE)allocation_base, module_path, sizeof(module_path));
    if (!module_path_matches(module_path, exe_path, filters, filter_count)) {
      continue;
    }

    const unsigned char *begin = (const unsigned char *)region_base;
    const unsigned char *end = begin + mbi.RegionSize;
    for (size_t n = 0; n < needle_count; ++n) {
      const unsigned char *scan = begin;
      size_t hits = 0;
      size_t needle_len = cstr_len(needles[n]);
      while (hits < max_hits) {
        const unsigned char *hit = find_bytes(scan, end, (const unsigned char *)needles[n], needle_len);
        if (!hit) {
          break;
        }
        log_scan_hit("string", needles[n], (uintptr_t)hit, allocation_base, region_base, mbi.Protect, mbi.Type, module_path);
        ++hits;
        scan = hit + 1;
      }
    }

    for (size_t p = 0; p < pattern_count; ++p) {
      const unsigned char *scan = begin;
      size_t hits = 0;
      while (hits < max_hits) {
        const unsigned char *hit = find_pattern(scan, end, &patterns[p]);
        if (!hit) {
          break;
        }
        log_scan_hit("signature", patterns[p].name, (uintptr_t)hit, allocation_base, region_base, mbi.Protect, mbi.Type, module_path);
        ++hits;
        scan = hit + 1;
      }
    }
  }

  line_init(&line);
  line_append(&line, "event=scan-finish");
  emit_line(&line);
}

static void probe_run(const char *phase) {
  int delay = env_int("UE4SSL_WIN_SNAPSHOT_DELAY_SECONDS", 0);
  if (delay > 0) {
    Sleep((DWORD)(delay * 1000));
  }

  static char exe_path[1024];
  static char dll_path[1024];
  GetModuleFileNameA(0, exe_path, sizeof(exe_path));
  GetModuleFileNameA(self_module, dll_path, sizeof(dll_path));

  static char safe_exe[1024];
  static char safe_dll[1024];
  static char safe_config[1024];
  safe_value(exe_path, safe_exe, sizeof(safe_exe));
  safe_value(dll_path, safe_dll, sizeof(safe_dll));
  safe_value(config_path, safe_config, sizeof(safe_config));

  static Line line;
  line_init(&line);
  line_append(&line, "event=loaded phase=");
  line_append(&line, phase);
  line_append(&line, " exe=");
  line_append(&line, safe_exe);
  line_append(&line, " dll=");
  line_append(&line, safe_dll);
  if (config_file_found) {
    line_append(&line, " config=");
    line_append(&line, safe_config);
  }
  line_append(&line, " native=pe note=not-ue4ss-yet");
  emit_line(&line);

  log_modules();
  run_scans();
  validate_ue_anchors(phase);
  run_hook_dispatch_self_test(phase);
  run_mod_dispatch_self_test(phase);
  run_lua_dispatch_self_test(phase);
  run_lua_reflection_self_test(phase);
  run_process_event_hook_probe(phase);
  run_lua_process_event_self_test(phase);
  run_lua_mod_entrypoints(phase);
  install_process_event_live_hook(phase);
}

static DWORD __stdcall probe_thread(LPVOID parameter) {
  (void)parameter;
  probe_run("thread");
  return 0;
}

static int mark_probe_started(void) {
  if (probe_started) {
    return 0;
  }
  probe_started = 1;
  return 1;
}

static void *real_version_proc(const char *name) {
  if (!real_version_module) {
    real_version_module = LoadLibraryA("C:\\windows\\system32\\version.dll");
    if (!real_version_module || real_version_module == self_module) {
      real_version_module = LoadLibraryA("version.dll");
    }
  }
  if (!real_version_module || real_version_module == self_module) {
    return 0;
  }
  return GetProcAddress(real_version_module, name);
}

typedef uintptr_t (__stdcall *Fn2)(uintptr_t, uintptr_t);
typedef uintptr_t (__stdcall *Fn3)(uintptr_t, uintptr_t, uintptr_t);
typedef uintptr_t (__stdcall *Fn4)(uintptr_t, uintptr_t, uintptr_t, uintptr_t);
typedef uintptr_t (__stdcall *Fn5)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t);
typedef uintptr_t (__stdcall *Fn8)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t);

static uintptr_t call2(const char *name, uintptr_t a, uintptr_t b) {
  Fn2 fn = (Fn2)real_version_proc(name);
  return fn ? fn(a, b) : 0;
}

static uintptr_t call3(const char *name, uintptr_t a, uintptr_t b, uintptr_t c) {
  Fn3 fn = (Fn3)real_version_proc(name);
  return fn ? fn(a, b, c) : 0;
}

static uintptr_t call4(const char *name, uintptr_t a, uintptr_t b, uintptr_t c, uintptr_t d) {
  Fn4 fn = (Fn4)real_version_proc(name);
  return fn ? fn(a, b, c, d) : 0;
}

static uintptr_t call5(const char *name, uintptr_t a, uintptr_t b, uintptr_t c, uintptr_t d, uintptr_t e) {
  Fn5 fn = (Fn5)real_version_proc(name);
  return fn ? fn(a, b, c, d, e) : 0;
}

static uintptr_t call8(const char *name, uintptr_t a, uintptr_t b, uintptr_t c, uintptr_t d, uintptr_t e, uintptr_t f, uintptr_t g, uintptr_t h) {
  Fn8 fn = (Fn8)real_version_proc(name);
  return fn ? fn(a, b, c, d, e, f, g, h) : 0;
}

__declspec(dllexport) int __stdcall UE4SSLWinProbeMarker(void) {
  return 0x44554e45;
}

__declspec(dllexport) void CALLBACK UE4SSLWinProbeSmoke(void *hwnd, HINSTANCE hinst, LPSTR cmdline, int show) {
  (void)hwnd;
  (void)hinst;
  (void)cmdline;
  (void)show;
  if (mark_probe_started()) {
    probe_run("smoke");
  } else {
    Sleep(1000);
  }
}

__declspec(dllexport) void CALLBACK UE4SSLWinProbeForwardSmoke(void *hwnd, HINSTANCE hinst, LPSTR cmdline, int show) {
  (void)hwnd;
  (void)hinst;
  (void)cmdline;
  (void)show;
  static const WCHAR kernel32_path[] = {
    'C', ':', '\\', 'w', 'i', 'n', 'd', 'o', 'w', 's', '\\',
    's', 'y', 's', 't', 'e', 'm', '3', '2', '\\',
    'k', 'e', 'r', 'n', 'e', 'l', '3', '2', '.', 'd', 'l', 'l', 0
  };
  DWORD handle = 0;
  uintptr_t size = call2("GetFileVersionInfoSizeW", (uintptr_t)kernel32_path, (uintptr_t)&handle);

  static Line line;
  line_init(&line);
  line_append(&line, "event=forward-smoke function=GetFileVersionInfoSizeW result=");
  line_append_dec(&line, size);
  line_append(&line, " handle=");
  line_append_hex(&line, handle);
  emit_line(&line);
}

__declspec(dllexport) uintptr_t __stdcall GetFileVersionInfoA(uintptr_t a, uintptr_t b, uintptr_t c, uintptr_t d) { return call4("GetFileVersionInfoA", a, b, c, d); }
__declspec(dllexport) uintptr_t __stdcall GetFileVersionInfoW(uintptr_t a, uintptr_t b, uintptr_t c, uintptr_t d) { return call4("GetFileVersionInfoW", a, b, c, d); }
__declspec(dllexport) uintptr_t __stdcall GetFileVersionInfoExA(uintptr_t a, uintptr_t b, uintptr_t c, uintptr_t d, uintptr_t e) { return call5("GetFileVersionInfoExA", a, b, c, d, e); }
__declspec(dllexport) uintptr_t __stdcall GetFileVersionInfoExW(uintptr_t a, uintptr_t b, uintptr_t c, uintptr_t d, uintptr_t e) { return call5("GetFileVersionInfoExW", a, b, c, d, e); }
__declspec(dllexport) uintptr_t __stdcall GetFileVersionInfoSizeA(uintptr_t a, uintptr_t b) { return call2("GetFileVersionInfoSizeA", a, b); }
__declspec(dllexport) uintptr_t __stdcall GetFileVersionInfoSizeW(uintptr_t a, uintptr_t b) { return call2("GetFileVersionInfoSizeW", a, b); }
__declspec(dllexport) uintptr_t __stdcall GetFileVersionInfoSizeExA(uintptr_t a, uintptr_t b, uintptr_t c) { return call3("GetFileVersionInfoSizeExA", a, b, c); }
__declspec(dllexport) uintptr_t __stdcall GetFileVersionInfoSizeExW(uintptr_t a, uintptr_t b, uintptr_t c) { return call3("GetFileVersionInfoSizeExW", a, b, c); }
__declspec(dllexport) uintptr_t __stdcall VerFindFileA(uintptr_t a, uintptr_t b, uintptr_t c, uintptr_t d, uintptr_t e, uintptr_t f, uintptr_t g, uintptr_t h) { return call8("VerFindFileA", a, b, c, d, e, f, g, h); }
__declspec(dllexport) uintptr_t __stdcall VerFindFileW(uintptr_t a, uintptr_t b, uintptr_t c, uintptr_t d, uintptr_t e, uintptr_t f, uintptr_t g, uintptr_t h) { return call8("VerFindFileW", a, b, c, d, e, f, g, h); }
__declspec(dllexport) uintptr_t __stdcall VerInstallFileA(uintptr_t a, uintptr_t b, uintptr_t c, uintptr_t d, uintptr_t e, uintptr_t f, uintptr_t g, uintptr_t h) { return call8("VerInstallFileA", a, b, c, d, e, f, g, h); }
__declspec(dllexport) uintptr_t __stdcall VerInstallFileW(uintptr_t a, uintptr_t b, uintptr_t c, uintptr_t d, uintptr_t e, uintptr_t f, uintptr_t g, uintptr_t h) { return call8("VerInstallFileW", a, b, c, d, e, f, g, h); }
__declspec(dllexport) uintptr_t __stdcall VerLanguageNameA(uintptr_t a, uintptr_t b, uintptr_t c) { return call3("VerLanguageNameA", a, b, c); }
__declspec(dllexport) uintptr_t __stdcall VerLanguageNameW(uintptr_t a, uintptr_t b, uintptr_t c) { return call3("VerLanguageNameW", a, b, c); }
__declspec(dllexport) uintptr_t __stdcall VerQueryValueA(uintptr_t a, uintptr_t b, uintptr_t c, uintptr_t d) { return call4("VerQueryValueA", a, b, c, d); }
__declspec(dllexport) uintptr_t __stdcall VerQueryValueW(uintptr_t a, uintptr_t b, uintptr_t c, uintptr_t d) { return call4("VerQueryValueW", a, b, c, d); }

BOOL WINAPI DllMain(HINSTANCE hinst, DWORD reason, LPVOID reserved) {
  (void)reserved;
  if (reason == DLL_PROCESS_ATTACH) {
    self_module = (HMODULE)hinst;
    DisableThreadLibraryCalls(self_module);
    if (env_bool("UE4SSL_WIN_AUTO_THREAD", 1) && mark_probe_started()) {
      HANDLE thread = CreateThread(0, 0, probe_thread, 0, 0, 0);
      if (thread && thread != INVALID_HANDLE_VALUE) {
        CloseHandle(thread);
      } else {
        probe_started = 0;
      }
    }
  } else if (reason == DLL_PROCESS_DETACH) {
    restore_process_event_live_hook("detach");
  }
  return TRUE;
}
