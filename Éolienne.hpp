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

    // Getter pour hauteur
    float getHauteur() const { return hauteur; }

    // Setter pour hauteur
    void setHauteur(float nouvelleHauteur) { hauteur = nouvelleHauteur; }

    // Getter pour vitesseVent
    float getVitesseVent() const { return vitesseVent; }

    // Setter pour vitesseVent
    void setVitesseVent(float nouvelleVitesse) { vitesseVent = nouvelleVitesse; }
};

#endif // EOLIENNE_HPP