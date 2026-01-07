#include "AlgorithmGenetique.hpp"
#include <random>
#include <algorithm>
#include <cassert>

/*
 * Constructeur :
 * Initialise les paramètres et les modules génétiques
 */
AlgorithmGenetique::AlgorithmGenetique(const std::vector<Objet>& objets,
                                       double capaciteSac,
                                       size_t taillePopulation,
                                       size_t nbGenerationsMax)
    : objets(objets),
      capaciteSac(capaciteSac),
      taillePopulation(taillePopulation),
      nbGenerationsMax(nbGenerationsMax),
      generationCourante(0),
      selection(3, taillePopulation),
      croisement(0.7),
      mutation(0.01)
{
    assert(!objets.empty());
    assert(taillePopulation >= 2);
}

/*
 * Initialise la population de manière aléatoire
 * et évalue immédiatement la fitness
 */
void AlgorithmGenetique::initialiser() {
    generationCourante = 0;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> bit(0, 1);

    std::vector<Individu> individus;

    for (size_t i = 0; i < taillePopulation; ++i) {
        std::vector<int> chromosome(objets.size());
        for (size_t j = 0; j < objets.size(); ++j)
            chromosome[j] = bit(gen);

        individus.emplace_back(chromosome);
    }

    population = Population(individus);
    evaluerPopulation();
}

/*
 * Exécute une génération :
 *  - sélection
 *  - croisement
 *  - mutation
 *  - évaluation
 */
void AlgorithmGenetique::step() {
    if (estTermine()) return;

    auto parents = selection.selectionner(population);
    std::vector<Individu> enfants;

    for (size_t i = 0; i + 1 < parents.size(); i += 2) {
        Individu enfant = croisement.appliquer(parents[i], parents[i + 1]);
        mutation.appliquer(enfant);
        enfants.push_back(enfant);
    }

    if (!enfants.empty())
        population.remplacer(enfants);

    evaluerPopulation();
    generationCourante++;
}

bool AlgorithmGenetique::estTermine() const {
    return generationCourante >= nbGenerationsMax;
}

/*
 * Évalue la fitness de chaque individu
 * Fitness = valeur totale si contrainte respectée, sinon 0
 */
void AlgorithmGenetique::evaluerPopulation() {
    for (size_t i = 0; i < population.taille(); ++i) {
        Individu& ind = population.getIndividu(i);

        double poids = ind.calculerPoidsTotal(objets);
        double fitness = 0.0;

        if (poids <= capaciteSac)
            fitness = ind.calculerValeurTotale(objets);

        ind.setFitness(fitness);
    }
}

/*
 * Retourne le meilleur individu courant
 * (solution approchée du problème)
 */
const Individu& AlgorithmGenetique::getMeilleurIndividu() const {
    const Individu* meilleur = &population.getIndividu(0);

    for (size_t i = 1; i < population.taille(); ++i) {
        const Individu& ind = population.getIndividu(i);
        if (ind.getFitness() > meilleur->getFitness())
            meilleur = &ind;
    }

    return *meilleur;
}
