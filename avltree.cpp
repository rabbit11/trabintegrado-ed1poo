//Vinicius Brandao Crepschi   RA: 743601
#include <stack>
#include <iostream>
#include <string.h>
#include "avltree.h"

//****************
//*METODOS PUBLIC*
//****************

int avlTree::vazia(){
    return (raiz == NULL)? 1 : 0;
}

void avlTree::inserir(string& plv){
    raiz = inserir(raiz, plv);
}

int avlTree::busca(string& plv){
    return busca(raiz, plv);
}

void avlTree::mostrar(){
    if(vazia()) return;

    printPreOrder(raiz);
}

stack<string> avlTree::inOrderPublic(){
    return inOrder();
}

//*****************
//*METODOS PRIVATE*
//*****************

//Retorna maximo entre dois int
int avlTree::max(int a, int b){
    return (a>b)? a : b;
}

//Retorna atributo altura
int avlTree::getAltura(no* raiz){
    if(raiz == NULL)
        return 0;

    return raiz->altura;
}

//Realiza rotação da arvore no caso Esquerda-Esquerda
no *avlTree::rotacionaEE(no *A){
    printf("CASO EE\n");
    no *B = A->esq;
    A->esq = B->dir;
    B->dir = A;

    //Atualizando alturas
    A->altura = max(getAltura(A->esq), getAltura(A->dir))+1;
    B->altura = max(getAltura(B->esq), getAltura(B->dir))+1;

    return B;
}

//Realiza rotação da arvore no caso Direita-Direita
no* avlTree::rotacionaDD(no *A){
    printf("CASO DD\n");
    no *B = A->dir;
    A->dir = B->esq;
    B->esq = A;

    //Atualizando alturas
    A->altura = max(getAltura(A->esq), getAltura(A->dir))+1;
    B->altura = max(getAltura(B->esq), getAltura(B->dir))+1;

    return B;
}

//Realiza rotação da arvore no caso Esquerda-Direita
no* avlTree::rotacionaED(no *A){
    printf("CASO ED\n");
    no* B = A->esq;
    no* C = B->dir;

    B->dir = C->esq;
    C->esq = B;
    A->esq = C->dir;
    C->dir = A;

    //Atualizando alturas
    C->altura = max(getAltura(A->esq), getAltura(A->dir))+1;
    B->altura = max(getAltura(B->esq), getAltura(B->dir))+1;

    return C;
}

//Realiza rotação da arvore no caso Direita-Esquerda
no* avlTree::rotacionaDE(no *A){
    printf("CASO DE\n");
    no* B = A->dir;
    no* C = B->esq;

    B->esq = C->dir;
    C->dir = B;
    A->dir = C->esq;
    C->esq = A;

    //Atualizando alturas
    C->altura = max(getAltura(A->esq), getAltura(A->dir))+1;
    B->altura = max(getAltura(B->esq), getAltura(B->dir))+1;

    return C;
}

//Calcula balanceamento de cada no
int avlTree::getBal(no *raiz){
    if(raiz == NULL)
        return 0;

    return(getAltura(raiz->esq) - getAltura(raiz->dir));
}

//Inserir privado
no *avlTree::inserir(no* raiz, string& a){
    if(raiz == NULL){
        raiz = new no;
        raiz->palavra = a;
        raiz->altura = 1;
        raiz->esq = raiz->dir = NULL;
    }

    if(a.compare(raiz->palavra) < 0){
        raiz->esq = inserir(raiz->esq, a);
    }

    else if(a.compare(raiz->palavra) > 0){
        raiz->dir = inserir(raiz->dir, a);
    }

    //fator de balanceamento
    int bal = getBal(raiz);

    //Caso Esquerda-Esquerda
    if(bal > 1 && (a.compare(raiz->dir->palavra) < 0)){
        return rotacionaEE(raiz);
    }

    //Caso Direita-Direita
    if(bal < -1 && (a.compare(raiz->dir->palavra) > 0)){
        return rotacionaDD(raiz);
    }

    //Caso Esquerda-Direita
    if(bal > 1 && (a.compare(raiz->esq->palavra) > 0)){
        return rotacionaED(raiz);
    }

    //Caso Direita-Esquerda
    if(bal < -1 && (a.compare(raiz->dir->palavra) < 0)){
        return rotacionaDE(raiz);
    }

    //Atualiza altura antes de retornar
    raiz->altura = 1 + max(getAltura(raiz->esq), getAltura(raiz->dir));
    return raiz;
}

//Busca privado
int avlTree::busca(no *raiz, string& a){
    no *temp = raiz;
    while(temp){
        if(a.compare(raiz->palavra) < 0)
            temp = temp->esq;
        else if(a.compare(raiz->palavra) > 0)
            temp = temp->dir;
        else //quando dado == t->item
            return 1;
    }
    return 0;
}

//Imprime a árvore em pre order
void avlTree::printPreOrder(no *raiz){
    if(raiz == NULL)
        return;

    cout << raiz->palavra << endl;
    printPreOrder(raiz->esq);
    printPreOrder(raiz->dir);
}

//Desaloca memoria da arvore
void avlTree::destruirAvl(no *raiz){
    if(raiz == NULL)
        return;

    destruirAvl(raiz->esq);
    destruirAvl(raiz->dir);

    delete(raiz);
}


stack<string> avlTree::inOrder(){
    no* temp = raiz;
    stack<string> s;
    stack<no*> percorre;

    percorre.push(temp);
    while(!percorre.empty()){
        temp = percorre.top();
        s.push(temp->palavra);
        percorre.pop();

        if(temp->esq){
            percorre.push(temp->esq);
        }if(temp->dir){
            percorre.push(temp->dir);
        }
    }
    return s;
}
