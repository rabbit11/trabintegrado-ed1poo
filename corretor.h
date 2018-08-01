#include <iostream>
#include "dicionario.h"
#include "avltree.h"
#include "palavra.h"
#include "Texto.h"
#include <list>

using namespace std;


class corretor{
    private:
        dicionario dic;
        Texto text;
        list<palavra> lista;

    public:
        corretor();
        ~corretor();
        void alterarPalavraTexto(int indice);
        void carregarTexto();
    	void salvarTexto();
        bool consultaDic(palavra& p);
        void inserirPalavraDic(palavra& p);

}
