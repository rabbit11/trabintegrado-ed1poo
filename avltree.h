#ifndef AVLTREE_H_
#define AVLTREE_H_
#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include "palavra.h"
using namespace std;

struct no{
    Palavra palavra;
    int altura;
    struct no* esq;
    struct no* dir;
};

class AvlTree{
    public:
        bool vazia();
        void inserir(Palavra&);
        int busca(Palavra&);
        int busca(Palavra& plv, stack<Palavra>& semelhante);
        stack<Palavra> inOrderPublic();
        void mostrar();
        void mostrarPre();
        AvlTree(){
            raiz = NULL;
        }
        ~AvlTree(){
            destruirAvl(raiz);
        }

    private:
        void printInOrder(no*);
        int busca(no*, Palavra&);
        int busca(no*, Palavra&, stack<Palavra>&);
        no *inserir(no*, Palavra&);
        int getBal(no*);
        void destruirAvl(no*);
        no *rotacionaED(no*);
        no *rotacionaDE(no*);
        no *rotacionaDireita(no*);
        no *rotacionaEsquerda(no*);
        int getAltura(no*);
        int max(int, int);
        no *raiz;
        stack<Palavra> inOrder();

};

#endif
