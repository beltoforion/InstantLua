-----------------------------------------------------------------
-- The code below is the benchmarked code.                     --
-- This can be modified for your own benchmarks.               --
-----------------------------------------------------------------


animation = {name = 'Animation'}
	local img  = love.graphics.newImage("explosion.png")
	anim = newAnimation(img, 96, 96, 0.1)
	
	anim = newAnimation(img, 96, 96, 0.1)
	anim:setMode("loop")
	anim:play()
animation.load =  function()


end

animation.update = function (dt)
	anim:update(dt)
end

animation.run = function()
	if u > 100 then v = -1 end
	if u < 10 then v = 1 end
	if o > 10000 then w = -1 end
	if o < 1 then w = 1 end
	u = u + v
	o = o + w
	for i=1,64,.8 do
		for j=1,48,.8 do
			red = (i*j/37.5) + 64
			blue = 192 - (i*j/37.5)
			love.graphics.setColor(red, 64, blue)
			anim:draw(i*10, j*10, (i*j)+(o/100), u/40, u/30)
			objects = objects + 1
		end
	end
end
