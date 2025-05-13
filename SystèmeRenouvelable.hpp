#ifndef SYSTEME_RENOUVELABLE_HPP
#define SYSTEME_RENOUVELABLE_HPP

#include "UnitéProduction.hpp"

class SystèmeRenouvelable : public UnitéProduction {
protected:
    std::string type;  // Type de système (solaire, éolienne, etc.)

public:
    SystèmeRenouvelable(std::string loc, std::string t);
    virtual ~SystèmeRenouvelable() = default;

    virtual float calculerEnergieProduite() = 0;  // Méthode abstraite
};

#endif // SYSTEME_RENOUVELABLE_HPP