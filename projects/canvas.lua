-- Transforms a given position p according to the transformation matrix m
function transform(m, p)
	local rnd = math.random()
	local i   = 1
	local pc  = m[1].p
 
	while pc<rnd do
    i  = i+1
		pc = pc + m[i].p
	end
   
	return { m[i].a * p[1] + m[i].b * p[2] + m[i].e,
	         m[i].c * p[1] + m[i].d * p[2] + m[i].f }
end

-- Iterate over the functions
function iterate(cv, m, n)
	local p = { math.random(), math.random() }

	for i=1,n do
		cv:drawPoint(1000*p[1], 1000*p[2])
		p = transform(m, p)	
	end
end

-- Initialize the function system
function execute()
	local cv = Canvas(1000, 1000, "Iteriertes Funktionssystem")
	math.randomseed(os.time())

	-- Sierpinsky triangle
	local m1 = { { a=0.5, b=0.0, c=0.0, d=0.5, e=0.0,  f=0.0, p=1/3 },
							 { a=0.5, b=0.0, c=0.0, d=0.5, e=0.25, f=0.5, p=1/3 },
					     { a=0.5, b=0.0, c=0.0, d=0.5, e=0.50, f=0.0, p=1/3 } }

  -- Barnslay fern
	local m2 = { { a= 0.00, b= 0.00, c= 0.00, d=0.16, e=0.0, f=0.00, p=0.01 },
							 { a= 0.85, b= 0.04, c=-0.04, d=0.85, e=0.0, f=1.60, p=0.85 },
						   { a= 0.20, b=-0.26, c= 0.23, d=0.22, e=0.0, f=1.60, p=0.07 },
							 { a=-0.15, b= 0.28, c= 0.26, d=0.24, e=0.0, f=0.44, p=0.07 } }

	-- 
	local m3 = { { a=0.0000, b= 0.2439, c= 0.0000, d= 0.3053, e=0.0000, f=0.0000, p=0.25 },
							 { a=0.7248, b= 0.0337, c=-0.0253, d= 0.7426, e=0.2060, f=0.2538, p=0.25 },
						   { a=0.1583, b=-0.1297, c= 0.3550, d= 0.3676, e=0.1383, f=0.1750, p=0.25 },
							 { a=0.3386, b= 0.3694, c= 0.2227, d=-0.0756, e=0.0679, f=0.0826, p=0.25 } }

	local m4 = { { a=0.50, b=-0.50, c= 0.00, d= 0.50, e=2.00, f=2.00, p=0.25 },
							 { a=0.50, b= 0.00, c=-0.00, d= 0.70, e=2.00, f=2.00, p=0.25 },
						   { a=0.25, b= 0.35, c= 0.35, d= 0.25, e=0.00, f=0.00, p=0.25 },
							 { a=0.00, b= 0.80, c= 0.80, d= 0.00, e=0.00, f=0.00, p=0.25 } }

	-- Twindragon
	local m6 = { { a=-0.5, b=0.5, c=-0.5, d=-0.5, e= 0.0, f= 0.0, p=0.5 },
							 { a=-0.5, b=0.5, c=-0.5, d=-0.5, e=-1.0, f=-1.0, p=0.5 } }

	iterate(cv, m1, 40000)
end

execute()
