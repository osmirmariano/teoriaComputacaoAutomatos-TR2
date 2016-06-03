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

    public:
		Expressao(){

		};

		~Expressao();

		/*--------------------------- AUTOMATO FINITO DETERMINÍSTICO DA LINGUAGEM ------------------------------*/
		void AFD(){

		};

		/*-----------------------------FUNÇÃO DE TRNASIÇÃO ESTENDIDA DA LINGUAGEM ------------------------------*/
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
};
