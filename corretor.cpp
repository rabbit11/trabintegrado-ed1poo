#include "corretor.h"
#include <string>

using namespace std;

Corretor::Corretor(){
//o que colocar aqui?
}

Corretor::~Corretor(){
// o que colocar aqui?
}

void Corretor::verificarTexto(){
    list<Palavra> :: iterator it;
    it = text.getPrimeiro();
    while(!text.ultimo(it)){
        if(!dic.consulta(text.getPalavra(it))){
            erros.push_front(text.getPalavra(it));
        }
        text.getProx(it);
    }
}

bool Corretor::getErros(){
    return (!erros.empty());
}

void Corretor::exibeErros(){
    list<Palavra> :: iterator it;
    for(it = erros.begin(); it != erros.end(); it++){
        cout << it->getWord() << endl;
    }
}

void Corretor::tratarErros(){
    list<Palavra> :: iterator it;
    int opc;
    string nova;
    Palavra b(nova);
    for(it = erros.begin(); it != erros.end(); it++){
        cout << it->getWord() << endl;
        cout << "1- Adicionar ao dicionario como excessao" << endl;
        cout << "2- Listar sugestoes do dicionario" << endl;
        cout << "3- Corrigir manualmente" << endl;
        cout << "4- Ignorar erro" << endl;
        cin >> opc;

        switch(opc){
            case 1:
                dic.inserirPalavra(*it);
                cout << "Palavra inserida com sucesso" << endl;
                break;

            case 2:
                dic.buscaSemelhantes(*it);

                break;

            case 3:
                cin >> nova;
                text.alterarPalavra(erros.front(), nova);
                break;

            case 4:
                break;
        }
    }
}
