#ifndef SMARTGRID_HPP
#define SMARTGRID_HPP

#include <vector>
#include <memory>
#include <map>
#include "UnitéProduction.hpp"
#include "Consommateur.hpp"
#include "SystèmeStockage.hpp"

class SmartGrid {
private:
    std::vector<std::shared_ptr<UnitéProduction>> unitésProduction;
    std::vector<std::shared_ptr<Consommateur>> consommateurs;
    SystèmeStockage stockage;

public:
    SmartGrid(SystèmeStockage stockage);
    ~SmartGrid() = default;

    void ajouterUnitéProduction(std::shared_ptr<UnitéProduction> unité);
    void ajouterConsommateur(std::shared_ptr<Consommateur> consommateur);
    void distribuerPuissance();
    void calculerFactures();
    void afficherRésuméConsommateurs();
};

#endif // SMARTGRID_HPP