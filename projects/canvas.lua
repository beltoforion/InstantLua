print("Starting test script")
print("--------------------")

local cv = Canvas(500, 500, "My canvas")
print("cv.width: "..cv.width)
print("cv.height: "..cv.width)
print("cv.title: "..cv.title)

-- draw bounding box
cv:moveTo(0,0)
cv:drawTo(cv.width, 0)
cv:drawTo(cv.width, cv.height)
cv:drawTo(0, cv.height)
cv:drawTo(0, 0)

--[[cv:drawLine(0, 0, cv.width, 0)
cv:drawLine(cv.width, 0, cv.width, cv.height)
cv:drawLine(cv.width, cv.height, 0, cv.height)
cv:drawLine(0, cv.height, 0, 0)
]]
