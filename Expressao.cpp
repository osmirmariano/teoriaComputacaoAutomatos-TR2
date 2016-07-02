#include <string>
#include <cstring>
#include <iostream>
#include <ctype.h>
#include <cstdlib>
#include <vector>

using namespace std;

class Expressao{
    public:
        int pertence;
        string palavra;

    public:
        Expressao(){
            this->pertence = 0;
            this->palavra = palavra;
        };

        ~Expressao();

        /*--------------------------- AUTOMATO FINITO DETERMINÍSTICO DA LINGUAGEM -------------------------*/
        void AFD(){
            cout << " FUNÇÃO TRANSIÇÃO  |     a     |     b     " << endl;
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

        //FUNÇÃO DE TRANSIÇÃO
        string funcaoTransicao(string estado, char simbolo){
            if (estado == "q0"){                
                if(simbolo == 'a'){
                    return "q1";
                }
                else
                    return "q0";
            }
            else if (estado == "q1"){          
                if(simbolo == 'a')
                    return "q2";
                else
                    return "q3";
            }
            else if (estado == "q2"){           
                if(simbolo == 'a')
                    return "q4";
                else
                    return "q5";
            }
            else if (estado == "q3"){          
                if(simbolo == 'a')
                    return "q6";
                else
                    return "q7";
            }
            else if (estado == "q4"){      
                if(simbolo == 'a')
                    return "q4";
                else
                    return "q5";
            }
            else if (estado == "q5"){        
                if(simbolo == 'a')
                    return "q6";
                else
                    return "q7";
            }
            else if (estado == "q6"){           
                if(simbolo == 'a')
                    return "q2";
                else
                    return "q3";
            }
            else if (estado == "q7"){           
                if(simbolo == 'a')
                    return "q1";
                else
                    return "q0";
            }
        };

        /*-------------------------FUNÇÃO DE TRNASIÇÃO ESTENDIDA DA LINGUAGEM ------------------*/
        string funcaoTransicaoEstendida(string estado, string palavra){
            string resto = "&";
            char simbolo;
            int tamanho = 0;
            tamanho = palavra.length();
            simbolo = palavra[tamanho-1];

            //FUNÇÃO DE TRANSIÇÃO - BASE
            if(palavra == "&")
                return estado;

            //FUNÇÃO DE TRANSIÇÃO ESTENDIDA
            for(int x = 0; x < tamanho-2; x++){
                resto = resto + "&";
            }
            
            for(int x = 0; x < tamanho-1; x++){
                resto[x] = palavra[x];
            }

            estado = funcaoTransicao(funcaoTransicaoEstendida(estado, resto), simbolo);
            return estado;            
        };     

        //FUNÇÃO PARA VERIFICAR SE A ṔALAVRA PERTENCE AO AUTOMATO E AO ALFABETO
        int verificaPalavraPertence(string palavraInformada){
            int tamanho =  palavraInformada.length();
            int pertence = 0;
            for(int x = 0; x < tamanho; x++){
                if(palavraInformada[x] != 'a' && palavraInformada[x] != 'b'){
                    return 1;
                }
            }
            return 0;
            
        };
};