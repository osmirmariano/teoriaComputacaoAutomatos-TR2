#include <iostream>
#include <istream>
#include "Expressao.cpp"

using namespace std;

int main(){
    int op;
    string expressao = "(a+b)*a(a+b)(a+b)", palavra;

    cout << endl << "----------------- V. 1.0.0 ------------------  " << endl;
    Expressao *exp = new Expressao();
    do{
        cout << endl << "---------------------------------------------" << endl;
        cout << "\t MENU PRINCIPAL" << endl;
        cout << "---------------------------------------------" << endl;
        cout << " 1 -- LINGUAGEM REGULAR" << endl;
        cout << " 2 -- AFD DA LINGUAGEM" << endl;
        cout << " 3 -- FUNCAO DE TRANSICAO ESTENDIDA POR INDUCAO" << endl;
        cout << " 0 -- SAIR " << endl;
        cout << "---------------------------------------------" << endl;
        cout << "OPCAO: ";
        cin >> op;
        cout << "---------------------------------------------" << endl << endl;
        system("cls");

        switch(op){
            case 1:{
                cout << endl << "---------------------------------------------" << endl;
                cout << "\t LINGUAGEM REGULAR" << endl;
                cout << "---------------------------------------------" << endl;
                cout << " " << expressao << endl;
                break;
            }
            case 2:
                cout << endl << "---------------------------------------------" << endl;
                cout << "\t AFD DA LINGUAGEM " << endl;
                cout << "---------------------------------------------" << endl;
                cout << " Projetar AFD no programa ou em PDF." << endl;
                break;
            case 3:
                cout << endl << "---------------------------------------------" << endl;
                cout << "\t FUNCAO DE TRANSICAO ESTENDIDA POR INDUCAO" << endl;
                cout << "---------------------------------------------" << endl;
                cout << " Mostrar  funcao de transicao estendida por inducao sobre o comprimento da palavra de entrada, ateh chegar a base" << endl;
                cout << " Palavra: ";
                cin >> palavra;
                //verificar se palavra é aceita pelo autômato e dps mostrar a função de transição estendida
                    //verificar se último elemento da palavra fica no estado final
                        // se palavra for aceita retornar estado final
                exp->funcaoTransicaoEstendida(palavra);
                break;
            case 0:
                cout << "PROGRAMA ENCERRADO COM SUCESSO!" << endl;
                break;
            default:
                cout << "\tOPÇÃO INVÁLIDA. POR FAVOR, INFORME UMA VÁLIDA" << endl;
        };

    }while(op != 0);
    return 0;
};

