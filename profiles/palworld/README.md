# Palworld Profile

Palworld is a validation target for generic UE4/5 runtime behavior. Existing
UE4SS mods are commonly Windows DLL/Lua deployments, so the near-term practical
path is a Windows client or Windows dedicated server under Wine/Proton.

Native Linux dedicated-server support should be treated as experimental until
`ProcessEvent` routing and FProperty marshalling pass profile canaries.
