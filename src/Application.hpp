#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <memory>
#include "AlgorithmGenetique.hpp"
#include "Interface.hpp"


 
class Application {
public:
    Application();

    // Lance la boucle principale
    void run();

private:
    // Copie les paramètres de l’interface vers l’algorithme
    void synchroniserParametres();

private:
    Interface interface;                         // Interface utilisateur
    std::unique_ptr<AlgorithmGenetique> algo;    // Moteur génétique
};

#endif
