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
	list<Palavra> palavraNoSymbol;
public:
	Texto() : nomeArquivo("texto.txt") {};
	void carregarTexto();
	void salvarTexto();
	void alterarPalavra(list<Palavra> :: iterator it);
 	list<Palavra> :: iterator getPrimeiro();
	void getProx(list<Palavra> :: iterator it);
	bool ultimo(list<Palavra> :: iterator it);
	Palavra& getPalavra(list<Palavra> :: iterator it);
};

#endif
