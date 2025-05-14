#include "ConsommateurDomicile.hpp"

ConsommateurDomicile::ConsommateurDomicile(int id, std::string adresse, std::string localisation, float puissanceContractee, float puissanceActive)
    : Consommateur(id, adresse, localisation, puissanceContractee), puissanceActive(puissanceActive) {}

float ConsommateurDomicile::calculerConsommation() {
    return puissanceActive / 1000.0; // Conversion de W à kWh
}

float ConsommateurDomicile::getPuissanceActive() const {
    return puissanceActive;
}

std::string ConsommateurDomicile::getType() const {
    return "Domicile";
}
