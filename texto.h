#ifndef TEXTO_H_
#define TEXTO_H_

#include <iostream>
#include <string>
#include <list>

#include "palavra.h"

using namespace std;

class Texto {

private:
	string nomeArquivo;
	list<Palavra> palavra;
public:
	Texto() : nomeArquivo("texto.txt") {};
	void carregarTexto();
	void salvarTexto();
	void alterarPalavra(list<Palavra> :: iterator it);
};

#endif
