print("Starting canvas test script")
print("---------------------------")

--[[
local cv2 = Canvas(500, 500, "Canvas2")
print("cv2.width: "..cv2.width)
print("cv2.height: "..cv2.width)
print("cv2.title: "..cv2.title)
]]--

local cv = Canvas(500, 500, "Canvas1")
print("cv1.width: "..cv.width)
print("cv1.height: "..cv.width)
print("cv1.title: "..cv.title)

-- draw bounding box
cv:moveTo(0,0)
cv:drawTo(cv.width, 0)
cv:drawTo(cv.width, cv.height)
cv:drawTo(0, cv.height)
cv:drawTo(0, 0)

cv:drawPoint(100, 100)
cv:drawCircle(100, 100, 50)
--cv:drawEllipse(100, 100, 200, 300)

math.randomseed(os.time())
local m = {}

for i=1,1000 do
  print("i:"..i)
end
