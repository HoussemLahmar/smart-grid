#include "Solaire.hpp"
#include <iostream>

Solaire::Solaire(std::string loc, float rendement, float surface)
    : SystèmeRenouvelable(loc, "Solaire"), rendement(rendement), surfacePanneaux(surface) {}

float Solaire::calculerPuissanceProduite() {
    // Exemple de calcul : P = η * S * I (I = irradiation fixe ici)
    float irradiation = 1000;  // W/m² (valeur fixe pour simplification)
    puissanceProduite = rendement * surfacePanneaux * irradiation;
    return puissanceProduite;
}

float Solaire::calculerEnergieProduite() {
    // Exemple : énergie = puissance * temps (temps = 1h pour simplification)
    return calculerPuissanceProduite() * 1;
}

bool Solaire::detecterAnomalie() {
    // Exemple simple d'anomalie : puissance produite en dehors des limites attendues
    if (puissanceProduite < 0 || puissanceProduite > surfacePanneaux * 1000) {
        return true;
    }
    return false;
}

// Implémentation des getters
float Solaire::getRendement() const {
    return rendement;
}

float Solaire::getSurfacePanneaux() const {
    return surfacePanneaux;
}

// Implémentation des setters
void Solaire::setRendement(float rendement) {
    this->rendement = rendement;
}

void Solaire::setSurfacePanneaux(float surface) {
    this->surfacePanneaux = surface;
}