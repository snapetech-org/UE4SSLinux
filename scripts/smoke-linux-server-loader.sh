#!/usr/bin/env bash
set -euo pipefail

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
repo_root="$(cd "$script_dir/.." && pwd)"
log="${UE4SSL_SERVER_SMOKE_LOG:-/tmp/ue4ssl-server-smoke.log}"
target="${UE4SSL_SERVER_SMOKE_TARGET:-/usr/bin/true}"

"$repo_root/scripts/build-linux-server-loader.sh" >/dev/null

rm -f "$log"
signature_file="$(mktemp)"
mod_script="$(mktemp)"
mod_script_two="$(mktemp)"
mod_script_compat="$(mktemp)"
trap 'rm -f "$signature_file" "$mod_script" "$mod_script_two" "$mod_script_compat"' EXIT
printf 'elf-file=7f 45 4c 46\n' >"$signature_file"
printf "%s\n" "local o=FindObject('SelfTestObject'); local decoded=FindObject('SelfTestUObjectName_0'); local shaped=StaticFindObject(nil,nil,'SelfTestObject'); local all=GetKnownObjects(); local matches=FindObjects('UE4SSLServerProbeSelfTestClass'); local allOf=FindAllOf('UE4SSLServerProbeSelfTestClass'); local asset=LoadAsset('/Script/UE4SSLServerProbe.SelfTestObject'); local cls=o and o:GetClass(); local methodOk=o and cls and o:GetName()=='SelfTestObject' and o:GetPathName()==o.PathName and o:GetAddress()==o.Address and o:IsValid() and o:GetFullName()=='UE4SSLServerProbeSelfTestClass /Script/UE4SSLServerProbe.SelfTestObject' and o:type()=='UObject' and o:GetFName()=='SelfTestObject' and o:GetOuter()==nil and o:GetWorld()==nil and cls.Name=='UE4SSLServerProbeSelfTestClass' and cls.ClassName=='UClass' and cls:type()=='UClass' and not cls:IsValid() and o:HasAllFlags(0) and not o:HasAnyFlags(1) and not o:HasAnyInternalFlags(1); local async=0; ExecuteAsync(function() async=async+1 end); ExecuteWithDelay(1,function() async=async+1 end); local fn=FName('ModProbe'); local ft=FText('ModText'); local compatOk=async==2 and fn.Name=='ModProbe' and ft.Text=='ModText' and RegisterConsoleCommandHandler('probe',function() return true end); local seen=0; ForEachUObject(function(x) if x and IsA(x,'UE4SSLServerProbeSelfTestClass') then seen=seen+1 end end); local up,uq=RegisterHook('/Script/UE4SSLServerProbe.TempMod:Function',function()return -1 end,function()return -1 end); local unregOk=up and uq and uq==up+1; UnregisterHook('/Script/UE4SSLServerProbe.TempMod:Function',up,uq); if not (o and shaped and shaped.Address==o.Address and decoded and asset and asset.Address==o.Address and methodOk and compatOk and unregOk and decoded.PathName=='/RuntimeProbe/SelfTestUObjectName_0' and all and all.Count and all.Count >= 1 and all[o.PathName] and all[decoded.PathName] and matches and matches.Count and matches.Count >= 1 and allOf and allOf.Count and allOf.Count >= 1 and seen >= 1 and IsA(o,'UObject')) then error('missing object registry') end; local path='/RuntimeProbe/SelfTestUObject.SelfTestUObjectName_0:Function'; local f=FindFunction(path); local first=FindFirstFunction(); local known=GetKnownFunctions(); if not (f and first and known and known.Count and known.Count >= 1 and known[path] and known[path].Address == f.Address and f:GetName()=='SelfTestUObjectName_0' and f:type()=='UFunction') then error('missing function registry') end; RegisterHook('/Script/UE4SSLServerProbe.ModEntry:Function', function() return 11 end, function() return 31 end)" >"$mod_script"
printf "%s\n" "local dcls=decoded and decoded:GetClass(); if not (decoded and decoded.ClassAddress and decoded.ClassAddress > 0 and dcls and dcls.Address==decoded.ClassAddress and dcls:IsValid() and dcls.ClassName=='UClass') then error('missing live class address') end" >>"$mod_script"
printf "%s\n" "local dsuper=dcls and dcls:GetSuperStruct(); if not (dcls and dcls.SuperAddress and dcls.SuperAddress > 0 and dsuper and dsuper.Address==dcls.SuperAddress and dcls:IsChildOf(dsuper)) then error('missing live super chain') end" >>"$mod_script"
printf "%s\n" "if not (decoded.HasObjectMetadata and decoded.ObjectFlags==17 and decoded.InternalIndex==7 and decoded.HasInternalFlags and decoded.InternalFlags==EInternalObjectFlags.Native and decoded:HasAllFlags(17) and decoded:HasAnyFlags(16) and not decoded:HasAnyFlags(32) and decoded:HasAnyInternalFlags(EInternalObjectFlags.Native) and not decoded:HasAnyInternalFlags(1)) then error('missing live object flags') end" >>"$mod_script"
printf "%s\n" "if not (f and f.HasFunctionFlags and f.FunctionFlags==1024 and f:GetFunctionFlags()==1024) then error('missing live function flags') end" >>"$mod_script"
printf "%s\n" "RegisterHook('/Script/UE4SSLServerProbe.ModEntry:Function', function() return 11 end, function() return 31 end)" >"$mod_script_two"
printf "%s\n" "local major,minor,hotfix=UE4SS.GetVersion(); ModRef:SetSharedVariable('probe-string','ok'); ModRef:SetSharedVariable('probe-number',42); ModRef:SetSharedVariable('probe-bool',true); local dirs=IterateGameDirectories(); local fname=FName('CompatProbe'); local custom=RegisterCustomProperty({Name='ProbeProperty',Type={IntProperty=PropertyTypes.IntProperty},BelongsToClass='/Script/UE4SSLServerProbe.SelfTestObject',OffsetInternal=0}); local compatOk=major==3 and minor==0 and hotfix==0 and UnrealVersion:GetMajor()>=4 and UnrealVersion:IsAtLeast(4,27) and custom and RegisterConsoleCommandHandler('probe',function() return true end) and RegisterConsoleCommandGlobalHandler('probe_global',function() return false end) and EObjectFlags.RF_NoFlags==0 and EObjectFlags.RF_ClassDefaultObject and EInternalObjectFlags.Native and PropertyTypes.IntProperty=='IntProperty' and Key.O and ModifierKey.CONTROL and dirs and dirs.Game and dirs.Game.Binaries and dirs.Game.Binaries.Win64 and ModRef:GetSharedVariable('probe-string')=='ok' and ModRef:GetSharedVariable('probe-number')==42 and ModRef:GetSharedVariable('probe-bool')==true and ModRef:type()=='ModRef' and fname:ToString()=='CompatProbe' and fname:GetComparisonIndex()==0; local o=FindObject('SelfTestObject'); local f=FindFunction('/RuntimeProbe/SelfTestUObject.SelfTestUObjectName_0:Function'); local cls=o and o:GetClass(); local cdo=cls and cls:GetCDO(); local r=o and o:Reflection(); local p=r and r:GetProperty('ProbeValue'); local bp=r and r:GetProperty('ProbeBool'); local fp=f and f:Reflection():GetProperty('Value'); local seenProps=0; if o then o:ForEachProperty(function(prop) if prop and prop:GetFName():ToString()=='ProbeValue' and prop:IsA(PropertyTypes.IntProperty) and prop:ContainerPtrToValuePtr(o)>0 then seenProps=seenProps+1 end end) end; local fProps=0; if f then f:ForEachProperty(function(prop) if prop and prop.IsParm then fProps=fProps+1 end end) end; local oldFlags=f and f:GetFunctionFlags(); local setFlagsOk=f and oldFlags==1024 and f:SetFunctionFlags(2048)==nil and f:GetFunctionFlags()==2048 and f.HasFunctionFlags==true and f.FunctionFlags==2048 and f:SetFunctionFlags(oldFlags)==nil and f:GetFunctionFlags()==oldFlags and f.FunctionFlags==oldFlags; compatOk=compatOk and o and f and cls and setFlagsOk and o:ProcessConsoleExec('probe',nil,o)==true and cdo and cdo:HasAllFlags(EObjectFlags.RF_ClassDefaultObject) and cdo:GetClass():GetName()==cls:GetName() and (cls:GetSuperStruct() and cls:GetSuperStruct():GetName()=='UObject') and not cls:IsChildOf('Missing') and r and r:type()=='UObjectReflection' and p and p:GetFullName():find('ProbeValue',1,true) and p:GetFName():ToString()=='ProbeValue' and p:IsA(PropertyTypes.IntProperty) and p:type()=='FIntProperty' and p:GetClass():GetName()=='FIntProperty' and p:ContainerPtrToValuePtr(o)>0 and bp and bp:GetByteMask()==1 and bp:GetFieldSize()>=1 and fp and fp.IsParm and fp:GetFName():ToString()=='Value' and seenProps>=1 and fProps>=1; if not compatOk then error('missing ue4ss compatibility globals') end" >"$mod_script_compat"
printf "%s\n" "local o=FindObject('SelfTestObject'); local r=o and o:Reflection(); local pf=r and r:GetProperty('ProbeFloat'); local pd=r and r:GetProperty('ProbeDouble'); local seenFloat=0; local seenDouble=0; if o then o:ForEachProperty(function(prop) if prop and prop:GetFName():ToString()=='ProbeFloat' and prop:IsA(PropertyTypes.FloatProperty) then seenFloat=seenFloat+1 end; if prop and prop:GetFName():ToString()=='ProbeDouble' and prop:IsA(PropertyTypes.DoubleProperty) then seenDouble=seenDouble+1 end end) end; if not (pf and pf:type()=='FFloatProperty' and pf:GetClass():GetName()=='FFloatProperty' and pf:IsA(PropertyTypes.FloatProperty) and pf:ContainerPtrToValuePtr(o)>0 and pd and pd:type()=='FDoubleProperty' and pd:GetClass():GetName()=='FDoubleProperty' and pd:IsA(PropertyTypes.DoubleProperty) and pd:ContainerPtrToValuePtr(o)>0 and seenFloat>=1 and seenDouble>=1) then error('missing numeric reflection descriptors') end" >>"$mod_script_compat"
printf "%s\n" "local pn=r and r:GetProperty('ProbeName'); local pt=r and r:GetProperty('ProbeText'); local seenName=0; local seenText=0; if o then o:ForEachProperty(function(prop) if prop and prop:GetFName():ToString()=='ProbeName' and prop:IsA(PropertyTypes.NameProperty) then seenName=seenName+1 end; if prop and prop:GetFName():ToString()=='ProbeText' and prop:IsA(PropertyTypes.TextProperty) then seenText=seenText+1 end end) end; if not (pn and pn:type()=='FNameProperty' and pn:GetClass():GetName()=='FNameProperty' and pn:IsA(PropertyTypes.NameProperty) and pn:ContainerPtrToValuePtr(o)>0 and pt and pt:type()=='FTextProperty' and pt:GetClass():GetName()=='FTextProperty' and pt:IsA(PropertyTypes.TextProperty) and pt:ContainerPtrToValuePtr(o)>0 and seenName>=1 and seenText>=1) then error('missing name/text reflection descriptors') end" >>"$mod_script_compat"
printf "%s\n" "local handled=RegisterConsoleCommandHandler('probe_args', function(ctx, command, args) return ctx and ctx.Name=='SelfTestObject' and command=='probe_args' and args=='spice flow' end); if not (handled and o and o:ProcessConsoleExec('probe_args spice flow',nil,o) and not o:ProcessConsoleExec('missing_probe',nil,o)) then error('missing ProcessConsoleExec dispatch') end" >>"$mod_script_compat"
printf "%s\n" "local preCount=0; local postCount=0; local preId=RegisterProcessConsoleExecPreHook(function(ctx, raw, command, args, handled) if ctx and ctx.Name=='SelfTestObject' and raw=='preprobe spice' and command=='preprobe' and args=='spice' and not handled then preCount=preCount+1; return true end return false end); local postId=RegisterProcessConsoleExecPostHook(function(ctx, raw, command, args, handled) if ctx and ctx.Name=='SelfTestObject' and raw=='probe_args spice flow' and command=='probe_args' and args=='spice flow' and handled then postCount=postCount+1; return true end return false end); if not (preId and postId and o and o:ProcessConsoleExec('preprobe spice',nil,o) and o:ProcessConsoleExec('probe_args spice flow',nil,o) and preCount==1 and postCount==1) then error('missing ProcessConsoleExec hooks') end" >>"$mod_script_compat"
printf "%s\n" "local lpPre=0; local lpPost=0; local lpPreId=RegisterULocalPlayerExecPreHook(function(ctx, raw, command, args, handled) if ctx and ctx.Name=='SelfTestObject' and raw=='localpre spice' and command=='localpre' and args=='spice' and not handled then lpPre=lpPre+1; return true end return false end); local lpPostId=RegisterULocalPlayerExecPostHook(function(ctx, raw, command, args, handled) if ctx and ctx.Name=='SelfTestObject' and raw=='localpost flow' and command=='localpost' and args=='flow' and not handled then lpPost=lpPost+1; return true end return false end); if not (lpPreId and lpPostId and o and o:ULocalPlayerExec('localpre spice') and ULocalPlayerExec(o,'localpost flow') and lpPre==1 and lpPost==1) then error('missing ULocalPlayerExec hooks') end" >>"$mod_script_compat"
printf "%s\n" "local callPre=0; local callPost=0; local callPreId=RegisterCallFunctionByNameWithArgumentsPreHook(function(ctx, name, args, handled, result) if ctx and ctx.Name=='SelfTestObject' and name=='HookedProbe' and args=='spice' and not handled and result==nil then callPre=callPre+1; return 77,true end return nil,false end); local callPostId=RegisterCallFunctionByNameWithArgumentsPostHook(function(ctx, name, args, handled, result) if ctx and ctx.Name=='SelfTestObject' and name=='DoubleProbeValue' and args=='flow' and handled and result==14 then callPost=callPost+1; return 84,true end return result,false end); if not (callPreId and callPostId and o and o:CallFunction('HookedProbe','spice')==77 and o:CallFunction('DoubleProbeValue','flow')==84 and callPre==1 and callPost==1) then error('missing CallFunctionByNameWithArguments hooks') end" >>"$mod_script_compat"
printf "%s\n" "local ce=0; local ceId=RegisterCustomEvent('probe.lifecycle',function(ctx,event,payload,handled) if ctx and ctx.Name=='SelfTestObject' and event=='probe.lifecycle' and payload=='payload' and not handled then ce=ce+1; return true end return false end); local lmPre,lmPost,bpPre,bpPost,gsPre,gsPost=0,0,0,0,0,0; local lmPreId=RegisterLoadMapPreHook(function(ctx,event,payload,handled) if ctx and ctx.Name=='SelfTestObject' and event=='LoadMap' and payload=='arrakis' and not handled then lmPre=lmPre+1; return true end return false end); local lmPostId=RegisterLoadMapPostHook(function(ctx,event,payload,handled) if ctx and ctx.Name=='SelfTestObject' and event=='LoadMap' and payload=='arrakis' and handled then lmPost=lmPost+1; return true end return false end); local bpPreId=RegisterBeginPlayPreHook(function(ctx,event,payload,handled) if ctx and ctx.Name=='SelfTestObject' and event=='BeginPlay' and payload=='actor' and not handled then bpPre=bpPre+1; return true end return false end); local bpPostId=RegisterBeginPlayPostHook(function(ctx,event,payload,handled) if ctx and ctx.Name=='SelfTestObject' and event=='BeginPlay' and payload=='actor' and handled then bpPost=bpPost+1; return true end return false end); local gsPreId=RegisterInitGameStatePreHook(function(ctx,event,payload,handled) if ctx and ctx.Name=='SelfTestObject' and event=='InitGameState' and payload=='game' and not handled then gsPre=gsPre+1; return true end return false end); local gsPostId=RegisterInitGameStatePostHook(function(ctx,event,payload,handled) if ctx and ctx.Name=='SelfTestObject' and event=='InitGameState' and payload=='game' and handled then gsPost=gsPost+1; return true end return false end); if not (ceId and UE4SSLProbeDispatchCustomEvent('probe.lifecycle',o,'payload') and ce==1 and lmPreId and lmPostId and UE4SSLProbeLoadMap(o,'arrakis') and lmPre==1 and lmPost==1 and bpPreId and bpPostId and UE4SSLProbeBeginPlay(o,'actor') and bpPre==1 and bpPost==1 and gsPreId and gsPostId and UE4SSLProbeInitGameState(o,'game') and gsPre==1 and gsPost==1) then error('missing lifecycle/custom event hooks') end" >>"$mod_script_compat"
printf "%s\n" "local seenFns=0; if o then o:ForEachFunction(function(fn) if fn and fn:GetName()=='SelfTestUObjectName_0' and fn:type()=='UFunction' then seenFns=seenFns+1 end end) end; local clsFns=0; if cls and f then cls:ForEachFunction(function(fn) if fn and fn.Address==f.Address then clsFns=clsFns+1; return true end end) end; if not (seenFns>=1 and clsFns>=1) then error('missing ForEachFunction registry') end" >>"$mod_script_compat"
printf "%s\n" "local o=FindObject('SelfTestObject'); local cls=o and o:GetClass(); if not (cls and cls:IsChildOf('UE4SSLServerProbeSelfTestClass') and cls:IsChildOf('/Script/CoreUObject.Object') and cls:IsChildOf(cls) and not cls:IsChildOf('UClass') and not cls:IsChildOf('Missing')) then error('missing IsChildOf compatibility') end" >>"$mod_script_compat"
printf "%s\n" "local notifyHit=0; local notifySecond=0; local notifyMiss=0; NotifyOnNewObject('UE4SSLServerProbeSelfTestClass', function(x) if x and x.Name=='NotifyConstructedProbe' then notifyHit=notifyHit+1; return 17 end end); NotifyOnNewObject('/RuntimeProbe/Constructed/NotifyConstructedProbe', function(x) if x and x.Name=='NotifyConstructedProbe' then notifySecond=notifySecond+1; return 19 end end); NotifyOnNewObject('MissingNotifyClass', function(x) notifyMiss=notifyMiss+1; return -99 end); local nc=StaticConstructObject(cls,o,'NotifyConstructedProbe'); local nco=nc and nc:GetOuter(); if not (nc and nc.Name=='NotifyConstructedProbe' and nco and nco.Address==o.Address and nc.OuterAddress==o.Address and nc.ClassAddress==cls.Address and notifyHit==1 and notifySecond==1 and notifyMiss==0) then error('missing NotifyOnNewObject dispatch') end" >>"$mod_script_compat"
printf "%s\n" "local world=StaticConstructObject({ClassName='UWorld',Name='SelfTestWorld'},nil,'SelfTestWorld'); local level=StaticConstructObject({ClassName='ULevel',Name='PersistentLevel'},world,'PersistentLevel'); local actor=StaticConstructObject({ClassName='AActor',Name='LevelChildProbe'},level,'LevelChildProbe'); local ww=world and world:GetWorld(); local aw=actor and actor:GetWorld(); local al=actor and actor:GetLevel(); local ll=level and level:GetLevel(); if not (ww and ww.Address==world.Address and aw and aw.Address==world.Address and al and al.Address==level.Address and ll and ll.Address==level.Address) then error('missing GetWorld/GetLevel world-context dispatch') end" >>"$mod_script_compat"

UE4SSL_SERVER_LOG="$log" \
UE4SSL_SERVER_SNAPSHOT_DELAY_SECONDS=0 \
UE4SSL_SERVER_SCAN_ENABLED=true \
UE4SSL_SERVER_SCAN_PRESETS= \
UE4SSL_SERVER_SCAN_STRINGS=true \
UE4SSL_SERVER_SCAN_SIGNATURES='elf=7f 45 4c 46' \
UE4SSL_SERVER_SCAN_SIGNATURES_FILE="$signature_file" \
UE4SSL_SERVER_SCAN_PATH_FILTER=true \
UE4SSL_SERVER_SCAN_MAX_HITS_PER_NEEDLE=4 \
UE4SSL_SERVER_SCAN_MAX_MAPPING_BYTES=268435456 \
UE4SSL_SERVER_UE_ANCHOR_SIGNATURES='ElfAnchor=7f 45 4c 46;ElfHeaderByte@hit+1=7f 45 4c 46' \
UE4SSL_SERVER_UE_ANCHOR_SIGNATURES_FILE="$signature_file" \
UE4SSL_SERVER_UE_ANCHORS='BadAnchor=0x1' \
UE4SSL_SERVER_UE_POINTER_PROBE=true \
UE4SSL_SERVER_UE_LAYOUT_PROBE=true \
UE4SSL_SERVER_UE_LAYOUT_SLOTS=2 \
UE4SSL_SERVER_UE_UOBJECT_PROBE=true \
UE4SSL_SERVER_UE_REFLECTION_PROBE=true \
UE4SSL_SERVER_UE_REFLECTION_FIELD_WALK=true \
UE4SSL_SERVER_UE_REFLECTION_PROPERTY_PROBE=true \
UE4SSL_SERVER_UE_REFLECTION_VALUE_PROBE=true \
UE4SSL_SERVER_UE_OBJECT_ARRAY_PROBE=true \
UE4SSL_SERVER_UE_OBJECT_ARRAY_MAX_OBJECTS=4 \
UE4SSL_SERVER_UE_FNAME_PROBE=true \
UE4SSL_SERVER_UE_SELF_TEST_ANCHOR=true \
UE4SSL_SERVER_HOOK_SELF_TEST=true \
UE4SSL_SERVER_MOD_SELF_TEST=true \
UE4SSL_SERVER_LUA_SELF_TEST=true \
UE4SSL_SERVER_LUA_REFLECTION_SELF_TEST=true \
UE4SSL_SERVER_LUA_REFLECTION_RAW_SET_ENABLED=true \
UE4SSL_SERVER_UE_PROCESS_EVENT_HOOK_PROBE=true \
UE4SSL_SERVER_UE_PROCESS_EVENT_HOOK_SELF_TEST_TARGET=true \
UE4SSL_SERVER_UE_PROCESS_EVENT_HOOK_INSTALL=true \
UE4SSL_SERVER_LUA_PROCESS_EVENT_SELF_TEST=true \
UE4SSL_SERVER_UE_PROCESS_EVENT_LIVE_HOOK=true \
UE4SSL_SERVER_UE_PROCESS_EVENT_LIVE_HOOK_SELF_TEST_TARGET=true \
UE4SSL_SERVER_UE_PROCESS_EVENT_LIVE_HOOK_CALL_SELF_TEST=true \
UE4SSL_SERVER_UE_PROCESS_EVENT_LIVE_HOOK_LOG_CALLS=true \
UE4SSL_SERVER_UE_PROCESS_EVENT_LIVE_HOOK_CALL_LOG_LIMIT=2 \
UE4SSL_SERVER_UE_PROCESS_EVENT_DISPATCH_SELF_TEST=true \
UE4SSL_SERVER_UE_PROCESS_EVENT_LIVE_LUA_DISPATCH=true \
UE4SSL_SERVER_LUA_MODS_ENABLED=true \
UE4SSL_SERVER_LUA_MOD_SCRIPTS="$mod_script;$mod_script_two;$mod_script_compat" \
UE4SSL_SERVER_LUA_MOD_DISPATCH_SELF_TEST=true \
LD_PRELOAD="$repo_root/build/linux-server-loader/libue4ssl_linux_server_loader.so" \
  "$target"

require_log() {
  local pattern="$1"
  if ! grep -q "$pattern" "$log"; then
    echo "missing expected Linux server probe log pattern: $pattern" >&2
    sed -n '1,180p' "$log" >&2 || true
    exit 1
  fi
}

require_log 'loader=server event=loaded'
require_log 'loader=server event=module'
require_log 'loader=server event=scan-start'
require_log 'loader=server event=signature-file'
require_log 'loader=server event=scan-hit kind=string name=true'
require_log 'loader=server event=scan-hit kind=signature name=elf'
require_log 'loader=server event=scan-hit kind=signature name=elf-file'
require_log 'loader=server event=scan-finish'
require_log 'loader=server event=ue-anchor-signature-start phase=snapshot'
require_log 'loader=server event=ue-anchor-signature name=ElfAnchor status=resolved'
require_log 'loader=server event=ue-anchor-signature name=ElfHeaderByte status=resolved.*transform=hit+1'
require_log 'loader=server event=ue-anchor-signature name=elf-file status=resolved'
require_log 'loader=server event=ue-anchor-start phase=snapshot'
require_log 'loader=server event=ue-anchor name=ElfAnchor status=mapped'
require_log 'loader=server event=ue-anchor name=ElfHeaderByte status=mapped'
require_log 'loader=server event=ue-anchor name=BadAnchor status=unmapped'
require_log 'loader=server event=ue-anchor name=SelfTest status=mapped'
require_log 'loader=server event=ue-pointer name=SelfTest status=target-mapped'
require_log 'loader=server event=ue-layout name=SelfTest status=target-readable'
require_log 'loader=server event=ue-layout-slot name=SelfTest status=target-mapped'
require_log 'loader=server event=ue-uobject name=SelfTestUObject status=candidate'
require_log 'loader=server event=lua-object-registry source=ue-uobject status=added name=SelfTestUObject'
require_log 'loader=server event=lua-object-registry source=ue-uobject-fname status=added name=SelfTestUObjectName_0 path=/RuntimeProbe/SelfTestUObjectName_0 aliasOf=SelfTestUObject class=UObjectCandidate'
require_log 'loader=server event=ue-fname source=ue-uobject objectName=SelfTestUObject status=decoded'
require_log 'loader=server event=ue-reflection-start'
require_log 'loader=server event=ue-reflection name=SelfTestUObject status=class-mapped'
require_log 'loader=server event=ue-fname source=ue-reflection-class objectName=SelfTestUObject status=decoded'
require_log 'loader=server event=ue-reflection-slot name=SelfTestUObject slot=children status=target-mapped'
require_log 'loader=server event=ue-reflection-slot name=SelfTestUObject slot=propertyLink status=target-mapped'
require_log 'loader=server event=ue-reflection-slot name=SelfTestUObject slot=functionLink status=target-mapped'
require_log 'loader=server event=ue-reflection-field name=SelfTestUObject chain=children index=0 status=candidate'
require_log 'loader=server event=ue-reflection-field name=SelfTestUObject chain=propertyLink index=0 status=candidate'
require_log 'loader=server event=ue-reflection-field name=SelfTestUObject chain=functionLink index=0 status=candidate'
require_log 'loader=server event=ue-function-param-root name=SelfTestUObject functionIndex=0 chain=childProperties status=root'
require_log 'loader=server event=ue-function-param-root name=SelfTestUObject functionIndex=0 chain=propertyLink status=root'
require_log 'loader=server event=ue-function-param name=SelfTestUObject functionIndex=0 chain=childProperties index=0 status=candidate .*functionName=SelfTestUObjectName_0 .*functionPath=/RuntimeProbe/SelfTestUObject.SelfTestUObjectName_0:Function'
require_log 'loader=server event=ue-function-param-root name=SelfTestUObject functionIndex=0 chain=childProperties status=root .*functionFlags=0x400 functionFlagsReadable=true'
require_log 'loader=server event=ue-function-param name=SelfTestUObject functionIndex=0 chain=childProperties index=0 status=candidate .*functionFlags=0x400 functionFlagsReadable=true'
require_log 'loader=server event=ue-function-param name=SelfTestUObject functionIndex=0 chain=childProperties index=0 status=candidate .*fieldClassName=FIntProperty .*fieldName=Value .*offsetInternal=0'
require_log 'loader=server event=ue-function-param name=SelfTestUObject functionIndex=0 chain=propertyLink index=2 status=candidate .*fieldClassName=FIntProperty .*fieldName=Touched .*offsetInternal=8'
require_log 'loader=server event=ue-function-param name=SelfTestUObject functionIndex=0 chain=propertyLink index=3 status=candidate .*fieldClassName=FNameProperty .*fieldName=NameToken .*offsetInternal=48'
require_log 'loader=server event=ue-function-param name=SelfTestUObject functionIndex=0 chain=propertyLink index=4 status=candidate .*fieldClassName=FStrProperty .*fieldName=Message .*offsetInternal=56'
require_log 'loader=server event=ue-function-param name=SelfTestUObject functionIndex=0 chain=propertyLink index=5 status=candidate .*fieldClassName=FStructProperty .*fieldName=Location .*offsetInternal=72'
require_log 'loader=server event=ue-reflection-property name=SelfTestUObject chain=childProperties index=0 status=candidate .*arrayDim=1 elementSize=4 propertyFlags=0x1 offsetInternal=12'
require_log 'loader=server event=ue-reflection-property name=SelfTestUObject chain=propertyLink index=0 status=candidate .*arrayDim=1 elementSize=4 propertyFlags=0x1 offsetInternal=12'
require_log 'loader=server event=ue-reflection-value name=SelfTestUObject chain=childProperties index=0 fieldName=SelfTestUObjectName_0 status=read .*offsetInternal=12 elementSize=4 arrayDim=1 .*readBytes=4 raw=07000000 rawLe=0x7'
require_log 'loader=server event=ue-reflection-value name=SelfTestUObject chain=propertyLink index=0 fieldName=SelfTestUObjectName_0 status=read .*offsetInternal=12 elementSize=4 arrayDim=1 .*readBytes=4 raw=07000000 rawLe=0x7'
require_log 'loader=server event=ue-fname source=ue-reflection-field objectName=SelfTestUObject.children_0 status=decoded'
require_log 'loader=server event=ue-reflection-finish'
require_log 'loader=server event=ue-object-array name=SelfTestObjectArray mode=indirect status=scanning'
require_log 'loader=server event=ue-object-array name=SelfTestObjectArray mode=indirect status=finished .*registered=1'
require_log 'loader=server event=lua-object-registry source=ue-object-array status=added name=SelfTestObjectArray_0'
require_log 'loader=server event=lua-object-registry source=ue-object-array-fname status=skipped name=SelfTestUObjectName_0 path=/RuntimeProbe/SelfTestUObjectName_0 aliasOf=SelfTestObjectArray_0 class=UObjectArrayItem'
require_log 'loader=server event=ue-fname source=ue-object-array objectName=SelfTestObjectArray_0 status=decoded'
require_log 'loader=server event=ue-object-array-finish phase=snapshot registryCount=4'
require_log 'loader=server event=hook-dispatch name=SelfTestHook status=installed'
require_log 'loader=server event=hook-dispatch name=SelfTestHook status=restored'
require_log 'loader=server event=hook-dispatch-self-test phase=snapshot status=passed'
require_log 'loader=server event=hook-dispatch-self-test .*original=42 callbacks=2 preCallbacks=1 postCallbacks=1'
require_log 'loader=server event=mod-dispatch-self-test phase=snapshot status=passed'
require_log 'loader=server event=mod-dispatch-self-test .*mods=1 loaded=1 unloaded=1 result=1042 original=42 callbacks=2 preCallbacks=1 postCallbacks=1'
require_log 'loader=server event=lua-dispatch-self-test phase=snapshot status=passed'
require_log 'loader=server event=lua-dispatch-self-test .*loadStatus=0 callStatus=0 callbackStatus=0 result=42 isNumber=true'
require_log 'loader=server event=lua-dispatch-self-test .*objectHandles=6 ueObjectHandles=4'
require_log 'loader=server event=lua-dispatch-self-test .*staticFindObjectCalls=1 staticFindObjectHits=1 findObjectCalls=1 findObjectHits=1 findFirstOfCalls=1 findFirstOfHits=1 getKnownObjectsCalls=1 getKnownObjectsHits=1 findObjectsCalls=1 findObjectsHits=1 findAllOfCalls=1 findAllOfHits=1 forEachUObjectCalls=1 forEachUObjectCallbacks=[1-9][0-9]* forEachFunctionCalls=0 forEachFunctionCallbacks=0 isACalls=[1-9][0-9]* isAHits=[1-9][0-9]* loadAssetCalls=1 loadAssetHits=1 staticConstructObjectCalls=1 staticConstructObjectHits=1'
require_log 'loader=server event=lua-reflection-self-test phase=snapshot status=passed'
require_log 'loader=server event=lua-reflection-self-test .*result=42 isNumber=true staticFindObjectCalls=2 staticFindObjectHits=2'
require_log 'loader=server event=lua-reflection-self-test .*getPropertyCalls=20 getPropertyHits=20 rawPropertyHits=2 rawPropertyValue=17 namedPropertyHits=2 rawPropertySetHits=1 rawPropertySetValue=17 arrayInnerPropertyHits=1 enumPropertyHits=1 enumUnderlyingPropertyHits=1 setElementPropertyHits=1 mapKeyPropertyHits=1 mapValuePropertyHits=1 importTextHits=1 exportTextHits=1 propertyMetadataHits=7 descriptorValueGetHits=16 descriptorValueSetHits=8 setPropertyCalls=9 setPropertyHits=9 callFunctionCalls=2 callFunctionHits=2 probeValue=21 probeBool=false probeFloat=13.750 probeDouble=-47.500 probeName=ArrakisName probeString=melange probeText=WaterDebt probeObject=0x'
require_log 'loader=server event=lua-reflection-self-test .*objectHandles=5 ueObjectHandles=4'
require_log 'loader=server event=ue-process-event-hook phase=snapshot status=target-mapped .*selfTestTarget=true install=true'
require_log 'loader=server event=hook-dispatch name=ProcessEventHookProbe status=installed'
require_log 'loader=server event=hook-dispatch name=ProcessEventHookProbe status=restored'
require_log 'loader=server event=ue-process-event-hook phase=snapshot status=passed .*installed=true restored=true selfTestTarget=true callSelfTest=true liveCalls=1 originalCalls=1 paramsResult=62 paramsTouched=1'
require_log 'loader=server event=lua-process-event-self-test phase=snapshot status=passed'
require_log 'loader=server event=lua-process-event-self-test .*result=4 isNumber=true hooks=2 hook=/Script/UE4SSLServerProbe.SelfTest:Function'
require_log 'loader=server event=lua-process-event-self-test .*installed=true restored=true hookCalls=1 originalCalls=2 originalAfterHook=1'
require_log 'loader=server event=lua-process-event-self-test .*paramDescriptorHits=2 paramDescriptorLookupCalls=13 paramDescriptorLookupHits=13 functionParamDescriptorCalls=2 functionParamDescriptorHits=2 paramGetCalls=21 paramGetHits=21 paramSetCalls=7 paramSetHits=7'
require_log 'loader=server event=lua-process-event-self-test .*paramsResult=42 paramsTouched=1 finalResult=52 finalTouched=1'
require_log 'loader=server event=lua-mod-start phase=snapshot status=running scripts=3'
require_log 'loader=server event=lua-mod-script phase=snapshot status=passed'
require_log 'loader=server event=lua-mod-script .*hooksAfter=1'
require_log 'loader=server event=lua-mod-script .*hooksAfter=2'
require_log 'loader=server event=lua-mod-dispatch-self-test phase=snapshot status=passed callbackStatus=0 hooks=2 hook=/Script/UE4SSLServerProbe.ModEntry:Function'
require_log 'loader=server event=lua-mod-dispatch-self-test .*preCalls=2 postCalls=2 preResult=11 postResult=31 preIsNumber=true postIsNumber=true'
require_log 'loader=server event=lua-mod-finish phase=snapshot status=passed .*scripts=3 loaded=3 failed=0 hooks=2'
require_log 'loader=server event=lua-mod-finish .*customEvents=1 customEventCalls=1 customEventHandled=1 loadMapPreHooks=1 loadMapPostHooks=1 loadMapPreCalls=1 loadMapPostCalls=1 loadMapPreHandled=1 loadMapPostHandled=1 beginPlayPreHooks=1 beginPlayPostHooks=1 beginPlayPreCalls=1 beginPlayPostCalls=1 beginPlayPreHandled=1 beginPlayPostHandled=1 initGameStatePreHooks=1 initGameStatePostHooks=1 initGameStatePreCalls=1 initGameStatePostCalls=1 initGameStatePreHandled=1 initGameStatePostHandled=1'
require_log 'loader=server event=lua-mod-finish .*processConsoleExecPreHooks=1 processConsoleExecPostHooks=1 processConsoleExecPreCalls=2 processConsoleExecPostCalls=2 processConsoleExecPreHandled=1 processConsoleExecPostHandled=1 localPlayerExecPreHooks=1 localPlayerExecPostHooks=1 localPlayerExecPreCalls=2 localPlayerExecPostCalls=2 localPlayerExecPreHandled=1 localPlayerExecPostHandled=1 callFunctionPreHooks=1 callFunctionPostHooks=1 callFunctionPreCalls=2 callFunctionPostCalls=1 callFunctionPreHandled=1 callFunctionPostHandled=1'
require_log 'loader=server event=lua-mod-finish .*findObjectCalls=5 findObjectHits=5 .*getKnownObjectsCalls=1 getKnownObjectsHits=1 findObjectsCalls=1 findObjectsHits=1 findAllOfCalls=1 findAllOfHits=1 forEachUObjectCalls=1 forEachUObjectCallbacks=[1-9][0-9]* forEachFunctionCalls=2 forEachFunctionCallbacks=2 isACalls=[1-9][0-9]* isAHits=[1-9][0-9]* loadAssetCalls=1 loadAssetHits=1'
require_log 'loader=server event=lua-mod-finish .*staticConstructObjectCalls=[3-9][0-9]* staticConstructObjectHits=[3-9][0-9]* notifyOnNewObjectCalls=3 .*notifyOnNewObjectCallbacks=2 notifyOnNewObjectResult=19 notifyOnNewObjectIsNumber=true notifyOnNewObjectStatus=0'
require_log 'loader=server event=lua-mod-finish .*staticConstructObjectOuterHits=[2-9][0-9]*'
require_log 'loader=server event=lua-mod-finish .*getWorldCalls=[2-9][0-9]* getWorldHits=[2-9][0-9]*'
require_log 'loader=server event=lua-mod-finish .*getCdoCalls=[1-9][0-9]* getCdoHits=[1-9][0-9]* getLevelCalls=[2-9][0-9]* getLevelHits=[2-9][0-9]*'
require_log 'loader=server event=ue-process-event-dispatch-self-test phase=snapshot status=armed .*callbacks=2'
require_log 'loader=server event=ue-process-event-live-hook phase=snapshot status=target-mapped .*selfTestTarget=true logCalls=true callLogLimit=2'
require_log 'loader=server event=ue-process-event-live-lua-dispatch phase=snapshot status=armed .*result=4 isNumber=true hooks=2 hook=/Script/UE4SSLServerProbe.LiveProcessEvent:Function callbacks=4'
require_log 'loader=server event=hook-dispatch name=ProcessEventLiveHook status=installed'
require_log 'loader=server event=ue-process-event-live-hook-call status=entered call=1'
require_log 'loader=server event=ue-process-event-live-hook-call status=returned call=1 originalCalled=true preCallbacks=2 postCallbacks=2'
require_log 'loader=server event=ue-process-event-live-hook phase=snapshot status=installed .*selfTestTarget=true callSelfTest=true dispatchCallbacks=4 luaDispatch=true luaPreStatus=0 luaPostStatus=0 luaPreCalls=1 luaPostCalls=1 luaObjectHandleHits=2 luaFunctionHandleHits=2 luaParamsHandleHits=2 luaParamDescriptorHits=2 luaParamDescriptorLookupCalls=13 luaParamDescriptorLookupHits=13 luaFunctionParamDescriptorCalls=2 luaFunctionParamDescriptorHits=2 luaParamGetCalls=21 luaParamGetHits=21 luaParamSetCalls=7 luaParamSetHits=7 preCallbacks=2 postCallbacks=2 liveCalls=1 originalCalls=1 paramsResult=62 paramsTouched=1'
require_log 'loader=server event=hook-dispatch name=ProcessEventLiveHook status=restored'
require_log 'loader=server event=ue-process-event-live-hook phase=unload status=restored .*liveCalls=1 originalCalls=1'
require_log 'loader=server event=ue-process-event-live-lua-dispatch phase=unload status=closed preCalls=1 postCalls=1 preResult=11 postResult=31 preStatus=0 postStatus=0'

printf 'Linux server loader smoke passed: %s\n' "$log"
