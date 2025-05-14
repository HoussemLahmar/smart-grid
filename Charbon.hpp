#ifndef CHARBON_HPP
#define CHARBON_HPP

#include "SystèmeNonRenouvelable.hpp"

class Charbon : public SystèmeNonRenouvelable {
private:
    std::string qualité;  // Corrigé pour utiliser le mot "qualité"

public:
    Charbon(std::string loc, std::string carb, std::string qualité);
    ~Charbon() override = default;

    float calculerPuissanceProduite() override;
    float calculerEnergieProduite() override;
    bool detecterAnomalie() override;

    // Getter et Setter corrigés pour "qualité"
    std::string getQualité() const { return qualité; }
    void setQualité(const std::string& nouvelleQualité) { qualité = nouvelleQualité; }
};

#endif // CHARBON_HPP