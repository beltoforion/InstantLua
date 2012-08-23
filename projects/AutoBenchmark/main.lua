-----------------------------------------------------------------
-- The folloing code should not be modified for the benchmarks --
-----------------------------------------------------------------

	results = {}
	global = {}

	require("AnAL")	
	require("tablePersistence")	
	require('animation')
	require('empty')
	require('image')
	require('primitive')
	require('mandelbrot')
	require('text')
	
	tests = {
		text,
		animation,
		empty,
		image,
		primitive,
		mandelbrot,
	}
	
	needLoad = true
	globalNum = 1
	doOnce = true
	
function myprint(txt, x, y, r, g, b, bgr, bgg, bgb, r)
	if not r then r = 1 end
	local cc = (r * 1) + 1
	local x = x - cc
	local y = y - cc
	local cor, cog, cob, coa = love.graphics.getColor()
	love.graphics.setColor(bgr, bgg, bgb, 255)
	for i=1,(r*2)+1 do
		for j=1,(r*2)+1 do
			if i == cc and j == cc then break end
			love.graphics.print(fpstxt, x+i, y+j)
		end
	end
	love.graphics.setColor(r, g, b, 255)
	love.graphics.print(fpstxt, x+cc, y+cc)
	love.graphics.setColor(cor, cog, cob, coa)
end

function resetBenchmark()
	global.maxframes = 500 -- Sets the maximum amount of frames we render for the test.
	tests[globalNum].load()

	u = 10
	v = 1
	o = 1
	w = 1
	cc = 0
	ccc = 0

	lasttime = love.timer.getMicroTime()
	starttime = lasttime
	xtrafps = ""
	objects = 0
	ended = false
	needLoad = false
end

resetBenchmark()

function love.draw()
	if not ended then
		cc = cc + 1
		ccc = ccc + 1
			tests[globalNum].run()
		if ccc > 50 then
			curtime = love.timer.getMicroTime()
			xtrafps = "\nFrame: " .. cc .. " of " .. global.maxframes .. "\nObjects: "..objects.."\nFPS:" .. string.format("%.2f", (ccc / (curtime - lasttime))) .. "\n"
			lasttime = curtime
			ccc = 0
		end
		if cc >= global.maxframes then
			ended = true
			curtime = love.timer.getMicroTime()
		end
		fpstxt = "Test: "..tests[globalNum].name.."\
FPS: " .. love.timer.getFPS() .. xtrafps
		myprint(fpstxt, 10, 10, 192, 192, 255, 0, 0, 0, 2)
	else
		if not (results[globalNum]) then
			results[globalNum] = {
				name = tests[globalNum].name,
				FPS = love.timer.getFPS(),
				extraDetails = xtrafps,
				totalFrames = cc,
				numObjects = objects,
				objectsPerSecond = string.format("%.2f", (objects / (curtime - starttime))),
				averageFPS = string.format("%.2f", (cc / (curtime - starttime))),
			}
		end
		if globalNum < #tests then
			globalNum  = globalNum +1
			resetBenchmark()
		else
			love.graphics.print(tostring('All Tests Finished: Your results have been saved to your appdata folder under `Benchmarker`'), 50,50)
			if doOnce then
				results['Readable'] = saveResults()
			else
				love.graphics.print(tostring(results['Readable']), 50,75)
			end
		end
		
	
	end
end

function saveResults()
	resultsReadable = "\
----------------------------------------------------------\
            ------"..os.date().. "------ \
---------------------------------------------------------- \ " 
		
	for k,v in pairs(results) do
		resultsReadable = resultsReadable.."\
"..v.name .."\
    FPS: ".. v.FPS .."\
    OPS:".. v.numObjects
	end
	if love.filesystem.exists('resultsReadable.txt') then
		resultsReadable = resultsReadable..love.filesystem.read('resultsReadable.txt')
	end
	love.filesystem.write("Results.raw", table.save(results))
	love.filesystem.write("resultsReadable.txt", resultsReadable)
	doOnce = false
	return resultsReadable
end

function love.update(dt)	
	tests[globalNum].update(dt)
end








