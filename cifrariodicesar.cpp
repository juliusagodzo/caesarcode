#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <string>

#define MAX 50

using namespace std;

int main(){
    system("CHCP 1252");
    system("cls");
	bool exist = false;
    fstream f1;
    f1.open("criptato.txt", ios::out);
    char decode[MAX], coded[MAX];
    cout << "INSERISCI LA FRASE DA CODIFICARE: ";
    cin.getline(decode, MAX);

    for (unsigned int i = 0; i < strlen(decode); i++)
        f1 << decode[i];
    f1.close();

    f1.open("criptato.txt", ios::in);
    cout << "Lettura del file..." << endl;
    
    for (unsigned int i = 0; i < strlen(decode); i++){
        f1 >> coded[i];
        cout << coded[i];
    }
    
    f1.close();

    return 0;
}
