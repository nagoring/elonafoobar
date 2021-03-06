require_relative("tests/lua/support/minctest")

local Chara = require("game.Chara")
local eating_effect = require("core.eating_effect")

Testing.start_in_debug_map()
for name, func in pairs(eating_effect) do
   lrun("test " .. name, function()
      lok(pcall(function() func(Chara.player()) end), "")
   end)
end
