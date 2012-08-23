function love.conf(t)
  t.modules.joystick = false   -- Enable the joystick module (boolean)
  t.modules.audio = false      -- Enable the audio module (boolean)
  t.modules.keyboard = true   -- Enable the keyboard module (boolean)
  t.modules.event = true      -- Enable the event module (boolean)
  t.modules.image = true      -- Enable the image module (boolean)
  t.modules.graphics = true   -- Enable the graphics module (boolean)
  t.modules.timer = true      -- Enable the timer module (boolean)
  t.modules.mouse = true      -- Enable the mouse module (boolean)
  t.modules.sound = true      -- Enable the sound module (boolean)
  t.modules.physics = true    -- Enable the physics module (boolean)
  t.console = false           -- Attach a console (boolean, Windows only)
  t.title = "Auto Benchmarker v0.9"        -- The title of the window the game is in (string)
  t.author = "Mark Sanders - Modefied by Shane Gadsby (schme16)"        -- The author of the game (string)
  t.screen.fullscreen = false -- Enable fullscreen (boolean)
  t.screen.vsync = false       -- Enable vertical sync (boolean)
  t.screen.fsaa = 0           -- The number of FSAA-buffers (number)
  t.screen.width = 640        -- The window width (number)
  t.screen.height = 480       -- The window height (number)
  t.version = 0               -- The L?VE version this game was made for (number)
end
