#ifndef POPULATION_HPP
#define POPULATION_HPP

#include <vector>
#include <cassert>
#include "Individu.hpp"

// Représente une population d'individus à une génération donnée
class Population {
private:
    std::vector<Individu> individus;

public:
    // Crée une population vide
    Population() = default;

    // Crée une population avec une liste d'individus
    Population(const std::vector<Individu>& individus)
        : individus(individus)
    {
        assert(!individus.empty());
    }

    // Retourne le nombre d'individus dans la population
    size_t taille() const {
        return individus.size();
    }

    // Retourne l'accès en lecture à un individu
    const Individu& getIndividu(size_t index) const {
        assert(index < individus.size());
        return individus[index];
    }

    // Retourne l'accès en modification à un individu
    Individu& getIndividu(size_t index) {
        assert(index < individus.size());
        return individus[index];
    }

    // Ajoute un individu à la population
    void ajouterIndividu(const Individu& individu) {
        individus.push_back(individu);
    }

    // Remplace toute la population
    void remplacer(const std::vector<Individu>& nouveauxIndividus) {
        assert(!nouveauxIndividus.empty());
        individus = nouveauxIndividus;
    }

    // Retourne tous les individus (lecture seule)
    const std::vector<Individu>& getIndividus() const {
        return individus;
    }
};

#endif // POPULATION_HPP
