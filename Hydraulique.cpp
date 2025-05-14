#include "Hydraulique.hpp"
#include <iostream>

Hydraulique::Hydraulique(std::string loc, float débit, float hauteur)
    : SystèmeRenouvelable(loc, "Hydraulique"), débit(débit), hauteurChute(hauteur) {}

float Hydraulique::calculerPuissanceProduite() {
    // Exemple : P = ρ * g * h * Q (ρ = 1000 kg/m³, g = 9.81 m/s²)
    const float densiteEau = 1000;  // kg/m³
    const float gravite = 9.81;  // m/s²
    puissanceProduite = densiteEau * gravite * hauteurChute * débit;
    return puissanceProduite;
}

float Hydraulique::calculerEnergieProduite() {
    // Exemple : énergie = puissance * temps (temps = 1h pour simplification)
    return calculerPuissanceProduite() * 1;
}

bool Hydraulique::detecterAnomalie() {
    // Exemple simple d'anomalie : débit ou hauteur en dehors des limites attendues
    if (débit <= 0 || hauteurChute <= 0) {
        return true;
    }
    return false;
}