#ifndef MUTATION_HPP
#define MUTATION_HPP

#include "Individu.hpp"

// Module responsable de la mutation des individus
class Mutation {
private:
    double tauxMutation; // probabilité entre 0.0 et 1.0

public:
    // Constructeur
    explicit Mutation(double tauxMutation);

    // Applique la mutation sur un individu
    void appliquer(Individu& individu) const;
};

#endif // MUTATION_HPP
