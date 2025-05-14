// DonnéesManager.cpp
#include "DonnéesManager.hpp"
#include <fstream>
#include <iostream>
#include <filesystem>
#include "Solaire.hpp"
#include "Éolienne.hpp"
#include <sstream>
#include <algorithm>


// Importer tous les autres types d'unités

DonnéesManager::DonnéesManager(const std::string& chemin) : cheminDossier(chemin) {
    // Créer le dossier s'il n'existe pas
    std::filesystem::create_directories(cheminDossier);
}

bool DonnéesManager::sauvegarderUnitésProduction(const std::vector<std::shared_ptr<UnitéProduction>>& unités) {
    std::ofstream fichier(cheminDossier + "/unites_production.csv");

    if (!fichier.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier pour sauvegarder les unités de production." << std::endl;
        return false;
    }

    // Écrire l'en-tête du fichier CSV
    fichier << "Type,Location,Puissance,Paramètres spécifiques" << std::endl;

    // Sauvegarder les données des unités de production
    for (const auto& unite : unités) {
        if (!sauvegarderUnité(fichier, unite)) {
            std::cerr << "Erreur : Impossible de sauvegarder une unité de production." << std::endl;
            return false;
        }
    }

    fichier.close();
    return true;
}

bool DonnéesManager::sauvegarderUnité(std::ofstream& fichier, const std::shared_ptr<UnitéProduction>& unite) {
    if (auto solaire = std::dynamic_pointer_cast<Solaire>(unite)) {
        fichier << "Solaire," << solaire->getLocation() << ","
                << solaire->calculerPuissanceProduite() << ","
                << "rendement=" << solaire->getRendement() << ",surface=" << solaire->getSurfacePanneaux() << std::endl;
    } else if (auto eolienne = std::dynamic_pointer_cast<Éolienne>(unite)) {
        fichier << "Éolienne," << eolienne->getLocation() << ","
                << eolienne->calculerPuissanceProduite() << ","
                << "hauteur=" << eolienne->getHauteur() << ",vitesse=" << eolienne->getVitesseVent() << std::endl;
    } else if (auto geothermique = std::dynamic_pointer_cast<Géothermique>(unite)) {
        fichier << "Géothermique," << geothermique->getLocation() << ","
                << geothermique->calculerPuissanceProduite() << ","
                << "profondeur=" << geothermique->getProfondeur() << std::endl;
    } else if (auto hydraulique = std::dynamic_pointer_cast<Hydraulique>(unite)) {
        fichier << "Hydraulique," << hydraulique->getLocation() << ","
                << hydraulique->calculerPuissanceProduite() << ","
                << "debit=" << hydraulique->getDebit() << ",hauteur=" << hydraulique->getHauteurChute() << std::endl;
    } else if (auto charbon = std::dynamic_pointer_cast<Charbon>(unite)) {
        fichier << "Charbon," << charbon->getLocation() << ","
                << charbon->calculerPuissanceProduite() << ","
                << "qualite=" << charbon->getQualite() << std::endl;
    } else if (auto gazNaturel = std::dynamic_pointer_cast<GazNaturel>(unite)) {
        fichier << "GazNaturel," << gazNaturel->getLocation() << ","
                << gazNaturel->calculerPuissanceProduite() << ","
                << "pression=" << gazNaturel->getPression() << std::endl;
    } else if (auto petrole = std::dynamic_pointer_cast<Pétrole>(unite)) {
        fichier << "Pétrole," << petrole->getLocation() << ","
                << petrole->calculerPuissanceProduite() << ","
                << "type=" << petrole->getType() << std::endl;
    } else {
        std::cerr << "Erreur : Type d'unité de production inconnu." << std::endl;
        return false;
    }
    return true;
}
// Enregistrer les consommateurs dans un fichier CSV
bool DonnéesManager::sauvegarderConsommateurs(const std::vector<std::shared_ptr<Consommateur>>& consommateurs) {
    std::ofstream fichier(cheminDossier + "/consommateurs.csv");

    if (!fichier.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier pour sauvegarder les consommateurs." << std::endl;
        return false;
    }

    // Écrire l'en-tête du fichier CSV
    fichier << "Type,ID,Adresse,Localisation,Consommation,Paramètres spécifiques" << std::endl;

    // Enregistrer les données des consommateurs
    for (const auto& consommateur : consommateurs) {
        if (auto domicile = std::dynamic_pointer_cast<ConsommateurDomicile>(consommateur)) {
            fichier << "Domicile," << domicile->getId() << ","
                    << domicile->getAdresse() << ","
                    << domicile->getLocalisation() << ","
                    << domicile->calculerConsommation() << ","
                    << "PuissanceContractée=" << domicile->getPuissanceContractee() << std::endl;
        } else if (auto industriel = std::dynamic_pointer_cast<ConsommateurIndustriel>(consommateur)) {
            fichier << "Industriel," << industriel->getId() << ","
                    << industriel->getAdresse() << ","
                    << industriel->getLocalisation() << ","
                    << industriel->calculerConsommation() << ","
                    << "PuissanceRéactive=" << industriel->getPuissanceReactive() << std::endl;
        } else {
            std::cerr << "Erreur : Type de consommateur inconnu." << std::endl;
            return false;
        }
    }

    fichier.close();
    return true;
}

// Enregistrer l'état du système de stockage
bool DonnéesManager::sauvegarderÉtatStockage(const SystèmeStockage& stockage) {
    std::ofstream fichier(cheminDossier + "/etat_stockage.csv");

    if (!fichier.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier pour sauvegarder l'état du stockage." << std::endl;
        return false;
    }

    // Écrire les données du stockage
    fichier << "Capacité,PuissanceMax,NiveauCharge" << std::endl;
    fichier << stockage.getCapacité() << ","
            << stockage.getPuissanceMax() << ","
            << stockage.getNiveauCharge() << std::endl;

    fichier.close();
    return true;
}

// Enregistrer les résultats des simulations
bool DonnéesManager::sauvegarderSimulation(const std::string& nom, float énergieProduction, float énergieConsommation) {
    std::ofstream fichier(cheminDossier + "/simulation_" + nom + ".csv");

    if (!fichier.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier pour sauvegarder la simulation." << std::endl;
        return false;
    }

    // Écrire les résultats de la simulation
    fichier << "NomSimulation,EnergieProduction,EnergieConsommation" << std::endl;
    fichier << nom << "," << énergieProduction << "," << énergieConsommation << std::endl;

    fichier.close();
    return true;
}
#include <sstream>

// Charger les unités de production depuis un fichier CSV
bool DonnéesManager::chargerUnitésProduction(std::vector<std::shared_ptr<UnitéProduction>>& unités) {
    std::ifstream fichier(cheminDossier + "/unites_production.csv");

    if (!fichier.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier pour charger les unités de production." << std::endl;
        return false;
    }

    std::string ligne;
    std::getline(fichier, ligne); // Ignorer l'en-tête du fichier CSV

    while (std::getline(fichier, ligne)) {
        std::istringstream stream(ligne);
        std::string type, location, paramString;
        float puissance;
        std::getline(stream, type, ',');
        std::getline(stream, location, ',');
        stream >> puissance;
        std::getline(stream, paramString, ','); // Lire les paramètres spécifiques

        if (type == "Solaire") {
            float rendement, surface;
            sscanf(paramString.c_str(), "rendement=%f,surface=%f", &rendement, &surface);
            unités.emplace_back(std::make_shared<Solaire>(location, rendement, surface));
        } else if (type == "Éolienne") {
            float hauteur, vitesse;
            sscanf(paramString.c_str(), "hauteur=%f,vitesse=%f", &hauteur, &vitesse);
            unités.emplace_back(std::make_shared<Éolienne>(location, hauteur, vitesse));
        } else if (type == "Géothermique") {
            float profondeur;
            sscanf(paramString.c_str(), "profondeur=%f", &profondeur);
            unités.emplace_back(std::make_shared<Géothermique>(location, profondeur));
        } else if (type == "Hydraulique") {
            float debit, hauteur;
            sscanf(paramString.c_str(), "debit=%f,hauteur=%f", &debit, &hauteur);
            unités.emplace_back(std::make_shared<Hydraulique>(location, debit, hauteur));
        } else if (type == "Charbon") {
            std::string qualite = paramString.substr(paramString.find("=") + 1);
            unités.emplace_back(std::make_shared<Charbon>(location, "Carbone", qualite));
        } else if (type == "GazNaturel") {
            float pression;
            sscanf(paramString.c_str(), "pression=%f", &pression);
            unités.emplace_back(std::make_shared<GazNaturel>(location, "Gaz Naturel", pression));
        } else if (type == "Pétrole") {
            std::string petroleType = paramString.substr(paramString.find("=") + 1);
            unités.emplace_back(std::make_shared<Pétrole>(location, "Pétrole", petroleType));
        } else {
            std::cerr << "Erreur : Type d'unité de production inconnu." << std::endl;
            return false;
        }
    }

    fichier.close();
    return true;
}

// Charger les consommateurs depuis un fichier CSV
bool DonnéesManager::chargerConsommateurs(std::vector<std::shared_ptr<Consommateur>>& consommateurs) {
    std::ifstream fichier(cheminDossier + "/consommateurs.csv");

    if (!fichier.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier pour charger les consommateurs." << std::endl;
        return false;
    }

    std::string ligne;
    std::getline(fichier, ligne); // Ignorer l'en-tête du fichier CSV

    while (std::getline(fichier, ligne)) {
        std::istringstream stream(ligne);
        std::string type, adresse, localisation, paramString;
        int id;
        float consommation;
        std::getline(stream, type, ',');
        stream >> id;
        std::getline(stream, adresse, ',');
        std::getline(stream, localisation, ',');
        stream >> consommation;
        std::getline(stream, paramString, ',');

        if (type == "Domicile") {
            float puissanceContractee;
            sscanf(paramString.c_str(), "PuissanceContractée=%f", &puissanceContractee);
            consommateurs.emplace_back(std::make_shared<ConsommateurDomicile>(id, adresse, localisation, puissanceContractee, consommation));
        } else if (type == "Industriel") {
            float puissanceReactive;
            sscanf(paramString.c_str(), "PuissanceRéactive=%f", &puissanceReactive);
            consommateurs.emplace_back(std::make_shared<ConsommateurIndustriel>(id, adresse, localisation, consommation, puissanceReactive));
        } else {
            std::cerr << "Erreur : Type de consommateur inconnu." << std::endl;
            return false;
        }
    }

    fichier.close();
    return true;
}

// Charger l'état du système de stockage depuis un fichier CSV
bool DonnéesManager::chargerÉtatStockage(SystèmeStockage& stockage) {
    std::ifstream fichier(cheminDossier + "/etat_stockage.csv");

    if (!fichier.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier pour charger l'état du stockage." << std::endl;
        return false;
    }

    std::string ligne;
    std::getline(fichier, ligne); // Ignorer l'en-tête du fichier CSV
    float capacité, puissanceMax, niveauCharge;

    if (std::getline(fichier, ligne)) {
        sscanf(ligne.c_str(), "%f,%f,%f", &capacité, &puissanceMax, &niveauCharge);
        stockage.setCapacité(capacité);
        stockage.setPuissanceMax(puissanceMax);
        stockage.setNiveauCharge(niveauCharge);
    } else {
        std::cerr << "Erreur : Données de stockage invalides ou manquantes." << std::endl;
        return false;
    }

    fichier.close();
    return true;
}

// Supprimer une unité de production par sa localisation
bool DonnéesManager::supprimerUnitéProduction(std::vector<std::shared_ptr<UnitéProduction>>& unités, const std::string& location) {
    auto it = std::remove_if(unités.begin(), unités.end(), [&location](const std::shared_ptr<UnitéProduction>& unité) {
        return unité->getLocation() == location;
    });

    if (it != unités.end()) {
        unités.erase(it, unités.end());
        std::cout << "Unité de production située à " << location << " supprimée avec succès." << std::endl;
        return true;
    } else {
        std::cerr << "Erreur : Aucune unité de production trouvée à la localisation " << location << "." << std::endl;
        return false;
    }
}

// Supprimer un consommateur par son ID
bool DonnéesManager::supprimerConsommateur(std::vector<std::shared_ptr<Consommateur>>& consommateurs, int id) {
    auto it = std::remove_if(consommateurs.begin(), consommateurs.end(), [&id](const std::shared_ptr<Consommateur>& consommateur) {
        return consommateur->getId() == id;
    });

    if (it != consommateurs.end()) {
        consommateurs.erase(it, consommateurs.end());
        std::cout << "Consommateur avec l'ID " << id << " supprimé avec succès." << std::endl;
        return true;
    } else {
        std::cerr << "Erreur : Aucun consommateur trouvé avec l'ID " << id << "." << std::endl;
        return false;
    }
}