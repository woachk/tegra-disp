#include "nvoc/runtime.h"
#include "nvoc/rtti.h"
#include "nvtypes.h"
#include "nvport/nvport.h"
#include "nvport/inline/util_valist.h"
#include "utils/nvassert.h"
#include "g_disp_objs_nvoc.h"

#ifdef DEBUG
char __nvoc_class_id_uniqueness_check_0xe9980c = 1;
#endif

extern const struct NVOC_CLASS_DEF __nvoc_class_def_DisplayApi;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_Object;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_RsResource;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_RmResourceCommon;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_RmResource;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_INotifier;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_Notifier;

void __nvoc_init_DisplayApi(DisplayApi*, RmHalspecOwner* );
void __nvoc_init_funcTable_DisplayApi(DisplayApi*, RmHalspecOwner* );
NV_STATUS __nvoc_ctor_DisplayApi(DisplayApi*, RmHalspecOwner* , struct CALL_CONTEXT * arg_pCallContext, struct RS_RES_ALLOC_PARAMS_INTERNAL * arg_pParams);
void __nvoc_init_dataField_DisplayApi(DisplayApi*, RmHalspecOwner* );
void __nvoc_dtor_DisplayApi(DisplayApi*);
extern const struct NVOC_EXPORT_INFO __nvoc_export_info_DisplayApi;

static const struct NVOC_RTTI __nvoc_rtti_DisplayApi_DisplayApi = {
    /*pClassDef=*/          &__nvoc_class_def_DisplayApi,
    /*dtor=*/               (NVOC_DYNAMIC_DTOR) &__nvoc_dtor_DisplayApi,
    /*offset=*/             0,
};

static const struct NVOC_RTTI __nvoc_rtti_DisplayApi_Object = {
    /*pClassDef=*/          &__nvoc_class_def_Object,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(DisplayApi, __nvoc_base_RmResource.__nvoc_base_RsResource.__nvoc_base_Object),
};

static const struct NVOC_RTTI __nvoc_rtti_DisplayApi_RsResource = {
    /*pClassDef=*/          &__nvoc_class_def_RsResource,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(DisplayApi, __nvoc_base_RmResource.__nvoc_base_RsResource),
};

static const struct NVOC_RTTI __nvoc_rtti_DisplayApi_RmResourceCommon = {
    /*pClassDef=*/          &__nvoc_class_def_RmResourceCommon,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(DisplayApi, __nvoc_base_RmResource.__nvoc_base_RmResourceCommon),
};

static const struct NVOC_RTTI __nvoc_rtti_DisplayApi_RmResource = {
    /*pClassDef=*/          &__nvoc_class_def_RmResource,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(DisplayApi, __nvoc_base_RmResource),
};

static const struct NVOC_RTTI __nvoc_rtti_DisplayApi_INotifier = {
    /*pClassDef=*/          &__nvoc_class_def_INotifier,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(DisplayApi, __nvoc_base_Notifier.__nvoc_base_INotifier),
};

static const struct NVOC_RTTI __nvoc_rtti_DisplayApi_Notifier = {
    /*pClassDef=*/          &__nvoc_class_def_Notifier,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(DisplayApi, __nvoc_base_Notifier),
};

static const struct NVOC_CASTINFO __nvoc_castinfo_DisplayApi = {
    /*numRelatives=*/       7,
    /*relatives=*/ {
        &__nvoc_rtti_DisplayApi_DisplayApi,
        &__nvoc_rtti_DisplayApi_Notifier,
        &__nvoc_rtti_DisplayApi_INotifier,
        &__nvoc_rtti_DisplayApi_RmResource,
        &__nvoc_rtti_DisplayApi_RmResourceCommon,
        &__nvoc_rtti_DisplayApi_RsResource,
        &__nvoc_rtti_DisplayApi_Object,
    },
};

const struct NVOC_CLASS_DEF __nvoc_class_def_DisplayApi = 
{
    /*classInfo=*/ {
        /*size=*/               sizeof(DisplayApi),
        /*classId=*/            classId(DisplayApi),
        /*providerId=*/         &__nvoc_rtti_provider,
#if NV_PRINTF_STRINGS_ALLOWED
        /*name=*/               "DisplayApi",
#endif
    },
    /*objCreatefn=*/        (NVOC_DYNAMIC_OBJ_CREATE) &__nvoc_objCreateDynamic_DisplayApi,
    /*pCastInfo=*/          &__nvoc_castinfo_DisplayApi,
    /*pExportInfo=*/        &__nvoc_export_info_DisplayApi
};

static NV_STATUS __nvoc_thunk_DisplayApi_resControl(struct RsResource *pDisplayApi, struct CALL_CONTEXT *pCallContext, struct RS_RES_CONTROL_PARAMS_INTERNAL *pParams) {
    return dispapiControl((struct DisplayApi *)(((unsigned char *)pDisplayApi) - __nvoc_rtti_DisplayApi_RsResource.offset), pCallContext, pParams);
}

static NV_STATUS __nvoc_thunk_DisplayApi_rmresControl_Prologue(struct RmResource *pDisplayApi, struct CALL_CONTEXT *pCallContext, struct RS_RES_CONTROL_PARAMS_INTERNAL *pRsParams) {
    return dispapiControl_Prologue((struct DisplayApi *)(((unsigned char *)pDisplayApi) - __nvoc_rtti_DisplayApi_RmResource.offset), pCallContext, pRsParams);
}

static void __nvoc_thunk_DisplayApi_rmresControl_Epilogue(struct RmResource *pDisplayApi, struct CALL_CONTEXT *pCallContext, struct RS_RES_CONTROL_PARAMS_INTERNAL *pRsParams) {
    dispapiControl_Epilogue((struct DisplayApi *)(((unsigned char *)pDisplayApi) - __nvoc_rtti_DisplayApi_RmResource.offset), pCallContext, pRsParams);
}

static NvBool __nvoc_thunk_RmResource_dispapiShareCallback(struct DisplayApi *pResource, struct RsClient *pInvokingClient, struct RsResourceRef *pParentRef, RS_SHARE_POLICY *pSharePolicy) {
    return rmresShareCallback((struct RmResource *)(((unsigned char *)pResource) + __nvoc_rtti_DisplayApi_RmResource.offset), pInvokingClient, pParentRef, pSharePolicy);
}

static NV_STATUS __nvoc_thunk_RmResource_dispapiCheckMemInterUnmap(struct DisplayApi *pRmResource, NvBool bSubdeviceHandleProvided) {
    return rmresCheckMemInterUnmap((struct RmResource *)(((unsigned char *)pRmResource) + __nvoc_rtti_DisplayApi_RmResource.offset), bSubdeviceHandleProvided);
}

static NvBool __nvoc_thunk_RmResource_dispapiAccessCallback(struct DisplayApi *pResource, struct RsClient *pInvokingClient, void *pAllocParams, RsAccessRight accessRight) {
    return rmresAccessCallback((struct RmResource *)(((unsigned char *)pResource) + __nvoc_rtti_DisplayApi_RmResource.offset), pInvokingClient, pAllocParams, accessRight);
}

static NV_STATUS __nvoc_thunk_RmResource_dispapiGetMemInterMapParams(struct DisplayApi *pRmResource, RMRES_MEM_INTER_MAP_PARAMS *pParams) {
    return rmresGetMemInterMapParams((struct RmResource *)(((unsigned char *)pRmResource) + __nvoc_rtti_DisplayApi_RmResource.offset), pParams);
}

static void __nvoc_thunk_Notifier_dispapiSetNotificationShare(struct DisplayApi *pNotifier, struct NotifShare *pNotifShare) {
    notifySetNotificationShare((struct Notifier *)(((unsigned char *)pNotifier) + __nvoc_rtti_DisplayApi_Notifier.offset), pNotifShare);
}

static NV_STATUS __nvoc_thunk_RsResource_dispapiControlFilter(struct DisplayApi *pResource, struct CALL_CONTEXT *pCallContext, struct RS_RES_CONTROL_PARAMS_INTERNAL *pParams) {
    return resControlFilter((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DisplayApi_RsResource.offset), pCallContext, pParams);
}

static void __nvoc_thunk_RsResource_dispapiAddAdditionalDependants(struct RsClient *pClient, struct DisplayApi *pResource, RsResourceRef *pReference) {
    resAddAdditionalDependants(pClient, (struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DisplayApi_RsResource.offset), pReference);
}

static NvU32 __nvoc_thunk_RsResource_dispapiGetRefCount(struct DisplayApi *pResource) {
    return resGetRefCount((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DisplayApi_RsResource.offset));
}

static NV_STATUS __nvoc_thunk_Notifier_dispapiUnregisterEvent(struct DisplayApi *pNotifier, NvHandle hNotifierClient, NvHandle hNotifierResource, NvHandle hEventClient, NvHandle hEvent) {
    return notifyUnregisterEvent((struct Notifier *)(((unsigned char *)pNotifier) + __nvoc_rtti_DisplayApi_Notifier.offset), hNotifierClient, hNotifierResource, hEventClient, hEvent);
}

static NV_STATUS __nvoc_thunk_RsResource_dispapiUnmap(struct DisplayApi *pResource, struct CALL_CONTEXT *pCallContext, RsCpuMapping *pCpuMapping) {
    return resUnmap((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DisplayApi_RsResource.offset), pCallContext, pCpuMapping);
}

static NvBool __nvoc_thunk_RsResource_dispapiCanCopy(struct DisplayApi *pResource) {
    return resCanCopy((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DisplayApi_RsResource.offset));
}

static NV_STATUS __nvoc_thunk_RsResource_dispapiMapTo(struct DisplayApi *pResource, RS_RES_MAP_TO_PARAMS *pParams) {
    return resMapTo((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DisplayApi_RsResource.offset), pParams);
}

static void __nvoc_thunk_RsResource_dispapiPreDestruct(struct DisplayApi *pResource) {
    resPreDestruct((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DisplayApi_RsResource.offset));
}

static NV_STATUS __nvoc_thunk_RsResource_dispapiUnmapFrom(struct DisplayApi *pResource, RS_RES_UNMAP_FROM_PARAMS *pParams) {
    return resUnmapFrom((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DisplayApi_RsResource.offset), pParams);
}

static PEVENTNOTIFICATION *__nvoc_thunk_Notifier_dispapiGetNotificationListPtr(struct DisplayApi *pNotifier) {
    return notifyGetNotificationListPtr((struct Notifier *)(((unsigned char *)pNotifier) + __nvoc_rtti_DisplayApi_Notifier.offset));
}

static struct NotifShare *__nvoc_thunk_Notifier_dispapiGetNotificationShare(struct DisplayApi *pNotifier) {
    return notifyGetNotificationShare((struct Notifier *)(((unsigned char *)pNotifier) + __nvoc_rtti_DisplayApi_Notifier.offset));
}

static NV_STATUS __nvoc_thunk_RsResource_dispapiControlLookup(struct DisplayApi *pResource, struct RS_RES_CONTROL_PARAMS_INTERNAL *pParams, const struct NVOC_EXPORTED_METHOD_DEF **ppEntry) {
    return resControlLookup((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DisplayApi_RsResource.offset), pParams, ppEntry);
}

static NV_STATUS __nvoc_thunk_RsResource_dispapiMap(struct DisplayApi *pResource, struct CALL_CONTEXT *pCallContext, RS_CPU_MAP_PARAMS *pParams, RsCpuMapping *pCpuMapping) {
    return resMap((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DisplayApi_RsResource.offset), pCallContext, pParams, pCpuMapping);
}

static NV_STATUS __nvoc_thunk_Notifier_dispapiGetOrAllocNotifShare(struct DisplayApi *pNotifier, NvHandle hNotifierClient, NvHandle hNotifierResource, struct NotifShare **ppNotifShare) {
    return notifyGetOrAllocNotifShare((struct Notifier *)(((unsigned char *)pNotifier) + __nvoc_rtti_DisplayApi_Notifier.offset), hNotifierClient, hNotifierResource, ppNotifShare);
}

const struct NVOC_EXPORT_INFO __nvoc_export_info_DisplayApi = 
{
    /*numEntries=*/     0,
    /*pExportEntries=*/  0
};

void __nvoc_dtor_RmResource(RmResource*);
void __nvoc_dtor_Notifier(Notifier*);
void __nvoc_dtor_DisplayApi(DisplayApi *pThis) {
    __nvoc_dispapiDestruct(pThis);
    __nvoc_dtor_RmResource(&pThis->__nvoc_base_RmResource);
    __nvoc_dtor_Notifier(&pThis->__nvoc_base_Notifier);
    PORT_UNREFERENCED_VARIABLE(pThis);
}

void __nvoc_init_dataField_DisplayApi(DisplayApi *pThis, RmHalspecOwner *pRmhalspecowner) {
    RmVariantHal *rmVariantHal = &pRmhalspecowner->rmVariantHal;
    PORT_UNREFERENCED_VARIABLE(pThis);
    PORT_UNREFERENCED_VARIABLE(pRmhalspecowner);
    PORT_UNREFERENCED_VARIABLE(rmVariantHal);
}

NV_STATUS __nvoc_ctor_RmResource(RmResource* , struct CALL_CONTEXT *, struct RS_RES_ALLOC_PARAMS_INTERNAL *);
NV_STATUS __nvoc_ctor_Notifier(Notifier* , struct CALL_CONTEXT *);
NV_STATUS __nvoc_ctor_DisplayApi(DisplayApi *pThis, RmHalspecOwner *pRmhalspecowner, struct CALL_CONTEXT * arg_pCallContext, struct RS_RES_ALLOC_PARAMS_INTERNAL * arg_pParams) {
    NV_STATUS status = NV_OK;
    status = __nvoc_ctor_RmResource(&pThis->__nvoc_base_RmResource, arg_pCallContext, arg_pParams);
    if (status != NV_OK) goto __nvoc_ctor_DisplayApi_fail_RmResource;
    status = __nvoc_ctor_Notifier(&pThis->__nvoc_base_Notifier, arg_pCallContext);
    if (status != NV_OK) goto __nvoc_ctor_DisplayApi_fail_Notifier;
    __nvoc_init_dataField_DisplayApi(pThis, pRmhalspecowner);

    status = __nvoc_dispapiConstruct(pThis, arg_pCallContext, arg_pParams);
    if (status != NV_OK) goto __nvoc_ctor_DisplayApi_fail__init;
    goto __nvoc_ctor_DisplayApi_exit; // Success

__nvoc_ctor_DisplayApi_fail__init:
    __nvoc_dtor_Notifier(&pThis->__nvoc_base_Notifier);
__nvoc_ctor_DisplayApi_fail_Notifier:
    __nvoc_dtor_RmResource(&pThis->__nvoc_base_RmResource);
__nvoc_ctor_DisplayApi_fail_RmResource:
__nvoc_ctor_DisplayApi_exit:

    return status;
}

static void __nvoc_init_funcTable_DisplayApi_1(DisplayApi *pThis, RmHalspecOwner *pRmhalspecowner) {
    RmVariantHal *rmVariantHal = &pRmhalspecowner->rmVariantHal;
    PORT_UNREFERENCED_VARIABLE(pThis);
    PORT_UNREFERENCED_VARIABLE(pRmhalspecowner);
    PORT_UNREFERENCED_VARIABLE(rmVariantHal);

    pThis->__dispapiControl__ = &dispapiControl_IMPL;

    pThis->__dispapiControl_Prologue__ = &dispapiControl_Prologue_IMPL;

    pThis->__dispapiControl_Epilogue__ = &dispapiControl_Epilogue_IMPL;

    pThis->__nvoc_base_RmResource.__nvoc_base_RsResource.__resControl__ = &__nvoc_thunk_DisplayApi_resControl;

    pThis->__nvoc_base_RmResource.__rmresControl_Prologue__ = &__nvoc_thunk_DisplayApi_rmresControl_Prologue;

    pThis->__nvoc_base_RmResource.__rmresControl_Epilogue__ = &__nvoc_thunk_DisplayApi_rmresControl_Epilogue;

    pThis->__dispapiShareCallback__ = &__nvoc_thunk_RmResource_dispapiShareCallback;

    pThis->__dispapiCheckMemInterUnmap__ = &__nvoc_thunk_RmResource_dispapiCheckMemInterUnmap;

    pThis->__dispapiAccessCallback__ = &__nvoc_thunk_RmResource_dispapiAccessCallback;

    pThis->__dispapiGetMemInterMapParams__ = &__nvoc_thunk_RmResource_dispapiGetMemInterMapParams;

    pThis->__dispapiSetNotificationShare__ = &__nvoc_thunk_Notifier_dispapiSetNotificationShare;

    pThis->__dispapiControlFilter__ = &__nvoc_thunk_RsResource_dispapiControlFilter;

    pThis->__dispapiAddAdditionalDependants__ = &__nvoc_thunk_RsResource_dispapiAddAdditionalDependants;

    pThis->__dispapiGetRefCount__ = &__nvoc_thunk_RsResource_dispapiGetRefCount;

    pThis->__dispapiUnregisterEvent__ = &__nvoc_thunk_Notifier_dispapiUnregisterEvent;

    pThis->__dispapiUnmap__ = &__nvoc_thunk_RsResource_dispapiUnmap;

    pThis->__dispapiCanCopy__ = &__nvoc_thunk_RsResource_dispapiCanCopy;

    pThis->__dispapiMapTo__ = &__nvoc_thunk_RsResource_dispapiMapTo;

    pThis->__dispapiPreDestruct__ = &__nvoc_thunk_RsResource_dispapiPreDestruct;

    pThis->__dispapiUnmapFrom__ = &__nvoc_thunk_RsResource_dispapiUnmapFrom;

    pThis->__dispapiGetNotificationListPtr__ = &__nvoc_thunk_Notifier_dispapiGetNotificationListPtr;

    pThis->__dispapiGetNotificationShare__ = &__nvoc_thunk_Notifier_dispapiGetNotificationShare;

    pThis->__dispapiControlLookup__ = &__nvoc_thunk_RsResource_dispapiControlLookup;

    pThis->__dispapiMap__ = &__nvoc_thunk_RsResource_dispapiMap;

    pThis->__dispapiGetOrAllocNotifShare__ = &__nvoc_thunk_Notifier_dispapiGetOrAllocNotifShare;
}

void __nvoc_init_funcTable_DisplayApi(DisplayApi *pThis, RmHalspecOwner *pRmhalspecowner) {
    __nvoc_init_funcTable_DisplayApi_1(pThis, pRmhalspecowner);
}

void __nvoc_init_RmResource(RmResource*);
void __nvoc_init_Notifier(Notifier*);
void __nvoc_init_DisplayApi(DisplayApi *pThis, RmHalspecOwner *pRmhalspecowner) {
    pThis->__nvoc_pbase_DisplayApi = pThis;
    pThis->__nvoc_pbase_Object = &pThis->__nvoc_base_RmResource.__nvoc_base_RsResource.__nvoc_base_Object;
    pThis->__nvoc_pbase_RsResource = &pThis->__nvoc_base_RmResource.__nvoc_base_RsResource;
    pThis->__nvoc_pbase_RmResourceCommon = &pThis->__nvoc_base_RmResource.__nvoc_base_RmResourceCommon;
    pThis->__nvoc_pbase_RmResource = &pThis->__nvoc_base_RmResource;
    pThis->__nvoc_pbase_INotifier = &pThis->__nvoc_base_Notifier.__nvoc_base_INotifier;
    pThis->__nvoc_pbase_Notifier = &pThis->__nvoc_base_Notifier;
    __nvoc_init_RmResource(&pThis->__nvoc_base_RmResource);
    __nvoc_init_Notifier(&pThis->__nvoc_base_Notifier);
    __nvoc_init_funcTable_DisplayApi(pThis, pRmhalspecowner);
}

NV_STATUS __nvoc_objCreate_DisplayApi(DisplayApi **ppThis, Dynamic *pParent, NvU32 createFlags, struct CALL_CONTEXT * arg_pCallContext, struct RS_RES_ALLOC_PARAMS_INTERNAL * arg_pParams) {
    NV_STATUS status;
    Object *pParentObj;
    DisplayApi *pThis;
    RmHalspecOwner *pRmhalspecowner;

    pThis = portMemAllocNonPaged(sizeof(DisplayApi));
    if (pThis == NULL) return NV_ERR_NO_MEMORY;

    portMemSet(pThis, 0, sizeof(DisplayApi));

    __nvoc_initRtti(staticCast(pThis, Dynamic), &__nvoc_class_def_DisplayApi);

    if (pParent != NULL && !(createFlags & NVOC_OBJ_CREATE_FLAGS_PARENT_HALSPEC_ONLY))
    {
        pParentObj = dynamicCast(pParent, Object);
        objAddChild(pParentObj, &pThis->__nvoc_base_RmResource.__nvoc_base_RsResource.__nvoc_base_Object);
    }
    else
    {
        pThis->__nvoc_base_RmResource.__nvoc_base_RsResource.__nvoc_base_Object.pParent = NULL;
    }

    if ((pRmhalspecowner = dynamicCast(pParent, RmHalspecOwner)) == NULL)
        pRmhalspecowner = objFindAncestorOfType(RmHalspecOwner, pParent);
    NV_ASSERT_OR_RETURN(pRmhalspecowner != NULL, NV_ERR_INVALID_ARGUMENT);

    __nvoc_init_DisplayApi(pThis, pRmhalspecowner);
    status = __nvoc_ctor_DisplayApi(pThis, pRmhalspecowner, arg_pCallContext, arg_pParams);
    if (status != NV_OK) goto __nvoc_objCreate_DisplayApi_cleanup;

    *ppThis = pThis;
    return NV_OK;

__nvoc_objCreate_DisplayApi_cleanup:
    // do not call destructors here since the constructor already called them
    portMemFree(pThis);
    return status;
}

NV_STATUS __nvoc_objCreateDynamic_DisplayApi(DisplayApi **ppThis, Dynamic *pParent, NvU32 createFlags, va_list args) {
    NV_STATUS status;
    struct CALL_CONTEXT * arg_pCallContext = va_arg(args, struct CALL_CONTEXT *);
    struct RS_RES_ALLOC_PARAMS_INTERNAL * arg_pParams = va_arg(args, struct RS_RES_ALLOC_PARAMS_INTERNAL *);

    status = __nvoc_objCreate_DisplayApi(ppThis, pParent, createFlags, arg_pCallContext, arg_pParams);

    return status;
}

#ifdef DEBUG
char __nvoc_class_id_uniqueness_check_0x999839 = 1;
#endif

extern const struct NVOC_CLASS_DEF __nvoc_class_def_DispObject;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_Object;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_RsResource;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_RmResourceCommon;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_RmResource;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_INotifier;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_Notifier;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_DisplayApi;

void __nvoc_init_DispObject(DispObject*, RmHalspecOwner* );
void __nvoc_init_funcTable_DispObject(DispObject*, RmHalspecOwner* );
NV_STATUS __nvoc_ctor_DispObject(DispObject*, RmHalspecOwner* , struct CALL_CONTEXT * arg_pCallContext, struct RS_RES_ALLOC_PARAMS_INTERNAL * arg_pParams);
void __nvoc_init_dataField_DispObject(DispObject*, RmHalspecOwner* );
void __nvoc_dtor_DispObject(DispObject*);
extern const struct NVOC_EXPORT_INFO __nvoc_export_info_DispObject;

static const struct NVOC_RTTI __nvoc_rtti_DispObject_DispObject = {
    /*pClassDef=*/          &__nvoc_class_def_DispObject,
    /*dtor=*/               (NVOC_DYNAMIC_DTOR) &__nvoc_dtor_DispObject,
    /*offset=*/             0,
};

static const struct NVOC_RTTI __nvoc_rtti_DispObject_Object = {
    /*pClassDef=*/          &__nvoc_class_def_Object,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(DispObject, __nvoc_base_DisplayApi.__nvoc_base_RmResource.__nvoc_base_RsResource.__nvoc_base_Object),
};

static const struct NVOC_RTTI __nvoc_rtti_DispObject_RsResource = {
    /*pClassDef=*/          &__nvoc_class_def_RsResource,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(DispObject, __nvoc_base_DisplayApi.__nvoc_base_RmResource.__nvoc_base_RsResource),
};

static const struct NVOC_RTTI __nvoc_rtti_DispObject_RmResourceCommon = {
    /*pClassDef=*/          &__nvoc_class_def_RmResourceCommon,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(DispObject, __nvoc_base_DisplayApi.__nvoc_base_RmResource.__nvoc_base_RmResourceCommon),
};

static const struct NVOC_RTTI __nvoc_rtti_DispObject_RmResource = {
    /*pClassDef=*/          &__nvoc_class_def_RmResource,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(DispObject, __nvoc_base_DisplayApi.__nvoc_base_RmResource),
};

static const struct NVOC_RTTI __nvoc_rtti_DispObject_INotifier = {
    /*pClassDef=*/          &__nvoc_class_def_INotifier,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(DispObject, __nvoc_base_DisplayApi.__nvoc_base_Notifier.__nvoc_base_INotifier),
};

static const struct NVOC_RTTI __nvoc_rtti_DispObject_Notifier = {
    /*pClassDef=*/          &__nvoc_class_def_Notifier,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(DispObject, __nvoc_base_DisplayApi.__nvoc_base_Notifier),
};

static const struct NVOC_RTTI __nvoc_rtti_DispObject_DisplayApi = {
    /*pClassDef=*/          &__nvoc_class_def_DisplayApi,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(DispObject, __nvoc_base_DisplayApi),
};

static const struct NVOC_CASTINFO __nvoc_castinfo_DispObject = {
    /*numRelatives=*/       8,
    /*relatives=*/ {
        &__nvoc_rtti_DispObject_DispObject,
        &__nvoc_rtti_DispObject_DisplayApi,
        &__nvoc_rtti_DispObject_Notifier,
        &__nvoc_rtti_DispObject_INotifier,
        &__nvoc_rtti_DispObject_RmResource,
        &__nvoc_rtti_DispObject_RmResourceCommon,
        &__nvoc_rtti_DispObject_RsResource,
        &__nvoc_rtti_DispObject_Object,
    },
};

const struct NVOC_CLASS_DEF __nvoc_class_def_DispObject = 
{
    /*classInfo=*/ {
        /*size=*/               sizeof(DispObject),
        /*classId=*/            classId(DispObject),
        /*providerId=*/         &__nvoc_rtti_provider,
#if NV_PRINTF_STRINGS_ALLOWED
        /*name=*/               "DispObject",
#endif
    },
    /*objCreatefn=*/        (NVOC_DYNAMIC_OBJ_CREATE) &__nvoc_objCreateDynamic_DispObject,
    /*pCastInfo=*/          &__nvoc_castinfo_DispObject,
    /*pExportInfo=*/        &__nvoc_export_info_DispObject
};

static NvBool __nvoc_thunk_RmResource_dispobjShareCallback(struct DispObject *pResource, struct RsClient *pInvokingClient, struct RsResourceRef *pParentRef, RS_SHARE_POLICY *pSharePolicy) {
    return rmresShareCallback((struct RmResource *)(((unsigned char *)pResource) + __nvoc_rtti_DispObject_RmResource.offset), pInvokingClient, pParentRef, pSharePolicy);
}

static NV_STATUS __nvoc_thunk_DisplayApi_dispobjControl(struct DispObject *pDisplayApi, struct CALL_CONTEXT *pCallContext, struct RS_RES_CONTROL_PARAMS_INTERNAL *pParams) {
    return dispapiControl((struct DisplayApi *)(((unsigned char *)pDisplayApi) + __nvoc_rtti_DispObject_DisplayApi.offset), pCallContext, pParams);
}

static NvBool __nvoc_thunk_RmResource_dispobjAccessCallback(struct DispObject *pResource, struct RsClient *pInvokingClient, void *pAllocParams, RsAccessRight accessRight) {
    return rmresAccessCallback((struct RmResource *)(((unsigned char *)pResource) + __nvoc_rtti_DispObject_RmResource.offset), pInvokingClient, pAllocParams, accessRight);
}

static NV_STATUS __nvoc_thunk_RmResource_dispobjGetMemInterMapParams(struct DispObject *pRmResource, RMRES_MEM_INTER_MAP_PARAMS *pParams) {
    return rmresGetMemInterMapParams((struct RmResource *)(((unsigned char *)pRmResource) + __nvoc_rtti_DispObject_RmResource.offset), pParams);
}

static NV_STATUS __nvoc_thunk_RsResource_dispobjUnmap(struct DispObject *pResource, struct CALL_CONTEXT *pCallContext, RsCpuMapping *pCpuMapping) {
    return resUnmap((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DispObject_RsResource.offset), pCallContext, pCpuMapping);
}

static NV_STATUS __nvoc_thunk_RmResource_dispobjCheckMemInterUnmap(struct DispObject *pRmResource, NvBool bSubdeviceHandleProvided) {
    return rmresCheckMemInterUnmap((struct RmResource *)(((unsigned char *)pRmResource) + __nvoc_rtti_DispObject_RmResource.offset), bSubdeviceHandleProvided);
}

static void __nvoc_thunk_Notifier_dispobjSetNotificationShare(struct DispObject *pNotifier, struct NotifShare *pNotifShare) {
    notifySetNotificationShare((struct Notifier *)(((unsigned char *)pNotifier) + __nvoc_rtti_DispObject_Notifier.offset), pNotifShare);
}

static NV_STATUS __nvoc_thunk_RsResource_dispobjControlFilter(struct DispObject *pResource, struct CALL_CONTEXT *pCallContext, struct RS_RES_CONTROL_PARAMS_INTERNAL *pParams) {
    return resControlFilter((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DispObject_RsResource.offset), pCallContext, pParams);
}

static NvU32 __nvoc_thunk_RsResource_dispobjGetRefCount(struct DispObject *pResource) {
    return resGetRefCount((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DispObject_RsResource.offset));
}

static NV_STATUS __nvoc_thunk_Notifier_dispobjUnregisterEvent(struct DispObject *pNotifier, NvHandle hNotifierClient, NvHandle hNotifierResource, NvHandle hEventClient, NvHandle hEvent) {
    return notifyUnregisterEvent((struct Notifier *)(((unsigned char *)pNotifier) + __nvoc_rtti_DispObject_Notifier.offset), hNotifierClient, hNotifierResource, hEventClient, hEvent);
}

static NV_STATUS __nvoc_thunk_RsResource_dispobjMapTo(struct DispObject *pResource, RS_RES_MAP_TO_PARAMS *pParams) {
    return resMapTo((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DispObject_RsResource.offset), pParams);
}

static NV_STATUS __nvoc_thunk_DisplayApi_dispobjControl_Prologue(struct DispObject *pDisplayApi, struct CALL_CONTEXT *pCallContext, struct RS_RES_CONTROL_PARAMS_INTERNAL *pRsParams) {
    return dispapiControl_Prologue((struct DisplayApi *)(((unsigned char *)pDisplayApi) + __nvoc_rtti_DispObject_DisplayApi.offset), pCallContext, pRsParams);
}

static NvBool __nvoc_thunk_RsResource_dispobjCanCopy(struct DispObject *pResource) {
    return resCanCopy((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DispObject_RsResource.offset));
}

static void __nvoc_thunk_RsResource_dispobjAddAdditionalDependants(struct RsClient *pClient, struct DispObject *pResource, RsResourceRef *pReference) {
    resAddAdditionalDependants(pClient, (struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DispObject_RsResource.offset), pReference);
}

static void __nvoc_thunk_RsResource_dispobjPreDestruct(struct DispObject *pResource) {
    resPreDestruct((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DispObject_RsResource.offset));
}

static NV_STATUS __nvoc_thunk_RsResource_dispobjUnmapFrom(struct DispObject *pResource, RS_RES_UNMAP_FROM_PARAMS *pParams) {
    return resUnmapFrom((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DispObject_RsResource.offset), pParams);
}

static PEVENTNOTIFICATION *__nvoc_thunk_Notifier_dispobjGetNotificationListPtr(struct DispObject *pNotifier) {
    return notifyGetNotificationListPtr((struct Notifier *)(((unsigned char *)pNotifier) + __nvoc_rtti_DispObject_Notifier.offset));
}

static void __nvoc_thunk_DisplayApi_dispobjControl_Epilogue(struct DispObject *pDisplayApi, struct CALL_CONTEXT *pCallContext, struct RS_RES_CONTROL_PARAMS_INTERNAL *pRsParams) {
    dispapiControl_Epilogue((struct DisplayApi *)(((unsigned char *)pDisplayApi) + __nvoc_rtti_DispObject_DisplayApi.offset), pCallContext, pRsParams);
}

static struct NotifShare *__nvoc_thunk_Notifier_dispobjGetNotificationShare(struct DispObject *pNotifier) {
    return notifyGetNotificationShare((struct Notifier *)(((unsigned char *)pNotifier) + __nvoc_rtti_DispObject_Notifier.offset));
}

static NV_STATUS __nvoc_thunk_RsResource_dispobjControlLookup(struct DispObject *pResource, struct RS_RES_CONTROL_PARAMS_INTERNAL *pParams, const struct NVOC_EXPORTED_METHOD_DEF **ppEntry) {
    return resControlLookup((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DispObject_RsResource.offset), pParams, ppEntry);
}

static NV_STATUS __nvoc_thunk_RsResource_dispobjMap(struct DispObject *pResource, struct CALL_CONTEXT *pCallContext, RS_CPU_MAP_PARAMS *pParams, RsCpuMapping *pCpuMapping) {
    return resMap((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DispObject_RsResource.offset), pCallContext, pParams, pCpuMapping);
}

static NV_STATUS __nvoc_thunk_Notifier_dispobjGetOrAllocNotifShare(struct DispObject *pNotifier, NvHandle hNotifierClient, NvHandle hNotifierResource, struct NotifShare **ppNotifShare) {
    return notifyGetOrAllocNotifShare((struct Notifier *)(((unsigned char *)pNotifier) + __nvoc_rtti_DispObject_Notifier.offset), hNotifierClient, hNotifierResource, ppNotifShare);
}

static const struct NVOC_EXPORTED_METHOD_DEF __nvoc_exported_method_def_DispObject[] = 
{
    {               /*  [0] */
        /*pFunc=*/      (void (*)(void)) dispobjCtrlCmdSetRmFreeFlags_IMPL,
        /*flags=*/      0x200u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x50700117u,
        /*paramSize=*/  sizeof(NV5070_CTRL_SET_RMFREE_FLAGS_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispObject.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispobjCtrlCmdSetRmFreeFlags"
#endif
    },
    {               /*  [1] */
        /*pFunc=*/      (void (*)(void)) dispobjCtrlCmdIMPSetGetParameter_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x50700118u,
        /*paramSize=*/  sizeof(NV5070_CTRL_IMP_SET_GET_PARAMETER_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispObject.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispobjCtrlCmdIMPSetGetParameter"
#endif
    },
    {               /*  [2] */
        /*pFunc=*/      (void (*)(void)) dispobjCtrlCmdGetRgStatus_IMPL,
        /*flags=*/      0x204u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x50700202u,
        /*paramSize=*/  sizeof(NV5070_CTRL_CMD_GET_RG_STATUS_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispObject.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispobjCtrlCmdGetRgStatus"
#endif
    },
    {               /*  [3] */
        /*pFunc=*/      (void (*)(void)) dispobjCtrlCmdGetRgUnderflowProp_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x50700203u,
        /*paramSize=*/  sizeof(NV5070_CTRL_CMD_GET_RG_UNDERFLOW_PROP_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispObject.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispobjCtrlCmdGetRgUnderflowProp"
#endif
    },
    {               /*  [4] */
        /*pFunc=*/      (void (*)(void)) dispobjCtrlCmdSetRgUnderflowProp_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x50700204u,
        /*paramSize=*/  sizeof(NV5070_CTRL_CMD_SET_RG_UNDERFLOW_PROP_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispObject.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispobjCtrlCmdSetRgUnderflowProp"
#endif
    },
    {               /*  [5] */
        /*pFunc=*/      (void (*)(void)) dispobjCtrlCmdGetRgFliplockProp_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x50700205u,
        /*paramSize=*/  sizeof(NV5070_CTRL_CMD_GET_RG_FLIPLOCK_PROP_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispObject.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispobjCtrlCmdGetRgFliplockProp"
#endif
    },
    {               /*  [6] */
        /*pFunc=*/      (void (*)(void)) dispobjCtrlCmdSetRgFliplockProp_IMPL,
        /*flags=*/      0x200u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x50700206u,
        /*paramSize=*/  sizeof(NV5070_CTRL_CMD_SET_RG_FLIPLOCK_PROP_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispObject.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispobjCtrlCmdSetRgFliplockProp"
#endif
    },
    {               /*  [7] */
        /*pFunc=*/      (void (*)(void)) dispobjCtrlCmdGetRgConnectedLockpin_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x50700207u,
        /*paramSize=*/  sizeof(NV5070_CTRL_CMD_GET_RG_CONNECTED_LOCKPIN_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispObject.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispobjCtrlCmdGetRgConnectedLockpin"
#endif
    },
    {               /*  [8] */
        /*pFunc=*/      (void (*)(void)) dispobjCtrlCmdGetRgConnectedLockpinStateless_IMPL,
        /*flags=*/      0x200u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x5070020au,
        /*paramSize=*/  sizeof(NV5070_CTRL_GET_RG_CONNECTED_LOCKPIN_STATELESS_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispObject.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispobjCtrlCmdGetRgConnectedLockpinStateless"
#endif
    },
    {               /*  [9] */
        /*pFunc=*/      (void (*)(void)) dispobjCtrlCmdGetRgScanLine_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x5070020cu,
        /*paramSize=*/  sizeof(NV5070_CTRL_CMD_GET_RG_SCAN_LINE_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispObject.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispobjCtrlCmdGetRgScanLine"
#endif
    },
    {               /*  [10] */
        /*pFunc=*/      (void (*)(void)) dispobjCtrlCmdGetSorSeqCtl_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x50700301u,
        /*paramSize=*/  sizeof(NV5070_CTRL_CMD_GET_SOR_SEQ_CTL_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispObject.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispobjCtrlCmdGetSorSeqCtl"
#endif
    },
    {               /*  [11] */
        /*pFunc=*/      (void (*)(void)) dispobjCtrlCmdSetSorSeqCtl_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x50700302u,
        /*paramSize=*/  sizeof(NV5070_CTRL_CMD_SET_SOR_SEQ_CTL_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispObject.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispobjCtrlCmdSetSorSeqCtl"
#endif
    },
    {               /*  [12] */
        /*pFunc=*/      (void (*)(void)) dispobjCtrlCmdSeqProgSpeed_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x50700305u,
        /*paramSize=*/  sizeof(NV5070_CTRL_SEQ_PROG_SPEED_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispObject.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispobjCtrlCmdSeqProgSpeed"
#endif
    },
    {               /*  [13] */
        /*pFunc=*/      (void (*)(void)) dispobjCtrlCmdGetSorPwm_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x50700420u,
        /*paramSize=*/  sizeof(NV5070_CTRL_CMD_GET_SOR_PWM_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispObject.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispobjCtrlCmdGetSorPwm"
#endif
    },
    {               /*  [14] */
        /*pFunc=*/      (void (*)(void)) dispobjCtrlCmdSetSorPwm_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x50700421u,
        /*paramSize=*/  sizeof(NV5070_CTRL_CMD_SET_SOR_PWM_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispObject.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispobjCtrlCmdSetSorPwm"
#endif
    },
    {               /*  [15] */
        /*pFunc=*/      (void (*)(void)) dispobjCtrlCmdGetSorOpMode_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x50700422u,
        /*paramSize=*/  sizeof(NV5070_CTRL_CMD_GET_SOR_OP_MODE_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispObject.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispobjCtrlCmdGetSorOpMode"
#endif
    },
    {               /*  [16] */
        /*pFunc=*/      (void (*)(void)) dispobjCtrlCmdSetSorOpMode_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x50700423u,
        /*paramSize=*/  sizeof(NV5070_CTRL_CMD_SET_SOR_OP_MODE_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispObject.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispobjCtrlCmdSetSorOpMode"
#endif
    },
    {               /*  [17] */
        /*pFunc=*/      (void (*)(void)) dispobjCtrlCmdSetSorFlushMode_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x50700457u,
        /*paramSize=*/  sizeof(NV5070_CTRL_SET_SOR_FLUSH_MODE_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispObject.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispobjCtrlCmdSetSorFlushMode"
#endif
    },
    {               /*  [18] */
        /*pFunc=*/      (void (*)(void)) dispobjCtrlCmdSystemGetCapsV2_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x50700709u,
        /*paramSize=*/  sizeof(NV5070_CTRL_SYSTEM_GET_CAPS_V2_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispObject.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispobjCtrlCmdSystemGetCapsV2"
#endif
    },
    {               /*  [19] */
        /*pFunc=*/      (void (*)(void)) dispobjCtrlCmdEventSetTrigger_IMPL,
        /*flags=*/      0x10u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x50700902u,
        /*paramSize=*/  0,
        /*pClassInfo=*/ &(__nvoc_class_def_DispObject.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispobjCtrlCmdEventSetTrigger"
#endif
    },

};

const struct NVOC_EXPORT_INFO __nvoc_export_info_DispObject = 
{
    /*numEntries=*/     20,
    /*pExportEntries=*/ __nvoc_exported_method_def_DispObject
};

void __nvoc_dtor_DisplayApi(DisplayApi*);
void __nvoc_dtor_DispObject(DispObject *pThis) {
    __nvoc_dtor_DisplayApi(&pThis->__nvoc_base_DisplayApi);
    PORT_UNREFERENCED_VARIABLE(pThis);
}

void __nvoc_init_dataField_DispObject(DispObject *pThis, RmHalspecOwner *pRmhalspecowner) {
    RmVariantHal *rmVariantHal = &pRmhalspecowner->rmVariantHal;
    PORT_UNREFERENCED_VARIABLE(pThis);
    PORT_UNREFERENCED_VARIABLE(pRmhalspecowner);
    PORT_UNREFERENCED_VARIABLE(rmVariantHal);
}

NV_STATUS __nvoc_ctor_DisplayApi(DisplayApi* , RmHalspecOwner* , struct CALL_CONTEXT *, struct RS_RES_ALLOC_PARAMS_INTERNAL *);
NV_STATUS __nvoc_ctor_DispObject(DispObject *pThis, RmHalspecOwner *pRmhalspecowner, struct CALL_CONTEXT * arg_pCallContext, struct RS_RES_ALLOC_PARAMS_INTERNAL * arg_pParams) {
    NV_STATUS status = NV_OK;
    status = __nvoc_ctor_DisplayApi(&pThis->__nvoc_base_DisplayApi, pRmhalspecowner, arg_pCallContext, arg_pParams);
    if (status != NV_OK) goto __nvoc_ctor_DispObject_fail_DisplayApi;
    __nvoc_init_dataField_DispObject(pThis, pRmhalspecowner);

    status = __nvoc_dispobjConstruct(pThis, arg_pCallContext, arg_pParams);
    if (status != NV_OK) goto __nvoc_ctor_DispObject_fail__init;
    goto __nvoc_ctor_DispObject_exit; // Success

__nvoc_ctor_DispObject_fail__init:
    __nvoc_dtor_DisplayApi(&pThis->__nvoc_base_DisplayApi);
__nvoc_ctor_DispObject_fail_DisplayApi:
__nvoc_ctor_DispObject_exit:

    return status;
}

static void __nvoc_init_funcTable_DispObject_1(DispObject *pThis, RmHalspecOwner *pRmhalspecowner) {
    RmVariantHal *rmVariantHal = &pRmhalspecowner->rmVariantHal;
    PORT_UNREFERENCED_VARIABLE(pThis);
    PORT_UNREFERENCED_VARIABLE(pRmhalspecowner);
    PORT_UNREFERENCED_VARIABLE(rmVariantHal);

    pThis->__dispobjCtrlCmdSetRmFreeFlags__ = &dispobjCtrlCmdSetRmFreeFlags_IMPL;

    pThis->__dispobjCtrlCmdIMPSetGetParameter__ = &dispobjCtrlCmdIMPSetGetParameter_IMPL;

    pThis->__dispobjCtrlCmdGetRgStatus__ = &dispobjCtrlCmdGetRgStatus_IMPL;

    pThis->__dispobjCtrlCmdGetRgUnderflowProp__ = &dispobjCtrlCmdGetRgUnderflowProp_IMPL;

    pThis->__dispobjCtrlCmdSetRgUnderflowProp__ = &dispobjCtrlCmdSetRgUnderflowProp_IMPL;

    pThis->__dispobjCtrlCmdGetRgFliplockProp__ = &dispobjCtrlCmdGetRgFliplockProp_IMPL;

    pThis->__dispobjCtrlCmdSetRgFliplockProp__ = &dispobjCtrlCmdSetRgFliplockProp_IMPL;

    pThis->__dispobjCtrlCmdGetRgConnectedLockpin__ = &dispobjCtrlCmdGetRgConnectedLockpin_IMPL;

    pThis->__dispobjCtrlCmdGetRgConnectedLockpinStateless__ = &dispobjCtrlCmdGetRgConnectedLockpinStateless_IMPL;

    pThis->__dispobjCtrlCmdGetRgScanLine__ = &dispobjCtrlCmdGetRgScanLine_IMPL;

    pThis->__dispobjCtrlCmdGetSorSeqCtl__ = &dispobjCtrlCmdGetSorSeqCtl_IMPL;

    pThis->__dispobjCtrlCmdSetSorSeqCtl__ = &dispobjCtrlCmdSetSorSeqCtl_IMPL;

    pThis->__dispobjCtrlCmdSeqProgSpeed__ = &dispobjCtrlCmdSeqProgSpeed_IMPL;

    pThis->__dispobjCtrlCmdGetSorPwm__ = &dispobjCtrlCmdGetSorPwm_IMPL;

    pThis->__dispobjCtrlCmdSetSorPwm__ = &dispobjCtrlCmdSetSorPwm_IMPL;

    pThis->__dispobjCtrlCmdGetSorOpMode__ = &dispobjCtrlCmdGetSorOpMode_IMPL;

    pThis->__dispobjCtrlCmdSetSorOpMode__ = &dispobjCtrlCmdSetSorOpMode_IMPL;

    pThis->__dispobjCtrlCmdSetSorFlushMode__ = &dispobjCtrlCmdSetSorFlushMode_IMPL;

    pThis->__dispobjCtrlCmdSystemGetCapsV2__ = &dispobjCtrlCmdSystemGetCapsV2_IMPL;

    pThis->__dispobjCtrlCmdEventSetTrigger__ = &dispobjCtrlCmdEventSetTrigger_IMPL;

    pThis->__dispobjShareCallback__ = &__nvoc_thunk_RmResource_dispobjShareCallback;

    pThis->__dispobjControl__ = &__nvoc_thunk_DisplayApi_dispobjControl;

    pThis->__dispobjAccessCallback__ = &__nvoc_thunk_RmResource_dispobjAccessCallback;

    pThis->__dispobjGetMemInterMapParams__ = &__nvoc_thunk_RmResource_dispobjGetMemInterMapParams;

    pThis->__dispobjUnmap__ = &__nvoc_thunk_RsResource_dispobjUnmap;

    pThis->__dispobjCheckMemInterUnmap__ = &__nvoc_thunk_RmResource_dispobjCheckMemInterUnmap;

    pThis->__dispobjSetNotificationShare__ = &__nvoc_thunk_Notifier_dispobjSetNotificationShare;

    pThis->__dispobjControlFilter__ = &__nvoc_thunk_RsResource_dispobjControlFilter;

    pThis->__dispobjGetRefCount__ = &__nvoc_thunk_RsResource_dispobjGetRefCount;

    pThis->__dispobjUnregisterEvent__ = &__nvoc_thunk_Notifier_dispobjUnregisterEvent;

    pThis->__dispobjMapTo__ = &__nvoc_thunk_RsResource_dispobjMapTo;

    pThis->__dispobjControl_Prologue__ = &__nvoc_thunk_DisplayApi_dispobjControl_Prologue;

    pThis->__dispobjCanCopy__ = &__nvoc_thunk_RsResource_dispobjCanCopy;

    pThis->__dispobjAddAdditionalDependants__ = &__nvoc_thunk_RsResource_dispobjAddAdditionalDependants;

    pThis->__dispobjPreDestruct__ = &__nvoc_thunk_RsResource_dispobjPreDestruct;

    pThis->__dispobjUnmapFrom__ = &__nvoc_thunk_RsResource_dispobjUnmapFrom;

    pThis->__dispobjGetNotificationListPtr__ = &__nvoc_thunk_Notifier_dispobjGetNotificationListPtr;

    pThis->__dispobjControl_Epilogue__ = &__nvoc_thunk_DisplayApi_dispobjControl_Epilogue;

    pThis->__dispobjGetNotificationShare__ = &__nvoc_thunk_Notifier_dispobjGetNotificationShare;

    pThis->__dispobjControlLookup__ = &__nvoc_thunk_RsResource_dispobjControlLookup;

    pThis->__dispobjMap__ = &__nvoc_thunk_RsResource_dispobjMap;

    pThis->__dispobjGetOrAllocNotifShare__ = &__nvoc_thunk_Notifier_dispobjGetOrAllocNotifShare;
}

void __nvoc_init_funcTable_DispObject(DispObject *pThis, RmHalspecOwner *pRmhalspecowner) {
    __nvoc_init_funcTable_DispObject_1(pThis, pRmhalspecowner);
}

void __nvoc_init_DisplayApi(DisplayApi*, RmHalspecOwner* );
void __nvoc_init_DispObject(DispObject *pThis, RmHalspecOwner *pRmhalspecowner) {
    pThis->__nvoc_pbase_DispObject = pThis;
    pThis->__nvoc_pbase_Object = &pThis->__nvoc_base_DisplayApi.__nvoc_base_RmResource.__nvoc_base_RsResource.__nvoc_base_Object;
    pThis->__nvoc_pbase_RsResource = &pThis->__nvoc_base_DisplayApi.__nvoc_base_RmResource.__nvoc_base_RsResource;
    pThis->__nvoc_pbase_RmResourceCommon = &pThis->__nvoc_base_DisplayApi.__nvoc_base_RmResource.__nvoc_base_RmResourceCommon;
    pThis->__nvoc_pbase_RmResource = &pThis->__nvoc_base_DisplayApi.__nvoc_base_RmResource;
    pThis->__nvoc_pbase_INotifier = &pThis->__nvoc_base_DisplayApi.__nvoc_base_Notifier.__nvoc_base_INotifier;
    pThis->__nvoc_pbase_Notifier = &pThis->__nvoc_base_DisplayApi.__nvoc_base_Notifier;
    pThis->__nvoc_pbase_DisplayApi = &pThis->__nvoc_base_DisplayApi;
    __nvoc_init_DisplayApi(&pThis->__nvoc_base_DisplayApi, pRmhalspecowner);
    __nvoc_init_funcTable_DispObject(pThis, pRmhalspecowner);
}

NV_STATUS __nvoc_objCreate_DispObject(DispObject **ppThis, Dynamic *pParent, NvU32 createFlags, struct CALL_CONTEXT * arg_pCallContext, struct RS_RES_ALLOC_PARAMS_INTERNAL * arg_pParams) {
    NV_STATUS status;
    Object *pParentObj;
    DispObject *pThis;
    RmHalspecOwner *pRmhalspecowner;

    pThis = portMemAllocNonPaged(sizeof(DispObject));
    if (pThis == NULL) return NV_ERR_NO_MEMORY;

    portMemSet(pThis, 0, sizeof(DispObject));

    __nvoc_initRtti(staticCast(pThis, Dynamic), &__nvoc_class_def_DispObject);

    if (pParent != NULL && !(createFlags & NVOC_OBJ_CREATE_FLAGS_PARENT_HALSPEC_ONLY))
    {
        pParentObj = dynamicCast(pParent, Object);
        objAddChild(pParentObj, &pThis->__nvoc_base_DisplayApi.__nvoc_base_RmResource.__nvoc_base_RsResource.__nvoc_base_Object);
    }
    else
    {
        pThis->__nvoc_base_DisplayApi.__nvoc_base_RmResource.__nvoc_base_RsResource.__nvoc_base_Object.pParent = NULL;
    }

    if ((pRmhalspecowner = dynamicCast(pParent, RmHalspecOwner)) == NULL)
        pRmhalspecowner = objFindAncestorOfType(RmHalspecOwner, pParent);
    NV_ASSERT_OR_RETURN(pRmhalspecowner != NULL, NV_ERR_INVALID_ARGUMENT);

    __nvoc_init_DispObject(pThis, pRmhalspecowner);
    status = __nvoc_ctor_DispObject(pThis, pRmhalspecowner, arg_pCallContext, arg_pParams);
    if (status != NV_OK) goto __nvoc_objCreate_DispObject_cleanup;

    *ppThis = pThis;
    return NV_OK;

__nvoc_objCreate_DispObject_cleanup:
    // do not call destructors here since the constructor already called them
    portMemFree(pThis);
    return status;
}

NV_STATUS __nvoc_objCreateDynamic_DispObject(DispObject **ppThis, Dynamic *pParent, NvU32 createFlags, va_list args) {
    NV_STATUS status;
    struct CALL_CONTEXT * arg_pCallContext = va_arg(args, struct CALL_CONTEXT *);
    struct RS_RES_ALLOC_PARAMS_INTERNAL * arg_pParams = va_arg(args, struct RS_RES_ALLOC_PARAMS_INTERNAL *);

    status = __nvoc_objCreate_DispObject(ppThis, pParent, createFlags, arg_pCallContext, arg_pParams);

    return status;
}

#ifdef DEBUG
char __nvoc_class_id_uniqueness_check_0x36aa0b = 1;
#endif

extern const struct NVOC_CLASS_DEF __nvoc_class_def_NvDispApi;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_Object;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_RsResource;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_RmResourceCommon;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_RmResource;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_INotifier;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_Notifier;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_DisplayApi;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_DispObject;

void __nvoc_init_NvDispApi(NvDispApi*, RmHalspecOwner* );
void __nvoc_init_funcTable_NvDispApi(NvDispApi*);
NV_STATUS __nvoc_ctor_NvDispApi(NvDispApi*, RmHalspecOwner* , struct CALL_CONTEXT * arg_pCallContext, struct RS_RES_ALLOC_PARAMS_INTERNAL * arg_pParams);
void __nvoc_init_dataField_NvDispApi(NvDispApi*);
void __nvoc_dtor_NvDispApi(NvDispApi*);
extern const struct NVOC_EXPORT_INFO __nvoc_export_info_NvDispApi;

static const struct NVOC_RTTI __nvoc_rtti_NvDispApi_NvDispApi = {
    /*pClassDef=*/          &__nvoc_class_def_NvDispApi,
    /*dtor=*/               (NVOC_DYNAMIC_DTOR) &__nvoc_dtor_NvDispApi,
    /*offset=*/             0,
};

static const struct NVOC_RTTI __nvoc_rtti_NvDispApi_Object = {
    /*pClassDef=*/          &__nvoc_class_def_Object,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(NvDispApi, __nvoc_base_DispObject.__nvoc_base_DisplayApi.__nvoc_base_RmResource.__nvoc_base_RsResource.__nvoc_base_Object),
};

static const struct NVOC_RTTI __nvoc_rtti_NvDispApi_RsResource = {
    /*pClassDef=*/          &__nvoc_class_def_RsResource,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(NvDispApi, __nvoc_base_DispObject.__nvoc_base_DisplayApi.__nvoc_base_RmResource.__nvoc_base_RsResource),
};

static const struct NVOC_RTTI __nvoc_rtti_NvDispApi_RmResourceCommon = {
    /*pClassDef=*/          &__nvoc_class_def_RmResourceCommon,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(NvDispApi, __nvoc_base_DispObject.__nvoc_base_DisplayApi.__nvoc_base_RmResource.__nvoc_base_RmResourceCommon),
};

static const struct NVOC_RTTI __nvoc_rtti_NvDispApi_RmResource = {
    /*pClassDef=*/          &__nvoc_class_def_RmResource,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(NvDispApi, __nvoc_base_DispObject.__nvoc_base_DisplayApi.__nvoc_base_RmResource),
};

static const struct NVOC_RTTI __nvoc_rtti_NvDispApi_INotifier = {
    /*pClassDef=*/          &__nvoc_class_def_INotifier,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(NvDispApi, __nvoc_base_DispObject.__nvoc_base_DisplayApi.__nvoc_base_Notifier.__nvoc_base_INotifier),
};

static const struct NVOC_RTTI __nvoc_rtti_NvDispApi_Notifier = {
    /*pClassDef=*/          &__nvoc_class_def_Notifier,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(NvDispApi, __nvoc_base_DispObject.__nvoc_base_DisplayApi.__nvoc_base_Notifier),
};

static const struct NVOC_RTTI __nvoc_rtti_NvDispApi_DisplayApi = {
    /*pClassDef=*/          &__nvoc_class_def_DisplayApi,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(NvDispApi, __nvoc_base_DispObject.__nvoc_base_DisplayApi),
};

static const struct NVOC_RTTI __nvoc_rtti_NvDispApi_DispObject = {
    /*pClassDef=*/          &__nvoc_class_def_DispObject,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(NvDispApi, __nvoc_base_DispObject),
};

static const struct NVOC_CASTINFO __nvoc_castinfo_NvDispApi = {
    /*numRelatives=*/       9,
    /*relatives=*/ {
        &__nvoc_rtti_NvDispApi_NvDispApi,
        &__nvoc_rtti_NvDispApi_DispObject,
        &__nvoc_rtti_NvDispApi_DisplayApi,
        &__nvoc_rtti_NvDispApi_Notifier,
        &__nvoc_rtti_NvDispApi_INotifier,
        &__nvoc_rtti_NvDispApi_RmResource,
        &__nvoc_rtti_NvDispApi_RmResourceCommon,
        &__nvoc_rtti_NvDispApi_RsResource,
        &__nvoc_rtti_NvDispApi_Object,
    },
};

const struct NVOC_CLASS_DEF __nvoc_class_def_NvDispApi = 
{
    /*classInfo=*/ {
        /*size=*/               sizeof(NvDispApi),
        /*classId=*/            classId(NvDispApi),
        /*providerId=*/         &__nvoc_rtti_provider,
#if NV_PRINTF_STRINGS_ALLOWED
        /*name=*/               "NvDispApi",
#endif
    },
    /*objCreatefn=*/        (NVOC_DYNAMIC_OBJ_CREATE) &__nvoc_objCreateDynamic_NvDispApi,
    /*pCastInfo=*/          &__nvoc_castinfo_NvDispApi,
    /*pExportInfo=*/        &__nvoc_export_info_NvDispApi
};

static NvBool __nvoc_thunk_RmResource_nvdispapiShareCallback(struct NvDispApi *pResource, struct RsClient *pInvokingClient, struct RsResourceRef *pParentRef, RS_SHARE_POLICY *pSharePolicy) {
    return rmresShareCallback((struct RmResource *)(((unsigned char *)pResource) + __nvoc_rtti_NvDispApi_RmResource.offset), pInvokingClient, pParentRef, pSharePolicy);
}

static NV_STATUS __nvoc_thunk_DisplayApi_nvdispapiControl(struct NvDispApi *pDisplayApi, struct CALL_CONTEXT *pCallContext, struct RS_RES_CONTROL_PARAMS_INTERNAL *pParams) {
    return dispapiControl((struct DisplayApi *)(((unsigned char *)pDisplayApi) + __nvoc_rtti_NvDispApi_DisplayApi.offset), pCallContext, pParams);
}

static NvBool __nvoc_thunk_RmResource_nvdispapiAccessCallback(struct NvDispApi *pResource, struct RsClient *pInvokingClient, void *pAllocParams, RsAccessRight accessRight) {
    return rmresAccessCallback((struct RmResource *)(((unsigned char *)pResource) + __nvoc_rtti_NvDispApi_RmResource.offset), pInvokingClient, pAllocParams, accessRight);
}

static NV_STATUS __nvoc_thunk_RmResource_nvdispapiGetMemInterMapParams(struct NvDispApi *pRmResource, RMRES_MEM_INTER_MAP_PARAMS *pParams) {
    return rmresGetMemInterMapParams((struct RmResource *)(((unsigned char *)pRmResource) + __nvoc_rtti_NvDispApi_RmResource.offset), pParams);
}

static NV_STATUS __nvoc_thunk_RsResource_nvdispapiUnmap(struct NvDispApi *pResource, struct CALL_CONTEXT *pCallContext, RsCpuMapping *pCpuMapping) {
    return resUnmap((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_NvDispApi_RsResource.offset), pCallContext, pCpuMapping);
}

static NV_STATUS __nvoc_thunk_RmResource_nvdispapiCheckMemInterUnmap(struct NvDispApi *pRmResource, NvBool bSubdeviceHandleProvided) {
    return rmresCheckMemInterUnmap((struct RmResource *)(((unsigned char *)pRmResource) + __nvoc_rtti_NvDispApi_RmResource.offset), bSubdeviceHandleProvided);
}

static void __nvoc_thunk_Notifier_nvdispapiSetNotificationShare(struct NvDispApi *pNotifier, struct NotifShare *pNotifShare) {
    notifySetNotificationShare((struct Notifier *)(((unsigned char *)pNotifier) + __nvoc_rtti_NvDispApi_Notifier.offset), pNotifShare);
}

static NV_STATUS __nvoc_thunk_RsResource_nvdispapiControlFilter(struct NvDispApi *pResource, struct CALL_CONTEXT *pCallContext, struct RS_RES_CONTROL_PARAMS_INTERNAL *pParams) {
    return resControlFilter((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_NvDispApi_RsResource.offset), pCallContext, pParams);
}

static NvU32 __nvoc_thunk_RsResource_nvdispapiGetRefCount(struct NvDispApi *pResource) {
    return resGetRefCount((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_NvDispApi_RsResource.offset));
}

static NV_STATUS __nvoc_thunk_Notifier_nvdispapiUnregisterEvent(struct NvDispApi *pNotifier, NvHandle hNotifierClient, NvHandle hNotifierResource, NvHandle hEventClient, NvHandle hEvent) {
    return notifyUnregisterEvent((struct Notifier *)(((unsigned char *)pNotifier) + __nvoc_rtti_NvDispApi_Notifier.offset), hNotifierClient, hNotifierResource, hEventClient, hEvent);
}

static NV_STATUS __nvoc_thunk_RsResource_nvdispapiMapTo(struct NvDispApi *pResource, RS_RES_MAP_TO_PARAMS *pParams) {
    return resMapTo((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_NvDispApi_RsResource.offset), pParams);
}

static NV_STATUS __nvoc_thunk_DisplayApi_nvdispapiControl_Prologue(struct NvDispApi *pDisplayApi, struct CALL_CONTEXT *pCallContext, struct RS_RES_CONTROL_PARAMS_INTERNAL *pRsParams) {
    return dispapiControl_Prologue((struct DisplayApi *)(((unsigned char *)pDisplayApi) + __nvoc_rtti_NvDispApi_DisplayApi.offset), pCallContext, pRsParams);
}

static NvBool __nvoc_thunk_RsResource_nvdispapiCanCopy(struct NvDispApi *pResource) {
    return resCanCopy((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_NvDispApi_RsResource.offset));
}

static void __nvoc_thunk_RsResource_nvdispapiAddAdditionalDependants(struct RsClient *pClient, struct NvDispApi *pResource, RsResourceRef *pReference) {
    resAddAdditionalDependants(pClient, (struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_NvDispApi_RsResource.offset), pReference);
}

static void __nvoc_thunk_RsResource_nvdispapiPreDestruct(struct NvDispApi *pResource) {
    resPreDestruct((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_NvDispApi_RsResource.offset));
}

static NV_STATUS __nvoc_thunk_RsResource_nvdispapiUnmapFrom(struct NvDispApi *pResource, RS_RES_UNMAP_FROM_PARAMS *pParams) {
    return resUnmapFrom((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_NvDispApi_RsResource.offset), pParams);
}

static PEVENTNOTIFICATION *__nvoc_thunk_Notifier_nvdispapiGetNotificationListPtr(struct NvDispApi *pNotifier) {
    return notifyGetNotificationListPtr((struct Notifier *)(((unsigned char *)pNotifier) + __nvoc_rtti_NvDispApi_Notifier.offset));
}

static void __nvoc_thunk_DisplayApi_nvdispapiControl_Epilogue(struct NvDispApi *pDisplayApi, struct CALL_CONTEXT *pCallContext, struct RS_RES_CONTROL_PARAMS_INTERNAL *pRsParams) {
    dispapiControl_Epilogue((struct DisplayApi *)(((unsigned char *)pDisplayApi) + __nvoc_rtti_NvDispApi_DisplayApi.offset), pCallContext, pRsParams);
}

static struct NotifShare *__nvoc_thunk_Notifier_nvdispapiGetNotificationShare(struct NvDispApi *pNotifier) {
    return notifyGetNotificationShare((struct Notifier *)(((unsigned char *)pNotifier) + __nvoc_rtti_NvDispApi_Notifier.offset));
}

static NV_STATUS __nvoc_thunk_RsResource_nvdispapiControlLookup(struct NvDispApi *pResource, struct RS_RES_CONTROL_PARAMS_INTERNAL *pParams, const struct NVOC_EXPORTED_METHOD_DEF **ppEntry) {
    return resControlLookup((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_NvDispApi_RsResource.offset), pParams, ppEntry);
}

static NV_STATUS __nvoc_thunk_RsResource_nvdispapiMap(struct NvDispApi *pResource, struct CALL_CONTEXT *pCallContext, RS_CPU_MAP_PARAMS *pParams, RsCpuMapping *pCpuMapping) {
    return resMap((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_NvDispApi_RsResource.offset), pCallContext, pParams, pCpuMapping);
}

static NV_STATUS __nvoc_thunk_Notifier_nvdispapiGetOrAllocNotifShare(struct NvDispApi *pNotifier, NvHandle hNotifierClient, NvHandle hNotifierResource, struct NotifShare **ppNotifShare) {
    return notifyGetOrAllocNotifShare((struct Notifier *)(((unsigned char *)pNotifier) + __nvoc_rtti_NvDispApi_Notifier.offset), hNotifierClient, hNotifierResource, ppNotifShare);
}

static const struct NVOC_EXPORTED_METHOD_DEF __nvoc_exported_method_def_NvDispApi[] = 
{
    {               /*  [0] */
        /*pFunc=*/      (void (*)(void)) nvdispapiCtrlCmdIdleChannel_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0xc3700101u,
        /*paramSize=*/  sizeof(NVC370_CTRL_IDLE_CHANNEL_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_NvDispApi.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "nvdispapiCtrlCmdIdleChannel"
#endif
    },
    {               /*  [1] */
        /*pFunc=*/      (void (*)(void)) nvdispapiCtrlCmdSetAccl_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0xc3700102u,
        /*paramSize=*/  sizeof(NVC370_CTRL_SET_ACCL_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_NvDispApi.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "nvdispapiCtrlCmdSetAccl"
#endif
    },
    {               /*  [2] */
        /*pFunc=*/      (void (*)(void)) nvdispapiCtrlCmdGetAccl_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0xc3700103u,
        /*paramSize=*/  sizeof(NVC370_CTRL_GET_ACCL_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_NvDispApi.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "nvdispapiCtrlCmdGetAccl"
#endif
    },
    {               /*  [3] */
        /*pFunc=*/      (void (*)(void)) nvdispapiCtrlCmdGetChannelInfo_IMPL,
        /*flags=*/      0x200u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0xc3700104u,
        /*paramSize=*/  sizeof(NVC370_CTRL_CMD_GET_CHANNEL_INFO_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_NvDispApi.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "nvdispapiCtrlCmdGetChannelInfo"
#endif
    },
    {               /*  [4] */
        /*pFunc=*/      (void (*)(void)) nvdispapiCtrlCmdGetLockpinsCaps_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0xc3700201u,
        /*paramSize=*/  sizeof(NVC370_CTRL_GET_LOCKPINS_CAPS_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_NvDispApi.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "nvdispapiCtrlCmdGetLockpinsCaps"
#endif
    },
    {               /*  [5] */
        /*pFunc=*/      (void (*)(void)) nvdispapiCtrlCmdSetSwaprdyGpioWar_IMPL,
        /*flags=*/      0x200u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0xc3700202u,
        /*paramSize=*/  sizeof(NVC370_CTRL_SET_SWAPRDY_GPIO_WAR_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_NvDispApi.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "nvdispapiCtrlCmdSetSwaprdyGpioWar"
#endif
    },
    {               /*  [6] */
        /*pFunc=*/      (void (*)(void)) nvdispapiCtrlCmdSetForceModeswitchFlagsOverrides_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0xc3700602u,
        /*paramSize=*/  sizeof(NVC370_CTRL_CMD_SET_FORCE_MODESWITCH_FLAGS_OVERRIDES_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_NvDispApi.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "nvdispapiCtrlCmdSetForceModeswitchFlagsOverrides"
#endif
    },

};

const struct NVOC_EXPORT_INFO __nvoc_export_info_NvDispApi = 
{
    /*numEntries=*/     7,
    /*pExportEntries=*/ __nvoc_exported_method_def_NvDispApi
};

void __nvoc_dtor_DispObject(DispObject*);
void __nvoc_dtor_NvDispApi(NvDispApi *pThis) {
    __nvoc_dtor_DispObject(&pThis->__nvoc_base_DispObject);
    PORT_UNREFERENCED_VARIABLE(pThis);
}

void __nvoc_init_dataField_NvDispApi(NvDispApi *pThis) {
    PORT_UNREFERENCED_VARIABLE(pThis);
}

NV_STATUS __nvoc_ctor_DispObject(DispObject* , RmHalspecOwner* , struct CALL_CONTEXT *, struct RS_RES_ALLOC_PARAMS_INTERNAL *);
NV_STATUS __nvoc_ctor_NvDispApi(NvDispApi *pThis, RmHalspecOwner *pRmhalspecowner, struct CALL_CONTEXT * arg_pCallContext, struct RS_RES_ALLOC_PARAMS_INTERNAL * arg_pParams) {
    NV_STATUS status = NV_OK;
    status = __nvoc_ctor_DispObject(&pThis->__nvoc_base_DispObject, pRmhalspecowner, arg_pCallContext, arg_pParams);
    if (status != NV_OK) goto __nvoc_ctor_NvDispApi_fail_DispObject;
    __nvoc_init_dataField_NvDispApi(pThis);

    status = __nvoc_nvdispapiConstruct(pThis, arg_pCallContext, arg_pParams);
    if (status != NV_OK) goto __nvoc_ctor_NvDispApi_fail__init;
    goto __nvoc_ctor_NvDispApi_exit; // Success

__nvoc_ctor_NvDispApi_fail__init:
    __nvoc_dtor_DispObject(&pThis->__nvoc_base_DispObject);
__nvoc_ctor_NvDispApi_fail_DispObject:
__nvoc_ctor_NvDispApi_exit:

    return status;
}

static void __nvoc_init_funcTable_NvDispApi_1(NvDispApi *pThis) {
    PORT_UNREFERENCED_VARIABLE(pThis);

    pThis->__nvdispapiCtrlCmdIdleChannel__ = &nvdispapiCtrlCmdIdleChannel_IMPL;

    pThis->__nvdispapiCtrlCmdSetAccl__ = &nvdispapiCtrlCmdSetAccl_IMPL;

    pThis->__nvdispapiCtrlCmdGetAccl__ = &nvdispapiCtrlCmdGetAccl_IMPL;

    pThis->__nvdispapiCtrlCmdGetChannelInfo__ = &nvdispapiCtrlCmdGetChannelInfo_IMPL;

    pThis->__nvdispapiCtrlCmdSetSwaprdyGpioWar__ = &nvdispapiCtrlCmdSetSwaprdyGpioWar_IMPL;

    pThis->__nvdispapiCtrlCmdGetLockpinsCaps__ = &nvdispapiCtrlCmdGetLockpinsCaps_IMPL;

    pThis->__nvdispapiCtrlCmdSetForceModeswitchFlagsOverrides__ = &nvdispapiCtrlCmdSetForceModeswitchFlagsOverrides_IMPL;

    pThis->__nvdispapiShareCallback__ = &__nvoc_thunk_RmResource_nvdispapiShareCallback;

    pThis->__nvdispapiControl__ = &__nvoc_thunk_DisplayApi_nvdispapiControl;

    pThis->__nvdispapiAccessCallback__ = &__nvoc_thunk_RmResource_nvdispapiAccessCallback;

    pThis->__nvdispapiGetMemInterMapParams__ = &__nvoc_thunk_RmResource_nvdispapiGetMemInterMapParams;

    pThis->__nvdispapiUnmap__ = &__nvoc_thunk_RsResource_nvdispapiUnmap;

    pThis->__nvdispapiCheckMemInterUnmap__ = &__nvoc_thunk_RmResource_nvdispapiCheckMemInterUnmap;

    pThis->__nvdispapiSetNotificationShare__ = &__nvoc_thunk_Notifier_nvdispapiSetNotificationShare;

    pThis->__nvdispapiControlFilter__ = &__nvoc_thunk_RsResource_nvdispapiControlFilter;

    pThis->__nvdispapiGetRefCount__ = &__nvoc_thunk_RsResource_nvdispapiGetRefCount;

    pThis->__nvdispapiUnregisterEvent__ = &__nvoc_thunk_Notifier_nvdispapiUnregisterEvent;

    pThis->__nvdispapiMapTo__ = &__nvoc_thunk_RsResource_nvdispapiMapTo;

    pThis->__nvdispapiControl_Prologue__ = &__nvoc_thunk_DisplayApi_nvdispapiControl_Prologue;

    pThis->__nvdispapiCanCopy__ = &__nvoc_thunk_RsResource_nvdispapiCanCopy;

    pThis->__nvdispapiAddAdditionalDependants__ = &__nvoc_thunk_RsResource_nvdispapiAddAdditionalDependants;

    pThis->__nvdispapiPreDestruct__ = &__nvoc_thunk_RsResource_nvdispapiPreDestruct;

    pThis->__nvdispapiUnmapFrom__ = &__nvoc_thunk_RsResource_nvdispapiUnmapFrom;

    pThis->__nvdispapiGetNotificationListPtr__ = &__nvoc_thunk_Notifier_nvdispapiGetNotificationListPtr;

    pThis->__nvdispapiControl_Epilogue__ = &__nvoc_thunk_DisplayApi_nvdispapiControl_Epilogue;

    pThis->__nvdispapiGetNotificationShare__ = &__nvoc_thunk_Notifier_nvdispapiGetNotificationShare;

    pThis->__nvdispapiControlLookup__ = &__nvoc_thunk_RsResource_nvdispapiControlLookup;

    pThis->__nvdispapiMap__ = &__nvoc_thunk_RsResource_nvdispapiMap;

    pThis->__nvdispapiGetOrAllocNotifShare__ = &__nvoc_thunk_Notifier_nvdispapiGetOrAllocNotifShare;
}

void __nvoc_init_funcTable_NvDispApi(NvDispApi *pThis) {
    __nvoc_init_funcTable_NvDispApi_1(pThis);
}

void __nvoc_init_DispObject(DispObject*, RmHalspecOwner* );
void __nvoc_init_NvDispApi(NvDispApi *pThis, RmHalspecOwner *pRmhalspecowner) {
    pThis->__nvoc_pbase_NvDispApi = pThis;
    pThis->__nvoc_pbase_Object = &pThis->__nvoc_base_DispObject.__nvoc_base_DisplayApi.__nvoc_base_RmResource.__nvoc_base_RsResource.__nvoc_base_Object;
    pThis->__nvoc_pbase_RsResource = &pThis->__nvoc_base_DispObject.__nvoc_base_DisplayApi.__nvoc_base_RmResource.__nvoc_base_RsResource;
    pThis->__nvoc_pbase_RmResourceCommon = &pThis->__nvoc_base_DispObject.__nvoc_base_DisplayApi.__nvoc_base_RmResource.__nvoc_base_RmResourceCommon;
    pThis->__nvoc_pbase_RmResource = &pThis->__nvoc_base_DispObject.__nvoc_base_DisplayApi.__nvoc_base_RmResource;
    pThis->__nvoc_pbase_INotifier = &pThis->__nvoc_base_DispObject.__nvoc_base_DisplayApi.__nvoc_base_Notifier.__nvoc_base_INotifier;
    pThis->__nvoc_pbase_Notifier = &pThis->__nvoc_base_DispObject.__nvoc_base_DisplayApi.__nvoc_base_Notifier;
    pThis->__nvoc_pbase_DisplayApi = &pThis->__nvoc_base_DispObject.__nvoc_base_DisplayApi;
    pThis->__nvoc_pbase_DispObject = &pThis->__nvoc_base_DispObject;
    __nvoc_init_DispObject(&pThis->__nvoc_base_DispObject, pRmhalspecowner);
    __nvoc_init_funcTable_NvDispApi(pThis);
}

NV_STATUS __nvoc_objCreate_NvDispApi(NvDispApi **ppThis, Dynamic *pParent, NvU32 createFlags, struct CALL_CONTEXT * arg_pCallContext, struct RS_RES_ALLOC_PARAMS_INTERNAL * arg_pParams) {
    NV_STATUS status;
    Object *pParentObj;
    NvDispApi *pThis;
    RmHalspecOwner *pRmhalspecowner;

    pThis = portMemAllocNonPaged(sizeof(NvDispApi));
    if (pThis == NULL) return NV_ERR_NO_MEMORY;

    portMemSet(pThis, 0, sizeof(NvDispApi));

    __nvoc_initRtti(staticCast(pThis, Dynamic), &__nvoc_class_def_NvDispApi);

    if (pParent != NULL && !(createFlags & NVOC_OBJ_CREATE_FLAGS_PARENT_HALSPEC_ONLY))
    {
        pParentObj = dynamicCast(pParent, Object);
        objAddChild(pParentObj, &pThis->__nvoc_base_DispObject.__nvoc_base_DisplayApi.__nvoc_base_RmResource.__nvoc_base_RsResource.__nvoc_base_Object);
    }
    else
    {
        pThis->__nvoc_base_DispObject.__nvoc_base_DisplayApi.__nvoc_base_RmResource.__nvoc_base_RsResource.__nvoc_base_Object.pParent = NULL;
    }

    if ((pRmhalspecowner = dynamicCast(pParent, RmHalspecOwner)) == NULL)
        pRmhalspecowner = objFindAncestorOfType(RmHalspecOwner, pParent);
    NV_ASSERT_OR_RETURN(pRmhalspecowner != NULL, NV_ERR_INVALID_ARGUMENT);

    __nvoc_init_NvDispApi(pThis, pRmhalspecowner);
    status = __nvoc_ctor_NvDispApi(pThis, pRmhalspecowner, arg_pCallContext, arg_pParams);
    if (status != NV_OK) goto __nvoc_objCreate_NvDispApi_cleanup;

    *ppThis = pThis;
    return NV_OK;

__nvoc_objCreate_NvDispApi_cleanup:
    // do not call destructors here since the constructor already called them
    portMemFree(pThis);
    return status;
}

NV_STATUS __nvoc_objCreateDynamic_NvDispApi(NvDispApi **ppThis, Dynamic *pParent, NvU32 createFlags, va_list args) {
    NV_STATUS status;
    struct CALL_CONTEXT * arg_pCallContext = va_arg(args, struct CALL_CONTEXT *);
    struct RS_RES_ALLOC_PARAMS_INTERNAL * arg_pParams = va_arg(args, struct RS_RES_ALLOC_PARAMS_INTERNAL *);

    status = __nvoc_objCreate_NvDispApi(ppThis, pParent, createFlags, arg_pCallContext, arg_pParams);

    return status;
}

#ifdef DEBUG
char __nvoc_class_id_uniqueness_check_0x6aa5e2 = 1;
#endif

extern const struct NVOC_CLASS_DEF __nvoc_class_def_DispSwObj;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_Object;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_RsResource;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_RmResourceCommon;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_RmResource;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_INotifier;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_Notifier;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_DisplayApi;

void __nvoc_init_DispSwObj(DispSwObj*, RmHalspecOwner* );
void __nvoc_init_funcTable_DispSwObj(DispSwObj*);
NV_STATUS __nvoc_ctor_DispSwObj(DispSwObj*, RmHalspecOwner* , struct CALL_CONTEXT * arg_pCallContext, struct RS_RES_ALLOC_PARAMS_INTERNAL * arg_pParams);
void __nvoc_init_dataField_DispSwObj(DispSwObj*);
void __nvoc_dtor_DispSwObj(DispSwObj*);
extern const struct NVOC_EXPORT_INFO __nvoc_export_info_DispSwObj;

static const struct NVOC_RTTI __nvoc_rtti_DispSwObj_DispSwObj = {
    /*pClassDef=*/          &__nvoc_class_def_DispSwObj,
    /*dtor=*/               (NVOC_DYNAMIC_DTOR) &__nvoc_dtor_DispSwObj,
    /*offset=*/             0,
};

static const struct NVOC_RTTI __nvoc_rtti_DispSwObj_Object = {
    /*pClassDef=*/          &__nvoc_class_def_Object,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(DispSwObj, __nvoc_base_DisplayApi.__nvoc_base_RmResource.__nvoc_base_RsResource.__nvoc_base_Object),
};

static const struct NVOC_RTTI __nvoc_rtti_DispSwObj_RsResource = {
    /*pClassDef=*/          &__nvoc_class_def_RsResource,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(DispSwObj, __nvoc_base_DisplayApi.__nvoc_base_RmResource.__nvoc_base_RsResource),
};

static const struct NVOC_RTTI __nvoc_rtti_DispSwObj_RmResourceCommon = {
    /*pClassDef=*/          &__nvoc_class_def_RmResourceCommon,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(DispSwObj, __nvoc_base_DisplayApi.__nvoc_base_RmResource.__nvoc_base_RmResourceCommon),
};

static const struct NVOC_RTTI __nvoc_rtti_DispSwObj_RmResource = {
    /*pClassDef=*/          &__nvoc_class_def_RmResource,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(DispSwObj, __nvoc_base_DisplayApi.__nvoc_base_RmResource),
};

static const struct NVOC_RTTI __nvoc_rtti_DispSwObj_INotifier = {
    /*pClassDef=*/          &__nvoc_class_def_INotifier,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(DispSwObj, __nvoc_base_DisplayApi.__nvoc_base_Notifier.__nvoc_base_INotifier),
};

static const struct NVOC_RTTI __nvoc_rtti_DispSwObj_Notifier = {
    /*pClassDef=*/          &__nvoc_class_def_Notifier,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(DispSwObj, __nvoc_base_DisplayApi.__nvoc_base_Notifier),
};

static const struct NVOC_RTTI __nvoc_rtti_DispSwObj_DisplayApi = {
    /*pClassDef=*/          &__nvoc_class_def_DisplayApi,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(DispSwObj, __nvoc_base_DisplayApi),
};

static const struct NVOC_CASTINFO __nvoc_castinfo_DispSwObj = {
    /*numRelatives=*/       8,
    /*relatives=*/ {
        &__nvoc_rtti_DispSwObj_DispSwObj,
        &__nvoc_rtti_DispSwObj_DisplayApi,
        &__nvoc_rtti_DispSwObj_Notifier,
        &__nvoc_rtti_DispSwObj_INotifier,
        &__nvoc_rtti_DispSwObj_RmResource,
        &__nvoc_rtti_DispSwObj_RmResourceCommon,
        &__nvoc_rtti_DispSwObj_RsResource,
        &__nvoc_rtti_DispSwObj_Object,
    },
};

const struct NVOC_CLASS_DEF __nvoc_class_def_DispSwObj = 
{
    /*classInfo=*/ {
        /*size=*/               sizeof(DispSwObj),
        /*classId=*/            classId(DispSwObj),
        /*providerId=*/         &__nvoc_rtti_provider,
#if NV_PRINTF_STRINGS_ALLOWED
        /*name=*/               "DispSwObj",
#endif
    },
    /*objCreatefn=*/        (NVOC_DYNAMIC_OBJ_CREATE) &__nvoc_objCreateDynamic_DispSwObj,
    /*pCastInfo=*/          &__nvoc_castinfo_DispSwObj,
    /*pExportInfo=*/        &__nvoc_export_info_DispSwObj
};

static NvBool __nvoc_thunk_RmResource_dispswobjShareCallback(struct DispSwObj *pResource, struct RsClient *pInvokingClient, struct RsResourceRef *pParentRef, RS_SHARE_POLICY *pSharePolicy) {
    return rmresShareCallback((struct RmResource *)(((unsigned char *)pResource) + __nvoc_rtti_DispSwObj_RmResource.offset), pInvokingClient, pParentRef, pSharePolicy);
}

static NV_STATUS __nvoc_thunk_DisplayApi_dispswobjControl(struct DispSwObj *pDisplayApi, struct CALL_CONTEXT *pCallContext, struct RS_RES_CONTROL_PARAMS_INTERNAL *pParams) {
    return dispapiControl((struct DisplayApi *)(((unsigned char *)pDisplayApi) + __nvoc_rtti_DispSwObj_DisplayApi.offset), pCallContext, pParams);
}

static NvBool __nvoc_thunk_RmResource_dispswobjAccessCallback(struct DispSwObj *pResource, struct RsClient *pInvokingClient, void *pAllocParams, RsAccessRight accessRight) {
    return rmresAccessCallback((struct RmResource *)(((unsigned char *)pResource) + __nvoc_rtti_DispSwObj_RmResource.offset), pInvokingClient, pAllocParams, accessRight);
}

static NV_STATUS __nvoc_thunk_RmResource_dispswobjGetMemInterMapParams(struct DispSwObj *pRmResource, RMRES_MEM_INTER_MAP_PARAMS *pParams) {
    return rmresGetMemInterMapParams((struct RmResource *)(((unsigned char *)pRmResource) + __nvoc_rtti_DispSwObj_RmResource.offset), pParams);
}

static NV_STATUS __nvoc_thunk_RsResource_dispswobjUnmap(struct DispSwObj *pResource, struct CALL_CONTEXT *pCallContext, RsCpuMapping *pCpuMapping) {
    return resUnmap((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DispSwObj_RsResource.offset), pCallContext, pCpuMapping);
}

static NV_STATUS __nvoc_thunk_RmResource_dispswobjCheckMemInterUnmap(struct DispSwObj *pRmResource, NvBool bSubdeviceHandleProvided) {
    return rmresCheckMemInterUnmap((struct RmResource *)(((unsigned char *)pRmResource) + __nvoc_rtti_DispSwObj_RmResource.offset), bSubdeviceHandleProvided);
}

static void __nvoc_thunk_Notifier_dispswobjSetNotificationShare(struct DispSwObj *pNotifier, struct NotifShare *pNotifShare) {
    notifySetNotificationShare((struct Notifier *)(((unsigned char *)pNotifier) + __nvoc_rtti_DispSwObj_Notifier.offset), pNotifShare);
}

static NV_STATUS __nvoc_thunk_RsResource_dispswobjControlFilter(struct DispSwObj *pResource, struct CALL_CONTEXT *pCallContext, struct RS_RES_CONTROL_PARAMS_INTERNAL *pParams) {
    return resControlFilter((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DispSwObj_RsResource.offset), pCallContext, pParams);
}

static NvU32 __nvoc_thunk_RsResource_dispswobjGetRefCount(struct DispSwObj *pResource) {
    return resGetRefCount((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DispSwObj_RsResource.offset));
}

static NV_STATUS __nvoc_thunk_Notifier_dispswobjUnregisterEvent(struct DispSwObj *pNotifier, NvHandle hNotifierClient, NvHandle hNotifierResource, NvHandle hEventClient, NvHandle hEvent) {
    return notifyUnregisterEvent((struct Notifier *)(((unsigned char *)pNotifier) + __nvoc_rtti_DispSwObj_Notifier.offset), hNotifierClient, hNotifierResource, hEventClient, hEvent);
}

static NV_STATUS __nvoc_thunk_RsResource_dispswobjMapTo(struct DispSwObj *pResource, RS_RES_MAP_TO_PARAMS *pParams) {
    return resMapTo((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DispSwObj_RsResource.offset), pParams);
}

static NV_STATUS __nvoc_thunk_DisplayApi_dispswobjControl_Prologue(struct DispSwObj *pDisplayApi, struct CALL_CONTEXT *pCallContext, struct RS_RES_CONTROL_PARAMS_INTERNAL *pRsParams) {
    return dispapiControl_Prologue((struct DisplayApi *)(((unsigned char *)pDisplayApi) + __nvoc_rtti_DispSwObj_DisplayApi.offset), pCallContext, pRsParams);
}

static NvBool __nvoc_thunk_RsResource_dispswobjCanCopy(struct DispSwObj *pResource) {
    return resCanCopy((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DispSwObj_RsResource.offset));
}

static void __nvoc_thunk_RsResource_dispswobjAddAdditionalDependants(struct RsClient *pClient, struct DispSwObj *pResource, RsResourceRef *pReference) {
    resAddAdditionalDependants(pClient, (struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DispSwObj_RsResource.offset), pReference);
}

static void __nvoc_thunk_RsResource_dispswobjPreDestruct(struct DispSwObj *pResource) {
    resPreDestruct((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DispSwObj_RsResource.offset));
}

static NV_STATUS __nvoc_thunk_RsResource_dispswobjUnmapFrom(struct DispSwObj *pResource, RS_RES_UNMAP_FROM_PARAMS *pParams) {
    return resUnmapFrom((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DispSwObj_RsResource.offset), pParams);
}

static PEVENTNOTIFICATION *__nvoc_thunk_Notifier_dispswobjGetNotificationListPtr(struct DispSwObj *pNotifier) {
    return notifyGetNotificationListPtr((struct Notifier *)(((unsigned char *)pNotifier) + __nvoc_rtti_DispSwObj_Notifier.offset));
}

static void __nvoc_thunk_DisplayApi_dispswobjControl_Epilogue(struct DispSwObj *pDisplayApi, struct CALL_CONTEXT *pCallContext, struct RS_RES_CONTROL_PARAMS_INTERNAL *pRsParams) {
    dispapiControl_Epilogue((struct DisplayApi *)(((unsigned char *)pDisplayApi) + __nvoc_rtti_DispSwObj_DisplayApi.offset), pCallContext, pRsParams);
}

static struct NotifShare *__nvoc_thunk_Notifier_dispswobjGetNotificationShare(struct DispSwObj *pNotifier) {
    return notifyGetNotificationShare((struct Notifier *)(((unsigned char *)pNotifier) + __nvoc_rtti_DispSwObj_Notifier.offset));
}

static NV_STATUS __nvoc_thunk_RsResource_dispswobjControlLookup(struct DispSwObj *pResource, struct RS_RES_CONTROL_PARAMS_INTERNAL *pParams, const struct NVOC_EXPORTED_METHOD_DEF **ppEntry) {
    return resControlLookup((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DispSwObj_RsResource.offset), pParams, ppEntry);
}

static NV_STATUS __nvoc_thunk_RsResource_dispswobjMap(struct DispSwObj *pResource, struct CALL_CONTEXT *pCallContext, RS_CPU_MAP_PARAMS *pParams, RsCpuMapping *pCpuMapping) {
    return resMap((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DispSwObj_RsResource.offset), pCallContext, pParams, pCpuMapping);
}

static NV_STATUS __nvoc_thunk_Notifier_dispswobjGetOrAllocNotifShare(struct DispSwObj *pNotifier, NvHandle hNotifierClient, NvHandle hNotifierResource, struct NotifShare **ppNotifShare) {
    return notifyGetOrAllocNotifShare((struct Notifier *)(((unsigned char *)pNotifier) + __nvoc_rtti_DispSwObj_Notifier.offset), hNotifierClient, hNotifierResource, ppNotifShare);
}

static const struct NVOC_EXPORTED_METHOD_DEF __nvoc_exported_method_def_DispSwObj[] = 
{
    {               /*  [0] */
        /*pFunc=*/      (void (*)(void)) dispswobjCtrlCmdIsModePossible_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0xc3720101u,
        /*paramSize=*/  sizeof(NVC372_CTRL_IS_MODE_POSSIBLE_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispSwObj.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispswobjCtrlCmdIsModePossible"
#endif
    },
    {               /*  [1] */
        /*pFunc=*/      (void (*)(void)) dispswobjCtrlCmdIsModePossibleOrSettings_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0xc3720102u,
        /*paramSize=*/  sizeof(NVC372_CTRL_IS_MODE_POSSIBLE_OR_SETTINGS_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispSwObj.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispswobjCtrlCmdIsModePossibleOrSettings"
#endif
    },
    {               /*  [2] */
        /*pFunc=*/      (void (*)(void)) dispswobjCtrlCmdVideoAdaptiveRefreshRate_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0xc3720103u,
        /*paramSize=*/  sizeof(NVC372_CTRL_CMD_VIDEO_ADAPTIVE_REFRESH_RATE_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispSwObj.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispswobjCtrlCmdVideoAdaptiveRefreshRate"
#endif
    },
    {               /*  [3] */
        /*pFunc=*/      (void (*)(void)) dispswobjCtrlCmdGetActiveViewportPointIn_IMPL,
        /*flags=*/      0x211u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0xc3720104u,
        /*paramSize=*/  sizeof(NVC372_CTRL_CMD_GET_ACTIVE_VIEWPORT_POINT_IN_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispSwObj.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispswobjCtrlCmdGetActiveViewportPointIn"
#endif
    },

};

const struct NVOC_EXPORT_INFO __nvoc_export_info_DispSwObj = 
{
    /*numEntries=*/     4,
    /*pExportEntries=*/ __nvoc_exported_method_def_DispSwObj
};

void __nvoc_dtor_DisplayApi(DisplayApi*);
void __nvoc_dtor_DispSwObj(DispSwObj *pThis) {
    __nvoc_dtor_DisplayApi(&pThis->__nvoc_base_DisplayApi);
    PORT_UNREFERENCED_VARIABLE(pThis);
}

void __nvoc_init_dataField_DispSwObj(DispSwObj *pThis) {
    PORT_UNREFERENCED_VARIABLE(pThis);
}

NV_STATUS __nvoc_ctor_DisplayApi(DisplayApi* , RmHalspecOwner* , struct CALL_CONTEXT *, struct RS_RES_ALLOC_PARAMS_INTERNAL *);
NV_STATUS __nvoc_ctor_DispSwObj(DispSwObj *pThis, RmHalspecOwner *pRmhalspecowner, struct CALL_CONTEXT * arg_pCallContext, struct RS_RES_ALLOC_PARAMS_INTERNAL * arg_pParams) {
    NV_STATUS status = NV_OK;
    status = __nvoc_ctor_DisplayApi(&pThis->__nvoc_base_DisplayApi, pRmhalspecowner, arg_pCallContext, arg_pParams);
    if (status != NV_OK) goto __nvoc_ctor_DispSwObj_fail_DisplayApi;
    __nvoc_init_dataField_DispSwObj(pThis);

    status = __nvoc_dispswobjConstruct(pThis, arg_pCallContext, arg_pParams);
    if (status != NV_OK) goto __nvoc_ctor_DispSwObj_fail__init;
    goto __nvoc_ctor_DispSwObj_exit; // Success

__nvoc_ctor_DispSwObj_fail__init:
    __nvoc_dtor_DisplayApi(&pThis->__nvoc_base_DisplayApi);
__nvoc_ctor_DispSwObj_fail_DisplayApi:
__nvoc_ctor_DispSwObj_exit:

    return status;
}

static void __nvoc_init_funcTable_DispSwObj_1(DispSwObj *pThis) {
    PORT_UNREFERENCED_VARIABLE(pThis);

    pThis->__dispswobjCtrlCmdIsModePossible__ = &dispswobjCtrlCmdIsModePossible_IMPL;

    pThis->__dispswobjCtrlCmdIsModePossibleOrSettings__ = &dispswobjCtrlCmdIsModePossibleOrSettings_IMPL;

    pThis->__dispswobjCtrlCmdVideoAdaptiveRefreshRate__ = &dispswobjCtrlCmdVideoAdaptiveRefreshRate_IMPL;

    pThis->__dispswobjCtrlCmdGetActiveViewportPointIn__ = &dispswobjCtrlCmdGetActiveViewportPointIn_IMPL;

    pThis->__dispswobjShareCallback__ = &__nvoc_thunk_RmResource_dispswobjShareCallback;

    pThis->__dispswobjControl__ = &__nvoc_thunk_DisplayApi_dispswobjControl;

    pThis->__dispswobjAccessCallback__ = &__nvoc_thunk_RmResource_dispswobjAccessCallback;

    pThis->__dispswobjGetMemInterMapParams__ = &__nvoc_thunk_RmResource_dispswobjGetMemInterMapParams;

    pThis->__dispswobjUnmap__ = &__nvoc_thunk_RsResource_dispswobjUnmap;

    pThis->__dispswobjCheckMemInterUnmap__ = &__nvoc_thunk_RmResource_dispswobjCheckMemInterUnmap;

    pThis->__dispswobjSetNotificationShare__ = &__nvoc_thunk_Notifier_dispswobjSetNotificationShare;

    pThis->__dispswobjControlFilter__ = &__nvoc_thunk_RsResource_dispswobjControlFilter;

    pThis->__dispswobjGetRefCount__ = &__nvoc_thunk_RsResource_dispswobjGetRefCount;

    pThis->__dispswobjUnregisterEvent__ = &__nvoc_thunk_Notifier_dispswobjUnregisterEvent;

    pThis->__dispswobjMapTo__ = &__nvoc_thunk_RsResource_dispswobjMapTo;

    pThis->__dispswobjControl_Prologue__ = &__nvoc_thunk_DisplayApi_dispswobjControl_Prologue;

    pThis->__dispswobjCanCopy__ = &__nvoc_thunk_RsResource_dispswobjCanCopy;

    pThis->__dispswobjAddAdditionalDependants__ = &__nvoc_thunk_RsResource_dispswobjAddAdditionalDependants;

    pThis->__dispswobjPreDestruct__ = &__nvoc_thunk_RsResource_dispswobjPreDestruct;

    pThis->__dispswobjUnmapFrom__ = &__nvoc_thunk_RsResource_dispswobjUnmapFrom;

    pThis->__dispswobjGetNotificationListPtr__ = &__nvoc_thunk_Notifier_dispswobjGetNotificationListPtr;

    pThis->__dispswobjControl_Epilogue__ = &__nvoc_thunk_DisplayApi_dispswobjControl_Epilogue;

    pThis->__dispswobjGetNotificationShare__ = &__nvoc_thunk_Notifier_dispswobjGetNotificationShare;

    pThis->__dispswobjControlLookup__ = &__nvoc_thunk_RsResource_dispswobjControlLookup;

    pThis->__dispswobjMap__ = &__nvoc_thunk_RsResource_dispswobjMap;

    pThis->__dispswobjGetOrAllocNotifShare__ = &__nvoc_thunk_Notifier_dispswobjGetOrAllocNotifShare;
}

void __nvoc_init_funcTable_DispSwObj(DispSwObj *pThis) {
    __nvoc_init_funcTable_DispSwObj_1(pThis);
}

void __nvoc_init_DisplayApi(DisplayApi*, RmHalspecOwner* );
void __nvoc_init_DispSwObj(DispSwObj *pThis, RmHalspecOwner *pRmhalspecowner) {
    pThis->__nvoc_pbase_DispSwObj = pThis;
    pThis->__nvoc_pbase_Object = &pThis->__nvoc_base_DisplayApi.__nvoc_base_RmResource.__nvoc_base_RsResource.__nvoc_base_Object;
    pThis->__nvoc_pbase_RsResource = &pThis->__nvoc_base_DisplayApi.__nvoc_base_RmResource.__nvoc_base_RsResource;
    pThis->__nvoc_pbase_RmResourceCommon = &pThis->__nvoc_base_DisplayApi.__nvoc_base_RmResource.__nvoc_base_RmResourceCommon;
    pThis->__nvoc_pbase_RmResource = &pThis->__nvoc_base_DisplayApi.__nvoc_base_RmResource;
    pThis->__nvoc_pbase_INotifier = &pThis->__nvoc_base_DisplayApi.__nvoc_base_Notifier.__nvoc_base_INotifier;
    pThis->__nvoc_pbase_Notifier = &pThis->__nvoc_base_DisplayApi.__nvoc_base_Notifier;
    pThis->__nvoc_pbase_DisplayApi = &pThis->__nvoc_base_DisplayApi;
    __nvoc_init_DisplayApi(&pThis->__nvoc_base_DisplayApi, pRmhalspecowner);
    __nvoc_init_funcTable_DispSwObj(pThis);
}

NV_STATUS __nvoc_objCreate_DispSwObj(DispSwObj **ppThis, Dynamic *pParent, NvU32 createFlags, struct CALL_CONTEXT * arg_pCallContext, struct RS_RES_ALLOC_PARAMS_INTERNAL * arg_pParams) {
    NV_STATUS status;
    Object *pParentObj;
    DispSwObj *pThis;
    RmHalspecOwner *pRmhalspecowner;

    pThis = portMemAllocNonPaged(sizeof(DispSwObj));
    if (pThis == NULL) return NV_ERR_NO_MEMORY;

    portMemSet(pThis, 0, sizeof(DispSwObj));

    __nvoc_initRtti(staticCast(pThis, Dynamic), &__nvoc_class_def_DispSwObj);

    if (pParent != NULL && !(createFlags & NVOC_OBJ_CREATE_FLAGS_PARENT_HALSPEC_ONLY))
    {
        pParentObj = dynamicCast(pParent, Object);
        objAddChild(pParentObj, &pThis->__nvoc_base_DisplayApi.__nvoc_base_RmResource.__nvoc_base_RsResource.__nvoc_base_Object);
    }
    else
    {
        pThis->__nvoc_base_DisplayApi.__nvoc_base_RmResource.__nvoc_base_RsResource.__nvoc_base_Object.pParent = NULL;
    }

    if ((pRmhalspecowner = dynamicCast(pParent, RmHalspecOwner)) == NULL)
        pRmhalspecowner = objFindAncestorOfType(RmHalspecOwner, pParent);
    NV_ASSERT_OR_RETURN(pRmhalspecowner != NULL, NV_ERR_INVALID_ARGUMENT);

    __nvoc_init_DispSwObj(pThis, pRmhalspecowner);
    status = __nvoc_ctor_DispSwObj(pThis, pRmhalspecowner, arg_pCallContext, arg_pParams);
    if (status != NV_OK) goto __nvoc_objCreate_DispSwObj_cleanup;

    *ppThis = pThis;
    return NV_OK;

__nvoc_objCreate_DispSwObj_cleanup:
    // do not call destructors here since the constructor already called them
    portMemFree(pThis);
    return status;
}

NV_STATUS __nvoc_objCreateDynamic_DispSwObj(DispSwObj **ppThis, Dynamic *pParent, NvU32 createFlags, va_list args) {
    NV_STATUS status;
    struct CALL_CONTEXT * arg_pCallContext = va_arg(args, struct CALL_CONTEXT *);
    struct RS_RES_ALLOC_PARAMS_INTERNAL * arg_pParams = va_arg(args, struct RS_RES_ALLOC_PARAMS_INTERNAL *);

    status = __nvoc_objCreate_DispSwObj(ppThis, pParent, createFlags, arg_pCallContext, arg_pParams);

    return status;
}

#ifdef DEBUG
char __nvoc_class_id_uniqueness_check_0x41f4f2 = 1;
#endif

extern const struct NVOC_CLASS_DEF __nvoc_class_def_DispCommon;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_Object;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_RsResource;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_RmResourceCommon;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_RmResource;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_INotifier;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_Notifier;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_DisplayApi;

void __nvoc_init_DispCommon(DispCommon*, RmHalspecOwner* );
void __nvoc_init_funcTable_DispCommon(DispCommon*);
NV_STATUS __nvoc_ctor_DispCommon(DispCommon*, RmHalspecOwner* , struct CALL_CONTEXT * arg_pCallContext, struct RS_RES_ALLOC_PARAMS_INTERNAL * arg_pParams);
void __nvoc_init_dataField_DispCommon(DispCommon*);
void __nvoc_dtor_DispCommon(DispCommon*);
extern const struct NVOC_EXPORT_INFO __nvoc_export_info_DispCommon;

static const struct NVOC_RTTI __nvoc_rtti_DispCommon_DispCommon = {
    /*pClassDef=*/          &__nvoc_class_def_DispCommon,
    /*dtor=*/               (NVOC_DYNAMIC_DTOR) &__nvoc_dtor_DispCommon,
    /*offset=*/             0,
};

static const struct NVOC_RTTI __nvoc_rtti_DispCommon_Object = {
    /*pClassDef=*/          &__nvoc_class_def_Object,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(DispCommon, __nvoc_base_DisplayApi.__nvoc_base_RmResource.__nvoc_base_RsResource.__nvoc_base_Object),
};

static const struct NVOC_RTTI __nvoc_rtti_DispCommon_RsResource = {
    /*pClassDef=*/          &__nvoc_class_def_RsResource,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(DispCommon, __nvoc_base_DisplayApi.__nvoc_base_RmResource.__nvoc_base_RsResource),
};

static const struct NVOC_RTTI __nvoc_rtti_DispCommon_RmResourceCommon = {
    /*pClassDef=*/          &__nvoc_class_def_RmResourceCommon,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(DispCommon, __nvoc_base_DisplayApi.__nvoc_base_RmResource.__nvoc_base_RmResourceCommon),
};

static const struct NVOC_RTTI __nvoc_rtti_DispCommon_RmResource = {
    /*pClassDef=*/          &__nvoc_class_def_RmResource,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(DispCommon, __nvoc_base_DisplayApi.__nvoc_base_RmResource),
};

static const struct NVOC_RTTI __nvoc_rtti_DispCommon_INotifier = {
    /*pClassDef=*/          &__nvoc_class_def_INotifier,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(DispCommon, __nvoc_base_DisplayApi.__nvoc_base_Notifier.__nvoc_base_INotifier),
};

static const struct NVOC_RTTI __nvoc_rtti_DispCommon_Notifier = {
    /*pClassDef=*/          &__nvoc_class_def_Notifier,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(DispCommon, __nvoc_base_DisplayApi.__nvoc_base_Notifier),
};

static const struct NVOC_RTTI __nvoc_rtti_DispCommon_DisplayApi = {
    /*pClassDef=*/          &__nvoc_class_def_DisplayApi,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(DispCommon, __nvoc_base_DisplayApi),
};

static const struct NVOC_CASTINFO __nvoc_castinfo_DispCommon = {
    /*numRelatives=*/       8,
    /*relatives=*/ {
        &__nvoc_rtti_DispCommon_DispCommon,
        &__nvoc_rtti_DispCommon_DisplayApi,
        &__nvoc_rtti_DispCommon_Notifier,
        &__nvoc_rtti_DispCommon_INotifier,
        &__nvoc_rtti_DispCommon_RmResource,
        &__nvoc_rtti_DispCommon_RmResourceCommon,
        &__nvoc_rtti_DispCommon_RsResource,
        &__nvoc_rtti_DispCommon_Object,
    },
};

const struct NVOC_CLASS_DEF __nvoc_class_def_DispCommon = 
{
    /*classInfo=*/ {
        /*size=*/               sizeof(DispCommon),
        /*classId=*/            classId(DispCommon),
        /*providerId=*/         &__nvoc_rtti_provider,
#if NV_PRINTF_STRINGS_ALLOWED
        /*name=*/               "DispCommon",
#endif
    },
    /*objCreatefn=*/        (NVOC_DYNAMIC_OBJ_CREATE) &__nvoc_objCreateDynamic_DispCommon,
    /*pCastInfo=*/          &__nvoc_castinfo_DispCommon,
    /*pExportInfo=*/        &__nvoc_export_info_DispCommon
};

static NvBool __nvoc_thunk_RmResource_dispcmnShareCallback(struct DispCommon *pResource, struct RsClient *pInvokingClient, struct RsResourceRef *pParentRef, RS_SHARE_POLICY *pSharePolicy) {
    return rmresShareCallback((struct RmResource *)(((unsigned char *)pResource) + __nvoc_rtti_DispCommon_RmResource.offset), pInvokingClient, pParentRef, pSharePolicy);
}

static NV_STATUS __nvoc_thunk_DisplayApi_dispcmnControl(struct DispCommon *pDisplayApi, struct CALL_CONTEXT *pCallContext, struct RS_RES_CONTROL_PARAMS_INTERNAL *pParams) {
    return dispapiControl((struct DisplayApi *)(((unsigned char *)pDisplayApi) + __nvoc_rtti_DispCommon_DisplayApi.offset), pCallContext, pParams);
}

static NvBool __nvoc_thunk_RmResource_dispcmnAccessCallback(struct DispCommon *pResource, struct RsClient *pInvokingClient, void *pAllocParams, RsAccessRight accessRight) {
    return rmresAccessCallback((struct RmResource *)(((unsigned char *)pResource) + __nvoc_rtti_DispCommon_RmResource.offset), pInvokingClient, pAllocParams, accessRight);
}

static NV_STATUS __nvoc_thunk_RmResource_dispcmnGetMemInterMapParams(struct DispCommon *pRmResource, RMRES_MEM_INTER_MAP_PARAMS *pParams) {
    return rmresGetMemInterMapParams((struct RmResource *)(((unsigned char *)pRmResource) + __nvoc_rtti_DispCommon_RmResource.offset), pParams);
}

static NV_STATUS __nvoc_thunk_RsResource_dispcmnUnmap(struct DispCommon *pResource, struct CALL_CONTEXT *pCallContext, RsCpuMapping *pCpuMapping) {
    return resUnmap((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DispCommon_RsResource.offset), pCallContext, pCpuMapping);
}

static NV_STATUS __nvoc_thunk_RmResource_dispcmnCheckMemInterUnmap(struct DispCommon *pRmResource, NvBool bSubdeviceHandleProvided) {
    return rmresCheckMemInterUnmap((struct RmResource *)(((unsigned char *)pRmResource) + __nvoc_rtti_DispCommon_RmResource.offset), bSubdeviceHandleProvided);
}

static void __nvoc_thunk_Notifier_dispcmnSetNotificationShare(struct DispCommon *pNotifier, struct NotifShare *pNotifShare) {
    notifySetNotificationShare((struct Notifier *)(((unsigned char *)pNotifier) + __nvoc_rtti_DispCommon_Notifier.offset), pNotifShare);
}

static NV_STATUS __nvoc_thunk_RsResource_dispcmnControlFilter(struct DispCommon *pResource, struct CALL_CONTEXT *pCallContext, struct RS_RES_CONTROL_PARAMS_INTERNAL *pParams) {
    return resControlFilter((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DispCommon_RsResource.offset), pCallContext, pParams);
}

static NvU32 __nvoc_thunk_RsResource_dispcmnGetRefCount(struct DispCommon *pResource) {
    return resGetRefCount((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DispCommon_RsResource.offset));
}

static NV_STATUS __nvoc_thunk_Notifier_dispcmnUnregisterEvent(struct DispCommon *pNotifier, NvHandle hNotifierClient, NvHandle hNotifierResource, NvHandle hEventClient, NvHandle hEvent) {
    return notifyUnregisterEvent((struct Notifier *)(((unsigned char *)pNotifier) + __nvoc_rtti_DispCommon_Notifier.offset), hNotifierClient, hNotifierResource, hEventClient, hEvent);
}

static NV_STATUS __nvoc_thunk_RsResource_dispcmnMapTo(struct DispCommon *pResource, RS_RES_MAP_TO_PARAMS *pParams) {
    return resMapTo((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DispCommon_RsResource.offset), pParams);
}

static NV_STATUS __nvoc_thunk_DisplayApi_dispcmnControl_Prologue(struct DispCommon *pDisplayApi, struct CALL_CONTEXT *pCallContext, struct RS_RES_CONTROL_PARAMS_INTERNAL *pRsParams) {
    return dispapiControl_Prologue((struct DisplayApi *)(((unsigned char *)pDisplayApi) + __nvoc_rtti_DispCommon_DisplayApi.offset), pCallContext, pRsParams);
}

static NvBool __nvoc_thunk_RsResource_dispcmnCanCopy(struct DispCommon *pResource) {
    return resCanCopy((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DispCommon_RsResource.offset));
}

static void __nvoc_thunk_RsResource_dispcmnAddAdditionalDependants(struct RsClient *pClient, struct DispCommon *pResource, RsResourceRef *pReference) {
    resAddAdditionalDependants(pClient, (struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DispCommon_RsResource.offset), pReference);
}

static void __nvoc_thunk_RsResource_dispcmnPreDestruct(struct DispCommon *pResource) {
    resPreDestruct((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DispCommon_RsResource.offset));
}

static NV_STATUS __nvoc_thunk_RsResource_dispcmnUnmapFrom(struct DispCommon *pResource, RS_RES_UNMAP_FROM_PARAMS *pParams) {
    return resUnmapFrom((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DispCommon_RsResource.offset), pParams);
}

static PEVENTNOTIFICATION *__nvoc_thunk_Notifier_dispcmnGetNotificationListPtr(struct DispCommon *pNotifier) {
    return notifyGetNotificationListPtr((struct Notifier *)(((unsigned char *)pNotifier) + __nvoc_rtti_DispCommon_Notifier.offset));
}

static void __nvoc_thunk_DisplayApi_dispcmnControl_Epilogue(struct DispCommon *pDisplayApi, struct CALL_CONTEXT *pCallContext, struct RS_RES_CONTROL_PARAMS_INTERNAL *pRsParams) {
    dispapiControl_Epilogue((struct DisplayApi *)(((unsigned char *)pDisplayApi) + __nvoc_rtti_DispCommon_DisplayApi.offset), pCallContext, pRsParams);
}

static struct NotifShare *__nvoc_thunk_Notifier_dispcmnGetNotificationShare(struct DispCommon *pNotifier) {
    return notifyGetNotificationShare((struct Notifier *)(((unsigned char *)pNotifier) + __nvoc_rtti_DispCommon_Notifier.offset));
}

static NV_STATUS __nvoc_thunk_RsResource_dispcmnControlLookup(struct DispCommon *pResource, struct RS_RES_CONTROL_PARAMS_INTERNAL *pParams, const struct NVOC_EXPORTED_METHOD_DEF **ppEntry) {
    return resControlLookup((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DispCommon_RsResource.offset), pParams, ppEntry);
}

static NV_STATUS __nvoc_thunk_RsResource_dispcmnMap(struct DispCommon *pResource, struct CALL_CONTEXT *pCallContext, RS_CPU_MAP_PARAMS *pParams, RsCpuMapping *pCpuMapping) {
    return resMap((struct RsResource *)(((unsigned char *)pResource) + __nvoc_rtti_DispCommon_RsResource.offset), pCallContext, pParams, pCpuMapping);
}

static NV_STATUS __nvoc_thunk_Notifier_dispcmnGetOrAllocNotifShare(struct DispCommon *pNotifier, NvHandle hNotifierClient, NvHandle hNotifierResource, struct NotifShare **ppNotifShare) {
    return notifyGetOrAllocNotifShare((struct Notifier *)(((unsigned char *)pNotifier) + __nvoc_rtti_DispCommon_Notifier.offset), hNotifierClient, hNotifierResource, ppNotifShare);
}

static const struct NVOC_EXPORTED_METHOD_DEF __nvoc_exported_method_def_DispCommon[] = 
{
    {               /*  [0] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSystemGetNumHeads_IMPL,
        /*flags=*/      0x212u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x730102u,
        /*paramSize=*/  sizeof(NV0073_CTRL_SYSTEM_GET_NUM_HEADS_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSystemGetNumHeads"
#endif
    },
    {               /*  [1] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSystemGetScanline_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x730108u,
        /*paramSize=*/  sizeof(NV0073_CTRL_SYSTEM_GET_SCANLINE_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSystemGetScanline"
#endif
    },
    {               /*  [2] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSystemGetSuppported_IMPL,
        /*flags=*/      0x212u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x730120u,
        /*paramSize=*/  sizeof(NV0073_CTRL_SYSTEM_GET_SUPPORTED_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSystemGetSuppported"
#endif
    },
    {               /*  [3] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSystemGetConnectState_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x730122u,
        /*paramSize=*/  sizeof(NV0073_CTRL_SYSTEM_GET_CONNECT_STATE_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSystemGetConnectState"
#endif
    },
    {               /*  [4] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSystemGetHotplugConfig_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x730123u,
        /*paramSize=*/  sizeof(NV0073_CTRL_SYSTEM_GET_SET_HOTPLUG_CONFIG_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSystemGetHotplugConfig"
#endif
    },
    {               /*  [5] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSystemGetHeadRoutingMap_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x730125u,
        /*paramSize=*/  sizeof(NV0073_CTRL_SYSTEM_GET_HEAD_ROUTING_MAP_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSystemGetHeadRoutingMap"
#endif
    },
    {               /*  [6] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSystemGetActive_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x730126u,
        /*paramSize=*/  sizeof(NV0073_CTRL_SYSTEM_GET_ACTIVE_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSystemGetActive"
#endif
    },
    {               /*  [7] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSystemGetCapsV2_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x730138u,
        /*paramSize=*/  sizeof(NV0073_CTRL_SYSTEM_GET_CAPS_V2_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSystemGetCapsV2"
#endif
    },
    {               /*  [8] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSystemGetBootDisplays_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x730166u,
        /*paramSize=*/  sizeof(NV0073_CTRL_SYSTEM_GET_BOOT_DISPLAYS_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSystemGetBootDisplays"
#endif
    },
    {               /*  [9] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSystemSetVrr_IMPL,
        /*flags=*/      0x204u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x730175u,
        /*paramSize=*/  sizeof(NV0073_CTRL_SYSTEM_SET_VRR_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSystemSetVrr"
#endif
    },
    {               /*  [10] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSystemGetVrrConfig_IMPL,
        /*flags=*/      0x204u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x730176u,
        /*paramSize=*/  sizeof(NV0073_CTRL_SYSTEM_GET_VRR_CONFIG_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSystemGetVrrConfig"
#endif
    },
    {               /*  [11] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSystemGetHotplugUnplugState_IMPL,
        /*flags=*/      0x0u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x73017bu,
        /*paramSize=*/  sizeof(NV0073_CTRL_SYSTEM_GET_HOTPLUG_UNPLUG_STATE_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSystemGetHotplugUnplugState"
#endif
    },
    {               /*  [12] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSystemArmLightweightSupervisor_IMPL,
        /*flags=*/      0x204u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x73017eu,
        /*paramSize=*/  sizeof(NV0073_CTRL_SYSTEM_ARM_LIGHTWEIGHT_SUPERVISOR_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSystemArmLightweightSupervisor"
#endif
    },
    {               /*  [13] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSystemConfigVrrPstateSwitch_IMPL,
        /*flags=*/      0x204u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x730184u,
        /*paramSize=*/  sizeof(NV0073_CTRL_SYSTEM_CONFIG_VRR_PSTATE_SWITCH_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSystemConfigVrrPstateSwitch"
#endif
    },
    {               /*  [14] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSystemQueryDisplayIdsWithMux_IMPL,
        /*flags=*/      0x200u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x730190u,
        /*paramSize=*/  sizeof(NV0073_CTRL_CMD_SYSTEM_QUERY_DISPLAY_IDS_WITH_MUX_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSystemQueryDisplayIdsWithMux"
#endif
    },
    {               /*  [15] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSystemAllocateDisplayBandwidth_IMPL,
        /*flags=*/      0x4u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x730196u,
        /*paramSize=*/  sizeof(NV0073_CTRL_SYSTEM_ALLOCATE_DISPLAY_BANDWIDTH_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSystemAllocateDisplayBandwidth"
#endif
    },
    {               /*  [16] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSystemGetHotplugEventConfig_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x730197u,
        /*paramSize=*/  sizeof(NV0073_CTRL_SYSTEM_HOTPLUG_EVENT_CONFIG_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSystemGetHotplugEventConfig"
#endif
    },
    {               /*  [17] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSystemSetHotplugEventConfig_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x730198u,
        /*paramSize=*/  sizeof(NV0073_CTRL_SYSTEM_HOTPLUG_EVENT_CONFIG_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSystemSetHotplugEventConfig"
#endif
    },
    {               /*  [18] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSystemCheckSidebandI2cSupport_IMPL,
        /*flags=*/      0x200u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x73019cu,
        /*paramSize=*/  sizeof(NV0073_CTRL_CMD_SYSTEM_CHECK_SIDEBAND_I2C_SUPPORT_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSystemCheckSidebandI2cSupport"
#endif
    },
    {               /*  [19] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSpecificGetI2cPortid_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x730211u,
        /*paramSize=*/  sizeof(NV0073_CTRL_SPECIFIC_GET_I2C_PORTID_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSpecificGetI2cPortid"
#endif
    },
    {               /*  [20] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSpecificGetType_IMPL,
        /*flags=*/      0x212u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x730240u,
        /*paramSize=*/  sizeof(NV0073_CTRL_SPECIFIC_GET_TYPE_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSpecificGetType"
#endif
    },
    {               /*  [21] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSpecificFakeDevice_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x730243u,
        /*paramSize=*/  sizeof(NV0073_CTRL_CMD_SPECIFIC_FAKE_DEVICE_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSpecificFakeDevice"
#endif
    },
    {               /*  [22] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSpecificGetEdidV2_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x730245u,
        /*paramSize=*/  sizeof(NV0073_CTRL_SPECIFIC_GET_EDID_V2_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSpecificGetEdidV2"
#endif
    },
    {               /*  [23] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSpecificSetEdidV2_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x730246u,
        /*paramSize=*/  sizeof(NV0073_CTRL_SPECIFIC_SET_EDID_V2_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSpecificSetEdidV2"
#endif
    },
    {               /*  [24] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSpecificGetConnectorData_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x730250u,
        /*paramSize=*/  sizeof(NV0073_CTRL_SPECIFIC_GET_CONNECTOR_DATA_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSpecificGetConnectorData"
#endif
    },
    {               /*  [25] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSpecificSetHdmiEnable_IMPL,
        /*flags=*/      0x204u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x730273u,
        /*paramSize=*/  sizeof(NV0073_CTRL_SPECIFIC_SET_HDMI_ENABLE_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSpecificSetHdmiEnable"
#endif
    },
    {               /*  [26] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSpecificCtrlHdmi_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x730274u,
        /*paramSize=*/  sizeof(NV0073_CTRL_SPECIFIC_CTRL_HDMI_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSpecificCtrlHdmi"
#endif
    },
    {               /*  [27] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSpecificGetAllHeadMask_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x730287u,
        /*paramSize=*/  sizeof(NV0073_CTRL_SPECIFIC_GET_ALL_HEAD_MASK_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSpecificGetAllHeadMask"
#endif
    },
    {               /*  [28] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSpecificSetOdPacket_IMPL,
        /*flags=*/      0x204u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x730288u,
        /*paramSize=*/  sizeof(NV0073_CTRL_SPECIFIC_SET_OD_PACKET_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSpecificSetOdPacket"
#endif
    },
    {               /*  [29] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSpecificSetOdPacketCtrl_IMPL,
        /*flags=*/      0x200u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x730289u,
        /*paramSize=*/  sizeof(NV0073_CTRL_SPECIFIC_SET_OD_PACKET_CTRL_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSpecificSetOdPacketCtrl"
#endif
    },
    {               /*  [30] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSpecificGetPclkLimit_IMPL,
        /*flags=*/      0x200u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x73028au,
        /*paramSize=*/  sizeof(NV0073_CTRL_SPECIFIC_GET_PCLK_LIMIT_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSpecificGetPclkLimit"
#endif
    },
    {               /*  [31] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSpecificOrGetInfo_IMPL,
        /*flags=*/      0x212u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x73028bu,
        /*paramSize=*/  sizeof(NV0073_CTRL_SPECIFIC_OR_GET_INFO_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSpecificOrGetInfo"
#endif
    },
    {               /*  [32] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSpecificSetHdmiSinkCaps_IMPL,
        /*flags=*/      0x204u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x730293u,
        /*paramSize=*/  sizeof(NV0073_CTRL_SPECIFIC_SET_HDMI_SINK_CAPS_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSpecificSetHdmiSinkCaps"
#endif
    },
    {               /*  [33] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSpecificSetMonitorPower_IMPL,
        /*flags=*/      0x200u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x730295u,
        /*paramSize=*/  sizeof(NV0073_CTRL_SPECIFIC_SET_MONITOR_POWER_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSpecificSetMonitorPower"
#endif
    },
    {               /*  [34] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSpecificSetHdmiFrlLinkConfig_IMPL,
        /*flags=*/      0x204u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x73029au,
        /*paramSize=*/  sizeof(NV0073_CTRL_SPECIFIC_SET_HDMI_FRL_LINK_CONFIG_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSpecificSetHdmiFrlLinkConfig"
#endif
    },
    {               /*  [35] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSpecificGetRegionalCrcs_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x7302a0u,
        /*paramSize=*/  sizeof(NV0073_CTRL_CMD_SPECIFIC_GET_REGIONAL_CRCS_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSpecificGetRegionalCrcs"
#endif
    },
    {               /*  [36] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSpecificApplyEdidOverrideV2_IMPL,
        /*flags=*/      0x200u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x7302a1u,
        /*paramSize=*/  sizeof(NV0073_CTRL_SPECIFIC_APPLY_EDID_OVERRIDE_V2_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSpecificApplyEdidOverrideV2"
#endif
    },
    {               /*  [37] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSpecificGetHdmiGpuCaps_IMPL,
        /*flags=*/      0x200u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x7302a2u,
        /*paramSize=*/  sizeof(NV0073_CTRL_SPECIFIC_GET_HDMI_GPU_CAPS_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSpecificGetHdmiGpuCaps"
#endif
    },
    {               /*  [38] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSpecificGetHdmiScdcData_IMPL,
        /*flags=*/      0x204u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x7302a6u,
        /*paramSize=*/  sizeof(NV0073_CTRL_SPECIFIC_GET_HDMI_SCDC_DATA_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSpecificGetHdmiScdcData"
#endif
    },
    {               /*  [39] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSpecificIsDirectmodeDisplay_IMPL,
        /*flags=*/      0x200u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x7302a7u,
        /*paramSize=*/  sizeof(NV0073_CTRL_SPECIFIC_IS_DIRECTMODE_DISPLAY_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSpecificIsDirectmodeDisplay"
#endif
    },
    {               /*  [40] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSpecificSetHdmiFrlCapacityComputation_IMPL,
        /*flags=*/      0x204u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x7302a8u,
        /*paramSize=*/  sizeof(NV0073_CTRL_SPECIFIC_GET_HDMI_FRL_CAPACITY_COMPUTATION_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSpecificSetHdmiFrlCapacityComputation"
#endif
    },
    {               /*  [41] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdSpecificDispI2cReadWrite_IMPL,
        /*flags=*/      0x204u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x7302acu,
        /*paramSize=*/  sizeof(NV0073_CTRL_SPECIFIC_DISP_I2C_READ_WRITE_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdSpecificDispI2cReadWrite"
#endif
    },
    {               /*  [42] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdInternalGetHotplugUnplugState_IMPL,
        /*flags=*/      0x600u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x730401u,
        /*paramSize=*/  sizeof(NV0073_CTRL_SYSTEM_GET_HOTPLUG_UNPLUG_STATE_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdInternalGetHotplugUnplugState"
#endif
    },
    {               /*  [43] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDfpGetInfo_IMPL,
        /*flags=*/      0x212u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x731140u,
        /*paramSize=*/  sizeof(NV0073_CTRL_DFP_GET_INFO_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDfpGetInfo"
#endif
    },
    {               /*  [44] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDfpGetDisplayportDongleInfo_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x731142u,
        /*paramSize=*/  sizeof(NV0073_CTRL_DFP_GET_DISPLAYPORT_DONGLE_INFO_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDfpGetDisplayportDongleInfo"
#endif
    },
    {               /*  [45] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDfpSetEldAudioCaps_IMPL,
        /*flags=*/      0x204u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x731144u,
        /*paramSize=*/  sizeof(NV0073_CTRL_DFP_SET_ELD_AUDIO_CAP_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDfpSetEldAudioCaps"
#endif
    },
    {               /*  [46] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDfpUpdateDynamicDfpCache_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x73114eu,
        /*paramSize=*/  sizeof(NV0073_CTRL_DFP_UPDATE_DYNAMIC_DFP_CACHE_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDfpUpdateDynamicDfpCache"
#endif
    },
    {               /*  [47] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDfpSetAudioEnable_IMPL,
        /*flags=*/      0x200u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x731150u,
        /*paramSize=*/  sizeof(NV0073_CTRL_DFP_SET_AUDIO_ENABLE_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDfpSetAudioEnable"
#endif
    },
    {               /*  [48] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDfpAssignSor_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x731152u,
        /*paramSize=*/  sizeof(NV0073_CTRL_DFP_ASSIGN_SOR_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDfpAssignSor"
#endif
    },
    {               /*  [49] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDfpGetPadlinkMask_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x731153u,
        /*paramSize=*/  sizeof(NV0073_CTRL_DFP_GET_PADLINK_MASK_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDfpGetPadlinkMask"
#endif
    },
    {               /*  [50] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDfpConfigTwoHeadOneOr_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x731156u,
        /*paramSize=*/  sizeof(NV0073_CTRL_DFP_CONFIG_TWO_HEAD_ONE_OR_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDfpConfigTwoHeadOneOr"
#endif
    },
    {               /*  [51] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDfpDscCrcControl_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x731157u,
        /*paramSize=*/  sizeof(NV0073_CTRL_DFP_DSC_CRC_CONTROL_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDfpDscCrcControl"
#endif
    },
    {               /*  [52] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDfpInitMuxData_IMPL,
        /*flags=*/      0x200u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x731158u,
        /*paramSize=*/  sizeof(NV0073_CTRL_CMD_DFP_INIT_MUX_DATA_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDfpInitMuxData"
#endif
    },
    {               /*  [53] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDfpGetDsiModeTiming_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x731166u,
        /*paramSize=*/  sizeof(NV0073_CTRL_CMD_DFP_GET_DSI_MODE_TIMING_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDfpGetDsiModeTiming"
#endif
    },
    {               /*  [54] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDpAuxchCtrl_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x731341u,
        /*paramSize=*/  sizeof(NV0073_CTRL_DP_AUXCH_CTRL_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDpAuxchCtrl"
#endif
    },
    {               /*  [55] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDpAuxchSetSema_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x731342u,
        /*paramSize=*/  sizeof(NV0073_CTRL_DP_AUXCH_SET_SEMA_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDpAuxchSetSema"
#endif
    },
    {               /*  [56] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDpCtrl_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x731343u,
        /*paramSize=*/  sizeof(NV0073_CTRL_DP_CTRL_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDpCtrl"
#endif
    },
    {               /*  [57] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDpGetLaneData_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x731345u,
        /*paramSize=*/  sizeof(NV0073_CTRL_DP_LANE_DATA_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDpGetLaneData"
#endif
    },
    {               /*  [58] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDpSetLaneData_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x731346u,
        /*paramSize=*/  sizeof(NV0073_CTRL_DP_LANE_DATA_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDpSetLaneData"
#endif
    },
    {               /*  [59] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDpSetTestpattern_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x731347u,
        /*paramSize=*/  sizeof(NV0073_CTRL_DP_SET_TESTPATTERN_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDpSetTestpattern"
#endif
    },
    {               /*  [60] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDpSetPreemphasisDrivecurrentPostcursor2Data_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x731351u,
        /*paramSize=*/  sizeof(NV0073_CTRL_DP_SET_PREEMPHASIS_DRIVECURRENT_POSTCURSOR2_DATA_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDpSetPreemphasisDrivecurrentPostcursor2Data"
#endif
    },
    {               /*  [61] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDpGetPreemphasisDrivecurrentPostcursor2Data_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x731352u,
        /*paramSize=*/  sizeof(NV0073_CTRL_DP_GET_PREEMPHASIS_DRIVECURRENT_POSTCURSOR2_DATA_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDpGetPreemphasisDrivecurrentPostcursor2Data"
#endif
    },
    {               /*  [62] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDpMainLinkCtrl_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x731356u,
        /*paramSize=*/  sizeof(NV0073_CTRL_DP_MAIN_LINK_CTRL_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDpMainLinkCtrl"
#endif
    },
    {               /*  [63] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDpSetAudioMuteStream_IMPL,
        /*flags=*/      0x204u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x731359u,
        /*paramSize=*/  sizeof(NV0073_CTRL_DP_SET_AUDIO_MUTESTREAM_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDpSetAudioMuteStream"
#endif
    },
    {               /*  [64] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDpTopologyAllocateDisplayId_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x73135bu,
        /*paramSize=*/  sizeof(NV0073_CTRL_CMD_DP_TOPOLOGY_ALLOCATE_DISPLAYID_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDpTopologyAllocateDisplayId"
#endif
    },
    {               /*  [65] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDpTopologyFreeDisplayId_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x73135cu,
        /*paramSize=*/  sizeof(NV0073_CTRL_CMD_DP_TOPOLOGY_FREE_DISPLAYID_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDpTopologyFreeDisplayId"
#endif
    },
    {               /*  [66] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDpGetLinkConfig_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x731360u,
        /*paramSize=*/  sizeof(NV0073_CTRL_DP_GET_LINK_CONFIG_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDpGetLinkConfig"
#endif
    },
    {               /*  [67] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDpGetEDPData_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x731361u,
        /*paramSize=*/  sizeof(NV0073_CTRL_DP_GET_EDP_DATA_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDpGetEDPData"
#endif
    },
    {               /*  [68] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDpConfigStream_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x731362u,
        /*paramSize=*/  sizeof(NV0073_CTRL_CMD_DP_CONFIG_STREAM_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDpConfigStream"
#endif
    },
    {               /*  [69] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDpSetRateGov_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x731363u,
        /*paramSize=*/  sizeof(NV0073_CTRL_CMD_DP_SET_RATE_GOV_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDpSetRateGov"
#endif
    },
    {               /*  [70] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDpSetManualDisplayPort_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x731365u,
        /*paramSize=*/  sizeof(NV0073_CTRL_CMD_DP_SET_MANUAL_DISPLAYPORT_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDpSetManualDisplayPort"
#endif
    },
    {               /*  [71] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDpSendACT_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x731367u,
        /*paramSize=*/  sizeof(NV0073_CTRL_CMD_DP_SEND_ACT_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDpSendACT"
#endif
    },
    {               /*  [72] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDpGetCaps_IMPL,
        /*flags=*/      0x212u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x731369u,
        /*paramSize=*/  sizeof(NV0073_CTRL_CMD_DP_GET_CAPS_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDpGetCaps"
#endif
    },
    {               /*  [73] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDpSetMSAProperties_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x73136au,
        /*paramSize=*/  sizeof(NV0073_CTRL_CMD_DP_SET_MSA_PROPERTIES_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDpSetMSAProperties"
#endif
    },
    {               /*  [74] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDpGenerateFakeInterrupt_IMPL,
        /*flags=*/      0x10u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x73136bu,
        /*paramSize=*/  sizeof(NV0073_CTRL_CMD_DP_GENERATE_FAKE_INTERRUPT_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDpGenerateFakeInterrupt"
#endif
    },
    {               /*  [75] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDpConfigRadScratchReg_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x73136cu,
        /*paramSize=*/  sizeof(NV0073_CTRL_CMD_DP_CONFIG_RAD_SCRATCH_REG_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDpConfigRadScratchReg"
#endif
    },
    {               /*  [76] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDpConfigSingleHeadMultiStream_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x73136eu,
        /*paramSize=*/  sizeof(NV0073_CTRL_CMD_DP_CONFIG_SINGLE_HEAD_MULTI_STREAM_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDpConfigSingleHeadMultiStream"
#endif
    },
    {               /*  [77] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDpSetTriggerSelect_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x73136fu,
        /*paramSize=*/  sizeof(NV0073_CTRL_CMD_DP_SET_TRIGGER_SELECT_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDpSetTriggerSelect"
#endif
    },
    {               /*  [78] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDpSetTriggerAll_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x731370u,
        /*paramSize=*/  sizeof(NV0073_CTRL_CMD_DP_SET_TRIGGER_ALL_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDpSetTriggerAll"
#endif
    },
    {               /*  [79] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDpGetAuxLogData_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x731373u,
        /*paramSize=*/  sizeof(NV0073_CTRL_CMD_DP_GET_AUXLOGGER_BUFFER_DATA_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDpGetAuxLogData"
#endif
    },
    {               /*  [80] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDpConfigIndexedLinkRates_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x731377u,
        /*paramSize=*/  sizeof(NV0073_CTRL_CMD_DP_CONFIG_INDEXED_LINK_RATES_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDpConfigIndexedLinkRates"
#endif
    },
    {               /*  [81] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDpSetStereoMSAProperties_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x731378u,
        /*paramSize=*/  sizeof(NV0073_CTRL_CMD_DP_SET_STEREO_MSA_PROPERTIES_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDpSetStereoMSAProperties"
#endif
    },
    {               /*  [82] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDpConfigureFec_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x73137au,
        /*paramSize=*/  sizeof(NV0073_CTRL_CMD_DP_CONFIGURE_FEC_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDpConfigureFec"
#endif
    },
    {               /*  [83] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDpConfigMacroPad_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x73137bu,
        /*paramSize=*/  sizeof(NV0073_CTRL_CMD_DP_CONFIG_MACRO_PAD_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDpConfigMacroPad"
#endif
    },
    {               /*  [84] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDpGetGenericInfoframe_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x73137eu,
        /*paramSize=*/  sizeof(NV0073_CTRL_DP_GET_GENERIC_INFOFRAME_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDpGetGenericInfoframe"
#endif
    },
    {               /*  [85] */
        /*pFunc=*/      (void (*)(void)) dispcmnCtrlCmdDpGetMsaAttributes_IMPL,
        /*flags=*/      0x210u,
        /*accessRight=*/0x0u,
        /*methodId=*/   0x73137fu,
        /*paramSize=*/  sizeof(NV0073_CTRL_DP_GET_MSA_ATTRIBUTES_PARAMS),
        /*pClassInfo=*/ &(__nvoc_class_def_DispCommon.classInfo),
#if NV_PRINTF_STRINGS_ALLOWED
        /*func=*/       "dispcmnCtrlCmdDpGetMsaAttributes"
#endif
    },

};

const struct NVOC_EXPORT_INFO __nvoc_export_info_DispCommon = 
{
    /*numEntries=*/     86,
    /*pExportEntries=*/ __nvoc_exported_method_def_DispCommon
};

void __nvoc_dtor_DisplayApi(DisplayApi*);
void __nvoc_dtor_DispCommon(DispCommon *pThis) {
    __nvoc_dtor_DisplayApi(&pThis->__nvoc_base_DisplayApi);
    PORT_UNREFERENCED_VARIABLE(pThis);
}

void __nvoc_init_dataField_DispCommon(DispCommon *pThis) {
    PORT_UNREFERENCED_VARIABLE(pThis);
}

NV_STATUS __nvoc_ctor_DisplayApi(DisplayApi* , RmHalspecOwner* , struct CALL_CONTEXT *, struct RS_RES_ALLOC_PARAMS_INTERNAL *);
NV_STATUS __nvoc_ctor_DispCommon(DispCommon *pThis, RmHalspecOwner *pRmhalspecowner, struct CALL_CONTEXT * arg_pCallContext, struct RS_RES_ALLOC_PARAMS_INTERNAL * arg_pParams) {
    NV_STATUS status = NV_OK;
    status = __nvoc_ctor_DisplayApi(&pThis->__nvoc_base_DisplayApi, pRmhalspecowner, arg_pCallContext, arg_pParams);
    if (status != NV_OK) goto __nvoc_ctor_DispCommon_fail_DisplayApi;
    __nvoc_init_dataField_DispCommon(pThis);

    status = __nvoc_dispcmnConstruct(pThis, arg_pCallContext, arg_pParams);
    if (status != NV_OK) goto __nvoc_ctor_DispCommon_fail__init;
    goto __nvoc_ctor_DispCommon_exit; // Success

__nvoc_ctor_DispCommon_fail__init:
    __nvoc_dtor_DisplayApi(&pThis->__nvoc_base_DisplayApi);
__nvoc_ctor_DispCommon_fail_DisplayApi:
__nvoc_ctor_DispCommon_exit:

    return status;
}

static void __nvoc_init_funcTable_DispCommon_1(DispCommon *pThis) {
    PORT_UNREFERENCED_VARIABLE(pThis);

    pThis->__dispcmnCtrlCmdSystemGetCapsV2__ = &dispcmnCtrlCmdSystemGetCapsV2_IMPL;

    pThis->__dispcmnCtrlCmdSystemGetNumHeads__ = &dispcmnCtrlCmdSystemGetNumHeads_IMPL;

    pThis->__dispcmnCtrlCmdSystemGetScanline__ = &dispcmnCtrlCmdSystemGetScanline_IMPL;

    pThis->__dispcmnCtrlCmdSystemGetSuppported__ = &dispcmnCtrlCmdSystemGetSuppported_IMPL;

    pThis->__dispcmnCtrlCmdSystemGetConnectState__ = &dispcmnCtrlCmdSystemGetConnectState_IMPL;

    pThis->__dispcmnCtrlCmdSystemGetHotplugUnplugState__ = &dispcmnCtrlCmdSystemGetHotplugUnplugState_IMPL;

    pThis->__dispcmnCtrlCmdInternalGetHotplugUnplugState__ = &dispcmnCtrlCmdInternalGetHotplugUnplugState_IMPL;

    pThis->__dispcmnCtrlCmdSystemGetHeadRoutingMap__ = &dispcmnCtrlCmdSystemGetHeadRoutingMap_IMPL;

    pThis->__dispcmnCtrlCmdSystemGetActive__ = &dispcmnCtrlCmdSystemGetActive_IMPL;

    pThis->__dispcmnCtrlCmdSystemGetBootDisplays__ = &dispcmnCtrlCmdSystemGetBootDisplays_IMPL;

    pThis->__dispcmnCtrlCmdSystemQueryDisplayIdsWithMux__ = &dispcmnCtrlCmdSystemQueryDisplayIdsWithMux_IMPL;

    pThis->__dispcmnCtrlCmdSystemCheckSidebandI2cSupport__ = &dispcmnCtrlCmdSystemCheckSidebandI2cSupport_IMPL;

    pThis->__dispcmnCtrlCmdSystemAllocateDisplayBandwidth__ = &dispcmnCtrlCmdSystemAllocateDisplayBandwidth_IMPL;

    pThis->__dispcmnCtrlCmdSystemGetHotplugConfig__ = &dispcmnCtrlCmdSystemGetHotplugConfig_IMPL;

    pThis->__dispcmnCtrlCmdSystemGetHotplugEventConfig__ = &dispcmnCtrlCmdSystemGetHotplugEventConfig_IMPL;

    pThis->__dispcmnCtrlCmdSystemSetHotplugEventConfig__ = &dispcmnCtrlCmdSystemSetHotplugEventConfig_IMPL;

    pThis->__dispcmnCtrlCmdSystemSetVrr__ = &dispcmnCtrlCmdSystemSetVrr_IMPL;

    pThis->__dispcmnCtrlCmdSystemGetVrrConfig__ = &dispcmnCtrlCmdSystemGetVrrConfig_IMPL;

    pThis->__dispcmnCtrlCmdSystemArmLightweightSupervisor__ = &dispcmnCtrlCmdSystemArmLightweightSupervisor_IMPL;

    pThis->__dispcmnCtrlCmdSystemConfigVrrPstateSwitch__ = &dispcmnCtrlCmdSystemConfigVrrPstateSwitch_IMPL;

    pThis->__dispcmnCtrlCmdSpecificGetType__ = &dispcmnCtrlCmdSpecificGetType_IMPL;

    pThis->__dispcmnCtrlCmdSpecificGetEdidV2__ = &dispcmnCtrlCmdSpecificGetEdidV2_IMPL;

    pThis->__dispcmnCtrlCmdSpecificSetEdidV2__ = &dispcmnCtrlCmdSpecificSetEdidV2_IMPL;

    pThis->__dispcmnCtrlCmdSpecificFakeDevice__ = &dispcmnCtrlCmdSpecificFakeDevice_IMPL;

    pThis->__dispcmnCtrlCmdSpecificGetConnectorData__ = &dispcmnCtrlCmdSpecificGetConnectorData_IMPL;

    pThis->__dispcmnCtrlCmdSpecificSetHdmiEnable__ = &dispcmnCtrlCmdSpecificSetHdmiEnable_IMPL;

    pThis->__dispcmnCtrlCmdSpecificCtrlHdmi__ = &dispcmnCtrlCmdSpecificCtrlHdmi_IMPL;

    pThis->__dispcmnCtrlCmdSpecificGetAllHeadMask__ = &dispcmnCtrlCmdSpecificGetAllHeadMask_IMPL;

    pThis->__dispcmnCtrlCmdSpecificSetOdPacket__ = &dispcmnCtrlCmdSpecificSetOdPacket_IMPL;

    pThis->__dispcmnCtrlCmdSpecificSetOdPacketCtrl__ = &dispcmnCtrlCmdSpecificSetOdPacketCtrl_IMPL;

    pThis->__dispcmnCtrlCmdSpecificOrGetInfo__ = &dispcmnCtrlCmdSpecificOrGetInfo_IMPL;

    pThis->__dispcmnCtrlCmdSpecificGetPclkLimit__ = &dispcmnCtrlCmdSpecificGetPclkLimit_IMPL;

    pThis->__dispcmnCtrlCmdSpecificSetHdmiSinkCaps__ = &dispcmnCtrlCmdSpecificSetHdmiSinkCaps_IMPL;

    pThis->__dispcmnCtrlCmdSpecificSetMonitorPower__ = &dispcmnCtrlCmdSpecificSetMonitorPower_IMPL;

    pThis->__dispcmnCtrlCmdSpecificSetHdmiFrlLinkConfig__ = &dispcmnCtrlCmdSpecificSetHdmiFrlLinkConfig_IMPL;

    pThis->__dispcmnCtrlCmdSpecificApplyEdidOverrideV2__ = &dispcmnCtrlCmdSpecificApplyEdidOverrideV2_IMPL;

    pThis->__dispcmnCtrlCmdSpecificGetI2cPortid__ = &dispcmnCtrlCmdSpecificGetI2cPortid_IMPL;

    pThis->__dispcmnCtrlCmdSpecificGetHdmiGpuCaps__ = &dispcmnCtrlCmdSpecificGetHdmiGpuCaps_IMPL;

    pThis->__dispcmnCtrlCmdSpecificGetHdmiScdcData__ = &dispcmnCtrlCmdSpecificGetHdmiScdcData_IMPL;

    pThis->__dispcmnCtrlCmdSpecificIsDirectmodeDisplay__ = &dispcmnCtrlCmdSpecificIsDirectmodeDisplay_IMPL;

    pThis->__dispcmnCtrlCmdSpecificSetHdmiFrlCapacityComputation__ = &dispcmnCtrlCmdSpecificSetHdmiFrlCapacityComputation_IMPL;

    pThis->__dispcmnCtrlCmdSpecificDispI2cReadWrite__ = &dispcmnCtrlCmdSpecificDispI2cReadWrite_IMPL;

    pThis->__dispcmnCtrlCmdDfpGetInfo__ = &dispcmnCtrlCmdDfpGetInfo_IMPL;

    pThis->__dispcmnCtrlCmdDfpGetDisplayportDongleInfo__ = &dispcmnCtrlCmdDfpGetDisplayportDongleInfo_IMPL;

    pThis->__dispcmnCtrlCmdDfpSetEldAudioCaps__ = &dispcmnCtrlCmdDfpSetEldAudioCaps_IMPL;

    pThis->__dispcmnCtrlCmdDfpSetAudioEnable__ = &dispcmnCtrlCmdDfpSetAudioEnable_IMPL;

    pThis->__dispcmnCtrlCmdDfpUpdateDynamicDfpCache__ = &dispcmnCtrlCmdDfpUpdateDynamicDfpCache_IMPL;

    pThis->__dispcmnCtrlCmdDfpAssignSor__ = &dispcmnCtrlCmdDfpAssignSor_IMPL;

    pThis->__dispcmnCtrlCmdDfpDscCrcControl__ = &dispcmnCtrlCmdDfpDscCrcControl_IMPL;

    pThis->__dispcmnCtrlCmdDfpInitMuxData__ = &dispcmnCtrlCmdDfpInitMuxData_IMPL;

    pThis->__dispcmnCtrlCmdDfpGetDsiModeTiming__ = &dispcmnCtrlCmdDfpGetDsiModeTiming_IMPL;

    pThis->__dispcmnCtrlCmdDfpConfigTwoHeadOneOr__ = &dispcmnCtrlCmdDfpConfigTwoHeadOneOr_IMPL;

    pThis->__dispcmnCtrlCmdDfpGetPadlinkMask__ = &dispcmnCtrlCmdDfpGetPadlinkMask_IMPL;

    pThis->__dispcmnCtrlCmdDpAuxchCtrl__ = &dispcmnCtrlCmdDpAuxchCtrl_IMPL;

    pThis->__dispcmnCtrlCmdDpAuxchSetSema__ = &dispcmnCtrlCmdDpAuxchSetSema_IMPL;

    pThis->__dispcmnCtrlCmdDpCtrl__ = &dispcmnCtrlCmdDpCtrl_IMPL;

    pThis->__dispcmnCtrlCmdDpGetLaneData__ = &dispcmnCtrlCmdDpGetLaneData_IMPL;

    pThis->__dispcmnCtrlCmdDpSetLaneData__ = &dispcmnCtrlCmdDpSetLaneData_IMPL;

    pThis->__dispcmnCtrlCmdDpSetTestpattern__ = &dispcmnCtrlCmdDpSetTestpattern_IMPL;

    pThis->__dispcmnCtrlCmdDpMainLinkCtrl__ = &dispcmnCtrlCmdDpMainLinkCtrl_IMPL;

    pThis->__dispcmnCtrlCmdDpSetAudioMuteStream__ = &dispcmnCtrlCmdDpSetAudioMuteStream_IMPL;

    pThis->__dispcmnCtrlCmdDpGetLinkConfig__ = &dispcmnCtrlCmdDpGetLinkConfig_IMPL;

    pThis->__dispcmnCtrlCmdDpGetEDPData__ = &dispcmnCtrlCmdDpGetEDPData_IMPL;

    pThis->__dispcmnCtrlCmdDpTopologyAllocateDisplayId__ = &dispcmnCtrlCmdDpTopologyAllocateDisplayId_IMPL;

    pThis->__dispcmnCtrlCmdDpTopologyFreeDisplayId__ = &dispcmnCtrlCmdDpTopologyFreeDisplayId_IMPL;

    pThis->__dispcmnCtrlCmdDpConfigStream__ = &dispcmnCtrlCmdDpConfigStream_IMPL;

    pThis->__dispcmnCtrlCmdDpConfigSingleHeadMultiStream__ = &dispcmnCtrlCmdDpConfigSingleHeadMultiStream_IMPL;

    pThis->__dispcmnCtrlCmdDpSetRateGov__ = &dispcmnCtrlCmdDpSetRateGov_IMPL;

    pThis->__dispcmnCtrlCmdDpSendACT__ = &dispcmnCtrlCmdDpSendACT_IMPL;

    pThis->__dispcmnCtrlCmdDpSetManualDisplayPort__ = &dispcmnCtrlCmdDpSetManualDisplayPort_IMPL;

    pThis->__dispcmnCtrlCmdDpGetCaps__ = &dispcmnCtrlCmdDpGetCaps_IMPL;

    pThis->__dispcmnCtrlCmdDpSetMSAProperties__ = &dispcmnCtrlCmdDpSetMSAProperties_IMPL;

    pThis->__dispcmnCtrlCmdDpSetStereoMSAProperties__ = &dispcmnCtrlCmdDpSetStereoMSAProperties_IMPL;

    pThis->__dispcmnCtrlCmdDpGenerateFakeInterrupt__ = &dispcmnCtrlCmdDpGenerateFakeInterrupt_IMPL;

    pThis->__dispcmnCtrlCmdDpConfigRadScratchReg__ = &dispcmnCtrlCmdDpConfigRadScratchReg_IMPL;

    pThis->__dispcmnCtrlCmdDpSetTriggerSelect__ = &dispcmnCtrlCmdDpSetTriggerSelect_IMPL;

    pThis->__dispcmnCtrlCmdDpSetTriggerAll__ = &dispcmnCtrlCmdDpSetTriggerAll_IMPL;

    pThis->__dispcmnCtrlCmdDpGetAuxLogData__ = &dispcmnCtrlCmdDpGetAuxLogData_IMPL;

    pThis->__dispcmnCtrlCmdDpConfigIndexedLinkRates__ = &dispcmnCtrlCmdDpConfigIndexedLinkRates_IMPL;

    pThis->__dispcmnCtrlCmdDpConfigureFec__ = &dispcmnCtrlCmdDpConfigureFec_IMPL;

    pThis->__dispcmnCtrlCmdDpGetGenericInfoframe__ = &dispcmnCtrlCmdDpGetGenericInfoframe_IMPL;

    pThis->__dispcmnCtrlCmdDpGetMsaAttributes__ = &dispcmnCtrlCmdDpGetMsaAttributes_IMPL;

    pThis->__dispcmnCtrlCmdDpConfigMacroPad__ = &dispcmnCtrlCmdDpConfigMacroPad_IMPL;

    pThis->__dispcmnCtrlCmdDpSetPreemphasisDrivecurrentPostcursor2Data__ = &dispcmnCtrlCmdDpSetPreemphasisDrivecurrentPostcursor2Data_IMPL;

    pThis->__dispcmnCtrlCmdDpGetPreemphasisDrivecurrentPostcursor2Data__ = &dispcmnCtrlCmdDpGetPreemphasisDrivecurrentPostcursor2Data_IMPL;

    pThis->__dispcmnCtrlCmdSpecificGetRegionalCrcs__ = &dispcmnCtrlCmdSpecificGetRegionalCrcs_IMPL;

    pThis->__dispcmnShareCallback__ = &__nvoc_thunk_RmResource_dispcmnShareCallback;

    pThis->__dispcmnControl__ = &__nvoc_thunk_DisplayApi_dispcmnControl;

    pThis->__dispcmnAccessCallback__ = &__nvoc_thunk_RmResource_dispcmnAccessCallback;

    pThis->__dispcmnGetMemInterMapParams__ = &__nvoc_thunk_RmResource_dispcmnGetMemInterMapParams;

    pThis->__dispcmnUnmap__ = &__nvoc_thunk_RsResource_dispcmnUnmap;

    pThis->__dispcmnCheckMemInterUnmap__ = &__nvoc_thunk_RmResource_dispcmnCheckMemInterUnmap;

    pThis->__dispcmnSetNotificationShare__ = &__nvoc_thunk_Notifier_dispcmnSetNotificationShare;

    pThis->__dispcmnControlFilter__ = &__nvoc_thunk_RsResource_dispcmnControlFilter;

    pThis->__dispcmnGetRefCount__ = &__nvoc_thunk_RsResource_dispcmnGetRefCount;

    pThis->__dispcmnUnregisterEvent__ = &__nvoc_thunk_Notifier_dispcmnUnregisterEvent;

    pThis->__dispcmnMapTo__ = &__nvoc_thunk_RsResource_dispcmnMapTo;

    pThis->__dispcmnControl_Prologue__ = &__nvoc_thunk_DisplayApi_dispcmnControl_Prologue;

    pThis->__dispcmnCanCopy__ = &__nvoc_thunk_RsResource_dispcmnCanCopy;

    pThis->__dispcmnAddAdditionalDependants__ = &__nvoc_thunk_RsResource_dispcmnAddAdditionalDependants;

    pThis->__dispcmnPreDestruct__ = &__nvoc_thunk_RsResource_dispcmnPreDestruct;

    pThis->__dispcmnUnmapFrom__ = &__nvoc_thunk_RsResource_dispcmnUnmapFrom;

    pThis->__dispcmnGetNotificationListPtr__ = &__nvoc_thunk_Notifier_dispcmnGetNotificationListPtr;

    pThis->__dispcmnControl_Epilogue__ = &__nvoc_thunk_DisplayApi_dispcmnControl_Epilogue;

    pThis->__dispcmnGetNotificationShare__ = &__nvoc_thunk_Notifier_dispcmnGetNotificationShare;

    pThis->__dispcmnControlLookup__ = &__nvoc_thunk_RsResource_dispcmnControlLookup;

    pThis->__dispcmnMap__ = &__nvoc_thunk_RsResource_dispcmnMap;

    pThis->__dispcmnGetOrAllocNotifShare__ = &__nvoc_thunk_Notifier_dispcmnGetOrAllocNotifShare;
}

void __nvoc_init_funcTable_DispCommon(DispCommon *pThis) {
    __nvoc_init_funcTable_DispCommon_1(pThis);
}

void __nvoc_init_DisplayApi(DisplayApi*, RmHalspecOwner* );
void __nvoc_init_DispCommon(DispCommon *pThis, RmHalspecOwner *pRmhalspecowner) {
    pThis->__nvoc_pbase_DispCommon = pThis;
    pThis->__nvoc_pbase_Object = &pThis->__nvoc_base_DisplayApi.__nvoc_base_RmResource.__nvoc_base_RsResource.__nvoc_base_Object;
    pThis->__nvoc_pbase_RsResource = &pThis->__nvoc_base_DisplayApi.__nvoc_base_RmResource.__nvoc_base_RsResource;
    pThis->__nvoc_pbase_RmResourceCommon = &pThis->__nvoc_base_DisplayApi.__nvoc_base_RmResource.__nvoc_base_RmResourceCommon;
    pThis->__nvoc_pbase_RmResource = &pThis->__nvoc_base_DisplayApi.__nvoc_base_RmResource;
    pThis->__nvoc_pbase_INotifier = &pThis->__nvoc_base_DisplayApi.__nvoc_base_Notifier.__nvoc_base_INotifier;
    pThis->__nvoc_pbase_Notifier = &pThis->__nvoc_base_DisplayApi.__nvoc_base_Notifier;
    pThis->__nvoc_pbase_DisplayApi = &pThis->__nvoc_base_DisplayApi;
    __nvoc_init_DisplayApi(&pThis->__nvoc_base_DisplayApi, pRmhalspecowner);
    __nvoc_init_funcTable_DispCommon(pThis);
}

NV_STATUS __nvoc_objCreate_DispCommon(DispCommon **ppThis, Dynamic *pParent, NvU32 createFlags, struct CALL_CONTEXT * arg_pCallContext, struct RS_RES_ALLOC_PARAMS_INTERNAL * arg_pParams) {
    NV_STATUS status;
    Object *pParentObj;
    DispCommon *pThis;
    RmHalspecOwner *pRmhalspecowner;

    pThis = portMemAllocNonPaged(sizeof(DispCommon));
    if (pThis == NULL) return NV_ERR_NO_MEMORY;

    portMemSet(pThis, 0, sizeof(DispCommon));

    __nvoc_initRtti(staticCast(pThis, Dynamic), &__nvoc_class_def_DispCommon);

    if (pParent != NULL && !(createFlags & NVOC_OBJ_CREATE_FLAGS_PARENT_HALSPEC_ONLY))
    {
        pParentObj = dynamicCast(pParent, Object);
        objAddChild(pParentObj, &pThis->__nvoc_base_DisplayApi.__nvoc_base_RmResource.__nvoc_base_RsResource.__nvoc_base_Object);
    }
    else
    {
        pThis->__nvoc_base_DisplayApi.__nvoc_base_RmResource.__nvoc_base_RsResource.__nvoc_base_Object.pParent = NULL;
    }

    if ((pRmhalspecowner = dynamicCast(pParent, RmHalspecOwner)) == NULL)
        pRmhalspecowner = objFindAncestorOfType(RmHalspecOwner, pParent);
    NV_ASSERT_OR_RETURN(pRmhalspecowner != NULL, NV_ERR_INVALID_ARGUMENT);

    __nvoc_init_DispCommon(pThis, pRmhalspecowner);
    status = __nvoc_ctor_DispCommon(pThis, pRmhalspecowner, arg_pCallContext, arg_pParams);
    if (status != NV_OK) goto __nvoc_objCreate_DispCommon_cleanup;

    *ppThis = pThis;
    return NV_OK;

__nvoc_objCreate_DispCommon_cleanup:
    // do not call destructors here since the constructor already called them
    portMemFree(pThis);
    return status;
}

NV_STATUS __nvoc_objCreateDynamic_DispCommon(DispCommon **ppThis, Dynamic *pParent, NvU32 createFlags, va_list args) {
    NV_STATUS status;
    struct CALL_CONTEXT * arg_pCallContext = va_arg(args, struct CALL_CONTEXT *);
    struct RS_RES_ALLOC_PARAMS_INTERNAL * arg_pParams = va_arg(args, struct RS_RES_ALLOC_PARAMS_INTERNAL *);

    status = __nvoc_objCreate_DispCommon(ppThis, pParent, createFlags, arg_pCallContext, arg_pParams);

    return status;
}

