#include "Fitness.hpp"
#include <cassert>

Fitness::Fitness(const std::vector<Objet>& objets,
                 int capaciteSac,
                 double coefficientPenalite)
    : objets(objets),
      capaciteSac(capaciteSac),
      coefficientPenalite(coefficientPenalite)
{
    assert(capaciteSac > 0);
}
// definitio de fonction evalution
void Fitness::evaluer(Individu& individu) const
{
    int poidsTotal = 0;
    int valeurTotale = 0;

    const std::vector<int>& chromosome = individu.getChromosome();

    for (size_t i = 0; i < chromosome.size(); ++i) {
        if (chromosome[i] == 1) {
            poidsTotal  += objets[i].getPoids();
            valeurTotale += objets[i].getValeur();
        }
    }

    double fitness;
 //action de la penaliter 
    if (poidsTotal <= capaciteSac) {
        fitness = valeurTotale;
    } else {
        int depassement = poidsTotal - capaciteSac;
        fitness = valeurTotale - coefficientPenalite * depassement;
    }

    individu.setFitness(fitness);
}
