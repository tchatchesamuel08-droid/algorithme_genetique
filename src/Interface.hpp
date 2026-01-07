#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <SDL3/SDL.h>
#include <vector>
#include "Stats.hpp"
#include "Population.hpp"


class Application;

class Interface {
public:
    explicit Interface(Application& app);

    // Initialisation / destruction
    bool init();
    void frame();      // une frame graphique
    void shutdown();

    // Demandes utilisateur
    bool demandeQuitter() const;
    bool demandeStep() const;
    bool demandePlay() const;
    bool demandeReset() const;
    // Données du problème (fournies à l’algorithme)
    const std::vector<Objet>& getObjets() const;
    double getCapaciteSac() const;
    size_t getTaillePopulation() const;
    size_t getNbGenerations() const;

    // Paramètres modifiables
    double getTauxMutation() const;
    double getTauxCroisement() const;
    int getTailleTournoi() const;
    int getNombreParents() const;

    // Affichage
    void afficherStats(const Stats& stats);
    void afficherPopulation(const Population& pop);
    // Affiche le meilleur individu (solution courante)
    void afficherMeilleur(const Individu& meilleur);
private:
    Application& application;

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    bool quitter = false;

    // États UI
    bool step = false;
    bool play = false;
    bool reset = false;

    // Paramètres GA
    float tauxMutation = 0.01f;
    float  tauxCroisement = 0.7f;
    int tailleTournoi = 3;
    int nombreParents = 20;
};

#endif
