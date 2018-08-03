#include "corretor.h"

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
        if(!dic.consulta(getPalavra(it))){
            erros.push_front(getPalavra(it));
        }
        text.getProximo(it);
    }
}

bool Corretor::getErros(){
    return erros.empty();
}

void Corretor::exibeErros(){
    list<Palavra> :: iterator it;
    for(it = erros.begin(); it != erros.end(); it++){
        cout << erros.front().getWord() << endl;
    }
}

void Corretor::tratarErros(){
    list<Palavra> :: iterator it;
    int opc;
    for(it = erros.begin(); it != erros.end(); it++){
        cout << erros.front().getWord() << endl;
        cout << "1- Adicionar ao dicionario como excessao" << endl;
        cout << "2- Listar sugestoes do dicionario" << endl;
        cout << "3- Corrigir manualmente" << endl;
        cout << "4- Ignorar erro" << endl;
        cin >> opc;

        switch(opc){
            case 1:
                dic.inserirPalavra(erros.front().getWord());
                cout << "Palavra inserida com sucesso" << endl;
                break;

            case 2:
                dic.buscarSemelhantes(erros.front().getWord());
                break;

            case 3:
                string a;
                cin >> a;
                Palavra b(a);
                //funcao do natham de procurar a palavra e inserir la;
                break;

            case 4:
                break;
        }
    }
}
