#!/usr/bin/env python3
import importlib.util
import json
import subprocess
import tempfile
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
SCRIPT = ROOT / "analysis" / "summarize-linux-loader-scan.py"


spec = importlib.util.spec_from_file_location("summarize_linux_loader_scan", SCRIPT)
scan_summary = importlib.util.module_from_spec(spec)
assert spec.loader is not None
spec.loader.exec_module(scan_summary)


SAMPLE_LOG = """\
2026-06-16T17:27:26+0000 pid=93 event=loaded exe=/usr/bin/dash
2026-06-16T17:27:26+0000 pid=93 event=scan-hit kind=string name=DeepDesert addr=0x1 imageOffset=0x1 fileOffset=0x1 perms=r-xp map=/usr/bin/dash
2026-06-16T17:27:26+0000 pid=100 event=loaded exe=/home/dune/server/TargetGame/Binaries/Linux/TargetGameServer-Linux-Shipping
2026-06-16T17:27:26+0000 pid=100 event=scan-map phase=snapshot bytes=342523904 perms=r-xp offset=0x0 map=/home/dune/server/TargetGame/Binaries/Linux/TargetGameServer-Linux-Shipping
2026-06-16T17:27:26+0000 pid=100 event=scan-hit kind=string name=ServerRequestBaseBackup addr=0x5628a0c2e3f9 imageOffset=0x5a553f9 fileOffset=0x5a553f9 perms=r-xp map=/home/dune/server/TargetGame/Binaries/Linux/TargetGameServer-Linux-Shipping
2026-06-16T17:27:26+0000 pid=100 event=scan-hit kind=signature name=brt-action-guard addr=0x5628a9227d15 imageOffset=0xe04ed15 fileOffset=0xe04ed15 perms=r-xp map=/home/dune/server/TargetGame/Binaries/Linux/TargetGameServer-Linux-Shipping
2026-06-16T17:27:28+0000 pid=100 event=scan-finish phase=snapshot mappings=54 scanned=3 filtered=50 unreadable=1 sizeSkipped=0 hits=2
2026-06-16T17:27:28+0000 pid=100 loader=server event=ue-anchor name=SelfTestUObject status=mapped addr=0x1000 imageOffset=0x100 fileOffset=0x100 perms=rw-p map=/home/dune/server/TargetGame/Binaries/Linux/TargetGameServer-Linux-Shipping
2026-06-16T17:27:28+0000 pid=100 loader=server event=ue-pointer name=SelfTestUObject status=target-mapped anchor=0x1000 value=0x2000
2026-06-16T17:27:28+0000 pid=100 loader=server event=ue-layout name=SelfTestUObject status=target-readable anchor=0x1000 target=0x2000 slots=2
2026-06-16T17:27:28+0000 pid=100 loader=server event=ue-layout-slot name=SelfTestUObject status=target-mapped target=0x2000 offset=0x0 value=0x3000
2026-06-16T17:27:28+0000 pid=100 loader=server event=ue-uobject name=SelfTestUObject status=candidate anchor=0x1000 target=0x2000 classMapped=true nameComparisonIndex=1234 nameNumber=1
2026-06-16T17:27:28+0000 pid=100 loader=server event=ue-reflection name=SelfTestUObject status=class-mapped object=0x2000 class=0x3000 classVtable=0x4000 classVtableMapped=true classNameComparisonIndex=1234 classNameNumber=1 slots=6
2026-06-16T17:27:28+0000 pid=100 loader=server event=ue-reflection-slot name=SelfTestUObject slot=children status=target-mapped class=0x3000 offset=0x38 value=0x2000
2026-06-16T17:27:28+0000 pid=100 loader=server event=ue-reflection-slot name=SelfTestUObject slot=propertyLink status=target-mapped class=0x3000 offset=0x48 value=0x2000
2026-06-16T17:27:28+0000 pid=100 loader=server event=ue-reflection-slot name=SelfTestUObject slot=functionLink status=target-mapped class=0x3000 offset=0x50 value=0x2000
2026-06-16T17:27:28+0000 pid=100 loader=server event=ue-fname source=ue-reflection-field objectName=SelfTestUObject.children_0 status=decoded object=0x2100 decoded=SelfTestUObjectName_0
2026-06-16T17:27:28+0000 pid=100 loader=server event=ue-reflection-field name=SelfTestUObject chain=children index=0 status=candidate field=0x2100 class=0x3000 classMapped=true nameComparisonIndex=1234 nameNumber=1 next=0x0 nextReadable=true nextMapped=false
2026-06-16T17:27:28+0000 pid=100 loader=server event=ue-reflection-field name=SelfTestUObject chain=propertyLink index=0 status=candidate field=0x2200 class=0x3000 classMapped=true nameComparisonIndex=1234 nameNumber=1 next=0x0 nextReadable=true nextMapped=false
2026-06-16T17:27:28+0000 pid=100 loader=server event=ue-reflection-field name=SelfTestUObject chain=functionLink index=0 status=candidate field=0x2300 class=0x3000 classMapped=true nameComparisonIndex=1234 nameNumber=1 next=0x0 nextReadable=true nextMapped=false
2026-06-16T17:27:28+0000 pid=100 loader=server event=ue-function-param-root name=SelfTestUObject functionIndex=0 chain=childProperties status=root function=0x2300 offset=0x40 root=0x2400 functionFlags=0x400 functionFlagsReadable=true functionFlagsOffset=0x58
2026-06-16T17:27:28+0000 pid=100 loader=server event=ue-function-param name=SelfTestUObject functionIndex=0 chain=childProperties index=0 status=candidate function=0x2300 functionName=SelfTestUObjectName_0 functionPath=/RuntimeProbe/SelfTestUObject.SelfTestUObjectName_0:Function field=0x2400 class=0x3000 classMapped=true nameComparisonIndex=1234 nameNumber=1 fieldName=SelfTestParam_0 arrayDim=1 elementSize=4 propertyFlags=0x80 offsetInternal=16 arrayDimReadable=true elementSizeReadable=true propertyFlagsReadable=true offsetInternalReadable=true functionFlags=0x400 functionFlagsReadable=true next=0x0 nextReadable=true nextMapped=false
2026-06-16T17:27:28+0000 pid=100 loader=server event=ue-function-param-container-child name=SelfTestUObject functionIndex=0 chain=childProperties index=0 status=candidate field=0x2400 containerClassName=FArrayProperty role=inner child=0x2500 childOffset=0x70 childClass=0x3000 childClassMapped=true childClassName=FIntProperty childNameComparisonIndex=1235 childNameNumber=1 childName=SelfTestInner_0
2026-06-16T17:27:28+0000 pid=100 loader=server event=ue-function-param-root name=SelfTestUObject functionIndex=0 chain=propertyLink status=null-root function=0x2300 offset=0x48
2026-06-16T17:27:28+0000 pid=100 loader=server event=ue-reflection-property name=SelfTestUObject chain=childProperties index=0 status=candidate field=0x2200 arrayDim=1 elementSize=4 propertyFlags=0x1 offsetInternal=12 arrayDimReadable=true elementSizeReadable=true propertyFlagsReadable=true offsetInternalReadable=true
2026-06-16T17:27:28+0000 pid=100 loader=server event=ue-reflection-property name=SelfTestUObject chain=propertyLink index=0 status=candidate field=0x2200 arrayDim=1 elementSize=4 propertyFlags=0x1 offsetInternal=12 arrayDimReadable=true elementSizeReadable=true propertyFlagsReadable=true offsetInternalReadable=true
2026-06-16T17:27:28+0000 pid=100 loader=server event=ue-reflection-value name=SelfTestUObject chain=childProperties index=0 fieldName=SelfTestUObjectName_0 status=read object=0x2000 address=0x200c offsetInternal=12 elementSize=4 arrayDim=1 requestedBytes=4 readBytes=4 raw=07000000 rawLe=0x7 truncated=false
2026-06-16T17:27:28+0000 pid=100 loader=server event=ue-reflection-value name=SelfTestUObject chain=propertyLink index=0 fieldName=SelfTestUObjectName_0 status=read object=0x2000 address=0x200c offsetInternal=12 elementSize=4 arrayDim=1 requestedBytes=4 readBytes=4 raw=07000000 rawLe=0x7 truncated=false
2026-06-16T17:27:28+0000 pid=100 loader=server event=lua-object-registry source=ue-uobject status=added name=SelfTestUObject path=/RuntimeProbe/SelfTestUObject class=UObjectCandidate address=0x2000 registryCount=1
2026-06-16T17:27:28+0000 pid=100 loader=server event=lua-object-registry source=ue-uobject-fname status=added name=SelfTestUObjectName_0 path=/RuntimeProbe/SelfTestUObjectName_0 aliasOf=SelfTestUObject class=UObjectCandidate address=0x2000 registryCount=2
2026-06-16T17:27:28+0000 pid=100 loader=server event=ue-object-array name=SelfTestObjectArray mode=indirect status=finished base=0x3000 scanned=1 registered=1
2026-06-16T17:27:28+0000 pid=100 loader=server event=lua-object-registry source=ue-object-array status=added name=SelfTestObjectArray_0 path=/RuntimeProbe/SelfTestObjectArray_0 class=UObjectArrayItem address=0x2000 registryCount=3
2026-06-16T17:27:28+0000 pid=100 loader=server event=ue-fname source=ue-object-array objectName=SelfTestObjectArray_0 status=decoded object=0x2000 decoded=SelfTestUObjectName_0
2026-06-16T17:27:28+0000 pid=100 loader=server event=lua-object-registry source=ue-object-array-fname status=skipped name=SelfTestUObjectName_0 path=/RuntimeProbe/SelfTestUObjectName_0 aliasOf=SelfTestObjectArray_0 class=UObjectArrayItem address=0x2000 registryCount=3
2026-06-16T17:27:28+0000 pid=100 loader=server event=hook-dispatch-self-test phase=snapshot status=passed before=42 after=1042 final=42 original=42 callbacks=2 preCallbacks=1 postCallbacks=1 installed=true restored=true
2026-06-16T17:27:28+0000 pid=100 loader=server event=mod-dispatch-self-test phase=snapshot status=passed mods=1 loaded=1 unloaded=1 result=1042 original=42 callbacks=2 preCallbacks=1 postCallbacks=1 loadCallbacks=1 unloadCallbacks=1
2026-06-16T17:27:28+0000 pid=100 loader=server event=lua-dispatch-self-test phase=snapshot status=passed library=liblua5.4.so loadStatus=0 callStatus=0 callbackStatus=0 result=42 isNumber=true hooks=1 hook=/Script/UE4SSLServerProbe.SelfTest:Function preCalls=1 postCalls=1 preResult=11 postResult=31 preIsNumber=true postIsNumber=true staticFindObjectCalls=1 staticFindObjectHits=1 findObjectCalls=1 findObjectHits=1 findFirstOfCalls=1 findFirstOfHits=1 getKnownObjectsCalls=1 getKnownObjectsHits=1 findObjectsCalls=1 findObjectsHits=1 findAllOfCalls=1 findAllOfHits=1 forEachUObjectCalls=1 forEachUObjectCallbacks=4 isACalls=6 isAHits=5 loadAssetCalls=1 loadAssetHits=1 staticConstructObjectCalls=1 staticConstructObjectHits=1
2026-06-16T17:27:28+0000 pid=100 loader=server event=lua-reflection-self-test phase=snapshot status=passed library=liblua5.4.so loadStatus=0 callStatus=0 result=42 isNumber=true staticFindObjectCalls=2 staticFindObjectHits=2 getPropertyCalls=20 getPropertyHits=20 rawPropertyHits=2 rawPropertyValue=17 namedPropertyHits=2 rawPropertySetHits=1 rawPropertySetValue=17 arrayInnerPropertyHits=1 enumPropertyHits=1 enumUnderlyingPropertyHits=1 setElementPropertyHits=1 mapKeyPropertyHits=1 mapValuePropertyHits=1 importTextHits=1 exportTextHits=1 propertyMetadataHits=7 descriptorValueGetHits=16 descriptorValueSetHits=8 setPropertyCalls=9 setPropertyHits=9 callFunctionCalls=2 callFunctionHits=2 probeValue=21 probeBool=false probeFloat=13.750 probeDouble=-47.500 probeName=ArrakisName probeString=melange probeText=WaterDebt probeObject=0x1234
2026-06-16T17:27:28+0000 pid=100 loader=server event=lua-process-event-self-test phase=snapshot status=passed library=liblua5.4.so loadStatus=0 callStatus=0 result=4 isNumber=true hooks=2 hook=/Script/UE4SSLServerProbe.SelfTest:Function installed=true restored=true hookCalls=1 originalCalls=2 originalAfterHook=1 preStatus=0 postStatus=0 preCalls=1 postCalls=1 preResult=11 postResult=31 preIsNumber=true postIsNumber=true paramDescriptorHits=2 paramDescriptorLookupCalls=13 paramDescriptorLookupHits=13 functionParamDescriptorCalls=2 functionParamDescriptorHits=2 paramGetCalls=21 paramGetHits=21 paramSetCalls=7 paramSetHits=7 paramsResult=42 paramsTouched=1 finalResult=52 finalTouched=1
2026-06-16T17:27:28+0000 pid=100 loader=server event=ue-process-event-dispatch-self-test phase=snapshot status=armed preRegistered=true postRegistered=true callbacks=2
2026-06-16T17:27:28+0000 pid=100 loader=server event=ue-process-event-live-lua-dispatch phase=snapshot status=armed library=liblua5.4.so loadStatus=0 callStatus=0 result=4 isNumber=true hooks=2 hook=/Script/UE4SSLServerProbe.LiveProcessEvent:Function callbacks=4 scriptBytes=111
2026-06-16T17:27:28+0000 pid=100 loader=server event=ue-process-event-live-hook phase=snapshot status=installed target=0x4000 selfTestTarget=true callSelfTest=true dispatchCallbacks=4 luaDispatch=true luaPreStatus=0 luaPostStatus=0 luaPreCalls=1 luaPostCalls=1 luaObjectHandleHits=2 luaFunctionHandleHits=2 luaParamsHandleHits=2 luaParamDescriptorHits=2 luaParamDescriptorLookupCalls=13 luaParamDescriptorLookupHits=13 luaFunctionParamDescriptorCalls=2 luaFunctionParamDescriptorHits=2 luaParamGetCalls=21 luaParamGetHits=21 luaParamSetCalls=7 luaParamSetHits=7 preCallbacks=2 postCallbacks=2 liveCalls=1 originalCalls=1 paramsResult=62 paramsTouched=1 trampoline=0x5000
2026-06-16T17:27:29+0000 pid=100 loader=server event=ue-process-event-live-lua-dispatch phase=unload status=closed preCalls=1 postCalls=1 preResult=11 postResult=31 preStatus=0 postStatus=0
2026-06-16T17:27:28+0000 pid=100 loader=server event=lua-mod-script phase=snapshot status=passed name=mod.lua loadStatus=0 callStatus=0 bytes=100 hooksBefore=0 hooksAfter=1
2026-06-16T17:27:28+0000 pid=100 loader=server event=lua-mod-script phase=snapshot status=passed name=mod-two.lua loadStatus=0 callStatus=0 bytes=100 hooksBefore=1 hooksAfter=2
2026-06-16T17:27:28+0000 pid=100 loader=server event=lua-mod-dispatch-self-test phase=snapshot status=passed callbackStatus=0 hooks=2 hook=/Script/UE4SSLServerProbe.ModEntry:Function preCalls=2 postCalls=2 preResult=11 postResult=31 preIsNumber=true postIsNumber=true
2026-06-16T17:27:28+0000 pid=100 loader=server event=lua-mod-finish phase=snapshot status=passed scripts=2 loaded=2 failed=0 hooks=2 findObjectCalls=1 findObjectHits=1 getKnownObjectsCalls=1 getKnownObjectsHits=1 findObjectsCalls=1 findObjectsHits=1 findAllOfCalls=1 findAllOfHits=1 forEachUObjectCalls=1 forEachUObjectCallbacks=4 isACalls=5 isAHits=2 loadAssetCalls=1 loadAssetHits=1
"""

SAMPLE_LOG = SAMPLE_LOG.replace(
    "forEachUObjectCalls=1 forEachUObjectCallbacks=4 isACalls=6",
    "forEachUObjectCalls=1 forEachUObjectCallbacks=4 forEachFunctionCalls=0 forEachFunctionCallbacks=0 isACalls=6",
)
SAMPLE_LOG = SAMPLE_LOG.replace(
    "forEachUObjectCalls=1 forEachUObjectCallbacks=4 isACalls=5",
    "forEachUObjectCalls=1 forEachUObjectCallbacks=4 forEachFunctionCalls=2 forEachFunctionCallbacks=2 isACalls=5",
)
SAMPLE_LOG = SAMPLE_LOG.replace(
    "loadAssetCalls=1 loadAssetHits=1\n",
    (
        "loadAssetCalls=1 loadAssetHits=1 "
        "staticConstructObjectCalls=1 staticConstructObjectHits=1 "
        "notifyOnNewObjectCalls=3 notifyOnNewObjectCallbacks=2 "
        "notifyOnNewObjectResult=19 notifyOnNewObjectIsNumber=true "
        "notifyOnNewObjectStatus=0 staticConstructObjectOuterHits=1 "
        "getWorldCalls=3 getWorldHits=2 "
        "getCdoCalls=1 getCdoHits=1 getLevelCalls=2 getLevelHits=2\n"
    ),
)
SAMPLE_LOG = SAMPLE_LOG.replace(
    "hooks=2 findObjectCalls=1",
    (
        "hooks=2 customEvents=1 customEventCalls=1 customEventHandled=1 "
        "loadMapPreHooks=1 loadMapPostHooks=1 loadMapPreCalls=1 loadMapPostCalls=1 "
        "loadMapPreHandled=1 loadMapPostHandled=1 "
        "beginPlayPreHooks=1 beginPlayPostHooks=1 beginPlayPreCalls=1 beginPlayPostCalls=1 "
        "beginPlayPreHandled=1 beginPlayPostHandled=1 "
        "initGameStatePreHooks=1 initGameStatePostHooks=1 "
        "initGameStatePreCalls=1 initGameStatePostCalls=1 "
        "initGameStatePreHandled=1 initGameStatePostHandled=1 "
        "processConsoleExecPreHooks=1 processConsoleExecPostHooks=1 "
        "processConsoleExecPreCalls=2 processConsoleExecPostCalls=2 "
        "processConsoleExecPreHandled=1 processConsoleExecPostHandled=1 "
        "localPlayerExecPreHooks=1 localPlayerExecPostHooks=1 "
        "localPlayerExecPreCalls=2 localPlayerExecPostCalls=2 "
        "localPlayerExecPreHandled=1 localPlayerExecPostHandled=1 "
        "callFunctionPreHooks=1 callFunctionPostHooks=1 "
        "callFunctionPreCalls=2 callFunctionPostCalls=1 "
        "callFunctionPreHandled=1 callFunctionPostHandled=1 findObjectCalls=1"
    ),
)


class LinuxLoaderScanSummaryTests(unittest.TestCase):
    def test_summarize_filters_to_server_pid(self):
        records = [scan_summary.parse_line(line) for line in SAMPLE_LOG.splitlines()]
        summary = scan_summary.summarize(records, "TargetGameServer", None)

        self.assertEqual(summary["serverPids"], ["100"])
        self.assertEqual(summary["hitCount"], 2)
        self.assertEqual(summary["uniqueHitCount"], 3)
        self.assertIn("ServerRequestBaseBackup", summary["hitsByName"])
        self.assertNotIn("DeepDesert", summary["hitsByName"])
        self.assertEqual(summary["hitsByName"]["brt-action-guard"]["category"], "brt")
        self.assertEqual(summary["hitsByName"]["SelfTestUObject"]["category"], "ue")
        self.assertEqual(summary["scanFinish"][0]["sizeSkipped"], "0")
        self.assertEqual(summary["mappedUeAnchorCount"], 1)
        self.assertEqual(summary["mappedUePointerCount"], 1)
        self.assertEqual(summary["readableUeLayoutCount"], 1)
        self.assertEqual(summary["mappedUeLayoutSlotCount"], 1)
        self.assertEqual(summary["candidateUeUObjectCount"], 1)
        self.assertEqual(summary["classMappedUeUObjectCount"], 1)
        self.assertEqual(summary["ueReflectionCount"], 1)
        self.assertEqual(summary["classMappedUeReflectionCount"], 1)
        self.assertEqual(summary["ueReflectionSlotCount"], 3)
        self.assertEqual(summary["mappedUeReflectionSlotCount"], 3)
        self.assertEqual(summary["ueReflectionFieldCount"], 3)
        self.assertEqual(summary["candidateUeReflectionFieldCount"], 3)
        self.assertEqual(summary["classMappedUeReflectionFieldCount"], 3)
        self.assertEqual(summary["ueReflectionPropertyCount"], 2)
        self.assertEqual(summary["candidateUeReflectionPropertyCount"], 2)
        self.assertEqual(summary["readableUeReflectionPropertyCount"], 2)
        self.assertEqual(summary["ueReflectionValueCount"], 2)
        self.assertEqual(summary["readUeReflectionValueCount"], 2)
        self.assertEqual(summary["ueFunctionParamRootCount"], 2)
        self.assertEqual(summary["rootedUeFunctionParamRootCount"], 1)
        self.assertEqual(summary["ueFunctionParamCount"], 1)
        self.assertEqual(summary["candidateUeFunctionParamCount"], 1)
        self.assertEqual(summary["ueFunctionParamContainerChildCount"], 1)
        self.assertEqual(summary["candidateUeFunctionParamContainerChildCount"], 1)
        self.assertEqual(summary["decodedUeFunctionParamContainerChildCount"], 1)
        self.assertEqual(summary["readableUeFunctionParamCount"], 1)
        self.assertEqual(summary["namedUeFunctionParamCount"], 1)
        self.assertEqual(summary["uniqueUeFunctionPathCount"], 1)
        self.assertEqual(summary["ueFunctionPaths"], ["/RuntimeProbe/SelfTestUObject.SelfTestUObjectName_0:Function"])
        self.assertEqual(summary["readableUeFunctionFlagRootCount"], 1)
        self.assertEqual(summary["readableUeFunctionFlagParamCount"], 1)
        self.assertEqual(summary["ueFunctionFlagPathCount"], 1)
        self.assertEqual(summary["ueFunctionFlagPaths"], ["/RuntimeProbe/SelfTestUObject.SelfTestUObjectName_0:Function"])
        self.assertEqual(summary["ueFunctionFlagValues"], ["0x400"])
        self.assertEqual(summary["finishedUeObjectArrayCount"], 1)
        self.assertEqual(summary["decodedUeFNameCount"], 2)
        self.assertEqual(summary["passedHookSelfTestCount"], 1)
        self.assertEqual(summary["passedModSelfTestCount"], 1)
        self.assertEqual(summary["passedLuaSelfTestCount"], 1)
        self.assertEqual(summary["passedLuaCallbackSelfTestCount"], 1)
        self.assertEqual(summary["passedLuaApiSelfTestCount"], 1)
        self.assertEqual(summary["passedLuaObjectApiSelfTestCount"], 1)
        self.assertEqual(summary["passedLuaReflectionSelfTestCount"], 1)
        self.assertEqual(summary["namedLuaReflectionSelfTestCount"], 1)
        self.assertEqual(summary["rawSetLuaReflectionSelfTestCount"], 1)
        self.assertEqual(summary["numericLuaReflectionSelfTestCount"], 1)
        self.assertEqual(summary["nameTextLuaReflectionSelfTestCount"], 1)
        self.assertEqual(summary["arrayInnerLuaReflectionSelfTestCount"], 1)
        self.assertEqual(summary["enumLuaReflectionSelfTestCount"], 1)
        self.assertEqual(summary["containerLuaReflectionSelfTestCount"], 1)
        self.assertEqual(summary["importTextLuaReflectionSelfTestCount"], 1)
        self.assertEqual(summary["exportTextLuaReflectionSelfTestCount"], 1)
        self.assertEqual(summary["propertyMetadataLuaReflectionSelfTestCount"], 1)
        self.assertEqual(summary["descriptorValueLuaReflectionSelfTestCount"], 1)
        self.assertEqual(summary["passedLuaProcessEventSelfTestCount"], 1)
        self.assertEqual(summary["luaProcessEventParamAccessorSelfTestCount"], 1)
        self.assertEqual(summary["luaProcessEventScalarParamAccessorSelfTestCount"], 1)
        self.assertEqual(summary["luaProcessEventNameStringParamAccessorSelfTestCount"], 1)
        self.assertEqual(summary["luaProcessEventStructParamAccessorSelfTestCount"], 1)
        self.assertEqual(summary["routedLuaProcessEventSelfTestCount"], 1)
        self.assertEqual(summary["installedUeProcessEventLiveHookCount"], 1)
        self.assertEqual(summary["ueProcessEventLuaContextHandleCount"], 1)
        self.assertEqual(summary["ueProcessEventLiveLuaParamAccessorCount"], 1)
        self.assertEqual(summary["ueProcessEventLiveLuaScalarParamAccessorCount"], 1)
        self.assertEqual(summary["ueProcessEventLiveLuaNameStringParamAccessorCount"], 1)
        self.assertEqual(summary["ueProcessEventLiveLuaStructParamAccessorCount"], 1)
        self.assertEqual(summary["routedUeProcessEventLiveLuaHookCount"], 1)
        self.assertEqual(summary["armedUeProcessEventDispatchSelfTestCount"], 1)
        self.assertEqual(summary["ueProcessEventLiveLuaDispatchCount"], 2)
        self.assertEqual(summary["armedUeProcessEventLiveLuaDispatchCount"], 1)
        self.assertEqual(summary["multiHookUeProcessEventLiveLuaDispatchCount"], 1)
        self.assertEqual(summary["closedUeProcessEventLiveLuaDispatchCount"], 1)
        self.assertEqual(summary["ueProcessEventLiveLuaDispatchStatusCounts"], {"armed": 1, "closed": 1})
        self.assertEqual(summary["passedLuaModScriptCount"], 2)
        self.assertEqual(summary["passedLuaModDispatchSelfTestCount"], 1)
        self.assertEqual(summary["passedLuaModFinishCount"], 1)
        self.assertEqual(summary["luaObjectApiModFinishCount"], 1)
        self.assertEqual(summary["luaFunctionIterationModFinishCount"], 1)
        self.assertEqual(summary["luaProcessConsoleExecHookModFinishCount"], 1)
        self.assertEqual(summary["luaLocalPlayerExecHookModFinishCount"], 1)
        self.assertEqual(summary["luaCallFunctionHookModFinishCount"], 1)
        self.assertEqual(summary["luaLifecycleHookModFinishCount"], 1)
        self.assertEqual(summary["luaNotifyOnNewObjectModFinishCount"], 1)
        self.assertEqual(summary["luaSyntheticOuterModFinishCount"], 1)
        self.assertEqual(summary["luaWorldContextModFinishCount"], 1)
        self.assertEqual(summary["luaClassDefaultObjectModFinishCount"], 1)
        self.assertEqual(summary["luaLevelModFinishCount"], 1)
        self.assertEqual(summary["luaObjectRegistryCount"], 4)
        self.assertEqual(summary["addedLuaObjectRegistryCount"], 3)
        self.assertEqual(summary["ueLuaObjectRegistryCount"], 1)
        self.assertEqual(summary["objectArrayLuaObjectRegistryCount"], 1)
        self.assertEqual(summary["decodedLuaObjectAliasRegistryCount"], 1)
        self.assertEqual(summary["skippedDecodedLuaObjectAliasRegistryCount"], 1)

    def test_cli_json_output(self):
        with tempfile.TemporaryDirectory() as tmp:
            log = Path(tmp) / "loader.log"
            log.write_text(SAMPLE_LOG, encoding="utf-8")
            result = subprocess.run(
                [str(SCRIPT), str(log), "--format", "json"],
                cwd=ROOT,
                text=True,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                check=True,
            )

        summary = json.loads(result.stdout)
        self.assertEqual(summary["hitCount"], 2)
        self.assertEqual(summary["categories"], {"brt": 2, "ue": 1})


if __name__ == "__main__":
    unittest.main()
