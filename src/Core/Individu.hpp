#ifndef INDIVIDU_HPP
#define INDIVIDU_HPP

#include <vector>
#include <cassert>
#include "Objet.hpp"

// Représente une solution candidate du problème du sac à dos
class Individu {
private:
    std::vector<int> chromosome;   // 0 ou 1 pour chaque objet
    double fitness;

public:
    // Crée un individu à partir d'un chromosome donné
    // Le chromosome doit avoir la même taille que la liste des objets
    Individu(const std::vector<int>& chromosome)
        : chromosome(chromosome), fitness(0.0)
    {
        // Vérification simple : chromosome non vide
        assert(!chromosome.empty());
    }

    // Retourne le chromosome
    const std::vector<int>& getChromosome() const {
        return chromosome;
    }

    // Retourne la fitness de l'individu
    double getFitness() const {
        return fitness;
    }

    // Met à jour la fitness (calculée ailleurs)
    void setFitness(double nouvelleFitness) {
        assert(nouvelleFitness >= 0.0);
        fitness = nouvelleFitness;
    }

    // Calcule le poids total du sac pour cet individu
    double calculerPoidsTotal(const std::vector<Objet>& objets) const {
        assert(objets.size() == chromosome.size());

        double poidsTotal = 0.0;
        for (size_t i = 0; i < chromosome.size(); ++i) {
            if (chromosome[i] == 1) {
                poidsTotal += objets[i].getPoids();
            }
        }
        return poidsTotal;
    }

    // Calcule la valeur totale du sac pour cet individu
    double calculerValeurTotale(const std::vector<Objet>& objets) const {
        assert(objets.size() == chromosome.size());

        double valeurTotale = 0.0;
        for (size_t i = 0; i < chromosome.size(); ++i) {
            if (chromosome[i] == 1) {
                valeurTotale += objets[i].getValeur();
            }
        }
        return valeurTotale;
    }
};

#endif // INDIVIDU_HPP
