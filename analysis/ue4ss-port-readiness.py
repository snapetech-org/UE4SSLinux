#!/usr/bin/env python3
import argparse
import importlib.util
import json
import sys
from pathlib import Path


CORE_GROUPS = ("names", "objects", "world", "dispatch")
REFLECTION_GROUP = "reflection"


def import_script(script_name, module_name):
    script = Path(__file__).resolve().parent / script_name
    spec = importlib.util.spec_from_file_location(module_name, script)
    module = importlib.util.module_from_spec(spec)
    if spec.loader is None:
        raise RuntimeError(f"unable to import {script}")
    spec.loader.exec_module(module)
    return module


def load_json(path):
    with path.open("r", encoding="utf-8", errors="replace") as handle:
        return json.load(handle)


def gate(name, passed, evidence="", blocker=""):
    return {
        "name": name,
        "passed": bool(passed),
        "evidence": evidence,
        "blocker": "" if passed else blocker,
    }


def summarize_log(path, loader_filter, pid_filter, exe_substrings):
    scan_mod = import_script("summarize-client-loader-scan.py", "summarize_client_loader_scan")
    ue_mod = import_script("summarize-client-ue-anchors.py", "summarize_client_ue_anchors")
    scan = scan_mod.summarize(
        scan_mod.load_records(path),
        loader_filter=loader_filter,
        pid_filter=pid_filter,
        exe_substrings=exe_substrings,
    )
    ue = ue_mod.summarize(scan)
    return {"path": str(path), "scan": scan, "ue": ue}


def merge_log_summaries(log_summaries):
    merged_hits = {}
    total_loads = 0
    total_starts = 0
    total_finishes = 0
    total_pointers = 0
    total_mapped_pointers = 0
    total_layouts = 0
    total_readable_layouts = 0
    total_layout_slots = 0
    total_mapped_layout_slots = 0
    total_uobjects = 0
    total_candidate_uobjects = 0
    total_class_mapped_uobjects = 0
    total_ue_reflections = 0
    total_class_mapped_ue_reflections = 0
    total_ue_reflection_slots = 0
    total_mapped_ue_reflection_slots = 0
    total_ue_reflection_fields = 0
    total_candidate_ue_reflection_fields = 0
    total_class_mapped_ue_reflection_fields = 0
    total_ue_reflection_properties = 0
    total_candidate_ue_reflection_properties = 0
    total_readable_ue_reflection_properties = 0
    total_ue_reflection_values = 0
    total_read_ue_reflection_values = 0
    total_ue_function_param_roots = 0
    total_rooted_ue_function_param_roots = 0
    total_ue_function_params = 0
    total_candidate_ue_function_params = 0
    total_ue_function_param_container_children = 0
    total_candidate_ue_function_param_container_children = 0
    total_decoded_ue_function_param_container_children = 0
    total_readable_ue_function_params = 0
    total_named_ue_function_params = 0
    ue_function_paths = set()
    total_readable_ue_function_flag_roots = 0
    total_readable_ue_function_flag_params = 0
    ue_function_flag_paths = set()
    ue_function_flag_values = set()
    total_hook_self_tests = 0
    total_passed_hook_self_tests = 0
    total_mod_self_tests = 0
    total_passed_mod_self_tests = 0
    total_lua_self_tests = 0
    total_passed_lua_self_tests = 0
    total_passed_lua_callback_self_tests = 0
    total_passed_lua_api_self_tests = 0
    total_passed_lua_object_api_self_tests = 0
    total_lua_reflection_self_tests = 0
    total_passed_lua_reflection_self_tests = 0
    total_raw_set_lua_reflection_self_tests = 0
    total_named_lua_reflection_self_tests = 0
    total_numeric_lua_reflection_self_tests = 0
    total_name_text_lua_reflection_self_tests = 0
    total_array_inner_lua_reflection_self_tests = 0
    total_enum_lua_reflection_self_tests = 0
    total_container_lua_reflection_self_tests = 0
    total_import_text_lua_reflection_self_tests = 0
    total_export_text_lua_reflection_self_tests = 0
    total_property_metadata_lua_reflection_self_tests = 0
    total_descriptor_value_lua_reflection_self_tests = 0
    total_lua_process_event_self_tests = 0
    total_passed_lua_process_event_self_tests = 0
    total_lua_process_event_param_accessor_self_tests = 0
    total_lua_process_event_scalar_param_accessor_self_tests = 0
    total_lua_process_event_name_string_param_accessor_self_tests = 0
    total_lua_process_event_struct_param_accessor_self_tests = 0
    total_routed_lua_process_event_self_tests = 0
    total_lua_mod_scripts = 0
    total_passed_lua_mod_scripts = 0
    total_lua_mod_dispatch_self_tests = 0
    total_passed_lua_mod_dispatch_self_tests = 0
    total_lua_mod_finishes = 0
    total_passed_lua_mod_finishes = 0
    total_lua_object_api_mod_finishes = 0
    total_lua_function_iteration_mod_finishes = 0
    total_lua_process_console_exec_hook_mod_finishes = 0
    total_lua_local_player_exec_hook_mod_finishes = 0
    total_lua_call_function_hook_mod_finishes = 0
    total_lua_lifecycle_hook_mod_finishes = 0
    total_lua_notify_on_new_object_mod_finishes = 0
    total_lua_synthetic_outer_mod_finishes = 0
    total_lua_world_context_mod_finishes = 0
    total_lua_class_default_object_mod_finishes = 0
    total_lua_level_mod_finishes = 0
    total_lua_object_registry = 0
    total_added_lua_object_registry = 0
    total_ue_lua_object_registry = 0
    total_object_array_lua_object_registry = 0
    total_decoded_lua_object_alias_registry = 0
    total_skipped_decoded_lua_object_alias_registry = 0
    total_ue_object_arrays = 0
    total_finished_ue_object_arrays = 0
    total_ue_object_array_items = 0
    total_internal_flag_ue_object_array_items = 0
    total_nonzero_internal_flag_ue_object_array_items = 0
    total_ue_fnames = 0
    total_decoded_ue_fnames = 0
    total_ue_anchor_signatures = 0
    total_resolved_ue_anchor_signatures = 0
    total_ue_anchor_signature_status_counts = {}
    total_ue_process_event_hooks = 0
    total_passed_ue_process_event_hooks = 0
    total_ue_process_event_live_hooks = 0
    total_installed_ue_process_event_live_hooks = 0
    total_ue_process_event_live_contexts = 0
    total_resolved_ue_process_event_live_contexts = 0
    total_ue_process_event_live_params = 0
    total_read_ue_process_event_live_params = 0
    total_raw_ue_process_event_live_params = 0
    total_container_ue_process_event_live_params = 0
    total_sampled_container_ue_process_event_live_params = 0
    total_ue_process_event_lua_context_handles = 0
    total_ue_process_event_live_lua_param_accessors = 0
    total_ue_process_event_live_lua_scalar_param_accessors = 0
    total_ue_process_event_live_lua_name_string_param_accessors = 0
    total_ue_process_event_live_lua_struct_param_accessors = 0
    total_routed_ue_process_event_live_lua_hooks = 0
    total_restored_ue_process_event_live_hooks = 0
    total_ue_process_event_live_hook_status_counts = {}
    total_ue_process_event_dispatch_self_tests = 0
    total_armed_ue_process_event_dispatch_self_tests = 0
    total_ue_process_event_live_lua_dispatches = 0
    total_armed_ue_process_event_live_lua_dispatches = 0
    total_multi_hook_ue_process_event_live_lua_dispatches = 0
    total_closed_ue_process_event_live_lua_dispatches = 0
    total_ue_process_event_live_lua_dispatch_status_counts = {}
    loaders = set()
    pids = set()
    for summary in log_summaries:
        scan = summary["scan"]
        total_loads += scan.get("loadCount", 0)
        total_starts += scan.get("scanStartCount", 0)
        total_finishes += scan.get("scanFinishCount", 0)
        total_pointers += scan.get("uePointerCount", 0)
        total_mapped_pointers += scan.get("mappedUePointerCount", 0)
        total_layouts += scan.get("ueLayoutCount", 0)
        total_readable_layouts += scan.get("readableUeLayoutCount", 0)
        total_layout_slots += scan.get("ueLayoutSlotCount", 0)
        total_mapped_layout_slots += scan.get("mappedUeLayoutSlotCount", 0)
        total_uobjects += scan.get("ueUObjectCount", 0)
        total_candidate_uobjects += scan.get("candidateUeUObjectCount", 0)
        total_class_mapped_uobjects += scan.get("classMappedUeUObjectCount", 0)
        total_ue_reflections += scan.get("ueReflectionCount", 0)
        total_class_mapped_ue_reflections += scan.get("classMappedUeReflectionCount", 0)
        total_ue_reflection_slots += scan.get("ueReflectionSlotCount", 0)
        total_mapped_ue_reflection_slots += scan.get("mappedUeReflectionSlotCount", 0)
        total_ue_reflection_fields += scan.get("ueReflectionFieldCount", 0)
        total_candidate_ue_reflection_fields += scan.get("candidateUeReflectionFieldCount", 0)
        total_class_mapped_ue_reflection_fields += scan.get("classMappedUeReflectionFieldCount", 0)
        total_ue_reflection_properties += scan.get("ueReflectionPropertyCount", 0)
        total_candidate_ue_reflection_properties += scan.get("candidateUeReflectionPropertyCount", 0)
        total_readable_ue_reflection_properties += scan.get("readableUeReflectionPropertyCount", 0)
        total_ue_reflection_values += scan.get("ueReflectionValueCount", 0)
        total_read_ue_reflection_values += scan.get("readUeReflectionValueCount", 0)
        total_ue_function_param_roots += scan.get("ueFunctionParamRootCount", 0)
        total_rooted_ue_function_param_roots += scan.get("rootedUeFunctionParamRootCount", 0)
        total_ue_function_params += scan.get("ueFunctionParamCount", 0)
        total_candidate_ue_function_params += scan.get("candidateUeFunctionParamCount", 0)
        total_ue_function_param_container_children += scan.get("ueFunctionParamContainerChildCount", 0)
        total_candidate_ue_function_param_container_children += scan.get(
            "candidateUeFunctionParamContainerChildCount", 0
        )
        total_decoded_ue_function_param_container_children += scan.get(
            "decodedUeFunctionParamContainerChildCount", 0
        )
        total_readable_ue_function_params += scan.get("readableUeFunctionParamCount", 0)
        total_named_ue_function_params += scan.get("namedUeFunctionParamCount", 0)
        ue_function_paths.update(path for path in scan.get("ueFunctionPaths", []) if path)
        total_readable_ue_function_flag_roots += scan.get("readableUeFunctionFlagRootCount", 0)
        total_readable_ue_function_flag_params += scan.get("readableUeFunctionFlagParamCount", 0)
        ue_function_flag_paths.update(path for path in scan.get("ueFunctionFlagPaths", []) if path)
        ue_function_flag_values.update(value for value in scan.get("ueFunctionFlagValues", []) if value)
        total_hook_self_tests += scan.get("hookSelfTestCount", 0)
        total_passed_hook_self_tests += scan.get("passedHookSelfTestCount", 0)
        total_mod_self_tests += scan.get("modSelfTestCount", 0)
        total_passed_mod_self_tests += scan.get("passedModSelfTestCount", 0)
        total_lua_self_tests += scan.get("luaSelfTestCount", 0)
        total_passed_lua_self_tests += scan.get("passedLuaSelfTestCount", 0)
        total_passed_lua_callback_self_tests += scan.get("passedLuaCallbackSelfTestCount", 0)
        total_passed_lua_api_self_tests += scan.get("passedLuaApiSelfTestCount", 0)
        total_passed_lua_object_api_self_tests += scan.get("passedLuaObjectApiSelfTestCount", 0)
        total_lua_reflection_self_tests += scan.get("luaReflectionSelfTestCount", 0)
        total_passed_lua_reflection_self_tests += scan.get("passedLuaReflectionSelfTestCount", 0)
        total_raw_set_lua_reflection_self_tests += scan.get("rawSetLuaReflectionSelfTestCount", 0)
        total_named_lua_reflection_self_tests += scan.get("namedLuaReflectionSelfTestCount", 0)
        total_numeric_lua_reflection_self_tests += scan.get("numericLuaReflectionSelfTestCount", 0)
        total_name_text_lua_reflection_self_tests += scan.get("nameTextLuaReflectionSelfTestCount", 0)
        total_array_inner_lua_reflection_self_tests += scan.get("arrayInnerLuaReflectionSelfTestCount", 0)
        total_enum_lua_reflection_self_tests += scan.get("enumLuaReflectionSelfTestCount", 0)
        total_container_lua_reflection_self_tests += scan.get("containerLuaReflectionSelfTestCount", 0)
        total_import_text_lua_reflection_self_tests += scan.get("importTextLuaReflectionSelfTestCount", 0)
        total_export_text_lua_reflection_self_tests += scan.get("exportTextLuaReflectionSelfTestCount", 0)
        total_property_metadata_lua_reflection_self_tests += scan.get("propertyMetadataLuaReflectionSelfTestCount", 0)
        total_descriptor_value_lua_reflection_self_tests += scan.get("descriptorValueLuaReflectionSelfTestCount", 0)
        total_lua_process_event_self_tests += scan.get("luaProcessEventSelfTestCount", 0)
        total_passed_lua_process_event_self_tests += scan.get("passedLuaProcessEventSelfTestCount", 0)
        total_lua_process_event_param_accessor_self_tests += scan.get("luaProcessEventParamAccessorSelfTestCount", 0)
        total_lua_process_event_scalar_param_accessor_self_tests += scan.get("luaProcessEventScalarParamAccessorSelfTestCount", 0)
        total_lua_process_event_name_string_param_accessor_self_tests += scan.get("luaProcessEventNameStringParamAccessorSelfTestCount", 0)
        total_lua_process_event_struct_param_accessor_self_tests += scan.get("luaProcessEventStructParamAccessorSelfTestCount", 0)
        total_routed_lua_process_event_self_tests += scan.get("routedLuaProcessEventSelfTestCount", 0)
        total_lua_mod_scripts += scan.get("luaModScriptCount", 0)
        total_passed_lua_mod_scripts += scan.get("passedLuaModScriptCount", 0)
        total_lua_mod_dispatch_self_tests += scan.get("luaModDispatchSelfTestCount", 0)
        total_passed_lua_mod_dispatch_self_tests += scan.get("passedLuaModDispatchSelfTestCount", 0)
        total_lua_mod_finishes += scan.get("luaModFinishCount", 0)
        total_passed_lua_mod_finishes += scan.get("passedLuaModFinishCount", 0)
        total_lua_object_api_mod_finishes += scan.get("luaObjectApiModFinishCount", 0)
        total_lua_function_iteration_mod_finishes += scan.get("luaFunctionIterationModFinishCount", 0)
        total_lua_process_console_exec_hook_mod_finishes += scan.get("luaProcessConsoleExecHookModFinishCount", 0)
        total_lua_local_player_exec_hook_mod_finishes += scan.get("luaLocalPlayerExecHookModFinishCount", 0)
        total_lua_call_function_hook_mod_finishes += scan.get("luaCallFunctionHookModFinishCount", 0)
        total_lua_lifecycle_hook_mod_finishes += scan.get("luaLifecycleHookModFinishCount", 0)
        total_lua_notify_on_new_object_mod_finishes += scan.get("luaNotifyOnNewObjectModFinishCount", 0)
        total_lua_synthetic_outer_mod_finishes += scan.get("luaSyntheticOuterModFinishCount", 0)
        total_lua_world_context_mod_finishes += scan.get("luaWorldContextModFinishCount", 0)
        total_lua_class_default_object_mod_finishes += scan.get("luaClassDefaultObjectModFinishCount", 0)
        total_lua_level_mod_finishes += scan.get("luaLevelModFinishCount", 0)
        total_lua_object_registry += scan.get("luaObjectRegistryCount", 0)
        total_added_lua_object_registry += scan.get("addedLuaObjectRegistryCount", 0)
        total_ue_lua_object_registry += scan.get("ueLuaObjectRegistryCount", 0)
        total_object_array_lua_object_registry += scan.get("objectArrayLuaObjectRegistryCount", 0)
        total_decoded_lua_object_alias_registry += scan.get("decodedLuaObjectAliasRegistryCount", 0)
        total_skipped_decoded_lua_object_alias_registry += scan.get("skippedDecodedLuaObjectAliasRegistryCount", 0)
        total_ue_object_arrays += scan.get("ueObjectArrayCount", 0)
        total_finished_ue_object_arrays += scan.get("finishedUeObjectArrayCount", 0)
        total_ue_object_array_items += scan.get("ueObjectArrayItemCount", 0)
        total_internal_flag_ue_object_array_items += scan.get("internalFlagUeObjectArrayItemCount", 0)
        total_nonzero_internal_flag_ue_object_array_items += scan.get("nonzeroInternalFlagUeObjectArrayItemCount", 0)
        total_ue_fnames += scan.get("ueFNameCount", 0)
        total_decoded_ue_fnames += scan.get("decodedUeFNameCount", 0)
        total_ue_anchor_signatures += scan.get("ueAnchorSignatureCount", 0)
        total_resolved_ue_anchor_signatures += scan.get("resolvedUeAnchorSignatureCount", 0)
        for status, count in scan.get("ueAnchorSignatureStatusCounts", {}).items():
            total_ue_anchor_signature_status_counts[status] = total_ue_anchor_signature_status_counts.get(status, 0) + count
        total_ue_process_event_hooks += scan.get("ueProcessEventHookCount", 0)
        total_passed_ue_process_event_hooks += scan.get("passedUeProcessEventHookCount", 0)
        total_ue_process_event_live_hooks += scan.get("ueProcessEventLiveHookCount", 0)
        total_installed_ue_process_event_live_hooks += scan.get("installedUeProcessEventLiveHookCount", 0)
        total_ue_process_event_live_contexts += scan.get("ueProcessEventLiveContextCount", 0)
        total_resolved_ue_process_event_live_contexts += scan.get("resolvedUeProcessEventLiveContextCount", 0)
        total_ue_process_event_live_params += scan.get("ueProcessEventLiveParamCount", 0)
        total_read_ue_process_event_live_params += scan.get("readUeProcessEventLiveParamCount", 0)
        total_raw_ue_process_event_live_params += scan.get("rawUeProcessEventLiveParamCount", 0)
        total_container_ue_process_event_live_params += scan.get("containerUeProcessEventLiveParamCount", 0)
        total_sampled_container_ue_process_event_live_params += scan.get("sampledContainerUeProcessEventLiveParamCount", 0)
        total_ue_process_event_lua_context_handles += scan.get("ueProcessEventLuaContextHandleCount", 0)
        total_ue_process_event_live_lua_param_accessors += scan.get("ueProcessEventLiveLuaParamAccessorCount", 0)
        total_ue_process_event_live_lua_scalar_param_accessors += scan.get("ueProcessEventLiveLuaScalarParamAccessorCount", 0)
        total_ue_process_event_live_lua_name_string_param_accessors += scan.get("ueProcessEventLiveLuaNameStringParamAccessorCount", 0)
        total_ue_process_event_live_lua_struct_param_accessors += scan.get("ueProcessEventLiveLuaStructParamAccessorCount", 0)
        total_routed_ue_process_event_live_lua_hooks += scan.get("routedUeProcessEventLiveLuaHookCount", 0)
        total_restored_ue_process_event_live_hooks += scan.get("restoredUeProcessEventLiveHookCount", 0)
        for status, count in scan.get("ueProcessEventLiveHookStatusCounts", {}).items():
            total_ue_process_event_live_hook_status_counts[status] = (
                total_ue_process_event_live_hook_status_counts.get(status, 0) + count
            )
        total_ue_process_event_dispatch_self_tests += scan.get("ueProcessEventDispatchSelfTestCount", 0)
        total_armed_ue_process_event_dispatch_self_tests += scan.get("armedUeProcessEventDispatchSelfTestCount", 0)
        total_ue_process_event_live_lua_dispatches += scan.get("ueProcessEventLiveLuaDispatchCount", 0)
        total_armed_ue_process_event_live_lua_dispatches += scan.get("armedUeProcessEventLiveLuaDispatchCount", 0)
        total_multi_hook_ue_process_event_live_lua_dispatches += scan.get("multiHookUeProcessEventLiveLuaDispatchCount", 0)
        total_closed_ue_process_event_live_lua_dispatches += scan.get("closedUeProcessEventLiveLuaDispatchCount", 0)
        for status, count in scan.get("ueProcessEventLiveLuaDispatchStatusCounts", {}).items():
            total_ue_process_event_live_lua_dispatch_status_counts[status] = (
                total_ue_process_event_live_lua_dispatch_status_counts.get(status, 0) + count
            )
        loaders.update(scan.get("loaders", []))
        pids.update(scan.get("pids", []))
        for name, hit in scan.get("hitsByName", {}).items():
            current = merged_hits.setdefault(
                name,
                {
                    "category": hit.get("category", ""),
                    "count": 0,
                    "kinds": {},
                    "sources": {},
                    "first": hit.get("first", {}),
                    "offsets": [],
                },
            )
            current["count"] += hit.get("count", 0)
            current["offsets"].extend(hit.get("offsets", []))
            if not current.get("first") and hit.get("first"):
                current["first"] = hit["first"]
            for key, value in hit.get("kinds", {}).items():
                current["kinds"][key] = current["kinds"].get(key, 0) + value
            for key, value in hit.get("sources", {}).items():
                current["sources"][key] = current["sources"].get(key, 0) + value
    ue_mod = import_script("summarize-client-ue-anchors.py", "summarize_client_ue_anchors")
    return {
        "loadCount": total_loads,
        "scanStartCount": total_starts,
        "scanFinishCount": total_finishes,
        "uePointerCount": total_pointers,
        "mappedUePointerCount": total_mapped_pointers,
        "ueLayoutCount": total_layouts,
        "readableUeLayoutCount": total_readable_layouts,
        "ueLayoutSlotCount": total_layout_slots,
        "mappedUeLayoutSlotCount": total_mapped_layout_slots,
        "ueUObjectCount": total_uobjects,
        "candidateUeUObjectCount": total_candidate_uobjects,
        "classMappedUeUObjectCount": total_class_mapped_uobjects,
        "ueReflectionCount": total_ue_reflections,
        "classMappedUeReflectionCount": total_class_mapped_ue_reflections,
        "ueReflectionSlotCount": total_ue_reflection_slots,
        "mappedUeReflectionSlotCount": total_mapped_ue_reflection_slots,
        "ueReflectionFieldCount": total_ue_reflection_fields,
        "candidateUeReflectionFieldCount": total_candidate_ue_reflection_fields,
        "classMappedUeReflectionFieldCount": total_class_mapped_ue_reflection_fields,
        "ueReflectionPropertyCount": total_ue_reflection_properties,
        "candidateUeReflectionPropertyCount": total_candidate_ue_reflection_properties,
        "readableUeReflectionPropertyCount": total_readable_ue_reflection_properties,
        "ueReflectionValueCount": total_ue_reflection_values,
        "readUeReflectionValueCount": total_read_ue_reflection_values,
        "ueFunctionParamRootCount": total_ue_function_param_roots,
        "rootedUeFunctionParamRootCount": total_rooted_ue_function_param_roots,
        "ueFunctionParamCount": total_ue_function_params,
        "candidateUeFunctionParamCount": total_candidate_ue_function_params,
        "ueFunctionParamContainerChildCount": total_ue_function_param_container_children,
        "candidateUeFunctionParamContainerChildCount": total_candidate_ue_function_param_container_children,
        "decodedUeFunctionParamContainerChildCount": total_decoded_ue_function_param_container_children,
        "readableUeFunctionParamCount": total_readable_ue_function_params,
        "namedUeFunctionParamCount": total_named_ue_function_params,
        "uniqueUeFunctionPathCount": len(ue_function_paths),
        "ueFunctionPaths": sorted(ue_function_paths),
        "readableUeFunctionFlagRootCount": total_readable_ue_function_flag_roots,
        "readableUeFunctionFlagParamCount": total_readable_ue_function_flag_params,
        "ueFunctionFlagPathCount": len(ue_function_flag_paths),
        "ueFunctionFlagPaths": sorted(ue_function_flag_paths),
        "ueFunctionFlagValues": sorted(ue_function_flag_values),
        "hookSelfTestCount": total_hook_self_tests,
        "passedHookSelfTestCount": total_passed_hook_self_tests,
        "modSelfTestCount": total_mod_self_tests,
        "passedModSelfTestCount": total_passed_mod_self_tests,
        "luaSelfTestCount": total_lua_self_tests,
        "passedLuaSelfTestCount": total_passed_lua_self_tests,
        "passedLuaCallbackSelfTestCount": total_passed_lua_callback_self_tests,
        "passedLuaApiSelfTestCount": total_passed_lua_api_self_tests,
        "passedLuaObjectApiSelfTestCount": total_passed_lua_object_api_self_tests,
        "luaReflectionSelfTestCount": total_lua_reflection_self_tests,
        "passedLuaReflectionSelfTestCount": total_passed_lua_reflection_self_tests,
        "rawSetLuaReflectionSelfTestCount": total_raw_set_lua_reflection_self_tests,
        "namedLuaReflectionSelfTestCount": total_named_lua_reflection_self_tests,
        "numericLuaReflectionSelfTestCount": total_numeric_lua_reflection_self_tests,
        "nameTextLuaReflectionSelfTestCount": total_name_text_lua_reflection_self_tests,
        "arrayInnerLuaReflectionSelfTestCount": total_array_inner_lua_reflection_self_tests,
        "enumLuaReflectionSelfTestCount": total_enum_lua_reflection_self_tests,
        "containerLuaReflectionSelfTestCount": total_container_lua_reflection_self_tests,
        "importTextLuaReflectionSelfTestCount": total_import_text_lua_reflection_self_tests,
        "exportTextLuaReflectionSelfTestCount": total_export_text_lua_reflection_self_tests,
        "propertyMetadataLuaReflectionSelfTestCount": total_property_metadata_lua_reflection_self_tests,
        "descriptorValueLuaReflectionSelfTestCount": total_descriptor_value_lua_reflection_self_tests,
        "luaProcessEventSelfTestCount": total_lua_process_event_self_tests,
        "passedLuaProcessEventSelfTestCount": total_passed_lua_process_event_self_tests,
        "luaProcessEventParamAccessorSelfTestCount": total_lua_process_event_param_accessor_self_tests,
        "luaProcessEventScalarParamAccessorSelfTestCount": total_lua_process_event_scalar_param_accessor_self_tests,
        "luaProcessEventNameStringParamAccessorSelfTestCount": total_lua_process_event_name_string_param_accessor_self_tests,
        "luaProcessEventStructParamAccessorSelfTestCount": total_lua_process_event_struct_param_accessor_self_tests,
        "routedLuaProcessEventSelfTestCount": total_routed_lua_process_event_self_tests,
        "luaModScriptCount": total_lua_mod_scripts,
        "passedLuaModScriptCount": total_passed_lua_mod_scripts,
        "luaModDispatchSelfTestCount": total_lua_mod_dispatch_self_tests,
        "passedLuaModDispatchSelfTestCount": total_passed_lua_mod_dispatch_self_tests,
        "luaModFinishCount": total_lua_mod_finishes,
        "passedLuaModFinishCount": total_passed_lua_mod_finishes,
        "luaObjectApiModFinishCount": total_lua_object_api_mod_finishes,
        "luaFunctionIterationModFinishCount": total_lua_function_iteration_mod_finishes,
        "luaProcessConsoleExecHookModFinishCount": total_lua_process_console_exec_hook_mod_finishes,
        "luaLocalPlayerExecHookModFinishCount": total_lua_local_player_exec_hook_mod_finishes,
        "luaCallFunctionHookModFinishCount": total_lua_call_function_hook_mod_finishes,
        "luaLifecycleHookModFinishCount": total_lua_lifecycle_hook_mod_finishes,
        "luaNotifyOnNewObjectModFinishCount": total_lua_notify_on_new_object_mod_finishes,
        "luaSyntheticOuterModFinishCount": total_lua_synthetic_outer_mod_finishes,
        "luaWorldContextModFinishCount": total_lua_world_context_mod_finishes,
        "luaClassDefaultObjectModFinishCount": total_lua_class_default_object_mod_finishes,
        "luaLevelModFinishCount": total_lua_level_mod_finishes,
        "luaObjectRegistryCount": total_lua_object_registry,
        "addedLuaObjectRegistryCount": total_added_lua_object_registry,
        "ueLuaObjectRegistryCount": total_ue_lua_object_registry,
        "objectArrayLuaObjectRegistryCount": total_object_array_lua_object_registry,
        "decodedLuaObjectAliasRegistryCount": total_decoded_lua_object_alias_registry,
        "skippedDecodedLuaObjectAliasRegistryCount": total_skipped_decoded_lua_object_alias_registry,
        "ueObjectArrayCount": total_ue_object_arrays,
        "finishedUeObjectArrayCount": total_finished_ue_object_arrays,
        "ueObjectArrayItemCount": total_ue_object_array_items,
        "internalFlagUeObjectArrayItemCount": total_internal_flag_ue_object_array_items,
        "nonzeroInternalFlagUeObjectArrayItemCount": total_nonzero_internal_flag_ue_object_array_items,
        "ueFNameCount": total_ue_fnames,
        "decodedUeFNameCount": total_decoded_ue_fnames,
        "ueAnchorSignatureCount": total_ue_anchor_signatures,
        "resolvedUeAnchorSignatureCount": total_resolved_ue_anchor_signatures,
        "ueAnchorSignatureStatusCounts": dict(sorted(total_ue_anchor_signature_status_counts.items())),
        "ueProcessEventHookCount": total_ue_process_event_hooks,
        "passedUeProcessEventHookCount": total_passed_ue_process_event_hooks,
        "ueProcessEventLiveHookCount": total_ue_process_event_live_hooks,
        "installedUeProcessEventLiveHookCount": total_installed_ue_process_event_live_hooks,
        "ueProcessEventLiveContextCount": total_ue_process_event_live_contexts,
        "resolvedUeProcessEventLiveContextCount": total_resolved_ue_process_event_live_contexts,
        "ueProcessEventLiveParamCount": total_ue_process_event_live_params,
        "readUeProcessEventLiveParamCount": total_read_ue_process_event_live_params,
        "rawUeProcessEventLiveParamCount": total_raw_ue_process_event_live_params,
        "containerUeProcessEventLiveParamCount": total_container_ue_process_event_live_params,
        "sampledContainerUeProcessEventLiveParamCount": total_sampled_container_ue_process_event_live_params,
        "ueProcessEventLuaContextHandleCount": total_ue_process_event_lua_context_handles,
        "ueProcessEventLiveLuaParamAccessorCount": total_ue_process_event_live_lua_param_accessors,
        "ueProcessEventLiveLuaScalarParamAccessorCount": total_ue_process_event_live_lua_scalar_param_accessors,
        "ueProcessEventLiveLuaNameStringParamAccessorCount": total_ue_process_event_live_lua_name_string_param_accessors,
        "ueProcessEventLiveLuaStructParamAccessorCount": total_ue_process_event_live_lua_struct_param_accessors,
        "routedUeProcessEventLiveLuaHookCount": total_routed_ue_process_event_live_lua_hooks,
        "restoredUeProcessEventLiveHookCount": total_restored_ue_process_event_live_hooks,
        "ueProcessEventLiveHookStatusCounts": dict(sorted(total_ue_process_event_live_hook_status_counts.items())),
        "ueProcessEventDispatchSelfTestCount": total_ue_process_event_dispatch_self_tests,
        "armedUeProcessEventDispatchSelfTestCount": total_armed_ue_process_event_dispatch_self_tests,
        "ueProcessEventLiveLuaDispatchCount": total_ue_process_event_live_lua_dispatches,
        "armedUeProcessEventLiveLuaDispatchCount": total_armed_ue_process_event_live_lua_dispatches,
        "multiHookUeProcessEventLiveLuaDispatchCount": total_multi_hook_ue_process_event_live_lua_dispatches,
        "closedUeProcessEventLiveLuaDispatchCount": total_closed_ue_process_event_live_lua_dispatches,
        "ueProcessEventLiveLuaDispatchStatusCounts": dict(sorted(total_ue_process_event_live_lua_dispatch_status_counts.items())),
        "loaders": sorted(loaders),
        "pids": sorted(pids),
        "hitsByName": merged_hits,
        "ue": ue_mod.summarize({"hitsByName": merged_hits}),
    }


def signature_validation_status(validation_summaries):
    if not validation_summaries:
        return {
            "provided": False,
            "patternCount": 0,
            "promotableCount": 0,
            "statusCounts": {},
            "exactOnly": False,
            "allPromotable": False,
        }
    pattern_count = 0
    promotable_count = 0
    status_counts = {}
    for validation in validation_summaries:
        pattern_count += validation.get("patternCount", 0)
        promotable_count += validation.get("promotableCount", 0)
        for status, count in validation.get("statusCounts", {}).items():
            status_counts[status] = status_counts.get(status, 0) + count
    exact_only = pattern_count > 0 and status_counts == {"unique-expected": pattern_count}
    return {
        "provided": True,
        "patternCount": pattern_count,
        "promotableCount": promotable_count,
        "statusCounts": dict(sorted(status_counts.items())),
        "exactOnly": exact_only,
        "allPromotable": pattern_count > 0 and promotable_count == pattern_count,
    }


def build_report(log_summaries, validation_summaries):
    merged = merge_log_summaries(log_summaries)
    ue = merged["ue"]
    signatures = signature_validation_status(validation_summaries)

    gates = []
    gates.append(
        gate(
            "loader-loaded",
            merged["loadCount"] > 0,
            f"loads={merged['loadCount']} loaders={','.join(merged['loaders']) or 'unknown'}",
            "no loader loaded event in scoped logs",
        )
    )
    gates.append(
        gate(
            "scan-completed",
            merged["scanStartCount"] > 0 and merged["scanFinishCount"] >= merged["scanStartCount"],
            f"starts={merged['scanStartCount']} finishes={merged['scanFinishCount']}",
            "scan did not start and finish cleanly",
        )
    )
    for group in CORE_GROUPS:
        data = ue["groups"][group]
        gates.append(
            gate(
                f"ue-{group}",
                data["present"] > 0,
                f"present={data['present']}/{data['total']}",
                f"missing {group} anchor group",
            )
        )
    reflection = ue["groups"][REFLECTION_GROUP]
    gates.append(
        gate(
            "ue-reflection-surface",
            reflection["present"] >= 2,
            f"present={reflection['present']}/{reflection['total']}",
            "need at least two reflection anchors before reflection reader work",
        )
    )
    gates.append(
        gate(
            "ue-reflection-probe",
            merged["classMappedUeReflectionCount"] > 0
            and merged["mappedUeReflectionSlotCount"] > 0,
            (
                f"classMapped={merged['classMappedUeReflectionCount']}/{merged['ueReflectionCount']} "
                f"mappedSlots={merged['mappedUeReflectionSlotCount']}/{merged['ueReflectionSlotCount']}"
            ),
            "no read-only UClass reflection probe found a mapped class with mapped field/function slots",
        )
    )
    gates.append(
        gate(
            "ue-reflection-field-walk",
            merged["candidateUeReflectionFieldCount"] > 0
            and merged["classMappedUeReflectionFieldCount"] > 0,
            (
                f"candidates={merged['candidateUeReflectionFieldCount']}/{merged['ueReflectionFieldCount']} "
                f"classMapped={merged['classMappedUeReflectionFieldCount']}"
            ),
            "no bounded UClass field/function chain walk produced class-mapped reflected field candidates",
        )
    )
    gates.append(
        gate(
            "ue-reflection-property-descriptors",
            merged["candidateUeReflectionPropertyCount"] > 0
            and merged["readableUeReflectionPropertyCount"] > 0,
            (
                f"candidates={merged['candidateUeReflectionPropertyCount']}/{merged['ueReflectionPropertyCount']} "
                f"readable={merged['readableUeReflectionPropertyCount']}"
            ),
            "no bounded FProperty descriptor probe produced readable property metadata",
        )
    )
    gates.append(
        gate(
            "ue-function-param-descriptors",
            merged["rootedUeFunctionParamRootCount"] > 0
            and merged["candidateUeFunctionParamCount"] > 0
            and merged["readableUeFunctionParamCount"] > 0,
            (
                f"roots={merged['rootedUeFunctionParamRootCount']}/{merged['ueFunctionParamRootCount']} "
                f"descriptors={merged['readableUeFunctionParamCount']}/{merged['ueFunctionParamCount']}"
            ),
            "no bounded UFunction param descriptor probe produced readable param metadata",
        )
    )
    gates.append(
        gate(
            "ue-function-param-container-children",
            merged["decodedUeFunctionParamContainerChildCount"] > 0,
            (
                f"decoded={merged['decodedUeFunctionParamContainerChildCount']} "
                f"candidates={merged['candidateUeFunctionParamContainerChildCount']}/"
                f"{merged['ueFunctionParamContainerChildCount']}"
            ),
            "no bounded UFunction container param scan produced decoded inner/key/value child property metadata",
        )
    )
    gates.append(
        gate(
            "ue-function-identities",
            merged["namedUeFunctionParamCount"] > 0
            and merged["uniqueUeFunctionPathCount"] > 0,
            (
                f"named={merged['namedUeFunctionParamCount']}/{merged['readableUeFunctionParamCount']} "
                f"paths={merged['uniqueUeFunctionPathCount']} "
                f"sample={merged['ueFunctionPaths'][:3]}"
            ),
            "no decoded UFunction identity produced a Lua-visible runtime function path",
        )
    )
    gates.append(
        gate(
            "ue-function-flags",
            merged["readableUeFunctionFlagRootCount"] > 0
            and merged["readableUeFunctionFlagParamCount"] > 0
            and merged["ueFunctionFlagPathCount"] > 0,
            (
                f"roots={merged['readableUeFunctionFlagRootCount']} "
                f"descriptors={merged['readableUeFunctionFlagParamCount']} "
                f"paths={merged['ueFunctionFlagPathCount']} "
                f"values={merged['ueFunctionFlagValues'][:4]}"
            ),
            "no bounded UFunction probe produced readable FunctionFlags promoted to Lua-visible function handles",
        )
    )
    gates.append(
        gate(
            "ue-reflection-property-values",
            merged["readUeReflectionValueCount"] > 0,
            f"read={merged['readUeReflectionValueCount']}/{merged['ueReflectionValueCount']}",
            "no bounded reflected property value probe read container bytes",
        )
    )
    gates.append(
        gate(
            "ue-pointer-probe",
            merged["mappedUePointerCount"] > 0,
            f"targetMapped={merged['mappedUePointerCount']}/{merged['uePointerCount']}",
            "no UE anchor pointer probe resolved to a mapped target",
        )
    )
    gates.append(
        gate(
            "ue-layout-probe",
            merged["readableUeLayoutCount"] > 0 and merged["mappedUeLayoutSlotCount"] > 0,
            f"readable={merged['readableUeLayoutCount']}/{merged['ueLayoutCount']} mappedSlots={merged['mappedUeLayoutSlotCount']}/{merged['ueLayoutSlotCount']}",
            "no UE layout probe produced a readable target with mapped pointer slots",
        )
    )
    gates.append(
        gate(
            "ue-uobject-probe",
            merged["candidateUeUObjectCount"] > 0 and merged["classMappedUeUObjectCount"] > 0,
            f"candidates={merged['candidateUeUObjectCount']}/{merged['ueUObjectCount']} classMapped={merged['classMappedUeUObjectCount']}",
            "no UObjectBase candidate probe produced a class-mapped object candidate",
        )
    )
    gates.append(
        gate(
            "signature-manifest-exact",
            signatures["exactOnly"],
            f"patterns={signatures['patternCount']} statuses={signatures['statusCounts']}",
            "no exact same-build signature validation, or at least one signature is missing/ambiguous/moved",
        )
    )
    gates.append(
        gate(
            "signature-manifest-promotable",
            signatures["allPromotable"],
            f"promotable={signatures['promotableCount']}/{signatures['patternCount']}",
            "no promotable signature validation, or at least one signature is missing/ambiguous",
        )
    )
    gates.append(
        gate(
            "hook-dispatch-self-test",
            merged["passedHookSelfTestCount"] > 0,
            f"passed={merged['passedHookSelfTestCount']}/{merged['hookSelfTestCount']}",
            "no guarded hook-dispatch self-test passed in scoped logs",
        )
    )
    gates.append(
        gate(
            "mod-dispatch-self-test",
            merged["passedModSelfTestCount"] > 0,
            f"passed={merged['passedModSelfTestCount']}/{merged['modSelfTestCount']}",
            "no native mod-dispatch lifecycle self-test passed in scoped logs",
        )
    )
    gates.append(
        gate(
            "lua-dispatch-self-test",
            merged["passedLuaSelfTestCount"] > 0
            and merged["passedLuaCallbackSelfTestCount"] > 0
            and merged["passedLuaApiSelfTestCount"] > 0,
            (
                f"passed={merged['passedLuaSelfTestCount']}/{merged['luaSelfTestCount']} "
                f"callbackBridge={merged['passedLuaCallbackSelfTestCount']} "
                f"apiSurface={merged['passedLuaApiSelfTestCount']}"
            ),
            "no Lua runtime execution plus callback-bridge and API-surface self-test passed in scoped logs",
        )
    )
    gates.append(
        gate(
            "lua-object-api",
            merged["passedLuaObjectApiSelfTestCount"] > 0
            and merged["luaObjectApiModFinishCount"] > 0,
            (
                f"selfTest={merged['passedLuaObjectApiSelfTestCount']} "
                f"mods={merged['luaObjectApiModFinishCount']}"
            ),
            "no Lua object lookup/enumeration API self-test and mod-entrypoint use passed in scoped logs",
        )
    )
    gates.append(
        gate(
            "lua-function-iteration",
            merged["luaFunctionIterationModFinishCount"] > 0,
            f"mods={merged['luaFunctionIterationModFinishCount']}",
            "no Lua mod proved ForEachFunction enumerated promoted UFunction handles from an owner/class handle",
        )
    )
    gates.append(
        gate(
            "lua-process-console-exec-hooks",
            merged["luaProcessConsoleExecHookModFinishCount"] > 0,
            f"mods={merged['luaProcessConsoleExecHookModFinishCount']}",
            "no Lua mod proved RegisterProcessConsoleExecPreHook/PostHook dispatch around loader-owned ProcessConsoleExec",
        )
    )
    gates.append(
        gate(
            "lua-local-player-exec-hooks",
            merged["luaLocalPlayerExecHookModFinishCount"] > 0,
            f"mods={merged['luaLocalPlayerExecHookModFinishCount']}",
            "no Lua mod proved RegisterULocalPlayerExecPreHook/PostHook dispatch around loader-owned ULocalPlayerExec",
        )
    )
    gates.append(
        gate(
            "lua-call-function-hooks",
            merged["luaCallFunctionHookModFinishCount"] > 0,
            f"mods={merged['luaCallFunctionHookModFinishCount']}",
            "no Lua mod proved RegisterCallFunctionByNameWithArgumentsPreHook/PostHook dispatch around loader-owned CallFunction",
        )
    )
    gates.append(
        gate(
            "lua-lifecycle-hooks",
            merged["luaLifecycleHookModFinishCount"] > 0,
            f"mods={merged['luaLifecycleHookModFinishCount']}",
            "no Lua mod proved RegisterCustomEvent and lifecycle pre/post hooks dispatch around loader-owned lifecycle shims",
        )
    )
    gates.append(
        gate(
            "lua-object-notify",
            merged["luaNotifyOnNewObjectModFinishCount"] > 0,
            f"mods={merged['luaNotifyOnNewObjectModFinishCount']}",
            "no Lua mod proved NotifyOnNewObject dispatched multiple callbacks for a newly constructed object handle",
        )
    )
    gates.append(
        gate(
            "lua-synthetic-outer",
            merged["luaSyntheticOuterModFinishCount"] > 0,
            f"mods={merged['luaSyntheticOuterModFinishCount']}",
            "no Lua mod proved StaticConstructObject preserved a loader-owned outer handle",
        )
    )
    gates.append(
        gate(
            "lua-world-context",
            merged["luaWorldContextModFinishCount"] > 0,
            f"mods={merged['luaWorldContextModFinishCount']}",
            "no Lua mod proved GetWorld resolved a world-like handle or a world outer chain",
        )
    )
    gates.append(
        gate(
            "lua-class-default-object",
            merged["luaClassDefaultObjectModFinishCount"] > 0,
            f"mods={merged['luaClassDefaultObjectModFinishCount']}",
            "no Lua mod proved GetCDO returned a class-default-object handle",
        )
    )
    gates.append(
        gate(
            "lua-level",
            merged["luaLevelModFinishCount"] > 0,
            f"mods={merged['luaLevelModFinishCount']}",
            "no Lua mod proved GetLevel resolved a loader-owned level handle",
        )
    )
    gates.append(
        gate(
            "lua-process-event-self-test",
            merged["passedLuaProcessEventSelfTestCount"] > 0,
            f"passed={merged['passedLuaProcessEventSelfTestCount']}/{merged['luaProcessEventSelfTestCount']}",
            "no Lua callback bridge passed through a ProcessEvent-shaped hook/trampoline self-test",
        )
    )
    gates.append(
        gate(
            "ue-process-event-hook-probe",
            merged["passedUeProcessEventHookCount"] > 0,
            f"passed={merged['passedUeProcessEventHookCount']}/{merged['ueProcessEventHookCount']}",
            "no resolved ProcessEvent target passed guarded install/restore probing",
        )
    )
    gates.append(
        gate(
            "ue-process-event-live-hook",
            merged["installedUeProcessEventLiveHookCount"] > 0,
            (
                f"installed={merged['installedUeProcessEventLiveHookCount']}/{merged['ueProcessEventLiveHookCount']} "
                f"restored={merged['restoredUeProcessEventLiveHookCount']} "
                f"statuses={merged['ueProcessEventLiveHookStatusCounts']}"
            ),
            "no persistent ProcessEvent hook scaffold was installed on a resolved target",
        )
    )
    gates.append(
        gate(
            "ue-process-event-dispatch-self-test",
            merged["armedUeProcessEventDispatchSelfTestCount"] > 0,
            f"armed={merged['armedUeProcessEventDispatchSelfTestCount']}/{merged['ueProcessEventDispatchSelfTestCount']}",
            "no native ProcessEvent pre/original/post dispatch callback registry self-test was armed",
        )
    )
    gates.append(
        gate(
            "ue-process-event-live-lua-dispatch",
            merged["armedUeProcessEventLiveLuaDispatchCount"] > 0,
            (
                f"armed={merged['armedUeProcessEventLiveLuaDispatchCount']}/{merged['ueProcessEventLiveLuaDispatchCount']} "
                f"closed={merged['closedUeProcessEventLiveLuaDispatchCount']} "
                f"statuses={merged['ueProcessEventLiveLuaDispatchStatusCounts']}"
            ),
            "no live ProcessEvent hook armed Lua RegisterHook pre/post callbacks",
        )
    )
    gates.append(
        gate(
            "ue-process-event-live-context",
            merged["resolvedUeProcessEventLiveContextCount"] > 0,
            (
                f"resolved={merged['resolvedUeProcessEventLiveContextCount']}/"
                f"{merged['ueProcessEventLiveContextCount']}"
            ),
            "no sampled live ProcessEvent call resolved object, function path, params pointer, and function param descriptors",
        )
    )
    gates.append(
        gate(
            "ue-process-event-live-param-values",
            merged["readUeProcessEventLiveParamCount"] > 0,
            (
                f"read={merged['readUeProcessEventLiveParamCount']}/"
                f"{merged['ueProcessEventLiveParamCount']}"
            ),
            "no sampled live ProcessEvent params were read through promoted function param descriptors",
        )
    )
    gates.append(
        gate(
            "ue-process-event-live-raw-param-values",
            merged["rawUeProcessEventLiveParamCount"] > 0,
            (
                f"raw={merged['rawUeProcessEventLiveParamCount']} "
                f"total={merged['ueProcessEventLiveParamCount']}"
            ),
            "no sampled complex live ProcessEvent params were read as bounded raw payload bytes",
        )
    )
    gates.append(
        gate(
            "ue-process-event-live-container-param-values",
            merged["containerUeProcessEventLiveParamCount"] > 0,
            (
                f"container={merged['containerUeProcessEventLiveParamCount']} "
                f"total={merged['ueProcessEventLiveParamCount']}"
            ),
            "no sampled array/set/map live ProcessEvent params were read as typed container header values",
        )
    )
    gates.append(
        gate(
            "ue-process-event-live-container-data-samples",
            merged["sampledContainerUeProcessEventLiveParamCount"] > 0,
            (
                f"sampled={merged['sampledContainerUeProcessEventLiveParamCount']} "
                f"container={merged['containerUeProcessEventLiveParamCount']}"
            ),
            "no sampled live array ProcessEvent params had a readable data pointer for bounded storage bytes",
        )
    )
    gates.append(
        gate(
            "ue-process-event-lua-context-handles",
            merged["ueProcessEventLuaContextHandleCount"] > 0,
            (
                f"withHandles={merged['ueProcessEventLuaContextHandleCount']} "
                f"installed={merged['installedUeProcessEventLiveHookCount']}"
            ),
            "no live ProcessEvent Lua callback received UObject, UFunction, and params context tables",
        )
    )
    gates.append(
        gate(
            "ue-process-event-lua-param-accessors",
            merged["luaProcessEventParamAccessorSelfTestCount"] > 0
            and merged["ueProcessEventLiveLuaParamAccessorCount"] > 0,
            (
                f"selfTests={merged['luaProcessEventParamAccessorSelfTestCount']} "
                f"liveHooks={merged['ueProcessEventLiveLuaParamAccessorCount']}"
            ),
            "no function-param descriptor GetFunctionParams plus descriptor-handle GetParamDescriptor/GetParamValue/SetParamValue access passed through both the ProcessEvent self-test and live hook",
        )
    )
    gates.append(
        gate(
            "ue-process-event-lua-scalar-param-accessors",
            merged["luaProcessEventScalarParamAccessorSelfTestCount"] > 0
            and merged["ueProcessEventLiveLuaScalarParamAccessorCount"] > 0,
            (
                f"selfTests={merged['luaProcessEventScalarParamAccessorSelfTestCount']} "
                f"liveHooks={merged['ueProcessEventLiveLuaScalarParamAccessorCount']}"
            ),
            "no ProcessEvent self/live Lua path proved signed/unsigned integer plus float/double GetParamValue/SetParamValue coverage",
        )
    )
    gates.append(
        gate(
            "ue-process-event-lua-name-string-param-accessors",
            merged["luaProcessEventNameStringParamAccessorSelfTestCount"] > 0
            and merged["ueProcessEventLiveLuaNameStringParamAccessorCount"] > 0,
            (
                f"selfTests={merged['luaProcessEventNameStringParamAccessorSelfTestCount']} "
                f"liveHooks={merged['ueProcessEventLiveLuaNameStringParamAccessorCount']}"
            ),
            "no ProcessEvent self/live Lua path proved FName/FString GetParamValue/SetParamValue coverage",
        )
    )
    gates.append(
        gate(
            "ue-process-event-lua-struct-param-accessors",
            merged["luaProcessEventStructParamAccessorSelfTestCount"] > 0
            and merged["ueProcessEventLiveLuaStructParamAccessorCount"] > 0,
            (
                f"selfTests={merged['luaProcessEventStructParamAccessorSelfTestCount']} "
                f"liveHooks={merged['ueProcessEventLiveLuaStructParamAccessorCount']}"
            ),
            "no ProcessEvent self/live Lua path proved FVector-shaped FStructProperty GetParamValue/SetParamValue coverage",
        )
    )
    gates.append(
        gate(
            "ue-process-event-lua-hook-routing",
            merged["routedLuaProcessEventSelfTestCount"] > 0
            and merged["multiHookUeProcessEventLiveLuaDispatchCount"] > 0
            and merged["routedUeProcessEventLiveLuaHookCount"] > 0,
            (
                f"selfTests={merged['routedLuaProcessEventSelfTestCount']} "
                f"multiHookDispatch={merged['multiHookUeProcessEventLiveLuaDispatchCount']} "
                f"liveHooks={merged['routedUeProcessEventLiveLuaHookCount']}"
            ),
            "no ProcessEvent Lua self/live path proved multiple RegisterHook entries with only the matching function callback firing",
        )
    )
    gates.append(
        gate(
            "lua-reflection-self-test",
            merged["passedLuaReflectionSelfTestCount"] > 0,
            f"passed={merged['passedLuaReflectionSelfTestCount']}/{merged['luaReflectionSelfTestCount']}",
            "no Lua reflection/property get-set/function-call self-test passed",
        )
    )
    gates.append(
        gate(
            "lua-reflection-raw-set",
            merged["rawSetLuaReflectionSelfTestCount"] > 0,
            f"rawSet={merged['rawSetLuaReflectionSelfTestCount']}/{merged['luaReflectionSelfTestCount']}",
            "no Lua reflection self-test proved guarded raw reflected scalar SetPropertyValue",
        )
    )
    gates.append(
        gate(
            "lua-reflection-named-property",
            merged["namedLuaReflectionSelfTestCount"] > 0,
            f"named={merged['namedLuaReflectionSelfTestCount']}/{merged['luaReflectionSelfTestCount']}",
            "no Lua reflection self-test used a decoded FName-backed property alias",
        )
    )
    gates.append(
        gate(
            "lua-reflection-numeric-property-values",
            merged["numericLuaReflectionSelfTestCount"] > 0,
            f"numeric={merged['numericLuaReflectionSelfTestCount']}/{merged['luaReflectionSelfTestCount']}",
            "no Lua reflection self-test proved FFloatProperty/FDoubleProperty get/set values",
        )
    )
    gates.append(
        gate(
            "lua-reflection-name-text-property-values",
            merged["nameTextLuaReflectionSelfTestCount"] > 0,
            f"nameText={merged['nameTextLuaReflectionSelfTestCount']}/{merged['luaReflectionSelfTestCount']}",
            "no Lua reflection self-test proved FNameProperty/FTextProperty get/set values",
        )
    )
    gates.append(
        gate(
            "lua-reflection-array-inner-property",
            merged["arrayInnerLuaReflectionSelfTestCount"] > 0,
            f"arrayInner={merged['arrayInnerLuaReflectionSelfTestCount']}/{merged['luaReflectionSelfTestCount']}",
            "no Lua reflection self-test proved FArrayProperty:GetInner() metadata",
        )
    )
    gates.append(
        gate(
            "lua-reflection-enum-property",
            merged["enumLuaReflectionSelfTestCount"] > 0,
            f"enum={merged['enumLuaReflectionSelfTestCount']}/{merged['luaReflectionSelfTestCount']}",
            "no Lua reflection self-test proved FEnumProperty:GetEnum()/GetUnderlyingProperty() metadata",
        )
    )
    gates.append(
        gate(
            "lua-reflection-container-properties",
            merged["containerLuaReflectionSelfTestCount"] > 0,
            f"containers={merged['containerLuaReflectionSelfTestCount']}/{merged['luaReflectionSelfTestCount']}",
            "no Lua reflection self-test proved FSetProperty element and FMapProperty key/value metadata",
        )
    )
    gates.append(
        gate(
            "lua-reflection-import-text",
            merged["importTextLuaReflectionSelfTestCount"] > 0,
            f"importText={merged['importTextLuaReflectionSelfTestCount']}/{merged['luaReflectionSelfTestCount']}",
            "no Lua reflection self-test proved bounded FProperty:ImportText text-to-value writes",
        )
    )
    gates.append(
        gate(
            "lua-reflection-export-text",
            merged["exportTextLuaReflectionSelfTestCount"] > 0,
            f"exportText={merged['exportTextLuaReflectionSelfTestCount']}/{merged['luaReflectionSelfTestCount']}",
            "no Lua reflection self-test proved bounded FProperty:ExportText value-to-text exports",
        )
    )
    gates.append(
        gate(
            "lua-reflection-property-metadata",
            merged["propertyMetadataLuaReflectionSelfTestCount"] > 0,
            (
                f"metadata={merged['propertyMetadataLuaReflectionSelfTestCount']}/"
                f"{merged['luaReflectionSelfTestCount']}"
            ),
            "no Lua reflection self-test proved FProperty metadata accessors",
        )
    )
    gates.append(
        gate(
            "lua-reflection-descriptor-values",
            merged["descriptorValueLuaReflectionSelfTestCount"] > 0,
            (
                f"descriptorValues={merged['descriptorValueLuaReflectionSelfTestCount']}/"
                f"{merged['luaReflectionSelfTestCount']}"
            ),
            "no Lua reflection self-test proved descriptor-level FProperty GetValue/SetValue",
        )
    )
    gates.append(
        gate(
            "lua-mod-entrypoints",
            merged["passedLuaModScriptCount"] > 0
            and merged["passedLuaModDispatchSelfTestCount"] > 0
            and merged["passedLuaModFinishCount"] > 0,
            (
                f"scripts={merged['passedLuaModScriptCount']}/{merged['luaModScriptCount']} "
                f"dispatch={merged['passedLuaModDispatchSelfTestCount']}/{merged['luaModDispatchSelfTestCount']} "
                f"finishes={merged['passedLuaModFinishCount']}/{merged['luaModFinishCount']}"
            ),
            "no Lua mod entrypoint load plus callback-dispatch self-test passed in scoped logs",
        )
    )
    gates.append(
        gate(
            "lua-object-registry",
            merged["ueLuaObjectRegistryCount"] > 0,
            (
                f"added={merged['addedLuaObjectRegistryCount']}/{merged['luaObjectRegistryCount']} "
                f"ueCandidates={merged['ueLuaObjectRegistryCount']}"
            ),
            "no class-mapped UObject probe candidate was added to the Lua object registry",
        )
    )
    gates.append(
        gate(
            "lua-decoded-object-aliases",
            merged["decodedLuaObjectAliasRegistryCount"] > 0,
            (
                f"added={merged['decodedLuaObjectAliasRegistryCount']} "
                f"skippedDuplicates={merged['skippedDecodedLuaObjectAliasRegistryCount']}"
            ),
            "no FName-decoded UObject/object-array name was promoted into a Lua object alias",
        )
    )
    gates.append(
        gate(
            "ue-object-array-registry",
            merged["objectArrayLuaObjectRegistryCount"] > 0,
            (
                f"objectArrayCandidates={merged['objectArrayLuaObjectRegistryCount']} "
                f"finishedArrays={merged['finishedUeObjectArrayCount']}/{merged['ueObjectArrayCount']}"
            ),
            "no bounded object-array walk added a candidate to the Lua object registry",
        )
    )
    gates.append(
        gate(
            "ue-object-internal-flags",
            merged["internalFlagUeObjectArrayItemCount"] > 0
            and merged["nonzeroInternalFlagUeObjectArrayItemCount"] > 0,
            (
                f"readable={merged['internalFlagUeObjectArrayItemCount']}/{merged['ueObjectArrayItemCount']} "
                f"nonzero={merged['nonzeroInternalFlagUeObjectArrayItemCount']}"
            ),
            "no object-array item produced readable nonzero InternalFlags for Lua HasAnyInternalFlags",
        )
    )
    gates.append(
        gate(
            "ue-fname-decoder",
            merged["decodedUeFNameCount"] > 0,
            f"decoded={merged['decodedUeFNameCount']}/{merged['ueFNameCount']}",
            "no UObject or object-array candidate resolved through a bounded FNamePool decoder",
        )
    )

    gate_map = {item["name"]: item["passed"] for item in gates}
    ready_object_discovery = (
        gate_map["loader-loaded"]
        and gate_map["scan-completed"]
        and gate_map["ue-names"]
        and gate_map["ue-objects"]
        and gate_map["ue-world"]
        and gate_map["ue-pointer-probe"]
        and gate_map["ue-layout-probe"]
        and gate_map["ue-uobject-probe"]
        and gate_map["ue-object-internal-flags"]
        and gate_map["ue-fname-decoder"]
        and gate_map["lua-decoded-object-aliases"]
    )
    ready_hooks = (
        ready_object_discovery
        and gate_map["ue-dispatch"]
        and gate_map["signature-manifest-promotable"]
        and gate_map["hook-dispatch-self-test"]
        and gate_map["ue-process-event-hook-probe"]
        and gate_map["ue-process-event-live-hook"]
        and gate_map["ue-process-event-dispatch-self-test"]
    )
    ready_reflection = (
        ready_object_discovery
        and gate_map["ue-reflection-surface"]
        and gate_map["ue-reflection-probe"]
        and gate_map["ue-reflection-field-walk"]
        and gate_map["ue-reflection-property-descriptors"]
        and gate_map["ue-function-param-descriptors"]
        and gate_map["ue-function-param-container-children"]
        and gate_map["ue-function-identities"]
        and gate_map["ue-function-flags"]
        and gate_map["ue-reflection-property-values"]
    )
    ready_lua = (
        ready_hooks
        and ready_reflection
        and gate_map["mod-dispatch-self-test"]
        and gate_map["lua-dispatch-self-test"]
        and gate_map["lua-object-api"]
        and gate_map["lua-function-iteration"]
        and gate_map["lua-process-console-exec-hooks"]
        and gate_map["lua-local-player-exec-hooks"]
        and gate_map["lua-call-function-hooks"]
        and gate_map["lua-lifecycle-hooks"]
        and gate_map["lua-object-notify"]
        and gate_map["lua-synthetic-outer"]
        and gate_map["lua-world-context"]
        and gate_map["lua-class-default-object"]
        and gate_map["lua-level"]
        and gate_map["lua-reflection-self-test"]
        and gate_map["lua-reflection-numeric-property-values"]
        and gate_map["lua-reflection-name-text-property-values"]
        and gate_map["lua-process-event-self-test"]
        and gate_map["ue-process-event-live-lua-dispatch"]
        and gate_map["ue-process-event-live-context"]
        and gate_map["ue-process-event-live-param-values"]
        and gate_map["ue-process-event-live-raw-param-values"]
        and gate_map["ue-process-event-live-container-param-values"]
        and gate_map["ue-process-event-live-container-data-samples"]
        and gate_map["ue-process-event-lua-context-handles"]
        and gate_map["ue-process-event-lua-param-accessors"]
        and gate_map["ue-process-event-lua-scalar-param-accessors"]
        and gate_map["ue-process-event-lua-name-string-param-accessors"]
        and gate_map["ue-process-event-lua-struct-param-accessors"]
        and gate_map["ue-process-event-lua-hook-routing"]
        and gate_map["lua-mod-entrypoints"]
        and gate_map["lua-object-registry"]
        and gate_map["lua-decoded-object-aliases"]
        and gate_map["ue-object-array-registry"]
        and gate_map["ue-fname-decoder"]
    )

    next_steps = []
    for item in gates:
        if not item["passed"] and item["name"].startswith("ue-"):
            next_steps.append(item["blocker"])
    if not ready_object_discovery:
        next_steps.append("keep work in read-only scan/xref mode")
    elif not gate_map["hook-dispatch-self-test"]:
        next_steps.append("run the guarded hook-dispatch self-test before ProcessEvent hook work")
    elif not ready_hooks:
        next_steps.append("validate read-only object/world/dispatch surfaces before ProcessEvent hook work")
    elif not gate_map["ue-function-param-descriptors"]:
        next_steps.append("enable the bounded UFunction param descriptor probe from functionLink candidates before Lua dispatch")
    elif not gate_map["ue-function-param-container-children"]:
        next_steps.append("promote decoded inner/key/value child property metadata from live container UFunction params before typed container element unmarshaling")
    elif not gate_map["ue-function-identities"]:
        next_steps.append("decode functionLink FNames into runtime UFunction paths before exposing RegisterHook routing to Lua mods")
    elif not gate_map["ue-function-flags"]:
        next_steps.append("read and promote UFunction FunctionFlags into Lua-visible function handles before treating GetFunctionFlags as live-compatible")
    elif not ready_reflection:
        next_steps.append("enable the read-only UE reflection field/function chain walk, FProperty descriptor probe, UFunction param descriptor probe, and bounded property value probe before Lua dispatch")
    elif not gate_map["mod-dispatch-self-test"]:
        next_steps.append("run the native mod-dispatch lifecycle self-test before Lua binding work")
    elif not gate_map["lua-dispatch-self-test"]:
        next_steps.append("run the Lua runtime execution, callback-bridge, and API-surface self-test before exposing UE4SS Lua APIs")
    elif not gate_map["lua-function-iteration"]:
        next_steps.append("run a Lua mod that proves ForEachFunction enumerates promoted UFunction handles from object/class handles")
    elif not gate_map["lua-process-console-exec-hooks"]:
        next_steps.append("run a Lua mod that proves RegisterProcessConsoleExecPreHook/PostHook dispatch around loader-owned ProcessConsoleExec")
    elif not gate_map["lua-local-player-exec-hooks"]:
        next_steps.append("run a Lua mod that proves RegisterULocalPlayerExecPreHook/PostHook dispatch around loader-owned ULocalPlayerExec")
    elif not gate_map["lua-call-function-hooks"]:
        next_steps.append("run a Lua mod that proves RegisterCallFunctionByNameWithArgumentsPreHook/PostHook dispatch around loader-owned CallFunction")
    elif not gate_map["lua-lifecycle-hooks"]:
        next_steps.append("run a Lua mod that proves RegisterCustomEvent and lifecycle pre/post hooks dispatch around loader-owned lifecycle shims")
    elif not gate_map["lua-object-notify"]:
        next_steps.append("run a Lua mod that proves NotifyOnNewObject dispatches multiple callbacks for a newly constructed object handle")
    elif not gate_map["lua-synthetic-outer"]:
        next_steps.append("run a Lua mod that proves StaticConstructObject preserves and resolves a loader-owned outer handle")
    elif not gate_map["lua-world-context"]:
        next_steps.append("run a Lua mod that proves GetWorld resolves a world-like handle and a world outer chain")
    elif not gate_map["lua-class-default-object"]:
        next_steps.append("run a Lua mod that proves GetCDO returns a class-default-object handle")
    elif not gate_map["lua-level"]:
        next_steps.append("run a Lua mod that proves GetLevel resolves a loader-owned level handle")
    elif not gate_map["lua-reflection-self-test"]:
        next_steps.append("run the Lua reflection/property self-test before live FProperty marshaling")
    elif not gate_map["lua-reflection-numeric-property-values"]:
        next_steps.append("run the Lua reflection self-test with FFloatProperty/FDoubleProperty get/set coverage")
    elif not gate_map["lua-reflection-name-text-property-values"]:
        next_steps.append("run the Lua reflection self-test with FNameProperty/FTextProperty get/set coverage")
    elif not gate_map["lua-process-event-self-test"]:
        next_steps.append("run the ProcessEvent-shaped Lua callback hook self-test before game ProcessEvent hook work")
    elif not gate_map["ue-process-event-hook-probe"]:
        next_steps.append("run the guarded ProcessEvent install/restore probe on a resolved ProcessEvent target")
    elif not gate_map["ue-process-event-live-hook"]:
        next_steps.append("install the opt-in persistent ProcessEvent hook scaffold on a resolved target")
    elif not gate_map["ue-process-event-dispatch-self-test"]:
        next_steps.append("arm and invoke the native ProcessEvent dispatch callback registry")
    elif not gate_map["ue-process-event-live-lua-dispatch"]:
        next_steps.append("arm the opt-in live ProcessEvent Lua dispatch bridge and prove RegisterHook callbacks run from the live hook")
    elif not gate_map["ue-process-event-lua-context-handles"]:
        next_steps.append("route live ProcessEvent Lua callbacks with resolved UObject, UFunction, and params context tables")
    elif not gate_map["ue-process-event-lua-param-accessors"]:
        next_steps.append("prove Lua GetFunctionParams plus descriptor-handle GetParamDescriptor/GetParamValue/SetParamValue access from both ProcessEvent self-test and live hook callbacks")
    elif not gate_map["ue-process-event-lua-scalar-param-accessors"]:
        next_steps.append("prove signed/unsigned integer plus float/double ProcessEvent Lua param get/set coverage in both self-test and live hook callbacks")
    elif not gate_map["ue-process-event-lua-name-string-param-accessors"]:
        next_steps.append("prove FName/FString ProcessEvent Lua param get/set coverage in both self-test and live hook callbacks")
    elif not gate_map["ue-process-event-lua-struct-param-accessors"]:
        next_steps.append("prove FVector-shaped FStructProperty ProcessEvent Lua param get/set coverage in both self-test and live hook callbacks")
    elif not gate_map["ue-process-event-lua-hook-routing"]:
        next_steps.append("prove multiple Lua RegisterHook entries route only the matching ProcessEvent function path before exposing mod callbacks")
    elif not gate_map["lua-mod-entrypoints"]:
        next_steps.append("load a Lua mod entrypoint and prove its registered callbacks dispatch before exposing UE4SS Lua APIs")
    elif not gate_map["lua-object-registry"]:
        next_steps.append("ingest class-mapped UObject probe candidates into the Lua object registry")
    elif not gate_map["lua-decoded-object-aliases"]:
        next_steps.append("promote decoded UObject FNames into Lua object aliases before relying on UE4SS-style FindObject names")
    elif not gate_map["ue-object-array-registry"]:
        next_steps.append("walk a bounded GUObjectArray/FChunkedFixedUObjectArray candidate into the Lua object registry")
    elif not gate_map["ue-object-internal-flags"]:
        next_steps.append("promote readable FUObjectItem InternalFlags into Lua object handles before relying on HasAnyInternalFlags")
    elif not gate_map["ue-fname-decoder"]:
        next_steps.append("decode UObject names through a bounded FNamePool reader")
    elif not gate_map["lua-reflection-named-property"]:
        next_steps.append("run the Lua reflection self-test with decoded FName property aliases enabled")
    elif not ready_lua:
        next_steps.append("add guarded ProcessEvent hook dispatch before Lua/mod APIs")
    else:
        next_steps.append(
            "prove promoted UFunction param descriptors and class-aware GetParamValue/SetParamValue against a real ProcessEvent ctx.Function and active params pointer before full FProperty marshaling"
        )

    return {
        "schemaVersion": "ue4sslinux-ue4ss-port-readiness/v1",
        "logCount": len(log_summaries),
        "loaders": merged["loaders"],
        "pids": merged["pids"],
        "gates": gates,
        "signatures": signatures,
        "ue": ue,
        "ready": {
            "objectDiscovery": ready_object_discovery,
            "hooks": ready_hooks,
            "reflection": ready_reflection,
            "luaDispatch": ready_lua,
            "pointerProbe": gate_map["ue-pointer-probe"],
            "layoutProbe": gate_map["ue-layout-probe"],
            "uobjectProbe": gate_map["ue-uobject-probe"],
            "ueReflectionProbe": gate_map["ue-reflection-probe"],
            "ueReflectionFieldWalk": gate_map["ue-reflection-field-walk"],
            "ueReflectionPropertyDescriptors": gate_map["ue-reflection-property-descriptors"],
            "ueFunctionParamDescriptors": gate_map["ue-function-param-descriptors"],
            "ueFunctionParamContainerChildren": gate_map["ue-function-param-container-children"],
            "ueFunctionIdentities": gate_map["ue-function-identities"],
            "ueFunctionFlags": gate_map["ue-function-flags"],
            "ueReflectionPropertyValues": gate_map["ue-reflection-property-values"],
            "hookDispatch": gate_map["hook-dispatch-self-test"],
            "modDispatch": gate_map["mod-dispatch-self-test"],
            "luaRuntime": gate_map["lua-dispatch-self-test"],
            "luaObjectApi": gate_map["lua-object-api"],
            "luaFunctionIteration": gate_map["lua-function-iteration"],
            "luaProcessConsoleExecHooks": gate_map["lua-process-console-exec-hooks"],
            "luaLocalPlayerExecHooks": gate_map["lua-local-player-exec-hooks"],
            "luaCallFunctionHooks": gate_map["lua-call-function-hooks"],
            "luaLifecycleHooks": gate_map["lua-lifecycle-hooks"],
            "luaObjectNotify": gate_map["lua-object-notify"],
            "luaSyntheticOuter": gate_map["lua-synthetic-outer"],
            "luaWorldContext": gate_map["lua-world-context"],
            "luaClassDefaultObject": gate_map["lua-class-default-object"],
            "luaLevel": gate_map["lua-level"],
            "luaReflection": gate_map["lua-reflection-self-test"],
            "luaReflectionRawSet": gate_map["lua-reflection-raw-set"],
            "luaReflectionNamedProperty": gate_map["lua-reflection-named-property"],
            "luaReflectionNumericPropertyValues": gate_map["lua-reflection-numeric-property-values"],
            "luaReflectionNameTextPropertyValues": gate_map["lua-reflection-name-text-property-values"],
            "luaReflectionArrayInnerProperty": gate_map["lua-reflection-array-inner-property"],
            "luaReflectionEnumProperty": gate_map["lua-reflection-enum-property"],
            "luaReflectionContainerProperties": gate_map["lua-reflection-container-properties"],
            "luaReflectionImportText": gate_map["lua-reflection-import-text"],
            "luaReflectionExportText": gate_map["lua-reflection-export-text"],
            "luaReflectionPropertyMetadata": gate_map["lua-reflection-property-metadata"],
            "luaReflectionDescriptorValues": gate_map["lua-reflection-descriptor-values"],
            "luaProcessEvent": gate_map["lua-process-event-self-test"],
            "ueProcessEventHookProbe": gate_map["ue-process-event-hook-probe"],
            "ueProcessEventLiveHook": gate_map["ue-process-event-live-hook"],
            "ueProcessEventDispatch": gate_map["ue-process-event-dispatch-self-test"],
            "ueProcessEventLiveLuaDispatch": gate_map["ue-process-event-live-lua-dispatch"],
            "ueProcessEventLiveContext": gate_map["ue-process-event-live-context"],
            "ueProcessEventLiveParamValues": gate_map["ue-process-event-live-param-values"],
            "ueProcessEventLiveRawParamValues": gate_map["ue-process-event-live-raw-param-values"],
            "ueProcessEventLiveContainerParamValues": gate_map["ue-process-event-live-container-param-values"],
            "ueProcessEventLiveContainerDataSamples": gate_map["ue-process-event-live-container-data-samples"],
            "ueProcessEventLuaContextHandles": gate_map["ue-process-event-lua-context-handles"],
            "ueProcessEventLuaParamAccessors": gate_map["ue-process-event-lua-param-accessors"],
            "ueProcessEventLuaScalarParamAccessors": gate_map["ue-process-event-lua-scalar-param-accessors"],
            "ueProcessEventLuaNameStringParamAccessors": gate_map["ue-process-event-lua-name-string-param-accessors"],
            "ueProcessEventLuaStructParamAccessors": gate_map["ue-process-event-lua-struct-param-accessors"],
            "ueProcessEventLuaHookRouting": gate_map["ue-process-event-lua-hook-routing"],
            "luaMods": gate_map["lua-mod-entrypoints"],
            "luaObjectRegistry": gate_map["lua-object-registry"],
            "luaDecodedObjectAliases": gate_map["lua-decoded-object-aliases"],
            "ueObjectArrayRegistry": gate_map["ue-object-array-registry"],
            "ueObjectInternalFlags": gate_map["ue-object-internal-flags"],
            "ueFNameDecoder": gate_map["ue-fname-decoder"],
            "anchorSignatureResolver": merged["resolvedUeAnchorSignatureCount"] > 0,
        },
        "nextSteps": next_steps,
    }


def markdown(report):
    lines = ["# UE4SS Port Readiness", ""]
    lines.append(f"- Logs: `{report['logCount']}`")
    lines.append(f"- Loaders: `{', '.join(report['loaders']) or 'unknown'}`")
    lines.append(f"- Ready pointer probe: `{str(report['ready']['pointerProbe']).lower()}`")
    lines.append(f"- Ready layout probe: `{str(report['ready']['layoutProbe']).lower()}`")
    lines.append(f"- Ready UObject probe: `{str(report['ready']['uobjectProbe']).lower()}`")
    lines.append(f"- Ready UE reflection probe: `{str(report['ready']['ueReflectionProbe']).lower()}`")
    lines.append(f"- Ready UE reflection field walk: `{str(report['ready']['ueReflectionFieldWalk']).lower()}`")
    lines.append(f"- Ready UE reflection property descriptors: `{str(report['ready']['ueReflectionPropertyDescriptors']).lower()}`")
    lines.append(f"- Ready UE function param descriptors: `{str(report['ready']['ueFunctionParamDescriptors']).lower()}`")
    lines.append(f"- Ready UE function param container children: `{str(report['ready']['ueFunctionParamContainerChildren']).lower()}`")
    lines.append(f"- Ready UE function identities: `{str(report['ready']['ueFunctionIdentities']).lower()}`")
    lines.append(f"- Ready UE function flags: `{str(report['ready']['ueFunctionFlags']).lower()}`")
    lines.append(f"- Ready UE reflection property values: `{str(report['ready']['ueReflectionPropertyValues']).lower()}`")
    lines.append(f"- Ready hook dispatch: `{str(report['ready']['hookDispatch']).lower()}`")
    lines.append(f"- Ready mod dispatch: `{str(report['ready']['modDispatch']).lower()}`")
    lines.append(f"- Ready Lua runtime: `{str(report['ready']['luaRuntime']).lower()}`")
    lines.append(f"- Ready Lua object API: `{str(report['ready']['luaObjectApi']).lower()}`")
    lines.append(f"- Ready Lua function iteration: `{str(report['ready']['luaFunctionIteration']).lower()}`")
    lines.append(f"- Ready Lua ProcessConsoleExec hooks: `{str(report['ready']['luaProcessConsoleExecHooks']).lower()}`")
    lines.append(f"- Ready Lua ULocalPlayerExec hooks: `{str(report['ready']['luaLocalPlayerExecHooks']).lower()}`")
    lines.append(f"- Ready Lua CallFunctionByNameWithArguments hooks: `{str(report['ready']['luaCallFunctionHooks']).lower()}`")
    lines.append(f"- Ready Lua lifecycle hooks: `{str(report['ready']['luaLifecycleHooks']).lower()}`")
    lines.append(f"- Ready Lua object notification: `{str(report['ready']['luaObjectNotify']).lower()}`")
    lines.append(f"- Ready Lua synthetic outer: `{str(report['ready']['luaSyntheticOuter']).lower()}`")
    lines.append(f"- Ready Lua world context: `{str(report['ready']['luaWorldContext']).lower()}`")
    lines.append(f"- Ready Lua class default object: `{str(report['ready']['luaClassDefaultObject']).lower()}`")
    lines.append(f"- Ready Lua level: `{str(report['ready']['luaLevel']).lower()}`")
    lines.append(f"- Ready Lua reflection: `{str(report['ready']['luaReflection']).lower()}`")
    lines.append(f"- Ready Lua reflection raw set: `{str(report['ready']['luaReflectionRawSet']).lower()}`")
    lines.append(f"- Ready Lua reflection named property: `{str(report['ready']['luaReflectionNamedProperty']).lower()}`")
    lines.append(f"- Ready Lua reflection numeric property values: `{str(report['ready']['luaReflectionNumericPropertyValues']).lower()}`")
    lines.append(f"- Ready Lua reflection name/text property values: `{str(report['ready']['luaReflectionNameTextPropertyValues']).lower()}`")
    lines.append(f"- Ready Lua reflection array inner property: `{str(report['ready']['luaReflectionArrayInnerProperty']).lower()}`")
    lines.append(f"- Ready Lua reflection enum property: `{str(report['ready']['luaReflectionEnumProperty']).lower()}`")
    lines.append(f"- Ready Lua reflection container properties: `{str(report['ready']['luaReflectionContainerProperties']).lower()}`")
    lines.append(f"- Ready Lua reflection ImportText: `{str(report['ready']['luaReflectionImportText']).lower()}`")
    lines.append(f"- Ready Lua reflection ExportText: `{str(report['ready']['luaReflectionExportText']).lower()}`")
    lines.append(f"- Ready Lua reflection property metadata: `{str(report['ready']['luaReflectionPropertyMetadata']).lower()}`")
    lines.append(f"- Ready Lua reflection descriptor values: `{str(report['ready']['luaReflectionDescriptorValues']).lower()}`")
    lines.append(f"- Ready Lua ProcessEvent hook: `{str(report['ready']['luaProcessEvent']).lower()}`")
    lines.append(f"- Ready UE ProcessEvent hook probe: `{str(report['ready']['ueProcessEventHookProbe']).lower()}`")
    lines.append(f"- Ready UE ProcessEvent live hook: `{str(report['ready']['ueProcessEventLiveHook']).lower()}`")
    lines.append(f"- Ready UE ProcessEvent dispatch: `{str(report['ready']['ueProcessEventDispatch']).lower()}`")
    lines.append(f"- Ready UE ProcessEvent live Lua dispatch: `{str(report['ready']['ueProcessEventLiveLuaDispatch']).lower()}`")
    lines.append(f"- Ready UE ProcessEvent live context: `{str(report['ready']['ueProcessEventLiveContext']).lower()}`")
    lines.append(f"- Ready UE ProcessEvent live param values: `{str(report['ready']['ueProcessEventLiveParamValues']).lower()}`")
    lines.append(f"- Ready UE ProcessEvent live raw param values: `{str(report['ready']['ueProcessEventLiveRawParamValues']).lower()}`")
    lines.append(f"- Ready UE ProcessEvent live container param values: `{str(report['ready']['ueProcessEventLiveContainerParamValues']).lower()}`")
    lines.append(f"- Ready UE ProcessEvent live container data samples: `{str(report['ready']['ueProcessEventLiveContainerDataSamples']).lower()}`")
    lines.append(f"- Ready UE ProcessEvent Lua context handles: `{str(report['ready']['ueProcessEventLuaContextHandles']).lower()}`")
    lines.append(f"- Ready UE ProcessEvent Lua function-param accessors: `{str(report['ready']['ueProcessEventLuaParamAccessors']).lower()}`")
    lines.append(f"- Ready UE ProcessEvent Lua scalar param accessors: `{str(report['ready']['ueProcessEventLuaScalarParamAccessors']).lower()}`")
    lines.append(f"- Ready UE ProcessEvent Lua name/string param accessors: `{str(report['ready']['ueProcessEventLuaNameStringParamAccessors']).lower()}`")
    lines.append(f"- Ready UE ProcessEvent Lua struct param accessors: `{str(report['ready']['ueProcessEventLuaStructParamAccessors']).lower()}`")
    lines.append(f"- Ready UE ProcessEvent Lua hook routing: `{str(report['ready']['ueProcessEventLuaHookRouting']).lower()}`")
    lines.append(f"- Ready Lua mods: `{str(report['ready']['luaMods']).lower()}`")
    lines.append(f"- Ready Lua object registry: `{str(report['ready']['luaObjectRegistry']).lower()}`")
    lines.append(f"- Ready Lua decoded object aliases: `{str(report['ready']['luaDecodedObjectAliases']).lower()}`")
    lines.append(f"- Ready UE object array registry: `{str(report['ready']['ueObjectArrayRegistry']).lower()}`")
    lines.append(f"- Ready UE object internal flags: `{str(report['ready']['ueObjectInternalFlags']).lower()}`")
    lines.append(f"- Ready UE FName decoder: `{str(report['ready']['ueFNameDecoder']).lower()}`")
    lines.append(f"- Ready signature-resolved anchors: `{str(report['ready']['anchorSignatureResolver']).lower()}`")
    lines.append(f"- Ready object discovery: `{str(report['ready']['objectDiscovery']).lower()}`")
    lines.append(f"- Ready hooks: `{str(report['ready']['hooks']).lower()}`")
    lines.append(f"- Ready reflection: `{str(report['ready']['reflection']).lower()}`")
    lines.append(f"- Ready Lua dispatch: `{str(report['ready']['luaDispatch']).lower()}`")
    lines.append("")
    lines.append("## Gates")
    lines.append("")
    for item in report["gates"]:
        status = "pass" if item["passed"] else "block"
        lines.append(f"- `{status}` `{item['name']}` {item['evidence']}")
        if item["blocker"]:
            lines.append(f"  - blocker: {item['blocker']}")
    lines.append("")
    lines.append("## Next Steps")
    lines.append("")
    for step in report["nextSteps"]:
        lines.append(f"- {step}")
    lines.append("")
    return "\n".join(lines)


def main(argv=None):
    parser = argparse.ArgumentParser(description="Gate UE4SS-port readiness from loader logs and signature validations.")
    parser.add_argument("--client-log", type=Path, action="append", default=[], help="client loader/probe log")
    parser.add_argument("--server-log", type=Path, action="append", default=[], help="server loader/probe log")
    parser.add_argument("--log", type=Path, action="append", default=[], help="generic loader/probe log")
    parser.add_argument("--loader", action="append", default=[])
    parser.add_argument("--pid", action="append", default=[])
    parser.add_argument("--exe-substring", action="append", default=[])
    parser.add_argument("--signature-validation-json", type=Path, action="append", default=[])
    parser.add_argument("--format", choices=("json", "markdown"), default="markdown")
    args = parser.parse_args(argv)

    log_paths = args.log + args.client_log + args.server_log
    if not log_paths:
        parser.error("provide --log, --client-log, or --server-log")
    log_summaries = [
        summarize_log(path, args.loader, args.pid, args.exe_substring)
        for path in log_paths
    ]
    validations = [load_json(path) for path in args.signature_validation_json]
    report = build_report(log_summaries, validations)
    if args.format == "json":
        json.dump(report, sys.stdout, indent=2, sort_keys=True)
        sys.stdout.write("\n")
    else:
        sys.stdout.write(markdown(report))


if __name__ == "__main__":
    main()
