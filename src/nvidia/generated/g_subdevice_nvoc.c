#include "nvoc/runtime.h"
#include "nvoc/rtti.h"
#include "nvtypes.h"
#include "nvport/nvport.h"
#include "nvport/inline/util_valist.h"
#include "utils/nvassert.h"
#include "g_subdevice_nvoc.h"

#ifdef DEBUG
char __nvoc_class_id_uniqueness_check_0x4b01b3 = 1;
#endif

extern const struct NVOC_CLASS_DEF __nvoc_class_def_Subdevice;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_Object;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_RsResource;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_RmResourceCommon;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_RmResource;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_GpuResource;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_INotifier;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_Notifier;

void __nvoc_init_Subdevice(Subdevice*);
void __nvoc_init_funcTable_Subdevice(Subdevice*);
NV_STATUS __nvoc_ctor_Subdevice(Subdevice*, struct CALL_CONTEXT * arg_pCallContext, struct RS_RES_ALLOC_PARAMS_INTERNAL * arg_pParams);
void __nvoc_init_dataField_Subdevice(Subdevice*);
void __nvoc_dtor_Subdevice(Subdevice*);
extern const struct NVOC_EXPORT_INFO __nvoc_export_info_Subdevice;

static const struct NVOC_RTTI __nvoc_rtti_Subdevice_Subdevice = {
    /*pClassDef=*/          &__nvoc_class_def_Subdevice,
    /*dtor=*/               (NVOC_DYNAMIC_DTOR) &__nvoc_dtor_Subdevice,
    /*offset=*/             0,
};

static const struct NVOC_RTTI __nvoc_rtti_Subdevice_Object = {
    /*pClassDef=*/          &__nvoc_class_def_Object,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(Subdevice, __nvoc_base_GpuResource.__nvoc_base_RmResource.__nvoc_base_RsResource.__nvoc_base_Object),
};

static const struct NVOC_RTTI __nvoc_rtti_Subdevice_RsResource = {
    /*pClassDef=*/          &__nvoc_class_def_RsResource,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(Subdevice, __nvoc_base_GpuResource.__nvoc_base_RmResource.__nvoc_base_RsResource),
};

static const struct NVOC_RTTI __nvoc_rtti_Subdevice_RmResourceCommon = {
    /*pClassDef=*/          &__nvoc_class_def_RmResourceCommon,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(Subdevice, __nvoc_base_GpuResource.__nvoc_base_RmResource.__nvoc_base_RmResourceCommon),
};

static const struct NVOC_RTTI __nvoc_rtti_Subdevice_RmResource = {
    /*pClassDef=*/          &__nvoc_class_def_RmResource,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(Subdevice, __nvoc_base_GpuResource.__nvoc_base_RmResource),
};

static const struct NVOC_RTTI __nvoc_rtti_Subdevice_GpuResource = {
    /*pClassDef=*/          &__nvoc_class_def_GpuResource,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(Subdevice, __nvoc_base_GpuResource),
};

static const struct NVOC_RTTI __nvoc_rtti_Subdevice_INotifier = {
    /*pClassDef=*/          &__nvoc_class_def_INotifier,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(Subdevice, __nvoc_base_Notifier.__nvoc_base_INotifier),
};

static const struct NVOC_RTTI __nvoc_rtti_Subdevice_Notifier = {
    /*pClassDef=*/          &__nvoc_class_def_Notifier,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(Subdevice, __nvoc_base_Notifier),
};

static const struct NVOC_CASTINFO __nvoc_castinfo_Subdevice = {
    /*numRelatives=*/       8,
    /*relatives=*/ {
        &__nvoc_rtti_Subdevice_Subdevice,
        &__nvoc_rtti_Subdevice_Notifier,
        &__nvoc_rtti_Subdevice_INotifier,
        &__nvoc_rtti_Subdevice_GpuResource,
        &__nvoc_rtti_Subdevice_RmResource,
        &__nvoc_rtti_Subdevice_RmResourceCommon,
        &__nvoc_rtti_Subdevice_RsResource,
        &__nvoc_rtti_Subdevice_Object,
    },
};

const struct NVOC_CLASS_DEF __nvoc_class_def_Subdevice = 
{
    /*classInfo=*/ {
        /*size=*/               sizeof(Subdevice),
        /*classId=*/            classId(Subdevice),
        /*providerId=*/         &__nvoc_rtti_provider,
#if NV_PRINTF_STRINGS_ALLOWED
        /*name=*/               "Subdevice",
#endif
    },
    /*objCreatefn=*/        (NVOC_DYNAMIC_OBJ_CREATE) &__nvoc_objCreateDynamic_Subdevice,
    /*pCastInfo=*/          &__nvoc_castinfo_Subdevice,
    /*pExportInfo=*/        &__nvoc_export_info_Subdevice
};

static void __nvoc_thunk_Subdevice_resPreDestruct(struct RsResource *pResource) {
    subdevicePreDestruct((struct Subdevice *)(((unsigned char *)pResource) - __nvoc_rtti_Subdevice_RsResource.offset));
}

static NV_STATUS __nvoc_thunk_Subdevice_gpuresInternalControlForward(struct GpuResource *pSubdevice, NvU32 command, void *pParams, NvU32 size) {
    return subdeviceInternalControlForward((struct Subdevice *)(((unsigned char *)pSubdevice) - __nvoc_rtti_Subdevice_GpuResource.offset), command, pParams, size);
}

static NV_STATUS __nvoc_thunk_Subdevice_resControlFilter(struct RsResource *pSubdevice, struct CALL_CONTEXT *pCallContext, struct RS_RES_CONTROL_PARAMS_INTERNAL *pParams) {
    return subdeviceControlFilter((struct Subdevice *)(((unsigned char *)pSubdevice) - __nvoc_rtti_Subdevice_RsResource.offset), pCallContext, pParams);
}

static NvBool __nvoc_thunk_GpuResource_subdeviceShareCallback(struct Subdevice *pGpuResource, struct RsClient *pInvokingClient, struct RsResourceRef *pParentRef, RS_SHARE_POLICY *pSharePolicy) {
    return gpuresShareCallback((struct GpuResource *)(((unsigned char *)pGpuResource) + __nvoc_rtti_Subdevice_GpuResource.offset), pInvokingClient, pParentRef, pSharePolicy);
}

static NV_STATUS __nvoc_thunk_RsResource_subdeviceMapTo(struct Subdevice *pResource, RS_RES_MAP_TO_PARAMS *pParams) {
    return resMapTo((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_Subdevice_RsResource.offset), pParams);
}

static NV_STATUS __nvoc_thunk_Notifier_subdeviceGetOrAllocNotifShare(struct Subdevice *pNotifier, NvHandle hNotifierClient, NvHandle hNotifierResource, struct NotifShare **ppNotifShare) {
    return notifyGetOrAllocNotifShare((struct Notifier *)(((unsigned char *)pNotifier) + __nvoc_rtti_Subdevice_Notifier.offset), hNotifierClient, hNotifierResource, ppNotifShare);
}

static NV_STATUS __nvoc_thunk_RmResource_subdeviceCheckMemInterUnmap(struct Subdevice *pRmResource, NvBool bSubdeviceHandleProvided) {
    return rmresCheckMemInterUnmap((struct RmResource *)(((unsigned char *)pRmResource) + __nvoc_rtti_Subdevice_RmResource.offset), bSubdeviceHandleProvided);
}

static NV_STATUS __nvoc_thunk_GpuResource_subdeviceGetMapAddrSpace(struct Subdevice *pGpuResource, struct CALL_CONTEXT *pCallContext, NvU32 mapFlags, NV_ADDRESS_SPACE *pAddrSpace) {
    return gpuresGetMapAddrSpace((struct GpuResource *)(((unsigned char *)pGpuResource) + __nvoc_rtti_Subdevice_GpuResource.offset), pCallContext, mapFlags, pAddrSpace);
}

static void __nvoc_thunk_Notifier_subdeviceSetNotificationShare(struct Subdevice *pNotifier, struct NotifShare *pNotifShare) {
    notifySetNotificationShare((struct Notifier *)(((unsigned char *)pNotifier) + __nvoc_rtti_Subdevice_Notifier.offset), pNotifShare);
}

static NvU32 __nvoc_thunk_RsResource_subdeviceGetRefCount(struct Subdevice *pResource) {
    return resGetRefCount((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_Subdevice_RsResource.offset));
}

static void __nvoc_thunk_RsResource_subdeviceAddAdditionalDependants(struct RsClient *pClient, struct Subdevice *pResource, RsResourceRef *pReference) {
    resAddAdditionalDependants(pClient, (struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_Subdevice_RsResource.offset), pReference);
}

static NV_STATUS __nvoc_thunk_RmResource_subdeviceControl_Prologue(struct Subdevice *pResource, struct CALL_CONTEXT *pCallContext, struct RS_RES_CONTROL_PARAMS_INTERNAL *pParams) {
    return rmresControl_Prologue((struct RmResource *)(((unsigned char *)pResource) + __nvoc_rtti_Subdevice_RmResource.offset), pCallContext, pParams);
}

static NV_STATUS __nvoc_thunk_GpuResource_subdeviceGetRegBaseOffsetAndSize(struct Subdevice *pGpuResource, struct OBJGPU *pGpu, NvU32 *pOffset, NvU32 *pSize) {
    return gpuresGetRegBaseOffsetAndSize((struct GpuResource *)(((unsigned char *)pGpuResource) + __nvoc_rtti_Subdevice_GpuResource.offset), pGpu, pOffset, pSize);
}

static NV_STATUS __nvoc_thunk_RsResource_subdeviceUnmapFrom(struct Subdevice *pResource, RS_RES_UNMAP_FROM_PARAMS *pParams) {
    return resUnmapFrom((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_Subdevice_RsResource.offset), pParams);
}

static void __nvoc_thunk_RmResource_subdeviceControl_Epilogue(struct Subdevice *pResource, struct CALL_CONTEXT *pCallContext, struct RS_RES_CONTROL_PARAMS_INTERNAL *pParams) {
    rmresControl_Epilogue((struct RmResource *)(((unsigned char *)pResource) + __nvoc_rtti_Subdevice_RmResource.offset), pCallContext, pParams);
}

static NV_STATUS __nvoc_thunk_RsResource_subdeviceControlLookup(struct Subdevice *pResource, struct RS_RES_CONTROL_PARAMS_INTERNAL *pParams, const struct NVOC_EXPORTED_METHOD_DEF **ppEntry) {
    return resControlLookup((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_Subdevice_RsResource.offset), pParams, ppEntry);
}

static NvHandle __nvoc_thunk_GpuResource_subdeviceGetInternalObjectHandle(struct Subdevice *pGpuResource) {
    return gpuresGetInternalObjectHandle((struct GpuResource *)(((unsigned char *)pGpuResource) + __nvoc_rtti_Subdevice_GpuResource.offset));
}

static NV_STATUS __nvoc_thunk_GpuResource_subdeviceControl(struct Subdevice *pGpuResource, struct CALL_CONTEXT *pCallContext, struct RS_RES_CONTROL_PARAMS_INTERNAL *pParams) {
    return gpuresControl((struct GpuResource *)(((unsigned char *)pGpuResource) + __nvoc_rtti_Subdevice_GpuResource.offset), pCallContext, pParams);
}

static NV_STATUS __nvoc_thunk_GpuResource_subdeviceUnmap(struct Subdevice *pGpuResource, struct CALL_CONTEXT *pCallContext, struct RsCpuMapping *pCpuMapping) {
    return gpuresUnmap((struct GpuResource *)(((unsigned char *)pGpuResource) + __nvoc_rtti_Subdevice_GpuResource.offset), pCallContext, pCpuMapping);
}

static NV_STATUS __nvoc_thunk_RmResource_subdeviceGetMemInterMapParams(struct Subdevice *pRmResource, RMRES_MEM_INTER_MAP_PARAMS *pParams) {
    return rmresGetMemInterMapParams((struct RmResource *)(((unsigned char *)pRmResource) + __nvoc_rtti_Subdevice_RmResource.offset), pParams);
}

static NV_STATUS __nvoc_thunk_Notifier_subdeviceUnregisterEvent(struct Subdevice *pNotifier, NvHandle hNotifierClient, NvHandle hNotifierResource, NvHandle hEventClient, NvHandle hEvent) {
    return notifyUnregisterEvent((struct Notifier *)(((unsigned char *)pNotifier) + __nvoc_rtti_Subdevice_Notifier.offset), hNotifierClient, hNotifierResource, hEventClient, hEvent);
}

static NvBool __nvoc_thunk_RsResource_subdeviceCanCopy(struct Subdevice *pResource) {
    return resCanCopy((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_Subdevice_RsResource.offset));
}

static PEVENTNOTIFICATION *__nvoc_thunk_Notifier_subdeviceGetNotificationListPtr(struct Subdevice *pNotifier) {
    return notifyGetNotificationListPtr((struct Notifier *)(((unsigned char *)pNotifier) + __nvoc_rtti_Subdevice_Notifier.offset));
}

static struct NotifShare *__nvoc_thunk_Notifier_subdeviceGetNotificationShare(struct Subdevice *pNotifier) {
    return notifyGetNotificationShare((struct Notifier *)(((unsigned char *)pNotifier) + __nvoc_rtti_Subdevice_Notifier.offset));
}

static NV_STATUS __nvoc_thunk_GpuResource_subdeviceMap(struct Subdevice *pGpuResource, struct CALL_CONTEXT *pCallContext, struct RS_CPU_MAP_PARAMS *pParams, struct RsCpuMapping *pCpuMapping) {
    return gpuresMap((struct GpuResource *)(((unsigned char *)pGpuResource) + __nvoc_rtti_Subdevice_GpuResource.offset), pCallContext, pParams, pCpuMapping);
}

static NvBool __nvoc_thunk_RmResource_subdeviceAccessCallback(struct Subdevice *pResource, struct RsClient *pInvokingClient, void *pAllocParams, RsAccessRight accessRight) {
    return rmresAccessCallback((struct RmResource *)(((unsigned char *)pResource) + __nvoc_rtti_Subdevice_RmResource.offset), pInvokingClient, pAllocParams, accessRight);
}

static const struct NVOC_EXPORTED_METHOD_DEF __nvoc_exported_method_def_Subdevice[] = 
{
    {               /*  [0] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdGpuGetInfo_IMPL,
        /*flags=*/      0x850u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800101u,
        /*paramSize=*/  sizeof(NV2080_CTRL_GPU_GET_INFO_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdGpuGetInfo"
#endif
    },
    {               /*  [1] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdGpuGetInfoV2_IMPL,
        /*flags=*/      0x50u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800102u,
        /*paramSize=*/  sizeof(NV2080_CTRL_GPU_GET_INFO_V2_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdGpuGetInfoV2"
#endif
    },
    {               /*  [2] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdGpuGetNameString_IMPL,
        /*flags=*/      0xa10u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800110u,
        /*paramSize=*/  sizeof(NV2080_CTRL_GPU_GET_NAME_STRING_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdGpuGetNameString"
#endif
    },
    {               /*  [3] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdGpuGetShortNameString_IMPL,
        /*flags=*/      0x4a10u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800111u,
        /*paramSize=*/  sizeof(NV2080_CTRL_GPU_GET_SHORT_NAME_STRING_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdGpuGetShortNameString"
#endif
    },
    {               /*  [4] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdGpuGetSdm_IMPL,
        /*flags=*/      0x11u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800118u,
        /*paramSize=*/  sizeof(NV2080_CTRL_GPU_GET_SDM_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdGpuGetSdm"
#endif
    },
    {               /*  [5] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdGpuGetSimulationInfo_IMPL,
        /*flags=*/      0x813u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800119u,
        /*paramSize=*/  sizeof(NV2080_CTRL_GPU_GET_SIMULATION_INFO_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdGpuGetSimulationInfo"
#endif
    },
    {               /*  [6] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdGpuSetSdm_IMPL,
        /*flags=*/      0x5u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800120u,
        /*paramSize=*/  sizeof(NV2080_CTRL_GPU_SET_SDM_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdGpuSetSdm"
#endif
    },
    {               /*  [7] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdGpuGetEngines_IMPL,
        /*flags=*/      0x811u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800123u,
        /*paramSize=*/  sizeof(NV2080_CTRL_GPU_GET_ENGINES_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdGpuGetEngines"
#endif
    },
    {               /*  [8] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdGpuGetEngineClasslist_IMPL,
        /*flags=*/      0x811u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800124u,
        /*paramSize=*/  sizeof(NV2080_CTRL_GPU_GET_ENGINE_CLASSLIST_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdGpuGetEngineClasslist"
#endif
    },
    {               /*  [9] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdGpuQueryMode_IMPL,
        /*flags=*/      0x10u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800128u,
        /*paramSize=*/  sizeof(NV2080_CTRL_GPU_QUERY_MODE_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdGpuQueryMode"
#endif
    },
    {               /*  [10] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdGpuPromoteCtx_IMPL,
        /*flags=*/      0x2204u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x2080012bu,
        /*paramSize=*/  sizeof(NV2080_CTRL_GPU_PROMOTE_CTX_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdGpuPromoteCtx"
#endif
    },
    {               /*  [11] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdGpuEvictCtx_IMPL,
        /*flags=*/      0x2200u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x2080012cu,
        /*paramSize=*/  sizeof(NV2080_CTRL_GPU_EVICT_CTX_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdGpuEvictCtx"
#endif
    },
    {               /*  [12] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdGpuInitializeCtx_IMPL,
        /*flags=*/      0x2210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x2080012du,
        /*paramSize=*/  sizeof(NV2080_CTRL_GPU_INITIALIZE_CTX_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdGpuInitializeCtx"
#endif
    },
    {               /*  [13] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdGpuGetOEMBoardInfo_IMPL,
        /*flags=*/      0x4210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x2080013fu,
        /*paramSize=*/  sizeof(NV2080_CTRL_GPU_GET_OEM_BOARD_INFO_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdGpuGetOEMBoardInfo"
#endif
    },
    {               /*  [14] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdGpuGetId_IMPL,
        /*flags=*/      0x812u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800142u,
        /*paramSize=*/  sizeof(NV2080_CTRL_GPU_GET_ID_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdGpuGetId"
#endif
    },
    {               /*  [15] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdGpuSetGpuDebugMode_IMPL,
        /*flags=*/      0x11u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800143u,
        /*paramSize=*/  sizeof(NV2080_CTRL_GPU_SET_GPU_DEBUG_MODE_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdGpuSetGpuDebugMode"
#endif
    },
    {               /*  [16] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdGpuGetGpuDebugMode_IMPL,
        /*flags=*/      0x11u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800144u,
        /*paramSize=*/  sizeof(NV2080_CTRL_GPU_GET_GPU_DEBUG_MODE_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdGpuGetGpuDebugMode"
#endif
    },
    {               /*  [17] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdGpuGetEnginePartnerList_IMPL,
        /*flags=*/      0x850u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800147u,
        /*paramSize=*/  sizeof(NV2080_CTRL_GPU_GET_ENGINE_PARTNERLIST_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdGpuGetEnginePartnerList"
#endif
    },
    {               /*  [18] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdGpuGetGidInfo_IMPL,
        /*flags=*/      0xa50u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x2080014au,
        /*paramSize=*/  sizeof(NV2080_CTRL_GPU_GET_GID_INFO_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdGpuGetGidInfo"
#endif
    },
    {               /*  [19] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdGpuSetOptimusInfo_IMPL,
        /*flags=*/      0x10u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x2080014cu,
        /*paramSize=*/  sizeof(NV2080_CTRL_GPU_OPTIMUS_INFO_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdGpuSetOptimusInfo"
#endif
    },
    {               /*  [20] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdGpuGetIpVersion_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x2080014du,
        /*paramSize=*/  sizeof(NV2080_CTRL_GPU_GET_IP_VERSION_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdGpuGetIpVersion"
#endif
    },
    {               /*  [21] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdGpuHandleGpuSR_IMPL,
        /*flags=*/      0x13u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800167u,
        /*paramSize=*/  0,
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdGpuHandleGpuSR"
#endif
    },
    {               /*  [22] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdGpuGetOEMInfo_IMPL,
        /*flags=*/      0x4210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800169u,
        /*paramSize=*/  sizeof(NV2080_CTRL_GPU_GET_OEM_INFO_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdGpuGetOEMInfo"
#endif
    },
    {               /*  [23] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdGpuGetEnginesV2_IMPL,
        /*flags=*/      0x811u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800170u,
        /*paramSize=*/  sizeof(NV2080_CTRL_GPU_GET_ENGINES_V2_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdGpuGetEnginesV2"
#endif
    },
    {               /*  [24] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdGpuQueryFunctionStatus_IMPL,
        /*flags=*/      0x10u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800173u,
        /*paramSize=*/  sizeof(NV2080_CTRL_CMD_GPU_QUERY_FUNCTION_STATUS_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdGpuQueryFunctionStatus"
#endif
    },
    {               /*  [25] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdGpuGetCachedInfo_IMPL,
        /*flags=*/      0x13u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800182u,
        /*paramSize=*/  sizeof(NV2080_CTRL_GPU_GET_INFO_V2_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdGpuGetCachedInfo"
#endif
    },
    {               /*  [26] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdGpuGetMaxSupportedPageSize_IMPL,
        /*flags=*/      0x50u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800188u,
        /*paramSize=*/  sizeof(NV2080_CTRL_GPU_GET_MAX_SUPPORTED_PAGE_SIZE_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdGpuGetMaxSupportedPageSize"
#endif
    },
    {               /*  [27] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdGpuGetPids_IMPL,
        /*flags=*/      0x10u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x2080018du,
        /*paramSize=*/  sizeof(NV2080_CTRL_GPU_GET_PIDS_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdGpuGetPids"
#endif
    },
    {               /*  [28] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdGpuGetPidInfo_IMPL,
        /*flags=*/      0x10u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x2080018eu,
        /*paramSize=*/  sizeof(NV2080_CTRL_GPU_GET_PID_INFO_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdGpuGetPidInfo"
#endif
    },
    {               /*  [29] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdValidateMemMapRequest_IMPL,
        /*flags=*/      0x0u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800198u,
        /*paramSize=*/  sizeof(NV2080_CTRL_GPU_VALIDATE_MEM_MAP_REQUEST_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdValidateMemMapRequest"
#endif
    },
    {               /*  [30] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdGpuGetEngineLoadTimes_IMPL,
        /*flags=*/      0x12u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x2080019bu,
        /*paramSize=*/  sizeof(NV2080_CTRL_GPU_GET_ENGINE_LOAD_TIMES_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdGpuGetEngineLoadTimes"
#endif
    },
    {               /*  [31] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdEventSetNotification_IMPL,
        /*flags=*/      0x10u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800301u,
        /*paramSize=*/  sizeof(NV2080_CTRL_EVENT_SET_NOTIFICATION_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdEventSetNotification"
#endif
    },
    {               /*  [32] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdEventSetTrigger_IMPL,
        /*flags=*/      0x10u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800302u,
        /*paramSize=*/  0,
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdEventSetTrigger"
#endif
    },
    {               /*  [33] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdEventSetMemoryNotifies_IMPL,
        /*flags=*/      0x10u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800303u,
        /*paramSize=*/  sizeof(NV2080_CTRL_EVENT_SET_MEMORY_NOTIFIES_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdEventSetMemoryNotifies"
#endif
    },
    {               /*  [34] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdEventSetSemaphoreMemory_IMPL,
        /*flags=*/      0x10u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800304u,
        /*paramSize=*/  sizeof(NV2080_CTRL_EVENT_SET_SEMAPHORE_MEMORY_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdEventSetSemaphoreMemory"
#endif
    },
    {               /*  [35] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdEventSetSemaMemValidation_IMPL,
        /*flags=*/      0x10u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800306u,
        /*paramSize=*/  sizeof(NV2080_CTRL_EVENT_SET_SEMA_MEM_VALIDATION_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdEventSetSemaMemValidation"
#endif
    },
    {               /*  [36] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdEventSetTriggerFifo_IMPL,
        /*flags=*/      0x11u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800308u,
        /*paramSize=*/  sizeof(NV2080_CTRL_EVENT_SET_TRIGGER_FIFO_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdEventSetTriggerFifo"
#endif
    },
    {               /*  [37] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdTimerSchedule_IMPL,
        /*flags=*/      0x10u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800401u,
        /*paramSize=*/  sizeof(NV2080_CTRL_CMD_TIMER_SCHEDULE_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdTimerSchedule"
#endif
    },
    {               /*  [38] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdTimerCancel_IMPL,
        /*flags=*/      0x10u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800402u,
        /*paramSize=*/  0,
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdTimerCancel"
#endif
    },
    {               /*  [39] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdTimerGetTime_IMPL,
        /*flags=*/      0x10u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800403u,
        /*paramSize=*/  sizeof(NV2080_CTRL_TIMER_GET_TIME_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdTimerGetTime"
#endif
    },
    {               /*  [40] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdTimerGetRegisterOffset_IMPL,
        /*flags=*/      0x11u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800404u,
        /*paramSize=*/  sizeof(NV2080_CTRL_TIMER_GET_REGISTER_OFFSET_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdTimerGetRegisterOffset"
#endif
    },
    {               /*  [41] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdTimerGetGpuCpuTimeCorrelationInfo_IMPL,
        /*flags=*/      0x10u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800406u,
        /*paramSize=*/  sizeof(NV2080_CTRL_TIMER_GET_GPU_CPU_TIME_CORRELATION_INFO_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdTimerGetGpuCpuTimeCorrelationInfo"
#endif
    },
    {               /*  [42] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdDisplayGetStaticInfo_IMPL,
        /*flags=*/      0x600u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800a01u,
        /*paramSize=*/  sizeof(NV2080_CTRL_INTERNAL_DISPLAY_GET_STATIC_INFO_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdDisplayGetStaticInfo"
#endif
    },
    {               /*  [43] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdInternalGetChipInfo_IMPL,
        /*flags=*/      0x4600u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800a36u,
        /*paramSize=*/  sizeof(NV2080_CTRL_INTERNAL_GPU_GET_CHIP_INFO_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdInternalGetChipInfo"
#endif
    },
    {               /*  [44] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdInternalGetDeviceInfoTable_IMPL,
        /*flags=*/      0x4600u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800a40u,
        /*paramSize=*/  sizeof(NV2080_CTRL_INTERNAL_GET_DEVICE_INFO_TABLE_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdInternalGetDeviceInfoTable"
#endif
    },
    {               /*  [45] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdDisplayWriteInstMem_IMPL,
        /*flags=*/      0x600u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800a49u,
        /*paramSize=*/  sizeof(NV2080_CTRL_INTERNAL_DISPLAY_WRITE_INST_MEM_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdDisplayWriteInstMem"
#endif
    },
    {               /*  [46] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdInternalRecoverAllComputeContexts_IMPL,
        /*flags=*/      0x600u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800a4au,
        /*paramSize=*/  0,
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdInternalRecoverAllComputeContexts"
#endif
    },
    {               /*  [47] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdDisplayGetIpVersion_IMPL,
        /*flags=*/      0x600u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800a4bu,
        /*paramSize=*/  sizeof(NV2080_CTRL_INTERNAL_DISPLAY_GET_IP_VERSION_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdDisplayGetIpVersion"
#endif
    },
    {               /*  [48] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdInternalGetSmcMode_IMPL,
        /*flags=*/      0x600u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800a4cu,
        /*paramSize=*/  sizeof(NV2080_CTRL_INTERNAL_GPU_GET_SMC_MODE_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdInternalGetSmcMode"
#endif
    },
    {               /*  [49] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdDisplaySetupRgLineIntr_IMPL,
        /*flags=*/      0x600u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800a4du,
        /*paramSize=*/  sizeof(NV2080_CTRL_INTERNAL_DISPLAY_SETUP_RG_LINE_INTR_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdDisplaySetupRgLineIntr"
#endif
    },
    {               /*  [50] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdDisplaySetImportedImpData_IMPL,
        /*flags=*/      0x600u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800a54u,
        /*paramSize=*/  sizeof(NV2080_CTRL_INTERNAL_DISPLAY_SET_IMP_INIT_INFO_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdDisplaySetImportedImpData"
#endif
    },
    {               /*  [51] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdDisplaySetChannelPushbuffer_IMPL,
        /*flags=*/      0x600u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800a58u,
        /*paramSize=*/  sizeof(NV2080_CTRL_INTERNAL_DISPLAY_CHANNEL_PUSHBUFFER_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdDisplaySetChannelPushbuffer"
#endif
    },
    {               /*  [52] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdDisplayGetDisplayMask_IMPL,
        /*flags=*/      0x600u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20800a5du,
        /*paramSize=*/  sizeof(NV2080_CTRL_INTERNAL_DISPLAY_GET_ACTIVE_DISPLAY_DEVICES_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdDisplayGetDisplayMask"
#endif
    },
    {               /*  [53] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdEccGetAggregateErrorCounts_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20803401u,
        /*paramSize=*/  sizeof(NV2080_CTRL_ECC_GET_AGGREGATE_ERROR_COUNTS_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdEccGetAggregateErrorCounts"
#endif
    },
    {               /*  [54] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdEccGetDetailedAggregateErrorCounts_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20803402u,
        /*paramSize=*/  sizeof(NV2080_CTRL_ECC_GET_DETAILED_AGGREGATE_ERROR_COUNTS_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdEccGetDetailedAggregateErrorCounts"
#endif
    },
    {               /*  [55] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdEccGetDetailedErrorCounts_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20803403u,
        /*paramSize=*/  sizeof(NV2080_CTRL_ECC_GET_DETAILED_ERROR_COUNTS_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdEccGetDetailedErrorCounts"
#endif
    },
    {               /*  [56] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdEccGetLatestEccAddresses_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20803407u,
        /*paramSize=*/  sizeof(NV2080_CTRL_ECC_GET_LATEST_ECC_ADDRESSES_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdEccGetLatestEccAddresses"
#endif
    },
    {               /*  [57] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdEccGetClientExposedCounters_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20803408u,
        /*paramSize=*/  sizeof(NV2080_CTRL_ECC_GET_CLIENT_EXPOSED_COUNTERS_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdEccGetClientExposedCounters"
#endif
    },
    {               /*  [58] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdGspGetFeatures_IMPL,
        /*flags=*/      0x211u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20803601u,
        /*paramSize=*/  sizeof(NV2080_CTRL_GSP_GET_FEATURES_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdGspGetFeatures"
#endif
    },
    {               /*  [59] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdOsUnixGc6BlockerRefCnt_IMPL,
        /*flags=*/      0x3u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20803d01u,
        /*paramSize=*/  sizeof(NV2080_CTRL_OS_UNIX_GC6_BLOCKER_REFCNT_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdOsUnixGc6BlockerRefCnt"
#endif
    },
    {               /*  [60] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdOsUnixAllowDisallowGcoff_IMPL,
        /*flags=*/      0x11u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20803d02u,
        /*paramSize=*/  sizeof(NV2080_CTRL_OS_UNIX_ALLOW_DISALLOW_GCOFF_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdOsUnixAllowDisallowGcoff"
#endif
    },
    {               /*  [61] */
        /*pFunc=*/      (void (*)(void)) subdeviceCtrlCmdOsUnixAudioDynamicPower_IMPL,
        /*flags=*/      0x1u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x20803d03u,
        /*paramSize=*/  sizeof(NV2080_CTRL_OS_UNIX_AUDIO_DYNAMIC_POWER_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_Subdevice.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "subdeviceCtrlCmdOsUnixAudioDynamicPower"
#endif
    },

};

const struct NVOC_EXPORT_INFO __nvoc_export_info_Subdevice = 
{
    /*numEntries=*/     62,
    /*pExportEntries=*/ __nvoc_exported_method_def_Subdevice
};

void __nvoc_dtor_GpuResource(GpuResource*);
void __nvoc_dtor_Notifier(Notifier*);
void __nvoc_dtor_Subdevice(Subdevice *pThis) {
    __nvoc_subdeviceDestruct(pThis);
    __nvoc_dtor_GpuResource(&pThis->__nvoc_base_GpuResource);
    __nvoc_dtor_Notifier(&pThis->__nvoc_base_Notifier);
    PORT_UNREFERENCED_VARIABLE(pThis);
}

void __nvoc_init_dataField_Subdevice(Subdevice *pThis) {
    PORT_UNREFERENCED_VARIABLE(pThis);
}

NV_STATUS __nvoc_ctor_GpuResource(GpuResource* , struct CALL_CONTEXT *, struct RS_RES_ALLOC_PARAMS_INTERNAL *);
NV_STATUS __nvoc_ctor_Notifier(Notifier* , struct CALL_CONTEXT *);
NV_STATUS __nvoc_ctor_Subdevice(Subdevice *pThis, struct CALL_CONTEXT * arg_pCallContext, struct RS_RES_ALLOC_PARAMS_INTERNAL * arg_pParams) {
    NV_STATUS status = NV_OK;
    status = __nvoc_ctor_GpuResource(&pThis->__nvoc_base_GpuResource, arg_pCallContext, arg_pParams);
    if (status != NV_OK) goto __nvoc_ctor_Subdevice_fail_GpuResource;
    status = __nvoc_ctor_Notifier(&pThis->__nvoc_base_Notifier, arg_pCallContext);
    if (status != NV_OK) goto __nvoc_ctor_Subdevice_fail_Notifier;
    __nvoc_init_dataField_Subdevice(pThis);

    status = __nvoc_subdeviceConstruct(pThis, arg_pCallContext, arg_pParams);
    if (status != NV_OK) goto __nvoc_ctor_Subdevice_fail__init;
    goto __nvoc_ctor_Subdevice_exit; // Success

__nvoc_ctor_Subdevice_fail__init:
    __nvoc_dtor_Notifier(&pThis->__nvoc_base_Notifier);
__nvoc_ctor_Subdevice_fail_Notifier:
    __nvoc_dtor_GpuResource(&pThis->__nvoc_base_GpuResource);
__nvoc_ctor_Subdevice_fail_GpuResource:
__nvoc_ctor_Subdevice_exit:

    return status;
}

static void __nvoc_init_funcTable_Subdevice_1(Subdevice *pThis) {
    PORT_UNREFERENCED_VARIABLE(pThis);

    pThis->__subdevicePreDestruct__ = &subdevicePreDestruct_IMPL;

    pThis->__subdeviceInternalControlForward__ = &subdeviceInternalControlForward_IMPL;

    pThis->__subdeviceControlFilter__ = &subdeviceControlFilter_IMPL;

    pThis->__subdeviceCtrlCmdGpuGetCachedInfo__ = &subdeviceCtrlCmdGpuGetCachedInfo_IMPL;

    pThis->__subdeviceCtrlCmdGpuGetInfo__ = &subdeviceCtrlCmdGpuGetInfo_IMPL;

    pThis->__subdeviceCtrlCmdGpuGetInfoV2__ = &subdeviceCtrlCmdGpuGetInfoV2_IMPL;

    pThis->__subdeviceCtrlCmdGpuGetIpVersion__ = &subdeviceCtrlCmdGpuGetIpVersion_IMPL;

    pThis->__subdeviceCtrlCmdGpuSetOptimusInfo__ = &subdeviceCtrlCmdGpuSetOptimusInfo_IMPL;

    pThis->__subdeviceCtrlCmdGpuGetNameString__ = &subdeviceCtrlCmdGpuGetNameString_IMPL;

    pThis->__subdeviceCtrlCmdGpuGetShortNameString__ = &subdeviceCtrlCmdGpuGetShortNameString_IMPL;

    pThis->__subdeviceCtrlCmdGpuGetSdm__ = &subdeviceCtrlCmdGpuGetSdm_IMPL;

    pThis->__subdeviceCtrlCmdGpuSetSdm__ = &subdeviceCtrlCmdGpuSetSdm_IMPL;

    pThis->__subdeviceCtrlCmdGpuGetSimulationInfo__ = &subdeviceCtrlCmdGpuGetSimulationInfo_IMPL;

    pThis->__subdeviceCtrlCmdGpuGetEngines__ = &subdeviceCtrlCmdGpuGetEngines_IMPL;

    pThis->__subdeviceCtrlCmdGpuGetEnginesV2__ = &subdeviceCtrlCmdGpuGetEnginesV2_IMPL;

    pThis->__subdeviceCtrlCmdGpuGetEngineClasslist__ = &subdeviceCtrlCmdGpuGetEngineClasslist_IMPL;

    pThis->__subdeviceCtrlCmdGpuGetEnginePartnerList__ = &subdeviceCtrlCmdGpuGetEnginePartnerList_IMPL;

    pThis->__subdeviceCtrlCmdGpuQueryMode__ = &subdeviceCtrlCmdGpuQueryMode_IMPL;

    pThis->__subdeviceCtrlCmdGpuGetOEMBoardInfo__ = &subdeviceCtrlCmdGpuGetOEMBoardInfo_IMPL;

    pThis->__subdeviceCtrlCmdGpuGetOEMInfo__ = &subdeviceCtrlCmdGpuGetOEMInfo_IMPL;

    pThis->__subdeviceCtrlCmdGpuHandleGpuSR__ = &subdeviceCtrlCmdGpuHandleGpuSR_IMPL;

    pThis->__subdeviceCtrlCmdGpuSetGpuDebugMode__ = &subdeviceCtrlCmdGpuSetGpuDebugMode_IMPL;

    pThis->__subdeviceCtrlCmdGpuGetGpuDebugMode__ = &subdeviceCtrlCmdGpuGetGpuDebugMode_IMPL;

    pThis->__subdeviceCtrlCmdGpuInitializeCtx__ = &subdeviceCtrlCmdGpuInitializeCtx_IMPL;

    pThis->__subdeviceCtrlCmdGpuPromoteCtx__ = &subdeviceCtrlCmdGpuPromoteCtx_IMPL;

    pThis->__subdeviceCtrlCmdGpuEvictCtx__ = &subdeviceCtrlCmdGpuEvictCtx_IMPL;

    pThis->__subdeviceCtrlCmdGpuGetId__ = &subdeviceCtrlCmdGpuGetId_IMPL;

    pThis->__subdeviceCtrlCmdGpuGetGidInfo__ = &subdeviceCtrlCmdGpuGetGidInfo_IMPL;

    pThis->__subdeviceCtrlCmdGpuGetPids__ = &subdeviceCtrlCmdGpuGetPids_IMPL;

    pThis->__subdeviceCtrlCmdGpuGetPidInfo__ = &subdeviceCtrlCmdGpuGetPidInfo_IMPL;

    pThis->__subdeviceCtrlCmdGpuQueryFunctionStatus__ = &subdeviceCtrlCmdGpuQueryFunctionStatus_IMPL;

    pThis->__subdeviceCtrlCmdGpuGetMaxSupportedPageSize__ = &subdeviceCtrlCmdGpuGetMaxSupportedPageSize_IMPL;

    pThis->__subdeviceCtrlCmdValidateMemMapRequest__ = &subdeviceCtrlCmdValidateMemMapRequest_IMPL;

    pThis->__subdeviceCtrlCmdGpuGetEngineLoadTimes__ = &subdeviceCtrlCmdGpuGetEngineLoadTimes_IMPL;

    pThis->__subdeviceCtrlCmdEventSetTrigger__ = &subdeviceCtrlCmdEventSetTrigger_IMPL;

    pThis->__subdeviceCtrlCmdEventSetTriggerFifo__ = &subdeviceCtrlCmdEventSetTriggerFifo_IMPL;

    pThis->__subdeviceCtrlCmdEventSetNotification__ = &subdeviceCtrlCmdEventSetNotification_IMPL;

    pThis->__subdeviceCtrlCmdEventSetMemoryNotifies__ = &subdeviceCtrlCmdEventSetMemoryNotifies_IMPL;

    pThis->__subdeviceCtrlCmdEventSetSemaphoreMemory__ = &subdeviceCtrlCmdEventSetSemaphoreMemory_IMPL;

    pThis->__subdeviceCtrlCmdEventSetSemaMemValidation__ = &subdeviceCtrlCmdEventSetSemaMemValidation_IMPL;

    pThis->__subdeviceCtrlCmdTimerCancel__ = &subdeviceCtrlCmdTimerCancel_IMPL;

    pThis->__subdeviceCtrlCmdTimerSchedule__ = &subdeviceCtrlCmdTimerSchedule_IMPL;

    pThis->__subdeviceCtrlCmdTimerGetTime__ = &subdeviceCtrlCmdTimerGetTime_IMPL;

    pThis->__subdeviceCtrlCmdTimerGetRegisterOffset__ = &subdeviceCtrlCmdTimerGetRegisterOffset_IMPL;

    pThis->__subdeviceCtrlCmdTimerGetGpuCpuTimeCorrelationInfo__ = &subdeviceCtrlCmdTimerGetGpuCpuTimeCorrelationInfo_IMPL;

    pThis->__subdeviceCtrlCmdEccGetAggregateErrorCounts__ = &subdeviceCtrlCmdEccGetAggregateErrorCounts_IMPL;

    pThis->__subdeviceCtrlCmdEccGetDetailedAggregateErrorCounts__ = &subdeviceCtrlCmdEccGetDetailedAggregateErrorCounts_IMPL;

    pThis->__subdeviceCtrlCmdEccGetDetailedErrorCounts__ = &subdeviceCtrlCmdEccGetDetailedErrorCounts_IMPL;

    pThis->__subdeviceCtrlCmdEccGetLatestEccAddresses__ = &subdeviceCtrlCmdEccGetLatestEccAddresses_IMPL;

    pThis->__subdeviceCtrlCmdEccGetClientExposedCounters__ = &subdeviceCtrlCmdEccGetClientExposedCounters_IMPL;

    pThis->__subdeviceCtrlCmdGspGetFeatures__ = &subdeviceCtrlCmdGspGetFeatures_IMPL;

    pThis->__subdeviceCtrlCmdOsUnixGc6BlockerRefCnt__ = &subdeviceCtrlCmdOsUnixGc6BlockerRefCnt_IMPL;

    pThis->__subdeviceCtrlCmdOsUnixAllowDisallowGcoff__ = &subdeviceCtrlCmdOsUnixAllowDisallowGcoff_IMPL;

    pThis->__subdeviceCtrlCmdOsUnixAudioDynamicPower__ = &subdeviceCtrlCmdOsUnixAudioDynamicPower_IMPL;

    pThis->__subdeviceCtrlCmdDisplayGetIpVersion__ = &subdeviceCtrlCmdDisplayGetIpVersion_IMPL;

    pThis->__subdeviceCtrlCmdDisplayGetStaticInfo__ = &subdeviceCtrlCmdDisplayGetStaticInfo_IMPL;

    pThis->__subdeviceCtrlCmdDisplaySetChannelPushbuffer__ = &subdeviceCtrlCmdDisplaySetChannelPushbuffer_IMPL;

    pThis->__subdeviceCtrlCmdDisplayWriteInstMem__ = &subdeviceCtrlCmdDisplayWriteInstMem_IMPL;

    pThis->__subdeviceCtrlCmdDisplaySetupRgLineIntr__ = &subdeviceCtrlCmdDisplaySetupRgLineIntr_IMPL;

    pThis->__subdeviceCtrlCmdDisplaySetImportedImpData__ = &subdeviceCtrlCmdDisplaySetImportedImpData_IMPL;

    pThis->__subdeviceCtrlCmdDisplayGetDisplayMask__ = &subdeviceCtrlCmdDisplayGetDisplayMask_IMPL;

    pThis->__subdeviceCtrlCmdInternalGetChipInfo__ = &subdeviceCtrlCmdInternalGetChipInfo_IMPL;

    pThis->__subdeviceCtrlCmdInternalGetDeviceInfoTable__ = &subdeviceCtrlCmdInternalGetDeviceInfoTable_IMPL;

    pThis->__subdeviceCtrlCmdInternalRecoverAllComputeContexts__ = &subdeviceCtrlCmdInternalRecoverAllComputeContexts_IMPL;

    pThis->__subdeviceCtrlCmdInternalGetSmcMode__ = &subdeviceCtrlCmdInternalGetSmcMode_IMPL;

    pThis->__nvoc_base_GpuResource.__nvoc_base_RmResource.__nvoc_base_RsResource.__resPreDestruct__ = &__nvoc_thunk_Subdevice_resPreDestruct;

    pThis->__nvoc_base_GpuResource.__gpuresInternalControlForward__ = &__nvoc_thunk_Subdevice_gpuresInternalControlForward;

    pThis->__nvoc_base_GpuResource.__nvoc_base_RmResource.__nvoc_base_RsResource.__resControlFilter__ = &__nvoc_thunk_Subdevice_resControlFilter;

    pThis->__subdeviceShareCallback__ = &__nvoc_thunk_GpuResource_subdeviceShareCallback;

    pThis->__subdeviceMapTo__ = &__nvoc_thunk_RsResource_subdeviceMapTo;

    pThis->__subdeviceGetOrAllocNotifShare__ = &__nvoc_thunk_Notifier_subdeviceGetOrAllocNotifShare;

    pThis->__subdeviceCheckMemInterUnmap__ = &__nvoc_thunk_RmResource_subdeviceCheckMemInterUnmap;

    pThis->__subdeviceGetMapAddrSpace__ = &__nvoc_thunk_GpuResource_subdeviceGetMapAddrSpace;

    pThis->__subdeviceSetNotificationShare__ = &__nvoc_thunk_Notifier_subdeviceSetNotificationShare;

    pThis->__subdeviceGetRefCount__ = &__nvoc_thunk_RsResource_subdeviceGetRefCount;

    pThis->__subdeviceAddAdditionalDependants__ = &__nvoc_thunk_RsResource_subdeviceAddAdditionalDependants;

    pThis->__subdeviceControl_Prologue__ = &__nvoc_thunk_RmResource_subdeviceControl_Prologue;

    pThis->__subdeviceGetRegBaseOffsetAndSize__ = &__nvoc_thunk_GpuResource_subdeviceGetRegBaseOffsetAndSize;

    pThis->__subdeviceUnmapFrom__ = &__nvoc_thunk_RsResource_subdeviceUnmapFrom;

    pThis->__subdeviceControl_Epilogue__ = &__nvoc_thunk_RmResource_subdeviceControl_Epilogue;

    pThis->__subdeviceControlLookup__ = &__nvoc_thunk_RsResource_subdeviceControlLookup;

    pThis->__subdeviceGetInternalObjectHandle__ = &__nvoc_thunk_GpuResource_subdeviceGetInternalObjectHandle;

    pThis->__subdeviceControl__ = &__nvoc_thunk_GpuResource_subdeviceControl;

    pThis->__subdeviceUnmap__ = &__nvoc_thunk_GpuResource_subdeviceUnmap;

    pThis->__subdeviceGetMemInterMapParams__ = &__nvoc_thunk_RmResource_subdeviceGetMemInterMapParams;

    pThis->__subdeviceUnregisterEvent__ = &__nvoc_thunk_Notifier_subdeviceUnregisterEvent;

    pThis->__subdeviceCanCopy__ = &__nvoc_thunk_RsResource_subdeviceCanCopy;

    pThis->__subdeviceGetNotificationListPtr__ = &__nvoc_thunk_Notifier_subdeviceGetNotificationListPtr;

    pThis->__subdeviceGetNotificationShare__ = &__nvoc_thunk_Notifier_subdeviceGetNotificationShare;

    pThis->__subdeviceMap__ = &__nvoc_thunk_GpuResource_subdeviceMap;

    pThis->__subdeviceAccessCallback__ = &__nvoc_thunk_RmResource_subdeviceAccessCallback;
}

void __nvoc_init_funcTable_Subdevice(Subdevice *pThis) {
    __nvoc_init_funcTable_Subdevice_1(pThis);
}

void __nvoc_init_GpuResource(GpuResource*);
void __nvoc_init_Notifier(Notifier*);
void __nvoc_init_Subdevice(Subdevice *pThis) {
    pThis->__nvoc_pbase_Subdevice = pThis;
    pThis->__nvoc_pbase_Object = &pThis->__nvoc_base_GpuResource.__nvoc_base_RmResource.__nvoc_base_RsResource.__nvoc_base_Object;
    pThis->__nvoc_pbase_RsResource = &pThis->__nvoc_base_GpuResource.__nvoc_base_RmResource.__nvoc_base_RsResource;
    pThis->__nvoc_pbase_RmResourceCommon = &pThis->__nvoc_base_GpuResource.__nvoc_base_RmResource.__nvoc_base_RmResourceCommon;
    pThis->__nvoc_pbase_RmResource = &pThis->__nvoc_base_GpuResource.__nvoc_base_RmResource;
    pThis->__nvoc_pbase_GpuResource = &pThis->__nvoc_base_GpuResource;
    pThis->__nvoc_pbase_INotifier = &pThis->__nvoc_base_Notifier.__nvoc_base_INotifier;
    pThis->__nvoc_pbase_Notifier = &pThis->__nvoc_base_Notifier;
    __nvoc_init_GpuResource(&pThis->__nvoc_base_GpuResource);
    __nvoc_init_Notifier(&pThis->__nvoc_base_Notifier);
    __nvoc_init_funcTable_Subdevice(pThis);
}

NV_STATUS __nvoc_objCreate_Subdevice(Subdevice **ppThis, Dynamic *pParent, NvU32 createFlags, struct CALL_CONTEXT * arg_pCallContext, struct RS_RES_ALLOC_PARAMS_INTERNAL * arg_pParams) {
    NV_STATUS status;
    Object *pParentObj;
    Subdevice *pThis;

    pThis = portMemAllocNonPaged(sizeof(Subdevice));
    if (pThis == NULL) return NV_ERR_NO_MEMORY;

    portMemSet(pThis, 0, sizeof(Subdevice));

    __nvoc_initRtti(staticCast(pThis, Dynamic), &__nvoc_class_def_Subdevice);

    if (pParent != NULL && !(createFlags & NVOC_OBJ_CREATE_FLAGS_PARENT_HALSPEC_ONLY))
    {
        pParentObj = dynamicCast(pParent, Object);
        objAddChild(pParentObj, &pThis->__nvoc_base_GpuResource.__nvoc_base_RmResource.__nvoc_base_RsResource.__nvoc_base_Object);
    }
    else
    {
        pThis->__nvoc_base_GpuResource.__nvoc_base_RmResource.__nvoc_base_RsResource.__nvoc_base_Object.pParent = NULL;
    }

    __nvoc_init_Subdevice(pThis);
    status = __nvoc_ctor_Subdevice(pThis, arg_pCallContext, arg_pParams);
    if (status != NV_OK) goto __nvoc_objCreate_Subdevice_cleanup;

    *ppThis = pThis;
    return NV_OK;

__nvoc_objCreate_Subdevice_cleanup:
    // do not call destructors here since the constructor already called them
    portMemFree(pThis);
    return status;
}

NV_STATUS __nvoc_objCreateDynamic_Subdevice(Subdevice **ppThis, Dynamic *pParent, NvU32 createFlags, va_list args) {
    NV_STATUS status;
    struct CALL_CONTEXT * arg_pCallContext = va_arg(args, struct CALL_CONTEXT *);
    struct RS_RES_ALLOC_PARAMS_INTERNAL * arg_pParams = va_arg(args, struct RS_RES_ALLOC_PARAMS_INTERNAL *);

    status = __nvoc_objCreate_Subdevice(ppThis, pParent, createFlags, arg_pCallContext, arg_pParams);

    return status;
}

