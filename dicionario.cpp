#include <iostream>
#include <stack>
#include <string>
#include "dicionario.h"
#include <fstream>
using namespace std;

dicionario::dicionario(){
  importarDicionario();
}

dicionario::~dicionario(){
    exportarDicionario();
    //metodo destruirAvl???
}


//função que retorna 0 para palavra não encontrada e 1 para palavra encontrada
// bool dicionario::consulta(palavra p){
//     return tree.busca(p.word);
// }
//
// //função que retorna 1 para palavra inserida com sucesso e 0 para palavra não inserida
// bool dicionario::inserirPalavra(palavra p){
//     return tree.inserir(p.word)
// }

//funçao que carrega dicionario a partir de um arquivo .txt e o insere na árvore
//retorna 1 para insercao bem sucedida e 0 para insercao nao realizada
bool dicionario::importarDicionario(){
    string buffer;
    ifstream arquivo("dic.txt");

    if(arquivo){
      while(getline(arquivo, buffer)){
        tree.inserir(buffer);
      }
    }
}

bool dicionario::exportarDicionario(){
    stack <string>s;
    string temp;
    ofstream arquivo("dic.txt");

    s = tree.inOrderPublic();

    if(arquivo){
        while(!s.empty()){
            temp = s.top();
            arquivo << temp << endl;
            s.pop();
        }
    }
}


//função que busca e retorna uma lista de palavras semelhantes aquela passada como parâmetro
// string palavrasSemelhantes(palavra p){
//     if(!tree){
//         return;
//     }else{
//         if(p.word.compare(tree.palavra.word) >= -2 && p.word.compare(tree.palavra.word) <= 2){
//             semelhante.push(tree.palavra);
//         }else if(p.esq.word.compare(tree.palavra.word) < -2){
//             //qual criterio usar para decisão de "descer" na árvore
//         }
//     }
// }
