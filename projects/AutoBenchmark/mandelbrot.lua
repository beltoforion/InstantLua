-----------------------------------------------------------------
-- The code below is the benchmarked code.                     --
-- This can be modified for your own benchmarks.               --
-----------------------------------------------------------------

mandelbrot = {name = 'Mandelbrot'}
		 -- Sets the maximum amount of frames we render for the test.
function mandelbrot.update() end
function mandelbrot.load() global.maxframes = 5 end

function mandelbrot.run()
	local width = 640
	local height = 480
	local wscale = 2/width
	local m, limit2 = 50, 4.0
	local write, char = io.write, string.char
	local insert = table.insert
	local results={}
--	insert(results, "P4\n" .. width .. " " .. height .. "\n")
	imageData = love.image.newImageData( width, height )
	for y=0,height-1 do
	  local Ci = 2*y / height - 1
	  for xb=0,width-1,1 do
		local bits = 0
		local xbb = xb+7
		for x=xb,xbb < width and xbb or width-1 do
		  bits = bits + bits
		  local Zr, Zi, Zrq, Ziq = 0.0, 0.0, 0.0, 0.0
		  local Cr = x * wscale - 1.5
		  for i=1,m do
			local Zri = Zr*Zi
			Zr = Zrq-Ziq+Cr
			Zi = Zri+Zri+Ci
			Zrq = Zr*Zr
			Ziq = Zi*Zi
			if Zrq + Ziq > limit2 then
				bits = bits + 1
				break
			end
		  end
		end
		if xbb >= width then
			for x=width,xbb do bits = bits + bits + 1 end
		end
		imageData:setPixel( xb, y, 255-bits, bits, 128, 255 )
		objects = objects + 1
--		insert(results,(char(255-bits))..(char(255-bits))..(char(255-bits))..(char(255)))
	  end
	end
--	imageFile = love.filesystem.newFileData(table.concat(results), "bla.bmp")
--	imageData = love.image.newImageData(table.concat(results))
	love.graphics.draw( love.graphics.newImage(imageData), 0, 0, 0, 1, 1, 0, 0 )
end
