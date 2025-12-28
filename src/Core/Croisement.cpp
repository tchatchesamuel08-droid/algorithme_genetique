#include "Croisement.hpp"
#include <random>

Croisement::Croisement(double tauxCroisement)
    : tauxCroisement(tauxCroisement)
{
}

Individu Croisement::appliquer(const Individu& parent1,
                               const Individu& parent2) const
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> proba(0.0, 1.0);

    const auto& chrom1 = parent1.getChromosome();
    const auto& chrom2 = parent2.getChromosome();

    // L’enfant commence comme une copie du parent 1
    std::vector<int> enfantChromosome = chrom1;

    // Croisement à un point selon le taux de croisement
    if (proba(gen) < tauxCroisement) {
        std::uniform_int_distribution<> point(1, chrom1.size() - 1);
        size_t k = point(gen);

        for (size_t i = k; i < chrom1.size(); ++i) {
            enfantChromosome[i] = chrom2[i];
        }
    }

    return Individu(enfantChromosome);
}
