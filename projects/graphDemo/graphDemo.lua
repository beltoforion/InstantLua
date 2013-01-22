function fn(x,z)
  return x/math.sqrt((1-x*x)^2+(2*z*x/300)^2+0.001)
end

cv = Canvas(640, 480, "Pseudo 3d graph")

puab  = 10;  linab = 10
xuntg = -2;  xobg  = 2
yuntg = -7;  yobg  = 7
zuntg =-200; zobg  = 200

wz = 45
mazx=math.cos(wz) 
mazy=math.sin(wz)
masx=640/(xobg-xuntg)
masy=400/(yobg-yuntg)
masz=400/(zobg-zuntg)

--[[
if (xuntg*xobg<=0) then
  cv:moveTo((-xuntg)*masx, 0)
	cv:drawTo((-xuntg)*masx, 400)
end

if (yuntg*yobg<=0) then
  cv:moveTo(0, (y-yuntg)*masy)
	cv:drawTo(640, (y-yuntg)*masx)
end
]]

for z=zobg,zuntg,-1/masz*linab do
  cv:moveTo(-z*masz*mazx, (fn(xuntg,z)-yuntg)*masy-z*masz*mazy)
  for x=xuntg, xobg, 1/masx*puab do
    y=fn(x,z)
    cv:drawTo((x-xuntg)*masx-z*masz*mazx, (y-yuntg)*masy-z*masz*mazy)
	end
end


