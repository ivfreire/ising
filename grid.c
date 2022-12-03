#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "ising.h"

int main(int argc, char* argv[]) {
	srand(time(NULL));

	double T = atof(argv[1]);
	int N = atoi(argv[2]);
	
	char grid[LENGTH][LENGTH];
	
	for (int i = 0; i < LENGTH; i++)
		for (int j = 0;j < LENGTH; j++) {
			if ((float)rand() / RAND_MAX >= 0.5) grid[i][j] = 1;
			else grid[i][j] = -1;
		}
	
	verbose = 0;
	monte_carlo(&grid[0][0], N, T);

	return 0;
}