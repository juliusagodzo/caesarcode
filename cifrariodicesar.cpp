// cifrariodicesar.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
/*Svetonio narra che Giulio Cesare adottava un codice crittografico per comunicare con il proprio
esercito durante la campagna di Gallia. Il messaggio in chiaro era costituito da un testo in latino. Il
messaggio cifrato si otteneva dal messaggio in chiaro traslando ciascuna lettera in avanti di tre
caratteri lungo l’alfabeto. Ad esempio, la A diveniva D, la B diveniva E, e così via. (Arrivati alla
fine dell’alfabeto, si ricominciava da capo, come nell’addizione modulo 3.)
Scrivi un programma che implementi una variante ammodernata dell’algoritmo di Giulio Cesare.
L’utente ha la possibilità di scegliere fra quattro opzioni contenute in un menu, come segue.


• Inserisci messaggio in chiaro. L’utente inserisce un messaggio che deve essere costituito da
una stringa formata usando l’alfabeto inglese

• Visualizza messaggio in chiaro. Il programma visualizza l’ultimo messaggio in chiaro
inserito dall’utente. Se non è stato ancora inserito alcun messaggio, il programma avvisa
l’utente e prosegue ripresentando il menu.

• Visualizza messaggio cifrato. Il programma visualizza l’ultimo messaggio inserito
dall’utente, cifrato usando uno shift di n caratteri. Se non è stato ancora inserito alcun
messaggio in chiaro, il programma avvisa l’utente e prosegue ripresentando il menu.

• Visualizza messaggio decifrato. Il programma visualizza la decrittazione dell’ultimo
messaggio cifrato. Se non è stato ancora cifrato alcun messaggio, il programma avvisa
l’utente e prosegue ripresentando il menu. Termina. Esce dal programma.

Nota che se l’utente inserisce un nuovo messaggio in chiaro, l’ultimo messaggio in chiaro inserito
va perduto.
Nota
Nell’esercizio, se l’utente chiede due volte di seguito la visualizzazione del messaggio cifrato dopo
aver inserito un messaggio in chiaro, quante volte calcoli la cifratura del messaggio? Se la risposta è
due, modifica il programma in modo che la cifratura di ciascun messaggio in chiaro avvenga al più
una volta. Analogamente deve avvenire per la decifratura del messaggio.*/

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

// Per eseguire il programma: CTRL+F5 oppure Debug > Avvia senza eseguire debug
// Per eseguire il debug del programma: F5 oppure Debug > Avvia debug

// Suggerimenti per iniziare: 
//   1. Usare la finestra Esplora soluzioni per aggiungere/gestire i file
//   2. Usare la finestra Team Explorer per connettersi al controllo del codice sorgente
//   3. Usare la finestra di output per visualizzare l'output di compilazione e altri messaggi
//   4. Usare la finestra Elenco errori per visualizzare gli errori
//   5. Passare a Progetto > Aggiungi nuovo elemento per creare nuovi file di codice oppure a Progetto > Aggiungi elemento esistente per aggiungere file di codice esistenti al progetto
//   6. Per aprire di nuovo questo progetto in futuro, passare a File > Apri > Progetto e selezionare il file con estensione sln
