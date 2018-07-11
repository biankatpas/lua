idade = 20 -- Declara a variavel global "idade" e lhe atribui o valor 20

function mostra_idade() -- Cria a função "mostra_idade"
    print(idade) -- Mostra na tela a variavel global "idade"
end -- Finaliza a função "mostra_idade"

mostra_idade(); -- Chama a função "mostra_idade"

local nome = "Herbocinética" -- Declara uma variavel local "nome" e lhe atribui a string "Herbocinética"

function mostra_nome(parametro_nome) -- Cria a função "mostra_nome" recebendo como parametro o nome
    print(parametro_nome) -- Mostra na tela o parametro_nome
end -- Finaliza a função "mostra_nome"

mostra_nome(nome) -- Chama a função "mostra_nome"

local a = 5 -- Declara uma variavel local "a" com valor 5
local b = 6 -- Declara uma variavel local "b" com valor 6

function soma(a,b) -- Cria a função soma que recebe como parametro as variaveis a e b
    return a+b -- Retorna a soma de a + b
end -- Finaliza a função "soma"

local soma = soma(a,b) -- Variavel local soma recebe o retorno da função soma
print(soma) -- Mostra a variavel "soma" na tela

m = function (a,b) return a*b end
--res = m(1,2)
print(m(1,20))
