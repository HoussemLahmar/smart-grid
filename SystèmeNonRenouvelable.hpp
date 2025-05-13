#ifndef SYSTEME_NON_RENOUVELABLE_HPP
#define SYSTEME_NON_RENOUVELABLE_HPP

#include "UnitéProduction.hpp"

class SystèmeNonRenouvelable : public UnitéProduction {
protected:
    std::string carburant;  // Type de carburant utilisé (charbon, pétrole, gaz, etc.)

public:
    SystèmeNonRenouvelable(std::string loc, std::string carb);
    virtual ~SystèmeNonRenouvelable() = default;

    virtual float calculerEnergieProduite() = 0;  // Méthode abstraite
};

#endif // SYSTEME_NON_RENOUVELABLE_HPP