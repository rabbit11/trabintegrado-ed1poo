#include <iostream>
#include <stack>
#include "avltree.h"


using namespace std;

class dicionario{
    private:
        avlTree tree;
        //stack <palavra>semelhante;
        bool mudou;
    public:
        dicionario();
        ~dicionario();
        void printarvore();
        bool consulta(string& p);
        void inserirPalavra(string& p);
        void importarDicionario();
        void exportarDicionario();
        //string palavrasSemelhantes(palavra p);

};
