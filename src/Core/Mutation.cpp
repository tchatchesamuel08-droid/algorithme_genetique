#include "Mutation.hpp"
#include <cstdlib>   // rand()
#include <ctime>

// Constructeur
Mutation::Mutation(double tauxMutation)
    : tauxMutation(tauxMutation)
{
    // Initialisation du générateur aléatoire
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

// Applique la mutation sur un individu
void Mutation::appliquer(Individu& individu) const
{
    std::vector<int>& chromosome = individu.getChromosome();

    for (int& gene : chromosome) {
        double alea = static_cast<double>(std::rand()) / RAND_MAX;

        if (alea < tauxMutation) {
            gene = 1 - gene; // inversion binaire
        }
    }
}
