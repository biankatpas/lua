// LuaExemplo
// Escrito por Marcos Medeiros, 09/2012.
#include <iostream>
#include <lua.hpp>
 
using namespace std;
 
// Essa função vai ser chamada quando Lua encontrar a função
// mensagem no script, o nome aqui não tem relação alguma com
// o nome da função em Lua, isso é definido quando registramos
// essa função.
// A estrutura de TODA função que lua chama é essa:
//    int func(lua_State *L)
// Retornamos como inteiro o número de valores retornados
// na pilha da vm de lua.
int mensagem_callback(lua_State *L)
{
    // Vamos pegar o primeiro argumento da pilha,
    // O último valor colocado na pilha é dado por -1, 0 é o topo
    // -2 é o penúltimo, -3 antepenúltimo e assim por diante...
    // Existem funções de lua (lua_tonumber por exemplo) que convertem o
    // valor da pilha para o tipo real dele, bem essas funções na
    // verdade só fazem o casting do valor na posição indicada na pilha.
    const char *str = lua_tostring(L, -1);
    cout << str;
    return 0;
}
 
int meunome_callback(lua_State *L)
{
    const size_t nome_max = 50;
    static char nome[nome_max];
 
    // Limpa o nome
    for (size_t i = 0; i < nome_max; i++)
        nome[i] = 0;
 
    cout << "Qual o seu nome? ";
    cin.getline(nome, nome_max);
 
    // Coloca na pilha a nossa string que é o retorno da função
    lua_pushstring(L, nome);
    // Devemos retornar a quatidade de valores que a função retorna
    // nesse caso é apenas o ponteiro para o nome
    return 1;
}
 
int main()
{
    lua_State *L = NULL;
 
    // Vamos criar nossa vm
    L = luaL_newstate();
 
    // Vamos registrar nossas funções, ou nossa API
    // para o programa em Lua chamar.
    // O segundo argumento é o nome da função em Lua, e o terceiro
    // a função que a vm deve chamar em C
    lua_register(L, "mensagem", mensagem_callback);
    lua_register(L, "meunome", meunome_callback);
 
    if (luaL_dofile(L, "ola_c.lua") != LUA_OK) {
        lua_close(L);
        cout << "Alguma coisa deu errado =(" << endl;
        return 1;
    }
 
    // Diz a Lua para processar nosso arquivo
    lua_pcall(L, 0, 0, 0);
 
    // Agora vamos chamar uma função diretamente daqui.
    // Para isso precisamos empilhar o nome da função.
    // Mas para pegar o local dessa função, utilizamos lua_getglobal
 
    // Vamos chamar a função sem argumento
    lua_getglobal(L, "minha_funcao_1");
 
    // Aqui o primeiro argumento é a nossa VM,
    // o segundo é o número de argumentos que a função tem,
    //   esses valores são empilhados utilizando lua_pushnumber, lua_pushstring, etc...
    // o terceiro é o número de valores retornados pela função
    // e o quarto o valor de erro...
    lua_pcall(L, 0, 0, 0);
 
    // Vamos chamar a função com 1 argumento
    lua_getglobal(L, "minha_funcao_2");
    // a minha_funcao_2 recebe um inteiro como parametro, então vamos empilhar
    lua_pushnumber(L, 123456789);
    lua_pcall(L, 1, 0, 0);
 
    // Vamos chamar a função com 1 argumento e um valor de retorno
    lua_getglobal(L, "minha_funcao_3");
    // a minha_funcao_3 recebe um inteiro como parametro, então vamos empilhar
    lua_pushnumber(L, 2);
    // aqui temos um parametro e um valor de retorno
    lua_pcall(L, 1, 1, 0);
    int retorno = lua_tonumber(L, -1);
    cout << "A minha_funcao_3 retornou " << retorno << endl;
 
    // Agora destruimos nossa vm
    lua_close(L);
    return 0;
}