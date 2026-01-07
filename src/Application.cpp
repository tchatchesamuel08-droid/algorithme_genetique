#include "Application.hpp"

/*
 * Constructeur :
 * Initialise l’interface, mais sans moteur actif
 */
Application::Application()
    : interface(*this), algo(nullptr) {}

/*
 * Boucle principale de l’application
 * (UNE SEULE boucle dans tout le projet)
 */
void Application::run() {
    interface.init();

    while (!interface.demandeQuitter()) {

        // Affichage + gestion des événements
        interface.frame();

        // Réinitialisation demandée par l’utilisateur
        if (interface.demandeReset()) {
            algo = std::make_unique<AlgorithmGenetique>(
                interface.getObjets(),
                interface.getCapaciteSac(),
                interface.getTaillePopulation(),
                interface.getNbGenerations()
            );
            algo->initialiser();
        }

        if (algo) {
            // Synchronisation des paramètres
            synchroniserParametres();

            // Exécution pas à pas ou continue
            if (interface.demandeStep() || interface.demandePlay())
                algo->step();

            // Affichage des résultats
            interface.afficherStats(algo->getStats());
            interface.afficherPopulation(algo->getPopulation());
            interface.afficherMeilleur(algo->getMeilleurIndividu());
        }
    }

    interface.shutdown();
}

/*
 * Met à jour les paramètres de l’algorithme
 * à partir des valeurs de l’interface
 */
void Application::synchroniserParametres() {
    algo->setTauxMutation(interface.getTauxMutation());
    algo->setTauxCroisement(interface.getTauxCroisement());
    algo->setTailleTournoi(interface.getTailleTournoi());
    algo->setNombreParents(interface.getNombreParents());
}
