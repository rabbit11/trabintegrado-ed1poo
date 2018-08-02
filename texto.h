#ifndef TEXTO_H_
#define TEXTO_H_

#include <iostream>
#include <string>
#include <list>

#include "Palavra.h"

using namespace std;

class Texto {

private:
	string nomeArquivo;
	list<Palavra> palavra;
public:
	Texto() : nomeArquivo("texto.txt"), nPalavras(0) {};
	void carregarTexto();
	void salvarTexto();
	void alterarPalavra(list<palavra> :: iterator it);
};

#endif