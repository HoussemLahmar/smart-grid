#include "Consommateur.hpp"

Consommateur::Consommateur(int id, std::string adresse, std::string localisation, float puissance)
    : id(id), adresse(adresse), localisation(localisation), puissanceContractee(puissance) {}

std::string Consommateur::getLocalisation() const {
    return localisation;
}

int Consommateur::getId() const {
    return id;
}

std::string Consommateur::getAdresse() const {
    return adresse;
}

float Consommateur::getPuissanceContractee() const {
    return puissanceContractee;
}