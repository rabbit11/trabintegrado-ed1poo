#include <iostream>
#include <string>
#include <fstream>
#include "palavra.h"
using namespace std;

struct no{
    Palavra palavra;
    int altura;
    struct no* esq;
    struct no* dir;
};

class avlTree{
    public:
        bool vazia();
        void inserir(Palavra&);
        int busca(Palavra&);
        void mostrar();
        void mostrarPre();
        avlTree(){
            raiz = NULL;
        }
        ~avlTree(){
            destruirAvl(raiz);
        }

    private:
        void printPreOrder(no*);
        void printInOrder(no*);
        int busca(no*, Palavra&);
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
};
