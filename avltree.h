#include <iostream>
#include <string>
#include <stack>
#include <fstream>
using namespace std;

struct no{
    string palavra;
    int altura;
    struct no* esq;
    struct no* dir;
};

class avlTree{
    public:
        int vazia();
        void inserir(string&);
        int busca(string&);
        void mostrar();
        void mostrarPre();
        bool importarDic();
        avlTree(){
            raiz = NULL;
        }
        ~avlTree(){
            destruirAvl(raiz);
        }
        stack<string> inOrderPublic();

    private:
        void printPreOrder(no*);
        void printInOrder(no*);
        int busca(no*, string&);
        no *inserir(no*, string&);
        int getBal(no*);
        void destruirAvl(no*);
        no *rotacionaDoubleRight(no*);
        no *rotacionaDoubleLeft(no*);
        no *rotacionaSingleRight(no*);
        no *rotacionaSingleLeft(no*);
        int getAltura(no*);
        int max(int, int);
        no *raiz;
        stack<string> inOrder();
};
