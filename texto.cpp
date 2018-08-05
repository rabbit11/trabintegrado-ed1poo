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

    ifstream arq;
    arq.open(load, ios::in);

    if(arq.is_open()) {
        while (arq >> plv) {
            for (unsigned int i = 0; i < plv.length(); i++) {
                plv[i] = tolower(plv[i]);
            }
            Palavra p(plv);
            palavra.push_back(p);
        }
        arq.close();

        list<Palavra> :: iterator it;
        for (it = palavra.begin(); it != palavra.end(); it++) {
            string temp = it->getWord();
            for (unsigned int i = 0; i < temp.length(); i++) {
                if ( !( (temp[i] >= 97 && temp[i] <= 122) || (temp[i] >= 192 && temp[i] <= 255))) {
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

bool Texto::salvarTexto() {
    if (!palavra.empty()) {
        ofstream arq;
        arq.open(save, ios::out | ios::trunc);

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

void Texto::alterarPalavra(const Palavra &errada, const Palavra &correta) {

    list<Palavra> :: iterator it;
    for (it = palavra.begin(); it != palavra.end(); it++) {
        if(it->getWord() == errada.getWord())
            break;
    }
    *it = correta;
}

//retorna um iterador para o elemento de primeira posição na list
list<Palavra> :: iterator Texto::getPrimeiro() {
    list<Palavra> :: iterator it = palavraNoSymbol.begin();
    return it;
}

//retorna true caso o iterador estiver na ultima posição da list
//e false caso contrario
bool Texto::ultimo(const list<Palavra> :: iterator &it) const {
    if (it == palavraNoSymbol.end())
        return true;
    return false;
}

//retorna palavra para qual o iterador da list aponta
Palavra& Texto::getPalavra(const list<Palavra> :: iterator &it) const {
    return *it;
}

void Texto::setLoad(const string &s) {
    load = s;
}

void Texto::setSave(const string &s) {
    save = s;
}

void Texto::contexto(list<Palavra> :: iterator &it) const {

    list<Palavra> :: iterator temp;
    list<Palavra> :: iterator fim;
    fim = palavraNoSymbol.end();
    advance(fim, -1);
    for (temp = palavraNoSymbol.begin(); temp != palavraNoSymbol.end(); temp++) {
        if(*temp == *it)
            break;
    }

    if (temp == palavraNoSymbol.begin()) {
        cout << *temp << " ";
        advance(temp, 1);
        cout << *temp << endl;;
    }
    else if (temp == fim) {
        advance(temp, -1);
        cout << *temp << " ";
        advance(temp, 1);
        cout << *temp << endl;

    }
    else {
        advance(temp, -1);
        cout << *temp << " ";
        advance(temp, 1);
        cout << *temp << " ";
        advance(temp, 1);
        cout << *temp << endl;
    }
}
