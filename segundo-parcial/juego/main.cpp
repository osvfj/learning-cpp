#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

    string palabra_adivinar;
    char abecedario[27];
    srand(time(0));

    for (int i = 0; i < 26; ++i) {
        abecedario[i] = 'a' + i;
    }

    abecedario[26] = ' ';

    cout << "Ingresa la palabra a adivinar: ";
    getline(cin, palabra_adivinar);

    bool bot_1_jugando = true; 
    bool fin_juego = false;

    char bot_1[palabra_adivinar.length()];
    char bot_2[palabra_adivinar.length()];

    char letra_generada;

    for (int i = 0; i < palabra_adivinar.length(); ++i) {
        bot_1[i] = '_';
        bot_2[i] = '_';
    }

    while(!fin_juego){
        letra_generada = abecedario[rand()  % 27];
        bool letra_encontrada = false;

        for(int i = 0; i < palabra_adivinar.length(); ++i){
            if(letra_generada == palabra_adivinar[i]){
                letra_encontrada = true;
                if(bot_1_jugando){
                    bot_1[i] = letra_generada;
                } else {
                    bot_2[i] = letra_generada;
                }
            }
        } 
    }

    return 0;
}