#ifndef GEOTHERMIQUE_HPP
#define GEOTHERMIQUE_HPP

#include "SystèmeRenouvelable.hpp"

class Géothermique : public SystèmeRenouvelable {
private:
    float profondeur;  // Profondeur du puits géothermique (m)

public:
    Géothermique(std::string loc, float profondeur);
    ~Géothermique() override = default;

    float calculerPuissanceProduite() override;
    float calculerEnergieProduite() override;
    bool detecterAnomalie() override;

    // Getter pour profondeur
    float getProfondeur() const { return profondeur; }

    // Setter pour profondeur
    void setProfondeur(float nouvelleProfondeur) { profondeur = nouvelleProfondeur; }
};

#endif // GEOTHERMIQUE_HPP