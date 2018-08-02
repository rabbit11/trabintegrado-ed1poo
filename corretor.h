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
        list<Palavra> lista;

    public:
        Corretor();
        ~Corretor();
    	void salvarTexto();
        bool consultaDic(Palavra& p);
        void inserirPalavraDic(Palavra& p);

};

#endif
