-----------------------------------------------------------------
-- The code below is the benchmarked code.                     --
-- This can be modified for your own benchmarks.               --
-----------------------------------------------------------------
text =  {name = 'Text'}
text.load = function()

end

text.update = function(dt)

end

text.run = function()
	if u > 100 then v = -1 end
	if u < 10 then v = 1 end
	if o > 10000 then w = -1 end
	if o < 1 then w = 1 end
	u = u + v
	o = o + w
	for i=1,64,3 do
		for j=1,48,2.7 do
			red = (i*j/37.5) + 64
			blue = 192 - (i*j/37.5)
			love.graphics.setColor(red, 64, blue)
			love.graphics.print("Hello lövely World!", i*10, j*10, (i*j)+(o/100), u/40, u/30)
			objects = objects + 1
		end
	end
end
