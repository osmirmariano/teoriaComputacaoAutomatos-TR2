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
        cout << " 1 -- AFD DA LINGUAGEM" << endl;
        cout << " 2 -- FUNCAO DE TRANSICAO ESTENDIDA" << endl;
        cout << " 0 -- SAIR " << endl;
        cout << "---------------------------------------------" << endl;
        cout << "OPCAO: ";
        cin >> op;
        cout << "---------------------------------------------" << endl << endl;

        switch(op){
            case 1:
                cout << endl << "---------------------------------------------" << endl;
                cout << "\t AFD DA LINGUAGEM " << endl;
                cout << "---------------------------------------------" << endl;
                exp->AFD();
                break;
            case 2:
                cout << endl << "---------------------------------------------" << endl;
                cout << "\t FUNCAO DE TRANSICAO ESTENDIDA" << endl;
                cout << "---------------------------------------------" << endl;
                cout << " PALAVRA: ";
                cin >> palavra;
                cout << "---------------------------------------------" << endl << endl;
                exp->transicaoEstendida(palavra);
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
