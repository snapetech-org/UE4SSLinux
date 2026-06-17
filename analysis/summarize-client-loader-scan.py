#!/usr/bin/env python3
import argparse
import json
import sys
from collections import Counter, defaultdict
from pathlib import Path


CATEGORY_NEEDLES = {
    "ue": (
        "FNamePool",
        "GUObjectArray",
        "GObjectArray",
        "GWorld",
        "ProcessEvent",
        "StaticFindObject",
        "UObject",
        "UFunction",
        "UClass",
        "FProperty",
    ),
    "client": (
        "LocalPlayer",
        "PlayerController",
        "GameViewport",
        "ViewportClient",
        "ConsoleKey",
        "InputSettings",
        "ClientTravel",
        "ClientRestart",
    ),
    "cheat": (
        "CheatManager",
        "CheatClass",
        "EnableCheats",
        "AdminLogin",
        "ServerCheat",
        "ClientMessage",
    ),
    "brt": (
        "BaseBackup",
        "PerformCanBePlaced",
        "Fail_InvalidMap",
        "m_BaseBackupToolMapRestriction",
    ),
    "deep-desert": (
        "DeepDesert",
        "ShiftingSands",
        "SpiceField",
        "PerMapSystem",
    ),
    "platform": (
        "TargetGame",
        "EngineVersion",
        "rundll32.exe",
        "elf",
        "mz",
    ),
}

DEFAULT_EXPECTED = (
    "FNamePool",
    "GUObjectArray",
    "GObjectArray",
    "GWorld",
    "ProcessEvent",
    "CheatManager",
    "ServerRequestBaseBackup",
    "BaseBackupActionPlace",
    "DeepDesert",
)


def parse_line(line):
    line = line.strip().replace("\r", "")
    if not line:
        return None
    parts = line.split()
    if not parts:
        return None
    record = {"timestamp": parts[0]}
    for token in parts[1:]:
        if "=" not in token:
            continue
        key, value = token.split("=", 1)
        record[key] = value
    return record


def load_records(path):
    records = []
    with path.open("r", encoding="utf-8", errors="replace") as handle:
        for line in handle:
            record = parse_line(line)
            if record:
                records.append(record)
    return records


def category_for(name):
    for category, needles in CATEGORY_NEEDLES.items():
        if any(needle in name for needle in needles):
            return category
    return "other"


def record_source(record):
    return record.get("map") or record.get("module") or record.get("name") or ""


def record_offset(record):
    return (
        record.get("imageOffset")
        or record.get("rva")
        or record.get("fileOffset")
        or record.get("addr")
        or ""
    )


def record_int(record, key, default=0):
    try:
        return int(str(record.get(key, default)), 0)
    except (TypeError, ValueError):
        return default


def record_float(record, key, default=0.0):
    try:
        return float(str(record.get(key, default)))
    except (TypeError, ValueError):
        return default


def lua_object_api_surface_passed(record):
    return (
        record_int(record, "findObjectCalls") > 0
        and record_int(record, "findObjectHits") > 0
        and record_int(record, "getKnownObjectsCalls") > 0
        and record_int(record, "getKnownObjectsHits") > 0
        and record_int(record, "findObjectsCalls") > 0
        and record_int(record, "findObjectsHits") > 0
        and record_int(record, "findAllOfCalls") > 0
        and record_int(record, "findAllOfHits") > 0
        and record_int(record, "forEachUObjectCalls") > 0
        and record_int(record, "forEachUObjectCallbacks") > 0
        and record_int(record, "isACalls") >= 2
        and record_int(record, "isAHits") >= 2
        and record_int(record, "loadAssetCalls") > 0
        and record_int(record, "loadAssetHits") > 0
    )


def lua_function_iteration_surface_passed(record):
    return (
        record_int(record, "forEachFunctionCalls") > 0
        and record_int(record, "forEachFunctionCallbacks") > 0
    )


def lua_notify_on_new_object_surface_passed(record):
    return (
        record_int(record, "notifyOnNewObjectCalls") >= 2
        and record_int(record, "notifyOnNewObjectCallbacks") >= 2
        and record_int(record, "notifyOnNewObjectStatus", -1) == 0
    )


def lua_synthetic_outer_surface_passed(record):
    return record_int(record, "staticConstructObjectOuterHits") > 0


def lua_world_context_surface_passed(record):
    return record_int(record, "getWorldCalls") > 0 and record_int(record, "getWorldHits") > 0


def lua_class_default_object_surface_passed(record):
    return record_int(record, "getCdoCalls") > 0 and record_int(record, "getCdoHits") > 0


def lua_level_surface_passed(record):
    return record_int(record, "getLevelCalls") > 0 and record_int(record, "getLevelHits") > 0


def lua_process_console_exec_hook_surface_passed(record):
    return (
        record_int(record, "processConsoleExecPreHooks") > 0
        and record_int(record, "processConsoleExecPostHooks") > 0
        and record_int(record, "processConsoleExecPreCalls") > 0
        and record_int(record, "processConsoleExecPostCalls") > 0
        and record_int(record, "processConsoleExecPreHandled") > 0
        and record_int(record, "processConsoleExecPostHandled") > 0
    )


def lua_local_player_exec_hook_surface_passed(record):
    return (
        record_int(record, "localPlayerExecPreHooks") > 0
        and record_int(record, "localPlayerExecPostHooks") > 0
        and record_int(record, "localPlayerExecPreCalls") > 0
        and record_int(record, "localPlayerExecPostCalls") > 0
        and record_int(record, "localPlayerExecPreHandled") > 0
        and record_int(record, "localPlayerExecPostHandled") > 0
    )


def lua_call_function_hook_surface_passed(record):
    return (
        record_int(record, "callFunctionPreHooks") > 0
        and record_int(record, "callFunctionPostHooks") > 0
        and record_int(record, "callFunctionPreCalls") > 0
        and record_int(record, "callFunctionPostCalls") > 0
        and record_int(record, "callFunctionPreHandled") > 0
        and record_int(record, "callFunctionPostHandled") > 0
    )


def lua_lifecycle_hook_surface_passed(record):
    return (
        record_int(record, "customEvents") > 0
        and record_int(record, "customEventCalls") > 0
        and record_int(record, "customEventHandled") > 0
        and record_int(record, "loadMapPreHooks") > 0
        and record_int(record, "loadMapPostHooks") > 0
        and record_int(record, "loadMapPreCalls") > 0
        and record_int(record, "loadMapPostCalls") > 0
        and record_int(record, "loadMapPreHandled") > 0
        and record_int(record, "loadMapPostHandled") > 0
        and record_int(record, "beginPlayPreHooks") > 0
        and record_int(record, "beginPlayPostHooks") > 0
        and record_int(record, "beginPlayPreCalls") > 0
        and record_int(record, "beginPlayPostCalls") > 0
        and record_int(record, "beginPlayPreHandled") > 0
        and record_int(record, "beginPlayPostHandled") > 0
        and record_int(record, "initGameStatePreHooks") > 0
        and record_int(record, "initGameStatePostHooks") > 0
        and record_int(record, "initGameStatePreCalls") > 0
        and record_int(record, "initGameStatePostCalls") > 0
        and record_int(record, "initGameStatePreHandled") > 0
        and record_int(record, "initGameStatePostHandled") > 0
    )


def lua_reflection_self_test_passed(record):
    if record.get("status") != "passed":
        return False
    raw_hits = record_int(record, "rawPropertyHits")
    raw_value = record_int(record, "rawPropertyValue")
    raw_set_hits = record_int(record, "rawPropertySetHits")
    raw_set_value = record_int(record, "rawPropertySetValue")
    return (
        record.get("result") == "42"
        and record_int(record, "staticFindObjectHits") >= 1
        and record_int(record, "getPropertyCalls") >= 17
        and record_int(record, "getPropertyHits") >= 17
        and record_int(record, "setPropertyCalls") >= 8
        and record_int(record, "setPropertyHits") >= 8
        and record.get("callFunctionCalls") == "2"
        and record.get("callFunctionHits") == "2"
        and record.get("probeValue") == "21"
        and record.get("probeBool") == "false"
        and abs(record_float(record, "probeFloat") - 13.75) < 0.001
        and abs(record_float(record, "probeDouble") + 47.5) < 0.001
        and record.get("probeName") == "ArrakisName"
        and record.get("probeString") == "melange"
        and record.get("probeText") == "WaterDebt"
        and str(record.get("probeObject", "")).startswith("0x")
        and (raw_hits == 0 or raw_value in (7, 13, 17))
        and (raw_set_hits == 0 or (raw_set_hits == 1 and raw_set_value == 17 and raw_value == 17))
    )


def lua_reflection_array_inner_property_passed(record):
    return lua_reflection_self_test_passed(record) and record_int(record, "arrayInnerPropertyHits") > 0


def lua_reflection_enum_property_passed(record):
    return (
        lua_reflection_self_test_passed(record)
        and record_int(record, "enumPropertyHits") > 0
        and record_int(record, "enumUnderlyingPropertyHits") > 0
    )


def lua_reflection_container_property_passed(record):
    return (
        lua_reflection_self_test_passed(record)
        and record_int(record, "setElementPropertyHits") > 0
        and record_int(record, "mapKeyPropertyHits") > 0
        and record_int(record, "mapValuePropertyHits") > 0
    )


def lua_reflection_import_text_passed(record):
    return lua_reflection_self_test_passed(record) and record_int(record, "importTextHits") > 0


def lua_reflection_export_text_passed(record):
    return lua_reflection_self_test_passed(record) and record_int(record, "exportTextHits") > 0


def lua_reflection_property_metadata_passed(record):
    return lua_reflection_self_test_passed(record) and record_int(record, "propertyMetadataHits") > 0


def lua_reflection_descriptor_values_passed(record):
    return (
        lua_reflection_self_test_passed(record)
        and record_int(record, "descriptorValueGetHits") > 0
        and record_int(record, "descriptorValueSetHits") > 0
    )


def lua_reflection_numeric_property_values_passed(record):
    return (
        lua_reflection_self_test_passed(record)
        and record_int(record, "getPropertyHits") >= 17
        and record_int(record, "setPropertyHits") >= 8
        and abs(record_float(record, "probeFloat") - 13.75) < 0.001
        and abs(record_float(record, "probeDouble") + 47.5) < 0.001
    )


def lua_reflection_name_text_property_values_passed(record):
    return (
        lua_reflection_self_test_passed(record)
        and record_int(record, "getPropertyHits") >= 17
        and record_int(record, "setPropertyHits") >= 8
        and record.get("probeName") == "ArrakisName"
        and record.get("probeText") == "WaterDebt"
    )


def process_event_accessor_value(record, suffix, prefix=""):
    key = f"{prefix}{suffix}" if prefix else suffix[:1].lower() + suffix[1:]
    return record_int(record, key)


def process_event_param_accessors_passed(record, prefix=""):
    return (
        process_event_accessor_value(record, "ParamDescriptorHits", prefix) > 0
        and process_event_accessor_value(record, "ParamDescriptorLookupHits", prefix) > 0
        and process_event_accessor_value(record, "FunctionParamDescriptorCalls", prefix) > 0
        and process_event_accessor_value(record, "FunctionParamDescriptorHits", prefix) > 0
        and process_event_accessor_value(record, "ParamGetHits", prefix) > 0
        and process_event_accessor_value(record, "ParamSetHits", prefix) > 0
    )


def process_event_scalar_param_accessors_passed(record, prefix=""):
    return (
        process_event_accessor_value(record, "ParamDescriptorHits", prefix) >= 2
        and process_event_accessor_value(record, "ParamDescriptorLookupHits", prefix) >= 12
        and process_event_accessor_value(record, "FunctionParamDescriptorHits", prefix) >= 2
        and process_event_accessor_value(record, "ParamGetHits", prefix) >= 16
        and process_event_accessor_value(record, "ParamSetHits", prefix) >= 4
    )


def process_event_name_string_param_accessors_passed(record, prefix=""):
    return (
        process_event_accessor_value(record, "ParamDescriptorHits", prefix) >= 2
        and process_event_accessor_value(record, "ParamDescriptorLookupHits", prefix) >= 12
        and process_event_accessor_value(record, "FunctionParamDescriptorHits", prefix) >= 2
        and process_event_accessor_value(record, "ParamGetHits", prefix) >= 18
        and process_event_accessor_value(record, "ParamSetHits", prefix) >= 6
    )


def process_event_struct_param_accessors_passed(record, prefix=""):
    return (
        process_event_accessor_value(record, "ParamDescriptorHits", prefix) >= 2
        and process_event_accessor_value(record, "ParamDescriptorLookupHits", prefix) >= 13
        and process_event_accessor_value(record, "FunctionParamDescriptorHits", prefix) >= 2
        and process_event_accessor_value(record, "ParamGetHits", prefix) >= 21
        and process_event_accessor_value(record, "ParamSetHits", prefix) >= 7
    )


def function_flags_readable(record):
    return record.get("functionFlagsReadable") == "true" and "functionFlags" in record


def process_label(record):
    loader = record.get("loader", "")
    exe = record.get("exe", "")
    if loader:
        return loader
    if "TargetGameServer" in exe:
        return "server"
    if "TargetGame-Win64" in exe or exe.lower().endswith(".exe"):
        return "win-client"
    if "TargetGame" in exe:
        return "linux-client"
    return "client"


def matches_filters(record, loader_filter, pid_filter, exe_substrings):
    if loader_filter and record.get("loader") not in loader_filter:
        return False
    if pid_filter and record.get("pid") not in pid_filter:
        return False
    if exe_substrings:
        haystack = " ".join(
            value for value in (record.get("exe", ""), record.get("module", ""), record.get("map", "")) if value
        )
        if not any(substring in haystack for substring in exe_substrings):
            return False
    return True


def summarize(records, loader_filter=None, pid_filter=None, exe_substrings=None, expected=None):
    loader_filter = set(loader_filter or [])
    pid_filter = set(str(pid) for pid in (pid_filter or []))
    exe_substrings = tuple(exe_substrings or [])
    expected = tuple(expected or DEFAULT_EXPECTED)

    scoped_records = [
        record
        for record in records
        if matches_filters(record, loader_filter, pid_filter, exe_substrings)
    ]
    loaded = [record for record in scoped_records if record.get("event") == "loaded"]
    modules = [record for record in scoped_records if record.get("event") == "module"]
    starts = [record for record in scoped_records if record.get("event") == "scan-start"]
    finishes = [record for record in scoped_records if record.get("event") == "scan-finish"]
    skips = [record for record in scoped_records if record.get("event") == "scan-skip"]
    hits = [record for record in scoped_records if record.get("event") == "scan-hit"]
    ue_anchors = [record for record in scoped_records if record.get("event") == "ue-anchor"]
    mapped_ue_anchors = [record for record in ue_anchors if record.get("status") == "mapped"]
    ue_anchor_signatures = [
        record for record in scoped_records if record.get("event") == "ue-anchor-signature"
    ]
    resolved_ue_anchor_signatures = [
        record for record in ue_anchor_signatures if record.get("status") == "resolved"
    ]
    ue_pointers = [record for record in scoped_records if record.get("event") == "ue-pointer"]
    mapped_ue_pointers = [record for record in ue_pointers if record.get("status") == "target-mapped"]
    ue_layouts = [record for record in scoped_records if record.get("event") == "ue-layout"]
    readable_ue_layouts = [record for record in ue_layouts if record.get("status") == "target-readable"]
    ue_layout_slots = [record for record in scoped_records if record.get("event") == "ue-layout-slot"]
    mapped_ue_layout_slots = [record for record in ue_layout_slots if record.get("status") == "target-mapped"]
    ue_uobjects = [record for record in scoped_records if record.get("event") == "ue-uobject"]
    candidate_ue_uobjects = [record for record in ue_uobjects if record.get("status") == "candidate"]
    class_mapped_ue_uobjects = [
        record for record in candidate_ue_uobjects if record.get("classMapped") == "true"
    ]
    ue_reflections = [record for record in scoped_records if record.get("event") == "ue-reflection"]
    class_mapped_ue_reflections = [
        record for record in ue_reflections if record.get("status") == "class-mapped"
    ]
    ue_reflection_slots = [
        record for record in scoped_records if record.get("event") == "ue-reflection-slot"
    ]
    mapped_ue_reflection_slots = [
        record for record in ue_reflection_slots if record.get("status") == "target-mapped"
    ]
    ue_reflection_fields = [
        record for record in scoped_records if record.get("event") == "ue-reflection-field"
    ]
    candidate_ue_reflection_fields = [
        record for record in ue_reflection_fields if record.get("status") == "candidate"
    ]
    class_mapped_ue_reflection_fields = [
        record for record in candidate_ue_reflection_fields if record.get("classMapped") == "true"
    ]
    ue_reflection_properties = [
        record for record in scoped_records if record.get("event") == "ue-reflection-property"
    ]
    candidate_ue_reflection_properties = [
        record for record in ue_reflection_properties if record.get("status") == "candidate"
    ]
    readable_ue_reflection_properties = [
        record
        for record in candidate_ue_reflection_properties
        if record.get("arrayDimReadable") == "true"
        and record.get("elementSizeReadable") == "true"
        and record.get("propertyFlagsReadable") == "true"
        and record.get("offsetInternalReadable") == "true"
        and 0 < record_int(record, "arrayDim") <= 1024
        and 0 < record_int(record, "elementSize") <= 4096
        and record_int(record, "offsetInternal", -1) >= 0
    ]
    ue_reflection_values = [
        record for record in scoped_records if record.get("event") == "ue-reflection-value"
    ]
    read_ue_reflection_values = [
        record for record in ue_reflection_values if record.get("status") == "read"
    ]
    ue_function_param_roots = [
        record for record in scoped_records if record.get("event") == "ue-function-param-root"
    ]
    rooted_ue_function_param_roots = [
        record for record in ue_function_param_roots if record.get("status") == "root"
    ]
    ue_function_params = [record for record in scoped_records if record.get("event") == "ue-function-param"]
    candidate_ue_function_params = [
        record for record in ue_function_params if record.get("status") == "candidate"
    ]
    ue_function_param_container_children = [
        record for record in scoped_records if record.get("event") == "ue-function-param-container-child"
    ]
    candidate_ue_function_param_container_children = [
        record for record in ue_function_param_container_children if record.get("status") == "candidate"
    ]
    decoded_ue_function_param_container_children = [
        record
        for record in candidate_ue_function_param_container_children
        if record.get("childClassName") and record.get("role") in {"inner", "element", "key", "value"}
    ]
    readable_ue_function_params = [
        record
        for record in candidate_ue_function_params
        if record.get("arrayDimReadable") == "true"
        and record.get("elementSizeReadable") == "true"
        and record.get("propertyFlagsReadable") == "true"
        and record.get("offsetInternalReadable") == "true"
        and 0 < record_int(record, "arrayDim") <= 1024
        and 0 < record_int(record, "elementSize") <= 4096
        and record_int(record, "offsetInternal", -1) >= 0
    ]
    named_ue_function_params = [
        record
        for record in readable_ue_function_params
        if record.get("functionName") and record.get("functionPath")
    ]
    ue_function_paths = sorted(
        set(record.get("functionPath", "") for record in named_ue_function_params if record.get("functionPath"))
    )
    readable_ue_function_flag_roots = [
        record for record in rooted_ue_function_param_roots if function_flags_readable(record)
    ]
    readable_ue_function_flag_params = [
        record for record in candidate_ue_function_params if function_flags_readable(record)
    ]
    ue_function_flag_paths = sorted(
        set(record.get("functionPath", "") for record in readable_ue_function_flag_params if record.get("functionPath"))
    )
    ue_function_flag_values = sorted(
        set(record.get("functionFlags", "") for record in readable_ue_function_flag_roots + readable_ue_function_flag_params if record.get("functionFlags"))
    )
    hook_dispatches = [record for record in scoped_records if record.get("event") == "hook-dispatch"]
    hook_self_tests = [record for record in scoped_records if record.get("event") == "hook-dispatch-self-test"]
    passed_hook_self_tests = [record for record in hook_self_tests if record.get("status") == "passed"]
    mod_self_tests = [record for record in scoped_records if record.get("event") == "mod-dispatch-self-test"]
    passed_mod_self_tests = [record for record in mod_self_tests if record.get("status") == "passed"]
    lua_self_tests = [record for record in scoped_records if record.get("event") == "lua-dispatch-self-test"]
    passed_lua_self_tests = [record for record in lua_self_tests if record.get("status") == "passed"]
    passed_lua_callback_self_tests = [
        record
        for record in passed_lua_self_tests
        if record.get("callbackStatus") == "0"
        and record.get("preCalls") == "1"
        and record.get("postCalls") == "1"
        and record.get("preResult") == "11"
        and record.get("postResult") == "31"
        and record.get("preIsNumber") == "true"
        and record.get("postIsNumber") == "true"
    ]
    passed_lua_api_self_tests = [
        record
        for record in passed_lua_callback_self_tests
        if record.get("staticFindObjectCalls") == "1"
        and record.get("staticFindObjectHits") == "1"
        and lua_object_api_surface_passed(record)
        and record.get("findFirstOfCalls") == "1"
        and record.get("findFirstOfHits") == "1"
        and record.get("staticConstructObjectCalls") == "1"
        and record.get("staticConstructObjectHits") == "1"
        and record.get("notifyOnNewObjectCalls") == "1"
        and record.get("executeInGameThreadCalls") == "1"
        and record.get("executeInGameThreadCallbacks") == "1"
        and record.get("executeInGameThreadResult") == "9"
        and record.get("executeInGameThreadIsNumber") == "true"
    ]
    passed_lua_object_api_self_tests = [
        record for record in passed_lua_callback_self_tests if lua_object_api_surface_passed(record)
    ]
    lua_reflection_self_tests = [
        record for record in scoped_records if record.get("event") == "lua-reflection-self-test"
    ]
    passed_lua_reflection_self_tests = [
        record
        for record in lua_reflection_self_tests
        if lua_reflection_self_test_passed(record)
    ]
    raw_set_lua_reflection_self_tests = [
        record
        for record in passed_lua_reflection_self_tests
        if record_int(record, "rawPropertySetHits") > 0
    ]
    named_lua_reflection_self_tests = [
        record
        for record in passed_lua_reflection_self_tests
        if record_int(record, "namedPropertyHits") > 0
    ]
    numeric_lua_reflection_self_tests = [
        record
        for record in passed_lua_reflection_self_tests
        if lua_reflection_numeric_property_values_passed(record)
    ]
    name_text_lua_reflection_self_tests = [
        record
        for record in passed_lua_reflection_self_tests
        if lua_reflection_name_text_property_values_passed(record)
    ]
    array_inner_lua_reflection_self_tests = [
        record
        for record in passed_lua_reflection_self_tests
        if lua_reflection_array_inner_property_passed(record)
    ]
    enum_lua_reflection_self_tests = [
        record
        for record in passed_lua_reflection_self_tests
        if lua_reflection_enum_property_passed(record)
    ]
    container_lua_reflection_self_tests = [
        record
        for record in passed_lua_reflection_self_tests
        if lua_reflection_container_property_passed(record)
    ]
    import_text_lua_reflection_self_tests = [
        record
        for record in passed_lua_reflection_self_tests
        if lua_reflection_import_text_passed(record)
    ]
    export_text_lua_reflection_self_tests = [
        record
        for record in passed_lua_reflection_self_tests
        if lua_reflection_export_text_passed(record)
    ]
    property_metadata_lua_reflection_self_tests = [
        record
        for record in passed_lua_reflection_self_tests
        if lua_reflection_property_metadata_passed(record)
    ]
    descriptor_value_lua_reflection_self_tests = [
        record
        for record in passed_lua_reflection_self_tests
        if lua_reflection_descriptor_values_passed(record)
    ]
    lua_process_event_self_tests = [
        record for record in scoped_records if record.get("event") == "lua-process-event-self-test"
    ]
    passed_lua_process_event_self_tests = [
        record
        for record in lua_process_event_self_tests
        if record.get("status") == "passed"
        and record.get("installed") == "true"
        and record.get("restored") == "true"
        and record.get("hookCalls") == "1"
        and record.get("originalAfterHook") == "1"
        and record.get("preStatus") == "0"
        and record.get("postStatus") == "0"
        and record.get("preCalls") == "1"
        and record.get("postCalls") == "1"
        and record.get("preResult") == "11"
        and record.get("postResult") == "31"
        and record.get("paramsResult") == "42"
        and record.get("finalResult") == "52"
    ]
    lua_process_event_param_accessor_self_tests = [
        record
        for record in passed_lua_process_event_self_tests
        if process_event_param_accessors_passed(record)
    ]
    lua_process_event_scalar_param_accessor_self_tests = [
        record
        for record in passed_lua_process_event_self_tests
        if process_event_scalar_param_accessors_passed(record)
    ]
    lua_process_event_name_string_param_accessor_self_tests = [
        record
        for record in passed_lua_process_event_self_tests
        if process_event_name_string_param_accessors_passed(record)
    ]
    lua_process_event_struct_param_accessor_self_tests = [
        record
        for record in passed_lua_process_event_self_tests
        if process_event_struct_param_accessors_passed(record)
    ]
    routed_lua_process_event_self_tests = [
        record
        for record in passed_lua_process_event_self_tests
        if record_int(record, "hooks") > record_int(record, "preCalls")
        and record_int(record, "preCalls") == record_int(record, "postCalls")
        and record_int(record, "preCalls") > 0
    ]
    lua_mod_scripts = [record for record in scoped_records if record.get("event") == "lua-mod-script"]
    passed_lua_mod_scripts = [record for record in lua_mod_scripts if record.get("status") == "passed"]
    lua_mod_dispatch_self_tests = [
        record for record in scoped_records if record.get("event") == "lua-mod-dispatch-self-test"
    ]
    passed_lua_mod_dispatch_self_tests = [
        record for record in lua_mod_dispatch_self_tests if record.get("status") == "passed"
    ]
    lua_mod_finishes = [record for record in scoped_records if record.get("event") == "lua-mod-finish"]
    passed_lua_mod_finishes = [record for record in lua_mod_finishes if record.get("status") == "passed"]
    lua_object_api_mod_finishes = [
        record for record in passed_lua_mod_finishes if lua_object_api_surface_passed(record)
    ]
    lua_function_iteration_mod_finishes = [
        record for record in passed_lua_mod_finishes if lua_function_iteration_surface_passed(record)
    ]
    lua_notify_on_new_object_mod_finishes = [
        record for record in passed_lua_mod_finishes if lua_notify_on_new_object_surface_passed(record)
    ]
    lua_synthetic_outer_mod_finishes = [
        record for record in passed_lua_mod_finishes if lua_synthetic_outer_surface_passed(record)
    ]
    lua_world_context_mod_finishes = [
        record for record in passed_lua_mod_finishes if lua_world_context_surface_passed(record)
    ]
    lua_class_default_object_mod_finishes = [
        record for record in passed_lua_mod_finishes if lua_class_default_object_surface_passed(record)
    ]
    lua_level_mod_finishes = [
        record for record in passed_lua_mod_finishes if lua_level_surface_passed(record)
    ]
    lua_process_console_exec_hook_mod_finishes = [
        record for record in passed_lua_mod_finishes if lua_process_console_exec_hook_surface_passed(record)
    ]
    lua_local_player_exec_hook_mod_finishes = [
        record for record in passed_lua_mod_finishes if lua_local_player_exec_hook_surface_passed(record)
    ]
    lua_call_function_hook_mod_finishes = [
        record for record in passed_lua_mod_finishes if lua_call_function_hook_surface_passed(record)
    ]
    lua_lifecycle_hook_mod_finishes = [
        record for record in passed_lua_mod_finishes if lua_lifecycle_hook_surface_passed(record)
    ]
    lua_object_registry = [record for record in scoped_records if record.get("event") == "lua-object-registry"]
    added_lua_object_registry = [record for record in lua_object_registry if record.get("status") == "added"]
    ue_lua_object_registry = [
        record for record in added_lua_object_registry if record.get("source") == "ue-uobject"
    ]
    object_array_lua_object_registry = [
        record for record in added_lua_object_registry if record.get("source") == "ue-object-array"
    ]
    decoded_lua_object_alias_registry = [
        record
        for record in added_lua_object_registry
        if record.get("source") in ("ue-uobject-fname", "ue-object-array-fname")
    ]
    skipped_decoded_lua_object_alias_registry = [
        record
        for record in lua_object_registry
        if record.get("status") == "skipped"
        and record.get("source") in ("ue-uobject-fname", "ue-object-array-fname")
    ]
    ue_object_arrays = [record for record in scoped_records if record.get("event") == "ue-object-array"]
    finished_ue_object_arrays = [
        record for record in ue_object_arrays if record.get("status") == "finished"
    ]
    ue_object_array_items = [
        record for record in scoped_records if record.get("event") == "ue-object-array-item"
    ]
    internal_flag_ue_object_array_items = [
        record for record in ue_object_array_items if record.get("internalFlagsReadable") == "true"
    ]
    nonzero_internal_flag_ue_object_array_items = [
        record
        for record in internal_flag_ue_object_array_items
        if record_int(record, "internalFlags") != 0
    ]
    ue_fnames = [record for record in scoped_records if record.get("event") == "ue-fname"]
    decoded_ue_fnames = [record for record in ue_fnames if record.get("status") == "decoded"]
    ue_process_event_hooks = [
        record for record in scoped_records if record.get("event") == "ue-process-event-hook"
    ]
    passed_ue_process_event_hooks = [
        record for record in ue_process_event_hooks if record.get("status") == "passed"
    ]
    ue_process_event_live_hooks = [
        record for record in scoped_records if record.get("event") == "ue-process-event-live-hook"
    ]
    installed_ue_process_event_live_hooks = [
        record for record in ue_process_event_live_hooks if record.get("status") == "installed"
    ]
    ue_process_event_live_contexts = [
        record for record in scoped_records if record.get("event") == "ue-process-event-live-context"
    ]
    resolved_ue_process_event_live_contexts = [
        record
        for record in ue_process_event_live_contexts
        if record.get("status") == "resolved"
        and record.get("objectResolved") == "true"
        and record.get("functionPath")
        and record_int(record, "functionParamDescriptors") > 0
        and record.get("paramsPresent") == "true"
    ]
    ue_process_event_live_params = [
        record for record in scoped_records if record.get("event") == "ue-process-event-live-param"
    ]
    read_ue_process_event_live_params = [
        record
        for record in ue_process_event_live_params
        if record.get("status") == "read"
        and record.get("functionPath")
        and record.get("param")
        and record_int(record, "size") > 0
    ]
    raw_ue_process_event_live_params = [
        record
        for record in ue_process_event_live_params
        if record.get("status") == "raw"
        and record.get("functionPath")
        and record.get("param")
        and record_int(record, "size") > 0
        and "rawHex=" in record.get("value", "")
    ]
    container_ue_process_event_live_params = [
        record
        for record in ue_process_event_live_params
        if record.get("status") == "container"
        and record.get("functionPath")
        and record.get("param")
        and record_int(record, "size") > 0
        and "kind=" in record.get("value", "")
        and "rawHex=" in record.get("value", "")
    ]
    sampled_container_ue_process_event_live_params = [
        record
        for record in container_ue_process_event_live_params
        if "dataSampleHex=" in record.get("value", "")
    ]
    ue_process_event_lua_context_handle_hooks = [
        record
        for record in installed_ue_process_event_live_hooks
        if record_int(record, "luaObjectHandleHits") > 0
        and record_int(record, "luaFunctionHandleHits") > 0
        and record_int(record, "luaParamsHandleHits") > 0
    ]
    ue_process_event_live_lua_param_accessor_hooks = [
        record
        for record in installed_ue_process_event_live_hooks
        if process_event_param_accessors_passed(record, "lua")
    ]
    ue_process_event_live_lua_scalar_param_accessor_hooks = [
        record
        for record in installed_ue_process_event_live_hooks
        if process_event_scalar_param_accessors_passed(record, "lua")
    ]
    ue_process_event_live_lua_name_string_param_accessor_hooks = [
        record
        for record in installed_ue_process_event_live_hooks
        if process_event_name_string_param_accessors_passed(record, "lua")
    ]
    ue_process_event_live_lua_struct_param_accessor_hooks = [
        record
        for record in installed_ue_process_event_live_hooks
        if process_event_struct_param_accessors_passed(record, "lua")
    ]
    routed_ue_process_event_live_lua_hooks = [
        record
        for record in installed_ue_process_event_live_hooks
        if record.get("luaDispatch") == "true"
        and record_int(record, "luaPreCalls") > 0
        and record_int(record, "luaPostCalls") > 0
    ]
    restored_ue_process_event_live_hooks = [
        record for record in ue_process_event_live_hooks if record.get("status") == "restored"
    ]
    ue_process_event_dispatch_self_tests = [
        record for record in scoped_records if record.get("event") == "ue-process-event-dispatch-self-test"
    ]
    armed_ue_process_event_dispatch_self_tests = [
        record for record in ue_process_event_dispatch_self_tests if record.get("status") == "armed"
    ]
    ue_process_event_live_lua_dispatches = [
        record for record in scoped_records if record.get("event") == "ue-process-event-live-lua-dispatch"
    ]
    armed_ue_process_event_live_lua_dispatches = [
        record for record in ue_process_event_live_lua_dispatches if record.get("status") == "armed"
    ]
    multi_hook_ue_process_event_live_lua_dispatches = [
        record for record in armed_ue_process_event_live_lua_dispatches if record_int(record, "hooks") > 1
    ]
    closed_ue_process_event_live_lua_dispatches = [
        record for record in ue_process_event_live_lua_dispatches if record.get("status") == "closed"
    ]
    forward_smokes = [record for record in scoped_records if record.get("event") == "forward-smoke"]

    if not loaded and not hits and (loader_filter or pid_filter or exe_substrings):
        # Some logs put exe only on event=loaded. If an exe filter was too narrow,
        # still return an empty scoped summary rather than guessing.
        pass

    categories = Counter()
    hits_by_name = {}
    offsets_by_name = defaultdict(list)
    kinds_by_name = defaultdict(Counter)
    sources_by_name = defaultdict(Counter)
    pointers_by_name = defaultdict(list)
    layouts_by_name = defaultdict(list)
    layout_slots_by_name = defaultdict(list)
    uobjects_by_name = defaultdict(list)
    fnames_by_object_name = defaultdict(list)

    anchor_hit_records = hits + mapped_ue_anchors + resolved_ue_anchor_signatures
    for hit in anchor_hit_records:
        name = hit.get("name", "")
        if not name:
            continue
        categories[category_for(name)] += 1
        kind = hit.get("kind") or hit.get("event", "")
        if hit.get("event") == "ue-anchor-signature":
            kind = "ue-anchor-signature"
        kinds_by_name[name][kind] += 1
        source = record_source(hit)
        if source:
            sources_by_name[name][source] += 1
        offsets_by_name[name].append(
            {
                "kind": kind,
                "addr": hit.get("addr", ""),
                "offset": record_offset(hit),
                "imageOffset": hit.get("imageOffset", ""),
                "fileOffset": hit.get("fileOffset", ""),
                "rva": hit.get("rva", ""),
                "source": source,
            }
        )

    for name in sorted(offsets_by_name):
        offsets = offsets_by_name[name]
        hits_by_name[name] = {
            "category": category_for(name),
            "count": len(offsets),
            "kinds": dict(kinds_by_name[name]),
            "sources": dict(sources_by_name[name]),
            "first": offsets[0],
            "offsets": offsets,
        }

    for pointer in ue_pointers:
        name = pointer.get("name", "")
        if name:
            pointers_by_name[name].append(pointer)

    for layout in ue_layouts:
        name = layout.get("name", "")
        if name:
            layouts_by_name[name].append(layout)
    for slot in ue_layout_slots:
        name = slot.get("name", "")
        if name:
            layout_slots_by_name[name].append(slot)
    for uobject in ue_uobjects:
        name = uobject.get("name", "")
        if name:
            uobjects_by_name[name].append(uobject)
    for fname in ue_fnames:
        name = fname.get("objectName", "")
        if name:
            fnames_by_object_name[name].append(fname)

    present_names = set(hits_by_name)
    expected_status = {
        name: {
            "present": name in present_names,
            "category": category_for(name),
            "count": hits_by_name.get(name, {}).get("count", 0),
            "first": hits_by_name.get(name, {}).get("first", {}),
        }
        for name in expected
    }

    module_paths = []
    seen_modules = set()
    for module in modules:
        path = module.get("path") or module.get("name") or module.get("module") or ""
        if path and path not in seen_modules:
            seen_modules.add(path)
            module_paths.append(path)

    return {
        "recordCount": len(scoped_records),
        "loadCount": len(loaded),
        "moduleCount": len(modules),
        "scanStartCount": len(starts),
        "scanFinishCount": len(finishes),
        "scanSkipCount": len(skips),
        "hitCount": len(hits),
        "ueAnchorCount": len(ue_anchors),
        "mappedUeAnchorCount": len(mapped_ue_anchors),
        "ueAnchorSignatureCount": len(ue_anchor_signatures),
        "resolvedUeAnchorSignatureCount": len(resolved_ue_anchor_signatures),
        "ueAnchorSignatureStatusCounts": dict(Counter(record.get("status", "") for record in ue_anchor_signatures)),
        "uePointerCount": len(ue_pointers),
        "mappedUePointerCount": len(mapped_ue_pointers),
        "ueLayoutCount": len(ue_layouts),
        "readableUeLayoutCount": len(readable_ue_layouts),
        "ueLayoutSlotCount": len(ue_layout_slots),
        "mappedUeLayoutSlotCount": len(mapped_ue_layout_slots),
        "ueUObjectCount": len(ue_uobjects),
        "candidateUeUObjectCount": len(candidate_ue_uobjects),
        "classMappedUeUObjectCount": len(class_mapped_ue_uobjects),
        "ueReflectionCount": len(ue_reflections),
        "classMappedUeReflectionCount": len(class_mapped_ue_reflections),
        "ueReflectionSlotCount": len(ue_reflection_slots),
        "mappedUeReflectionSlotCount": len(mapped_ue_reflection_slots),
        "ueReflectionFieldCount": len(ue_reflection_fields),
        "candidateUeReflectionFieldCount": len(candidate_ue_reflection_fields),
        "classMappedUeReflectionFieldCount": len(class_mapped_ue_reflection_fields),
        "ueReflectionPropertyCount": len(ue_reflection_properties),
        "candidateUeReflectionPropertyCount": len(candidate_ue_reflection_properties),
        "readableUeReflectionPropertyCount": len(readable_ue_reflection_properties),
        "ueReflectionValueCount": len(ue_reflection_values),
        "readUeReflectionValueCount": len(read_ue_reflection_values),
        "ueFunctionParamRootCount": len(ue_function_param_roots),
        "rootedUeFunctionParamRootCount": len(rooted_ue_function_param_roots),
        "ueFunctionParamCount": len(ue_function_params),
        "candidateUeFunctionParamCount": len(candidate_ue_function_params),
        "ueFunctionParamContainerChildCount": len(ue_function_param_container_children),
        "candidateUeFunctionParamContainerChildCount": len(candidate_ue_function_param_container_children),
        "decodedUeFunctionParamContainerChildCount": len(decoded_ue_function_param_container_children),
        "readableUeFunctionParamCount": len(readable_ue_function_params),
        "namedUeFunctionParamCount": len(named_ue_function_params),
        "uniqueUeFunctionPathCount": len(ue_function_paths),
        "ueFunctionPaths": ue_function_paths,
        "readableUeFunctionFlagRootCount": len(readable_ue_function_flag_roots),
        "readableUeFunctionFlagParamCount": len(readable_ue_function_flag_params),
        "ueFunctionFlagPathCount": len(ue_function_flag_paths),
        "ueFunctionFlagPaths": ue_function_flag_paths,
        "ueFunctionFlagValues": ue_function_flag_values,
        "hookDispatchCount": len(hook_dispatches),
        "hookSelfTestCount": len(hook_self_tests),
        "passedHookSelfTestCount": len(passed_hook_self_tests),
        "modSelfTestCount": len(mod_self_tests),
        "passedModSelfTestCount": len(passed_mod_self_tests),
        "luaSelfTestCount": len(lua_self_tests),
        "passedLuaSelfTestCount": len(passed_lua_self_tests),
        "passedLuaCallbackSelfTestCount": len(passed_lua_callback_self_tests),
        "passedLuaApiSelfTestCount": len(passed_lua_api_self_tests),
        "passedLuaObjectApiSelfTestCount": len(passed_lua_object_api_self_tests),
        "luaReflectionSelfTestCount": len(lua_reflection_self_tests),
        "passedLuaReflectionSelfTestCount": len(passed_lua_reflection_self_tests),
        "rawSetLuaReflectionSelfTestCount": len(raw_set_lua_reflection_self_tests),
        "namedLuaReflectionSelfTestCount": len(named_lua_reflection_self_tests),
        "numericLuaReflectionSelfTestCount": len(numeric_lua_reflection_self_tests),
        "nameTextLuaReflectionSelfTestCount": len(name_text_lua_reflection_self_tests),
        "arrayInnerLuaReflectionSelfTestCount": len(array_inner_lua_reflection_self_tests),
        "enumLuaReflectionSelfTestCount": len(enum_lua_reflection_self_tests),
        "containerLuaReflectionSelfTestCount": len(container_lua_reflection_self_tests),
        "importTextLuaReflectionSelfTestCount": len(import_text_lua_reflection_self_tests),
        "exportTextLuaReflectionSelfTestCount": len(export_text_lua_reflection_self_tests),
        "propertyMetadataLuaReflectionSelfTestCount": len(property_metadata_lua_reflection_self_tests),
        "descriptorValueLuaReflectionSelfTestCount": len(descriptor_value_lua_reflection_self_tests),
        "luaProcessEventSelfTestCount": len(lua_process_event_self_tests),
        "passedLuaProcessEventSelfTestCount": len(passed_lua_process_event_self_tests),
        "luaProcessEventParamAccessorSelfTestCount": len(lua_process_event_param_accessor_self_tests),
        "luaProcessEventScalarParamAccessorSelfTestCount": len(lua_process_event_scalar_param_accessor_self_tests),
        "luaProcessEventNameStringParamAccessorSelfTestCount": len(lua_process_event_name_string_param_accessor_self_tests),
        "luaProcessEventStructParamAccessorSelfTestCount": len(lua_process_event_struct_param_accessor_self_tests),
        "routedLuaProcessEventSelfTestCount": len(routed_lua_process_event_self_tests),
        "luaModScriptCount": len(lua_mod_scripts),
        "passedLuaModScriptCount": len(passed_lua_mod_scripts),
        "luaModDispatchSelfTestCount": len(lua_mod_dispatch_self_tests),
        "passedLuaModDispatchSelfTestCount": len(passed_lua_mod_dispatch_self_tests),
        "luaModFinishCount": len(lua_mod_finishes),
        "passedLuaModFinishCount": len(passed_lua_mod_finishes),
        "luaObjectApiModFinishCount": len(lua_object_api_mod_finishes),
        "luaFunctionIterationModFinishCount": len(lua_function_iteration_mod_finishes),
        "luaProcessConsoleExecHookModFinishCount": len(lua_process_console_exec_hook_mod_finishes),
        "luaLocalPlayerExecHookModFinishCount": len(lua_local_player_exec_hook_mod_finishes),
        "luaCallFunctionHookModFinishCount": len(lua_call_function_hook_mod_finishes),
        "luaLifecycleHookModFinishCount": len(lua_lifecycle_hook_mod_finishes),
        "luaNotifyOnNewObjectModFinishCount": len(lua_notify_on_new_object_mod_finishes),
        "luaSyntheticOuterModFinishCount": len(lua_synthetic_outer_mod_finishes),
        "luaWorldContextModFinishCount": len(lua_world_context_mod_finishes),
        "luaClassDefaultObjectModFinishCount": len(lua_class_default_object_mod_finishes),
        "luaLevelModFinishCount": len(lua_level_mod_finishes),
        "luaObjectRegistryCount": len(lua_object_registry),
        "addedLuaObjectRegistryCount": len(added_lua_object_registry),
        "ueLuaObjectRegistryCount": len(ue_lua_object_registry),
        "objectArrayLuaObjectRegistryCount": len(object_array_lua_object_registry),
        "decodedLuaObjectAliasRegistryCount": len(decoded_lua_object_alias_registry),
        "skippedDecodedLuaObjectAliasRegistryCount": len(skipped_decoded_lua_object_alias_registry),
        "ueObjectArrayCount": len(ue_object_arrays),
        "finishedUeObjectArrayCount": len(finished_ue_object_arrays),
        "ueObjectArrayItemCount": len(ue_object_array_items),
        "internalFlagUeObjectArrayItemCount": len(internal_flag_ue_object_array_items),
        "nonzeroInternalFlagUeObjectArrayItemCount": len(nonzero_internal_flag_ue_object_array_items),
        "ueFNameCount": len(ue_fnames),
        "decodedUeFNameCount": len(decoded_ue_fnames),
        "ueProcessEventHookCount": len(ue_process_event_hooks),
        "passedUeProcessEventHookCount": len(passed_ue_process_event_hooks),
        "ueProcessEventLiveHookCount": len(ue_process_event_live_hooks),
        "installedUeProcessEventLiveHookCount": len(installed_ue_process_event_live_hooks),
        "ueProcessEventLiveContextCount": len(ue_process_event_live_contexts),
        "resolvedUeProcessEventLiveContextCount": len(resolved_ue_process_event_live_contexts),
        "ueProcessEventLiveParamCount": len(ue_process_event_live_params),
        "readUeProcessEventLiveParamCount": len(read_ue_process_event_live_params),
        "rawUeProcessEventLiveParamCount": len(raw_ue_process_event_live_params),
        "containerUeProcessEventLiveParamCount": len(container_ue_process_event_live_params),
        "sampledContainerUeProcessEventLiveParamCount": len(sampled_container_ue_process_event_live_params),
        "ueProcessEventLuaContextHandleCount": len(ue_process_event_lua_context_handle_hooks),
        "ueProcessEventLiveLuaParamAccessorCount": len(ue_process_event_live_lua_param_accessor_hooks),
        "ueProcessEventLiveLuaScalarParamAccessorCount": len(ue_process_event_live_lua_scalar_param_accessor_hooks),
        "ueProcessEventLiveLuaNameStringParamAccessorCount": len(ue_process_event_live_lua_name_string_param_accessor_hooks),
        "ueProcessEventLiveLuaStructParamAccessorCount": len(ue_process_event_live_lua_struct_param_accessor_hooks),
        "routedUeProcessEventLiveLuaHookCount": len(routed_ue_process_event_live_lua_hooks),
        "restoredUeProcessEventLiveHookCount": len(restored_ue_process_event_live_hooks),
        "ueProcessEventLiveHookStatusCounts": dict(Counter(record.get("status", "") for record in ue_process_event_live_hooks)),
        "ueProcessEventDispatchSelfTestCount": len(ue_process_event_dispatch_self_tests),
        "armedUeProcessEventDispatchSelfTestCount": len(armed_ue_process_event_dispatch_self_tests),
        "ueProcessEventLiveLuaDispatchCount": len(ue_process_event_live_lua_dispatches),
        "armedUeProcessEventLiveLuaDispatchCount": len(armed_ue_process_event_live_lua_dispatches),
        "multiHookUeProcessEventLiveLuaDispatchCount": len(multi_hook_ue_process_event_live_lua_dispatches),
        "closedUeProcessEventLiveLuaDispatchCount": len(closed_ue_process_event_live_lua_dispatches),
        "ueProcessEventLiveLuaDispatchStatusCounts": dict(Counter(record.get("status", "") for record in ue_process_event_live_lua_dispatches)),
        "uniqueHitCount": len(hits_by_name),
        "forwardSmokeCount": len(forward_smokes),
        "loaders": sorted(set(record.get("loader", process_label(record)) for record in loaded + hits)),
        "pids": sorted(set(record.get("pid", "") for record in loaded + hits if record.get("pid"))),
        "loaded": loaded,
        "modules": module_paths,
        "scanStarts": starts,
        "scanFinishes": finishes,
        "scanSkips": skips,
        "ueAnchors": ue_anchors,
        "ueAnchorSignatures": ue_anchor_signatures,
        "uePointers": ue_pointers,
        "uePointersByName": dict(sorted(pointers_by_name.items())),
        "ueLayouts": ue_layouts,
        "ueLayoutsByName": dict(sorted(layouts_by_name.items())),
        "ueLayoutSlots": ue_layout_slots,
        "ueLayoutSlotsByName": dict(sorted(layout_slots_by_name.items())),
        "ueUObjects": ue_uobjects,
        "ueUObjectsByName": dict(sorted(uobjects_by_name.items())),
        "ueReflectionFields": ue_reflection_fields,
        "ueReflectionProperties": ue_reflection_properties,
        "ueReflectionValues": ue_reflection_values,
        "ueFunctionParamRoots": ue_function_param_roots,
        "ueFunctionParams": ue_function_params,
        "hookDispatches": hook_dispatches,
        "hookSelfTests": hook_self_tests,
        "modSelfTests": mod_self_tests,
        "luaSelfTests": lua_self_tests,
        "luaReflectionSelfTests": lua_reflection_self_tests,
        "luaProcessEventSelfTests": lua_process_event_self_tests,
        "luaModScripts": lua_mod_scripts,
        "luaModDispatchSelfTests": lua_mod_dispatch_self_tests,
        "luaModFinishes": lua_mod_finishes,
        "luaObjectRegistry": lua_object_registry,
        "ueObjectArrays": ue_object_arrays,
        "ueObjectArrayItems": ue_object_array_items,
        "ueFNames": ue_fnames,
        "ueProcessEventHooks": ue_process_event_hooks,
        "ueProcessEventLiveHooks": ue_process_event_live_hooks,
        "ueProcessEventLiveContexts": ue_process_event_live_contexts,
        "ueProcessEventLiveParams": ue_process_event_live_params,
        "ueProcessEventDispatchSelfTests": ue_process_event_dispatch_self_tests,
        "ueProcessEventLiveLuaDispatches": ue_process_event_live_lua_dispatches,
        "ueFNamesByObjectName": dict(sorted(fnames_by_object_name.items())),
        "forwardSmokes": forward_smokes,
        "categories": dict(sorted(categories.items())),
        "expected": expected_status,
        "missingExpected": [name for name, status in expected_status.items() if not status["present"]],
        "hitsByName": hits_by_name,
    }


def markdown(summary, top):
    lines = []
    lines.append("# Client Loader Scan Summary")
    lines.append("")
    lines.append(f"- Loaders: `{', '.join(summary['loaders']) or 'unknown'}`")
    lines.append(f"- PIDs: `{', '.join(summary['pids']) or 'none'}`")
    lines.append(f"- Loaded events: `{summary['loadCount']}`")
    lines.append(f"- Module events: `{summary['moduleCount']}`")
    lines.append(f"- Scan starts: `{summary['scanStartCount']}`")
    lines.append(f"- Scan finishes: `{summary['scanFinishCount']}`")
    lines.append(f"- Hit count: `{summary['hitCount']}`")
    if summary["ueAnchorCount"]:
        lines.append(f"- UE anchors: `{summary['mappedUeAnchorCount']}/{summary['ueAnchorCount']}` mapped")
    if summary["ueAnchorSignatureCount"]:
        lines.append(
            f"- UE anchor signatures: `{summary['resolvedUeAnchorSignatureCount']}/{summary['ueAnchorSignatureCount']}` "
            f"resolved status={summary['ueAnchorSignatureStatusCounts']}"
        )
    if summary["uePointerCount"]:
        lines.append(f"- UE pointers: `{summary['mappedUePointerCount']}/{summary['uePointerCount']}` target-mapped")
    if summary["ueLayoutCount"] or summary["ueLayoutSlotCount"]:
        lines.append(
            f"- UE layouts: `{summary['readableUeLayoutCount']}/{summary['ueLayoutCount']}` readable, "
            f"slots `{summary['mappedUeLayoutSlotCount']}/{summary['ueLayoutSlotCount']}` target-mapped"
        )
    if summary["ueUObjectCount"]:
        lines.append(
            f"- UE UObject candidates: `{summary['candidateUeUObjectCount']}/{summary['ueUObjectCount']}` "
            f"candidates, class-mapped `{summary['classMappedUeUObjectCount']}`"
        )
    if summary["ueProcessEventHookCount"]:
        lines.append(
            f"- UE ProcessEvent hook probes: "
            f"`{summary['passedUeProcessEventHookCount']}/{summary['ueProcessEventHookCount']}` passed"
        )
    if summary["ueProcessEventLiveHookCount"]:
        lines.append(
            f"- UE ProcessEvent live hooks: "
            f"`{summary['installedUeProcessEventLiveHookCount']}/{summary['ueProcessEventLiveHookCount']}` installed, "
            f"Lua context handles `{summary['ueProcessEventLuaContextHandleCount']}`, "
            f"function-descriptor Lua params accessors `{summary['ueProcessEventLiveLuaParamAccessorCount']}`, "
            f"restored `{summary['restoredUeProcessEventLiveHookCount']}` "
            f"status={summary['ueProcessEventLiveHookStatusCounts']}"
        )
    if summary["ueProcessEventDispatchSelfTestCount"]:
        lines.append(
            f"- UE ProcessEvent dispatch self-tests: "
            f"`{summary['armedUeProcessEventDispatchSelfTestCount']}/{summary['ueProcessEventDispatchSelfTestCount']}` armed"
        )
    if summary["ueProcessEventLiveLuaDispatchCount"]:
        lines.append(
            f"- UE ProcessEvent live Lua dispatch: "
            f"`{summary['armedUeProcessEventLiveLuaDispatchCount']}/{summary['ueProcessEventLiveLuaDispatchCount']}` armed, "
            f"closed `{summary['closedUeProcessEventLiveLuaDispatchCount']}` "
            f"status={summary['ueProcessEventLiveLuaDispatchStatusCounts']}"
        )
    if summary["hookSelfTestCount"]:
        lines.append(
            f"- Hook dispatch self-tests: `{summary['passedHookSelfTestCount']}/{summary['hookSelfTestCount']}` passed"
        )
    if summary["modSelfTestCount"]:
        lines.append(
            f"- Mod dispatch self-tests: `{summary['passedModSelfTestCount']}/{summary['modSelfTestCount']}` passed"
        )
    if summary["luaSelfTestCount"]:
        lines.append(
            f"- Lua dispatch self-tests: `{summary['passedLuaSelfTestCount']}/{summary['luaSelfTestCount']}` passed, "
            f"callback bridge `{summary['passedLuaCallbackSelfTestCount']}`, "
            f"api surface `{summary['passedLuaApiSelfTestCount']}`, "
            f"object API `{summary['passedLuaObjectApiSelfTestCount']}`"
        )
    if summary["luaReflectionSelfTestCount"]:
        detail = f"`{summary['passedLuaReflectionSelfTestCount']}/{summary['luaReflectionSelfTestCount']}` passed"
        if summary.get("namedLuaReflectionSelfTestCount", 0):
            detail += f", named-property `{summary['namedLuaReflectionSelfTestCount']}`"
        if summary.get("rawSetLuaReflectionSelfTestCount", 0):
            detail += f", raw-set `{summary['rawSetLuaReflectionSelfTestCount']}`"
        if summary.get("numericLuaReflectionSelfTestCount", 0):
            detail += f", numeric-values `{summary['numericLuaReflectionSelfTestCount']}`"
        if summary.get("nameTextLuaReflectionSelfTestCount", 0):
            detail += f", name-text-values `{summary['nameTextLuaReflectionSelfTestCount']}`"
        if summary.get("arrayInnerLuaReflectionSelfTestCount", 0):
            detail += f", array-inner `{summary['arrayInnerLuaReflectionSelfTestCount']}`"
        if summary.get("enumLuaReflectionSelfTestCount", 0):
            detail += f", enum-property `{summary['enumLuaReflectionSelfTestCount']}`"
        if summary.get("containerLuaReflectionSelfTestCount", 0):
            detail += f", container-property `{summary['containerLuaReflectionSelfTestCount']}`"
        if summary.get("importTextLuaReflectionSelfTestCount", 0):
            detail += f", import-text `{summary['importTextLuaReflectionSelfTestCount']}`"
        if summary.get("exportTextLuaReflectionSelfTestCount", 0):
            detail += f", export-text `{summary['exportTextLuaReflectionSelfTestCount']}`"
        if summary.get("propertyMetadataLuaReflectionSelfTestCount", 0):
            detail += f", property-metadata `{summary['propertyMetadataLuaReflectionSelfTestCount']}`"
        if summary.get("descriptorValueLuaReflectionSelfTestCount", 0):
            detail += f", descriptor-values `{summary['descriptorValueLuaReflectionSelfTestCount']}`"
        lines.append(f"- Lua reflection self-tests: {detail}")
    if summary["ueReflectionCount"]:
        lines.append(
            f"- UE reflection probes: "
            f"`{summary['classMappedUeReflectionCount']}/{summary['ueReflectionCount']}` class-mapped, "
            f"slots `{summary['mappedUeReflectionSlotCount']}/{summary['ueReflectionSlotCount']}` mapped"
        )
    if summary["ueReflectionFieldCount"]:
        lines.append(
            f"- UE reflection fields: candidates "
            f"`{summary['candidateUeReflectionFieldCount']}/{summary['ueReflectionFieldCount']}`, "
            f"class-mapped `{summary['classMappedUeReflectionFieldCount']}`"
        )
    if summary["ueReflectionPropertyCount"]:
        lines.append(
            f"- UE reflection properties: candidates "
            f"`{summary['candidateUeReflectionPropertyCount']}/{summary['ueReflectionPropertyCount']}`, "
            f"readable descriptors `{summary['readableUeReflectionPropertyCount']}`"
        )
    if summary["ueReflectionValueCount"]:
        lines.append(
            f"- UE reflection values: read "
            f"`{summary['readUeReflectionValueCount']}/{summary['ueReflectionValueCount']}`"
        )
    if summary["ueFunctionParamRootCount"] or summary["ueFunctionParamCount"]:
        lines.append(
            f"- UE function params: roots "
            f"`{summary['rootedUeFunctionParamRootCount']}/{summary['ueFunctionParamRootCount']}`, "
            f"descriptors `{summary['readableUeFunctionParamCount']}/{summary['ueFunctionParamCount']}` readable, "
            f"flags roots `{summary['readableUeFunctionFlagRootCount']}`, "
            f"flags descriptors `{summary['readableUeFunctionFlagParamCount']}`"
        )
    if summary["luaProcessEventSelfTestCount"]:
        lines.append(
            f"- Lua ProcessEvent self-tests: "
            f"`{summary['passedLuaProcessEventSelfTestCount']}/{summary['luaProcessEventSelfTestCount']}` passed"
        )
    if summary["luaModScriptCount"] or summary["luaModFinishCount"]:
        lines.append(
            f"- Lua mod entrypoints: scripts `{summary['passedLuaModScriptCount']}/{summary['luaModScriptCount']}` passed, "
            f"dispatch `{summary['passedLuaModDispatchSelfTestCount']}/{summary['luaModDispatchSelfTestCount']}`, "
            f"finishes `{summary['passedLuaModFinishCount']}/{summary['luaModFinishCount']}`, "
            f"object API `{summary['luaObjectApiModFinishCount']}`, "
            f"function iteration `{summary['luaFunctionIterationModFinishCount']}`, "
            f"console exec hooks `{summary['luaProcessConsoleExecHookModFinishCount']}`, "
            f"local player exec hooks `{summary['luaLocalPlayerExecHookModFinishCount']}`, "
            f"call function hooks `{summary['luaCallFunctionHookModFinishCount']}`, "
            f"lifecycle hooks `{summary['luaLifecycleHookModFinishCount']}`, "
            f"object notify `{summary['luaNotifyOnNewObjectModFinishCount']}`, "
            f"synthetic outer `{summary['luaSyntheticOuterModFinishCount']}`, "
            f"world context `{summary['luaWorldContextModFinishCount']}`, "
            f"class default object `{summary['luaClassDefaultObjectModFinishCount']}`, "
            f"level `{summary['luaLevelModFinishCount']}`"
        )
    if summary["luaObjectRegistryCount"]:
        lines.append(
            f"- Lua object registry: `{summary['addedLuaObjectRegistryCount']}/{summary['luaObjectRegistryCount']}` added, "
            f"UE candidates `{summary['ueLuaObjectRegistryCount']}`, "
            f"object-array candidates `{summary['objectArrayLuaObjectRegistryCount']}`, "
            f"decoded aliases `{summary['decodedLuaObjectAliasRegistryCount']}`"
        )
    if summary["ueObjectArrayCount"]:
        lines.append(
            f"- UE object arrays: `{summary['finishedUeObjectArrayCount']}/{summary['ueObjectArrayCount']}` finished"
        )
    if summary["ueObjectArrayItemCount"]:
        lines.append(
            "- UE object-array internal flags: "
            f"`{summary['internalFlagUeObjectArrayItemCount']}/{summary['ueObjectArrayItemCount']}` readable, "
            f"`{summary['nonzeroInternalFlagUeObjectArrayItemCount']}` nonzero"
        )
    if summary["ueFNameCount"]:
        lines.append(
            f"- UE FName decodes: `{summary['decodedUeFNameCount']}/{summary['ueFNameCount']}` decoded"
        )
    lines.append(f"- Unique names: `{summary['uniqueHitCount']}`")
    if summary["forwardSmokeCount"]:
        lines.append(f"- Forward smokes: `{summary['forwardSmokeCount']}`")
    if summary["missingExpected"]:
        lines.append(f"- Missing expected: `{', '.join(summary['missingExpected'])}`")
    lines.append("")

    lines.append("## Expected Anchors")
    lines.append("")
    for name, status in summary["expected"].items():
        marker = "present" if status["present"] else "missing"
        first = status["first"].get("offset", "")
        suffix = f" first=`{first}`" if first else ""
        lines.append(f"- `{name}`: `{marker}` count=`{status['count']}`{suffix}")
    lines.append("")

    lines.append("## Categories")
    lines.append("")
    for category, count in summary["categories"].items():
        lines.append(f"- `{category}`: `{count}` hits")
    if not summary["categories"]:
        lines.append("- none")
    lines.append("")

    lines.append("## Modules")
    lines.append("")
    for module in summary["modules"][:top]:
        lines.append(f"- `{module}`")
    if len(summary["modules"]) > top:
        lines.append(f"- ... +{len(summary['modules']) - top} more")
    if not summary["modules"]:
        lines.append("- none")
    lines.append("")

    lines.append("## Hits")
    lines.append("")
    items = sorted(summary["hitsByName"].items(), key=lambda item: (item[1]["category"], item[0]))
    for name, data in items:
        offsets = ", ".join(offset["offset"] for offset in data["offsets"][:top] if offset["offset"])
        if len(data["offsets"]) > top:
            offsets += f", ... +{len(data['offsets']) - top}"
        lines.append(
            f"- `{data['category']}` `{name}` count=`{data['count']}` first=`{data['first']['offset']}` offsets=`{offsets}`"
        )
    if not items:
        lines.append("- none")
    lines.append("")
    return "\n".join(lines)


def main(argv=None):
    parser = argparse.ArgumentParser(description="Summarize Linux or Windows client loader probe logs.")
    parser.add_argument("log", type=Path)
    parser.add_argument("--loader", action="append", choices=("client", "win-client", "linux-client", "server"), default=[])
    parser.add_argument("--pid", action="append", default=[])
    parser.add_argument("--exe-substring", action="append", default=[])
    parser.add_argument("--expected", action="append", default=[])
    parser.add_argument("--format", choices=("json", "markdown"), default="markdown")
    parser.add_argument("--top", type=int, default=12)
    args = parser.parse_args(argv)

    summary = summarize(
        load_records(args.log),
        loader_filter=args.loader,
        pid_filter=args.pid,
        exe_substrings=args.exe_substring,
        expected=args.expected or DEFAULT_EXPECTED,
    )
    if args.format == "json":
        json.dump(summary, sys.stdout, indent=2, sort_keys=True)
        sys.stdout.write("\n")
    else:
        sys.stdout.write(markdown(summary, args.top))


if __name__ == "__main__":
    main()
