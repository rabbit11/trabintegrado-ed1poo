#include <iostream>
#include <string>

#include "palavra.h"

bool Palavra::operator== (Palavra &op2) {

	if(op2.word == word)
		return true;
	return false;
}

int Palavra::compara(Palavra &plv2){
	return word.compare(plv2.getWord());
}

string Palavra::getWord(){
	return word;
}

void Palavra::setWord(string &p){
	word = p;
}
