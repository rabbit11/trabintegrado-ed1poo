#include <iostream>
#include <string>

#include "palavra.h"
//****************
//*METODOS PUBLIC*
//****************

//Sobrecarga do operador ==
bool Palavra::operator== (Palavra &op2){

	if(op2.word == word)
		return true;
	return false;
}

//Invoca função compare da biblioteca string
int Palavra::compara(Palavra &plv2){
	return word.compare(plv2.getWord());
}

//Retorna o atributo string word
string Palavra::getWord(){
	return word;
}

//Altera o valor do atributo string word
void Palavra::setWord(string &p){
	word = p;
}

void Palavra::incrementarOcorrencia(){
	ocorrencias++;
}
