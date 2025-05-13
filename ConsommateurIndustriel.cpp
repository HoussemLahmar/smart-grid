#include "ConsommateurIndustriel.hpp"

ConsommateurIndustriel::ConsommateurIndustriel(int id, std::string adresse, std::string localisation, float puissanceContractee, float puissanceReactive)
    : Consommateur(id, adresse, localisation, puissanceContractee), puissanceReactive(puissanceReactive) {}

float ConsommateurIndustriel::calculerConsommation() {
    return (puissanceContractee + puissanceReactive) / 1000.0; // Conversion de W à kWh
}

float ConsommateurIndustriel::getPuissanceReactive() const {
    return puissanceReactive;
}