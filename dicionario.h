#ifndef DICIONARIO_H_
#define DICIONARIO_H_
#include <iostream>
#include <stack>
#include <iterator>
#include <deque>
#include "avltree.h"
#include "palavra.h"
#include <algorithm>

using namespace std;

class Dicionario{
    private:
        AvlTree tree;
        bool mudou;
        deque<Palavra> semelhantes;
    public:
        Dicionario();
        ~Dicionario();
        void printarvore();
        bool consulta(Palavra& p);
        void inserirPalavra(Palavra& p);
        void importarDicionario();
        void exportarDicionario();
        void buscaSemelhantes(Palavra& p);
        void printSemelhantes(stack<Palavra>&);

        bool ultimo(deque<Palavra> :: iterator& it);
        deque<Palavra> :: iterator getPrimeiro();
        void getProx(deque<Palavra> :: iterator& it);
        Palavra& getPalavra(deque<Palavra> :: iterator& it);


};

#endif
