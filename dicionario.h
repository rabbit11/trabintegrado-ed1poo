#ifndef DICIONARIO_H_
#define DICIONARIO_H_
#include <iostream>
#include <stack>
#include "avltree.h"
#include "palavra.h"

using namespace std;

class Dicionario{
    private:
        AvlTree tree;
        bool mudou;
    public:
        Dicionario();
        ~Dicionario();
        void printarvore();
        bool consulta(Palavra& p);
        void inserirPalavra(Palavra& p);
        void importarDicionario();
        void exportarDicionario(Palavra& p);
        void buscaSemelhantes(Palavra& p);
        void printSemelhantes(stack<Palavra>&);

};

#endif
