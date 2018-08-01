#include <iostream>
#include <stack>
#include <string>
#include "dicionario.h"
#include <fstream>

using namespace std;


//construtor default da classe dicionario, que inicializa a variável "mudou"
//e importa um dicionario de um arquivo .txt
dicionario::dicionario(){
    mudou = false;
    importarDicionario();
}

//destrutor da classe dicionario, que caso o dicionário tenha sido alterado,
//chama a função exportar dicinário para que novas palavras inseridas pelo usuário
//sejam salvas no arquivo .txt
dicionario::~dicionario(){
    exportarDicionario();
}

//função utilizada para que pudéssemos checar se todas as palavras foram importadas
//para a árvore corretamente
void dicionario::printarvore(){
    tree.mostrar();
}

//função que permite ao usuário efetuar a consulta de uma palavra no exportarDicionario
//retorna false para palavra não encontrada e true para palavra encontrada
bool dicionario::consulta(string& p){
    return tree.busca(p);
}

//função que permite ao usuário inserir uma nova palavra no dicionário
void dicionario::inserirPalavra(string& p){
    mudou = true;
    return tree.inserir(p);
}

//funçao que carrega dicionario a partir de um arquivo .txt e o insere na árvore
void dicionario::importarDicionario(){
    string buffer;
    ifstream arquivo;
    arquivo.open("dic.txt");

    while(!arquivo.eof()){
        //getline(arquivo, buffer);
        arquivo >> buffer;
        //cout << buffer << endl;
        tree.inserir(buffer);
      }

    // if(arquivo){
    //     while(arquivo >> buffer){
    //         tree.inserir(buffer);
    //         //cout << buffer << endl;
    //     }
    //     arquivo.close();
    // }

    arquivo.close();

    return;
}

void dicionario::exportarDicionario(){

    //verifica se alguma alteraçao foi feita no dicionario, caso alguma alteração tenha sido feita
    //exportamos o novo dicionario para "dic.txt", do contrario mantemos como este estava antes
    if(mudou == true){
        stack <string>s;
        string temp;
        ofstream arquivo;
        arquivo.open("dic.txt");

        s = tree.inOrderPublic();

        if(arquivo){
            while(!s.empty()){
                temp = s.top();
                arquivo << temp << endl;
                s.pop();
            }
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
