#include "Pétrole.hpp"
#include <iostream>

Pétrole::Pétrole(std::string loc, std::string carb, std::string type)
    : SystèmeNonRenouvelable(loc, carb), type(type) {}

float Pétrole::calculerPuissanceProduite() {
    // Exemple : P = η * V * PCI (PCI = pouvoir calorifique inférieur)
    const float rendement = 0.40;  // Rendement fictif
    const float volume = 100;  // Volume fictif en litres
    const float PCI = 35000;  // PCI fictif en kJ/litre
    puissanceProduite = rendement * volume * PCI;
    return puissanceProduite;
}

float Pétrole::calculerEnergieProduite() {
    // Exemple : énergie = puissance * temps (temps = 1h pour simplification)
    return calculerPuissanceProduite() * 1;
}

bool Pétrole::detecterAnomalie() {
    // Exemple simple d'anomalie : type non valide
    if (type.empty() || (type != "Brut" && type != "Raffiné")) {
        return true;
    }
    return false;
}