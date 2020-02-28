#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#define MAX 50
using namespace std;
void main() {
    system("CHCP 1252");
    system("cls");
    unsigned int risposta, i, k, numberoftimes=0;
    char scelta;
    char criptato[MAX] = {}, chiaro[MAX] = {}, decriptato[MAX] = {}, ultimocriptato[MAX] = {}, ultimochiaro[MAX] = {}, riga[MAX] = {};
    ofstream save;
    ifstream read;
    bool exist = false;
    char alfabeto[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

    cout << "1. Inserire messaggio in chiaro:" << endl;
    cout << "2. Visualizza ultimo messaggio in chiaro:" << endl;
    cout << "3. Visualizza ultimo messaggio criptato:" << endl;
    cout << "4. Visualizza ultimo messaggio decriptato:" << endl;
    cout << "5. Termina" << endl << endl;
    cout << "SCEGLI UNA VOCE DAL MENU: ";

    cin >> risposta;

    switch (risposta) {
    case 1:
        cout << endl << "INSERISCI LA FRASE DA CODIFICARE: ";
        cin.ignore();
        cin.getline(chiaro, MAX);

        cout << "VUOI SALVARE IL MESSAGGIO IN CHIARO? (s/n) ";
        cin >> scelta;
        cin.ignore();
        if (scelta == 's') {
            save.open("chiaro.txt", ios::out);
            for (i = 0; i < strlen(chiaro); i++) {
                save << chiaro[i];
                numberoftimes++;
            }
            save.close();

            save.open("numberoftimes.txt", ios::out);
            save << numberoftimes;
            save.close();
        }
        for (i = 0; i < strlen(chiaro); i++) {  
            for (k = 0; k < 26; k++) {
                if (chiaro[i] == alfabeto[k]) {
                    if (alfabeto[k] == 'z') {
                        criptato[i] = 'c';
                        break;
                    }
                    else if (alfabeto[k] == 'y') {
                        criptato[i] = 'b';
                        break;
                    }
                    else if (alfabeto[k] == 'x') {
                        criptato[i] = 'a';
                        break;
                    }
                    else
                        criptato[i] = alfabeto[k] +3;
                }
            }
        }
        save.open("criptato.txt", ios::out);
        cout << "Sto scrivendo i dati nel file...." << endl;
        for (i = 0; i < strlen(criptato); i++)
            save << criptato[i];
        save.close();
        
        cout << "Vuoi visualizzare il messaggio criptato? (s/n) ";
        cin >> scelta;

        if (scelta == 's') {
            cout <<endl<< "Lettura del file..." << endl;
            read.open("criptato.txt", ios::in);
            for (i = 0; i < strlen(chiaro); i++) {
                read >> riga[i];
                cout << riga[i];
            }
            read.close();
        }

        cout <<endl<< "Vuoi salvare il messaggio criptato? (s/n) ";
        cin >> scelta;
        if (scelta == 's') {
            save.open("Ucriptato.txt", ios::out);
            cout << "Sto scrivendo i dati nel file...." << endl;
            for (i = 0; i < strlen(criptato); i++) {
                save << criptato[i];
                exist = true;
            }
            save.close();
            if (exist == true)
                cout << endl << "SALVATAGGIO EFFETTUATO CON SUCCESSO!!!" << endl;
        }
        break;
    case 2:
        read.open("numberoftimes.txt", ios::in);
        read >> numberoftimes;
        read.close();
        cout << endl << "Lettura del file..." << endl;
        read.open("chiaro.txt", ios::in);

        for (i = 0; i < numberoftimes; i++) {
            read >> riga[i];
            cout << riga[i];
        }
        read.close();
        break;
    case 3:
        read.open("numberoftimes.txt", ios::in);
        read >> numberoftimes;
        read.close();
        cout << endl << "Lettura del file..." << endl;
        read.open("ucriptato.txt", ios::in);
        for (i = 0; i < numberoftimes; i++) {
            read >> riga[i];
            cout << riga[i];
        }
        read.close();
        break;
    case 4:
        read.open("numberoftimes.txt", ios::in);
        read >> numberoftimes;
        read.close();
        cout << endl << "Lettura del file..." << endl;
        read.open("criptato.txt", ios::in);
        for (i = 0; i < numberoftimes; i++) 
            read >> riga[i];
        read.close();
        cout << endl << "LA PAROLA DECRIPTATA è: ";
        for (i = 0; i < strlen(riga); i++) {
            for (k = 0; k < 26; k++) {
                if (riga[i] == alfabeto[k]) {
                    if (alfabeto[k] == 'a') {
                        decriptato[i] = 'x';
                        break;
                    }
                    else if (alfabeto[k] == 'b') {
                        decriptato[i] = 'y';
                        break;
                    }
                    else if (alfabeto[k] == 'c') {
                        decriptato[i] = 'z';
                        break;
                    }
                    else
                        decriptato[i] = alfabeto[k] - 3;
                }
            }
            cout << decriptato[i];
        }
        break;
    case 5:
        exit(1);
    }
    exit(0);
}
