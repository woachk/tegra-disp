#include "nvoc/runtime.h"
#include "nvoc/rtti.h"
#include "nvtypes.h"
#include "nvport/nvport.h"
#include "nvport/inline/util_valist.h"
#include "utils/nvassert.h"
#include "g_kern_disp_nvoc.h"

#ifdef DEBUG
char __nvoc_class_id_uniqueness_check_0x55952e = 1;
#endif

extern const struct NVOC_CLASS_DEF __nvoc_class_def_KernelDisplay;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_Object;

extern const struct NVOC_CLASS_DEF __nvoc_class_def_OBJENGSTATE;

void __nvoc_init_KernelDisplay(KernelDisplay*, RmHalspecOwner* );
void __nvoc_init_funcTable_KernelDisplay(KernelDisplay*, RmHalspecOwner* );
NV_STATUS __nvoc_ctor_KernelDisplay(KernelDisplay*, RmHalspecOwner* );
void __nvoc_init_dataField_KernelDisplay(KernelDisplay*, RmHalspecOwner* );
void __nvoc_dtor_KernelDisplay(KernelDisplay*);
extern const struct NVOC_EXPORT_INFO __nvoc_export_info_KernelDisplay;

static const struct NVOC_RTTI __nvoc_rtti_KernelDisplay_KernelDisplay = {
    /*pClassDef=*/          &__nvoc_class_def_KernelDisplay,
    /*dtor=*/               (NVOC_DYNAMIC_DTOR) &__nvoc_dtor_KernelDisplay,
    /*offset=*/             0,
};

static const struct NVOC_RTTI __nvoc_rtti_KernelDisplay_Object = {
    /*pClassDef=*/          &__nvoc_class_def_Object,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(KernelDisplay, __nvoc_base_OBJENGSTATE.__nvoc_base_Object),
};

static const struct NVOC_RTTI __nvoc_rtti_KernelDisplay_OBJENGSTATE = {
    /*pClassDef=*/          &__nvoc_class_def_OBJENGSTATE,
    /*dtor=*/               &__nvoc_destructFromBase,
    /*offset=*/             NV_OFFSETOF(KernelDisplay, __nvoc_base_OBJENGSTATE),
};

static const struct NVOC_CASTINFO __nvoc_castinfo_KernelDisplay = {
    /*numRelatives=*/       3,
    /*relatives=*/ {
        &__nvoc_rtti_KernelDisplay_KernelDisplay,
        &__nvoc_rtti_KernelDisplay_OBJENGSTATE,
        &__nvoc_rtti_KernelDisplay_Object,
    },
};

const struct NVOC_CLASS_DEF __nvoc_class_def_KernelDisplay = 
{
    /*classInfo=*/ {
        /*size=*/               sizeof(KernelDisplay),
        /*classId=*/            classId(KernelDisplay),
        /*providerId=*/         &__nvoc_rtti_provider,
#if NV_PRINTF_STRINGS_ALLOWED
        /*name=*/               "KernelDisplay",
#endif
    },
    /*objCreatefn=*/        (NVOC_DYNAMIC_OBJ_CREATE) &__nvoc_objCreateDynamic_KernelDisplay,
    /*pCastInfo=*/          &__nvoc_castinfo_KernelDisplay,
    /*pExportInfo=*/        &__nvoc_export_info_KernelDisplay
};

static NV_STATUS __nvoc_thunk_KernelDisplay_engstateConstructEngine(struct OBJGPU *pGpu, struct OBJENGSTATE *pKernelDisplay, ENGDESCRIPTOR engDesc) {
    return kdispConstructEngine(pGpu, (struct KernelDisplay *)(((unsigned char *)pKernelDisplay) - __nvoc_rtti_KernelDisplay_OBJENGSTATE.offset), engDesc);
}

static NV_STATUS __nvoc_thunk_KernelDisplay_engstateStatePreInitLocked(struct OBJGPU *pGpu, struct OBJENGSTATE *pKernelDisplay) {
    return kdispStatePreInitLocked(pGpu, (struct KernelDisplay *)(((unsigned char *)pKernelDisplay) - __nvoc_rtti_KernelDisplay_OBJENGSTATE.offset));
}

static NV_STATUS __nvoc_thunk_KernelDisplay_engstateStateInitLocked(struct OBJGPU *pGpu, struct OBJENGSTATE *pKernelDisplay) {
    return kdispStateInitLocked(pGpu, (struct KernelDisplay *)(((unsigned char *)pKernelDisplay) - __nvoc_rtti_KernelDisplay_OBJENGSTATE.offset));
}

static void __nvoc_thunk_KernelDisplay_engstateStateDestroy(struct OBJGPU *pGpu, struct OBJENGSTATE *pKernelDisplay) {
    kdispStateDestroy(pGpu, (struct KernelDisplay *)(((unsigned char *)pKernelDisplay) - __nvoc_rtti_KernelDisplay_OBJENGSTATE.offset));
}

static NV_STATUS __nvoc_thunk_OBJENGSTATE_kdispReconcileTunableState(POBJGPU pGpu, struct KernelDisplay *pEngstate, void *pTunableState) {
    return engstateReconcileTunableState(pGpu, (struct OBJENGSTATE *)(((unsigned char *)pEngstate) + __nvoc_rtti_KernelDisplay_OBJENGSTATE.offset), pTunableState);
}

static NV_STATUS __nvoc_thunk_OBJENGSTATE_kdispStateLoad(POBJGPU pGpu, struct KernelDisplay *pEngstate, NvU32 arg0) {
    return engstateStateLoad(pGpu, (struct OBJENGSTATE *)(((unsigned char *)pEngstate) + __nvoc_rtti_KernelDisplay_OBJENGSTATE.offset), arg0);
}

static NV_STATUS __nvoc_thunk_OBJENGSTATE_kdispStateUnload(POBJGPU pGpu, struct KernelDisplay *pEngstate, NvU32 arg0) {
    return engstateStateUnload(pGpu, (struct OBJENGSTATE *)(((unsigned char *)pEngstate) + __nvoc_rtti_KernelDisplay_OBJENGSTATE.offset), arg0);
}

static NV_STATUS __nvoc_thunk_OBJENGSTATE_kdispStatePreLoad(POBJGPU pGpu, struct KernelDisplay *pEngstate, NvU32 arg0) {
    return engstateStatePreLoad(pGpu, (struct OBJENGSTATE *)(((unsigned char *)pEngstate) + __nvoc_rtti_KernelDisplay_OBJENGSTATE.offset), arg0);
}

static NV_STATUS __nvoc_thunk_OBJENGSTATE_kdispStatePostUnload(POBJGPU pGpu, struct KernelDisplay *pEngstate, NvU32 arg0) {
    return engstateStatePostUnload(pGpu, (struct OBJENGSTATE *)(((unsigned char *)pEngstate) + __nvoc_rtti_KernelDisplay_OBJENGSTATE.offset), arg0);
}

static NV_STATUS __nvoc_thunk_OBJENGSTATE_kdispStatePreUnload(POBJGPU pGpu, struct KernelDisplay *pEngstate, NvU32 arg0) {
    return engstateStatePreUnload(pGpu, (struct OBJENGSTATE *)(((unsigned char *)pEngstate) + __nvoc_rtti_KernelDisplay_OBJENGSTATE.offset), arg0);
}

static NV_STATUS __nvoc_thunk_OBJENGSTATE_kdispStateInitUnlocked(POBJGPU pGpu, struct KernelDisplay *pEngstate) {
    return engstateStateInitUnlocked(pGpu, (struct OBJENGSTATE *)(((unsigned char *)pEngstate) + __nvoc_rtti_KernelDisplay_OBJENGSTATE.offset));
}

static void __nvoc_thunk_OBJENGSTATE_kdispInitMissing(POBJGPU pGpu, struct KernelDisplay *pEngstate) {
    engstateInitMissing(pGpu, (struct OBJENGSTATE *)(((unsigned char *)pEngstate) + __nvoc_rtti_KernelDisplay_OBJENGSTATE.offset));
}

static NV_STATUS __nvoc_thunk_OBJENGSTATE_kdispStatePreInitUnlocked(POBJGPU pGpu, struct KernelDisplay *pEngstate) {
    return engstateStatePreInitUnlocked(pGpu, (struct OBJENGSTATE *)(((unsigned char *)pEngstate) + __nvoc_rtti_KernelDisplay_OBJENGSTATE.offset));
}

static NV_STATUS __nvoc_thunk_OBJENGSTATE_kdispGetTunableState(POBJGPU pGpu, struct KernelDisplay *pEngstate, void *pTunableState) {
    return engstateGetTunableState(pGpu, (struct OBJENGSTATE *)(((unsigned char *)pEngstate) + __nvoc_rtti_KernelDisplay_OBJENGSTATE.offset), pTunableState);
}

static NV_STATUS __nvoc_thunk_OBJENGSTATE_kdispCompareTunableState(POBJGPU pGpu, struct KernelDisplay *pEngstate, void *pTunables1, void *pTunables2) {
    return engstateCompareTunableState(pGpu, (struct OBJENGSTATE *)(((unsigned char *)pEngstate) + __nvoc_rtti_KernelDisplay_OBJENGSTATE.offset), pTunables1, pTunables2);
}

static void __nvoc_thunk_OBJENGSTATE_kdispFreeTunableState(POBJGPU pGpu, struct KernelDisplay *pEngstate, void *pTunableState) {
    engstateFreeTunableState(pGpu, (struct OBJENGSTATE *)(((unsigned char *)pEngstate) + __nvoc_rtti_KernelDisplay_OBJENGSTATE.offset), pTunableState);
}

static NV_STATUS __nvoc_thunk_OBJENGSTATE_kdispStatePostLoad(POBJGPU pGpu, struct KernelDisplay *pEngstate, NvU32 arg0) {
    return engstateStatePostLoad(pGpu, (struct OBJENGSTATE *)(((unsigned char *)pEngstate) + __nvoc_rtti_KernelDisplay_OBJENGSTATE.offset), arg0);
}

static NV_STATUS __nvoc_thunk_OBJENGSTATE_kdispAllocTunableState(POBJGPU pGpu, struct KernelDisplay *pEngstate, void **ppTunableState) {
    return engstateAllocTunableState(pGpu, (struct OBJENGSTATE *)(((unsigned char *)pEngstate) + __nvoc_rtti_KernelDisplay_OBJENGSTATE.offset), ppTunableState);
}

static NV_STATUS __nvoc_thunk_OBJENGSTATE_kdispSetTunableState(POBJGPU pGpu, struct KernelDisplay *pEngstate, void *pTunableState) {
    return engstateSetTunableState(pGpu, (struct OBJENGSTATE *)(((unsigned char *)pEngstate) + __nvoc_rtti_KernelDisplay_OBJENGSTATE.offset), pTunableState);
}

static NvBool __nvoc_thunk_OBJENGSTATE_kdispIsPresent(POBJGPU pGpu, struct KernelDisplay *pEngstate) {
    return engstateIsPresent(pGpu, (struct OBJENGSTATE *)(((unsigned char *)pEngstate) + __nvoc_rtti_KernelDisplay_OBJENGSTATE.offset));
}

const struct NVOC_EXPORT_INFO __nvoc_export_info_KernelDisplay = 
{
    /*numEntries=*/     0,
    /*pExportEntries=*/  0
};

void __nvoc_dtor_OBJENGSTATE(OBJENGSTATE*);
void __nvoc_dtor_KernelDisplay(KernelDisplay *pThis) {
    __nvoc_kdispDestruct(pThis);
    __nvoc_dtor_OBJENGSTATE(&pThis->__nvoc_base_OBJENGSTATE);
    PORT_UNREFERENCED_VARIABLE(pThis);
}

void __nvoc_init_dataField_KernelDisplay(KernelDisplay *pThis, RmHalspecOwner *pRmhalspecowner) {
    RmVariantHal *rmVariantHal = &pRmhalspecowner->rmVariantHal;
    ChipHal *chipHal = &pRmhalspecowner->chipHal;
    DispIpHal *dispIpHal = &pRmhalspecowner->dispIpHal;
    PORT_UNREFERENCED_VARIABLE(pThis);
    PORT_UNREFERENCED_VARIABLE(pRmhalspecowner);
    PORT_UNREFERENCED_VARIABLE(rmVariantHal);
    PORT_UNREFERENCED_VARIABLE(chipHal);
    PORT_UNREFERENCED_VARIABLE(dispIpHal);

    // NVOC Property Hal field -- PDB_PROP_KDISP_IS_MISSING
    if (0)
    {
    }
    else if (( ((unsigned long)(rmVariantHal->__nvoc_HalVarIdx>> 5) == 0UL) && ((((unsigned long)1) << (rmVariantHal->__nvoc_HalVarIdx & 0x1f)) & 0x00000002UL) )) /* RmVariantHal: PF_KERNEL_ONLY */ 
    {
        pThis->setProperty(pThis, PDB_PROP_KDISP_IS_MISSING, ((NvBool)(0 != 0)));
    }

    // NVOC Property Hal field -- PDB_PROP_KDISP_IMP_ENABLE
    if (( ((unsigned long)(chipHal->__nvoc_HalVarIdx>> 5) == 2UL) && ((((unsigned long)1) << (chipHal->__nvoc_HalVarIdx & 0x1f)) & 0x00001000UL) )) /* ChipHal: T234D */ 
    {
        pThis->setProperty(pThis, PDB_PROP_KDISP_IMP_ENABLE, ((NvBool)(0 == 0)));
    }
    // default
    else
    {
        pThis->setProperty(pThis, PDB_PROP_KDISP_IMP_ENABLE, ((NvBool)(0 != 0)));
    }

    pThis->pStaticInfo = ((void *)0);

    pThis->bWarPurgeSatellitesOnCoreFree = ((NvBool)(0 != 0));
}

NV_STATUS __nvoc_ctor_OBJENGSTATE(OBJENGSTATE* );
NV_STATUS __nvoc_ctor_KernelDisplay(KernelDisplay *pThis, RmHalspecOwner *pRmhalspecowner) {
    NV_STATUS status = NV_OK;
    status = __nvoc_ctor_OBJENGSTATE(&pThis->__nvoc_base_OBJENGSTATE);
    if (status != NV_OK) goto __nvoc_ctor_KernelDisplay_fail_OBJENGSTATE;
    __nvoc_init_dataField_KernelDisplay(pThis, pRmhalspecowner);
    goto __nvoc_ctor_KernelDisplay_exit; // Success

__nvoc_ctor_KernelDisplay_fail_OBJENGSTATE:
__nvoc_ctor_KernelDisplay_exit:

    return status;
}

static void __nvoc_init_funcTable_KernelDisplay_1(KernelDisplay *pThis, RmHalspecOwner *pRmhalspecowner) {
    RmVariantHal *rmVariantHal = &pRmhalspecowner->rmVariantHal;
    ChipHal *chipHal = &pRmhalspecowner->chipHal;
    DispIpHal *dispIpHal = &pRmhalspecowner->dispIpHal;
    PORT_UNREFERENCED_VARIABLE(pThis);
    PORT_UNREFERENCED_VARIABLE(pRmhalspecowner);
    PORT_UNREFERENCED_VARIABLE(rmVariantHal);
    PORT_UNREFERENCED_VARIABLE(chipHal);
    PORT_UNREFERENCED_VARIABLE(dispIpHal);

    pThis->__kdispConstructEngine__ = &kdispConstructEngine_IMPL;

    pThis->__kdispStatePreInitLocked__ = &kdispStatePreInitLocked_IMPL;

    pThis->__kdispStateInitLocked__ = &kdispStateInitLocked_IMPL;

    pThis->__kdispStateDestroy__ = &kdispStateDestroy_IMPL;

    pThis->__nvoc_base_OBJENGSTATE.__engstateConstructEngine__ = &__nvoc_thunk_KernelDisplay_engstateConstructEngine;

    pThis->__nvoc_base_OBJENGSTATE.__engstateStatePreInitLocked__ = &__nvoc_thunk_KernelDisplay_engstateStatePreInitLocked;

    pThis->__nvoc_base_OBJENGSTATE.__engstateStateInitLocked__ = &__nvoc_thunk_KernelDisplay_engstateStateInitLocked;

    pThis->__nvoc_base_OBJENGSTATE.__engstateStateDestroy__ = &__nvoc_thunk_KernelDisplay_engstateStateDestroy;

    pThis->__kdispReconcileTunableState__ = &__nvoc_thunk_OBJENGSTATE_kdispReconcileTunableState;

    pThis->__kdispStateLoad__ = &__nvoc_thunk_OBJENGSTATE_kdispStateLoad;

    pThis->__kdispStateUnload__ = &__nvoc_thunk_OBJENGSTATE_kdispStateUnload;

    pThis->__kdispStatePreLoad__ = &__nvoc_thunk_OBJENGSTATE_kdispStatePreLoad;

    pThis->__kdispStatePostUnload__ = &__nvoc_thunk_OBJENGSTATE_kdispStatePostUnload;

    pThis->__kdispStatePreUnload__ = &__nvoc_thunk_OBJENGSTATE_kdispStatePreUnload;

    pThis->__kdispStateInitUnlocked__ = &__nvoc_thunk_OBJENGSTATE_kdispStateInitUnlocked;

    pThis->__kdispInitMissing__ = &__nvoc_thunk_OBJENGSTATE_kdispInitMissing;

    pThis->__kdispStatePreInitUnlocked__ = &__nvoc_thunk_OBJENGSTATE_kdispStatePreInitUnlocked;

    pThis->__kdispGetTunableState__ = &__nvoc_thunk_OBJENGSTATE_kdispGetTunableState;

    pThis->__kdispCompareTunableState__ = &__nvoc_thunk_OBJENGSTATE_kdispCompareTunableState;

    pThis->__kdispFreeTunableState__ = &__nvoc_thunk_OBJENGSTATE_kdispFreeTunableState;

    pThis->__kdispStatePostLoad__ = &__nvoc_thunk_OBJENGSTATE_kdispStatePostLoad;

    pThis->__kdispAllocTunableState__ = &__nvoc_thunk_OBJENGSTATE_kdispAllocTunableState;

    pThis->__kdispSetTunableState__ = &__nvoc_thunk_OBJENGSTATE_kdispSetTunableState;

    pThis->__kdispIsPresent__ = &__nvoc_thunk_OBJENGSTATE_kdispIsPresent;
}

void __nvoc_init_funcTable_KernelDisplay(KernelDisplay *pThis, RmHalspecOwner *pRmhalspecowner) {
    __nvoc_init_funcTable_KernelDisplay_1(pThis, pRmhalspecowner);
}

void __nvoc_init_OBJENGSTATE(OBJENGSTATE*);
void __nvoc_init_KernelDisplay(KernelDisplay *pThis, RmHalspecOwner *pRmhalspecowner) {
    pThis->__nvoc_pbase_KernelDisplay = pThis;
    pThis->__nvoc_pbase_Object = &pThis->__nvoc_base_OBJENGSTATE.__nvoc_base_Object;
    pThis->__nvoc_pbase_OBJENGSTATE = &pThis->__nvoc_base_OBJENGSTATE;
    __nvoc_init_OBJENGSTATE(&pThis->__nvoc_base_OBJENGSTATE);
    __nvoc_init_funcTable_KernelDisplay(pThis, pRmhalspecowner);
}

NV_STATUS __nvoc_objCreate_KernelDisplay(KernelDisplay **ppThis, Dynamic *pParent, NvU32 createFlags) {
    NV_STATUS status;
    Object *pParentObj;
    KernelDisplay *pThis;
    RmHalspecOwner *pRmhalspecowner;

    pThis = portMemAllocNonPaged(sizeof(KernelDisplay));
    if (pThis == NULL) return NV_ERR_NO_MEMORY;

    portMemSet(pThis, 0, sizeof(KernelDisplay));

    __nvoc_initRtti(staticCast(pThis, Dynamic), &__nvoc_class_def_KernelDisplay);

    if (pParent != NULL && !(createFlags & NVOC_OBJ_CREATE_FLAGS_PARENT_HALSPEC_ONLY))
    {
        pParentObj = dynamicCast(pParent, Object);
        objAddChild(pParentObj, &pThis->__nvoc_base_OBJENGSTATE.__nvoc_base_Object);
    }
    else
    {
        pThis->__nvoc_base_OBJENGSTATE.__nvoc_base_Object.pParent = NULL;
    }

    if ((pRmhalspecowner = dynamicCast(pParent, RmHalspecOwner)) == NULL)
        pRmhalspecowner = objFindAncestorOfType(RmHalspecOwner, pParent);
    NV_ASSERT_OR_RETURN(pRmhalspecowner != NULL, NV_ERR_INVALID_ARGUMENT);

    __nvoc_init_KernelDisplay(pThis, pRmhalspecowner);
    status = __nvoc_ctor_KernelDisplay(pThis, pRmhalspecowner);
    if (status != NV_OK) goto __nvoc_objCreate_KernelDisplay_cleanup;

    *ppThis = pThis;
    return NV_OK;

__nvoc_objCreate_KernelDisplay_cleanup:
    // do not call destructors here since the constructor already called them
    portMemFree(pThis);
    return status;
}

NV_STATUS __nvoc_objCreateDynamic_KernelDisplay(KernelDisplay **ppThis, Dynamic *pParent, NvU32 createFlags, va_list args) {
    NV_STATUS status;

    status = __nvoc_objCreate_KernelDisplay(ppThis, pParent, createFlags);

    return status;
}

