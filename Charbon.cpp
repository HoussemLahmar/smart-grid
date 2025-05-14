#include "Charbon.hpp"
#include <iostream>

Charbon::Charbon(std::string loc, std::string carb, std::string qualité)
    : SystèmeNonRenouvelable(loc, carb), qualité(qualité) {}

float Charbon::calculerPuissanceProduite() {
    // Exemple : P = η * m * PCI (PCI = pouvoir calorifique inférieur)
    const float rendement = 0.35;  // Rendement fictif
    const float masse = 100;  // Masse fictive en kg
    const float PCI = 25000;  // PCI fictif en kJ/kg
    puissanceProduite = rendement * masse * PCI;
    return puissanceProduite;
}

float Charbon::calculerEnergieProduite() {
    // Exemple : énergie = puissance * temps (temps = 1h pour simplification)
    return calculerPuissanceProduite() * 1;
}

bool Charbon::detecterAnomalie() {
    // Exemple simple d'anomalie : qualité du charbon non valide
    if (qualité.empty() || (qualité != "Haute" && qualité != "Moyenne" && qualité != "Basse")) {
        return true;
    }
    return false;
}