#include "texto.h"
#include "palavra.h"

#include <iostream>
#include <string>
#include <fstream>
#include <iterator>
#include <list>
#include <algorithm>

using namespace std;

void Texto::carregarTexto() {
    string plv;

    cout << "Insira o nome do arquivo a ser carregado (sem a extensao)" << endl;
    string filename;
    cin >> filename;
    filename += ".txt";

    ifstream arquivo;
    arquivo.open(filename.c_str(), ios::in);
    nomeArquivo = filename;

    if(arquivo.is_open()) {
        while (arquivo >> plv) {
            for (unsigned i = 0; i < plv.length(); i++) {
                plv[i] = tolower(plv[i]);
            }
          palavra.push_back(plv);
        }
        arquivo.close();

        list<Palavra> :: iterator it;
        for (it = palavra.begin(); it != palavra.end(); it++) {
            string temp = palavra.front().getWord();
            for (unsigned i = 0; i < temp.length(); i++) {
                if ( !(temp[i] > 'a' || temp[i] < 'z') ) {
                    temp.erase(remove(temp.begin(), temp.end(), temp[i]), temp.end());
                }
                 palavraNoSymbol.push_back(temp);
            }
    }

        cout << "O arquivo foi carregado com sucesso" << endl;
    }

    else throw "Arquivo nao encontrado";
}

void Texto::salvarTexto() {
    string filename;
    cout << "Insira o nome do arquivo a ser salvo (sem a extensao)" << endl;
    cin >> filename;
    filename += ".txt";
    ofstream arquivo;
    arquivo.open(filename.c_str(), ios::out | ios::trunc);

    if(arquivo.is_open()) {
        list<Palavra> :: iterator it;
        for (it = palavra.begin(); it != palavra.end(); it++) {
            arquivo << it->getWord() << " ";
        }
    }

    else throw "Nao foi possivel salvar o arquivo";
}

void Texto::alterarPalavra(list<Palavra> :: iterator it) {

    string s;
    cout << "Digite a nova palavra" << endl;
    cin >> s;
    Palavra p(s);
    palavra.insert(it, s);

}

list<Palavra> :: iterator Texto::getPrimeiro() {
    list<Palavra> :: iterator it = palavraNoSymbol.begin();
    return it;
}

void Texto::getProx(list<Palavra> :: iterator it) {
    advance(it, 1);
}

bool Texto::ultimo(list<Palavra> :: iterator it) {
    if (it == palavraNoSymbol.end())
        return true;
    return false;
}

Palavra& Texto::getPalavra(list<Palavra> :: iterator it) {
    return *it;
}
