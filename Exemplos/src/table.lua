t = {}    -- construct an empty table and assign it to variable "t"
print(t)

t["id"] = 123 -- assign the value 123 to the key "id" in the table
t[1] = "banana" -- assign the value "bar" to the key 3 in the table
t[2] = "morango"

print(t["id"])
print(t.id) -- string constants as keys there's a special shortcut syntax for it
print(t[1])
print(t[3]) -- If there's no value associated with the key, it's not an error, instead the result will be nil
print(#t) --You can get the "length" of an array using the # operator

-- insert, remove, concat, pairs

