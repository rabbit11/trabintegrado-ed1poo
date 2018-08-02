
#include "Texto.h"
#include "palavra.h"

#include <iostream>
#include <string>
#include <fstream>
#include <iterator>
#include <list>

using namespace std;

void Texto::carregarTexto() {
    string word;

    cout << "Insira o nome do arquivo a ser carregado (sem a extensao)" << endl;
    string filename;
    cin >> filename;
    filename += ".txt";

    ifstream arquivo;
    arquivo.open(filename.c_str(), ios::in);
    nomeArquivo = filename;

    if(arquivo.is_open()) {
    	while (arquivo >> word) {
	      push_front(word);
	    }
		arquivo.close();
    }

    else throw "Arquivo nao encontrado";
}

void Texto::salvarTexto() {
    string filename;
    cout << "Insira o nome do arquivo a ser salvo (sem a extensao)" << endl;
    cin >> filename;
    filename += ".txt";
    ofstream arquivo;
    arquivo.open(filename.c_str(), ios::out | ios::app);

    if(arquivo.is_open()) {
        list<Palavra> :: iterator it;
        for (it = palavra.begin(); it != palavra.end(); it++) {
            arquivo << *it;
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
