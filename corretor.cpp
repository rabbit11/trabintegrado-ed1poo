#include "corretor.h"

Corretor::Corretor(){
//o que colocar aqui?
}

Corretor::~Corretor(){
// o que colocar aqui?
}

//-----------------------chamadas de funçao da classe texto---------------------------------------

//chama a funçao alterarPalavra da classe Texto mantendo assim um bom encapsulamento

//chama a funçao salvarTexto da classe Texto mantendo assim um bom encapsulamento
void Corretor::salvarTexto(){
    text.carregarTexto();
}

//-----------------------chamadas de funçao da classe dicionario-----------------------------------

//chama a funçao inserir Palavra da classe dicionario mantendo assim um bom encapsulamento
void Corretor::inserirPalavraDic(Palavra& p){
    dic.inserirPalavra(p);
}

void Corretor::percorrerTexto(){
    list<Palavra> :: iterator it = text.getPrimeiro();
    while(!ultimo(it)){
        if(!dic.consulta(text.getPalavra(it))){
            cout << text.getPalavra(it) << ": Nao consta no dicionario, inserir? y/n" << endl;
            char sn;
            cin >> sn;
            if(sn == 'y')
                dic.inserirPalavra(text.getPalavra(it));
        }
        it.getProx();
    }
}

bool Corretor::textoVazio(){

}
