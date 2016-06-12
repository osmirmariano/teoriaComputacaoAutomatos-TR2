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

    public:
        Expressao(){
            this->pertence = 0;
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

        /*-----------------------------FUNÇÃO DE TRNASIÇÃO ESTENDIDA DA LINGUAGEM --------------------------*/
        void funcaoTransicaoEstendida(string palavra){
            int tam = 0;
            string q0, q1, q2, q3, q4, q5, q6, q7, estado="q0";
            tam = palavra.length();

            for(int x = 0; x < tam; x++){
                if(palavra[x] != 'a' && palavra[x] != 'b'){
                    pertence = 1;
                }
                else{
                    if(estado == "q0"){
                        if(palavra[x] == 'a'){
                            estado = "q1";
                        }
                        else{
                            if(palavra[x] == 'b')
                                estado == "q0";
                        }
                    }
                    else{
                        if (estado == "q1"){
                            if(palavra[x] == 'a'){
                                estado = "q2";
                            }
                            else if(palavra[x] == 'b'){
                                estado = "q3";
                            }
                        }
                        else{
                            if(estado == "q2"){
                                if(palavra[x] == 'a'){
                                    estado = "q4";
                                }
                                else if(palavra[x] == 'b'){
                                    estado = "q5";
                                }
                            }
                            else{
                                if (estado == "q3"){
                                    if(palavra[x] == 'a'){
                                        estado = "q6";
                                    }
                                    else if(palavra[x] == 'b'){
                                        estado = "q7";
                                    }
                                }
                                else{
                                    if (estado == "q4"){
                                        if(palavra[x] == 'a'){
                                            estado = "q4";
                                        }
                                        else if(palavra[x] == 'b'){
                                            estado = "q5";
                                        }
                                    }
                                    else{
                                        if (estado == "q5"){
                                            if(palavra[x] == 'a'){
                                                estado = "q6";
                                            }
                                            else if(palavra[x] == 'b'){
                                                estado = "q7";
                                            }
                                        }
                                        else{
                                            if (estado == "q6"){
                                                if(palavra[x] == 'a'){
                                                    estado = "q2";
                                                }
                                                else if(palavra[x] == 'b'){
                                                    estado = "q3";
                                                }
                                            }
                                            else{
                                                if (estado == "q7"){
                                                    if(palavra[x] == 'a'){
                                                        estado = "q1";
                                                    }
                                                    else if(palavra[x] == 'b'){
                                                        estado = "q0";
                                                    }
                                                }
                                            } 
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            
            if(pertence == 0){
                cout << endl << " ESTADO RETORNADO: " << estado << endl;
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
                cout << " A PALAVRA NÃO PERTENCE AO ALFABETO" << endl;
            }
            
        };     
};