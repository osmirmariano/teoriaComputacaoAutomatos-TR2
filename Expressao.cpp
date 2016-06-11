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

        void transicaoEstendida(string palavra){
            int tam = 0;
            string q0, q1, q2, q3, q4, q5, q6, q7, estado="q0", w, k;
            tam = palavra.length();

            for(int x = 0; x <= tam; x++){
                cout << "PALAVRA: " << palavra[x] << endl;
                cout << "X: " << x << endl;

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
                                            else{
                                                if(palavra[x] == ' '){
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
                cout << endl << "ESTADO: " << estado << endl;
            }
            //
            if (estado == "q4" || estado == "q5" || estado == "q6" || estado == "q7"){
                cout << "---------------------------------------------" << endl;
                cout << " PALAVRA ACEITA PELA O AUTÔMATO!" << endl;
                cout << " \tESTADO " << estado << " É FINAL" << endl;
                cout << "---------------------------------------------" << endl;
            }else{
                cout << "---------------------------------------------" << endl;
                cout << " PALAVRA NÃO É ACEITA PELO O AUTÔMATO!" << endl;
                cout << "\tESTADO " << estado << " NÃO É FINAL" << endl;
                cout << "---------------------------------------------" << endl;
            }
        }

        /*-----------------------------FUNÇÃO DE TRNASIÇÃO ESTENDIDA DA LINGUAGEM --------------------------*/
        void funcaoTransicaoEstendida(string palavra){ // δ(q,w) = δ(δ(q,x),a)
            int tam = 0;
            string q0, q1, q2, q3, q4, q5, q6, q7, estado="q0", w, k;
            tam = palavra.length();
            /*cout << "TAM: " << tam << endl;
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
            cout << endl;*/
            cout << " -- (qo, &) = qo" << endl;
            for(int x = 0; x <= tam; x++){
                w += palavra[x];
                k += palavra[x-1];
                if(estado == "q0" && palavra[x] == 'a'){
                    cout << " -- (qo, " << palavra[x] << ") = "  << "((qo, &" << "), " << palavra[x] << ") = ";
                    cout << " (" << estado << ", " << palavra[x] << ") = ";
                    estado = "q1";
                    cout << estado << endl;
                    x = 0;

                }else{
                    if(estado == "q0"  && palavra[x] == 'b'){
                        cout << " -- (qo, " << w << ") = "  << "((qo, &), " << palavra[x] << ") = ";
                        //cout << "((qo, " << w << "), " << palavra[x] << ") = ";

                        cout << " (" << estado << ", " << palavra[x] << ") = ";
                        estado = "q0";
                        cout << estado << endl;
                    }else{
                        if(estado == "q1" && palavra[x] == 'a'){
                            cout << " -- (qo, " << w << ") = "  << "((qo, " << k << "), " << palavra[x] << ") = ";
                            //cout << "((qo, " << w << "), " << palavra[x] << ") = ";

                            cout << " (" << estado << ", " << palavra[x] << ") = ";
                            estado = "q2";
                            cout << estado << endl;
                        }else{
                            if(estado == "q1" && palavra[x] == 'b'){
                                cout << " -- (qo, " << w << ") = "  << "((qo, " << k << "), " << palavra[x] << ") = ";
                                //cout << "((qo, " << w << "), " << palavra[x] << ") = ";

                                cout << " (" << estado << ", " << palavra[x] << ") = ";
                                estado = "q3";
                                cout << estado << endl;
                            }else{
                                if(estado == "q2" && palavra[x] == 'a'){
                                    cout << " -- (qo, " << w << ") = "  << "((qo, " << k << "), " << palavra[x] << ") = ";
                                    //cout << "((qo, " << w << "), " << palavra[x] << ") = ";

                                    cout << " (" << estado << ", " << palavra[x] << ") = ";
                                    estado = "q4";
                                    cout << estado << endl;
                                }else{
                                    if(estado == "q2" && palavra[x] == 'b'){
                                        cout << " -- (qo, " << w << ") = "  << "((qo, " << k << "), " << palavra[x] << ") = ";
                                        //cout << "((qo, " << w << "), " << palavra[x] << ") = ";

                                        cout << " (" << estado << ", " << palavra[x] << ") = ";
                                        estado = "q5";
                                        cout << estado << endl;
                                    }else{
                                        if(estado == "q3" && palavra[x] == 'a'){
                                            cout << " -- (qo, " << w << ") = "  << "((qo, " << k << "), " << palavra[x] << ") = ";
                                            //cout << "((qo, " << w << "), " << palavra[x] << ") = ";

                                            cout << " (" << estado << ", " << palavra[x] << ") = ";
                                            estado = "q6";
                                            cout << estado << endl;
                                        }else{
                                            if(estado == "q3" && palavra[x] == 'b'){
                                                cout << " -- (qo, " << w << ") = "  << "((qo, " << k << "), " << palavra[x] << ") = ";
                                                //cout << "((qo, " << w << "), " << palavra[x] << ") = ";

                                                cout << " (" << estado << ", " << palavra[x] << ") = ";
                                                estado = "q7";
                                                cout << estado << endl;
                                            }else{
                                                if(estado == "q4" && palavra[x] == 'a'){
                                                    cout << " -- (qo, " << w << ") = "  << "((qo, " << k << "), " << palavra[x] << ") = ";
                                                    //cout << "((qo, " << w << "), " << palavra[x] << ") = ";

                                                    cout << " (" << estado << ", " << palavra[x] << ") = ";
                                                    estado = "q4";
                                                    cout << estado << endl;
                                                }else{
                                                    if(estado == "q4" && palavra[x] == 'b'){
                                                        cout << " -- (qo, " << w << ") = "  << "((qo, " << k << "), " << palavra[x] << ") = ";
                                                        //cout << "((qo, " << w << "), " << palavra[x] << ") = ";

                                                        cout << " (" << estado << ", " << palavra[x] << ") = ";
                                                        estado = "q5";
                                                        cout << estado << endl;
                                                    }else{
                                                        if(estado == "q5" && palavra[x] == 'a'){
                                                            cout << " -- (qo, " << w << ") = "  << "((qo, " << k << "), " << palavra[x] << ") = ";
                                                            //cout << "((qo, " << w << "), " << palavra[x] << ") = ";

                                                            cout << " (" << estado << ", " << palavra[x] << ") = ";
                                                            estado = "q6";
                                                            cout << estado << endl;
                                                        }else{
                                                            if(estado == "q5" && palavra[x] == 'b'){
                                                                cout << " -- (qo, " << w << ") = "  << "((qo, " << k << "), " << palavra[x] << ") = ";
                                                                //cout << "((qo, " << w << "), " << palavra[x] << ") = ";

                                                                cout << " (" << estado << ", " << palavra[x] << ") = ";
                                                                estado = "q7";
                                                                cout << estado << endl;
                                                            }else{
                                                                if(estado == "q6" && palavra[x] == 'a'){
                                                                    cout << " -- (qo, " << w << ") = "  << "((qo, " << k << "), " << palavra[x] << ") = ";
                                                                    //cout << "((qo, " << w << "), " << palavra[x] << ") = ";

                                                                    cout << " (" << estado << ", " << palavra[x] << ") = ";
                                                                    estado = "q2";
                                                                    cout << estado << endl;
                                                                }else{
                                                                    if(estado == "q6" && palavra[x] == 'b'){
                                                                        cout << " -- (qo, " << w << ") = "  << "((qo, " << k << "), " << palavra[x] << ") = ";
                                                                        //cout << "((qo, " << w << "), " << palavra[x] << ") = ";

                                                                        cout << " (" << estado << ", " << palavra[x] << ") = ";
                                                                        estado = "q3";
                                                                        cout << estado << endl;
                                                                    }else{
                                                                        if(estado == "q7" && palavra[x] == 'a'){
                                                                            cout << " -- (qo, " << w << ") = "  << "((qo, " << k << "), " << palavra[x] << ") = ";
                                                                            //cout << "((qo, " << w << "), " << palavra[x] << ") = ";

                                                                            cout << " (" << estado << ", " << palavra[x] << ") = ";
                                                                            estado = "q1";
                                                                            cout << estado << endl;
                                                                        }else{
                                                                            if(estado == "q7" && palavra[x] == 'b'){
                                                                                cout << " -- (qo, " << w << ") = "  << "((qo, " << k << "), " << palavra[x] << ") = ";
                                                                                //cout << "((qo, " << w << "), " << palavra[x] << ") = ";

                                                                                cout << " (" << estado << ", " << palavra[x] << ") = ";
                                                                                estado = "q0";
                                                                                cout << estado << endl;
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
            }
            if (estado == "q4" || estado == "q5" || estado == "q6" || estado == "q7"){
                cout << "---------------------------------------------" << endl;
                cout << " PALAVRA ACEITA PELA O AUTÔMATO!" << endl;
                cout << " \tESTADO " << estado << " É FINAL" << endl;
                cout << "---------------------------------------------" << endl;
            }else{
                cout << "---------------------------------------------" << endl;
                cout << " PALAVRA NÃO É ACEITA PELO O AUTÔMATO!" << endl;
                cout << "\tESTADO " << estado << " NÃO É FINAL" << endl;
                cout << "---------------------------------------------" << endl;
            }
        };

};