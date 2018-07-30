//Vinicius Brandao Crepschi   RA: 743601

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

    //cout << "inorder:" << endl;
    printInOrder(raiz);
}

void avlTree::mostrarPre(){
    if(vazia()) return;

    //cout << "preorder" << endl;
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

//Rotaciona para direita
no *avlTree::rotacionaSingleRight(no* A){
    //cout << "SingleRight" << endl;
    no *B = A->esq;
    A->esq = B->dir;
    B->dir = A;

    //Atualizando alturas
    A->altura = max(getAltura(A->esq), getAltura(A->dir))+1;
    B->altura = max(getAltura(B->esq), getAltura(A))+1;

    return B;
}

//Rotaciona para a esquerda
no* avlTree::rotacionaSingleLeft(no* A){
    //cout << "SingleLeft" << endl;
    no *B = A->dir;
    A->dir = B->esq;
    B->esq = A;

    //Atualizando alturas
    A->altura = max(getAltura(A->esq), getAltura(A->dir))+1;
    B->altura = max(getAltura(A->dir), getAltura(A))+1;

    return B;
}

//Rotaciona a sub arvore a esquerda e depois rotaciona para a direita
no* avlTree::rotacionaDoubleRight(no* A){
    A->esq = rotacionaSingleLeft(A->esq);
    return rotacionaSingleRight(A);
}

//Rotaciona a sub arvore a direita e depois rotaciona para a esquerda
no* avlTree::rotacionaDoubleLeft(no* A){
    A->dir = rotacionaSingleRight(A->dir);
    return rotacionaSingleLeft(A);
}

//Calcula balanceamento de cada no
int avlTree::getBal(no* raiz){
    if(raiz == NULL)
        return 0;

    return(getAltura(raiz->esq) - getAltura(raiz->dir));
}

//Inserir privado
no *avlTree::inserir(no* raiz, string &a){
    if(raiz == NULL){
        //cout << "novo no" << endl;
        raiz = new no;
        raiz->palavra = a;
        raiz->altura = 0;
        raiz->esq = NULL;
        raiz->dir = NULL;
    }

    else if(a.compare(raiz->palavra) < 0){
        //cout << "desceu esq" << endl;
        raiz->esq = inserir(raiz->esq, a);
    }

    else if(a.compare(raiz->palavra) > 0){
        //cout << "desceu dir" << endl;
        raiz->dir = inserir(raiz->dir, a);
    }

    //fator de balanceamento
    int bal = getBal(raiz);

    if(bal == 2){
        //Caso EE
        if(a.compare(raiz->esq->palavra) < 0)
            raiz = rotacionaSingleRight(raiz);
        //Caso ED
        else
            raiz = rotacionaDoubleRight(raiz);
    }

    else if(bal == -2){
        //Caso DD
        if(a.compare(raiz->dir->palavra) > 0)
            raiz = rotacionaSingleLeft(raiz);
        //Caso DE
        else
            raiz = rotacionaDoubleLeft(raiz);
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
void avlTree::printInOrder(no *raiz){
    if(raiz == NULL)
        return;

    printInOrder(raiz->esq);
    cout << raiz->palavra << endl;
    printInOrder(raiz->dir);
}

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
    raiz = NULL;
}

stack<string> avlTree::inOrder(){
    no* temp = raiz;
    stack<string> s;
    stack<no*> percorre;

    percorre.push(temp);
    while(!percorre.empty()){
        temp = percorre.top();
        s.push(temp->palavra);
        //cout << temp->palavra;
        percorre.pop();

        if(temp->esq){
            percorre.push(temp->esq);
        }if(temp->dir){
            percorre.push(temp->dir);
        }
    }
    return s;
}
