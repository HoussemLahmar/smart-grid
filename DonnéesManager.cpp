// DonnéesManager.cpp
#include "DonnéesManager.hpp"
#include <fstream>
#include <iostream>
#include <filesystem>
#include "Solaire.hpp"
#include "Éolienne.hpp"
// Importer tous les autres types d'unités

DonnéesManager::DonnéesManager(const std::string& chemin) : cheminDossier(chemin) {
    // Créer le dossier s'il n'existe pas
    std::filesystem::create_directories(cheminDossier);
}

bool DonnéesManager::sauvegarderUnitésProduction(const std::vector<std::shared_ptr<UnitéProduction>>& unités) {
    std::ofstream fichier(cheminDossier + "/unites_production.csv");
    
    if (!fichier) {
        std::cerr << "Erreur lors de l'ouverture du fichier d'unités de production" << std::endl;
        return false;
    }
    
    // Écrire l'en-tête du fichier CSV
    fichier << "Type,Location,Puissance,Paramètres spécifiques" << std::endl;
    
    for (const auto& unite : unités) {
        // Identifier le type d'unité et sauvegarder les données spécifiques
        if (auto solaire = std::dynamic_pointer_cast<Solaire>(unite)) {
            fichier << "Solaire," << solaire->getLocation() << "," 
                    << solaire->calculerPuissanceProduite() << ","
                    << "rendement=" << solaire->getRendement() << ",surface=" << solaire->getSurfacePanneaux() << std::endl;
        }
        else if (auto eolienne = std::dynamic_pointer_cast<Éolienne>(unite)) {
            fichier << "Éolienne," << eolienne->getLocation() << "," 
                    << eolienne->calculerPuissanceProduite() << ","
                    << "hauteur=" << eolienne->getHauteur() << ",vitesse=" << eolienne->getVitesseVent() << std::endl;
        }
        // Continuer pour les autres types d'unités
    }
    
    fichier.close();
    return true;
}

// Implémentations similaires pour les autres méthodes