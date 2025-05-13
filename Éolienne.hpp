#ifndef EOLIENNE_HPP
#define EOLIENNE_HPP

#include "SystèmeRenouvelable.hpp"

class Éolienne : public SystèmeRenouvelable {
private:
    float hauteur;  // Hauteur de l'éolienne (m)
    float vitesseVent;  // Vitesse du vent (m/s)

public:
    Éolienne(std::string loc, float hauteur, float vitesse);
    ~Éolienne() override = default;

    float calculerPuissanceProduite() override;
    float calculerEnergieProduite() override;
    bool detecterAnomalie() override;
    
    // Getters
    float getHauteur() const;
    float getVitesseVent() const;
    
    // Setters
    void setHauteur(float hauteur);
    void setVitesseVent(float vitesse);
};

#endif // EOLIENNE_HPP