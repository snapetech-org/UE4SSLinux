#!/usr/bin/env bash
set -euo pipefail

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
repo_root="$(cd "$script_dir/.." && pwd)"
log="${UE4SSL_WIN_LUA_SMOKE_LOG:-/tmp/ue4ssl-win-client-probe-lua-smoke.log}"
loader="${UE4SSL_WINDOWS_PRELOAD:-$repo_root/build/windows-client-loader/ue4ssl_windows_proxy_loader.dll}"
lua_dll="${UE4SSL_WIN_LUA_DLL:-}"

if [ -z "$lua_dll" ]; then
  echo "UE4SSL_WIN_LUA_DLL must point at a real Windows Lua DLL, for example lua54.dll" >&2
  exit 2
fi
if [ ! -f "$lua_dll" ]; then
  echo "missing Windows Lua DLL: $lua_dll" >&2
  exit 2
fi
if ! command -v wine >/dev/null 2>&1; then
  echo "wine is required for the Windows client Lua smoke test" >&2
  exit 1
fi
if ! command -v winepath >/dev/null 2>&1; then
  echo "winepath is required for the Windows client Lua smoke test" >&2
  exit 1
fi

"$repo_root/scripts/build-windows-client-loader.sh" >/dev/null

rm -f "$log"
mod_root="$(mktemp -d)"
trap 'rm -rf "$mod_root"' EXIT
mkdir -p "$mod_root/CallbackMod/Scripts"
mkdir -p "$mod_root/CallbackModTwo/Scripts"
mkdir -p "$mod_root/CompatMod/Scripts"
printf "%s\n" "local o=FindObject('SelfTestObject'); local decoded=FindObject('SelfTestUObjectName_0'); local shaped=StaticFindObject(nil,nil,'SelfTestObject'); local all=GetKnownObjects(); local matches=FindObjects('UE4SSLProbeSelfTestClass'); local allOf=FindAllOf('UE4SSLProbeSelfTestClass'); local asset=LoadAsset('/Script/UE4SSLProbe.SelfTestObject'); local cls=o and o:GetClass(); local methodOk=o and cls and o:GetName()=='SelfTestObject' and o:GetPathName()==o.PathName and o:GetAddress()==o.Address and o:IsValid() and o:GetFullName()=='UE4SSLProbeSelfTestClass /Script/UE4SSLProbe.SelfTestObject' and o:type()=='UObject' and o:GetFName()=='SelfTestObject' and o:GetOuter()==nil and o:GetWorld()==nil and cls.Name=='UE4SSLProbeSelfTestClass' and cls.ClassName=='UClass' and cls:type()=='UClass' and not cls:IsValid() and o:HasAllFlags(0) and not o:HasAnyFlags(1) and not o:HasAnyInternalFlags(1); local async=0; ExecuteAsync(function() async=async+1 end); ExecuteWithDelay(1,function() async=async+1 end); local fn=FName('ModProbe'); local ft=FText('ModText'); local compatOk=async==2 and fn.Name=='ModProbe' and ft.Text=='ModText' and RegisterConsoleCommandHandler('probe',function() return true end); local seen=0; ForEachUObject(function(x) if x and IsA(x,'UE4SSLProbeSelfTestClass') then seen=seen+1 end end); local up,uq=RegisterHook('/Script/UE4SSLProbe.TempMod:Function',function()return -1 end,function()return -1 end); local unregOk=up and uq and uq==up+1; UnregisterHook('/Script/UE4SSLProbe.TempMod:Function',up,uq); if not (o and shaped and shaped.Address==o.Address and decoded and asset and asset.Address==o.Address and methodOk and compatOk and unregOk and decoded.PathName=='/RuntimeProbe/SelfTestUObjectName_0' and all and all.Count and all.Count >= 1 and all[o.PathName] and all[decoded.PathName] and matches and matches.Count and matches.Count >= 1 and allOf and allOf.Count and allOf.Count >= 1 and seen >= 1 and IsA(o,'UObject')) then error('missing object registry') end; local path='/RuntimeProbe/SelfTestUObject.SelfTestUObjectName_0:Function'; local f=FindFunction(path); local first=FindFirstFunction(); local known=GetKnownFunctions(); if not (f and first and known and known.Count and known.Count >= 1 and known[path] and known[path].Address == f.Address and f:GetName()=='SelfTestUObjectName_0' and f:type()=='UFunction') then error('missing function registry') end; RegisterHook('/Script/UE4SSLProbe.ModEntry:Function', function() return 11 end, function() return 31 end)" >"$mod_root/CallbackMod/Scripts/main.lua"
printf "%s\n" "local dcls=decoded and decoded:GetClass(); if not (decoded and decoded.ClassAddress and decoded.ClassAddress > 0 and dcls and dcls.Address==decoded.ClassAddress and dcls:IsValid() and dcls.ClassName=='UClass') then error('missing live class address') end" >>"$mod_root/CallbackMod/Scripts/main.lua"
printf "%s\n" "local dsuper=dcls and dcls:GetSuperStruct(); if not (dcls and dcls.SuperAddress and dcls.SuperAddress > 0 and dsuper and dsuper.Address==dcls.SuperAddress and dcls:IsChildOf(dsuper)) then error('missing live super chain') end" >>"$mod_root/CallbackMod/Scripts/main.lua"
printf "%s\n" "if not (decoded.HasObjectMetadata and decoded.ObjectFlags==17 and decoded.InternalIndex==7 and decoded.HasInternalFlags and decoded.InternalFlags==EInternalObjectFlags.Native and decoded:HasAllFlags(17) and decoded:HasAnyFlags(16) and not decoded:HasAnyFlags(32) and decoded:HasAnyInternalFlags(EInternalObjectFlags.Native) and not decoded:HasAnyInternalFlags(1)) then error('missing live object flags') end" >>"$mod_root/CallbackMod/Scripts/main.lua"
printf "%s\n" "if not (f and f.HasFunctionFlags and f.FunctionFlags==1024 and f:GetFunctionFlags()==1024) then error('missing live function flags') end" >>"$mod_root/CallbackMod/Scripts/main.lua"
printf "%s\n" "RegisterHook('/Script/UE4SSLProbe.ModEntry:Function', function() return 11 end, function() return 31 end)" >"$mod_root/CallbackModTwo/Scripts/main.lua"
printf "%s\n" "local major,minor,hotfix=UE4SS.GetVersion(); ModRef:SetSharedVariable('probe-string','ok'); ModRef:SetSharedVariable('probe-number',42); ModRef:SetSharedVariable('probe-bool',true); local dirs=IterateGameDirectories(); local fname=FName('CompatProbe'); local custom=RegisterCustomProperty({Name='ProbeProperty',Type={IntProperty=PropertyTypes.IntProperty},BelongsToClass='/Script/UE4SSLProbe.SelfTestObject',OffsetInternal=0}); local compatOk=major==3 and minor==0 and hotfix==0 and UnrealVersion:GetMajor()>=4 and UnrealVersion:IsAtLeast(4,27) and custom and RegisterConsoleCommandHandler('probe',function() return true end) and RegisterConsoleCommandGlobalHandler('probe_global',function() return false end) and EObjectFlags.RF_NoFlags==0 and EObjectFlags.RF_ClassDefaultObject and EInternalObjectFlags.Native and PropertyTypes.IntProperty=='IntProperty' and Key.O and ModifierKey.CONTROL and dirs and dirs.Game and dirs.Game.Binaries and dirs.Game.Binaries.Win64 and ModRef:GetSharedVariable('probe-string')=='ok' and ModRef:GetSharedVariable('probe-number')==42 and ModRef:GetSharedVariable('probe-bool')==true and ModRef:type()=='ModRef' and fname:ToString()=='CompatProbe' and fname:GetComparisonIndex()==0; local o=FindObject('SelfTestObject'); local f=FindFunction('/RuntimeProbe/SelfTestUObject.SelfTestUObjectName_0:Function'); local cls=o and o:GetClass(); local cdo=cls and cls:GetCDO(); local r=o and o:Reflection(); local p=r and r:GetProperty('ProbeValue'); local bp=r and r:GetProperty('ProbeBool'); local fp=f and f:Reflection():GetProperty('Value'); local seenProps=0; if o then o:ForEachProperty(function(prop) if prop and prop:GetFName():ToString()=='ProbeValue' and prop:IsA(PropertyTypes.IntProperty) and prop:ContainerPtrToValuePtr(o)>0 then seenProps=seenProps+1 end end) end; local fProps=0; if f then f:ForEachProperty(function(prop) if prop and prop.IsParm then fProps=fProps+1 end end) end; local oldFlags=f and f:GetFunctionFlags(); local setFlagsOk=f and oldFlags==1024 and f:SetFunctionFlags(2048)==nil and f:GetFunctionFlags()==2048 and f.HasFunctionFlags==true and f.FunctionFlags==2048 and f:SetFunctionFlags(oldFlags)==nil and f:GetFunctionFlags()==oldFlags and f.FunctionFlags==oldFlags; compatOk=compatOk and o and f and cls and setFlagsOk and o:ProcessConsoleExec('probe',nil,o)==true and cdo and cdo:HasAllFlags(EObjectFlags.RF_ClassDefaultObject) and cdo:GetClass():GetName()==cls:GetName() and (cls:GetSuperStruct() and cls:GetSuperStruct():GetName()=='UObject') and not cls:IsChildOf('Missing') and r and r:type()=='UObjectReflection' and p and p:GetFullName():find('ProbeValue',1,true) and p:GetFName():ToString()=='ProbeValue' and p:IsA(PropertyTypes.IntProperty) and p:type()=='FIntProperty' and p:GetClass():GetName()=='FIntProperty' and p:ContainerPtrToValuePtr(o)>0 and bp and bp:GetByteMask()==1 and bp:GetFieldSize()>=1 and fp and fp.IsParm and fp:GetFName():ToString()=='Value' and seenProps>=1 and fProps>=1; if not compatOk then error('missing ue4ss compatibility globals') end" >"$mod_root/CompatMod/Scripts/main.lua"
printf "%s\n" "local o=FindObject('SelfTestObject'); local r=o and o:Reflection(); local pf=r and r:GetProperty('ProbeFloat'); local pd=r and r:GetProperty('ProbeDouble'); local seenFloat=0; local seenDouble=0; if o then o:ForEachProperty(function(prop) if prop and prop:GetFName():ToString()=='ProbeFloat' and prop:IsA(PropertyTypes.FloatProperty) then seenFloat=seenFloat+1 end; if prop and prop:GetFName():ToString()=='ProbeDouble' and prop:IsA(PropertyTypes.DoubleProperty) then seenDouble=seenDouble+1 end end) end; if not (pf and pf:type()=='FFloatProperty' and pf:GetClass():GetName()=='FFloatProperty' and pf:IsA(PropertyTypes.FloatProperty) and pf:ContainerPtrToValuePtr(o)>0 and pd and pd:type()=='FDoubleProperty' and pd:GetClass():GetName()=='FDoubleProperty' and pd:IsA(PropertyTypes.DoubleProperty) and pd:ContainerPtrToValuePtr(o)>0 and seenFloat>=1 and seenDouble>=1) then error('missing numeric reflection descriptors') end" >>"$mod_root/CompatMod/Scripts/main.lua"
printf "%s\n" "local pn=r and r:GetProperty('ProbeName'); local pt=r and r:GetProperty('ProbeText'); local seenName=0; local seenText=0; if o then o:ForEachProperty(function(prop) if prop and prop:GetFName():ToString()=='ProbeName' and prop:IsA(PropertyTypes.NameProperty) then seenName=seenName+1 end; if prop and prop:GetFName():ToString()=='ProbeText' and prop:IsA(PropertyTypes.TextProperty) then seenText=seenText+1 end end) end; if not (pn and pn:type()=='FNameProperty' and pn:GetClass():GetName()=='FNameProperty' and pn:IsA(PropertyTypes.NameProperty) and pn:ContainerPtrToValuePtr(o)>0 and pt and pt:type()=='FTextProperty' and pt:GetClass():GetName()=='FTextProperty' and pt:IsA(PropertyTypes.TextProperty) and pt:ContainerPtrToValuePtr(o)>0 and seenName>=1 and seenText>=1) then error('missing name/text reflection descriptors') end" >>"$mod_root/CompatMod/Scripts/main.lua"
printf "%s\n" "local handled=RegisterConsoleCommandHandler('probe_args', function(ctx, command, args) return ctx and ctx.Name=='SelfTestObject' and command=='probe_args' and args=='spice flow' end); if not (handled and o and o:ProcessConsoleExec('probe_args spice flow',nil,o) and not o:ProcessConsoleExec('missing_probe',nil,o)) then error('missing ProcessConsoleExec dispatch') end" >>"$mod_root/CompatMod/Scripts/main.lua"
printf "%s\n" "local preCount=0; local postCount=0; local preId=RegisterProcessConsoleExecPreHook(function(ctx, raw, command, args, handled) if ctx and ctx.Name=='SelfTestObject' and raw=='preprobe spice' and command=='preprobe' and args=='spice' and not handled then preCount=preCount+1; return true end return false end); local postId=RegisterProcessConsoleExecPostHook(function(ctx, raw, command, args, handled) if ctx and ctx.Name=='SelfTestObject' and raw=='probe_args spice flow' and command=='probe_args' and args=='spice flow' and handled then postCount=postCount+1; return true end return false end); if not (preId and postId and o and o:ProcessConsoleExec('preprobe spice',nil,o) and o:ProcessConsoleExec('probe_args spice flow',nil,o) and preCount==1 and postCount==1) then error('missing ProcessConsoleExec hooks') end" >>"$mod_root/CompatMod/Scripts/main.lua"
printf "%s\n" "local lpPre=0; local lpPost=0; local lpPreId=RegisterULocalPlayerExecPreHook(function(ctx, raw, command, args, handled) if ctx and ctx.Name=='SelfTestObject' and raw=='localpre spice' and command=='localpre' and args=='spice' and not handled then lpPre=lpPre+1; return true end return false end); local lpPostId=RegisterULocalPlayerExecPostHook(function(ctx, raw, command, args, handled) if ctx and ctx.Name=='SelfTestObject' and raw=='localpost flow' and command=='localpost' and args=='flow' and not handled then lpPost=lpPost+1; return true end return false end); if not (lpPreId and lpPostId and o and o:ULocalPlayerExec('localpre spice') and ULocalPlayerExec(o,'localpost flow') and lpPre==1 and lpPost==1) then error('missing ULocalPlayerExec hooks') end" >>"$mod_root/CompatMod/Scripts/main.lua"
printf "%s\n" "local callPre=0; local callPost=0; local callPreId=RegisterCallFunctionByNameWithArgumentsPreHook(function(ctx, name, args, handled, result) if ctx and ctx.Name=='SelfTestObject' and name=='HookedProbe' and args=='spice' and not handled and result==nil then callPre=callPre+1; return 77,true end return nil,false end); local callPostId=RegisterCallFunctionByNameWithArgumentsPostHook(function(ctx, name, args, handled, result) if ctx and ctx.Name=='SelfTestObject' and name=='DoubleProbeValue' and args=='flow' and handled and result==14 then callPost=callPost+1; return 84,true end return result,false end); if not (callPreId and callPostId and o and o:CallFunction('HookedProbe','spice')==77 and o:CallFunction('DoubleProbeValue','flow')==84 and callPre==1 and callPost==1) then error('missing CallFunctionByNameWithArguments hooks') end" >>"$mod_root/CompatMod/Scripts/main.lua"
printf "%s\n" "local ce=0; local ceId=RegisterCustomEvent('probe.lifecycle',function(ctx,event,payload,handled) if ctx and ctx.Name=='SelfTestObject' and event=='probe.lifecycle' and payload=='payload' and not handled then ce=ce+1; return true end return false end); local lmPre,lmPost,bpPre,bpPost,gsPre,gsPost=0,0,0,0,0,0; local lmPreId=RegisterLoadMapPreHook(function(ctx,event,payload,handled) if ctx and ctx.Name=='SelfTestObject' and event=='LoadMap' and payload=='arrakis' and not handled then lmPre=lmPre+1; return true end return false end); local lmPostId=RegisterLoadMapPostHook(function(ctx,event,payload,handled) if ctx and ctx.Name=='SelfTestObject' and event=='LoadMap' and payload=='arrakis' and handled then lmPost=lmPost+1; return true end return false end); local bpPreId=RegisterBeginPlayPreHook(function(ctx,event,payload,handled) if ctx and ctx.Name=='SelfTestObject' and event=='BeginPlay' and payload=='actor' and not handled then bpPre=bpPre+1; return true end return false end); local bpPostId=RegisterBeginPlayPostHook(function(ctx,event,payload,handled) if ctx and ctx.Name=='SelfTestObject' and event=='BeginPlay' and payload=='actor' and handled then bpPost=bpPost+1; return true end return false end); local gsPreId=RegisterInitGameStatePreHook(function(ctx,event,payload,handled) if ctx and ctx.Name=='SelfTestObject' and event=='InitGameState' and payload=='game' and not handled then gsPre=gsPre+1; return true end return false end); local gsPostId=RegisterInitGameStatePostHook(function(ctx,event,payload,handled) if ctx and ctx.Name=='SelfTestObject' and event=='InitGameState' and payload=='game' and handled then gsPost=gsPost+1; return true end return false end); if not (ceId and UE4SSLProbeDispatchCustomEvent('probe.lifecycle',o,'payload') and ce==1 and lmPreId and lmPostId and UE4SSLProbeLoadMap(o,'arrakis') and lmPre==1 and lmPost==1 and bpPreId and bpPostId and UE4SSLProbeBeginPlay(o,'actor') and bpPre==1 and bpPost==1 and gsPreId and gsPostId and UE4SSLProbeInitGameState(o,'game') and gsPre==1 and gsPost==1) then error('missing lifecycle/custom event hooks') end" >>"$mod_root/CompatMod/Scripts/main.lua"
printf "%s\n" "local seenFns=0; if o then o:ForEachFunction(function(fn) if fn and fn:GetName()=='SelfTestUObjectName_0' and fn:type()=='UFunction' then seenFns=seenFns+1 end end) end; local clsFns=0; if cls and f then cls:ForEachFunction(function(fn) if fn and fn.Address==f.Address then clsFns=clsFns+1; return true end end) end; if not (seenFns>=1 and clsFns>=1) then error('missing ForEachFunction registry') end" >>"$mod_root/CompatMod/Scripts/main.lua"
printf "%s\n" "local o=FindObject('SelfTestObject'); local cls=o and o:GetClass(); if not (cls and cls:IsChildOf('UE4SSLProbeSelfTestClass') and cls:IsChildOf('/Script/CoreUObject.Object') and cls:IsChildOf(cls) and not cls:IsChildOf('UClass') and not cls:IsChildOf('Missing')) then error('missing IsChildOf compatibility') end" >>"$mod_root/CompatMod/Scripts/main.lua"
printf "%s\n" "local notifyHit=0; local notifySecond=0; local notifyMiss=0; NotifyOnNewObject('UE4SSLProbeSelfTestClass', function(x) if x and x.Name=='NotifyConstructedProbe' then notifyHit=notifyHit+1; return 17 end end); NotifyOnNewObject('/RuntimeProbe/Constructed/NotifyConstructedProbe', function(x) if x and x.Name=='NotifyConstructedProbe' then notifySecond=notifySecond+1; return 19 end end); NotifyOnNewObject('MissingNotifyClass', function(x) notifyMiss=notifyMiss+1; return -99 end); local nc=StaticConstructObject(cls,o,'NotifyConstructedProbe'); local nco=nc and nc:GetOuter(); if not (nc and nc.Name=='NotifyConstructedProbe' and nco and nco.Address==o.Address and nc.OuterAddress==o.Address and nc.ClassAddress==cls.Address and notifyHit==1 and notifySecond==1 and notifyMiss==0) then error('missing NotifyOnNewObject dispatch') end" >>"$mod_root/CompatMod/Scripts/main.lua"
printf "%s\n" "local world=StaticConstructObject({ClassName='UWorld',Name='SelfTestWorld'},nil,'SelfTestWorld'); local level=StaticConstructObject({ClassName='ULevel',Name='PersistentLevel'},world,'PersistentLevel'); local actor=StaticConstructObject({ClassName='AActor',Name='LevelChildProbe'},level,'LevelChildProbe'); local ww=world and world:GetWorld(); local aw=actor and actor:GetWorld(); local al=actor and actor:GetLevel(); local ll=level and level:GetLevel(); if not (ww and ww.Address==world.Address and aw and aw.Address==world.Address and al and al.Address==level.Address and ll and ll.Address==level.Address) then error('missing GetWorld/GetLevel world-context dispatch') end" >>"$mod_root/CompatMod/Scripts/main.lua"

dll_win="$(WINEDEBUG=-all winepath -w "$loader" 2>/dev/null)"
log_win="$(WINEDEBUG=-all winepath -w "$log" 2>/dev/null)"
lua_dll_win="$(WINEDEBUG=-all winepath -w "$lua_dll" 2>/dev/null)"
mod_root_win="$(WINEDEBUG=-all winepath -w "$mod_root" 2>/dev/null)"

WINEDEBUG=-all \
UE4SSL_WIN_LOG="$log_win" \
UE4SSL_WIN_AUTO_THREAD=false \
UE4SSL_WIN_SNAPSHOT_DELAY_SECONDS=0 \
UE4SSL_WIN_SCAN_ENABLED=false \
UE4SSL_WIN_LOG_MODULES=false \
UE4SSL_WIN_UE_REFLECTION_PROBE=true \
UE4SSL_WIN_UE_REFLECTION_FIELD_WALK=true \
UE4SSL_WIN_UE_REFLECTION_PROPERTY_PROBE=true \
UE4SSL_WIN_UE_REFLECTION_VALUE_PROBE=true \
UE4SSL_WIN_UE_OBJECT_ARRAY_PROBE=true \
UE4SSL_WIN_UE_OBJECT_ARRAY_MAX_OBJECTS=4 \
UE4SSL_WIN_UE_FNAME_PROBE=true \
UE4SSL_WIN_UE_SELF_TEST_ANCHOR=true \
UE4SSL_WIN_HOOK_SELF_TEST=true \
UE4SSL_WIN_MOD_SELF_TEST=true \
UE4SSL_WIN_LUA_SELF_TEST=true \
UE4SSL_WIN_LUA_DLL="$lua_dll_win" \
UE4SSL_WIN_LUA_REFLECTION_SELF_TEST=true \
UE4SSL_WIN_LUA_REFLECTION_RAW_SET_ENABLED=true \
UE4SSL_WIN_LUA_PROCESS_EVENT_SELF_TEST=true \
UE4SSL_WIN_UE_PROCESS_EVENT_LIVE_HOOK=true \
UE4SSL_WIN_UE_PROCESS_EVENT_LIVE_HOOK_SELF_TEST_TARGET=true \
UE4SSL_WIN_UE_PROCESS_EVENT_LIVE_HOOK_CALL_SELF_TEST=true \
UE4SSL_WIN_UE_PROCESS_EVENT_LIVE_HOOK_LOG_CALLS=true \
UE4SSL_WIN_UE_PROCESS_EVENT_LIVE_HOOK_CALL_LOG_LIMIT=2 \
UE4SSL_WIN_UE_PROCESS_EVENT_DISPATCH_SELF_TEST=true \
UE4SSL_WIN_UE_PROCESS_EVENT_LIVE_LUA_DISPATCH=true \
UE4SSL_WIN_LUA_MODS_ENABLED=true \
UE4SSL_WIN_LUA_MOD_ROOT="$mod_root_win" \
UE4SSL_WIN_LUA_MOD_DISPATCH_SELF_TEST=true \
  wine rundll32.exe "$dll_win,UE4SSLWinProbeSmoke" >/tmp/ue4ssl-win-client-probe-lua-smoke.out 2>&1

require_log() {
  local pattern="$1"
  if ! grep -q "$pattern" "$log"; then
    echo "missing expected Windows client Lua smoke log pattern: $pattern" >&2
    sed -n '1,220p' "$log" >&2 || true
    sed -n '1,160p' /tmp/ue4ssl-win-client-probe-lua-smoke.out >&2 || true
    exit 1
  fi
}

require_log 'event=lua-dispatch-self-test phase=smoke status=passed'
require_log 'event=lua-dispatch-self-test .*loadStatus=0 callStatus=0 callbackStatus=0 result=42 isNumber=true'
require_log 'event=lua-dispatch-self-test .*objectHandles=4 ueObjectHandles=2'
require_log 'event=lua-dispatch-self-test .*staticFindObjectCalls=1 staticFindObjectHits=1 findObjectCalls=1 findObjectHits=1 findFirstOfCalls=1 findFirstOfHits=1 getKnownObjectsCalls=1 getKnownObjectsHits=1 findObjectsCalls=1 findObjectsHits=1 findAllOfCalls=1 findAllOfHits=1 forEachUObjectCalls=1 forEachUObjectCallbacks=[1-9][0-9]* forEachFunctionCalls=0 forEachFunctionCallbacks=0 isACalls=[1-9][0-9]* isAHits=[1-9][0-9]* loadAssetCalls=1 loadAssetHits=1 staticConstructObjectCalls=1 staticConstructObjectHits=1'
require_log 'event=lua-reflection-self-test phase=smoke status=passed'
require_log 'event=ue-reflection-value name=SelfTestUObject chain=propertyLink index=0 fieldName=SelfTestUObjectName_0 status=read .*offsetInternal=12 elementSize=4 arrayDim=1 .*readBytes=4 raw=07000000 rawLe=0x7'
require_log 'event=lua-object-registry source=ue-object-array-fname status=added name=SelfTestUObjectName_0 path=/RuntimeProbe/SelfTestUObjectName_0 aliasOf=SelfTestObjectArray_0 class=UObjectArrayItem'
require_log 'event=lua-reflection-self-test .*result=42 isNumber=true staticFindObjectCalls=2 staticFindObjectHits=[1-9][0-9]*'
require_log 'event=lua-reflection-self-test .*getPropertyCalls=20 getPropertyHits=20 rawPropertyHits=2 rawPropertyValue=17 namedPropertyHits=2 rawPropertySetHits=1 rawPropertySetValue=17 arrayInnerPropertyHits=1 enumPropertyHits=1 enumUnderlyingPropertyHits=1 setElementPropertyHits=1 mapKeyPropertyHits=1 mapValuePropertyHits=1 importTextHits=1 exportTextHits=1 propertyMetadataHits=7 descriptorValueGetHits=16 descriptorValueSetHits=8 setPropertyCalls=9 setPropertyHits=9 callFunctionCalls=2 callFunctionHits=2 probeValue=21 probeBool=false probeFloat=13.750 probeDouble=-47.500 probeName=ArrakisName probeString=melange probeText=WaterDebt probeObject=0x'
require_log 'event=lua-process-event-self-test phase=smoke status=passed'
require_log 'event=lua-process-event-self-test .*result=4 isNumber=true hooks=2 hook=/Script/UE4SSLProbe.SelfTest:Function'
require_log 'event=lua-process-event-self-test .*installed=true restored=true hookCalls=1 originalCalls=2 originalAfterHook=1'
require_log 'event=lua-process-event-self-test .*paramDescriptorHits=2 paramDescriptorLookupCalls=13 paramDescriptorLookupHits=13 functionParamDescriptorCalls=2 functionParamDescriptorHits=2 paramGetCalls=21 paramGetHits=21 paramSetCalls=7 paramSetHits=7'
require_log 'event=ue-process-event-dispatch-self-test phase=smoke status=armed .*callbacks=2'
require_log 'event=ue-process-event-live-lua-dispatch phase=smoke status=armed .*result=4 isNumber=true hooks=2 hook=/Script/UE4SSLProbe.LiveProcessEvent:Function callbacks=4'
require_log 'event=ue-process-event-live-hook-call status=returned call=1 originalCalled=true preCallbacks=2 postCallbacks=2'
require_log 'event=ue-process-event-live-hook phase=smoke status=installed .*selfTestTarget=true callSelfTest=true dispatchCallbacks=4 luaDispatch=true luaPreStatus=0 luaPostStatus=0 luaPreCalls=1 luaPostCalls=1 luaObjectHandleHits=2 luaFunctionHandleHits=2 luaParamsHandleHits=2 luaParamDescriptorHits=2 luaParamDescriptorLookupCalls=13 luaParamDescriptorLookupHits=13 luaFunctionParamDescriptorCalls=2 luaFunctionParamDescriptorHits=2 luaParamGetCalls=21 luaParamGetHits=21 luaParamSetCalls=7 luaParamSetHits=7 preCallbacks=2 postCallbacks=2 liveCalls=1 originalCalls=1 paramsResult=62 paramsTouched=1'
require_log 'event=ue-process-event-live-hook phase=detach status=restored .*liveCalls=1 originalCalls=1'
require_log 'event=ue-process-event-live-lua-dispatch phase=detach status=closed preCalls=1 postCalls=1 preResult=11 postResult=31 preStatus=0 postStatus=0'
require_log 'event=lua-mod-script phase=smoke status=passed name=CallbackMod'
require_log 'event=lua-mod-script phase=smoke status=passed name=CallbackModTwo'
require_log 'event=lua-mod-script phase=smoke status=passed name=CompatMod'
require_log 'event=lua-mod-script .*hooksAfter=1'
require_log 'event=lua-mod-script .*hooksAfter=2'
require_log 'event=lua-mod-dispatch-self-test phase=smoke status=passed callbackStatus=0 hooks=2 hook=/Script/UE4SSLProbe.ModEntry:Function'
require_log 'event=lua-mod-dispatch-self-test .*preCalls=2 postCalls=2 preResult=11 postResult=31 preIsNumber=true postIsNumber=true'
require_log 'event=lua-mod-finish phase=smoke status=passed .*scripts=3 loaded=3 failed=0 hooks=2'
require_log 'event=lua-mod-finish .*customEvents=1 customEventCalls=1 customEventHandled=1 loadMapPreHooks=1 loadMapPostHooks=1 loadMapPreCalls=1 loadMapPostCalls=1 loadMapPreHandled=1 loadMapPostHandled=1 beginPlayPreHooks=1 beginPlayPostHooks=1 beginPlayPreCalls=1 beginPlayPostCalls=1 beginPlayPreHandled=1 beginPlayPostHandled=1 initGameStatePreHooks=1 initGameStatePostHooks=1 initGameStatePreCalls=1 initGameStatePostCalls=1 initGameStatePreHandled=1 initGameStatePostHandled=1'
require_log 'event=lua-mod-finish .*processConsoleExecPreHooks=1 processConsoleExecPostHooks=1 processConsoleExecPreCalls=2 processConsoleExecPostCalls=2 processConsoleExecPreHandled=1 processConsoleExecPostHandled=1 localPlayerExecPreHooks=1 localPlayerExecPostHooks=1 localPlayerExecPreCalls=2 localPlayerExecPostCalls=2 localPlayerExecPreHandled=1 localPlayerExecPostHandled=1 callFunctionPreHooks=1 callFunctionPostHooks=1 callFunctionPreCalls=2 callFunctionPostCalls=1 callFunctionPreHandled=1 callFunctionPostHandled=1'
require_log 'event=lua-mod-finish .*findObjectCalls=5 findObjectHits=5 .*getKnownObjectsCalls=1 getKnownObjectsHits=1 findObjectsCalls=1 findObjectsHits=1 findAllOfCalls=1 findAllOfHits=1 forEachUObjectCalls=1 forEachUObjectCallbacks=[1-9][0-9]* forEachFunctionCalls=2 forEachFunctionCallbacks=2 isACalls=[1-9][0-9]* isAHits=[1-9][0-9]* loadAssetCalls=1 loadAssetHits=1'
require_log 'event=lua-mod-finish .*staticConstructObjectCalls=[3-9][0-9]* staticConstructObjectHits=[3-9][0-9]* notifyOnNewObjectCalls=3 .*notifyOnNewObjectCallbacks=2 notifyOnNewObjectResult=19 notifyOnNewObjectIsNumber=true notifyOnNewObjectStatus=0'
require_log 'event=lua-mod-finish .*staticConstructObjectOuterHits=[2-9][0-9]*'
require_log 'event=lua-mod-finish .*getWorldCalls=[2-9][0-9]* getWorldHits=[2-9][0-9]*'
require_log 'event=lua-mod-finish .*getCdoCalls=[1-9][0-9]* getCdoHits=[1-9][0-9]* getLevelCalls=[2-9][0-9]* getLevelHits=[2-9][0-9]*'

printf 'Windows client Lua smoke passed: %s\n' "$log"
