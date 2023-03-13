# Ising model

The Ising model is a mathematical model used to describe the behavior of interacting spins in a magnetic material. This project is an implementation of the Ising model in C programming.

### More on the Ising model

In the Ising model, each cell (spin) is represented by "+1" or "-1" states. The spins are arranged on a lattice, such as a square or cubic lattice, and interact with their nearest neighbors. The interaction between the spins is described by a Hamiltonian, which determines the energy of the system based on the orientation of the spins.

The behavior of the system is typically described using statistical mechanics, which involves calculating the probability of each possible configuration of spins at a given temperature. At high temperatures, the spins are randomly oriented, and the system is in a disordered or "paramagnetic" state. As the temperature decreases, the spins begin to align, and the system undergoes a phase transition to a "ferromagnetic" state, where all the spins are aligned in the same direction.

### Monte Carlo method with the Metropolis Algorithm

The Metropolis algorithm is a Monte Carlo method used to simulate the behavior of complex systems, including the Ising model. The algorithm involves randomly selecting a particle in the system and proposing a change in its spin orientation. The change is then accepted or rejected based on a probability determined by the change in energy and the temperature of the system. If the change is accepted, the spin orientation is updated, and the algorithm proceeds to the next iteration. The process is repeated many times to sample the configuration space of the system and calculate the average values of various properties, such as energy, magnetization, and specific heat.

## Usage

Change the `LENGTH` macro in `ising.h` file to the desired model's side length.

```c
#define LENGHT 128
```

Then compile the code with gcc compiler and execute the output binary in the terminal.

```
$ gcc ising.c -o ising -lm
$ ./ising
```
A list of temperatures and final magnetization should be prompted to the terminal.

## Magnetization

<img src='plots/magnetization.png' float='center' width='300px'>

## 

- Code created as an assignment for the Statistical Mechanics I course at the Institute of Physics at USP in 2022.
