#ifndef CONSOMMATEUR_INDUSTRIEL_HPP
#define CONSOMMATEUR_INDUSTRIEL_HPP

#include "Consommateur.hpp"

class ConsommateurIndustriel : public Consommateur {
private:
    float puissanceReactive;  // Puissance réactive consommée (VAR)

public:
    ConsommateurIndustriel(int id, std::string adresse, std::string localisation, float puissanceContractee, float puissanceReactive);
    ~ConsommateurIndustriel() override = default;

    float calculerConsommation() override;
    float getPuissanceReactive() const;
    std::string getType() const override; // Implémentation pour Industriel

};

#endif // CONSOMMATEUR_INDUSTRIEL_HPP