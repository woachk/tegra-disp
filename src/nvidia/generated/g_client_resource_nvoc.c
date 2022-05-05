#include "nvoc/runtime.h"
#include "nvoc/rtti.h"
#include "nvtypes.h"
#include "nvport/nvport.h"
#include "nvport/inline/util_valist.h"
#include "utils/nvassert.h"
#include "g_client_resource_nvoc.h"

#ifdef DEBUG
char __nvoc_class_id_uniqueness_check_0x37a701 = 1;
#endif

extern const struct NVOC_CLASS_DEF __nvoc_class_def_RmClientResource;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_Object;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_RsResource;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_RsClientResource;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_RmResourceCommon;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_INotifier;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_Notifier;

void __nvoc_init_RmClientResource(RmClientResource*);
void __nvoc_init_funcTable_RmClientResource(RmClientResource*);
NV_STATUS __nvoc_ctor_RmClientResource(RmClientResource*, struct CALL_CONTEXT * arg_pCallContext, struct RS_RES_ALLOC_PARAMS_INTERNAL * arg_pParams);
void __nvoc_init_dataField_RmClientResource(RmClientResource*);
void __nvoc_dtor_RmClientResource(RmClientResource*);
extern const struct NVOC_EXPORT_INFO __nvoc_export_info_RmClientResource;

static const struct NVOC_RTTI __nvoc_rtti_RmClientResource_RmClientResource = {
    /*pClassDef=*/          &__nvoc_class_def_RmClientResource,
    /*dtor=*/               (NVOC_DYNAMIC_DTOR) &__nvoc_dtor_RmClientResource,
    /*offset=*/             0,
};

static const struct NVOC_RTTI __nvoc_rtti_RmClientResource_Object = {
    /*pClassDef=*/          &__nvoc_class_def_Object,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(RmClientResource, __nvoc_base_RsClientResource.__nvoc_base_RsResource.__nvoc_base_Object),
};

static const struct NVOC_RTTI __nvoc_rtti_RmClientResource_RsResource = {
    /*pClassDef=*/          &__nvoc_class_def_RsResource,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(RmClientResource, __nvoc_base_RsClientResource.__nvoc_base_RsResource),
};

static const struct NVOC_RTTI __nvoc_rtti_RmClientResource_RsClientResource = {
    /*pClassDef=*/          &__nvoc_class_def_RsClientResource,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(RmClientResource, __nvoc_base_RsClientResource),
};

static const struct NVOC_RTTI __nvoc_rtti_RmClientResource_RmResourceCommon = {
    /*pClassDef=*/          &__nvoc_class_def_RmResourceCommon,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(RmClientResource, __nvoc_base_RmResourceCommon),
};

static const struct NVOC_RTTI __nvoc_rtti_RmClientResource_INotifier = {
    /*pClassDef=*/          &__nvoc_class_def_INotifier,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(RmClientResource, __nvoc_base_Notifier.__nvoc_base_INotifier),
};

static const struct NVOC_RTTI __nvoc_rtti_RmClientResource_Notifier = {
    /*pClassDef=*/          &__nvoc_class_def_Notifier,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(RmClientResource, __nvoc_base_Notifier),
};

static const struct NVOC_CASTINFO __nvoc_castinfo_RmClientResource = {
    /*numRelatives=*/       7,
    /*relatives=*/ {
        &__nvoc_rtti_RmClientResource_RmClientResource,
        &__nvoc_rtti_RmClientResource_Notifier,
        &__nvoc_rtti_RmClientResource_INotifier,
        &__nvoc_rtti_RmClientResource_RmResourceCommon,
        &__nvoc_rtti_RmClientResource_RsClientResource,
        &__nvoc_rtti_RmClientResource_RsResource,
        &__nvoc_rtti_RmClientResource_Object,
    },
};

const struct NVOC_CLASS_DEF __nvoc_class_def_RmClientResource = 
{
    /*classInfo=*/ {
        /*size=*/               sizeof(RmClientResource),
        /*classId=*/            classId(RmClientResource),
        /*providerId=*/         &__nvoc_rtti_provider,
#if NV_PRINTF_STRINGS_ALLOWED
        /*name=*/               "RmClientResource",
#endif
    },
    /*objCreatefn=*/        (NVOC_DYNAMIC_OBJ_CREATE) &__nvoc_objCreateDynamic_RmClientResource,
    /*pCastInfo=*/          &__nvoc_castinfo_RmClientResource,
    /*pExportInfo=*/        &__nvoc_export_info_RmClientResource
};

static NvBool __nvoc_thunk_RmClientResource_resAccessCallback(struct RsResource *pRmCliRes, struct RsClient *pInvokingClient, void *pAllocParams, RsAccessRight accessRight) {
    return cliresAccessCallback((struct RmClientResource *)(((unsigned char *)pRmCliRes) - __nvoc_rtti_RmClientResource_RsResource.offset), pInvokingClient, pAllocParams, accessRight);
}

static NvBool __nvoc_thunk_RmClientResource_resShareCallback(struct RsResource *pRmCliRes, struct RsClient *pInvokingClient, struct RsResourceRef *pParentRef, RS_SHARE_POLICY *pSharePolicy) {
    return cliresShareCallback((struct RmClientResource *)(((unsigned char *)pRmCliRes) - __nvoc_rtti_RmClientResource_RsResource.offset), pInvokingClient, pParentRef, pSharePolicy);
}

static NV_STATUS __nvoc_thunk_RsResource_cliresControl(struct RmClientResource *pResource, struct CALL_CONTEXT *pCallContext, struct RS_RES_CONTROL_PARAMS_INTERNAL *pParams) {
    return resControl((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_RmClientResource_RsResource.offset), pCallContext, pParams);
}

static NV_STATUS __nvoc_thunk_RsResource_cliresUnmap(struct RmClientResource *pResource, struct CALL_CONTEXT *pCallContext, RsCpuMapping *pCpuMapping) {
    return resUnmap((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_RmClientResource_RsResource.offset), pCallContext, pCpuMapping);
}

static NV_STATUS __nvoc_thunk_RsResource_cliresMapTo(struct RmClientResource *pResource, RS_RES_MAP_TO_PARAMS *pParams) {
    return resMapTo((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_RmClientResource_RsResource.offset), pParams);
}

static void __nvoc_thunk_Notifier_cliresSetNotificationShare(struct RmClientResource *pNotifier, struct NotifShare *pNotifShare) {
    notifySetNotificationShare((struct Notifier *)(((unsigned char *)pNotifier) + __nvoc_rtti_RmClientResource_Notifier.offset), pNotifShare);
}

static NV_STATUS __nvoc_thunk_RsResource_cliresControlFilter(struct RmClientResource *pResource, struct CALL_CONTEXT *pCallContext, struct RS_RES_CONTROL_PARAMS_INTERNAL *pParams) {
    return resControlFilter((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_RmClientResource_RsResource.offset), pCallContext, pParams);
}

static void __nvoc_thunk_RsResource_cliresAddAdditionalDependants(struct RsClient *pClient, struct RmClientResource *pResource, RsResourceRef *pReference) {
    resAddAdditionalDependants(pClient, (struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_RmClientResource_RsResource.offset), pReference);
}

static NvU32 __nvoc_thunk_RsResource_cliresGetRefCount(struct RmClientResource *pResource) {
    return resGetRefCount((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_RmClientResource_RsResource.offset));
}

static NV_STATUS __nvoc_thunk_Notifier_cliresUnregisterEvent(struct RmClientResource *pNotifier, NvHandle hNotifierClient, NvHandle hNotifierResource, NvHandle hEventClient, NvHandle hEvent) {
    return notifyUnregisterEvent((struct Notifier *)(((unsigned char *)pNotifier) + __nvoc_rtti_RmClientResource_Notifier.offset), hNotifierClient, hNotifierResource, hEventClient, hEvent);
}

static NvBool __nvoc_thunk_RsResource_cliresCanCopy(struct RmClientResource *pResource) {
    return resCanCopy((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_RmClientResource_RsResource.offset));
}

static NV_STATUS __nvoc_thunk_RsResource_cliresControl_Prologue(struct RmClientResource *pResource, struct CALL_CONTEXT *pCallContext, struct RS_RES_CONTROL_PARAMS_INTERNAL *pParams) {
    return resControl_Prologue((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_RmClientResource_RsResource.offset), pCallContext, pParams);
}

static void __nvoc_thunk_RsResource_cliresPreDestruct(struct RmClientResource *pResource) {
    resPreDestruct((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_RmClientResource_RsResource.offset));
}

static NV_STATUS __nvoc_thunk_RsResource_cliresUnmapFrom(struct RmClientResource *pResource, RS_RES_UNMAP_FROM_PARAMS *pParams) {
    return resUnmapFrom((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_RmClientResource_RsResource.offset), pParams);
}

static PEVENTNOTIFICATION *__nvoc_thunk_Notifier_cliresGetNotificationListPtr(struct RmClientResource *pNotifier) {
    return notifyGetNotificationListPtr((struct Notifier *)(((unsigned char *)pNotifier) + __nvoc_rtti_RmClientResource_Notifier.offset));
}

static void __nvoc_thunk_RsResource_cliresControl_Epilogue(struct RmClientResource *pResource, struct CALL_CONTEXT *pCallContext, struct RS_RES_CONTROL_PARAMS_INTERNAL *pParams) {
    resControl_Epilogue((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_RmClientResource_RsResource.offset), pCallContext, pParams);
}

static struct NotifShare *__nvoc_thunk_Notifier_cliresGetNotificationShare(struct RmClientResource *pNotifier) {
    return notifyGetNotificationShare((struct Notifier *)(((unsigned char *)pNotifier) + __nvoc_rtti_RmClientResource_Notifier.offset));
}

static NV_STATUS __nvoc_thunk_RsResource_cliresControlLookup(struct RmClientResource *pResource, struct RS_RES_CONTROL_PARAMS_INTERNAL *pParams, const struct NVOC_EXPORTED_METHOD_DEF **ppEntry) {
    return resControlLookup((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_RmClientResource_RsResource.offset), pParams, ppEntry);
}

static NV_STATUS __nvoc_thunk_RsResource_cliresMap(struct RmClientResource *pResource, struct CALL_CONTEXT *pCallContext, RS_CPU_MAP_PARAMS *pParams, RsCpuMapping *pCpuMapping) {
    return resMap((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_RmClientResource_RsResource.offset), pCallContext, pParams, pCpuMapping);
}

static NV_STATUS __nvoc_thunk_Notifier_cliresGetOrAllocNotifShare(struct RmClientResource *pNotifier, NvHandle hNotifierClient, NvHandle hNotifierResource, struct NotifShare **ppNotifShare) {
    return notifyGetOrAllocNotifShare((struct Notifier *)(((unsigned char *)pNotifier) + __nvoc_rtti_RmClientResource_Notifier.offset), hNotifierClient, hNotifierResource, ppNotifShare);
}

static const struct NVOC_EXPORTED_METHOD_DEF __nvoc_exported_method_def_RmClientResource[] = 
{
    {               /*  [0] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdSystemGetCpuInfo_IMPL,
        /*flags=*/      0x13u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x102u,
        /*paramSize=*/  sizeof(NV0000_CTRL_SYSTEM_GET_CPU_INFO_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdSystemGetCpuInfo"
#endif
    },
    {               /*  [1] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdSystemSetMemorySize_IMPL,
        /*flags=*/      0x10u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x107u,
        /*paramSize=*/  sizeof(NV0000_CTRL_SYSTEM_SET_MEMORY_SIZE_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdSystemSetMemorySize"
#endif
    },
    {               /*  [2] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdSystemGetClassList_IMPL,
        /*flags=*/      0x10u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x108u,
        /*paramSize=*/  sizeof(NV0000_CTRL_SYSTEM_GET_CLASSLIST_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdSystemGetClassList"
#endif
    },
    {               /*  [3] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdSystemNotifyEvent_IMPL,
        /*flags=*/      0x10u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x110u,
        /*paramSize=*/  sizeof(NV0000_CTRL_SYSTEM_NOTIFY_EVENT_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdSystemNotifyEvent"
#endif
    },
    {               /*  [4] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdSystemDebugCtrlRmMsg_IMPL,
        /*flags=*/      0x10u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x121u,
        /*paramSize=*/  sizeof(NV0000_CTRL_SYSTEM_DEBUG_RMMSG_CTRL_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdSystemDebugCtrlRmMsg"
#endif
    },
    {               /*  [5] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdSystemGetPrivilegedStatus_IMPL,
        /*flags=*/      0x10u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x135u,
        /*paramSize=*/  sizeof(NV0000_CTRL_SYSTEM_GET_PRIVILEGED_STATUS_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdSystemGetPrivilegedStatus"
#endif
    },
    {               /*  [6] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdSystemGetFabricStatus_IMPL,
        /*flags=*/      0x810u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x136u,
        /*paramSize=*/  sizeof(NV0000_CTRL_SYSTEM_GET_FABRIC_STATUS_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdSystemGetFabricStatus"
#endif
    },
    {               /*  [7] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdSystemGetRmInstanceId_IMPL,
        /*flags=*/      0x13u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x139u,
        /*paramSize=*/  sizeof(NV0000_CTRL_SYSTEM_GET_RM_INSTANCE_ID_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdSystemGetRmInstanceId"
#endif
    },
    {               /*  [8] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdSystemSyncExternalFabricMgmt_IMPL,
        /*flags=*/      0x4u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x13cu,
        /*paramSize=*/  sizeof(NV0000_CTRL_CMD_SYSTEM_SYNC_EXTERNAL_FABRIC_MGMT_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdSystemSyncExternalFabricMgmt"
#endif
    },
    {               /*  [9] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdSystemGetClientDatabaseInfo_IMPL,
        /*flags=*/      0x13u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x13du,
        /*paramSize=*/  sizeof(NV0000_CTRL_SYSTEM_GET_CLIENT_DATABASE_INFO_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdSystemGetClientDatabaseInfo"
#endif
    },
    {               /*  [10] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdSystemGetBuildVersionV2_IMPL,
        /*flags=*/      0x811u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x13eu,
        /*paramSize=*/  sizeof(NV0000_CTRL_SYSTEM_GET_BUILD_VERSION_V2_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdSystemGetBuildVersionV2"
#endif
    },
    {               /*  [11] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdSystemGetFeatures_IMPL,
        /*flags=*/      0x10u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x1f0u,
        /*paramSize=*/  sizeof(NV0000_CTRL_SYSTEM_GET_FEATURES_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdSystemGetFeatures"
#endif
    },
    {               /*  [12] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdGpuGetAttachedIds_IMPL,
        /*flags=*/      0x811u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x201u,
        /*paramSize=*/  sizeof(NV0000_CTRL_GPU_GET_ATTACHED_IDS_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdGpuGetAttachedIds"
#endif
    },
    {               /*  [13] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdGpuGetIdInfo_IMPL,
        /*flags=*/      0x810u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x202u,
        /*paramSize=*/  sizeof(NV0000_CTRL_GPU_GET_ID_INFO_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdGpuGetIdInfo"
#endif
    },
    {               /*  [14] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdGpuGetInitStatus_IMPL,
        /*flags=*/      0x11u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x203u,
        /*paramSize=*/  sizeof(NV0000_CTRL_GPU_GET_INIT_STATUS_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdGpuGetInitStatus"
#endif
    },
    {               /*  [15] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdGpuGetDeviceIds_IMPL,
        /*flags=*/      0x13u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x204u,
        /*paramSize=*/  sizeof(NV0000_CTRL_GPU_GET_DEVICE_IDS_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdGpuGetDeviceIds"
#endif
    },
    {               /*  [16] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdGpuGetIdInfoV2_IMPL,
        /*flags=*/      0x810u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x205u,
        /*paramSize=*/  sizeof(NV0000_CTRL_GPU_GET_ID_INFO_V2_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdGpuGetIdInfoV2"
#endif
    },
    {               /*  [17] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdGpuGetProbedIds_IMPL,
        /*flags=*/      0x811u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x214u,
        /*paramSize=*/  sizeof(NV0000_CTRL_GPU_GET_PROBED_IDS_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdGpuGetProbedIds"
#endif
    },
    {               /*  [18] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdGpuAttachIds_IMPL,
        /*flags=*/      0x11u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x215u,
        /*paramSize=*/  sizeof(NV0000_CTRL_GPU_ATTACH_IDS_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdGpuAttachIds"
#endif
    },
    {               /*  [19] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdGpuDetachIds_IMPL,
        /*flags=*/      0x11u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x216u,
        /*paramSize=*/  sizeof(NV0000_CTRL_GPU_DETACH_IDS_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdGpuDetachIds"
#endif
    },
    {               /*  [20] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdGpuGetPciInfo_IMPL,
        /*flags=*/      0x810u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x21bu,
        /*paramSize=*/  sizeof(NV0000_CTRL_GPU_GET_PCI_INFO_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdGpuGetPciInfo"
#endif
    },
    {               /*  [21] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdGpuGetSvmSize_IMPL,
        /*flags=*/      0x10u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x240u,
        /*paramSize=*/  sizeof(NV0000_CTRL_GPU_GET_SVM_SIZE_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdGpuGetSvmSize"
#endif
    },
    {               /*  [22] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdGpuGetUuidInfo_IMPL,
        /*flags=*/      0x10u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x274u,
        /*paramSize=*/  sizeof(NV0000_CTRL_GPU_GET_UUID_INFO_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdGpuGetUuidInfo"
#endif
    },
    {               /*  [23] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdGpuGetUuidFromGpuId_IMPL,
        /*flags=*/      0x10u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x275u,
        /*paramSize=*/  sizeof(NV0000_CTRL_GPU_GET_UUID_FROM_GPU_ID_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdGpuGetUuidFromGpuId"
#endif
    },
    {               /*  [24] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdGpuModifyGpuDrainState_IMPL,
        /*flags=*/      0x4u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x278u,
        /*paramSize=*/  sizeof(NV0000_CTRL_GPU_MODIFY_DRAIN_STATE_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdGpuModifyGpuDrainState"
#endif
    },
    {               /*  [25] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdGpuQueryGpuDrainState_IMPL,
        /*flags=*/      0x11u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x279u,
        /*paramSize=*/  sizeof(NV0000_CTRL_GPU_QUERY_DRAIN_STATE_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdGpuQueryGpuDrainState"
#endif
    },
    {               /*  [26] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdGpuGetMemOpEnable_IMPL,
        /*flags=*/      0x811u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x27bu,
        /*paramSize=*/  sizeof(NV0000_CTRL_GPU_GET_MEMOP_ENABLE_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdGpuGetMemOpEnable"
#endif
    },
    {               /*  [27] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdGpuDisableNvlinkInit_IMPL,
        /*flags=*/      0x13u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x281u,
        /*paramSize=*/  sizeof(NV0000_CTRL_GPU_DISABLE_NVLINK_INIT_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdGpuDisableNvlinkInit"
#endif
    },
    {               /*  [28] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdLegacyConfig_IMPL,
        /*flags=*/      0x10u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x282u,
        /*paramSize=*/  sizeof(NV0000_CTRL_GPU_LEGACY_CONFIG_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdLegacyConfig"
#endif
    },
    {               /*  [29] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdEventSetNotification_IMPL,
        /*flags=*/      0x10u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x501u,
        /*paramSize=*/  sizeof(NV0000_CTRL_EVENT_SET_NOTIFICATION_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdEventSetNotification"
#endif
    },
    {               /*  [30] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdEventGetSystemEventStatus_IMPL,
        /*flags=*/      0x10u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x502u,
        /*paramSize=*/  sizeof(NV0000_CTRL_GET_SYSTEM_EVENT_STATUS_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdEventGetSystemEventStatus"
#endif
    },
    {               /*  [31] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdSetSubProcessID_IMPL,
        /*flags=*/      0x10u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x901u,
        /*paramSize=*/  sizeof(NV0000_CTRL_SET_SUB_PROCESS_ID_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdSetSubProcessID"
#endif
    },
    {               /*  [32] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdDisableSubProcessUserdIsolation_IMPL,
        /*flags=*/      0x10u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x902u,
        /*paramSize=*/  sizeof(NV0000_CTRL_DISABLE_SUB_PROCESS_USERD_ISOLATION_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdDisableSubProcessUserdIsolation"
#endif
    },
    {               /*  [33] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdClientGetAddrSpaceType_IMPL,
        /*flags=*/      0x810u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0xd01u,
        /*paramSize=*/  sizeof(NV0000_CTRL_CLIENT_GET_ADDR_SPACE_TYPE_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdClientGetAddrSpaceType"
#endif
    },
    {               /*  [34] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdClientGetHandleInfo_IMPL,
        /*flags=*/      0x11u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0xd02u,
        /*paramSize=*/  sizeof(NV0000_CTRL_CLIENT_GET_HANDLE_INFO_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdClientGetHandleInfo"
#endif
    },
    {               /*  [35] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdClientGetAccessRights_IMPL,
        /*flags=*/      0x11u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0xd03u,
        /*paramSize=*/  sizeof(NV0000_CTRL_CLIENT_GET_ACCESS_RIGHTS_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdClientGetAccessRights"
#endif
    },
    {               /*  [36] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdClientSetInheritedSharePolicy_IMPL,
        /*flags=*/      0x11u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0xd04u,
        /*paramSize=*/  sizeof(NV0000_CTRL_CLIENT_SET_INHERITED_SHARE_POLICY_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdClientSetInheritedSharePolicy"
#endif
    },
    {               /*  [37] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdClientGetChildHandle_IMPL,
        /*flags=*/      0x11u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0xd05u,
        /*paramSize=*/  sizeof(NV0000_CTRL_CMD_CLIENT_GET_CHILD_HANDLE_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdClientGetChildHandle"
#endif
    },
    {               /*  [38] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdClientShareObject_IMPL,
        /*flags=*/      0x11u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0xd06u,
        /*paramSize=*/  sizeof(NV0000_CTRL_CLIENT_SHARE_OBJECT_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdClientShareObject"
#endif
    },
    {               /*  [39] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdOsUnixFlushUserCache_IMPL,
        /*flags=*/      0x10u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x3d02u,
        /*paramSize=*/  sizeof(NV0000_CTRL_OS_UNIX_FLUSH_USER_CACHE_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdOsUnixFlushUserCache"
#endif
    },
    {               /*  [40] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdOsUnixExportObjectToFd_IMPL,
        /*flags=*/      0x11u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x3d05u,
        /*paramSize=*/  sizeof(NV0000_CTRL_OS_UNIX_EXPORT_OBJECT_TO_FD_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdOsUnixExportObjectToFd"
#endif
    },
    {               /*  [41] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdOsUnixImportObjectFromFd_IMPL,
        /*flags=*/      0x11u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x3d06u,
        /*paramSize=*/  sizeof(NV0000_CTRL_OS_UNIX_IMPORT_OBJECT_FROM_FD_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdOsUnixImportObjectFromFd"
#endif
    },
    {               /*  [42] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdOsUnixGetExportObjectInfo_IMPL,
        /*flags=*/      0x11u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x3d08u,
        /*paramSize=*/  sizeof(NV0000_CTRL_OS_UNIX_GET_EXPORT_OBJECT_INFO_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdOsUnixGetExportObjectInfo"
#endif
    },
    {               /*  [43] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdOsUnixCreateExportObjectFd_IMPL,
        /*flags=*/      0x11u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x3d0au,
        /*paramSize=*/  sizeof(NV0000_CTRL_OS_UNIX_CREATE_EXPORT_OBJECT_FD_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdOsUnixCreateExportObjectFd"
#endif
    },
    {               /*  [44] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdOsUnixExportObjectsToFd_IMPL,
        /*flags=*/      0x11u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x3d0bu,
        /*paramSize=*/  sizeof(NV0000_CTRL_OS_UNIX_EXPORT_OBJECTS_TO_FD_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdOsUnixExportObjectsToFd"
#endif
    },
    {               /*  [45] */
        /*pFunc=*/      (void (*)(void)) cliresCtrlCmdOsUnixImportObjectsFromFd_IMPL,
        /*flags=*/      0x11u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x3d0cu,
        /*paramSize=*/  sizeof(NV0000_CTRL_OS_UNIX_IMPORT_OBJECTS_FROM_FD_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_RmClientResource.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "cliresCtrlCmdOsUnixImportObjectsFromFd"
#endif
    },

};

const struct NVOC_EXPORT_INFO __nvoc_export_info_RmClientResource = 
{
    /*numEntries=*/     46,
    /*pExportEntries=*/ __nvoc_exported_method_def_RmClientResource
};

void __nvoc_dtor_RsClientResource(RsClientResource*);
void __nvoc_dtor_RmResourceCommon(RmResourceCommon*);
void __nvoc_dtor_Notifier(Notifier*);
void __nvoc_dtor_RmClientResource(RmClientResource *pThis) {
    __nvoc_cliresDestruct(pThis);
    __nvoc_dtor_RsClientResource(&pThis->__nvoc_base_RsClientResource);
    __nvoc_dtor_RmResourceCommon(&pThis->__nvoc_base_RmResourceCommon);
    __nvoc_dtor_Notifier(&pThis->__nvoc_base_Notifier);
    PORT_UNREFERENCED_VARIABLE(pThis);
}

void __nvoc_init_dataField_RmClientResource(RmClientResource *pThis) {
    PORT_UNREFERENCED_VARIABLE(pThis);
}

NV_STATUS __nvoc_ctor_RsClientResource(RsClientResource* , struct CALL_CONTEXT *, struct RS_RES_ALLOC_PARAMS_INTERNAL *);
NV_STATUS __nvoc_ctor_RmResourceCommon(RmResourceCommon* );
NV_STATUS __nvoc_ctor_Notifier(Notifier* , struct CALL_CONTEXT *);
NV_STATUS __nvoc_ctor_RmClientResource(RmClientResource *pThis, struct CALL_CONTEXT * arg_pCallContext, struct RS_RES_ALLOC_PARAMS_INTERNAL * arg_pParams) {
    NV_STATUS status = NV_OK;
    status = __nvoc_ctor_RsClientResource(&pThis->__nvoc_base_RsClientResource, arg_pCallContext, arg_pParams);
    if (status != NV_OK) goto __nvoc_ctor_RmClientResource_fail_RsClientResource;
    status = __nvoc_ctor_RmResourceCommon(&pThis->__nvoc_base_RmResourceCommon);
    if (status != NV_OK) goto __nvoc_ctor_RmClientResource_fail_RmResourceCommon;
    status = __nvoc_ctor_Notifier(&pThis->__nvoc_base_Notifier, arg_pCallContext);
    if (status != NV_OK) goto __nvoc_ctor_RmClientResource_fail_Notifier;
    __nvoc_init_dataField_RmClientResource(pThis);

    status = __nvoc_cliresConstruct(pThis, arg_pCallContext, arg_pParams);
    if (status != NV_OK) goto __nvoc_ctor_RmClientResource_fail__init;
    goto __nvoc_ctor_RmClientResource_exit; // Success

__nvoc_ctor_RmClientResource_fail__init:
    __nvoc_dtor_Notifier(&pThis->__nvoc_base_Notifier);
__nvoc_ctor_RmClientResource_fail_Notifier:
    __nvoc_dtor_RmResourceCommon(&pThis->__nvoc_base_RmResourceCommon);
__nvoc_ctor_RmClientResource_fail_RmResourceCommon:
    __nvoc_dtor_RsClientResource(&pThis->__nvoc_base_RsClientResource);
__nvoc_ctor_RmClientResource_fail_RsClientResource:
__nvoc_ctor_RmClientResource_exit:

    return status;
}

static void __nvoc_init_funcTable_RmClientResource_1(RmClientResource *pThis) {
    PORT_UNREFERENCED_VARIABLE(pThis);

    pThis->__cliresAccessCallback__ = &cliresAccessCallback_IMPL;

    pThis->__cliresShareCallback__ = &cliresShareCallback_IMPL;

    pThis->__cliresCtrlCmdSystemGetCpuInfo__ = &cliresCtrlCmdSystemGetCpuInfo_IMPL;

    pThis->__cliresCtrlCmdSystemGetFeatures__ = &cliresCtrlCmdSystemGetFeatures_IMPL;

    pThis->__cliresCtrlCmdSystemGetBuildVersionV2__ = &cliresCtrlCmdSystemGetBuildVersionV2_IMPL;

    pThis->__cliresCtrlCmdSystemSetMemorySize__ = &cliresCtrlCmdSystemSetMemorySize_IMPL;

    pThis->__cliresCtrlCmdSystemGetClassList__ = &cliresCtrlCmdSystemGetClassList_IMPL;

    pThis->__cliresCtrlCmdSystemNotifyEvent__ = &cliresCtrlCmdSystemNotifyEvent_IMPL;

    pThis->__cliresCtrlCmdSystemDebugCtrlRmMsg__ = &cliresCtrlCmdSystemDebugCtrlRmMsg_IMPL;

    pThis->__cliresCtrlCmdSystemGetPrivilegedStatus__ = &cliresCtrlCmdSystemGetPrivilegedStatus_IMPL;

    pThis->__cliresCtrlCmdSystemGetFabricStatus__ = &cliresCtrlCmdSystemGetFabricStatus_IMPL;

    pThis->__cliresCtrlCmdSystemGetRmInstanceId__ = &cliresCtrlCmdSystemGetRmInstanceId_IMPL;

    pThis->__cliresCtrlCmdSystemGetClientDatabaseInfo__ = &cliresCtrlCmdSystemGetClientDatabaseInfo_IMPL;

    pThis->__cliresCtrlCmdClientGetAddrSpaceType__ = &cliresCtrlCmdClientGetAddrSpaceType_IMPL;

    pThis->__cliresCtrlCmdClientGetHandleInfo__ = &cliresCtrlCmdClientGetHandleInfo_IMPL;

    pThis->__cliresCtrlCmdClientGetAccessRights__ = &cliresCtrlCmdClientGetAccessRights_IMPL;

    pThis->__cliresCtrlCmdClientSetInheritedSharePolicy__ = &cliresCtrlCmdClientSetInheritedSharePolicy_IMPL;

    pThis->__cliresCtrlCmdClientShareObject__ = &cliresCtrlCmdClientShareObject_IMPL;

    pThis->__cliresCtrlCmdClientGetChildHandle__ = &cliresCtrlCmdClientGetChildHandle_IMPL;

    pThis->__cliresCtrlCmdGpuGetAttachedIds__ = &cliresCtrlCmdGpuGetAttachedIds_IMPL;

    pThis->__cliresCtrlCmdGpuGetIdInfo__ = &cliresCtrlCmdGpuGetIdInfo_IMPL;

    pThis->__cliresCtrlCmdGpuGetIdInfoV2__ = &cliresCtrlCmdGpuGetIdInfoV2_IMPL;

    pThis->__cliresCtrlCmdGpuGetInitStatus__ = &cliresCtrlCmdGpuGetInitStatus_IMPL;

    pThis->__cliresCtrlCmdGpuGetDeviceIds__ = &cliresCtrlCmdGpuGetDeviceIds_IMPL;

    pThis->__cliresCtrlCmdGpuGetProbedIds__ = &cliresCtrlCmdGpuGetProbedIds_IMPL;

    pThis->__cliresCtrlCmdGpuAttachIds__ = &cliresCtrlCmdGpuAttachIds_IMPL;

    pThis->__cliresCtrlCmdGpuDetachIds__ = &cliresCtrlCmdGpuDetachIds_IMPL;

    pThis->__cliresCtrlCmdGpuGetSvmSize__ = &cliresCtrlCmdGpuGetSvmSize_IMPL;

    pThis->__cliresCtrlCmdGpuGetPciInfo__ = &cliresCtrlCmdGpuGetPciInfo_IMPL;

    pThis->__cliresCtrlCmdGpuGetUuidInfo__ = &cliresCtrlCmdGpuGetUuidInfo_IMPL;

    pThis->__cliresCtrlCmdGpuGetUuidFromGpuId__ = &cliresCtrlCmdGpuGetUuidFromGpuId_IMPL;

    pThis->__cliresCtrlCmdGpuModifyGpuDrainState__ = &cliresCtrlCmdGpuModifyGpuDrainState_IMPL;

    pThis->__cliresCtrlCmdGpuQueryGpuDrainState__ = &cliresCtrlCmdGpuQueryGpuDrainState_IMPL;

    pThis->__cliresCtrlCmdGpuGetMemOpEnable__ = &cliresCtrlCmdGpuGetMemOpEnable_IMPL;

    pThis->__cliresCtrlCmdGpuDisableNvlinkInit__ = &cliresCtrlCmdGpuDisableNvlinkInit_IMPL;

    pThis->__cliresCtrlCmdLegacyConfig__ = &cliresCtrlCmdLegacyConfig_IMPL;

    pThis->__cliresCtrlCmdEventSetNotification__ = &cliresCtrlCmdEventSetNotification_IMPL;

    pThis->__cliresCtrlCmdEventGetSystemEventStatus__ = &cliresCtrlCmdEventGetSystemEventStatus_IMPL;

    pThis->__cliresCtrlCmdOsUnixExportObjectToFd__ = &cliresCtrlCmdOsUnixExportObjectToFd_IMPL;

    pThis->__cliresCtrlCmdOsUnixImportObjectFromFd__ = &cliresCtrlCmdOsUnixImportObjectFromFd_IMPL;

    pThis->__cliresCtrlCmdOsUnixGetExportObjectInfo__ = &cliresCtrlCmdOsUnixGetExportObjectInfo_IMPL;

    pThis->__cliresCtrlCmdOsUnixCreateExportObjectFd__ = &cliresCtrlCmdOsUnixCreateExportObjectFd_IMPL;

    pThis->__cliresCtrlCmdOsUnixExportObjectsToFd__ = &cliresCtrlCmdOsUnixExportObjectsToFd_IMPL;

    pThis->__cliresCtrlCmdOsUnixImportObjectsFromFd__ = &cliresCtrlCmdOsUnixImportObjectsFromFd_IMPL;

    pThis->__cliresCtrlCmdOsUnixFlushUserCache__ = &cliresCtrlCmdOsUnixFlushUserCache_IMPL;

    pThis->__cliresCtrlCmdSetSubProcessID__ = &cliresCtrlCmdSetSubProcessID_IMPL;

    pThis->__cliresCtrlCmdDisableSubProcessUserdIsolation__ = &cliresCtrlCmdDisableSubProcessUserdIsolation_IMPL;

    pThis->__cliresCtrlCmdSystemSyncExternalFabricMgmt__ = &cliresCtrlCmdSystemSyncExternalFabricMgmt_IMPL;

    pThis->__nvoc_base_RsClientResource.__nvoc_base_RsResource.__resAccessCallback__ = &__nvoc_thunk_RmClientResource_resAccessCallback;

    pThis->__nvoc_base_RsClientResource.__nvoc_base_RsResource.__resShareCallback__ = &__nvoc_thunk_RmClientResource_resShareCallback;

    pThis->__cliresControl__ = &__nvoc_thunk_RsResource_cliresControl;

    pThis->__cliresUnmap__ = &__nvoc_thunk_RsResource_cliresUnmap;

    pThis->__cliresMapTo__ = &__nvoc_thunk_RsResource_cliresMapTo;

    pThis->__cliresSetNotificationShare__ = &__nvoc_thunk_Notifier_cliresSetNotificationShare;

    pThis->__cliresControlFilter__ = &__nvoc_thunk_RsResource_cliresControlFilter;

    pThis->__cliresAddAdditionalDependants__ = &__nvoc_thunk_RsResource_cliresAddAdditionalDependants;

    pThis->__cliresGetRefCount__ = &__nvoc_thunk_RsResource_cliresGetRefCount;

    pThis->__cliresUnregisterEvent__ = &__nvoc_thunk_Notifier_cliresUnregisterEvent;

    pThis->__cliresCanCopy__ = &__nvoc_thunk_RsResource_cliresCanCopy;

    pThis->__cliresControl_Prologue__ = &__nvoc_thunk_RsResource_cliresControl_Prologue;

    pThis->__cliresPreDestruct__ = &__nvoc_thunk_RsResource_cliresPreDestruct;

    pThis->__cliresUnmapFrom__ = &__nvoc_thunk_RsResource_cliresUnmapFrom;

    pThis->__cliresGetNotificationListPtr__ = &__nvoc_thunk_Notifier_cliresGetNotificationListPtr;

    pThis->__cliresControl_Epilogue__ = &__nvoc_thunk_RsResource_cliresControl_Epilogue;

    pThis->__cliresGetNotificationShare__ = &__nvoc_thunk_Notifier_cliresGetNotificationShare;

    pThis->__cliresControlLookup__ = &__nvoc_thunk_RsResource_cliresControlLookup;

    pThis->__cliresMap__ = &__nvoc_thunk_RsResource_cliresMap;

    pThis->__cliresGetOrAllocNotifShare__ = &__nvoc_thunk_Notifier_cliresGetOrAllocNotifShare;
}

void __nvoc_init_funcTable_RmClientResource(RmClientResource *pThis) {
    __nvoc_init_funcTable_RmClientResource_1(pThis);
}

void __nvoc_init_RsClientResource(RsClientResource*);
void __nvoc_init_RmResourceCommon(RmResourceCommon*);
void __nvoc_init_Notifier(Notifier*);
void __nvoc_init_RmClientResource(RmClientResource *pThis) {
    pThis->__nvoc_pbase_RmClientResource = pThis;
    pThis->__nvoc_pbase_Object = &pThis->__nvoc_base_RsClientResource.__nvoc_base_RsResource.__nvoc_base_Object;
    pThis->__nvoc_pbase_RsResource = &pThis->__nvoc_base_RsClientResource.__nvoc_base_RsResource;
    pThis->__nvoc_pbase_RsClientResource = &pThis->__nvoc_base_RsClientResource;
    pThis->__nvoc_pbase_RmResourceCommon = &pThis->__nvoc_base_RmResourceCommon;
    pThis->__nvoc_pbase_INotifier = &pThis->__nvoc_base_Notifier.__nvoc_base_INotifier;
    pThis->__nvoc_pbase_Notifier = &pThis->__nvoc_base_Notifier;
    __nvoc_init_RsClientResource(&pThis->__nvoc_base_RsClientResource);
    __nvoc_init_RmResourceCommon(&pThis->__nvoc_base_RmResourceCommon);
    __nvoc_init_Notifier(&pThis->__nvoc_base_Notifier);
    __nvoc_init_funcTable_RmClientResource(pThis);
}

NV_STATUS __nvoc_objCreate_RmClientResource(RmClientResource **ppThis, Dynamic *pParent, NvU32 createFlags, struct CALL_CONTEXT * arg_pCallContext, struct RS_RES_ALLOC_PARAMS_INTERNAL * arg_pParams) {
    NV_STATUS status;
    Object *pParentObj;
    RmClientResource *pThis;

    pThis = portMemAllocNonPaged(sizeof(RmClientResource));
    if (pThis == NULL) return NV_ERR_NO_MEMORY;

    portMemSet(pThis, 0, sizeof(RmClientResource));

    __nvoc_initRtti(staticCast(pThis, Dynamic), &__nvoc_class_def_RmClientResource);

    if (pParent != NULL && !(createFlags & NVOC_OBJ_CREATE_FLAGS_PARENT_HALSPEC_ONLY))
    {
        pParentObj = dynamicCast(pParent, Object);
        objAddChild(pParentObj, &pThis->__nvoc_base_RsClientResource.__nvoc_base_RsResource.__nvoc_base_Object);
    }
    else
    {
        pThis->__nvoc_base_RsClientResource.__nvoc_base_RsResource.__nvoc_base_Object.pParent = NULL;
    }

    __nvoc_init_RmClientResource(pThis);
    status = __nvoc_ctor_RmClientResource(pThis, arg_pCallContext, arg_pParams);
    if (status != NV_OK) goto __nvoc_objCreate_RmClientResource_cleanup;

    *ppThis = pThis;
    return NV_OK;

__nvoc_objCreate_RmClientResource_cleanup:
    // do not call destructors here since the constructor already called them
    portMemFree(pThis);
    return status;
}

NV_STATUS __nvoc_objCreateDynamic_RmClientResource(RmClientResource **ppThis, Dynamic *pParent, NvU32 createFlags, va_list args) {
    NV_STATUS status;
    struct CALL_CONTEXT * arg_pCallContext = va_arg(args, struct CALL_CONTEXT *);
    struct RS_RES_ALLOC_PARAMS_INTERNAL * arg_pParams = va_arg(args, struct RS_RES_ALLOC_PARAMS_INTERNAL *);

    status = __nvoc_objCreate_RmClientResource(ppThis, pParent, createFlags, arg_pCallContext, arg_pParams);

    return status;
}

