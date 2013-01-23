function doSomething()
  print("abc") 
end

local ct = 0
while true do 
  doSomething()

	local stat, err
	if (ct==1) then
		doSomething, err = load("print(\"def\")")
	elseif (ct==2) then
		doSomething, err = load("print(\"ghi\")")
	elseif (ct>=3) then
		break
	end

	if (stat==nil) then
		print(err)
	else
		print("ct="..ct)
	end

	sys.delay(1)
	ct = ct+1
end


