#ifndef ISING_H
#define ISING_H

#define LENGTH 128	// Grid side's length
#define J 1

int verbose = 1;

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
		if (verbose == 0) printf("%d\t%f\n", i, magnetization(grid));
	}	
}

#endif