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
    
    // Getters
    float getRendement() const;
    float getSurfacePanneaux() const;
    
    // Setters
    void setRendement(float rendement);
    void setSurfacePanneaux(float surface);
};

#endif // SOLAIRE_HPP