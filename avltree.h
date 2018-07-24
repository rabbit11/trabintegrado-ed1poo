#include <iostream>
#include <stack>
#include <string>
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
        avlTree(){
            raiz = NULL;
        }
        ~avlTree(){
            destruirAvl(raiz);
        }
        stack<string> inOrderPublic();

    private:
        void printPreOrder(no *);
        int busca(no*, string&);
        no *inserir(no*, string&);
        int getBal(no *);
        void destruirAvl(no *);
        no *rotacionaDE(no *);
        no *rotacionaED(no *);
        no *rotacionaEE(no *);
        no *rotacionaDD(no *);
        int getAltura(no *);
        int max(int, int);
        no *raiz;
        stack<string> inOrder();

};
