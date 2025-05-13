#include "Éolienne.hpp"
#include <iostream>
#include <cmath>

#define M_PI  2*3.14

Éolienne::Éolienne(std::string loc, float hauteur, float vitesse)
    : SystèmeRenouvelable(loc, "Éolienne"), hauteur(hauteur), vitesseVent(vitesse) {}

float Éolienne::calculerPuissanceProduite() {
    // Exemple : P = 0.5 * ρ * A * v³ (ρ = 1.225 kg/m³, A = surface balayée)
    float densiteAir = 1.225;  // kg/m³
    float rayon = hauteur / 10;  // Approximatif : rayon des pales
    float aire = M_PI * rayon * rayon;
    puissanceProduite = 0.5 * densiteAir * aire * std::pow(vitesseVent, 3);
    return puissanceProduite;
}

float Éolienne::calculerEnergieProduite() {
    // Exemple : énergie = puissance * temps (temps = 1h pour simplification)
    return calculerPuissanceProduite() * 1;
}

bool Éolienne::detecterAnomalie() {
    // Exemple simple d'anomalie : vitesse du vent hors des limites
    if (vitesseVent < 3 || vitesseVent > 25) {
        return true;
    }
    return false;
}

// Implémentation des getters
float Éolienne::getHauteur() const {
    return hauteur;
}

float Éolienne::getVitesseVent() const {
    return vitesseVent;
}

// Implémentation des setters
void Éolienne::setHauteur(float hauteur) {
    this->hauteur = hauteur;
}

void Éolienne::setVitesseVent(float vitesse) {
    this->vitesseVent = vitesse;
}