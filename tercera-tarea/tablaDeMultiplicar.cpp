#include <iostream>

int main(){

	// Este primer loop indica el número 'base' -> 2x, 3x, 4x, etc.
	for(int i = 2; i <= 9; i++){
		/* Para crear una línea divisora al momento de pasar
		 * al siguiente número 'base' */
		std::cout << "-----------" << std::endl;
		// Este loop indica la segunda parte -> 2x1, 3x2, 4x3, etc.
		for(int j = 1; j<= 10; j++){
			int multiplication = i*j;
			printf("%dx%d=%d\n", i, j, multiplication);	
		}
	}

	return 0;
}
