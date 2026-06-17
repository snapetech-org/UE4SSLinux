#!/usr/bin/env python3
import importlib.util
import json
import subprocess
import tempfile
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
SCRIPT_CANDIDATES = (
    ROOT / "scripts" / "ue4ss-port-readiness.py",
    ROOT / "analysis" / "ue4ss-port-readiness.py",
)
SCRIPT = next((path for path in SCRIPT_CANDIDATES if path.exists()), SCRIPT_CANDIDATES[0])


spec = importlib.util.spec_from_file_location("ue4ss_port_readiness", SCRIPT)
readiness = importlib.util.module_from_spec(spec)
assert spec.loader is not None
spec.loader.exec_module(readiness)


PARTIAL_LOG = """\
2026-06-16T17:43:39Z pid=312 loader=win-client event=loaded phase=thread exe=C:\\game\\TargetGame-Win64-Shipping.exe native=pe
2026-06-16T17:43:39Z pid=312 loader=win-client event=scan-start strings=2 signatures=0 filters=0 maxHits=2 maxRegionBytes=268435456
2026-06-16T17:43:39Z pid=312 loader=win-client event=scan-hit kind=string name=FNamePool addr=0x140010000 rva=0x10000 allocationBase=0x140000000 regionBase=0x140010000 protect=0x2 type=0x1000000 module=C:\\game\\TargetGame-Win64-Shipping.exe
2026-06-16T17:43:39Z pid=312 loader=win-client event=scan-finish
"""


SIGNATURE_ANCHOR_LOG = """\
2026-06-16T17:43:39Z pid=312 loader=win-client event=loaded phase=thread exe=C:\\game\\TargetGame-Win64-Shipping.exe native=pe
2026-06-16T17:43:39Z pid=312 loader=win-client event=scan-start strings=0 signatures=4 filters=0 maxHits=2 maxRegionBytes=268435456
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-anchor-signature name=FNamePool status=resolved hit=0x140001000 addr=0x140010000 transform=riprel32+3 rva=0x10000 allocationBase=0x140000000 regionBase=0x140010000 protect=0x4 type=0x1000000 module=C:\\game\\TargetGame-Win64-Shipping.exe
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-anchor-signature name=GUObjectArray status=resolved hit=0x140002000 addr=0x140020000 transform=riprel32+3 rva=0x20000 allocationBase=0x140000000 regionBase=0x140020000 protect=0x4 type=0x1000000 module=C:\\game\\TargetGame-Win64-Shipping.exe
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-anchor-signature name=GWorld status=resolved hit=0x140003000 addr=0x140030000 transform=riprel32+3 rva=0x30000 allocationBase=0x140000000 regionBase=0x140030000 protect=0x4 type=0x1000000 module=C:\\game\\TargetGame-Win64-Shipping.exe
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-anchor-signature name=ProcessEvent status=resolved hit=0x140004000 addr=0x140040000 transform=callrel32 rva=0x40000 allocationBase=0x140000000 regionBase=0x140040000 protect=0x20 type=0x1000000 module=C:\\game\\TargetGame-Win64-Shipping.exe
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-anchor-signature name=UObject status=resolved hit=0x140005000 addr=0x140050000 transform=hit rva=0x50000 allocationBase=0x140000000 regionBase=0x140050000 protect=0x4 type=0x1000000 module=C:\\game\\TargetGame-Win64-Shipping.exe
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-anchor-signature name=UFunction status=resolved hit=0x140006000 addr=0x140060000 transform=hit rva=0x60000 allocationBase=0x140000000 regionBase=0x140060000 protect=0x4 type=0x1000000 module=C:\\game\\TargetGame-Win64-Shipping.exe
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-anchor-signature name=StaticFindObject status=missing oversizedRegions=0
2026-06-16T17:43:39Z pid=312 loader=win-client event=scan-finish
"""


READY_LOG = """\
2026-06-16T17:43:39Z pid=312 loader=win-client event=loaded phase=thread exe=C:\\game\\TargetGame-Win64-Shipping.exe native=pe
2026-06-16T17:43:39Z pid=312 loader=win-client event=scan-start strings=8 signatures=1 filters=0 maxHits=2 maxRegionBytes=268435456
2026-06-16T17:43:39Z pid=312 loader=win-client event=scan-hit kind=string name=FNamePool addr=0x140010000 rva=0x10000 allocationBase=0x140000000 regionBase=0x140010000 protect=0x2 type=0x1000000 module=C:\\game\\TargetGame-Win64-Shipping.exe
2026-06-16T17:43:39Z pid=312 loader=win-client event=scan-hit kind=string name=GUObjectArray addr=0x140020000 rva=0x20000 allocationBase=0x140000000 regionBase=0x140020000 protect=0x2 type=0x1000000 module=C:\\game\\TargetGame-Win64-Shipping.exe
2026-06-16T17:43:39Z pid=312 loader=win-client event=scan-hit kind=string name=GWorld addr=0x140030000 rva=0x30000 allocationBase=0x140000000 regionBase=0x140030000 protect=0x2 type=0x1000000 module=C:\\game\\TargetGame-Win64-Shipping.exe
2026-06-16T17:43:39Z pid=312 loader=win-client event=scan-hit kind=string name=ProcessEvent addr=0x140040000 rva=0x40000 allocationBase=0x140000000 regionBase=0x140040000 protect=0x2 type=0x1000000 module=C:\\game\\TargetGame-Win64-Shipping.exe
2026-06-16T17:43:39Z pid=312 loader=win-client event=scan-hit kind=string name=UObject addr=0x140050000 rva=0x50000 allocationBase=0x140000000 regionBase=0x140050000 protect=0x2 type=0x1000000 module=C:\\game\\TargetGame-Win64-Shipping.exe
2026-06-16T17:43:39Z pid=312 loader=win-client event=scan-hit kind=string name=UFunction addr=0x140060000 rva=0x60000 allocationBase=0x140000000 regionBase=0x140060000 protect=0x2 type=0x1000000 module=C:\\game\\TargetGame-Win64-Shipping.exe
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-pointer name=GWorld status=target-mapped anchor=0x140030000 value=0x140070000 rva=0x70000 allocationBase=0x140000000 regionBase=0x140070000 protect=0x4 type=0x1000000 module=C:\\game\\TargetGame-Win64-Shipping.exe
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-layout name=GWorld status=target-readable anchor=0x140030000 target=0x140070000 slots=2 protect=0x4 module=C:\\game\\TargetGame-Win64-Shipping.exe
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-layout-slot name=GWorld target=0x140070000 offset=0x0 value=0x140080000 status=target-mapped readable=true writable=true executable=false protect=0x4
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-layout-slot name=GWorld target=0x140070000 offset=0x8 value=0x0 status=null
2026-06-16T17:43:39Z pid=312 loader=win-client event=lua-object-registry source=ue-uobject status=added name=GWorld path=/RuntimeProbe/GWorld class=UObjectCandidate address=0x140070000 registryCount=1
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-uobject name=GWorld status=candidate anchor=0x140030000 target=0x140070000 vtable=0x140080000 vtableMapped=true objectFlags=0x11 internalIndex=7 class=0x140070000 classMapped=true nameComparisonIndex=1234 nameNumber=1 outer=0x0 outerMapped=false
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-reflection name=GWorld status=class-mapped object=0x140070000 class=0x140070000 classVtable=0x140080000 classVtableMapped=true classNameComparisonIndex=1234 classNameNumber=1 slots=6 nextOffset=0x28 superOffset=0x30 childrenOffset=0x38 childPropertiesOffset=0x40 propertyLinkOffset=0x48 functionLinkOffset=0x50
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-reflection-slot name=GWorld slot=children status=target-mapped class=0x140070000 offset=0x38 value=0x140080000 readable=true writable=true executable=false protect=0x4
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-reflection-slot name=GWorld slot=propertyLink status=target-mapped class=0x140070000 offset=0x48 value=0x140080000 readable=true writable=true executable=false protect=0x4
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-reflection-slot name=GWorld slot=functionLink status=target-mapped class=0x140070000 offset=0x50 value=0x140080000 readable=true writable=true executable=false protect=0x4
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-reflection-field name=GWorld chain=children index=0 status=candidate field=0x140080000 class=0x140070000 classMapped=true nameComparisonIndex=1234 nameNumber=1 next=0x0 nextReadable=true nextMapped=false
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-reflection-field name=GWorld chain=propertyLink index=0 status=candidate field=0x140081000 class=0x140070000 classMapped=true nameComparisonIndex=1234 nameNumber=1 next=0x0 nextReadable=true nextMapped=false
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-reflection-field name=GWorld chain=functionLink index=0 status=candidate field=0x140082000 class=0x140070000 classMapped=true nameComparisonIndex=1234 nameNumber=1 next=0x0 nextReadable=true nextMapped=false
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-function-param-root name=GWorld functionIndex=0 chain=childProperties status=root function=0x140082000 offset=0x40 root=0x140083000 functionFlags=0x400 functionFlagsReadable=true functionFlagsOffset=0x58
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-function-param name=GWorld functionIndex=0 chain=childProperties index=0 status=candidate function=0x140082000 functionName=DecodedFunction_0 functionPath=/RuntimeProbe/GWorld.DecodedFunction_0:Function field=0x140083000 class=0x140070000 classMapped=true nameComparisonIndex=1234 nameNumber=1 fieldName=DecodedParam_0 arrayDim=1 elementSize=4 propertyFlags=0x80 offsetInternal=16 arrayDimReadable=true elementSizeReadable=true propertyFlagsReadable=true offsetInternalReadable=true functionFlags=0x400 functionFlagsReadable=true next=0x0 nextReadable=true nextMapped=false
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-function-param-container-child name=GWorld functionIndex=0 chain=childProperties index=0 status=candidate field=0x140083000 containerClassName=FArrayProperty role=inner child=0x140084000 childOffset=0x70 childClass=0x140070000 childClassMapped=true childClassName=FIntProperty childNameComparisonIndex=1235 childNameNumber=1 childName=DecodedArrayInner_0
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-function-param-root name=GWorld functionIndex=0 chain=propertyLink status=null-root function=0x140082000 offset=0x48
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-reflection-property name=GWorld chain=childProperties index=0 status=candidate field=0x140081000 arrayDim=1 elementSize=4 propertyFlags=0x1 offsetInternal=12 arrayDimReadable=true elementSizeReadable=true propertyFlagsReadable=true offsetInternalReadable=true
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-reflection-property name=GWorld chain=propertyLink index=0 status=candidate field=0x140081000 arrayDim=1 elementSize=4 propertyFlags=0x1 offsetInternal=12 arrayDimReadable=true elementSizeReadable=true propertyFlagsReadable=true offsetInternalReadable=true
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-reflection-value name=GWorld chain=childProperties index=0 fieldName=DecodedWorld_0 status=read object=0x140070000 address=0x14007000c offsetInternal=12 elementSize=4 arrayDim=1 requestedBytes=4 readBytes=4 raw=07000000 rawLe=0x7 truncated=false
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-reflection-value name=GWorld chain=propertyLink index=0 fieldName=DecodedWorld_0 status=read object=0x140070000 address=0x14007000c offsetInternal=12 elementSize=4 arrayDim=1 requestedBytes=4 readBytes=4 raw=07000000 rawLe=0x7 truncated=false
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-fname source=ue-uobject objectName=GWorld status=decoded object=0x140070000 pool=0x1400b0000 resolver=FNamePool:direct comparisonIndex=1234 number=1 block=0 offset=0x4d2 entry=0x1400b1348 wide=false decoded=DecodedWorld_0
2026-06-16T17:43:39Z pid=312 loader=win-client event=lua-object-registry source=ue-uobject-fname status=added name=DecodedWorld_0 path=/RuntimeProbe/DecodedWorld_0 aliasOf=GWorld class=UObjectCandidate address=0x140070000 registryCount=2
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-object-array name=GWorld mode=indirect status=scanning base=0x140090000 chunks=0x1400a0000 maxElements=2 numElements=1 maxChunks=1 numChunks=1 limit=1 itemSize=24 chunkSize=65536
2026-06-16T17:43:39Z pid=312 loader=win-client event=lua-object-registry source=ue-object-array status=added name=GWorld_0 path=/RuntimeProbe/GWorld_0 class=UObjectArrayItem address=0x140070000 registryCount=3
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-object-array-item name=GWorld index=0 status=registered object=0x140070000 class=0x140070000 internalFlags=0x2000000 internalFlagsReadable=true
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-fname source=ue-object-array objectName=GWorld_0 status=decoded object=0x140070000 pool=0x1400b0000 resolver=FNamePool:direct comparisonIndex=1234 number=1 block=0 offset=0x4d2 entry=0x1400b1348 wide=false decoded=DecodedWorld_0
2026-06-16T17:43:39Z pid=312 loader=win-client event=lua-object-registry source=ue-object-array-fname status=skipped name=DecodedWorld_0 path=/RuntimeProbe/DecodedWorld_0 aliasOf=GWorld_0 class=UObjectArrayItem address=0x140070000 registryCount=3
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-object-array name=GWorld mode=indirect status=finished base=0x140090000 scanned=1 registered=1
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-process-event-hook phase=thread status=passed target=0x140040000 installed=true restored=true selfTestTarget=false callSelfTest=false liveCalls=0 originalCalls=0 paramsResult=0 paramsTouched=0 trampoline=0x1400c0000
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-process-event-dispatch-self-test phase=thread status=armed preRegistered=true postRegistered=true callbacks=2
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-process-event-live-lua-dispatch phase=thread status=armed library=lua54.dll loadStatus=0 callStatus=0 result=4 isNumber=true hooks=2 hook=/Script/UE4SSLProbe.LiveProcessEvent:Function callbacks=4 scriptBytes=111
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-process-event-live-context status=resolved call=1 object=0x140070000 objectResolved=true objectPath=/RuntimeProbe/GWorld objectClass=UObjectCandidate function=0x140082000 functionPath=/RuntimeProbe/GWorld.DecodedFunction_0:Function functionParamDescriptors=1 params=0x20 paramsPresent=true
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-process-event-live-param status=read call=1 function=0x140082000 functionPath=/RuntimeProbe/GWorld.DecodedFunction_0:Function param=DecodedParam_0 className=FIntProperty type=int32 offset=16 size=4 value=62
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-process-event-live-param status=raw call=1 function=0x140082000 functionPath=/RuntimeProbe/GWorld.DecodedFunction_0:Function param=DecodedStruct_0 className=FStructProperty type=struct offset=24 size=16 value=rawHex=0102030405060708090a0b0c0d0e0f10
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-process-event-live-param status=container call=1 function=0x140082000 functionPath=/RuntimeProbe/GWorld.DecodedFunction_0:Function param=DecodedArray_0 className=FArrayProperty type=array offset=40 size=16 value=kind=FScriptArray,data=0x1400f0000,num=2,max=4,rawHex=00000f40010000000200000004000000,dataSampleHex=2a0000002b0000002c0000002d000000
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-process-event-live-hook phase=thread status=installed target=0x140040000 selfTestTarget=true callSelfTest=true dispatchCallbacks=4 luaDispatch=true luaPreStatus=0 luaPostStatus=0 luaPreCalls=1 luaPostCalls=1 luaObjectHandleHits=2 luaFunctionHandleHits=2 luaParamsHandleHits=2 luaParamDescriptorHits=2 luaParamDescriptorLookupCalls=13 luaParamDescriptorLookupHits=13 luaFunctionParamDescriptorCalls=2 luaFunctionParamDescriptorHits=2 luaParamGetCalls=21 luaParamGetHits=21 luaParamSetCalls=7 luaParamSetHits=7 preCallbacks=2 postCallbacks=2 liveCalls=1 originalCalls=1 paramsResult=62 paramsTouched=1 trampoline=0x1400d0000
2026-06-16T17:43:40Z pid=312 loader=win-client event=ue-process-event-live-lua-dispatch phase=detach status=closed preCalls=1 postCalls=1 preResult=11 postResult=31 preStatus=0 postStatus=0
2026-06-16T17:43:39Z pid=312 loader=win-client event=hook-dispatch-self-test phase=thread status=passed before=42 after=1042 final=42 original=42 callbacks=2 preCallbacks=1 postCallbacks=1 installed=true restored=true target=0x140090000 replacement=0x140091000 trampoline=0x140092000
2026-06-16T17:43:39Z pid=312 loader=win-client event=mod-dispatch-self-test phase=thread status=passed mods=1 loaded=1 unloaded=1 result=1042 original=42 callbacks=2 preCallbacks=1 postCallbacks=1 loadCallbacks=1 unloadCallbacks=1
2026-06-16T17:43:39Z pid=312 loader=win-client event=lua-dispatch-self-test phase=thread status=passed library=lua54.dll loadStatus=0 callStatus=0 callbackStatus=0 result=42 isNumber=true hooks=1 hook=/Script/UE4SSLProbe.SelfTest:Function preRef=3 postRef=4 preCalls=1 postCalls=1 preResult=11 postResult=31 preIsNumber=true postIsNumber=true objectHandles=4 ueObjectHandles=2 staticFindObjectCalls=1 staticFindObjectHits=1 findObjectCalls=1 findObjectHits=1 findFirstOfCalls=1 findFirstOfHits=1 getKnownObjectsCalls=1 getKnownObjectsHits=1 findObjectsCalls=1 findObjectsHits=1 findAllOfCalls=1 findAllOfHits=1 forEachUObjectCalls=1 forEachUObjectCallbacks=4 isACalls=6 isAHits=5 loadAssetCalls=1 loadAssetHits=1 staticConstructObjectCalls=1 staticConstructObjectHits=1 notifyOnNewObjectCalls=1 executeInGameThreadCalls=1 executeInGameThreadCallbacks=1 executeInGameThreadResult=9 executeInGameThreadIsNumber=true scriptBytes=612
2026-06-16T17:43:39Z pid=312 loader=win-client event=lua-reflection-self-test phase=thread status=passed library=lua54.dll loadStatus=0 callStatus=0 result=42 isNumber=true staticFindObjectCalls=2 staticFindObjectHits=2 getPropertyCalls=20 getPropertyHits=20 rawPropertyHits=2 rawPropertyValue=17 namedPropertyHits=2 rawPropertySetHits=1 rawPropertySetValue=17 arrayInnerPropertyHits=1 enumPropertyHits=1 enumUnderlyingPropertyHits=1 setElementPropertyHits=1 mapKeyPropertyHits=1 mapValuePropertyHits=1 importTextHits=1 exportTextHits=1 propertyMetadataHits=7 descriptorValueGetHits=16 descriptorValueSetHits=8 setPropertyCalls=9 setPropertyHits=9 callFunctionCalls=2 callFunctionHits=2 probeValue=21 probeBool=false probeFloat=13.750 probeDouble=-47.500 probeName=ArrakisName probeString=melange probeText=WaterDebt probeObject=0x1234 objectHandles=3 ueObjectHandles=2 scriptBytes=2200
2026-06-16T17:43:39Z pid=312 loader=win-client event=lua-process-event-self-test phase=thread status=passed library=lua54.dll loadStatus=0 callStatus=0 result=4 isNumber=true hooks=2 hook=/Script/UE4SSLProbe.SelfTest:Function installed=true restored=true hookCalls=1 originalCalls=2 originalAfterHook=1 preStatus=0 postStatus=0 preCalls=1 postCalls=1 preResult=11 postResult=31 preIsNumber=true postIsNumber=true paramDescriptorHits=2 paramDescriptorLookupCalls=13 paramDescriptorLookupHits=13 functionParamDescriptorCalls=2 functionParamDescriptorHits=2 paramGetCalls=21 paramGetHits=21 paramSetCalls=7 paramSetHits=7 paramsResult=42 paramsTouched=1 finalResult=52 finalTouched=1 object=0x140070000 function=0x140061000 params=0x20 trampoline=0x140092000 scriptBytes=103
2026-06-16T17:43:39Z pid=312 loader=win-client event=lua-mod-start phase=thread status=running library=lua54.dll scripts=2 skipped=0
2026-06-16T17:43:39Z pid=312 loader=win-client event=lua-mod-script phase=thread status=passed name=CallbackMod path=C:\\mods\\CallbackMod\\Scripts\\main.lua loadStatus=0 callStatus=0 hooksBefore=0 hooksAfter=1 scriptBytes=100
2026-06-16T17:43:39Z pid=312 loader=win-client event=lua-mod-script phase=thread status=passed name=CallbackModTwo path=C:\\mods\\CallbackModTwo\\Scripts\\main.lua loadStatus=0 callStatus=0 hooksBefore=1 hooksAfter=2 scriptBytes=100
2026-06-16T17:43:39Z pid=312 loader=win-client event=lua-mod-dispatch-self-test phase=thread status=passed callbackStatus=0 hooks=2 hook=/Script/UE4SSLProbe.ModEntry:Function preCalls=2 postCalls=2 preResult=11 postResult=31 preIsNumber=true postIsNumber=true
2026-06-16T17:43:39Z pid=312 loader=win-client event=lua-mod-finish phase=thread status=passed library=lua54.dll scripts=2 loaded=2 failed=0 hooks=2 skipped=0 objectHandles=4 ueObjectHandles=2 staticFindObjectCalls=1 staticFindObjectHits=1 findObjectCalls=1 findObjectHits=1 findFirstOfCalls=1 findFirstOfHits=1 getKnownObjectsCalls=1 getKnownObjectsHits=1 findObjectsCalls=1 findObjectsHits=1 findAllOfCalls=1 findAllOfHits=1 forEachUObjectCalls=1 forEachUObjectCallbacks=4 isACalls=5 isAHits=2 loadAssetCalls=1 loadAssetHits=1 staticConstructObjectCalls=1 staticConstructObjectHits=1
2026-06-16T17:43:39Z pid=312 loader=win-client event=scan-finish
"""

READY_LOG = READY_LOG.replace(
    "forEachUObjectCalls=1 forEachUObjectCallbacks=4 isACalls=6",
    "forEachUObjectCalls=1 forEachUObjectCallbacks=4 forEachFunctionCalls=0 forEachFunctionCallbacks=0 isACalls=6",
)
READY_LOG = READY_LOG.replace(
    "forEachUObjectCalls=1 forEachUObjectCallbacks=4 isACalls=5",
    "forEachUObjectCalls=1 forEachUObjectCallbacks=4 forEachFunctionCalls=2 forEachFunctionCallbacks=2 isACalls=5",
)
READY_LOG = READY_LOG.replace(
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
READY_LOG = READY_LOG.replace(
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


class Ue4ssPortReadinessTests(unittest.TestCase):
    def test_blocks_without_core_ue_groups(self):
        with tempfile.TemporaryDirectory() as tmp:
            log = Path(tmp) / "partial.log"
            log.write_text(PARTIAL_LOG, encoding="utf-8")
            summary = readiness.summarize_log(log, ["win-client"], [], [])
            report = readiness.build_report([summary], [])

        self.assertFalse(report["ready"]["objectDiscovery"])
        self.assertFalse(report["ready"]["pointerProbe"])
        self.assertFalse(report["ready"]["layoutProbe"])
        self.assertFalse(report["ready"]["uobjectProbe"])
        self.assertFalse(report["ready"]["hookDispatch"])
        self.assertFalse(report["ready"]["modDispatch"])
        self.assertFalse(report["ready"]["luaRuntime"])
        self.assertFalse(report["ready"]["luaObjectApi"])
        self.assertFalse(report["ready"]["luaFunctionIteration"])
        self.assertFalse(report["ready"]["luaProcessConsoleExecHooks"])
        self.assertFalse(report["ready"]["luaLocalPlayerExecHooks"])
        self.assertFalse(report["ready"]["luaCallFunctionHooks"])
        self.assertFalse(report["ready"]["luaLifecycleHooks"])
        self.assertFalse(report["ready"]["luaObjectNotify"])
        self.assertFalse(report["ready"]["luaSyntheticOuter"])
        self.assertFalse(report["ready"]["luaWorldContext"])
        self.assertFalse(report["ready"]["luaClassDefaultObject"])
        self.assertFalse(report["ready"]["luaLevel"])
        self.assertFalse(report["ready"]["luaReflection"])
        self.assertFalse(report["ready"]["luaReflectionRawSet"])
        self.assertFalse(report["ready"]["luaReflectionNamedProperty"])
        self.assertFalse(report["ready"]["luaReflectionNumericPropertyValues"])
        self.assertFalse(report["ready"]["luaReflectionNameTextPropertyValues"])
        self.assertFalse(report["ready"]["luaReflectionArrayInnerProperty"])
        self.assertFalse(report["ready"]["luaReflectionEnumProperty"])
        self.assertFalse(report["ready"]["luaReflectionContainerProperties"])
        self.assertFalse(report["ready"]["luaReflectionImportText"])
        self.assertFalse(report["ready"]["luaReflectionExportText"])
        self.assertFalse(report["ready"]["luaReflectionPropertyMetadata"])
        self.assertFalse(report["ready"]["luaReflectionDescriptorValues"])
        self.assertFalse(report["ready"]["luaProcessEvent"])
        self.assertFalse(report["ready"]["ueProcessEventHookProbe"])
        self.assertFalse(report["ready"]["ueProcessEventLiveHook"])
        self.assertFalse(report["ready"]["ueProcessEventDispatch"])
        self.assertFalse(report["ready"]["ueProcessEventLiveLuaDispatch"])
        self.assertFalse(report["ready"]["ueProcessEventLiveParamValues"])
        self.assertFalse(report["ready"]["ueProcessEventLiveRawParamValues"])
        self.assertFalse(report["ready"]["ueProcessEventLiveContainerParamValues"])
        self.assertFalse(report["ready"]["ueProcessEventLiveContainerDataSamples"])
        self.assertFalse(report["ready"]["ueProcessEventLuaContextHandles"])
        self.assertFalse(report["ready"]["ueProcessEventLuaParamAccessors"])
        self.assertFalse(report["ready"]["ueProcessEventLuaScalarParamAccessors"])
        self.assertFalse(report["ready"]["ueProcessEventLuaNameStringParamAccessors"])
        self.assertFalse(report["ready"]["ueProcessEventLuaStructParamAccessors"])
        self.assertFalse(report["ready"]["ueProcessEventLuaHookRouting"])
        self.assertFalse(report["ready"]["luaMods"])
        self.assertFalse(report["ready"]["luaObjectRegistry"])
        self.assertFalse(report["ready"]["luaDecodedObjectAliases"])
        self.assertFalse(report["ready"]["ueObjectArrayRegistry"])
        self.assertFalse(report["ready"]["ueObjectInternalFlags"])
        self.assertFalse(report["ready"]["ueFNameDecoder"])
        self.assertFalse(report["ready"]["ueReflectionProbe"])
        self.assertFalse(report["ready"]["ueReflectionFieldWalk"])
        self.assertFalse(report["ready"]["ueReflectionPropertyDescriptors"])
        self.assertFalse(report["ready"]["ueFunctionParamDescriptors"])
        self.assertFalse(report["ready"]["ueFunctionParamContainerChildren"])
        self.assertFalse(report["ready"]["ueFunctionIdentities"])
        self.assertFalse(report["ready"]["ueFunctionFlags"])
        self.assertFalse(report["ready"]["ueReflectionPropertyValues"])
        self.assertFalse(report["ready"]["hooks"])
        self.assertFalse(report["ready"]["luaDispatch"])
        self.assertFalse(next(gate for gate in report["gates"] if gate["name"] == "ue-objects")["passed"])

    def test_resolved_anchor_signatures_satisfy_core_anchor_gates(self):
        with tempfile.TemporaryDirectory() as tmp:
            log = Path(tmp) / "signature-anchors.log"
            log.write_text(SIGNATURE_ANCHOR_LOG, encoding="utf-8")
            summary = readiness.summarize_log(log, ["win-client"], [], [])
            report = readiness.build_report([summary], [])

        self.assertTrue(next(gate for gate in report["gates"] if gate["name"] == "ue-names")["passed"])
        self.assertTrue(next(gate for gate in report["gates"] if gate["name"] == "ue-objects")["passed"])
        self.assertTrue(next(gate for gate in report["gates"] if gate["name"] == "ue-world")["passed"])
        self.assertTrue(next(gate for gate in report["gates"] if gate["name"] == "ue-dispatch")["passed"])
        self.assertTrue(next(gate for gate in report["gates"] if gate["name"] == "ue-reflection-surface")["passed"])
        self.assertFalse(report["ready"]["objectDiscovery"])
        self.assertFalse(report["ready"]["pointerProbe"])

    def test_opens_all_readiness_gates_with_core_anchors_and_promotable_signatures(self):
        validation = {
            "patternCount": 2,
            "promotableCount": 2,
            "statusCounts": {"unique-expected": 2},
        }
        with tempfile.TemporaryDirectory() as tmp:
            log = Path(tmp) / "ready.log"
            log.write_text(READY_LOG, encoding="utf-8")
            summary = readiness.summarize_log(log, ["win-client"], [], [])
            report = readiness.build_report([summary], [validation])

        self.assertTrue(report["ready"]["objectDiscovery"])
        self.assertTrue(report["ready"]["pointerProbe"])
        self.assertTrue(report["ready"]["layoutProbe"])
        self.assertTrue(report["ready"]["uobjectProbe"])
        self.assertTrue(report["ready"]["ueReflectionProbe"])
        self.assertTrue(report["ready"]["ueReflectionFieldWalk"])
        self.assertTrue(report["ready"]["ueReflectionPropertyDescriptors"])
        self.assertTrue(report["ready"]["ueFunctionParamDescriptors"])
        self.assertTrue(report["ready"]["ueFunctionParamContainerChildren"])
        self.assertTrue(report["ready"]["ueFunctionIdentities"])
        self.assertTrue(report["ready"]["ueFunctionFlags"])
        self.assertTrue(report["ready"]["ueReflectionPropertyValues"])
        self.assertTrue(report["ready"]["hookDispatch"])
        self.assertTrue(report["ready"]["modDispatch"])
        self.assertTrue(report["ready"]["luaRuntime"])
        self.assertTrue(report["ready"]["luaObjectApi"])
        self.assertTrue(report["ready"]["luaFunctionIteration"])
        self.assertTrue(report["ready"]["luaProcessConsoleExecHooks"])
        self.assertTrue(report["ready"]["luaLocalPlayerExecHooks"])
        self.assertTrue(report["ready"]["luaCallFunctionHooks"])
        self.assertTrue(report["ready"]["luaLifecycleHooks"])
        self.assertTrue(report["ready"]["luaObjectNotify"])
        self.assertTrue(report["ready"]["luaSyntheticOuter"])
        self.assertTrue(report["ready"]["luaWorldContext"])
        self.assertTrue(report["ready"]["luaClassDefaultObject"])
        self.assertTrue(report["ready"]["luaLevel"])
        self.assertTrue(report["ready"]["luaReflection"])
        self.assertTrue(report["ready"]["luaReflectionRawSet"])
        self.assertTrue(report["ready"]["luaReflectionNamedProperty"])
        self.assertTrue(report["ready"]["luaReflectionNumericPropertyValues"])
        self.assertTrue(report["ready"]["luaReflectionNameTextPropertyValues"])
        self.assertTrue(report["ready"]["luaReflectionArrayInnerProperty"])
        self.assertTrue(report["ready"]["luaReflectionEnumProperty"])
        self.assertTrue(report["ready"]["luaReflectionContainerProperties"])
        self.assertTrue(report["ready"]["luaReflectionImportText"])
        self.assertTrue(report["ready"]["luaReflectionExportText"])
        self.assertTrue(report["ready"]["luaReflectionPropertyMetadata"])
        self.assertTrue(report["ready"]["luaReflectionDescriptorValues"])
        self.assertTrue(report["ready"]["luaProcessEvent"])
        self.assertTrue(report["ready"]["ueProcessEventHookProbe"])
        self.assertTrue(report["ready"]["ueProcessEventLiveHook"])
        self.assertTrue(report["ready"]["ueProcessEventDispatch"])
        self.assertTrue(report["ready"]["ueProcessEventLiveLuaDispatch"])
        self.assertTrue(report["ready"]["ueProcessEventLiveContext"])
        self.assertTrue(report["ready"]["ueProcessEventLiveParamValues"])
        self.assertTrue(report["ready"]["ueProcessEventLiveRawParamValues"])
        self.assertTrue(report["ready"]["ueProcessEventLiveContainerParamValues"])
        self.assertTrue(report["ready"]["ueProcessEventLiveContainerDataSamples"])
        self.assertTrue(report["ready"]["ueProcessEventLuaContextHandles"])
        self.assertTrue(report["ready"]["ueProcessEventLuaParamAccessors"])
        self.assertTrue(report["ready"]["ueProcessEventLuaScalarParamAccessors"])
        self.assertTrue(report["ready"]["ueProcessEventLuaNameStringParamAccessors"])
        self.assertTrue(report["ready"]["ueProcessEventLuaStructParamAccessors"])
        self.assertTrue(report["ready"]["ueProcessEventLuaHookRouting"])
        self.assertTrue(report["ready"]["luaMods"])
        self.assertTrue(report["ready"]["luaObjectRegistry"])
        self.assertTrue(report["ready"]["luaDecodedObjectAliases"])
        self.assertTrue(report["ready"]["ueObjectArrayRegistry"])
        self.assertTrue(report["ready"]["ueObjectInternalFlags"])
        self.assertTrue(report["ready"]["ueFNameDecoder"])
        self.assertTrue(report["ready"]["hooks"])
        self.assertTrue(report["ready"]["reflection"])
        self.assertTrue(report["ready"]["luaDispatch"])

    def test_cli_json_output(self):
        with tempfile.TemporaryDirectory() as tmp:
            log = Path(tmp) / "partial.log"
            validation = Path(tmp) / "validation.json"
            log.write_text(PARTIAL_LOG, encoding="utf-8")
            validation.write_text(
                json.dumps({"patternCount": 1, "promotableCount": 1, "statusCounts": {"unique-unexpected": 1}}),
                encoding="utf-8",
            )
            result = subprocess.run(
                [
                    str(SCRIPT),
                    "--client-log",
                    str(log),
                    "--loader",
                    "win-client",
                    "--signature-validation-json",
                    str(validation),
                    "--format",
                    "json",
                ],
                cwd=ROOT,
                text=True,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                check=True,
            )

        report = json.loads(result.stdout)
        self.assertEqual(report["schemaVersion"], "ue4sslinux-ue4ss-port-readiness/v1")
        self.assertTrue(report["signatures"]["allPromotable"])
        self.assertFalse(report["signatures"]["exactOnly"])


if __name__ == "__main__":
    unittest.main()
