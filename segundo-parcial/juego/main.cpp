#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <iomanip>

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
            if(letra_generada == tolower(palabra_adivinar[i])){
                letra_encontrada = true;
                if(bot_1_jugando){
                    bot_1[i] = letra_generada;
                } else {
                    bot_2[i] = letra_generada;
                }
            }
        } 

        if (letra_encontrada) {
            cout << "Bot " << (bot_1_jugando ? "1" : "2") << ": " << letra_generada << endl;
            cout << "Presiona Enter..." << endl;
            cin.get();
            bot_1_jugando = !bot_1_jugando; 
        }

        bool bot1_gano = true;
        bool bot2_gano = true;
        for (int i = 0; i < palabra_adivinar.length(); ++i) {
            if (bot_1[i] != tolower(palabra_adivinar[i])) {
                bot1_gano = false;
            }
            if (bot_2[i] != tolower(palabra_adivinar[i])) {
                bot2_gano = false;
            }
        }


        cout << string(50, '\n');

        cout << "+--------------+--------------+" << endl;
        cout << "| Bot 1        | Bot 2        |" << endl;
        cout << "+--------------+--------------+" << endl;
        for (int i = 0; i < palabra_adivinar.length(); ++i) {
            cout << "| " << std::setw(12) << bot_1[i] << " | " << std::setw(12) << bot_2[i] << " |" << endl;
        }
        cout << "+--------------+--------------+" << endl;


        if (bot1_gano || bot2_gano) {
            fin_juego = true;
            if (bot1_gano && bot2_gano) {
                cout << "¡Empate! Ambos bots ganaron." << endl;
            } else if (bot1_gano) {
                cout << "¡Bot 1 ha adivinado la palabra y gana!" << endl;
            } else {
                cout << "¡Bot 2 ha adivinado la palabra y gana!" << endl;
            }
        }

    }

    return 0;
}