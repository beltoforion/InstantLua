-----------------------------------------------------------------
-- The code below is the benchmarked code.                     --
-- This can be modified for your own benchmarks.               --
-----------------------------------------------------------------
primitive = {name = 'Primitive'}
	
function primitive.update() end
function primitive.load() end

function primitive.run()
	if u > 10 then v = -.1 end
	if u < 1 then v = .1 end
	if o > 10000 then w = -1 end
	if o < 1 then w = 1 end
	u = u + v
	o = o + w
	for i=1,64,1.4 do
		for j=1,48,1.5 do
			red = (i*j/37.5) + 64
			blue = 192 - (i*j/37.5)
			love.graphics.setColor(red, 64, blue)
			love.graphics.rectangle( "line", i*10, j*10, i*10+(32-i)+u, j*10+(24-i)+u)
			love.graphics.setColor(64, red, blue)
			love.graphics.line(i*10, j*10, i*10+(32-i)+u, j*10+(24-i)+u)
			love.graphics.setColor(blue, red, 64)
			love.graphics.point(i*10, j*10)
			love.graphics.point(i*10+(32-i)+u, j*10+(24-i)+u)
			love.graphics.setColor(blue+64, red+64, 128)
			love.graphics.triangle( "line", i*10, j*10, i*10+(32-i)+u, j*10+(24-i)+u, i*10-(32-i)+u, j*10-(24-i)+u )
			objects = objects + 5
		end
	end
end
