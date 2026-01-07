#include "Selection.hpp"
#include <cstdlib>

// Initialise les paramètres de la sélection
Selection::Selection(size_t tailleTournoi, size_t nombreParents)
    : tailleTournoi(tailleTournoi), nombreParents(nombreParents)
{
    assert(tailleTournoi > 0);
    assert(nombreParents > 0);
}

// Applique la sélection par tournoi sur une population
std::vector<Individu>
Selection::selectionner(const Population& population) const
{
    assert(population.taille() >= tailleTournoi);

    std::vector<Individu> parents;

    for (size_t i = 0; i < nombreParents; ++i) {
          size_t index0 = std::rand() % population.taille();
        Individu meilleur = population.getIndividu(index0);

        for (size_t j = 0; j < tailleTournoi; ++j) {
            size_t index = std::rand() % population.taille();
            const Individu& candidat = population.getIndividu(index);

             if (candidat.getFitness() > meilleur.getFitness()) {
                meilleur = candidat;
            }
        }

        parents.push_back(meilleur);
    }

    return parents;
}
