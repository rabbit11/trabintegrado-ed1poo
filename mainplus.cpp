//Vinicius Brandao Crepschi   RA: 743601
#include "avltree.h"
#include "palavra.h"
#include <iostream>
#include <string>

int main(){
    avlTree t;
    int b = 0;
    // string buffer;
    // ifstream arquivo("dic.txt");
    //
    // if(arquivo){
    //     while(getline(arquivo, buffer)){
    //         t.inserir(buffer);
    //     }
    // }

    for(int i = 0; i < 10; i++){
        string temp;
        Palavra a;
        cin >> temp;
        a.setWord(temp);
        t.inserir(a);
        cout << "Mostrar? ";
        cin >> b;
        if(b){
            t.mostrar();
            t.mostrarPre();
        }
    }

    t.mostrar();

    return 0;
}
