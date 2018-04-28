#!/usr/bin/lua

local a = 3
local b = 2
local r = 0
local op = "+"

if op == "+" then
  r = a + b
elseif op == "-" then
  r = a - b
elseif op == "*" then
  r = a*b
elseif op == "/" then
  r = a/b
else
  error("invalid operation")
end

print(r)
