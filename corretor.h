#ifndef CORRETOR_H_
#define CORRETOR_H_

#include <iostream>
#include "dicionario.h"
#include "avltree.h"
#include "palavra.h"
#include "texto.h"
#include <list>

using namespace std;

class Corretor{
    private:
        Dicionario dic;
        Texto text;
        list<Palavra> erros;
        list<Palavra> :: iterator it;

    public:
        Corretor(){
            text.carregarTexto();
        }
        ~Corretor();
        void verificarTexto();
        bool getErros();
        void exibeErros();
        void corrigirPalavra(string a, Palavra);
        Palavra erroAtual();
        void adicionarEx(Palavra);
        bool errosFim();
        void errosProx();
        void salvarTexto();
        void mostrarSemelhantes(Palavra);
        void corrigirSemelhante(int);
};

#endif
