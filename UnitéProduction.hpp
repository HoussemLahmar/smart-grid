#ifndef UNITE_PRODUCTION_HPP
#define UNITE_PRODUCTION_HPP

#include <string>
#include <iostream>

class UnitéProduction {
protected:
    std::string location;  // Localisation géographique
    float puissanceProduite;  // Puissance produite (W)
    float puissanceTotaleDelivrée;  // Puissance totale délivrée (W)
    bool état;  // État opérationnel (true = fonctionnel, false = en panne)

public:
    UnitéProduction(std::string loc);
    virtual ~UnitéProduction() = default;

    virtual bool detecterAnomalie() = 0;  // Méthode abstraite
    virtual float calculerPuissanceProduite() = 0;  // Méthode abstraite

    void setÉtat(bool nouvelÉtat);
    bool getÉtat() const;
    std::string getLocation() const;
};

#endif // UNITE_PRODUCTION_HPP