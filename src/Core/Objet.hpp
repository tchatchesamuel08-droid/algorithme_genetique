#ifndef OBJET_HPP
#define OBJET_HPP

#include <cassert>

// Classe représentant un objet du sac à dos.
// Un objet possède un poids et une valeur qui ne changent pas.
class Objet {
private:
    double poids;
    double valeur;

public:
    // Crée un objet avec un poids et une valeur.
    // Le poids doit être positif, la valeur non négative.
    Objet(double poids, double valeur)
        : poids(poids), valeur(valeur)
    {
        assert(poids > 0.0);
        assert(valeur >= 0.0);
    }

    // Retourne le poids de l'objet
    double getPoids() const {
        return poids;
    }

    // Retourne la valeur de l'objet
    double getValeur() const {
        return valeur;
    }
};

#endif
