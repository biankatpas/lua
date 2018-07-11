-- função sem argumento
function minha_funcao_1()
    mensagem("Minha funcao 1 chamada\n")
end
 
-- função com 1 argumento
function minha_funcao_2(x)
    mensagem("Minha funcao 2 chamada com: ")
    mensagem(x)
    mensagem("\n")
end
 
-- função com 1 argumento e um retorno
function minha_funcao_3(x)
    mensagem("Minha funcao 3 chamada com: ")
    mensagem(x)
    mensagem(" vou retornar x*3");
    mensagem("\n")
    return (x * 3)
end
 
nome = meunome()
mensagem("Ola Mundo, Ola ");
mensagem(nome)
mensagem("\n")