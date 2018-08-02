#include "corretor.h"

corretor::corretor(){
//o que colocar aqui?
}

corretor::~corretor(){
// o que colocar aqui?
}

//-----------------------chamadas de funçao da classe texto---------------------------------------

//chama a funçao alterarPalavra da classe Texto mantendo assim um bom encapsulamento
void corretor::alterarPalavraTexto(int indice){
    text.alterarPalavra(indice);
}

//chama a funçao carregarTexto da classe Texto mantendo assim um bom encapsulamento
void corretor::carregarTexto(){
    text.carregarTexto();
}

//chama a funçao salvarTexto da classe Texto mantendo assim um bom encapsulamento
void corretor::salvarTexto(){
    text.carregarTexto();
}

//-----------------------chamadas de funçao da classe dicionario-----------------------------------

//chama a funçao consulta da classe dicionario mantendo assim um bom encapsulamento
bool corretor::consultaDic(palavra& p){
    
    dic.consulta(p);
}

//chama a funçao inserir palavra da classe dicionario mantendo assim um bom encapsulamento
void corretor::inserirPalavraDic(palavra& p){
    dic.inserirPalavra(p);
}
