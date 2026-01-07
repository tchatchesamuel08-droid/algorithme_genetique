#ifndef STATS_HPP
#define STATS_HPP

#include <cstddef>

// Structure contenant les statistiques observables de l'algorithme génétique
struct Stats {
    size_t generation;        // Numéro de génération courant
    double fitnessMax;        // Meilleure fitness de la population
    double fitnessMoyenne;    // Fitness moyenne
    size_t nbInvalides;       // Nombre d'individus invalides (poids > capacité)
};

#endif
