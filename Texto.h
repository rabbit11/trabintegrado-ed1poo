#ifndef TEXTO_H_
#define TEXTO_H_

#include <iostream>

#include "Palavra.h"

using namespace std;

class Texto {

private:
	int nPalavras;
	string arquivo;
	Palavra palavra[10000];
public:
	Texto() : arquivo("texto.txt"), nPalavras(0) {};
	void carregarTexto();
	void salvarTexto();
	void alterarPalavra(int indice);

};

#endif