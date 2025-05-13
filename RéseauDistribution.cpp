#include "RéseauDistribution.hpp"
#include <iostream>

RéseauDistribution::RéseauDistribution(float tension, float impédance)
    : tension(tension), impédance(impédance) {}

float RéseauDistribution::calculerPertes() {
    // Exemple : pertes = (P² * R) / V² (simplification)
    const float puissance = 1000;  // Puissance fictive
    return (puissance * puissance * impédance) / (tension * tension);
}

void RéseauDistribution::distribuerPuissance(float puissance) {
    std::cout << "Distribution de " << puissance << " W vers les consommateurs.\n";
}