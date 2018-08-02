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

    // string plv1 = "the";
    // string plv2 = "of";   //Testando insercao manual
    // // scanf("%s", plv2); //ad
    // string plv3 = "to";
    // // scanf("%s", plv3); //eb
    // string plv4 = "and";
    // string plv5 = "a";
    // // string plv6 = "hêin";
    // // string plv7 = "são";
    // //
    // t.inserir(plv1);
    // t.inserir(plv2);
    // t.inserir(plv3);
    // t.inserir(plv4);
    // t.inserir(plv5);
    // t.inserir(plv6);
    // t.inserir(plv7);

    t.mostrar();

    return 0;
}
