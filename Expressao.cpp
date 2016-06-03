#include <string>
#include <iostream>
#include <ctype.h>
#include <cstdlib>
#include <vector>

using namespace std;

class Expressao{
	public:
		int cont;
		vector<string> alfabetos;
        vector<char> alfa;
        //vector<char> palavra;

    public:
		Expressao(){

		};

		~Expressao();

		/*--------------------------- AUTOMATO FINITO DETERMINÍSTICO DA LINGUAGEM -------------------------*/
		void AFD(){
            cout << " FUNÇÃO TRNASIÇÃO  |     a     |     b     " << endl;
            cout << "---------------------------------------------" << endl;
            cout << "      ->qo         |     q1    |     qo     " << endl;
            cout << "---------------------------------------------" << endl;
            cout << "        q1         |     q2    |     q3     " << endl;
            cout << "---------------------------------------------" << endl;
            cout << "        q2         |     q4    |     q5     " << endl;
            cout << "---------------------------------------------" << endl;
            cout << "        q3         |     q6    |     q7     " << endl;
            cout << "---------------------------------------------" << endl;
            cout << "       *q4         |     q4    |     q5     " << endl;
            cout << "---------------------------------------------" << endl;
            cout << "       *q5         |     q6    |     q7     " << endl;
            cout << "---------------------------------------------" << endl;
            cout << "       *q6         |     q2    |     q3     " << endl;
            cout << "---------------------------------------------" << endl;
            cout << "       *q7         |     q1    |     qo     " << endl;
            cout << "---------------------------------------------" << endl << endl;
		};

        void AFD(string palavra){
            
        };

        /*-----------------------------FUNÇÃO QUE VERIFICA SE PERTENCE AO AFD------------------------------*/
        void verifPertenceAFD (string palavra){
            int tamanho = 0;
            tamanho = palavra.length();
            /*for(){
                if(palac)
            }

            if(palavra[tamanho-1] == q4 || palavra[tamanho-1] == q5 || palavra[tamanho-1] == q6 || palavra[tamanho-1] == q7)
                cout << " PALAVRA ACEITA PELO AFD" << endl;
            else
                cout << " PALAVRA NÃO ACEITA PELO AFD" << endl;*/
            
        }

		/*-----------------------------FUNÇÃO DE TRNASIÇÃO ESTENDIDA DA LINGUAGEM --------------------------*/
		void funcaoTransicaoEstendida(string palavra){ // δ(q,w) = δ(δ(q,x),a)
            int tam = 0, y=0;
            string w;
            tam = palavra.length();

            for(int x = 0; x < tam-1; x++){
               // for(int y = 0; y < tam; y++){
                    w += palavra[x];
               // }
                cout << " Subpalavra: " << w << endl;
                //w="";
            }
        };

        void naoSeiAinda(){
            int quantidade;
            string estados, armazena, alfabeto;

            cout << " INFORME O ALFABETO: ";
            cin >> alfabeto;
            cout  << endl;
            cout << " INFORME A QUANTIDADE DE ESTADOS: ";
            cin >> quantidade;
            for (int x = 0; x < quantidade; x++){
                cout << " " << x+1 << "º ESTADO: ";
                cin >> estados;
                armazena += estados;                    
            }
            cout << endl << " ESTADOS: " << armazena << endl;
            cout << " ALFABETO: " << alfabeto << endl;
            int valor = armazena.length();
            cout << " TAMANHO: " << valor;
            for (int x = 0; x < valor-1; x++){

            }
        }
        
};
