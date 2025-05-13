#include "UnitéProduction.hpp"

UnitéProduction::UnitéProduction(std::string loc)
    : location(loc), puissanceProduite(0), puissanceTotaleDelivrée(0), état(true) {}

void UnitéProduction::setÉtat(bool nouvelÉtat) {
    état = nouvelÉtat;
}

bool UnitéProduction::getÉtat() const {
    return état;
}

std::string UnitéProduction::getLocation() const {
    return location;
}