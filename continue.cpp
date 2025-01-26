#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            continue; // Saltamos los números pares
        }
	cout << i << "\n";
    }
    return 0;
}
