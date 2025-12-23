#ifndef SELECTION_HPP
#define SELECTION_HPP

#include "Population.hpp"
#include <vector>

// Sélection par tournoi
class Selection {
private:
    size_t tailleTournoi;
    size_t nombreParents;

public:
//contructeur de la classe selection 
    Selection(size_t tailleTournoi, size_t nombreParents);

    std::vector<Individu> selectionner(const Population& population) const;
};

#endif
