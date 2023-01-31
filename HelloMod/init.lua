local ffi = require("ffi")

ffi.cdef([[
bool set_clipboard(const char* text);
]])

local clipboard = ffi.load("mods/HelloMod/dll/clipboard.dll")

function OnWorldInitialized()
    local seed = StatsGetValue("world_seed")
    local text = "Currently playing this seed: " .. seed
    if not clipboard.set_clipboard(text) then
        GamePrint("Couldn't set clipboard!")
    end
end
