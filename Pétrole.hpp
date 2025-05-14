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

    // Getter pour type
    std::string getType() const { return type; }

    // Setter pour type
    void setType(const std::string& nouveauType) { type = nouveauType; }
};

#endif // PETROLE_HPP