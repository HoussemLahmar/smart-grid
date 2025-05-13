#ifndef CHARBON_HPP
#define CHARBON_HPP

#include "SystèmeNonRenouvelable.hpp"

class Charbon : public SystèmeNonRenouvelable {
private:
    std::string qualite;  // Qualité du charbon

public:
    Charbon(std::string loc, std::string carb, std::string qualite);
    ~Charbon() override = default;

    float calculerPuissanceProduite() override;
    float calculerEnergieProduite() override;
    bool detecterAnomalie() override;
};

#endif // CHARBON_HPP