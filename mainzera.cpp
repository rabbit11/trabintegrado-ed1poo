#include "corretor.h"
#include <iostream>
#include <string>

int main(){
    Corretor corretor;
    string sory;
    string name;
    cout << "7777777777777777777777777777777777777777777777777" << endl;
    cout << "77 -CORRETOR ORTOGRAFICO HERRAR EH UMANO v2.1- 77" << endl;
    cout << "7777777777777777777777777777777777777777777777777" << endl;
    cout << endl;
    cout << "Digite o nome do arquivo a ser corrigido" << endl;
    cin >> name;
    corretor.carregarTexto(name);
    cout << "Iniciar correcao do texto? (y/n)" << endl;
    cin >> sory;

    if(sory == "y"){
        corretor.verificarTexto();  //Inicializa lista de erros
        if(corretor.getErros()){    //Verifica se existem erros
            cout << "Erros foram encontrados nas seguintes palavras: " << endl;
            corretor.exibeErros();  //Imprime lista de erros
            int opc;
            string nova;
            while(!corretor.errosFim()){ //Retorna 0 se chega ao fim da lista de erros
                opc = 0;
                cout << "Erro: " << corretor.erroAtual() << endl; //Retorna a Palavra erro atual da lista
                cout << "Contexto: ";
                corretor.mostrarContexto(corretor.erroAtual()); //Imprime palavra antes e depois do erro
                cout << "1- Adicionar ao dicionario como excecao" << endl;
                cout << "2- Listar sugestoes do dicionario" << endl;
                cout << "3- Corrigir manualmente" << endl;
                cout << "4- Ignorar erro" << endl;
                cin >> opc;

                switch (opc) {
                    case 1:
                        corretor.adicionarEx(corretor.erroAtual());  //Adiciona palavra ao dicionario
                        cout << "Palavra adicionada ao dicionario." << endl;
                        break;

                    case 2:
                        corretor.mostrarSemelhantes(corretor.erroAtual()); //Exibe lista de sugestoes
                        cout << "Selecione sugestao: " << endl;
                        cin >> opc;
                        corretor.corrigirSemelhante(corretor.erroAtual(), opc); //Corrige palavra usando sugestao

                        break;

                    case 3:
                        cin >> nova;
                        corretor.corrigirPalavra(nova, corretor.erroAtual()); //Corrige palavra usando string inserida
                        break;

                    case 4:
                        break;
                }
                corretor.errosProx();  //Itera pela lista de erros
            }
        }
    }
    string n;
    cout << "Digite o nome do arquivo a ser exportado" << endl;
    cin >> n;
    corretor.salvarTexto(n); //Exporta arquivo de texto corrigido
    cout << "Arquivo corrigido exportado. Bye!" << endl;
    return 0;
}
