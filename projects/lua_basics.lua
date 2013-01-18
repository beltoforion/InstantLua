function foo.bar()
end

function foo.bar2()
end

-- require "messagebox"

print("Starting test script")
print("--------------------")


local msgbox1 = MessageBox("Das ist ein Nachrichtenfenster")
--print("msgbox1.this_ptr: "..msgbox1.this_ptr)
print("msgbox1.text:     "..msgbox1.text)
print("msgbox1.detailed_text:  "..msgbox1.detailed_text)
msgbox1:show()

local msgbox2 = MessageBox("Das ist ein Nachrichtenfenster", "mit Hilfstext")
print("msgbox2.text:"..msgbox2.text)
print("msgbox2.detailed_text:"..msgbox2.detailed_text)
msgbox2:show()

--[[

sys.msgbox("This is a Lua test script", "Press ok to continue")

print("sys="..tostring(sys))
sys.delay(.1)

print("sys.client="..sys.client)
sys.delay(.1)

print("sys.time="..sys.time)
sys.delay(.1)

print("sys.time_str="..sys.time_str)
sys.delay(.1)
]]--

print("test script end")
