---  - Lay out each keyboard in rows of sub-arrays. Each sub-array
--    represents one key.
--
--   - Each sub-array consists of four slots described as follows:
--      example: ["a", "A", "\u00e1", "\u00c1"]
--
--         a) Normal character
--         A) Character + Shift/Caps
--      \u00e1) Character + Alt/AltGr/AltLk
--      \u00c1) Character + Shift/Caps + Alt/AltGr/AltLk
--
--    You may include sub-arrays which are fewer than four slots.
--    In these cases, the missing slots will be blanked when the
--    corresponding modifier key (Shift or AltGr) is pressed.
--
--   - If the second slot of a sub-array matches one of the following
--    strings:
--      "Tab", "Caps", "Shift", "Enter", "Bksp",
--      "Alt" OR "AltGr", "AltLk"
--    then the function of the key will be the following,
--    respectively:
--      - Insert a tab
--      - Toggle Caps Lock (technically a Shift Lock)
--      - Next entered character will be the shifted character
--      - Insert a newline (textarea), or does nothing
--      - Delete the previous character
--      - Next entered character will be the alternate character
--      - Toggle Alt/AltGr Lock
--
--    The first slot of this sub-array will be the text to display
--    on the corresponding key. This allows for easy localisation
--    of key names.
--
--   - Layout dead keys (diacritic + letter) should be added as
--    property/value pairs of objects with hash keys equal to the
--    diacritic.  See the "this.VKI_deadkey" object below the layout
--    definitions.  In each property/value pair, the value is what
--    the diacritic would change the property name to.
--
--   - Note that any characters beyond the normal ASCII set should be
--    entered in escaped Unicode format.  (eg \u00a3 = Pound symbol)
--    You can find Unicode values for characters here:
--    http://unicode.org/charts/
--
--   - To remove a keyboard, just delete it, or comment it out of the
--    source code. If you decide to remove the US International
--    keyboard layout, make sure you change the default layout
--    (this.VKI_kt) above so it references an existing layout.

function AssignKeyboards(keyLayout)
  keyLayout['math'] = {
    ['name']= "Math", ['keys']= {
      {{"\\", "|"}, {"1", "!", "~"}, {"2", "", "\u02C7"}, {"3", "", "^"}, {"4", "", "\u02D8"}, {"5", "%", "\u00B0"}, {"6", "^", "\u02DB"}, {"7", "", "`"}, {"8", "*", "\u02D9"}, {"9", "(", "\u00B4"}, {"0", ")", "\u02DD"}, {"-", "", "\u00A8"}, {"=", "+", "\u00B8"}, {"Bksp", "Bksp"}},
      {{"", ""}, {"q", "Q"}, {"w", "W"}, {"e", "E"}, {"r", "R"}, {"t", "T"}, {"y", "Y"}, {"u", "U"}, {"i", "I"}, {"o", "O"}, {"p", "P"}, {"[", "{"}, {"]", "}"}, {"", ""}},
      {{"Caps", "Caps"}, {"a", "A"}, {"s", "S"}, {"d", "D"}, {"f", "F"}, {"g", "G"}, {"h", "H"}, {"j", "J"}, {"k", "K"}, {"l", "L"}, {"", ""}, {"", ""}, {"Enter", "Enter"}},
      {{"Shift", "Shift"}, {"z", "Z"}, {"x", "X"}, {"c", "C"}, {"v", "V"}, {"b", "B"}, {"n", "N"}, {"m", "M"}, {"", ""}, {".", ""}, {"/", ""}, {"Shift", "Shift"}},
      {{" ", " "}}
    }, ['lang']= {"mat"} };

  keyLayout['math2'] = {
    ['name']= "Math2", ['keys']= {
      {{"+", ""}, {"-", ""}, {"*", ""}, {"/", ""}},
      {{"sin", "csc"}, {"cos", "sec"}, {"tan", "cot"}, {"asin", "acsc"}, {"acos", "asec"}, {"atan", "acot"}}, 
      {{"Caps", "Caps"}, {"1", ""}, {"2", ""}, {"3", ""}, {"4", ""}, {"5", ""}, {"6", ""}, {"7", ""}, {"8", ""}, {"9", ""}, {"0", ""}, {"Enter", "Enter"}},
      {{"Bksp", "Bksp"}, {"a", "A"}, {"b", "B"}, {"c", "C"}, {"d", "D"}, {"e", "E"}, {"f", "F"}, {"g", "G"}, {"h", "H"}, {"i", "I"}, {"j", "J"}, {"Bksp", "Bksp"}},
      {{"", ""}, {"k", "K"}, {"l", "L"}, {"m", "M"}, {"n", "N"}, {"o", "O"}, {"p", "P"}, {"q", "Q"}, {"r", "R"}, {"s", "S"}, {"t", "T"}, {"", ""}},
      {{"Shift", "Shift"}, {"u", "U"}, {"v", "V"}, {"w", "W"}, {"x", "X"}, {"y", "Y"}, {"z", "Z"}, {"Shift", "Shift"}},
      {{" ", " "}}
    }, ['lang']= {"mat2"} };

  keyLayout['us-int'] = {
    ['name']= "US International", ['keys']= {
      {{"`", "~"}, {"1", "!", "\u00a1", "\u00b9"}, {"2", "@", "\u00b2"}, {"3", "#", "\u00b3"}, {"4", "$", "\u00a4", "\u00a3"}, {"5", "%", "\u20ac"}, {"6", "^", "\u00bc"}, {"7", "&", "\u00bd"}, {"8", "*", "\u00be"}, {"9", "(", "\u2018"}, {"0", ")", "\u2019"}, {"-", "_", "\u00a5"}, {"=", "+", "\u00d7", "\u00f7"}, {"Bksp", "Bksp"}},
      {{"Tab", "Tab"}, {"q", "Q", "\u00e4", "\u00c4"}, {"w", "W", "\u00e5", "\u00c5"}, {"e", "E", "\u00e9", "\u00c9"}, {"r", "R", "\u00ae"}, {"t", "T", "\u00fe", "\u00de"}, {"y", "Y", "\u00fc", "\u00dc"}, {"u", "U", "\u00fa", "\u00da"}, {"i", "I", "\u00ed", "\u00cd"}, {"o", "O", "\u00f3", "\u00d3"}, {"p", "P", "\u00f6", "\u00d6"}, {"[", "{", "\u00ab"}, {"]", "}", "\u00bb"}, {"\\", "|", "\u00ac", "\u00a6"}},
      {{"Caps", "Caps"}, {"a", "A", "\u00e1", "\u00c1"}, {"s", "S", "\u00df", "\u00a7"}, {"d", "D", "\u00f0", "\u00d0"}, {"f", "F"}, {"g", "G"}, {"h", "H"}, {"j", "J"}, {"k", "K"}, {"l", "L", "\u00f8", "\u00d8"}, {";", ":", "\u00b6", "\u00b0"}, {"'", '"', "\u00b4", "\u00a8"}, {"Enter", "Enter"}},
      {{"Shift", "Shift"}, {"z", "Z", "\u00e6", "\u00c6"}, {"x", "X"}, {"c", "C", "\u00a9", "\u00a2"}, {"v", "V"}, {"b", "B"}, {"n", "N", "\u00f1", "\u00d1"}, {"m", "M", "\u00b5"}, {",", "<", "\u00e7", "\u00c7"}, {".", ">"}, {"/", "?", "\u00bf"}, {"Shift", "Shift"}},
      {{" ", " ", " ", " "}, {"Alt", "Alt"}}
    }, ['lang']= {"en"} };

  keyLayout['us-std'] = {
    ['name']= "US Standard", ['keys']= {
      {{"`", "~"}, {"1", "!"}, {"2", "@"}, {"3", "#"}, {"4", "$"}, {"5", "%"}, {"6", "^"}, {"7", "&"}, {"8", "*"}, {"9", "("}, {"0", ")"}, {"-", "_"}, {"=", "+"}, {"Bksp", "Bksp"}},
      {{"Tab", "Tab"}, {"q", "Q"}, {"w", "W"}, {"e", "E"}, {"r", "R"}, {"t", "T"}, {"y", "Y"}, {"u", "U"}, {"i", "I"}, {"o", "O"}, {"p", "P"}, {"[", "{"}, {"]", "}"}, {"\\", "|"}},
      {{"Caps", "Caps"}, {"a", "A"}, {"s", "S"}, {"d", "D"}, {"f", "F"}, {"g", "G"}, {"h", "H"}, {"j", "J"}, {"k", "K"}, {"l", "L"}, {";", ":"}, {"'", '"'}, {"Enter", "Enter"}},
      {{"Shift", "Shift"}, {"z", "Z"}, {"x", "X"}, {"c", "C"}, {"v", "V"}, {"b", "B"}, {"n", "N"}, {"m", "M"}, {",", "<"}, {".", ">"}, {"/", "?"}, {"Shift", "Shift"}},
      {{" ", " "}}
    }, ['lang']= {"en-us"} };
  ConvertKeyboardToUTF8(keyLayout)
end

function ConvertKeyboardToUTF8(keyLayout)
  local keyboard, rowKey, keyDef

  for name,layout in pairs(keyLayout) do
    layout.name = JSUCS2StringReplace(layout.name)

    keyboard = layout.keys
    for rows=1,#keyboard do
      rowKeys = keyboard[rows]
      for keySlot=1,#rowKeys do
        keyDef = rowKeys[keySlot]
        for k=1,#keyDef do
          keyDef[k] = JSUCS2StringDecode(keyDef[k])
        end
      end
    end
  end
end

--- Lay out each dead key set as an object of property/value
--    pairs.  The rows below are wrapped so uppercase letters are
--    below their lowercase equivalents.
--
--   - The property name is the letter pressed after the diacritic.
--   - The property value is the letter this key-combo will generate.
--
--   - Note that if you have created a new keyboard layout and want
--    it included in the distributed script, PLEASE TELL ME if you
--    have added additional dead keys to the ones below.
function AssignDeadKeys(deadkeyTable)
  deadkeyTable['"'] =   { --// Umlaut / Diaeresis / Greek Dialytika / Hiragana/Katakana Voiced Sound Mark
    ['a']= "\u00e4", ['e']= "\u00eb", ['i']= "\u00ef", ['o']= "\u00f6", ['u']= "\u00fc", ['y']= "\u00ff", ['\u03b9']= "\u03ca", ['\u03c5']= "\u03cb", ['\u016B']= "\u01D6", ['\u00FA']= "\u01D8", ['\u01D4']= "\u01DA", ['\u00F9']= "\u01DC",
    ['A']= "\u00c4", ['E']= "\u00cb", ['I']= "\u00cf", ['O']= "\u00d6", ['U']= "\u00dc", ['Y']= "\u0178", ['\u0399']= "\u03aa", ['\u03a5']= "\u03ab", ['\u016A']= "\u01D5", ['\u00DA']= "\u01D7", ['\u01D3']= "\u01D9", ['\u00D9']= "\u01DB",
    ['\u304b']= "\u304c", ['\u304d']= "\u304e", ['\u304f']= "\u3050", ['\u3051']= "\u3052", ['\u3053']= "\u3054", ['\u305f']= "\u3060", ['\u3061']= "\u3062", ['\u3064']= "\u3065", ['\u3066']= "\u3067", ['\u3068']= "\u3069",
    ['\u3055']= "\u3056", ['\u3057']= "\u3058", ['\u3059']= "\u305a", ['\u305b']= "\u305c", ['\u305d']= "\u305e", ['\u306f']= "\u3070", ['\u3072']= "\u3073", ['\u3075']= "\u3076", ['\u3078']= "\u3079", ['\u307b']= "\u307c",
    ['\u30ab']= "\u30ac", ['\u30ad']= "\u30ae", ['\u30af']= "\u30b0", ['\u30b1']= "\u30b2", ['\u30b3']= "\u30b4", ['\u30bf']= "\u30c0", ['\u30c1']= "\u30c2", ['\u30c4']= "\u30c5", ['\u30c6']= "\u30c7", ['\u30c8']= "\u30c9",
    ['\u30b5']= "\u30b6", ['\u30b7']= "\u30b8", ['\u30b9']= "\u30ba", ['\u30bb']= "\u30bc", ['\u30bd']= "\u30be", ['\u30cf']= "\u30d0", ['\u30d2']= "\u30d3", ['\u30d5']= "\u30d6", ['\u30d8']= "\u30d9", ['\u30db']= "\u30dc"
  };
  deadkeyTable['\u00a8'] = deadkeyTable['"']
  deadkeyTable['\u309B'] = deadkeyTable['"']

  deadkeyTable['~'] = {  --// Tilde / Stroke
    ['a']= "\u00e3", ['l']= "\u0142", ['n']= "\u00f1", ['o']= "\u00f5",
    ['A']= "\u00c3", ['L']= "\u0141", ['N']= "\u00d1", ['O']= "\u00d5"
  };
  deadkeyTable['^'] = {  --// Circumflex
    ['a']= "\u00e2", ['e']= "\u00ea", ['i']= "\u00ee", ['o']= "\u00f4", ['u']= "\u00fb", ['w']= "\u0175", ['y']= "\u0177",
    ['A']= "\u00c2", ['E']= "\u00ca", ['I']= "\u00ce", ['O']= "\u00d4", ['U']= "\u00db", ['W']= "\u0174", ['Y']= "\u0176"
  };
  deadkeyTable['\u02c7'] = { --// Baltic caron
    ['c']= "\u010D", ['d']= "\u010f", ['e']= "\u011b", ['s']= "\u0161", ['l']= "\u013e", ['n']= "\u0148", ['r']= "\u0159", ['t']= "\u0165", ['u']= "\u01d4", ['z']= "\u017E", ['\u00fc']= "\u01da",
    ['C']= "\u010C", ['D']= "\u010e", ['E']= "\u011a", ['S']= "\u0160", ['L']= "\u013d", ['N']= "\u0147", ['R']= "\u0158", ['T']= "\u0164", ['U']= "\u01d3", ['Z']= "\u017D", ['\u00dc']= "\u01d9"
  };
  deadkeyTable['\u02d8'] = { --// Romanian and Turkish breve
    ['a']= "\u0103", ['g']= "\u011f",
    ['A']= "\u0102", ['G']= "\u011e"
  };
  deadkeyTable['-'] = { --// Macron
    ['a']= "\u0101", ['e']= "\u0113", ['i']= "\u012b", ['o']= "\u014d", ['u']= "\u016B", ['y']= "\u0233", ['\u00fc']= "\u01d6", ['\u00e6']= "\u01e3",
    ['A']= "\u0100", ['E']= "\u0112", ['I']= "\u012a", ['O']= "\u014c", ['U']= "\u016A", ['Y']= "\u0232", ['\u00dc']= "\u01d5", ['\u00c6']= "\u01e2"
  };
  deadkeyTable['-'] = deadkeyTable['\u00af']

  deadkeyTable['`'] = { --// Grave
    ['a']= "\u00e0", ['e']= "\u00e8", ['i']= "\u00ec", ['o']= "\u00f2", ['u']= "\u00f9", ['\u00fc']= "\u01dc",
    ['A']= "\u00c0", ['E']= "\u00c8", ['I']= "\u00cc", ['O']= "\u00d2", ['U']= "\u00d9", ['\u00dc']= "\u01db"
  };
  deadkeyTable["'"] =  { --// Acute / Greek Tonos
    ['a']= "\u00e1", ['e']= "\u00e9", ['i']= "\u00ed", ['o']= "\u00f3", ['u']= "\u00fa", ['y']= "\u00fd", ['\u03b1']= "\u03ac", ['\u03b5']= "\u03ad", ['\u03b7']= "\u03ae", ['\u03b9']= "\u03af", ['\u03bf']= "\u03cc", ['\u03c5']= "\u03cd", ['\u03c9']= "\u03ce", ['\u00fc']= "\u01d8",
    ['A']= "\u00c1", ['E']= "\u00c9", ['I']= "\u00cd", ['O']= "\u00d3", ['U']= "\u00da", ['Y']= "\u00dd", ['\u0391']= "\u0386", ['\u0395']= "\u0388", ['\u0397']= "\u0389", ['\u0399']= "\u038a", ['\u039f']= "\u038c", ['\u03a5']= "\u038e", ['\u03a9']= "\u038f", ['\u00dc']= "\u01d7"
  };
  deadkeyTable['\u00b4'] = deadkeyTable["'"]
  deadkeyTable['\u0384'] = deadkeyTable["'"]

  deadkeyTable['\u02dd'] = { --// Hungarian Double Acute Accent
    ['o']= "\u0151", ['u']= "\u0171",
    ['O']= "\u0150", ['U']= "\u0170"
  };
  deadkeyTable['\u0385'] = { --// Greek Dialytika + Tonos
    ['\u03b9']= "\u0390", ['\u03c5']= "\u03b0"
  };
  deadkeyTable['\u00b0'] = { --// Ring
    ['a']= "\u00e5", ['u']= "\u016f",
    ['A']= "\u00c5", ['U']= "\u016e"
  };
  deadkeyTable['\u00ba'] = deadkeyTable['\u00b0']

  deadkeyTable['\u02DB'] = { --// Ogonek
    ['a']= "\u0106", ['e']= "\u0119", ['i']= "\u012f", ['o']= "\u01eb", ['u']= "\u0173", ['y']= "\u0177",
    ['A']= "\u0105", ['E']= "\u0118", ['I']= "\u012e", ['O']= "\u01ea", ['U']= "\u0172", ['Y']= "\u0176"
  };
  deadkeyTable['\u02D9'] = { --// Dot-above
    ['c']= "\u010B", ['e']= "\u0117", ['g']= "\u0121", ['z']= "\u017C",
    ['C']= "\u010A", ['E']= "\u0116", ['G']= "\u0120", ['Z']= "\u017B"
  };
  deadkeyTable['\u00B8'] = { --// Cedilla
    ['c']= "\u00e7", ['s']= "\u015F",
    ['C']= "\u00c7", ['S']= "\u015E"
  };
  deadkeyTable['\u201a'] = deadkeyTable['\u00B8']
  deadkeyTable[','] = { --// Comma
    ['s']= "\u0219", ['t']= "\u021B",
    ['S']= "\u0218", ['T']= "\u021A"
  };
  deadkeyTable['\u3002'] = { --// Hiragana/Katakana Point
    ['\u306f']= "\u3071", ['\u3072']= "\u3074", ['\u3075']= "\u3077", ['\u3078']= "\u307a", ['\u307b']= "\u307d",
    ['\u30cf']= "\u30d1", ['\u30d2']= "\u30d4", ['\u30d5']= "\u30d7", ['\u30d8']= "\u30da", ['\u30db']= "\u30dd"
  };
end


--- Converts a UCS2 (16bit) value to a UTF8 character table for most code points
-- of interest (ignores U+D7FF to U+DFFF or those above U+FFFF)
--
--@param ucs2 The 16bit UCS2 integer value
--@param char_table A table into which the individual decoded characters are inserted
--@return The number of characters inserted
local function UCS2ToUTF8(ucs2, char_table)
  local byte0, byte1, byte2

  if (ucs2 < 0x80) then
    table.insert(char_table, ucs2)
    return 1
  end

  if (ucs2 >= 0x80  and ucs2 < 0x800) then
    --byte0 = (ucs2 >> 6)   | 0xC0;
    byte0 = bit32.bor(bit32.rshift(ucs2, 6), 0xC0)
    --byte1 = (ucs2 & 0x3F) | 0x80;
    byte1 = bit32.bor(bit32.band(ucs2, 0x3F), 0x80)

    table.insert(char_table, byte0)
    table.insert(char_table, byte1)
    return 2;
  end

  if (ucs2 >= 0x800 and ucs2 < 0xFFFF) then
    --byte0 = ((ucs2 >> 12)       ) | 0xE0;
    byte0 = bit32.bor(bit32.rshift(ucs2, 12), 0xE0)
    --byte1 = ((ucs2 >> 6 ) & 0x3F) | 0x80;
    byte1 = bit32.bor(bit32.band(bit32.rshift(ucs2, 6), 0x3F), 0x80)
    --byte2 = ((ucs2      ) & 0x3F) | 0x80;
    byte2 = bit32.bor(bit32.band(ucs2, 0x3F), 0x80)

    table.insert(char_table, byte0)
    table.insert(char_table, byte1)
    table.insert(char_table, byte2)
    return 3;
  end

  return 0;
end

--- This function converts a UTF-8 encoded string into a Lua table with
--- its corresponding unicode codepoints (UTF-32)
--- @param utf8str The Lua string containing UTF8 values
--- @return A table of UCS2 integer codepoints
function UTF8ToUCS2(utf8str)
  local res, seq, val = {}, 0, nil
  for i = 1, #utf8str do
    local c = utf8str:byte(i)
    if seq == 0 then
      table.insert(res, val)
      seq = c < 0x80 and 1 or c < 0xE0 and 2 or c < 0xF0 and 3 or
        c < 0xF8 and 4 or --c < 0xFC and 5 or c < 0xFE and 6 or
        error("invalid UTF-8 character sequence")
      val = bit32.band(c, 2^(8-seq) - 1)
    else
      val = bit32.bor(bit32.lshift(val, 6), bit32.band(c, 0x3F))
    end
    seq = seq - 1
  end
  table.insert(res, val)
  table.insert(res, 0)
  return res
end

-- Convert a UCS2 string to UTF-8.  The UCS2 strings are a bit funky in that
-- they are not really encoded but "\u01D6" which turns into "u01D6" since
-- the \u isn't an escape character in Lua.
function JSUCS2StringDecode(ucs2)
  if(ucs2 == nil) then
    return nil
  end

  --  local ucs2dec = string.match(ucs2,"\\u(%d)+")
  local ucs2hex = string.match(ucs2,"^u(%x%x%x%x)$")
  if(ucs2hex == nil) then
    --print("No match on " .. tostring(ucs2))
    return ucs2
  end

  local utf8Chars = {}
  local cnt = UCS2ToUTF8(tonumber(ucs2hex, 16), utf8Chars)
  local str = string.char(unpack(utf8Chars))

  --print(string.format("UCS2 Number Found %s => %s", ucs2hex, str))

  return str
end

function JSUCS2StringReplace(ucs2String)
  return string.gsub(ucs2String, "(u%x%x%x%x)", JSUCS2StringDecode)
end

--JSUCS2StringReplace("Farsi - \u0641\u0627\u0631\u0633\u06cc")

function UTF8Delete(utf8String)
  local len = #utf8String
  if(len <= 1) then
    return ""
  end

  -- Simple non-encoded character (no top bit set)
  --print(string.format("Delete %x", utf8String:byte(len)))
  if(bit32.band(utf8String:byte(len), 0x80) == 0) then
    return string.sub(utf8String, 1, len-1)
  end

  -- Trim off the 10xxxxxx bits indicating UTF8 encoding
  while(len > 1 and (bit32.band(utf8String:byte(len), 0xc0) == 0x80)) do
    --print(string.format("Ex Delete %x", utf8String:byte(len)))
    len = len - 1
  end

  -- Take one off for the final 11xxxxxx bits
  --print(string.format("Ex Last Delete %x", utf8String:byte(len)))
  len = len - 1

  if(len < 1) then
    return ""
  end

  return string.sub(utf8String, 1, len)
end
