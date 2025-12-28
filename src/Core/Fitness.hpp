#ifndef FITNESS_HPP
#define FITNESS_HPP

#include <vector>
#include "Individu.hpp"
#include "Objet.hpp"

// Calcule la fitness d'un individu pour le problème du sac à dos
class Fitness {
private:
    std::vector<Objet> objets;
    int capaciteSac;
    double coefficientPenalite;

public:
    Fitness(const std::vector<Objet>& objets,
            int capaciteSac,
            double coefficientPenalite = 1.0);

    // Calcule et met à jour la fitness d'un individu
    void evaluer(Individu& individu) const;
};

#endif // FITNESS_HPP
