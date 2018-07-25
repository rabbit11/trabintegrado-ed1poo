#include "Texto.h"
#include "Palavra.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void Texto::carregarTexto() {
    string buffer;

    string name;
    cin >> name;
    name += ".txt";

    ifstream arquivo(name);

    if(arquivo.is_open()) {
    	int j = 0;
    	while (arquivo >> buffer) {
	      palavra[j] = buffer;
	      j++;
	    } 
		nPalavras = j;
		arquivo.close();
    }

    else throw "Arquivo nao encontrado";
}

void Texto::salvarTexto() {
    string name;
    cin >> name;
    name += ".txt";
    ofstream arquivo(name);

    if(arquivo.is_open()) {
    	for(int i = 0; i < nPalavras; i++) {
        	arquivo << palavra[i] << " ";
        }
    }

    else throw "Nao foi possivel salvar o arquivo";
}

void Texto::alterarPalavra(int indice) {

	string s;
	cout << "Digite o que sera alterado" << endl;
	cin >> s;
	palavra[indice] = s;

}