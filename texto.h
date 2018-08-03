#ifndef TEXTO_H_
#define TEXTO_H_

#include <iostream>
#include <string>
#include <list>

#include "palavra.h"

using namespace std;

class Texto {

private:
	string filename;
	list<Palavra> palavra;
	list<Palavra> palavraNoSymbol;
public:
	Texto(string file = "text.txt") : filename(file) {};
	bool carregarTexto();
	void alterarPalavra(Palavra errada, Palavra correta);
	bool salvarTexto(string arquivo);
	bool ultimo(list<Palavra> :: iterator it);
	list<Palavra> :: iterator getPrimeiro();
	Palavra& getPalavra(list<Palavra> :: iterator it);
};

#endif
