#include "GazNaturel.hpp"
#include <iostream>

GazNaturel::GazNaturel(std::string loc, std::string carb, float pression)
    : SystèmeNonRenouvelable(loc, carb), pression(pression) {}

float GazNaturel::calculerPuissanceProduite() {
    // Exemple : P = η * V * PCI (PCI = pouvoir calorifique inférieur)
    const float rendement = 0.45;  // Rendement fictif
    const float volume = 200;  // Volume fictif en m³
    const float PCI = 40000;  // PCI fictif en kJ/m³
    puissanceProduite = rendement * volume * PCI;
    return puissanceProduite;
}

float GazNaturel::calculerEnergieProduite() {
    // Exemple : énergie = puissance * temps (temps = 1h pour simplification)
    return calculerPuissanceProduite() * 1;
}

bool GazNaturel::detecterAnomalie() {
    // Exemple simple d'anomalie : pression hors des limites
    if (pression < 1 || pression > 200) {
        return true;
    }
    return false;
}