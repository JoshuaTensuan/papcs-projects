local virtualKeyboard
local scaledDown = false

local function SyncKeyboardName()
  local name = virtualKeyboard:CurrentKeyboardName()
--  print("Current keyboard name is " .. tostring(name))
  gre.set_value("content_layer.language.text",name)
end

--- Emulates a keydown/keyup event
--
--@param ucs2Value A UCS2 codepoint value
--@param text The UTF8 text from which the USC2 codepoint was derived.
--@param modifiers The shift modifiers for the keyboard input.
--@param KVI The instance of the keyboard
local function CBKVI_KeyEmulation(code, text, modifiers, virtualKeyboard, channel)
  if(modifiers == nil) then
    modifiers = 0
  end
  
  local active_screen = gre.env("active_screen")
  
  local args = {}
  args["code"] = code
  args["modifiers"] = modifiers
  
  if(code < math.pow(2,16)) then --Less than 2 bytes
    args["key"] = code
  end
  
  if(channel == nil) then
    gre.send_event_data("gre.keydown", "4u1 code 2u1 key 2u1 modifiers", args)
    gre.send_event_data("gre.keyup", "4u1 code 2u1 key 2u1 modifiers", args)
  else
    gre.send_event_data("gre.keydown", "4u1 code 2u1 key 2u1 modifiers", args, channel)
    gre.send_event_data("gre.keyup", "4u1 code 2u1 key 2u1 modifiers", args, channel)
  end
end

function CBVKI_Init(mapargs) 
  virtualKeyboard = VKI.Init("Screen","vk_layer", "key_template", "content_layer.textfield.text", "math2", "fonts/CODE2000-AUTOHINTED.TTF", "content_layer.selector", "content_layer.textfield3.answer", "content_layer.textfield4.prev")
  virtualKeyboard:SetEmulation(CBKVI_KeyEmulation)
  
  SyncKeyboardName()
end

function CBVKI_KeyPress(mapargs)
  virtualKeyboard:Press(mapargs)
end

function CBVKI_KeyRelease(mapargs)
  virtualKeyboard:Release(mapargs)
end

function CBVKI_KeyOutbound(mapargs)
  virtualKeyboard:Outbound(mapargs)
end

function CBVKI_Next(mapargs)
  local current = virtualKeyboard:CurrentKeyboardType()
  local list = virtualKeyboard:KeyboardTypeList()
  for i=1,#list do
--    print(list[i] .. " vs " .. current)
    if(list[i] == current) then
      if(i+1 <= #list) then
        virtualKeyboard:ChangeKeyboardType(list[i+1])
      else  
        virtualKeyboard:ChangeKeyboardType(list[1])
      end
      break
    end
  end
  SyncKeyboardName()
end

function CBVKI_Resize(mapargs)
  virtualKeyboard:UpdateSize() 
end

function CBVKI_SelectLanguage(mapargs)
  local row = mapargs.context_row
  local list = virtualKeyboard:KeyboardTypeList()
  
  virtualKeyboard:ChangeKeyboardType(list[row])
  SyncKeyboardName()
end

function CBScaleDown()
  if(scaledDown == false) then
    scaledDown = true
    gre.animation_trigger("scale_down")
  end
end

function CBScaleUp()
  if(scaledDown == true) then
    scaledDown = false
    gre.animation_trigger("scale_up")
  end
end

