#ifndef SOLAIRE_HPP
#define SOLAIRE_HPP

#include "SystèmeRenouvelable.hpp"

class Solaire : public SystèmeRenouvelable {
private:
    float rendement;  // Rendement des panneaux solaires
    float surfacePanneaux;  // Surface totale des panneaux (m²)

public:
    Solaire(std::string loc, float rendement, float surface);
    ~Solaire() override = default;

    float calculerPuissanceProduite() override;
    float calculerEnergieProduite() override;
    bool detecterAnomalie() override;
};

#endif // SOLAIRE_HPP