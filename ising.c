#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "ising.h"

int main(int argc, char* argv[]) {
	srand(time(NULL));
	
	char grid[LENGTH][LENGTH];
	
	int N = 100;
	for (int t = 0; t < N; t++) {

		// Initializes grid
		for (int i = 0; i < LENGTH; i++)
			for (int j = 0;j < LENGTH; j++)
				grid[i][j] = 1;

		float T =  4 * (float)t / N;
		monte_carlo(&grid[0][0], 100, T);
		printf("%f\t%f\n", T, magnetization(&grid[0][0]));
	}

	return 0;
}