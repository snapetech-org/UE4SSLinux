#!/usr/bin/env python3
import importlib.util
import json
import subprocess
import tempfile
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
SCRIPT_CANDIDATES = (
    ROOT / "scripts" / "summarize-client-loader-scan.py",
    ROOT / "analysis" / "summarize-client-loader-scan.py",
)
SCRIPT = next((path for path in SCRIPT_CANDIDATES if path.exists()), SCRIPT_CANDIDATES[0])


spec = importlib.util.spec_from_file_location("summarize_client_loader_scan", SCRIPT)
scan_summary = importlib.util.module_from_spec(spec)
assert spec.loader is not None
spec.loader.exec_module(scan_summary)


SAMPLE_LOG = """\
2026-06-16T17:43:39Z pid=312 loader=win-client event=loaded phase=thread exe=C:\\windows\\system32\\rundll32.exe dll=Z:\\repo\\version.dll native=pe note=not-ue4ss-yet
2026-06-16T17:43:39Z pid=312 loader=win-client event=module base=0x140000000 firstRegion=0x140000000 protect=0x2 path=C:\\windows\\system32\\rundll32.exe
2026-06-16T17:43:39Z pid=312 loader=win-client event=scan-start strings=2 signatures=1 filters=0 maxHits=2 maxRegionBytes=268435456
2026-06-16T17:43:39Z pid=312 loader=win-client event=scan-hit kind=string name=FNamePool addr=0x140010000 rva=0x10000 allocationBase=0x140000000 regionBase=0x140010000 protect=0x2 type=0x1000000 module=C:\\game\\TargetGame-Win64-Shipping.exe
2026-06-16T17:43:39Z pid=312 loader=win-client event=scan-hit kind=string name=ProcessEvent addr=0x140020000 rva=0x20000 allocationBase=0x140000000 regionBase=0x140020000 protect=0x2 type=0x1000000 module=C:\\game\\TargetGame-Win64-Shipping.exe
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-anchor name=GUObjectArray status=mapped addr=0x140030000 rva=0x30000 allocationBase=0x140000000 regionBase=0x140030000 protect=0x4 type=0x1000000 module=C:\\game\\TargetGame-Win64-Shipping.exe
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-anchor name=GWorld status=unmapped addr=0x1
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-anchor-signature name=GWorld status=resolved hit=0x140020100 addr=0x140040000 transform=riprel32+3 rva=0x40000 allocationBase=0x140000000 regionBase=0x140040000 protect=0x4 type=0x1000000 module=C:\\game\\TargetGame-Win64-Shipping.exe
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-anchor-signature name=StaticFindObject status=missing oversizedRegions=0
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-pointer name=GUObjectArray status=target-mapped anchor=0x140030000 value=0x140050000 rva=0x50000 allocationBase=0x140000000 regionBase=0x140050000 protect=0x4 type=0x1000000 module=C:\\game\\TargetGame-Win64-Shipping.exe
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-pointer name=GWorld status=anchor-unmapped anchor=0x1
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-layout name=GUObjectArray status=target-readable anchor=0x140030000 target=0x140050000 slots=2 protect=0x4 module=C:\\game\\TargetGame-Win64-Shipping.exe
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-layout-slot name=GUObjectArray target=0x140050000 offset=0x0 value=0x140060000 status=target-mapped readable=true writable=true executable=false protect=0x4
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-layout-slot name=GUObjectArray target=0x140050000 offset=0x8 value=0x0 status=null
2026-06-16T17:43:39Z pid=312 loader=win-client event=lua-object-registry source=ue-uobject status=added name=GUObjectArray path=/RuntimeProbe/GUObjectArray class=UObjectCandidate address=0x140050000 registryCount=1
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-uobject name=GUObjectArray status=candidate anchor=0x140030000 target=0x140050000 vtable=0x140060000 vtableMapped=true objectFlags=0x11 internalIndex=7 class=0x140050000 classMapped=true nameComparisonIndex=1234 nameNumber=1 outer=0x0 outerMapped=false
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-reflection name=GUObjectArray status=class-mapped object=0x140050000 class=0x140050000 classVtable=0x140060000 classVtableMapped=true classNameComparisonIndex=1234 classNameNumber=1 slots=6 nextOffset=0x28 superOffset=0x30 childrenOffset=0x38 childPropertiesOffset=0x40 propertyLinkOffset=0x48 functionLinkOffset=0x50
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-reflection-slot name=GUObjectArray slot=children status=target-mapped class=0x140050000 offset=0x38 value=0x140060000 readable=true writable=true executable=false protect=0x4
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-reflection-slot name=GUObjectArray slot=propertyLink status=target-mapped class=0x140050000 offset=0x48 value=0x140060000 readable=true writable=true executable=false protect=0x4
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-reflection-slot name=GUObjectArray slot=functionLink status=target-mapped class=0x140050000 offset=0x50 value=0x140060000 readable=true writable=true executable=false protect=0x4
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-fname source=ue-reflection-field objectName=GUObjectArray.children_0 status=decoded object=0x140060000 pool=0x1400a0000 resolver=FNamePool:direct comparisonIndex=1234 number=1 block=0 offset=0x4d2 entry=0x1400b1348 wide=false decoded=DecodedField_0
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-reflection-field name=GUObjectArray chain=children index=0 status=candidate field=0x140060000 class=0x140050000 classMapped=true nameComparisonIndex=1234 nameNumber=1 next=0x0 nextReadable=true nextMapped=false
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-reflection-field name=GUObjectArray chain=propertyLink index=0 status=candidate field=0x140061000 class=0x140050000 classMapped=true nameComparisonIndex=1234 nameNumber=1 next=0x0 nextReadable=true nextMapped=false
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-reflection-field name=GUObjectArray chain=functionLink index=0 status=candidate field=0x140062000 class=0x140050000 classMapped=true nameComparisonIndex=1234 nameNumber=1 next=0x0 nextReadable=true nextMapped=false
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-function-param-root name=GUObjectArray functionIndex=0 chain=childProperties status=root function=0x140062000 offset=0x40 root=0x140063000 functionFlags=0x400 functionFlagsReadable=true functionFlagsOffset=0x58
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-function-param name=GUObjectArray functionIndex=0 chain=childProperties index=0 status=candidate function=0x140062000 functionName=DecodedFunction_0 functionPath=/RuntimeProbe/GUObjectArray.DecodedFunction_0:Function field=0x140063000 class=0x140050000 classMapped=true nameComparisonIndex=1234 nameNumber=1 fieldName=DecodedParam_0 arrayDim=1 elementSize=4 propertyFlags=0x80 offsetInternal=16 arrayDimReadable=true elementSizeReadable=true propertyFlagsReadable=true offsetInternalReadable=true functionFlags=0x400 functionFlagsReadable=true next=0x0 nextReadable=true nextMapped=false
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-function-param-container-child name=GUObjectArray functionIndex=0 chain=childProperties index=0 status=candidate field=0x140063000 containerClassName=FArrayProperty role=inner child=0x140064000 childOffset=0x70 childClass=0x140050000 childClassMapped=true childClassName=FIntProperty childNameComparisonIndex=1235 childNameNumber=1 childName=DecodedArrayInner_0
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-function-param-root name=GUObjectArray functionIndex=0 chain=propertyLink status=null-root function=0x140062000 offset=0x48
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-reflection-property name=GUObjectArray chain=childProperties index=0 status=candidate field=0x140061000 arrayDim=1 elementSize=4 propertyFlags=0x1 offsetInternal=12 arrayDimReadable=true elementSizeReadable=true propertyFlagsReadable=true offsetInternalReadable=true
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-reflection-property name=GUObjectArray chain=propertyLink index=0 status=candidate field=0x140061000 arrayDim=1 elementSize=4 propertyFlags=0x1 offsetInternal=12 arrayDimReadable=true elementSizeReadable=true propertyFlagsReadable=true offsetInternalReadable=true
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-reflection-value name=GUObjectArray chain=childProperties index=0 fieldName=DecodedField_0 status=read object=0x140050000 address=0x14005000c offsetInternal=12 elementSize=4 arrayDim=1 requestedBytes=4 readBytes=4 raw=07000000 rawLe=0x7 truncated=false
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-reflection-value name=GUObjectArray chain=propertyLink index=0 fieldName=DecodedField_0 status=read object=0x140050000 address=0x14005000c offsetInternal=12 elementSize=4 arrayDim=1 requestedBytes=4 readBytes=4 raw=07000000 rawLe=0x7 truncated=false
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-fname source=ue-uobject objectName=GUObjectArray status=decoded object=0x140050000 pool=0x1400a0000 resolver=FNamePool:direct comparisonIndex=1234 number=1 block=0 offset=0x4d2 entry=0x1400b1348 wide=false decoded=DecodedObject_0
2026-06-16T17:43:39Z pid=312 loader=win-client event=lua-object-registry source=ue-uobject-fname status=added name=DecodedObject_0 path=/RuntimeProbe/DecodedObject_0 aliasOf=GUObjectArray class=UObjectCandidate address=0x140050000 registryCount=2
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-object-array name=GUObjectArray mode=indirect status=scanning base=0x140070000 chunks=0x140080000 maxElements=2 numElements=1 maxChunks=1 numChunks=1 limit=1 itemSize=24 chunkSize=65536
2026-06-16T17:43:39Z pid=312 loader=win-client event=lua-object-registry source=ue-object-array status=added name=GUObjectArray_0 path=/RuntimeProbe/GUObjectArray_0 class=UObjectArrayItem address=0x140050000 registryCount=3
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-object-array-item name=GUObjectArray index=0 status=registered object=0x140050000 class=0x140050000
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-fname source=ue-object-array objectName=GUObjectArray_0 status=decoded object=0x140050000 pool=0x1400a0000 resolver=FNamePool:direct comparisonIndex=1234 number=1 block=0 offset=0x4d2 entry=0x1400b1348 wide=false decoded=DecodedObject_0
2026-06-16T17:43:39Z pid=312 loader=win-client event=lua-object-registry source=ue-object-array-fname status=skipped name=DecodedObject_0 path=/RuntimeProbe/DecodedObject_0 aliasOf=GUObjectArray_0 class=UObjectArrayItem address=0x140050000 registryCount=3
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-object-array name=GUObjectArray mode=indirect status=finished base=0x140070000 scanned=1 registered=1
2026-06-16T17:43:39Z pid=312 loader=win-client event=hook-dispatch name=SelfTestHook status=installed target=0x140090000 replacement=0x140091000 trampoline=0x140092000 patchBytes=12
2026-06-16T17:43:39Z pid=312 loader=win-client event=hook-dispatch name=SelfTestHook status=restored target=0x140090000
2026-06-16T17:43:39Z pid=312 loader=win-client event=hook-dispatch-self-test phase=thread status=passed before=42 after=1042 final=42 original=42 callbacks=2 preCallbacks=1 postCallbacks=1 installed=true restored=true target=0x140090000 replacement=0x140091000 trampoline=0x140092000
2026-06-16T17:43:39Z pid=312 loader=win-client event=mod-dispatch-self-test phase=thread status=passed mods=1 loaded=1 unloaded=1 result=1042 original=42 callbacks=2 preCallbacks=1 postCallbacks=1 loadCallbacks=1 unloadCallbacks=1
2026-06-16T17:43:39Z pid=312 loader=win-client event=lua-dispatch-self-test phase=thread status=passed library=lua54.dll loadStatus=0 callStatus=0 callbackStatus=0 result=42 isNumber=true hooks=1 hook=/Script/UE4SSLProbe.SelfTest:Function preRef=3 postRef=4 preCalls=1 postCalls=1 preResult=11 postResult=31 preIsNumber=true postIsNumber=true objectHandles=4 ueObjectHandles=2 staticFindObjectCalls=1 staticFindObjectHits=1 findObjectCalls=1 findObjectHits=1 findFirstOfCalls=1 findFirstOfHits=1 getKnownObjectsCalls=1 getKnownObjectsHits=1 findObjectsCalls=1 findObjectsHits=1 findAllOfCalls=1 findAllOfHits=1 forEachUObjectCalls=1 forEachUObjectCallbacks=4 isACalls=6 isAHits=5 loadAssetCalls=1 loadAssetHits=1 staticConstructObjectCalls=1 staticConstructObjectHits=1 notifyOnNewObjectCalls=1 executeInGameThreadCalls=1 executeInGameThreadCallbacks=1 executeInGameThreadResult=9 executeInGameThreadIsNumber=true scriptBytes=612
2026-06-16T17:43:39Z pid=312 loader=win-client event=lua-reflection-self-test phase=thread status=passed library=lua54.dll loadStatus=0 callStatus=0 result=42 isNumber=true staticFindObjectCalls=2 staticFindObjectHits=2 getPropertyCalls=20 getPropertyHits=20 rawPropertyHits=2 rawPropertyValue=17 namedPropertyHits=2 rawPropertySetHits=1 rawPropertySetValue=17 arrayInnerPropertyHits=1 enumPropertyHits=1 enumUnderlyingPropertyHits=1 setElementPropertyHits=1 mapKeyPropertyHits=1 mapValuePropertyHits=1 importTextHits=1 exportTextHits=1 propertyMetadataHits=7 descriptorValueGetHits=16 descriptorValueSetHits=8 setPropertyCalls=9 setPropertyHits=9 callFunctionCalls=2 callFunctionHits=2 probeValue=21 probeBool=false probeFloat=13.750 probeDouble=-47.500 probeName=ArrakisName probeString=melange probeText=WaterDebt probeObject=0x1234 objectHandles=3 ueObjectHandles=2 scriptBytes=2200
2026-06-16T17:43:39Z pid=312 loader=win-client event=lua-process-event-self-test phase=thread status=passed library=lua54.dll loadStatus=0 callStatus=0 result=4 isNumber=true hooks=2 hook=/Script/UE4SSLProbe.SelfTest:Function installed=true restored=true hookCalls=1 originalCalls=2 originalAfterHook=1 preStatus=0 postStatus=0 preCalls=1 postCalls=1 preResult=11 postResult=31 preIsNumber=true postIsNumber=true paramDescriptorHits=2 paramDescriptorLookupCalls=13 paramDescriptorLookupHits=13 functionParamDescriptorCalls=2 functionParamDescriptorHits=2 paramGetCalls=21 paramGetHits=21 paramSetCalls=7 paramSetHits=7 paramsResult=42 paramsTouched=1 finalResult=52 finalTouched=1 object=0x140050000 function=0x140061000 params=0x20 trampoline=0x140092000 scriptBytes=103
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-process-event-dispatch-self-test phase=thread status=armed preRegistered=true postRegistered=true callbacks=2
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-process-event-live-lua-dispatch phase=thread status=armed library=lua54.dll loadStatus=0 callStatus=0 result=4 isNumber=true hooks=2 hook=/Script/UE4SSLProbe.LiveProcessEvent:Function callbacks=4 scriptBytes=111
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-process-event-live-context status=resolved call=1 object=0x140050000 objectResolved=true objectPath=/RuntimeProbe/GUObjectArray objectClass=UObjectCandidate function=0x140062000 functionPath=/RuntimeProbe/GUObjectArray.DecodedFunction_0:Function functionParamDescriptors=1 params=0x20 paramsPresent=true
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-process-event-live-param status=read call=1 function=0x140062000 functionPath=/RuntimeProbe/GUObjectArray.DecodedFunction_0:Function param=DecodedParam_0 className=FIntProperty type=int32 offset=16 size=4 value=62
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-process-event-live-param status=raw call=1 function=0x140062000 functionPath=/RuntimeProbe/GUObjectArray.DecodedFunction_0:Function param=DecodedStruct_0 className=FStructProperty type=struct offset=24 size=16 value=rawHex=0102030405060708090a0b0c0d0e0f10
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-process-event-live-param status=container call=1 function=0x140062000 functionPath=/RuntimeProbe/GUObjectArray.DecodedFunction_0:Function param=DecodedArray_0 className=FArrayProperty type=array offset=40 size=16 value=kind=FScriptArray,data=0x1400f0000,num=2,max=4,rawHex=00000f40010000000200000004000000,dataSampleHex=2a0000002b0000002c0000002d000000
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-process-event-live-hook phase=thread status=installed target=0x140040000 selfTestTarget=true callSelfTest=true dispatchCallbacks=4 luaDispatch=true luaPreStatus=0 luaPostStatus=0 luaPreCalls=1 luaPostCalls=1 luaObjectHandleHits=2 luaFunctionHandleHits=2 luaParamsHandleHits=2 luaParamDescriptorHits=2 luaParamDescriptorLookupCalls=13 luaParamDescriptorLookupHits=13 luaFunctionParamDescriptorCalls=2 luaFunctionParamDescriptorHits=2 luaParamGetCalls=21 luaParamGetHits=21 luaParamSetCalls=7 luaParamSetHits=7 preCallbacks=2 postCallbacks=2 liveCalls=1 originalCalls=1 paramsResult=62 paramsTouched=1 trampoline=0x1400d0000
2026-06-16T17:43:40Z pid=312 loader=win-client event=ue-process-event-live-lua-dispatch phase=detach status=closed preCalls=1 postCalls=1 preResult=11 postResult=31 preStatus=0 postStatus=0
2026-06-16T17:43:39Z pid=312 loader=win-client event=lua-mod-start phase=thread status=running library=lua54.dll scripts=2 skipped=0
2026-06-16T17:43:39Z pid=312 loader=win-client event=lua-mod-script phase=thread status=passed name=CallbackMod path=C:\\mods\\CallbackMod\\Scripts\\main.lua loadStatus=0 callStatus=0 hooksBefore=0 hooksAfter=1 scriptBytes=100
2026-06-16T17:43:39Z pid=312 loader=win-client event=lua-mod-script phase=thread status=passed name=CallbackModTwo path=C:\\mods\\CallbackModTwo\\Scripts\\main.lua loadStatus=0 callStatus=0 hooksBefore=1 hooksAfter=2 scriptBytes=100
2026-06-16T17:43:39Z pid=312 loader=win-client event=lua-mod-dispatch-self-test phase=thread status=passed callbackStatus=0 hooks=2 hook=/Script/UE4SSLProbe.ModEntry:Function preCalls=2 postCalls=2 preResult=11 postResult=31 preIsNumber=true postIsNumber=true
2026-06-16T17:43:39Z pid=312 loader=win-client event=lua-mod-finish phase=thread status=passed library=lua54.dll scripts=2 loaded=2 failed=0 hooks=2 skipped=0 objectHandles=4 ueObjectHandles=2 staticFindObjectCalls=1 staticFindObjectHits=1 findObjectCalls=1 findObjectHits=1 findFirstOfCalls=1 findFirstOfHits=1 getKnownObjectsCalls=1 getKnownObjectsHits=1 findObjectsCalls=1 findObjectsHits=1 findAllOfCalls=1 findAllOfHits=1 forEachUObjectCalls=1 forEachUObjectCallbacks=4 isACalls=5 isAHits=2 loadAssetCalls=1 loadAssetHits=1 staticConstructObjectCalls=1 staticConstructObjectHits=1
2026-06-16T17:43:39Z pid=312 loader=win-client event=scan-finish
2026-06-16T17:43:40Z pid=332 loader=win-client event=forward-smoke function=GetFileVersionInfoSizeW result=1812 handle=0x0
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
    "staticConstructObjectCalls=1 staticConstructObjectHits=1\n",
    (
        "staticConstructObjectCalls=1 staticConstructObjectHits=1 "
        "notifyOnNewObjectCalls=3 notifyOnNewObjectCallbacks=2 "
        "notifyOnNewObjectResult=19 notifyOnNewObjectIsNumber=true "
        "notifyOnNewObjectStatus=0 staticConstructObjectOuterHits=1 "
        "getWorldCalls=3 getWorldHits=2 "
        "getCdoCalls=1 getCdoHits=1 getLevelCalls=2 getLevelHits=2\n"
    ),
)
SAMPLE_LOG = SAMPLE_LOG.replace(
    "hooks=2 skipped=0 objectHandles=4",
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
        "callFunctionPreHandled=1 callFunctionPostHandled=1 skipped=0 objectHandles=4"
    ),
)


class ClientLoaderScanSummaryTests(unittest.TestCase):
    def test_summarize_windows_log(self):
        records = [scan_summary.parse_line(line) for line in SAMPLE_LOG.splitlines()]
        summary = scan_summary.summarize(records, loader_filter=["win-client"])

        self.assertEqual(summary["hitCount"], 2)
        self.assertEqual(summary["moduleCount"], 1)
        self.assertEqual(summary["ueAnchorCount"], 2)
        self.assertEqual(summary["mappedUeAnchorCount"], 1)
        self.assertEqual(summary["ueAnchorSignatureCount"], 2)
        self.assertEqual(summary["resolvedUeAnchorSignatureCount"], 1)
        self.assertEqual(summary["ueAnchorSignatureStatusCounts"], {"missing": 1, "resolved": 1})
        self.assertEqual(summary["uePointerCount"], 2)
        self.assertEqual(summary["mappedUePointerCount"], 1)
        self.assertEqual(summary["ueLayoutCount"], 1)
        self.assertEqual(summary["readableUeLayoutCount"], 1)
        self.assertEqual(summary["ueLayoutSlotCount"], 2)
        self.assertEqual(summary["mappedUeLayoutSlotCount"], 1)
        self.assertEqual(summary["ueUObjectCount"], 1)
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
        self.assertEqual(summary["ueFunctionPaths"], ["/RuntimeProbe/GUObjectArray.DecodedFunction_0:Function"])
        self.assertEqual(summary["readableUeFunctionFlagRootCount"], 1)
        self.assertEqual(summary["readableUeFunctionFlagParamCount"], 1)
        self.assertEqual(summary["ueFunctionFlagPathCount"], 1)
        self.assertEqual(summary["ueFunctionFlagPaths"], ["/RuntimeProbe/GUObjectArray.DecodedFunction_0:Function"])
        self.assertEqual(summary["ueFunctionFlagValues"], ["0x400"])
        self.assertEqual(summary["hookDispatchCount"], 2)
        self.assertEqual(summary["hookSelfTestCount"], 1)
        self.assertEqual(summary["passedHookSelfTestCount"], 1)
        self.assertEqual(summary["modSelfTestCount"], 1)
        self.assertEqual(summary["passedModSelfTestCount"], 1)
        self.assertEqual(summary["luaSelfTestCount"], 1)
        self.assertEqual(summary["passedLuaSelfTestCount"], 1)
        self.assertEqual(summary["passedLuaCallbackSelfTestCount"], 1)
        self.assertEqual(summary["passedLuaApiSelfTestCount"], 1)
        self.assertEqual(summary["passedLuaObjectApiSelfTestCount"], 1)
        self.assertEqual(summary["luaReflectionSelfTestCount"], 1)
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
        self.assertEqual(summary["luaProcessEventSelfTestCount"], 1)
        self.assertEqual(summary["passedLuaProcessEventSelfTestCount"], 1)
        self.assertEqual(summary["luaProcessEventParamAccessorSelfTestCount"], 1)
        self.assertEqual(summary["luaProcessEventScalarParamAccessorSelfTestCount"], 1)
        self.assertEqual(summary["luaProcessEventNameStringParamAccessorSelfTestCount"], 1)
        self.assertEqual(summary["luaProcessEventStructParamAccessorSelfTestCount"], 1)
        self.assertEqual(summary["routedLuaProcessEventSelfTestCount"], 1)
        self.assertEqual(summary["installedUeProcessEventLiveHookCount"], 1)
        self.assertEqual(summary["ueProcessEventLiveContextCount"], 1)
        self.assertEqual(summary["resolvedUeProcessEventLiveContextCount"], 1)
        self.assertEqual(summary["ueProcessEventLiveParamCount"], 3)
        self.assertEqual(summary["readUeProcessEventLiveParamCount"], 1)
        self.assertEqual(summary["rawUeProcessEventLiveParamCount"], 1)
        self.assertEqual(summary["containerUeProcessEventLiveParamCount"], 1)
        self.assertEqual(summary["sampledContainerUeProcessEventLiveParamCount"], 1)
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
        self.assertEqual(summary["luaModScriptCount"], 2)
        self.assertEqual(summary["passedLuaModScriptCount"], 2)
        self.assertEqual(summary["luaModDispatchSelfTestCount"], 1)
        self.assertEqual(summary["passedLuaModDispatchSelfTestCount"], 1)
        self.assertEqual(summary["luaModFinishCount"], 1)
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
        self.assertEqual(summary["ueObjectArrayCount"], 2)
        self.assertEqual(summary["finishedUeObjectArrayCount"], 1)
        self.assertEqual(summary["ueFNameCount"], 3)
        self.assertEqual(summary["decodedUeFNameCount"], 3)
        self.assertEqual(summary["forwardSmokeCount"], 1)
        self.assertEqual(summary["hitsByName"]["FNamePool"]["category"], "ue")
        self.assertIn("GUObjectArray", summary["hitsByName"])
        self.assertEqual(summary["hitsByName"]["GWorld"]["kinds"], {"ue-anchor-signature": 1})
        self.assertEqual(summary["uePointersByName"]["GUObjectArray"][0]["status"], "target-mapped")
        self.assertEqual(summary["ueLayoutSlotsByName"]["GUObjectArray"][0]["status"], "target-mapped")
        self.assertEqual(summary["ueUObjectsByName"]["GUObjectArray"][0]["classMapped"], "true")
        self.assertEqual(summary["ueFNamesByObjectName"]["GUObjectArray"][0]["decoded"], "DecodedObject_0")
        self.assertNotIn("GWorld", summary["missingExpected"])
        self.assertIn("GObjectArray", summary["missingExpected"])

    def test_cli_json_output(self):
        with tempfile.TemporaryDirectory() as tmp:
            log = Path(tmp) / "client.log"
            log.write_text(SAMPLE_LOG, encoding="utf-8")
            result = subprocess.run(
                [str(SCRIPT), str(log), "--loader", "win-client", "--format", "json"],
                cwd=ROOT,
                text=True,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                check=True,
            )

        summary = json.loads(result.stdout)
        self.assertEqual(summary["categories"], {"ue": 4})
        self.assertEqual(summary["scanFinishCount"], 1)


if __name__ == "__main__":
    unittest.main()
