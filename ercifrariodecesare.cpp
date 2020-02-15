#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main(){
    int risposta;
    bool avanti=true;
    string chiaro="",ultimochiaro="",criptato="",ultimocriptato="",decriptato="",ultimodecriptato="";
    do{
    cout<<"1 Inserire messaggio in chiaro:"<<endl;
    cout<<"2 Visualizza ultimo messaggio in chiaro:"<<endl;
    cout<<"3 Visualizza ultimo messaggio criptato:"<<endl;
    cout<<"4 Visualizza ultimo messaggio decriptato:"<<endl;
    cout<<"5 Termina"<<endl;
    cin>>risposta;

        switch(risposta){

                case 1:

                    break;
                case 2:
                    if(ultimochiaro.empty()==true){
                        cout<<"Non è ancora stato inserito un messaggio"<<endl;

                    }
                    else{

                    }

                    break;
                case 3:

                    break;
                case 4:

                    break;
                case 5:

                    avanti=false;
                    break;
            }
    }while(avanti==true);
}
