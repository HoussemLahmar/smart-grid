#ifndef PETROLE_HPP
#define PETROLE_HPP

#include "SystèmeNonRenouvelable.hpp"

class Pétrole : public SystèmeNonRenouvelable {
private:
    std::string type;

public:
    Pétrole(std::string loc, std::string carb, std::string type);
    ~Pétrole() override = default;

    float calculerPuissanceProduite() override;
    float calculerEnergieProduite() override;
    bool detecterAnomalie() override;
};

#endif // PETROLE_HPP