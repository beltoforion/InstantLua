-----------------------------------------------------------------
-- The code below is the benchmarked code.                     --
-- This can be modified for your own benchmarks.               --
-----------------------------------------------------------------

image = {name='Image'}

	green_ball = love.graphics.newImage("green_ball.png")
	big_love_ball = love.graphics.newImage("big_love_ball.png")

	
	function image.update() end
	function image.load() end
	
function image.run()
	if u > 100 then v = -1 end
	if u < 10 then v = 1 end
	if o > 10000 then w = -1 end
	if o < 1 then w = 1 end
	u = u + v
	o = o + w
	for i=1,64,1 do
		for j=1,48,1.5 do
			red = (i*j/37.5) + 64
			blue = 192 - (i*j/37.5)
			love.graphics.setColor(red, 64, blue)
			love.graphics.draw(green_ball, i*10, j*10, (i*j)+(o/100), u/40, u/30)
			love.graphics.draw(big_love_ball, j*10, i*10, (i*j)+(o/100), u/40, u/30)
			objects = objects + 2
		end
	end
end
