#ifndef CROISEMENT_HPP
#define CROISEMENT_HPP

#include "Individu.hpp"

// Gère le croisement entre deux individus
class Croisement {
private:
    double tauxCroisement; // Probabilité de croisement

public:
    explicit Croisement(double tauxCroisement);

    // Applique le croisement et retourne un nouvel individu
    Individu appliquer(const Individu& parent1,
                       const Individu& parent2) const;
};

#endif // CROISEMENT_HPP
