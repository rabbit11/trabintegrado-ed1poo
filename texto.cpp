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
                if ( !( (temp[i] >= 97 && temp[i] <= 122) || (temp[i] >= -128 && temp[i] <= 0))) {
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
            for (it = palavraNoSymbol.begin(); it != palavraNoSymbol.end(); it++) {
                arq << *it << " ";
            }
            arq.close();
            return true;
        }

        else throw "Nao foi possivel salvar o arquivo";

    }
    else throw "A lista esta vazia";
}

void Texto::alterarPalavra(const Palavra &errada, const Palavra &correta) {

    list<Palavra> :: iterator it;
    list<Palavra> :: iterator it2 = palavra.begin();
    bool flag = false;
    char tempc;

    for (it = palavraNoSymbol.begin(), it2 = palavra.begin(); it != palavraNoSymbol.end() && it2 != palavra.end(); it++, it2++) {
      string temp = it2->getWord();
      flag = false;
      for (unsigned int i = 0; i < temp.length(); i++) {
          if ( !( (temp[i] >= 97 && temp[i] <= 122) || (temp[i] >= -128 && temp[i] <= 0))) {
              tempc = temp[i];
              flag = true;
              break;
          }
      }
        if(it->getWord() == errada.getWord())
            break;
    }
    *it = correta;
    if (flag)
      it->setWord(it->getWord() + tempc);
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

void Texto::contexto(list<Palavra> :: iterator &it) {

    list<Palavra> :: iterator temp;
    list<Palavra> :: iterator fim;
    fim = palavra.end();
    advance(fim, -1);
    for (temp = palavra.begin(); temp != fim; temp++) {
        if(*temp == *it)
            break;
    }

    if (temp == palavra.begin()) {
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
