#ifndef CONSOMMATEUR_DOMICILE_HPP
#define CONSOMMATEUR_DOMICILE_HPP

#include "Consommateur.hpp"
#include <string>

class ConsommateurDomicile : public Consommateur {
private:
    float puissanceActive;  // Puissance active consommée (W)

public:
    ConsommateurDomicile(int id, std::string adresse, std::string localisation, float puissanceContractee, float puissanceActive);
    ~ConsommateurDomicile() override = default;

    float calculerConsommation() override;
    float getPuissanceActive() const;
    std::string getType() const override; // Implémentation pour Domicile

};

#endif // CONSOMMATEUR_DOMICILE_HPP