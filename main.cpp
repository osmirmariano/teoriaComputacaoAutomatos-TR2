#include <iostream>
#include <istream>
#include "Expressao.cpp"

using namespace std;

int main(){
    int op, quantidade;
    string palavra;

    Expressao *exp = new Expressao();
   
    do{
        cout << endl << "---------------------------------------------" << endl;
        cout << "\t MENU PRINCIPAL" << endl;
        cout << "---------------------------------------------" << endl;
        cout << " EXPRESSÃO REGULAR DEFINIDA: (a+b)*a(a+b)(a+b)" << endl;
        cout << "---------------------------------------------" << endl;
        cout << " 1 -- INSERÇÃO DE PALAVRA" << endl;
        cout << " 2 -- AFD DA LINGUAGEM" << endl;
        cout << " 3 -- FUNCAO DE TRANSICAO ESTENDIDA" << endl;
        cout << " 4 -- INSERÇÃO DOS ESTADOS" << endl;
        cout << " 0 -- SAIR " << endl;
        cout << "---------------------------------------------" << endl;
        cout << "OPCAO: ";
        cin >> op;
        cout << "---------------------------------------------" << endl << endl;

        switch(op){
            case 1:{
                cout << endl << "---------------------------------------------" << endl;
                cout << "\t INSERÇÃO DE PALAVRAS" << endl;
                cout << "---------------------------------------------" << endl;
                cout << " PALAVRA: ";
                cin >> palavra;
                exp->verifPertenceAFD(palavra);
                break;
            }
            case 2:
                cout << endl << "---------------------------------------------" << endl;
                cout << "\t AFD DA LINGUAGEM " << endl;
                cout << "---------------------------------------------" << endl;
                exp->AFD();
                break;
            case 3:
                cout << endl << "---------------------------------------------" << endl;
                cout << "\t FUNCAO DE TRANSICAO ESTENDIDA" << endl;
                cout << "---------------------------------------------" << endl;
                cout << " Mostrar  funcao de transicao estendida por inducao sobre o comprimento da palavra de entrada, ateh chegar a base" << endl;
                cout << " Palavra: ";
                cin >> palavra;
                //verificar se palavra é aceita pelo autômato e dps mostrar a função de transição estendida
                    //verificar se último elemento da palavra fica no estado final
                        // se palavra for aceita retornar estado final
                exp->funcaoTransicaoEstendida(palavra);
                break;
            case 4:
                cout << endl << "---------------------------------------------" << endl;
                cout << "\t INSERÇÃO DOS ESTADOS" << endl;
                cout << "---------------------------------------------" << endl;
                exp->naoSeiAinda();
                //cout << "ESTADOS: " << armazena << endl;
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

