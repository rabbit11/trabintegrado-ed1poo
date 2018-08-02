#include "corretor.h"
#include <iostream>
#include <string>

int main(){
    Corretor corretor;
    int opc;
    string sory;
    cout << "CORRETOR ORTOGRÁFICO HERRAR EH UMANO v2.1" << endl;
    cout << "Iniciar correção do texto? y/n" << endl;
    cin >> sory;

    if(sory == "s"){
        corretor.verificarTexto();
        if(corretor.getErros()){
            cout << "Erros foram encontrados: " << endl;
            corretor.exibeErros();
            corretor.tratarErros();
        }
    }


    return 0;
}
