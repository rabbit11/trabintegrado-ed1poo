#include "corretor.h"
#include <string>

using namespace std;

//Itera pela lista de palavras do texto comparando-as com o Dicionario
//e adicionando a lista de erros caso nao encontre
void Corretor::verificarTexto(){
    list<Palavra> :: iterator temp;
    temp = text.getPrimeiro();
    while(!text.ultimo(temp)){
        if(!dic.consulta(text.getPalavra(temp))){
            erros.push_back(text.getPalavra(temp));
        }
        advance(temp, 1);
    }
    it = erros.begin();
}

//Retorna true caso a lista de erros esteja vazia
bool Corretor::getErros(){
    return (!erros.empty());
}

//Percorre a lista de erros com iterador e a imprime
void Corretor::exibeErros(){
    list<Palavra> :: iterator temp;
    for(temp = erros.begin(); temp != erros.end(); temp++){
        cout << *temp << endl;
    }
}

//Envia a palavra nova e a palavra a ser substituida
void Corretor::corrigirPalavra(string a, Palavra b){
    Palavra nova(a);
    text.alterarPalavra(b, nova);
}

//Retorna o ponteiro do iterador que corresponde a uma Palavra
Palavra Corretor::erroAtual(){
    return *it;
}

//Envia uma palavra pra ser adicionada ao dicionario
void Corretor::adicionarEx(Palavra a){
    dic.inserirPalavra(a);
}

//Retrona true caso chegue ao fim da lista de erros
bool Corretor::errosFim(){
    if(it == erros.end())
        return true;
    else
        return false;
}

//Avanca o iterador um elemento na lista de erros
void Corretor::errosProx(){
    advance(it, 1);
}

//Recebe o nome do arquivo a ser salvo e envia para o texto
void Corretor::salvarTexto(const string &n){
    text.setSave(n);
    text.salvarTexto();
}

//Envia palavra para o dicionario encontrar sugestoes e as exibe
void Corretor::mostrarSemelhantes(Palavra a){
    dic.buscaSemelhantes(a);
    dic.printSemelhantes();
}

//Recebe a palavra errada e o numero da sugestao escolhida
void Corretor::corrigirSemelhante(Palavra errada, int i){
    text.alterarPalavra(errada, dic.getPalavra(i));
    dic.resetSemelhantes();
}

//Imprime a palavra anterior e posterior ao erro
void Corretor::mostrarContexto(Palavra a){
    text.contexto(it);
}

//Recebe nome do arquivo e o carrega
void Corretor::carregarTexto(const string &s) {
    text.setLoad(s);
    text.carregarTexto();
}
