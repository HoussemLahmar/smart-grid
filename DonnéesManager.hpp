#ifndef DONNEES_MANAGER_HPP
#define DONNEES_MANAGER_HPP

#include <string>
#include <vector>
#include <memory>
#include "UnitéProduction.hpp"
#include "Consommateur.hpp"
#include "SystèmeStockage.hpp"

class DonnéesManager {
private:
    std::string cheminDossier; // Chemin du dossier où sauvegarder et charger les fichiers

public:
    DonnéesManager(const std::string& chemin);
    ~DonnéesManager() = default;

    // Méthodes de sauvegarde
    bool sauvegarderUnitésProduction(const std::vector<std::shared_ptr<UnitéProduction>>& unités);
    bool sauvegarderConsommateurs(const std::vector<std::shared_ptr<Consommateur>>& consommateurs);
    bool sauvegarderÉtatStockage(const SystèmeStockage& stockage);
    bool sauvegarderSimulation(const std::string& nom, float énergieProduction, float énergieConsommation);

    // Méthodes de chargement
    bool chargerUnitésProduction(std::vector<std::shared_ptr<UnitéProduction>>& unités);
    bool chargerConsommateurs(std::vector<std::shared_ptr<Consommateur>>& consommateurs);
    bool chargerÉtatStockage(SystèmeStockage& stockage);

    // Méthodes de suppression
    bool supprimerUnitéProduction(std::vector<std::shared_ptr<UnitéProduction>>& unités, const std::string& location);
    bool supprimerConsommateur(std::vector<std::shared_ptr<Consommateur>>& consommateurs, int id);

    // Méthodes utilitaires
    std::vector<std::string> listeSimulations();
    void supprimerSimulation(const std::string& nom);
};

#endif // DONNEES_MANAGER_HPP