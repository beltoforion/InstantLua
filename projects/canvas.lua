print("Starting canvas test script")
print("---------------------------")

local cv = Canvas(500, 500, "Sierpinsky triangle")
print("cv.width: "..cv.width)
print("cv.height: "..cv.width)
print("cv.title: "..cv.title)

-- draw bounding box
cv:moveTo(0,0)
cv:drawTo(cv.width, 0)
cv:drawTo(cv.width, cv.height)
cv:drawTo(0, cv.height)
cv:drawTo(0, 0)

cv:drawPoint(100, 100)
cv:drawCircle(100, 100, 50)
--cv:drawEllipse(100, 100, 200, 300)

