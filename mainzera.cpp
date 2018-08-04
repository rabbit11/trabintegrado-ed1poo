#include "corretor.h"
#include <iostream>
#include <string>

int main(){
    Corretor corretor;
    string sory;
    cout << "CORRETOR ORTOGRAFICO HERRAR EH UMANO v2.1" << endl;
    cout << "Iniciar correcao do texto? y/n" << endl;
    cin >> sory;

    if(sory == "y"){
        corretor.verificarTexto();
        if(corretor.getErros()){
            cout << "Erros foram encontrados nas seguintes palavras: " << endl;
            corretor.exibeErros();
            int opc;
            string nova;
            while(!corretor.errosFim()){
                opc = 0;
                cout << "Erro: " << corretor.erroAtual().getWord() << endl;
                cout << "1- Adicionar ao dicionario como exceçao" << endl;
                cout << "2- Listar sugestoes do dicionario" << endl;
                cout << "3- Corrigir manualmente" << endl;
                cout << "4- Ignorar erro" << endl;
                cin >> opc;

                switch (opc) {
                    case 1:
                        corretor.adicionarEx(corretor.erroAtual());
                        cout << "Palavra adicionada ao dicionário." << endl;
                        break;

                    case 2:
                        corretor.mostrarSemelhantes(corretor.erroAtual());
                        cout << "Selecione sugestao: " << endl;
                        cin >> opc;
                        corretor.corrigirSemelhante(corretor.erroAtual(), opc);

                        break;

                    case 3:
                        cin >> nova;
                        corretor.corrigirPalavra(nova, corretor.erroAtual());
                        break;

                    case 4:
                        break;
                }
                corretor.errosProx();
            }
        }
    }

    corretor.salvarTexto();
    cout << "Arquivo corrigido exportado. Bye!" << endl;
    return 0;
}
