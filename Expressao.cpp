#include <string>
#include <cstring>
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

        void transicaoEstendida(string palavra){
            int tam = 0, y=0, cont=0;
            string q0, q1, q2, q3, q4, q5, q6, q7, w, estado = "qo";
            tam = palavra.length();
            for(int x = tam-1; x >= 0; x--){
                cont++;
                for(int y = 0; y < tam-cont; y++){
                    w += palavra[y];
                }
                if (w == "")
                    w = "&";
                cout << " PALAVRA: " << w << " | ÚLTIMO SÍMBOLO: " << palavra[x] << " x: " << x << endl;
                cout << "---------------------------------------------" << endl;
                w="";  
            }
            cout << endl;


            for(int x = 0; x <= tam; x++){
                if (x == 0){
                    cout << estado << ", ";
                    cout << palavra[x] << endl;
                    if(estado == "qo" && palavra == "a"){
                        cout << "---------------------------------------------" << endl;
                        estado = "q1";
                        cout << "RETORNO: " << estado << endl;
                    }
                    else{
                        if(estado == "qo" && palavra == "b"){
                            cout << "---------------------------------------------" << endl;
                            estado = "qo";
                            cout << "RETORNO: " << estado << endl;
                        }
                    }
                }
                
                else{
                    if (x == 1){
                        cout << estado << ", ";
                        cout << palavra[x] << endl;
                        if(estado == "q1" && palavra == "a"){
                            cout << "---------------------------------------------" << endl;
                            estado = "q2";
                            cout << "RETORNO: " << estado << endl;
                        }
                        else{
                            if(estado == "q1" && palavra == "b"){
                                cout << "---------------------------------------------" << endl;
                                estado = "q3";
                                cout << "RETORNO: " << estado << endl;
                            }
                        }
                    }

                    else{
                        /*if(x == 2){
                            cout << estado << ", ";
                            cout << palavra[x] << endl;
                        }*/
                    }
                }
            }

            cout << endl <<" ESTADO RETORNADO: " << estado << endl;
            if (estado == "q4" || estado == "q5" || estado == "q6" || estado == "q7")
                cout << " PALAVRA ACEITA PELA O AUTÔMATO!" << endl;
            else

                cout << " PALAVRA NÃO É ACEITA PELO O AUTÔMATO!" << endl;

            
            
        }

		/*-----------------------------FUNÇÃO DE TRNASIÇÃO ESTENDIDA DA LINGUAGEM --------------------------*/
		void funcaoTransicaoEstendida(string palavra){ // δ(q,w) = δ(δ(q,x),a)
            int tam = 0, y=0, cont=0;
            string w;
            tam = palavra.length();
            for(int x = tam-1; x >= 0; x--){
                cont++;
                for(int y = 0; y < tam-cont; y++){
                    w += palavra[y];
                }
                if (w == ""){
                    w = "&";
                }
                cout << " PALAVRA: " << w << " | ÚLTIMO SÍMBOLO: " << palavra[x] << endl;
                cout << "---------------------------------------------" << endl;
               w="";
            }
            cout << endl;

            string q0, q1, q2, q3, q4, q5, q6, q7, estado;
            if(estado == "q0" && palavra == "a"){
                estado = "q1";
            }else{
                if(estado == "q0"  && palavra == "b"){
                    estado = "q0";
                }else{
                    if(estado == "q1" && palavra == "a"){
                        estado = "q2";
                    }else{
                        if(estado == "q1" && palavra == "b"){
                            estado = "q3";
                        }else{
                            if(estado == "q2" && palavra == "a"){
                                estado = "q4";
                            }else{
                                if(estado == "q2" && palavra == "b"){
                                    estado = "q5";
                                }else{
                                    if(estado == "q3" && palavra == "a"){
                                        estado = "q6";
                                    }else{
                                        if(estado == "q3" && palavra == "b"){
                                            estado = "q7";
                                        }else{
                                            if(estado == "q4" && palavra == "a"){
                                                estado = "q4";
                                            }else{
                                                if(estado == "q4" && palavra == "b"){
                                                    estado = "q5";
                                                }else{
                                                    if(estado == "q5" && palavra == "a"){
                                                        estado = "q6";
                                                    }else{
                                                        if(estado == "q5" && palavra == "b"){
                                                            estado = "q7";
                                                        }else{
                                                            if(estado == "q6" && palavra == "a"){
                                                                estado = "q2";
                                                            }else{
                                                                if(estado == "q6" && palavra == "b"){
                                                                    estado = "q3";
                                                                }else{
                                                                    if(estado == "q7" && palavra == "a"){
                                                                        estado = "q1";
                                                                    }else{
                                                                        if(estado == "q7" && palavra == "b"){
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
                            }
                        }
                    }
                }
            }
            cout << endl <<" ESTADO RETORNADO: " << estado << endl;
            if (estado == "q4" || estado == "q5" || estado == "q6" || estado == "q7")
                cout << " PALAVRA ACEITA PELA O AUTÔMATO!" << endl;
            else
                cout << " PALAVRA NÃO É ACEITA PELO O AUTÔMATO!" << endl;
        };

};
