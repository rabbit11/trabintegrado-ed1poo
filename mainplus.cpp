//Vinicius Brandao Crepschi   RA: 743601
#include "dicionario.h"
#include "corretor.h"
#include "texto.h"
#include "avltree.h"
#include "palavra.h"
#include <iostream>
#include <string>

int main(){
    Dicionario d;
    Palavra a("ab");

    d.buscaSemelhantes(a);
    d.printSemelhantes();

    return 0;
}
