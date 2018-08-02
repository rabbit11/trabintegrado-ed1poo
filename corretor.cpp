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

//chama a funçao consulta da classe dicionario mantendo assim um bom encapsulamento
bool Corretor::consultaDic(Palavra& p){

    dic.consulta(p);
}

//chama a funçao inserir Palavra da classe dicionario mantendo assim um bom encapsulamento
void Corretor::inserirPalavraDic(Palavra& p){
    dic.inserirPalavra(p);
}
