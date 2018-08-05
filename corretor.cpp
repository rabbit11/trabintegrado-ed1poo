#include "corretor.h"
#include <string>

using namespace std;

Corretor::~Corretor(){
// o que colocar aqui?
}

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

bool Corretor::getErros(){
    return (!erros.empty());
}

void Corretor::exibeErros(){
    list<Palavra> :: iterator temp;
    for(temp = erros.begin(); temp != erros.end(); temp++){
        cout << *temp << endl;
    }
}

void Corretor::corrigirPalavra(string a, Palavra b){
    Palavra nova(a);
    text.alterarPalavra(b, nova);
}

Palavra Corretor::erroAtual(){
    return *it;
}

void Corretor::adicionarEx(Palavra a){
    dic.inserirPalavra(a);
}

bool Corretor::errosFim(){
    if(it == erros.end())
        return true;
    else
        return false;
}

void Corretor::errosProx(){
    advance(it, 1);
}

void Corretor::salvarTexto(){
    text.setSave("saida.txt");
    text.salvarTexto();
}

void Corretor::mostrarSemelhantes(Palavra a){
    dic.buscaSemelhantes(a);
    dic.printSemelhantes();
}

void Corretor::corrigirSemelhante(Palavra errada, int i){
    text.alterarPalavra(errada, dic.getPalavra(i));
    dic.resetSemelhantes();
}

void Corretor::mostrarContexto(Palavra a){
    text.contexto(it);
}
