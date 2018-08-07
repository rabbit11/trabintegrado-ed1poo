#include "texto.h"
#include "palavra.h"

#include <iostream>
#include <string>
#include <fstream>
#include <iterator>
#include <list>
#include <algorithm>

using namespace std;

/*-------------------------------------------------------------------------------------------------------------------------------
     carregarTexto: Funcao para carregar o arquivo .txt para a correcao. Retorna uma excecao caso o arquivo nao seja encontrado.
-------------------------------------------------------------------------------------------------------------------------------*/
void Texto::carregarTexto() {
    string plv;

    ifstream arq;
    arq.open(load, ios::in);

    if(arq.is_open()) {
        while (arq >> plv) {
            Palavra p(plv);
            palavra.push_back(p);
        }
        arq.close();

        list<Palavra> :: iterator it;
        for (it = palavra.begin(); it != palavra.end(); it++) {
            string temp = it->getWord();
            for (unsigned int i = 0; i < temp.length(); i++) {
                    temp[i] = tolower(temp[i]);
                temp[i] = tolower(temp[i]);

              if ( !( (temp[i] >= 97 && temp[i] <= 122) || (temp[i] >= -128 && temp[i] <= 0))) {
                    temp.erase(remove(temp.begin(), temp.end(), temp[i]), temp.end());
              }
            }
            Palavra p(temp);
            palavraNoSymbol.push_back(p);
        }
    }

    else throw "Arquivo nao encontrado";
}

/*-------------------------------------------------------------------------------------------------------------------------------
     salvarTexto: Funcao para salvar o arquivo .txt corrigido. Retorna uma excecao caso nao seja possivel salvar o arquivo
-------------------------------------------------------------------------------------------------------------------------------*/
void Texto::salvarTexto() {
    if (!palavra.empty()) {
        ofstream arq;
        arq.open(save, ios::out | ios::trunc);

        if(arq.is_open()) {
            list<Palavra> :: iterator it;
            for (it = palavra.begin(); it != palavra.end(); it++) {
                arq << *it << " ";
            }
            arq.close();
        }

        else throw "Nao foi possivel salvar o arquivo";

    }
    else throw "A lista esta vazia";
}

/*-------------------------------------------------------------------------------------------------------------------------------
     alterarPalavra: Funcao para trocar a palavrada errada pela correta na lista
-------------------------------------------------------------------------------------------------------------------------------*/
void Texto::alterarPalavra(const Palavra &errada, const Palavra &correta) {

    list<Palavra> :: iterator it;
    list<Palavra> :: iterator it2;
    bool flag = false;
    char tempc;
    it = palavraNoSymbol.begin();
    it2 = palavra.begin();

    for(int i = 0; i < errada.getOcorrencias(); i++) {
        for (; it != palavraNoSymbol.end(); it++, it2++) {
            string temp = it2->getWord();
            flag = false;

            for (unsigned int i = 0; i < temp.length(); i++) {
                    temp[i] = tolower(temp[i]);
                if (!((temp[i] >= 97 && temp[i] <= 122) || (temp[i] >= -128 && temp[i] <= 0))) {
                    tempc = temp[i];
                    flag = true;
                    break;
                }
            }
            if(*it == errada)
                break;

      for (; it != palavraNoSymbol.end(); it++, it2++) {
        string temp = it2->getWord();
        flag = false;
        for (unsigned int i = 0; i < temp.length(); i++) {
            temp[i] = tolower(temp[i]);
          if ( !( (temp[i] >= 97 && temp[i] <= 122) || (temp[i] >= -128 && temp[i] <= 0))) {
              tempc = temp[i];
              flag = true;
              break;
          }
       }
          if(it->getWord() == errada.getWord())
              break;
      }
      *it2 = correta;
      if (flag)
      it2->setWord(it2->getWord() + tempc);
  }
}

/*-------------------------------------------------------------------------------------------------------------------------------
     getPrimeiro: retorna um iterador para o elemento de primeira posição na list
-------------------------------------------------------------------------------------------------------------------------------*/
list<Palavra> :: iterator Texto::getPrimeiro() {
    list<Palavra> :: iterator it = palavraNoSymbol.begin();
    return it;
}

/*-------------------------------------------------------------------------------------------------------------------------------
     ultimo: retorna true caso o iterador estiver na ultima posição da list e false caso contrario
-------------------------------------------------------------------------------------------------------------------------------*/
bool Texto::ultimo(const list<Palavra> :: iterator &it) const {
    if (it == palavraNoSymbol.end())
        return true;
    return false;
}

/*-------------------------------------------------------------------------------------------------------------------------------
     getPalavra: retorna palavra para qual o iterador da list aponta
-------------------------------------------------------------------------------------------------------------------------------*/
Palavra& Texto::getPalavra(const list<Palavra> :: iterator &it) const {
    return *it;
}

/*-------------------------------------------------------------------------------------------------------------------------------
     contexto: printa palavras proximas a palavra errada
-------------------------------------------------------------------------------------------------------------------------------*/
void Texto::contexto(list<Palavra> :: iterator &it) {

    list<Palavra> :: iterator temp;
    list<Palavra> :: iterator temp2;
    list<Palavra> :: iterator fim;
    fim = palavraNoSymbol.end();
    advance(fim, -1);
    for (temp = palavraNoSymbol.begin(), temp2 = palavraNoSymbol.begin(); temp != fim; temp++, temp2++) {
        if(*temp == *it)
            break;
    }

    if (temp == palavraNoSymbol.begin()) {
        cout << *temp2 << " ";
        advance(temp2, 1);
        cout << *temp2 << endl;
    }
    else if (temp == fim) {
        advance(temp2, -1);
        cout << *temp2 << " ";
        advance(temp2, 1);
        cout << *temp2 << endl;

    }
    else {
        advance(temp2, -1);
        cout << *temp2 << " ";
        advance(temp2, 1);
        cout << *temp2 << " ";
        advance(temp2, 1);
        cout << *temp2 << endl;
    }
}

/*-------------------------------------------------------------------------------------------------------------------------------
     Getters e setters
-------------------------------------------------------------------------------------------------------------------------------*/
void Texto::setLoad(const string &s) {
    load = s;
}

void Texto::setSave(const string &s) {
    save = s;
}
