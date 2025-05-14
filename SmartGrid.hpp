#ifndef SMARTGRID_HPP
#define SMARTGRID_HPP

#include <vector>
#include <string>
#include <memory>
#include <map>
#include "UnitéProduction.hpp"
#include "Consommateur.hpp"
#include "SystèmeStockage.hpp"
#include "ConsommateurDomicile.hpp"
#include "ConsommateurDomicile.hpp"
#include "CSVHandler.hpp"

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
    void chargerConsommateurs(const std::string& filename);
    void sauvegarderConsommateurs(const std::string& filename);
};

#endif // SMARTGRID_HPP