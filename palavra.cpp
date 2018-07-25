#include <iostream>
#include <string>
#include <palavra.h>


bool Palavra::operator== (Palavra & op2){
	
	if(word1 == word2)
		return true;
	else 
		return false;
}