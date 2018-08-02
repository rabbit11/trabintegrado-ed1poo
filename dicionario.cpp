#include <iostream>
#include <stack>
#include <string>
#include "dicionario.h"
#include "palavra.h"
#include <fstream>

using namespace std;


//construtor default da classe Dicionario, que inicializa a variável "mudou"
//e importa um Dicionario de um arquivo .txt
Dicionario::Dicionario(){
    mudou = false;
    importarDicionario();
}

Dicionario::~Dicionario(){
    return;
}

//função utilizada para que pudéssemos checar se todas as palavras foram importadas
//para a árvore corretamente
void Dicionario::printarvore(){
    tree.mostrar();
}

//função que permite ao usuário efetuar a consulta de uma palavra no exportarDicionario
//retorna false para palavra não encontrada e true para palavra encontrada
bool Dicionario::consulta(Palavra& p){
    return tree.busca(p);
}

//função que permite ao usuário inserir uma nova palavra na árvore do Dicionario
//e consequentemente insere no arquivo.txt do Dicionario
void Dicionario::inserirPalavra(Palavra& p){
    mudou = true;
    tree.inserir(p);
    exportarDicionario(p);
}

//funçao que carrega Dicionario a partir de um arquivo .txt e o insere na árvore
void Dicionario::importarDicionario(){
    Palavra buffer;
    string temp;
    ifstream arquivo;
    arquivo.open("dic.txt");

    while(!arquivo.eof()){
        //getline(arquivo, buffer);
        arquivo >> temp;
        buffer.setWord(temp);
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

    cout << "Dicionário importado com sucesso!" << endl;

    return;
}

//verifica se alguma alteraçao foi feita no Dicionario, caso alguma alteração tenha sido feita
//exportamos o novo Dicionario para "dic.txt", do contrario mantemos como este estava antes
void Dicionario::exportarDicionario(Palavra& p){
    if(mudou == true){
        ofstream arquivo;
        arquivo.open("dic.txt", ios::app);

        if(arquivo.is_open()){
            arquivo << p.getWord() << endl;
        }
        arquivo.close();
    }
}

//a versão abaixa exporta o dicionário como um todo
// void Dicionario::exportarDicionario(){
//     if(mudou == true){
//         stack <string>s;
//         string temp;
//         ofstream arquivo;
//         arquivo.open("dic.txt");
//
//         s = tree.inOrderPublic();
//
//         if(arquivo){
//             while(!s.empty()){
//                 temp = s.top();
//                 arquivo << temp << endl;
//                 s.pop();
//             }
//         }
//     }
// }


//função que busca e retorna uma lista de palavras semelhantes aquela passada como parâmetro

void Dicionario::buscaSemelhantes(Palavra& p){
    if(!tree.vazia()){
        return;
    }else{
        stack<Palavra> semelhante;
        string aux = p.getWord();
        aux = aux.substr(0,2);
        Palavra temp(aux);

        tree.busca(temp, semelhante);
    }
    return;
}

void printSemelhantes(stack<Palavra>& semelhante){
    for(int i = 0; !semelhante.empty(); i++){
        Palavra temp = semelhante.top();
        string aux = temp.getWord();
        cout << i << "." << aux << endl;
    }
}

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
