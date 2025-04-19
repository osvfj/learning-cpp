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

    int random = rand()  % 27;

    cout << abecedario[random] << endl;
    return 0;
}