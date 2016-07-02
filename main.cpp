#include <iostream>
#include <istream>
#include "Expressao.cpp"

using namespace std;

int main(){
    int op, quantidade;
    string palavraInformada, estado, palavra;

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
        cout << " OPCAO: ";
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
                cin >> palavraInformada;  
                cout << "---------------------------------------------" << endl << endl;
                estado = "q0";
                if(exp->verificaPalavraPertence(palavraInformada) == 0){
                    estado = exp->funcaoTransicaoEstendida(estado, palavraInformada);
                    if (estado == "q4" || estado == "q5" || estado == "q6" || estado == "q7"){
                        cout << "---------------------------------------------" << endl;
                        cout << " PALAVRA ACEITA PELA O AUTÔMATO!" << endl;
                        cout << " \tESTADO " << estado << " É FINAL" << endl;
                        cout << "---------------------------------------------" << endl;
                    }
                    else{
                        cout << "---------------------------------------------" << endl;
                        cout << " PALAVRA NÃO É ACEITA PELO O AUTÔMATO!" << endl;
                        cout << "\tESTADO " << estado << " NÃO É FINAL" << endl;
                        cout << "---------------------------------------------" << endl;
                    }
                }
                else{
                    cout << " A PALAVRA NÃO PERTENCE AO ALFABETO {a,b}" << endl;
                }
                //exp->verificaPalavraPertence(palavraInformada);                
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
