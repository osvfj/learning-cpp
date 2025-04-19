#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

    string palabra_adivinar;
    char abecedario[26];
    srand(time(0));

    for (int i = 0; i < 26; ++i) {
        abecedario[i] = 'a' + i;
    }

    cout << "Ingresa la palabra a adivinar: ";
    getline(cin, palabra_adivinar);

    char bot_1[palabra_adivinar.length()];
    char bot_2[palabra_adivinar.length()];

    char letra_generada;

    for (int i = 0; i < palabra_adivinar.length(); ++i) {
        bot_1[i] = '_';
    }


    int j = 0;
    while(j < 1000){
        letra_generada = abecedario[rand()  % 26];
        for(int i = 0; i < palabra_adivinar.length(); ++i){
            if(letra_generada == palabra_adivinar[i]){
                bot_1[i] = letra_generada;
                cout << letra_generada << endl;
            }
        } 
        j++;
    }

    cout << "---------------------------" << endl;

    for(int i = 0; i < palabra_adivinar.length(); ++i){
        cout << bot_1[i];
    }
    cout << endl;
    return 0;
}