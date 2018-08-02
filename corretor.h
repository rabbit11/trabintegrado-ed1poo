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

    public:
        Corretor();
        ~Corretor();
        void verificarTexto();
        bool getErros();
        void exibeErros();
};

#endif
