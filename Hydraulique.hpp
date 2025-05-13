#ifndef HYDRAULIQUE_HPP
#define HYDRAULIQUE_HPP

#include "SystèmeRenouvelable.hpp"

class Hydraulique : public SystèmeRenouvelable {
private:
    float debit;  // Débit d'eau (m³/s)
    float hauteurChute;  // Hauteur de chute d'eau (m)

public:
    Hydraulique(std::string loc, float debit, float hauteur);
    ~Hydraulique() override = default;

    float calculerPuissanceProduite() override;
    float calculerEnergieProduite() override;
    bool detecterAnomalie() override;
};

#endif // HYDRAULIQUE_HPP