#ifndef HYDRAULIQUE_HPP
#define HYDRAULIQUE_HPP

#include "SystèmeRenouvelable.hpp"

class Hydraulique : public SystèmeRenouvelable {
private:
    float débit;  // Débit d'eau (m³/s)
    float hauteurChute;  // Hauteur de chute d'eau (m)

public:
    Hydraulique(std::string loc, float débit, float hauteur);
    ~Hydraulique() override = default;

    float calculerPuissanceProduite() override;
    float calculerEnergieProduite() override;
    bool detecterAnomalie() override;

    // Getter et Setter corrigés pour "débit" et "hauteurChute"
    float getDébit() const { return débit; }
    void setDébit(float nouveauDébit) { débit = nouveauDébit; }

    float getHauteurChute() const { return hauteurChute; }
    void setHauteurChute(float nouvelleHauteur) { hauteurChute = nouvelleHauteur; }
};

#endif // HYDRAULIQUE_HPP