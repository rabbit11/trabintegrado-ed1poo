#include <iostream>
#include <stack>
#include "avltree.h"

using namespace std;

class dicionario{
    private:
        avlTree tree;
        //stack <palavra>semelhante;
    public:
        dicionario();
        ~dicionario();
        //bool consulta(palavra p);
        //bool inserirPalavra(palavra p);
        bool importarDicionario();
        bool exportarDicionario();
        //string palavrasSemelhantes(palavra p);

};
