-- Introduction to lua --
function lua_basics()  
-- First lets define some simple variables --  
a = 1
b = 2

-- array variables need to be initialised using the [] operator first --  
arr_val = { 1,2,3,4,5,6,7,8,9,10 }  
arr_str = {"hello", "world" }  
arr_mixed = { 1, "hello", "world"}  

-- The length of an array can be determined using the table.getn function --  
print("array len:"..table.getn(arr_val))

-- You don't have to initialize arrays --  
arr_val2 = {}  

-- Next we do a simple calculation --  
c = a + b  
d = a - b  
e = a * b  
f = a / b  

-- Lua has the following logical operators --  
a = b ~= c  -- not equal  
a = b == c  -- equal    
a = b <  c  -- less than  
a = b >  c  -- greater  
a = b <= c  -- less or equal  
a = b >= c  -- greater or equal  

-- Code branching works like this --  
if (a~=b) then    
-- do something --  
end    

-- First lets say hello using lua --  
print("This is a small lua sample script")  
 
-- you can output values by concatenating them with strings using the ".." operator --  
count = 1000  
print("Hello World "..count.." times");  

-- You can build loops too --  
sum = 0  
print("Lua can do loops too. Lets count to 10");  
for i = 0, 10 do    
  print("i="..i);  
end

end

function doSomething2(arg1, arg2)
end

function doSomething3(arg1, arg2, arg3)
end
