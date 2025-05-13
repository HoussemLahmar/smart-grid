#include "Géothermique.hpp"
#include <iostream>

Géothermique::Géothermique(std::string loc, float profondeur)
    : SystèmeRenouvelable(loc, "Géothermique"), profondeur(profondeur) {}

float Géothermique::calculerPuissanceProduite() {
    // Exemple : P = C * ΔT (C = capacité thermique, ΔT = différence de température)
    const float capaciteThermique = 500;  // Capacité thermique fictive
    const float deltaTemperature = 50;  // Différence de température fictive
    puissanceProduite = capaciteThermique * deltaTemperature;
    return puissanceProduite;
}

float Géothermique::calculerEnergieProduite() {
    // Exemple : énergie = puissance * temps (temps = 1h pour simplification)
    return calculerPuissanceProduite() * 1;
}

bool Géothermique::detecterAnomalie() {
    // Exemple simple d'anomalie : profondeur en dehors des limites attendues
    if (profondeur <= 0 || profondeur > 10000) {
        return true;
    }
    return false;
}