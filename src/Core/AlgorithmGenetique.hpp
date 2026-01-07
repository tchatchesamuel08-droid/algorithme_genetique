#ifndef ALGORITHME_GENETIQUE_HPP
#define ALGORITHME_GENETIQUE_HPP

#include <vector>
#include "Population.hpp"
#include "Selection.hpp"
#include "Croisement.hpp"
#include "Mutation.hpp"
#include "Objet.hpp"
#include "Stats.hpp"


class AlgorithmGenetique {
public:
    // Constructeur
     
    AlgorithmGenetique(const std::vector<Objet>& objets,
                       double capaciteSac,
                       size_t taillePopulation,
                       size_t nbGenerationsMax);

    // Initialise (ou réinitialise) complètement la population
    void initialiser();

    // Exécute UNE génération complète
    void step();

    // Indique si l’algorithme est terminé
    bool estTermine() const;

    // Accès en lecture à la population courante
    const Population& getPopulation() const;

    // Retourne les statistiques globales de la génération courante
    Stats getStats() const;

    // Retourne le meilleur individu courant (solution approchée)
    const Individu& getMeilleurIndividu() const;

    // --- Paramètres modifiables dynamiquement ---
    void setTauxMutation(double taux);
    void setTauxCroisement(double taux);
    void setTailleTournoi(size_t taille);
    void setNombreParents(size_t nb);
    void setCapaciteSac(double capacite);

private:
    // Calcule la fitness de tous les individus
    void evaluerPopulation();

    // Données fixes du problème
    std::vector<Objet> objets;

    // Paramètres de l’algorithme
    double capaciteSac;
    size_t taillePopulation;
    size_t nbGenerationsMax;

    // État courant
    size_t generationCourante;

    // Population courante
    Population population;

    // Modules génétiques (stratégies)
    Selection selection;
    Croisement croisement;
    Mutation mutation;
};

#endif 
