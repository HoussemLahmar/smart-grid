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
};

#endif // GEOTHERMIQUE_HPP