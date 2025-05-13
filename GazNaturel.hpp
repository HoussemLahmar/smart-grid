#ifndef GAZ_NATUREL_HPP
#define GAZ_NATUREL_HPP

#include "SystèmeNonRenouvelable.hpp"

class GazNaturel : public SystèmeNonRenouvelable {
private:
    float pression;  // Pression du gaz (bar)

public:
    GazNaturel(std::string loc, std::string carb, float pression);
    ~GazNaturel() override = default;

    float calculerPuissanceProduite() override;
    float calculerEnergieProduite() override;
    bool detecterAnomalie() override;
};

#endif // GAZ_NATUREL_HPP