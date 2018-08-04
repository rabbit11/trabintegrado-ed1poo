#include <iostream>
#include <stack>
#include <string>
#include "avltree.h"
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
    exportarDicionario();
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

    cout << "Dicionario importado com sucesso!" << endl;

    return;
}

//verifica se alguma alteraçao foi feita no Dicionario, caso alguma alteração tenha sido feita
//exportamos o novo Dicionario para "dic.txt", do contrario mantemos como este estava antes
// void Dicionario::exportarDicionario(Palavra& p){
//     if(mudou == true){
//         ofstream arquivo;
//         arquivo.open("dic.txt", ios::app);
//
//         if(arquivo.is_open()){
//             arquivo << p.getWord() << endl;
//         }
//         arquivo.close();
//     }
// }

//a versão abaixa exporta o dicionário como um todo, caso uma alteração no dicionário tenha sido efetuada
void Dicionario::exportarDicionario(){
    if(mudou == true){
        stack <Palavra>s;
        string temp;
        ofstream arquivo;
        arquivo.open("dic.txt");

        s = tree.inOrderPublic();

        if(arquivo){
            while(!s.empty()){
                temp = s.top().getWord();
                arquivo << temp << endl;
                s.pop();
            }
        }
    }
}

//função que busca e retorna uma lista de palavras semelhantes aquela passada como parâmetro
void Dicionario::buscaSemelhantes(Palavra& p){
    if(tree.vazia()){
        return;
    }else{
        tree.busca(p, semelhantes);
    }
    return;
}

//função que reseta a lista de semelhantes para que possa ser usada
//para armazenar novas palavras semelhantes a uma outra palavra
void Dicionario::resetSemelhantes(){
    if(!semelhantes.empty()){
        semelhantes.clear();
    }
    else throw "Lista de semelhantes não possui elementos.";
}

//retorna true caso o iterador esteja na última palavra do deque
//e false caso o contrário
bool Dicionario::ultimo(deque<Palavra> :: iterator& it){
    if(it == semelhantes.end()){
        return true;
    }
    return false;
}

//função que retorna um iterador para o primeiro elemento do deque
//de palavras semelhantes
deque<Palavra> :: iterator Dicionario::getPrimeiro(){
    deque<Palavra>::iterator it = semelhantes.begin();

    return it;
}

//função para avançar o iterador no deque de palavras semelhantes
void Dicionario::getProx(deque<Palavra> :: iterator& it){
    advance(it, 1);
}

//função retorna a palavra para qual o iterador está apontando
Palavra& Dicionario::getPalavra(deque<Palavra> :: iterator& it){
    return *it;
}

//função retorna uma palavra do deque de acordo com o índice fornecido
Palavra& Dicionario::getPalavra(unsigned i){
    if(i < semelhantes.size() && i <= 6){
        return semelhantes[i];
    }
    else throw "Indice inserido inválido";
}

//imprime lista de palavras semelhantes
void Dicionario::printSemelhantes(){

    if(semelhantes.empty()){
        throw "Não foram encontradas palavras semelhantes.";
    }
    int tamanho = semelhantes.size();
    for(int i = 0;  i < 7 && i < tamanho; i++){
        Palavra temp = semelhantes[i];
        string aux = temp.getWord();
        cout << i << "." << aux << endl;

    }
}
