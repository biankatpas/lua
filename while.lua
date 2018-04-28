#!/usr/bin/lua

local vPar = 0 -- Declara-se uma variavel local de nome "vPar"

print("Numeros pares de 0 a 100") -- Mostra o texto na tela

while (vPar <= 100) do -- Enquanto vPar for menor ou igual a 100
    if (vPar % 2 == 0) then -- Se o resto da divisão de vPar por 2 for igual a 0 significa que o valor é um numero par
        print(vPar) -- Mostra o numero par na tela
    end -- fecha o comando "if"
    vPar = vPar + 1 -- vPar recebe +1
end -- fecha o comando "while"
