modname = "LUA"

tickcount = 0

function tick()
   tickcount = tickcount + 1
   if (tickcount % 20) == 0 then
	  tw.sendchat(-1, -2, "tick count from lua: " .. tickcount)
   end
end
