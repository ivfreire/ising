#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define LENGTH 32	// Grid side's length
#define J 1

// Evaluates total magnetization
float magnetization(char* grid) {
	int total_spin = 0;

	for (int i = 0; i < LENGTH; i++)
		for (int j = 0; j < LENGTH; j++)
			total_spin += *(grid + LENGTH * i + j);

	return (float)(abs(total_spin)) / (LENGTH * LENGTH);
}

// Calculates one site's energy
char energy(char* grid, int i, int j) {
	char e = 0;

	int l = (LENGTH + (j - 1)) % LENGTH;
	int r = (j + 1) % LENGTH;
	int t = (LENGTH + (i - 1)) % LENGTH;
	int b = (i + 1) % LENGTH;
	
	e += *(grid + LENGTH * i + l);
	e += *(grid + LENGTH * i + r);
	e += *(grid + LENGTH * t + j);
	e += *(grid + LENGTH * b + j);

	return - e * *(grid + LENGTH * i + j);
}

// Checks if site's spin is flippable
int test_flip(char* grid, int i, int j, float T) {
	char de		= -2 * energy(grid, i, j);
	float z 	= (float)rand() / RAND_MAX;
	float r 	= exp(-de / T);
	if (de > 0 && z > r) return 1;
	return 0;
}

// Flipping...
void flip(char* grid, int i, int j) {
	*(grid + LENGTH * i + j) = - *(grid + LENGTH * i + j);
}

// Chooses a site at random and flip its spin 
void step(char* grid, float T) {
	int i = rand() % LENGTH;
	int j = rand() % LENGTH;
	if (test_flip(grid, i, j, T) == 0) flip(grid, i, j);
}

// Run numerous steps to evaluate the grid model
void monte_carlo(char* grid, int N, float T) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < (LENGTH * LENGTH); j++) step(grid, T);
	}	
}


int main(int argc, char* argv[]) {
	srand(time(NULL));
	
	char grid[LENGTH][LENGTH];
	
	int N = 20;
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