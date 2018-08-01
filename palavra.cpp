#include <iostream>
#include <string>

#include "Palavra.h"

bool Palavra::operator== (Palavra &op2) {
	
	if(op2.word == word)
		return true;
	return false;
}