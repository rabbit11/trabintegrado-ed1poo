#include "texto.h"
#include "palavra.h"

#include <iostream>
#include <string>
#include <fstream>
#include <iterator>
#include <list>
#include <algorithm>

using namespace std;

bool Texto::carregarTexto() {
    string plv;

    ifstream arquivo;
    arquivo.open(filename.c_str(), ios::in);

    if(arquivo.is_open()) {
        while (arquivo >> plv) {
            for (unsigned int i = 0; i < plv.length(); i++) {
                plv[i] = tolower(plv[i]);
            }
            Palavra p(plv);
            palavra.push_back(p);
        }
        arquivo.close();

        list<Palavra> :: iterator it;
        for (it = palavra.begin(); it != palavra.end(); it++) {
            string temp = it->getWord();
            for (unsigned int i = 0; i < temp.length(); i++) {
                if ( !(temp[i] >= 'a' && temp[i] <= 'z') ) {
                    temp.erase(remove(temp.begin(), temp.end(), temp[i]), temp.end());
                }
            }
            Palavra p(temp);
            palavraNoSymbol.push_back(p);
        }
        return true;
    }

    else throw "Arquivo nao encontrado";
}

bool Texto::salvarTexto(string arquivo) {
    if (!palavra.empty()) {
        ofstream arq;
        arq.open(arquivo.c_str(), ios::out | ios::trunc);

        if(arq.is_open()) {
            list<Palavra> :: iterator it;
            for (it = palavra.begin(); it != palavra.end(); it++) {
                arq << it->getWord() << " ";
            }
            arq.close();
            return true;
        }

        else throw "Nao foi possivel salvar o arquivo";

    }
    else throw "A lista está vazia";
}

void Texto::alterarPalavra(Palavra errada, Palavra correta) {

    list<Palavra> :: iterator it;
    for (it = palavra.begin(); it != palavra.end(); it++) {
        if(palavra.front() == errada)
            break;
    }
    palavra.insert(it, correta);
}

//retorna um iterador para o elemento de primeira posição na list
list<Palavra> :: iterator Texto::getPrimeiro() {
    list<Palavra> :: iterator it = palavraNoSymbol.begin();
    return it;
}

//avança o iterador 1 posição na list
void Texto::getProx(list<Palavra> :: iterator it) {
    advance(it, 1);
}

//retorna true caso o iterador estiver na ultima posição da list
//e false caso contrario
bool Texto::ultimo(list<Palavra> :: iterator it) {
    if (it == palavraNoSymbol.end())
        return true;
    return false;
}

//retorna palavra para qual o iterador da list aponta
Palavra& Texto::getPalavra(list<Palavra> :: iterator it) {
    return *it;
}
