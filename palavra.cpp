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
string Palavra::getWord() const {
	return word;
}

//Altera o valor do atributo string word
void Palavra::setWord(const string &p){
	word = p;
}

//Incrementa o campo ocorrencia da classe palavra
void Palavra::incrementarOcorrencia(){
	ocorrencias++;
}

//Retorna o número de ocorrencias de determinada palavra
int Palavra::getOcorrencias() const {
	return ocorrencias;
}

//Sobrecarga do operador <<
ostream& operator<<(ostream& os, const Palavra& a)
{
    os << a.word;
    return os;
}
